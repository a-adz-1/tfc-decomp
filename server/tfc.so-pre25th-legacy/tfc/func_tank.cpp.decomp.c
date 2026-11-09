// Ghidra decompilation of functions from tfc/func_tank.cpp
// 47 functions, ordered by original source line

// CFuncTank::UpdateTargetPosition  @ 000d7a20  (line 51)

/* DWARF original prototype: Vector UpdateTargetPosition(CFuncTank * this, CBaseEntity * pTarget) */

Vector * __thiscall
CFuncTank::UpdateTargetPosition(Vector *__return_storage_ptr__,CFuncTank *this,CBaseEntity *pTarget)

{
  (*pTarget->_vptr_CBaseEntity[0x35])
            (__return_storage_ptr__,pTarget,&((this->super_CBaseEntity).pev)->origin);
  return __return_storage_ptr__;
}


// CFuncTank::ObjectCaps  @ 000d7a60  (line 60)

/* DWARF original prototype: int ObjectCaps(CFuncTank * this) */

int __thiscall CFuncTank::ObjectCaps(CFuncTank *this)

{
  return 0;
}


// CFuncTank::Restore  @ 000d4ff0  (line 156)

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


// CFuncTank::Save  @ 000d50b0  (line 156)

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


// CFuncTank::Spawn  @ 000d6320  (line 170)

/* DWARF original prototype: void Spawn(CFuncTank * this) */

void __thiscall CFuncTank::Spawn(CFuncTank *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  entvars_t *peVar6;
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
  ((this->super_CBaseEntity).pev)->solid = 4;
  peVar6 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,gpGlobals->pStringBase + peVar6->model);
  peVar6 = (this->super_CBaseEntity).pev;
  this->m_yawCenter = (peVar6->angles).y;
  this->m_pitchCenter = (peVar6->angles).x;
  if ((peVar6->spawnflags & 1) != 0) {
    peVar6->nextthink = peVar6->ltime + 1.0;
    peVar6 = (this->super_CBaseEntity).pev;
  }
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
  (*g_engfuncs.pfnAngleVectors)(&(peVar6->angles).x,&local_30,&local_24,&local_18);
  peVar6 = (this->super_CBaseEntity).pev;
  fVar1 = (this->m_barrelPos).z;
  fVar2 = (this->m_barrelPos).y;
  fVar3 = (this->m_barrelPos).x;
  fVar4 = (peVar6->origin).z;
  fVar5 = (peVar6->origin).y;
  (this->m_sightOrigin).x =
       fVar1 * local_18 + fVar3 * local_30 + (peVar6->origin).x + fVar2 * local_24;
  (this->m_sightOrigin).y = local_2c * fVar3 + fVar5 + local_20 * fVar2 + local_14 * fVar1;
  (this->m_sightOrigin).z = local_28 * fVar3 + fVar4 + local_1c * fVar2 + local_10 * fVar1;
  if (this->m_fireRate <= 0.0) {
    this->m_fireRate = 1.0;
  }
  if (5 < (uint)this->m_spread) {
    this->m_spread = 0;
  }
  (peVar6->oldorigin).x = (peVar6->origin).x;
  (peVar6->oldorigin).y = (peVar6->origin).y;
  (peVar6->oldorigin).z = (peVar6->origin).z;
  return;
}


// CFuncTank::Precache  @ 000d4e50  (line 195)

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
                    /* WARNING: Could not recover jumptable at 0x000d4e9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + sVar1);
  return;
}


// CFuncTank::KeyValue  @ 000d5b80  (line 206)

/* DWARF original prototype: void KeyValue(CFuncTank * this, KeyValueData * pkvd) */

