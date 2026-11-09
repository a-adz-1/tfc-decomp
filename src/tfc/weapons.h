/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
#ifndef WEAPONS_H
#define WEAPONS_H

#ifndef CLIENT_DLL
#include "effects.h"
#else
class CBeam;
class CSprite;
#endif

class CBasePlayer;
extern int gmsgWeapPickup;

void DeactivateSatchels( CBasePlayer *pOwner );

// Contact Grenade / Timed grenade / Satchel Charge
class CGrenade : public CBaseMonster
{
	// Data members: exact layout of the original tfc.so (from DWARF)
public:
	CGrenade();

	BOOL m_bDontPlaySound;
	BOOL m_bDontSpark;
	BOOL m_bDontSmoke;
	float m_flExplosionScale;
	float m_flSmokeScale;
	BOOL m_fRegisteredSound;// whether or not this grenade has issued its DANGER sound to the world sound list yet.
	unsigned short m_usExplode;
	// End of data members

public:
	void Spawn( void );

	typedef enum { SATCHEL_DETONATE = 0, SATCHEL_RELEASE } SATCHELCODE;

	static CGrenade *ShootTimed( entvars_t *pevOwner, Vector vecStart, Vector vecVelocity, float time );
	static CGrenade *ShootContact( entvars_t *pevOwner, Vector vecStart, Vector vecVelocity );
	static CGrenade *ShootSatchelCharge( entvars_t *pevOwner, Vector vecStart, Vector vecVelocity );
	static void UseSatchelCharges( entvars_t *pevOwner, SATCHELCODE code );

	virtual void Explode( Vector vecSrc, Vector vecAim );
	virtual void Explode( TraceResult *pTrace, int bitsDamageType );
	void EXPORT Smoke( void );

	void EXPORT BounceTouch( CBaseEntity *pOther );
	void EXPORT SlideTouch( CBaseEntity *pOther );
	void EXPORT ExplodeTouch( CBaseEntity *pOther );
	void EXPORT DangerSoundThink( void );
	void EXPORT PreDetonate( void );
	void EXPORT Detonate( void );
	void EXPORT DetonateUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void EXPORT TumbleThink( void );

	virtual int	BloodColor( void ) { return DONT_BLEED; }
	virtual void Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib );


	// TFC methods (declarations from tfc.so DWARF)
public:
	virtual BOOL setBirthdayModel();
	virtual void setModel();
	virtual void BounceSound( void );
	BOOL InNoGrenadeZone(Vector);
};


// constant items
#define ITEM_HEALTHKIT		1
#define ITEM_ANTIDOTE		2
#define ITEM_SECURITY		3
#define ITEM_BATTERY		4

#define WEAPON_NONE				0
#define WEAPON_CROWBAR			1
#define	WEAPON_GLOCK			2
#define WEAPON_PYTHON			3
#define WEAPON_MP5				4
#define WEAPON_CHAINGUN			5
#define WEAPON_CROSSBOW			6
#define WEAPON_SHOTGUN			7
#define WEAPON_RPG				8
#define WEAPON_GAUSS			9
#define WEAPON_EGON				10
#define WEAPON_HORNETGUN		11
#define WEAPON_HANDGRENADE		12
#define WEAPON_TRIPMINE			13
#define	WEAPON_SATCHEL			14
#define	WEAPON_SNARK			15

#define WEAPON_ALLWEAPONS		(~(1<<WEAPON_SUIT))

#define WEAPON_SUIT				31	// ?????

#define MAX_WEAPONS			32


#define MAX_NORMAL_BATTERY	100


// weapon weight factors (for auto-switching)   (-1 = noswitch)
#define CROWBAR_WEIGHT		0
#define GLOCK_WEIGHT		10
#define PYTHON_WEIGHT		15
#define MP5_WEIGHT			15
#define SHOTGUN_WEIGHT		15
#define CROSSBOW_WEIGHT		10
#define RPG_WEIGHT			20
#define GAUSS_WEIGHT		20
#define EGON_WEIGHT			20
#define HORNETGUN_WEIGHT	15
#define HANDGRENADE_WEIGHT	5
#define SNARK_WEIGHT		5
#define SATCHEL_WEIGHT		-10
#define TRIPMINE_WEIGHT		-10


// weapon clip/carry ammo capacities
#define URANIUM_MAX_CARRY		100
#define	_9MM_MAX_CARRY			250
#define _357_MAX_CARRY			36
#define BUCKSHOT_MAX_CARRY		125
#define BOLT_MAX_CARRY			50
#define ROCKET_MAX_CARRY		5
#define HANDGRENADE_MAX_CARRY	10
#define SATCHEL_MAX_CARRY		5
#define TRIPMINE_MAX_CARRY		5
#define SNARK_MAX_CARRY			15
#define HORNET_MAX_CARRY		8
#define M203_GRENADE_MAX_CARRY	10

// the maximum amount of ammo each weapon's clip can hold
#define WEAPON_NOCLIP			-1

