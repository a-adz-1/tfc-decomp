// PM_Accelerate  @ 080676c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_Accelerate(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (((DAT_081051d4 == 0) &&
      ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
             (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) == 0x40)) &&
     (fVar1 = param_2 - (_DAT_0810518c * param_1[2] +
                        DAT_08105188 * param_1[1] + DAT_08105184 * *param_1),
     0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
    fVar2 = param_3 * frametime * param_2 * _DAT_081051c8;
    if (fVar1 < fVar2) {
      fVar2 = fVar1;
    }
    iVar3 = 0;
    do {
      (&DAT_08105184)[iVar3] = fVar2 * param_1[iVar3] + (&DAT_08105184)[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  return;
}


// PM_AddCorrectGravity  @ 08066aa0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_AddCorrectGravity(void)

{
  float fVar1;
  
  fVar1 = _DAT_081051c4;
  if ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051c4) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_081051c4 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = 1.0;
  }
  _DAT_0810518c =
       _DAT_081051a4 * frametime + (_DAT_0810518c - fVar1 * (float)movevars._4_4_ * 0.5 * frametime)
  ;
  _DAT_081051a4 = 0.0;
  PM_CheckVelocity();
  return;
}


// PM_AddGravity  @ 08068c50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_AddGravity(void)

{
  float fVar1;
  
  fVar1 = _DAT_081051c4;
  if ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051c4) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_081051c4 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = 1.0;
  }
  _DAT_0810518c =
       _DAT_081051a4 * frametime + (_DAT_0810518c - fVar1 * (float)movevars._4_4_ * frametime);
  _DAT_081051a4 = 0.0;
  PM_CheckVelocity();
  return;
}


// PM_AddToTouched  @ 08069d10
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
PM_AddToTouched(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               int param_13)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 in_stack_00000044;
  undefined4 *in_stack_00000048;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  iVar4 = 0;
  if (0 < DAT_081125d0) {
    do {
      if ((&DAT_08112604)[iVar4 * 0x11] == param_13) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_081125d0);
  }
  if (iVar4 == DAT_081125d0) {
    uVar3 = DAT_08105184;
    uVar1 = DAT_08105188;
    uVar2 = _DAT_0810518c;
    if (((byte)(0.0 < (float)pm_pushfix._12_4_ |
                (byte)((ushort)((ushort)NAN((float)pm_pushfix._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)pm_pushfix._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) &&
       (DAT_08105164 != 0)) {
      local_3c = param_1;
      local_38 = param_2;
      local_34 = param_3;
      local_30 = param_4;
      local_2c = param_5;
      local_28 = param_6;
      local_24 = param_7;
      local_20 = param_8;
      local_1c = param_9;
      local_18 = param_10;
      local_14 = param_11;
      local_10 = param_12;
      local_c = EDICT_NUM(*(undefined4 *)(&DAT_08105214 + (&DAT_08112604)[iVar4 * 0x11] * 0x58));
      iVar4 = sv_player;
      uVar2 = _DAT_0810518c;
      uVar1 = DAT_08105188;
      uVar3 = DAT_08105184;
      local_8 = in_stack_00000044;
      *(undefined4 *)(sv_player + 0xfc) = *in_stack_00000048;
      *(undefined4 *)(iVar4 + 0x100) = in_stack_00000048[1];
      *(undefined4 *)(iVar4 + 0x104) = in_stack_00000048[2];
      if (((*(byte *)(local_c + 0x263) & 4) == 0) && (DAT_081051d8 == 0)) {
        SV_Impact(local_c,iVar4,&local_3c);
      }
    }
    _DAT_0810518c = uVar2;
    DAT_08105188 = uVar1;
    DAT_08105184 = uVar3;
    if (599 < DAT_081125d0) {
      Con_DPrintf("Too many entities were touched!\n");
    }
    puVar5 = &DAT_081125d4 + DAT_081125d0 * 0x11;
    for (iVar4 = 0x11; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4),
        iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *(undefined4 *)register0x00000010;
      puVar5 = puVar5 + 1;
    }
    DAT_081125d0 = DAT_081125d0 + 1;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// PM_AirAccelerate  @ 08067770
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_AirAccelerate(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if ((DAT_081051d4 == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = param_2;
    if ((byte)(30.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 30.0) << 0xe) >> 8)) == 1) {
      fVar1 = 30.0;
    }
    fVar1 = fVar1 - (_DAT_0810518c * param_1[2] +
                    DAT_08105188 * param_1[1] + DAT_08105184 * *param_1);
    if (0.0 < fVar1) {
      fVar2 = param_3 * param_2 * frametime * _DAT_081051c8;
      if (fVar1 < fVar2) {
        fVar2 = fVar1;
      }
      iVar3 = 0;
      do {
        (&DAT_08105184)[iVar3] = fVar2 * param_1[iVar3] + (&DAT_08105184)[iVar3];
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
    }
  }
  return;
}


// PM_AirMove  @ 08067b40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_AirMove(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10 [3];
  
  fVar2 = _DAT_081125c0;
  fVar1 = _DAT_081125bc;
  _DAT_080ca0f0 = 0;
  _DAT_080c9e9c = 0;
  VectorNormalize(&forward);
  VectorNormalize(&right);
  iVar3 = 0;
  do {
    local_10[iVar3] = fVar2 * (float)(&right)[iVar3] + fVar1 * (float)(&forward)[iVar3];
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  local_10[2] = 0.0;
  local_1c = local_10[0];
  local_18 = local_10[1];
  local_14 = 0;
  lVar4 = (longdouble)VectorNormalize(&local_1c);
  if ((longdouble)_DAT_081051e0 < lVar4) {
    VectorScale(local_10,(float)((longdouble)_DAT_081051e0 / lVar4),local_10);
    lVar4 = (longdouble)_DAT_081051e0;
  }
  PM_AirAccelerate(&local_1c,(float)lVar4,movevars._24_4_);
  DAT_08105184 = DAT_08105184 + _DAT_0810519c;
  DAT_08105188 = DAT_08105188 + _DAT_081051a0;
  _DAT_0810518c = _DAT_0810518c + _DAT_081051a4;
  PM_FlyMove();
  return;
}


// PM_CatagorizePosition  @ 08067c70
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_CatagorizePosition(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int aiStack_ac [14];
  undefined4 uStack_74;
  int *piStack_70;
  undefined4 *puStack_6c;
  undefined4 *puStack_68;
  undefined4 uStack_64;
  int local_54 [5];
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_2c;
  int local_24;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  uStack_64 = 0x8067c7d;
  PM_CheckWater();
  local_10 = DAT_0810516c;
  local_c = DAT_08105170;
  local_8 = _DAT_08105174 - 2.0;
  if ((byte)(180.0 < _DAT_0810518c | (byte)((ushort)((ushort)NAN(_DAT_0810518c) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_0810518c == 180.0) << 0xe) >> 8)) == 1) {
    onground = -1;
  }
  else {
    piStack_70 = local_54;
    uStack_64 = 0;
    puStack_68 = &local_10;
    puStack_6c = &DAT_0810516c;
    uStack_74 = 0x8067ce4;
    PM_PlayerMove();
    if (0.7 <= local_2c) {
      onground = local_24;
    }
    else {
      onground = -1;
    }
    if ((((onground != -1) && (_DAT_081051d0 = 0, waterlevel < 2)) && (local_54[1] == 0)) &&
       (local_54[0] == 0)) {
      DAT_0810516c = local_40;
      DAT_08105170 = local_3c;
      _DAT_08105174 = local_38;
    }
    if (0 < local_24) {
      puStack_68 = &DAT_08105184;
      piVar2 = local_54;
      piVar3 = aiStack_ac;
      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar3 = *piVar2;
        piVar2 = piVar2 + 1;
        piVar3 = piVar3 + 1;
      }
      PM_AddToTouched();
    }
  }
  return;
}


// PM_CheckStuck  @ 08068560
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PM_CheckStuck(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  longdouble lVar12;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  lVar12 = (longdouble)Sys_FloatTime();
  ft_150._0_4_ = (undefined4)lVar12;
  local_2c = (float)ft_150._0_4_;
  iVar5 = PM_TestPlayerPosition(&DAT_0810516c);
  lVar12 = (longdouble)Sys_FloatTime();
  ft_150._4_4_ = (undefined4)lVar12;
  local_2c = (float)ft_150._4_4_;
  if (iVar5 == -1) {
    ResetStuckOffsets(pmove,DAT_08105164);
LAB_080685af:
    uVar6 = 0;
  }
  else {
    local_10 = DAT_0810516c;
    local_c = DAT_08105170;
    local_8 = _DAT_08105174;
    if ((DAT_08105164 == 0) && ((iVar5 == 0 || ((&DAT_081051f4)[iVar5 * 0x16] != 0)))) {
      iVar10 = 0;
      ResetStuckOffsets(pmove,0);
      do {
        GetRandomStuckOffsets(pmove,DAT_08105164,&local_1c);
        local_28 = local_10 + local_1c;
        local_24 = local_c + local_18;
        local_20 = local_8 + local_14;
        iVar7 = PM_TestPlayerPosition(&local_28);
        if (iVar7 == -1) {
          ResetStuckOffsets(pmove,DAT_08105164);
          goto LAB_08068891;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0x36);
    }
    bVar11 = DAT_08105164 == 0;
    lVar12 = (longdouble)Sys_FloatTime();
    local_2c = (float)lVar12;
    fVar4 = local_2c - 0.05;
    fVar1 = *(float *)(rgStuckCheckTime_151 + (uint)bVar11 * 4 + pmove * 8);
    if (0x3f < (byte)((fVar4 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar4 == fVar1) << 0xe) >> 8)) - 1)) {
      *(float *)(rgStuckCheckTime_151 + pmove * 8 + (uint)bVar11 * 4) = local_2c;
      if (((DAT_08105164 != 0) && (DAT_081051d8 == 0)) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)pm_nostucktouch._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)pm_nostucktouch._12_4_ == 0.0) << 0xe) >> 8)) ==
          0x40)) {
        iVar5 = *(int *)(&DAT_08105214 + iVar5 * 0x58);
        iVar7 = EDICT_NUM(iVar5);
        iVar10 = sv_player;
        if ((*(byte *)(iVar7 + 0x263) & 4) == 0) {
          iVar9 = iVar5;
          if (iVar5 < 0) {
            iVar9 = iVar5 + 7;
          }
          iVar8 = iVar5;
          if (iVar5 < 0) {
            iVar8 = iVar5 + 7;
          }
          if ((*(byte *)((iVar9 >> 3) + g_playertouch) >>
               (iVar5 - (uint)((byte)iVar8 & 0xf8) & 0x1f) & 1) == 0) {
            local_64 = g_Trace;
            local_60 = DAT_0811c544;
            local_5c = DAT_0811c548;
            local_58 = DAT_0811c54c;
            local_54 = DAT_0811c550;
            local_50 = DAT_0811c554;
            local_4c = DAT_0811c558;
            local_48 = DAT_0811c55c;
            local_44 = DAT_0811c560;
            local_40 = DAT_0811c564;
            local_3c = DAT_0811c568;
            local_38 = DAT_0811c56c;
            local_30 = DAT_0811c580;
            uVar6 = *(undefined4 *)(sv_player + 0xfc);
            uVar2 = *(undefined4 *)(sv_player + 0x100);
            uVar3 = *(undefined4 *)(sv_player + 0x104);
            *(undefined4 *)(sv_player + 0xfc) = DAT_08105184;
            *(undefined4 *)(iVar10 + 0x100) = DAT_08105188;
            *(undefined4 *)(iVar10 + 0x104) = _DAT_0810518c;
            local_34 = iVar7;
            SV_SetGlobalTrace(&local_64);
            (*DAT_08178eb0)(iVar7,sv_player);
            iVar5 = sv_player;
            *(undefined4 *)(sv_player + 0xfc) = uVar6;
            *(undefined4 *)(iVar5 + 0x100) = uVar2;
            *(undefined4 *)(iVar5 + 0x104) = uVar3;
          }
        }
      }
      iVar5 = GetRandomStuckOffsets(pmove,DAT_08105164,&local_1c);
      local_28 = local_10 + local_1c;
      local_24 = local_c + local_18;
      local_20 = local_8 + local_14;
      iVar10 = PM_TestPlayerPosition(&local_28);
      if (iVar10 == -1) {
        ResetStuckOffsets(pmove,DAT_08105164);
        if (0x1a < iVar5) {
LAB_08068891:
          DAT_0810516c = local_28;
          DAT_08105170 = local_24;
          _DAT_08105174 = local_20;
        }
        goto LAB_080685af;
      }
      lVar12 = (longdouble)Sys_FloatTime();
      ft_150._8_4_ = (undefined4)lVar12;
    }
    uVar6 = 1;
  }
  return uVar6;
}


// PM_CheckVelocity  @ 08066920
void PM_CheckVelocity(void)

{
  float fVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (((&DAT_08105184)[iVar2] & nanmask) == nanmask) {
      Con_Printf("PM  Got a NaN velocity %i\n",iVar2);
      (&DAT_08105184)[iVar2] = 0;
    }
    if (((&DAT_0810516c)[iVar2] & nanmask) == nanmask) {
      Con_Printf("PM  Got a NaN origin on %i\n",iVar2);
      (&DAT_0810516c)[iVar2] = 0;
    }
    if ((float)(&DAT_08105184)[iVar2] <= (float)movevars._56_4_) {
      if ((float)(&DAT_08105184)[iVar2] < -(float)movevars._56_4_) {
        Con_DPrintf("PM  Got a velocity too low on %i\n",iVar2);
        fVar1 = -(float)movevars._56_4_;
        goto LAB_080669e1;
      }
    }
    else {
      Con_DPrintf("PM  Got a velocity too high on %i\n",iVar2);
      fVar1 = (float)movevars._56_4_;
LAB_080669e1:
      (&DAT_08105184)[iVar2] = fVar1;
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return;
    }
  } while( true );
}