void __thiscall CFuncTank::KeyValue(CFuncTank *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  CBaseEntity *in_EAX;
  string_t sVar2;
  long lVar3;
  int iVar4;
  KeyValueData *in_EDX;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  double dVar9;
  
  bVar8 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar4 = 0xd;
  pcVar6 = in_EDX->szKeyName;
  pcVar5 = pcVar6;
  pcVar7 = "yawtolerance";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar5 == *pcVar7;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    dVar9 = strtod(in_EDX->szValue,(char **)0x0);
    in_EAX[1].m_pfnUse.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)
         (float)dVar9;
    in_EDX->fHandled = 1;
  }
  else {
    iVar4 = 0xb;
    bVar8 = false;
    pcVar5 = pcVar6;
    pcVar7 = "pitchrange";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar5 == *pcVar7;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      dVar9 = strtod(in_EDX->szValue,(char **)0x0);
      in_EAX[1].m_pfnBlocked.__delta = (int)(float)dVar9;
      in_EDX->fHandled = 1;
    }
    else {
      iVar4 = 10;
      bVar8 = false;
      pcVar5 = pcVar6;
      pcVar7 = "pitchrate";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pcVar5 == *pcVar7;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        dVar9 = strtod(in_EDX->szValue,(char **)0x0);
        in_EAX[1].m_pfnBlocked.__pfn =
             (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)(float)dVar9;
        in_EDX->fHandled = 1;
      }
      else {
        iVar4 = 0xf;
        bVar8 = false;
        pcVar5 = pcVar6;
        pcVar7 = "pitchtolerance";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar8 = *pcVar5 == *pcVar7;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          dVar9 = strtod(in_EDX->szValue,(char **)0x0);
          in_EAX[1].nextpc = (int)(float)dVar9;
          in_EDX->fHandled = 1;
        }
        else {
          iVar4 = 9;
          bVar8 = false;
          pcVar5 = pcVar6;
          pcVar7 = "firerate";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar8 = *pcVar5 == *pcVar7;
            pcVar5 = pcVar5 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            dVar9 = strtod(in_EDX->szValue,(char **)0x0);
            in_EAX[1].last_impulse = (int)(float)dVar9;
            in_EDX->fHandled = 1;
          }
          else {
            iVar4 = 7;
            bVar8 = false;
            pcVar5 = pcVar6;
            pcVar7 = "barrel";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar8 = *pcVar5 == *pcVar7;
              pcVar5 = pcVar5 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar8);
            if (bVar8) {
              dVar9 = strtod(in_EDX->szValue,(char **)0x0);
              in_EAX[1].no_grenades_2 = (int)(float)dVar9;
              in_EDX->fHandled = 1;
            }
            else {
              iVar4 = 8;
              bVar8 = false;
              pcVar5 = pcVar6;
              pcVar7 = "barrely";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar8 = *pcVar5 == *pcVar7;
                pcVar5 = pcVar5 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar8);
              if (bVar8) {
                dVar9 = strtod(in_EDX->szValue,(char **)0x0);
                in_EAX[1].tp_grenades_1 = (int)(float)dVar9;
                in_EDX->fHandled = 1;
              }
              else {
                iVar4 = 8;
                bVar8 = false;
                pcVar5 = pcVar6;
                pcVar7 = "barrelz";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar8 = *pcVar5 == *pcVar7;
                  pcVar5 = pcVar5 + 1;
                  pcVar7 = pcVar7 + 1;
                } while (bVar8);
                if (bVar8) {
                  dVar9 = strtod(in_EDX->szValue,(char **)0x0);
                  in_EAX[1].tp_grenades_2 = (int)(float)dVar9;
                  in_EDX->fHandled = 1;
                }
                else {
                  iVar4 = 0xc;
                  bVar8 = false;
                  pcVar5 = pcVar6;
                  pcVar7 = "spritescale";
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar8 = *pcVar5 == *pcVar7;
                    pcVar5 = pcVar5 + 1;
                    pcVar7 = pcVar7 + 1;
                  } while (bVar8);
                  if (bVar8) {
                    dVar9 = strtod(in_EDX->szValue,(char **)0x0);
                    in_EAX[1].m_iszGrenadeName = (string_t)(float)dVar9;
                    in_EDX->fHandled = 1;
                  }
                  else {
                    iVar4 = 0xc;
                    bVar8 = false;
                    pcVar5 = pcVar6;
                    pcVar7 = "spritesmoke";
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar8 = *pcVar5 == *pcVar7;
                      pcVar5 = pcVar5 + 1;
                      pcVar7 = pcVar7 + 1;
                    } while (bVar8);
                    if (bVar8) {
                      iVar4 = (*g_engfuncs.pfnAllocString)(in_EDX->szValue);
                      in_EAX[1].got_aliases = iVar4;
                      in_EDX->fHandled = 1;
                    }
                    else {
                      iVar4 = 0xc;
                      bVar8 = false;
                      pcVar5 = pcVar6;
                      pcVar7 = "spriteflash";
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar8 = *pcVar5 == *pcVar7;
                        pcVar5 = pcVar5 + 1;
                        pcVar7 = pcVar7 + 1;
                      } while (bVar8);
                      if (bVar8) {
                        iVar4 = (*g_engfuncs.pfnAllocString)(in_EDX->szValue);
                        in_EAX[1].cheat_check = iVar4;
                        in_EDX->fHandled = 1;
                      }
                      else {
                        iVar4 = 0xc;
                        bVar8 = false;
                        pcVar5 = pcVar6;
                        pcVar7 = "rotatesound";
                        do {
                          if (iVar4 == 0) break;
                          iVar4 = iVar4 + -1;
                          bVar8 = *pcVar5 == *pcVar7;
                          pcVar5 = pcVar5 + 1;
                          pcVar7 = pcVar7 + 1;
                        } while (bVar8);
                        if (bVar8) {
                          peVar1 = in_EAX->pev;
                          sVar2 = (*g_engfuncs.pfnAllocString)(in_EDX->szValue);
                          peVar1->noise = sVar2;
                          in_EDX->fHandled = 1;
                        }
                        else {
                          iVar4 = 0xc;
                          bVar8 = false;
                          pcVar5 = pcVar6;
                          pcVar7 = "persistence";
                          do {
                            if (iVar4 == 0) break;
                            iVar4 = iVar4 + -1;
                            bVar8 = *pcVar5 == *pcVar7;
                            pcVar5 = pcVar5 + 1;
                            pcVar7 = pcVar7 + 1;
                          } while (bVar8);
                          if (bVar8) {
                            dVar9 = strtod(in_EDX->szValue,(char **)0x0);
                            in_EAX[1].tf_items = (int)(float)dVar9;
                            in_EDX->fHandled = 1;
                          }
                          else {
                            iVar4 = 7;
                            bVar8 = false;
                            pcVar5 = pcVar6;
                            pcVar7 = "bullet";
                            do {
                              if (iVar4 == 0) break;
                              iVar4 = iVar4 + -1;
                              bVar8 = *pcVar5 == *pcVar7;
                              pcVar5 = pcVar5 + 1;
                              pcVar7 = pcVar7 + 1;
                            } while (bVar8);
                            if (bVar8) {
                              lVar3 = strtol(in_EDX->szValue,(char **)0x0,10);
                              in_EAX[1].is_removed = lVar3;
                              in_EDX->fHandled = 1;
                            }
                            else {
                              iVar4 = 0xe;
                              bVar8 = false;
                              pcVar5 = pcVar6;
                              pcVar7 = "bullet_damage";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar8 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar8);
                              if (bVar8) {
                                lVar3 = strtol(in_EDX->szValue,(char **)0x0,10);
                                in_EAX[1].is_undercover = lVar3;
                                in_EDX->fHandled = 1;
                              }
                              else {
                                iVar4 = 0xb;
                                bVar8 = false;
                                pcVar5 = pcVar6;
                                pcVar7 = "firespread";
                                do {
                                  if (iVar4 == 0) break;
                                  iVar4 = iVar4 + -1;
                                  bVar8 = *pcVar5 == *pcVar7;
                                  pcVar5 = pcVar5 + 1;
                                  pcVar7 = pcVar7 + 1;
                                } while (bVar8);
                                if (bVar8) {
                                  lVar3 = strtol(in_EDX->szValue,(char **)0x0,10);
                                  in_EAX[1].is_unableto_spy_or_teleport = lVar3;
                                  in_EDX->fHandled = 1;
                                }
                                else {
                                  iVar4 = 9;
                                  bVar8 = false;
                                  pcVar5 = pcVar6;
                                  pcVar7 = "minRange";
                                  do {
                                    if (iVar4 == 0) break;
                                    iVar4 = iVar4 + -1;
                                    bVar8 = *pcVar5 == *pcVar7;
                                    pcVar5 = pcVar5 + 1;
                                    pcVar7 = pcVar7 + 1;
                                  } while (bVar8);
                                  if (bVar8) {
                                    dVar9 = strtod(in_EDX->szValue,(char **)0x0);
                                    in_EAX[1].tf_items_flags = (int)(float)dVar9;
                                    in_EDX->fHandled = 1;
                                  }
                                  else {
                                    iVar4 = 9;
                                    bVar8 = false;
                                    pcVar5 = "maxRange";
                                    do {
                                      if (iVar4 == 0) break;
                                      iVar4 = iVar4 + -1;
                                      bVar8 = *pcVar6 == *pcVar5;
                                      pcVar6 = pcVar6 + 1;
                                      pcVar5 = pcVar5 + 1;
                                    } while (bVar8);
                                    if (bVar8) {
                                      dVar9 = strtod(in_EDX->szValue,(char **)0x0);
                                      in_EAX[1].no_grenades_1 = (int)(float)dVar9;
                                      in_EDX->fHandled = 1;
                                    }
                                    else {
                                      CBaseEntity::KeyValue(in_EAX,in_EDX);
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


// CFuncTank::KeyValue  @ 000d5ff0  (line 207)

/* DWARF original prototype: void KeyValue(CFuncTank * this, KeyValueData * pkvd) */

void __thiscall CFuncTank::KeyValue(CFuncTank *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  double dVar5;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 8;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "yawrate";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    dVar5 = strtod(pkvd->szValue,(char **)0x0);
    this->m_yawRate = (float)dVar5;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 9;
    bVar4 = false;
    pcVar2 = pkvd->szKeyName;
    pcVar3 = "yawrange";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      KeyValue(this,pkvd);
      return;
    }
    dVar5 = strtod(pkvd->szValue,(char **)0x0);
    this->m_yawRange = (float)dVar5;
    pkvd->fHandled = 1;
  }
  return;
}


// CFuncTank::OnControls  @ 000d5710  (line 317)

/* DWARF original prototype: BOOL OnControls(CFuncTank * this, entvars_t * pevTest) */

BOOL __thiscall CFuncTank::OnControls(CFuncTank *this,entvars_t *pevTest)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: Vector offset@[???] */
  if ((((this->super_CBaseEntity).pev)->spawnflags & 0x20) != 0) {
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


// CFuncTank::StartControl  @ 000d6480  (line 330)

/* DWARF original prototype: BOOL StartControl(CFuncTank * this, CBasePlayer * pController) */

BOOL __thiscall CFuncTank::StartControl(CFuncTank *this,CBasePlayer *pController)

{
  CBasePlayerItem *pCVar1;
  entvars_t *peVar2;
  
  if (this->m_pController != (CBasePlayer *)0x0) {
    return 0;
  }
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


// CFuncTank::StopControl  @ 000d6560  (line 353)

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
    this->m_pController = (CBasePlayer *)0x0;
    peVar3 = (this->super_CBaseEntity).pev;
    if ((peVar3->spawnflags & 1) != 0) {
      peVar3->nextthink = peVar3->ltime + 1.0;
    }
  }
  return;
}


// CFuncTank::ControllerPostFrame  @ 000d65e0  (line 374)

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
    local_44 = local_38 * fVar3 + (peVar6->origin).z + local_2c * fVar2 + local_20 * fVar1;
    local_48 = local_3c * fVar3 + (peVar6->origin).y + local_30 * fVar2 + local_24 * fVar1;
    local_4c = fVar1 * local_28 + fVar3 * local_40 + (peVar6->origin).x + fVar2 * local_34;
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


// CFuncTank::Use  @ 000d6780  (line 400)

/* DWARF original prototype: void Use(CFuncTank * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTank::Use(CFuncTank *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  int iVar1;
  entvars_t *peVar2;
  BOOL BVar3;
  uint uVar4;
  
  uVar4 = ((this->super_CBaseEntity).pev)->spawnflags;
  if ((uVar4 & 0x20) == 0) {
    iVar1 = CBaseEntity::ShouldToggle(&this->super_CBaseEntity,useType,uVar4 & 1);
    if (iVar1 != 0) {
      peVar2 = (this->super_CBaseEntity).pev;
      uVar4 = peVar2->spawnflags;
      if ((uVar4 & 1) == 0) {
        peVar2->spawnflags = uVar4 | 1;
        peVar2 = (this->super_CBaseEntity).pev;
        peVar2->nextthink = peVar2->ltime + 0.1;
        this->m_fireLast = 0.0;
        return;
      }
      peVar2->spawnflags = uVar4 & 0xfffffffe;
      peVar2 = (this->super_CBaseEntity).pev;
      this->m_fireLast = 0.0;
      uVar4 = peVar2->spawnflags;
      if ((uVar4 & 0x8000) != 0) {
        EMIT_SOUND_DYN(peVar2->pContainingEntity,6,gpGlobals->pStringBase + peVar2->noise,0.0,0.0,
                       0x20,100);
        peVar2 = (this->super_CBaseEntity).pev;
        uVar4 = peVar2->spawnflags;
      }
      peVar2->spawnflags = uVar4 & 0xffff7fff;
    }
  }
  else {
    iVar1 = (*pActivator->_vptr_CBaseEntity[10])(pActivator);
    if ((iVar1 == 2) &&
       (BVar3 = ActivationSucceeded(&this->super_CBaseEntity,(CBasePlayer *)pActivator,
                                    (CBaseEntity *)0x0), BVar3 != 0)) {
      if ((value == 2.0) && (useType == USE_SET)) {
        ControllerPostFrame(this);
        return;
      }
      if ((useType != USE_OFF) && (this->m_pController == (CBasePlayer *)0x0)) {
        EHANDLE::operator=((EHANDLE *)&pActivator[1].rs_gr,&this->super_CBaseEntity);
        StartControl(this,(CBasePlayer *)pActivator);
        return;
      }
      StopControl(this);
      return;
    }
  }
  return;
}


// CFuncTank::FindTarget  @ 000d6990  (line 441)

/* DWARF original prototype: edict_t * FindTarget(CFuncTank * this, edict_t * pPlayer) */

edict_t * __thiscall CFuncTank::FindTarget(CFuncTank *this,edict_t *pPlayer)

{
  return pPlayer;
}


// CFuncTank::InRange  @ 000d69a0  (line 446)

/* DWARF original prototype: BOOL InRange(CFuncTank * this, float range) */

BOOL __thiscall CFuncTank::InRange(CFuncTank *this,float range)

{
  BOOL BVar1;
  
  BVar1 = 0;
  if (this->m_minRange <= range) {
    BVar1 = 1;
    if (0.0 < this->m_maxRange) {
      return (uint)(range <= this->m_maxRange);
    }
  }
  return BVar1;
}


// CFuncTank::Think  @ 000d73d0  (line 457)

/* DWARF original prototype: void Think(CFuncTank * this) */

void __thiscall CFuncTank::Think(CFuncTank *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  TrackTarget(this);
  peVar1 = (this->super_CBaseEntity).pev;
  if ((ABS((peVar1->avelocity).x) <= 1.0) && (ABS((peVar1->avelocity).y) <= 1.0)) {
    if ((peVar1->spawnflags & 0x8000U) == 0) {
      peVar1->spawnflags = peVar1->spawnflags & 0xffff7fff;
    }
    else {
      EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20
                     ,100);
      peVar1 = (this->super_CBaseEntity).pev;
      peVar1->spawnflags = peVar1->spawnflags & 0xffff7fff;
    }
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


// CFuncTank::TrackTarget  @ 000d6b40  (line 468)

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
  entvars_t *peVar9;
  int iVar10;
  float *pfVar11;
  edict_t *unaff_EDI;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined4 local_130;
  TraceResult local_ec;
  float local_ac;
  vec_t local_a8;
  vec_t local_a4;
  Vector local_94;
  Vector local_88;
  vec_t local_7c;
  vec_t local_78;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  pfVar11 = (float *)&stack0xfffffed4;
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
  local_130 = 0xd6b63;
  peVar8 = (*g_engfuncs.pfnFindClientInPVS)(((this->super_CBaseEntity).pev)->pContainingEntity);
  if (this->m_pController == (CBasePlayer *)0x0) {
    peVar9 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: float range@[???] */
    if ((peVar9->spawnflags & 1) == 0) {
      return;
    }
    peVar9->nextthink = peVar9->ltime + 0.1;
    if (peVar8 != (edict_t *)0x0) {
      local_130 = 0xd6f83;
      iVar10 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar8);
      if (iVar10 != 0) {
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
        local_130 = 0xd6fbb;
        (*g_engfuncs.pfnAngleVectors)
                  (&(((this->super_CBaseEntity).pev)->angles).x,&local_40,&local_34,&local_28);
        peVar9 = (this->super_CBaseEntity).pev;
        fVar12 = (this->m_barrelPos).z;
        fVar14 = (this->m_barrelPos).y;
        fVar13 = (this->m_barrelPos).x;
        local_88.z = local_38 * fVar13 + (peVar9->origin).z + local_2c * fVar14 + local_20 * fVar12;
        local_88.y = local_3c * fVar13 + (peVar9->origin).y + local_30 * fVar14 + local_24 * fVar12;
        local_88.x = fVar12 * local_28 + fVar13 * local_40 + (peVar9->origin).x + fVar14 * local_34;
        local_94.z = (peVar8->v).origin.z + (peVar8->v).view_ofs.z;
        local_94.y = (peVar8->v).origin.y + (peVar8->v).view_ofs.y;
        local_94.x = (peVar8->v).origin.x + (peVar8->v).view_ofs.x;
        fVar12 = (local_94.z - local_88.z) * (local_94.z - local_88.z) +
                 (local_94.y - local_88.y) * (local_94.y - local_88.y) +
                 (local_94.x - local_88.x) * (local_94.x - local_88.x);
        fVar14 = SQRT(fVar12);
        if (NAN(fVar14)) {
          local_130 = 0xd73b5;
          fVar14 = sqrtf(fVar12);
        }
        if (fVar14 < this->m_minRange) {
          return;
        }
        if ((0.0 < this->m_maxRange) && (this->m_maxRange < fVar14)) {
          return;
        }
        local_130 = 0xd711b;
        UTIL_TraceLine(&local_88,&local_94,dont_ignore_monsters,
                       ((this->super_CBaseEntity).pev)->pContainingEntity,&local_ec);
        if ((local_ec.flFraction == 1.0) || (bVar7 = false, peVar8 == local_ec.pHit)) {
                    /* Unresolved local var: CBaseEntity * pInstance@[DW_OP_reg7(EDI)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          if ((this->m_minRange <= fVar14) &&
             (((this->m_maxRange <= 0.0 || (fVar14 <= this->m_maxRange)) &&
              (peVar8->pvPrivateData != (int *)0x0)))) {
            local_130 = 0xd7341;
            iVar10 = (**(code **)(*(int *)peVar8->pvPrivateData + 0x88))();
            if (iVar10 != 0) {
              bVar7 = true;
              local_130 = 0xd7364;
              (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x42])();
              pfVar11 = (float *)&local_130;
              (this->m_sightOrigin).x = local_88.z;
              (this->m_sightOrigin).y = local_7c;
              (this->m_sightOrigin).z = local_78;
              goto LAB_000d713d;
            }
          }
          bVar7 = false;
          pfVar11 = (float *)&stack0xfffffed4;
        }
LAB_000d713d:
        peVar9 = (this->super_CBaseEntity).pev;
        fVar12 = (this->m_sightOrigin).z;
        fVar14 = (peVar9->origin).z;
        fVar13 = (this->m_sightOrigin).y;
        fVar1 = (peVar9->origin).y;
        fVar2 = (this->m_sightOrigin).x;
        fVar3 = (peVar9->origin).x;
        pfVar11[1] = (float)(pfVar11 + 0x23);
        *pfVar11 = (float)(pfVar11 + 0x2f);
        pfVar11[0x23] = fVar2 - fVar3;
        pfVar11[0x24] = fVar13 - fVar1;
        pfVar11[0x25] = fVar12 - fVar14;
        pfVar11[-1] = 1.234592e-39;
        UTIL_VecToAngles((Vector *)*pfVar11,(Vector *)pfVar11[1]);
        pfVar11[0x20] = pfVar11[0x2f];
        pfVar11[0x21] = pfVar11[0x30];
        pfVar11[0x22] = pfVar11[0x31];
        fVar12 = pfVar11[0x25] * pfVar11[0x25] +
                 pfVar11[0x24] * pfVar11[0x24] + pfVar11[0x23] * pfVar11[0x23];
        fVar14 = SQRT(fVar12);
        if (NAN(fVar14)) {
          *pfVar11 = fVar12;
          pfVar11[-1] = 1.23539e-39;
          fVar14 = sqrtf(*pfVar11);
        }
        pfVar11[2] = fVar14;
        pfVar11[1] = (float)(pfVar11 + 0x20);
        *pfVar11 = (float)this;
        pfVar11[-1] = 1.234761e-39;
        AdjustAnglesForBarrel((CFuncTank *)*pfVar11,(Vector *)pfVar11[1],pfVar11[2]);
        fVar12 = pfVar11[0x20];
        goto LAB_000d6bb4;
      }
    }
    peVar9 = (this->super_CBaseEntity).pev;
    if ((peVar9->spawnflags & 1) != 0) {
      peVar9->nextthink = peVar9->ltime + 2.0;
    }
  }
  else {
    peVar9 = (this->m_pController->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    bVar7 = false;
    local_ac = (peVar9->v_angle).x;
    fVar12 = 0.0 - local_ac;
    local_a8 = (peVar9->v_angle).y;
    local_a4 = (peVar9->v_angle).z;
    peVar9 = (this->super_CBaseEntity).pev;
    peVar9->nextthink = peVar9->ltime + 0.05;
    pfVar11 = (float *)&stack0xfffffed4;
    peVar8 = unaff_EDI;
LAB_000d6bb4:
    pfVar11[0x20] = -fVar12;
    fVar12 = this->m_yawCenter;
    *pfVar11 = pfVar11[0x21];
    pfVar11[1] = fVar12;
    pfVar11[8] = fVar12;
    pfVar11[-1] = 1.232551e-39;
    fVar12 = UTIL_AngleDistance(*pfVar11,pfVar11[1]);
    pfVar11[0x21] = pfVar11[8] + fVar12;
    fVar12 = this->m_pitchCenter;
    *pfVar11 = pfVar11[0x20];
    pfVar11[1] = fVar12;
    pfVar11[8] = fVar12;
    pfVar11[-1] = 1.23261e-39;
    fVar12 = UTIL_AngleDistance(*pfVar11,pfVar11[1]);
    pfVar11[0x20] = pfVar11[8] + fVar12;
    fVar12 = pfVar11[0x21];
    fVar14 = this->m_yawCenter + this->m_yawRange;
    if (fVar14 < fVar12) {
      pfVar11[0x21] = fVar14;
    }
    else {
      fVar14 = this->m_yawCenter - this->m_yawRange;
      if (fVar14 <= fVar12) {
        fVar14 = fVar12;
        if (bVar7) {
          this->m_lastSightTime = gpGlobals->time;
        }
      }
      else {
        pfVar11[0x21] = fVar14;
      }
    }
    fVar12 = (((this->super_CBaseEntity).pev)->angles).y;
    *pfVar11 = fVar14;
    pfVar11[1] = fVar12;
    pfVar11[-1] = 1.23274e-39;
    fVar12 = UTIL_AngleDistance(*pfVar11,pfVar11[1]);
    peVar9 = (this->super_CBaseEntity).pev;
    pfVar11[0xe] = fVar12;
    (peVar9->avelocity).y = fVar12 * 10.0;
    peVar9 = (this->super_CBaseEntity).pev;
    fVar12 = (peVar9->avelocity).y;
    fVar14 = this->m_yawRate;
    if ((fVar14 < fVar12) || (fVar14 = -fVar14, fVar12 < fVar14)) {
      (peVar9->avelocity).y = fVar14;
      peVar9 = (this->super_CBaseEntity).pev;
    }
    fVar12 = pfVar11[0x20];
    fVar14 = this->m_pitchCenter + this->m_pitchRange;
    if (fVar12 <= fVar14) {
      fVar14 = this->m_pitchCenter - this->m_pitchRange;
      if (fVar12 < fVar14) {
        pfVar11[0x20] = fVar14;
        fVar12 = fVar14;
      }
    }
    else {
      pfVar11[0x20] = fVar14;
      fVar12 = fVar14;
    }
    fVar14 = (peVar9->angles).x;
    *pfVar11 = fVar12;
    pfVar11[1] = fVar14;
    pfVar11[-1] = 1.232931e-39;
    fVar13 = UTIL_AngleDistance(*pfVar11,pfVar11[1]);
    (((this->super_CBaseEntity).pev)->avelocity).x = fVar13 * 10.0;
    peVar9 = (this->super_CBaseEntity).pev;
    fVar12 = (peVar9->avelocity).x;
    fVar14 = this->m_pitchRate;
    if ((fVar14 < fVar12) || (fVar14 = -fVar14, fVar12 < fVar14)) {
      (peVar9->avelocity).x = fVar14;
    }
    if (this->m_pController == (CBasePlayer *)0x0) {
      if (this->m_persist <= gpGlobals->time - this->m_lastSightTime) {
LAB_000d6f3a:
        this->m_fireLast = 0.0;
        return;
      }
      if ((this->m_pitchTolerance <= ABS(fVar13)) || (this->m_yawTolerance <= ABS(pfVar11[0xe]))) {
        peVar9 = (this->super_CBaseEntity).pev;
        if ((peVar9->spawnflags & 0x10) == 0) goto LAB_000d6f3a;
      }
      else {
        peVar9 = (this->super_CBaseEntity).pev;
      }
                    /* Unresolved local var: BOOL fire@[???]
                       Unresolved local var: Vector forward@[???] */
      pfVar11[3] = 0.0;
      pfVar11[2] = 0.0;
      pfVar11[1] = (float)(pfVar11 + 0x32);
      *pfVar11 = (float)&peVar9->angles;
      pfVar11[-1] = 1.233368e-39;
      (*g_engfuncs.pfnAngleVectors)
                ((float *)*pfVar11,(float *)pfVar11[1],(float *)pfVar11[2],(float *)pfVar11[3]);
      peVar9 = (this->super_CBaseEntity).pev;
      if ((peVar9->spawnflags & 0x10) != 0) {
                    /* Unresolved local var: float length@[???] */
        fVar12 = pfVar11[0x25] * pfVar11[0x25] +
                 pfVar11[0x24] * pfVar11[0x24] + pfVar11[0x23] * pfVar11[0x23];
        fVar14 = SQRT(fVar12);
        if (NAN(fVar14)) {
          *pfVar11 = fVar12;
          pfVar11[-1] = 1.235348e-39;
          fVar14 = sqrtf(*pfVar11);
        }
        peVar6 = ((this->super_CBaseEntity).pev)->pContainingEntity;
        pfVar11[4] = (float)(pfVar11 + 0x10);
        pfVar11[3] = (float)peVar6;
        pfVar11[2] = 0.0;
        pfVar11[1] = (float)(pfVar11 + 0x35);
        *pfVar11 = (float)(pfVar11 + 0x29);
        pfVar11[0x35] = fVar14 * pfVar11[0x32] + pfVar11[0x29];
        pfVar11[0x36] = pfVar11[0x33] * fVar14 + pfVar11[0x2a];
        pfVar11[0x37] = pfVar11[0x34] * fVar14 + pfVar11[0x2b];
        pfVar11[-1] = 1.235092e-39;
        UTIL_TraceLine((Vector *)*pfVar11,(Vector *)pfVar11[1],(IGNORE_MONSTERS)pfVar11[2],
                       (edict_t *)pfVar11[3],(TraceResult *)pfVar11[4]);
        if ((edict_t *)pfVar11[0x1c] != peVar8) goto LAB_000d6f3a;
        peVar9 = (this->super_CBaseEntity).pev;
      }
      p_Var4 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x41];
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
      pfVar11[3] = (float)(pfVar11 + 0x3b);
      pfVar11[2] = (float)(pfVar11 + 0x3e);
      pfVar11[1] = (float)(pfVar11 + 0x41);
      *pfVar11 = (float)&peVar9->angles;
      pfVar11[-1] = 1.233465e-39;
      (*g_engfuncs.pfnAngleVectors)
                ((float *)*pfVar11,(float *)pfVar11[1],(float *)pfVar11[2],(float *)pfVar11[3]);
      peVar5 = (this->super_CBaseEntity).pev;
      fVar12 = (this->m_barrelPos).z;
      fVar14 = (this->m_barrelPos).y;
      fVar13 = (this->m_barrelPos).x;
      fVar1 = (peVar5->origin).z;
      fVar2 = (peVar5->origin).y;
      fVar3 = (peVar5->origin).x;
      pfVar11[3] = (float)peVar9;
      pfVar11[2] = (float)(pfVar11 + 0x32);
      pfVar11[1] = (float)(pfVar11 + 0x38);
      *pfVar11 = (float)this;
      pfVar11[0x38] =
           fVar12 * pfVar11[0x3b] + fVar13 * pfVar11[0x41] + fVar3 + fVar14 * pfVar11[0x3e];
      pfVar11[0x39] =
           pfVar11[0x42] * fVar13 + fVar2 + pfVar11[0x3f] * fVar14 + pfVar11[0x3c] * fVar12;
      pfVar11[0x3a] =
           pfVar11[0x43] * fVar13 + fVar1 + pfVar11[0x40] * fVar14 + pfVar11[0x3d] * fVar12;
      pfVar11[-1] = 1.233706e-39;
      (*p_Var4)();
    }
  }
  return;
}


// CFuncTank::AdjustAnglesForBarrel  @ 000d69f0  (line 612)

/* DWARF original prototype: void AdjustAnglesForBarrel(CFuncTank * this, Vector * angles, float
   distance) */

void __thiscall CFuncTank::AdjustAnglesForBarrel(CFuncTank *this,Vector *angles,float distance)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
                    /* Unresolved local var: float r2@[???]
                       Unresolved local var: float d2@[???] */
  fVar1 = (this->m_barrelPos).y;
  if (fVar1 == 0.0) {
    fVar2 = (this->m_barrelPos).z;
    if (fVar2 == 0.0) {
      return;
    }
    fVar4 = (distance - fVar2) * (distance - fVar2);
    if (fVar1 == 0.0) goto LAB_000d6aca;
  }
  else {
    fVar4 = distance - (this->m_barrelPos).z;
    fVar4 = fVar4 * fVar4;
  }
  fVar2 = angles->y;
  fVar1 = fVar4 - fVar1 * fVar1;
  fVar3 = SQRT(fVar1);
  if (NAN(fVar3)) {
    dVar5 = sqrt((double)fVar1);
    fVar3 = (float)dVar5;
  }
  dVar5 = atan2((double)(this->m_barrelPos).y,(double)fVar3);
  angles->y = (float)((longdouble)dVar5 * (longdouble)57.29577951308232 + (longdouble)fVar2);
  fVar2 = (this->m_barrelPos).z;
  if (fVar2 == 0.0) {
    return;
  }
LAB_000d6aca:
  fVar1 = angles->x;
  fVar4 = fVar4 - fVar2 * fVar2;
  fVar3 = SQRT(fVar4);
  if (NAN(fVar3)) {
    dVar5 = sqrt((double)fVar4);
    fVar3 = (float)dVar5;
    fVar2 = (this->m_barrelPos).z;
  }
  dVar5 = atan2((double)-fVar2,(double)fVar3);
  angles->x = (float)((longdouble)dVar5 * (longdouble)57.29577951308232 + (longdouble)fVar1);
  return;
}


// CFuncTank::Fire  @ 000d4bd0  (line 636)

/* DWARF original prototype: void Fire(CFuncTank * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTank::Fire(CFuncTank *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  globalvars_t *pgVar5;
  int iVar6;
  CSprite *pCVar7;
  longdouble lVar8;
  
  if (NAN(this->m_fireLast)) {
    iVar6 = this->m_iszSpriteSmoke;
    if (iVar6 != 0) goto LAB_000d4c64;
LAB_000d4c05:
    iVar6 = this->m_iszSpriteFlash;
  }
  else {
    if (this->m_fireLast == 0.0) goto LAB_000d4c30;
    iVar6 = this->m_iszSpriteSmoke;
    if (iVar6 == 0) goto LAB_000d4c05;
LAB_000d4c64:
                    /* Unresolved local var: CSprite * pSprite@[???] */
    pCVar7 = CSprite::SpriteCreate(gpGlobals->pStringBase + iVar6,barrelEnd,1);
    lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(15.0,20.0);
    peVar4 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateUntilDead;
    (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar4->framerate = (float)lVar8;
    pgVar5 = gpGlobals;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->dmgtime =
         (float)((longdouble)pCVar7->m_maxFrame / lVar8 + (longdouble)gpGlobals->time);
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->nextthink = pgVar5->time;
    peVar4 = (this->super_CBaseEntity).pev;
    fVar1 = (peVar4->rendercolor).z;
    fVar2 = (peVar4->rendercolor).y;
    fVar3 = (peVar4->rendercolor).x;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 4;
    (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = (float)(int)fVar3;
    (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = (float)(int)fVar2;
    (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = (float)(int)fVar1;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0;
    peVar4 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(40.0,80.0);
    (peVar4->velocity).z = (float)lVar8;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->scale = this->m_spriteScale;
    iVar6 = this->m_iszSpriteFlash;
  }
  if (iVar6 != 0) {
                    /* Unresolved local var: CSprite * pSprite@[???] */
    pCVar7 = CSprite::SpriteCreate(gpGlobals->pStringBase + iVar6,barrelEnd,1);
    peVar4 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateUntilDead;
    (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar4->framerate = 60.0;
    pgVar5 = gpGlobals;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->dmgtime =
         pCVar7->m_maxFrame / 60.0 + gpGlobals->time;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->nextthink = pgVar5->time;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 5;
    (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = 255.0;
    (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = 255.0;
    (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = 255.0;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0xe;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->scale = this->m_spriteScale;
  }
  CBaseEntity::SUB_UseTargets(&this->super_CBaseEntity,&this->super_CBaseEntity,USE_TOGGLE,0.0);
LAB_000d4c30:
  this->m_fireLast = gpGlobals->time;
  return;
}


// CFuncTank::TankTrace  @ 000d54e0  (line 660)

/* DWARF original prototype: void TankTrace(CFuncTank * this, Vector * vecStart, Vector *
   vecForward, Vector * vecSpread, TraceResult * tr) */

void __thiscall
CFuncTank::TankTrace
          (CFuncTank *this,Vector *vecStart,Vector *vecForward,Vector *vecSpread,TraceResult *tr)

{
  int in_EAX;
  float *in_ECX;
  Vector *in_EDX;
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  Vector local_28 [2];
  
  do {
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???] */
    lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar4 = lVar4 + (longdouble)(float)lVar3;
    lVar3 = (longdouble)(float)(lVar2 + (longdouble)(float)lVar1);
  } while ((longdouble)1 < lVar4 * lVar4 + lVar3 * lVar3);
  lVar4 = lVar4 * (longdouble)(float)(this->super_CBaseEntity).pev;
  lVar1 = (longdouble)(float)(lVar2 + (longdouble)(float)lVar1) *
          (longdouble)(float)(this->super_CBaseEntity)._vptr_CBaseEntity;
  lVar2 = (longdouble)4096.0;
  local_28[0].x =
       (vec_t)((lVar1 * (longdouble)(gpGlobals->v_right).x + (longdouble)*in_ECX +
               lVar4 * (longdouble)(gpGlobals->v_up).x) * lVar2 + (longdouble)in_EDX->x);
  local_28[0].y =
       (vec_t)(((longdouble)(gpGlobals->v_right).y * lVar1 + (longdouble)in_ECX[1] +
               (longdouble)(gpGlobals->v_up).y * lVar4) * lVar2 + (longdouble)in_EDX->y);
  local_28[0].z =
       (vec_t)(((longdouble)(gpGlobals->v_right).z * lVar1 + (longdouble)in_ECX[2] +
               (longdouble)(gpGlobals->v_up).z * lVar4) * lVar2 + (longdouble)in_EDX->z);
  UTIL_TraceLine(in_EDX,local_28,dont_ignore_monsters,*(edict_t **)(*(int *)(in_EAX + 4) + 0x208),
                 (TraceResult *)vecStart);
  return;
}


// CFuncTank::TankTrace  @ 000d7580  (line 661)

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
  
  do {
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???] */
    lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
    lVar4 = lVar4 + (longdouble)(float)lVar3;
    lVar3 = (longdouble)(float)(lVar2 + (longdouble)(float)lVar1);
  } while ((longdouble)1 < lVar4 * lVar4 + lVar3 * lVar3);
  lVar4 = lVar4 * (longdouble)vecSpread->y;
  lVar1 = (longdouble)(float)(lVar2 + (longdouble)(float)lVar1) * (longdouble)vecSpread->x;
  lVar2 = (longdouble)4096.0;
  local_18.x = (vec_t)((lVar1 * (longdouble)(gpGlobals->v_right).x + (longdouble)vecForward->x +
                       lVar4 * (longdouble)(gpGlobals->v_up).x) * lVar2 + (longdouble)vecStart->x);
  local_18.y = (vec_t)(((longdouble)(gpGlobals->v_right).y * lVar1 + (longdouble)vecForward->y +
                       (longdouble)(gpGlobals->v_up).y * lVar4) * lVar2 + (longdouble)vecStart->y);
  local_18.z = (vec_t)(((longdouble)(gpGlobals->v_right).z * lVar1 + (longdouble)vecForward->z +
                       (longdouble)(gpGlobals->v_up).z * lVar4) * lVar2 + (longdouble)vecStart->z);
  UTIL_TraceLine(vecStart,&local_18,dont_ignore_monsters,
                 ((this->super_CBaseEntity).pev)->pContainingEntity,tr);
  return;
}


// CFuncTank::StartRotSound  @ 000d76b0  (line 680)

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


// CFuncTank::StopRotSound  @ 000d7740  (line 689)

/* DWARF original prototype: void StopRotSound(CFuncTank * this) */

void __thiscall CFuncTank::StopRotSound(CFuncTank *this)

{
  entvars_t *peVar1;
  uint uVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  uVar2 = peVar1->spawnflags;
  if ((uVar2 & 0x8000) != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20,
                   100);
    peVar1 = (this->super_CBaseEntity).pev;
    uVar2 = peVar1->spawnflags;
  }
  peVar1->spawnflags = uVar2 & 0xffff7fff;
  return;
}


// func_tank  @ 000d77d0  (line 700)

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
  *puVar1 = &PTR__CFuncTankGun_0017f4a8;
  puVar1[1] = pev;
  return;
}


// CFuncTankGun::Fire  @ 000d51d0  (line 703)

/* DWARF original prototype: void Fire(CFuncTankGun * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTankGun::Fire(CFuncTankGun *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  TANKBULLET TVar1;
  int iVar2;
  Vector vecSrc;
  Vector vecSrc_00;
  Vector vecSrc_01;
  Vector vecDirShooting;
  Vector vecDirShooting_00;
  Vector vecDirShooting_01;
  Vector vecSpread;
  Vector vecSpread_00;
  Vector vecSpread_01;
  entvars_t *pevAttacker_00;
  entvars_t *peVar3;
  vec_t in_stack_ffffff5c;
  float in_stack_ffffff60;
  int in_stack_ffffff64;
  int in_stack_ffffff68;
  float iDamage;
  vec_t local_88;
  vec_t local_84;
  vec_t local_80;
  vec_t local_7c;
  vec_t local_78;
  vec_t local_74;
  vec_t local_70;
  vec_t local_6c;
  vec_t local_68;
  vec_t local_64;
  vec_t local_60;
  vec_t local_5c;
  vec_t local_58;
  vec_t local_54;
  vec_t local_50;
  vec_t local_4c;
  vec_t local_48;
  vec_t local_44;
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
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int bulletCount@[???] */
    UTIL_MakeAimVectors(&((this->super_CFuncTank).super_CBaseEntity.pev)->angles);
    iDamage = (gpGlobals->time - (this->super_CFuncTank).m_fireLast) *
              (this->super_CFuncTank).m_fireRate;
    pevAttacker_00 = (entvars_t *)(int)iDamage;
    if ((int)pevAttacker_00 < 1) {
      return;
    }
    peVar3 = (entvars_t *)0x0;
    do {
      TVar1 = (this->super_CFuncTank).m_bulletType;
      if (TVar1 == TANK_BULLET_MP5) {
        iVar2 = (this->super_CFuncTank).m_spread;
        local_64 = gTankSpread[iVar2].x;
        local_60 = gTankSpread[iVar2].y;
        local_5c = gTankSpread[iVar2].z;
        local_58 = forward->x;
        local_54 = forward->y;
        local_50 = forward->z;
        local_4c = barrelEnd->x;
        local_48 = barrelEnd->y;
        local_44 = barrelEnd->z;
        vecSrc_00.y = (vec_t)&local_58;
        vecSrc_00.x = (vec_t)&local_4c;
        vecSrc_00.z = (vec_t)&local_64;
        vecDirShooting_00.z = 1.4013e-45;
        vecDirShooting_00.x = 4096.0;
        vecDirShooting_00.y = 1.26117e-44;
        vecSpread_00.y = (vec_t)pevAttacker;
        vecSpread_00.x = (vec_t)(this->super_CFuncTank).m_iBulletDamage;
        vecSpread_00.z = in_stack_ffffff5c;
        CBaseEntity::FireBullets
                  ((CBaseEntity *)this,1,vecSrc_00,vecDirShooting_00,vecSpread_00,in_stack_ffffff60,
                   in_stack_ffffff64,in_stack_ffffff68,(int)iDamage,pevAttacker_00);
      }
      else if (TVar1 == TANK_BULLET_12MM) {
        iVar2 = (this->super_CFuncTank).m_spread;
        local_40 = gTankSpread[iVar2].x;
        local_3c = gTankSpread[iVar2].y;
        local_38 = gTankSpread[iVar2].z;
        local_34 = forward->x;
        local_30 = forward->y;
        local_2c = forward->z;
        local_28 = barrelEnd->x;
        local_24 = barrelEnd->y;
        local_20 = barrelEnd->z;
        vecSrc_01.y = (vec_t)&local_34;
        vecSrc_01.x = (vec_t)&local_28;
        vecSrc_01.z = (vec_t)&local_40;
        vecDirShooting_01.z = 1.4013e-45;
        vecDirShooting_01.x = 4096.0;
        vecDirShooting_01.y = 1.4013e-44;
        vecSpread_01.y = (vec_t)pevAttacker;
        vecSpread_01.x = (vec_t)(this->super_CFuncTank).m_iBulletDamage;
        vecSpread_01.z = in_stack_ffffff5c;
        CBaseEntity::FireBullets
                  ((CBaseEntity *)this,1,vecSrc_01,vecDirShooting_01,vecSpread_01,in_stack_ffffff60,
                   in_stack_ffffff64,in_stack_ffffff68,(int)iDamage,pevAttacker_00);
      }
      else if (TVar1 == TANK_BULLET_9MM) {
        iVar2 = (this->super_CFuncTank).m_spread;
        local_88 = gTankSpread[iVar2].x;
        local_84 = gTankSpread[iVar2].y;
        local_80 = gTankSpread[iVar2].z;
        local_7c = forward->x;
        local_78 = forward->y;
        local_74 = forward->z;
        local_70 = barrelEnd->x;
        local_6c = barrelEnd->y;
        local_68 = barrelEnd->z;
        vecSrc.y = (vec_t)&local_7c;
        vecSrc.x = (vec_t)&local_70;
        vecSrc.z = (vec_t)&local_88;
        vecDirShooting.z = 1.4013e-45;
        vecDirShooting.x = 4096.0;
        vecDirShooting.y = 1.12104e-44;
        vecSpread.y = (vec_t)pevAttacker;
        vecSpread.x = (vec_t)(this->super_CFuncTank).m_iBulletDamage;
        vecSpread.z = in_stack_ffffff5c;
        CBaseEntity::FireBullets
                  ((CBaseEntity *)this,1,vecSrc,vecDirShooting,vecSpread,in_stack_ffffff60,
                   in_stack_ffffff64,in_stack_ffffff68,(int)iDamage,pevAttacker_00);
      }
      peVar3 = (entvars_t *)((int)&peVar3->classname + 1);
    } while (peVar3 != pevAttacker_00);
  }
  CFuncTank::Fire(&this->super_CFuncTank,barrelEnd,forward,pevAttacker);
  return;
}


// func_tanklaser  @ 000d7840  (line 761)

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
  *puVar1 = &PTR__CFuncTankLaser_0017f5c8;
  puVar1[1] = pev;
  return;
}


// CFuncTankLaser::Save  @ 000d5a40  (line 769)

/* DWARF original prototype: int Save(CFuncTankLaser * this, CSave * save) */

int __thiscall CFuncTankLaser::Save(CFuncTankLaser *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CFuncTank",this,CFuncTank::m_SaveData,0x19);
    if (iVar1 != 0) {
      iVar2 = CSave::WriteFields(save,"CFuncTankLaser",this,m_SaveData,2);
    }
  }
  return iVar2;
}


// CFuncTankLaser::Restore  @ 000d5ae0  (line 769)

/* DWARF original prototype: int Restore(CFuncTankLaser * this, CRestore * restore) */

int __thiscall CFuncTankLaser::Restore(CFuncTankLaser *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CFuncTank",this,CFuncTank::m_SaveData,0x19);
    if (iVar1 != 0) {
      iVar2 = CRestore::ReadFields(restore,"CFuncTankLaser",this,m_SaveData,2);
    }
  }
  return iVar2;
}