//#define CROWBAR_MAX_CLIP		WEAPON_NOCLIP
#define GLOCK_MAX_CLIP			17
#define PYTHON_MAX_CLIP			6
#define MP5_MAX_CLIP			50
#define MP5_DEFAULT_AMMO		25
#define SHOTGUN_MAX_CLIP		8
#define CROSSBOW_MAX_CLIP		5
#define RPG_MAX_CLIP			1
#define GAUSS_MAX_CLIP			WEAPON_NOCLIP
#define EGON_MAX_CLIP			WEAPON_NOCLIP
#define HORNETGUN_MAX_CLIP		WEAPON_NOCLIP
#define HANDGRENADE_MAX_CLIP	WEAPON_NOCLIP
#define SATCHEL_MAX_CLIP		WEAPON_NOCLIP
#define TRIPMINE_MAX_CLIP		WEAPON_NOCLIP
#define SNARK_MAX_CLIP			WEAPON_NOCLIP


// the default amount of ammo that comes with each gun when it spawns
#define GLOCK_DEFAULT_GIVE			17
#define PYTHON_DEFAULT_GIVE			6
#define MP5_DEFAULT_GIVE			25
#define MP5_DEFAULT_AMMO			25
#define MP5_M203_DEFAULT_GIVE		0
#define SHOTGUN_DEFAULT_GIVE		12
#define CROSSBOW_DEFAULT_GIVE		5
#define RPG_DEFAULT_GIVE			1
#define GAUSS_DEFAULT_GIVE			20
#define EGON_DEFAULT_GIVE			20
#define HANDGRENADE_DEFAULT_GIVE	5
#define SATCHEL_DEFAULT_GIVE		1
#define TRIPMINE_DEFAULT_GIVE		1
#define SNARK_DEFAULT_GIVE			5
#define HIVEHAND_DEFAULT_GIVE		8

// The amount of ammo given to a player by an ammo item.
#define AMMO_URANIUMBOX_GIVE	20
#define AMMO_GLOCKCLIP_GIVE		GLOCK_MAX_CLIP
#define AMMO_357BOX_GIVE		PYTHON_MAX_CLIP
#define AMMO_MP5CLIP_GIVE		MP5_MAX_CLIP
#define AMMO_CHAINBOX_GIVE		200
#define AMMO_M203BOX_GIVE		2
#define AMMO_BUCKSHOTBOX_GIVE	12
#define AMMO_CROSSBOWCLIP_GIVE	CROSSBOW_MAX_CLIP
#define AMMO_RPGCLIP_GIVE		RPG_MAX_CLIP
#define AMMO_URANIUMBOX_GIVE	20
#define AMMO_SNARKBOX_GIVE		5

// bullet types
typedef	enum
{
	BULLET_NONE = 0,
	BULLET_PLAYER_9MM, // glock
	BULLET_PLAYER_MP5, // mp5
	BULLET_PLAYER_357, // python
	BULLET_PLAYER_BUCKSHOT, // shotgun
	BULLET_PLAYER_CROWBAR, // crowbar swipe
	BULLET_PLAYER_TF_BUCKSHOT, // TFC shotguns
	BULLET_PLAYER_TF_ASSAULT, // TFC assault cannon

	BULLET_MONSTER_9MM,
	BULLET_MONSTER_MP5,
	BULLET_MONSTER_12MM,
} Bullet;


#define ITEM_FLAG_SELECTONEMPTY		1
#define ITEM_FLAG_NOAUTORELOAD		2
#define ITEM_FLAG_NOAUTOSWITCHEMPTY	4
#define ITEM_FLAG_LIMITINWORLD		8
#define ITEM_FLAG_EXHAUSTIBLE		16 // A player can totally exhaust their ammo supply and lose this weapon
#define ITEM_FLAG_NOAUTOSWITCHTO	32

#define WEAPON_IS_ONTARGET 0x40

typedef struct
{
	int		iSlot;
	int		iPosition;
	const char	*pszAmmo1;	// ammo 1 type
	int		iAmmo1;			// max ammo 1
	const char	*pszAmmo2;	// ammo 2 type
	int		iAmmo2;			// max ammo 2
	const char	*pszName;
	int		iMaxClip;
	int		iId;
	int		iFlags;
	int		iWeight;// this value used to determine this weapon's importance in autoselection.
} ItemInfo;

typedef struct
{
	const char *pszName;
	int iId;
} AmmoInfo;

// Items that the player has in their inventory that they can use
class CBasePlayerItem : public CBaseAnimating
{
public:
	virtual void SetObjectCollisionBox( void );

	virtual int		Save( CSave &save );
	virtual int		Restore( CRestore &restore );
	
	static	TYPEDESCRIPTION m_SaveData[];

	virtual int AddToPlayer( CBasePlayer *pPlayer );	// return TRUE if the item you want the item added to the player inventory
	virtual int AddDuplicate( CBasePlayerItem *pItem ) { return FALSE; }	// return TRUE if you want your duplicate removed from world
	void EXPORT DestroyItem( void );
	void EXPORT DefaultTouch( CBaseEntity *pOther );	// default weapon touch
	void EXPORT FallThink ( void );// when an item is first spawned, this think is run to determine when the object has hit the ground.
	void EXPORT Materialize( void );// make a weapon visible and tangible
	void EXPORT AttemptToMaterialize( void );  // the weapon desires to become visible and tangible, if the game rules allow for it
	CBaseEntity* Respawn ( void );// copy a weapon
	void FallInit( void );
	void CheckRespawn( void );
	virtual int iItemSlot( void ) { return 0; }			// return 0 to MAX_ITEMS_SLOTS, used in hud
	virtual int GetItemInfo(ItemInfo *p) { return 0; };	// returns 0 if struct not filled out
	virtual BOOL CanDeploy( void ) { return TRUE; };
	virtual BOOL Deploy( )								// returns is deploy was successful
		 { return TRUE; };

