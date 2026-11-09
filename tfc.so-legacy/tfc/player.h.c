// Ghidra decompilation of functions from tfc/player.h
// 9 functions, ordered by original source line

// CBasePlayer::BodyTarget  @ 00113860  (line 259)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Vector BodyTarget(CBasePlayer * this, Vector * posSrc) */

Vector * __thiscall
CBasePlayer::BodyTarget(Vector *__return_storage_ptr__,CBasePlayer *this,Vector *posSrc)

{
  float local_50;
  float local_40;
  float local_30;
  float local_1c;
  float local_18;
  float local_14;
  
  (*g_engfuncs.pfnRandomFloat)(0.5,1.1);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x32])(&local_18,this);
  __return_storage_ptr__->x = local_50 + local_1c;
  __return_storage_ptr__->y = local_40 + local_18;
  __return_storage_ptr__->z = local_30 + local_14;
  return __return_storage_ptr__;
}


// CBasePlayer::StartSneaking  @ 001138f0  (line 260)

/* DWARF original prototype: void StartSneaking(CBasePlayer * this) */

void __thiscall CBasePlayer::StartSneaking(CBasePlayer *this)

{
  this->m_tSneaking = gpGlobals->time - 1.0;
  return;
}


// CBasePlayer::StopSneaking  @ 00113910  (line 261)

/* DWARF original prototype: void StopSneaking(CBasePlayer * this) */

void __thiscall CBasePlayer::StopSneaking(CBasePlayer *this)

{
  this->m_tSneaking = gpGlobals->time + 30.0;
  return;
}


// CBasePlayer::IsSneaking  @ 00113930  (line 262)

/* DWARF original prototype: BOOL IsSneaking(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsSneaking(CBasePlayer *this)

{
  return (uint)(this->m_tSneaking <= gpGlobals->time);
}


// CBasePlayer::IsAlive  @ 00113950  (line 263)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL IsAlive(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsAlive(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar2 = peVar1->deadflag;
  if ((iVar2 != 5) && (iVar2 != 0)) {
    return 0;
  }
  return (uint)(0.0 < peVar1->health);
}


// CBasePlayer::ShouldFadeOnDeath  @ 00113990  (line 264)

/* DWARF original prototype: BOOL ShouldFadeOnDeath(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::ShouldFadeOnDeath(CBasePlayer *this)

{
  return 0;
}


// CBasePlayer::IsPlayer  @ 001139a0  (line 265)

/* DWARF original prototype: BOOL IsPlayer(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsPlayer(CBasePlayer *this)

{
  return 1;
}


// CBasePlayer::IsNetClient  @ 001139b0  (line 267)

/* DWARF original prototype: BOOL IsNetClient(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsNetClient(CBasePlayer *this)

{
  return 1;
}


// CBasePlayer::ObjectCaps  @ 001139c0  (line 285)

/* DWARF original prototype: int ObjectCaps(CBasePlayer * this) */

int __thiscall CBasePlayer::ObjectCaps(CBasePlayer *this)

{
  return 0;
}


