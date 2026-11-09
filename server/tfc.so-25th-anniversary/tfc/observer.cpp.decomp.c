// Ghidra decompilation of functions from tfc/observer.cpp
// 5 functions, ordered by original source line

// CBasePlayer::Observer_FindNextPlayer  @ 000bed20  (line 31)

/* DWARF original prototype: void Observer_FindNextPlayer(CBasePlayer * this, bool bReverse) */

void __thiscall CBasePlayer::Observer_FindNextPlayer(CBasePlayer *this,bool bReverse)

{
  EHANDLE *this_00;
  int iVar1;
  entvars_t *peVar2;
  int iVar3;
  CBaseEntity *pCVar4;
  CBasePlayer *pEntity;
  int iVar5;
  
                    /* Unresolved local var: int iStart@[???]
                       Unresolved local var: int iCurrent@[???]
                       Unresolved local var: int iDir@[???] */
  this_00 = &this->m_hObserverTarget;
  iVar3 = EHANDLE::operator_int(this_00);
  if (iVar3 == 0) {
    iVar3 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  }
  else {
    pCVar4 = EHANDLE::operator->(this_00);
    iVar3 = (*g_engfuncs.pfnIndexOfEdict)(pCVar4->pev->pContainingEntity);
  }
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  iVar5 = iVar3;
  while( true ) {
    iVar1 = iVar5 + ((-(uint)!bReverse & 2) - 1);
    if (gpGlobals->maxClients < iVar1) {
      iVar5 = 1;
    }
    else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      iVar5 = gpGlobals->maxClients;
      if (0 < iVar1) {
        iVar5 = iVar1;
      }
    }
    pEntity = UTIL_PlayerByIndex(iVar5);
    if ((((pEntity != (CBasePlayer *)0x0) && (pEntity != this)) &&
        ((pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.has_disconnected == 0)) &&
       ((peVar2 = (pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev, peVar2->iuser1 == 0 &&
        ((peVar2->effects & 0x80) == 0)))) break;
    if (iVar3 == iVar5) {
LAB_000bedf9:
      iVar3 = EHANDLE::operator_int(this_00);
      if (iVar3 != 0) {
        pCVar4 = EHANDLE::operator->(this_00);
        UTIL_SetOrigin((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev,&pCVar4->pev->origin);
        iVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->iuser2;
        pCVar4 = EHANDLE::operator->(this_00);
        iVar5 = (*g_engfuncs.pfnIndexOfEdict)(pCVar4->pev->pContainingEntity);
        if (iVar3 != iVar5) {
          (*g_engfuncs.pfnMessageBegin)
                    (1,gmsgResetFade,(float *)0x0,
                     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          (*g_engfuncs.pfnMessageEnd)();
        }
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (peVar2->iuser1 != 3) {
          pCVar4 = EHANDLE::operator->(this_00);
          iVar3 = (*g_engfuncs.pfnIndexOfEdict)(pCVar4->pev->pContainingEntity);
          peVar2->iuser2 = iVar3;
          return;
        }
      }
      return;
    }
  }
  EHANDLE::operator=(this_00,(CBaseEntity *)pEntity);
  goto LAB_000bedf9;
}


// CBasePlayer::Observer_HandleButtons  @ 000bf2d0  (line 97)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Observer_HandleButtons(CBasePlayer * this) */

void __thiscall CBasePlayer::Observer_HandleButtons(CBasePlayer *this)

{
  int iVar1;
  uint uVar2;
  
  if (gpGlobals->time < this->m_flNextObserverInput) {
    return;
  }
  uVar2 = this->m_afButtonPressed;
  if ((uVar2 & 2) == 0) goto LAB_000bf351;
  iVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->iuser1;
  if (iVar1 == 1) {
LAB_000bf327:
    Observer_SetMode(this,2);
  }
  else if (iVar1 == 2) {
    Observer_SetMode(this,4);
  }
  else if (iVar1 == 4) {
    Observer_SetMode(this,3);
  }
  else if (iVar1 == 3) {
    Observer_SetMode(this,5);
  }
  else {
    if (iVar1 != 5) goto LAB_000bf327;
    Observer_SetMode(this,6);
  }
  this->m_flNextObserverInput = gpGlobals->time + 0.2;
  uVar2 = this->m_afButtonPressed;
LAB_000bf351:
  if ((uVar2 & 1) != 0) {
    Observer_FindNextPlayer(this,false);
    this->m_flNextObserverInput = gpGlobals->time + 0.2;
    uVar2 = this->m_afButtonPressed;
  }
  if ((uVar2 & 0x800) == 0) {
    return;
  }
  Observer_FindNextPlayer(this,true);
  this->m_flNextObserverInput = gpGlobals->time + 0.2;
  return;
}


// CBasePlayer::Observer_CheckTarget  @ 000bf440  (line 144)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Observer_CheckTarget(CBasePlayer * this) */

void __thiscall CBasePlayer::Observer_CheckTarget(CBasePlayer *this)

{
  EHANDLE *this_00;
  int iVar1;
  CBaseEntity *pCVar2;
  CBasePlayer *pCVar3;
  
                    /* Unresolved local var: CBasePlayer * target@[???] */
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->iuser1 != 3) {
    this_00 = &this->m_hObserverTarget;
    iVar1 = EHANDLE::operator_int(this_00);
    if (iVar1 == 0) {
      Observer_FindNextPlayer(this,false);
      iVar1 = EHANDLE::operator_int(this_00);
      if (iVar1 == 0) {
                    /* Unresolved local var: int lastMode@[???] */
        iVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->iuser1;
        Observer_SetMode(this,3);
        this->m_iObserverLastMode = iVar1;
        return;
      }
    }
    pCVar2 = EHANDLE::operator->(this_00);
    iVar1 = (*g_engfuncs.pfnIndexOfEdict)(pCVar2->pev->pContainingEntity);
    pCVar3 = UTIL_PlayerByIndex(iVar1);
    if (pCVar3 == (CBasePlayer *)0x0) {
      Observer_FindNextPlayer(this,false);
    }
  }
  return;
}


// CBasePlayer::Observer_CheckProperties  @ 000beef0  (line 191)

/* DWARF original prototype: void Observer_CheckProperties(CBasePlayer * this) */

void __thiscall CBasePlayer::Observer_CheckProperties(CBasePlayer *this)

{
  int iVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  CBasePlayer *pCVar4;
  
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->iuser1 == 4) {
    iVar2 = EHANDLE::operator_int(&this->m_hObserverTarget);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBasePlayer * target@[???]
                       Unresolved local var: int weapon@[???] */
      pCVar3 = EHANDLE::operator->(&this->m_hObserverTarget);
      iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pCVar3->pev->pContainingEntity);
      pCVar4 = UTIL_PlayerByIndex(iVar2);
      if (pCVar4 == (CBasePlayer *)0x0) {
        return;
      }
      if (pCVar4->m_pActiveItem == (CBasePlayerItem *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = pCVar4->m_pActiveItem->m_iId;
      }
      iVar1 = pCVar4->m_iFOV;
      if ((this->m_iFOV == iVar1) && (iVar2 == this->m_iObserverWeapon)) {
        return;
      }
      this->m_iFOV = iVar1;
      this->m_iClientFOV = iVar1;
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgSetFOV,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(this->m_iFOV);
      (*g_engfuncs.pfnMessageEnd)();
      this->m_iObserverWeapon = iVar2;
      goto LAB_000bef30;
    }
  }
  this->m_iFOV = 0x5a;
  if (this->m_iObserverWeapon == 0) {
    return;
  }
  this->m_iObserverWeapon = 0;
LAB_000bef30:
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgCurWeapon,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(1);
  (*g_engfuncs.pfnWriteByte)(this->m_iObserverWeapon);
  (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x000bef87. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Observer_SetMode  @ 000bf060  (line 240)

/* DWARF original prototype: void Observer_SetMode(CBasePlayer * this, int iMode) */

void __thiscall CBasePlayer::Observer_SetMode(CBasePlayer *this,int iMode)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  CBasePlayer *pCVar4;
  int in_GS_OFFSET;
  char local_30 [16];
  int local_20;
  
                    /* Unresolved local var: char[16] modemsg@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->iuser1 == iMode) goto LAB_000bf186;
  this_00 = &this->m_hObserverTarget;
  if (iMode - 1U < 6) {
    iVar2 = EHANDLE::operator_int(this_00);
    if (iVar2 != 0) {
LAB_000bf27d:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar4 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
      if ((((pCVar4 == (CBasePlayer *)0x0) || (this == pCVar4)) ||
          ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.has_disconnected != 0)) ||
         ((peVar1 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev, peVar1->iuser1 != 0 ||
          ((peVar1->effects & 0x80) != 0)))) {
        EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
      }
    }
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->iuser1 = iMode;
    if (iMode != 3) goto LAB_000bf1d0;
  }
  else {
    iVar2 = EHANDLE::operator_int(this_00);
    if (iVar2 != 0) {
      iMode = 4;
      goto LAB_000bf27d;
    }
    iMode = 4;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->iuser1 = 4;
LAB_000bf1d0:
    iVar2 = EHANDLE::operator_int(this_00);
    if (iVar2 == 0) {
      Observer_FindNextPlayer(this,false);
      iVar2 = EHANDLE::operator_int(this_00);
      if (iVar2 == 0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Spec_NoTarget",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->iuser1 = 3;
      }
    }
  }
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->iuser1 == 3) {
    peVar1->iuser2 = 0;
  }
  else {
    pCVar3 = EHANDLE::operator->(this_00);
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pCVar3->pev->pContainingEntity);
    peVar1->iuser2 = iVar2;
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->iuser3 = 0;
  __sprintf_chk(local_30,1,0x10,"#Spec_Mode%i",
                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->iuser1);
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,4,local_30,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_iObserverLastMode = iMode;
  (*g_engfuncs.pfnMessageBegin)(1,gmsgResetFade,(float *)0x0,peVar1->pContainingEntity);
  (*g_engfuncs.pfnMessageEnd)();
LAB_000bf186:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


