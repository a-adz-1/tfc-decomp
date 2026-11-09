// Ghidra decompilation of functions from tfc/func_tank.cpp
// 52 functions, ordered by original source line

// CFuncTank::~CFuncTank  @ 0009ab50  (line 40)

/* DWARF original prototype: void ~CFuncTank(CFuncTank * this, int __in_chrg) */

void __thiscall CFuncTank::~CFuncTank(CFuncTank *this,int __in_chrg)

{
  return;
}


// CFuncTank::UpdateTargetPosition  @ 0009ab00  (line 51)

/* DWARF original prototype: Vector UpdateTargetPosition(CFuncTank * this, CBaseEntity * pTarget) */

Vector * __thiscall
CFuncTank::UpdateTargetPosition(Vector *__return_storage_ptr__,CFuncTank *this,CBaseEntity *pTarget)

{
  (*pTarget->_vptr_CBaseEntity[0x35])
            (__return_storage_ptr__,pTarget,&((this->super_CBaseEntity).pev)->origin);
  return __return_storage_ptr__;
}


// CFuncTank::ObjectCaps  @ 0009ab40  (line 60)

/* DWARF original prototype: int ObjectCaps(CFuncTank * this) */

int __thiscall CFuncTank::ObjectCaps(CFuncTank *this)

{
  return 0;
}


// CFuncTank::Save  @ 00097870  (line 156)

/* DWARF original prototype: int Save(CFuncTank * this, CSave * save) */

int __thiscall CFuncTank::Save(CFuncTank *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CFuncTank",this,m_SaveData,0x19);
  }
  return iVar2;
}


// CFuncTank::Restore  @ 000978d0  (line 156)

/* DWARF original prototype: int Restore(CFuncTank * this, CRestore * restore) */

int __thiscall CFuncTank::Restore(CFuncTank *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CFuncTank",this,m_SaveData,0x19);
  }
  return iVar2;
}


// CFuncTank::Spawn  @ 00098110  (line 170)

/* DWARF original prototype: void Spawn(CFuncTank * this) */

void __thiscall CFuncTank::Spawn(CFuncTank *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  _2globalvars_t *p1Var6;
  entvars_t *peVar7;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])(this);
  ((this->super_CBaseEntity).pev)->movetype = 7;
  p1Var6 = gpGlobals;
  ((this->super_CBaseEntity).pev)->solid = 4;
  peVar7 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar7->pContainingEntity,p1Var6->pStringBase + peVar7->model);
  peVar7 = (this->super_CBaseEntity).pev;
  this->m_yawCenter = (peVar7->angles).y;
  this->m_pitchCenter = (peVar7->angles).x;
  if ((peVar7->spawnflags & 1) != 0) {
    peVar7->nextthink = peVar7->ltime + 1.0;
    peVar7 = (this->super_CBaseEntity).pev;
  }
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
  (*g_engfuncs.pfnAngleVectors)(&(peVar7->angles).x,&local_30,&local_24,&local_18);
  peVar7 = (this->super_CBaseEntity).pev;
  fVar1 = (this->m_barrelPos).z;
  fVar2 = (this->m_barrelPos).y;
  fVar3 = (this->m_barrelPos).x;
  fVar4 = (peVar7->origin).z;
  fVar5 = (peVar7->origin).y;
  (this->m_sightOrigin).x =
       fVar1 * local_18 + fVar2 * local_24 + fVar3 * local_30 + (peVar7->origin).x;
  (this->m_sightOrigin).y = local_14 * fVar1 + local_20 * fVar2 + local_2c * fVar3 + fVar5;
  (this->m_sightOrigin).z = local_10 * fVar1 + local_1c * fVar2 + local_28 * fVar3 + fVar4;
  if (this->m_fireRate <= 0.0) {
    this->m_fireRate = 1.0;
  }
  if (5 < (uint)this->m_spread) {
    this->m_spread = 0;
  }
  (peVar7->oldorigin).x = (peVar7->origin).x;
  (peVar7->oldorigin).y = (peVar7->origin).y;
  (peVar7->oldorigin).z = (peVar7->origin).z;
  return;
}


// CFuncTank::Precache  @ 00096ee0  (line 195)

/* DWARF original prototype: void Precache(CFuncTank * this) */

void __thiscall CFuncTank::Precache(CFuncTank *this)

{
  string_t sVar1;
  
  if (this->m_iszSpriteSmoke != 0) {
    (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + this->m_iszSpriteSmoke);
  }
  if (this->m_iszSpriteFlash != 0) {
    (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + this->m_iszSpriteFlash);
  }
  sVar1 = ((this->super_CBaseEntity).pev)->noise;
  if (sVar1 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00096f26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + sVar1);
  return;
}


// CFuncTank::KeyValue  @ 00096f80  (line 207)

/* DWARF original prototype: void KeyValue(CFuncTank * this, KeyValueData * pkvd) */