	virtual BOOL CanHolster( void ) { return TRUE; };// can this weapon be put away right now?
	virtual void Holster( int skiplocal = 0 );
	virtual void UpdateItemInfo( void ) { return; };

	virtual void ItemPreFrame( void )	{ return; }		// called each frame by the player PreThink
	virtual void ItemPostFrame( void ) { return; }		// called each frame by the player PostThink

	virtual void Drop( void );
	virtual void Kill( void );
	virtual void AttachToPlayer ( CBasePlayer *pPlayer );

	virtual int PrimaryAmmoIndex() { return -1; };
	virtual int SecondaryAmmoIndex() { return -1; };

	virtual int UpdateClientData( CBasePlayer *pPlayer ) { return 0; }

	virtual CBasePlayerItem *GetWeaponPtr( void ) { return NULL; };

	static ItemInfo ItemInfoArray[ MAX_WEAPONS ];
	static AmmoInfo AmmoInfoArray[ MAX_AMMO_SLOTS ];

	CBasePlayer	*m_pPlayer;
	CBasePlayerItem *m_pNext;
	int		m_iId;												// WEAPON_???


	int			iItemPosition( void ) { return ItemInfoArray[ m_iId ].iPosition; }
	const char	*pszAmmo1( void )	{ return ItemInfoArray[ m_iId ].pszAmmo1; }
	int			iMaxAmmo1( void )	{ return ItemInfoArray[ m_iId ].iAmmo1; }
	const char	*pszAmmo2( void )	{ return ItemInfoArray[ m_iId ].pszAmmo2; }
	int			iMaxAmmo2( void )	{ return ItemInfoArray[ m_iId ].iAmmo2; }
	const char	*pszName( void )	{ return ItemInfoArray[ m_iId ].pszName; }
	int			iMaxClip( void )	{ return ItemInfoArray[ m_iId ].iMaxClip; }
	int			iWeight( void )		{ return ItemInfoArray[ m_iId ].iWeight; }
	int			iFlags( void )		{ return ItemInfoArray[ m_iId ].iFlags; }

	// int		m_iIdPrimary;										// Unique Id for primary ammo
	// int		m_iIdSecondary;										// Unique Id for secondary ammo
};


// inventory items that 
class CBasePlayerWeapon : public CBasePlayerItem
{
	// Data members: exact layout of the original tfc.so (from DWARF)
public:
	int m_iPlayEmptySound;
	int m_fFireOnEmpty;		// True when the gun is empty and the player is still holding down the
	float	m_flNextPrimaryAttack;								// soonest time ItemPostFrame will call PrimaryAttack
	float	m_flNextSecondaryAttack;							// soonest time ItemPostFrame will call SecondaryAttack
	float	m_flTimeWeaponIdle;									// soonest time ItemPostFrame will call WeaponIdle
	float m_flNextReload;
	float m_flPumpTime;
	float m_fReloadTime;
	float m_fAimedDamage;
	float m_fNextAimBonus;
	int m_fInZoom;
	int m_iWeaponState;
	int		m_fInReload;										// Are we in the middle of a reload;
	int		m_fInSpecialReload;									// Are we in the middle of a reload for the shotguns
	int		m_iPrimaryAmmoType;									// "primary" ammo index into players m_rgAmmo[]
	int		m_iSecondaryAmmoType;								// "secondary" ammo index into players m_rgAmmo[]
	int		m_iClip;											// number of shots left in the primary weapon clip, -1 it not used
	int		m_iClientClip;										// the last version of m_iClip sent to hud dll
	int		m_iClientWeaponState;								// the last version of the weapon state sent to hud dll (is current weapon, is on target)
	int		m_iDefaultAmmo;// how much ammo you get when you pick up this weapon as placed by a level designer.
	float	m_flPrevPrimaryAttack;
	float	m_flLastFireTime;
	// End of data members

public:
	virtual int		Save( CSave &save );
	virtual int		Restore( CRestore &restore );
	
	static	TYPEDESCRIPTION m_SaveData[];

	// generic weapon versions of CBasePlayerItem calls
	virtual int AddToPlayer( CBasePlayer *pPlayer );
	virtual int AddDuplicate( CBasePlayerItem *pItem );

	virtual int ExtractAmmo( CBasePlayerWeapon *pWeapon ); //{ return TRUE; };			// Return TRUE if you can add ammo to yourself when picked up
	virtual int ExtractClipAmmo( CBasePlayerWeapon *pWeapon );// { return TRUE; };			// Return TRUE if you can add ammo to yourself when picked up

	virtual int AddWeapon( void ) { ExtractAmmo( this ); return TRUE; };	// Return TRUE if you want to add yourself to the player

