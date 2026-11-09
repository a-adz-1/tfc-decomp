/***
*
*	Team Fortress Classic: map scripting (goals, goal items, timer goals,
*	team spawn points, team checks, results, item carrying, end rounds)
*
*	Reconstructed from tfc.so (legacy), DWARF-guided. The logic follows
*	QuakeWorld TF's tfortmap.qc.
*
****/

#include <time.h>

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "player.h"
#include "weapons.h"
#include "gamerules.h"
#include "shake.h"
#include "tf_defs.h"

char *g_szStates[4] = { "Active", "Inactive", "Removed", "Delayed" };

extern int g_iSkillLevel;

void InactivateGoal( CBaseEntity *Goal );
void RestoreGoal( CBaseEntity *Goal );
void InactivateSpawn( CBaseEntity *Spawn );
void ActivateSpawn( CBaseEntity *Spawn );
BOOL AllGoalsInState( int iGroupNo, int iState );
BOOL HasItemFromGroup( CBaseEntity *AP, int iGroupNo );
BOOL IsAffectedBy( CBaseEntity *Goal, CBasePlayer *Player, CBasePlayer *AP );
void Apply_Results( CBaseEntity *Goal, CBasePlayer *Player, CBasePlayer *AP, BOOL bAddBonuses );
void RemoveResults( CBaseEntity *Goal, CBasePlayer *pPlayer );
BOOL APMeetsCriteria( CBaseEntity *Goal, CBaseEntity *AP );
void SetupRespawn( CBaseEntity *pGoal );
BOOL ShouldActivate( CBaseEntity *Goal, CBaseEntity *AP );
void DoItemGroupWork( CBaseEntity *Item, CBasePlayer *AP );
void DoTriggerWork( CBaseEntity *Goal, CBasePlayer *AP );
void ParseTFDetect( CBaseEntity *AD );
void EndRound( CBaseEntity *pGoal );

LINK_ENTITY_TO_CLASS( info_player_teamspawn, CTFSpawn );
LINK_ENTITY_TO_CLASS( info_tfdetect, CTFDetect );
LINK_ENTITY_TO_CLASS( info_tfgoal, CTFGoal );
LINK_ENTITY_TO_CLASS( info_tfgoal_timer, CTFTimerGoal );
LINK_ENTITY_TO_CLASS( item_tfgoal, CTFGoalItem );
LINK_ENTITY_TO_CLASS( info_tf_teamcheck, CTeamCheck );
LINK_ENTITY_TO_CLASS( info_tf_teamset, CTeamSet );

// Short names
LINK_ENTITY_TO_CLASS( i_t_t, CTFTimerGoal );
LINK_ENTITY_TO_CLASS( i_t_g, CTFGoal );
LINK_ENTITY_TO_CLASS( i_p_t, CTFSpawn );

// ex_skill_min/max: only exist on some skill levels (-1 = no limit)
BOOL CBaseEntity::CheckExistence( void )
{
	if ( ex_skill_min == -1 && g_iSkillLevel < 0 )
		return FALSE;
	if ( ex_skill_max == -1 && g_iSkillLevel > 0 )
		return FALSE;

	if ( ex_skill_min && ex_skill_min != -1 && g_iSkillLevel < ex_skill_min )
		return FALSE;
	if ( ex_skill_max && ex_skill_max != -1 && g_iSkillLevel > ex_skill_max )
		return FALSE;

	return TRUE;
}

//=========================================================
// Map keys. Split in three because one function got too big.
//=========================================================
void CBaseEntity::KeyValue( KeyValueData *pkvd )
{
	if ( FStrEq( pkvd->szKeyName, "goal_no" ) )
	{
		goal_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "mdl" ) )
	{
		pev->model = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "group_no" ) )
	{
		group_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team_no" ) )
	{
		team_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "playerclass" ) )
	{
		pev->playerclass = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "items_allowed" ) )
	{
		items_allowed = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "goal_state" ) )
	{
		goal_state = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "items" ) )
	{
		items = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "owned_by" ) )
	{
		owned_by = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "armorclass" ) )
	{
		armorclass = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "goal_activation" ) || FStrEq( pkvd->szKeyName, "g_a" ) )
	{
		goal_activation = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "goal_effects" ) || FStrEq( pkvd->szKeyName, "g_e" ) )
	{
		goal_effects = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "goal_result" ) )
	{
		goal_result = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "goal_group" ) )
	{
		goal_group = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "else_goal" ) )
	{
		else_goal = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "if_goal_is_active" ) )
	{
		if_goal_is_active = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "if_goal_is_inactive" ) )
	{
		if_goal_is_inactive = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "if_goal_is_removed" ) )
	{
		if_goal_is_removed = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "if_group_is_active" ) )
	{
		if_group_is_active = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "if_group_is_inactive" ) )
	{
		if_group_is_inactive = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "if_group_is_removed" ) )
	{
		if_group_is_removed = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "search_time" ) )
	{
		search_time = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "t_length" ) )
	{
		t_length = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "activate_goal_no" ) )
	{
		activate_goal_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "inactivate_goal_no" ) )
	{
		inactivate_goal_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "remove_goal_no" ) || FStrEq( pkvd->szKeyName, "rv_g" ) )
	{
		remove_goal_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "restore_goal_no" ) || FStrEq( pkvd->szKeyName, "rs_g" ) )
	{
		restore_goal_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "activate_group_no" ) )
	{
		activate_group_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "inactivate_group_no" ) )
	{
		inactivate_group_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "remove_group_no" ) || FStrEq( pkvd->szKeyName, "rv_gr" ) )
	{
		remove_group_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "restore_group_no" ) || FStrEq( pkvd->szKeyName, "rs_gr" ) )
	{
		restore_group_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "goal_min" ) )
	{
		Vector tmp;
		UTIL_StringToVector( (float *)tmp, pkvd->szValue );
		if ( tmp != g_vecZero )
			goal_min = tmp;
	}
	else if ( FStrEq( pkvd->szKeyName, "goal_max" ) )
	{
		Vector tmp;
		UTIL_StringToVector( (float *)tmp, pkvd->szValue );
		if ( tmp != g_vecZero )
			goal_max = tmp;
	}
	else if ( FStrEq( pkvd->szKeyName, "has_item_from_group" ) || FStrEq( pkvd->szKeyName, "h_i_g" ) )
	{
		has_item_from_group = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "hasnt_item_from_group" ) || FStrEq( pkvd->szKeyName, "hn_i_g" ) )
	{
		hasnt_item_from_group = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "remove_item_group" ) || FStrEq( pkvd->szKeyName, "r_i_g" ) )
	{
		remove_item_group = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "return_item_no" ) )
	{
		return_item_no = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "if_item_has_moved" ) )
	{
		if_item_has_moved = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "if_item_hasnt_moved" ) )
	{
		if_item_hasnt_moved = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "remove_spawnpoint" ) )
	{
		remove_spawnpoint = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "restore_spawnpoint" ) )
	{
		restore_spawnpoint = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "remove_spawngroup" ) || FStrEq( pkvd->szKeyName, "rv_s_h" ) )
	{
		remove_spawngroup = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "restore_spawngroup" ) || FStrEq( pkvd->szKeyName, "rs_s_h" ) )
	{
		restore_spawngroup = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "display_item_status1" ) )
	{
		display_item_status[0] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "display_item_status2" ) )
	{
		display_item_status[1] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "display_item_status3" ) )
	{
		display_item_status[2] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "display_item_status4" ) )
	{
		display_item_status[3] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team_str_home" ) || FStrEq( pkvd->szKeyName, "t_s_g" ) )
	{
		team_str_home = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team_str_moved" ) || FStrEq( pkvd->szKeyName, "t_s_m" ) )
	{
		team_str_moved = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team_str_carried" ) || FStrEq( pkvd->szKeyName, "t_s_c" ) )
	{
		team_str_carried = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "non_team_str_home" ) || FStrEq( pkvd->szKeyName, "t_s_h" ) )
	{
		non_team_str_home = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "non_team_str_moved" ) )
	{
		non_team_str_moved = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "non_team_str_carried" ) || FStrEq( pkvd->szKeyName, "n_s_c" ) )
	{
		non_team_str_carried = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "ex_skill_min" ) )
	{
		ex_skill_min = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "ex_skill_max" ) )
	{
		ex_skill_max = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "increase_team1" ) )
	{
		increase_team[0] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "increase_team2" ) )
	{
		increase_team[1] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "increase_team3" ) )
	{
		increase_team[2] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "increase_team4" ) )
	{
		increase_team[3] = atoi( pkvd->szValue );
	}
	else
	{
		KeyValuePartTwo( pkvd );
		return;
	}

	pkvd->fHandled = TRUE;
}