// CFuncTankLaser::Activate  @ 000d5880  (line 772)

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


// CFuncTankLaser::KeyValue  @ 000d6240  (line 786)

/* DWARF original prototype: void KeyValue(CFuncTankLaser * this, KeyValueData * pkvd) */

void __thiscall CFuncTankLaser::KeyValue(CFuncTankLaser *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  string_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  double dVar8;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 0xc;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "laserentity";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    peVar1->message = sVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 8;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "yawrate";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CFuncTank).m_yawRate = (float)dVar8;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 9;
      bVar7 = false;
      pcVar4 = "yawrange";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (!bVar7) {
        CFuncTank::KeyValue(&this->super_CFuncTank,pkvd);
        return;
      }
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CFuncTank).m_yawRange = (float)dVar8;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CFuncTankLaser::GetLaser  @ 000d5790  (line 797)

/* DWARF original prototype: CLaser * GetLaser(CFuncTankLaser * this) */

CLaser * __thiscall CFuncTankLaser::GetLaser(CFuncTankLaser *this)

{
  int in_EAX;
  edict_t *peVar1;
  int iVar2;
  CLaser *pCVar3;
  entvars_t *peVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
                    /* Unresolved local var: edict_t * pentLaser@[???] */
  peVar1 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1d4));
  do {
    if ((peVar1 == (edict_t *)0x0) ||
       (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar2 == 0)) {
      return *(CLaser **)(in_EAX + 0x4f0);
    }
    peVar4 = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      peVar4 = (entvars_t *)0x0;
    }
    iVar2 = 10;
    pcVar5 = gpGlobals->pStringBase + peVar4->classname;
    bVar7 = pcVar5 == (char *)0x0;
    pcVar6 = "env_laser";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
      pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
    } while (bVar7);
    if (bVar7) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
      if ((peVar1 == (edict_t *)0x0) &&
         (peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar1 == (edict_t *)0x0)) {
        pCVar3 = (CLaser *)0x0;
      }
      else {
        pCVar3 = peVar1->pvPrivateData;
      }
      *(CLaser **)(in_EAX + 0x4f0) = pCVar3;
      return pCVar3;
    }
    peVar1 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar1,"targetname",
                        gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1d4));
  } while( true );
}