	// generic "shared" ammo handlers
	BOOL AddPrimaryAmmo( int iCount, char *szName, int iMaxClip, int iMaxCarry );
	BOOL AddSecondaryAmmo( int iCount, char *szName, int iMaxCarry );

	virtual void UpdateItemInfo( void ) {};	// updates HUD state

							// attack key(s)
	virtual BOOL PlayEmptySound( void );
	virtual void ResetEmptySound( void );

	virtual void SendWeaponAnim( int iAnim, int skiplocal = 1 );  // skiplocal is 1 if client is predicting weapon animations

	virtual BOOL CanDeploy( void );
	virtual BOOL IsUseable( void );
	BOOL DefaultDeploy( char *szViewModel, char *szWeaponModel, int iAnim, char *szAnimExt, int skiplocal = 0 );
	BOOL DefaultReload( int iClipSize, int iAnim, float fDelay );

	virtual void ItemPostFrame( void );	// called each frame by the player PostThink
	// called by CBasePlayerWeapons ItemPostFrame()
	virtual void PrimaryAttack( void ) { return; }				// do "+ATTACK"
	virtual void SecondaryAttack( void ) { return; }			// do "+ATTACK2"
	virtual void Reload( void ) { return; }						// do "+RELOAD"
	virtual void WeaponIdle( void ) { return; }					// called when no buttons pressed
	virtual int UpdateClientData( CBasePlayer *pPlayer );		// sends hud info to client dll, if things have changed
	virtual void RetireWeapon( void );
	virtual BOOL ShouldWeaponIdle( void ) {return FALSE; };
	virtual float GetNextAttackDelay( float delay );
	virtual void Holster( int skiplocal = 0 );
	
	int	PrimaryAmmoIndex(); 
	int	SecondaryAmmoIndex(); 


	virtual CBasePlayerItem *GetWeaponPtr( void ) { return (CBasePlayerItem *)this; };



	
	// hle time creep vars


	// TFC methods (declarations from tfc.so DWARF)
public:
	void DB_LogShots(int32);
};


class CBasePlayerAmmo : public CBaseEntity
{
public:
	virtual void Spawn( void );
	void EXPORT DefaultTouch( CBaseEntity *pOther ); // default weapon touch
	virtual BOOL AddAmmo( CBaseEntity *pOther ) { return TRUE; };

	CBaseEntity* Respawn( void );
	void EXPORT Materialize( void );
};


extern DLL_GLOBAL	short	g_sModelIndexLaser;// holds the index for the laser beam
extern DLL_GLOBAL	const char *g_pModelNameLaser;

extern DLL_GLOBAL	short	g_sModelIndexLaserDot;// holds the index for the laser beam dot
extern DLL_GLOBAL	short	g_sModelIndexFireball;// holds the index for the fireball
extern DLL_GLOBAL	short	g_sModelIndexSmoke;// holds the index for the smoke cloud
extern DLL_GLOBAL	short	g_sModelIndexWExplosion;// holds the index for the underwater explosion
extern DLL_GLOBAL	short	g_sModelIndexBubbles;// holds the index for the bubbles model
extern DLL_GLOBAL	short	g_sModelIndexBloodDrop;// holds the sprite index for blood drops
extern DLL_GLOBAL	short	g_sModelIndexBloodSpray;// holds the sprite index for blood spray (bigger)

extern void ClearMultiDamage(void);
extern void ApplyMultiDamage(entvars_t* pevInflictor, entvars_t* pevAttacker );
extern void AddMultiDamage( entvars_t *pevInflictor, CBaseEntity *pEntity, float flDamage, int bitsDamageType);

extern void DecalGunshot( TraceResult *pTrace, int iBulletType );
extern void SpawnBlood(Vector vecSpot, int bloodColor, float flDamage);
extern int DamageDecal( CBaseEntity *pEntity, int bitsDamageType );
extern void RadiusDamage( Vector vecSrc, entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, float flRadius, int iClassIgnore, int bitsDamageType );

typedef struct 
{
	CBaseEntity		*pEntity;
	float			amount;
	int				type;
} MULTIDAMAGE;

extern MULTIDAMAGE gMultiDamage;


#define LOUD_GUN_VOLUME			1000
#define NORMAL_GUN_VOLUME		600
#define QUIET_GUN_VOLUME		200

#define	BRIGHT_GUN_FLASH		512
#define NORMAL_GUN_FLASH		256
#define	DIM_GUN_FLASH			128

#define BIG_EXPLOSION_VOLUME	2048
#define NORMAL_EXPLOSION_VOLUME	1024
#define SMALL_EXPLOSION_VOLUME	512

#define	WEAPON_ACTIVITY_VOLUME	64