void CBaseEntity::KeyValuePartTwo( KeyValueData *pkvd )
{
	if ( FStrEq( pkvd->szKeyName, "wait" ) )
	{
		wait = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "increase_team" ) )
	{
		count = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "axhitme" ) )
	{
		axhitme = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "pausetime" ) || FStrEq( pkvd->szKeyName, "delay" ) )
	{
		drop_time = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "attack_finished" ) )
	{
		attack_finished = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "distance" ) )
	{
		distance = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "killtarget" ) )
	{
		killtarget = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "noise4" ) )
	{
		noise4 = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "broadcast" ) || FStrEq( pkvd->szKeyName, "b_b" ) )
	{
		broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team_broadcast" ) || FStrEq( pkvd->szKeyName, "b_t" ) )
	{
		team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "speak" ) )
	{
		speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "AP_speak" ) )
	{
		AP_speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team_speak" ) )
	{
		team_speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "owners_team_speak" ) )
	{
		owners_team_speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "non_owners_team_speak" ) )
	{
		non_owners_team_speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "non_team_broadcast" ) || FStrEq( pkvd->szKeyName, "b_n" ) )
	{
		non_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "non_team_speak" ) )
	{
		non_team_speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "owners_team_broadcast" ) || FStrEq( pkvd->szKeyName, "b_o" ) )
	{
		owners_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "non_owners_team_broadcast" ) )
	{
		non_owners_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "netname_broadcast" ) || FStrEq( pkvd->szKeyName, "n_b" ) )
	{
		netname_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "netname_team_broadcast" ) || FStrEq( pkvd->szKeyName, "n_t" ) )
	{
		netname_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "netname_non_team_broadcast" ) || FStrEq( pkvd->szKeyName, "n_n" ) )
	{
		netname_non_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "netname_owners_team_broadcast" ) || FStrEq( pkvd->szKeyName, "n_o" ) )
	{
		netname_owners_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team_drop" ) || FStrEq( pkvd->szKeyName, "d_t" ) )
	{
		team_drop = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "non_team_drop" ) || FStrEq( pkvd->szKeyName, "d_n" ) )
	{
		non_team_drop = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "netname_team_drop" ) || FStrEq( pkvd->szKeyName, "d_n_t" ) )
	{
		netname_team_drop = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "netname_non_team_drop" ) || FStrEq( pkvd->szKeyName, "d_n_n" ) )
	{
		netname_non_team_drop = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "all_active" ) )
	{
		all_active = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "delay_time" ) )
	{
		delay_time = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "ammo_shells" ) || FStrEq( pkvd->szKeyName, "a_s" ) )
	{
		ammo_shells = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "ammo_nails" ) || FStrEq( pkvd->szKeyName, "a_n" ) )
	{
		ammo_nails = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "ammo_rockets" ) || FStrEq( pkvd->szKeyName, "a_r" ) )
	{
		ammo_rockets = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "ammo_cells" ) || FStrEq( pkvd->szKeyName, "a_c" ) )
	{
		ammo_cells = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "ammo_medikit" ) )
	{
		ammo_medikit = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "ammo_detpack" ) )
	{
		ammo_detpack = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "no_grenades_1" ) )
	{
		no_grenades_1 = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "no_grenades_2" ) )
	{
		no_grenades_2 = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "maxammo_shells" ) )
	{
		maxammo_shells = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "maxammo_nails" ) )
	{
		maxammo_nails = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "maxammo_rockets" ) )
	{
		maxammo_rockets = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "maxammo_cells" ) )
	{
		maxammo_cells = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "maxammo_medikit" ) )
	{
		maxammo_medikit = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "maxammo_detpack" ) )
	{
		maxammo_detpack = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team1_allies" ) )
	{
		teamallies[1] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team2_allies" ) )
	{
		teamallies[2] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team3_allies" ) )
	{
		teamallies[3] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team4_allies" ) )
	{
		teamallies[4] = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "invincible_finished" ) )
	{
		invincible_finished = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "invisible_finished" ) )
	{
		invisible_finished = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "super_damage_finished" ) )
	{
		super_damage_finished = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "last_impulse" ) )
	{
		last_impulse = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "radsuit_finished" ) )
	{
		radsuit_finished = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "deathtype" ) )
	{
		deathtype = ALLOC_STRING( pkvd->szValue );
	}
	// info_tfdetect keeps the team names in the speak fields
	else if ( FStrEq( pkvd->szKeyName, "team1_name" ) )
	{
		speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team2_name" ) )
	{
		AP_speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team3_name" ) )
	{
		team_speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "team4_name" ) )
	{
		owners_team_speak = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "speed_reduction" ) )
	{
		speed_reduction = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_time" ) )
	{
		m_flEndRoundTime = atof( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_team1" ) )
	{
		m_iszEndRoundMsg_Team1 = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_team2" ) )
	{
		m_iszEndRoundMsg_Team2 = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_team3" ) )
	{
		m_iszEndRoundMsg_Team3 = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_team4" ) )
	{
		m_iszEndRoundMsg_Team4 = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_win_team1" ) )
	{
		m_iszEndRoundMsg_Team1_Win = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_win_team2" ) )
	{
		m_iszEndRoundMsg_Team2_Win = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_win_team3" ) )
	{
		m_iszEndRoundMsg_Team3_Win = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_win_team4" ) )
	{
		m_iszEndRoundMsg_Team4_Win = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_lose_team1" ) )
	{
		m_iszEndRoundMsg_Team1_Lose = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_lose_team2" ) )
	{
		m_iszEndRoundMsg_Team2_Lose = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_lose_team3" ) )
	{
		m_iszEndRoundMsg_Team3_Lose = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_lose_team4" ) )
	{
		m_iszEndRoundMsg_Team4_Lose = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "teamcheck" ) )
	{
		teamcheck = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "owned_by_teamcheck" ) )
	{
		owned_by_teamcheck = ALLOC_STRING( pkvd->szValue );
	}
	// info_tfdetect keeps the number of teams in last_impulse
	else if ( FStrEq( pkvd->szKeyName, "number_of_teams" ) )
	{
		last_impulse = atoi( pkvd->szValue );
	}
	else
	{
		KeyValuePartThree( pkvd );
		return;
	}

	pkvd->fHandled = TRUE;
}

void CBaseEntity::KeyValuePartThree( KeyValueData *pkvd )
{
	if ( FStrEq( pkvd->szKeyName, "endround_owned_by" ) )
	{
		m_iszEndRoundMsg_OwnedBy = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "endround_non_owned_by" ) )
	{
		m_iszEndRoundMsg_NonOwnedBy = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_broadcast" ) || FStrEq( pkvd->szKeyName, "org_b_b" ) )
	{
		org_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_team_broadcast" ) || FStrEq( pkvd->szKeyName, "org_b_t" ) )
	{
		org_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_message" ) )
	{
		org_message = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_owners_team_broadcast" ) || FStrEq( pkvd->szKeyName, "org_b_o" ) )
	{
		org_owners_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_non_owners_team_broadcast" ) )
	{
		org_non_owners_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_non_team_broadcast" ) || FStrEq( pkvd->szKeyName, "org_b_n" ) )
	{
		org_non_team_broadcast = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_noise3" ) )
	{
		org_noise3 = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_noise4" ) )
	{
		org_noise4 = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_team_drop" ) || FStrEq( pkvd->szKeyName, "org_d_t" ) )
	{
		org_team_drop = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "org_non_team_drop" ) || FStrEq( pkvd->szKeyName, "org_d_n" ) )
	{
		org_non_team_drop = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "increase_team_owned_by" ) )
	{
		increase_team_owned_by = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "replacement_model" ) )
	{
		replacement_model = ALLOC_STRING( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "replacement_model_body" ) )
	{
		replacement_model_body = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "replacement_model_skin" ) )
	{
		replacement_model_skin = atoi( pkvd->szValue );
	}
	else if ( FStrEq( pkvd->szKeyName, "replacement_model_flags" ) )
	{
		replacement_model_flags = atoi( pkvd->szValue );
	}
	else
	{
		return;
	}

	pkvd->fHandled = TRUE;
}

// Team number of the info_tf_teamcheck with this targetname
int GetTeamCheckTeam( const char *pTargetName )
{
	edict_t *pTarget = FIND_ENTITY_BY_TARGETNAME( NULL, pTargetName );
	if ( FNullEnt( pTarget ) )
		return 0;

	CBaseEntity *pEntity = CBaseEntity::Instance( pTarget );
	if ( !strcmp( STRING( pEntity->pev->classname ), "info_tf_teamcheck" ) )
		return pEntity->team_no;

	return 0;
}

//=========================================================
// info_player_teamspawn
//=========================================================
void CTFSpawn::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	if ( ( team_no < 1 || team_no > 4 ) && !teamcheck )
	{
		ALERT( at_console, "Teamspawnpoint with an invalid team_no of %d\n", team_no );
		return;
	}

	// The map's number of teams comes from its spawn points
	if ( team_no > number_of_teams )
		number_of_teams = team_no;

	pev->classname = pev->netname = MAKE_STRING( "info_player_teamspawn" );
}

void CTFSpawn::Activate( void )
{
	m_pTeamCheck = NULL;

	edict_t *pTarget = FIND_ENTITY_BY_TARGETNAME( NULL, STRING( teamcheck ) );
	if ( FNullEnt( pTarget ) )
		return;

	CBaseEntity *pEntity = CBaseEntity::Instance( pTarget );
	if ( !strcmp( STRING( pEntity->pev->classname ), "info_tf_teamcheck" ) )
		m_pTeamCheck = pEntity;
}

BOOL CTFSpawn::CheckTeam( int iTeamNo )
{
	if ( team_no )
		return team_no == iTeamNo;

	if ( m_pTeamCheck )
		return iTeamNo == m_pTeamCheck->team_no;

	return FALSE;
}

//=========================================================
// info_tfgoal
//=========================================================
void CTFGoal::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	pev->classname = MAKE_STRING( "info_tfgoal" );

	if ( pev->model )
	{
		// Brush models are invisible triggers
		char *pModel = (char *)STRING( pev->model );
		if ( *pModel == '*' )
			pev->effects |= EF_NODRAW;

		PRECACHE_MODEL( pModel );
		SET_MODEL( ENT( pev ), STRING( pev->model ) );
	}

	if ( pev->noise )
		PRECACHE_SOUND( (char *)STRING( pev->noise ) );

	PRECACHE_SOUND( "items/protect.wav" );
	PRECACHE_SOUND( "items/protect2.wav" );
	PRECACHE_SOUND( "items/protect3.wav" );
	PRECACHE_SOUND( "FVox/HEV_logon.wav" );
	PRECACHE_SOUND( "FVox/hev_shutdown.wav" );
	PRECACHE_SOUND( "items/inv1.wav" );
	PRECACHE_SOUND( "items/inv2.wav" );
	PRECACHE_SOUND( "items/inv3.wav" );
	PRECACHE_SOUND( "items/damage.wav" );
	PRECACHE_SOUND( "items/damage2.wav" );
	PRECACHE_SOUND( "items/damage3.wav" );

	pev->solid = SOLID_TRIGGER;

	if ( !goal_state )
		goal_state = TFGS_INACTIVE;

	if ( goal_min != g_vecZero && goal_max != g_vecZero )
		UTIL_SetSize( pev, goal_min, goal_max );

	UTIL_SetOrigin( pev, pev->origin );

	StartGoal();
}

// Point goals touch over a 48x48x16 box; brush goals over a cube
// enclosing the model
void CTFGoal::SetObjectCollisionBox( void )
{
	char *pModel = (char *)STRING( pev->model );

	if ( *pModel == '*' )
	{
		float max, v;
		int i;

		max = 0;
		for ( i = 0; i < 3; i++ )
		{
			v = fabs( ( (float *)pev->mins )[i] );
			if ( v > max )
				max = v;
			v = fabs( ( (float *)pev->maxs )[i] );
			if ( v > max )
				max = v;
		}

		for ( i = 0; i < 3; i++ )
		{
			( (float *)pev->absmin )[i] = ( (float *)pev->origin )[i] - max;
			( (float *)pev->absmax )[i] = ( (float *)pev->origin )[i] + max;
		}

		pev->absmin.x -= 1;
		pev->absmin.y -= 1;
		pev->absmin.z -= 1;
		pev->absmax.x += 1;
		pev->absmax.y += 1;
		pev->absmax.z += 1;
	}
	else
	{
		pev->absmin = pev->origin + Vector( -24, -24, 0 );
		pev->absmax = pev->origin + Vector( 24, 24, 16 );
	}
}

//=========================================================
// info_tfgoal_timer
//=========================================================
void CTFTimerGoal::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	CTFGoal::Spawn();
	pev->classname = MAKE_STRING( "info_tfgoal_timer" );

	if ( search_time <= 0 )
	{
		ALERT( at_console, "Timer Goal %s created with no specified time.\n", STRING( pev->netname ) );
		dremove( this );
		return;
	}

	pev->solid = SOLID_NOT;
}

//=========================================================
// item_tfgoal
//=========================================================
void CTFGoalItem::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	pev->classname = MAKE_STRING( "item_tfgoal" );

	if ( pev->model )
	{
		PRECACHE_MODEL( (char *)STRING( pev->model ) );
		SET_MODEL( ENT( pev ), STRING( pev->model ) );

		pev->sequence = LookupSequence( "not_carried" );
		if ( pev->sequence != -1 )
		{
			ResetSequenceInfo();
			pev->frame = 0;
		}
	}

	PRECACHE_SOUND( "items/itembk2.wav" );
	if ( pev->noise )
		PRECACHE_SOUND( (char *)STRING( pev->noise ) );

	if ( !goal_state )
		goal_state = TFGS_INACTIVE;

	if ( goal_activation & TFGI_SOLID )
	{
		pev->solid = SOLID_BBOX;
		if ( goal_min == g_vecZero )
			goal_min = Vector( -16, -16, -24 );
		if ( goal_max == g_vecZero )
			goal_max = Vector( 16, 16, 32 );
	}
	else
	{
		pev->solid = SOLID_TRIGGER;
	}

	if ( !pev->netname )
		pev->netname = MAKE_STRING( "goalitem" );

	if ( drop_time <= 0 )
		drop_time = 60;

	UTIL_SetSize( pev, goal_min, goal_max );
	UTIL_SetOrigin( pev, pev->origin );

	SetTouch( &CBaseEntity::item_tfgoal_touch );
	StartItem();
}

void CTFGoalItem::StartItem( void )
{
	SetThink( &CTFGoalItem::PlaceItem );
	pev->nextthink = gpGlobals->time + 0.2;

	if ( goal_state == TFGS_REMOVED )
		RemoveGoal( this );
}

void CTFGoalItem::PlaceItem( void )
{
	pev->velocity = g_vecZero;

	if ( goal_activation & TFGI_DROPTOGROUND )
	{
		pev->movetype = MOVETYPE_TOSS;
		pev->origin.z += 6;
		UTIL_SetOrigin( pev, pev->origin );

		if ( !DROP_TO_FLOOR( ENT( pev ) ) )
		{
			ALERT( at_error, "TF GoalItem %s fell out of level at %f,%f,%f", STRING( pev->netname ), pev->origin.x, pev->origin.y, pev->origin.z );
			UTIL_Remove( this );
			return;
		}
	}

	pev->movetype = MOVETYPE_NONE;
	pev->oldorigin = pev->origin;

	// Glow in the owning team's colour
	if ( goal_activation & TFGI_ITEMGLOWS )
	{
		pev->renderfx = kRenderFxGlowShell;

		if ( owned_by_teamcheck )
			owned_by = GetTeamCheckTeam( STRING( owned_by_teamcheck ) );

		if ( owned_by >= 1 && owned_by <= 4 )
			pev->rendercolor = rgbcolors[owned_by];
		else
			pev->rendercolor = rgbcolors[0];

		pev->renderamt = 100;
	}

	{
		// Each item gets its own bit, for "items_allowed" checks
		static int item_list_bit = 1;
		item_list = item_list_bit;
		item_list_bit *= 2;
	}
}

void CTFGoal::StartGoal( void )
{
	m_bAddBonuses = FALSE;
	SetThink( &CTFGoal::PlaceGoal );
	pev->nextthink = gpGlobals->time + 0.2;

	if ( goal_state == TFGS_REMOVED )
		RemoveGoal( this );
}

void CTFGoal::PlaceGoal( void )
{
	if ( FClassnameIs( pev, "info_tfgoal_timer" ) )
	{
		SetThink( &CBaseEntity::tfgoal_timer_tick );
		pev->nextthink = gpGlobals->time + search_time;
	}
	else if ( goal_activation & TFGA_TOUCH )
	{
		SetTouch( &CBaseEntity::tfgoal_touch );
	}

	pev->classname = MAKE_STRING( "info_tfgoal" );

	if ( goal_activation & TFGA_DROPTOGROUND )
	{
		pev->movetype = MOVETYPE_TOSS;
		pev->origin.z += 6;
		UTIL_SetOrigin( pev, pev->origin );

		if ( !DROP_TO_FLOOR( ENT( pev ) ) )
		{
			ALERT( at_error, "TF Goal %s fell out of level at %f,%f,%f", STRING( pev->netname ), pev->origin.x, pev->origin.y, pev->origin.z );
			UTIL_Remove( this );
			return;
		}
	}

	pev->movetype = MOVETYPE_NONE;
	pev->velocity = g_vecZero;
	pev->oldorigin = pev->origin;
}

void CTFDetect::Spawn( void )
{
}

//=========================================================
// Finding goals, items and spawn points by number
//=========================================================
CBaseEntity *Finditem( int ino )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->goal_no == ino )
			return pEnt;

		pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
	}

	ALERT( at_console, "Could not find an item with a goal_no of %d.\n", ino );
	return NULL;
}

CBaseEntity *Findgoal( int gno )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "info_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->goal_no == gno )
			return pEnt;

		pEnt = UTIL_FindEntityByClassname( pEnt, "info_tfgoal" );
	}

	ALERT( at_console, "Could not find a goal with a goal_no of %d.\n", gno );
	return NULL;
}

CBaseEntity *Findteamspawn( int gno )
{
	CBaseEntity *pEnt = UTIL_FindEntityByString( NULL, "netname", "info_player_teamspawn" );
	while ( pEnt )
	{
		if ( pEnt->goal_no == gno )
			return pEnt;

		pEnt = UTIL_FindEntityByString( pEnt, "netname", "info_player_teamspawn" );
	}

	ALERT( at_console, "Could not find a Teamspawn with a goal_no of %d.\n", gno );
	return NULL;
}

//=========================================================
// Goal states
//=========================================================
void InactivateGoal( CBaseEntity *Goal )
{
	if ( Goal->goal_state != TFGS_ACTIVE )
		return;

	// Timer goals stay non-solid
	if ( Goal->Classify() != CLASS_TFGOAL_TIMER )
	{
		if ( ( Goal->goal_activation & TFGI_SOLID ) && ( Goal->Classify() == CLASS_TFGOAL || Goal->Classify() == CLASS_TFGOAL_ITEM ) )
			Goal->pev->solid = SOLID_BBOX;
		else
			Goal->pev->solid = SOLID_TRIGGER;
	}

	Goal->goal_state = TFGS_INACTIVE;

	char *pModel = (char *)STRING( Goal->pev->model );
	if ( *pModel != '*' )
		Goal->pev->effects &= ~EF_NODRAW;
}

void RestoreGoal( CBaseEntity *Goal )
{
	if ( Goal->goal_state != TFGS_REMOVED )
		return;

	if ( Goal->search_time == 0 )
	{
		if ( ( Goal->goal_activation & TFGI_SOLID ) && FClassnameIs( Goal->pev, "item_tfgoal" ) )
			Goal->pev->solid = SOLID_BBOX;
		else
			Goal->pev->solid = SOLID_TRIGGER;
	}
	else
	{
		Goal->pev->nextthink = gpGlobals->time + Goal->search_time;
	}

	Goal->goal_state = TFGS_INACTIVE;

	char *pModel = (char *)STRING( Goal->pev->model );
	if ( *pModel != '*' )
		Goal->pev->effects &= ~EF_NODRAW;
}

void RemoveGoal( CBaseEntity *Goal )
{
	Goal->pev->solid = SOLID_NOT;
	Goal->goal_state = TFGS_REMOVED;
	Goal->pev->effects |= EF_NODRAW;
}

void InactivateSpawn( CBaseEntity *Spawn )
{
	Spawn->goal_state = TFGS_REMOVED;
}

void ActivateSpawn( CBaseEntity *Spawn )
{
	Spawn->goal_state = TFGS_INACTIVE;
}

// Are all the goals in this group in this state?
BOOL AllGoalsInState( int iGroupNo, int iState )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "info_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->group_no == iGroupNo && pEnt->goal_state != iState )
			return FALSE;

		pEnt = UTIL_FindEntityByClassname( pEnt, "info_tfgoal" );
	}

	return TRUE;
}

// Is the AP carrying an item from this group?
BOOL HasItemFromGroup( CBaseEntity *AP, int iGroupNo )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->group_no == iGroupNo && pEnt->pev->owner == AP->edict() )
			return TRUE;

		pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
	}

	return FALSE;
}

//=========================================================
// Is this player affected by the goal's results?
//=========================================================
BOOL IsAffectedBy( CBaseEntity *Goal, CBasePlayer *Player, CBasePlayer *AP )
{
	// Observers are never affected
	if ( !Player->pev->playerclass )
		return FALSE;

	if ( Goal->goal_effects & TFGE_SAME_ENVIRONMENT )
	{
		int iEnviron = UTIL_PointContents( Goal->pev->origin );
		if ( UTIL_PointContents( Player->pev->origin ) != iEnviron )
			return FALSE;
	}

	// Radius effect
	if ( Goal->t_length != 0 )
	{
		if ( ( Goal->pev->origin - Player->pev->origin ).Length() <= Goal->t_length )
		{
			if ( !( Goal->goal_effects & TFGE_WALL ) )
				return TRUE;

			TraceResult tr;
			UTIL_TraceLine( Goal->pev->origin, Player->pev->origin, dont_ignore_monsters, Goal->edict(), &tr );
			if ( tr.flFraction == 1.0 )
				return TRUE;
		}
	}

	if ( Goal->Classify() != CLASS_TFGOAL_TIMER && AP )
	{
		if ( Goal->Classify() == CLASS_TFSPAWN && Player == AP )
			return TRUE;

		if ( ( Goal->goal_effects & TFGE_AP ) && Player == AP )
			return TRUE;

		if ( ( Goal->goal_effects & TFGE_AP_TEAM ) && AP->team_no == Player->team_no )
			return TRUE;
	}

	if ( ( Goal->goal_effects & TFGE_NOT_AP_TEAM ) && ( !AP || AP->team_no != Player->team_no ) )
		return TRUE;

	if ( ( Goal->goal_effects & TFGE_NOT_AP ) && Player != AP )
		return TRUE;

	// maxammo_shells: affects this team; maxammo_nails: affects everyone but this team
	if ( Goal->maxammo_shells && Goal->maxammo_shells == Player->team_no )
		return TRUE;

	if ( Goal->maxammo_nails && Goal->maxammo_nails != Player->team_no )
		return TRUE;

	return FALSE;
}

//=========================================================
// Give the goal's results to a player
//=========================================================
void Apply_Results( CBaseEntity *Goal, CBasePlayer *Player, CBasePlayer *AP, BOOL bAddBonuses )
{
	// Items are flagged on the player, so their results can be removed
	if ( FClassnameIs( Goal->pev, "item_tfgoal" ) )
		Player->item_list |= Goal->item_list;

	if ( Player == AP && Goal->count != 0 && Player->team_no > 0 )
		TeamFortress_TeamIncreaseScore( Player->team_no, Goal->count );

	if ( bAddBonuses )
	{
		if ( Player->IsAlive() )
		{
			if ( Goal->pev->health > 0 )
				Player->TakeHealth( Goal->pev->health, 0 );
			if ( Goal->pev->health < 0 )
				Player->TakeDamage( Goal->pev, Goal->pev, 0 - Goal->pev->health, DMG_IGNOREARMOR | DMG_NEVERGIB );
		}

		if ( Player->IsAlive() )
		{
			if ( Goal->pev->armortype > 0 )
				Player->pev->armortype = Goal->pev->armortype;
			else if ( Goal->pev->armorvalue > 0 )
				Player->pev->armortype = Player->armor_allowed;

			Player->pev->armorvalue += Goal->pev->armorvalue;

			if ( Goal->armorclass > 0 )
				Player->armorclass = Goal->armorclass;

			Player->GiveTFAmmo( Goal->ammo_shells, Goal->ammo_nails, Goal->ammo_rockets, Goal->ammo_cells );
			Player->ammo_medikit += Goal->ammo_medikit;

			Player->ammo_detpack += Goal->ammo_detpack;
			if ( Player->ammo_detpack > Player->maxammo_detpack )
				Player->ammo_detpack = Player->maxammo_detpack;

			if ( Player->tp_grenades_1 )
				Player->no_grenades_1 += Goal->no_grenades_1;
			if ( Player->tp_grenades_2 )
				Player->no_grenades_2 += Goal->no_grenades_2;

			// Lost the grenade they were priming?
			if ( Player->tfstate & TFSTATE_GRENPRIMED )
			{
				if ( ( Player->m_iPrimedGrenType == 1 && Player->no_grenades_1 <= 0 && Goal->no_grenades_1 < 0 ) ||
					 ( Player->m_iPrimedGrenType == 2 && Player->no_grenades_2 <= 0 && Goal->no_grenades_2 < 0 ) )
				{
					Player->tfstate &= ~( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING );
					Player->bRemoveGrenade = TRUE;
				}
			}

			// Powerups. Items give them for as long as they're carried.
			if ( Goal->invincible_finished > 0 )
			{
				Player->items |= IT_INVULNERABILITY;
				Player->invincible_finished = gpGlobals->time + Goal->invincible_finished;
				if ( FClassnameIs( Goal->pev, "item_tfgoal" ) )
				{
					Player->tfstate |= TFSTATE_INVINCIBLE;
					Player->invincible_finished = gpGlobals->time + 666;
				}
				Player->pev->renderfx = kRenderFxNone;
			}

			if ( Goal->invisible_finished > 0 )
			{
				Player->items |= IT_INVISIBILITY;
				Player->invisible_finished = gpGlobals->time + Goal->invisible_finished;
				if ( FClassnameIs( Goal->pev, "item_tfgoal" ) )
				{
					Player->tfstate |= TFSTATE_INVISIBLE;
					Player->invisible_finished = gpGlobals->time + 666;
				}
				Player->pev->renderfx = kRenderFxNone;
			}

			if ( Goal->super_damage_finished > 0 )
			{
				Player->items |= IT_QUAD;
				Player->super_damage_finished = gpGlobals->time + Goal->super_damage_finished;
				if ( FClassnameIs( Goal->pev, "item_tfgoal" ) )
				{
					Player->tfstate |= TFSTATE_QUAD;
					Player->super_damage_finished = gpGlobals->time + 666;
				}
				Player->pev->renderfx = kRenderFxNone;
			}

			if ( Goal->radsuit_finished > 0 )
			{
				Player->items |= IT_SUIT;
				Player->radsuit_finished = gpGlobals->time + Goal->radsuit_finished;
				if ( FClassnameIs( Goal->pev, "item_tfgoal" ) )
				{
					Player->tfstate |= TFSTATE_RADSUIT;
					Player->radsuit_finished = gpGlobals->time + 666;
				}
			}
		}

		Player->lives += Goal->lives;

		if ( Goal->pev->frags )
			Player->TF_AddFrags( Goal->pev->frags );

		Player->TeamFortress_CheckClassStats();
	}

	// Spies lose their disguise
	if ( Player->pev->playerclass == PC_SPY && ( Goal->goal_result & TFGR_REMOVE_DISGUISE ) )
	{
		Player->immune_to_check = gpGlobals->time + 10;
		Player->Spy_RemoveDisguise();
	}

	// Give an item
	if ( Goal->items && !FClassnameIs( Goal->pev, "item_tfgoal" ) )
	{
		CBaseEntity *pItem = Finditem( Goal->items );
		if ( pItem && pItem != Goal )
			tfgoalitem_GiveToPlayer( pItem, Player, Goal );
	}

	// Take an item away
	if ( Goal->axhitme )
	{
		CBaseEntity *pItem = Finditem( Goal->axhitme );
		if ( pItem->pev->owner == Player->edict() )
			tfgoalitem_RemoveFromPlayer( pItem, Player, GI_DROP_REMOVEGOAL );
	}

	// Take a group of items away
	if ( Goal->remove_item_group )
	{
		CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
		while ( pEnt )
		{
			if ( pEnt->group_no == Goal->remove_item_group && pEnt->pev->owner == Player->edict() )
			{
				// Removing it can move it, so find the next one first
				CBaseEntity *pItemToRemove = pEnt;
				pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
				tfgoalitem_RemoveFromPlayer( pItemToRemove, Player, GI_DROP_REMOVEGOAL );
			}
			else
			{
				pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
			}
		}
	}

	Player->DisplayLocalItemStatus( Goal );

	if ( Goal->goal_result & TFGR_DESTROY_BUILDINGS )
	{
		Player->no_sentry_message = TRUE;
		Player->no_dispenser_message = TRUE;
		Player->no_entry_teleporter_message = TRUE;
		Player->no_exit_teleporter_message = TRUE;

		Player->Engineer_RemoveBuildings();
		Player->TeamFortress_RemoveLiveGrenades();
		Player->TeamFortress_RemoveRockets();
		Player->RemovePipebombs();

		if ( Player->is_detpacking )
		{
			Player->TeamFortress_DetpackStop();
		}
		else
		{
			// Give back a detpack that was lying around
			if ( Player->TeamFortress_RemoveDetpacks() )
				Player->ammo_detpack++;
		}
	}

	if ( ( Goal->goal_result & TFGR_FORCE_RESPAWN ) && Player->IsAlive() )
		Player->ForceRespawn();

	if ( Goal->replacement_model && !Player->replacement_model )
	{
		Player->replacement_model = Goal->replacement_model;
		Player->replacement_model_body = Goal->replacement_model_body;
		Player->replacement_model_skin = Goal->replacement_model_skin;
		Player->replacement_model_flags = Goal->replacement_model_flags;
		Player->TeamFortress_SetSkin();
	}
}

//=========================================================
// Take an item's results back off a player
//=========================================================
void RemoveResults( CBaseEntity *Goal, CBasePlayer *pPlayer )
{
	if ( FClassnameIs( Goal->pev, "item_tfgoal" ) )
	{
		if ( !( pPlayer->item_list & Goal->item_list ) )
			return;

		if ( Goal->goal_activation & TFGI_DONTREMOVERES )
			return;

		pPlayer->item_list &= ~Goal->item_list;
	}

	if ( Goal->pev->health > 0 )
		pPlayer->TakeDamage( Goal->pev, Goal->pev, Goal->pev->health, DMG_IGNOREARMOR );
	if ( Goal->pev->health < 0 )
		pPlayer->TakeHealth( 0 - Goal->pev->health, 0 );

	pPlayer->lives -= Goal->lives;
	pPlayer->pev->armortype -= Goal->pev->armortype;
	pPlayer->pev->armorvalue -= Goal->pev->armorvalue;
	pPlayer->armorclass &= ~Goal->armorclass;

	if ( Goal->pev->frags )
		pPlayer->TF_AddFrags( Goal->pev->frags );

	pPlayer->ammo_shells -= Goal->ammo_shells;
	pPlayer->ammo_nails -= Goal->ammo_nails;
	pPlayer->ammo_rockets -= Goal->ammo_rockets;
	pPlayer->ammo_cells -= Goal->ammo_cells;
	pPlayer->ammo_medikit -= Goal->ammo_medikit;

	pPlayer->ammo_detpack -= Goal->ammo_detpack;
	if ( pPlayer->ammo_detpack > pPlayer->maxammo_detpack )
		pPlayer->ammo_detpack = pPlayer->maxammo_detpack;

	pPlayer->no_grenades_1 -= Goal->no_grenades_1;
	pPlayer->no_grenades_2 -= Goal->no_grenades_2;

	if ( ( pPlayer->tfstate & TFSTATE_GRENPRIMED ) && ( pPlayer->no_grenades_2 <= 0 || pPlayer->no_grenades_1 <= 0 ) )
	{
		pPlayer->tfstate &= ~( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING );
		pPlayer->bRemoveGrenade = TRUE;
	}

	// Powerups stay if another carried item gives them
	BOOL puinvin = FALSE;
	BOOL puinvis = FALSE;
	BOOL puquad = FALSE;
	BOOL purad = FALSE;

	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->pev->owner == pPlayer->edict() && pEnt != Goal )
		{
			if ( pEnt->invincible_finished > 0 )
				puinvin = TRUE;
			if ( pEnt->invisible_finished > 0 )
				puinvis = TRUE;
			if ( pEnt->super_damage_finished > 0 )
				puquad = TRUE;
			if ( pEnt->radsuit_finished > 0 )
				purad = TRUE;
		}

		pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
	}

	// The permanent powerup runs down from now
	if ( !puinvin && Goal->invincible_finished > 0 )
	{
		pPlayer->tfstate &= ~TFSTATE_INVINCIBLE;
		pPlayer->items |= IT_INVULNERABILITY;
		pPlayer->invincible_finished = gpGlobals->time + Goal->invincible_finished;
	}

	if ( !puinvis && Goal->invisible_finished > 0 )
	{
		pPlayer->tfstate &= ~TFSTATE_INVISIBLE;
		pPlayer->items |= IT_INVISIBILITY;
		pPlayer->invisible_finished = gpGlobals->time + Goal->invisible_finished;
	}

	if ( !puquad && Goal->super_damage_finished > 0 )
	{
		pPlayer->tfstate &= ~TFSTATE_QUAD;
		pPlayer->items |= IT_QUAD;
		pPlayer->super_damage_finished = gpGlobals->time + Goal->super_damage_finished;
	}

	if ( !purad && Goal->radsuit_finished > 0 )
	{
		pPlayer->tfstate &= ~TFSTATE_RADSUIT;
		pPlayer->items |= IT_SUIT;
		pPlayer->radsuit_finished = gpGlobals->time + Goal->radsuit_finished;
	}

	pPlayer->TeamFortress_CheckClassStats();

	if ( Goal->replacement_model && Goal->replacement_model == pPlayer->replacement_model )
	{
		pPlayer->replacement_model = 0;
		pPlayer->replacement_model_body = 0;
		pPlayer->replacement_model_skin = 0;
		pPlayer->replacement_model_flags = 0;
		pPlayer->TeamFortress_SetSkin();
	}
}