// PM_CheckWater  @ 08067f80
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool PM_CheckWater(void)

{
  int iVar1;
  int iVar2;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = DAT_081051c0 * 0xc;
  local_10 = ((float)(&player_mins)[DAT_081051c0 * 3] + *(float *)(player_maxs + iVar1)) * 0.5 +
             DAT_0810516c;
  local_c = ((float)(&DAT_080aae04)[DAT_081051c0 * 3] + *(float *)(player_maxs + iVar1 + 4)) * 0.5 +
            DAT_08105170;
  local_8 = _DAT_08105174 + *(float *)(&DAT_080aae08 + iVar1) + 1.0;
  waterlevel = 0;
  watertype = -1;
  iVar1 = PM_PointContents(&local_10);
  if (iVar1 + 0xeU < 0xc) {
    iVar2 = PM_TruePointContents(&local_10);
    waterlevel = 1;
    local_8 = (*(float *)(&DAT_080aae08 + DAT_081051c0 * 0xc) +
              *(float *)(player_maxs + DAT_081051c0 * 0xc + 8)) * 0.5 + _DAT_08105174;
    watertype = iVar1;
    iVar1 = PM_PointContents(&local_10);
    if (iVar1 + 0xeU < 0xc) {
      waterlevel = 2;
      local_8 = _DAT_08105174 + _DAT_081051b0;
      iVar1 = PM_PointContents(&local_10);
      if (iVar1 + 0xeU < 0xc) {
        waterlevel = 3;
      }
    }
    if (iVar2 + 0xeU < 6) {
      VectorMA(&DAT_0810519c,(float)waterlevel * 50.0,&current_table_141 + (-9 - iVar2) * 0xc,
               &DAT_0810519c);
    }
  }
  return 1 < waterlevel;
}


// PM_ClipVelocity  @ 08066a00
byte PM_ClipVelocity(float *param_1,float *param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  byte bVar9;
  
  fVar1 = param_2[2];
  bVar9 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar9 = bVar9 | 2;
  }
  fVar1 = *param_1;
  fVar2 = *param_2;
  fVar3 = param_1[1];
  fVar4 = param_2[1];
  fVar5 = param_1[2];
  fVar6 = param_2[2];
  iVar8 = 0;
  do {
    fVar7 = param_1[iVar8] -
            (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2) * param_4 * param_2[iVar8];
    *(float *)(param_3 + iVar8 * 4) = fVar7;
    if ((-0.1 < fVar7) &&
       ((byte)(fVar7 < 0.1 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar7 == 0.1) << 0xe) >> 8)) == 1)) {
      *(undefined4 *)(param_3 + iVar8 * 4) = 0;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 3);
  return bVar9;
}


// PM_DrawBBox  @ 08066800
void PM_DrawBBox(float *param_1,float *param_2,float *param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  float local_70 [24];
  float local_10;
  float local_c;
  float local_8;
  
  uVar1 = 0;
  do {
    if ((uVar1 & 1) == 0) {
      local_10 = *param_2 + 0.0;
    }
    else {
      local_10 = *param_1 - 0.0;
    }
    if ((uVar1 & 2) == 0) {
      local_c = param_2[1] + 0.0;
    }
    else {
      local_c = param_1[1] - 0.0;
    }
    if ((uVar1 & 4) == 0) {
      local_8 = param_2[2] + 0.0;
    }
    else {
      local_8 = param_1[2] - 0.0;
    }
    local_10 = local_10 + *param_3;
    local_c = local_c + param_3[1];
    local_8 = local_8 + param_3[2];
    local_70[uVar1 * 3] = local_10;
    local_70[uVar1 * 3 + 1] = local_c;
    local_70[uVar1 * 3 + 2] = local_8;
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 8);
  iVar2 = 0;
  do {
    PM_DrawRectangle(local_70 + (&DAT_080aae84)[iVar2 * 4] * 3,
                     local_70 + (&PM_boxpnt)[iVar2 * 4] * 3,
                     local_70 + (&DAT_080aae88)[iVar2 * 4] * 3,
                     local_70 + (&DAT_080aae8c)[iVar2 * 4] * 3,param_4,param_5);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  return;
}


// PM_DrawPhysEntBBox  @ 080664b0
void PM_DrawPhysEntBBox(int param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c [24];
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((param_1 < DAT_081051e4) && (0 < param_1)) {
    iVar3 = param_1 * 0x58;
    if ((&DAT_081051f4)[param_1 * 0x16] == 0) {
      uVar2 = 0;
      do {
        if ((uVar2 & 1) == 0) {
          local_1c = *(float *)(&DAT_08105208 + iVar3);
        }
        else {
          local_1c = *(float *)(&DAT_081051fc + iVar3);
        }
        if ((uVar2 & 2) == 0) {
          local_18 = *(float *)(&DAT_0810520c + iVar3);
        }
        else {
          local_18 = *(float *)(&DAT_08105200 + iVar3);
        }
        if ((uVar2 & 4) == 0) {
          local_14 = *(float *)(&DAT_08105210 + iVar3);
        }
        else {
          local_14 = *(float *)(&DAT_08105204 + iVar3);
        }
        local_1c = local_1c + (float)(&DAT_081051e8)[param_1 * 0x16];
        local_18 = local_18 + (float)(&DAT_081051ec)[param_1 * 0x16];
        local_14 = local_14 + (float)(&DAT_081051f0)[param_1 * 0x16];
        local_7c[uVar2 * 3] = local_1c;
        local_7c[uVar2 * 3 + 1] = local_18;
        local_7c[uVar2 * 3 + 2] = local_14;
        uVar2 = uVar2 + 1;
      } while ((int)uVar2 < 8);
      iVar3 = 0;
      do {
        PM_DrawRectangle(local_7c + (&DAT_080aae84)[iVar3 * 4] * 3,
                         local_7c + (&PM_boxpnt)[iVar3 * 4] * 3,
                         local_7c + (&DAT_080aae88)[iVar3 * 4] * 3,
                         local_7c + (&DAT_080aae8c)[iVar3 * 4] * 3,param_2,param_3);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 6);
    }
    else {
      local_10 = (float)(&DAT_081051e8)[param_1 * 0x16];
      local_c = (float)(&DAT_081051ec)[param_1 * 0x16];
      local_8 = (float)(&DAT_081051f0)[param_1 * 0x16];
      uVar2 = 0;
      do {
        if ((uVar2 & 1) == 0) {
          local_1c = *(float *)((&DAT_081051f4)[param_1 * 0x16] + 0x60) + 0.0;
        }
        else {
          local_1c = *(float *)((&DAT_081051f4)[param_1 * 0x16] + 0x54) - 0.0;
        }
        if ((uVar2 & 2) == 0) {
          local_18 = *(float *)((&DAT_081051f4)[param_1 * 0x16] + 100) + 0.0;
        }
        else {
          local_18 = *(float *)((&DAT_081051f4)[param_1 * 0x16] + 0x58) - 0.0;
        }
        if ((uVar2 & 4) == 0) {
          local_14 = *(float *)((&DAT_081051f4)[param_1 * 0x16] + 0x68) + 0.0;
        }
        else {
          local_14 = *(float *)((&DAT_081051f4)[param_1 * 0x16] + 0x5c) - 0.0;
        }
        local_7c[uVar2 * 3] = local_1c;
        local_7c[uVar2 * 3 + 1] = local_18;
        local_7c[uVar2 * 3 + 2] = local_14;
        uVar2 = uVar2 + 1;
      } while ((int)uVar2 < 8);
      if ((((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_08105218)[param_1 * 0x16]) << 10) >> 8)
                  | (byte)((ushort)((ushort)((float)(&DAT_08105218)[param_1 * 0x16] == 0.0) << 0xe)
                          >> 8)) != 0x40) ||
          ((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_0810521c)[param_1 * 0x16]) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)(&DAT_0810521c)[param_1 * 0x16] == 0.0) << 0xe) >>
                       8)) != 0x40)) ||
         (fVar1 = (float)(&DAT_08105220)[param_1 * 0x16],
         (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
        AngleVectorsTranspose(&DAT_08105218 + param_1 * 0x16,&local_88,&local_94,&local_a0);
        iVar3 = 0;
        do {
          local_1c = local_7c[iVar3 * 3];
          local_18 = local_7c[iVar3 * 3 + 1];
          local_14 = local_7c[iVar3 * 3 + 2];
          local_7c[iVar3 * 3] = local_14 * local_80 + local_18 * local_84 + local_1c * local_88;
          local_7c[iVar3 * 3 + 1] = local_14 * local_8c + local_18 * local_90 + local_1c * local_94;
          local_7c[iVar3 * 3 + 2] = local_14 * local_98 + local_18 * local_9c + local_1c * local_a0;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 8);
      }
      iVar3 = 0;
      do {
        local_7c[iVar3 * 3] = local_7c[iVar3 * 3] + local_10;
        local_7c[iVar3 * 3 + 1] = local_7c[iVar3 * 3 + 1] + local_c;
        local_7c[iVar3 * 3 + 2] = local_7c[iVar3 * 3 + 2] + local_8;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 8);
      iVar3 = 0;
      do {
        PM_DrawRectangle(local_7c + (&DAT_080aae84)[iVar3 * 4] * 3,
                         local_7c + (&PM_boxpnt)[iVar3 * 4] * 3,
                         local_7c + (&DAT_080aae88)[iVar3 * 4] * 3,
                         local_7c + (&DAT_080aae8c)[iVar3 * 4] * 3,param_2,param_3);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 6);
    }
  }
  return;
}


// PM_DrawRectangle  @ 08066450
void PM_DrawRectangle(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  PM_ParticleLine(param_1,param_2,param_5,param_6,0);
  PM_ParticleLine(param_2,param_4,param_5,param_6,0);
  PM_ParticleLine(param_4,param_3,param_5,param_6,0);
  PM_ParticleLine(param_3,param_1,param_5,param_6,0);
  return;
}


// PM_Duck  @ 080695c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_Duck(void)

{
  double dVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char **ppcVar6;
  longdouble lVar7;
  char *pcStack_74;
  float local_68;
  undefined4 local_64;
  char *pcStack_60;
  float local_58 [4];
  int local_48;
  float local_8;
  
  uVar3 = _DAT_081125ca ^ DAT_081051cc;
  uVar5 = uVar3 & _DAT_081125ca;
  pcStack_74 = (char *)(uVar5 >> 2 & 1);
  Con_Printf("btn %i bInDuck %i FL_DUCKING %i ofs %.2f h %i ch %i pr %i",_DAT_081125ca >> 2 & 1,
             DAT_081051b8 != 0,DAT_081051bc >> 0xe & 1,(double)_DAT_081051b0,DAT_081051c0,
             uVar3 >> 2 & 1);
  if ((((_DAT_081125ca & 4) != 0) || (DAT_081051b8 != 0)) ||
     (ppcVar6 = (char **)&stack0xffffff90, (DAT_081051bc & 0x4000) != 0)) {
    if ((_DAT_081125ca & 4) == 0) {
      local_58[0] = DAT_0810516c;
      local_58[1] = (float)DAT_08105170;
      local_58[2] = (float)_DAT_08105174;
      if (onground != -1) {
        iVar4 = 0;
        do {
          local_58[iVar4] =
               ((float)(&DAT_080aae0c)[iVar4] - (float)(&player_mins)[iVar4]) + local_58[iVar4];
          iVar4 = iVar4 + 1;
        } while (iVar4 < 3);
      }
      pcStack_74 = (char *)0x0;
      PM_PlayerMove();
      ppcVar6 = &pcStack_74;
      if (local_48 == 0) {
        DAT_081051bc = DAT_081051bc & 0xffffbfff;
        DAT_081051b8 = 0;
        _DAT_081051b0 = 28.0;
        DAT_081051c0 = 0;
        DAT_0810516c = local_58[0];
        DAT_08105170 = local_58[1];
        _DAT_08105174 = local_58[2];
      }
      else {
        Con_Printf("Stuck on up\n");
        ppcVar6 = &pcStack_74;
      }
    }
    else {
      _DAT_081125bc = _DAT_081125bc * 0.333;
      _DAT_081125c0 = _DAT_081125c0 * 0.333;
      _DAT_081125c4 = _DAT_081125c4 * 0.333;
      local_8 = _DAT_081125c4;
      if (((uVar5 & 4) != 0) && ((DAT_081051bc & 0x4000) == 0)) {
        _DAT_081051b4 = _DAT_08105168;
        DAT_081051b8 = 1;
        pcStack_74 = "(new)";
        Con_Printf();
      }
      fVar2 = (_DAT_08105168 - _DAT_081051b4) / 1000.0;
      dVar1 = (double)fVar2;
      pcStack_60 = (char *)((ulonglong)dVar1 >> 0x20);
      pcStack_74 = pcStack_60;
      local_64 = SUB84(dVar1,0);
      Con_Printf("e %.2f",local_64);
      ppcVar6 = (char **)&stack0xffffff90;
      if (DAT_081051b8 != 0) {
        if (((byte)((0.4 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(dVar1 == 0.4) << 0xe) >> 8)) - 1) < 0x40) ||
           (onground == -1)) {
          if (onground != -1) {
            iVar4 = 0;
            do {
              (&DAT_0810516c)[iVar4] =
                   (&DAT_0810516c)[iVar4] -
                   ((float)(&DAT_080aae0c)[iVar4] - (float)(&player_mins)[iVar4]);
              iVar4 = iVar4 + 1;
            } while (iVar4 < 3);
            pcStack_74 = (char *)0x8069762;
            PM_FixPlayerCrouchStuck();
          }
          DAT_081051c0 = 1;
          _DAT_081051b0 = 12.0;
          DAT_081051bc = DAT_081051bc | 0x4000;
          DAT_081051b8 = 0;
          ppcVar6 = (char **)&stack0xffffff90;
        }
        else {
          local_68 = 0.0;
          if (DAT_08105164 != 0) {
            local_68 = 18.0;
          }
          pcStack_74 = (char *)0x40200000;
          lVar7 = (longdouble)PM_SplineFraction(fVar2);
          _DAT_081051b0 =
               (float)(((longdouble)12.0 - (longdouble)local_68) * lVar7 +
                      (longdouble)28.0 * ((longdouble)1 - lVar7));
          ppcVar6 = (char **)&stack0xffffff90;
        }
      }
    }
  }
  *(undefined **)((int)ppcVar6 + -4) = &DAT_080a2a33;
  *(undefined4 *)((int)ppcVar6 + -8) = 0x80698a7;
  Con_Printf();
  return;
}


