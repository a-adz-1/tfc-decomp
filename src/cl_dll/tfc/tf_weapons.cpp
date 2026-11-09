/***
*
*	Team Fortress Classic: client-side weapon prediction
*
*	The weapons code runs on the client too (wpn_shared, CLIENT_DLL), on a
*	private set of entities and a stand-in player, so firing feels instant.
*	This is the glue: the stand-ins, the engine stubs, and copying weapon
*	state in and out of the prediction frames.
*
*	Reconstructed from client.so (25th Anniversary), DWARF-guided.
*
****/
#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "weapons.h"
#include "nodes.h"
#include "player.h"
#include "tf_defs.h"

#include "usercmd.h"
#include "entity_state.h"
#include "demo_api.h"
#include "pm_defs.h"
#include "event_api.h"
#include "r_efx.h"

#include "../hud_iface.h"
#include "../com_weapons.h"
#include "../demo.h"

extern globalvars_t *gpGlobals;
extern int g_iUser1;

// Pool of client side entities/entvars_t
static entvars_t	ev[ 32 ];
static int			num_ents = 0;

// The entity we'll use to represent the local client
static CBasePlayer	player;

// Local version of game .dll global variables ( time, etc. )
static globalvars_t	Globals;

static CBasePlayerWeapon *g_pWpns[ 32 ];

// The sniper's laser dot, drawn by tf_objects.cpp
struct laserdot_info_t
{
	Vector previousorigin;
	int laserdotactive;
	int laserdotintensity;
};

static laserdot_info_t g_laserdot;

// TFC weapon placeholder entities.
CTFShotgun			g_Gun;
CTFSuperShotgun		g_Super;
CTFNailgun			g_NG;
CTFSuperNailgun		g_SNG;
CTFTranq			g_Tranq;
CTFFlamethrower		g_Flame;
CTFIncendiaryC		g_IC;
CTFRailgun			g_Rail;
CTFRpg				g_RPG;
CTFAutoRifle		g_AR;
CTFAssaultC			g_AC;
CTFGrenadeLauncher	g_GL;
CTFPipebombLauncher	g_PL;
CTFSniperRifle		g_Sniper;
CTFKnife			g_Knife;
CTFSpanner			g_Spanner;
CTFMedikit			g_Medkit;
CTFAxe				g_Crowbar;
CLaserSpot			g_Spot;

// HUD_PrepEntity ammo pointer
#define AMMO_NONE		0
#define AMMO_SHELLS		1
#define AMMO_CELLS		2
#define AMMO_NAILS		3
#define AMMO_ROCKETS	4

/*
======================
AlertMessage

Print debug messages to console
======================
*/
void AlertMessage( ALERT_TYPE atype, char *szFmt, ... )
{
	va_list		argptr;
	static char	string[1024];

	va_start( argptr, szFmt );
	vsprintf( string, szFmt, argptr );
	va_end( argptr );

	gEngfuncs.Con_Printf( "cl:  " );
	gEngfuncs.Con_Printf( string );
}

/*
=====================
HUD_PrepEntity

Links the raw entity to an entvars_s holder.  If a player is passed in as the owner, then
we set up the m_pPlayer field and the weapon's ammo pointer.
=====================
*/
void HUD_PrepEntity( CBaseEntity *pEntity, CBasePlayer *pWeaponOwner, int ammotype )
{
	memset( &ev[ num_ents ], 0, sizeof( entvars_t ) );
	pEntity->pev = &ev[ num_ents++ ];

	pEntity->Precache();
	pEntity->Spawn();

	if ( pWeaponOwner )
	{
		ItemInfo info;

		( (CBasePlayerWeapon *)pEntity )->m_pPlayer = pWeaponOwner;

		switch ( ammotype )
		{
		case AMMO_SHELLS:	pEntity->current_ammo = &pWeaponOwner->ammo_shells; break;
		case AMMO_CELLS:	pEntity->current_ammo = &pWeaponOwner->ammo_cells; break;
		case AMMO_NAILS:	pEntity->current_ammo = &pWeaponOwner->ammo_nails; break;
		case AMMO_ROCKETS:	pEntity->current_ammo = &pWeaponOwner->ammo_rockets; break;
		}

		( (CBasePlayerWeapon *)pEntity )->GetItemInfo( &info );

		g_pWpns[ info.iId ] = (CBasePlayerWeapon *)pEntity;
	}
}

