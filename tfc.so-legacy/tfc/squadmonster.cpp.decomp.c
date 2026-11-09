// Ghidra decompilation of functions from tfc/squadmonster.cpp
// 21 functions, ordered by original source line

// CSquadMonster::Restore  @ 00123df0  (line 40)

/* DWARF original prototype: int Restore(CSquadMonster * this, CRestore * restore) */

int __thiscall CSquadMonster::Restore(CSquadMonster *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CSquadMonster",this,m_SaveData,5);
  }
  return iVar2;
}


// CSquadMonster::Save  @ 00123e50  (line 40)

/* DWARF original prototype: int Save(CSquadMonster * this, CSave * save) */

int __thiscall CSquadMonster::Save(CSquadMonster *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CSquadMonster",this,m_SaveData,5);
  }
  return iVar2;
}


// CSquadMonster::OccupySlot  @ 00125ab0  (line 48)

/* DWARF original prototype: BOOL OccupySlot(CSquadMonster * this, int iDesiredSlots) */

BOOL __thiscall CSquadMonster::OccupySlot(CSquadMonster *this,int iDesiredSlots)

{
  uint uVar1;
  int iVar2;
  BOOL BVar3;
  CSquadMonster *pCVar4;
  uint uVar5;
  BOOL BVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iMask@[???]
                       Unresolved local var: int iSquadSlots@[???]
                       Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg0(EAX)] */
  BVar6 = 1;
  iVar2 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar2 != 0) {
    BVar3 = SquadEnemySplit(this);
    if (BVar3 == 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
      pCVar4 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
      if (pCVar4 == (CSquadMonster *)0x0) {
        pCVar4 = this;
      }
      BVar6 = 0;
      uVar1 = pCVar4->m_afSquadSlots;
      if (uVar1 != iDesiredSlots) {
        if (((iDesiredSlots & 1U) == 0) || ((uVar1 & 1) != 0)) {
          if (((iDesiredSlots & 2U) == 0) || ((uVar1 & 2) != 0)) {
            if (((iDesiredSlots & 4U) == 0) || ((uVar1 & 4) != 0)) {
              if (((iDesiredSlots & 8U) == 0) || ((uVar1 & 8) != 0)) {
                if (((iDesiredSlots & 0x10U) == 0) || ((uVar1 & 0x10) != 0)) {
                  if (((iDesiredSlots & 0x20U) == 0) || ((uVar1 & 0x20) != 0)) {
                    if (((iDesiredSlots & 0x40U) == 0) || ((uVar1 & 0x40) != 0)) {
                      if (((iDesiredSlots & 0x80U) == 0) || ((uVar1 & 0x80) != 0)) {
                        if (((iDesiredSlots & 0x100U) == 0) || ((uVar1 & 0x100) != 0)) {
                          if (((iDesiredSlots & 0x200U) == 0) || ((uVar1 & 0x200) != 0)) {
                            if ((iDesiredSlots & 0x400U) == 0) {
                              return 0;
                            }
                            uVar5 = 0x400;
                            if ((uVar1 & 0x400) != 0) {
                              return 0;
                            }
                          }
                          else {
                            uVar5 = 0x200;
                          }
                        }
                        else {
                          uVar5 = 0x100;
                        }
                      }
                      else {
                        uVar5 = 0x80;
                      }
                    }
                    else {
                      uVar5 = 0x40;
                    }
                  }
                  else {
                    uVar5 = 0x20;
                  }
                }
                else {
                  uVar5 = 0x10;
                }
              }
              else {
                uVar5 = 8;
              }
            }
            else {
              uVar5 = 4;
            }
          }
          else {
            uVar5 = 2;
          }
        }
        else {
          uVar5 = 1;
        }
        BVar6 = 1;
        pCVar4->m_afSquadSlots = uVar1 | uVar5;
        this->m_iMySlot = uVar5;
      }
    }
    else {
      this->m_iMySlot = 0x400;
    }
  }
  return BVar6;
}


// CSquadMonster::VacateSlot  @ 00124730  (line 100)

/* DWARF original prototype: void VacateSlot(CSquadMonster * this) */

void __thiscall CSquadMonster::VacateSlot(CSquadMonster *this)

{
  int iVar1;
  CSquadMonster *pCVar2;
  
  if (this->m_iMySlot != 0) {
    iVar1 = EHANDLE::operator_int(&this->m_hSquadLeader);
    if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
      pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
      if (pCVar2 == (CSquadMonster *)0x0) {
        pCVar2 = this;
      }
      pCVar2->m_afSquadSlots = pCVar2->m_afSquadSlots & ~this->m_iMySlot;
      this->m_iMySlot = 0;
      return;
    }
  }
  return;
}


// CSquadMonster::ScheduleChange  @ 001240c0  (line 113)

/* DWARF original prototype: void ScheduleChange(CSquadMonster * this) */

void __thiscall CSquadMonster::ScheduleChange(CSquadMonster *this)

{
  int iVar1;
  CSquadMonster *pCVar2;
  
  if (this->m_iMySlot != 0) {
    iVar1 = EHANDLE::operator_int(&this->m_hSquadLeader);
    if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
      pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
      if (pCVar2 == (CSquadMonster *)0x0) {
        pCVar2 = this;
      }
      pCVar2->m_afSquadSlots = pCVar2->m_afSquadSlots & ~this->m_iMySlot;
      this->m_iMySlot = 0;
      return;
    }
  }
  return;
}


// CSquadMonster::Killed  @ 00124970  (line 121)

/* DWARF original prototype: void Killed(CSquadMonster * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CSquadMonster::Killed(CSquadMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  EHANDLE *this_00;
  int iVar1;
  CSquadMonster *pCVar2;
  
  this_00 = &this->m_hSquadLeader;
  if (this->m_iMySlot != 0) {
    iVar1 = EHANDLE::operator_int(this_00);
    if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
      pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_00);
      if (pCVar2 == (CSquadMonster *)0x0) {
        pCVar2 = this;
      }
      pCVar2->m_afSquadSlots = pCVar2->m_afSquadSlots & ~this->m_iMySlot;
      this->m_iMySlot = 0;
    }
  }
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_00);
    if (pCVar2 == (CSquadMonster *)0x0) {
      pCVar2 = this;
    }
    SquadRemove(pCVar2,this);
  }
  CBaseMonster::Killed(&this->super_CBaseMonster,pevInflictor,pevAttacker,iGib);
  return;
}


// CSquadMonster::SquadRemove  @ 001247a0  (line 142)

/* DWARF original prototype: void SquadRemove(CSquadMonster * this, CSquadMonster * pRemove) */

void __thiscall CSquadMonster::SquadRemove(CSquadMonster *this,CSquadMonster *pRemove)