#define VECTOR_CONE_1DEGREES	Vector( 0.00873, 0.00873, 0.00873 )
#define VECTOR_CONE_2DEGREES	Vector( 0.01745, 0.01745, 0.01745 )
#define VECTOR_CONE_3DEGREES	Vector( 0.02618, 0.02618, 0.02618 )
#define VECTOR_CONE_4DEGREES	Vector( 0.03490, 0.03490, 0.03490 )
#define VECTOR_CONE_5DEGREES	Vector( 0.04362, 0.04362, 0.04362 )
#define VECTOR_CONE_6DEGREES	Vector( 0.05234, 0.05234, 0.05234 )
#define VECTOR_CONE_7DEGREES	Vector( 0.06105, 0.06105, 0.06105 )
#define VECTOR_CONE_8DEGREES	Vector( 0.06976, 0.06976, 0.06976 )
#define VECTOR_CONE_9DEGREES	Vector( 0.07846, 0.07846, 0.07846 )
#define VECTOR_CONE_10DEGREES	Vector( 0.08716, 0.08716, 0.08716 )
#define VECTOR_CONE_15DEGREES	Vector( 0.13053, 0.13053, 0.13053 )
#define VECTOR_CONE_20DEGREES	Vector( 0.17365, 0.17365, 0.17365 )

//=========================================================
// CWeaponBox - a single entity that can store weapons
// and ammo. 
//=========================================================
class CWeaponBox : public CBaseEntity
{
	// Data members: exact layout of the original tfc.so (from DWARF)
public:
	CBasePlayerItem	*m_rgpPlayerItems[MAX_ITEM_TYPES];// one slot for each
	float m_flTouchableAt;
	float m_flCreationTime;
	int m_rgiszAmmo[MAX_AMMO_SLOTS];// ammo names
	int	m_rgAmmo[MAX_AMMO_SLOTS];// ammo quantities
	int m_cAmmoTypes;// how many ammo types packed into this box (if packed by a level designer)
	// End of data members

	void Precache( void );
	void Spawn( void );
	void Touch( CBaseEntity *pOther );
	void KeyValue( KeyValueData *pkvd );
	BOOL IsEmpty( void );
	int  GiveAmmo( int iCount, char *szName, int iMax, int *pIndex = NULL );
	void SetObjectCollisionBox( void );

public:
	void EXPORT Kill ( void );
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];

	BOOL HasWeapon( CBasePlayerItem *pCheckItem );
	BOOL PackWeapon( CBasePlayerItem *pWeapon );
	BOOL PackAmmo( int iszName, int iCount );
	



	// TFC methods (declarations from tfc.so DWARF)
public:
	virtual void TeamFortress_TakeEMPBlast(entvars_t *);
};

#ifdef CLIENT_DLL
bool bIsMultiplayer ( void );
void LoadVModel ( char *szViewModel, CBasePlayer *m_pPlayer );
#endif



class CCrowbar : public CBasePlayerWeapon
{
	// Data members: exact layout of the original tfc.so (from DWARF)
public:
	int m_iSwing;
	TraceResult m_trHit;
	// End of data members

public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 1; }
	void EXPORT SwingAgain( void );
	void EXPORT Smack( void );
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack( void );
	int Swing( int fFirst );
	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );

private:
};





class CLaserSpot : public CBaseEntity
{
	void Spawn( void );
	void Precache( void );

	int	ObjectCaps( void ) { return FCAP_DONT_SAVE; }

public:
	void Suspend( float flSuspendTime );
	void EXPORT Revive( void );
	
	static CLaserSpot *CreateSpot( void );
};








class CHandGrenade : public CBasePlayerWeapon
{
	// Data members: exact layout of the original tfc.so (from DWARF)
public:
	float m_flStartThrow;
	float m_flReleaseThrow;
	// End of data members

public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 5; }
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack( void );
	BOOL Deploy( void );
	BOOL CanHolster( void );
	void Holster( void );
	void WeaponIdle( void );
	
};







//=========================================================
// Team Fortress Classic weapons and buildables
// (declarations from tfc.so DWARF, original weapons.h lines 391-1140)
//=========================================================
class CTFGrenadeLauncher;
class CTFRpg;
//
//=========================================================
// original line 391
extern short g_sModelIndexNail;
extern short g_sModelIndexNapalm;
// original line 393
extern short g_sModelIndexPlayerFlame;
// original line 394
extern short g_sModelIndexSaveMe;
// original line 396
extern short g_sModelIndexGrenade;
// original line 397
extern short g_sModelIndexMirvGrenade;
// original line 398
extern short g_sModelIndexNapalmGrenade;
// original line 399
extern short g_sModelIndexNailGrenade;
// original line 514
class CTFGrenade : public CGrenade
{
public:
	int m_iTrail;
	float m_flCreationTime;

	virtual void Spawn();
	virtual void Precache();
	void GrenadeTouch(CBaseEntity *);
	static CTFGrenade * CreateTFGrenade(Vector, Vector, CBaseEntity *, CTFGrenadeLauncher *);
	static CTFGrenade * CreateTFPipebomb(Vector, Vector, CBaseEntity *, CTFGrenadeLauncher *);
	virtual void RadiusDamage(entvars_t *, entvars_t *, float, int, int);
	virtual void setModel();
	void PipebombDetonate();
	virtual void TeamFortress_TakeEMPBlast(entvars_t *);
};

// original line 535
class CTFNailgun : public CBasePlayerWeapon
{
private:
	unsigned short m_usFireNailGun;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual void Reload();
	virtual int iItemSlot() { return 2; }
	virtual int GetItemInfo(ItemInfo *);
	virtual int AddToPlayer(CBasePlayer *);
	virtual BOOL Deploy();
	virtual void PrimaryAttack();
	virtual void SecondaryAttack();
	virtual void WeaponIdle();
};

