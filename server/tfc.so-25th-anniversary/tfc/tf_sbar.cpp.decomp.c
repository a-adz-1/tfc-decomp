// Ghidra decompilation of functions from tfc/tf_sbar.cpp
// 3 functions, ordered by original source line

// CBasePlayer::TeamFortress_InitStatusBar  @ 000fba50  (line 40)

/* DWARF original prototype: void TeamFortress_InitStatusBar(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_InitStatusBar(CBasePlayer *this)

{
  this->m_flStatusBarDisappearDelay = 0.0;
  this->m_SbarString2[0] = '\0';
  this->m_SbarString1[0] = '\0';
  this->m_SbarString0[0] = '\0';
  return;
}


// CBasePlayer::GetTeleporter  @ 000fba80  (line 46)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CBaseEntity * GetTeleporter(CBasePlayer * this, int type) */

CBaseEntity * __thiscall CBasePlayer::GetTeleporter(CBasePlayer *this,int type)

{
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
      return (CBaseEntity *)0x0;
    }
    pCVar1 = EHANDLE::operator->(&pStartEntity->real_owner);
    if ((pCVar1->pev ==
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev) && (pStartEntity[1].goal_result == type)) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_teleporter");
  }
  return pStartEntity;
}


// CBasePlayer::TeamFortress_UpdateStatusBar  @ 000fbb00  (line 70)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_UpdateStatusBar(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_UpdateStatusBar(CBasePlayer *this)