{
  CSquadMonster *pCVar1;
  CSquadMonster *pCVar2;
  CBaseEntity *pCVar3;
  EHANDLE *this_00;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  pCVar1 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
  if (pCVar1 == (CSquadMonster *)0x0) {
    pCVar1 = this;
  }
  if (pRemove == pCVar1) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CSquadMonster * pMember@[???] */
    pCVar3 = EHANDLE::operator_CBaseEntity_(this->m_hSquadMember);
    if (pCVar3 != (CBaseEntity *)0x0) {
      EHANDLE::operator=((EHANDLE *)&pCVar3[1].goal_activation,(CBaseEntity *)0x0);
      EHANDLE::operator=(this->m_hSquadMember,(CBaseEntity *)0x0);
    }
    pCVar3 = EHANDLE::operator_CBaseEntity_(this->m_hSquadMember + 1);
    if (pCVar3 != (CBaseEntity *)0x0) {
      EHANDLE::operator=((EHANDLE *)&pCVar3[1].goal_activation,(CBaseEntity *)0x0);
      EHANDLE::operator=(this->m_hSquadMember + 1,(CBaseEntity *)0x0);
    }
    pCVar3 = EHANDLE::operator_CBaseEntity_(this->m_hSquadMember + 2);
    if (pCVar3 != (CBaseEntity *)0x0) {
      EHANDLE::operator=((EHANDLE *)&pCVar3[1].goal_activation,(CBaseEntity *)0x0);
      EHANDLE::operator=(this->m_hSquadMember + 2,(CBaseEntity *)0x0);
    }
    pCVar3 = EHANDLE::operator_CBaseEntity_(this->m_hSquadMember + 3);
    if (pCVar3 != (CBaseEntity *)0x0) {
      EHANDLE::operator=((EHANDLE *)&pCVar3[1].goal_activation,(CBaseEntity *)0x0);
      EHANDLE::operator=(this->m_hSquadMember + 3,(CBaseEntity *)0x0);
    }
  }
  else {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg7(EDI)]
                       Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar1 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
    if ((pCVar1 != (CSquadMonster *)0x0) || (pCVar1 = this, this != (CSquadMonster *)0x0)) {
                    /* Unresolved local var: int i@[???] */
      this_00 = pCVar1->m_hSquadMember;
      pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_00);
      if (pCVar2 != this) {
        this_00 = pCVar1->m_hSquadMember + 1;
        pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_00);
        if (this != pCVar2) {
          this_00 = pCVar1->m_hSquadMember + 2;
          pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_00);
          if (this != pCVar2) {
            this_00 = pCVar1->m_hSquadMember + 3;
            pCVar1 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_00);
            if (this != pCVar1) goto LAB_00124840;
          }
        }
      }
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
  }
LAB_00124840:
  EHANDLE::operator=(&pRemove->m_hSquadLeader,(CBaseEntity *)0x0);
  return;
}


// CSquadMonster::SquadAdd  @ 00124a40  (line 185)

/* DWARF original prototype: BOOL SquadAdd(CSquadMonster * this, CSquadMonster * pAdd) */

BOOL __thiscall CSquadMonster::SquadAdd(CSquadMonster *this,CSquadMonster *pAdd)

{
  int iVar1;
  EHANDLE *this_00;
  
                    /* Unresolved local var: int i@[???] */
  this_00 = this->m_hSquadMember;
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    this_00 = this->m_hSquadMember + 1;
    iVar1 = EHANDLE::operator_int(this_00);
    if (iVar1 != 0) {
      this_00 = this->m_hSquadMember + 2;
      iVar1 = EHANDLE::operator_int(this_00);
      if (iVar1 != 0) {
        this_00 = this->m_hSquadMember + 3;
        iVar1 = EHANDLE::operator_int(this_00);
        if (iVar1 != 0) {
          return 0;
        }
      }
    }
  }
  EHANDLE::operator=(this_00,(CBaseEntity *)pAdd);
  EHANDLE::operator=(&pAdd->m_hSquadLeader,(CBaseEntity *)this);
  return 1;
}


// CSquadMonster::SquadPasteEnemyInfo  @ 00124ae0  (line 212)

/* DWARF original prototype: void SquadPasteEnemyInfo(CSquadMonster * this) */

void __thiscall CSquadMonster::SquadPasteEnemyInfo(CSquadMonster *this)

{
  CSquadMonster *pCVar1;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg0(EAX)]
                       Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  pCVar1 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
  if ((pCVar1 != (CSquadMonster *)0x0) || (pCVar1 = this, this != (CSquadMonster *)0x0)) {
    (pCVar1->super_CBaseMonster).m_vecEnemyLKP.x = (this->super_CBaseMonster).m_vecEnemyLKP.x;
    (pCVar1->super_CBaseMonster).m_vecEnemyLKP.y = (this->super_CBaseMonster).m_vecEnemyLKP.y;
    (pCVar1->super_CBaseMonster).m_vecEnemyLKP.z = (this->super_CBaseMonster).m_vecEnemyLKP.z;
  }
  return;
}


// CSquadMonster::SquadCopyEnemyInfo  @ 00124b30  (line 227)

/* DWARF original prototype: void SquadCopyEnemyInfo(CSquadMonster * this) */

void __thiscall CSquadMonster::SquadCopyEnemyInfo(CSquadMonster *this)

{
  CSquadMonster *pCVar1;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg0(EAX)]
                       Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  pCVar1 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
  if ((pCVar1 != (CSquadMonster *)0x0) || (pCVar1 = this, this != (CSquadMonster *)0x0)) {
    (this->super_CBaseMonster).m_vecEnemyLKP.x = (pCVar1->super_CBaseMonster).m_vecEnemyLKP.x;
    (this->super_CBaseMonster).m_vecEnemyLKP.y = (pCVar1->super_CBaseMonster).m_vecEnemyLKP.y;
    (this->super_CBaseMonster).m_vecEnemyLKP.z = (pCVar1->super_CBaseMonster).m_vecEnemyLKP.z;
  }
  return;
}


// CSquadMonster::SquadMakeEnemy  @ 00124b80  (line 240)

/* DWARF original prototype: void SquadMakeEnemy(CSquadMonster * this, CBaseEntity * pEnemy) */

void __thiscall CSquadMonster::SquadMakeEnemy(CSquadMonster *this,CBaseEntity *pEnemy)