// CFuncTankLaser::GetLaser  @ 000d78b0  (line 798)

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


// CFuncTankLaser::Think  @ 000d7540  (line 822)

/* DWARF original prototype: void Think(CFuncTankLaser * this) */

void __thiscall CFuncTankLaser::Think(CFuncTankLaser *this)

{
  if ((this->m_pLaser != (CLaser *)0x0) && (this->m_laserTime < gpGlobals->time)) {
    CLaser::TurnOff(this->m_pLaser);
  }
  CFuncTank::Think(&this->super_CFuncTank);
  return;
}


// CFuncTankLaser::Fire  @ 000d58e0  (line 831)

/* DWARF original prototype: void Fire(CFuncTankLaser * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTankLaser::Fire(CFuncTankLaser *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  entvars_t *peVar1;
  int iVar2;
  CLaser *pCVar3;
  int iVar4;
  CFuncTankLaser *in_stack_ffffff84;
  Vector *in_stack_ffffff8c;
  Vector *in_stack_ffffff90;
  TraceResult *in_stack_ffffff94;
  TraceResult local_54;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TraceResult tr@[???] */
                    /* Unresolved local var: edict_t * pentLaser@[???] */
  if (((this->super_CFuncTank).m_fireLast != 0.0) &&
     ((this->m_pLaser != (CLaser *)0x0 ||
      (pCVar3 = GetLaser(in_stack_ffffff84), pCVar3 != (CLaser *)0x0)))) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: int bulletCount@[???] */
    UTIL_MakeAimVectors(&((this->super_CFuncTank).super_CBaseEntity.pev)->angles);
    iVar2 = (int)((gpGlobals->time - (this->super_CFuncTank).m_fireLast) *
                 (this->super_CFuncTank).m_fireRate);
    if (iVar2 == 0) {
      return;
    }
    if (0 < iVar2) {
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 1;
        peVar1 = (this->m_pLaser->super_CBeam).super_CBaseEntity.pev;
        (peVar1->origin).x = barrelEnd->x;
        (peVar1->origin).y = barrelEnd->y;
        (peVar1->origin).z = barrelEnd->z;
        CFuncTank::TankTrace
                  ((CFuncTank *)(gTankSpread + (this->super_CFuncTank).m_spread),(Vector *)&local_54
                   ,in_stack_ffffff8c,in_stack_ffffff90,in_stack_ffffff94);
        this->m_laserTime = gpGlobals->time;
        CLaser::TurnOn(this->m_pLaser);
        ((this->m_pLaser->super_CBeam).super_CBaseEntity.pev)->dmgtime = gpGlobals->time - 1.0;
        CLaser::FireAtPoint(this->m_pLaser,&local_54);
        ((this->m_pLaser->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
      } while (iVar4 != iVar2);
    }
  }
  CFuncTank::Fire(&this->super_CFuncTank,barrelEnd,forward,
                  (this->super_CFuncTank).super_CBaseEntity.pev);
  return;
}


