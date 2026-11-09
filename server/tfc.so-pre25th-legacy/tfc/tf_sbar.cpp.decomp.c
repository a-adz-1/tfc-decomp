// Ghidra decompilation of functions from tfc/tf_sbar.cpp
// 3 functions, ordered by original source line

// CBasePlayer::TeamFortress_InitStatusBar  @ 0012f070  (line 40)

/* DWARF original prototype: void TeamFortress_InitStatusBar(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_InitStatusBar(CBasePlayer *this)

{
  this->m_flStatusBarDisappearDelay = 0.0;
  this->m_SbarString2[0] = '\0';
  this->m_SbarString1[0] = '\0';
  this->m_SbarString0[0] = '\0';
  return;
}


// CBasePlayer::GetTeleporter  @ 0012f0a0  (line 46)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CBaseEntity * GetTeleporter(CBasePlayer * this, int type) */

CBaseEntity * __thiscall CBasePlayer::GetTeleporter(CBasePlayer *this,int type)

{
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
      (pStartEntity != (CBaseEntity *)0x0 &&
      ((pCVar1 = EHANDLE::operator->(&pStartEntity->real_owner),
       pCVar1->pev !=
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev || (pStartEntity[1].goal_result != type))));
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_teleporter")) {
  }
  return pStartEntity;
}


// CBasePlayer::TeamFortress_UpdateStatusBar  @ 0012f110  (line 70)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_UpdateStatusBar(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_UpdateStatusBar(CBasePlayer *this)