{
  EHANDLE *pEVar1;
  int *piVar2;
  entvars_t *peVar3;
  vec_t vVar4;
  int iVar5;
  CSquadMonster *this_00;
  CBaseMonster *pCVar6;
  CBaseEntity *pCVar7;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg3(EBX)] */
  iVar5 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar5 != 0) {
    if (pEnemy == (CBaseEntity *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00124e42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*g_engfuncs.pfnAlertMessage)(at_console,"ERROR: SquadMakeEnemy() - pEnemy is NULL!\n");
      return;
    }
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    this_00 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
    if (this_00 == (CSquadMonster *)0x0) {
      this_00 = this;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CSquadMonster * pMember@[???] */
    pCVar6 = (CBaseMonster *)EHANDLE::operator_CBaseEntity_(this_00->m_hSquadMember);
    if (pCVar6 != (CBaseMonster *)0x0) {
      pEVar1 = &pCVar6->m_hEnemy;
      pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
      if ((pCVar7 != pEnemy) && ((pCVar6->m_afConditions & 0x10) == 0)) {
        iVar5 = EHANDLE::operator_int(pEVar1);
        if (iVar5 != 0) {
          pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
          CBaseMonster::PushEnemy(pCVar6,pCVar7,&pCVar6->m_vecEnemyLKP);
        }
        EHANDLE::operator=(pEVar1,pEnemy);
        peVar3 = pEnemy->pev;
        (pCVar6->m_vecEnemyLKP).x = (peVar3->origin).x;
        (pCVar6->m_vecEnemyLKP).y = (peVar3->origin).y;
        vVar4 = (peVar3->origin).z;
        pCVar6->m_afConditions = pCVar6->m_afConditions | 0x10000;
        (pCVar6->m_vecEnemyLKP).z = vVar4;
      }
    }
    pCVar6 = (CBaseMonster *)EHANDLE::operator_CBaseEntity_(this_00->m_hSquadMember + 1);
    if (pCVar6 != (CBaseMonster *)0x0) {
      pEVar1 = &pCVar6->m_hEnemy;
      pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
      if ((pCVar7 != pEnemy) && ((pCVar6->m_afConditions & 0x10) == 0)) {
        iVar5 = EHANDLE::operator_int(pEVar1);
        if (iVar5 != 0) {
          pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
          CBaseMonster::PushEnemy(pCVar6,pCVar7,&pCVar6->m_vecEnemyLKP);
        }
        EHANDLE::operator=(pEVar1,pEnemy);
        peVar3 = pEnemy->pev;
        (pCVar6->m_vecEnemyLKP).x = (peVar3->origin).x;
        (pCVar6->m_vecEnemyLKP).y = (peVar3->origin).y;
        vVar4 = (peVar3->origin).z;
        pCVar6->m_afConditions = pCVar6->m_afConditions | 0x10000;
        (pCVar6->m_vecEnemyLKP).z = vVar4;
      }
    }
    pCVar6 = (CBaseMonster *)EHANDLE::operator_CBaseEntity_(this_00->m_hSquadMember + 2);
    if (pCVar6 != (CBaseMonster *)0x0) {
      pEVar1 = &pCVar6->m_hEnemy;
      pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
      if ((pCVar7 != pEnemy) && ((pCVar6->m_afConditions & 0x10) == 0)) {
        iVar5 = EHANDLE::operator_int(pEVar1);
        if (iVar5 != 0) {
          pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
          CBaseMonster::PushEnemy(pCVar6,pCVar7,&pCVar6->m_vecEnemyLKP);
        }
        EHANDLE::operator=(pEVar1,pEnemy);
        peVar3 = pEnemy->pev;
        (pCVar6->m_vecEnemyLKP).x = (peVar3->origin).x;
        (pCVar6->m_vecEnemyLKP).y = (peVar3->origin).y;
        vVar4 = (peVar3->origin).z;
        pCVar6->m_afConditions = pCVar6->m_afConditions | 0x10000;
        (pCVar6->m_vecEnemyLKP).z = vVar4;
      }
    }
    pCVar6 = (CBaseMonster *)EHANDLE::operator_CBaseEntity_(this_00->m_hSquadMember + 3);
    if (pCVar6 != (CBaseMonster *)0x0) {
      pEVar1 = &pCVar6->m_hEnemy;
      pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
      if ((pCVar7 != pEnemy) && ((pCVar6->m_afConditions & 0x10) == 0)) {
        iVar5 = EHANDLE::operator_int(pEVar1);
        if (iVar5 != 0) {
          pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
          CBaseMonster::PushEnemy(pCVar6,pCVar7,&pCVar6->m_vecEnemyLKP);
        }
        EHANDLE::operator=(pEVar1,pEnemy);
        peVar3 = pEnemy->pev;
        (pCVar6->m_vecEnemyLKP).x = (peVar3->origin).x;
        (pCVar6->m_vecEnemyLKP).y = (peVar3->origin).y;
        vVar4 = (peVar3->origin).z;
        pCVar6->m_afConditions = pCVar6->m_afConditions | 0x10000;
        (pCVar6->m_vecEnemyLKP).z = vVar4;
      }
    }
    if (this_00 != (CSquadMonster *)0x0) {
      pEVar1 = &(this_00->super_CBaseMonster).m_hEnemy;
      pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
      if ((pCVar7 != pEnemy) && (((this_00->super_CBaseMonster).m_afConditions & 0x10) == 0)) {
        iVar5 = EHANDLE::operator_int(pEVar1);
        if (iVar5 != 0) {
          pCVar7 = EHANDLE::operator_CBaseEntity_(pEVar1);
          CBaseMonster::PushEnemy
                    (&this_00->super_CBaseMonster,pCVar7,
                     &(this_00->super_CBaseMonster).m_vecEnemyLKP);
        }
        EHANDLE::operator=(pEVar1,pEnemy);
        peVar3 = pEnemy->pev;
        (this_00->super_CBaseMonster).m_vecEnemyLKP.x = (peVar3->origin).x;
        (this_00->super_CBaseMonster).m_vecEnemyLKP.y = (peVar3->origin).y;
        vVar4 = (peVar3->origin).z;
        piVar2 = &(this_00->super_CBaseMonster).m_afConditions;
        *piVar2 = *piVar2 | 0x10000;
        (this_00->super_CBaseMonster).m_vecEnemyLKP.z = vVar4;
      }
    }
  }
  return;
}


// CSquadMonster::SquadCount  @ 00124f80  (line 281)

/* DWARF original prototype: int SquadCount(CSquadMonster * this) */

int __thiscall CSquadMonster::SquadCount(CSquadMonster *this)

{
  int iVar1;
  CSquadMonster *pCVar2;
  CBaseEntity *pCVar3;
  CBaseEntity *pCVar4;
  int iVar5;
  uint uVar6;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???]
                       Unresolved local var: int squadCount@[???] */
  iVar5 = 0;
  iVar1 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
    if (pCVar2 == (CSquadMonster *)0x0) {
      pCVar2 = this;
    }
                    /* Unresolved local var: int i@[???] */
    pCVar3 = EHANDLE::operator_CBaseEntity_(pCVar2->m_hSquadMember);
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar2->m_hSquadMember + 1);
    uVar6 = (uint)(pCVar3 != (CBaseEntity *)0x0);
    if (pCVar4 != (CBaseEntity *)0x0) {
      uVar6 = (pCVar3 != (CBaseEntity *)0x0) + 1;
    }
    pCVar3 = EHANDLE::operator_CBaseEntity_(pCVar2->m_hSquadMember + 2);
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar2->m_hSquadMember + 3);
    iVar5 = (((uVar6 - (pCVar3 == (CBaseEntity *)0x0)) - (uint)(pCVar4 == (CBaseEntity *)0x0)) + 3)
            - (uint)(pCVar2 == (CSquadMonster *)0x0);
  }
  return iVar5;
}