//=========================================================
// Does the AP match the goal's criteria?
//=========================================================
BOOL APMeetsCriteria( CBaseEntity *Goal, CBaseEntity *AP )
{
	if ( AP && AP->Classify() == CLASS_PLAYER )
	{
		if ( Goal->team_no )
		{
			if ( Goal->team_no != AP->team_no )
				return FALSE;
			if ( AP->pev->deadflag )
				return FALSE;
		}

		if ( Goal->teamcheck && AP->team_no != GetTeamCheckTeam( STRING( Goal->teamcheck ) ) )
			return FALSE;

		if ( Goal->pev->playerclass && Goal->pev->playerclass != AP->pev->playerclass )
			return FALSE;

		if ( Goal->items_allowed )
		{
			CBaseEntity *pItem = Finditem( Goal->items_allowed );
			if ( !pItem )
				return FALSE;
			if ( pItem->pev->owner != AP->edict() )
				return FALSE;
		}
	}

	CBaseEntity *pGoal;

	if ( Goal->if_goal_is_active )
	{
		pGoal = Findgoal( Goal->if_goal_is_active );
		if ( !pGoal )
			return FALSE;
		if ( pGoal->goal_state != TFGS_ACTIVE )
			return FALSE;
	}

	if ( Goal->if_goal_is_inactive )
	{
		pGoal = Findgoal( Goal->if_goal_is_inactive );
		if ( !pGoal )
			return FALSE;
		if ( pGoal->goal_state != TFGS_INACTIVE )
			return FALSE;
	}

	if ( Goal->if_goal_is_removed )
	{
		pGoal = Findgoal( Goal->if_goal_is_removed );
		if ( !pGoal )
			return FALSE;
		if ( pGoal->goal_state != TFGS_REMOVED )
			return FALSE;
	}

	if ( Goal->if_group_is_active && !AllGoalsInState( Goal->if_group_is_active, TFGS_ACTIVE ) )
		return FALSE;

	if ( Goal->if_group_is_inactive && !AllGoalsInState( Goal->if_group_is_inactive, TFGS_INACTIVE ) )
		return FALSE;

	if ( Goal->if_group_is_removed && !AllGoalsInState( Goal->if_group_is_removed, TFGS_REMOVED ) )
		return FALSE;

	CBaseEntity *pItem;

	if ( Goal->if_item_has_moved )
	{
		pItem = Finditem( Goal->if_item_has_moved );
		if ( !pItem )
			return FALSE;
		if ( pItem->goal_state != TFGS_ACTIVE && pItem->pev->origin == pItem->pev->oldorigin )
			return FALSE;
	}

	if ( Goal->if_item_hasnt_moved )
	{
		pItem = Finditem( Goal->if_item_hasnt_moved );
		if ( !pItem )
			return FALSE;
		if ( pItem->goal_state == TFGS_ACTIVE || pItem->pev->origin != pItem->pev->oldorigin )
			return FALSE;
	}

	if ( AP && AP->Classify() == CLASS_PLAYER )
	{
		if ( Goal->has_item_from_group && !HasItemFromGroup( AP, Goal->has_item_from_group ) )
			return FALSE;

		if ( Goal->hasnt_item_from_group && HasItemFromGroup( AP, Goal->hasnt_item_from_group ) )
			return FALSE;
	}

	return TRUE;
}

