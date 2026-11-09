// Ghidra decompilation of functions from tfc/squadmonster.cpp
// 21 functions, ordered by original source line

// CSquadMonster::Restore  @ 000efa70  (line 40)

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


// CSquadMonster::Save  @ 000efad0  (line 40)

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


// CSquadMonster::OccupySlot  @ 000efda0  (line 48)

/* DWARF original prototype: BOOL OccupySlot(CSquadMonster * this, int iDesiredSlots) */

BOOL __thiscall CSquadMonster::OccupySlot(CSquadMonster *this,int iDesiredSlots)

{
  EHANDLE *this_00;
  uint uVar1;
  int iVar2;
  CSquadMonster *pCVar3;
  CBaseEntity *pCVar4;
  int iVar5;
  uint uVar6;
  BOOL BVar7;
  EHANDLE *this_01;
  EHANDLE *pEVar8;
  CBaseEntity *local_28;
  EHANDLE *local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iMask@[???]
                       Unresolved local var: int iSquadSlots@[???]
                       Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  this_00 = &this->m_hSquadLeader;
  iVar2 = EHANDLE::operator_int(this_00);
  if (iVar2 == 0) {
    return 1;
  }
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???]
                       Unresolved local var: CBaseEntity * pEnemy@[???] */
  iVar2 = EHANDLE::operator_int(this_00);
  if (iVar2 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar3 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    if (pCVar3 == (CSquadMonster *)0x0) {
      local_24 = &(this->super_CBaseMonster).m_hEnemy;
      local_28 = EHANDLE::operator_cast_to_CBaseEntity_(local_24);
      pCVar3 = this;
      if (this == (CSquadMonster *)0x0) {
        pEVar8 = (EHANDLE *)0x6c4;
        do {
          pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar8);
          if (pCVar4 != (CBaseEntity *)0x0) {
            iVar2 = EHANDLE::operator_int((EHANDLE *)&pCVar4[1].weapon);
            if ((iVar2 != 0) &&
               (pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)&pCVar4[1].weapon),
               local_28 != pCVar4)) goto LAB_000effb0;
          }
          pEVar8 = pEVar8 + 1;
        } while (pEVar8 != (EHANDLE *)0x6e4);
        goto LAB_000efdf8;
      }
    }
    else {
      local_24 = &(pCVar3->super_CBaseMonster).m_hEnemy;
      local_28 = EHANDLE::operator_cast_to_CBaseEntity_(local_24);
    }
                    /* Unresolved local var: int i@[???] */
    pEVar8 = pCVar3->m_hSquadMember;
    iVar2 = 0;
    do {
                    /* Unresolved local var: CSquadMonster * pMember@[???] */
      if (iVar2 == 4) {
        iVar5 = EHANDLE::operator_int(local_24);
        this_01 = local_24;
        if (iVar5 == 0) break;
LAB_000eff9e:
        pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_(this_01);
        if (pCVar4 != local_28) {
LAB_000effb0:
          this->m_iMySlot = 0x400;
          return 1;
        }
      }
      else {
        pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar8);
        if (pCVar4 != (CBaseEntity *)0x0) {
          iVar5 = EHANDLE::operator_int((EHANDLE *)&pCVar4[1].weapon);
          this_01 = (EHANDLE *)&pCVar4[1].weapon;
          if (iVar5 != 0) goto LAB_000eff9e;
        }
      }
      iVar2 = iVar2 + 1;
      pEVar8 = pEVar8 + 1;
    } while (iVar2 != 5);
  }
LAB_000efdf8:
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  pCVar3 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  if (pCVar3 == (CSquadMonster *)0x0) {
    pCVar3 = this;
  }
  uVar1 = pCVar3->m_afSquadSlots;
  if (uVar1 == iDesiredSlots) {
    BVar7 = 0;
  }
  else {
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
                        if ((uVar1 & 0x400) != 0) {
                          return 0;
                        }
                        uVar6 = 0x400;
                      }
                      else {
                        uVar6 = 0x200;
                      }
                    }
                    else {
                      uVar6 = 0x100;
                    }
                  }
                  else {
                    uVar6 = 0x80;
                  }
                }
                else {
                  uVar6 = 0x40;
                }
              }
              else {
                uVar6 = 0x20;
              }
            }
            else {
              uVar6 = 0x10;
            }
          }
          else {
            uVar6 = 8;
          }
        }
        else {
          uVar6 = 4;
        }
      }
      else {
        uVar6 = 2;
      }
    }
    else {
      uVar6 = 1;
    }
    pCVar3->m_afSquadSlots = uVar1 | uVar6;
    this->m_iMySlot = uVar6;
    BVar7 = 1;
  }
  return BVar7;
}


// CSquadMonster::VacateSlot  @ 000f00a0  (line 100)

/* DWARF original prototype: void VacateSlot(CSquadMonster * this) */

void __thiscall CSquadMonster::VacateSlot(CSquadMonster *this)