/*
=====================
HUD_GetLastOrg

Retruns the last position that we stored for egon beam endpoint.
=====================
*/
void HUD_GetLastOrg( float *org )
{
	int i;

	// Return last origin
	for ( i = 0; i < 3; i++ )
	{
		org[i] = g_laserdot.previousorigin[i];
	}
}

/*
=====================
HUD_SetLastOrg

Remember our exact predicted origin so we can draw the laser dot from it
=====================
*/
void HUD_SetLastOrg( void )
{
	int i;

	// Offset final origin by view_offset
	for ( i = 0; i < 3; i++ )
	{
		g_laserdot.previousorigin[i] = g_finalstate->playerstate.origin[i] + g_finalstate->client.view_ofs[ i ];
	}
}

/*
=====================
HUD_NeedSpot

Should the laser dot be drawn, and how bright
=====================
*/
int HUD_NeedSpot( int *damage )
{
	*damage = g_laserdot.laserdotintensity;
	return g_laserdot.laserdotactive;
}

/*
=====================
HUD_SpotActive
=====================
*/
int HUD_SpotActive( void )
{
	return !( g_Spot.pev->effects & EF_NODRAW );
}

/*
=====================
CLaserSpot::CreateSpot

There's only one spot on the client: turn it on
=====================
*/
CLaserSpot *CLaserSpot::CreateSpot( void )
{
	g_Spot.pev->effects &= ~EF_NODRAW;
	return &g_Spot;
}

/*
=====================
CBaseEntity :: Killed

If weapons code "kills" an entity, just set its effects to EF_NODRAW
=====================
*/
void CBaseEntity :: Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib )
{
	pev->effects |= EF_NODRAW;
}

/*
=====================
CBasePlayerWeapon :: CanDeploy
=====================
*/
BOOL CBasePlayerWeapon :: CanDeploy( void )
{
	BOOL bHasAmmo = 0;
	ItemInfo info;

	GetItemInfo( &info );

	if ( !info.pszAmmo1 )
	{
		// this weapon doesn't use ammo, can always deploy.
		return TRUE;
	}

	if ( info.iAmmo1 == -1 )
		return TRUE;

	// the rifle doesn't predict its ammo
	if ( this == &g_Sniper )
		return TRUE;

	if ( current_ammo )
		bHasAmmo = *current_ammo;
	else
		bHasAmmo = ( m_pPlayer->m_rgAmmo[ m_iPrimaryAmmoType ] != 0 );

	if ( info.pszAmmo2 )
	{
		bHasAmmo |= ( m_pPlayer->m_rgAmmo[ m_iSecondaryAmmoType ] != 0 );
	}

	if ( m_iClip > 0 )
	{
		bHasAmmo |= 1;
	}

	if ( !bHasAmmo )
	{
		return FALSE;
	}

	return TRUE;
}

/*
=====================
CBasePlayerWeapon :: DefaultDeploy
=====================
*/
BOOL CBasePlayerWeapon :: DefaultDeploy( char *szViewModel, char *szWeaponModel, int iAnim, char *szAnimExt, int skiplocal )
{
	if ( !CanDeploy() )
		return FALSE;

	gEngfuncs.CL_LoadModel( szViewModel, &m_pPlayer->pev->viewmodel );
	m_pPlayer->current_weapon = m_iId;

	SendWeaponAnim( iAnim, 0 );

	m_pPlayer->m_flNextAttack = 0.5;
	m_flTimeWeaponIdle = 1.0;
	return TRUE;
}

/*
=====================
CBasePlayerWeapon :: PlayEmptySound
=====================
*/
BOOL CBasePlayerWeapon :: PlayEmptySound( void )
{
	if ( m_iPlayEmptySound )
	{
		HUD_PlaySound( "weapons/357_cock1.wav", 0.8 );
		m_iPlayEmptySound = 0;
		return 0;
	}
	return 0;
}

/*
=====================
CBasePlayerWeapon :: ResetEmptySound
=====================
*/
void CBasePlayerWeapon :: ResetEmptySound( void )
{
	m_iPlayEmptySound = 1;
}