//=========================================================
// After activation: reset, remove, or wait to respawn
//=========================================================
void SetupRespawn( CBaseEntity *pGoal )
{
	pGoal->m_bAddBonuses = FALSE;

	// Only activates once
	if ( pGoal->goal_result & TFGR_SINGLE )
	{
		RemoveGoal( pGoal );
		return;
	}

	// Timer goals tick again
	if ( pGoal->Classify() == CLASS_TFGOAL_TIMER )
	{
		InactivateGoal( pGoal );
		pGoal->SetThink( &CBaseEntity::tfgoal_timer_tick );
		pGoal->pev->nextthink = gpGlobals->time + pGoal->search_time;
		return;
	}

	if ( pGoal->wait > 0 )
	{
		pGoal->SetThink( &CBaseEntity::DoRespawn );
		pGoal->pev->nextthink = gpGlobals->time + pGoal->wait;
	}
	else if ( pGoal->wait != -1 )
	{
		// -1 stays active forever
		InactivateGoal( pGoal );
	}
}

void CBaseEntity::DoRespawn( void )
{
	RestoreGoal( this );
	InactivateGoal( this );
}

//=========================================================
// Should this goal activate for this AP?
//=========================================================
BOOL ShouldActivate( CBaseEntity *Goal, CBaseEntity *AP )
{
	BOOL bAct = FALSE;

	if ( Goal->goal_state != TFGS_ACTIVE && Goal->goal_state != TFGS_REMOVED && Goal->goal_state != TFGS_DELAYED )
	{
		BOOL bAPMet = APMeetsCriteria( Goal, AP );
		BOOL bRevAct;

		if ( FClassnameIs( Goal->pev, "item_tfgoal" ) )
			bRevAct = Goal->goal_activation & TFGI_REVERSE_AP;
		else
			bRevAct = Goal->goal_activation & TFGA_REVERSE_AP;

		// Reverse AP activates when the criteria are _not_ met
		if ( bAPMet )
			bAct = !bRevAct;
		else
			bAct = ( bRevAct != 0 );
	}

	return bAct;
}

BOOL ActivationSucceeded( CBaseEntity *Goal, CBasePlayer *AP, CBaseEntity *ActivatingGoal )
{
	// Only timers run during prematch
	if ( cb_prematch_time > gpGlobals->time && Goal->Classify() != CLASS_TFGOAL_TIMER )
		return FALSE;

	if ( ShouldActivate( Goal, AP ) )
		return TRUE;

	// Failed: try the else goal
	if ( Goal->else_goal )
	{
		CBaseEntity *pElseGoal = Findgoal( Goal->else_goal );
		if ( pElseGoal )
			ActivateDoResults( pElseGoal, AP, Goal );
	}

	return FALSE;
}

BOOL ActivateDoResults( CBaseEntity *Goal, CBasePlayer *AP, CBaseEntity *ActivatingGoal )
{
	if ( !ActivationSucceeded( Goal, AP, ActivatingGoal ) )
		return FALSE;

	if ( ActivatingGoal == Goal || Goal->m_bAddBonuses == TRUE )
		DoResults( Goal, AP, TRUE );
	else if ( ActivatingGoal )
		DoResults( Goal, AP, ActivatingGoal->goal_result & TFGR_ADD_BONUSES );
	else
		DoResults( Goal, AP, FALSE );

	return TRUE;
}

//=========================================================
// Goals and spawn points changed by this goal
//=========================================================
void DoGoalWork( CBaseEntity *Goal, CBasePlayer *AP )
{
	CBaseEntity *pFoundGoal;

	if ( Goal->activate_goal_no )
	{
		pFoundGoal = Findgoal( Goal->activate_goal_no );
		if ( pFoundGoal )
			ActivateDoResults( pFoundGoal, AP, Goal );
	}

	if ( Goal->inactivate_goal_no )
	{
		pFoundGoal = Findgoal( Goal->inactivate_goal_no );
		if ( pFoundGoal )
			InactivateGoal( pFoundGoal );
	}

	if ( Goal->restore_goal_no )
	{
		pFoundGoal = Findgoal( Goal->restore_goal_no );
		if ( pFoundGoal )
			RestoreGoal( pFoundGoal );
	}

	if ( Goal->remove_goal_no )
	{
		pFoundGoal = Findgoal( Goal->remove_goal_no );
		if ( pFoundGoal )
			RemoveGoal( pFoundGoal );
	}

	if ( Goal->return_item_no )
	{
		pFoundGoal = Finditem( Goal->return_item_no );
		if ( pFoundGoal )
		{
			CBaseEntity *pOwner = CBaseEntity::Instance( pFoundGoal->pev->owner );
			if ( pFoundGoal->goal_state == TFGS_ACTIVE )
				tfgoalitem_RemoveFromPlayer( pFoundGoal, (CBasePlayer *)pOwner, GI_DROP_REMOVEGOAL );

			// Return it after a moment
			CBaseEntity *pTimer = pFoundGoal->CreateTimer( TF_TIMER_RETURNITEM );
			pTimer->weapon = GI_RET_TIME;
			pTimer->SetThink( &CBaseEntity::ReturnItem );
			pTimer->pev->nextthink = gpGlobals->time + 0.1;

			pFoundGoal->pev->solid = SOLID_NOT;
			UTIL_SetOrigin( pFoundGoal->pev, pFoundGoal->pev->origin );
		}
	}

	if ( Goal->remove_spawnpoint )
	{
		pFoundGoal = Findteamspawn( Goal->remove_spawnpoint );
		if ( pFoundGoal )
			InactivateSpawn( pFoundGoal );
	}

	if ( Goal->restore_spawnpoint )
	{
		pFoundGoal = Findteamspawn( Goal->restore_spawnpoint );
		if ( pFoundGoal && pFoundGoal->goal_state == TFGS_REMOVED )
			ActivateSpawn( pFoundGoal );
	}
}