{
  float fVar1;
  char cVar2;
  undefined2 uVar3;
  _func_int_varargs *p_Var4;
  _func_int_varargs **pp_Var5;
  char *pcVar6;
  _2globalvars_t *p1Var7;
  byte bVar8;
  int iVar9;
  int iVar10;
  entvars_t *peVar11;
  char *pcVar12;
  CBaseEntity *pCVar13;
  CBasePlayer *pCVar14;
  uint *puVar15;
  uint *puVar16;
  undefined2 *puVar17;
  CBaseEntity *pCVar18;
  CBaseEntity *pCVar19;
  uint uVar20;
  BOOL BVar21;
  edict_t *peVar22;
  int iVar23;
  undefined4 *puVar24;
  float *pfVar25;
  float *pfVar26;
  uint uVar27;
  undefined2 *puVar28;
  float *pfVar29;
  int *piVar30;
  int iVar31;
  uint uVar32;
  char *pcVar33;
  undefined2 *puVar34;
  int in_GS_OFFSET;
  bool bVar35;
  byte bVar36;
  float fVar37;
  float fVar38;
  undefined4 uStackY_2f0;
  char *local_2ac;
  char *local_2a8;
  char *local_2a4;
  int aiStack_294 [6];
  BOOL local_27c;
  Vector local_278 [7];
  undefined1 local_220;
  uint local_1a0;
  undefined4 local_19c;
  undefined4 uStack_198;
  undefined2 local_194;
  undefined1 uStack_192;
  undefined4 uStack_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined2 local_114;
  undefined1 local_112;
  undefined1 local_a0;
  undefined4 local_20;
  
                    /* Unresolved local var: int[7] newSBarState@[???]
                       Unresolved local var: char[128] sbuf0@[???]
                       Unresolved local var: char[128] sbuf1@[???]
                       Unresolved local var: char[128] sbuf2@[???]
                       Unresolved local var: char[128] temp@[???]
                       Unresolved local var: BOOL bForceResend@[???] */
  bVar36 = 0;
  pfVar29 = (float *)&stack0xfffffd14;
  local_20 = *(undefined4 *)(in_GS_OFFSET + 0x14);
  uVar20 = 0;
  do {
    uVar27 = uVar20;
    *(undefined4 *)((int)aiStack_294 + uVar27) = 0;
    *(undefined4 *)((int)aiStack_294 + uVar27 + 4) = 0;
    uVar20 = uVar27 + 8;
  } while (uVar27 + 8 < 0x18);
  *(undefined4 *)((int)aiStack_294 + uVar27 + 8) = 0;
  local_a0 = 0;
  pcVar12 = this->m_SbarString2;
  local_1a0 = local_1a0 & 0xffffff00;
  local_220 = 0;
  uStackY_2f0 = 0xfbb7b;
  __strcpy_chk();
  p1Var7 = gpGlobals;
  fVar37 = gpGlobals->time;
  if (fVar37 < cb_prematch_time) {
LAB_000fbdb4:
    local_11c = 0x72705f72;
    local_118 = 0x74616d65;
    local_114 = 0x6863;
    local_112 = 0;
    if (tfc_clanbattle.value != 0.0) {
      local_1a0 = 0x61625323;
      local_19c = 0x61625f72;
      uStack_198 = 0x656c7474;
      local_194 = 0x6469;
      uStack_192 = 0;
      aiStack_294[5] =
           (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.tf_id;
    }
    local_27c = cease_fire;
    fVar38 = cb_prematch_time;
  }
  else {
    fVar38 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.respawn_time;
    if (fVar38 <= fVar37) {
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
      peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      local_278[0].z = (peVar11->v_angle).z + (peVar11->punchangle).z;
      local_278[0].y = (peVar11->v_angle).y + (peVar11->punchangle).y;
      local_278[0].x = (peVar11->v_angle).x + (peVar11->punchangle).x;
      uStackY_2f0 = 0xfc031;
      UTIL_MakeVectors(local_278);
      p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x33];
      if (p_Var4 == CBaseEntity::EyePosition) {
        peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        local_2a4 = (char *)((peVar11->origin).z + (peVar11->view_ofs).z);
        local_2a8 = (char *)((peVar11->origin).y + (peVar11->view_ofs).y);
        pcVar12 = (char *)((peVar11->origin).x + (peVar11->view_ofs).x);
        local_2ac = pcVar12;
        pfVar29 = (float *)&stack0xfffffd14;
        pcVar33 = local_2a4;
        pcVar6 = local_2a8;
      }
      else {
        uStackY_2f0 = 0xfc433;
        (*p_Var4)();
        peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        pfVar29 = (float *)&uStackY_2f0;
        pcVar33 = local_2a8;
        pcVar6 = local_2ac;
      }
      fVar37 = (gpGlobals->v_forward).z;
      fVar38 = (gpGlobals->v_forward).y;
      fVar1 = (gpGlobals->v_forward).x;
      pfVar29[4] = (float)local_278;
      peVar22 = peVar11->pContainingEntity;
      *pfVar29 = (float)&local_2ac;
      pfVar29[3] = (float)peVar22;
      pfVar29[2] = 0.0;
      pfVar29[1] = (float)(pfVar29 + 0x13);
      pfVar29[0x13] = fVar1 * 2048.0 + (float)pcVar12;
      pfVar29[0x14] = fVar38 * 2048.0 + (float)pcVar6;
      pfVar29[0x15] = fVar37 * 2048.0 + (float)pcVar33;
      pfVar29[-1] = 1.446692e-39;
      UTIL_TraceLine((Vector *)*pfVar29,(Vector *)pfVar29[1],(IGNORE_MONSTERS)pfVar29[2],
                     (edict_t *)pfVar29[3],(_1TraceResult *)pfVar29[4]);
      if (pfVar29[0x21] != 1.0) {
        if (pfVar29[0x29] == 0.0) {
LAB_000fc181:
          if (this->m_flStatusBarDisappearDelay <= gpGlobals->time) goto LAB_000fc17b;
          fVar37 = (float)this->m_izSBarState[1];
          pfVar29[0x18] = (float)this->m_izSBarState[2];
          fVar38 = (float)this->m_izSBarState[3];
          pfVar29[0x17] = fVar37;
          pfVar29[0x19] = fVar38;
        }
        else {
          *pfVar29 = pfVar29[0x29];
          pfVar29[-1] = 1.446758e-39;
          iVar23 = (*g_engfuncs.pfnEntOffsetOfPEntity)((edict_t *)*pfVar29);
          if (iVar23 == 0) goto LAB_000fc181;
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: BOOL bFoundTarget@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???] */
          peVar22 = (edict_t *)pfVar29[0x29];
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          if (peVar22 == (edict_t *)0x0) {
            *pfVar29 = 0.0;
            pfVar29[-1] = 1.451494e-39;
            peVar22 = (*g_engfuncs.pfnPEntityOfEntOffset)((int)*pfVar29);
            if (peVar22 != (edict_t *)0x0) goto LAB_000fc110;
            pCVar13 = (CBaseEntity *)0x0;
          }
          else {
LAB_000fc110:
            pCVar13 = peVar22->pvPrivateData;
          }
          pp_Var5 = pCVar13->_vptr_CBaseEntity;
          *pfVar29 = (float)pCVar13;
          p_Var4 = pp_Var5[10];
          pfVar29[-1] = 1.446806e-39;
          iVar23 = (*p_Var4)();
          if (iVar23 == 2) {
            if (pCVar13->is_feigning == 0) {
LAB_000fc9d2:
              pfVar29[1] = (float)pCVar13;
              *pfVar29 = (float)this;
              pfVar29[-1] = 1.449949e-39;
              BVar21 = CBaseEntity::IsAlly((CBaseEntity *)*pfVar29,(CBaseEntity *)pfVar29[1]);
              if (BVar21 == 0) {
                fVar37 = (pfVar29[0x12] - pfVar29[0x24]) * (pfVar29[0x12] - pfVar29[0x24]) +
                         (pfVar29[0x11] - pfVar29[0x23]) * (pfVar29[0x11] - pfVar29[0x23]) +
                         (pfVar29[0x10] - pfVar29[0x22]) * (pfVar29[0x10] - pfVar29[0x22]);
                fVar38 = SQRT(fVar37);
                if (NAN(fVar38)) {
                  *pfVar29 = fVar37;
                  pfVar29[-1] = 1.452056e-39;
                  fVar38 = sqrtf(*pfVar29);
                }
                if (fVar38 <= 1024.0) goto LAB_000fc9e6;
                if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0) goto LAB_000fc17b;
              }
              else {
LAB_000fc9e6:
                if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0) &&
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.team_no != 0)) {
                  *pfVar29 = (float)&pCVar13->undercover_target;
                  pfVar29[-1] = 1.452086e-39;
                  iVar23 = EHANDLE::operator_int((EHANDLE *)*pfVar29);
                  if ((iVar23 != 0) &&
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.team_no != pCVar13->team_no &&
                      (pCVar13->pev->playerclass == 8)))) {
                    *pfVar29 = (float)&pCVar13->undercover_target;
                    pfVar29[-1] = 1.452156e-39;
                    pCVar13 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*pfVar29);
                  }
                }
              }
              if (tfc_playerid.value == 2.0) {
LAB_000fcf1a:
                *(undefined2 *)(pfVar29 + 0x73) = 0x20;
              }
              else {
                if (tfc_playerid.value == 1.0) {
                  pfVar29[1] = (float)pCVar13;
                  *pfVar29 = (float)this;
                  pfVar29[-1] = 1.451777e-39;
                  BVar21 = CBaseEntity::IsAlly((CBaseEntity *)*pfVar29,(CBaseEntity *)pfVar29[1]);
                  if ((BVar21 == 0) &&
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0)) goto LAB_000fcf1a;
                }
                uVar20 = 0;
                do {
                  uVar27 = uVar20;
                  *(undefined4 *)((int)pfVar29 + uVar27 + 0x1cc) =
                       *(undefined4 *)("1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%" + uVar27);
                  uVar20 = uVar27 + 4;
                } while (uVar27 + 4 < 0x28);
                *(char *)((int)pfVar29 + uVar27 + 0x1d0) =
                     "1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%"[uVar27 + 4];
              }
              *pfVar29 = (float)pCVar13->pev->pContainingEntity;
              pfVar29[-1] = 1.45187e-39;
              fVar37 = (float)(*g_engfuncs.pfnIndexOfEdict)((edict_t *)*pfVar29);
              pfVar29[1] = (float)pCVar13;
              pfVar29[0x17] = fVar37;
              *pfVar29 = (float)&this->m_hLastIDTarget;
              pfVar29[-1] = 1.451901e-39;
              EHANDLE::operator=((EHANDLE *)*pfVar29,(CBaseEntity *)pfVar29[1]);
              goto LAB_000fcbd9;
            }
            pfVar29[1] = (float)pCVar13;
            *pfVar29 = (float)this;
            pfVar29[-1] = 1.449903e-39;
            BVar21 = CBaseEntity::IsAlly((CBaseEntity *)*pfVar29,(CBaseEntity *)pfVar29[1]);
            if ((BVar21 != 0) ||
               (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->iuser1 != 0)) goto LAB_000fc9d2;
          }
          else {
            pcVar12 = gpGlobals->pStringBase + pCVar13->pev->classname;
            bVar35 = pcVar12 == (char *)0x0;
            iVar23 = 0x13;
            pfVar29[0xb] = (float)pcVar12;
            pcVar33 = "building_sentrygun";
            do {
              if (iVar23 == 0) break;
              iVar23 = iVar23 + -1;
              bVar35 = *pcVar12 == *pcVar33;
              pcVar12 = pcVar12 + (uint)bVar36 * -2 + 1;
              pcVar33 = pcVar33 + (uint)bVar36 * -2 + 1;
            } while (bVar35);
            if (bVar35) {
              *pfVar29 = (float)&pCVar13->real_owner;
              pfVar29[-1] = 1.450448e-39;
              pCVar19 = EHANDLE::operator->((EHANDLE *)*pfVar29);
              *pfVar29 = (float)pCVar19->pev->pContainingEntity;
              pfVar29[-1] = 1.450473e-39;
              fVar37 = (float)(*g_engfuncs.pfnIndexOfEdict)((edict_t *)*pfVar29);
              pfVar29[0x17] = fVar37;
              if (tfc_playerid.value == 2.0) {
LAB_000fcbcc:
                *(undefined2 *)(pfVar29 + 0x73) = 0x20;
              }
              else {
                if ((tfc_playerid.value == 1.0) &&
                   (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0)) {
                  pfVar29[1] = (float)pCVar13;
                  *pfVar29 = (float)this;
                  pfVar29[-1] = 1.450619e-39;
                  BVar21 = CBaseEntity::IsAlly((CBaseEntity *)*pfVar29,(CBaseEntity *)pfVar29[1]);
                  if (BVar21 == 0) goto LAB_000fcbcc;
                }
                uVar20 = 0;
                do {
                  uVar27 = uVar20;
                  *(undefined4 *)((int)pfVar29 + uVar27 + 0x1cc) =
                       *(undefined4 *)
                        ("1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%" + uVar27)
                  ;
                  uVar20 = uVar27 + 4;
                } while (uVar27 + 4 < 0x3c);
                *(short *)((int)pfVar29 + uVar27 + 0x1d0) =
                     (short)*(undefined4 *)
                             ("1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%" +
                             uVar27 + 4);
              }
            }
            else {
              iVar23 = 0x13;
              bVar35 = false;
              pcVar12 = (char *)pfVar29[0xb];
              pcVar33 = "building_dispenser";
              do {
                if (iVar23 == 0) break;
                iVar23 = iVar23 + -1;
                bVar35 = *pcVar12 == *pcVar33;
                pcVar12 = pcVar12 + (uint)bVar36 * -2 + 1;
                pcVar33 = pcVar33 + (uint)bVar36 * -2 + 1;
              } while (bVar35);
              if (bVar35) {
                *pfVar29 = (float)&pCVar13->real_owner;
                pfVar29[-1] = 1.450962e-39;
                pCVar19 = EHANDLE::operator->((EHANDLE *)*pfVar29);
                *pfVar29 = (float)pCVar19->pev->pContainingEntity;
                pfVar29[-1] = 1.450987e-39;
                fVar37 = (float)(*g_engfuncs.pfnIndexOfEdict)((edict_t *)*pfVar29);
                pfVar29[0x17] = fVar37;
                if (tfc_playerid.value == 2.0) goto LAB_000fcbcc;
                if ((tfc_playerid.value == 1.0) &&
                   (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0)) {
                  pfVar29[1] = (float)pCVar13;
                  *pfVar29 = (float)this;
                  pfVar29[-1] = 1.451157e-39;
                  BVar21 = CBaseEntity::IsAlly((CBaseEntity *)*pfVar29,(CBaseEntity *)pfVar29[1]);
                  if (BVar21 == 0) goto LAB_000fcbcc;
                }
                uVar20 = 0;
                do {
                  uVar27 = uVar20;
                  *(undefined4 *)((int)pfVar29 + uVar27 + 0x1cc) =
                       *(undefined4 *)
                        ("1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%" + uVar27);
                  uVar20 = uVar27 + 4;
                } while (uVar27 + 4 < 0x3c);
                *(char *)((int)pfVar29 + uVar27 + 0x1d0) =
                     "1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"[uVar27 + 4];
              }
              else {
                iVar23 = 0x14;
                bVar35 = false;
                pcVar12 = (char *)pfVar29[0xb];
                pcVar33 = "building_teleporter";
                do {
                  if (iVar23 == 0) break;
                  iVar23 = iVar23 + -1;
                  bVar35 = *pcVar12 == *pcVar33;
                  pcVar12 = pcVar12 + (uint)bVar36 * -2 + 1;
                  pcVar33 = pcVar33 + (uint)bVar36 * -2 + 1;
                } while (bVar35);
                if (!bVar35) goto LAB_000fc17b;
                *pfVar29 = (float)&pCVar13->real_owner;
                pfVar29[-1] = 1.451263e-39;
                pCVar19 = EHANDLE::operator->((EHANDLE *)*pfVar29);
                *pfVar29 = (float)pCVar19->pev->pContainingEntity;
                pfVar29[-1] = 1.451288e-39;
                fVar37 = (float)(*g_engfuncs.pfnIndexOfEdict)((edict_t *)*pfVar29);
                pfVar29[0x17] = fVar37;
                if (tfc_playerid.value == 2.0) goto LAB_000fcbcc;
                if ((tfc_playerid.value == 1.0) &&
                   (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0)) {
                  pfVar29[1] = (float)pCVar13;
                  *pfVar29 = (float)this;
                  pfVar29[-1] = 1.452024e-39;
                  BVar21 = CBaseEntity::IsAlly((CBaseEntity *)*pfVar29,(CBaseEntity *)pfVar29[1]);
                  if (BVar21 == 0) goto LAB_000fcbcc;
                }
                uVar20 = 0;
                if (pCVar13[1].goal_result == 4) {
                  uVar20 = 0;
                  do {
                    uVar27 = uVar20;
                    *(undefined4 *)((int)pfVar29 + uVar27 + 0x1cc) =
                         *(undefined4 *)
                          (
                          "1 Teleporter entrance built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                          + uVar27);
                    uVar20 = uVar27 + 4;
                  } while (uVar27 + 4 < 0x44);
                  cVar2 = "1 Teleporter entrance built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                          [uVar27 + 6];
                  *(undefined2 *)((int)pfVar29 + uVar27 + 0x1d0) =
                       (short)*(undefined4 *)
                               (
                               "1 Teleporter entrance built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                               + uVar27 + 4);
                  *(char *)((undefined2 *)((int)pfVar29 + uVar27 + 0x1d0) + 1) = cVar2;
                }
                else {
                  do {
                    uVar27 = uVar20;
                    *(undefined4 *)((int)pfVar29 + uVar27 + 0x1cc) =
                         *(undefined4 *)
                          ("1 Teleporter exit built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%" +
                          uVar27);
                    uVar20 = uVar27 + 4;
                  } while (uVar27 + 4 < 0x40);
                  cVar2 = "1 Teleporter exit built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                          [uVar27 + 6];
                  *(undefined2 *)((int)pfVar29 + uVar27 + 0x1d0) =
                       (short)*(undefined4 *)
                               (
                               "1 Teleporter exit built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%"
                               + uVar27 + 4);
                  *(char *)((undefined2 *)((int)pfVar29 + uVar27 + 0x1d0) + 1) = cVar2;
                }
              }
            }
LAB_000fcbd9:
            pfVar29[1] = (float)pCVar13;
            *pfVar29 = (float)this;
            pfVar29[-1] = 1.450676e-39;
            BVar21 = CBaseEntity::IsAlly((CBaseEntity *)*pfVar29,(CBaseEntity *)pfVar29[1]);
            if (((BVar21 != 0) ||
                (peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev, peVar11->playerclass == 5)) ||
               (peVar11->iuser1 != 0)) {
              pfVar29[0xb] = (pCVar13->pev->health / pCVar13->pev->max_health) * 100.0;
              pfVar29[0x18] = (float)(int)pfVar29[0xb];
              pfVar29[0xb] = (pCVar13->pev->armorvalue / pCVar13->maxarmor) * 100.0;
              pfVar29[0x19] = (float)(int)pfVar29[0xb];
            }
            this->m_flStatusBarDisappearDelay = gpGlobals->time + 1.0;
          }
LAB_000fc17b:
          fVar37 = pfVar29[0x17];
        }
        if (((int)fVar37 < 0) || (gpGlobals->maxClients < (int)fVar37)) {
          pfVar29[2] = fVar37;
          pfVar29[1] = (float)"ERROR: SBAR_ID_TARGETNAME = %d\n";
          *pfVar29 = 1.4013e-45;
          pfVar29[-1] = 1.447077e-39;
          __printf_chk();
          pfVar29[0x17] = 0.0;
        }
      }
      peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      pfVar29[0xc] = (float)(pfVar29 + 0x53);
      iVar23 = peVar11->playerclass;
      if (iVar23 == 8) {
        iVar23 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.undercover_team;
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.is_undercover == 0) {
          if (iVar23 == 0) {
            iVar23 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.undercover_skin;
            if (iVar23 == 0) {
              fVar37 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.respawn_time;
              pfVar29[0xe] = (float)(pfVar29 + 0x33);
              pfVar29[0xb] = fVar37;
              goto LAB_000fbc67;
            }
            goto LAB_000fc725;
          }
LAB_000fca58:
          pfVar29[0x53] = 7.798984e+34;
          *pfVar29 = (float)iVar23;
          *(undefined2 *)((int)pfVar29 + 0x15a) = 0x20;
          pfVar29[0xc] = (float)(pfVar29 + 0x53);
          pfVar29[0x54] = 1.8491225e+31;
          pfVar29[0x55] = 1.8496496e+31;
          *(undefined2 *)(pfVar29 + 0x56) = 0x6465;
          pfVar29[-1] = 1.450233e-39;
          pcVar12 = GetTeamName((int)*pfVar29);
          pfVar26 = pfVar29 + 0x53;
          do {
            pfVar25 = pfVar26;
            uVar27 = (int)*pfVar25 + 0xfefefeffU & ~(uint)*pfVar25;
            uVar20 = uVar27 & 0x80808080;
            pfVar26 = pfVar25 + 1;
          } while (uVar20 == 0);
          if ((uVar27 & 0x8080) == 0) {
            pfVar26 = (float *)((int)pfVar25 + 6);
            uVar20 = uVar20 >> 0x10;
          }
          *pfVar29 = (float)((int)pfVar26 + (-3 - (uint)CARRY1((byte)uVar20,(byte)uVar20)));
          pfVar29[2] = 1.79366e-43;
          pfVar29[1] = (float)pcVar12;
          pfVar29[-1] = 1.450336e-39;
          puVar34 = (undefined2 *)__stpcpy_chk();
          iVar23 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.undercover_skin;
          if (iVar23 == 0) {
            *puVar34 = 0x2320;
            *(undefined1 *)(puVar34 + 1) = 0;
            pfVar29[2] = 1.79366e-43;
            *pfVar29 = (float)(puVar34 + 1);
            pfVar29[1] = (float)sClassNames[8];
            pfVar29[-1] = 1.450408e-39;
            __strcpy_chk();
            iVar23 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->playerclass;
            goto LAB_000fc200;
          }
          peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
          pfVar26 = (float *)pfVar29[0xc];
        }
        else {
          if (iVar23 != 0) goto LAB_000fca58;
          iVar23 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.undercover_skin;
          if (iVar23 == 0) {
            fVar37 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.respawn_time;
            pfVar29[0x53] = 7.798984e+34;
            pfVar29[0x54] = 1.8491225e+31;
            pfVar29[0x55] = 1.8496496e+31;
            pfVar29[0x56] = 9.498664e-39;
            pfVar29[0xb] = fVar37;
            pfVar29[0xe] = (float)(pfVar29 + 0x33);
            goto LAB_000fbc67;
          }
LAB_000fc725:
          pfVar29[0x55] = 1.8496496e+31;
          *(undefined2 *)(pfVar29 + 0x56) = 0x6465;
          *(undefined1 *)((int)pfVar29 + 0x15a) = 0;
          pfVar29[0x54] = 1.8491225e+31;
          pfVar29[0x53] = 7.798984e+34;
          pfVar29[0xc] = (float)(pfVar29 + 0x53);
          pfVar26 = pfVar29 + 0x53;
        }
        do {
          pfVar25 = pfVar26;
          uVar20 = (int)*pfVar25 + 0xfefefeffU & ~(uint)*pfVar25;
          uVar27 = uVar20 & 0x80808080;
          pfVar26 = pfVar25 + 1;
        } while (uVar27 == 0);
        bVar8 = (byte)uVar27;
        if ((uVar20 & 0x8080) == 0) {
          bVar8 = (byte)(uVar27 >> 0x10);
          pfVar26 = (float *)((int)pfVar25 + 6);
        }
        puVar34 = (undefined2 *)((int)pfVar26 + (-3 - (uint)CARRY1(bVar8,bVar8)));
        *puVar34 = 0x2320;
        *(undefined1 *)(puVar34 + 1) = 0;
        pcVar12 = sClassNames[iVar23];
        pfVar29[2] = 1.79366e-43;
        *pfVar29 = (float)(puVar34 + 1);
        pfVar29[1] = (float)pcVar12;
        pfVar29[-1] = 1.449203e-39;
        __strcpy_chk();
        iVar23 = peVar11->playerclass;
      }