/*
=====================
CBasePlayerWeapon::Holster

Put away weapon
=====================
*/
void CBasePlayerWeapon::Holster( int skiplocal )
{
	m_pPlayer->tfstate &= ~TFSTATE_RELOADING;
	m_fInReload = FALSE; // cancel any reload in progress.
	m_pPlayer->pev->viewmodel = 0;
}

/*
=====================
CBasePlayerWeapon::SendWeaponAnim

Animate weapon model
=====================
*/
void CBasePlayerWeapon::SendWeaponAnim( int iAnim, int skiplocal )
{
	m_pPlayer->pev->weaponanim = iAnim;

	// the tranquiliser is drawn with the first body
	int body = 2;
	if ( this == &g_Tranq )
		body = 1;

	HUD_SendWeaponAnim( iAnim, body, 0 );
}

/*
=====================
CBasePlayerWeapon::ItemPostFrame

Handles weapon firing, reloading, etc.
=====================
*/
void CBasePlayerWeapon::ItemPostFrame( void )
{
	ItemInfo info;
	GetItemInfo( &info );

	int *pAmmo = current_ammo;
	if ( !pAmmo )
		pAmmo = &m_pPlayer->m_rgAmmo[ m_iPrimaryAmmoType ];

	if ( ( m_fInReload ) && ( m_pPlayer->m_flNextAttack <= 0.0 ) )
	{
		ItemInfo reload;
		GetItemInfo( &reload );

		// complete the reload.
		int j = min( reload.iMaxClip - m_iClip, *pAmmo );

		// Add them to the clip
		m_iClip += j;
		*pAmmo -= j;

		m_fInReload = FALSE;
		m_pPlayer->tfstate &= ~TFSTATE_RELOADING;
	}

	if ( ( m_pPlayer->pev->button & IN_ATTACK ) && ( m_flNextPrimaryAttack <= 0.0 ) )
	{
		if ( ( m_iClip == 0 && info.pszAmmo1 ) || ( info.iMaxClip == -1 && !*pAmmo ) )
		{
			m_fFireOnEmpty = TRUE;
		}

		// quad damage sound timer
		if ( gpGlobals->time < m_pPlayer->super_damage_finished && m_pPlayer->m_fSuperSound < gpGlobals->time )
		{
			m_fSuperSound = gpGlobals->time + 1;
		}

		PrimaryAttack();
	}
	else if ( ( m_pPlayer->pev->button & IN_RELOAD ) && info.iMaxClip != WEAPON_NOCLIP && !m_fInReload )
	{
		// reload when reload is pressed, or if no buttons are down and weapon is empty.
		Reload();
	}
	else if ( !( m_pPlayer->pev->button & ( IN_ATTACK | IN_ATTACK2 ) ) )
	{
		// no fire buttons down
		m_fFireOnEmpty = FALSE;

		// weapon is useable. Reload if empty and weapon has waited as long as it has to after firing
		if ( m_iClip == 0 && !( info.iFlags & ITEM_FLAG_NOAUTORELOAD ) && m_flNextPrimaryAttack < 0.0 )
		{
			Reload();
			return;
		}

		WeaponIdle();
		return;
	}

	// catch all
	if ( ShouldWeaponIdle() )
	{
		WeaponIdle();
	}
}

/*
=====================
CBasePlayer::SelectItem

  Switch weapons
=====================
*/
void CBasePlayer::SelectItem( const char *pstr )
{
}

/*
=====================
CBasePlayer::SelectLastItem

=====================
*/
void CBasePlayer::SelectLastItem( void )
{
	if ( !m_pLastItem )
	{
		return;
	}

	if ( m_pActiveItem && !m_pActiveItem->CanHolster() )
	{
		return;
	}

	if ( m_pActiveItem )
		m_pActiveItem->Holster();

	CBasePlayerItem *pTemp = m_pActiveItem;
	m_pActiveItem = m_pLastItem;
	m_pLastItem = pTemp;
	m_pActiveItem->Deploy();
}

/*
=====================
CBasePlayer::Killed

=====================
*/
void CBasePlayer::Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib )
{
	// Holster weapon immediately, to allow it to cleanup
	if ( m_pActiveItem )
		m_pActiveItem->Holster();

	tfstate &= ~TFSTATE_AIMING;
	TeamFortress_SetSpeed();

	// stop a primed grenade's ticking
	gEngfuncs.pEventAPI->EV_StopSound( gEngfuncs.GetLocalPlayer()->index, CHAN_STATIC, "weapons/timer.wav" );
}