{
  float fVar1;
  undefined2 uVar2;
  edict_t *peVar3;
  globalvars_t *pgVar4;
  byte *pbVar5;
  CBaseEntity *pCVar6;
  CBasePlayer *pCVar7;
  CBaseEntity *pCVar8;
  CBaseEntity *pCVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  entvars_t *peVar13;
  BOOL BVar14;
  undefined2 *puVar15;
  int iVar16;
  uint *puVar17;
  undefined2 *puVar18;
  uint *puVar19;
  char cVar20;
  char cVar21;
  undefined1 uVar22;
  undefined4 *puVar23;
  uint uVar24;
  char *pcVar25;
  int *piVar26;
  byte *pbVar27;
  uint *puVar28;
  byte *pbVar29;
  uint uVar30;
  bool bVar31;
  bool bVar32;
  bool bVar33;
  byte bVar34;
  ushort in_FPUControlWord;
  float fVar35;
  globalvars_t *local_2f0;
  uint local_2e4;
  undefined8 local_2d4;
  undefined4 local_2cc;
  undefined4 uStack_2c8;
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined2 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined2 local_240;
  undefined1 local_23e;
  uint local_1d0;
  undefined1 local_1cc;
  char local_150 [4];
  undefined1 local_14c [2];
  char acStack_14a [122];
  TraceResult local_d0;
  char local_90 [36];
  int local_6c [6];
  BOOL local_54 [4];
  Vector local_44;
  undefined1 local_38 [12];
  float local_2c;
  float local_28;
  ushort local_20;
  ushort local_1e;
  
  bVar34 = 0;
                    /* Unresolved local var: int[7] newSBarState@[???]
                       Unresolved local var: char[128] sbuf0@[???]
                       Unresolved local var: char[128] sbuf1@[???]
                       Unresolved local var: char[128] sbuf2@[???]
                       Unresolved local var: char[128] temp@[???]
                       Unresolved local var: BOOL bForceResend@[???] */
  uVar10 = 0;
  do {
    uVar11 = uVar10;
    *(undefined4 *)((int)local_6c + uVar11) = 0;
    *(undefined4 *)((int)local_6c + uVar11 + 4) = 0;
    *(undefined4 *)((int)local_6c + uVar11 + 8) = 0;
    *(undefined4 *)((int)local_6c + uVar11 + 0xc) = 0;
    uVar10 = uVar11 + 0x10;
  } while (uVar11 + 0x10 < 0x10);
  *(undefined4 *)((int)local_6c + uVar11 + 0x10) = 0;
  *(undefined4 *)((int)local_54 + (uVar11 - 4)) = 0;
  *(undefined4 *)((int)local_54 + uVar11) = 0;
  local_14c[0] = 0;
  local_2cc = local_2cc & 0xffffff00;
  local_1cc = 0;
  strcpy((char *)&local_24c,this->m_SbarString2);
  if (cb_prematch_time <= gpGlobals->time) {
    fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.respawn_time;
    if (fVar1 <= gpGlobals->time) {
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      local_44.z = (peVar13->v_angle).z + (peVar13->punchangle).z;
      local_44.y = (peVar13->v_angle).y + (peVar13->punchangle).y;
      local_44.x = (peVar13->v_angle).x + (peVar13->punchangle).x;
      UTIL_MakeVectors(&local_44);
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x33])();
      piVar26 = (int *)&stack0xfffffcd0;
      local_28 = (gpGlobals->v_forward).z * 2048.0 + (float)local_38._4_4_;
      local_2c = (gpGlobals->v_forward).y * 2048.0 + (float)local_38._0_4_;
      local_38._8_4_ = (gpGlobals->v_forward).x * 2048.0 + local_44.z;
      UTIL_TraceLine((Vector *)local_38,(Vector *)(local_38 + 8),dont_ignore_monsters,
                     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,&local_d0);
      if (local_d0.flFraction != 1.0) {
        if ((local_d0.pHit == (edict_t *)0x0) ||
           (iVar16 = (*g_engfuncs.pfnEntOffsetOfPEntity)(local_d0.pHit), iVar16 == 0)) {
          local_2f0 = gpGlobals;
          iVar16 = 0;
          if (gpGlobals->time < this->m_flStatusBarDisappearDelay) {
            local_6c[1] = this->m_izSBarState[2];
            local_6c[0] = this->m_izSBarState[1];
            local_6c[2] = this->m_izSBarState[3];
            goto LAB_0012fae3;
          }
LAB_0012fa70:
          gpGlobals = local_2f0;
          if (iVar16 <= local_2f0->maxClients) goto LAB_0012f94e;
        }
        else {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg2(EDX)]
                       Unresolved local var: BOOL bFoundTarget@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          if (local_d0.pHit == (edict_t *)0x0) {
            local_d0.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
            pCVar6 = (CBaseEntity *)0x0;
            if (local_d0.pHit != (edict_t *)0x0) goto LAB_0012f9cf;
          }
          else {
LAB_0012f9cf:
            pCVar6 = (local_d0.pHit)->pvPrivateData;
          }
          iVar16 = (*pCVar6->_vptr_CBaseEntity[10])();
          if (iVar16 == 2) {
            if (((pCVar6->is_feigning != 0) &&
                (BVar14 = CBaseEntity::IsAlly((CBaseEntity *)this,pCVar6), BVar14 == 0)) &&
               (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->iuser1 == 0)) {
              iVar16 = 0;
              local_2f0 = gpGlobals;
              goto LAB_0012fa70;
            }
            BVar14 = CBaseEntity::IsAlly((CBaseEntity *)this,pCVar6);
            if (BVar14 == 0) {
              fVar1 = ((float)local_38._4_4_ - local_d0.vecEndPos.z) *
                      ((float)local_38._4_4_ - local_d0.vecEndPos.z) +
                      ((float)local_38._0_4_ - local_d0.vecEndPos.y) *
                      ((float)local_38._0_4_ - local_d0.vecEndPos.y) +
                      (local_44.z - local_d0.vecEndPos.x) * (local_44.z - local_d0.vecEndPos.x);
              fVar35 = SQRT(fVar1);
              if (NAN(fVar35)) {
                fVar35 = sqrtf(fVar1);
              }
              if (fVar35 <= 1024.0) goto LAB_00130547;
              if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0) goto LAB_0012fae3;
            }
            else {
LAB_00130547:
              if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0) &&
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no != 0)) {
                iVar16 = EHANDLE::operator_int(&pCVar6->undercover_target);
                if ((iVar16 != 0) &&
                   (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no != pCVar6->team_no &&
                    (pCVar6->pev->playerclass == 8)))) {
                  pCVar6 = EHANDLE::operator_CBaseEntity_(&pCVar6->undercover_target);
                }
              }
            }
            if ((tfc_playerid.value == 2.0) ||
               (((tfc_playerid.value == 1.0 &&
                 (BVar14 = CBaseEntity::IsAlly((CBaseEntity *)this,pCVar6), BVar14 == 0)) &&
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->iuser1 == 0)))) {
              local_250 = 0x20;
            }
            else {
              uVar10 = 0;
              do {
                uVar11 = uVar10;
                *(undefined4 *)((int)&local_24c + uVar11) =
                     *(undefined4 *)("1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%" + uVar11);
                uVar10 = uVar11 + 4;
              } while (uVar10 < 0x28);
              *(char *)((int)&local_24c + uVar10) =
                   "1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%"[uVar11 + 4];
            }
            local_6c[0] = (*g_engfuncs.pfnIndexOfEdict)(pCVar6->pev->pContainingEntity);
            EHANDLE::operator=(&this->m_hLastIDTarget,pCVar6);
          }
          else {
            local_2f0 = gpGlobals;
            uVar10 = pCVar6->pev->classname;
            iVar16 = 0x13;
            bVar32 = CARRY4((uint)gpGlobals->pStringBase,uVar10);
            pbVar5 = (byte *)(gpGlobals->pStringBase + uVar10);
            bVar33 = pbVar5 == (byte *)0x0;
            pbVar27 = pbVar5;
            pbVar29 = (byte *)"building_sentrygun";
            do {
              if (iVar16 == 0) break;
              iVar16 = iVar16 + -1;
              bVar32 = *pbVar27 < *pbVar29;
              bVar33 = *pbVar27 == *pbVar29;
              pbVar27 = pbVar27 + (uint)bVar34 * -2 + 1;
              pbVar29 = pbVar29 + (uint)bVar34 * -2 + 1;
            } while (bVar33);
            bVar31 = (!bVar32 && !bVar33) < bVar32;
            if ((!bVar32 && !bVar33) == bVar32) {
              pCVar8 = EHANDLE::operator->(&pCVar6->real_owner);
              local_6c[0] = (*g_engfuncs.pfnIndexOfEdict)(pCVar8->pev->pContainingEntity);
              if ((tfc_playerid.value == 2.0) ||
                 (((tfc_playerid.value == 1.0 &&
                   (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0)) &&
                  (BVar14 = CBaseEntity::IsAlly((CBaseEntity *)this,pCVar6), BVar14 == 0)))) {
LAB_001306ec:
                local_250 = 0x20;
              }
              else {
                uVar10 = 0;
                do {
                  uVar11 = uVar10;
                  *(undefined4 *)((int)&local_24c + uVar11) =
                       *(undefined4 *)
                        ("1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%" + uVar11)
                  ;
                  uVar10 = uVar11 + 4;
                } while (uVar10 < 0x3c);
                *(short *)((int)&local_24c + uVar10) =
                     (short)*(undefined4 *)
                             ("1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%" +
                             uVar11 + 4);
              }
            }
            else {
              iVar16 = 0x13;
              bVar32 = false;
              pbVar27 = pbVar5;
              pbVar29 = (byte *)"building_dispenser";
              do {
                if (iVar16 == 0) break;
                iVar16 = iVar16 + -1;
                bVar31 = *pbVar27 < *pbVar29;
                bVar32 = *pbVar27 == *pbVar29;
                pbVar27 = pbVar27 + (uint)bVar34 * -2 + 1;
                pbVar29 = pbVar29 + (uint)bVar34 * -2 + 1;
              } while (bVar32);
              bVar33 = (!bVar31 && !bVar32) < bVar31;
              if ((!bVar31 && !bVar32) == bVar31) {
                pCVar8 = EHANDLE::operator->(&pCVar6->real_owner);
                local_6c[0] = (*g_engfuncs.pfnIndexOfEdict)(pCVar8->pev->pContainingEntity);
                if ((tfc_playerid.value == 2.0) ||
                   (((tfc_playerid.value == 1.0 &&
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0)) &&
                    (BVar14 = CBaseEntity::IsAlly((CBaseEntity *)this,pCVar6), BVar14 == 0))))
                goto LAB_001306ec;
                uVar10 = 0;
                do {
                  uVar11 = uVar10;
                  *(undefined4 *)((int)&local_24c + uVar11) =
                       *(undefined4 *)
                        ("1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%" + uVar11);
                  uVar10 = uVar11 + 4;
                } while (uVar10 < 0x3c);
                *(char *)((int)&local_24c + uVar10) =
                     "1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"[uVar11 + 4];
              }
              else {
                iVar16 = 0x14;
                bVar32 = false;
                pbVar27 = (byte *)"building_teleporter";
                do {
                  if (iVar16 == 0) break;
                  iVar16 = iVar16 + -1;
                  bVar33 = *pbVar5 < *pbVar27;
                  bVar32 = *pbVar5 == *pbVar27;
                  pbVar5 = pbVar5 + (uint)bVar34 * -2 + 1;
                  pbVar27 = pbVar27 + (uint)bVar34 * -2 + 1;
                } while (bVar32);
                iVar16 = 0;
                if ((!bVar33 && !bVar32) != bVar33) goto LAB_0012fa70;
                pCVar8 = EHANDLE::operator->(&pCVar6->real_owner);
                local_6c[0] = (*g_engfuncs.pfnIndexOfEdict)(pCVar8->pev->pContainingEntity);
                if ((tfc_playerid.value == 2.0) ||
                   (((tfc_playerid.value == 1.0 &&
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0)) &&
                    (BVar14 = CBaseEntity::IsAlly((CBaseEntity *)this,pCVar6), BVar14 == 0))))
                goto LAB_001306ec;
                uVar10 = 0;
                if (pCVar6[1].goal_result == 4) {
                  uVar10 = 0;
                  do {
                    uVar11 = uVar10;
                    *(undefined4 *)((int)&local_24c + uVar11) =
                         *(undefined4 *)
                          (
                          "1 Teleporter entrance built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                          + uVar11);
                    uVar10 = uVar11 + 4;
                  } while (uVar10 < 0x44);
                  *(short *)((int)&local_24c + uVar10) =
                       (short)*(undefined4 *)
                               (
                               "1 Teleporter entrance built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                               + uVar11 + 4);
                  *(char *)((int)&local_248 + uVar11 + 2) =
                       "1 Teleporter entrance built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                       [uVar11 + 6];
                }
                else {
                  do {
                    uVar11 = uVar10;
                    *(undefined4 *)((int)&local_24c + uVar11) =
                         *(undefined4 *)
                          ("1 Teleporter exit built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%" +
                          uVar11);
                    uVar10 = uVar11 + 4;
                  } while (uVar10 < 0x40);
                  *(short *)((int)&local_24c + uVar10) =
                       (short)*(undefined4 *)
                               (
                               "1 Teleporter exit built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                               + uVar11 + 4);
                  *(char *)((int)&local_248 + uVar11 + 2) =
                       "1 Teleporter exit built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                       [uVar11 + 6];
                }
              }
            }
          }
          BVar14 = CBaseEntity::IsAlly((CBaseEntity *)this,pCVar6);
          if (((BVar14 != 0) ||
              (peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev, peVar13->playerclass == 5)) ||
             (peVar13->iuser1 != 0)) {
            peVar13 = pCVar6->pev;
            local_6c[1] = (int)((peVar13->health / peVar13->max_health) * 100.0);
            local_6c[2] = (int)((peVar13->armorvalue / pCVar6->maxarmor) * 100.0);
          }
          this->m_flStatusBarDisappearDelay = gpGlobals->time + 1.0;
LAB_0012fae3:
          if (-1 < local_6c[0]) {
            local_2f0 = gpGlobals;
            iVar16 = local_6c[0];
            goto LAB_0012fa70;
          }
        }
        printf("ERROR: SBAR_ID_TARGETNAME = %d\n");
        local_6c[0] = 0;
      }