LAB_000fc200:
      pfVar29[0xe] = (float)(pfVar29 + 0x33);
      if (iVar23 == 9) {
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.has_sentry == 0.0) {
          if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.has_entry_teleporter != 0.0) goto LAB_000fc4c2;
          fVar37 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.has_exit_teleporter;
          if (fVar37 != 0.0) goto LAB_000fc4a0;
          if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.is_building == 0) {
            pfVar29[0xb] = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.respawn_time;
            goto LAB_000fbc67;
          }
LAB_000fc6b8:
          if (*(char *)(pfVar29 + 0x53) == '\0') {
            fVar37 = pfVar29[0xc];
            uVar20 = 0;
            do {
              uVar27 = uVar20;
              *(undefined4 *)((int)fVar37 + uVar27) = *(undefined4 *)("#Engineer_building" + uVar27)
              ;
              uVar20 = uVar27 + 4;
            } while (uVar20 < 0x10);
            puVar34 = (undefined2 *)((int)fVar37 + uVar20);
            cVar2 = "#Engineer_building"[uVar27 + 6];
            *puVar34 = *(undefined2 *)("#Engineer_building" + uVar27 + 4);
            *(char *)(puVar34 + 1) = cVar2;
LAB_000fc6f6:
            iVar23 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->playerclass;
            pfVar29[0xe] = (float)(pfVar29 + 0x33);
            goto LAB_000fc210;
          }
          pfVar29[0xe] = (float)(pfVar29 + 0x33);