//=========================================================
// Groups of goals changed by this goal
//=========================================================
void DoGroupWork( CBaseEntity *Goal, CBasePlayer *AP )
{
	CBaseEntity *pEnt;

	// Fire last_impulse when the whole group is active
	if ( Goal->all_active )
	{
		if ( !Goal->last_impulse )
		{
			ALERT( at_console, "Goal %d has .all_active specified, but no .last_impulse\n", Goal->goal_no );
		}
		else if ( AllGoalsInState( Goal->all_active, TFGS_ACTIVE ) )
		{
			CBaseEntity *pGoal = Findgoal( Goal->last_impulse );
			if ( pGoal )
				DoResults( pGoal, AP, Goal->goal_result & TFGR_ADD_BONUSES );
		}
	}

	if ( Goal->activate_group_no )
	{
		pEnt = UTIL_FindEntityByClassname( NULL, "info_tfgoal" );
		while ( pEnt )
		{
			if ( pEnt->group_no == Goal->activate_group_no )
				ActivateDoResults( pEnt, AP, Goal );

			pEnt = UTIL_FindEntityByClassname( pEnt, "info_tfgoal" );
		}
	}

	if ( Goal->inactivate_group_no )
	{
		pEnt = UTIL_FindEntityByClassname( NULL, "info_tfgoal" );
		while ( pEnt )
		{
			if ( pEnt->group_no == Goal->inactivate_group_no )
				InactivateGoal( pEnt );

			pEnt = UTIL_FindEntityByClassname( pEnt, "info_tfgoal" );
		}
	}

	if ( Goal->remove_group_no )
	{
		pEnt = UTIL_FindEntityByClassname( NULL, "info_tfgoal" );
		while ( pEnt )
		{
			if ( pEnt->group_no == Goal->remove_group_no )
				RemoveGoal( pEnt );

			pEnt = UTIL_FindEntityByClassname( pEnt, "info_tfgoal" );
		}
	}

	if ( Goal->restore_group_no )
	{
		pEnt = UTIL_FindEntityByClassname( NULL, "info_tfgoal" );
		while ( pEnt )
		{
			if ( pEnt->group_no == Goal->restore_group_no )
				RestoreGoal( pEnt );

			pEnt = UTIL_FindEntityByClassname( pEnt, "info_tfgoal" );
		}
	}
}

//=========================================================
// Item groups: distance = group all carried, pain_finished = goal
// to fire; speed = group all carried by one player,
// attack_finished = goal to fire
//=========================================================
void DoItemGroupWork( CBaseEntity *Item, CBasePlayer *AP )
{
	CBaseEntity *pEnt;

	if ( Item->distance != 0 )
	{
		if ( Item->pev->pain_finished == 0 )
			ALERT( at_console, "GoalItem %d has .distance specified, but no .pain_finished\n", Item->goal_no );

		BOOL bAllCarried = TRUE;
		pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
		while ( pEnt && bAllCarried )
		{
			if ( pEnt->group_no == Item->distance )
				bAllCarried = ( pEnt->goal_state == TFGS_ACTIVE );

			pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
		}

		if ( bAllCarried )
		{
			CBaseEntity *pGoal = Findgoal( Item->pev->pain_finished );
			if ( pGoal )
				DoResults( pGoal, AP, Item->goal_result & TFGR_ADD_BONUSES );
		}
	}

	if ( Item->pev->speed != 0 )
	{
		if ( Item->attack_finished == 0 )
			ALERT( at_console, "GoalItem %d has .speed specified, but no .attack_finished\n", Item->goal_no );

		BOOL bAllCarried = TRUE;
		CBaseEntity *pCarrier = NULL;
		pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
		while ( pEnt && bAllCarried )
		{
			if ( pEnt->group_no == Item->pev->speed )
			{
				if ( pEnt->goal_state != TFGS_ACTIVE )
				{
					bAllCarried = FALSE;
				}
				else if ( !pCarrier )
				{
					pCarrier = CBaseEntity::Instance( pEnt->pev->owner );
				}
				else if ( pCarrier != CBaseEntity::Instance( pEnt->pev->owner ) )
				{
					bAllCarried = FALSE;
				}
			}

			pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
		}

		if ( bAllCarried )
		{
			CBaseEntity *pGoal = Findgoal( Item->attack_finished );
			if ( pGoal )
				DoResults( pGoal, AP, Item->goal_result & TFGR_ADD_BONUSES );
		}
	}
}

//=========================================================
// Map entity triggering
//=========================================================
void DoTriggerWork( CBaseEntity *Goal, CBasePlayer *AP )
{
	if ( Goal->killtarget )
	{
		edict_t *pentKillTarget = FIND_ENTITY_BY_TARGETNAME( NULL, STRING( Goal->killtarget ) );
		while ( !FNullEnt( pentKillTarget ) )
		{
			UTIL_Remove( CBaseEntity::Instance( pentKillTarget ) );
			pentKillTarget = FIND_ENTITY_BY_TARGETNAME( pentKillTarget, STRING( Goal->killtarget ) );
		}
	}

	if ( Goal->pev->target )
	{
		edict_t *pentTarget = FIND_ENTITY_BY_TARGETNAME( NULL, STRING( Goal->pev->target ) );
		while ( !FNullEnt( pentTarget ) )
		{
			CBaseEntity *pTarget = CBaseEntity::Instance( pentTarget );
			if ( !( pTarget->pev->flags & FL_KILLME ) )
				pTarget->Use( AP, Goal, USE_TOGGLE, 0 );

			pentTarget = FIND_ENTITY_BY_TARGETNAME( pentTarget, STRING( Goal->pev->target ) );
		}
	}
}

void CBaseEntity::DelayedResult( void )
{
	CBasePlayer *pEnemy = (CBasePlayer *)CBaseEntity::Instance( pev->enemy );

	if ( goal_state == TFGS_DELAYED )
		DoResults( this, pEnemy, weapon );
}

// Logs "player triggered" lines in the standard format
static void LogPlayerTrigger( CBasePlayer *AP, const char *pszTrigger )
{
	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"%s\"\n",
		STRING( AP->pev->netname ),
		GETPLAYERUSERID( AP->edict() ),
		GETPLAYERAUTHID( AP->edict() ),
		AP->team_no ? GetTeamName( AP->team_no ) : "SPECTATOR",
		pszTrigger );
}

//=========================================================
// Do all the goal's results
//=========================================================
void DoResults( CBaseEntity *Goal, CBasePlayer *AP, BOOL bAddBonuses )
{
	int i;
	BOOL bDumpScores;
	BOOL bGotOne;

	// Only timers run during prematch
	if ( cb_prematch_time > gpGlobals->time && Goal->Classify() != CLASS_TFGOAL_TIMER )
		return;

	// Already active
	if ( Goal->goal_state == TFGS_ACTIVE )
		return;

	// Delayed results
	if ( Goal->delay_time > 0 && Goal->goal_state != TFGS_DELAYED )
	{
		Goal->goal_state = TFGS_DELAYED;
		Goal->CreateTimer( TF_TIMER_DELAYEDGOAL );
		Goal->pev->enemy = AP->edict();
		Goal->SetThink( &CBaseEntity::DelayedResult );
		Goal->pev->nextthink = gpGlobals->time + Goal->delay_time;
		Goal->weapon = bAddBonuses;
		return;
	}

	if ( Goal->owned_by_teamcheck )
		Goal->owned_by = GetTeamCheckTeam( STRING( Goal->owned_by_teamcheck ) );

	Goal->goal_state = TFGS_INACTIVE;

	if ( Goal->Classify() == CLASS_TFGOAL || Goal->Classify() == CLASS_TFGOAL_TIMER )
		Goal->pev->effects |= EF_NODRAW;

	if ( Goal->pev->noise )
		EMIT_SOUND( Goal->edict(), CHAN_VOICE, STRING( Goal->pev->noise ), 1, ATTN_NORM );

	// Team scores
	for ( i = 0; i < 4; i++ )
	{
		if ( Goal->increase_team[i] )
			TeamFortress_TeamIncreaseScore( i + 1, Goal->increase_team[i] );
	}

	if ( Goal->increase_team_owned_by && Goal->owned_by )
		TeamFortress_TeamIncreaseScore( Goal->owned_by, Goal->increase_team_owned_by );

	// Log it
	const char *pszName = STRING( Goal->pev->netname );
	if ( *pszName )
	{
		if ( AP )
			LogPlayerTrigger( AP, pszName );
		else
			UTIL_LogPrintf( "World triggered \"%s\"\n", pszName );
	}

	bGotOne = ( AP != NULL );

	// Standard CTF maps
	if ( AP && CTF_Map == TRUE && ( Goal->goal_no == CTF_FLAG1 || Goal->goal_no == CTF_DROPOFF1 ) )
	{
		for ( i = 1; i <= gpGlobals->maxClients; i++ )
		{
			CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
			if ( !pPlayer )
				continue;

			if ( ( pPlayer->team_no == 2 && Goal->goal_no == CTF_FLAG1 ) || ( pPlayer->team_no == 1 && Goal->goal_no == CTF_FLAG2 ) )
			{
				if ( pPlayer == AP )
					ClientPrint( AP->pev, HUD_PRINTCENTER, "You got the enemy flag!\n\nReturn to base!" );
				else
					ClientPrint( pPlayer->pev, HUD_PRINTCENTER, "Your team GOT the ENEMY flag!!" );
			}
			else if ( Goal->goal_no == CTF_FLAG1 || Goal->goal_no == CTF_FLAG2 )
			{
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, "Your flag has been TAKEN!!" );
			}
			else if ( ( pPlayer->team_no == 2 && Goal->goal_no == CTF_DROPOFF1 ) || ( pPlayer->team_no == 1 && Goal->goal_no == CTF_DROPOFF2 ) )
			{
				if ( pPlayer == AP )
					ClientPrint( AP->pev, HUD_PRINTCENTER, "You CAPTURED the FLAG!!" );
				else
					ClientPrint( pPlayer->pev, HUD_PRINTCENTER, "Your flag was CAPTURED!!" );
			}
			else if ( Goal->goal_no == CTF_DROPOFF1 || Goal->goal_no == CTF_DROPOFF2 )
			{
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, "Your team CAPTURED the flag!!" );
			}
		}

		switch ( Goal->goal_no )
		{
		case CTF_FLAG1:
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s GOT the BLUE flag!", STRING( AP->pev->netname ) ) );
			LogPlayerTrigger( AP, "Stole_Blue_Flag" );
			AP->items |= IT_KEY1;
			break;
		case CTF_FLAG2:
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s GOT the RED flag!", STRING( AP->pev->netname ) ) );
			LogPlayerTrigger( AP, "Stole_Red_Flag" );
			AP->items |= IT_KEY2;
			break;
		case CTF_DROPOFF1:
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s CAPTURED the RED flag!", STRING( AP->pev->netname ) ) );
			LogPlayerTrigger( AP, "Captured_Red_Flag" );
			AP->items &= ~IT_KEY2;
			break;
		case CTF_DROPOFF2:
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s CAPTURED the BLUE flag!", STRING( AP->pev->netname ) ) );
			LogPlayerTrigger( AP, "Captured_Blue_Flag" );
			AP->items &= ~IT_KEY1;
			break;
		}
	}

	// Spawn groups
	CBaseEntity *pEnt;
	if ( Goal->remove_spawngroup )
	{
		pEnt = UTIL_FindEntityByString( NULL, "netname", "info_player_teamspawn" );
		while ( pEnt )
		{
			if ( pEnt->group_no == Goal->remove_spawngroup )
				InactivateSpawn( pEnt );

			pEnt = UTIL_FindEntityByString( pEnt, "netname", "info_player_teamspawn" );
		}
	}

	if ( Goal->restore_spawngroup )
	{
		pEnt = UTIL_FindEntityByString( NULL, "netname", "info_player_teamspawn" );
		while ( pEnt )
		{
			if ( pEnt->group_no == Goal->restore_spawngroup )
				ActivateSpawn( pEnt );

			pEnt = UTIL_FindEntityByString( pEnt, "netname", "info_player_teamspawn" );
		}
	}

	if ( Goal->broadcast && !CTF_Map )
		UTIL_LogPrintf( "World triggered \"%s\"\n", STRING( Goal->broadcast ) );

	if ( Goal->netname_broadcast && bGotOne && !CTF_Map )
		LogPlayerTrigger( AP, STRING( Goal->netname_broadcast ) );

	// Messages and effects for every player
	for ( i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
		if ( !pPlayer )
			continue;

		if ( Goal->broadcast && !CTF_Map )
			UTIL_ShowMessage( STRING( Goal->broadcast ), pPlayer->edict() );

		if ( Goal->netname_broadcast && bGotOne && !CTF_Map )
			ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, STRING( Goal->netname_broadcast ), STRING( AP->pev->netname ) );

		if ( Goal->org_broadcast && !CTF_Map )
			ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Goal->org_broadcast ) );

		if ( Goal->speak )
			pPlayer->ClientHearVox( STRING( Goal->speak ) );

		if ( pPlayer == AP )
		{
			if ( Goal->pev->message && Goal->Classify() != CLASS_TFSPAWN )
				UTIL_ShowMessage( STRING( Goal->pev->message ), AP->edict() );

			if ( Goal->org_message && Goal->Classify() != CLASS_TFSPAWN )
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Goal->org_message ) );

			if ( Goal->AP_speak )
				pPlayer->ClientHearVox( STRING( Goal->AP_speak ) );
		}
		else if ( bGotOne && AP->team_no == pPlayer->team_no )
		{
			// The AP's team
			if ( Goal->owners_team_broadcast && pPlayer->team_no == Goal->owned_by )
				UTIL_ShowMessage( STRING( Goal->owners_team_broadcast ), pPlayer->edict() );
			else if ( Goal->non_owners_team_broadcast && pPlayer->team_no != Goal->owned_by )
				UTIL_ShowMessage( STRING( Goal->non_owners_team_broadcast ), pPlayer->edict() );
			else if ( Goal->team_broadcast )
				UTIL_ShowMessage( STRING( Goal->team_broadcast ), pPlayer->edict() );

			if ( Goal->org_owners_team_broadcast && pPlayer->team_no == Goal->owned_by )
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Goal->org_owners_team_broadcast ) );
			else if ( Goal->org_non_owners_team_broadcast && pPlayer->team_no != Goal->owned_by )
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Goal->org_non_owners_team_broadcast ) );
			else if ( Goal->org_team_broadcast )
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Goal->org_team_broadcast ) );

			if ( Goal->owners_team_speak && pPlayer->team_no == Goal->owned_by )
				pPlayer->ClientHearVox( STRING( Goal->owners_team_speak ) );
			else if ( Goal->non_owners_team_speak && pPlayer->team_no != Goal->owned_by )
				pPlayer->ClientHearVox( STRING( Goal->non_owners_team_speak ) );
			else if ( Goal->team_speak )
				pPlayer->ClientHearVox( STRING( Goal->team_speak ) );

			if ( Goal->netname_owners_team_broadcast && pPlayer->team_no == Goal->owned_by )
				ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, STRING( Goal->netname_owners_team_broadcast ), STRING( AP->pev->netname ) );
			else if ( Goal->netname_team_broadcast )
				ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, STRING( Goal->netname_team_broadcast ), STRING( AP->pev->netname ) );
		}
		else
		{
			// Everyone else
			if ( Goal->owners_team_broadcast && pPlayer->team_no == Goal->owned_by )
				UTIL_ShowMessage( STRING( Goal->owners_team_broadcast ), pPlayer->edict() );
			else if ( Goal->non_owners_team_broadcast && pPlayer->team_no != Goal->owned_by )
				UTIL_ShowMessage( STRING( Goal->non_owners_team_broadcast ), pPlayer->edict() );
			else if ( Goal->non_team_broadcast )
				UTIL_ShowMessage( STRING( Goal->non_team_broadcast ), pPlayer->edict() );

			if ( Goal->org_owners_team_broadcast && pPlayer->team_no == Goal->owned_by )
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Goal->org_owners_team_broadcast ) );
			else if ( Goal->org_non_owners_team_broadcast && pPlayer->team_no != Goal->owned_by )
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Goal->org_non_owners_team_broadcast ) );
			else if ( Goal->org_non_team_broadcast )
				ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Goal->org_non_team_broadcast ) );

			if ( Goal->owners_team_speak && pPlayer->team_no == Goal->owned_by )
				pPlayer->ClientHearVox( STRING( Goal->owners_team_speak ) );
			else if ( Goal->non_owners_team_speak && pPlayer->team_no != Goal->owned_by )
				pPlayer->ClientHearVox( STRING( Goal->non_owners_team_speak ) );
			else if ( Goal->non_team_speak )
				pPlayer->ClientHearVox( STRING( Goal->non_team_speak ) );

			if ( Goal->netname_owners_team_broadcast && bGotOne && pPlayer->team_no == Goal->owned_by )
				ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, STRING( Goal->netname_owners_team_broadcast ), STRING( AP->pev->netname ) );
			else if ( bGotOne && Goal->netname_non_team_broadcast )
				ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, STRING( Goal->netname_non_team_broadcast ), STRING( AP->pev->netname ) );
		}

		if ( IsAffectedBy( Goal, pPlayer, AP ) )
		{
			// Timers can check the criteria of every affected player
			if ( Goal->search_time != 0 && ( Goal->goal_effects & TFGE_TIMER_CHECK_AP ) )
			{
				if ( APMeetsCriteria( Goal, pPlayer ) )
					Apply_Results( Goal, pPlayer, AP, bAddBonuses );
			}
			else
			{
				Apply_Results( Goal, pPlayer, AP, bAddBonuses );
			}
		}
	}

	if ( Goal->Classify() == CLASS_TFGOAL_TIMER || Goal->Classify() == CLASS_TFGOAL )
		Goal->goal_state = TFGS_ACTIVE;

	bDumpScores = Goal->goal_result & TFGR_ENDGAME;
	if ( bDumpScores )
	{
		// End of the level
		TeamFortress_TeamShowScores( TRUE, NULL );
		if ( g_pGameRules->IsMultiplayer() )
			( (CHalfLifeMultiplay *)g_pGameRules )->GoToIntermission();
		return;
	}

	if ( Goal->m_flEndRoundTime )
		EndRound( Goal );

	DoGroupWork( Goal, AP );
	DoGoalWork( Goal, AP );

	if ( Goal->Classify() == CLASS_TFGOAL_TIMER || Goal->Classify() == CLASS_TFGOAL_ITEM ||
		 Goal->Classify() == CLASS_TFGOAL || Goal->Classify() == CLASS_TFSPAWN || Goal->do_triggerwork == TRUE )
		DoTriggerWork( Goal, AP );

	if ( Goal->Classify() == CLASS_TFGOAL || Goal->Classify() == CLASS_TFGOAL_TIMER )
		SetupRespawn( Goal );
}