// original line 555
class CTFSuperNailgun : public CTFNailgun
{
private:
	unsigned short m_usFireSuperNailGun;

public:
	virtual int iItemSlot() { return 4; }
	virtual int GetItemInfo(ItemInfo *);
	virtual void PrimaryAttack();
	virtual BOOL Deploy();
	virtual void Precache();
};

// original line 570
class CTFNailgunNail : public CGrenade
{
private:
	Vector m_vecPreviousVelocity;

public:
	virtual void Spawn();
	virtual void Precache();
	void RailgunNail_Think();
	void NailTouch(CBaseEntity *);
	void EXPORT TranqTouch(CBaseEntity *);
	void RailgunNailTouch(CBaseEntity *);
	static CTFNailgunNail * CreateNail(BOOL, Vector, Vector, CBaseEntity *, CBaseEntity *, BOOL);
	static CTFNailgunNail * CreateSuperNail(Vector, Vector, CBaseEntity *, CBaseEntity *);
	static CTFNailgunNail * CreateTranqNail(Vector, Vector, CBaseEntity *, CBaseEntity *);
	static CTFNailgunNail * CreateRailgunNail(Vector, Vector, CBaseEntity *, CBaseEntity *);
	static CTFNailgunNail * CreateNailGrenNail(Vector, Vector, CBaseEntity *, CBaseEntity *);
};

// original line 590
class CTFRpgRocket : public CGrenade
{
public:
	int m_iTrail;

	virtual void Spawn();
	virtual void Precache();
	void EXPORT RocketTouch(CBaseEntity *);
	static CTFRpgRocket * CreateRpgRocket(Vector, Vector, CBaseEntity *, CTFRpg *);
	virtual void RadiusDamage(entvars_t *, entvars_t *, float, int, int);
};

// original line 617
enum TFTURRET_ANIM
{
	TFTURRET_ANIM_NONE = 0,
	TFTURRET_ANIM_FIRE,
	TFTURRET_ANIM_SPIN
};

// original line 624
class CTFSentrygun : public CBaseMonster
{
public:
	BOOL m_bTurningRight;
	int m_iShardIndex;
	float m_flNextCheck;
	int m_iBaseTurnRate;
	float m_fTurnRate;
	Vector m_vecCurAngles;
	Vector m_vecGoalAngles;
	Vector m_vecCurDishAngles;

	virtual void Spawn();
	virtual void Precache();
	virtual int Classify() { return CLASS_MACHINE; }
	virtual int TakeDamage(entvars_t *, entvars_t *, float, int);
	virtual BOOL FInViewCone(CBaseEntity *);
	virtual int BloodColor() { return DONT_BLEED; }
	virtual BOOL EngineerUse(CBasePlayer *);
	void Upgrade();
	void Remove();
	void SentryRotate();
	void Attack();
	void Sentry_Explode();
	virtual void TeamFortress_TakeEMPBlast(entvars_t *);
	void CheckShield();
	virtual void Killed(entvars_t *, entvars_t *, int);
	BOOL CheckSentry();
	void SetSentryAnim(TFTURRET_ANIM);
	BOOL FindTarget();
	void FoundTarget();
	BOOL ValidTarget(CBaseEntity *);
	int Range(CBaseEntity *);
	BOOL Fire();
	int MoveTurret();
};

// original line 671
class CTFSentrygunBase : public CBaseEntity
{

public:
	virtual void Spawn();
	virtual void Finished();
	void Remove();
	virtual int Classify() { return CLASS_MACHINE; }
	virtual int TakeDamage(entvars_t *, entvars_t *, float, int);
	static CTFSentrygunBase * CreateSentryBase(Vector, Vector, CBaseEntity *);
};

// original line 684
class CTFDispenser : public CBaseMonster
{
public:
	int m_iShardIndex;
	float m_flNextUseTime;
	float m_flInitialUseDelay;
	float m_flNextRefillTime;
	int m_iDestroyed;

	virtual void Spawn();
	virtual void Precache();
	void Dispenser_Explode();
	void DispenserThink();
	void DispenserTouch(CBaseEntity *);
	virtual int Classify() { return CLASS_MACHINE; }
	virtual int BloodColor() { return DONT_BLEED; }
	void Remove();
	virtual void TeamFortress_TakeEMPBlast(entvars_t *);
	virtual void Finished();
	static CTFDispenser * CreateDispenser(Vector, Vector, CBaseEntity *);
	virtual BOOL EngineerUse(CBasePlayer *);
	virtual void Killed(entvars_t *, entvars_t *, int);
	BOOL RefillPlayer(CBasePlayer *);
};

// original line 716
class CTFFlamethrower : public CBasePlayerWeapon
{
private:
	unsigned short m_usFireFlame;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual void Reload();
	virtual int iItemSlot() { return 5; }
	virtual int GetItemInfo(ItemInfo *);
	virtual int AddToPlayer(CBasePlayer *);
	virtual BOOL Deploy();
	virtual BOOL CanHolster();
	virtual void Holster(int);
	virtual void PrimaryAttack();
	virtual void SecondaryAttack();
	virtual void WeaponIdle();
};

// original line 738
class CTFFlamethrowerBurst : public CGrenade
{
public:
	int m_iTrail;

