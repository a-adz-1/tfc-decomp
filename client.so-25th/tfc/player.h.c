// Ghidra decompilation of functions from tfc/player.h
// 9 functions, ordered by original source line

// CBasePlayer::BodyTarget  @ 00059f10  (line 259)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Vector BodyTarget(CBasePlayer * this, Vector * posSrc) */

Vector * __thiscall
CBasePlayer::BodyTarget(Vector *__return_storage_ptr__,CBasePlayer *this,Vector *posSrc)

{
  entvars_t *peVar1;
  _func_int_varargs *p_Var2;
  longdouble extraout_ST0;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  float local_2c;
  float local_1c;
  float local_18;
  float local_14;
  
  (*g_engfuncs.pfnRandomFloat)(0.5,1.1);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  lVar3 = (longdouble)(peVar1->view_ofs).z * extraout_ST0;
  p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x32];
  lVar4 = (longdouble)(peVar1->view_ofs).y * extraout_ST0;
  lVar8 = (longdouble)(peVar1->view_ofs).x * extraout_ST0;
  if (p_Var2 == CBaseEntity::Center) {
    lVar6 = (longdouble)0.5 * ((longdouble)(peVar1->absmax).z + (longdouble)(peVar1->absmin).z);
    lVar5 = ((longdouble)(peVar1->absmax).y + (longdouble)(peVar1->absmin).y) * (longdouble)0.5;
    lVar7 = (longdouble)0.5 * ((longdouble)(peVar1->absmax).x + (longdouble)(peVar1->absmin).x);
  }
  else {
    (*p_Var2)(&local_18,this);
    lVar6 = (longdouble)local_14;
    lVar5 = (longdouble)local_18;
    lVar7 = (longdouble)local_1c;
    lVar8 = (longdouble)(float)lVar4;
    lVar4 = (longdouble)(float)lVar3;
    lVar3 = (longdouble)local_2c;
  }
  __return_storage_ptr__->x = (float)(lVar7 + lVar8);
  __return_storage_ptr__->y = (float)(lVar4 + lVar5);
  __return_storage_ptr__->z = (float)(lVar3 + lVar6);
  return __return_storage_ptr__;
}


// CBasePlayer::StartSneaking  @ 00059c40  (line 260)

/* DWARF original prototype: void StartSneaking(CBasePlayer * this) */

void __thiscall CBasePlayer::StartSneaking(CBasePlayer *this)

{
  this->m_tSneaking = gpGlobals->time - 1.0;
  return;
}


// CBasePlayer::StopSneaking  @ 00059c60  (line 261)

/* DWARF original prototype: void StopSneaking(CBasePlayer * this) */

void __thiscall CBasePlayer::StopSneaking(CBasePlayer *this)

{
  this->m_tSneaking = gpGlobals->time + 30.0;
  return;
}


// CBasePlayer::IsSneaking  @ 00059c80  (line 262)

/* DWARF original prototype: BOOL IsSneaking(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsSneaking(CBasePlayer *this)

{
  return (uint)(this->m_tSneaking <= gpGlobals->time);
}


// CBasePlayer::IsAlive  @ 00059ca0  (line 263)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL IsAlive(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsAlive(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar2 = peVar1->deadflag;
  if ((iVar2 != 0) && (iVar2 != 5)) {
    return 0;
  }
  return (uint)(0.0 < peVar1->health);
}


// CBasePlayer::ShouldFadeOnDeath  @ 00059ce0  (line 264)

/* DWARF original prototype: BOOL ShouldFadeOnDeath(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::ShouldFadeOnDeath(CBasePlayer *this)

{
  return 0;
}


// CBasePlayer::IsPlayer  @ 00059cf0  (line 265)

/* DWARF original prototype: BOOL IsPlayer(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsPlayer(CBasePlayer *this)

{
  return 1;
}


// CBasePlayer::IsNetClient  @ 00059d00  (line 267)

/* DWARF original prototype: BOOL IsNetClient(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsNetClient(CBasePlayer *this)

{
  return 1;
}


// CBasePlayer::ObjectCaps  @ 00059d10  (line 285)

/* DWARF original prototype: int ObjectCaps(CBasePlayer * this) */

int __thiscall CBasePlayer::ObjectCaps(CBasePlayer *this)

{
  return 0;
}