LAB_0012f94e:
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      iVar16 = peVar13->playerclass;
      if (iVar16 == 8) {
        iVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.undercover_team;
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.is_undercover == 0) {
          if (iVar16 != 0) goto LAB_00130448;
          iVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.undercover_skin;
          if (iVar16 == 0) {
LAB_0012fe37:
            fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.respawn_time;
            goto LAB_0012f344;
          }
LAB_001303b6:
          local_2d4 = (double)CONCAT44(0x79705323,(undefined4)local_2d4);
          local_2cc = 0x7369645f;
          uStack_2c8 = 0x73697567;
          local_2c4 = CONCAT13(local_2c4._3_1_,0x6465);
LAB_001303e5:
          local_2f0 = (globalvars_t *)((int)&local_2d4 + 4);
          do {
            puVar19 = (uint *)local_2f0;
            uVar10 = *puVar19 + 0xfefefeff & ~*puVar19;
            uVar11 = uVar10 & 0x80808080;
            local_2f0 = (globalvars_t *)(puVar19 + 1);
          } while (uVar11 == 0);
          uVar24 = uVar11 >> 0x10;
          puVar17 = (uint *)((int)puVar19 + 6);
          if ((uVar10 & 0x8080) != 0) {
            puVar17 = puVar19 + 1;
            uVar24 = uVar11;
          }
          puVar15 = (undefined2 *)((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar24,(byte)uVar24)));
          *puVar15 = 0x2320;
          *(undefined1 *)(puVar15 + 1) = 0;
          pcVar12 = sClassNames[iVar16];
        }
        else {
          if (iVar16 == 0) {
            iVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.undercover_skin;
            if (iVar16 == 0) {
              local_2cc = 0x7369645f;
              uStack_2c8 = 0x73697567;
              local_2d4 = (double)CONCAT44(0x79705323,(undefined4)local_2d4);
              local_2c4 = 0x676e69;
              goto LAB_0012fe37;
            }
            goto LAB_001303b6;
          }
LAB_00130448:
          local_2d4 = (double)CONCAT44(0x79705323,(undefined4)local_2d4);
          puVar19 = (uint *)((int)&local_2d4 + 4);
          local_2cc = 0x7369645f;
          uStack_2c8 = 0x73697567;
          local_2c4 = CONCAT13(local_2c4._3_1_,0x6465);
          puVar17 = puVar19;
          do {
            puVar28 = puVar17;
            uVar10 = *puVar28 + 0xfefefeff & ~*puVar28;
            uVar11 = uVar10 & 0x80808080;
            puVar17 = puVar28 + 1;
          } while (uVar11 == 0);
          uVar24 = uVar11 >> 0x10;
          puVar17 = (uint *)((int)puVar28 + 6);
          if ((uVar10 & 0x8080) != 0) {
            puVar17 = puVar28 + 1;
            uVar24 = uVar11;
          }
          pcVar12 = (char *)((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar24,(byte)uVar24)));
          pcVar12[0] = ' ';
          pcVar12[1] = '\0';
          pcVar12 = GetTeamName(iVar16);
          strcat((char *)puVar19,pcVar12);
          iVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.undercover_skin;
          if (iVar16 != 0) goto LAB_001303e5;
          do {
            puVar17 = puVar19;
            uVar11 = *puVar17 + 0xfefefeff & ~*puVar17;
            uVar10 = uVar11 & 0x80808080;
            puVar19 = puVar17 + 1;
          } while (uVar10 == 0);
          if ((uVar11 & 0x8080) == 0) {
            puVar19 = (uint *)((int)puVar17 + 6);
            uVar10 = uVar10 >> 0x10;
          }
          pcVar12 = (char *)((int)puVar19 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
          pcVar12[0] = ' ';
          pcVar12[1] = '#';
          pcVar12[2] = '\0';
          pcVar12 = sClassNames[8];
        }
        local_2f0 = (globalvars_t *)((int)&local_2d4 + 4);
        strcat((char *)local_2f0,pcVar12);
        peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        iVar16 = peVar13->playerclass;
      }
      local_2f0 = (globalvars_t *)((int)&local_2d4 + 4);
      if (iVar16 == 9) {
        fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.has_sentry;
        if (fVar1 == 0.0) {
          fVar35 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.has_entry_teleporter;
          if ((fVar35 != 0.0) ||
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.has_exit_teleporter != 0.0)) {
            if (fVar1 != 0.0) goto LAB_0012fb30;
            goto LAB_0012fee2;
          }
        }
        else {
LAB_0012fb30:
                    /* Unresolved local var: CBaseEntity * te@[???] */
          for (pCVar6 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun");
              pCVar6 != (CBaseEntity *)0x0;
              pCVar6 = UTIL_FindEntityByClassname(pCVar6,"building_sentrygun")) {
            pCVar7 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar6->real_owner);
            if (this == pCVar7) {
                    /* Unresolved local var: int health@[???] */
              sprintf((char *)local_2f0,"#Sentry_sbar %d");
              pgVar4 = local_2f0;
              do {
                puVar19 = (uint *)pgVar4;
                uVar10 = *puVar19 + 0xfefefeff & ~*puVar19;
                uVar11 = uVar10 & 0x80808080;
                pgVar4 = (globalvars_t *)(puVar19 + 1);
              } while (uVar11 == 0);
              uVar30 = 0x13;
              uVar24 = uVar11 >> 0x10;
              puVar17 = (uint *)((int)puVar19 + 6);
              if ((uVar10 & 0x8080) != 0) {
                puVar17 = puVar19 + 1;
                uVar24 = uVar11;
              }
              puVar18 = (undefined2 *)
                        ((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar24,(byte)uVar24)));
              puVar23 = &DAT_0018ece0;
              bVar32 = ((uint)puVar18 & 1) != 0;
              puVar15 = puVar18;
              if (bVar32) {
                puVar15 = (undefined2 *)((int)puVar18 + 1);
                uVar30 = 0x12;
                *(undefined1 *)puVar18 = 0x25;
                puVar23 = (undefined4 *)((int)&DAT_0018ece0 + 1);
              }
              if (((uint)puVar15 & 2) != 0) {
                uVar2 = *(undefined2 *)puVar23;
                uVar30 = uVar30 - 2;
                puVar23 = (undefined4 *)((int)puVar23 + 2);
                *puVar15 = uVar2;
                puVar15 = puVar15 + 1;
              }
              uVar10 = 0;
              do {
                *(undefined4 *)((int)puVar15 + uVar10) = *(undefined4 *)((int)puVar23 + uVar10);
                uVar10 = uVar10 + 4;
              } while (uVar10 < (uVar30 & 0xfffffffc));
              iVar16 = 0;
              if ((uVar30 & 2) != 0) {
                *(undefined2 *)((int)puVar15 + uVar10) = *(undefined2 *)((int)puVar23 + uVar10);
                iVar16 = 2;
              }
              if (!bVar32) {
                *(undefined1 *)((int)((int)puVar15 + uVar10) + iVar16) =
                     *(undefined1 *)((int)((int)puVar23 + uVar10) + iVar16);
              }
              pgVar4 = local_2f0;
              if (pCVar6->ammo_shells == 0) {
                do {
                  puVar19 = (uint *)pgVar4;
                  uVar11 = *puVar19 + 0xfefefeff & ~*puVar19;
                  uVar10 = uVar11 & 0x80808080;
                  pgVar4 = (globalvars_t *)(puVar19 + 1);
                } while (uVar10 == 0);
                puVar17 = puVar19 + 1;
                if ((uVar11 & 0x8080) == 0) {
                  puVar17 = (uint *)((int)puVar19 + 6);
                  uVar10 = uVar10 >> 0x10;
                }
                *(undefined2 *)((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))) =
                     0x20;
                pgVar4 = local_2f0;
                if ((pCVar6->ammo_rockets == 0) && (pCVar6->weapon == 3)) {
                  do {
                    puVar19 = (uint *)pgVar4;
                    uVar11 = *puVar19 + 0xfefefeff & ~*puVar19;
                    uVar10 = uVar11 & 0x80808080;
                    pgVar4 = (globalvars_t *)(puVar19 + 1);
                  } while (uVar10 == 0);
                  puVar17 = puVar19 + 1;
                  if ((uVar11 & 0x8080) == 0) {
                    puVar17 = (uint *)((int)puVar19 + 6);
                    uVar10 = uVar10 >> 0x10;
                  }
                  puVar23 = (undefined4 *)
                            ((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
                  *puVar23 = 0x5f6f4e23;
                  puVar23[1] = 0x6f6d6d41;
                  *(undefined1 *)(puVar23 + 2) = 0;
                }
                else {
                  do {
                    puVar19 = (uint *)pgVar4;
                    uVar11 = *puVar19 + 0xfefefeff & ~*puVar19;
                    uVar10 = uVar11 & 0x80808080;
                    pgVar4 = (globalvars_t *)(puVar19 + 1);
                  } while (uVar10 == 0);
                  puVar17 = puVar19 + 1;
                  if ((uVar11 & 0x8080) == 0) {
                    puVar17 = (uint *)((int)puVar19 + 6);
                    uVar10 = uVar10 >> 0x10;
                  }
                  puVar23 = (undefined4 *)
                            ((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
                  *puVar23 = 0x5f6f4e23;
                  puVar23[1] = 0x6c656853;
                  *(undefined2 *)(puVar23 + 2) = 0x736c;
                  *(undefined1 *)((int)puVar23 + 10) = 0;
                }
              }
              else {
                local_6c[3] = (int)(((float)pCVar6->ammo_shells / (float)pCVar6->maxammo_shells) *
                                   100.0);
                if ((pCVar6->ammo_rockets == 0) && (pCVar6->weapon == 3)) {
                  do {
                    puVar19 = (uint *)pgVar4;
                    uVar11 = *puVar19 + 0xfefefeff & ~*puVar19;
                    uVar10 = uVar11 & 0x80808080;
                    pgVar4 = (globalvars_t *)(puVar19 + 1);
                  } while (uVar10 == 0);
                  puVar17 = puVar19 + 1;
                  if ((uVar11 & 0x8080) == 0) {
                    puVar17 = (uint *)((int)puVar19 + 6);
                    uVar10 = uVar10 >> 0x10;
                  }
                  *(undefined2 *)((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))) =
                       0x20;
                  pgVar4 = local_2f0;
                  do {
                    puVar19 = (uint *)pgVar4;
                    uVar11 = *puVar19 + 0xfefefeff & ~*puVar19;
                    uVar10 = uVar11 & 0x80808080;
                    pgVar4 = (globalvars_t *)(puVar19 + 1);
                  } while (uVar10 == 0);
                  puVar17 = puVar19 + 1;
                  if ((uVar11 & 0x8080) == 0) {
                    puVar17 = (uint *)((int)puVar19 + 6);
                    uVar10 = uVar10 >> 0x10;
                  }
                  puVar23 = (undefined4 *)
                            ((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
                  *puVar23 = 0x5f6f4e23;
                  puVar23[1] = 0x6b636f52;
                  puVar23[2] = 0x737465;
                }
              }
            }
          }
          fVar35 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.has_entry_teleporter;
LAB_0012fee2:
          if ((fVar35 != 0.0) ||
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.has_exit_teleporter != 0.0)) {
                    /* Unresolved local var: char[32] szTemp@[???]
                       Unresolved local var: int iEntryHealth@[???]
                       Unresolved local var: int iExitHealth@[???]
                       Unresolved local var: CTFTeleporter * pEntry@[DW_OP_reg7(EDI)]
                       Unresolved local var: CTFTeleporter * pExit@[DW_OP_reg6(ESI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
            for (pCVar6 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
                (pCVar6 != (CBaseEntity *)0x0 &&
                ((pCVar8 = EHANDLE::operator->(&pCVar6->real_owner),
                 pCVar8->pev !=
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev || (pCVar6[1].goal_result != 4))));
                pCVar6 = UTIL_FindEntityByClassname(pCVar6,"building_teleporter")) {
            }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            for (pCVar8 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
                (pCVar8 != (CBaseEntity *)0x0 &&
                ((pCVar9 = EHANDLE::operator->(&pCVar8->real_owner),
                 pCVar9->pev !=
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev || (pCVar8[1].goal_result != 5))));
                pCVar8 = UTIL_FindEntityByClassname(pCVar8,"building_teleporter")) {
            }
            if (pCVar6 != (CBaseEntity *)0x0) {
              puVar19 = &local_1d0;
              do {
                puVar17 = puVar19;
                uVar10 = *puVar17 + 0xfefefeff & ~*puVar17;
                uVar11 = uVar10 & 0x80808080;
                puVar19 = puVar17 + 1;
              } while (uVar11 == 0);
              uVar24 = uVar11 >> 0x10;
              puVar19 = (uint *)((int)puVar17 + 6);
              if ((uVar10 & 0x8080) != 0) {
                puVar19 = puVar17 + 1;
                uVar24 = uVar11;
              }
              pcVar25 = (char *)((int)puVar19 + (-3 - (uint)CARRY1((byte)uVar24,(byte)uVar24)));
              bVar32 = ((uint)pcVar25 & 1) != 0;
              pcVar12 = "#Teleporter_entry_sbar ";
              local_2e4 = 0x18;
              if (bVar32) {
                *pcVar25 = '#';
                pcVar25 = pcVar25 + 1;
                pcVar12 = "Teleporter_entry_sbar ";
                local_2e4 = 0x17;
              }
              if (((uint)pcVar25 & 2) != 0) {
                uVar2 = *(undefined2 *)pcVar12;
                pcVar12 = pcVar12 + 2;
                *(undefined2 *)pcVar25 = uVar2;
                pcVar25 = pcVar25 + 2;
                local_2e4 = local_2e4 - 2;
              }
              uVar10 = 0;
              do {
                *(undefined4 *)(pcVar25 + uVar10) = *(undefined4 *)(pcVar12 + uVar10);
                uVar10 = uVar10 + 4;
              } while (uVar10 < (local_2e4 & 0xfffffffc));
              iVar16 = 0;
              if ((local_2e4 & 2) != 0) {
                *(undefined2 *)(pcVar25 + uVar10) = *(undefined2 *)(pcVar12 + uVar10);
                iVar16 = 2;
              }
              if (bVar32) {
                (pcVar25 + uVar10)[iVar16] = (pcVar12 + uVar10)[iVar16];
              }
              sprintf(local_90,"%d");
              strncat((char *)&local_1d0,local_90,0x7f);
              puVar19 = &local_1d0;
              do {
                puVar17 = puVar19;
                uVar10 = *puVar17 + 0xfefefeff & ~*puVar17;
                uVar11 = uVar10 & 0x80808080;
                puVar19 = puVar17 + 1;
              } while (uVar11 == 0);
              uVar24 = uVar11 >> 0x10;
              puVar19 = (uint *)((int)puVar17 + 6);
              if ((uVar10 & 0x8080) != 0) {
                puVar19 = puVar17 + 1;
                uVar24 = uVar11;
              }
              builtin_strncpy((char *)((int)puVar19 + (-3 - (uint)CARRY1((byte)uVar24,(byte)uVar24))
                                      ),"%%\n0",5);
            }
            if (pCVar8 != (CBaseEntity *)0x0) {
              puVar19 = &local_1d0;
              if ((char)local_1d0 != '\0') {
                do {
                  puVar17 = puVar19;
                  uVar10 = *puVar17 + 0xfefefeff & ~*puVar17;
                  uVar11 = uVar10 & 0x80808080;
                  puVar19 = puVar17 + 1;
                } while (uVar11 == 0);
                uVar24 = uVar11 >> 0x10;
                puVar19 = (uint *)((int)puVar17 + 6);
                if ((uVar10 & 0x8080) != 0) {
                  puVar19 = puVar17 + 1;
                  uVar24 = uVar11;
                }
                builtin_strncpy((char *)((int)puVar19 +
                                        (-3 - (uint)CARRY1((byte)uVar24,(byte)uVar24))),"   ",4);
                puVar19 = &local_1d0;
              }
              do {
                puVar17 = puVar19;
                uVar10 = *puVar17 + 0xfefefeff & ~*puVar17;
                uVar11 = uVar10 & 0x80808080;
                puVar19 = puVar17 + 1;
              } while (uVar11 == 0);
              uVar30 = 0x17;
              uVar24 = uVar11 >> 0x10;
              puVar19 = (uint *)((int)puVar17 + 6);
              if ((uVar10 & 0x8080) != 0) {
                puVar19 = puVar17 + 1;
                uVar24 = uVar11;
              }
              pcVar25 = (char *)((int)puVar19 + (-3 - (uint)CARRY1((byte)uVar24,(byte)uVar24)));
              pcVar12 = "#Teleporter_exit_sbar ";
              bVar32 = ((uint)pcVar25 & 1) != 0;
              if (bVar32) {
                uVar30 = 0x16;
                *pcVar25 = '#';
                pcVar25 = pcVar25 + 1;
                pcVar12 = "Teleporter_exit_sbar ";
              }
              if (((uint)pcVar25 & 2) != 0) {
                uVar2 = *(undefined2 *)pcVar12;
                uVar30 = uVar30 - 2;
                pcVar12 = pcVar12 + 2;
                *(undefined2 *)pcVar25 = uVar2;
                pcVar25 = pcVar25 + 2;
              }
              uVar10 = 0;
              do {
                *(undefined4 *)(pcVar25 + uVar10) = *(undefined4 *)(pcVar12 + uVar10);
                uVar10 = uVar10 + 4;
              } while (uVar10 < (uVar30 & 0xfffffffc));
              iVar16 = 0;
              if ((uVar30 & 2) != 0) {
                *(undefined2 *)(pcVar25 + uVar10) = *(undefined2 *)(pcVar12 + uVar10);
                iVar16 = 2;
              }
              if (!bVar32) {
                (pcVar25 + uVar10)[iVar16] = (pcVar12 + uVar10)[iVar16];
              }
              sprintf(local_90,"%d");
              strncat((char *)&local_1d0,local_90,0x7f);
              puVar19 = &local_1d0;
              do {
                puVar17 = puVar19;
                uVar11 = *puVar17 + 0xfefefeff & ~*puVar17;
                uVar10 = uVar11 & 0x80808080;
                puVar19 = puVar17 + 1;
              } while (uVar10 == 0);
              if ((uVar11 & 0x8080) == 0) {
                puVar19 = (uint *)((int)puVar17 + 6);
                uVar10 = uVar10 >> 0x10;
              }
              builtin_strncpy((char *)((int)puVar19 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))
                                      ),"%%\n0",5);
            }
          }
          if ((char)local_1d0 != '\0') {
            if (local_2d4._4_1_ != '\0') {
              strcpy(local_150,(char *)&local_1d0);
              peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev;
              goto LAB_001302b0;
            }
            strcpy((char *)local_2f0,(char *)&local_1d0);
          }
          peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
        }
LAB_001302b0:
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.is_building != 0) {
          uVar10 = 0;
          if (local_2d4._4_1_ != '\0') {
            do {
              uVar11 = uVar10;
              *(undefined4 *)(local_150 + uVar11) = *(undefined4 *)("#Engineer_building" + uVar11);
              uVar10 = uVar11 + 4;
            } while (uVar11 + 4 < 0x10);
            *(undefined2 *)(local_14c + uVar11) = *(undefined2 *)("#Engineer_building" + uVar11 + 4)
            ;
            local_14c[uVar11 + 2] = "#Engineer_building"[uVar11 + 6];
            iVar16 = peVar13->playerclass;
            goto LAB_0012f97c;
          }
          do {
            uVar11 = uVar10;
            *(undefined4 *)((int)local_2f0 + uVar11) =
                 *(undefined4 *)("#Engineer_building" + uVar11);
            uVar10 = uVar11 + 4;
          } while (uVar10 < 0x10);
          *(undefined2 *)((int)local_2f0 + uVar10) =
               *(undefined2 *)("#Engineer_building" + uVar11 + 4);
          *(char *)((int)&local_2cc + uVar11 + 2) = "#Engineer_building"[uVar11 + 6];
        }
        iVar16 = peVar13->playerclass;
      }
LAB_0012f97c:
      if ((iVar16 == 4) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_detpacking != 0)) {
        local_2d4 = (double)CONCAT44(0x6d654423,(undefined4)local_2d4);
        local_2cc = 0x6e616d6f;
        uStack_2c8 = 0x7465645f;
        local_2c4 = 0x6b636170;
        local_2c0 = 0x676e69;
      }
      fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.respawn_time;
      piVar26 = (int *)&stack0xfffffcd0;
      goto LAB_0012f344;
    }
    local_24c = 0x61625323;
    local_248 = 0x65645f72;
    local_244 = CONCAT13(local_244._3_1_,0x6461);
    fVar35 = fVar1;
  }
  else {
                    /* Unresolved local var: float flTimeToCheck@[???]
                       Unresolved local var: int iSecondsLeft@[???]
                       Unresolved local var: int iMinutesLeft@[???] */
    local_248 = 0x72705f72;
    local_244 = 0x74616d65;
    local_240 = 0x6863;
    local_24c = 0x61625323;
    local_23e = 0;
    if (tfc_clanbattle.value != 0.0) {
      local_2cc = 0x61625323;
      uStack_2c8 = 0x61625f72;
      local_2c4 = 0x656c7474;
      local_2c0 = CONCAT13(local_2c0._3_1_,0x6469);
      local_6c[5] = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tf_id;
    }
    fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.respawn_time;
    local_54[0] = cease_fire;
    fVar35 = cb_prematch_time;
  }
  local_24c = 0x61625323;
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  iVar16 = (int)ROUND(fVar35 - gpGlobals->time) % 0x3c;
  if (iVar16 == 1) {
    local_6c[3] = 1;
  }
  else {
    local_6c[1] = iVar16;
  }
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  local_1e = in_FPUControlWord;
  local_20 = in_FPUControlWord & 0xf3ff | 0x800;
  local_2d4 = (double)ROUND(fVar35 - gpGlobals->time);
  if ((int)(local_2d4 / 60.0) == 1) {
    local_6c[4] = 1;
    piVar26 = (int *)&stack0xfffffcd4;
  }
  else {
    local_6c[2] = (int)(local_2d4 / 60.0);
    piVar26 = (int *)&stack0xfffffcd4;
  }
LAB_0012f344:
  if ((fVar1 != 0.0) && (bVar32 = gpGlobals->time == fVar1, fVar1 < gpGlobals->time)) {
    iVar16 = 0xb;
    pcVar12 = (char *)&local_24c;
    pcVar25 = "#Sbar_dead";
    do {
      if (iVar16 == 0) break;
      iVar16 = iVar16 + -1;
      bVar32 = *pcVar12 == *pcVar25;
      pcVar12 = pcVar12 + (uint)bVar34 * -2 + 1;
      pcVar25 = pcVar25 + (uint)bVar34 * -2 + 1;
    } while (bVar32);
    if (bVar32) {
      *(undefined1 *)(piVar26 + 0x38) = 0;
    }
  }
  piVar26[1] = (int)this->m_SbarString0;
  *piVar26 = piVar26[0x12];
  piVar26[-1] = 0x12f390;
  iVar16 = strcmp((char *)*piVar26,(char *)piVar26[1]);
  if (iVar16 != 0) {
    peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    piVar26[2] = 0;
    *piVar26 = 1;
    piVar26[3] = (int)peVar3;
    piVar26[1] = gmsgStatusText;
    piVar26[-1] = 0x12f7f9;
    (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
    *piVar26 = 0;
    piVar26[-1] = 0x12f806;
    (*g_engfuncs.pfnWriteByte)(*piVar26);
    *piVar26 = piVar26[0x12];
    piVar26[-1] = 0x12f813;
    (*g_engfuncs.pfnWriteString)((char *)*piVar26);
    piVar26[-1] = 0x12f819;
    (*g_engfuncs.pfnMessageEnd)();
    *piVar26 = (int)this->m_SbarString0;
    piVar26[1] = piVar26[0x12];
    piVar26[-1] = 0x12f829;
    strcpy((char *)*piVar26,(char *)piVar26[1]);
  }
  piVar26[1] = (int)this->m_SbarString1;
  *(bool *)(piVar26 + 0xf) = iVar16 != 0;
  *piVar26 = piVar26[0x10];
  piVar26[-1] = 0x12f3b4;
  iVar16 = strcmp((char *)*piVar26,(char *)piVar26[1]);
  uVar22 = (undefined1)piVar26[0xf];
  if (iVar16 != 0) {
    peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    piVar26[2] = 0;
    *piVar26 = 1;
    piVar26[3] = (int)peVar3;
    piVar26[1] = gmsgStatusText;
    piVar26[-1] = 0x12f799;
    (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
    *piVar26 = 1;
    piVar26[-1] = 0x12f7a6;
    (*g_engfuncs.pfnWriteByte)(*piVar26);
    *piVar26 = piVar26[0x10];
    piVar26[-1] = 0x12f7b3;
    (*g_engfuncs.pfnWriteString)((char *)*piVar26);
    piVar26[-1] = 0x12f7b9;
    (*g_engfuncs.pfnMessageEnd)();
    *piVar26 = (int)this->m_SbarString1;
    piVar26[1] = piVar26[0x10];
    piVar26[-1] = 0x12f7c9;
    strcpy((char *)*piVar26,(char *)piVar26[1]);
    uVar22 = 1;
  }
  *piVar26 = (int)&local_24c;
  *(undefined1 *)(piVar26 + 0xf) = uVar22;
  piVar26[1] = piVar26[0x11];
  piVar26[-1] = 0x12f3d5;
  iVar16 = strcmp((char *)*piVar26,(char *)piVar26[1]);
  cVar20 = (char)piVar26[0xf];
  if (iVar16 != 0) {
    peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    *piVar26 = 1;
    piVar26[3] = (int)peVar3;
    piVar26[2] = 0;
    piVar26[1] = gmsgStatusText;
    piVar26[-1] = 0x12f739;
    (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
    *piVar26 = 2;
    piVar26[-1] = 0x12f746;
    (*g_engfuncs.pfnWriteByte)(*piVar26);
    *piVar26 = (int)&local_24c;
    piVar26[-1] = 0x12f74f;
    (*g_engfuncs.pfnWriteString)((char *)*piVar26);
    piVar26[-1] = 0x12f755;
    (*g_engfuncs.pfnMessageEnd)();
    piVar26[1] = (int)&local_24c;
    *piVar26 = piVar26[0x11];
    piVar26[-1] = 0x12f765;
    strcpy((char *)*piVar26,(char *)piVar26[1]);
    cVar20 = '\x01';
  }
                    /* Unresolved local var: int i@[???] */
  iVar16 = piVar26[0xb1];
  if ((cVar20 != '\0') || (cVar21 = '\0', iVar16 != this->m_izSBarState[1])) {
    peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    *(char *)(piVar26 + 0xf) = cVar20;
    *piVar26 = 1;
    piVar26[3] = (int)peVar3;
    piVar26[2] = 0;
    piVar26[1] = gmsgStatusValue;
    piVar26[-1] = 0x12f6dd;
    (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
    *piVar26 = 1;
    piVar26[-1] = 0x12f6ea;
    (*g_engfuncs.pfnWriteByte)(*piVar26);
    *piVar26 = iVar16;
    piVar26[-1] = 0x12f6f3;
    (*g_engfuncs.pfnWriteShort)(*piVar26);
    piVar26[-1] = 0x12f6f9;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_izSBarState[1] = iVar16;
    cVar21 = (char)piVar26[0xf];
  }
  iVar16 = piVar26[0xb2];
  if ((cVar21 != '\0') || (cVar20 = '\0', iVar16 != this->m_izSBarState[2])) {
    peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    *(char *)(piVar26 + 0xf) = cVar21;
    *piVar26 = 1;
    piVar26[3] = (int)peVar3;
    piVar26[2] = 0;
    piVar26[1] = gmsgStatusValue;
    piVar26[-1] = 0x12f67d;
    (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
    *piVar26 = 2;
    piVar26[-1] = 0x12f68a;
    (*g_engfuncs.pfnWriteByte)(*piVar26);
    *piVar26 = iVar16;
    piVar26[-1] = 0x12f693;
    (*g_engfuncs.pfnWriteShort)(*piVar26);
    piVar26[-1] = 0x12f699;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_izSBarState[2] = iVar16;
    cVar20 = (char)piVar26[0xf];
  }
  iVar16 = piVar26[0xb3];
  if ((cVar20 != '\0') || (cVar21 = '\0', iVar16 != this->m_izSBarState[3])) {
    peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    *(char *)(piVar26 + 0xf) = cVar20;
    *piVar26 = 1;
    piVar26[3] = (int)peVar3;
    piVar26[2] = 0;
    piVar26[1] = gmsgStatusValue;
    piVar26[-1] = 0x12f61d;
    (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
    *piVar26 = 3;
    piVar26[-1] = 0x12f62a;
    (*g_engfuncs.pfnWriteByte)(*piVar26);
    *piVar26 = iVar16;
    piVar26[-1] = 0x12f633;
    (*g_engfuncs.pfnWriteShort)(*piVar26);
    piVar26[-1] = 0x12f639;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_izSBarState[3] = iVar16;
    cVar21 = (char)piVar26[0xf];
  }
  iVar16 = piVar26[0xb4];
  if ((cVar21 != '\0') || (cVar20 = '\0', iVar16 != this->m_izSBarState[4])) {
    peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    *(char *)(piVar26 + 0xf) = cVar21;
    *piVar26 = 1;
    piVar26[3] = (int)peVar3;
    piVar26[2] = 0;
    piVar26[1] = gmsgStatusValue;
    piVar26[-1] = 0x12f5bd;
    (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
    *piVar26 = 4;
    piVar26[-1] = 0x12f5ca;
    (*g_engfuncs.pfnWriteByte)(*piVar26);
    *piVar26 = iVar16;
    piVar26[-1] = 0x12f5d3;
    (*g_engfuncs.pfnWriteShort)(*piVar26);
    piVar26[-1] = 0x12f5d9;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_izSBarState[4] = iVar16;
    cVar20 = (char)piVar26[0xf];
  }
  iVar16 = piVar26[0xb5];
  if ((cVar20 != '\0') || (cVar21 = '\0', iVar16 != this->m_izSBarState[5])) {
    peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    *(char *)(piVar26 + 0xf) = cVar20;
    *piVar26 = 1;
    piVar26[3] = (int)peVar3;
    piVar26[2] = 0;
    piVar26[1] = gmsgStatusValue;
    piVar26[-1] = 0x12f55d;
    (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
    *piVar26 = 5;
    piVar26[-1] = 0x12f56a;
    (*g_engfuncs.pfnWriteByte)(*piVar26);
    *piVar26 = iVar16;
    piVar26[-1] = 0x12f573;
    (*g_engfuncs.pfnWriteShort)(*piVar26);
    piVar26[-1] = 0x12f579;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_izSBarState[5] = iVar16;
    cVar21 = (char)piVar26[0xf];
  }
  iVar16 = piVar26[0xb6];
  if ((cVar21 == '\0') && (iVar16 == this->m_izSBarState[6])) {
    return;
  }
  peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity;
  piVar26[2] = 0;
  *piVar26 = 1;
  piVar26[3] = (int)peVar3;
  piVar26[1] = gmsgStatusValue;
  piVar26[-1] = 0x12f4f9;
  (*g_engfuncs.pfnMessageBegin)(*piVar26,piVar26[1],(float *)piVar26[2],(edict_t *)piVar26[3]);
  *piVar26 = 6;
  piVar26[-1] = 0x12f506;
  (*g_engfuncs.pfnWriteByte)(*piVar26);
  *piVar26 = iVar16;
  piVar26[-1] = 0x12f50f;
  (*g_engfuncs.pfnWriteShort)(*piVar26);
  piVar26[-1] = 0x12f515;
  (*g_engfuncs.pfnMessageEnd)();
  this->m_izSBarState[6] = iVar16;
  return;
}