LAB_000fc975:
          fVar37 = pfVar29[0xe];
          uVar20 = 0;
          do {
            uVar27 = uVar20;
            *(undefined4 *)((int)fVar37 + uVar27) = *(undefined4 *)("#Engineer_building" + uVar27);
            uVar20 = uVar27 + 4;
          } while (uVar20 < 0x10);
          puVar34 = (undefined2 *)((int)fVar37 + uVar20);
          cVar2 = "#Engineer_building"[uVar27 + 6];
          *puVar34 = *(undefined2 *)("#Engineer_building" + uVar27 + 4);
          *(char *)(puVar34 + 1) = cVar2;
        }
        else {
                    /* Unresolved local var: CBaseEntity * te@[???] */
          pfVar29[1] = (float)"building_sentrygun";
          *pfVar29 = 0.0;
          pfVar29[-1] = 1.447274e-39;
          pCVar13 = UTIL_FindEntityByClassname((CBaseEntity *)*pfVar29,(char *)pfVar29[1]);
          while (pCVar13 != (CBaseEntity *)0x0) {
            *pfVar29 = (float)&pCVar13->real_owner;
            pfVar29[-1] = 1.447352e-39;
            pCVar14 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*pfVar29);
            if (this == pCVar14) {
                    /* Unresolved local var: int health@[???] */
              pfVar29[0xb] = (pCVar13->pev->health / pCVar13->pev->max_health) * 100.0;
              fVar37 = (float)(int)pfVar29[0xb];
              if ((int)fVar37 < 0) {
                fVar37 = 0.0;
              }
              else if (100 < (int)fVar37) {
                fVar37 = 1.4013e-43;
              }
              pfVar29[3] = (float)"#Sentry_sbar %d";
              puVar16 = (uint *)pfVar29[0xc];
              pfVar29[4] = fVar37;
              pfVar29[2] = 1.79366e-43;
              pfVar29[1] = 1.4013e-45;
              *pfVar29 = (float)puVar16;
              pfVar29[-1] = 1.447488e-39;
              __sprintf_chk();
              do {
                puVar15 = puVar16;
                uVar27 = *puVar15 + 0xfefefeff & ~*puVar15;
                uVar20 = uVar27 & 0x80808080;
                puVar16 = puVar15 + 1;
              } while (uVar20 == 0);
              uVar32 = 0x13;
              if ((uVar27 & 0x8080) == 0) {
                puVar16 = (uint *)((int)puVar15 + 6);
                uVar20 = uVar20 >> 0x10;
              }
              puVar24 = &DAT_0015dbb4;
              puVar17 = (undefined2 *)
                        ((int)puVar16 + (-3 - (uint)CARRY1((byte)uVar20,(byte)uVar20)));
              bVar35 = ((uint)puVar17 & 1) != 0;
              puVar34 = puVar17;
              if (bVar35) {
                puVar34 = (undefined2 *)((int)puVar17 + 1);
                uVar32 = 0x12;
                *(undefined1 *)puVar17 = 0x25;
                puVar24 = (undefined4 *)((int)&DAT_0015dbb4 + 1);
              }
              puVar28 = puVar34;
              if (((uint)puVar34 & 2) != 0) {
                uVar3 = *(undefined2 *)puVar24;
                puVar28 = puVar34 + 1;
                puVar24 = (undefined4 *)((int)puVar24 + 2);
                uVar32 = uVar32 - 2;
                *puVar34 = uVar3;
              }
              pfVar29[0xb] = (float)(uVar32 & 0xfffffffc);
              fVar37 = 0.0;
              pfVar29[0xe] = (float)puVar17;
              do {
                *(undefined4 *)((int)puVar28 + (int)fVar37) =
                     *(undefined4 *)((int)puVar24 + (int)fVar37);
                fVar37 = (float)((int)fVar37 + 4);
              } while ((uint)fVar37 < (uint)pfVar29[0xb]);
              fVar38 = pfVar29[0xe];
              iVar23 = 0;
              if ((uVar32 & 2) != 0) {
                *(undefined2 *)((int)puVar28 + (int)fVar37) =
                     *(undefined2 *)((int)puVar24 + (int)fVar37);
                iVar23 = 2;
              }
              if (!bVar35) {
                *(undefined1 *)((int)puVar28 + (int)fVar37 + iVar23) =
                     *(undefined1 *)((int)puVar24 + (int)fVar37 + iVar23);
              }
              if ((float)pCVar13->ammo_shells == 0.0) {
                *(undefined2 *)((int)fVar38 + 0x12) = 0x20;
                if ((pCVar13->ammo_rockets == 0) && (pCVar13->weapon == 3)) {
                  *(undefined4 *)((int)fVar38 + 0x13) = 0x5f6f4e23;
                  *(undefined4 *)((int)fVar38 + 0x17) = 0x6f6d6d41;
                  *(undefined1 *)((int)fVar38 + 0x1b) = 0;
                }
                else {
                  *(undefined4 *)((int)fVar38 + 0x13) = 0x5f6f4e23;
                  *(undefined4 *)((int)fVar38 + 0x17) = 0x6c656853;
                  *(undefined2 *)((int)fVar38 + 0x1b) = 0x736c;
                  *(undefined1 *)((int)fVar38 + 0x1d) = 0;
                }
              }
              else {
                pfVar29[0xb] = (float)pCVar13->ammo_shells;
                pfVar29[0xb] = ((float)(int)pfVar29[0xb] / (float)pCVar13->maxammo_shells) * 100.0;
                pfVar29[0x1a] = (float)(int)pfVar29[0xb];
                if ((pCVar13->ammo_rockets == 0) && (pCVar13->weapon == 3)) {
                  *(undefined1 *)((int)fVar38 + 0x12) = 0x20;
                  *(undefined4 *)((int)fVar38 + 0x13) = 0x5f6f4e23;
                  *(undefined4 *)((int)fVar38 + 0x17) = 0x6b636f52;
                  *(undefined4 *)((int)fVar38 + 0x1b) = 0x737465;
                }
              }
            }
            *pfVar29 = (float)pCVar13;
            pfVar29[1] = (float)"building_sentrygun";
            pfVar29[-1] = 1.447319e-39;
            pCVar13 = UTIL_FindEntityByClassname((CBaseEntity *)*pfVar29,(char *)pfVar29[1]);
          }
          if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.has_entry_teleporter == 0.0) {
            fVar37 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.has_exit_teleporter;
LAB_000fc4a0:
            if (fVar37 != 0.0) goto LAB_000fc4c2;
          }
          else {
LAB_000fc4c2:
                    /* Unresolved local var: char[32] szTemp@[???]
                       Unresolved local var: int iEntryHealth@[???]
                       Unresolved local var: int iExitHealth@[???]
                       Unresolved local var: CTFTeleporter * pEntry@[DW_OP_reg3(EBX)]
                       Unresolved local var: CTFTeleporter * pExit@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
            pfVar29[1] = (float)"building_teleporter";
            *pfVar29 = 0.0;
            pfVar29[-1] = 1.448145e-39;
            pCVar13 = UTIL_FindEntityByClassname((CBaseEntity *)*pfVar29,(char *)pfVar29[1]);
            while (pCVar13 != (CBaseEntity *)0x0) {
              *pfVar29 = (float)&pCVar13->real_owner;
              pfVar29[-1] = 1.448227e-39;
              pCVar19 = EHANDLE::operator->((EHANDLE *)*pfVar29);
              if ((pCVar19->pev ==
                   (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev) && (pCVar13[1].goal_result == 4)) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
                pfVar29[1] = (float)"building_teleporter";
                *pfVar29 = 0.0;
                pfVar29[-1] = 1.44828e-39;
                pCVar19 = UTIL_FindEntityByClassname((CBaseEntity *)*pfVar29,(char *)pfVar29[1]);
                if (pCVar19 != (CBaseEntity *)0x0) goto LAB_000fc563;
                goto LAB_000fc806;
              }
              *pfVar29 = (float)pCVar13;
              pfVar29[1] = (float)"building_teleporter";
              pfVar29[-1] = 1.448193e-39;
              pCVar13 = UTIL_FindEntityByClassname((CBaseEntity *)*pfVar29,(char *)pfVar29[1]);
            }
            pfVar29[1] = (float)"building_teleporter";
            *pfVar29 = 0.0;
            pfVar29[-1] = 1.449248e-39;
            pCVar19 = UTIL_FindEntityByClassname((CBaseEntity *)*pfVar29,(char *)pfVar29[1]);
            if (pCVar19 != (CBaseEntity *)0x0) {
              pCVar13 = (CBaseEntity *)0x0;
LAB_000fc563:
              do {
                *pfVar29 = (float)&pCVar19->real_owner;
                pfVar29[-1] = 1.448361e-39;
                pCVar18 = EHANDLE::operator->((EHANDLE *)*pfVar29);
                if ((pCVar18->pev ==
                     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev) && (pCVar19[1].goal_result == 5)) {
                  if (pCVar13 != (CBaseEntity *)0x0) goto LAB_000fc806;
                  goto LAB_000fc598;
                }
                *pfVar29 = (float)pCVar19;
                pfVar29[1] = (float)"building_teleporter";
                pfVar29[-1] = 1.448327e-39;
                pCVar19 = UTIL_FindEntityByClassname((CBaseEntity *)*pfVar29,(char *)pfVar29[1]);
              } while (pCVar19 != (CBaseEntity *)0x0);
              if (pCVar13 != (CBaseEntity *)0x0) {
LAB_000fc806:
                pfVar26 = pfVar29 + 0x93;
                pfVar29[2] = 1.79366e-43;
                pfVar29[1] = (float)"#Teleporter_entry_sbar ";
                *pfVar29 = (float)pfVar26;
                pfVar29[-1] = 1.449334e-39;
                __strcat_chk();
                pfVar29[0xb] = (pCVar13->pev->health / pCVar13->pev->max_health) * 100.0;
                fVar37 = (float)(int)pfVar29[0xb];
                if ((int)fVar37 < 0) {
                  fVar37 = 0.0;
                }
                else if (100 < (int)fVar37) {
                  fVar37 = 1.4013e-43;
                }
                pfVar29[4] = fVar37;
                pfVar29[3] = (float)"%d";
                pfVar29[2] = 4.48416e-44;
                pfVar29[1] = 1.4013e-45;
                *pfVar29 = (float)(pfVar29 + 0x2b);
                pfVar29[-1] = 1.449468e-39;
                __sprintf_chk();
                pfVar29[3] = 1.79366e-43;
                pfVar29[2] = 1.77965e-43;
                pfVar29[1] = (float)(pfVar29 + 0x2b);
                *pfVar29 = (float)pfVar26;
                pfVar29[-1] = 1.44951e-39;
                __strncat_chk();
                pfVar29[2] = 1.79366e-43;
                pfVar29[1] = (float)&DAT_0015dbc2;
                *pfVar29 = (float)pfVar26;
                pfVar29[-1] = 1.449547e-39;
                __strcat_chk();
                if (pCVar19 != (CBaseEntity *)0x0) {
LAB_000fc598:
                  pfVar26 = pfVar29 + 0x93;
                  if (*(char *)pfVar26 != '\0') {
                    pfVar29[2] = 1.79366e-43;
                    pfVar29[1] = (float)&DAT_0015dbdf;
                    *pfVar29 = (float)pfVar26;
                    pfVar29[-1] = 1.451217e-39;
                    __strcat_chk();
                  }
                  pfVar29[2] = 1.79366e-43;
                  pfVar29[1] = (float)"#Teleporter_exit_sbar ";
                  *pfVar29 = (float)pfVar26;
                  pfVar29[-1] = 1.448472e-39;
                  __strcat_chk();
                  pfVar29[0xb] = (pCVar19->pev->health / pCVar19->pev->max_health) * 100.0;
                  fVar37 = (float)(int)pfVar29[0xb];
                  if ((int)fVar37 < 0) {
                    fVar37 = 0.0;
                  }
                  else if (100 < (int)fVar37) {
                    fVar37 = 1.4013e-43;
                  }
                  pfVar29[3] = (float)"%d";
                  pfVar29[2] = 4.48416e-44;
                  pfVar29[4] = fVar37;
                  pfVar29[1] = 1.4013e-45;
                  *pfVar29 = (float)(pfVar29 + 0x2b);
                  pfVar29[-1] = 1.448596e-39;
                  __sprintf_chk();
                  pfVar29[3] = 1.79366e-43;
                  pfVar29[2] = 1.77965e-43;
                  pfVar29[1] = (float)(pfVar29 + 0x2b);
                  *pfVar29 = (float)pfVar26;
                  pfVar29[-1] = 1.448639e-39;
                  __strncat_chk();
                  pfVar29[2] = 1.79366e-43;
                  pfVar29[1] = (float)&DAT_0015dbc2;
                  *pfVar29 = (float)pfVar26;
                  pfVar29[-1] = 1.448675e-39;
                  __strcat_chk();
                }
              }
            }
          }
          if (*(char *)(pfVar29 + 0x93) == '\0') {
LAB_000fc6b1:
            if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.is_building != 0) goto LAB_000fc6b8;
            goto LAB_000fc6f6;
          }
          pfVar29[2] = 1.79366e-43;
          pfVar29[1] = (float)(pfVar29 + 0x93);
          if (*(char *)(pfVar29 + 0x53) == '\0') {
            *pfVar29 = pfVar29[0xc];
            pfVar29[-1] = 1.44881e-39;
            __strcpy_chk();
            goto LAB_000fc6b1;
          }
          *pfVar29 = (float)(pfVar29 + 0x33);
          pfVar29[0xe] = (float)(pfVar29 + 0x33);
          pfVar29[-1] = 1.448758e-39;
          __strcpy_chk();
          if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.is_building != 0) goto LAB_000fc975;
        }
        iVar23 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->playerclass;
      }
LAB_000fc210:
      if (iVar23 == 4) {
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.is_detpacking != 0) {
          pfVar29[0x56] = 2.748863e+26;
          pfVar29[0x53] = 4.4346525e+27;
          pfVar29[0x54] = 1.7441606e+28;
          pfVar29[0x55] = 7.269725e+31;
          pfVar29[0x57] = 9.498664e-39;
        }
        pfVar29[0xb] = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.respawn_time;
      }
      else {
        pfVar29[0xb] = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.respawn_time;
      }
      goto LAB_000fbc67;
    }
                    /* Unresolved local var: float flTimeToCheck@[???]
                       Unresolved local var: int iSecondsLeft@[???]
                       Unresolved local var: int iMinutesLeft@[???] */
    if (fVar37 < cb_prematch_time) goto LAB_000fbdb4;
    local_11c = 0x65645f72;
    local_118 = CONCAT13(local_118._3_1_,0x6461);
  }
  local_120 = 0x61625323;
  uStackY_2f0 = 0xfbbf1;
  fVar37 = ceilf(fVar38 - gpGlobals->time);
  iVar23 = (int)fVar37 % 0x3c;
  if ((int)fVar37 % 0x3c == 1) {
    aiStack_294[3] = 1;
    iVar23 = aiStack_294[1];
  }
  aiStack_294[1] = iVar23;
  uStackY_2f0 = 0xfbc34;
  fVar37 = ceilf(fVar38 - p1Var7->time);
  if ((int)(fVar37 / 60.0) == 1) {
    aiStack_294[4] = 1;
  }
  else {
    aiStack_294[2] = (int)(fVar37 / 60.0);
    pfVar29 = (float *)&stack0xfffffd14;
  }