{
  int iVar1;
  CSquadMonster *pCVar2;
  
  if (this->m_iMySlot != 0) {
    iVar1 = EHANDLE::operator_int(&this->m_hSquadLeader);
    if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
      pCVar2 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
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


// CSquadMonster::ScheduleChange  @ 000efb30  (line 113)

/* DWARF original prototype: void ScheduleChange(CSquadMonster * this) */

void __thiscall CSquadMonster::ScheduleChange(CSquadMonster *this)

{
  int iVar1;
  CSquadMonster *pCVar2;
  
  if (this->m_iMySlot != 0) {
    iVar1 = EHANDLE::operator_int(&this->m_hSquadLeader);
    if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
      pCVar2 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
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


// CSquadMonster::Killed  @ 000f0210  (line 121)

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
      pCVar2 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
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
    pCVar2 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    if (pCVar2 == (CSquadMonster *)0x0) {
      pCVar2 = this;
    }
    SquadRemove(pCVar2,this);
  }
  CBaseMonster::Killed(&this->super_CBaseMonster,pevInflictor,pevAttacker,iGib);
  return;
}


// CSquadMonster::SquadRemove  @ 000f0110  (line 142)

/* DWARF original prototype: void SquadRemove(CSquadMonster * this, CSquadMonster * pRemove) */

void __thiscall CSquadMonster::SquadRemove(CSquadMonster *this,CSquadMonster *pRemove)

{
  CSquadMonster *pCVar1;
  CSquadMonster *pCVar2;
  CBaseEntity *pCVar3;
  EHANDLE *pEVar4;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  pCVar1 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
  if (pCVar1 == (CSquadMonster *)0x0) {
    pCVar1 = this;
  }
  if (pRemove == pCVar1) {
    pEVar4 = this->m_hSquadMember;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CSquadMonster * pMember@[???] */
      pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar4);
      if (pCVar3 != (CBaseEntity *)0x0) {
        EHANDLE::operator=((EHANDLE *)&pCVar3[1].goal_activation,(CBaseEntity *)0x0);
        EHANDLE::operator=(pEVar4,(CBaseEntity *)0x0);
      }
      pEVar4 = pEVar4 + 1;
    } while (pEVar4 != (EHANDLE *)&this->m_afSquadSlots);
  }
  else {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar1 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
    if ((pCVar1 != (CSquadMonster *)0x0) || (pCVar1 = this, this != (CSquadMonster *)0x0)) {
      pEVar4 = pCVar1->m_hSquadMember;
      do {
                    /* Unresolved local var: int i@[???] */
        pCVar2 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(pEVar4);
        if (this == pCVar2) {
          EHANDLE::operator=(pEVar4,(CBaseEntity *)0x0);
          break;
        }
        pEVar4 = pEVar4 + 1;
      } while ((EHANDLE *)&pCVar1->m_afSquadSlots != pEVar4);
    }
  }
  EHANDLE::operator=(&pRemove->m_hSquadLeader,(CBaseEntity *)0x0);
  return;
}


// CSquadMonster::SquadAdd  @ 000f02e0  (line 185)

/* DWARF original prototype: BOOL SquadAdd(CSquadMonster * this, CSquadMonster * pAdd) */

BOOL __thiscall CSquadMonster::SquadAdd(CSquadMonster *this,CSquadMonster *pAdd)

{
  int iVar1;
  EHANDLE *this_00;
  
  this_00 = this->m_hSquadMember;
  do {
                    /* Unresolved local var: int i@[???] */
    iVar1 = EHANDLE::operator_int(this_00);
    if (iVar1 == 0) {
      EHANDLE::operator=(this_00,(CBaseEntity *)pAdd);
      EHANDLE::operator=(&pAdd->m_hSquadLeader,(CBaseEntity *)this);
      return 1;
    }
    this_00 = this_00 + 1;
  } while (this_00 != (EHANDLE *)&this->m_afSquadSlots);
  return 0;
}


// CSquadMonster::SquadPasteEnemyInfo  @ 000f0370  (line 212)

/* DWARF original prototype: void SquadPasteEnemyInfo(CSquadMonster * this) */

void __thiscall CSquadMonster::SquadPasteEnemyInfo(CSquadMonster *this)

{
  CSquadMonster *pCVar1;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  pCVar1 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
  if ((pCVar1 != (CSquadMonster *)0x0) || (pCVar1 = this, this != (CSquadMonster *)0x0)) {
    (pCVar1->super_CBaseMonster).m_vecEnemyLKP.x = (this->super_CBaseMonster).m_vecEnemyLKP.x;
    (pCVar1->super_CBaseMonster).m_vecEnemyLKP.y = (this->super_CBaseMonster).m_vecEnemyLKP.y;
    (pCVar1->super_CBaseMonster).m_vecEnemyLKP.z = (this->super_CBaseMonster).m_vecEnemyLKP.z;
  }
  return;
}


// CSquadMonster::SquadCopyEnemyInfo  @ 000f03c0  (line 227)

/* DWARF original prototype: void SquadCopyEnemyInfo(CSquadMonster * this) */

void __thiscall CSquadMonster::SquadCopyEnemyInfo(CSquadMonster *this)

{
  CSquadMonster *pCVar1;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  pCVar1 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
  if ((pCVar1 != (CSquadMonster *)0x0) || (pCVar1 = this, this != (CSquadMonster *)0x0)) {
    (this->super_CBaseMonster).m_vecEnemyLKP.x = (pCVar1->super_CBaseMonster).m_vecEnemyLKP.x;
    (this->super_CBaseMonster).m_vecEnemyLKP.y = (pCVar1->super_CBaseMonster).m_vecEnemyLKP.y;
    (this->super_CBaseMonster).m_vecEnemyLKP.z = (pCVar1->super_CBaseMonster).m_vecEnemyLKP.z;
  }
  return;
}