// CSquadMonster::SquadRecruit  @ 00125030  (line 304)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int SquadRecruit(CSquadMonster * this, int searchRadius, int
   maxMembers) */

int __thiscall CSquadMonster::SquadRecruit(CSquadMonster *this,int searchRadius,int maxMembers)

{
  EHANDLE *this_00;
  int iVar1;
  int iVar2;
  CSquadMonster *pCVar3;
  entvars_t *peVar4;
  CBaseEntity *pCVar5;
  entvars_t *peVar6;
  int local_80;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int squadCount@[???]
                       Unresolved local var: int iMyClass@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[10])(this);
  this_00 = &this->m_hSquadLeader;
  iVar2 = EHANDLE::operator_int(this_00);
  local_80 = 0;
  if ((iVar2 == 0) && (1 < maxMembers)) {
    EHANDLE::operator=(this_00,(CBaseEntity *)this);
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar6->netname == 0) {
      pCVar5 = (CBaseEntity *)0x0;
      local_80 = 1;
LAB_001250bb:
      pCVar5 = UTIL_FindEntityInSphere(pCVar5,&peVar6->origin,(float)searchRadius);
      if (pCVar5 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CSquadMonster * pRecruit@[???] */
        pCVar3 = (CSquadMonster *)(*pCVar5->_vptr_CBaseEntity[0x14])(pCVar5);
        if ((((pCVar3 != this) && (pCVar3 != (CSquadMonster *)0x0)) &&
            (iVar2 = (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pCVar3),
            iVar2 != 0)) && ((pCVar3->super_CBaseMonster).m_pCine == (CCineMonster *)0x0)) {
          iVar2 = EHANDLE::operator_int(&pCVar3->m_hSquadLeader);
          if ((iVar2 != 0) ||
             (iVar2 = (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pCVar3),
             iVar2 != iVar1)) goto LAB_001250b8;
          if (iVar1 == 7) goto LAB_001253ec;
          peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          goto LAB_0012513c;
        }
        goto LAB_001250b8;
      }
      goto LAB_00125387;
    }
    pCVar5 = UTIL_FindEntityByString
                       ((CBaseEntity *)0x0,"netname",gpGlobals->pStringBase + peVar6->netname);
    if (pCVar5 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CSquadMonster * pRecruit@[???]
                       Unresolved local var: int i@[???] */
      local_80 = 1;
      do {
        pCVar3 = (CSquadMonster *)(*pCVar5->_vptr_CBaseEntity[0x14])(pCVar5);
        if (pCVar3 != (CSquadMonster *)0x0) {
          iVar2 = EHANDLE::operator_int(&pCVar3->m_hSquadLeader);
          if (((iVar2 == 0) &&
              (iVar2 = (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pCVar3),
              iVar2 == iVar1)) && (pCVar3 != this)) {
            iVar2 = EHANDLE::operator_int(this->m_hSquadMember);
            if (iVar2 == 0) {
              iVar2 = 0;
            }
            else {
              iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 1);
              if (iVar2 == 0) {
                iVar2 = 1;
              }
              else {
                iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 2);
                if (iVar2 == 0) {
                  iVar2 = 2;
                }
                else {
                  iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 3);
                  if (iVar2 != 0) break;
                  iVar2 = 3;
                }
              }
            }
            EHANDLE::operator=((EHANDLE *)&this->m_hSquadMember[iVar2].m_pent,(CBaseEntity *)pCVar3)
            ;
            EHANDLE::operator=(&pCVar3->m_hSquadLeader,(CBaseEntity *)this);
            local_80 = local_80 + 1;
          }
        }
        pCVar5 = UTIL_FindEntityByString
                           (pCVar5,"netname",
                            gpGlobals->pStringBase +
                            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->netname);
      } while (pCVar5 != (CBaseEntity *)0x0);
LAB_00125387:
      if (local_80 != 1) {
        return local_80;
      }
    }
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    local_80 = 1;
  }
  return local_80;
LAB_001253ec:
  peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar2 = strcmp(gpGlobals->pStringBase + peVar6->classname,
                 gpGlobals->pStringBase + peVar4->classname);
  if (iVar2 == 0) {
LAB_0012513c:
    if (peVar4->netname == 0) {
                    /* Unresolved local var: TraceResult tr@[???] */
      local_34.z = (peVar6->view_ofs).z;
      local_28[0].z = (peVar4->origin).z + local_34.z;
      local_34.y = (peVar6->view_ofs).y;
      local_28[0].y = (peVar4->origin).y + local_34.y;
      local_34.x = (peVar6->view_ofs).x;
      local_28[0].x = (peVar4->origin).x + local_34.x;
      local_34.z = local_34.z + (peVar6->origin).z;
      local_34.y = local_34.y + (peVar6->origin).y;
      local_34.x = local_34.x + (peVar6->origin).x;
      UTIL_TraceLine(&local_34,local_28,ignore_monsters,peVar4->pContainingEntity,&local_6c);
      if (local_6c.flFraction == 1.0) {
                    /* Unresolved local var: int i@[???] */
        iVar2 = EHANDLE::operator_int(this->m_hSquadMember);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 1);
          if (iVar2 == 0) {
            iVar2 = 1;
          }
          else {
            iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 2);
            if (iVar2 == 0) {
              iVar2 = 2;
            }
            else {
              iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 3);
              if (iVar2 != 0) goto LAB_00125387;
              iVar2 = 3;
            }
          }
        }
        EHANDLE::operator=((EHANDLE *)&this->m_hSquadMember[iVar2].m_pent,(CBaseEntity *)pCVar3);
        EHANDLE::operator=(&pCVar3->m_hSquadLeader,(CBaseEntity *)this);
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        local_80 = local_80 + 1;
      }
      else {
LAB_001250b8:
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
    }
  }
  goto LAB_001250bb;
}


// CSquadMonster::CheckEnemy  @ 00124130  (line 384)

/* DWARF original prototype: int CheckEnemy(CSquadMonster * this, CBaseEntity * pEnemy) */

int __thiscall CSquadMonster::CheckEnemy(CSquadMonster *this,CBaseEntity *pEnemy)