/*
=====================
CBasePlayer::Spawn

=====================
*/
void CBasePlayer::Spawn( void )
{
	if ( m_pActiveItem )
		m_pActiveItem->Deploy();
}

/*
=====================
CBasePlayer::TeamFortress_SetSpeed

The class's top speed, as the server sets it
=====================
*/
void CBasePlayer::TeamFortress_SetSpeed( void )
{
	float flMaxSpeed;

	// can't move while setting a detpack, or without a class
	if ( ( tfstate & TFSTATE_CANT_MOVE ) || !pev->playerclass )
	{
		pev->velocity = g_vecZero;
		g_engfuncs.pfnSetClientMaxspeed( ENT( pev ), 1 );
		pev->maxspeed = 1;
		return;
	}

	switch ( pev->playerclass )
	{
	case PC_SCOUT:		flMaxSpeed = PC_SCOUT_MAXSPEED; break;
	case PC_SNIPER:		flMaxSpeed = PC_SNIPER_MAXSPEED; break;
	case PC_SOLDIER:	flMaxSpeed = PC_SOLDIER_MAXSPEED; break;
	case PC_DEMOMAN:	flMaxSpeed = PC_DEMOMAN_MAXSPEED; break;
	case PC_MEDIC:		flMaxSpeed = PC_MEDIC_MAXSPEED; break;
	case PC_HVYWEAP:	flMaxSpeed = PC_HVYWEAP_MAXSPEED; break;
	case PC_PYRO:		flMaxSpeed = PC_PYRO_MAXSPEED; break;
	case PC_SPY:		flMaxSpeed = PC_SPY_MAXSPEED; break;
	case PC_ENGINEER:	flMaxSpeed = PC_ENGINEER_MAXSPEED; break;
	case PC_CIVILIAN:	flMaxSpeed = PC_CIVILIAN_MAXSPEED; break;
	default:			flMaxSpeed = 0; break;
	}

	// Snipers aiming walk slowly
	if ( ( tfstate & TFSTATE_AIMING ) && flMaxSpeed > 80 )
		flMaxSpeed = 80;

	pev->maxspeed = flMaxSpeed;
}

/*
=====================
UTIL_TraceLine

Don't actually trace, but act like the trace didn't hit anything.
=====================
*/
void UTIL_TraceLine( const Vector &vecStart, const Vector &vecEnd, IGNORE_MONSTERS igmon, edict_t *pentIgnore, TraceResult *ptr )
{
	memset( ptr, 0, sizeof( *ptr ) );
	ptr->flFraction = 1.0;
}

/*
=====================
UTIL_ParticleBox

For debugging, draw a box around a player made out of particles
=====================
*/
void UTIL_ParticleBox( CBasePlayer *player, float *mins, float *maxs, float life, unsigned char r, unsigned char g, unsigned char b )
{
	int i;
	vec3_t mmin, mmax;

	for ( i = 0; i < 3; i++ )
	{
		mmin[ i ] = player->pev->origin[ i ] + mins[ i ];
		mmax[ i ] = player->pev->origin[ i ] + maxs[ i ];
	}

	gEngfuncs.pEfxAPI->R_ParticleBox( (float *)&mmin, (float *)&mmax, 5.0, 0, 255, 0 );
}

/*
=====================
UTIL_ParticleBoxes

For debugging, draw boxes for other collidable players
=====================
*/
void UTIL_ParticleBoxes( void )
{
	int idx;
	physent_t *pe;
	cl_entity_t *player;
	vec3_t mins, maxs;

	gEngfuncs.pEventAPI->EV_SetUpPlayerPrediction( false, true );

	// Store off the old count
	gEngfuncs.pEventAPI->EV_PushPMStates();

	player = gEngfuncs.GetLocalPlayer();
	// Now add in all of the players.
	gEngfuncs.pEventAPI->EV_SetSolidPlayers ( player->index - 1 );

	for ( idx = 1; idx < 100; idx++ )
	{
		pe = gEngfuncs.pEventAPI->EV_GetPhysent( idx );
		if ( !pe )
			break;

		if ( pe->info >= 1 && pe->info <= gEngfuncs.GetMaxClients() )
		{
			mins = pe->origin + pe->mins;
			maxs = pe->origin + pe->maxs;

			gEngfuncs.pEfxAPI->R_ParticleBox( (float *)&mins, (float *)&maxs, 0, 0, 255, 2.0 );
		}
	}

	gEngfuncs.pEventAPI->EV_PopPMStates();
}