// CSquadMonster::SquadMakeEnemy  @ 000f0410  (line 240)

/* DWARF original prototype: void SquadMakeEnemy(CSquadMonster * this, CBaseEntity * pEnemy) */

void __thiscall CSquadMonster::SquadMakeEnemy(CSquadMonster *this,CBaseEntity *pEnemy)

{
  EHANDLE *pEVar1;
  int *piVar2;
  entvars_t *peVar3;
  vec_t vVar4;
  int iVar5;
  CSquadMonster *this_00;
  CBaseEntity *pCVar6;
  CBaseMonster *this_01;
  int iVar7;
  EHANDLE *pEVar8;
  CSquadMonster *local_20;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  iVar5 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar5 != 0) {
    if (pEnemy == (CBaseEntity *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000f05d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*g_engfuncs.pfnAlertMessage)(at_console,"ERROR: SquadMakeEnemy() - pEnemy is NULL!\n");
      return;
    }
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    local_20 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
    if (local_20 == (CSquadMonster *)0x0) {
      if (this == (CSquadMonster *)0x0) {
        pEVar8 = (EHANDLE *)0x6c4;
        do {
          this_01 = (CBaseMonster *)EHANDLE::operator_cast_to_CBaseEntity_(pEVar8);
          if (this_01 != (CBaseMonster *)0x0) {
            pEVar1 = &this_01->m_hEnemy;
            pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar1);
            if ((pEnemy != pCVar6) && ((this_01->m_afConditions & 0x10) == 0)) {
              iVar5 = EHANDLE::operator_int(pEVar1);
              if (iVar5 != 0) {
                pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar1);
                CBaseMonster::PushEnemy(this_01,pCVar6,&this_01->m_vecEnemyLKP);
              }
              EHANDLE::operator=(pEVar1,pEnemy);
              peVar3 = pEnemy->pev;
              (this_01->m_vecEnemyLKP).x = (peVar3->origin).x;
              (this_01->m_vecEnemyLKP).y = (peVar3->origin).y;
              vVar4 = (peVar3->origin).z;
              this_01->m_afConditions = this_01->m_afConditions | 0x10000;
              (this_01->m_vecEnemyLKP).z = vVar4;
            }
          }
          pEVar8 = pEVar8 + 1;
        } while (pEVar8 != (EHANDLE *)0x6e4);
        return;
      }
      local_20 = this;
    }
    pEVar8 = local_20->m_hSquadMember;
                    /* Unresolved local var: int i@[???] */
    iVar5 = 0;
    do {
      this_00 = local_20;
                    /* Unresolved local var: CSquadMonster * pMember@[???] */
      if ((iVar5 == 4) ||
         (this_00 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(pEVar8),
         this_00 != (CSquadMonster *)0x0)) {
        pEVar1 = &(this_00->super_CBaseMonster).m_hEnemy;
        pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar1);
        if ((pEnemy != pCVar6) && (((this_00->super_CBaseMonster).m_afConditions & 0x10) == 0)) {
          iVar7 = EHANDLE::operator_int(pEVar1);
          if (iVar7 != 0) {
            pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar1);
            CBaseMonster::PushEnemy
                      (&this_00->super_CBaseMonster,pCVar6,
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
      iVar5 = iVar5 + 1;
      pEVar8 = pEVar8 + 1;
    } while (iVar5 != 5);
  }
  return;
}


// CSquadMonster::SquadCount  @ 000f0690  (line 281)

/* DWARF original prototype: int SquadCount(CSquadMonster * this) */

int __thiscall CSquadMonster::SquadCount(CSquadMonster *this)

{
  int iVar1;
  CSquadMonster *pCVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  EHANDLE *pEVar5;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???]
                       Unresolved local var: int squadCount@[???] */
  iVar1 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar1 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar2 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
    if ((pCVar2 == (CSquadMonster *)0x0) && (pCVar2 = this, this == (CSquadMonster *)0x0)) {
      pEVar5 = (EHANDLE *)0x6c4;
      iVar1 = 0;
      do {
        pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar5);
        iVar1 = (iVar1 + 1) - (uint)(pCVar3 == (CBaseEntity *)0x0);
        pEVar5 = pEVar5 + 1;
      } while (pEVar5 != (EHANDLE *)0x6e4);
    }
    else {
      pEVar5 = pCVar2->m_hSquadMember;
                    /* Unresolved local var: int i@[???] */
      iVar4 = 0;
      iVar1 = 0;
      do {
        if ((iVar4 == 4) ||
           (pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar5), pCVar3 != (CBaseEntity *)0x0))
        {
          iVar1 = iVar1 + 1;
        }
        iVar4 = iVar4 + 1;
        pEVar5 = pEVar5 + 1;
      } while (iVar4 != 5);
    }
    return iVar1;
  }
  return 0;
}


// CSquadMonster::SquadRecruit  @ 000f0740  (line 304)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int SquadRecruit(CSquadMonster * this, int searchRadius, int
   maxMembers) */