{
  EHANDLE *this_00;
  EHANDLE *this_01;
  CBaseEntity *pCVar1;
  int iVar2;
  int iVar3;
  CSquadMonster *pCVar4;
  CBaseEntity *pCVar5;
  
                    /* Unresolved local var: int iUpdatedLKP@[???] */
  this_00 = &(this->super_CBaseMonster).m_hEnemy;
  this_01 = &this->m_hSquadLeader;
  pCVar1 = EHANDLE::operator_CBaseEntity_(this_00);
  iVar2 = CBaseMonster::CheckEnemy(&this->super_CBaseMonster,pCVar1);
  iVar3 = EHANDLE::operator_int(this_01);
  if (iVar3 != 0) {
    pCVar1 = EHANDLE::operator_CBaseEntity_(this_00);
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar4 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_01);
    if (pCVar4 == (CSquadMonster *)0x0) {
      pCVar4 = this;
    }
    pCVar5 = EHANDLE::operator_CBaseEntity_(&(pCVar4->super_CBaseMonster).m_hEnemy);
    if (pCVar1 == pCVar5) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg0(EAX)]
                       Unresolved local var: CSquadMonster * pSquadLeader@[???] */
      if (iVar2 == 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg0(EAX)]
                       Unresolved local var: CSquadMonster * pSquadLeader@[???] */
        pCVar4 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_01);
        if ((pCVar4 != (CSquadMonster *)0x0) || (pCVar4 = this, this != (CSquadMonster *)0x0)) {
          (this->super_CBaseMonster).m_vecEnemyLKP.x = (pCVar4->super_CBaseMonster).m_vecEnemyLKP.x;
          (this->super_CBaseMonster).m_vecEnemyLKP.y = (pCVar4->super_CBaseMonster).m_vecEnemyLKP.y;
          (this->super_CBaseMonster).m_vecEnemyLKP.z = (pCVar4->super_CBaseMonster).m_vecEnemyLKP.z;
        }
      }
      else {
        pCVar4 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_01);
        if ((pCVar4 != (CSquadMonster *)0x0) || (pCVar4 = this, this != (CSquadMonster *)0x0)) {
          (pCVar4->super_CBaseMonster).m_vecEnemyLKP.x = (this->super_CBaseMonster).m_vecEnemyLKP.x;
          (pCVar4->super_CBaseMonster).m_vecEnemyLKP.y = (this->super_CBaseMonster).m_vecEnemyLKP.y;
          (pCVar4->super_CBaseMonster).m_vecEnemyLKP.z = (this->super_CBaseMonster).m_vecEnemyLKP.z;
        }
      }
    }
  }
  return iVar2;
}


// CSquadMonster::StartMonster  @ 00124250  (line 411)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartMonster(CSquadMonster * this) */

void __thiscall CSquadMonster::StartMonster(CSquadMonster *this)

{
  EHANDLE *this_00;
  int iVar1;
  int iVar2;
  CSquadMonster *pCVar3;
  entvars_t *peVar4;
  entvars_t *peVar5;
  CBaseEntity *pCVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  byte bVar10;
  int local_78;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
  bVar10 = 0;
  CBaseMonster::StartMonster(&this->super_CBaseMonster);
  if (((this->super_CBaseMonster).m_afCapability & 8) == 0) {
    return;
  }
  this_00 = &this->m_hSquadLeader;
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    return;
  }
                    /* Unresolved local var: int iSquadSize@[???] */
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar5->netname != 0) && ((peVar5->spawnflags & 0x20) == 0)) {
    return;
  }
                    /* Unresolved local var: int iSquadSize@[DW_OP_breg4(ESP): +52]
                       Unresolved local var: int squadCount@[???]
                       Unresolved local var: int iMyClass@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[10])(this);
  iVar2 = EHANDLE::operator_int(this_00);
  if (iVar2 != 0) goto LAB_0012460a;
  EHANDLE::operator=(this_00,(CBaseEntity *)this);
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar5->netname == 0) {
    pCVar6 = (CBaseEntity *)0x0;
    local_78 = 1;
LAB_00124303:
    pCVar6 = UTIL_FindEntityInSphere(pCVar6,&peVar5->origin,1024.0);
    if (pCVar6 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CSquadMonster * pRecruit@[???] */
      pCVar3 = (CSquadMonster *)(*pCVar6->_vptr_CBaseEntity[0x14])(pCVar6);
      if ((((this != pCVar3) && (pCVar3 != (CSquadMonster *)0x0)) &&
          (iVar2 = (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pCVar3), iVar2 != 0
          )) && ((pCVar3->super_CBaseMonster).m_pCine == (CCineMonster *)0x0)) {
        iVar2 = EHANDLE::operator_int(&pCVar3->m_hSquadLeader);
        if ((iVar2 != 0) ||
           (iVar2 = (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pCVar3),
           iVar1 != iVar2)) goto LAB_00124300;
        if (iVar1 == 7) goto LAB_001246bd;
        peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        goto LAB_00124384;
      }
      goto LAB_00124300;
    }
    goto LAB_001245cb;
  }
  pCVar6 = UTIL_FindEntityByString
                     ((CBaseEntity *)0x0,"netname",gpGlobals->pStringBase + peVar5->netname);
  if (pCVar6 == (CBaseEntity *)0x0) {
LAB_00124670:
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    local_78 = 1;
  }
  else {
                    /* Unresolved local var: CSquadMonster * pRecruit@[???]
                       Unresolved local var: int i@[???] */
    local_78 = 1;
    do {
      pCVar3 = (CSquadMonster *)(*pCVar6->_vptr_CBaseEntity[0x14])(pCVar6);
      if (pCVar3 != (CSquadMonster *)0x0) {
        iVar2 = EHANDLE::operator_int(&pCVar3->m_hSquadLeader);
        if (((iVar2 == 0) &&
            (iVar2 = (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pCVar3),
            iVar1 == iVar2)) && (this != pCVar3)) {
          iVar2 = EHANDLE::operator_int(this->m_hSquadMember);
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 1);
            if (iVar2 == 0) {
              iVar2 = 1;
            }
            else {
              iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 2);
              if (iVar2 == 0) {
                iVar2 = 2;
              }
              else {
                iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 3);
                if (iVar2 != 0) break;
                iVar2 = 3;
              }
            }
          }
          EHANDLE::operator=((EHANDLE *)&this->m_hSquadMember[iVar2].m_pent,(CBaseEntity *)pCVar3);
          EHANDLE::operator=(&pCVar3->m_hSquadLeader,(CBaseEntity *)this);
          local_78 = local_78 + 1;
        }
      }
      pCVar6 = UTIL_FindEntityByString
                         (pCVar6,"netname",
                          gpGlobals->pStringBase +
                          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->netname);
    } while (pCVar6 != (CBaseEntity *)0x0);
LAB_001245cb:
    if (local_78 == 1) goto LAB_00124670;
  }
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"Squad of %d %s formed\n",local_78,
             gpGlobals->pStringBase +
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->classname);
LAB_0012460a:
  pCVar3 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_00);
  if (pCVar3 == this) {
    bVar9 = gpGlobals->pStringBase +
            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->classname == (char *)0x0;
    iVar1 = 0x14;
    pcVar7 = gpGlobals->pStringBase +
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->classname;
    pcVar8 = "monster_human_grunt";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar9 = *pcVar7 == *pcVar8;
      pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
      pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    if (bVar9) {
      CBaseAnimating::SetBodygroup((CBaseAnimating *)this,1,1);
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->skin = 0;
    }
  }
  return;