/*
=====================
UTIL_ParticleLine

For debugging, draw a line made out of particles
=====================
*/
void UTIL_ParticleLine( CBasePlayer *player, float *start, float *end, float life, unsigned char r, unsigned char g, unsigned char b )
{
	gEngfuncs.pEfxAPI->R_ParticleLine( start, end, r, g, b, life );
}

/*
=====================
HUD_InitClientWeapons

Set up weapons, player and functions needed to run weapons code client-side.
=====================
*/
void HUD_InitClientWeapons( void )
{
	static int initialized = 0;
	if ( initialized )
		return;

	initialized = 1;

	// Set up pointer ( dummy object )
	gpGlobals = &Globals;

	// Fill in current time ( probably not needed )
	gpGlobals->time = gEngfuncs.GetClientTime();

	// Fake functions
	g_engfuncs.pfnPrecacheModel		= stub_PrecacheModel;
	g_engfuncs.pfnPrecacheSound		= stub_PrecacheSound;
	g_engfuncs.pfnPrecacheEvent		= gEngfuncs.pfnPrecacheEvent;
	g_engfuncs.pfnNameForFunction	= stub_NameForFunction;
	g_engfuncs.pfnSetModel			= stub_SetModel;
	g_engfuncs.pfnSetClientMaxspeed = HUD_SetMaxSpeed;

	// Handled locally
	g_engfuncs.pfnPlaybackEvent		= HUD_PlaybackEvent;
	g_engfuncs.pfnAlertMessage		= AlertMessage;

	// Pass through to engine
	g_engfuncs.pfnRandomFloat		= gEngfuncs.pfnRandomFloat;
	g_engfuncs.pfnRandomLong		= gEngfuncs.pfnRandomLong;

	// Allocate a slot for the local player
	HUD_PrepEntity( &player, NULL, AMMO_NONE );
	player.tfstate = 0;

	// Allocate slot(s) for each weapon that we are going to be predicting
	HUD_PrepEntity( &g_Gun, &player, AMMO_SHELLS );
	HUD_PrepEntity( &g_Super, &player, AMMO_SHELLS );
	HUD_PrepEntity( &g_NG, &player, AMMO_NAILS );
	HUD_PrepEntity( &g_SNG, &player, AMMO_NAILS );
	HUD_PrepEntity( &g_Tranq, &player, AMMO_NAILS );
	g_Tranq.pev->body = 1;
	HUD_PrepEntity( &g_Flame, &player, AMMO_CELLS );
	HUD_PrepEntity( &g_IC, &player, AMMO_ROCKETS );
	HUD_PrepEntity( &g_Rail, &player, AMMO_NAILS );
	HUD_PrepEntity( &g_RPG, &player, AMMO_ROCKETS );
	HUD_PrepEntity( &g_AR, &player, AMMO_SHELLS );
	HUD_PrepEntity( &g_AC, &player, AMMO_SHELLS );
	HUD_PrepEntity( &g_GL, &player, AMMO_ROCKETS );
	HUD_PrepEntity( &g_PL, &player, AMMO_ROCKETS );
	HUD_PrepEntity( &g_Sniper, &player, AMMO_NONE );
	HUD_PrepEntity( &g_Knife, &player, AMMO_NONE );
	HUD_PrepEntity( &g_Spanner, &player, AMMO_NONE );
	HUD_PrepEntity( &g_Medkit, &player, AMMO_NONE );
	HUD_PrepEntity( &g_Crowbar, &player, AMMO_NONE );
	HUD_PrepEntity( &g_Spot, NULL, AMMO_NONE );

	// the rifle starts unzoomed, without its dot
	g_Sniper.m_fAimedDamage = 0;
	g_Sniper.m_fInZoom = 0;
	g_Sniper.m_fNextAimBonus = 0;
	g_Sniper.m_iSpotActive = 0;
	g_Sniper.m_pSpot = NULL;
	g_Spot.pev->effects |= EF_NODRAW;
}