// PM_FixPlayerCrouchStuck  @ 08069510
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_FixPlayerCrouchStuck(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = PM_TestPlayerPosition(&DAT_0810516c);
  fVar3 = _DAT_08105174;
  uVar2 = DAT_08105170;
  uVar1 = DAT_0810516c;
  if (iVar4 != -1) {
    iVar4 = 0;
    do {
      _DAT_08105174 = _DAT_08105174 + 1.0;
      iVar5 = PM_TestPlayerPosition(&DAT_0810516c);
      if (iVar5 == -1) {
        Con_Printf(" fix %i",iVar4);
        return;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x12);
    Con_Printf(" stuck");
  }
  DAT_0810516c = uVar1;
  DAT_08105170 = uVar2;
  _DAT_08105174 = fVar3;
  return;
}


// PM_FixupGravityVelocity  @ 08066b10
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_FixupGravityVelocity(void)

{
  float fVar1;
  
  fVar1 = _DAT_081051c4;
  if ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051c4) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_081051c4 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = 1.0;
  }
  _DAT_0810518c = _DAT_0810518c - fVar1 * (float)movevars._4_4_ * frametime * 0.5;
  PM_CheckVelocity();
  return;
}


// PM_FlyMove  @ 08066b60
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint PM_FlyMove(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 auStack_140 [12];
  int aiStack_110 [2];
  float local_108;
  int aiStack_104 [3];
  float local_f8 [2];
  uint uVar7;
  float local_d4;
  float local_d0;
  int local_cc;
  int local_c8;
  float local_c0 [3];
  int local_b4 [4];
  float local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c [3];
  undefined1 local_40 [48];
  float local_10;
  float local_c;
  float local_8;
  
  uVar7 = 0;
  local_cc = 0;
  local_64 = DAT_08105184;
  local_60 = DAT_08105188;
  local_5c = _DAT_0810518c;
  local_58 = DAT_08105184;
  local_54 = DAT_08105188;
  local_50 = _DAT_0810518c;
  local_d4 = 0.0;
  local_d0 = frametime;
  local_c8 = 0;
  puVar4 = &stack0xffffff10;
  while( true ) {
    if ((((byte)((byte)((ushort)((ushort)NAN(DAT_08105184) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_08105184 == 0.0) << 0xe) >> 8)) == 0x40) &&
        ((byte)((byte)((ushort)((ushort)NAN(DAT_08105188) << 10) >> 8) |
               (byte)((ushort)((ushort)(DAT_08105188 == 0.0) << 0xe) >> 8)) == 0x40)) &&
       ((byte)(_DAT_0810518c < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_0810518c) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_0810518c == 0.0) << 0xe) >> 8)) == 0x40))
    goto LAB_08067053;
    iVar3 = 0;
    do {
      local_c0[iVar3] = local_d0 * (&DAT_08105184)[iVar3] + (float)(&DAT_0810516c)[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    *(undefined4 *)(puVar4 + -4) = 0;
    *(float **)(puVar4 + -8) = local_c0;
    *(undefined4 **)(puVar4 + -0xc) = &DAT_0810516c;
    *(int **)(puVar4 + -0x10) = local_b4;
    *(undefined4 *)(puVar4 + -0x14) = 0x8066c56;
    PM_PlayerMove();
    local_d4 = local_d4 + local_a4;
    if (local_b4[0] != 0) {
      DAT_08105184 = (float)vec3_origin._0_4_;
      DAT_08105188 = (float)vec3_origin._4_4_;
      _DAT_0810518c = (float)vec3_origin._8_4_;
      return 4;
    }
    if (0.0 < local_a4) {
      DAT_0810516c = local_a0;
      DAT_08105170 = local_9c;
      _DAT_08105174 = local_98;
      local_64 = DAT_08105184;
      local_60 = DAT_08105188;
      local_5c = _DAT_0810518c;
      local_cc = 0;
    }
    if ((byte)(1.0 < local_a4 | (byte)((ushort)((ushort)NAN(local_a4) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_a4 == 1.0) << 0xe) >> 8)) == 0x40) goto LAB_08067053;
    *(float **)(puVar4 + -8) = &DAT_08105184;
    piVar5 = local_b4;
    piVar6 = (int *)(puVar4 + -0x4c);
    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 1;
    }
    *(undefined4 *)(puVar4 + -0x50) = 0x8066d41;
    PM_AddToTouched();
    if ((byte)(0.7 < local_8c | (byte)((ushort)((ushort)NAN(local_8c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_8c == 0.7) << 0xe) >> 8)) == 1) {
      uVar7 = uVar7 | 1;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_8c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_8c == 0.0) << 0xe) >> 8)) == 0x40) {
      uVar7 = uVar7 | 2;
    }
    local_d0 = local_d0 - local_d0 * local_a4;
    if (4 < local_cc) break;
    local_4c[local_cc * 3] = local_94;
    local_4c[local_cc * 3 + 1] = local_90;
    local_4c[local_cc * 3 + 2] = local_8c;
    local_cc = local_cc + 1;
    if ((DAT_081051dc == 3) &&
       ((onground == -1 ||
        ((byte)(1.0 < _DAT_081051c8 | (byte)((ushort)((ushort)NAN(_DAT_081051c8) << 10) >> 8) |
               (byte)((ushort)((ushort)(_DAT_081051c8 == 1.0) << 0xe) >> 8)) != 0x40)))) {
      iVar3 = 0;
      if (0 < local_cc) {
        do {
          fVar1 = local_4c[iVar3 * 3 + 2];
          if ((byte)(0.7 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.7) << 0xe) >> 8)) == 1) {
            *(undefined4 *)(puVar4 + -8) = 0x3f800000;
            *(float **)(puVar4 + -0xc) = &local_70;
            *(float **)(puVar4 + -0x10) = local_4c + iVar3 * 3;
            *(float **)(puVar4 + -0x14) = &local_64;
            *(undefined4 *)(puVar4 + -0x18) = 0x8066e49;
            PM_ClipVelocity();
            local_64 = local_70;
            local_60 = local_6c;
            local_5c = local_68;
          }
          else {
            *(float *)(puVar4 + -8) = (1.0 - _DAT_081051c8) * (float)movevars._48_4_ + 1.0;
            *(float **)(puVar4 + -0xc) = &local_70;
            *(float **)(puVar4 + -0x10) = local_4c + iVar3 * 3;
            *(float **)(puVar4 + -0x14) = &local_64;
            *(undefined4 *)(puVar4 + -0x18) = 0x8066e95;
            PM_ClipVelocity();
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_cc);
      }
      DAT_08105184 = local_70;
      DAT_08105188 = local_6c;
      _DAT_0810518c = local_68;
      local_64 = local_70;
      local_60 = local_6c;
      local_5c = local_68;
    }
    else {
      iVar3 = 0;
      if (0 < local_cc) {
        do {
          *(undefined4 *)(puVar4 + -8) = 0x3f800000;
          *(float **)(puVar4 + -0xc) = &DAT_08105184;
          *(float **)(puVar4 + -0x10) = local_4c + iVar3 * 3;
          *(float **)(puVar4 + -0x14) = &local_64;
          *(undefined4 *)(puVar4 + -0x18) = 0x8066f08;
          PM_ClipVelocity();
          iVar2 = 0;
          if (0 < local_cc) {
            do {
              if ((iVar2 != iVar3) &&
                 (fVar1 = _DAT_0810518c * local_4c[iVar2 * 3 + 2] +
                          DAT_08105188 * local_4c[iVar2 * 3 + 1] +
                          DAT_08105184 * local_4c[iVar2 * 3],
                 (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) break;
              iVar2 = iVar2 + 1;
            } while (iVar2 < local_cc);
          }
        } while ((iVar2 != local_cc) && (iVar3 = iVar3 + 1, iVar3 < local_cc));
      }
      if (iVar3 == local_cc) {
        if (local_cc != 2) break;
        *(float **)(puVar4 + -8) = &local_10;
        *(undefined1 **)(puVar4 + -0xc) = local_40;
        *(float **)(puVar4 + -0x10) = local_4c;
        *(undefined4 *)(puVar4 + -0x14) = 0x8066fab;
        CrossProduct();
        *(float **)(puVar4 + -0x14) = &DAT_08105184;
        *(float *)(puVar4 + -0x18) =
             local_8 * _DAT_0810518c + local_c * DAT_08105188 + local_10 * DAT_08105184;
        *(float **)(puVar4 + -0x1c) = &local_10;
        *(undefined4 *)(puVar4 + -0x20) = 0x8066fdb;
        VectorScale();
      }
      fVar1 = _DAT_0810518c * local_50 + DAT_08105188 * local_54 + DAT_08105184 * local_58;
      if ((byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) break;
    }
    local_c8 = local_c8 + 1;
    puVar4 = puVar4 + -4;
    if (3 < local_c8) {
LAB_08067053:
      if ((byte)((byte)((ushort)((ushort)NAN(local_d4) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_d4 == 0.0) << 0xe) >> 8)) == 0x40) {
        DAT_08105184 = (float)vec3_origin._0_4_;
        DAT_08105188 = (float)vec3_origin._4_4_;
        _DAT_0810518c = (float)vec3_origin._8_4_;
      }
      return uVar7;
    }
  }
  DAT_08105184 = (float)vec3_origin._0_4_;
  DAT_08105188 = (float)vec3_origin._4_4_;
  _DAT_0810518c = (float)vec3_origin._8_4_;
  goto LAB_08067053;
}


// PM_Friction  @ 08067520
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_Friction(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_78;
  undefined1 local_70 [16];
  float local_60;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  if (((byte)((byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
             (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) == 0x40) &&
     (fVar1 = SQRT(_DAT_0810518c * _DAT_0810518c +
                   DAT_08105188 * DAT_08105188 + DAT_08105184 * DAT_08105184), 0.1 <= fVar1)) {
    local_78 = 0.0;
    if (onground != -1) {
      local_2c = (DAT_08105184 / fVar1) * 16.0 + DAT_0810516c;
      local_28 = (DAT_08105188 / fVar1) * 16.0 + DAT_08105170;
      local_18 = _DAT_08105174 + *(float *)(&DAT_080aae08 + DAT_081051c0 * 0xc);
      local_24 = local_18 - 34.0;
      local_20 = local_2c;
      local_1c = local_28;
      PM_PlayerMove(local_70,&local_20,&local_2c,0);
      fVar2 = (float)movevars._32_4_;
      if ((byte)((byte)((ushort)((ushort)NAN(local_60) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_60 == 1.0) << 0xe) >> 8)) == 0x40) {
        fVar2 = (float)movevars._32_4_ * (float)movevars._36_4_;
      }
      fVar3 = fVar1;
      if ((byte)(fVar1 < (float)movevars._8_4_ |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN((float)movevars._8_4_)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == (float)movevars._8_4_) << 0xe) >> 8)) == 1) {
        fVar3 = (float)movevars._8_4_;
      }
      local_78 = fVar3 * fVar2 * _DAT_081051c8 * frametime + 0.0;
    }
    local_78 = fVar1 - local_78;
    if (local_78 < 0.0) {
      local_78 = 0.0;
    }
    local_78 = local_78 / fVar1;
    DAT_08105184 = local_78 * DAT_08105184;
    DAT_08105188 = local_78 * DAT_08105188;
    _DAT_0810518c = local_78 * _DAT_0810518c;
  }
  return;
}


// PM_HullForBox  @ 08069fe0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * PM_HullForBox(undefined4 *param_1,undefined4 *param_2)

{
  _DAT_080c54ec = *param_2;
  _DAT_080c5500 = *param_1;
  _DAT_080c5514 = param_2[1];
  _DAT_080c5528 = param_1[1];
  _DAT_080c553c = param_2[2];
  _DAT_080c5550 = param_1[2];
  return box_hull;
}


