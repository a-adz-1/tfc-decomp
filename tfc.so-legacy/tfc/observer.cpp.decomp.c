// Ghidra decompilation of functions from tfc/observer.cpp
// 5 functions, ordered by original source line

// CBasePlayer::Observer_FindNextPlayer  @ 000f82b0  (line 31)

/* DWARF original prototype: void Observer_FindNextPlayer(CBasePlayer * this, bool bReverse) */

void __thiscall CBasePlayer::Observer_FindNextPlayer(CBasePlayer *this,bool bReverse)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  CBasePlayer *pEntity;
  int iVar4;
  
                    /* Unresolved local var: int iStart@[???]
                       Unresolved local var: int iCurrent@[???]
                       Unresolved local var: int iDir@[???] */
  this_00 = &this->m_hObserverTarget;
  iVar2 = EHANDLE::operator_int(this_00);
  if (iVar2 == 0) {
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  }
  else {
    pCVar3 = EHANDLE::operator->(this_00);
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pCVar3->pev->pContainingEntity);
  }
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  iVar4 = iVar2;
  while( true ) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar4 = iVar4 + ((-(uint)!bReverse & 2) - 1);
    if (gpGlobals->maxClients < iVar4) {
      iVar4 = 1;
    }
    else if (iVar4 < 1) {
      iVar4 = gpGlobals->maxClients;
    }
    pEntity = UTIL_PlayerByIndex(iVar4);
    if ((((pEntity != (CBasePlayer *)0x0) && (this != pEntity)) &&
        ((pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.has_disconnected == 0)) &&
       ((peVar1 = (pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev, peVar1->iuser1 == 0 &&
        ((peVar1->effects & 0x80) == 0)))) break;
    if (iVar2 == iVar4) {
      iVar2 = EHANDLE::operator_int(this_00);
joined_r0x000f83c6:
      if (iVar2 != 0) {
        pCVar3 = EHANDLE::operator->(this_00);
        UTIL_SetOrigin((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev,&pCVar3->pev->origin);
        iVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->iuser2;
        pCVar3 = EHANDLE::operator->(this_00);
        iVar4 = (*g_engfuncs.pfnIndexOfEdict)(pCVar3->pev->pContainingEntity);
        if (iVar2 != iVar4) {
          (*g_engfuncs.pfnMessageBegin)
                    (1,gmsgResetFade,(float *)0x0,
                     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          (*g_engfuncs.pfnMessageEnd)();
        }
        peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (peVar1->iuser1 != 3) {
          pCVar3 = EHANDLE::operator->(this_00);
          iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pCVar3->pev->pContainingEntity);
          peVar1->iuser2 = iVar2;
          return;
        }
      }
      return;
    }
  }
  EHANDLE::operator=(this_00,(CBaseEntity *)pEntity);
  iVar2 = EHANDLE::operator_int(this_00);
  goto joined_r0x000f83c6;
}


// CBasePlayer::Observer_HandleButtons  @ 000f88c0  (line 97)

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
  if ((uVar2 & 2) == 0) goto LAB_000f8943;
  iVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->iuser1;
  if (iVar1 == 1) {
LAB_000f8919:
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
    if (iVar1 != 5) goto LAB_000f8919;
    Observer_SetMode(this,6);
  }
  this->m_flNextObserverInput = gpGlobals->time + 0.2;
  uVar2 = this->m_afButtonPressed;
LAB_000f8943:
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


// CBasePlayer::Observer_CheckTarget  @ 000f8810  (line 144)

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


// CBasePlayer::Observer_CheckProperties  @ 000f8480  (line 191)

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
                       Unresolved local var: int weapon@[DW_OP_reg6(ESI)] */
      pCVar3 = EHANDLE::operator->(&this->m_hObserverTarget);
      iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pCVar3->pev->pContainingEntity);
      pCVar4 = UTIL_PlayerByIndex(iVar2);
      if (pCVar4 == (CBasePlayer *)0x0) {
        return;
      }
      iVar2 = 0;
      if (pCVar4->m_pActiveItem != (CBasePlayerItem *)0x0) {
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
      goto LAB_000f84c0;
    }
  }
  this->m_iFOV = 0x5a;
  if (this->m_iObserverWeapon == 0) {
    return;
  }
  this->m_iObserverWeapon = 0;
LAB_000f84c0:
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgCurWeapon,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(1);
  (*g_engfuncs.pfnWriteByte)(this->m_iObserverWeapon);
  (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x000f851c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Observer_SetMode  @ 000f85f0  (line 240)

/* DWARF original prototype: void Observer_SetMode(CBasePlayer * this, int iMode) */

void __thiscall CBasePlayer::Observer_SetMode(CBasePlayer *this,int iMode)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  CBasePlayer *pCVar4;
  char local_2c [28];
  
                    /* Unresolved local var: char[16] modemsg@[???] */
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->iuser1 != iMode) {
    this_00 = &this->m_hObserverTarget;
    if (5 < iMode - 1U) {
      iMode = 4;
    }
    iVar2 = EHANDLE::operator_int(this_00);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((iVar2 != 0) &&
       ((((pCVar4 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(this_00),
          pCVar4 == (CBasePlayer *)0x0 || (this == pCVar4)) ||
         ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_disconnected != 0)) ||
        ((peVar1 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev, peVar1->iuser1 != 0 ||
         ((peVar1->effects & 0x80) != 0)))))) {
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->iuser1 = iMode;
    if ((iMode != 3) && (iVar2 = EHANDLE::operator_int(this_00), iVar2 == 0)) {
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
    sprintf(local_2c,"#Spec_Mode%i",
            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->iuser1);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,local_2c,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_iObserverLastMode = iMode;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgResetFade,(float *)0x0,peVar1->pContainingEntity);
    (*g_engfuncs.pfnMessageEnd)();
  }
  return;
}