	virtual void Spawn();
	virtual void Precache();
	void BurstTouch(CBaseEntity *);
	static CTFFlamethrowerBurst * CreateBurst(Vector, Vector, CBaseEntity *, CTFFlamethrower *);
};

// original line 749
class CTFIncendiaryC : public CBasePlayerWeapon
{
private:
	unsigned short m_usFireIC;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual void Reload();
	virtual int iItemSlot() { return 4; }
	virtual int GetItemInfo(ItemInfo *);
	virtual int AddToPlayer(CBasePlayer *);
	virtual BOOL Deploy();
	virtual BOOL CanHolster();
	virtual void Holster(int);
	virtual void PrimaryAttack();
	virtual void SecondaryAttack();
	virtual void WeaponIdle();
};

// original line 771
class CTFIncendiaryCRocket : public CGrenade
{
public:
	int m_iTrail;

	virtual void Spawn();
	virtual void Precache();
	void RocketTouch(CBaseEntity *);
	static CTFIncendiaryCRocket * CreateRpgRocket(Vector, Vector, CBaseEntity *, CTFIncendiaryC *);
	virtual void RadiusDamage(entvars_t *, entvars_t *, float, int, int);
};

// original line 783
class CTFShotgun : public CBasePlayerWeapon
{
public:
	int m_iShell;
	int m_iShellsReloaded;
	int m_iMaxClipSize;
	unsigned short m_usReloadShotgun;
	unsigned short m_usPumpShotgun;
private:
	unsigned short m_usFireShotgun;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int GetItemInfo(ItemInfo *);
	virtual int AddToPlayer(CBasePlayer *);
	virtual void PrimaryAttack();
	virtual void SecondaryAttack();
	virtual BOOL Deploy();
	virtual void Reload();
	virtual void WeaponIdle();
	virtual void ItemPostFrame();
};

// original line 809
class CTFSuperShotgun : public CTFShotgun
{
private:
	unsigned short m_usFireSuperShotgun;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual void PrimaryAttack();
	virtual int GetItemInfo(ItemInfo *);
	virtual BOOL Deploy();
};

// original line 822
class CTFTranq : public CBasePlayerWeapon
{
private:
	unsigned short m_usFireTranquilizer;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int iItemSlot() { return 2; }
	virtual int GetItemInfo(ItemInfo *);
	virtual void PrimaryAttack();
	virtual BOOL Deploy();
	virtual void Reload();
	virtual void WeaponIdle();
};

// original line 839
class CTFRailgun : public CBasePlayerWeapon
{
private:
	unsigned short m_usFireRail;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int iItemSlot() { return 2; }
	virtual int GetItemInfo(ItemInfo *);
	virtual void PrimaryAttack();
	virtual BOOL Deploy();
	virtual void Reload();
	virtual void WeaponIdle();
};

// original line 856
class CTFRpg : public CBasePlayerWeapon
{
private:
	unsigned short m_usFireRPG;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual void Reload();
	virtual int iItemSlot() { return 5; }
	virtual int GetItemInfo(ItemInfo *);
	virtual int AddToPlayer(CBasePlayer *);
	virtual BOOL Deploy();
	virtual BOOL CanHolster();
	virtual void Holster(int);
	virtual void PrimaryAttack();
	virtual void SecondaryAttack();
	virtual void WeaponIdle();
};

// original line 878
class CTFAutoRifle : public CBasePlayerWeapon
{
private:
	unsigned short m_usFireAutoRifle;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int iItemSlot() { return 3; }
	virtual int GetItemInfo(ItemInfo *);
	virtual void PrimaryAttack();
	virtual int AddToPlayer(CBasePlayer *);
	virtual BOOL Deploy();
	virtual void Holster(int);
	virtual void Reload();
	virtual void WeaponIdle();
};

// original line 898
class CTFAssaultC : public CBasePlayerWeapon
{
public:
	float m_flNextAnimTime;
	int m_iShell;
private:
	unsigned short m_usWindUp;
	unsigned short m_usWindDown;
	unsigned short m_usFire;
	unsigned short m_usStartSpin;
	unsigned short m_usSpin;
	unsigned short m_usACStart;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int iItemSlot() { return 3; }
	virtual int GetItemInfo(ItemInfo *);
	virtual int AddToPlayer(CBasePlayer *);
	void Fire();
	void Spin();
	void StartSpin();
	void WindUp();
	void WindDown(bool);
	virtual void PrimaryAttack();
	virtual BOOL Deploy();
	virtual void Reload();
	virtual void WeaponIdle();
	virtual void Holster(int);
	virtual BOOL ShouldWeaponIdle() { return TRUE; }
};

// original line 934
class CTFGrenadeLauncher : public CBasePlayerWeapon
{
public:
	int m_iAnim_Deploy;
	int m_iAnim_Holster;
	int m_iAnim_Idle;
	int m_iAnim_ReloadDown;
	int m_iAnim_ReloadUp;
	unsigned short m_usFireGL;