int __thiscall CSquadMonster::SquadRecruit(CSquadMonster *this,int searchRadius,int maxMembers)

{
  EHANDLE *this_00;
  _func_int_varargs *p_Var1;
  int iVar2;
  CSquadMonster *pCVar3;
  uint uVar4;
  entvars_t *peVar5;
  CBaseEntity *pCVar6;
  entvars_t *peVar7;
  EHANDLE *pEVar8;
  int local_80;
  int local_78;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int squadCount@[???]
                       Unresolved local var: int iMyClass@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  local_80 = 0;
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[10];
  if (p_Var1 != CBaseEntity::Classify) {
    local_80 = (*p_Var1)(this);
  }
  this_00 = &this->m_hSquadLeader;
  iVar2 = EHANDLE::operator_int(this_00);
  if ((iVar2 != 0) || (maxMembers < 2)) {
    return 0;
  }
  EHANDLE::operator=(this_00,(CBaseEntity *)this);
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar7->netname != 0) {
    pCVar6 = UTIL_FindEntityByString
                       ((CBaseEntity *)0x0,"netname",gpGlobals->pStringBase + peVar7->netname);
    local_78 = 1;
    if (pCVar6 != (CBaseEntity *)0x0) {
      do {
        pCVar3 = (CSquadMonster *)(*pCVar6->_vptr_CBaseEntity[0x14])(pCVar6);
        if (pCVar3 != (CSquadMonster *)0x0) {
          iVar2 = EHANDLE::operator_int(&pCVar3->m_hSquadLeader);
          if (iVar2 == 0) {
            p_Var1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10];
            iVar2 = 0;
            if (p_Var1 != CBaseEntity::Classify) {
              iVar2 = (*p_Var1)(pCVar3);
            }
            if ((this != pCVar3) && (local_80 == iVar2)) {
              pEVar8 = this->m_hSquadMember;
                    /* Unresolved local var: int i@[???] */
              while (iVar2 = EHANDLE::operator_int(pEVar8), iVar2 != 0) {
                pEVar8 = pEVar8 + 1;
                if (pEVar8 == (EHANDLE *)&this->m_afSquadSlots) goto LAB_000f0950;
              }
              EHANDLE::operator=(pEVar8,(CBaseEntity *)pCVar3);
              EHANDLE::operator=(&pCVar3->m_hSquadLeader,(CBaseEntity *)this);
              local_78 = local_78 + 1;
            }
          }
        }
                    /* Unresolved local var: CSquadMonster * pRecruit@[???] */
        pCVar6 = UTIL_FindEntityByString
                           (pCVar6,"netname",
                            gpGlobals->pStringBase +
                            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->netname);
      } while (pCVar6 != (CBaseEntity *)0x0);
LAB_000f0950:
      if (local_78 != 1) {
        return local_78;
      }
    }
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    return 1;
  }
  pCVar6 = (CBaseEntity *)0x0;
  local_78 = 1;
LAB_000f07d3:
  pCVar6 = UTIL_FindEntityInSphere(pCVar6,&peVar7->origin,(float)searchRadius);
  if (pCVar6 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CSquadMonster * pRecruit@[???] */
    pCVar3 = (CSquadMonster *)(*pCVar6->_vptr_CBaseEntity[0x14])(pCVar6);
    if ((pCVar3 != (CSquadMonster *)0x0) && (this != pCVar3)) {
      p_Var1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x22];
      if (p_Var1 == CBaseMonster::IsAlive) {
        uVar4 = (uint)(((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->deadflag != 2);
      }
      else {
        uVar4 = (*p_Var1)(pCVar3);
      }
      if ((uVar4 == 0) || ((pCVar3->super_CBaseMonster).m_pCine != (CCineMonster *)0x0))
      goto LAB_000f07d0;
      iVar2 = EHANDLE::operator_int(&pCVar3->m_hSquadLeader);
      if (iVar2 != 0) goto LAB_000f07d0;
      p_Var1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[10];
      iVar2 = 0;
      if (p_Var1 != CBaseEntity::Classify) {
        iVar2 = (*p_Var1)(pCVar3);
      }
      if (local_80 != iVar2) goto LAB_000f07d0;
      if (local_80 == 7) goto LAB_000f0b2c;
      peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar5 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      goto LAB_000f0882;
    }
    goto LAB_000f07d0;
  }
  goto LAB_000f0950;
LAB_000f0b2c:
  peVar5 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar2 = strcmp(gpGlobals->pStringBase + peVar7->classname,
                 gpGlobals->pStringBase + peVar5->classname);
  if (iVar2 == 0) {
LAB_000f0882:
    if (peVar5->netname == 0) {
                    /* Unresolved local var: TraceResult tr@[???] */
      local_60.z = (peVar7->view_ofs).z + (peVar5->origin).z;
      local_60.y = (peVar7->view_ofs).y + (peVar5->origin).y;
      local_60.x = (peVar5->origin).x + (peVar7->view_ofs).x;
      local_6c.z = (peVar7->view_ofs).z + (peVar7->origin).z;
      local_6c.y = (peVar7->view_ofs).y + (peVar7->origin).y;
      local_6c.x = (peVar7->origin).x + (peVar7->view_ofs).x;
      UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,peVar5->pContainingEntity,&local_54);
      if (local_54.flFraction == 1.0) {
        pEVar8 = this->m_hSquadMember;
                    /* Unresolved local var: int i@[???] */
        while (iVar2 = EHANDLE::operator_int(pEVar8), iVar2 != 0) {
          pEVar8 = pEVar8 + 1;
          if (pEVar8 == (EHANDLE *)&this->m_afSquadSlots) goto LAB_000f0950;
        }
        EHANDLE::operator=(pEVar8,(CBaseEntity *)pCVar3);
        EHANDLE::operator=(&pCVar3->m_hSquadLeader,(CBaseEntity *)this);
        local_78 = local_78 + 1;
      }
LAB_000f07d0:
      peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
  }
  goto LAB_000f07d3;
}


