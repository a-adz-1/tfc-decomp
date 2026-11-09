// Ghidra decompilation of functions from tfc/gamerules.h
// 16 functions, ordered by original source line

// CGameRules::IsTeamplay  @ 0009e0c0  (line 64)

/* DWARF original prototype: BOOL IsTeamplay(CGameRules * this) */

BOOL __thiscall CGameRules::IsTeamplay(CGameRules *this)

{
  return 0;
}


// CGameRules::GetGameDescription  @ 0009e0d0  (line 66)

/* DWARF original prototype: char * GetGameDescription(CGameRules * this) */

char * __thiscall CGameRules::GetGameDescription(CGameRules *this)

{
  return "Half-Life";
}


// CGameRules::UpdateGameMode  @ 0009e0e0  (line 72)

/* DWARF original prototype: void UpdateGameMode(CGameRules * this, CBasePlayer * pPlayer) */

void __thiscall CGameRules::UpdateGameMode(CGameRules *this,CBasePlayer *pPlayer)

{
  return;
}


// CGameRules::FPlayerCanTakeDamage  @ 0009e0f0  (line 76)

/* DWARF original prototype: BOOL FPlayerCanTakeDamage(CGameRules * this, CBasePlayer * pPlayer,
   CBaseEntity * pAttacker) */

BOOL __thiscall
CGameRules::FPlayerCanTakeDamage(CGameRules *this,CBasePlayer *pPlayer,CBaseEntity *pAttacker)

{
  return 1;
}


// CGameRules::ShouldAutoAim  @ 0009e100  (line 77)

/* DWARF original prototype: BOOL ShouldAutoAim(CGameRules * this, CBasePlayer * pPlayer, edict_t *
   target) */

BOOL __thiscall CGameRules::ShouldAutoAim(CGameRules *this,CBasePlayer *pPlayer,edict_t *target)

{
  return 1;
}


// CGameRules::AllowAutoTargetCrosshair  @ 0009e110  (line 86)

/* DWARF original prototype: BOOL AllowAutoTargetCrosshair(CGameRules * this) */

BOOL __thiscall CGameRules::AllowAutoTargetCrosshair(CGameRules *this)

{
  return 1;
}


// CGameRules::ClientCommand  @ 0009e120  (line 87)

/* DWARF original prototype: BOOL ClientCommand(CGameRules * this, CBasePlayer * pPlayer, char *
   pcmd) */

BOOL __thiscall CGameRules::ClientCommand(CGameRules *this,CBasePlayer *pPlayer,char *pcmd)

{
  return 0;
}


// CGameRules::ClientUserInfoChanged  @ 0009e130  (line 88)

/* DWARF original prototype: void ClientUserInfoChanged(CGameRules * this, CBasePlayer * pPlayer,
   char * infobuffer) */

void __thiscall
CGameRules::ClientUserInfoChanged(CGameRules *this,CBasePlayer *pPlayer,char *infobuffer)

{
  return;
}


// CGameRules::FlHEVChargerRechargeTime  @ 0009e140  (line 125)

/* DWARF original prototype: float FlHEVChargerRechargeTime(CGameRules * this) */

float __thiscall CGameRules::FlHEVChargerRechargeTime(CGameRules *this)

{
  return 0.0;
}


// CGameRules::PlayTextureSounds  @ 0009e150  (line 138)

/* DWARF original prototype: BOOL PlayTextureSounds(CGameRules * this) */

BOOL __thiscall CGameRules::PlayTextureSounds(CGameRules *this)

{
  return 1;
}


// CGameRules::PlayFootstepSounds  @ 0009e160  (line 139)

/* DWARF original prototype: BOOL PlayFootstepSounds(CGameRules * this, CBasePlayer * pl, float
   fvol) */

BOOL __thiscall CGameRules::PlayFootstepSounds(CGameRules *this,CBasePlayer *pl,float fvol)

{
  return 1;
}


// CGameRules::SendMOTDToClient  @ 0009e170  (line 141)

/* DWARF original prototype: void SendMOTDToClient(CGameRules * this, edict_t * client) */

void __thiscall CGameRules::SendMOTDToClient(CGameRules *this,edict_t *client)

{
  return;
}


// CHalfLifeRules::FAllowFlashlight  @ 0009e180  (line 158)

/* DWARF original prototype: BOOL FAllowFlashlight(CHalfLifeRules * this) */

BOOL __thiscall CHalfLifeRules::FAllowFlashlight(CHalfLifeRules *this)

{
  return 1;
}


// CHalfLifeRules::GetTeamID  @ 0009e190  (line 225)

/* DWARF original prototype: char * GetTeamID(CHalfLifeRules * this, CBaseEntity * pEntity) */

char * __thiscall CHalfLifeRules::GetTeamID(CHalfLifeRules *this,CBaseEntity *pEntity)

{
  return "";
}


// CHalfLifeMultiplay::GetTeamID  @ 0009e1a0  (line 313)

/* DWARF original prototype: char * GetTeamID(CHalfLifeMultiplay * this, CBaseEntity * pEntity) */

char * __thiscall CHalfLifeMultiplay::GetTeamID(CHalfLifeMultiplay *this,CBaseEntity *pEntity)

{
  return "";
}


// CHalfLifeMultiplay::PlayTextureSounds  @ 0009e1b0  (line 316)

/* DWARF original prototype: BOOL PlayTextureSounds(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::PlayTextureSounds(CHalfLifeMultiplay *this)

{
  return 0;
}