//=========================================================
// Touch functions
//=========================================================
void CBaseEntity::tfgoal_touch( CBaseEntity *pOther )
{
	if ( cb_prematch_time > gpGlobals->time )
		return;

	if ( !( goal_activation & TFGA_TOUCH ) )
		return;

	if ( pOther->Classify() != CLASS_PLAYER )
		return;

	if ( !pOther->IsAlive() )
		return;

	if ( goal_state == TFGS_ACTIVE )
		return;

	// CTF: can only capture with your own flag at home
	if ( CTF_Map )
	{
		CBaseEntity *pFlag;

		if ( goal_no == CTF_DROPOFF1 && pOther->team_no == 1 )
		{
			pFlag = Finditem( CTF_FLAG1 );
			if ( pFlag->goal_state == TFGS_ACTIVE || pFlag->pev->origin != pFlag->pev->oldorigin )
				return;
		}

		if ( goal_no == CTF_DROPOFF2 && pOther->team_no == 2 )
		{
			pFlag = Finditem( CTF_FLAG2 );
			if ( pFlag->goal_state == TFGS_ACTIVE || pFlag->pev->origin != pFlag->pev->oldorigin )
				return;
		}
	}

	ActivateDoResults( this, (CBasePlayer *)pOther, this );
}

void CBaseEntity::item_tfgoal_touch( CBaseEntity *pOther )
{
	if ( pOther->Classify() != CLASS_PLAYER )
		return;

	if ( !pOther->IsAlive() )
		return;

	if ( cb_prematch_time > gpGlobals->time )
		return;

	if ( pOther->is_feigning )
		return;

	// Can't carry two model-replacing items
	if ( replacement_model && pOther->replacement_model )
		return;

	// The player who threw it can't pick it up again for 5 seconds
	CTFGoalItem *pItem = (CTFGoalItem *)this;
	if ( pev->enemy && pItem->m_flDroppedAt != 0 && pev->enemy == pOther->edict() && gpGlobals->time < pItem->m_flDroppedAt + 5 )
		return;

	pItem->m_flDroppedAt = 0;

	// Must be able to see it
	TraceResult tr;
	UTIL_TraceLine( Center(), pOther->Center(), ignore_monsters, edict(), &tr );
	if ( tr.flFraction != 1.0 && tr.pHit != pOther->edict() )
		return;

	if ( CTF_Map == TRUE )
	{
		if ( pev->origin == pev->oldorigin )
		{
			// Own flag at home: ignore
			if ( pOther->team_no == 1 && goal_no == CTF_FLAG1 )
				return;
			if ( pOther->team_no == 2 && goal_no == CTF_FLAG2 )
				return;
		}
		else if ( team_no == 1 )
		{
			// Own flag dropped somewhere: return it
			char *pszTeam;
			if ( goal_no == CTF_FLAG1 )
			{
				UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s RETURNED the BLUE flag!", STRING( pOther->pev->netname ) ) );
				pszTeam = pOther->team_no ? GetTeamName( pOther->team_no ) : (char *)"SPECTATOR";
				UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Returned_Blue_Flag\"\n", STRING( pOther->pev->netname ), GETPLAYERUSERID( pOther->edict() ), GETPLAYERAUTHID( pOther->edict() ), pszTeam );
			}
			else
			{
				UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s RETURNED the RED flag!", STRING( pOther->pev->netname ) ) );
				pszTeam = pOther->team_no ? GetTeamName( pOther->team_no ) : (char *)"SPECTATOR";
				UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Returned_Red_Flag\"\n", STRING( pOther->pev->netname ), GETPLAYERUSERID( pOther->edict() ), GETPLAYERAUTHID( pOther->edict() ), pszTeam );
			}

			for ( int i = 1; i <= gpGlobals->maxClients; i++ )
			{
				CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
				if ( !pPlayer )
					continue;

				if ( pPlayer->team_no == 1 )
				{
					if ( goal_no == CTF_FLAG1 )
						ClientPrint( pPlayer->pev, HUD_PRINTCENTER, "Your flag was RETURNED!!\n" );
				}
				else if ( goal_no == CTF_FLAG1 )
				{
					ClientPrint( pPlayer->pev, HUD_PRINTCENTER, "The ENEMY flag was RETURNED!!\n" );
				}
				else if ( pPlayer->team_no == 2 && goal_no == CTF_FLAG2 )
				{
					ClientPrint( pPlayer->pev, HUD_PRINTCENTER, "Your flag was RETURNED!!\n" );
				}
			}

			goal_state = TFGS_INACTIVE;
			pev->solid = SOLID_TRIGGER;
			SetTouch( &CBaseEntity::item_tfgoal_touch );
			pev->origin = pev->oldorigin;
			UTIL_SetOrigin( pev, pev->origin );
			EMIT_SOUND_DYN( edict(), CHAN_WEAPON, "items/itembk2.wav", 1, ATTN_NORM, 0, 150 );
			return;
		}
	}

	if ( ActivationSucceeded( this, (CBasePlayer *)pOther, NULL ) )
	{
		tfgoalitem_GiveToPlayer( this, (CBasePlayer *)pOther, this );

		// Picked up (it may have killed them)
		if ( pOther->pev->health > 0 )
			goal_state = TFGS_ACTIVE;
	}
}

//=========================================================
// Goal items
//=========================================================
void tfgoalitem_GiveToPlayer( CBaseEntity *Item, CBasePlayer *AP, CBaseEntity *Goal )
{
	// Stop it being removed
	if ( Item->redrop_count )
		Item->SetThink( NULL );

	Item->pev->owner = AP->edict();
	Item->pev->movetype = MOVETYPE_FOLLOW;
	Item->pev->aiment = AP->edict();

	if ( Item->pev->model )
	{
		Item->pev->effects &= ~EF_NODRAW;
		Item->pev->sequence = ( (CBaseAnimating *)Item )->LookupSequence( "carried" );
		if ( Item->pev->sequence != -1 )
		{
			( (CBaseAnimating *)Item )->ResetSequenceInfo();
			Item->pev->frame = 0;
		}
	}

	Item->pev->solid = SOLID_NOT;

	if ( Item->goal_activation & TFGI_GLOW )
		AP->pev->effects |= EF_BRIGHTFIELD;

	if ( Item->goal_activation & TFGI_SLOW )
		AP->TeamFortress_SetSpeed();

	if ( Item->speed_reduction )
		AP->TeamFortress_SetSpeed();

	if ( Item->goal_activation & TFGI_ITEMGLOWS )
	{
		Item->pev->renderfx = kRenderFxNone;
		Item->pev->rendercolor = g_vecZero;
		Item->pev->renderamt = 0;
	}

	// Keys
	if ( Item->items & IT_KEY1 )
		AP->items |= IT_KEY1;
	if ( Item->items & IT_KEY2 )
		AP->items |= IT_KEY2;
	if ( Item->items & IT_KEY3 )
		AP->items |= IT_KEY3;
	if ( Item->items & IT_KEY4 )
		AP->items |= IT_KEY4;

	// Goal gives the item without its results
	if ( Goal != Item && ( Goal->goal_result & TFGR_NO_ITEM_RESULTS ) )
	{
		Item->goal_state = TFGS_ACTIVE;
		return;
	}

	// Spies can't disguise, and nobody can teleport, while carrying it
	if ( Item->goal_result & TFGR_REMOVE_DISGUISE )
		AP->is_unableto_spy_or_teleport = TRUE;

	DoResults( Item, AP, TRUE );
	DoItemGroupWork( Item, AP );
}