void __thiscall CFuncTank::KeyValue(CFuncTank *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  string_t sVar2;
  TANKBULLET TVar3;
  long lVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  double dVar10;
  
  bVar9 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar5 = 8;
  pcVar8 = "?yawrate";
  pcVar7 = pkvd->szKeyName;
  pcVar6 = pcVar7;
  do {
    pcVar8 = pcVar8 + 1;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
  } while (bVar9);
  if (bVar9) {
    dVar10 = strtod(pkvd->szValue,(char **)0x0);
    this->m_yawRate = (float)dVar10;
    pkvd->fHandled = 1;
  }
  else {
    iVar5 = 9;
    bVar9 = false;
    pcVar8 = pcVar7;
    pcVar6 = "yawrange";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pcVar8 == *pcVar6;
      pcVar8 = pcVar8 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar9);
    if (bVar9) {
      dVar10 = strtod(pkvd->szValue,(char **)0x0);
      this->m_yawRange = (float)dVar10;
      pkvd->fHandled = 1;
    }
    else {
      iVar5 = 0xd;
      bVar9 = false;
      pcVar8 = pcVar7;
      pcVar6 = "yawtolerance";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar9 = *pcVar8 == *pcVar6;
        pcVar8 = pcVar8 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar9);
      if (bVar9) {
        dVar10 = strtod(pkvd->szValue,(char **)0x0);
        this->m_yawTolerance = (float)dVar10;
        pkvd->fHandled = 1;
      }
      else {
        iVar5 = 0xb;
        bVar9 = false;
        pcVar8 = pcVar7;
        pcVar6 = "pitchrange";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar9 = *pcVar8 == *pcVar6;
          pcVar8 = pcVar8 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar9);
        if (bVar9) {
          dVar10 = strtod(pkvd->szValue,(char **)0x0);
          this->m_pitchRange = (float)dVar10;
          pkvd->fHandled = 1;
        }
        else {
          iVar5 = 10;
          bVar9 = false;
          pcVar8 = pcVar7;
          pcVar6 = "pitchrate";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar9 = *pcVar8 == *pcVar6;
            pcVar8 = pcVar8 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar9);
          if (bVar9) {
            dVar10 = strtod(pkvd->szValue,(char **)0x0);
            this->m_pitchRate = (float)dVar10;
            pkvd->fHandled = 1;
          }
          else {
            iVar5 = 0xf;
            bVar9 = false;
            pcVar8 = pcVar7;
            pcVar6 = "pitchtolerance";
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar9 = *pcVar8 == *pcVar6;
              pcVar8 = pcVar8 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar9);
            if (bVar9) {
              dVar10 = strtod(pkvd->szValue,(char **)0x0);
              this->m_pitchTolerance = (float)dVar10;
              pkvd->fHandled = 1;
            }
            else {
              iVar5 = 9;
              bVar9 = false;
              pcVar8 = pcVar7;
              pcVar6 = "firerate";
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar9 = *pcVar8 == *pcVar6;
                pcVar8 = pcVar8 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar9);
              if (bVar9) {
                dVar10 = strtod(pkvd->szValue,(char **)0x0);
                this->m_fireRate = (float)dVar10;
                pkvd->fHandled = 1;
              }
              else {
                iVar5 = 7;
                bVar9 = false;
                pcVar8 = pcVar7;
                pcVar6 = "barrel";
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar9 = *pcVar8 == *pcVar6;
                  pcVar8 = pcVar8 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar9);
                if (bVar9) {
                  dVar10 = strtod(pkvd->szValue,(char **)0x0);
                  (this->m_barrelPos).x = (float)dVar10;
                  pkvd->fHandled = 1;
                }
                else {
                  iVar5 = 8;
                  bVar9 = false;
                  pcVar8 = pcVar7;
                  pcVar6 = "barrely";
                  do {
                    if (iVar5 == 0) break;
                    iVar5 = iVar5 + -1;
                    bVar9 = *pcVar8 == *pcVar6;
                    pcVar8 = pcVar8 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar9);
                  if (bVar9) {
                    dVar10 = strtod(pkvd->szValue,(char **)0x0);
                    (this->m_barrelPos).y = (float)dVar10;
                    pkvd->fHandled = 1;
                  }
                  else {
                    iVar5 = 8;
                    bVar9 = false;
                    pcVar8 = pcVar7;
                    pcVar6 = "barrelz";
                    do {
                      if (iVar5 == 0) break;
                      iVar5 = iVar5 + -1;
                      bVar9 = *pcVar8 == *pcVar6;
                      pcVar8 = pcVar8 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (bVar9);
                    if (bVar9) {
                      dVar10 = strtod(pkvd->szValue,(char **)0x0);
                      (this->m_barrelPos).z = (float)dVar10;
                      pkvd->fHandled = 1;
                    }
                    else {
                      iVar5 = 0xc;
                      bVar9 = false;
                      pcVar8 = pcVar7;
                      pcVar6 = "spritescale";
                      do {
                        if (iVar5 == 0) break;
                        iVar5 = iVar5 + -1;
                        bVar9 = *pcVar8 == *pcVar6;
                        pcVar8 = pcVar8 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar9);
                      if (bVar9) {
                        dVar10 = strtod(pkvd->szValue,(char **)0x0);
                        this->m_spriteScale = (float)dVar10;
                        pkvd->fHandled = 1;
                      }
                      else {
                        iVar5 = 0xc;
                        bVar9 = false;
                        pcVar8 = pcVar7;
                        pcVar6 = "spritesmoke";
                        do {
                          if (iVar5 == 0) break;
                          iVar5 = iVar5 + -1;
                          bVar9 = *pcVar8 == *pcVar6;
                          pcVar8 = pcVar8 + 1;
                          pcVar6 = pcVar6 + 1;
                        } while (bVar9);
                        if (bVar9) {
                          iVar5 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                          this->m_iszSpriteSmoke = iVar5;
                          pkvd->fHandled = 1;
                        }
                        else {
                          iVar5 = 0xc;
                          bVar9 = false;
                          pcVar8 = pcVar7;
                          pcVar6 = "spriteflash";
                          do {
                            if (iVar5 == 0) break;
                            iVar5 = iVar5 + -1;
                            bVar9 = *pcVar8 == *pcVar6;
                            pcVar8 = pcVar8 + 1;
                            pcVar6 = pcVar6 + 1;
                          } while (bVar9);
                          if (bVar9) {
                            iVar5 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                            this->m_iszSpriteFlash = iVar5;
                            pkvd->fHandled = 1;
                          }
                          else {
                            iVar5 = 0xc;
                            bVar9 = false;
                            pcVar8 = pcVar7;
                            pcVar6 = "rotatesound";
                            do {
                              if (iVar5 == 0) break;
                              iVar5 = iVar5 + -1;
                              bVar9 = *pcVar8 == *pcVar6;
                              pcVar8 = pcVar8 + 1;
                              pcVar6 = pcVar6 + 1;
                            } while (bVar9);
                            if (bVar9) {
                              peVar1 = (this->super_CBaseEntity).pev;
                              sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                              peVar1->noise = sVar2;
                              pkvd->fHandled = 1;
                            }
                            else {
                              iVar5 = 0xc;
                              bVar9 = false;
                              pcVar8 = pcVar7;
                              pcVar6 = "persistence";
                              do {
                                if (iVar5 == 0) break;
                                iVar5 = iVar5 + -1;
                                bVar9 = *pcVar8 == *pcVar6;
                                pcVar8 = pcVar8 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                this->m_persist = (float)dVar10;
                                pkvd->fHandled = 1;
                              }
                              else {
                                iVar5 = 7;
                                bVar9 = false;
                                pcVar8 = pcVar7;
                                pcVar6 = "bullet";
                                do {
                                  if (iVar5 == 0) break;
                                  iVar5 = iVar5 + -1;
                                  bVar9 = *pcVar8 == *pcVar6;
                                  pcVar8 = pcVar8 + 1;
                                  pcVar6 = pcVar6 + 1;
                                } while (bVar9);
                                if (bVar9) {
                                  TVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                  this->m_bulletType = TVar3;
                                  pkvd->fHandled = 1;
                                }
                                else {
                                  iVar5 = 0xe;
                                  bVar9 = false;
                                  pcVar8 = pcVar7;
                                  pcVar6 = "bullet_damage";
                                  do {
                                    if (iVar5 == 0) break;
                                    iVar5 = iVar5 + -1;
                                    bVar9 = *pcVar8 == *pcVar6;
                                    pcVar8 = pcVar8 + 1;
                                    pcVar6 = pcVar6 + 1;
                                  } while (bVar9);
                                  if (bVar9) {
                                    lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
                                    this->m_iBulletDamage = lVar4;
                                    pkvd->fHandled = 1;
                                  }
                                  else {
                                    iVar5 = 0xb;
                                    bVar9 = false;
                                    pcVar8 = pcVar7;
                                    pcVar6 = "firespread";
                                    do {
                                      if (iVar5 == 0) break;
                                      iVar5 = iVar5 + -1;
                                      bVar9 = *pcVar8 == *pcVar6;
                                      pcVar8 = pcVar8 + 1;
                                      pcVar6 = pcVar6 + 1;
                                    } while (bVar9);
                                    if (bVar9) {
                                      lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
                                      this->m_spread = lVar4;
                                      pkvd->fHandled = 1;
                                    }
                                    else {
                                      iVar5 = 9;
                                      bVar9 = false;
                                      pcVar8 = pcVar7;
                                      pcVar6 = "minRange";
                                      do {
                                        if (iVar5 == 0) break;
                                        iVar5 = iVar5 + -1;
                                        bVar9 = *pcVar8 == *pcVar6;
                                        pcVar8 = pcVar8 + 1;
                                        pcVar6 = pcVar6 + 1;
                                      } while (bVar9);
                                      if (bVar9) {
                                        dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                        this->m_minRange = (float)dVar10;
                                        pkvd->fHandled = 1;
                                      }
                                      else {
                                        iVar5 = 9;
                                        bVar9 = false;
                                        pcVar8 = "maxRange";
                                        do {
                                          if (iVar5 == 0) break;
                                          iVar5 = iVar5 + -1;
                                          bVar9 = *pcVar7 == *pcVar8;
                                          pcVar7 = pcVar7 + 1;
                                          pcVar8 = pcVar8 + 1;
                                        } while (bVar9);
                                        if (!bVar9) {
                                          CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
                                          return;
                                        }
                                        dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                        this->m_maxRange = (float)dVar10;
                                        pkvd->fHandled = 1;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// CFuncTank::OnControls  @ 00097d40  (line 317)

/* DWARF original prototype: BOOL OnControls(CFuncTank * this, entvars_t * pevTest) */

BOOL __thiscall CFuncTank::OnControls(CFuncTank *this,entvars_t *pevTest)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: Vector offset@[???] */
  if ((((this->super_CBaseEntity).pev)->spawnflags & 0x20U) != 0) {
                    /* Unresolved local var: Vector offset@[???] */
    fVar1 = (this->m_vecControllerUsePos).z - (pevTest->origin).z;
    fVar2 = (this->m_vecControllerUsePos).y - (pevTest->origin).y;
    fVar3 = (this->m_vecControllerUsePos).x - (pevTest->origin).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
    fVar3 = SQRT(fVar1);
    if (NAN(fVar3)) {
      fVar3 = sqrtf(fVar1);
    }
    return (uint)(fVar3 < 30.0);
  }
  return 0;
}


// CFuncTank::StartControl  @ 0006c270  (line 329)

/* DWARF original prototype: BOOL StartControl(CFuncTank * this, CBasePlayer * pController) */

BOOL __thiscall CFuncTank::StartControl(CFuncTank *this,CBasePlayer *pController)

{
  uint *puVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int in_EDX;
  undefined4 extraout_EDX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  
  bVar6 = 0;
  (*g_engfuncs.pfnAlertMessage)(at_console,"using TANK!\n");
  *(int *)(in_EAX + 0x474) = in_EDX;
  piVar2 = *(int **)(in_EDX + 0x8fc);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x124))(piVar2,0,extraout_EDX,extraout_EDX);
    *(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x474) + 4) + 0xc0) = 0;
    *(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x474) + 4) + 0xbc) = 0;
  }
  puVar1 = (uint *)(*(int *)(in_EAX + 0x474) + 0x8d4);
  *puVar1 = *puVar1 | 1;
  puVar4 = (undefined4 *)(*(int *)(*(int *)(in_EAX + 0x474) + 4) + 8);
  puVar5 = (undefined4 *)(in_EAX + 0x47c);
  for (iVar3 = 3; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
    puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
  }
  *(float *)(*(int *)(in_EAX + 4) + 0x104) = *(float *)(*(int *)(in_EAX + 4) + 0x100) + 0.1;
  return 1;
}


// CFuncTank::StartControl  @ 00098cb0  (line 330)

/* DWARF original prototype: BOOL StartControl(CFuncTank * this, CBasePlayer * pController) */

BOOL __thiscall CFuncTank::StartControl(CFuncTank *this,CBasePlayer *pController)

{
  CBasePlayerItem *pCVar1;
  entvars_t *peVar2;
  
  if (this->m_pController == (CBasePlayer *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"using TANK!\n");
    this->m_pController = pController;
    pCVar1 = pController->m_pActiveItem;
    if (pCVar1 != (CBasePlayerItem *)0x0) {
      (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
                (pCVar1,0);
      ((this->m_pController->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->weaponmodel = 0;
      ((this->m_pController->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->viewmodel = 0;
      pController = this->m_pController;
    }
    pController->m_iHideHUD = pController->m_iHideHUD | 1;
    peVar2 = (this->m_pController->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (this->m_vecControllerUsePos).x = (peVar2->origin).x;
    (this->m_vecControllerUsePos).y = (peVar2->origin).y;
    (this->m_vecControllerUsePos).z = (peVar2->origin).z;
    peVar2 = (this->super_CBaseEntity).pev;
    peVar2->nextthink = peVar2->ltime + 0.1;
    return 1;
  }
  return 0;
}


// CFuncTank::StopControl  @ 00098d90  (line 353)

/* DWARF original prototype: void StopControl(CFuncTank * this) */

void __thiscall CFuncTank::StopControl(CFuncTank *this)

{
  int *piVar1;
  CBasePlayerItem *pCVar2;
  entvars_t *peVar3;
  
  if (this->m_pController != (CBasePlayer *)0x0) {
    pCVar2 = this->m_pController->m_pActiveItem;
    if (pCVar2 != (CBasePlayerItem *)0x0) {
      (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                (pCVar2);
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"stopped using TANK\n");
    piVar1 = &this->m_pController->m_iHideHUD;
    *piVar1 = *piVar1 & 0xfffffffe;
    ((this->super_CBaseEntity).pev)->nextthink = 0.0;
    peVar3 = (this->super_CBaseEntity).pev;
    this->m_pController = (CBasePlayer *)0x0;
    if ((peVar3->spawnflags & 1) != 0) {
      peVar3->nextthink = peVar3->ltime + 1.0;
    }
  }
  return;
}


// CFuncTank::ControllerPostFrame  @ 00098e10  (line 374)

/* DWARF original prototype: void ControllerPostFrame(CFuncTank * this) */

void __thiscall CFuncTank::ControllerPostFrame(CFuncTank *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  _func_int_varargs *p_Var4;
  entvars_t *peVar5;
  entvars_t *peVar6;
  CBasePlayer *pCVar7;
  float local_58 [3];
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  if ((this->m_flNextAttack <= gpGlobals->time) &&
     ((((this->m_pController->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity.pev)->button & 1) != 0)) {
                    /* Unresolved local var: Vector vecForward@[???] */
    (*g_engfuncs.pfnAngleVectors)
              (&(((this->super_CBaseEntity).pev)->angles).x,local_58,(float *)0x0,(float *)0x0);
    this->m_fireLast = (gpGlobals->time - 1.0 / this->m_fireRate) - 0.01;
    p_Var4 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x41];
    peVar5 = (this->m_pController->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
    (*g_engfuncs.pfnAngleVectors)
              (&(((this->super_CBaseEntity).pev)->angles).x,&local_40,&local_34,&local_28);
    peVar6 = (this->super_CBaseEntity).pev;
    fVar1 = (this->m_barrelPos).z;
    fVar2 = (this->m_barrelPos).y;
    fVar3 = (this->m_barrelPos).x;
    local_44 = local_20 * fVar1 + local_2c * fVar2 + local_38 * fVar3 + (peVar6->origin).z;
    local_48 = local_24 * fVar1 + local_30 * fVar2 + local_3c * fVar3 + (peVar6->origin).y;
    local_4c = fVar1 * local_28 + fVar2 * local_34 + fVar3 * local_40 + (peVar6->origin).x;
    (*p_Var4)(this,&local_4c,local_58,peVar5);
    pCVar7 = this->m_pController;
    if ((pCVar7 != (CBasePlayer *)0x0) &&
       ((((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->flags & 8) != 0)) {
      pCVar7->m_iWeaponVolume = 1000;
    }
    this->m_flNextAttack = 1.0 / this->m_fireRate + gpGlobals->time;
  }
  return;
}


// CFuncTank::Use  @ 00098fa0  (line 400)

/* DWARF original prototype: void Use(CFuncTank * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTank::Use(CFuncTank *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  int *piVar1;
  CBasePlayerItem *pCVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  entvars_t *peVar6;
  
  uVar5 = ((this->super_CBaseEntity).pev)->spawnflags;
  if ((uVar5 & 0x20) == 0) {
    iVar3 = CBaseEntity::ShouldToggle(&this->super_CBaseEntity,useType,uVar5 & 1);
    if (iVar3 != 0) {
      peVar6 = (this->super_CBaseEntity).pev;
      uVar5 = peVar6->spawnflags;
      if ((uVar5 & 1) == 0) {
        peVar6->spawnflags = uVar5 | 1;
        peVar6 = (this->super_CBaseEntity).pev;
        peVar6->nextthink = peVar6->ltime + 0.1;
        this->m_fireLast = 0.0;
        return;
      }
      peVar6->spawnflags = uVar5 & 0xfffffffe;
      peVar6 = (this->super_CBaseEntity).pev;
      this->m_fireLast = 0.0;
      uVar5 = peVar6->spawnflags;
      if ((uVar5 & 0x8000) != 0) {
        EMIT_SOUND_DYN(peVar6->pContainingEntity,6,gpGlobals->pStringBase + peVar6->noise,0.0,0.0,
                       0x20,100);
        peVar6 = (this->super_CBaseEntity).pev;
        uVar5 = peVar6->spawnflags;
      }
      peVar6->spawnflags = uVar5 & 0xffff7fff;
    }
  }
  else {
    iVar3 = (*pActivator->_vptr_CBaseEntity[10])(pActivator);
    if ((iVar3 == 2) &&
       (BVar4 = ActivationSucceeded(&this->super_CBaseEntity,(CBasePlayer *)pActivator,
                                    (CBaseEntity *)0x0), BVar4 != 0)) {
      if ((value == 2.0) && (useType == USE_SET)) {
        ControllerPostFrame(this);
        return;
      }
      if (this->m_pController == (CBasePlayer *)0x0) {
        if ((useType != USE_OFF) &&
           (EHANDLE::operator=((EHANDLE *)&pActivator[1].rs_gr,&this->super_CBaseEntity),
           this->m_pController == (CBasePlayer *)0x0)) {
          StartControl(this,(CBasePlayer *)pActivator);
          return;
        }
      }
      else {
        pCVar2 = this->m_pController->m_pActiveItem;
        if (pCVar2 != (CBasePlayerItem *)0x0) {
          (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x47])(pCVar2);
        }
        (*g_engfuncs.pfnAlertMessage)(at_console,"stopped using TANK\n");
        piVar1 = &this->m_pController->m_iHideHUD;
        *piVar1 = *piVar1 & 0xfffffffe;
        ((this->super_CBaseEntity).pev)->nextthink = 0.0;
        this->m_pController = (CBasePlayer *)0x0;
        peVar6 = (this->super_CBaseEntity).pev;
        if ((peVar6->spawnflags & 1) != 0) {
          peVar6->nextthink = peVar6->ltime + 1.0;
        }
      }
    }
  }
  return;
}


// CFuncTank::FindTarget  @ 00099500  (line 441)

/* DWARF original prototype: edict_t * FindTarget(CFuncTank * this, edict_t * pPlayer) */

edict_t * __thiscall CFuncTank::FindTarget(CFuncTank *this,edict_t *pPlayer)

{
  return pPlayer;
}


// CFuncTank::InRange  @ 00099510  (line 446)

/* DWARF original prototype: BOOL InRange(CFuncTank * this, float range) */

BOOL __thiscall CFuncTank::InRange(CFuncTank *this,float range)

{
  BOOL BVar1;
  
  BVar1 = 0;
  if (this->m_minRange <= range) {
    if (0.0 < this->m_maxRange) {
      return (uint)(range <= this->m_maxRange);
    }
    BVar1 = 1;
  }
  return BVar1;
}


// CFuncTank::Think  @ 00099ea0  (line 457)

/* DWARF original prototype: void Think(CFuncTank * this) */

void __thiscall CFuncTank::Think(CFuncTank *this)

{
  entvars_t *peVar1;
  uint uVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  TrackTarget(this);
  peVar1 = (this->super_CBaseEntity).pev;
  if ((ABS((peVar1->avelocity).x) <= 1.0) && (ABS((peVar1->avelocity).y) <= 1.0)) {
    uVar2 = peVar1->spawnflags;
    if ((uVar2 & 0x8000) != 0) {
      EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20
                     ,100);
      peVar1 = (this->super_CBaseEntity).pev;
      uVar2 = peVar1->spawnflags;
    }
    peVar1->spawnflags = uVar2 & 0xffff7fff;
    return;
  }
  if ((peVar1->noise != 0) && ((peVar1->spawnflags & 0x8000U) == 0)) {
    peVar1->spawnflags = peVar1->spawnflags | 0x8000;
    peVar1 = (this->super_CBaseEntity).pev;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.85,0.8,0,100
                  );
    return;
  }
  return;
}


// CFuncTank::TrackTarget  @ 00099680  (line 468)

/* DWARF original prototype: void TrackTarget(CFuncTank * this) */

void __thiscall CFuncTank::TrackTarget(CFuncTank *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  _func_int_varargs *p_Var4;
  entvars_t *peVar5;
  edict_t *peVar6;
  bool bVar7;
  edict_t *peVar8;
  int iVar9;
  entvars_t *peVar10;
  float *pfVar11;
  float *pfVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined4 local_100;
  float *local_dc;
  Vector local_a8;
  Vector local_9c [4];
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  _1TraceResult local_54;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: edict_t * pPlayer@[???]
                       Unresolved local var: BOOL updateTime@[???]
                       Unresolved local var: BOOL lineOfSight@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector direction@[???]
                       Unresolved local var: Vector targetPosition@[???]
                       Unresolved local var: Vector barrelEnd@[???]
                       Unresolved local var: edict_t * pTarget@[???]
                       Unresolved local var: float distY@[???]
                       Unresolved local var: float distX@[???] */
  pfVar12 = (float *)&stack0xffffff04;
  local_100 = 0x996a3;
  peVar8 = (*g_engfuncs.pfnFindClientInPVS)(((this->super_CBaseEntity).pev)->pContainingEntity);
  if (this->m_pController == (CBasePlayer *)0x0) {
    peVar10 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: float range@[???] */
    if ((peVar10->spawnflags & 1) == 0) {
      return;
    }
    peVar10->nextthink = peVar10->ltime + 0.1;
    if (peVar8 != (edict_t *)0x0) {
      local_100 = 0x998ff;
      iVar9 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar8);
      if (iVar9 != 0) {
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
        local_100 = 0x9993b;
        (*g_engfuncs.pfnAngleVectors)
                  (&(((this->super_CBaseEntity).pev)->angles).x,&local_6c,&local_60,
                   (float *)&local_54);
        peVar10 = (this->super_CBaseEntity).pev;
        fVar13 = (this->m_barrelPos).z;
        fVar15 = (this->m_barrelPos).y;
        fVar14 = (this->m_barrelPos).x;
        local_9c[0].z =
             (float)local_54.fInOpen * fVar13 +
             local_58 * fVar15 + local_64 * fVar14 + (peVar10->origin).z;
        local_9c[0].y =
             (float)local_54.fStartSolid * fVar13 +
             local_5c * fVar15 + local_68 * fVar14 + (peVar10->origin).y;
        local_9c[0].x =
             fVar13 * (float)local_54.fAllSolid +
             fVar15 * local_60 + fVar14 * local_6c + (peVar10->origin).x;
        local_a8.z = (peVar8->v).origin.z + (peVar8->v).view_ofs.z;
        local_a8.y = (peVar8->v).origin.y + (peVar8->v).view_ofs.y;
        local_a8.x = (peVar8->v).origin.x + (peVar8->v).view_ofs.x;
        fVar13 = (local_a8.z - local_9c[0].z) * (local_a8.z - local_9c[0].z) +
                 (local_a8.y - local_9c[0].y) * (local_a8.y - local_9c[0].y) +
                 (local_a8.x - local_9c[0].x) * (local_a8.x - local_9c[0].x);
        fVar15 = SQRT(fVar13);
        if (NAN(fVar15)) {
          local_100 = 0x99e75;
          fVar15 = sqrtf(fVar13);
        }
        if (fVar15 < this->m_minRange) {
          return;
        }
        if ((0.0 < this->m_maxRange) && (this->m_maxRange < fVar15)) {
          return;
        }
        local_100 = 0x99a89;
        UTIL_TraceLine(local_9c,&local_a8,dont_ignore_monsters,
                       ((this->super_CBaseEntity).pev)->pContainingEntity,&local_54);
                    /* Unresolved local var: CBaseEntity * pInstance@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if (((((local_54.flFraction != 1.0) && (peVar8 != local_54.pHit)) ||
             (fVar15 < this->m_minRange)) ||
            ((0.0 < this->m_maxRange && (this->m_maxRange < fVar15)))) ||
           (peVar8->pvPrivateData == (int *)0x0)) {
LAB_00099abb:
          bVar7 = false;
          local_dc = &local_60;
        }
        else {
          local_100 = 0x99d61;
          iVar9 = (**(code **)(*(int *)peVar8->pvPrivateData + 0x88))();
          if (iVar9 == 0) goto LAB_00099abb;
          bVar7 = true;
          local_100 = 0x99d85;
          (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x42])();
          pfVar12 = (float *)&local_100;
          (this->m_sightOrigin).x = local_64;
          (this->m_sightOrigin).y = local_60;
          (this->m_sightOrigin).z = local_5c;
        }
        peVar10 = (this->super_CBaseEntity).pev;
        fVar13 = (this->m_sightOrigin).z;
        fVar15 = (peVar10->origin).z;
        fVar14 = (this->m_sightOrigin).y;
        fVar1 = (peVar10->origin).y;
        fVar2 = (this->m_sightOrigin).x;
        fVar3 = (peVar10->origin).x;
        *pfVar12 = (float)local_dc;
        pfVar12[1] = (float)(pfVar12 + 0x12);
        pfVar12[0x12] = fVar2 - fVar3;
        pfVar12[0x13] = fVar14 - fVar1;
        pfVar12[0x14] = fVar13 - fVar15;
        pfVar12[-1] = 8.8211e-40;
        UTIL_VecToAngles((Vector *)*pfVar12,(Vector *)pfVar12[1]);
        pfVar12[0xf] = pfVar12[0x27];
        pfVar12[0x10] = pfVar12[0x28];
        pfVar12[0x11] = pfVar12[0x29];
        fVar13 = pfVar12[0x14] * pfVar12[0x14] +
                 pfVar12[0x13] * pfVar12[0x13] + pfVar12[0x12] * pfVar12[0x12];
        fVar15 = SQRT(fVar13);
        if (NAN(fVar15)) {
          *pfVar12 = fVar13;
          pfVar12[-1] = 8.8339e-40;
          fVar15 = sqrtf(*pfVar12);
        }
        pfVar12[2] = fVar15;
        pfVar12[1] = (float)(pfVar12 + 0xf);
        *pfVar12 = (float)this;
        pfVar12[-1] = 8.82239e-40;
        AdjustAnglesForBarrel((CFuncTank *)*pfVar12,(Vector *)pfVar12[1],pfVar12[2]);
        fVar13 = pfVar12[0xf];
        goto LAB_000996e8;
      }
    }
    peVar10 = (this->super_CBaseEntity).pev;
    if ((peVar10->spawnflags & 1) != 0) {
      peVar10->nextthink = peVar10->ltime + 2.0;
    }
  }
  else {
    bVar7 = false;
    fVar13 = 0.0 - (((this->m_pController->super_CBaseMonster).super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->v_angle).x;
    peVar10 = (this->super_CBaseEntity).pev;
    peVar10->nextthink = peVar10->ltime + 0.05;
    pfVar12 = (float *)&stack0xffffff04;
LAB_000996e8:
    pfVar12[0xf] = -fVar13;
    fVar13 = this->m_yawCenter;
    *pfVar12 = pfVar12[0x10];
    pfVar12[1] = fVar13;
    pfVar12[9] = fVar13;
    pfVar12[-1] = 8.80705e-40;
    fVar13 = UTIL_AngleDistance(*pfVar12,pfVar12[1]);
    pfVar12[0x10] = pfVar12[9] + fVar13;
    fVar13 = this->m_pitchCenter;
    *pfVar12 = pfVar12[0xf];
    pfVar12[1] = fVar13;
    pfVar12[9] = fVar13;
    pfVar12[-1] = 8.80761e-40;
    fVar13 = UTIL_AngleDistance(*pfVar12,pfVar12[1]);
    pfVar12[0xf] = pfVar12[9] + fVar13;
    fVar13 = pfVar12[0x10];
    fVar15 = this->m_yawCenter + this->m_yawRange;
    if (fVar15 < fVar13) {
      pfVar12[0x10] = fVar15;
    }
    else {
      fVar15 = this->m_yawCenter - this->m_yawRange;
      if (fVar15 <= fVar13) {
        fVar15 = fVar13;
        if (bVar7) {
          this->m_lastSightTime = gpGlobals->time;
        }
      }
      else {
        pfVar12[0x10] = fVar15;
      }
    }
    fVar13 = (((this->super_CBaseEntity).pev)->angles).y;
    *pfVar12 = fVar15;
    pfVar12[1] = fVar13;
    pfVar12[-1] = 8.80876e-40;
    fVar13 = UTIL_AngleDistance(*pfVar12,pfVar12[1]);
    peVar10 = (this->super_CBaseEntity).pev;
    pfVar12[9] = fVar13;
    (peVar10->avelocity).y = fVar13 * 10.0;
    peVar10 = (this->super_CBaseEntity).pev;
    fVar13 = (peVar10->avelocity).y;
    fVar15 = this->m_yawRate;
    if ((fVar15 < fVar13) || (fVar15 = -fVar15, fVar13 < fVar15)) {
      (peVar10->avelocity).y = fVar15;
      peVar10 = (this->super_CBaseEntity).pev;
    }
    fVar13 = pfVar12[0xf];
    fVar15 = this->m_pitchCenter + this->m_pitchRange;
    if (fVar13 <= fVar15) {
      fVar15 = this->m_pitchCenter - this->m_pitchRange;
      if (fVar13 < fVar15) {
        pfVar12[0xf] = fVar15;
        fVar13 = fVar15;
      }
    }
    else {
      pfVar12[0xf] = fVar15;
      fVar13 = fVar15;
    }
    fVar15 = (peVar10->angles).x;
    *pfVar12 = fVar13;
    pfVar12[1] = fVar15;
    pfVar12[-1] = 8.81065e-40;
    fVar14 = UTIL_AngleDistance(*pfVar12,pfVar12[1]);
    (((this->super_CBaseEntity).pev)->avelocity).x = fVar14 * 10.0;
    peVar10 = (this->super_CBaseEntity).pev;
    fVar13 = (peVar10->avelocity).x;
    fVar15 = this->m_pitchRate;
    if ((fVar15 < fVar13) || (fVar15 = -fVar15, fVar13 < fVar15)) {
      (peVar10->avelocity).x = fVar15;
    }
    if (this->m_pController == (CBasePlayer *)0x0) {
      if (this->m_persist <= gpGlobals->time - this->m_lastSightTime) {
LAB_00099cb2:
        this->m_fireLast = 0.0;
        return;
      }
      if ((this->m_pitchTolerance <= ABS(fVar14)) || (this->m_yawTolerance <= ABS(pfVar12[9]))) {
        peVar10 = (this->super_CBaseEntity).pev;
        if ((peVar10->spawnflags & 0x10) == 0) goto LAB_00099cb2;
      }
      else {
        peVar10 = (this->super_CBaseEntity).pev;
      }
                    /* Unresolved local var: BOOL fire@[???]
                       Unresolved local var: Vector forward@[???] */
      pfVar12[3] = 0.0;
      pfVar12[2] = 0.0;
      pfVar12[1] = (float)(pfVar12 + 0x1b);
      *pfVar12 = (float)&peVar10->angles;
      pfVar12[-1] = 8.82391e-40;
      (*g_engfuncs.pfnAngleVectors)
                ((float *)*pfVar12,(float *)pfVar12[1],(float *)pfVar12[2],(float *)pfVar12[3]);
      peVar10 = (this->super_CBaseEntity).pev;
      if ((peVar10->spawnflags & 0x10) == 0) {
        pfVar11 = pfVar12 + 0x27;
      }
      else {
                    /* Unresolved local var: float length@[???] */
        fVar13 = pfVar12[0x14] * pfVar12[0x14] +
                 pfVar12[0x13] * pfVar12[0x13] + pfVar12[0x12] * pfVar12[0x12];
        fVar15 = SQRT(fVar13);
        if (NAN(fVar15)) {
          *pfVar12 = fVar13;
          pfVar12[-1] = 8.83411e-40;
          fVar15 = sqrtf(*pfVar12);
        }
        peVar6 = ((this->super_CBaseEntity).pev)->pContainingEntity;
        pfVar12[4] = (float)(pfVar12 + 0x2a);
        pfVar12[1] = (float)(pfVar12 + 0x27);
        pfVar12[3] = (float)peVar6;
        pfVar12[2] = 0.0;
        *pfVar12 = (float)(pfVar12 + 0x18);
        pfVar12[9] = (float)(pfVar12 + 0x27);
        pfVar12[0x27] = fVar15 * pfVar12[0x1b] + pfVar12[0x18];
        pfVar12[0x28] = pfVar12[0x1c] * fVar15 + pfVar12[0x19];
        pfVar12[0x29] = pfVar12[0x1d] * fVar15 + pfVar12[0x1a];
        pfVar12[-1] = 8.83314e-40;
        UTIL_TraceLine((Vector *)*pfVar12,(Vector *)pfVar12[1],(IGNORE_MONSTERS)pfVar12[2],
                       (edict_t *)pfVar12[3],(_1TraceResult *)pfVar12[4]);
        pfVar11 = (float *)pfVar12[9];
        if (peVar8 != (edict_t *)pfVar12[0x36]) goto LAB_00099cb2;
        peVar10 = (this->super_CBaseEntity).pev;
      }
      p_Var4 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x41];
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
      pfVar12[2] = (float)(pfVar12 + 0x24);
      pfVar12[1] = (float)(pfVar12 + 0x21);
      *pfVar12 = (float)&peVar10->angles;
      pfVar12[3] = (float)pfVar11;
      pfVar12[-1] = 8.82487e-40;
      (*g_engfuncs.pfnAngleVectors)
                ((float *)*pfVar12,(float *)pfVar12[1],(float *)pfVar12[2],(float *)pfVar12[3]);
      peVar5 = (this->super_CBaseEntity).pev;
      fVar13 = (this->m_barrelPos).z;
      fVar15 = (this->m_barrelPos).y;
      fVar14 = (this->m_barrelPos).x;
      fVar1 = (peVar5->origin).z;
      fVar2 = (peVar5->origin).y;
      fVar3 = (peVar5->origin).x;
      pfVar12[3] = (float)peVar10;
      pfVar12[2] = (float)(pfVar12 + 0x1b);
      pfVar12[1] = (float)(pfVar12 + 0x1e);
      *pfVar12 = (float)this;
      pfVar12[0x1e] =
           fVar13 * pfVar12[0x27] + fVar15 * pfVar12[0x24] + fVar14 * pfVar12[0x21] + fVar3;
      pfVar12[0x1f] =
           pfVar12[0x28] * fVar13 + pfVar12[0x25] * fVar15 + pfVar12[0x22] * fVar14 + fVar2;
      pfVar12[0x20] =
           pfVar12[0x29] * fVar13 + pfVar12[0x26] * fVar15 + pfVar12[0x23] * fVar14 + fVar1;
      pfVar12[-1] = 8.82713e-40;
      (*p_Var4)();
    }
  }
  return;
}


// CFuncTank::AdjustAnglesForBarrel  @ 00099560  (line 612)

/* DWARF original prototype: void AdjustAnglesForBarrel(CFuncTank * this, Vector * angles, float
   distance) */

void __thiscall CFuncTank::AdjustAnglesForBarrel(CFuncTank *this,Vector *angles,float distance)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  
                    /* Unresolved local var: float r2@[???]
                       Unresolved local var: float d2@[???] */
  fVar1 = (this->m_barrelPos).y;
  if (fVar1 == 0.0) {
    fVar1 = (this->m_barrelPos).z;
    if (fVar1 != 0.0) {
      fVar3 = (distance - fVar1) * (distance - fVar1);
LAB_00099618:
      fVar3 = fVar3 - fVar1 * fVar1;
      fVar2 = SQRT(fVar3);
      if (NAN(fVar2)) {
        dVar4 = sqrt((double)fVar3);
        fVar2 = (float)dVar4;
        fVar1 = (this->m_barrelPos).z;
      }
      dVar4 = atan2((double)-fVar1,(double)fVar2);
      angles->x = (float)((longdouble)dVar4 * (longdouble)57.29577951308232 + (longdouble)angles->x)
      ;
      return;
    }
  }
  else {
    fVar3 = distance - (this->m_barrelPos).z;
    fVar3 = fVar3 * fVar3;
    fVar1 = fVar3 - fVar1 * fVar1;
    fVar2 = SQRT(fVar1);
    if (NAN(fVar2)) {
      dVar4 = sqrt((double)fVar1);
      fVar2 = (float)dVar4;
    }
    dVar4 = atan2((double)(this->m_barrelPos).y,(double)fVar2);
    angles->y = (float)((longdouble)dVar4 * (longdouble)57.29577951308232 + (longdouble)angles->y);
    fVar1 = (this->m_barrelPos).z;
    if (fVar1 != 0.0) goto LAB_00099618;
  }
  return;
}


// CFuncTank::Fire  @ 00097460  (line 636)

/* DWARF original prototype: void Fire(CFuncTank * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTank::Fire(CFuncTank *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  entvars_t *peVar5;
  _2globalvars_t *p1Var6;
  CSprite *pCVar7;
  longdouble lVar8;
  
  if (this->m_fireLast != 0.0) {
    if (this->m_iszSpriteSmoke == 0) {
      iVar4 = this->m_iszSpriteFlash;
    }
    else {
                    /* Unresolved local var: CSprite * pSprite@[???] */
      pCVar7 = CSprite::SpriteCreate(gpGlobals->pStringBase + this->m_iszSpriteSmoke,barrelEnd,1);
      lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(15.0,20.0);
      peVar5 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
      (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateUntilDead;
      (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar5->framerate = (float)lVar8;
      p1Var6 = gpGlobals;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->dmgtime =
           (float)((longdouble)pCVar7->m_maxFrame / lVar8 + (longdouble)gpGlobals->time);
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->nextthink = p1Var6->time;
      peVar5 = (this->super_CBaseEntity).pev;
      fVar1 = (peVar5->rendercolor).z;
      fVar2 = (peVar5->rendercolor).y;
      fVar3 = (peVar5->rendercolor).x;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 4;
      (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = (float)(int)fVar3;
      (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = (float)(int)fVar2;
      (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = (float)(int)fVar1;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0;
      peVar5 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
      lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(40.0,80.0);
      (peVar5->velocity).z = (float)lVar8;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->scale = this->m_spriteScale;
      iVar4 = this->m_iszSpriteFlash;
    }
    if (iVar4 != 0) {
                    /* Unresolved local var: CSprite * pSprite@[???] */
      pCVar7 = CSprite::SpriteCreate(gpGlobals->pStringBase + iVar4,barrelEnd,1);
      peVar5 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
      (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateUntilDead;
      (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar5->framerate = 60.0;
      p1Var6 = gpGlobals;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->dmgtime =
           pCVar7->m_maxFrame / 60.0 + gpGlobals->time;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->nextthink = p1Var6->time;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 5;
      (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = 255.0;
      (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = 255.0;
      (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = 255.0;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0xe;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->scale = this->m_spriteScale;
    }
    CBaseEntity::SUB_UseTargets(&this->super_CBaseEntity,&this->super_CBaseEntity,USE_TOGGLE,0.0);
  }
  this->m_fireLast = gpGlobals->time;
  return;
}


// CFuncTank::TankTrace  @ 0009a170  (line 661)

/* DWARF original prototype: void TankTrace(CFuncTank * this, Vector * vecStart, Vector *
   vecForward, Vector * vecSpread, TraceResult * tr) */

void __thiscall
CFuncTank::TankTrace
          (CFuncTank *this,Vector *vecStart,Vector *vecForward,Vector *vecSpread,TraceResult *tr)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  Vector local_18;
  
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  do {
    lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar4 = lVar4 + (longdouble)(float)lVar3;
    lVar1 = (longdouble)(float)((longdouble)(float)lVar1 + lVar2);
  } while ((longdouble)1 < lVar4 * lVar4 + lVar1 * lVar1);
  lVar4 = lVar4 * (longdouble)vecSpread->y;
  lVar1 = lVar1 * (longdouble)vecSpread->x;
  local_18.x = (vec_t)((lVar4 * (longdouble)(gpGlobals->v_up).x +
                       lVar1 * (longdouble)(gpGlobals->v_right).x + (longdouble)vecForward->x) *
                       (longdouble)4096.0 + (longdouble)vecStart->x);
  local_18.y = (vec_t)(((longdouble)(gpGlobals->v_up).y * lVar4 +
                       (longdouble)(gpGlobals->v_right).y * lVar1 + (longdouble)vecForward->y) *
                       (longdouble)4096.0 + (longdouble)vecStart->y);
  local_18.z = (vec_t)(((longdouble)(gpGlobals->v_up).z * lVar4 +
                       (longdouble)(gpGlobals->v_right).z * lVar1 + (longdouble)vecForward->z) *
                       (longdouble)4096.0 + (longdouble)vecStart->z);
  UTIL_TraceLine(vecStart,&local_18,dont_ignore_monsters,
                 ((this->super_CBaseEntity).pev)->pContainingEntity,tr);
  return;
}


// CFuncTank::StartRotSound  @ 0009a7a0  (line 680)

/* DWARF original prototype: void StartRotSound(CFuncTank * this) */

void __thiscall CFuncTank::StartRotSound(CFuncTank *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->noise != 0) && ((peVar1->spawnflags & 0x8000U) == 0)) {
    peVar1->spawnflags = peVar1->spawnflags | 0x8000;
    peVar1 = (this->super_CBaseEntity).pev;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.85,0.8,0,100
                  );
    return;
  }
  return;
}


// CFuncTank::StopRotSound  @ 0009a830  (line 689)

/* DWARF original prototype: void StopRotSound(CFuncTank * this) */

void __thiscall CFuncTank::StopRotSound(CFuncTank *this)

{
  uint uVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  uVar1 = peVar2->spawnflags;
  if ((uVar1 & 0x8000) != 0) {
    EMIT_SOUND_DYN(peVar2->pContainingEntity,6,gpGlobals->pStringBase + peVar2->noise,0.0,0.0,0x20,
                   100);
    peVar2 = (this->super_CBaseEntity).pev;
    uVar1 = peVar2->spawnflags;
  }
  peVar2->spawnflags = uVar1 & 0xffff7fff;
  return;
}


// CFuncTankGun::~CFuncTankGun  @ 0009aba0  (line 695)

/* DWARF original prototype: void ~CFuncTankGun(CFuncTankGun * this, int __in_chrg) */

void __thiscall CFuncTankGun::~CFuncTankGun(CFuncTankGun *this,int __in_chrg)

{
  return;
}


// func_tank  @ 0009a8b0  (line 700)

void func_tank(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x4f0,pev);
  *puVar1 = &PTR__CFuncTankGun_0014e75c;
  puVar1[1] = pev;
  return;
}


// CFuncTankGun::Fire  @ 00097a60  (line 703)

/* DWARF original prototype: void Fire(CFuncTankGun * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTankGun::Fire(CFuncTankGun *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  TANKBULLET TVar1;
  int iVar2;
  Vector vecSrc;
  Vector vecDirShooting;
  Vector vecSpread;
  entvars_t *pevAttacker_00;
  entvars_t *peVar3;
  undefined4 uVar4;
  int iVar5;
  vec_t in_stack_ffffff9c;
  float in_stack_ffffffa0;
  int in_stack_ffffffa4;
  int in_stack_ffffffa8;
  int in_stack_ffffffac;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???] */
  if ((this->super_CFuncTank).m_fireLast != 0.0) {
                    /* Unresolved local var: int i@[DW_OP_reg6(ESI)]
                       Unresolved local var: int bulletCount@[???] */
    UTIL_MakeAimVectors(&((this->super_CFuncTank).super_CBaseEntity.pev)->angles);
    pevAttacker_00 =
         (entvars_t *)
         (int)((gpGlobals->time - (this->super_CFuncTank).m_fireLast) *
              (this->super_CFuncTank).m_fireRate);
    if ((int)pevAttacker_00 < 1) {
      return;
    }
    peVar3 = (entvars_t *)0x0;
    do {
      TVar1 = (this->super_CFuncTank).m_bulletType;
      if (TVar1 == TANK_BULLET_MP5) {
        iVar2 = (this->super_CFuncTank).m_spread;
        local_34 = forward->x;
        local_30 = forward->y;
        local_28 = gTankSpread[iVar2].x;
        local_2c = forward->z;
        local_40 = barrelEnd->x;
        local_3c = barrelEnd->y;
        local_38 = barrelEnd->z;
        iVar5 = (this->super_CFuncTank).m_iBulletDamage;
        local_24 = gTankSpread[iVar2].y;
        local_20 = gTankSpread[iVar2].z;
        uVar4 = 9;
LAB_00097bb0:
        vecSrc.y = (vec_t)&local_34;
        vecSrc.x = (vec_t)&local_40;
        vecSrc.z = (vec_t)&local_28;
        vecDirShooting.y = (vec_t)uVar4;
        vecDirShooting.x = 4096.0;
        vecDirShooting.z = 1.4013e-45;
        vecSpread.y = (vec_t)pevAttacker;
        vecSpread.x = (vec_t)iVar5;
        vecSpread.z = in_stack_ffffff9c;
        CBaseEntity::FireBullets
                  ((CBaseEntity *)this,1,vecSrc,vecDirShooting,vecSpread,in_stack_ffffffa0,
                   in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,pevAttacker_00);
      }
      else {
        if (TVar1 == TANK_BULLET_12MM) {
          iVar2 = (this->super_CFuncTank).m_spread;
          local_34 = forward->x;
          local_30 = forward->y;
          local_28 = gTankSpread[iVar2].x;
          local_2c = forward->z;
          local_40 = barrelEnd->x;
          local_3c = barrelEnd->y;
          local_38 = barrelEnd->z;
          iVar5 = (this->super_CFuncTank).m_iBulletDamage;
          local_24 = gTankSpread[iVar2].y;
          local_20 = gTankSpread[iVar2].z;
          uVar4 = 10;
          goto LAB_00097bb0;
        }
        if (TVar1 == TANK_BULLET_9MM) {
          iVar2 = (this->super_CFuncTank).m_spread;
          local_34 = forward->x;
          local_30 = forward->y;
          local_28 = gTankSpread[iVar2].x;
          local_2c = forward->z;
          local_40 = barrelEnd->x;
          local_3c = barrelEnd->y;
          local_38 = barrelEnd->z;
          iVar5 = (this->super_CFuncTank).m_iBulletDamage;
          local_24 = gTankSpread[iVar2].y;
          local_20 = gTankSpread[iVar2].z;
          uVar4 = 8;
          goto LAB_00097bb0;
        }
      }
      peVar3 = (entvars_t *)((int)&peVar3->classname + 1);
    } while (pevAttacker_00 != peVar3);
  }
  CFuncTank::Fire(&this->super_CFuncTank,barrelEnd,forward,pevAttacker);
  return;
}


// CFuncTankLaser::~CFuncTankLaser  @ 0009ab90  (line 744)

/* DWARF original prototype: void ~CFuncTankLaser(CFuncTankLaser * this, int __in_chrg) */

void __thiscall CFuncTankLaser::~CFuncTankLaser(CFuncTankLaser *this,int __in_chrg)

{
  return;
}


// func_tanklaser  @ 0009a920  (line 761)

void func_tanklaser(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x4f8,pev);
  *puVar1 = &PTR__CFuncTankLaser_0014e870;
  puVar1[1] = pev;
  return;
}


// CFuncTankLaser::Restore  @ 00097f30  (line 769)

/* DWARF original prototype: int Restore(CFuncTankLaser * this, CRestore * restore) */

int __thiscall CFuncTankLaser::Restore(CFuncTankLaser *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CFuncTank",this,CFuncTank::m_SaveData,0x19);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CFuncTankLaser",this,m_SaveData,2);
      return iVar1;
    }
  }
  return 0;
}


// CFuncTankLaser::Save  @ 00097fd0  (line 769)

/* DWARF original prototype: int Save(CFuncTankLaser * this, CSave * save) */

int __thiscall CFuncTankLaser::Save(CFuncTankLaser *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CFuncTank",this,CFuncTank::m_SaveData,0x19);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CFuncTankLaser",this,m_SaveData,2);
      return iVar1;
    }
  }
  return 0;
}


// CFuncTankLaser::Activate  @ 00097a00  (line 772)

/* DWARF original prototype: void Activate(CFuncTankLaser * this) */

void __thiscall CFuncTankLaser::Activate(CFuncTankLaser *this)

{
  CLaser *pCVar1;
  CFuncTankLaser *in_stack_ffffffe4;
  
                    /* Unresolved local var: edict_t * pentLaser@[???] */
  pCVar1 = this->m_pLaser;
  if (pCVar1 == (CLaser *)0x0) {
    pCVar1 = GetLaser(in_stack_ffffffe4);
    if (pCVar1 == (CLaser *)0x0) {
      UTIL_Remove((CBaseEntity *)this);
      (*g_engfuncs.pfnAlertMessage)(at_error,"Laser tank with no env_laser!\n");
      return;
    }
    pCVar1 = this->m_pLaser;
  }
  CLaser::TurnOff(pCVar1);
  return;
}


// CFuncTankLaser::KeyValue  @ 000987a0  (line 786)

/* DWARF original prototype: void KeyValue(CFuncTankLaser * this, KeyValueData * pkvd) */

void __thiscall CFuncTankLaser::KeyValue(CFuncTankLaser *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  string_t sVar2;
  TANKBULLET TVar3;
  long lVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  double dVar10;
  
  bVar9 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar5 = 0xc;
  pcVar7 = pkvd->szKeyName;
  pcVar8 = pcVar7;
  pcVar6 = "laserentity";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar6;
    pcVar8 = pcVar8 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar9);
  if (bVar9) {
    peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    peVar1->message = sVar2;
    pkvd->fHandled = 1;
  }
  else {
    pcVar8 = "?yawrate";
    iVar5 = 8;
    bVar9 = false;
    pcVar6 = pcVar7;
    do {
      pcVar8 = pcVar8 + 1;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar6 + 1;
    } while (bVar9);
    if (bVar9) {
      dVar10 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CFuncTank).m_yawRate = (float)dVar10;
      pkvd->fHandled = 1;
    }
    else {
      iVar5 = 9;
      bVar9 = false;
      pcVar8 = pcVar7;
      pcVar6 = "yawrange";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar9 = *pcVar8 == *pcVar6;
        pcVar8 = pcVar8 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar9);
      if (bVar9) {
        dVar10 = strtod(pkvd->szValue,(char **)0x0);
        (this->super_CFuncTank).m_yawRange = (float)dVar10;
        pkvd->fHandled = 1;
      }
      else {
        iVar5 = 0xd;
        bVar9 = false;
        pcVar8 = pcVar7;
        pcVar6 = "yawtolerance";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar9 = *pcVar8 == *pcVar6;
          pcVar8 = pcVar8 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar9);
        if (bVar9) {
          dVar10 = strtod(pkvd->szValue,(char **)0x0);
          (this->super_CFuncTank).m_yawTolerance = (float)dVar10;
          pkvd->fHandled = 1;
        }
        else {
          iVar5 = 0xb;
          bVar9 = false;
          pcVar8 = pcVar7;
          pcVar6 = "pitchrange";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar9 = *pcVar8 == *pcVar6;
            pcVar8 = pcVar8 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar9);
          if (bVar9) {
            dVar10 = strtod(pkvd->szValue,(char **)0x0);
            (this->super_CFuncTank).m_pitchRange = (float)dVar10;
            pkvd->fHandled = 1;
          }
          else {
            iVar5 = 10;
            bVar9 = false;
            pcVar8 = pcVar7;
            pcVar6 = "pitchrate";
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar9 = *pcVar8 == *pcVar6;
              pcVar8 = pcVar8 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar9);
            if (bVar9) {
              dVar10 = strtod(pkvd->szValue,(char **)0x0);
              (this->super_CFuncTank).m_pitchRate = (float)dVar10;
              pkvd->fHandled = 1;
            }
            else {
              iVar5 = 0xf;
              bVar9 = false;
              pcVar8 = pcVar7;
              pcVar6 = "pitchtolerance";
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar9 = *pcVar8 == *pcVar6;
                pcVar8 = pcVar8 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar9);
              if (bVar9) {
                dVar10 = strtod(pkvd->szValue,(char **)0x0);
                (this->super_CFuncTank).m_pitchTolerance = (float)dVar10;
                pkvd->fHandled = 1;
              }
              else {
                iVar5 = 9;
                bVar9 = false;
                pcVar8 = pcVar7;
                pcVar6 = "firerate";
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar9 = *pcVar8 == *pcVar6;
                  pcVar8 = pcVar8 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar9);
                if (bVar9) {
                  dVar10 = strtod(pkvd->szValue,(char **)0x0);
                  (this->super_CFuncTank).m_fireRate = (float)dVar10;
                  pkvd->fHandled = 1;
                }
                else {
                  iVar5 = 7;
                  bVar9 = false;
                  pcVar8 = pcVar7;
                  pcVar6 = "barrel";
                  do {
                    if (iVar5 == 0) break;
                    iVar5 = iVar5 + -1;
                    bVar9 = *pcVar8 == *pcVar6;
                    pcVar8 = pcVar8 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar9);
                  if (bVar9) {
                    dVar10 = strtod(pkvd->szValue,(char **)0x0);
                    (this->super_CFuncTank).m_barrelPos.x = (float)dVar10;
                    pkvd->fHandled = 1;
                  }
                  else {
                    iVar5 = 8;
                    bVar9 = false;
                    pcVar8 = pcVar7;
                    pcVar6 = "barrely";
                    do {
                      if (iVar5 == 0) break;
                      iVar5 = iVar5 + -1;
                      bVar9 = *pcVar8 == *pcVar6;
                      pcVar8 = pcVar8 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (bVar9);
                    if (bVar9) {
                      dVar10 = strtod(pkvd->szValue,(char **)0x0);
                      (this->super_CFuncTank).m_barrelPos.y = (float)dVar10;
                      pkvd->fHandled = 1;
                    }
                    else {
                      iVar5 = 8;
                      bVar9 = false;
                      pcVar8 = pcVar7;
                      pcVar6 = "barrelz";
                      do {
                        if (iVar5 == 0) break;
                        iVar5 = iVar5 + -1;
                        bVar9 = *pcVar8 == *pcVar6;
                        pcVar8 = pcVar8 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar9);
                      if (bVar9) {
                        dVar10 = strtod(pkvd->szValue,(char **)0x0);
                        (this->super_CFuncTank).m_barrelPos.z = (float)dVar10;
                        pkvd->fHandled = 1;
                      }
                      else {
                        iVar5 = 0xc;
                        bVar9 = false;
                        pcVar8 = pcVar7;
                        pcVar6 = "spritescale";
                        do {
                          if (iVar5 == 0) break;
                          iVar5 = iVar5 + -1;
                          bVar9 = *pcVar8 == *pcVar6;
                          pcVar8 = pcVar8 + 1;
                          pcVar6 = pcVar6 + 1;
                        } while (bVar9);
                        if (bVar9) {
                          dVar10 = strtod(pkvd->szValue,(char **)0x0);
                          (this->super_CFuncTank).m_spriteScale = (float)dVar10;
                          pkvd->fHandled = 1;
                        }
                        else {
                          iVar5 = 0xc;
                          bVar9 = false;
                          pcVar8 = pcVar7;
                          pcVar6 = "spritesmoke";
                          do {
                            if (iVar5 == 0) break;
                            iVar5 = iVar5 + -1;
                            bVar9 = *pcVar8 == *pcVar6;
                            pcVar8 = pcVar8 + 1;
                            pcVar6 = pcVar6 + 1;
                          } while (bVar9);
                          if (bVar9) {
                            iVar5 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                            (this->super_CFuncTank).m_iszSpriteSmoke = iVar5;
                            pkvd->fHandled = 1;
                          }
                          else {
                            iVar5 = 0xc;
                            bVar9 = false;
                            pcVar8 = pcVar7;
                            pcVar6 = "spriteflash";
                            do {
                              if (iVar5 == 0) break;
                              iVar5 = iVar5 + -1;
                              bVar9 = *pcVar8 == *pcVar6;
                              pcVar8 = pcVar8 + 1;
                              pcVar6 = pcVar6 + 1;
                            } while (bVar9);
                            if (bVar9) {
                              iVar5 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                              (this->super_CFuncTank).m_iszSpriteFlash = iVar5;
                              pkvd->fHandled = 1;
                            }
                            else {
                              iVar5 = 0xc;
                              bVar9 = false;
                              pcVar8 = pcVar7;
                              pcVar6 = "rotatesound";
                              do {
                                if (iVar5 == 0) break;
                                iVar5 = iVar5 + -1;
                                bVar9 = *pcVar8 == *pcVar6;
                                pcVar8 = pcVar8 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
                                sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                peVar1->noise = sVar2;
                                pkvd->fHandled = 1;
                              }
                              else {
                                iVar5 = 0xc;
                                bVar9 = false;
                                pcVar8 = pcVar7;
                                pcVar6 = "persistence";
                                do {
                                  if (iVar5 == 0) break;
                                  iVar5 = iVar5 + -1;
                                  bVar9 = *pcVar8 == *pcVar6;
                                  pcVar8 = pcVar8 + 1;
                                  pcVar6 = pcVar6 + 1;
                                } while (bVar9);
                                if (bVar9) {
                                  dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                  (this->super_CFuncTank).m_persist = (float)dVar10;
                                  pkvd->fHandled = 1;
                                }
                                else {
                                  iVar5 = 7;
                                  bVar9 = false;
                                  pcVar8 = pcVar7;
                                  pcVar6 = "bullet";
                                  do {
                                    if (iVar5 == 0) break;
                                    iVar5 = iVar5 + -1;
                                    bVar9 = *pcVar8 == *pcVar6;
                                    pcVar8 = pcVar8 + 1;
                                    pcVar6 = pcVar6 + 1;
                                  } while (bVar9);
                                  if (bVar9) {
                                    TVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                    (this->super_CFuncTank).m_bulletType = TVar3;
                                    pkvd->fHandled = 1;
                                  }
                                  else {
                                    iVar5 = 0xe;
                                    bVar9 = false;
                                    pcVar8 = pcVar7;
                                    pcVar6 = "bullet_damage";
                                    do {
                                      if (iVar5 == 0) break;
                                      iVar5 = iVar5 + -1;
                                      bVar9 = *pcVar8 == *pcVar6;
                                      pcVar8 = pcVar8 + 1;
                                      pcVar6 = pcVar6 + 1;
                                    } while (bVar9);
                                    if (bVar9) {
                                      lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
                                      (this->super_CFuncTank).m_iBulletDamage = lVar4;
                                      pkvd->fHandled = 1;
                                    }
                                    else {
                                      iVar5 = 0xb;
                                      bVar9 = false;
                                      pcVar8 = pcVar7;
                                      pcVar6 = "firespread";
                                      do {
                                        if (iVar5 == 0) break;
                                        iVar5 = iVar5 + -1;
                                        bVar9 = *pcVar8 == *pcVar6;
                                        pcVar8 = pcVar8 + 1;
                                        pcVar6 = pcVar6 + 1;
                                      } while (bVar9);
                                      if (bVar9) {
                                        lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
                                        (this->super_CFuncTank).m_spread = lVar4;
                                        pkvd->fHandled = 1;
                                      }
                                      else {
                                        iVar5 = 9;
                                        bVar9 = false;
                                        pcVar8 = pcVar7;
                                        pcVar6 = "minRange";
                                        do {
                                          if (iVar5 == 0) break;
                                          iVar5 = iVar5 + -1;
                                          bVar9 = *pcVar8 == *pcVar6;
                                          pcVar8 = pcVar8 + 1;
                                          pcVar6 = pcVar6 + 1;
                                        } while (bVar9);
                                        if (bVar9) {
                                          dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                          (this->super_CFuncTank).m_minRange = (float)dVar10;
                                          pkvd->fHandled = 1;
                                        }
                                        else {
                                          iVar5 = 9;
                                          bVar9 = false;
                                          pcVar8 = "maxRange";
                                          do {
                                            if (iVar5 == 0) break;
                                            iVar5 = iVar5 + -1;
                                            bVar9 = *pcVar7 == *pcVar8;
                                            pcVar7 = pcVar7 + 1;
                                            pcVar8 = pcVar8 + 1;
                                          } while (bVar9);
                                          if (!bVar9) {
                                            CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
                                            return;
                                          }
                                          dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                          (this->super_CFuncTank).m_maxRange = (float)dVar10;
                                          pkvd->fHandled = 1;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// CFuncTankLaser::GetLaser  @ 00097930  (line 797)

/* DWARF original prototype: CLaser * GetLaser(CFuncTankLaser * this) */

CLaser * __thiscall CFuncTankLaser::GetLaser(CFuncTankLaser *this)

{
  CLaser *pCVar1;
  int in_EAX;
  edict_t *peVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
                    /* Unresolved local var: edict_t * pentLaser@[???] */
  bVar7 = 0;
  peVar2 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1d4));
  do {
    if ((peVar2 == (edict_t *)0x0) ||
       (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 == 0)) {
      return *(CLaser **)(in_EAX + 0x4f0);
    }
    iVar3 = 10;
    pcVar4 = gpGlobals->pStringBase + (peVar2->v).classname;
    bVar6 = pcVar4 == (char *)0x0;
    pcVar5 = "env_laser";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar1 = peVar2->pvPrivateData;
      *(CLaser **)(in_EAX + 0x4f0) = pCVar1;
      return pCVar1;
    }
    peVar2 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar2,"targetname",
                        gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1d4));
  } while( true );
}


// CFuncTankLaser::GetLaser  @ 0009a990  (line 798)

/* DWARF original prototype: CLaser * GetLaser(CFuncTankLaser * this) */

CLaser * __thiscall CFuncTankLaser::GetLaser(CFuncTankLaser *this)

{
  CLaser *pCVar1;
  
                    /* Unresolved local var: edict_t * pentLaser@[???] */
  if (this->m_pLaser != (CLaser *)0x0) {
    return this->m_pLaser;
  }
  pCVar1 = GetLaser(this);
  return pCVar1;
}


// CFuncTankLaser::Think  @ 00099ff0  (line 822)

/* DWARF original prototype: void Think(CFuncTankLaser * this) */

void __thiscall CFuncTankLaser::Think(CFuncTankLaser *this)

{
  entvars_t *peVar1;
  uint uVar2;
  
  if ((this->m_pLaser != (CLaser *)0x0) && (this->m_laserTime < gpGlobals->time)) {
    CLaser::TurnOff(this->m_pLaser);
  }
  peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  CFuncTank::TrackTarget(&this->super_CFuncTank);
  peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
  if ((ABS((peVar1->avelocity).x) <= 1.0) && (ABS((peVar1->avelocity).y) <= 1.0)) {
    uVar2 = peVar1->spawnflags;
    if ((uVar2 & 0x8000) != 0) {
      EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20
                     ,100);
      peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
      uVar2 = peVar1->spawnflags;
    }
    peVar1->spawnflags = uVar2 & 0xffff7fff;
    return;
  }
  if ((peVar1->noise != 0) && ((peVar1->spawnflags & 0x8000U) == 0)) {
    peVar1->spawnflags = peVar1->spawnflags | 0x8000;
    peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.85,0.8,0,100
                  );
    return;
  }
  return;
}


// CFuncTankLaser::Fire  @ 0009a2b0  (line 831)

/* DWARF original prototype: void Fire(CFuncTankLaser * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTankLaser::Fire(CFuncTankLaser *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  entvars_t *peVar1;
  int iVar2;
  CLaser *pCVar3;
  int iVar4;
  CFuncTankLaser *in_stack_ffffff74;
  TraceResult local_54;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TraceResult tr@[???] */
                    /* Unresolved local var: edict_t * pentLaser@[???] */
  if (((this->super_CFuncTank).m_fireLast != 0.0) &&
     ((this->m_pLaser != (CLaser *)0x0 ||
      (pCVar3 = GetLaser(in_stack_ffffff74), pCVar3 != (CLaser *)0x0)))) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: int bulletCount@[???] */
    UTIL_MakeAimVectors(&((this->super_CFuncTank).super_CBaseEntity.pev)->angles);
    iVar2 = (int)((gpGlobals->time - (this->super_CFuncTank).m_fireLast) *
                 (this->super_CFuncTank).m_fireRate);
    if (iVar2 == 0) {
      return;
    }
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        iVar4 = iVar4 + 1;
        peVar1 = (this->m_pLaser->super_CBeam).super_CBaseEntity.pev;
        (peVar1->origin).x = barrelEnd->x;
        (peVar1->origin).y = barrelEnd->y;
        (peVar1->origin).z = barrelEnd->z;
        CFuncTank::TankTrace
                  (&this->super_CFuncTank,barrelEnd,forward,
                   gTankSpread + (this->super_CFuncTank).m_spread,&local_54);
        this->m_laserTime = gpGlobals->time;
        CLaser::TurnOn(this->m_pLaser);
        ((this->m_pLaser->super_CBeam).super_CBaseEntity.pev)->dmgtime = gpGlobals->time - 1.0;
        CLaser::FireAtPoint(this->m_pLaser,&local_54);
        ((this->m_pLaser->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
      } while (iVar2 != iVar4);
    }
  }
  CFuncTank::Fire(&this->super_CFuncTank,barrelEnd,forward,
                  (this->super_CFuncTank).super_CBaseEntity.pev);
  return;
}


// CFuncTankRocket::~CFuncTankRocket  @ 0009ab80  (line 863)

/* DWARF original prototype: void ~CFuncTankRocket(CFuncTankRocket * this, int __in_chrg) */

void __thiscall CFuncTankRocket::~CFuncTankRocket(CFuncTankRocket *this,int __in_chrg)

{
  return;
}


// func_tankrocket  @ 0009a9b0  (line 869)

void func_tankrocket(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x4f0,pev);
  *puVar1 = &PTR__CFuncTankRocket_0014e984;
  puVar1[1] = pev;
  return;
}


// CFuncTankRocket::Precache  @ 00098070  (line 872)

/* DWARF original prototype: void Precache(CFuncTankRocket * this) */

void __thiscall CFuncTankRocket::Precache(CFuncTankRocket *this)

{
  int iVar1;
  string_t sVar2;
  
  UTIL_PrecacheOther("tf_rpg_rocket");
  iVar1 = (this->super_CFuncTank).m_iszSpriteSmoke;
  if (iVar1 != 0) {
    (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + iVar1);
  }
  iVar1 = (this->super_CFuncTank).m_iszSpriteFlash;
  if (iVar1 != 0) {
    (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + iVar1);
  }
  sVar2 = ((this->super_CFuncTank).super_CBaseEntity.pev)->noise;
  if (sVar2 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000980c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + sVar2);
  return;
}


// CFuncTankRocket::Fire  @ 00097dc0  (line 880)

/* DWARF original prototype: void Fire(CFuncTankRocket * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTankRocket::Fire
          (CFuncTankRocket *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  fVar1 = (this->super_CFuncTank).m_fireLast;
  if (fVar1 != 0.0) {
                    /* Unresolved local var: int bulletCount@[???] */
    iVar3 = (int)((gpGlobals->time - fVar1) * (this->super_CFuncTank).m_fireRate);
    if (iVar3 < 1) {
      return;
    }
    iVar4 = 0;
    do {
      peVar2 = (this->super_CFuncTank).super_CBaseEntity.pev;
      iVar4 = iVar4 + 1;
                    /* Unresolved local var: CBaseEntity * pRocket@[???] */
      CBaseEntity::Create("tf_rpg_rocket",barrelEnd,&peVar2->angles,peVar2->pContainingEntity);
    } while (iVar3 != iVar4);
  }
                    /* Unresolved local var: int i@[???] */
  CFuncTank::Fire(&this->super_CFuncTank,barrelEnd,forward,
                  (this->super_CFuncTank).super_CBaseEntity.pev);
  return;
}


// CFuncTankMortar::~CFuncTankMortar  @ 0009ab70  (line 900)

/* DWARF original prototype: void ~CFuncTankMortar(CFuncTankMortar * this, int __in_chrg) */

void __thiscall CFuncTankMortar::~CFuncTankMortar(CFuncTankMortar *this,int __in_chrg)

{
  return;
}


// func_tankmortar  @ 0009aa20  (line 906)

void func_tankmortar(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x4f0,pev);
  *puVar1 = &PTR__CFuncTankMortar_0014ea98;
  puVar1[1] = pev;
  return;
}


// CFuncTankMortar::KeyValue  @ 00098280  (line 910)

/* DWARF original prototype: void KeyValue(CFuncTankMortar * this, KeyValueData * pkvd) */

void __thiscall CFuncTankMortar::KeyValue(CFuncTankMortar *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  string_t sVar2;
  TANKBULLET TVar3;
  long lVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  double dVar10;
  
  bVar9 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar5 = 0xb;
  pcVar7 = pkvd->szKeyName;
  pcVar8 = pcVar7;
  pcVar6 = "iMagnitude";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar6;
    pcVar8 = pcVar8 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar9);
  if (bVar9) {
    peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
    lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
    peVar1->impulse = lVar4;
    pkvd->fHandled = 1;
  }
  else {
    pcVar8 = "?yawrate";
    iVar5 = 8;
    bVar9 = false;
    pcVar6 = pcVar7;
    do {
      pcVar8 = pcVar8 + 1;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar6 + 1;
    } while (bVar9);
    if (bVar9) {
      dVar10 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CFuncTank).m_yawRate = (float)dVar10;
      pkvd->fHandled = 1;
    }
    else {
      iVar5 = 9;
      bVar9 = false;
      pcVar8 = pcVar7;
      pcVar6 = "yawrange";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar9 = *pcVar8 == *pcVar6;
        pcVar8 = pcVar8 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar9);
      if (bVar9) {
        dVar10 = strtod(pkvd->szValue,(char **)0x0);
        (this->super_CFuncTank).m_yawRange = (float)dVar10;
        pkvd->fHandled = 1;
      }
      else {
        iVar5 = 0xd;
        bVar9 = false;
        pcVar8 = pcVar7;
        pcVar6 = "yawtolerance";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar9 = *pcVar8 == *pcVar6;
          pcVar8 = pcVar8 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar9);
        if (bVar9) {
          dVar10 = strtod(pkvd->szValue,(char **)0x0);
          (this->super_CFuncTank).m_yawTolerance = (float)dVar10;
          pkvd->fHandled = 1;
        }
        else {
          iVar5 = 0xb;
          bVar9 = false;
          pcVar8 = pcVar7;
          pcVar6 = "pitchrange";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar9 = *pcVar8 == *pcVar6;
            pcVar8 = pcVar8 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar9);
          if (bVar9) {
            dVar10 = strtod(pkvd->szValue,(char **)0x0);
            (this->super_CFuncTank).m_pitchRange = (float)dVar10;
            pkvd->fHandled = 1;
          }
          else {
            iVar5 = 10;
            bVar9 = false;
            pcVar8 = pcVar7;
            pcVar6 = "pitchrate";
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar9 = *pcVar8 == *pcVar6;
              pcVar8 = pcVar8 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar9);
            if (bVar9) {
              dVar10 = strtod(pkvd->szValue,(char **)0x0);
              (this->super_CFuncTank).m_pitchRate = (float)dVar10;
              pkvd->fHandled = 1;
            }
            else {
              iVar5 = 0xf;
              bVar9 = false;
              pcVar8 = pcVar7;
              pcVar6 = "pitchtolerance";
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar9 = *pcVar8 == *pcVar6;
                pcVar8 = pcVar8 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar9);
              if (bVar9) {
                dVar10 = strtod(pkvd->szValue,(char **)0x0);
                (this->super_CFuncTank).m_pitchTolerance = (float)dVar10;
                pkvd->fHandled = 1;
              }
              else {
                iVar5 = 9;
                bVar9 = false;
                pcVar8 = pcVar7;
                pcVar6 = "firerate";
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar9 = *pcVar8 == *pcVar6;
                  pcVar8 = pcVar8 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar9);
                if (bVar9) {
                  dVar10 = strtod(pkvd->szValue,(char **)0x0);
                  (this->super_CFuncTank).m_fireRate = (float)dVar10;
                  pkvd->fHandled = 1;
                }
                else {
                  iVar5 = 7;
                  bVar9 = false;
                  pcVar8 = pcVar7;
                  pcVar6 = "barrel";
                  do {
                    if (iVar5 == 0) break;
                    iVar5 = iVar5 + -1;
                    bVar9 = *pcVar8 == *pcVar6;
                    pcVar8 = pcVar8 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar9);
                  if (bVar9) {
                    dVar10 = strtod(pkvd->szValue,(char **)0x0);
                    (this->super_CFuncTank).m_barrelPos.x = (float)dVar10;
                    pkvd->fHandled = 1;
                  }
                  else {
                    iVar5 = 8;
                    bVar9 = false;
                    pcVar8 = pcVar7;
                    pcVar6 = "barrely";
                    do {
                      if (iVar5 == 0) break;
                      iVar5 = iVar5 + -1;
                      bVar9 = *pcVar8 == *pcVar6;
                      pcVar8 = pcVar8 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (bVar9);
                    if (bVar9) {
                      dVar10 = strtod(pkvd->szValue,(char **)0x0);
                      (this->super_CFuncTank).m_barrelPos.y = (float)dVar10;
                      pkvd->fHandled = 1;
                    }
                    else {
                      iVar5 = 8;
                      bVar9 = false;
                      pcVar8 = pcVar7;
                      pcVar6 = "barrelz";
                      do {
                        if (iVar5 == 0) break;
                        iVar5 = iVar5 + -1;
                        bVar9 = *pcVar8 == *pcVar6;
                        pcVar8 = pcVar8 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar9);
                      if (bVar9) {
                        dVar10 = strtod(pkvd->szValue,(char **)0x0);
                        (this->super_CFuncTank).m_barrelPos.z = (float)dVar10;
                        pkvd->fHandled = 1;
                      }
                      else {
                        iVar5 = 0xc;
                        bVar9 = false;
                        pcVar8 = pcVar7;
                        pcVar6 = "spritescale";
                        do {
                          if (iVar5 == 0) break;
                          iVar5 = iVar5 + -1;
                          bVar9 = *pcVar8 == *pcVar6;
                          pcVar8 = pcVar8 + 1;
                          pcVar6 = pcVar6 + 1;
                        } while (bVar9);
                        if (bVar9) {
                          dVar10 = strtod(pkvd->szValue,(char **)0x0);
                          (this->super_CFuncTank).m_spriteScale = (float)dVar10;
                          pkvd->fHandled = 1;
                        }
                        else {
                          iVar5 = 0xc;
                          bVar9 = false;
                          pcVar8 = pcVar7;
                          pcVar6 = "spritesmoke";
                          do {
                            if (iVar5 == 0) break;
                            iVar5 = iVar5 + -1;
                            bVar9 = *pcVar8 == *pcVar6;
                            pcVar8 = pcVar8 + 1;
                            pcVar6 = pcVar6 + 1;
                          } while (bVar9);
                          if (bVar9) {
                            iVar5 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                            (this->super_CFuncTank).m_iszSpriteSmoke = iVar5;
                            pkvd->fHandled = 1;
                          }
                          else {
                            iVar5 = 0xc;
                            bVar9 = false;
                            pcVar8 = pcVar7;
                            pcVar6 = "spriteflash";
                            do {
                              if (iVar5 == 0) break;
                              iVar5 = iVar5 + -1;
                              bVar9 = *pcVar8 == *pcVar6;
                              pcVar8 = pcVar8 + 1;
                              pcVar6 = pcVar6 + 1;
                            } while (bVar9);
                            if (bVar9) {
                              iVar5 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                              (this->super_CFuncTank).m_iszSpriteFlash = iVar5;
                              pkvd->fHandled = 1;
                            }
                            else {
                              iVar5 = 0xc;
                              bVar9 = false;
                              pcVar8 = pcVar7;
                              pcVar6 = "rotatesound";
                              do {
                                if (iVar5 == 0) break;
                                iVar5 = iVar5 + -1;
                                bVar9 = *pcVar8 == *pcVar6;
                                pcVar8 = pcVar8 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
                                sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                peVar1->noise = sVar2;
                                pkvd->fHandled = 1;
                              }
                              else {
                                iVar5 = 0xc;
                                bVar9 = false;
                                pcVar8 = pcVar7;
                                pcVar6 = "persistence";
                                do {
                                  if (iVar5 == 0) break;
                                  iVar5 = iVar5 + -1;
                                  bVar9 = *pcVar8 == *pcVar6;
                                  pcVar8 = pcVar8 + 1;
                                  pcVar6 = pcVar6 + 1;
                                } while (bVar9);
                                if (bVar9) {
                                  dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                  (this->super_CFuncTank).m_persist = (float)dVar10;
                                  pkvd->fHandled = 1;
                                }
                                else {
                                  iVar5 = 7;
                                  bVar9 = false;
                                  pcVar8 = pcVar7;
                                  pcVar6 = "bullet";
                                  do {
                                    if (iVar5 == 0) break;
                                    iVar5 = iVar5 + -1;
                                    bVar9 = *pcVar8 == *pcVar6;
                                    pcVar8 = pcVar8 + 1;
                                    pcVar6 = pcVar6 + 1;
                                  } while (bVar9);
                                  if (bVar9) {
                                    TVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                    (this->super_CFuncTank).m_bulletType = TVar3;
                                    pkvd->fHandled = 1;
                                  }
                                  else {
                                    iVar5 = 0xe;
                                    bVar9 = false;
                                    pcVar8 = pcVar7;
                                    pcVar6 = "bullet_damage";
                                    do {
                                      if (iVar5 == 0) break;
                                      iVar5 = iVar5 + -1;
                                      bVar9 = *pcVar8 == *pcVar6;
                                      pcVar8 = pcVar8 + 1;
                                      pcVar6 = pcVar6 + 1;
                                    } while (bVar9);
                                    if (bVar9) {
                                      lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
                                      (this->super_CFuncTank).m_iBulletDamage = lVar4;
                                      pkvd->fHandled = 1;
                                    }
                                    else {
                                      iVar5 = 0xb;
                                      bVar9 = false;
                                      pcVar8 = pcVar7;
                                      pcVar6 = "firespread";
                                      do {
                                        if (iVar5 == 0) break;
                                        iVar5 = iVar5 + -1;
                                        bVar9 = *pcVar8 == *pcVar6;
                                        pcVar8 = pcVar8 + 1;
                                        pcVar6 = pcVar6 + 1;
                                      } while (bVar9);
                                      if (bVar9) {
                                        lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
                                        (this->super_CFuncTank).m_spread = lVar4;
                                        pkvd->fHandled = 1;
                                      }
                                      else {
                                        iVar5 = 9;
                                        bVar9 = false;
                                        pcVar8 = pcVar7;
                                        pcVar6 = "minRange";
                                        do {
                                          if (iVar5 == 0) break;
                                          iVar5 = iVar5 + -1;
                                          bVar9 = *pcVar8 == *pcVar6;
                                          pcVar8 = pcVar8 + 1;
                                          pcVar6 = pcVar6 + 1;
                                        } while (bVar9);
                                        if (bVar9) {
                                          dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                          (this->super_CFuncTank).m_minRange = (float)dVar10;
                                          pkvd->fHandled = 1;
                                        }
                                        else {
                                          iVar5 = 9;
                                          bVar9 = false;
                                          pcVar8 = "maxRange";
                                          do {
                                            if (iVar5 == 0) break;
                                            iVar5 = iVar5 + -1;
                                            bVar9 = *pcVar7 == *pcVar8;
                                            pcVar7 = pcVar7 + 1;
                                            pcVar8 = pcVar8 + 1;
                                          } while (bVar9);
                                          if (!bVar9) {
                                            CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
                                            return;
                                          }
                                          dVar10 = strtod(pkvd->szValue,(char **)0x0);
                                          (this->super_CFuncTank).m_maxRange = (float)dVar10;
                                          pkvd->fHandled = 1;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// CFuncTankMortar::Fire  @ 0009a430  (line 922)

/* DWARF original prototype: void Fire(CFuncTankMortar * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTankMortar::Fire
          (CFuncTankMortar *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  int iVar5;
  _2globalvars_t *p1Var6;
  CSprite *pCVar7;
  longdouble lVar8;
  TraceResult local_44;
  
  fVar3 = (this->super_CFuncTank).m_fireLast;
  if (fVar3 != 0.0) {
                    /* Unresolved local var: int bulletCount@[???] */
    if (0 < (int)((gpGlobals->time - fVar3) * (this->super_CFuncTank).m_fireRate)) {
                    /* Unresolved local var: int bulletCount@[???]
                       Unresolved local var: TraceResult tr@[???] */
      UTIL_MakeAimVectors(&((this->super_CFuncTank).super_CBaseEntity.pev)->angles);
      CFuncTank::TankTrace
                (&this->super_CFuncTank,barrelEnd,forward,
                 gTankSpread + (this->super_CFuncTank).m_spread,&local_44);
      peVar4 = (this->super_CFuncTank).super_CBaseEntity.pev;
      ExplosionCreate(&local_44.vecEndPos,&peVar4->angles,peVar4->pContainingEntity,peVar4->impulse,
                      1);
      if ((this->super_CFuncTank).m_fireLast != 0.0) {
        iVar5 = (this->super_CFuncTank).m_iszSpriteSmoke;
        if (iVar5 != 0) {
                    /* Unresolved local var: CSprite * pSprite@[???] */
          pCVar7 = CSprite::SpriteCreate(gpGlobals->pStringBase + iVar5,barrelEnd,1);
          lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(15.0,20.0);
          peVar4 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
          (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn =
               CSprite::AnimateUntilDead;
          (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
          peVar4->framerate = (float)lVar8;
          p1Var6 = gpGlobals;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->dmgtime =
               (float)((longdouble)pCVar7->m_maxFrame / lVar8 + (longdouble)gpGlobals->time);
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->nextthink = p1Var6->time;
          peVar4 = (this->super_CFuncTank).super_CBaseEntity.pev;
          fVar3 = (peVar4->rendercolor).z;
          fVar1 = (peVar4->rendercolor).y;
          fVar2 = (peVar4->rendercolor).x;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 4;
          (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = (float)(int)fVar2;
          (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = (float)(int)fVar1;
          (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = (float)(int)fVar3;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0;
          peVar4 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
          lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(40.0,80.0);
          (peVar4->velocity).z = (float)lVar8;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->scale =
               (this->super_CFuncTank).m_spriteScale;
        }
        iVar5 = (this->super_CFuncTank).m_iszSpriteFlash;
        if (iVar5 != 0) {
                    /* Unresolved local var: CSprite * pSprite@[???] */
          pCVar7 = CSprite::SpriteCreate(gpGlobals->pStringBase + iVar5,barrelEnd,1);
          peVar4 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
          (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn =
               CSprite::AnimateUntilDead;
          (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
          peVar4->framerate = 60.0;
          p1Var6 = gpGlobals;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->dmgtime =
               pCVar7->m_maxFrame / 60.0 + gpGlobals->time;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->nextthink = p1Var6->time;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 5;
          (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = 255.0;
          (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = 255.0;
          (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = 255.0;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0xe;
          ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->scale =
               (this->super_CFuncTank).m_spriteScale;
        }
        CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
      }
      (this->super_CFuncTank).m_fireLast = gpGlobals->time;
    }
    return;
  }
  CFuncTank::Fire(&this->super_CFuncTank,barrelEnd,forward,
                  (this->super_CFuncTank).super_CBaseEntity.pev);
  return;
}


// CFuncTankControls::~CFuncTankControls  @ 0009ab60  (line 950)

/* DWARF original prototype: void ~CFuncTankControls(CFuncTankControls * this, int __in_chrg) */

void __thiscall CFuncTankControls::~CFuncTankControls(CFuncTankControls *this,int __in_chrg)

{
  return;
}


// func_tankcontrols  @ 0009aa90  (line 964)

void func_tankcontrols(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CFuncTankControls_0014ebac;
  puVar1[1] = pev;
  return;
}


// CFuncTankControls::Restore  @ 00097e70  (line 971)

/* DWARF original prototype: int Restore(CFuncTankControls * this, CRestore * restore) */

int __thiscall CFuncTankControls::Restore(CFuncTankControls *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CFuncTankControls",this,m_SaveData,1);
  }
  return iVar2;
}


// CFuncTankControls::Save  @ 00097ed0  (line 971)

/* DWARF original prototype: int Save(CFuncTankControls * this, CSave * save) */

int __thiscall CFuncTankControls::Save(CFuncTankControls *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CFuncTankControls",this,m_SaveData,1);
  }
  return iVar2;
}


// CFuncTankControls::ObjectCaps  @ 00096f70  (line 976)

/* DWARF original prototype: int ObjectCaps(CFuncTankControls * this) */

int __thiscall CFuncTankControls::ObjectCaps(CFuncTankControls *this)

{
  return 8;
}


// CFuncTankControls::Use  @ 00099200  (line 980)

/* DWARF original prototype: void Use(CFuncTankControls * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTankControls::Use
          (CFuncTankControls *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int *piVar1;
  CFuncTank *this_00;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  CBasePlayerItem *pCVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  entvars_t *peVar6;
  
  if ((((pActivator != (CBaseEntity *)0x0) &&
       (iVar3 = (*pActivator->_vptr_CBaseEntity[10])(pActivator), iVar3 != 2)) ||
      (BVar4 = ActivationSucceeded(&this->super_CBaseEntity,(CBasePlayer *)pActivator,
                                   (CBaseEntity *)0x0), BVar4 != 0)) &&
     (this_00 = this->m_pTank, this_00 != (CFuncTank *)0x0)) {
    UNRECOVERED_JUMPTABLE = (this_00->super_CBaseEntity)._vptr_CBaseEntity[0x2d];
    if (UNRECOVERED_JUMPTABLE != CFuncTank::Use) {
                    /* WARNING: Could not recover jumptable at 0x000993f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    uVar5 = ((this_00->super_CBaseEntity).pev)->spawnflags;
    if ((uVar5 & 0x20) == 0) {
      iVar3 = CBaseEntity::ShouldToggle(&this_00->super_CBaseEntity,useType,uVar5 & 1);
      if (iVar3 != 0) {
        peVar6 = (this_00->super_CBaseEntity).pev;
        uVar5 = peVar6->spawnflags;
        if ((uVar5 & 1) == 0) {
          peVar6->spawnflags = uVar5 | 1;
          peVar6 = (this_00->super_CBaseEntity).pev;
          peVar6->nextthink = peVar6->ltime + 0.1;
          this_00->m_fireLast = 0.0;
        }
        else {
          peVar6->spawnflags = uVar5 & 0xfffffffe;
          peVar6 = (this_00->super_CBaseEntity).pev;
          this_00->m_fireLast = 0.0;
          uVar5 = peVar6->spawnflags;
          if ((uVar5 & 0x8000) != 0) {
            EMIT_SOUND_DYN(peVar6->pContainingEntity,6,gpGlobals->pStringBase + peVar6->noise,0.0,
                           0.0,0x20,100);
            peVar6 = (this_00->super_CBaseEntity).pev;
            uVar5 = peVar6->spawnflags;
          }
          peVar6->spawnflags = uVar5 & 0xffff7fff;
        }
      }
    }
    else {
      iVar3 = (*pActivator->_vptr_CBaseEntity[10])(pActivator);
      if ((iVar3 == 2) &&
         (BVar4 = ActivationSucceeded(&this_00->super_CBaseEntity,(CBasePlayer *)pActivator,
                                      (CBaseEntity *)0x0), BVar4 != 0)) {
        if ((value == 2.0) && (useType == USE_SET)) {
          CFuncTank::ControllerPostFrame(this_00);
          return;
        }
        if (this_00->m_pController == (CBasePlayer *)0x0) {
          if ((useType != USE_OFF) &&
             (EHANDLE::operator=((EHANDLE *)&pActivator[1].rs_gr,&this_00->super_CBaseEntity),
             this_00->m_pController == (CBasePlayer *)0x0)) {
            CFuncTank::StartControl((CFuncTank *)this,(CBasePlayer *)pActivator);
            return;
          }
        }
        else {
          pCVar2 = this_00->m_pController->m_pActiveItem;
          if (pCVar2 != (CBasePlayerItem *)0x0) {
            (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x47])(pCVar2);
          }
          (*g_engfuncs.pfnAlertMessage)(at_console,"stopped using TANK\n");
          piVar1 = &this_00->m_pController->m_iHideHUD;
          *piVar1 = *piVar1 & 0xfffffffe;
          ((this_00->super_CBaseEntity).pev)->nextthink = 0.0;
          this_00->m_pController = (CBasePlayer *)0x0;
          peVar6 = (this_00->super_CBaseEntity).pev;
          if ((peVar6->spawnflags & 1) != 0) {
            peVar6->nextthink = peVar6->ltime + 1.0;
          }
        }
      }
    }
  }
  return;
}


// CFuncTankControls::Think  @ 000976e0  (line 997)

/* DWARF original prototype: void Think(CFuncTankControls * this) */

void __thiscall CFuncTankControls::Think(CFuncTankControls *this)

{
  char *pcVar1;
  int iVar2;
  edict_t *peVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
                    /* Unresolved local var: edict_t * pTarget@[???] */
  bVar7 = 0;
  peVar3 = (edict_t *)0x0;
  pcVar1 = gpGlobals->pStringBase;
  do {
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar3,"targetname",pcVar1 + ((this->super_CBaseEntity).pev)->target);
    if (peVar3 == (edict_t *)0x0) goto LAB_00097739;
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
    if (iVar2 == 0) break;
    iVar2 = 9;
    pcVar1 = gpGlobals->pStringBase;
    bVar6 = pcVar1 + (peVar3->v).classname == (char *)0x0;
    pcVar4 = pcVar1 + (peVar3->v).classname;
    pcVar5 = "func_tank";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
  } while (!bVar6);
  iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    this->m_pTank = peVar3->pvPrivateData;
    return;
  }
LAB_00097739:
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"No tank %s\n",
             gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->target);
  return;
}


// CFuncTankControls::Spawn  @ 000977c0  (line 1015)

/* DWARF original prototype: void Spawn(CFuncTankControls * this) */

void __thiscall CFuncTankControls::Spawn(CFuncTankControls *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  ((this->super_CBaseEntity).pev)->solid = 1;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  p1Var3 = gpGlobals;
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,p1Var3->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.3;
  return;
}