LAB_001246bd:
  peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar2 = strcmp(gpGlobals->pStringBase + peVar5->classname,
                 gpGlobals->pStringBase + peVar4->classname);
  if (iVar2 == 0) {
LAB_00124384:
    if (peVar4->netname == 0) {
                    /* Unresolved local var: TraceResult tr@[???] */
      local_28[0].z = (peVar5->view_ofs).z;
      local_34.z = (peVar4->origin).z + local_28[0].z;
      local_28[0].y = (peVar5->view_ofs).y;
      local_34.y = (peVar4->origin).y + local_28[0].y;
      local_28[0].x = (peVar5->view_ofs).x;
      local_34.x = (peVar4->origin).x + local_28[0].x;
      local_28[0].z = local_28[0].z + (peVar5->origin).z;
      local_28[0].y = local_28[0].y + (peVar5->origin).y;
      local_28[0].x = local_28[0].x + (peVar5->origin).x;
      UTIL_TraceLine(local_28,&local_34,ignore_monsters,peVar4->pContainingEntity,&local_6c);
      if (local_6c.flFraction == 1.0) {
                    /* Unresolved local var: int i@[???] */
        iVar2 = EHANDLE::operator_int(this->m_hSquadMember);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 1);
          if (iVar2 == 0) {
            iVar2 = 1;
          }
          else {
            iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 2);
            if (iVar2 == 0) {
              iVar2 = 2;
            }
            else {
              iVar2 = EHANDLE::operator_int(this->m_hSquadMember + 3);
              if (iVar2 != 0) goto LAB_001245cb;
              iVar2 = 3;
            }
          }
        }
        EHANDLE::operator=((EHANDLE *)&this->m_hSquadMember[iVar2].m_pent,(CBaseEntity *)pCVar3);
        EHANDLE::operator=(&pCVar3->m_hSquadLeader,(CBaseEntity *)this);
        local_78 = local_78 + 1;
      }
LAB_00124300:
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
  }
  goto LAB_00124303;
}


// CSquadMonster::NoFriendlyFire  @ 00125460  (line 449)

/* DWARF original prototype: BOOL NoFriendlyFire(CSquadMonster * this) */