// Timer think: put a goal item back where it started
void CBaseEntity::ReturnItem( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	pOwner->SetThink( NULL );
	pOwner->goal_state = TFGS_INACTIVE;

	if ( ( pOwner->goal_activation & TFGI_SOLID ) && FClassnameIs( pOwner->pev, "item_tfgoal" ) )
		pOwner->pev->solid = SOLID_BBOX;
	else
		pOwner->pev->solid = SOLID_TRIGGER;

	pOwner->pev->movetype = MOVETYPE_NONE;
	pOwner->pev->aiment = NULL;
	pOwner->SetTouch( &CBaseEntity::item_tfgoal_touch );
	pOwner->pev->angles = g_vecZero;
	pOwner->pev->origin = pOwner->pev->oldorigin;
	pOwner->pev->effects &= ~EF_NODRAW;
	UTIL_SetOrigin( pOwner->pev, pOwner->pev->origin );

	EMIT_SOUND_DYN( pOwner->edict(), CHAN_WEAPON, "items/itembk2.wav", 1, ATTN_NORM, 0, 150 );

	tfgoalitem_checkgoalreturn( pOwner );

	// Tell everyone, unless a goal returned it
	if ( weapon != GI_RET_GOAL && ( pOwner->pev->noise3 || pOwner->noise4 || pOwner->org_noise3 || pOwner->org_noise4 ) )
	{
		for ( int i = 1; i <= gpGlobals->maxClients; i++ )
		{
			CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
			if ( !pPlayer )
				continue;

			if ( pOwner->owned_by_teamcheck )
				pOwner->owned_by = GetTeamCheckTeam( STRING( pOwner->owned_by_teamcheck ) );

			if ( pPlayer->team_no == pOwner->owned_by )
			{
				if ( pOwner->pev->noise3 )
					UTIL_ShowMessage( STRING( pOwner->pev->noise3 ), pPlayer->edict() );
				else if ( pOwner->org_noise3 )
					ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( pOwner->org_noise3 ) );
			}
			else
			{
				if ( pOwner->noise4 )
					UTIL_ShowMessage( STRING( pOwner->noise4 ), pPlayer->edict() );
				else if ( pOwner->org_noise4 )
					ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( pOwner->org_noise4 ) );
			}
		}
	}

	UTIL_Remove( this );
}

void tfgoalitem_RemoveFromPlayer( CBaseEntity *Item, CBasePlayer *AP, int iMethod )
{
	BOOL lighton = FALSE;
	BOOL key1on = FALSE;
	BOOL key2on = FALSE;
	BOOL key3on = FALSE;
	BOOL key4on = FALSE;
	BOOL spyoff = FALSE;

	if ( Item->owned_by_teamcheck )
		Item->owned_by = GetTeamCheckTeam( STRING( Item->owned_by_teamcheck ) );

	// What do the player's other items still give?
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->pev->owner == AP->edict() && pEnt != Item )
		{
			if ( pEnt->goal_activation & TFGI_GLOW )
				lighton = TRUE;
			if ( pEnt->items & IT_KEY1 )
				key1on = TRUE;
			if ( pEnt->items & IT_KEY2 )
				key2on = TRUE;
			if ( pEnt->items & IT_KEY3 )
				key3on = TRUE;
			if ( pEnt->items & IT_KEY4 )
				key4on = TRUE;
			if ( pEnt->goal_result & TFGR_REMOVE_DISGUISE )
				spyoff = TRUE;
		}

		pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
	}

	// Keep the glow if a powerup gives it
	if ( !lighton )
	{
		if ( AP->invincible_finished <= gpGlobals->time + 3 && AP->super_damage_finished <= gpGlobals->time + 3 )
		{
			AP->pev->effects &= ~EF_BRIGHTFIELD;
			AP->pev->effects &= ~EF_BRIGHTLIGHT;
		}
	}

	if ( Item->goal_activation & TFGI_ITEMGLOWS )
	{
		Item->pev->renderfx = kRenderFxGlowShell;
		if ( Item->owned_by >= 1 && Item->owned_by <= 4 )
			Item->pev->rendercolor = rgbcolors[Item->owned_by];
		else
			Item->pev->rendercolor = rgbcolors[0];
		Item->pev->renderamt = 100;
	}

	if ( !spyoff )
		AP->is_unableto_spy_or_teleport = FALSE;

	if ( !key1on )
		AP->items &= ~IT_KEY1;
	if ( !key2on )
		AP->items &= ~IT_KEY2;
	if ( !key3on )
		AP->items &= ~IT_KEY3;
	if ( !key4on )
		AP->items &= ~IT_KEY4;

	// Take its results off everyone it affected
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
		if ( pPlayer && IsAffectedBy( Item, pPlayer, AP ) )
			RemoveResults( Item, pPlayer );
	}

	if ( Item->pev->model )
	{
		Item->pev->sequence = ( (CBaseAnimating *)Item )->LookupSequence( "not_carried" );
		if ( Item->pev->sequence != -1 )
		{
			( (CBaseAnimating *)Item )->ResetSequenceInfo();
			Item->pev->frame = 0;
		}
	}

	if ( iMethod == GI_DROP_PLAYERDEATH || iMethod == GI_DROP_PLAYERDROP )
	{
		// Drop messages
		for ( int i = 1; i <= gpGlobals->maxClients; i++ )
		{
			CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
			if ( !pPlayer )
				continue;

			if ( pPlayer->team_no == Item->owned_by )
			{
				if ( Item->team_drop )
					UTIL_ShowMessage( STRING( Item->team_drop ), pPlayer->edict() );
				if ( Item->netname_team_drop )
					ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, STRING( Item->netname_team_drop ), STRING( AP->pev->netname ) );
				if ( Item->org_team_drop )
					ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Item->org_team_drop ) );
			}
			else
			{
				if ( Item->non_team_drop )
					UTIL_ShowMessage( STRING( Item->non_team_drop ), pPlayer->edict() );
				if ( Item->netname_non_team_drop )
					ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, STRING( Item->netname_non_team_drop ), STRING( AP->pev->netname ) );
				if ( Item->org_non_team_drop )
					ClientPrint( pPlayer->pev, HUD_PRINTCENTER, STRING( Item->org_non_team_drop ) );
			}
		}

		if ( Item->goal_activation & TFGI_RETURN_DROP )
		{
			// Return it straight away
			CBaseEntity *pTimer = Item->CreateTimer( TF_TIMER_RETURNITEM );
			pTimer->weapon = ( iMethod == GI_DROP_PLAYERDEATH ) ? GI_RET_DROP_DEAD : GI_RET_DROP_LIVING;
			pTimer->SetThink( &CBaseEntity::ReturnItem );
			pTimer->pev->nextthink = gpGlobals->time + 0.5;
		}
		else if ( Item->goal_activation & TFGI_DROP )
		{
			if ( iMethod == GI_DROP_PLAYERDROP && ( Item->goal_activation & TFGI_CANBEDROPPED ) )
				tfgoalitem_drop( Item, TRUE, AP );
			else
				tfgoalitem_drop( Item, FALSE, AP );
		}
		else
		{
			// Gone for good
			Item->pev->owner = NULL;
			Item->pev->nextthink = gpGlobals->time;
			Item->SetThink( &CBaseEntity::SUB_Remove );
			AP->TeamFortress_SetSpeed();
			return;
		}

		Item->pev->owner = NULL;
		Item->pev->flags &= ~FL_ONGROUND;
		UTIL_SetSize( Item->pev, Item->goal_min, Item->goal_max );
		AP->TeamFortress_SetSpeed();
	}
	else if ( iMethod == GI_DROP_REMOVEGOAL )
	{
		Item->pev->owner = NULL;

		if ( Item->goal_activation & TFGI_RETURN_GOAL )
		{
			CBaseEntity *pTimer = Item->CreateTimer( TF_TIMER_RETURNITEM );
			pTimer->SetThink( &CBaseEntity::ReturnItem );
			pTimer->pev->nextthink = gpGlobals->time + 0.5;
			pTimer->weapon = GI_RET_GOAL;
			AP->TeamFortress_SetSpeed();
			return;
		}

		// Hide it
		Item->pev->solid = SOLID_NOT;
		Item->pev->effects |= EF_NODRAW;
		Item->pev->movetype = MOVETYPE_NONE;
		Item->pev->aiment = NULL;
		AP->TeamFortress_SetSpeed();
	}
}

// Drop the item where the player is (thrown forward if alive)
void tfgoalitem_drop( CBaseEntity *Item, BOOL PAlive, CBasePlayer *P )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( Item->pev->owner );

	Item->redrop_count = 0;
	Item->SetTouch( &CBaseEntity::item_tfgoal_touch );

	if ( pOwner->pev->flags & FL_DUCKING )
		Item->redrop_origin = pOwner->pev->origin + Vector( 0, 0, 26 );
	else
		Item->redrop_origin = pOwner->pev->origin + Vector( 0, 0, 8 );

	Item->DoDrop( Item->redrop_origin );
	Item->pev->owner = P->edict();

	if ( PAlive == TRUE )
	{
		UTIL_MakeAimVectors( P->pev->angles );
		Item->pev->velocity = gpGlobals->v_forward * 400 + gpGlobals->v_up * 200;

		// Can't be picked up until it's left the thrower
		Item->SetTouch( NULL );
		Item->SetThink( &CBaseEntity::tfgoalitem_droptouch );
		Item->pev->nextthink = gpGlobals->time + 0.75;

		Item->pev->enemy = P->edict();
		( (CTFGoalItem *)Item )->m_flDroppedAt = gpGlobals->time;
	}
}

void CBaseEntity::DoDrop( Vector vecOrigin )
{
	pev->origin = vecOrigin;
	UTIL_SetOrigin( pev, pev->origin );
	pev->movetype = MOVETYPE_TOSS;
	pev->aiment = NULL;
	pev->velocity.z = 400;

	// Kick it about if it keeps getting stuck
	if ( redrop_count > 1 )
	{
		pev->velocity.x = RANDOM_FLOAT( -50, 50 );
		pev->velocity.y = RANDOM_FLOAT( -50, 50 );
	}

	goal_state = TFGS_INACTIVE;
	pev->angles = g_vecZero;

	if ( goal_activation & TFGI_SOLID )
		pev->solid = SOLID_BBOX;
	else
		pev->solid = SOLID_TRIGGER;

	pev->effects &= ~EF_NODRAW;
	UTIL_SetSize( pev, goal_min, goal_max );

	redrop_count++;
	SetThink( &CBaseEntity::tfgoalitem_dropthink );
	pev->nextthink = gpGlobals->time + 5;
}

void CBaseEntity::tfgoalitem_droptouch( void )
{
	SetTouch( &CBaseEntity::item_tfgoal_touch );
	SetThink( &CBaseEntity::tfgoalitem_dropthink );
	pev->nextthink = gpGlobals->time + 4.25;
}

// Settled after a drop: remove it later, or redrop if it's somewhere bad
void CBaseEntity::tfgoalitem_dropthink( void )
{
	pev->movetype = MOVETYPE_TOSS;
	pev->aiment = NULL;

	if ( drop_time == 0 )
		return;

	int iEnviron = UTIL_PointContents( pev->origin );
	if ( iEnviron == CONTENTS_SLIME )
	{
		pev->nextthink = gpGlobals->time + drop_time / 4;
	}
	else if ( iEnviron == CONTENTS_LAVA )
	{
		pev->nextthink = gpGlobals->time + 5;
	}
	else if ( iEnviron == CONTENTS_SKY || iEnviron == CONTENTS_SOLID )
	{
		// Out of the world: drop it again where it was dropped
		if ( redrop_count < 3 )
		{
			DoDrop( redrop_origin );
			return;
		}

		pev->nextthink = gpGlobals->time + 2;
	}
	else
	{
		pev->nextthink = gpGlobals->time + drop_time;
	}

	SetThink( &CBaseEntity::tfgoalitem_remove );
}

void CBaseEntity::tfgoalitem_remove( void )
{
	// Someone picked it up
	if ( goal_state == TFGS_ACTIVE )
		return;

	if ( goal_activation & TFGI_RETURN_REMOVE )
	{
		CBaseEntity *pTimer = CreateTimer( TF_TIMER_RETURNITEM );
		pTimer->weapon = GI_RET_TIME;
		pTimer->SetThink( &CBaseEntity::ReturnItem );
		pTimer->pev->nextthink = gpGlobals->time + 0.1;
		return;
	}

	dremove( this );
}

// The item is back: fire its return goal (impulse)
void tfgoalitem_checkgoalreturn( CBaseEntity *Item )
{
	if ( Item->pev->impulse )
	{
		CBaseEntity *pGoal = Findgoal( Item->pev->impulse );
		if ( pGoal )
			ActivateDoResults( pGoal, NULL, Item );
	}
}

//=========================================================
// Item status lines (home / moved / carried)
//=========================================================
void DisplayItemStatus( CBaseEntity *Goal, CBasePlayer *Player, CBaseEntity *Item )
{
	if ( Item->owned_by_teamcheck )
		Item->owned_by = GetTeamCheckTeam( STRING( Item->owned_by_teamcheck ) );

	if ( Item->goal_state == TFGS_ACTIVE )
	{
		if ( !Goal->team_str_carried && !Goal->non_team_str_carried )
			return;

		CBaseEntity *pOwner = CBaseEntity::Instance( Item->pev->owner );
		const char *pszWho;

		if ( Player->team_no == Item->owned_by )
		{
			pszWho = ( Item->pev->owner == Player->edict() ) ? "you" : STRING( pOwner->pev->netname );
			ClientPrint( Player->pev, HUD_PRINTTALK, STRING( Goal->team_str_carried ), pszWho );
		}
		else
		{
			pszWho = ( Item->pev->owner == Player->edict() ) ? "you" : STRING( pOwner->pev->netname );
			ClientPrint( Player->pev, HUD_PRINTTALK, STRING( Goal->non_team_str_carried ), pszWho );
		}
		return;
	}

	if ( Item->pev->origin == Item->pev->oldorigin )
	{
		if ( !Goal->team_str_home && !Goal->non_team_str_home )
			return;

		if ( Player->team_no == Item->owned_by )
			ClientPrint( Player->pev, HUD_PRINTTALK, STRING( Goal->team_str_home ) );
		else
			ClientPrint( Player->pev, HUD_PRINTTALK, STRING( Goal->non_team_str_home ) );
	}
	else
	{
		if ( !Goal->team_str_moved && !Goal->non_team_str_moved )
			return;

		if ( Player->team_no == Item->owned_by )
			ClientPrint( Player->pev, HUD_PRINTTALK, STRING( Goal->team_str_moved ) );
		else
			ClientPrint( Player->pev, HUD_PRINTTALK, STRING( Goal->non_team_str_moved ) );
	}
}