// func_tankrocket  @ 000d78d0  (line 869)

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
  *puVar1 = &PTR__CFuncTankRocket_0017f6e8;
  puVar1[1] = pev;
  return;
}


// CFuncTankRocket::Precache  @ 000d60b0  (line 872)

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
                    /* WARNING: Could not recover jumptable at 0x000d610b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + sVar2);
  return;
}


// CFuncTankRocket::Fire  @ 000d5110  (line 880)

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
    iVar4 = (int)((gpGlobals->time - fVar1) * (this->super_CFuncTank).m_fireRate);
    if (iVar4 < 1) {
      return;
    }
    iVar3 = 0;
    do {
      peVar2 = (this->super_CFuncTank).super_CBaseEntity.pev;
      iVar3 = iVar3 + 1;
                    /* Unresolved local var: CBaseEntity * pRocket@[???] */
      CBaseEntity::Create("tf_rpg_rocket",barrelEnd,&peVar2->angles,peVar2->pContainingEntity);
    } while (iVar3 != iVar4);
  }
                    /* Unresolved local var: int i@[???] */
  CFuncTank::Fire(&this->super_CFuncTank,barrelEnd,forward,
                  (this->super_CFuncTank).super_CBaseEntity.pev);
  return;
}


// func_tankmortar  @ 000d7940  (line 906)

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
  *puVar1 = &PTR__CFuncTankMortar_0017f808;
  puVar1[1] = pev;
  return;
}