BOOL __thiscall CSquadMonster::NoFriendlyFire(CSquadMonster *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  CBaseEntity *pCVar5;
  CSquadMonster *pCVar6;
  CSquadMonster *pCVar7;
  BOOL BVar8;
  BOOL BVar9;
  int local_b4;
  undefined1 local_a0 [20];
  undefined1 local_8c [20];
  undefined1 local_78 [20];
  float local_64;
  float local_60;
  Vector local_5c;
  Vector local_50;
  float local_44;
  float local_40;
  float local_3c;
  Vector local_38;
  Vector local_2c [2];
  
                    /* Unresolved local var: CPlane backPlane@[???]
                       Unresolved local var: CPlane leftPlane@[???]
                       Unresolved local var: CPlane rightPlane@[???]
                       Unresolved local var: Vector vecLeftSide@[???]
                       Unresolved local var: Vector vecRightSide@[???]
                       Unresolved local var: Vector v_left@[???]
                       Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg7(EDI)] */
  BVar9 = 1;
  iVar4 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar4 != 0) {
    BVar9 = 0;
    CPlane::CPlane((CPlane *)local_a0);
    CPlane::CPlane((CPlane *)local_8c);
    CPlane::CPlane((CPlane *)local_78);
    this_00 = &(this->super_CBaseMonster).m_hEnemy;
    iVar4 = EHANDLE::operator_int(this_00);
    if (iVar4 != 0) {
      pCVar5 = EHANDLE::operator->(this_00);
      (*pCVar5->_vptr_CBaseEntity[0x32])(&local_40,pCVar5);
      local_38.z = local_3c - *(float *)(local_b4 + 0x10);
      local_38.y = local_40 - *(float *)(local_b4 + 0xc);
      local_38.x = local_44 - *(float *)(local_b4 + 8);
      UTIL_VecToAngles(local_2c,&local_38);
      UTIL_MakeVectors(local_2c);
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_5c.x = (peVar1->size).x * 1.5;
      fVar2 = (gpGlobals->v_right).z * local_5c.x;
      local_50.y = (gpGlobals->v_right).y;
      fVar3 = local_5c.x * local_50.y;
      local_50.x = (gpGlobals->v_right).x;
      local_5c.x = local_5c.x * local_50.x;
      local_5c.z = (peVar1->origin).z;
      local_5c.y = (peVar1->origin).y;
      local_78._16_4_ = (peVar1->origin).x - local_5c.x;
      local_64 = local_5c.y - fVar3;
      local_60 = local_5c.z - fVar2;
      local_5c.x = local_5c.x + (peVar1->origin).x;
      local_5c.y = local_5c.y + fVar3;
      local_5c.z = local_5c.z + fVar2;
      local_50.x = -local_50.x;
      local_50.y = -local_50.y;
      local_50.z = -(gpGlobals->v_right).z;
      CPlane::InitializePlane
                ((CPlane *)(local_a0 + 0x10),&gpGlobals->v_right,(Vector *)(local_78 + 0x10));
      CPlane::InitializePlane((CPlane *)(local_8c + 0x10),&local_50,&local_5c);
      CPlane::InitializePlane
                ((CPlane *)local_a0,&gpGlobals->v_forward,
                 &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->origin);
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
      pCVar6 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
      if (pCVar6 == (CSquadMonster *)0x0) {
        pCVar6 = this;
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CSquadMonster * pMember@[???] */
      pCVar7 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(pCVar6->m_hSquadMember);
      if ((((pCVar7 == (CSquadMonster *)0x0) || (this == pCVar7)) ||
          (BVar8 = CPlane::PointInFront
                             ((CPlane *)local_a0,
                              &((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->origin), BVar8 == 0)) ||
         ((BVar8 = CPlane::PointInFront
                             ((CPlane *)(local_a0 + 0x10),
                              &((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->origin), BVar8 == 0 ||
          (BVar8 = CPlane::PointInFront
                             ((CPlane *)(local_8c + 0x10),
                              &((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->origin), BVar8 == 0)))) {
        pCVar7 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(pCVar6->m_hSquadMember + 1);
        if (((this != pCVar7) &&
            ((pCVar7 != (CSquadMonster *)0x0 &&
             (BVar9 = CPlane::PointInFront
                                ((CPlane *)local_a0,
                                 &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                  origin), BVar9 != 0)))) &&
           ((BVar9 = CPlane::PointInFront
                               ((CPlane *)(local_a0 + 0x10),
                                &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                 origin), BVar9 != 0 &&
            (BVar9 = CPlane::PointInFront
                               ((CPlane *)(local_8c + 0x10),
                                &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                 origin), BVar9 != 0)))) {
          return 0;
        }
        pCVar7 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(pCVar6->m_hSquadMember + 2);
        if ((((this != pCVar7) && (pCVar7 != (CSquadMonster *)0x0)) &&
            (BVar9 = CPlane::PointInFront
                               ((CPlane *)local_a0,
                                &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                 origin), BVar9 != 0)) &&
           ((BVar9 = CPlane::PointInFront
                               ((CPlane *)(local_a0 + 0x10),
                                &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                 origin), BVar9 != 0 &&
            (BVar9 = CPlane::PointInFront
                               ((CPlane *)(local_8c + 0x10),
                                &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                 origin), BVar9 != 0)))) {
          return 0;
        }
        pCVar7 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(pCVar6->m_hSquadMember + 3);
        if (((this != pCVar7) && (pCVar7 != (CSquadMonster *)0x0)) &&
           ((BVar9 = CPlane::PointInFront
                               ((CPlane *)local_a0,
                                &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                 origin), BVar9 != 0 &&
            ((BVar9 = CPlane::PointInFront
                                ((CPlane *)(local_a0 + 0x10),
                                 &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                  origin), BVar9 != 0 &&
             (BVar9 = CPlane::PointInFront
                                ((CPlane *)(local_8c + 0x10),
                                 &((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                  origin), BVar9 != 0)))))) {
          return 0;
        }
        BVar9 = 1;
        if (this != pCVar6) {
          BVar9 = CPlane::PointInFront
                            ((CPlane *)local_a0,
                             &((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->origin);
          if (((BVar9 == 0) ||
              (BVar9 = CPlane::PointInFront
                                 ((CPlane *)(local_a0 + 0x10),
                                  &((pCVar6->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   origin), BVar9 == 0)) ||
             (BVar9 = CPlane::PointInFront
                                ((CPlane *)(local_8c + 0x10),
                                 &((pCVar6->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                  origin), BVar9 == 0)) {
            BVar9 = 1;
          }
          else {
            BVar9 = 0;
          }
        }
      }
    }
  }
  return BVar9;
}


// CSquadMonster::GetIdealState  @ 00124f10  (line 516)

/* DWARF original prototype: MONSTERSTATE GetIdealState(CSquadMonster * this) */

MONSTERSTATE __thiscall CSquadMonster::GetIdealState(CSquadMonster *this)

{
  MONSTERSTATE MVar1;
  int iVar2;
  CBaseEntity *pEnemy;
  
                    /* Unresolved local var: int iConditions@[???] */
  CBaseMonster::IScheduleFlags(&this->super_CBaseMonster);
  MVar1 = (this->super_CBaseMonster).m_MonsterState;
  if (((MVar1 == MONSTERSTATE_IDLE) || (MVar1 == MONSTERSTATE_ALERT)) &&
     (((this->super_CBaseMonster).m_afConditions & 0x10000) != 0)) {
    iVar2 = EHANDLE::operator_int(&this->m_hSquadLeader);
    if (iVar2 != 0) {
      pEnemy = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseMonster).m_hEnemy);
      SquadMakeEnemy(this,pEnemy);
    }
  }
  MVar1 = CBaseMonster::GetIdealState(&this->super_CBaseMonster);
  return MVar1;
}


// CSquadMonster::FValidateCover  @ 00123eb0  (line 542)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FValidateCover(CSquadMonster * this, Vector * vecCoverLocation) */

BOOL __thiscall CSquadMonster::FValidateCover(CSquadMonster *this,Vector *vecCoverLocation)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  int iVar2;
  CSquadMonster *pCVar3;
  CBaseEntity *pCVar4;
  float fVar5;
  float fVar6;
  
  this_00 = &this->m_hSquadLeader;
  iVar2 = EHANDLE::operator_int(this_00);
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  if ((iVar2 != 0) && (iVar2 = EHANDLE::operator_int(this_00), iVar2 != 0)) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar3 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(this_00);
    if (pCVar3 == (CSquadMonster *)0x0) {
      pCVar3 = this;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CSquadMonster * pSquadMember@[???] */
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar3->m_hSquadMember);
    if (pCVar4 != (CBaseEntity *)0x0) {
      fVar5 = vecCoverLocation->y - (pCVar4->pev->origin).y;
      fVar6 = vecCoverLocation->x - (pCVar4->pev->origin).x;
      fVar5 = fVar5 * fVar5 + fVar6 * fVar6;
      fVar6 = SQRT(fVar5);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar5);
      }
      if (fVar6 <= 128.0) {
        return 0;
      }
    }
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar3->m_hSquadMember + 1);
    if (pCVar4 != (CBaseEntity *)0x0) {
      fVar5 = vecCoverLocation->y - (pCVar4->pev->origin).y;
      fVar6 = vecCoverLocation->x - (pCVar4->pev->origin).x;
      fVar5 = fVar5 * fVar5 + fVar6 * fVar6;
      fVar6 = SQRT(fVar5);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar5);
      }
      if (fVar6 <= 128.0) {
        return 0;
      }
    }
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar3->m_hSquadMember + 2);
    if (pCVar4 != (CBaseEntity *)0x0) {
      fVar5 = vecCoverLocation->y - (pCVar4->pev->origin).y;
      fVar6 = vecCoverLocation->x - (pCVar4->pev->origin).x;
      fVar5 = fVar5 * fVar5 + fVar6 * fVar6;
      fVar6 = SQRT(fVar5);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar5);
      }
      if (fVar6 <= 128.0) {
        return 0;
      }
    }
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar3->m_hSquadMember + 3);
    if (pCVar4 != (CBaseEntity *)0x0) {
      fVar5 = vecCoverLocation->y - (pCVar4->pev->origin).y;
      fVar6 = vecCoverLocation->x - (pCVar4->pev->origin).x;
      fVar5 = fVar5 * fVar5 + fVar6 * fVar6;
      fVar6 = SQRT(fVar5);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar5);
      }
      if (fVar6 <= 128.0) {
        return 0;
      }
    }
    if ((pCVar3 != (CSquadMonster *)0x0) &&
       (peVar1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,
       fVar5 = vecCoverLocation->y - (peVar1->origin).y,
       fVar6 = vecCoverLocation->x - (peVar1->origin).x,
       fVar5 = sqrtf(fVar5 * fVar5 + fVar6 * fVar6), fVar5 <= 128.0)) {
      return 0;
    }
  }
  return 1;
}


// CSquadMonster::SquadEnemySplit  @ 00125900  (line 562)

/* DWARF original prototype: BOOL SquadEnemySplit(CSquadMonster * this) */

BOOL __thiscall CSquadMonster::SquadEnemySplit(CSquadMonster *this)

