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
#include "extdll.h"
#include "eiface.h"
#include "util.h"
#include "game.h"

// TFC server cvars (the HL single player skill cvars are gone)
cvar_t	tfc_spam_penalty1 = { "tfc_spam_penalty1", "8.0" };
cvar_t	tfc_spam_penalty2 = { "tfc_spam_penalty2", "2.0" };
cvar_t	tfc_spam_limit = { "tfc_spam_limit", "20.0" };
cvar_t	tfc_autoteam = { "tfc_autoteam", "0.0", FCVAR_SERVER };
cvar_t	tfc_birthday = { "tfc_birthday", "0.0" };
cvar_t	tfc_fragscoring = { "tfc_fragscoring", "0.0" };
cvar_t	tfc_respawndelay = { "tfc_respawndelay", "0.0", FCVAR_SERVER };
cvar_t	tfc_clanbattle = { "tfc_clanbattle", "0.0", FCVAR_SERVER };
cvar_t	tfc_clanbattle_prematch = { "tfc_clanbattle_prematch", "0.0" };
cvar_t	tfc_prematch = { "tfc_prematch", "0.0" };
cvar_t	tfc_clanbattle_ceasefire = { "tfc_clanbattle_ceasefire", "0.0" };
cvar_t	tfc_clanbattle_locked = { "tfc_clanbattle_locked", "0.0", FCVAR_SERVER };
cvar_t	tfc_adminpwd = { "tfc_adminpwd", "", FCVAR_SERVER | FCVAR_PROTECTED };
cvar_t	tfc_balance_teams = { "tfc_balance_teams", "1.0", FCVAR_SERVER };
cvar_t	tfc_balance_scores = { "tfc_balance_scores", "1.0", FCVAR_SERVER };
cvar_t	tfc_autokick_time = { "tfc_autokick_time", "180.0" };
cvar_t	tfc_autokick_kills = { "tfc_autokick_kills", "5.0" };
cvar_t	allow_spectators = { "allow_spectators", "1.0", FCVAR_SERVER };
cvar_t	tfc_spectchat = { "tfc_spectchat", "0.0", FCVAR_SERVER };
cvar_t	tfc_playerid = { "tfc_playerid", "0", FCVAR_SERVER };
cvar_t	displaysoundlist = { "displaysoundlist", "0" };
cvar_t	teamplay = { "mp_teamplay", "0", FCVAR_SERVER };
cvar_t	fraglimit = { "mp_fraglimit", "0", FCVAR_SERVER };
cvar_t	timelimit = { "mp_timelimit", "0", FCVAR_SERVER };
cvar_t	fragsleft = { "mp_fragsleft", "0", FCVAR_SERVER | FCVAR_UNLOGGED };
cvar_t	timeleft = { "mp_timeleft", "0", FCVAR_SERVER | FCVAR_UNLOGGED };
cvar_t	friendlyfire = { "mp_friendlyfire", "0", FCVAR_SERVER };
cvar_t	falldamage = { "mp_falldamage", "0", FCVAR_SERVER };
cvar_t	weaponstay = { "mp_weaponstay", "0", FCVAR_SERVER };
cvar_t	forcerespawn = { "mp_forcerespawn", "1", FCVAR_SERVER };
cvar_t	flashlight = { "mp_flashlight", "0", FCVAR_SERVER };
cvar_t	aimcrosshair = { "mp_autocrosshair", "1", FCVAR_SERVER };
cvar_t	decalfrequency = { "decalfrequency", "30", FCVAR_SERVER };
cvar_t	cr_scout = { "cr_scout", "0", FCVAR_SERVER };
cvar_t	cr_sniper = { "cr_sniper", "0", FCVAR_SERVER };
cvar_t	cr_soldier = { "cr_soldier", "0", FCVAR_SERVER };
cvar_t	cr_demoman = { "cr_demoman", "0", FCVAR_SERVER };
cvar_t	cr_medic = { "cr_medic", "0", FCVAR_SERVER };
cvar_t	cr_hwguy = { "cr_hwguy", "0", FCVAR_SERVER };
cvar_t	cr_pyro = { "cr_pyro", "0", FCVAR_SERVER };
cvar_t	cr_spy = { "cr_spy", "0", FCVAR_SERVER };
cvar_t	cr_engineer = { "cr_engineer", "0", FCVAR_SERVER };
cvar_t	cr_random = { "cr_random", "0", FCVAR_SERVER };
cvar_t	mp_chattime = { "mp_chattime", "10", FCVAR_SERVER };
// Addition: bunnyhop cap (0 standard 1.7 x max speed, 1 the cap at bunnyhop_limit x max speed, 2 uncapped)
cvar_t	bunnyhop_mode = { "bunnyhop_mode", "0", FCVAR_SERVER };
cvar_t	bunnyhop_limit = { "bunnyhop_limit", "1.7", FCVAR_SERVER };
// Addition: gentle team-coloured glow on thrown/fired grenades, and team-coloured sniper dots (both off by default)
cvar_t	sv_grenaderings = { "sv_grenaderings", "0", FCVAR_SERVER };
cvar_t	sv_grenaderings_amount = { "sv_grenaderings_amount", "6", FCVAR_SERVER };
cvar_t	sv_sniperdot_teamcolour = { "sv_sniperdot_teamcolour", "0", FCVAR_SERVER };

