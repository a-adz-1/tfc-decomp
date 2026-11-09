// Ghidra decompilation of functions from tfc/gamerules.h
// 16 functions, ordered by original source line

// CGameRules::IsTeamplay  @ 000db1a0  (line 64)

/* DWARF original prototype: BOOL IsTeamplay(CGameRules * this) */

BOOL __thiscall CGameRules::IsTeamplay(CGameRules *this)

{
  return 0;
}


// CGameRules::GetGameDescription  @ 000db1b0  (line 66)

/* DWARF original prototype: char * GetGameDescription(CGameRules * this) */

char * __thiscall CGameRules::GetGameDescription(CGameRules *this)

{
  return "Half-Life";
}


// CGameRules::UpdateGameMode  @ 000db1c0  (line 72)

/* DWARF original prototype: void UpdateGameMode(CGameRules * this, CBasePlayer * pPlayer) */

void __thiscall CGameRules::UpdateGameMode(CGameRules *this,CBasePlayer *pPlayer)

{
  return;
}


// CGameRules::FPlayerCanTakeDamage  @ 000db1d0  (line 76)

/* DWARF original prototype: BOOL FPlayerCanTakeDamage(CGameRules * this, CBasePlayer * pPlayer,
   CBaseEntity * pAttacker) */

BOOL __thiscall
CGameRules::FPlayerCanTakeDamage(CGameRules *this,CBasePlayer *pPlayer,CBaseEntity *pAttacker)

{
  return 1;
}


// CGameRules::ShouldAutoAim  @ 000db1e0  (line 77)

/* DWARF original prototype: BOOL ShouldAutoAim(CGameRules * this, CBasePlayer * pPlayer, edict_t *
   target) */

BOOL __thiscall CGameRules::ShouldAutoAim(CGameRules *this,CBasePlayer *pPlayer,edict_t *target)

{
  return 1;
}


// CGameRules::AllowAutoTargetCrosshair  @ 000db1f0  (line 86)

/* DWARF original prototype: BOOL AllowAutoTargetCrosshair(CGameRules * this) */

BOOL __thiscall CGameRules::AllowAutoTargetCrosshair(CGameRules *this)

{
  return 1;
}


// CGameRules::ClientCommand  @ 000db200  (line 87)

/* DWARF original prototype: BOOL ClientCommand(CGameRules * this, CBasePlayer * pPlayer, char *
   pcmd) */

BOOL __thiscall CGameRules::ClientCommand(CGameRules *this,CBasePlayer *pPlayer,char *pcmd)

{
  return 0;
}


// CGameRules::ClientUserInfoChanged  @ 000db210  (line 88)

/* DWARF original prototype: void ClientUserInfoChanged(CGameRules * this, CBasePlayer * pPlayer,
   char * infobuffer) */

void __thiscall
CGameRules::ClientUserInfoChanged(CGameRules *this,CBasePlayer *pPlayer,char *infobuffer)

{
  return;
}


// CGameRules::FlHEVChargerRechargeTime  @ 000db220  (line 125)

/* DWARF original prototype: float FlHEVChargerRechargeTime(CGameRules * this) */

float __thiscall CGameRules::FlHEVChargerRechargeTime(CGameRules *this)

{
  return 0.0;
}


// CGameRules::PlayTextureSounds  @ 000db230  (line 138)

/* DWARF original prototype: BOOL PlayTextureSounds(CGameRules * this) */

BOOL __thiscall CGameRules::PlayTextureSounds(CGameRules *this)

{
  return 1;
}


// CGameRules::PlayFootstepSounds  @ 000db240  (line 139)

/* DWARF original prototype: BOOL PlayFootstepSounds(CGameRules * this, CBasePlayer * pl, float
   fvol) */

BOOL __thiscall CGameRules::PlayFootstepSounds(CGameRules *this,CBasePlayer *pl,float fvol)

{
  return 1;
}


// CGameRules::SendMOTDToClient  @ 000db250  (line 141)

/* DWARF original prototype: void SendMOTDToClient(CGameRules * this, edict_t * client) */

void __thiscall CGameRules::SendMOTDToClient(CGameRules *this,edict_t *client)

{
  return;
}


// CHalfLifeRules::FAllowFlashlight  @ 000db260  (line 158)

/* DWARF original prototype: BOOL FAllowFlashlight(CHalfLifeRules * this) */

BOOL __thiscall CHalfLifeRules::FAllowFlashlight(CHalfLifeRules *this)

{
  return 1;
}


// CHalfLifeRules::GetTeamID  @ 000db270  (line 225)

/* DWARF original prototype: char * GetTeamID(CHalfLifeRules * this, CBaseEntity * pEntity) */

char * __thiscall CHalfLifeRules::GetTeamID(CHalfLifeRules *this,CBaseEntity *pEntity)

{
  return "";
}


// CHalfLifeMultiplay::GetTeamID  @ 000db280  (line 313)

/* DWARF original prototype: char * GetTeamID(CHalfLifeMultiplay * this, CBaseEntity * pEntity) */

char * __thiscall CHalfLifeMultiplay::GetTeamID(CHalfLifeMultiplay *this,CBaseEntity *pEntity)

{
  return "";
}


// CHalfLifeMultiplay::PlayTextureSounds  @ 000db290  (line 316)

/* DWARF original prototype: BOOL PlayTextureSounds(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::PlayTextureSounds(CHalfLifeMultiplay *this)

{
  return 0;
}