// PM_HullForBsp  @ 0806a6f0
int PM_HullForBsp(float *param_1,float *param_2)

{
  int in_ECX;
  
  if (DAT_081051c0 == 1) {
    in_ECX = (int)param_1[3] + 0x148;
  }
  else if (DAT_081051c0 < 2) {
    if (DAT_081051c0 == 0) {
      in_ECX = (int)param_1[3] + 0xf8;
    }
  }
  else if (DAT_081051c0 == 2) {
    in_ECX = (int)param_1[3] + 0xd0;
  }
  *param_2 = *(float *)(in_ECX + 0x10) - (float)(&player_mins)[DAT_081051c0 * 3];
  param_2[1] = *(float *)(in_ECX + 0x14) - (float)(&DAT_080aae04)[DAT_081051c0 * 3];
  param_2[2] = *(float *)(in_ECX + 0x18) - *(float *)(&DAT_080aae08 + DAT_081051c0 * 0xc);
  *param_2 = *param_2 + *param_1;
  param_2[1] = param_2[1] + param_1[1];
  param_2[2] = param_2[2] + param_1[2];
  return in_ECX;
}


// PM_HullForStudioModel  @ 0806a650
void PM_HullForStudioModel
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9)

{
  int iVar1;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = DAT_081051c0 * 0xc;
  local_10 = *(float *)(player_maxs + iVar1) - (float)(&player_mins)[DAT_081051c0 * 3];
  local_c = *(float *)(player_maxs + iVar1 + 4) - (float)(&DAT_080aae04)[DAT_081051c0 * 3];
  local_8 = *(float *)(player_maxs + iVar1 + 8) - *(float *)(&DAT_080aae08 + iVar1);
  VectorScale(&local_10,0x3f000000,&local_10);
  *param_2 = vec3_origin._0_4_;
  param_2[1] = vec3_origin._4_4_;
  param_2[2] = vec3_origin._8_4_;
  R_StudioHull(param_1,param_3,param_4,param_5,param_6,&local_10,param_7,param_8,param_9);
  return;
}


// PM_HullPointContents  @ 0806a030
int PM_HullPointContents(int *param_1,int param_2,float *param_3)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  
  if (param_1[2] < param_1[3]) {
    while (-1 < param_2) {
      if ((param_2 < param_1[2]) || (param_1[3] < param_2)) {
        Sys_Error("PM_HullPointContents: bad node number");
      }
      piVar1 = (int *)(*param_1 + param_2 * 8);
      pfVar2 = (float *)(param_1[1] + *piVar1 * 0x14);
      if (*(byte *)(pfVar2 + 4) < 3) {
        fVar3 = param_3[*(byte *)(pfVar2 + 4)];
      }
      else {
        fVar3 = pfVar2[2] * param_3[2] + pfVar2[1] * param_3[1] + *pfVar2 * *param_3;
      }
      if (0.0 <= fVar3 - pfVar2[3]) {
        param_2 = (int)(short)piVar1[1];
      }
      else {
        param_2 = (int)*(short *)((int)piVar1 + 6);
      }
    }
  }
  else {
    param_2 = -1;
  }
  return param_2;
}


// PM_InitBoxHull  @ 08069f20
void PM_InitBoxHull(void)

{
  uint uVar1;
  
  box_hull._0_4_ = &box_clipnodes;
  box_hull._4_4_ = &box_planes;
  box_hull._8_4_ = 0;
  box_hull._12_4_ = 5;
  uVar1 = 0;
  do {
    (&box_clipnodes)[uVar1 * 2] = uVar1;
    (&DAT_080c54a4)[uVar1 * 4 + (uVar1 & 1)] = 0xffff;
    if (uVar1 == 5) {
      uRam080c54cc = 0xfffe;
    }
    else {
      (&DAT_080c54a4)[uVar1 * 4 + (uVar1 & 1 ^ 1)] = (short)uVar1 + 1;
    }
    (&DAT_080c54f0)[uVar1 * 0x14] = (char)((int)uVar1 >> 1);
    (&box_planes)[((int)uVar1 >> 1) + uVar1 * 5] = 0x3f800000;
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 6);
  return;
}


// PM_Ladder  @ 08069090
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * PM_Ladder(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  
  if (0 < DAT_08112028) {
    iVar3 = 0;
    do {
      iVar1 = iVar3 * 0x58;
      if (((*(int *)(&DAT_08112038 + iVar1) != 0) &&
          (*(int *)(*(int *)(&DAT_08112038 + iVar1) + 0x44) == 0)) &&
         (*(int *)(&DAT_0811206c + iVar1) == -0x10)) {
        iVar2 = PM_HullForBsp(&DAT_0811202c + iVar1,&local_10);
        local_10 = DAT_0810516c - local_10;
        local_c = DAT_08105170 - local_c;
        local_8 = _DAT_08105174 - local_8;
        iVar2 = PM_HullPointContents(iVar2,*(undefined4 *)(iVar2 + 8),&local_10);
        if (iVar2 != -1) {
          return &DAT_0811202c + iVar1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_08112028);
  }
  return (undefined *)0x0;
}


// PM_LadderMove  @ 080691d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_LadderMove(int param_1)

{
  float fVar1;
  int iVar2;
  float local_b4;
  float local_b0;
  undefined4 local_a8 [2];
  undefined4 local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  undefined1 local_84 [12];
  float local_78;
  float local_74;
  float local_70;
  undefined1 local_6c [12];
  undefined1 local_60 [12];
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  undefined1 local_48 [16];
  float local_38;
  float local_28;
  float local_24;
  float local_20;
  float local_10;
  float local_c;
  float local_8;
  
  if (DAT_081051dc != 8) {
    iVar2 = *(int *)(param_1 + 0xc);
    local_10 = *(float *)(iVar2 + 0x54) + *(float *)(iVar2 + 0x60);
    local_c = *(float *)(iVar2 + 0x58) + *(float *)(iVar2 + 100);
    local_8 = *(float *)(iVar2 + 0x5c) + *(float *)(iVar2 + 0x68);
    VectorScale(&local_10,0x3f000000,&local_10);
    DAT_081051dc = 5;
    local_54 = DAT_0810516c;
    local_50 = DAT_08105170;
    local_4c = (*(float *)(&DAT_080aae08 + DAT_081051c0 * 0xc) - 1.0) + _DAT_08105174;
    iVar2 = PM_PointContents(&local_54);
    _DAT_081051c4 = 0;
    PM_TraceModel(param_1,&DAT_0810516c,&local_10,local_48);
    if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
      local_b0 = 0.0;
      local_b4 = 0.0;
      AngleVectors(&DAT_08105178,local_60,local_6c,0);
      if ((DAT_081125ca & 0x10) != 0) {
        local_b0 = -200.0;
      }
      if ((DAT_081125ca & 8) != 0) {
        local_b0 = local_b0 + 200.0;
      }
      if ((DAT_081125cb & 2) != 0) {
        local_b4 = -200.0;
      }
      if ((DAT_081125cb & 4) != 0) {
        local_b4 = local_b4 + 200.0;
      }
      if ((DAT_081125ca & 2) == 0) {
        if (((byte)((byte)((ushort)((ushort)NAN(local_b0) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_b0 == 0.0) << 0xe) >> 8)) == 0x40) &&
           ((byte)(local_b4 < 0.0 | (byte)((ushort)((ushort)NAN(local_b4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_b4 == 0.0) << 0xe) >> 8)) == 0x40)) {
          DAT_08105184 = vec3_origin._0_4_;
          DAT_08105188 = vec3_origin._4_4_;
          _DAT_0810518c = vec3_origin._8_4_;
        }
        else {
          VectorScale(local_60,local_b0,&local_78);
          VectorMA(&local_78,local_b4,local_6c,&local_78);
          local_a8[0] = vec3_origin._0_4_;
          local_a8[1] = vec3_origin._4_4_;
          local_a0 = 0x3f800000;
          CrossProduct(local_a8,&local_28,local_84);
          VectorNormalize(local_84);
          fVar1 = local_70 * local_20 + local_74 * local_24 + local_78 * local_28;
          VectorScale(&local_28,fVar1,&local_90);
          local_9c = local_78 - local_90;
          local_98 = local_74 - local_8c;
          local_94 = local_70 - local_88;
          CrossProduct(&local_28,local_84,local_a8);
          VectorMA(&local_9c,-fVar1,local_a8,&DAT_08105184);
          if ((iVar2 == -2) &&
             ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
            VectorMA(&DAT_08105184,0x43480000,&local_28,&DAT_08105184);
          }
        }
      }
      else {
        DAT_081051dc = 3;
        VectorScale(&local_28,0x43870000,&DAT_08105184);
      }
    }
  }
  return;
}


// PM_MinMaxForRay  @ 0806b220
void PM_MinMaxForRay(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar3 * 4);
    fVar2 = *(float *)(param_2 + iVar3 * 4);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      fVar1 = *(float *)(param_2 + iVar3 * 4);
    }
    *(float *)(param_3 + iVar3 * 4) = fVar1;
    fVar1 = *(float *)(param_1 + iVar3 * 4);
    if (fVar1 <= *(float *)(param_2 + iVar3 * 4)) {
      fVar1 = *(float *)(param_2 + iVar3 * 4);
    }
    *(float *)(param_4 + iVar3 * 4) = fVar1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return;
}


// PM_NameForContents  @ 08066160
char * PM_NameForContents(undefined4 param_1)

{
  char *pcVar1;
  
  switch(param_1) {
  case 0xfffffff0:
    pcVar1 = "LADDER";
    break;
  case 0xfffffff1:
    pcVar1 = "TRANSLUCENT";
    break;
  case 0xfffffff2:
    pcVar1 = "CDOWN";
    break;
  case 0xfffffff3:
    pcVar1 = "CUP";
    break;
  case 0xfffffff4:
    pcVar1 = "C270";
    break;
  case 0xfffffff5:
    pcVar1 = "C180";
    break;
  case 0xfffffff6:
    pcVar1 = "C90";
    break;
  case 0xfffffff7:
    pcVar1 = "C0";
    break;
  case 0xfffffff8:
    pcVar1 = "CLIP";
    break;
  case 0xfffffff9:
    pcVar1 = "ORIGIN";
    break;
  case 0xfffffffa:
    pcVar1 = "SKY";
    break;
  case 0xfffffffb:
    pcVar1 = "LAVA";
    break;
  case 0xfffffffc:
    pcVar1 = "SLIME";
    break;
  case 0xfffffffd:
    pcVar1 = "WATER";
    break;
  case 0xfffffffe:
    pcVar1 = "SOLID";
    break;
  case 0xffffffff:
    pcVar1 = "EMPTY";
    break;
  default:
    pcVar1 = "UNKNOWN";
  }
  return pcVar1;
}