	virtual void Spawn();
	virtual void Precache();
	virtual void Reload();
	virtual int iItemSlot() { return 3; }
	virtual int GetItemInfo(ItemInfo *);
	virtual int AddToPlayer(CBasePlayer *);
	virtual BOOL Deploy();
	virtual void Holster(int);
	virtual void PrimaryAttack();
	virtual void SecondaryAttack();
	virtual void WeaponIdle();
};

// original line 963
class CTFPipebombLauncher : public CTFGrenadeLauncher
{

public:
	virtual void Spawn();
	virtual int iItemSlot() { return 3; }
	virtual void PrimaryAttack();
	virtual int GetItemInfo(ItemInfo *);
};

// original line 972
class CTFSniperRifle : public CBasePlayerWeapon
{
public:
	CLaserSpot *m_pSpot;
	int m_iSpotActive;
private:
	unsigned short m_usFireSniper;
	unsigned short m_usSniperHit;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int iItemSlot() { return 3; }
	virtual int GetItemInfo(ItemInfo *);
	virtual void ItemPostFrame();
	virtual void PrimaryAttack();
	virtual void SecondaryAttack();
	virtual int AddToPlayer(CBasePlayer *);
	virtual BOOL Deploy();
	virtual void Holster(int);
	virtual void Reload();
	virtual void WeaponIdle();
	void UpdateSpot();
};

// original line 999
class CTFAxe : public CCrowbar
{
public:
	int m_iSwing;
	TraceResult m_trHit;
	BOOL m_bHullHit;
	unsigned short m_usAxe;
	unsigned short m_usAxeDecal;
	int classid;

	virtual void Spawn();
	virtual void Precache();
	virtual int iItemSlot() { return 1; }
	void EXPORT Smack();
	virtual BOOL AxeHit(CBaseEntity *, Vector, TraceResult *);
	virtual int GetItemInfo(ItemInfo *);
	virtual void PlayAnim(int);
	virtual void PlaySound(int, float);
	virtual void PlayDecal();
	virtual void PrimaryAttack();
	virtual BOOL Deploy();
	virtual void Holster(int);
	virtual BOOL IsUseable() { return TRUE; }
};

// original line 1028
class CTFKnife : public CTFAxe
{
private:
	unsigned short m_usKnife;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int GetItemInfo(ItemInfo *);
	virtual BOOL Deploy();
	virtual void Holster(int);
	virtual void WeaponIdle();
	virtual void PlayAnim(int);
};

// original line 1043
class CTFSpanner : public CTFAxe
{

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int GetItemInfo(ItemInfo *);
	virtual BOOL Deploy();
	virtual void Holster(int);
	virtual void WeaponIdle();
	virtual void PlayAnim(int);
	virtual BOOL AxeHit(CBaseEntity *, Vector, TraceResult *);
};

// original line 1058
class CTFMedikit : public CTFAxe
{
public:
	unsigned short m_usNormalShot;
	unsigned short m_usSuperShot;
	unsigned short m_usSteamShot;

	virtual void Spawn();
	virtual void Precache();
	virtual int GetItemInfo(ItemInfo *);
	virtual BOOL Deploy();
	virtual void Holster(int);
	virtual void WeaponIdle();
	virtual void PlayAnim(int);
	virtual void PlaySound(int, float);
	virtual void PlayDecal();
	virtual BOOL AxeHit(CBaseEntity *, Vector, TraceResult *);
};

// original line 1107
class CDetpack : public CGrenade
{
private:
	BOOL bTicked;
	BOOL bAlternateLight;
	CSprite *m_pBlinkSprite;

public:
	virtual void Spawn();
	virtual void Precache();
	virtual int Classify() { return CLASS_MACHINE; }
	void DetpackTouch(CBaseEntity *);
	void DetpackThink();
	void DetpackExplode();
	void Remove();
	virtual void TeamFortress_TakeEMPBlast(entvars_t *);
};

// original line 1129
class CTFTeleporter : public CBaseMonster
{
public:
	CBasePlayer *m_pPlayer;
	float m_flInitialUseDelay;
	int m_iType;
	int m_iState;
	int m_iDestroyed;
	int m_iShardIndex;
	float m_flMyNextThink;
	float m_flDamageDelay;

	virtual void Spawn();
	virtual void Precache();
	void Teleporter_Explode();
	void TeleporterThink();
	void TeleporterTouch(CBaseEntity *);
	virtual int Classify() { return CLASS_MACHINE; }
	virtual int BloodColor() { return DONT_BLEED; }
	void Remove();
	virtual void TeamFortress_TakeEMPBlast(entvars_t *);
	virtual void Finished();
	static CTFTeleporter * CreateTeleporter(Vector, Vector, CBaseEntity *, int);
	virtual BOOL EngineerUse(CBasePlayer *);
	virtual void Killed(entvars_t *, entvars_t *, int);
	void TeleporterSend(CBasePlayer *);
	void TeleporterReceive(CBasePlayer *, float);
	void TeleporterKilled();
	BOOL TeleportersReady();
	void TeleporterFadePlayer(int);
	void TeleporterProcessFade();
	void SetTeleporterRings(int);
	void SetTeleporterParticles(int);
	float GetDamageMultiplier();
	CTFTeleporter * FindMatch();
	const Vector & GetTeamColor();
	bool PlayerIsStandingOnTeleporter(CBaseEntity *);
};


#endif // WEAPONS_H