// CSquadMonster::CheckEnemy  @ 000efba0  (line 384)

/* DWARF original prototype: int CheckEnemy(CSquadMonster * this, CBaseEntity * pEnemy) */

int __thiscall CSquadMonster::CheckEnemy(CSquadMonster *this,CBaseEntity *pEnemy)

{
  EHANDLE *this_00;
  CBaseEntity *pCVar1;
  int iVar2;
  int iVar3;
  CBaseEntity *pCVar4;
  CSquadMonster *pCVar5;
  EHANDLE *this_01;
  
                    /* Unresolved local var: int iUpdatedLKP@[???] */
  this_01 = &(this->super_CBaseMonster).m_hEnemy;
  this_00 = &this->m_hSquadLeader;
  pCVar1 = EHANDLE::operator_cast_to_CBaseEntity_(this_01);
  iVar2 = CBaseMonster::CheckEnemy(&this->super_CBaseMonster,pCVar1);
  iVar3 = EHANDLE::operator_int(this_00);
  if (iVar3 != 0) {
    pCVar1 = EHANDLE::operator_cast_to_CBaseEntity_(this_01);
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    if (pCVar4 != (CBaseEntity *)0x0) {
      this_01 = (EHANDLE *)&pCVar4[1].weapon;
    }
    pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_(this_01);
    if (pCVar1 == pCVar4) {
      if (iVar2 == 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
        pCVar5 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
        if ((pCVar5 != (CSquadMonster *)0x0) || (pCVar5 = this, this != (CSquadMonster *)0x0)) {
          (this->super_CBaseMonster).m_vecEnemyLKP.x = (pCVar5->super_CBaseMonster).m_vecEnemyLKP.x;
          (this->super_CBaseMonster).m_vecEnemyLKP.y = (pCVar5->super_CBaseMonster).m_vecEnemyLKP.y;
          (this->super_CBaseMonster).m_vecEnemyLKP.z = (pCVar5->super_CBaseMonster).m_vecEnemyLKP.z;
        }
      }
      else {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
        pCVar5 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
        if ((pCVar5 != (CSquadMonster *)0x0) || (pCVar5 = this, this != (CSquadMonster *)0x0)) {
          (pCVar5->super_CBaseMonster).m_vecEnemyLKP.x = (this->super_CBaseMonster).m_vecEnemyLKP.x;
          (pCVar5->super_CBaseMonster).m_vecEnemyLKP.y = (this->super_CBaseMonster).m_vecEnemyLKP.y;
          (pCVar5->super_CBaseMonster).m_vecEnemyLKP.z = (this->super_CBaseMonster).m_vecEnemyLKP.z;
        }
      }
    }
  }
  return iVar2;
}


// CSquadMonster::StartMonster  @ 000f0b70  (line 411)

/* DWARF original prototype: void StartMonster(CSquadMonster * this) */

void __thiscall CSquadMonster::StartMonster(CSquadMonster *this)

{
  entvars_t *peVar1;
  int iVar2;
  CSquadMonster *pCVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  CBaseMonster::StartMonster(&this->super_CBaseMonster);
  if (((this->super_CBaseMonster).m_afCapability & 8) != 0) {
    iVar2 = EHANDLE::operator_int(&this->m_hSquadLeader);
                    /* Unresolved local var: int iSquadSize@[???] */
    if ((iVar2 == 0) &&
       ((peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev, peVar1->netname == 0 || ((peVar1->spawnflags & 0x20) != 0)
        ))) {
                    /* Unresolved local var: int iSquadSize@[???] */
      iVar2 = SquadRecruit(this,0x400,4);
      if (iVar2 != 0) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"Squad of %d %s formed\n",iVar2,
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->classname);
      }
      pCVar3 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
      if (this == pCVar3) {
        iVar2 = 0x14;
        bVar6 = gpGlobals->pStringBase +
                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->classname == (char *)0x0;
        pcVar4 = gpGlobals->pStringBase +
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->classname;
        pcVar5 = "monster_human_grunt";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
          pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
        } while (bVar6);
        if (bVar6) {
          CBaseAnimating::SetBodygroup((CBaseAnimating *)this,1,1);
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->skin = 0;
          return;
        }
      }
    }
  }
  return;
}


// CSquadMonster::NoFriendlyFire  @ 000f0c90  (line 449)

/* DWARF original prototype: BOOL NoFriendlyFire(CSquadMonster * this) */