// PM_NoClip  @ 08068b00
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_NoClip(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_10 [3];
  
  fVar2 = _DAT_081125c0;
  fVar1 = _DAT_081125bc;
  VectorNormalize(&forward);
  VectorNormalize(&right);
  iVar3 = 0;
  do {
    local_10[iVar3] = fVar2 * (float)(&right)[iVar3] + fVar1 * (float)(&forward)[iVar3];
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  local_10[2] = local_10[2] + _DAT_081125c4;
  VectorMA(&DAT_0810516c,frametime,local_10,&DAT_0810516c);
  DAT_08105184 = vec3_origin._0_4_;
  DAT_08105188 = vec3_origin._4_4_;
  _DAT_0810518c = vec3_origin._8_4_;
  return;
}


// PM_ParticleLine  @ 08066380
void PM_ParticleLine(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4,
                    float param_5)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  float local_2c;
  float local_1c [6];
  
  local_1c[0] = *param_2 - *param_1;
  local_1c[1] = param_2[1] - param_1[1];
  local_1c[2] = param_2[2] - param_1[2];
  lVar3 = (longdouble)VectorNormalize(local_1c);
  fVar1 = (float)lVar3;
  local_2c = 0.0;
  lVar4 = (longdouble)0.0;
  if ((byte)((lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1) < 0x40) {
    do {
      iVar2 = 0;
      do {
        (local_1c + 3)[iVar2] = local_2c * local_1c[iVar2] + param_1[iVar2];
        iVar2 = iVar2 + 1;
      } while (iVar2 < 3);
      CL_Particle(local_1c + 3,param_3,param_4,0,(int)ROUND(param_5));
      local_2c = local_2c + 2.0;
    } while ((byte)((local_2c < fVar1 |
                     (byte)((ushort)((ushort)(NAN(local_2c) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_2c == fVar1) << 0xe) >> 8)) - 1) < 0x40);
  }
  return;
}


// PM_Physics_Toss  @ 08068d60
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_Physics_Toss(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 **ppuVar5;
  undefined1 **ppuVar6;
  undefined4 *local_74;
  undefined1 *puStack_70;
  undefined4 local_54 [3];
  int local_48 [4];
  float local_38;
  undefined1 local_28 [8];
  float local_20;
  int local_18;
  
  puStack_70 = (undefined1 *)0x8068d6c;
  PM_CheckWater();
  if ((byte)(0.0 < _DAT_0810518c | (byte)((ushort)((ushort)NAN(_DAT_0810518c) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_0810518c == 0.0) << 0xe) >> 8)) == 1) {
    onground = -1;
  }
  if (onground != -1) {
    puStack_70 = vec3_origin;
    local_74 = (undefined4 *)&DAT_0810519c;
    iVar4 = VectorCompare();
    if (iVar4 != 0) {
      puStack_70 = vec3_origin;
      local_74 = &DAT_08105184;
      iVar4 = VectorCompare();
      if (iVar4 != 0) {
        return;
      }
    }
  }
  puStack_70 = (undefined1 *)0x8068dc6;
  PM_CheckVelocity();
  if (((DAT_081051dc != 5) && (DAT_081051dc != 0xb)) && (DAT_081051dc != 9)) {
    puStack_70 = (undefined1 *)0x8068de6;
    PM_AddGravity();
  }
  DAT_08105184 = DAT_08105184 + _DAT_0810519c;
  DAT_08105188 = DAT_08105188 + _DAT_081051a0;
  _DAT_0810518c = _DAT_0810518c + _DAT_081051a4;
  puStack_70 = (undefined1 *)0x8068e21;
  PM_CheckVelocity();
  local_74 = frametime;
  puStack_70 = (undefined1 *)local_54;
  VectorScale(&DAT_08105184);
  DAT_08105184 = DAT_08105184 - _DAT_0810519c;
  DAT_08105188 = DAT_08105188 - _DAT_081051a0;
  _DAT_0810518c = _DAT_0810518c - _DAT_081051a4;
  PM_PushEntity(local_48,local_54);
  PM_CheckVelocity();
  if (local_48[0] == 0) {
    ppuVar6 = &puStack_70;
    if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
      if (DAT_081051dc == 10) {
        local_74 = (undefined4 *)(2.0 - _DAT_081051c8);
      }
      else if (DAT_081051dc == 0xb) {
        local_74 = (undefined4 *)0x40000000;
      }
      else {
        local_74 = (undefined4 *)0x3f800000;
      }
      PM_ClipVelocity(&DAT_08105184,local_28,&DAT_08105184);
      uVar3 = vec3_origin._8_4_;
      uVar2 = vec3_origin._4_4_;
      uVar1 = vec3_origin._0_4_;
      ppuVar5 = (undefined4 **)&puStack_70;
      ppuVar6 = &puStack_70;
      if ((byte)(0.7 < local_20 | (byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_20 == 0.7) << 0xe) >> 8)) == 1) {
        if (_DAT_0810518c < (float)movevars._4_4_ * (float)frametime) {
          onground = local_18;
          _DAT_0810518c = 0.0;
        }
        if ((_DAT_0810518c * _DAT_0810518c +
             DAT_08105188 * DAT_08105188 + DAT_08105184 * DAT_08105184 < 900.0) ||
           (1 < DAT_081051dc - 10U)) {
          onground = local_18;
          DAT_08105184 = (float)vec3_origin._0_4_;
          DAT_08105188 = (float)vec3_origin._4_4_;
          _DAT_0810518c = (float)vec3_origin._8_4_;
        }
        else {
          local_74 = local_54;
          VectorScale(&DAT_08105184,(1.0 - local_38) * (float)frametime * 0.9);
          PM_PushEntity(local_48,local_54);
          ppuVar5 = &local_74;
        }
        DAT_08105184 = DAT_08105184 - (float)uVar1;
        DAT_08105188 = DAT_08105188 - (float)uVar2;
        _DAT_0810518c = _DAT_0810518c - (float)uVar3;
        ppuVar6 = (undefined1 **)ppuVar5;
      }
    }
    *(undefined4 *)((int)ppuVar6 + -4) = 0x806907c;
    PM_CheckWater();
  }
  else {
    onground = local_18;
    DAT_08105184 = (float)vec3_origin._0_4_;
    DAT_08105188 = (float)vec3_origin._4_4_;
    _DAT_0810518c = (float)vec3_origin._8_4_;
  }
  return;
}


// PM_PlayerMove  @ 0806aa30
int * PM_PlayerMove(int *param_1,float *param_2,float *param_3,byte param_4)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int local_16c;
  int local_168;
  int local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  int local_13c [4];
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  int local_8c [4];
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  int local_5c;
  int local_48 [4];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_8;
  
  piVar10 = local_8c;
  for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar10 = 0;
    piVar10 = piVar10 + 1;
  }
  local_7c = 1.0;
  local_5c = -1;
  local_78 = *param_3;
  local_74 = param_3[1];
  local_70 = param_3[2];
  local_168 = 0;
  do {
    if (DAT_081051e4 <= local_168) {
      piVar10 = local_8c;
      piVar11 = param_1;
      for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar11 = *piVar10;
        piVar10 = piVar10 + 1;
        piVar11 = piVar11 + 1;
      }
      return param_1;
    }
    iVar7 = local_168 * 0x58;
    pfVar1 = (float *)(&DAT_081051e8 + local_168 * 0x16);
    if (((((&DAT_081051f4)[local_168 * 0x16] == 0) || ((&DAT_08105224)[local_168 * 0x16] != 0)) ||
        ((&DAT_08105228)[local_168 * 0x16] == 0)) &&
       (((param_4 & 4) == 0 || (*(int *)(&DAT_0810522c + iVar7) == 0)))) {
      local_98 = *pfVar1;
      local_94 = (float)(&DAT_081051ec)[local_168 * 0x16];
      local_90 = (float)(&DAT_081051f0)[local_168 * 0x16];
      local_164 = 1;
      if ((&DAT_081051f4)[local_168 * 0x16] == 0) {
        if (*(int *)(&DAT_081051f8 + iVar7) != 0) {
          if ((param_4 & 1) != 0) goto LAB_0806b1e4;
          if ((*(int *)(*(int *)(&DAT_081051f8 + iVar7) + 0x44) == 3) &&
             (((*(byte *)(*(int *)(&DAT_081051f8 + iVar7) + 0x51) & 2) != 0 ||
              ((DAT_081051c0 == 2 && ((param_4 & 2) == 0)))))) {
            local_16c = PM_HullForStudioModel
                                  (*(undefined4 *)(&DAT_081051f8 + iVar7),&local_98,
                                   *(undefined4 *)(&DAT_08105230 + iVar7),
                                   *(undefined4 *)(&DAT_08105234 + iVar7),
                                   &DAT_08105218 + local_168 * 0x16,pfVar1,iVar7 + 0x8105238,
                                   iVar7 + 0x810523c,&local_164);
            goto LAB_0806ad2d;
          }
        }
        iVar9 = DAT_081051c0 * 0xc;
        local_bc = *(float *)(&DAT_081051fc + iVar7) - *(float *)(player_maxs + iVar9);
        local_b8 = *(float *)(&DAT_08105200 + iVar7) - *(float *)(player_maxs + iVar9 + 4);
        local_b4 = *(float *)(&DAT_08105204 + iVar7) - *(float *)(player_maxs + iVar9 + 8);
        local_c8 = *(float *)(&DAT_08105208 + iVar7) - (float)(&player_mins)[DAT_081051c0 * 3];
        local_c4 = *(float *)(&DAT_0810520c + iVar7) - (float)(&DAT_080aae04)[DAT_081051c0 * 3];
        local_c0 = *(float *)(&DAT_08105210 + iVar7) - *(float *)(&DAT_080aae08 + iVar9);
        local_16c = PM_HullForBox(&local_bc,&local_c8);
      }
      else {
        if (DAT_081051c0 == 1) {
          local_16c = (&DAT_081051f4)[local_168 * 0x16] + 0x148;
        }
        else if (DAT_081051c0 < 2) {
          if (DAT_081051c0 == 0) {
            local_16c = (&DAT_081051f4)[local_168 * 0x16] + 0xf8;
          }
        }
        else if (DAT_081051c0 == 2) {
          local_16c = (&DAT_081051f4)[local_168 * 0x16] + 0xd0;
        }
        local_98 = (*(float *)(local_16c + 0x10) - (float)(&player_mins)[DAT_081051c0 * 3]) +
                   *pfVar1;
        local_94 = (*(float *)(local_16c + 0x14) - (float)(&DAT_080aae04)[DAT_081051c0 * 3]) +
                   (float)(&DAT_081051ec)[local_168 * 0x16];
        local_90 = (*(float *)(local_16c + 0x18) - *(float *)(&DAT_080aae08 + DAT_081051c0 * 0xc)) +
                   (float)(&DAT_081051f0)[local_168 * 0x16];
      }
LAB_0806ad2d:
      local_a4 = *param_2 - local_98;
      local_a0 = param_2[1] - local_94;
      local_9c = param_2[2] - local_90;
      local_b0 = *param_3 - local_98;
      local_ac = param_3[1] - local_94;
      local_a8 = param_3[2] - local_90;
      if (((&DAT_08105224)[local_168 * 0x16] == 4) &&
         ((((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_08105218)[local_168 * 0x16]) << 10) >> 8
                         ) |
                  (byte)((ushort)((ushort)((float)(&DAT_08105218)[local_168 * 0x16] == 0.0) << 0xe)
                        >> 8)) != 0x40 ||
           ((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_0810521c)[local_168 * 0x16]) << 10) >> 8
                         ) |
                  (byte)((ushort)((ushort)((float)(&DAT_0810521c)[local_168 * 0x16] == 0.0) << 0xe)
                        >> 8)) != 0x40)) ||
          (fVar2 = (float)(&DAT_08105220)[local_168 * 0x16],
          (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)))) {
        bVar3 = true;
        AngleVectors(&DAT_08105218 + local_168 * 0x16,&local_d4,&local_e0,&local_ec);
        fVar6 = local_a0;
        fVar5 = local_a4;
        fVar4 = local_ac;
        fVar2 = local_b0;
        local_a4 = local_9c * local_cc + local_a0 * local_d0 + local_a4 * local_d4;
        local_a0 = -(local_9c * local_d8 + local_a0 * local_dc + fVar5 * local_e0);
        local_9c = local_9c * local_e4 + fVar6 * local_e8 + fVar5 * local_ec;
        local_f8 = local_b0;
        local_f4 = local_ac;
        local_f0 = local_a8;
        local_b0 = local_a8 * local_cc + local_ac * local_d0 + local_b0 * local_d4;
        local_ac = -(local_a8 * local_d8 + local_ac * local_dc + fVar2 * local_e0);
        local_a8 = local_a8 * local_e4 + fVar4 * local_e8 + fVar2 * local_ec;
      }
      else {
        bVar3 = false;
      }
      piVar10 = local_48;
      for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar10 = 0;
        piVar10 = piVar10 + 1;
      }
      local_38 = 1.0;
      local_48[0] = 1;
      local_34 = *param_3;
      local_30 = param_3[1];
      local_2c = param_3[2];
      if (local_164 == 1) {
        PM_RecursiveHullCheck
                  (local_16c,*(undefined4 *)(local_16c + 8),0,0x3f800000,&local_a4,&local_b0,
                   local_48);
      }
      else {
        iVar7 = 0;
        iVar9 = 0;
        if (0 < local_164) {
          do {
            piVar10 = local_13c;
            for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
              *piVar10 = 0;
              piVar10 = piVar10 + 1;
            }
            local_12c = 1.0;
            local_13c[0] = 1;
            local_128 = *param_3;
            local_124 = param_3[1];
            local_120 = param_3[2];
            PM_RecursiveHullCheck
                      (iVar9 * 0x28 + local_16c,*(undefined4 *)(local_16c + 8 + iVar9 * 0x28),0,
                       0x3f800000,&local_a4,&local_b0,local_13c);
            if (((iVar9 == 0) || (local_13c[0] != 0)) ||
               ((local_13c[1] != 0 ||
                ((byte)(local_12c < local_38 |
                        (byte)((ushort)((ushort)(NAN(local_12c) || NAN(local_38)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(local_12c == local_38) << 0xe) >> 8)) == 1)))) {
              iVar7 = iVar9;
              if (local_48[1] == 0) {
                piVar10 = local_13c;
                piVar11 = local_48;
                for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
                  *piVar11 = *piVar10;
                  piVar10 = piVar10 + 1;
                  piVar11 = piVar11 + 1;
                }
              }
              else {
                piVar10 = local_13c;
                piVar11 = local_48;
                for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
                  *piVar11 = *piVar10;
                  piVar10 = piVar10 + 1;
                  piVar11 = piVar11 + 1;
                }
                local_48[1] = 1;
              }
            }
            local_8 = SV_HitgroupForStudioHull(iVar7);
            iVar9 = iVar9 + 1;
          } while (iVar9 < local_164);
        }
      }
      if (local_48[0] != 0) {
        local_48[1] = 1;
      }
      if (local_48[1] != 0) {
        local_38 = 0.0;
      }
      if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
        if (bVar3) {
          AngleVectorsTranspose(&DAT_08105218 + local_168 * 0x16,&local_f8,&local_148,&local_154);
          fVar4 = local_24;
          fVar2 = local_28;
          local_160 = local_28;
          local_15c = local_24;
          local_158 = local_20;
          local_28 = local_20 * local_f0 + local_24 * local_f4 + local_28 * local_f8;
          local_24 = local_20 * local_140 + local_24 * local_144 + fVar2 * local_148;
          local_20 = local_20 * local_14c + fVar4 * local_150 + fVar2 * local_154;
        }
        local_34 = (*param_3 - *param_2) * local_38 + *param_2;
        local_30 = (param_3[1] - param_2[1]) * local_38 + param_2[1];
        local_2c = (param_3[2] - param_2[2]) * local_38 + param_2[2];
      }
      if ((byte)(local_38 < local_7c |
                 (byte)((ushort)((ushort)(NAN(local_38) || NAN(local_7c)) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_38 == local_7c) << 0xe) >> 8)) == 1) {
        piVar10 = local_48;
        piVar11 = local_8c;
        for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar11 = *piVar10;
          piVar10 = piVar10 + 1;
          piVar11 = piVar11 + 1;
        }
        local_5c = local_168;
      }
    }