{
  EHANDLE *this_00;
  int iVar1;
  CSquadMonster *pCVar2;
  CBaseEntity *pCVar3;
  CBaseEntity *pCVar4;
  BOOL BVar5;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg3(EBX)]
                       Unresolved local var: CBaseEntity * pEnemy@[???] */
  iVar1 = EHANDLE::operator_int(&this->m_hSquadLeader);
  BVar5 = 0;
  if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar2 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
    if (pCVar2 == (CSquadMonster *)0x0) {
      pCVar2 = this;
    }
    this_00 = &(pCVar2->super_CBaseMonster).m_hEnemy;
    pCVar3 = EHANDLE::operator_CBaseEntity_(this_00);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CSquadMonster * pMember@[???] */
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar2->m_hSquadMember);
    if (pCVar4 != (CBaseEntity *)0x0) {
      iVar1 = EHANDLE::operator_int((EHANDLE *)&pCVar4[1].weapon);
      if ((iVar1 != 0) &&
         (pCVar4 = EHANDLE::operator_CBaseEntity_((EHANDLE *)&pCVar4[1].weapon), pCVar4 != pCVar3))
      {
        return 1;
      }
    }
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar2->m_hSquadMember + 1);
    if (pCVar4 != (CBaseEntity *)0x0) {
      iVar1 = EHANDLE::operator_int((EHANDLE *)&pCVar4[1].weapon);
      if ((iVar1 != 0) &&
         (pCVar4 = EHANDLE::operator_CBaseEntity_((EHANDLE *)&pCVar4[1].weapon), pCVar4 != pCVar3))
      {
        return 1;
      }
    }
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar2->m_hSquadMember + 2);
    if (pCVar4 != (CBaseEntity *)0x0) {
      iVar1 = EHANDLE::operator_int((EHANDLE *)&pCVar4[1].weapon);
      if ((iVar1 != 0) &&
         (pCVar4 = EHANDLE::operator_CBaseEntity_((EHANDLE *)&pCVar4[1].weapon), pCVar4 != pCVar3))
      {
        return 1;
      }
    }
    pCVar4 = EHANDLE::operator_CBaseEntity_(pCVar2->m_hSquadMember + 3);
    if (pCVar4 != (CBaseEntity *)0x0) {
      iVar1 = EHANDLE::operator_int((EHANDLE *)&pCVar4[1].weapon);
      if ((iVar1 != 0) &&
         (pCVar4 = EHANDLE::operator_CBaseEntity_((EHANDLE *)&pCVar4[1].weapon), pCVar4 != pCVar3))
      {
        return 1;
      }
    }
    if (((pCVar2 == (CSquadMonster *)0x0) || (iVar1 = EHANDLE::operator_int(this_00), iVar1 == 0))
       || (pCVar4 = EHANDLE::operator_CBaseEntity_(this_00), pCVar4 == pCVar3)) {
      BVar5 = 0;
    }
    else {
      BVar5 = 1;
    }
  }
  return BVar5;
}


// CSquadMonster::SquadMemberInRange  @ 00125c60  (line 586)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL SquadMemberInRange(CSquadMonster * this, Vector * vecLocation,
   float flDist) */

BOOL __thiscall
CSquadMonster::SquadMemberInRange(CSquadMonster *this,Vector *vecLocation,float flDist)

{
  entvars_t *peVar1;
  float fVar2;
  int iVar3;
  CSquadMonster *pCVar4;
  CBaseEntity *pCVar5;
  float fVar6;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[DW_OP_reg3(EBX)] */
  iVar3 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar3 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar4 = (CSquadMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hSquadLeader);
    if (pCVar4 == (CSquadMonster *)0x0) {
      pCVar4 = this;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CSquadMonster * pSquadMember@[???] */
    pCVar5 = EHANDLE::operator_CBaseEntity_(pCVar4->m_hSquadMember);
    if (pCVar5 != (CBaseEntity *)0x0) {
      fVar2 = vecLocation->y - (pCVar5->pev->origin).y;
      fVar6 = vecLocation->x - (pCVar5->pev->origin).x;
      fVar2 = fVar2 * fVar2 + fVar6 * fVar6;
      fVar6 = SQRT(fVar2);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar2);
      }
      if (fVar6 <= flDist) {
        return 1;
      }
    }
    pCVar5 = EHANDLE::operator_CBaseEntity_(pCVar4->m_hSquadMember + 1);
    if (pCVar5 != (CBaseEntity *)0x0) {
      fVar2 = vecLocation->y - (pCVar5->pev->origin).y;
      fVar6 = vecLocation->x - (pCVar5->pev->origin).x;
      fVar2 = fVar2 * fVar2 + fVar6 * fVar6;
      fVar6 = SQRT(fVar2);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar2);
      }
      if (fVar6 <= flDist) {
        return 1;
      }
    }
    pCVar5 = EHANDLE::operator_CBaseEntity_(pCVar4->m_hSquadMember + 2);
    if (pCVar5 != (CBaseEntity *)0x0) {
      fVar2 = vecLocation->y - (pCVar5->pev->origin).y;
      fVar6 = vecLocation->x - (pCVar5->pev->origin).x;
      fVar2 = fVar2 * fVar2 + fVar6 * fVar6;
      fVar6 = SQRT(fVar2);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar2);
      }
      if (fVar6 <= flDist) {
        return 1;
      }
    }
    pCVar5 = EHANDLE::operator_CBaseEntity_(pCVar4->m_hSquadMember + 3);
    if (pCVar5 != (CBaseEntity *)0x0) {
      fVar2 = vecLocation->y - (pCVar5->pev->origin).y;
      fVar6 = vecLocation->x - (pCVar5->pev->origin).x;
      fVar2 = fVar2 * fVar2 + fVar6 * fVar6;
      fVar6 = SQRT(fVar2);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar2);
      }
      if (fVar6 <= flDist) {
        return 1;
      }
    }
    if (pCVar4 != (CSquadMonster *)0x0) {
      peVar1 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar2 = vecLocation->y - (peVar1->origin).y;
      fVar6 = vecLocation->x - (peVar1->origin).x;
      fVar2 = fVar2 * fVar2 + fVar6 * fVar6;
      fVar6 = SQRT(fVar2);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar2);
      }
      if (fVar6 <= flDist) {
        return 1;
      }
    }
  }
  return 0;
}


// CSquadMonster::GetScheduleOfType  @ 00123dd0  (line 605)

/* DWARF original prototype: Schedule_t * GetScheduleOfType(CSquadMonster * this, int iType) */

Schedule_t * __thiscall CSquadMonster::GetScheduleOfType(CSquadMonster *this,int iType)

{
  Schedule_t *pSVar1;
  
  if (iType != 0xd) {
    pSVar1 = CBaseMonster::GetScheduleOfType(&this->super_CBaseMonster,iType);
    return pSVar1;
  }
  return slChaseEnemyFailed;
}