// Engine cvars
cvar_t	*g_footsteps = NULL;

// Register cvars here:
void GameDLLInit( void )
{
	CVAR_REGISTER( &tfc_spam_penalty1 );
	CVAR_REGISTER( &tfc_spam_penalty2 );
	CVAR_REGISTER( &tfc_spam_limit );
	CVAR_REGISTER( &tfc_autoteam );
	CVAR_REGISTER( &tfc_birthday );
	CVAR_REGISTER( &tfc_fragscoring );
	CVAR_REGISTER( &tfc_respawndelay );
	CVAR_REGISTER( &tfc_clanbattle );
	CVAR_REGISTER( &tfc_clanbattle_prematch );
	CVAR_REGISTER( &tfc_prematch );
	CVAR_REGISTER( &tfc_clanbattle_ceasefire );
	CVAR_REGISTER( &tfc_clanbattle_locked );
	CVAR_REGISTER( &tfc_adminpwd );
	CVAR_REGISTER( &tfc_balance_teams );
	CVAR_REGISTER( &tfc_balance_scores );
	CVAR_REGISTER( &tfc_autokick_time );
	CVAR_REGISTER( &tfc_autokick_kills );
	CVAR_REGISTER( &allow_spectators );
	CVAR_REGISTER( &tfc_spectchat );
	CVAR_REGISTER( &tfc_playerid );
	CVAR_REGISTER( &displaysoundlist );
	CVAR_REGISTER( &teamplay );
	CVAR_REGISTER( &fraglimit );
	CVAR_REGISTER( &timelimit );
	CVAR_REGISTER( &fragsleft );
	CVAR_REGISTER( &timeleft );
	CVAR_REGISTER( &friendlyfire );
	CVAR_REGISTER( &falldamage );
	CVAR_REGISTER( &weaponstay );
	CVAR_REGISTER( &forcerespawn );
	CVAR_REGISTER( &flashlight );
	CVAR_REGISTER( &aimcrosshair );
	CVAR_REGISTER( &decalfrequency );
	CVAR_REGISTER( &cr_scout );
	CVAR_REGISTER( &cr_sniper );
	CVAR_REGISTER( &cr_soldier );
	CVAR_REGISTER( &cr_demoman );
	CVAR_REGISTER( &cr_medic );
	CVAR_REGISTER( &cr_hwguy );
	CVAR_REGISTER( &cr_pyro );
	CVAR_REGISTER( &cr_spy );
	CVAR_REGISTER( &cr_engineer );
	CVAR_REGISTER( &cr_random );
	CVAR_REGISTER( &mp_chattime );
	CVAR_REGISTER( &bunnyhop_mode );
	CVAR_REGISTER( &bunnyhop_limit );
	CVAR_REGISTER( &sv_grenaderings );
	CVAR_REGISTER( &sv_grenaderings_amount );
	CVAR_REGISTER( &sv_sniperdot_teamcolour );

	g_footsteps = CVAR_GET_POINTER( "mp_footsteps" );
}

// TFC: game shutdown hook (NEW_DLL_FUNCTIONS)
void GameDLLShutdown( void )
{
}