LAB_0806b1e4:
    local_168 = local_168 + 1;
  } while( true );
}


// PM_PlayerMove2  @ 0806b470
int * PM_PlayerMove2(int *param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int local_184;
  int local_180;
  int local_17c;
  float local_178;
  float local_174;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  float local_158;
  int local_154 [4];
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  undefined1 local_e0 [12];
  undefined1 local_d4 [12];
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  int local_8c [4];
  float local_7c;
  int local_5c;
  int local_48 [4];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_8;
  
  PM_WorldTrace(local_8c,param_2,param_3);
  if (((byte)(0.0 < (float)pm_worldonly._12_4_ |
              (byte)((ushort)((ushort)NAN((float)pm_worldonly._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)pm_worldonly._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)(0.0 < local_7c | (byte)((ushort)((ushort)NAN(local_7c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_7c == 0.0) << 0xe) >> 8)) != 0x40)) {
    SV_MoveBounds(param_2,&player_mins + DAT_081051c0 * 3,player_maxs + DAT_081051c0 * 0xc,&local_34
                  ,local_d4,local_e0);
    for (local_180 = 1; local_180 < DAT_081051e4; local_180 = local_180 + 1) {
      iVar8 = local_180 * 0x58;
      pfVar1 = (float *)(&DAT_081051e8 + local_180 * 0x16);
      if (((((&DAT_081051f4)[local_180 * 0x16] == 0) || ((&DAT_08105224)[local_180 * 0x16] != 0)) ||
          ((&DAT_08105228)[local_180 * 0x16] == 0)) &&
         ((((byte)(0.0 < (float)pm_nostudio._12_4_ |
                   (byte)((ushort)((ushort)NAN((float)pm_nostudio._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)pm_nostudio._12_4_ == 0.0) << 0xe) >> 8)) == 0x40
           || (*(int *)(&DAT_081051f8 + iVar8) == 0)) &&
          (((byte)(0.0 < (float)pm_nocomplex._12_4_ |
                   (byte)((ushort)((ushort)NAN((float)pm_nocomplex._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)pm_nocomplex._12_4_ == 0.0) << 0xe) >> 8)) == 0x40
           || ((*(int *)(&DAT_081051f8 + iVar8) == 0 ||
               ((*(byte *)(*(int *)(&DAT_081051f8 + iVar8) + 0x51) & 2) == 0)))))))) {
        local_98 = *pfVar1;
        local_94 = (float)(&DAT_081051ec)[local_180 * 0x16];
        local_90 = (float)(&DAT_081051f0)[local_180 * 0x16];
        local_17c = 1;
        if ((&DAT_081051f4)[local_180 * 0x16] == 0) {
          if (((*(int *)(&DAT_081051f8 + iVar8) == 0) ||
              (*(int *)(*(int *)(&DAT_081051f8 + iVar8) + 0x44) != 3)) ||
             (((*(byte *)(*(int *)(&DAT_081051f8 + iVar8) + 0x51) & 2) == 0 && (DAT_081051c0 != 2)))
             ) {
            iVar9 = DAT_081051c0 * 0xc;
            local_bc = *(float *)(&DAT_081051fc + iVar8) - *(float *)(player_maxs + iVar9);
            local_b8 = *(float *)(&DAT_08105200 + iVar8) - *(float *)(player_maxs + iVar9 + 4);
            local_b4 = *(float *)(&DAT_08105204 + iVar8) - *(float *)(player_maxs + iVar9 + 8);
            local_c8 = *(float *)(&DAT_08105208 + iVar8) - (float)(&player_mins)[DAT_081051c0 * 3];
            local_c4 = *(float *)(&DAT_0810520c + iVar8) - (float)(&DAT_080aae04)[DAT_081051c0 * 3];
            local_c0 = *(float *)(&DAT_08105210 + iVar8) - *(float *)(&DAT_080aae08 + iVar9);
            local_184 = PM_HullForBox(&local_bc,&local_c8);
          }
          else {
            local_184 = PM_HullForStudioModel
                                  (*(undefined4 *)(&DAT_081051f8 + iVar8),&local_98,
                                   *(undefined4 *)(&DAT_08105230 + iVar8),
                                   *(undefined4 *)(&DAT_08105234 + iVar8),
                                   &DAT_08105218 + local_180 * 0x16,pfVar1,iVar8 + 0x8105238,
                                   iVar8 + 0x810523c,&local_17c);
          }
        }
        else {
          if (DAT_081051c0 == 1) {
            local_184 = (&DAT_081051f4)[local_180 * 0x16] + 0x148;
          }
          else if (DAT_081051c0 < 2) {
            if (DAT_081051c0 == 0) {
              local_184 = (&DAT_081051f4)[local_180 * 0x16] + 0xf8;
            }
          }
          else if (DAT_081051c0 == 2) {
            local_184 = (&DAT_081051f4)[local_180 * 0x16] + 0xd0;
          }
          local_98 = (*(float *)(local_184 + 0x10) - (float)(&player_mins)[DAT_081051c0 * 3]) +
                     *pfVar1;
          local_94 = (*(float *)(local_184 + 0x14) - (float)(&DAT_080aae04)[DAT_081051c0 * 3]) +
                     (float)(&DAT_081051ec)[local_180 * 0x16];
          local_90 = (*(float *)(local_184 + 0x18) - *(float *)(&DAT_080aae08 + DAT_081051c0 * 0xc))
                     + (float)(&DAT_081051f0)[local_180 * 0x16];
        }
        local_a4 = *param_2 - local_98;
        local_a0 = param_2[1] - local_94;
        local_9c = param_2[2] - local_90;
        local_b0 = *param_3 - local_98;
        local_ac = param_3[1] - local_94;
        local_a8 = param_3[2] - local_90;
        if (((&DAT_08105224)[local_180 * 0x16] == 4) &&
           ((((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_08105218)[local_180 * 0x16]) << 10) >>
                           8) |
                    (byte)((ushort)((ushort)((float)(&DAT_08105218)[local_180 * 0x16] == 0.0) << 0xe
                                   ) >> 8)) != 0x40 ||
             ((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_0810521c)[local_180 * 0x16]) << 10) >>
                           8) |
                    (byte)((ushort)((ushort)((float)(&DAT_0810521c)[local_180 * 0x16] == 0.0) << 0xe
                                   ) >> 8)) != 0x40)) ||
            (fVar2 = (float)(&DAT_08105220)[local_180 * 0x16],
            (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)))) {
          bVar3 = true;
          AngleVectors(&DAT_08105218 + local_180 * 0x16,&local_ec,&local_f8,&local_104);
          fVar6 = local_a0;
          fVar5 = local_a4;
          fVar4 = local_ac;
          fVar2 = local_b0;
          local_a4 = local_9c * local_e4 + local_a0 * local_e8 + local_a4 * local_ec;
          local_a0 = -(local_9c * local_f0 + local_a0 * local_f4 + fVar5 * local_f8);
          local_9c = local_9c * local_fc + fVar6 * local_100 + fVar5 * local_104;
          local_110 = local_b0;
          local_10c = local_ac;
          local_108 = local_a8;
          local_b0 = local_a8 * local_e4 + local_ac * local_e8 + local_b0 * local_ec;
          local_ac = -(local_a8 * local_f0 + local_ac * local_f4 + fVar2 * local_f8);
          local_a8 = local_a8 * local_fc + fVar4 * local_100 + fVar2 * local_104;
        }
        else {
          bVar3 = false;
        }
        piVar10 = local_48;
        for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
          *piVar10 = 0;
          piVar10 = piVar10 + 1;
        }
        local_38 = 1.0;
        local_48[0] = 1;
        local_34 = *param_3;
        local_30 = param_3[1];
        local_2c = param_3[2];
        if (local_17c == 1) {
          PM_RecursiveHullCheck
                    (local_184,*(undefined4 *)(local_184 + 8),0,0x3f800000,&local_a4,&local_b0,
                     local_48);
        }
        else {
          iVar8 = 0;
          iVar9 = 0;
          if (0 < local_17c) {
            do {
              piVar10 = local_154;
              for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
                *piVar10 = 0;
                piVar10 = piVar10 + 1;
              }
              local_144 = 1.0;
              local_154[0] = 1;
              local_140 = *param_3;
              local_13c = param_3[1];
              local_138 = param_3[2];
              PM_RecursiveHullCheck
                        (iVar9 * 0x28 + local_184,*(undefined4 *)(local_184 + 8 + iVar9 * 0x28),0,
                         0x3f800000,&local_a4,&local_b0,local_154);
              if (((iVar9 == 0) || (local_154[0] != 0)) ||
                 ((local_154[1] != 0 ||
                  ((byte)(local_144 < local_38 |
                          (byte)((ushort)((ushort)(NAN(local_144) || NAN(local_38)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(local_144 == local_38) << 0xe) >> 8)) == 1)))) {
                iVar8 = iVar9;
                if (local_48[1] == 0) {
                  piVar10 = local_154;
                  piVar11 = local_48;
                  for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *piVar11 = *piVar10;
                    piVar10 = piVar10 + 1;
                    piVar11 = piVar11 + 1;
                  }
                }
                else {
                  piVar10 = local_154;
                  piVar11 = local_48;
                  for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *piVar11 = *piVar10;
                    piVar10 = piVar10 + 1;
                    piVar11 = piVar11 + 1;
                  }
                  local_48[1] = 1;
                }
              }
              local_8 = SV_HitgroupForStudioHull(iVar8);
              iVar9 = iVar9 + 1;
            } while (iVar9 < local_17c);
          }
        }
        if (local_48[0] != 0) {
          local_48[1] = 1;
        }
        if (local_48[1] != 0) {
          local_38 = 0.0;
        }
        if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
          if (bVar3) {
            AngleVectorsTranspose(&DAT_08105218 + local_180 * 0x16,&local_110,&local_160,&local_16c)
            ;
            fVar4 = local_24;
            fVar2 = local_28;
            local_178 = local_28;
            local_174 = local_24;
            local_170 = local_20;
            local_28 = local_20 * local_108 + local_24 * local_10c + local_28 * local_110;
            local_24 = local_20 * local_158 + local_24 * local_15c + fVar2 * local_160;
            local_20 = local_20 * local_164 + fVar4 * local_168 + fVar2 * local_16c;
          }
          local_34 = (*param_3 - *param_2) * local_38 + *param_2;
          local_30 = (param_3[1] - param_2[1]) * local_38 + param_2[1];
          local_2c = (param_3[2] - param_2[2]) * local_38 + param_2[2];
        }
        if ((byte)(local_38 < local_7c |
                   (byte)((ushort)((ushort)(NAN(local_38) || NAN(local_7c)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_38 == local_7c) << 0xe) >> 8)) == 1) {
          piVar10 = local_48;
          piVar11 = local_8c;
          for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
            *piVar11 = *piVar10;
            piVar10 = piVar10 + 1;
            piVar11 = piVar11 + 1;
          }
          local_5c = local_180;
        }
      }
    }
  }
  piVar10 = local_8c;
  piVar11 = param_1;
  for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar11 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar11 = piVar11 + 1;
  }
  return param_1;
}


// PM_PointContents  @ 0806a190
int PM_PointContents(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = PM_HullPointContents(DAT_081051f4 + 0xd0,*(undefined4 *)(DAT_081051f4 + 0xd8),param_1);
  if (iVar1 + 0xeU < 6) {
    iVar1 = -3;
  }
  if ((iVar1 != -2) && (iVar2 = PM_SimulateLinkContents(param_1,0), iVar2 != -1)) {
    return iVar2;
  }
  return iVar1;
}


// PM_PrintFullState  @ 08065ff0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * PM_PrintFullState(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  char *__format;
  char local_104 [256];
  
  puVar3 = &szState_98;
  for (iVar2 = 0x200; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if (DAT_08105164 == 0) {
    __format = "%s player {\n";
  }
  else {
    __format = "%s server {\n";
  }
  sprintf((char *)&szState_98,__format);
  uVar1 = vstr();
  sprintf(local_104,"\torigin   = %s\n",uVar1);
  strcat((char *)&szState_98,local_104);
  uVar1 = vstr(&DAT_08105178);
  sprintf(local_104,"\tangles   = %s\n",uVar1);
  strcat((char *)&szState_98,local_104);
  uVar1 = vstr();
  sprintf(local_104,"\tvel      = %s\n",uVar1);
  strcat((char *)&szState_98,local_104);
  sprintf(local_104,"\tfriction = %.2f\n",(double)_DAT_081051c8);
  strcat((char *)&szState_98,local_104);
  sprintf(local_104,"\tmovetype = %i\n",DAT_081051dc);
  strcat((char *)&szState_98,local_104);
  sprintf(local_104,"\tcmd.f    = %.2f\n",(double)_DAT_081125bc);
  strcat((char *)&szState_98,local_104);
  sprintf(local_104,"\tcmd.ms   = %i\n");
  strcat((char *)&szState_98,local_104);
  sprintf(local_104,"}\n");
  strcat((char *)&szState_98,local_104);
  return &szState_98;
}


// PM_PrintPhysEnts  @ 08066290
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_PrintPhysEnts(void)