BOOL __thiscall CSquadMonster::NoFriendlyFire(CSquadMonster *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  entvars_t *peVar8;
  entvars_t *peVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  CBaseEntity *pCVar13;
  CSquadMonster *pCVar14;
  BOOL BVar15;
  EHANDLE *pEVar16;
  int *piVar17;
  undefined4 local_a0;
  entvars_t *local_8c;
  float local_80;
  float local_7c;
  float local_78;
  CPlane local_58;
  CPlane local_44;
  CPlane local_30;
  
                    /* Unresolved local var: CPlane backPlane@[???]
                       Unresolved local var: CPlane leftPlane@[???]
                       Unresolved local var: CPlane rightPlane@[???]
                       Unresolved local var: Vector vecLeftSide@[???]
                       Unresolved local var: Vector vecRightSide@[???]
                       Unresolved local var: Vector v_left@[???]
                       Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  piVar17 = (int *)&stack0xffffff64;
  local_a0 = 0xf0cc7;
  iVar12 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar12 != 0) {
    pEVar16 = &(this->super_CBaseMonster).m_hEnemy;
    local_a0 = 0xf0d0a;
    CPlane::CPlane(&local_58);
    local_a0 = 0xf0d16;
    CPlane::CPlane(&local_44);
    local_a0 = 0xf0d22;
    CPlane::CPlane(&local_30);
    local_a0 = 0xf0d2a;
    iVar12 = EHANDLE::operator_int(pEVar16);
    if (iVar12 == 0) {
      return 0;
    }
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_a0 = 0xf0d47;
    pCVar13 = EHANDLE::operator->(pEVar16);
    if (pCVar13->_vptr_CBaseEntity[0x32] == CBaseEntity::Center) {
      peVar9 = pCVar13->pev;
      local_78 = ((peVar9->absmax).z + (peVar9->absmin).z) * 0.5;
      local_7c = ((peVar9->absmax).y + (peVar9->absmin).y) * 0.5;
      local_80 = ((peVar9->absmax).x + (peVar9->absmin).x) * 0.5;
      local_8c = peVar8;
    }
    else {
      local_a0 = 0xf102d;
      (*pCVar13->_vptr_CBaseEntity[0x32])();
      piVar17 = &local_a0;
    }
    fVar2 = (local_8c->origin).z;
    piVar1 = piVar17 + 0xe;
    fVar3 = (local_8c->origin).y;
    piVar17[7] = (int)(piVar17 + 0xb);
    fVar4 = (local_8c->origin).x;
    piVar17[1] = (int)(piVar17 + 0xb);
    *piVar17 = (int)piVar1;
    piVar17[0xb] = (int)(local_80 - fVar4);
    piVar17[0xc] = (int)(local_7c - fVar3);
    piVar17[0xd] = (int)(local_78 - fVar2);
    piVar17[-1] = 0xf0de1;
    UTIL_VecToAngles((Vector *)*piVar17,(Vector *)piVar17[1]);
    *piVar17 = (int)piVar1;
    piVar17[-1] = 0xf0dec;
    UTIL_MakeVectors((Vector *)*piVar17);
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar10 = (peVar8->size).x * 1.5;
    fVar2 = (gpGlobals->v_right).z;
    piVar17[5] = (int)(fVar10 * fVar2);
    fVar3 = (gpGlobals->v_right).y;
    fVar11 = fVar10 * fVar3;
    fVar4 = (gpGlobals->v_right).x;
    fVar10 = fVar10 * fVar4;
    fVar5 = (peVar8->origin).z;
    fVar6 = (peVar8->origin).y;
    piVar17[8] = (int)((peVar8->origin).x - fVar10);
    piVar17[9] = (int)(fVar6 - fVar11);
    piVar17[10] = (int)(fVar5 - (float)piVar17[5]);
    fVar7 = (peVar8->origin).x;
    piVar17[1] = (int)&gpGlobals->v_right;
    piVar17[2] = piVar17[6];
    *piVar17 = (int)(piVar17 + 0x16);
    piVar17[0xb] = (int)(fVar10 + fVar7);
    piVar17[0xc] = (int)(fVar11 + fVar6);
    piVar17[0xd] = (int)(fVar5 + (float)piVar17[5]);
    piVar17[0xe] = (int)-fVar4;
    piVar17[0xf] = (int)-fVar3;
    piVar17[0x10] = (int)-fVar2;
    piVar17[-1] = 0xf0e83;
    CPlane::InitializePlane((CPlane *)*piVar17,(Vector *)piVar17[1],(Vector *)piVar17[2]);
    *piVar17 = (int)(piVar17 + 0x1b);
    piVar17[1] = (int)piVar1;
    piVar17[2] = piVar17[7];
    piVar17[-1] = 0xf0e9b;
    CPlane::InitializePlane((CPlane *)*piVar17,(Vector *)piVar17[1],(Vector *)piVar17[2]);
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    *piVar17 = (int)&local_58;
    piVar17[2] = (int)&peVar8->origin;
    piVar17[1] = (int)&gpGlobals->v_forward;
    piVar17[-1] = 0xf0eb9;
    CPlane::InitializePlane((CPlane *)*piVar17,(Vector *)piVar17[1],(Vector *)piVar17[2]);
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    *piVar17 = (int)&this->m_hSquadLeader;
    piVar17[-1] = 0xf0ec1;
    pCVar14 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*piVar17);
    piVar17[5] = (int)pCVar14;
    if ((pCVar14 != (CSquadMonster *)0x0) && (this != pCVar14)) {
                    /* Unresolved local var: int i@[???] */
      iVar12 = 0;
      pEVar16 = pCVar14->m_hSquadMember;
                    /* Unresolved local var: CSquadMonster * pMember@[???] */
      piVar17[0x28] = (int)this;
      do {
        *piVar17 = (int)pEVar16;
        piVar17[-1] = 0xf0ef3;
        pCVar13 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*piVar17);
        if ((pCVar13 != (CBaseEntity *)0x0) && ((CBaseEntity *)piVar17[0x28] != pCVar13))
        goto LAB_000f0f18;
        while( true ) {
          iVar12 = iVar12 + 1;
          pEVar16 = pEVar16 + 1;
          if (iVar12 == 5) {
            return 1;
          }
          if (iVar12 != 4) break;
          pCVar13 = (CBaseEntity *)piVar17[5];
LAB_000f0f18:
          peVar8 = pCVar13->pev;
          *piVar17 = (int)&local_58;
          piVar17[1] = (int)&peVar8->origin;
          piVar17[-1] = 0xf0f2a;
          BVar15 = CPlane::PointInFront((CPlane *)*piVar17,(Vector *)piVar17[1]);
          if (BVar15 != 0) {
            piVar17[1] = (int)&pCVar13->pev->origin;
            *piVar17 = (int)(piVar17 + 0x16);
            piVar17[-1] = 0xf0f44;
            BVar15 = CPlane::PointInFront((CPlane *)*piVar17,(Vector *)piVar17[1]);
            if (BVar15 != 0) {
              piVar17[1] = (int)&pCVar13->pev->origin;
              *piVar17 = (int)(piVar17 + 0x1b);
              piVar17[-1] = 0xf0f5e;
              BVar15 = CPlane::PointInFront((CPlane *)*piVar17,(Vector *)piVar17[1]);
              if (BVar15 != 0) {
                return 0;
              }
            }
          }
        }
      } while( true );
    }
    pEVar16 = this->m_hSquadMember;
    piVar17[5] = (int)&this->m_fEnemyEluded;
    piVar17[0x28] = (int)this;
    do {
      if (pEVar16 == (EHANDLE *)&this->m_afSquadSlots) {
        return 1;
      }
      *piVar17 = (int)pEVar16;
      piVar17[-1] = 0xf0f9d;
      pCVar13 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*piVar17);
      if ((pCVar13 != (CBaseEntity *)0x0) && ((CBaseEntity *)piVar17[0x28] != pCVar13)) {
        peVar8 = pCVar13->pev;
        *piVar17 = (int)&local_58;
        piVar17[1] = (int)&peVar8->origin;
        piVar17[-1] = 0xf0fd2;
        BVar15 = CPlane::PointInFront((CPlane *)*piVar17,(Vector *)piVar17[1]);
        if (BVar15 != 0) {
          piVar17[1] = (int)&pCVar13->pev->origin;
          *piVar17 = (int)(piVar17 + 0x16);
          piVar17[-1] = 0xf0fec;
          BVar15 = CPlane::PointInFront((CPlane *)*piVar17,(Vector *)piVar17[1]);
          if (BVar15 != 0) {
            piVar17[1] = (int)&pCVar13->pev->origin;
            *piVar17 = (int)(piVar17 + 0x1b);
            piVar17[-1] = 0xf1006;
            BVar15 = CPlane::PointInFront((CPlane *)*piVar17,(Vector *)piVar17[1]);
            if (BVar15 != 0) {
              return 0;
            }
          }
        }
      }
      pEVar16 = pEVar16 + 1;
    } while (pEVar16 != (EHANDLE *)piVar17[5]);
  }
  return 1;
}