/*
=====================
HUD_WeaponsPostThink

Run Weapon firing code on client
=====================
*/
void HUD_WeaponsPostThink( local_state_s *from, local_state_s *to, usercmd_t *cmd, double time, unsigned int random_seed )
{
	int i;
	int buttonsChanged;
	CBasePlayerWeapon *pWeapon = NULL;
	CBasePlayerWeapon *pCurrent;
	weapon_data_t nulldata, *pfrom, *pto;
	static int lasthealth;

	memset( &nulldata, 0, sizeof( nulldata ) );

	HUD_InitClientWeapons();

	// Get current clock
	gpGlobals->time = time;

	// Fill in data based on selected weapon
	switch ( from->client.m_iId )
	{
	case WEAPON_MEDIKIT:			pWeapon = &g_Medkit; break;
	case WEAPON_SPANNER:			pWeapon = &g_Spanner; break;
	case WEAPON_AXE:				pWeapon = &g_Crowbar; break;
	case WEAPON_SNIPER_RIFLE:		pWeapon = &g_Sniper; break;
	case WEAPON_AUTO_RIFLE:			pWeapon = &g_AR; break;
	case WEAPON_TF_SHOTGUN:			pWeapon = &g_Gun; break;
	case WEAPON_SUPER_SHOTGUN:		pWeapon = &g_Super; break;
	case WEAPON_NAILGUN:			pWeapon = &g_NG; break;
	case WEAPON_SUPER_NAILGUN:		pWeapon = &g_SNG; break;
	case WEAPON_GRENADE_LAUNCHER:	pWeapon = &g_GL; break;
	case WEAPON_FLAMETHROWER:		pWeapon = &g_Flame; break;
	case WEAPON_ROCKET_LAUNCHER:	pWeapon = &g_RPG; break;
	case WEAPON_INCENDIARY:			pWeapon = &g_IC; break;
	case WEAPON_ASSAULT_CANNON:		pWeapon = &g_AC; break;
	case WEAPON_TRANQ:				pWeapon = &g_Tranq; break;
	case WEAPON_LASER:				pWeapon = &g_Rail; break;
	case WEAPON_PIPEBOMB_LAUNCHER:	pWeapon = &g_PL; break;
	case WEAPON_KNIFE:				pWeapon = &g_Knife; break;
	}

	// Store pointer to our destination entity_state_t so we can get our origin, etc. from it
	//  for setting up events on the client
	g_finalstate = to;

	// If we are running events/etc. go ahead and see if we
	//  managed to die between last frame and this one
	// If so, run the appropriate player killed or spawn function
	if ( g_runfuncs )
	{
		if ( to->client.health <= 0 && lasthealth > 0 )
		{
			player.Killed( NULL, NULL, 0 );
		}
		else if ( to->client.health > 0 && lasthealth <= 0 )
		{
			player.Spawn();
		}

		lasthealth = to->client.health;
	}

	// We are not predicting the current weapon, just bow out here.
	if ( !pWeapon )
		return;

	for ( i = 0; i < 32; i++ )
	{
		pCurrent = g_pWpns[ i ];
		if ( !pCurrent )
		{
			continue;
		}

		pfrom = &from->weapondata[ i ];

		pCurrent->m_fInReload			= pfrom->m_fInReload;
		pCurrent->m_fInSpecialReload	= pfrom->m_fInSpecialReload;
		pCurrent->m_flNextReload		= pfrom->m_flNextReload;
		pCurrent->m_flPumpTime			= pfrom->m_flPumpTime;
		pCurrent->m_iWeaponState		= pfrom->m_iWeaponState;
		pCurrent->m_fAimedDamage		= pfrom->m_fAimedDamage;
		pCurrent->m_fNextAimBonus		= pfrom->m_fNextAimBonus;
		pCurrent->m_fInZoom				= pfrom->m_fInZoom;
		pCurrent->m_iClip				= pfrom->m_iClip;
		pCurrent->m_flNextPrimaryAttack	= pfrom->m_flNextPrimaryAttack;
		pCurrent->m_flNextSecondaryAttack = pfrom->m_flNextSecondaryAttack;
		pCurrent->m_flTimeWeaponIdle	= pfrom->m_flTimeWeaponIdle;
	}

	// For random weapon events, use this seed to seed random # generator
	player.random_seed = random_seed;

	// Get old buttons from previous state.
	player.m_afButtonLast = from->playerstate.oldbuttons;

	// Which buttsons chave changed
	buttonsChanged = ( player.m_afButtonLast ^ cmd->buttons );	// These buttons have changed this frame

	// Debounced button codes for pressed/released
	// The changed ones still down are "pressed"
	player.m_afButtonPressed = buttonsChanged & cmd->buttons;
	// The ones not down are "released"
	player.m_afButtonReleased = buttonsChanged & ( ~cmd->buttons );

	// Set player variables that weapons code might check/alter
	player.pev->playerclass = from->playerstate.playerclass;
	player.pev->button = cmd->buttons;

	player.pev->velocity = from->client.velocity;
	player.pev->flags = from->client.flags;

	player.pev->deadflag = from->client.deadflag;
	player.pev->waterlevel = from->client.waterlevel;
	player.pev->maxspeed = from->client.maxspeed;
	player.tfstate = from->client.tfstate;
	player.pev->fov = from->client.fov;
	player.pev->weaponanim = from->client.weaponanim;
	player.pev->viewmodel = from->client.viewmodel;
	player.m_flNextAttack = from->client.m_flNextAttack;

	player.ammo_shells = from->client.ammo_shells;
	player.ammo_nails = from->client.ammo_nails;
	player.ammo_cells = from->client.ammo_cells;
	player.ammo_rockets = from->client.ammo_rockets;

	// Point to current weapon object
	if ( from->client.m_iId )
	{
		player.m_pActiveItem = g_pWpns[ from->client.m_iId ];
	}

	// Don't go firing anything if we have died or are feigning death.
	// Or if we don't have a viewmodel, or we're spectating
	if ( ( player.pev->deadflag != DEAD_FEIGNING ) && !CL_IsDead() && player.pev->viewmodel && !g_iUser1 )
	{
		if ( player.m_flNextAttack <= 0 )
		{
			pWeapon->ItemPostFrame();
		}
	}

	// Assume that we are not going to switch weapons
	to->client.m_iId = from->client.m_iId;

	// Now see if we issued a changeweapon command ( and we're not dead )
	if ( cmd->weaponselect && ( player.pev->deadflag != DEAD_FEIGNING ) )
	{
		// Switched to a different weapon?
		if ( from->weapondata[ cmd->weaponselect ].m_iId == cmd->weaponselect )
		{
			CBasePlayerWeapon *pNew = g_pWpns[ cmd->weaponselect ];
			if ( pNew && ( pNew != pWeapon ) )
			{
				// Put away old weapon
				if ( player.m_pActiveItem )
					player.m_pActiveItem->Holster();

				player.m_pLastItem = player.m_pActiveItem;
				player.m_pActiveItem = pNew;

				// Deploy new weapon
				player.m_pActiveItem->Deploy();

				// Update weapon id so we can predict things correctly.
				to->client.m_iId = cmd->weaponselect;
			}
		}
	}

	HUD_SetLastOrg();

	// Wipe it so we can't use it after this frame
	g_finalstate = NULL;

	// The laser dot: on while the rifle is charging a shot
	if ( g_runfuncs )
	{
		g_laserdot.laserdotactive = 0;
		g_laserdot.laserdotintensity = 0;

		if ( to->client.m_iId == WEAPON_SNIPER_RIFLE && HUD_SpotActive() )
		{
			if ( !CL_IsDead() && ( cmd->buttons & IN_ATTACK ) )
			{
				g_laserdot.laserdotactive = 1;
				g_laserdot.laserdotintensity = (int)( pWeapon->m_fAimedDamage / 4 + 150 );
			}
			else
			{
				g_laserdot.laserdotactive = 0;
			}
		}
	}

	// Copy in results of prediction code
	to->playerstate.playerclass = player.pev->playerclass;
	to->client.viewmodel = player.pev->viewmodel;
	to->client.fov = player.pev->fov;
	to->client.weaponanim = player.pev->weaponanim;
	to->client.ammo_shells = player.ammo_shells;
	to->client.ammo_nails = player.ammo_nails;
	to->client.ammo_cells = player.ammo_cells;
	to->client.ammo_rockets = player.ammo_rockets;
	to->client.m_flNextAttack = player.m_flNextAttack;
	to->client.tfstate = player.tfstate;
	to->client.maxspeed = player.pev->maxspeed;

	// Make sure that weapon animation matches what the game .dll is telling us
	//  over the wire ( fixes some animation glitches )
	if ( g_runfuncs && ( HUD_GetWeaponAnim() != to->client.weaponanim ) )
	{
		int body = 2;

		// the tranquiliser is drawn with the first body
		if ( pWeapon == &g_Tranq )
			body = 1;

		// Force a fixed anim down to viewmodel
		HUD_SendWeaponAnim( to->client.weaponanim, body, 1 );
	}

	for ( i = 0; i < 32; i++ )
	{
		pCurrent = g_pWpns[ i ];

		pto = &to->weapondata[ i ];

		if ( !pCurrent )
		{
			memset( pto, 0, sizeof( weapon_data_t ) );
			continue;
		}

		pto->m_fInReload				= pCurrent->m_fInReload;
		pto->m_fInSpecialReload			= pCurrent->m_fInSpecialReload;
		pto->m_flNextReload				= pCurrent->m_flNextReload;
		pto->m_flPumpTime				= pCurrent->m_flPumpTime;
		pto->m_iWeaponState				= pCurrent->m_iWeaponState;
		pto->m_fAimedDamage				= pCurrent->m_fAimedDamage;
		pto->m_fNextAimBonus			= pCurrent->m_fNextAimBonus;
		pto->m_fInZoom					= pCurrent->m_fInZoom;
		pto->m_iClip					= pCurrent->m_iClip;
		pto->m_flNextPrimaryAttack		= pCurrent->m_flNextPrimaryAttack;
		pto->m_flNextSecondaryAttack	= pCurrent->m_flNextSecondaryAttack;
		pto->m_flTimeWeaponIdle			= pCurrent->m_flTimeWeaponIdle;

		// Decrement weapon counters, server does this at same time ( during post think, after doing everything else )
		pto->m_flNextReload				-= cmd->msec / 1000.0;
		pto->m_fNextAimBonus			-= cmd->msec / 1000.0;
		pto->m_flNextPrimaryAttack		-= cmd->msec / 1000.0;
		pto->m_flNextSecondaryAttack	-= cmd->msec / 1000.0;
		pto->m_flTimeWeaponIdle			-= cmd->msec / 1000.0;

		if ( pto->m_flPumpTime != -9999 )
		{
			pto->m_flPumpTime -= cmd->msec / 1000.0;
			if ( pto->m_flPumpTime < -0.001 )
				pto->m_flPumpTime = -0.001;
		}

		if ( pto->m_fNextAimBonus < -1.0 )
		{
			pto->m_fNextAimBonus = -1.0;
		}

		if ( pto->m_flNextPrimaryAttack < -1.0 )
		{
			pto->m_flNextPrimaryAttack = -1.0;
		}

		if ( pto->m_flNextSecondaryAttack < -0.001 )
		{
			pto->m_flNextSecondaryAttack = -0.001;
		}

		if ( pto->m_flTimeWeaponIdle < -0.001 )
		{
			pto->m_flTimeWeaponIdle = -0.001;
		}

		if ( pto->m_flNextReload < -0.001 )
		{
			pto->m_flNextReload = -0.001;
		}
	}

	// m_flNextAttack is now part of the weapons, but is part of the player instead
	to->client.m_flNextAttack -= cmd->msec / 1000.0;
	if ( to->client.m_flNextAttack < -0.001 )
	{
		to->client.m_flNextAttack = -0.001;
	}
}

/*
=====================
HUD_PostRunCmd

Client calls this during prediction, after it has moved the player and updated any info changed into to->
time is the current client clock based on prediction
cmd is the command that caused the movement, etc
runfuncs is 1 if this is the first time we've predicted this command.  If so, sounds and effects should play, otherwise, they should
be ignored
=====================
*/
void CL_DLLEXPORT HUD_PostRunCmd( struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed )
{
	g_runfuncs = runfuncs;

	if ( cl_lw && cl_lw->value )
	{
		// iuser4 set: the server says not to predict
		if ( !to->client.iuser4 )
			HUD_WeaponsPostThink( from, to, cmd, time, random_seed );
	}
	else
	{
		g_laserdot.laserdotactive = 0;
		to->client.fov = g_lastFOV;
		return;
	}

	// Store of final view angles
	g_lastFOV = to->client.fov;
}