// CFuncTankMortar::KeyValue  @ 000d6150  (line 910)

/* DWARF original prototype: void KeyValue(CFuncTankMortar * this, KeyValueData * pkvd) */

void __thiscall CFuncTankMortar::KeyValue(CFuncTankMortar *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  double dVar8;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 0xb;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "iMagnitude";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    peVar1 = (this->super_CFuncTank).super_CBaseEntity.pev;
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    peVar1->impulse = lVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 8;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "yawrate";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CFuncTank).m_yawRate = (float)dVar8;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 9;
      bVar7 = false;
      pcVar4 = "yawrange";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (!bVar7) {
        CFuncTank::KeyValue(&this->super_CFuncTank,pkvd);
        return;
      }
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CFuncTank).m_yawRange = (float)dVar8;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CFuncTankMortar::Fire  @ 000d5610  (line 922)

/* DWARF original prototype: void Fire(CFuncTankMortar * this, Vector * barrelEnd, Vector * forward,
   entvars_t * pevAttacker) */

void __thiscall
CFuncTankMortar::Fire
          (CFuncTankMortar *this,Vector *barrelEnd,Vector *forward,entvars_t *pevAttacker)

{
  float fVar1;
  entvars_t *peVar2;
  Vector *in_stack_ffffff8c;
  Vector *in_stack_ffffff90;
  TraceResult *in_stack_ffffff94;
  Vector local_44;
  Vector local_30 [3];
  
  fVar1 = (this->super_CFuncTank).m_fireLast;
  if (fVar1 != 0.0) {
                    /* Unresolved local var: int bulletCount@[???] */
    if ((int)((gpGlobals->time - fVar1) * (this->super_CFuncTank).m_fireRate) < 1) {
      return;
    }
                    /* Unresolved local var: int bulletCount@[???]
                       Unresolved local var: TraceResult tr@[???] */
    UTIL_MakeAimVectors(&((this->super_CFuncTank).super_CBaseEntity.pev)->angles);
    CFuncTank::TankTrace
              ((CFuncTank *)(gTankSpread + (this->super_CFuncTank).m_spread),&local_44,
               in_stack_ffffff8c,in_stack_ffffff90,in_stack_ffffff94);
    peVar2 = (this->super_CFuncTank).super_CBaseEntity.pev;
    ExplosionCreate(local_30,&peVar2->angles,peVar2->pContainingEntity,peVar2->impulse,1);
  }
  CFuncTank::Fire(&this->super_CFuncTank,barrelEnd,forward,
                  (this->super_CFuncTank).super_CBaseEntity.pev);
  return;
}