//=========================================================
// Map and server settings
//=========================================================
void ParseTFDetect( CBaseEntity *AD )
{
	if ( AD->team_broadcast )
		team_menu_string = AD->team_broadcast;

	// Number of teams
	if ( AD->last_impulse )
		number_of_teams = AD->last_impulse;

	// Team names
	if ( AD->speak )
		team_names[1] = AD->speak;
	if ( AD->AP_speak )
		team_names[2] = AD->AP_speak;
	if ( AD->team_speak )
		team_names[3] = AD->team_speak;
	if ( AD->owners_team_speak )
		team_names[4] = AD->owners_team_speak;

	// Server commands for the map
	if ( AD->pev->message )
		SERVER_COMMAND( (char *)STRING( AD->pev->message ) );

	// Team lives
	teamlives[1] = AD->ammo_shells;
	teamlives[2] = AD->ammo_nails;
	teamlives[3] = AD->ammo_rockets;
	teamlives[4] = AD->ammo_cells;
	for ( int i = 1; i <= 4; i++ )
	{
		if ( teamlives[i] == 0 )
			teamlives[i] = -1;
	}

	// Team sizes
	teammaxplayers[1] = AD->ammo_medikit;
	teammaxplayers[2] = AD->ammo_detpack;
	teammaxplayers[3] = AD->maxammo_medikit;
	teammaxplayers[4] = AD->maxammo_detpack;
	for ( int i = 1; i <= 4; i++ )
	{
		if ( teammaxplayers[i] == 0 )
			teammaxplayers[i] = 100;
	}

	// Illegal classes; -1 makes the team civilian
	illegalclasses[0] = AD->pev->playerclass;
	illegalclasses[1] = AD->maxammo_shells;
	illegalclasses[2] = AD->maxammo_nails;
	illegalclasses[3] = AD->maxammo_rockets;
	illegalclasses[4] = AD->maxammo_cells;

	civilianteams = 0;
	if ( illegalclasses[1] == -1 )
	{
		civilianteams |= TEAM1_CIVILIANS;
		illegalclasses[1] = 0;
	}
	if ( illegalclasses[2] == -1 )
	{
		civilianteams |= TEAM2_CIVILIANS;
		illegalclasses[2] = 0;
	}
	if ( illegalclasses[3] == -1 )
	{
		civilianteams |= TEAM3_CIVILIANS;
		illegalclasses[3] = 0;
	}
	if ( illegalclasses[4] == -1 )
	{
		civilianteams |= TEAM4_CIVILIANS;
		illegalclasses[4] = 0;
	}
}

void ParseTFServerSettings( void )
{
	toggleflags &= ~TFLAG_CHEATCHECK;

	// Christmas and the TFC birthday
	time_t aclock;
	time( &aclock );
	struct tm *ptm = localtime( &aclock );

	if ( ptm->tm_mon == 11 && ptm->tm_mday == 25 )
		christmas = TRUE;

	if ( tfc_birthday.value || ( ptm->tm_mon == 7 && ptm->tm_mday == 24 ) || christmas == TRUE )
	{
		birthday = TRUE;

		CBaseEntity *pTimer = CBaseEntity::Create( "timer", g_vecZero, g_vecZero, NULL );
		pTimer->weapon = TF_TIMER_DETPACKDISARM;
		pTimer->SetThink( &CBaseEntity::Timer_Birthday );
		pTimer->pev->nextthink = gpGlobals->time + 60;
	}

	cb_prematch_time = tfc_clanbattle_prematch.value * 60;
	if ( cb_prematch_time == 0 )
		cb_prematch_time = tfc_prematch.value * 60;

	if ( tfc_clanbattle.value )
	{
		clan_scores_dumped = 0;

		cb_ceasefire_time = tfc_clanbattle_ceasefire.value * 60;
		if ( cb_ceasefire_time )
		{
			last_cease_fire = TRUE;
			initial_cease_fire = TRUE;
			cease_fire = TRUE;
			clan_scores_dumped = 0;
		}
	}

	autokick_kills = tfc_autokick_kills.value;

	if ( tfc_fragscoring.value )
		toggleflags |= TFLAG_FRAGSCORING;
	else
		toggleflags &= ~TFLAG_FRAGSCORING;

	gpGlobals->teamplay = teamplay.value;
}

void ParseTFMapSettings( void )
{
	flagem_checked = 0;

	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "info_tfdetect" );
	if ( pEnt )
	{
		if ( !teamplay.value )
		{
			CVAR_SET_FLOAT( "mp_teamplay", 1 );
			gpGlobals->teamplay = 1;
		}

		ParseTFDetect( pEnt );

		if ( number_of_teams <= 0 || number_of_teams >= 5 )
			number_of_teams = 4;
	}
	else
	{
		// No detect entity: a CTF map, or four teams
		pEnt = UTIL_FindEntityByClassname( NULL, "info_player_team1" );
		if ( pEnt || CTF_Map == TRUE )
		{
			CTF_Map = TRUE;
			if ( !teamplay.value )
			{
				CVAR_SET_FLOAT( "mp_teamplay", 1 );
				gpGlobals->teamplay = 1;
			}
			number_of_teams = 2;
		}
		else
		{
			number_of_teams = 4;
		}

		for ( int i = 1; i <= 4; i++ )
		{
			teammaxplayers[i] = 100;
			teamlives[i] = -1;
		}

		civilianteams = 0;
		for ( int i = 1; i <= 4; i++ )
			illegalclasses[i] = 0;

		for ( int i = 1; i <= 4; i++ )
			g_pLastSpawns[i] = NULL;
	}

	for ( int i = 1; i <= 4; i++ )
	{
		teamfrags[i] = 0;
		teamscores[i] = 0;
	}

	autokick_kills = 0;
	cease_fire = FALSE;
	g_fNextPrematchAlert = 0;
}

//=========================================================
// Timer goals
//=========================================================
void CBaseEntity::tfgoal_timer_tick( void )
{
	if ( goal_state == TFGS_REMOVED )
		return;

	// Wait for prematch to finish
	if ( cb_prematch_time > gpGlobals->time )
	{
		SetThink( &CBaseEntity::tfgoal_timer_tick );
		pev->nextthink = cb_prematch_time + search_time;
		return;
	}

	if ( APMeetsCriteria( this, NULL ) )
	{
		DoResults( this, NULL, TRUE );
	}
	else
	{
		SetThink( &CBaseEntity::tfgoal_timer_tick );
		pev->nextthink = gpGlobals->time + search_time;
	}
}

// Fired by the map's entity I/O
void CTFGoal::Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
	// Only players are APs
	if ( pActivator && pActivator->Classify() != CLASS_PLAYER )
		pActivator = NULL;

	m_bAddBonuses = TRUE;
	ActivateDoResults( this, (CBasePlayer *)pActivator, pCaller );
}

//=========================================================
// End of round: fade out, freeze everyone, show the result
//=========================================================
void EndRound( CBaseEntity *pGoal )
{
	int highestScore = -99990;
	int winningTeam = 0;
	char *winnerMsg = "";

	UTIL_ScreenFadeAll( Vector( 0, 0, 0 ), 0.3, pGoal->m_flEndRoundTime, 255, FFADE_OUT | FFADE_MODULATE );
	TeamFortress_TeamShowScores( TRUE, NULL );

	if ( pGoal->m_iszEndRoundMsg_Team1_Win )
	{
		for ( int i = 1; i <= 4; i++ )
		{
			int teamScore = TeamFortress_TeamGetScoreFrags( i );
			if ( teamScore > highestScore )
			{
				highestScore = teamScore;
				winningTeam = i;
			}
		}

		switch ( winningTeam )
		{
		case 2:
			winnerMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team2_Win );
			break;
		case 3:
			winnerMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team3_Win );
			break;
		case 4:
			winnerMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team4_Win );
			break;
		default:
			winningTeam = 1;
			winnerMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team1_Win );
			break;
		}
	}

	cease_fire = TRUE;
	no_cease_fire_text = TRUE;

	CBasePlayer *client = NULL;
	while ( ( client = (CBasePlayer *)UTIL_FindEntityByClassname( client, "player" ) ) != NULL )
	{
		if ( FNullEnt( client->edict() ) )
			break;

		if ( !client->pev )
			continue;

		// Freeze them
		if ( !client->pev->iuser1 )
		{
			client->pev->iuser4 = TRUE;
			client->m_iHideHUD |= ( HIDEHUD_WEAPONS | HIDEHUD_HEALTH );
			client->tfstate |= TFSTATE_CANT_MOVE;
		}
		client->TeamFortress_SetSpeed();

		if ( pGoal->m_iszEndRoundMsg_OwnedBy && client->team_no == pGoal->owned_by )
		{
			UTIL_ShowMessage( STRING( pGoal->m_iszEndRoundMsg_OwnedBy ), client->edict() );
		}
		else if ( pGoal->m_iszEndRoundMsg_NonOwnedBy && client->team_no != pGoal->owned_by )
		{
			UTIL_ShowMessage( STRING( pGoal->m_iszEndRoundMsg_NonOwnedBy ), client->edict() );
		}
		else if ( pGoal->m_iszEndRoundMsg_Team1_Win )
		{
			if ( client->team_no == winningTeam )
			{
				UTIL_ShowMessage( winnerMsg, client->edict() );
			}
			else
			{
				char *loserMsg;
				switch ( client->team_no )
				{
				case 1: loserMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team1_Lose ); break;
				case 2: loserMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team2_Lose ); break;
				case 3: loserMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team3_Lose ); break;
				case 4: loserMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team4_Lose ); break;
				default: loserMsg = ""; break;
				}
				UTIL_ShowMessage( loserMsg, client->edict() );
			}
		}
		else
		{
			char *pszMsg;
			switch ( client->team_no )
			{
			case 1: pszMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team1 ); break;
			case 2: pszMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team2 ); break;
			case 3: pszMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team3 ); break;
			case 4: pszMsg = (char *)STRING( pGoal->m_iszEndRoundMsg_Team4 ); break;
			default: pszMsg = ""; break;
			}
			UTIL_ShowMessage( pszMsg, client->edict() );
		}
	}

	CBaseEntity *pTimer = pGoal->CreateTimer( TF_TIMER_ENDROUND );
	pTimer->SetThink( &CBaseEntity::EndRoundEnd );
	pTimer->pev->nextthink = gpGlobals->time + pGoal->m_flEndRoundTime;
}

// Timer think: unfreeze everyone
void CBaseEntity::EndRoundEnd( void )
{
	cease_fire = FALSE;

	CBasePlayer *client = NULL;
	while ( ( client = (CBasePlayer *)UTIL_FindEntityByClassname( client, "player" ) ) != NULL )
	{
		if ( FNullEnt( client->edict() ) )
			break;

		if ( !client->pev )
			continue;

		if ( !client->pev->iuser1 )
		{
			client->pev->iuser4 = FALSE;
			client->tfstate &= ~TFSTATE_CANT_MOVE;
			client->m_iHideHUD = 0;
		}
		client->TeamFortress_SetSpeed();
	}

	no_cease_fire_text = FALSE;
	pev->flags |= FL_KILLME;
}

//=========================================================
// info_tf_teamcheck / info_tf_teamset
//=========================================================
void CTeamCheck::Spawn( void )
{
}

void CTeamCheck::Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
	// Toggle swaps teams 1 and 2; set picks a team
	if ( useType == USE_TOGGLE )
	{
		team_no = ( team_no == 1 ) ? 2 : 1;
	}
	else if ( useType == USE_SET )
	{
		if ( value >= 1 && value <= 4 )
			team_no = value;
	}
}

BOOL CTeamCheck::TeamMatches( int iTeam )
{
	return iTeam == team_no;
}

void CTeamSet::Spawn( void )
{
}

void CTeamSet::Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
	if ( team_no )
		SUB_UseTargets( pActivator, USE_SET, team_no );
	else
		SUB_UseTargets( pActivator, USE_TOGGLE, 0 );
}

//=========================================================
// func_nogrenades: grenades can't be primed inside it
//=========================================================
class CNoGrenadeArea : public CBaseEntity
{
public:
	void Spawn( void );
};

LINK_ENTITY_TO_CLASS( func_nogrenades, CNoGrenadeArea );

void CNoGrenadeArea::Spawn( void )
{
	pev->solid = SOLID_TRIGGER;
	pev->movetype = MOVETYPE_NONE;
	pev->effects |= EF_NODRAW;
	SET_MODEL( ENT( pev ), STRING( pev->model ) );
	UTIL_SetSize( pev, pev->mins, pev->maxs );
	UTIL_SetOrigin( pev, pev->origin );
}