// CSquadMonster::GetIdealState  @ 000f0610  (line 516)

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
      pEnemy = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseMonster).m_hEnemy);
      SquadMakeEnemy(this,pEnemy);
      MVar1 = CBaseMonster::GetIdealState(&this->super_CBaseMonster);
      return MVar1;
    }
  }
  MVar1 = CBaseMonster::GetIdealState(&this->super_CBaseMonster);
  return MVar1;
}


// CSquadMonster::FValidateCover  @ 000efcc0  (line 542)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FValidateCover(CSquadMonster * this, Vector * vecCoverLocation) */

BOOL __thiscall CSquadMonster::FValidateCover(CSquadMonster *this,Vector *vecCoverLocation)

{
  entvars_t *peVar1;
  float fVar2;
  int iVar3;
  CSquadMonster *pCVar4;
  EHANDLE *pEVar5;
  float fVar6;
  
  pEVar5 = &this->m_hSquadLeader;
  iVar3 = EHANDLE::operator_int(pEVar5);
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  if ((iVar3 != 0) && (iVar3 = EHANDLE::operator_int(pEVar5), iVar3 != 0)) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar4 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(pEVar5);
    if (pCVar4 != (CSquadMonster *)0x0) {
      this = pCVar4;
    }
                    /* Unresolved local var: int i@[???] */
    iVar3 = 0;
    pEVar5 = this->m_hSquadMember;
    do {
                    /* Unresolved local var: CSquadMonster * pSquadMember@[???] */
      pCVar4 = this;
      if (iVar3 != 4) {
        pCVar4 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(pEVar5);
      }
      if (pCVar4 != (CSquadMonster *)0x0) {
        peVar1 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        fVar2 = vecCoverLocation->y - (peVar1->origin).y;
        fVar6 = vecCoverLocation->x - (peVar1->origin).x;
        fVar2 = fVar2 * fVar2 + fVar6 * fVar6;
        fVar6 = SQRT(fVar2);
        if (NAN(fVar6)) {
          fVar6 = sqrtf(fVar2);
        }
        if (fVar6 <= 128.0) {
          return 0;
        }
      }
      iVar3 = iVar3 + 1;
      pEVar5 = pEVar5 + 1;
    } while (iVar3 != 5);
  }
  return 1;
}