{
  int iVar1;
  
  Con_Printf("===== PMOVE ======\n");
  Con_Printf("Origin: %4.2f %4.2f %4.2f\n",(double)DAT_0810516c,(double)DAT_08105170,
             (double)_DAT_08105174);
  Con_Printf("------------------\n");
  iVar1 = 0;
  if (0 < DAT_081051e4) {
    do {
      Con_Printf("Ent:  %i\n",iVar1);
      Con_Printf("Org:  %4.2f %4.2f %4.2f\n",(double)(float)(&DAT_081051e8)[iVar1 * 0x16],
                 (double)(float)(&DAT_081051ec)[iVar1 * 0x16],
                 (double)(float)(&DAT_081051f0)[iVar1 * 0x16]);
      Con_Printf("Ang:  %4.2f %4.2f %4.2f\n",(double)(float)(&DAT_08105218)[iVar1 * 0x16],
                 (double)(float)(&DAT_0810521c)[iVar1 * 0x16],
                 (double)(float)(&DAT_08105220)[iVar1 * 0x16]);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_081051e4);
  }
  Con_Printf(&DAT_080a2a33);
  return;
}


// PM_PushEntity  @ 08068cb0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * PM_PushEntity(int *param_1,float *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int aiStack_b0 [14];
  undefined4 uStack_78;
  int *piStack_74;
  undefined4 *puStack_70;
  float *pfStack_6c;
  undefined4 uStack_68;
  float local_54;
  float local_50;
  float local_4c;
  int local_48 [4];
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_54 = DAT_0810516c + *param_2;
  local_50 = DAT_08105170 + param_2[1];
  local_4c = _DAT_08105174 + param_2[2];
  uStack_68 = 0;
  pfStack_6c = &local_54;
  puStack_70 = &DAT_0810516c;
  uStack_78 = 0x8068cf6;
  piStack_74 = local_48;
  PM_PlayerMove();
  DAT_0810516c = (float)local_34;
  DAT_08105170 = (float)local_30;
  _DAT_08105174 = (float)local_2c;
  if ((local_38 < 1.0) && (local_48[0] == 0)) {
    pfStack_6c = (float *)&DAT_08105184;
    piVar2 = local_48;
    piVar3 = aiStack_b0;
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    PM_AddToTouched();
  }
  piVar2 = local_48;
  piVar3 = param_1;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  return param_1;
}


// PM_RecursiveHullCheck  @ 0806a270
undefined4
PM_RecursiveHullCheck
          (int *param_1,int param_2,float param_3,float param_4,float *param_5,float *param_6,
          int *param_7)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  float local_20;
  float local_1c;
  float local_10;
  int local_c;
  int local_8;
  
  if (param_2 < 0) {
    if (param_2 == -2) {
      param_7[1] = 1;
      return 1;
    }
    *param_7 = 0;
    if (param_2 != -1) {
      param_7[3] = 1;
      return 1;
    }
  }
  else {
    if (param_1[2] < param_1[3]) {
      if ((param_2 < param_1[2]) || (param_1[3] < param_2)) {
        Sys_Error("PM_RecursiveHullCheck: bad node number");
      }
      piVar1 = (int *)(*param_1 + param_2 * 8);
      pfVar2 = (float *)(param_1[1] + *piVar1 * 0x14);
      if (*(byte *)(pfVar2 + 4) < 3) {
        fVar4 = param_5[*(byte *)(pfVar2 + 4)] - pfVar2[3];
        fVar3 = param_6[*(byte *)(pfVar2 + 4)];
      }
      else {
        fVar4 = (pfVar2[2] * param_5[2] + pfVar2[1] * param_5[1] + *pfVar2 * *param_5) - pfVar2[3];
        fVar3 = pfVar2[2] * param_6[2] + pfVar2[1] * param_6[1] + *pfVar2 * *param_6;
      }
      fVar3 = fVar3 - pfVar2[3];
      local_20 = param_3;
      pfVar8 = param_5;
      if (((byte)((0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) - 1) < 0x40) &&
         ((byte)((0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) - 1) < 0x40)) {
        iVar7 = (int)(short)piVar1[1];
      }
      else {
        if ((0.0 <= fVar4) || (0.0 <= fVar3)) {
          if (0.0 <= fVar4) {
            local_1c = fVar4 - 0.03125;
          }
          else {
            local_1c = fVar4 + 0.03125;
          }
          local_1c = local_1c / (fVar4 - fVar3);
          if (local_1c < 0.0) {
            local_1c = 0.0;
          }
          if ((byte)(1.0 < local_1c | (byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_1c == 1.0) << 0xe) >> 8)) == 1) {
            local_1c = 1.0;
          }
          local_20 = (param_4 - param_3) * local_1c + param_3;
          iVar7 = 0;
          do {
            (&local_10)[iVar7] = (param_6[iVar7] - param_5[iVar7]) * local_1c + param_5[iVar7];
            iVar7 = iVar7 + 1;
          } while (iVar7 < 3);
          iVar7 = PM_RecursiveHullCheck
                            (param_1,(int)*(short *)((uint)(fVar4 < 0.0) * 2 + 4 + (int)piVar1),
                             param_3,local_20,param_5,&local_10,param_7);
          if (iVar7 != 0) {
            pfVar8 = &local_10;
            iVar7 = (uint)(0.0 <= fVar4) * 2;
            iVar5 = PM_HullPointContents(param_1,(int)*(short *)(iVar7 + 4 + (int)piVar1),pfVar8);
            if (iVar5 != -2) {
              iVar7 = (int)*(short *)(iVar7 + 4 + (int)piVar1);
              goto LAB_0806a517;
            }
            if (*param_7 == 0) {
              if (fVar4 < 0.0 == 0) {
                param_7[8] = (int)*pfVar2;
                param_7[9] = (int)pfVar2[1];
                param_7[10] = (int)pfVar2[2];
                param_7[0xb] = (int)pfVar2[3];
              }
              else {
                param_7[8] = (int)((float)vec3_origin._0_4_ - *pfVar2);
                param_7[9] = (int)((float)vec3_origin._4_4_ - pfVar2[1]);
                param_7[10] = (int)((float)vec3_origin._8_4_ - pfVar2[2]);
                param_7[0xb] = (int)-pfVar2[3];
              }
              while (iVar7 = PM_HullPointContents(param_1,param_1[2],&local_10), iVar7 == -2) {
                local_1c = local_1c - 0.05;
                if (local_1c < 0.0) {
                  param_7[4] = (int)local_20;
                  param_7[5] = (int)local_10;
                  param_7[6] = local_c;
                  param_7[7] = local_8;
                  Con_DPrintf("Trace backed up past 0.0.\n");
                  return 0;
                }
                local_20 = (param_4 - param_3) * local_1c + param_3;
                iVar7 = 0;
                do {
                  (&local_10)[iVar7] = (param_6[iVar7] - param_5[iVar7]) * local_1c + param_5[iVar7]
                  ;
                  iVar7 = iVar7 + 1;
                } while (iVar7 < 3);
              }
              param_7[4] = (int)local_20;
              param_7[5] = (int)local_10;
              param_7[6] = local_c;
              param_7[7] = local_8;
            }
          }
          return 0;
        }
        iVar7 = (int)*(short *)((int)piVar1 + 6);
      }
LAB_0806a517:
      uVar6 = PM_RecursiveHullCheck(param_1,iVar7,local_20,param_4,pfVar8,param_6,param_7);
      return uVar6;
    }
    *param_7 = 0;
  }
  param_7[2] = 1;
  return 1;
}