LAB_000fbc67:
  if ((pfVar29[0xb] != 0.0) &&
     (bVar35 = gpGlobals->time == pfVar29[0xb], pfVar29[0xb] < gpGlobals->time)) {
    iVar23 = 0xb;
    piVar30 = (int *)(pfVar29 + 0x73);
    pcVar12 = "#Sbar_dead";
    do {
      if (iVar23 == 0) break;
      iVar23 = iVar23 + -1;
      bVar35 = (char)*piVar30 == *pcVar12;
      piVar30 = (int *)((int)piVar30 + (uint)bVar36 * -2 + 1);
      pcVar12 = pcVar12 + (uint)bVar36 * -2 + 1;
    } while (bVar35);
    if (bVar35) {
      *(undefined1 *)(pfVar29 + 0x73) = 0;
    }
  }
  pfVar29[1] = (float)this->m_SbarString0;
  *pfVar29 = pfVar29[0xe];
  pfVar29[-1] = 1.445254e-39;
  iVar23 = strcmp((char *)*pfVar29,(char *)pfVar29[1]);
  if (iVar23 != 0) {
    peVar22 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->pContainingEntity;
    *pfVar29 = 1.4013e-45;
    pfVar29[3] = (float)peVar22;
    pfVar29[2] = 0.0;
    pfVar29[1] = (float)gmsgStatusText;
    pfVar29[-1] = 1.44611e-39;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar29,(int)pfVar29[1],(float *)pfVar29[2],(edict_t *)pfVar29[3]);
    *pfVar29 = 0.0;
    pfVar29[-1] = 1.446129e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar29);
    iVar9 = (int)pfVar29[0xe];
    *pfVar29 = (float)iVar9;
    pfVar29[-1] = 1.446147e-39;
    (*g_engfuncs.pfnWriteString)((char *)*pfVar29);
    pfVar29[-1] = 1.446155e-39;
    (*g_engfuncs.pfnMessageEnd)();
    pfVar29[2] = 1.79366e-43;
    pfVar29[1] = (float)iVar9;
    *pfVar29 = (float)this->m_SbarString0;
    pfVar29[-1] = 1.446185e-39;
    __strcpy_chk();
  }
  pfVar29[1] = (float)this->m_SbarString1;
  *pfVar29 = pfVar29[0xc];
  pfVar29[-1] = 1.445296e-39;
  iVar9 = strcmp((char *)*pfVar29,(char *)pfVar29[1]);
  if (iVar9 != 0) {
    peVar22 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->pContainingEntity;
    *pfVar29 = 1.4013e-45;
    pfVar29[3] = (float)peVar22;
    pfVar29[2] = 0.0;
    pfVar29[1] = (float)gmsgStatusText;
    pfVar29[-1] = 1.445965e-39;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar29,(int)pfVar29[1],(float *)pfVar29[2],(edict_t *)pfVar29[3]);
    *pfVar29 = 1.4013e-45;
    pfVar29[-1] = 1.445983e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar29);
    iVar10 = (int)pfVar29[0xc];
    *pfVar29 = (float)iVar10;
    pfVar29[-1] = 1.446001e-39;
    (*g_engfuncs.pfnWriteString)((char *)*pfVar29);
    pfVar29[-1] = 1.44601e-39;
    (*g_engfuncs.pfnMessageEnd)();
    pfVar29[2] = 1.79366e-43;
    pfVar29[1] = (float)iVar10;
    *pfVar29 = (float)this->m_SbarString1;
    pfVar29[-1] = 1.446039e-39;
    __strcpy_chk();
  }
  pfVar29[1] = pfVar29[0xf];
  *pfVar29 = (float)(pfVar29 + 0x73);
  pfVar29[-1] = 1.44534e-39;
  iVar10 = strcmp((char *)*pfVar29,(char *)pfVar29[1]);
  if (iVar10 != 0) {
    peVar22 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->pContainingEntity;
    *pfVar29 = 1.4013e-45;
    pfVar29[3] = (float)peVar22;
    pfVar29[2] = 0.0;
    pfVar29[1] = (float)gmsgStatusText;
    pfVar29[-1] = 1.445797e-39;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar29,(int)pfVar29[1],(float *)pfVar29[2],(edict_t *)pfVar29[3]);
    *pfVar29 = 2.8026e-45;
    pfVar29[-1] = 1.445815e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar29);
    *pfVar29 = (float)(pfVar29 + 0x73);
    pfVar29[-1] = 1.445837e-39;
    (*g_engfuncs.pfnWriteString)((char *)*pfVar29);
    pfVar29[-1] = 1.445846e-39;
    (*g_engfuncs.pfnMessageEnd)();
    pfVar29[2] = 1.79366e-43;
    pfVar29[1] = (float)(pfVar29 + 0x73);
    *pfVar29 = pfVar29[0xf];
    pfVar29[-1] = 1.44589e-39;
    __strcpy_chk();
  }
                    /* Unresolved local var: int i@[???] */
  iVar31 = 1;
  do {
    while ((pfVar29[iVar31 + 0x16] != (float)this->m_izSBarState[iVar31] ||
           (iVar10 != 0 || (iVar9 != 0 || iVar23 != 0)))) {
      peVar22 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity;
      *pfVar29 = 1.4013e-45;
      pfVar29[3] = (float)peVar22;
      pfVar29[2] = 0.0;
      pfVar29[1] = (float)gmsgStatusValue;
      pfVar29[-1] = 1.445456e-39;
      (*g_engfuncs.pfnMessageBegin)
                ((int)*pfVar29,(int)pfVar29[1],(float *)pfVar29[2],(edict_t *)pfVar29[3]);
      *pfVar29 = (float)iVar31;
      pfVar29[-1] = 1.445469e-39;
      (*g_engfuncs.pfnWriteByte)((int)*pfVar29);
      *pfVar29 = pfVar29[iVar31 + 0x16];
      pfVar29[-1] = 1.445487e-39;
      (*g_engfuncs.pfnWriteShort)((int)*pfVar29);
      pfVar29[-1] = 1.445495e-39;
      (*g_engfuncs.pfnMessageEnd)();
      this->m_izSBarState[iVar31] = (int)pfVar29[iVar31 + 0x16];
      iVar31 = iVar31 + 1;
      if (iVar31 == 7) goto LAB_000fbd85;
    }
    iVar31 = iVar31 + 1;
  } while (iVar31 != 7);
LAB_000fbd85:
  if (pfVar29[0xb3] == (float)*(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  pfVar29[-1] = 1.451555e-39;
  __stack_chk_fail();
}