// CSquadMonster::SquadEnemySplit  @ 000f1050  (line 562)

/* DWARF original prototype: BOOL SquadEnemySplit(CSquadMonster * this) */

BOOL __thiscall CSquadMonster::SquadEnemySplit(CSquadMonster *this)

{
  int iVar1;
  CSquadMonster *pCVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  EHANDLE *this_00;
  EHANDLE *pEVar5;
  EHANDLE *this_01;
  CBaseEntity *local_20;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???]
                       Unresolved local var: CBaseEntity * pEnemy@[???] */
  iVar1 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar1 == 0) {
    return 0;
  }
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  pCVar2 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
  if (pCVar2 == (CSquadMonster *)0x0) {
    pEVar5 = &(this->super_CBaseMonster).m_hEnemy;
    local_20 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar5);
    if (this == (CSquadMonster *)0x0) {
      pEVar5 = (EHANDLE *)0x6c4;
      do {
        pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar5);
        if (pCVar3 != (CBaseEntity *)0x0) {
          iVar1 = EHANDLE::operator_int((EHANDLE *)&pCVar3[1].weapon);
          if ((iVar1 != 0) &&
             (pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)&pCVar3[1].weapon),
             pCVar3 != local_20)) {
            return 1;
          }
        }
        pEVar5 = pEVar5 + 1;
        if (pEVar5 == (EHANDLE *)0x6e4) {
          return 0;
        }
      } while( true );
    }
  }
  else {
    pEVar5 = &(pCVar2->super_CBaseMonster).m_hEnemy;
    local_20 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar5);
    this = pCVar2;
  }
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
  this_00 = this->m_hSquadMember;
                    /* Unresolved local var: CSquadMonster * pMember@[???] */
  do {
    pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    if (pCVar3 != (CBaseEntity *)0x0) {
      iVar4 = EHANDLE::operator_int((EHANDLE *)&pCVar3[1].weapon);
      this_01 = (EHANDLE *)&pCVar3[1].weapon;
      if (iVar4 != 0) goto LAB_000f10f7;
    }
    while( true ) {
      iVar1 = iVar1 + 1;
      this_00 = this_00 + 1;
      if (iVar1 == 5) {
        return 0;
      }
      if (iVar1 != 4) break;
      iVar4 = EHANDLE::operator_int(pEVar5);
      this_01 = pEVar5;
      if (iVar4 == 0) {
        return 0;
      }
LAB_000f10f7:
      pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(this_01);
      if (pCVar3 != local_20) {
        return 1;
      }
    }
  } while( true );
}


// CSquadMonster::SquadMemberInRange  @ 000f1180  (line 586)

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
  EHANDLE *this_00;
  float fVar5;
  
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
  iVar3 = EHANDLE::operator_int(&this->m_hSquadLeader);
  if (iVar3 != 0) {
                    /* Unresolved local var: CSquadMonster * pSquadLeader@[???] */
    pCVar4 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hSquadLeader);
    if (pCVar4 != (CSquadMonster *)0x0) {
      this = pCVar4;
    }
                    /* Unresolved local var: int i@[???] */
    iVar3 = 0;
    this_00 = this->m_hSquadMember;
    do {
                    /* Unresolved local var: CSquadMonster * pSquadMember@[???] */
      pCVar4 = this;
      if (iVar3 != 4) {
        pCVar4 = (CSquadMonster *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
      }
      if (pCVar4 != (CSquadMonster *)0x0) {
        peVar1 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        fVar2 = vecLocation->y - (peVar1->origin).y;
        fVar5 = vecLocation->x - (peVar1->origin).x;
        fVar2 = fVar2 * fVar2 + fVar5 * fVar5;
        fVar5 = SQRT(fVar2);
        if (NAN(fVar5)) {
          fVar5 = sqrtf(fVar2);
        }
        if (fVar5 <= flDist) {
          return 1;
        }
      }
      iVar3 = iVar3 + 1;
      this_00 = this_00 + 1;
    } while (iVar3 != 5);
  }
  return 0;
}


// CSquadMonster::GetScheduleOfType  @ 000efa50  (line 605)

/* DWARF original prototype: Schedule_t * GetScheduleOfType(CSquadMonster * this, int iType) */

Schedule_t * __thiscall CSquadMonster::GetScheduleOfType(CSquadMonster *this,int iType)

{
  Schedule_t *pSVar1;
  
  if (iType == 0xd) {
    return slChaseEnemyFailed;
  }
  pSVar1 = CBaseMonster::GetScheduleOfType(&this->super_CBaseMonster,iType);
  return pSVar1;
}