// PM_SimulateLinkContents  @ 0806a0e0
undefined4 PM_SimulateLinkContents(float *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  float local_10;
  float local_c;
  float local_8;
  
  if (1 < DAT_081051e4) {
    iVar2 = 1;
    do {
      if (((&DAT_08105224)[iVar2 * 0x16] == 0) && ((&DAT_081051f4)[iVar2 * 0x16] != 0)) {
        local_10 = *param_1 - (float)(&DAT_081051e8)[iVar2 * 0x16];
        local_c = param_1[1] - (float)(&DAT_081051ec)[iVar2 * 0x16];
        local_8 = param_1[2] - (float)(&DAT_081051f0)[iVar2 * 0x16];
        iVar1 = PM_HullPointContents
                          ((&DAT_081051f4)[iVar2 * 0x16] + 0xd0,
                           *(undefined4 *)((&DAT_081051f4)[iVar2 * 0x16] + 0xd8),&local_10);
        if (iVar1 != -1) {
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = *(undefined4 *)(&DAT_08105214 + iVar2 * 0x58);
          }
          return (&DAT_08105228)[iVar2 * 0x16];
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_081051e4);
  }
  return 0xffffffff;
}


// PM_SplineFraction  @ 08065fc0
longdouble PM_SplineFraction(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 * (longdouble)param_2;
  lVar2 = lVar1 * lVar1;
  return (longdouble)3.0 * lVar2 - (lVar2 + lVar2) * lVar1;
}


// PM_TestPlayerPosition  @ 0806a7b0
int PM_TestPlayerPosition(float *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
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
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  PM_PlayerMove(&g_Trace,&DAT_0810516c,&DAT_0810516c,0);
  iVar7 = 0;
  if (0 < DAT_081051e4) {
    do {
      iVar5 = iVar7 * 0x58;
      pfVar1 = (float *)(&DAT_081051e8 + iVar7 * 0x16);
      if ((((&DAT_081051f4)[iVar7 * 0x16] == 0) || ((&DAT_08105224)[iVar7 * 0x16] != 0)) ||
         ((&DAT_08105228)[iVar7 * 0x16] == 0)) {
        local_34 = *pfVar1;
        local_30 = (float)(&DAT_081051ec)[iVar7 * 0x16];
        local_2c = (float)(&DAT_081051f0)[iVar7 * 0x16];
        local_68 = 1;
        if ((&DAT_081051f4)[iVar7 * 0x16] == 0) {
          if (((*(int *)(&DAT_081051f8 + iVar5) == 0) ||
              (*(int *)(*(int *)(&DAT_081051f8 + iVar5) + 0x44) != 3)) ||
             (((*(byte *)(*(int *)(&DAT_081051f8 + iVar5) + 0x51) & 2) == 0 && (DAT_081051c0 != 2)))
             ) {
            iVar6 = DAT_081051c0 * 0xc;
            local_10 = *(float *)(&DAT_081051fc + iVar5) - *(float *)(player_maxs + iVar6);
            local_c = *(float *)(&DAT_08105200 + iVar5) - *(float *)(player_maxs + iVar6 + 4);
            local_8 = *(float *)(&DAT_08105204 + iVar5) - *(float *)(player_maxs + iVar6 + 8);
            local_1c = *(float *)(&DAT_08105208 + iVar5) - (float)(&player_mins)[DAT_081051c0 * 3];
            local_18 = *(float *)(&DAT_0810520c + iVar5) - (float)(&DAT_080aae04)[DAT_081051c0 * 3];
            local_14 = *(float *)(&DAT_08105210 + iVar5) - *(float *)(&DAT_080aae08 + iVar6);
            iVar5 = PM_HullForBox(&local_10,&local_1c);
          }
          else {
            iVar5 = PM_HullForStudioModel
                              (*(undefined4 *)(&DAT_081051f8 + iVar5),&local_34,
                               *(undefined4 *)(&DAT_08105230 + iVar5),
                               *(undefined4 *)(&DAT_08105234 + iVar5),&DAT_08105218 + iVar7 * 0x16,
                               pfVar1,iVar5 + 0x8105238,iVar5 + 0x810523c,&local_68);
          }
        }
        else {
          iVar5 = PM_HullForBsp(pfVar1,&local_34);
        }
        local_28 = *param_1 - local_34;
        local_24 = param_1[1] - local_30;
        local_20 = param_1[2] - local_2c;
        if (((&DAT_08105224)[iVar7 * 0x16] == 4) &&
           ((((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_08105218)[iVar7 * 0x16]) << 10) >> 8)
                    | (byte)((ushort)((ushort)((float)(&DAT_08105218)[iVar7 * 0x16] == 0.0) << 0xe)
                            >> 8)) != 0x40 ||
             ((byte)((byte)((ushort)((ushort)NAN((float)(&DAT_0810521c)[iVar7 * 0x16]) << 10) >> 8)
                    | (byte)((ushort)((ushort)((float)(&DAT_0810521c)[iVar7 * 0x16] == 0.0) << 0xe)
                            >> 8)) != 0x40)) ||
            (fVar2 = (float)(&DAT_08105220)[iVar7 * 0x16],
            (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)))) {
          AngleVectors(&DAT_08105218 + iVar7 * 0x16,&local_40,&local_4c,&local_58);
          local_64 = local_28;
          local_60 = local_24;
          local_5c = local_20;
          fVar4 = local_20 * local_38;
          fVar3 = local_28 * local_4c;
          fVar2 = local_20 * local_44;
          local_20 = local_20 * local_50 + local_24 * local_54 + local_28 * local_58;
          local_28 = fVar4 + local_24 * local_3c + local_28 * local_40;
          local_24 = -(fVar2 + local_24 * local_48 + fVar3);
        }
        if (local_68 == 1) {
          PM_global_testContents = PM_HullPointContents(iVar5,*(undefined4 *)(iVar5 + 8),&local_28);
          if (PM_global_testContents == -2) {
            return iVar7;
          }
        }
        else {
          iVar6 = 0;
          if (0 < local_68) {
            do {
              PM_global_testContents =
                   PM_HullPointContents
                             (iVar6 * 0x28 + iVar5,*(undefined4 *)(iVar5 + 8 + iVar6 * 0x28),
                              &local_28);
              if (PM_global_testContents == -2) {
                return iVar7;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < local_68);
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_081051e4);
  }
  return -1;
}


// PM_TraceModel  @ 08069130
longdouble PM_TraceModel(undefined4 param_1,float *param_2,float *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  uVar1 = DAT_081051c0;
  DAT_081051c0 = 2;
  iVar2 = PM_HullForBsp(param_1,&local_28);
  local_10 = *param_2 - local_28;
  local_c = param_2[1] - local_24;
  local_8 = param_2[2] - local_20;
  local_1c = *param_3 - local_28;
  local_18 = param_3[1] - local_24;
  local_14 = param_3[2] - local_20;
  DAT_081051c0 = uVar1;
  SV_RecursiveHullCheck(iVar2,*(undefined4 *)(iVar2 + 8),0,0x3f800000,&local_10,&local_1c,param_4);
  return (longdouble)*(float *)(param_4 + 0x10);
}


// PM_TruePointContents  @ 0806a230
undefined4 PM_TruePointContents(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (DAT_081051f4 + 0xd0 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = PM_HullPointContents(DAT_081051f4 + 0xd0,*(undefined4 *)(DAT_081051f4 + 0xd8),param_1);
  }
  return uVar1;
}


// PM_WalkMove  @ 080670a0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_WalkMove(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  int local_a8;
  int local_a4;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_80;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
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
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10 [3];
  
  fVar2 = _DAT_081125c0;
  fVar1 = _DAT_081125bc;
  _DAT_080ca0f0 = 0;
  _DAT_080c9e9c = 0;
  VectorNormalize(&forward);
  VectorNormalize(&right);
  iVar3 = 0;
  do {
    local_10[iVar3] = fVar2 * (float)(&right)[iVar3] + fVar1 * (float)(&forward)[iVar3];
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  local_10[2] = 0.0;
  local_1c = local_10[0];
  local_18 = local_10[1];
  local_14 = 0;
  lVar4 = (longdouble)VectorNormalize(&local_1c);
  if ((longdouble)_DAT_081051e0 < lVar4) {
    VectorScale(local_10,(float)((longdouble)_DAT_081051e0 / lVar4),local_10);
    lVar4 = (longdouble)_DAT_081051e0;
  }
  _DAT_0810518c = 0.0;
  PM_Accelerate(&local_1c,(float)lVar4,movevars._20_4_);
  DAT_08105184 = DAT_08105184 + _DAT_0810519c;
  DAT_08105188 = DAT_08105188 + _DAT_081051a0;
  _DAT_0810518c = _DAT_081051a4 + 0.0;
  lVar4 = (longdouble)Length(&DAT_08105184);
  iVar3 = onground;
  if ((longdouble)1 <= lVar4) {
    local_34 = DAT_08105184 * frametime + DAT_0810516c;
    local_30 = DAT_08105188 * frametime + DAT_08105170;
    local_20 = _DAT_08105174;
    local_2c = _DAT_08105174;
    local_28 = local_34;
    local_24 = local_30;
    PM_PlayerMove(&local_a8,&DAT_0810516c,&local_28,0);
    if ((byte)((byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_98 == 1.0) << 0xe) >> 8)) == 0x40) {
      DAT_0810516c = local_94;
      DAT_08105170 = local_90;
      _DAT_08105174 = local_8c;
    }
    else if (((iVar3 != -1) || (waterlevel != 0)) &&
            ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
                   (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) == 0x40)) {
      local_40 = DAT_0810516c;
      local_3c = DAT_08105170;
      local_38 = _DAT_08105174;
      local_4c = DAT_08105184;
      local_48 = DAT_08105188;
      local_44 = _DAT_0810518c;
      PM_FlyMove();
      local_58 = DAT_0810516c;
      local_54 = DAT_08105170;
      local_50 = _DAT_08105174;
      local_64 = DAT_08105184;
      local_60 = DAT_08105188;
      local_5c = _DAT_0810518c;
      DAT_0810516c = local_40;
      DAT_08105170 = local_3c;
      _DAT_08105174 = local_38;
      DAT_08105184 = local_4c;
      DAT_08105188 = local_48;
      _DAT_0810518c = local_44;
      local_28 = local_40;
      local_24 = local_3c;
      local_20 = local_38 + (float)movevars._52_4_;
      PM_PlayerMove(&local_a8,&DAT_0810516c,&local_28,0);
      if ((local_a4 == 0) && (local_a8 == 0)) {
        DAT_0810516c = local_94;
        DAT_08105170 = local_90;
        _DAT_08105174 = local_8c;
      }
      PM_FlyMove();
      local_28 = DAT_0810516c;
      local_24 = DAT_08105170;
      local_20 = _DAT_08105174 - (float)movevars._52_4_;
      PM_PlayerMove(&local_a8,&DAT_0810516c,&local_28,0);
      if (0.7 <= local_80) {
        if ((local_a4 == 0) && (local_a8 == 0)) {
          DAT_0810516c = local_94;
          DAT_08105170 = local_90;
          _DAT_08105174 = local_8c;
        }
        up._0_4_ = DAT_0810516c;
        up._4_4_ = DAT_08105170;
        up._8_4_ = _DAT_08105174;
        fVar1 = (local_54 - local_3c) * (local_54 - local_3c) +
                (local_58 - local_40) * (local_58 - local_40);
        fVar2 = (DAT_08105170 - local_3c) * (DAT_08105170 - local_3c) +
                (DAT_0810516c - local_40) * (DAT_0810516c - local_40);
        if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) {
          _DAT_0810518c = local_5c;
          return;
        }
      }
      DAT_0810516c = local_58;
      DAT_08105170 = local_54;
      _DAT_08105174 = local_50;
      DAT_08105184 = local_64;
      DAT_08105188 = local_60;
      _DAT_0810518c = local_5c;
    }
  }
  else {
    DAT_08105184 = (float)vec3_origin._0_4_;
    DAT_08105188 = (float)vec3_origin._4_4_;
    _DAT_0810518c = (float)vec3_origin._8_4_;
  }
  return;
}


// PM_WaterEntity  @ 0806a1e0
undefined4 PM_WaterEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  iVar1 = PM_HullPointContents(DAT_081051f4 + 0xd0,*(undefined4 *)(DAT_081051f4 + 0xd8),param_1);
  if (iVar1 < -2) {
    local_8 = 0;
  }
  if (iVar1 != -2) {
    PM_SimulateLinkContents(param_1,&local_8);
  }
  return local_8;
}


// PM_WaterJump  @ 08068bc0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_WaterJump(void)

{
  if ((byte)(2.0 < _DAT_081051d0 | (byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_081051d0 == 2.0) << 0xe) >> 8)) == 1) {
    _DAT_081051d0 = 2.0;
  }
  if ((byte)(0.0 < _DAT_081051d0 | (byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) != 0x40) {
    _DAT_081051d0 = _DAT_081051d0 - frametime;
    if (((byte)((_DAT_081051d0 < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
                (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) - 1) < 0x40) ||
       (waterlevel == 0)) {
      _DAT_081051d0 = 0.0;
      DAT_081051bc._1_1_ = DAT_081051bc._1_1_ & 0xf7;
    }
    DAT_08105184 = _DAT_08105190;
    DAT_08105188 = _DAT_08105194;
  }
  return;
}


// PM_WaterMove  @ 08067840
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PM_WaterMove(void)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_90;
  float local_8c;
  int local_84;
  int local_80;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  float local_10 [3];
  
  iVar2 = 0;
  do {
    local_10[iVar2] =
         (float)(&right)[iVar2] * _DAT_081125c0 + (float)(&forward)[iVar2] * _DAT_081125bc;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  if ((((byte)((byte)((ushort)((ushort)NAN(_DAT_081125bc) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_081125bc == 0.0) << 0xe) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(_DAT_081125c0) << 10) >> 8) |
             (byte)((ushort)((ushort)(_DAT_081125c0 == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((byte)((byte)((ushort)((ushort)NAN(_DAT_081125c4) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_081125c4 == 0.0) << 0xe) >> 8)) == 0x40)) {
    local_14 = local_10[2] - 60.0;
  }
  else {
    local_14 = local_10[2] + _DAT_081125c4;
  }
  local_1c = local_10[0];
  local_18 = local_10[1];
  local_10[2] = local_14;
  lVar3 = (longdouble)VectorNormalize(&local_1c);
  local_8c = (float)lVar3;
  if ((longdouble)_DAT_081051e0 < lVar3) {
    VectorScale(local_10,(float)((longdouble)_DAT_081051e0 / lVar3),local_10);
    local_8c = _DAT_081051e0;
  }
  local_8c = local_8c * 0.8;
  DAT_08105184 = DAT_08105184 + _DAT_0810519c;
  DAT_08105188 = DAT_08105188 + _DAT_081051a0;
  _DAT_0810518c = _DAT_0810518c + _DAT_081051a4;
  local_40 = DAT_08105184;
  local_3c = DAT_08105188;
  local_38 = _DAT_0810518c;
  lVar4 = (longdouble)VectorNormalize(&local_40);
  lVar3 = (longdouble)0;
  if ((byte)(lVar3 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar3 == lVar4) << 0xe) >> 8)) == 0x40) {
    local_90 = 0.0;
  }
  else {
    lVar5 = lVar4 - lVar4 * (longdouble)frametime * (longdouble)(float)movevars._32_4_ *
                    (longdouble)_DAT_081051c8;
    if ((byte)(lVar5 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar5 == lVar3) << 0xe) >> 8)) == 1) {
      lVar5 = lVar3;
    }
    local_90 = (float)lVar5;
    VectorScale(&DAT_08105184,(float)((longdouble)local_90 / lVar4),&DAT_08105184);
  }
  if (0.1 <= local_8c) {
    local_90 = local_8c - local_90;
    if ((byte)(0.0 < local_90 | (byte)((ushort)((ushort)NAN(local_90) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_90 == 0.0) << 0xe) >> 8)) == 1) {
      VectorNormalize(local_10);
      fVar1 = local_8c * (float)movevars._20_4_ * frametime * _DAT_081051c8;
      if (local_90 < fVar1) {
        fVar1 = local_90;
      }
      iVar2 = 0;
      do {
        (&DAT_08105184)[iVar2] = fVar1 * local_10[iVar2] + (&DAT_08105184)[iVar2];
        iVar2 = iVar2 + 1;
      } while (iVar2 < 3);
    }
    VectorMA(&DAT_0810516c,frametime,&DAT_08105184,&local_34);
    local_28 = local_34;
    local_24 = local_30;
    local_20 = (float)movevars._52_4_ + 1.0 + local_2c;
    PM_PlayerMove(&local_84,&local_28,&local_34,0);
    if ((local_80 == 0) && (local_84 == 0)) {
      DAT_0810516c = local_70;
      DAT_08105170 = local_6c;
      _DAT_08105174 = local_68;
    }
    else {
      PM_FlyMove();
    }
  }
  return;
}


// PM_WorldTrace  @ 0806b280
int * PM_WorldTrace(int *param_1,float *param_2,float *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48 [4];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_18;
  
  piVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  local_38 = 1.0;
  local_18 = 0xffffffff;
  local_34 = *param_3;
  local_30 = param_3[1];
  local_2c = param_3[2];
  local_54 = DAT_081051e8;
  local_50 = DAT_081051ec;
  local_4c = DAT_081051f0;
  if (DAT_081051f4 == 0) {
    Con_DPrintf("No world in PM_Worldtrace!!!\n");
  }
  else {
    if (DAT_081051c0 == 1) {
      local_70 = DAT_081051f4 + 0x148;
    }
    else if (DAT_081051c0 < 2) {
      if (DAT_081051c0 == 0) {
        local_70 = DAT_081051f4 + 0xf8;
      }
    }
    else if (DAT_081051c0 == 2) {
      local_70 = DAT_081051f4 + 0xd0;
    }
    local_54 = (*(float *)(local_70 + 0x10) - (float)(&player_mins)[DAT_081051c0 * 3]) +
               DAT_081051e8;
    local_50 = (*(float *)(local_70 + 0x14) - (float)(&DAT_080aae04)[DAT_081051c0 * 3]) +
               DAT_081051ec;
    local_4c = (*(float *)(local_70 + 0x18) - *(float *)(&DAT_080aae08 + DAT_081051c0 * 0xc)) +
               DAT_081051f0;
    local_60 = *param_2 - local_54;
    local_5c = param_2[1] - local_50;
    local_58 = param_2[2] - local_4c;
    local_6c = *param_3 - local_54;
    local_68 = param_3[1] - local_50;
    local_64 = param_3[2] - local_4c;
    PM_RecursiveHullCheck
              (local_70,*(undefined4 *)(local_70 + 8),0,0x3f800000,&local_60,&local_6c,local_48);
    if (local_48[0] != 0) {
      local_48[1] = 1;
    }
    if (local_48[1] != 0) {
      local_38 = 0.0;
    }
    if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
      local_34 = (*param_3 - *param_2) * local_38 + *param_2;
      local_30 = (param_3[1] - param_2[1]) * local_38 + param_2[1];
      local_2c = (param_3[2] - param_2[2]) * local_38 + param_2[2];
    }
  }
  piVar2 = local_48;
  piVar3 = param_1;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  return param_1;
}