// func_tankcontrols  @ 000d79b0  (line 964)

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
  *puVar1 = &PTR__CFuncTankControls_0017f928;
  puVar1[1] = pev;
  return;
}


// CFuncTankControls::Restore  @ 000d4f90  (line 971)

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


// CFuncTankControls::Save  @ 000d5050  (line 971)

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


// CFuncTankControls::ObjectCaps  @ 000d4a40  (line 976)

/* DWARF original prototype: int ObjectCaps(CFuncTankControls * this) */

int __thiscall CFuncTankControls::ObjectCaps(CFuncTankControls *this)

{
  return 8;
}


// CFuncTankControls::Use  @ 000d4ee0  (line 980)

/* DWARF original prototype: void Use(CFuncTankControls * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTankControls::Use
          (CFuncTankControls *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int iVar1;
  BOOL BVar2;
  
  if (((pActivator == (CBaseEntity *)0x0) ||
      (iVar1 = (*pActivator->_vptr_CBaseEntity[10])(pActivator), iVar1 == 2)) &&
     (BVar2 = ActivationSucceeded(&this->super_CBaseEntity,(CBasePlayer *)pActivator,
                                  (CBaseEntity *)0x0), BVar2 == 0)) {
    return;
  }
  if (this->m_pTank == (CFuncTank *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000d4f59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->m_pTank->super_CBaseEntity)._vptr_CBaseEntity[0x2d])();
  return;
}


// CFuncTankControls::Think  @ 000d4b00  (line 997)

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
  
  bVar7 = 0;
  peVar3 = (edict_t *)0x0;
  pcVar1 = gpGlobals->pStringBase;
  do {
                    /* Unresolved local var: edict_t * pTarget@[???] */
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar3,"targetname",pcVar1 + ((this->super_CBaseEntity).pev)->target);
    if (peVar3 == (edict_t *)0x0) goto LAB_000d4b98;
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
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
    this->m_pTank = peVar3->pvPrivateData;
    return;
  }
LAB_000d4b98:
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"No tank %s\n",
             gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->target);
  return;
}


// CFuncTankControls::Spawn  @ 000d4a50  (line 1015)

/* DWARF original prototype: void Spawn(CFuncTankControls * this) */

void __thiscall CFuncTankControls::Spawn(CFuncTankControls *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  ((this->super_CBaseEntity).pev)->solid = 1;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.3;
  return;
}


