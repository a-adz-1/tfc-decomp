// PM_Accelerate  @ 001215a4
void PM_Accelerate(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  if (((*(int *)(pmove + 0xd0) == 0) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40)) &&
     (fVar1 = param_2 - (*(float *)(pmove + 100) * param_1[2] +
                        *(float *)(pmove + 0x60) * param_1[1] + *(float *)(pmove + 0x5c) * *param_1)
     , 0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
    fVar2 = param_3 * *(float *)(pmove + 0x10) * param_2 * *(float *)(pmove + 0xc4);
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar2 = fVar1;
    }
    *(float *)(pmove + 0x5c) = fVar2 * *param_1 + *(float *)(pmove + 0x5c);
    *(float *)(pmove + 0x60) = fVar2 * param_1[1] + *(float *)(pmove + 0x60);
    *(float *)(pmove + 100) = fVar2 * param_1[2] + *(float *)(pmove + 100);
  }
  return;
}


// PM_AddCorrectGravity  @ 00120c18
void PM_AddCorrectGravity(void)

{
  FUN_00120c21();
  return;
}


// PM_AddGravity  @ 00124068
void PM_AddGravity(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(pmove + 0xc0);
  fVar2 = 1.0;
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar2 = fVar1;
  }
  *(float *)(pmove + 100) =
       *(float *)(pmove + 100) -
       fVar2 * **(float **)((int)&__DT_REL[0x114f].r_offset + pmove) * *(float *)(pmove + 0x10);
  *(float *)(pmove + 100) =
       *(float *)(pmove + 0x7c) * *(float *)(pmove + 0x10) + *(float *)(pmove + 100);
  *(undefined4 *)(pmove + 0x7c) = 0;
  PM_CheckVelocity();
  return;
}


// PM_AddToTouched  @ 001208f8
undefined4 PM_AddToTouched(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int in_stack_00000034;
  undefined4 uStack00000038;
  undefined4 uStack0000003c;
  undefined4 uStack00000040;
  undefined4 *in_stack_00000048;
  int local_4;
  
  local_4 = 0;
  if (0 < *(int *)("SecondaryAttack__6CTFRpg" + pmove + 2)) {
    iVar3 = 0;
    do {
      if (*(int *)("__vt_6CTFRpg" + pmove + iVar3 + 9) == in_stack_00000034) break;
      iVar3 = iVar3 + 0x44;
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)("SecondaryAttack__6CTFRpg" + pmove + 2));
  }
  if (local_4 == *(int *)("SecondaryAttack__6CTFRpg" + pmove + 2)) {
    uStack00000038 = *in_stack_00000048;
    uStack0000003c = in_stack_00000048[1];
    uStack00000040 = in_stack_00000048[2];
    if (599 < *(int *)("SecondaryAttack__6CTFRpg" + pmove + 2)) {
      (**(code **)((int)&__DT_REL[0x115d].r_info + pmove))("Too many entities were touched!\n");
    }
    iVar3 = pmove;
    pcVar4 = "SecondaryAttack__6CTFRpg" +
             (*(int *)("SecondaryAttack__6CTFRpg" + pmove + 2) * 0x10 +
             *(int *)("SecondaryAttack__6CTFRpg" + pmove + 2)) * 4 + pmove + 6;
    for (iVar2 = 0x11; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4),
        iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)register0x00000010;
      pcVar4 = pcVar4 + 4;
    }
    *(int *)("SecondaryAttack__6CTFRpg" + iVar3 + 2) =
         *(int *)("SecondaryAttack__6CTFRpg" + iVar3 + 2) + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// PM_AirAccelerate  @ 00121ec8
void PM_AirAccelerate(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  if ((*(int *)(pmove + 0xd0) == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar2 = param_2;
    if (30.0 < param_2) {
      fVar2 = 30.0;
    }
    fVar2 = fVar2 - (*(float *)(pmove + 100) * param_1[2] +
                    *(float *)(pmove + 0x60) * param_1[1] + *(float *)(pmove + 0x5c) * *param_1);
    if (0.0 < fVar2) {
      fVar1 = param_3 * param_2 * *(float *)(pmove + 0x10) * *(float *)(pmove + 0xc4);
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        fVar1 = fVar2;
      }
      *(float *)(pmove + 0x5c) = fVar1 * *param_1 + *(float *)(pmove + 0x5c);
      *(float *)(pmove + 0x60) = fVar1 * param_1[1] + *(float *)(pmove + 0x60);
      *(float *)(pmove + 100) = fVar1 * param_1[2] + *(float *)(pmove + 100);
    }
  }
  return;
}


// PM_AirMove  @ 001223d8
void PM_AirMove(void)

{
  FUN_001223e2();
  return;
}


// PM_CalcRoll  @ 001250ec
longdouble PM_CalcRoll(undefined4 param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  undefined1 local_24 [12];
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  AngleVectors(param_1,local_c,&local_18,local_24);
  fVar2 = param_2[2] * local_10 + param_2[1] * local_14 + *param_2 * local_18;
  fVar1 = 1.0;
  if (fVar2 < 0.0) {
    fVar1 = -1.0;
  }
  lVar3 = (longdouble)ABS(fVar2);
  lVar4 = (longdouble)param_3;
  if (lVar3 < (longdouble)param_4) {
    lVar4 = (lVar3 * lVar4) / (longdouble)param_4;
  }
  return lVar4 * (longdouble)fVar1;
}


// PM_CatagorizePosition  @ 001227b0
void PM_CatagorizePosition(void)

{
  int iVar1;
  code **ppcVar2;
  undefined4 *puVar3;
  undefined4 auStack_b0 [13];
  undefined4 uStack_7c;
  int *piStack_78;
  int iStack_74;
  undefined4 *puStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  code *local_54;
  int local_50 [4];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_2c;
  int local_24;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  uStack_68 = 0x1227c7;
  PM_CheckWater();
  local_c = *(undefined4 *)(pmove + 0x38);
  local_8 = *(undefined4 *)(pmove + 0x3c);
  local_4 = *(float *)(pmove + 0x40) - 2.0;
  if (*(float *)(pmove + 100) <= 180.0) {
    piStack_78 = local_50;
    uStack_68 = 0xffffffff;
    iStack_6c = 0;
    puStack_70 = &local_c;
    iStack_74 = pmove + 0x38;
    local_54 = *(code **)((int)&__DT_REL[0x1161].r_offset + pmove);
    uStack_7c = 0x12284e;
    (*local_54)();
    if ((byte)((0.7 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_2c == 0.7) << 0xe) >> 8)) - 1) < 0x40) {
      *(int *)(pmove + 0xe0) = local_24;
    }
    else {
      *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
    }
    if (*(int *)(pmove + 0xe0) != -1) {
      *(undefined4 *)(pmove + 0xcc) = 0;
      if (((*(int *)(pmove + 0xe4) < 2) && (local_50[0] == 0)) && (local_54 == (code *)0x0)) {
        *(undefined4 *)(pmove + 0x38) = local_40;
        *(undefined4 *)(pmove + 0x3c) = local_3c;
        *(undefined4 *)(pmove + 0x40) = local_38;
      }
    }
    if (0 < local_24) {
      iStack_6c = pmove + 0x5c;
      ppcVar2 = &local_54;
      puVar3 = auStack_b0;
      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *ppcVar2;
        ppcVar2 = ppcVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      PM_AddToTouched();
    }
  }
  else {
    *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
  }
  return;
}


// PM_CatagorizeTextureType  @ 001203e4
void PM_CatagorizeTextureType(void)

{
  undefined1 uVar1;
  char *__src;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(pmove + 0x38);
  local_8 = *(undefined4 *)(pmove + 0x3c);
  local_4 = *(undefined4 *)(pmove + 0x40);
  local_18 = *(undefined4 *)(pmove + 0x38);
  local_14 = *(undefined4 *)(pmove + 0x3c);
  local_10 = *(float *)(pmove + 0x40) - 64.0;
  *(undefined1 *)(pmove + 0xf0) = 0;
  *(undefined1 *)(pmove + 0x1f0) = 0x43;
  __src = (char *)(**(code **)((int)&__DT_REL[0x1168].r_offset + pmove))
                            (*(undefined4 *)(pmove + 0xe0),&local_c,&local_18);
  if (__src != (char *)0x0) {
    if ((*__src == '-') || (*__src == '+')) {
      __src = __src + 2;
    }
    if ((((*__src == '{') || (*__src == '!')) || (*__src == '~')) || (*__src == ' ')) {
      __src = __src + 1;
    }
    strcpy((char *)(pmove + 0xf0),__src);
    *(undefined1 *)(pmove + 0xfc) = 0;
    uVar1 = PM_FindTextureType(pmove + 0xf0);
    *(undefined1 *)(pmove + 0x1f0) = uVar1;
  }
  return;
}


// PM_CheckFalling  @ 00124dc0
void PM_CheckFalling(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  float local_8;
  
  if (((*(int *)(pmove + 0xe0) != -1) && (*(int *)(pmove + 0xd0) == 0)) &&
     (350.0 <= *(float *)(pmove + 0x9c))) {
    local_8 = 0.5;
    if (*(int *)(pmove + 0xe4) < 1) {
      if (*(float *)(pmove + 0x9c) <= 580.0) {
        if (*(float *)(pmove + 0x9c) <= 290.0) {
          fVar1 = *(float *)(pmove + 0x9c);
          if (0x3f < (byte)((200.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == 200.0) << 0xe) >> 8)) - 1)) {
            local_8 = 0.0;
          }
        }
        else {
          uVar3 = (**(code **)((int)&__DT_REL[0x115b].r_info + pmove))
                            (pmove + 0x4f3f0,&UNK_001456d0);
          iVar2 = __strtol_internal(uVar3,0,10,0);
          if (iVar2 == 1) {
            (**(code **)((int)&__DT_REL[0x1167].r_info + pmove))
                      (2,"player/pl_fallpain3.wav",0x3f800000,0x3f4ccccd,0,100);
          }
          local_8 = 0.85;
        }
      }
      else {
        (**(code **)((int)&__DT_REL[0x1167].r_info + pmove))
                  (2,"player/pl_fallpain3.wav",0x3f800000,0x3f4ccccd,0,100);
        local_8 = 1.0;
      }
    }
    if (0.0 < local_8) {
      *(undefined4 *)(pmove + 0x94) = 0;
      PM_UpdateStepSound();
      uVar3 = PM_MapTextureTypeStepType((int)*(char *)(pmove + 0x1f0),local_8);
      PM_PlayStepSound(uVar3);
      *(float *)(pmove + 0xa8) = *(float *)(pmove + 0x9c) * 0.013;
      if (8.0 < *(float *)(pmove + 0xa0)) {
        *(undefined4 *)(pmove + 0xa0) = 0x41000000;
      }
    }
  }
  if (*(int *)(pmove + 0xe0) != -1) {
    *(undefined4 *)(pmove + 0x9c) = 0;
  }
  return;
}


// PM_CheckParamters  @ 0012521c
void PM_CheckParamters(void)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  longdouble lVar5;
  float local_c;
  float local_8;
  float local_4;
  
  fVar4 = SQRT(*(float *)("Holster__6CTFRpgi" + pmove + 0xf) *
               *(float *)("Holster__6CTFRpgi" + pmove + 0xf) +
               *(float *)("Holster__6CTFRpgi" + pmove + 0xb) *
               *(float *)("Holster__6CTFRpgi" + pmove + 0xb) +
               *(float *)("Holster__6CTFRpgi" + pmove + 7) *
               *(float *)("Holster__6CTFRpgi" + pmove + 7));
  fVar2 = *(float *)(pmove + 0x1f8);
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar3 = *(float *)(pmove + 500);
    if (0x3f < (byte)((fVar3 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1)) {
      fVar3 = fVar2;
    }
    *(float *)(pmove + 500) = fVar3;
  }
  if (((byte)(0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (fVar2 = *(float *)(pmove + 500),
     0x3f < (byte)((fVar4 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar4 == fVar2) << 0xe) >> 8)) - 1))) {
    fVar4 = *(float *)(pmove + 500) / fVar4;
    *(float *)("Holster__6CTFRpgi" + pmove + 7) =
         fVar4 * *(float *)("Holster__6CTFRpgi" + pmove + 7);
    *(float *)("Holster__6CTFRpgi" + pmove + 0xb) =
         fVar4 * *(float *)("Holster__6CTFRpgi" + pmove + 0xb);
    *(float *)("Holster__6CTFRpgi" + pmove + 0xf) =
         fVar4 * *(float *)("Holster__6CTFRpgi" + pmove + 0xf);
  }
  if (((*(uint *)(pmove + 0xb8) & 0x1001000) != 0) || (*(int *)(pmove + 0xd0) != 0)) {
    pcVar1 = "Holster__6CTFRpgi" + pmove + 7;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1 = "Holster__6CTFRpgi" + pmove + 0xb;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1 = "Holster__6CTFRpgi" + pmove + 0xf;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
  }
  PM_DropPunchAngle(pmove + 0xa0);
  if (*(int *)(pmove + 0xd0) == 0) {
    local_c = *(float *)("CanHolster__6CTFRpg" + pmove + 0xf) + *(float *)(pmove + 0xa0);
    local_8 = *(float *)("CanHolster__6CTFRpg" + pmove + 0x13) + *(float *)(pmove + 0xa4);
    local_4 = *(float *)("Holster__6CTFRpgi" + pmove + 3) + *(float *)(pmove + 0xa8);
    lVar5 = (longdouble)
            PM_CalcRoll(&local_c,pmove + 0x5c,
                        *(undefined4 *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 100),
                        *(undefined4 *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x68));
    *(float *)(pmove + 0x4c) = (float)((longdouble)4.0 * lVar5);
    *(float *)(pmove + 0x44) = local_c;
    *(float *)(pmove + 0x48) = local_8;
  }
  else {
    *(undefined4 *)(pmove + 0x44) = *(undefined4 *)(pmove + 0x50);
    *(undefined4 *)(pmove + 0x48) = *(undefined4 *)(pmove + 0x54);
    *(undefined4 *)(pmove + 0x4c) = *(undefined4 *)(pmove + 0x58);
  }
  if (*(int *)(pmove + 0xd0) != 0) {
    *(undefined4 *)(pmove + 0x88) = 0xc1000000;
  }
  if (180.0 < *(float *)(pmove + 0x48)) {
    *(float *)(pmove + 0x48) = *(float *)(pmove + 0x48) - 360.0;
  }
  return;
}


// PM_CheckStuck  @ 001229e4
undefined4 PM_CheckStuck(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  longdouble lVar6;
  float fStack_80;
  int local_74;
  undefined1 local_68 [68];
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = (*(code *)pmove[0x13d57])(pmove + 0xe,local_68);
  if (iVar3 == -1) {
    PM_ResetStuckOffsets(*pmove,pmove[1]);
LAB_00122df9:
    uVar5 = 0;
  }
  else {
    local_c = (float)pmove[0xe];
    local_8 = (float)pmove[0xf];
    local_4 = (float)pmove[0x10];
    if ((pmove[1] == 0) && ((iVar3 == 0 || (pmove[iVar3 * 0x38 + 0xa0] != 0)))) {
      local_74 = 0;
      PM_ResetStuckOffsets(*pmove,pmove[1]);
      do {
        PM_GetRandomStuckOffsets(*pmove,pmove[1],&local_18);
        local_24 = local_c + local_18;
        local_20 = local_8 + local_14;
        local_1c = local_4 + local_10;
        iVar4 = (*(code *)pmove[0x13d57])(&local_24,local_68);
        if (iVar4 == -1) {
LAB_00122db0:
          PM_ResetStuckOffsets(*pmove,pmove[1]);
          pmove[0xe] = (int)local_24;
          pmove[0xf] = (int)local_20;
          pmove[0x10] = (int)local_1c;
          goto LAB_00122df9;
        }
        PM_GetRandomStuckOffsets(*pmove,pmove[1],&local_18);
        local_24 = local_c + local_18;
        local_20 = local_8 + local_14;
        local_1c = local_4 + local_10;
        iVar4 = (*(code *)pmove[0x13d57])(&local_24,local_68);
        if (iVar4 == -1) goto LAB_00122db0;
        PM_GetRandomStuckOffsets(*pmove,pmove[1],&local_18);
        local_24 = local_c + local_18;
        local_20 = local_8 + local_14;
        local_1c = local_4 + local_10;
        iVar4 = (*(code *)pmove[0x13d57])(&local_24,local_68);
        if (iVar4 == -1) goto LAB_00122db0;
        local_74 = local_74 + 3;
      } while (local_74 < 0x36);
    }
    iVar4 = pmove[1];
    lVar6 = (longdouble)(*(code *)pmove[0x13d5b])();
    if (*(float *)(rgStuckCheckTime_147 + (uint)(iVar4 == 0) * 4 + *pmove * 8) < (float)lVar6 - 0.05
       ) {
      *(float *)(rgStuckCheckTime_147 + (uint)(iVar4 == 0) * 4 + *pmove * 8) = (float)lVar6;
      (*(code *)pmove[0x13d5c])(iVar3,local_68);
      iVar3 = PM_GetRandomStuckOffsets(*pmove,pmove[1],&local_18);
      local_24 = local_c + local_18;
      local_20 = local_8 + local_14;
      local_1c = local_4 + local_10;
      iVar4 = (*(code *)pmove[0x13d57])(&local_24,0);
      if (iVar4 == -1) {
        PM_ResetStuckOffsets(*pmove,pmove[1]);
        if (0x1a < iVar3) {
LAB_00122e04:
          pmove[0xe] = (int)local_24;
          pmove[0xf] = (int)local_20;
          pmove[0x10] = (int)local_1c;
        }
        uVar5 = 0;
      }
      else {
        if (((*(byte *)((int)pmove + 0x45476) & 7) != 0) && (pmove[iVar4 * 0x38 + 0x9c] != 0)) {
          fStack_80 = 0.0;
          do {
            fVar1 = -8.0;
            while ((byte)((fVar1 < 8.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == 8.0) << 0xe) >> 8)) - 1) < 0x40) {
              fVar2 = -8.0;
              while ((byte)((fVar2 < 8.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == 8.0) << 0xe) >> 8)) - 1) < 0x40) {
                local_24 = fVar1 + local_c;
                local_20 = fVar2 + local_8;
                local_1c = fStack_80 + local_4;
                iVar3 = (*(code *)pmove[0x13d57])(&local_24,0);
                if (iVar3 == -1) goto LAB_00122e04;
                fVar2 = fVar2 + 8.0;
              }
              fVar1 = fVar1 + 8.0;
            }
            fStack_80 = fStack_80 + 18.0;
          } while ((byte)((fStack_80 < 72.0 | (byte)((ushort)((ushort)NAN(fStack_80) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fStack_80 == 72.0) << 0xe) >> 8)) - 1) < 0x40);
        }
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 1;
    }
  }
  return uVar5;
}


// PM_CheckVelocity  @ 001209e4
void PM_CheckVelocity(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    if ((*(uint *)(pmove + 0x5c + iVar3 * 4) & nanmask) == nanmask) {
      (**(code **)((int)&__DT_REL[0x115e].r_offset + pmove))("PM  Got a NaN velocity %i\n",iVar3);
      *(undefined4 *)(iVar4 + pmove + 0x5c) = 0;
    }
    if ((*(uint *)(pmove + 0x38 + iVar3 * 4) & nanmask) == nanmask) {
      (**(code **)((int)&__DT_REL[0x115e].r_offset + pmove))("PM  Got a NaN origin on %i\n",iVar3);
      *(undefined4 *)(iVar4 + pmove + 0x38) = 0;
    }
    fVar1 = *(float *)(iVar4 + 0x5c + pmove);
    fVar2 = *(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x34);
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
      fVar2 = -*(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x34);
      fVar1 = *(float *)(iVar4 + 0x5c + pmove);
      if (0x3f < (byte)((fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
        (**(code **)((int)&__DT_REL[0x115d].r_info + pmove))
                  ("PM  Got a velocity too low on %i\n",iVar3);
        fVar1 = -*(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x34);
        goto LAB_00120afe;
      }
    }
    else {
      (**(code **)((int)&__DT_REL[0x115d].r_info + pmove))
                ("PM  Got a velocity too high on %i\n",iVar3);
      fVar1 = *(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x34);
LAB_00120afe:
      *(float *)(iVar4 + 0x5c + pmove) = fVar1;
    }
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      return;
    }
  } while( true );
}


// PM_CheckWater  @ 00122590
bool PM_CheckWater(void)

{
  int iVar1;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = (*(float *)(pmove + 0x4f4f4 + *(int *)(pmove + 0xbc) * 0xc) +
            *(float *)(pmove + 0x4f524 + *(int *)(pmove + 0xbc) * 0xc)) * 0.5 +
            *(float *)(pmove + 0x38);
  local_10 = (*(float *)(pmove + 0x4f4f8 + *(int *)(pmove + 0xbc) * 0xc) +
             *(float *)(pmove + 0x4f528 + *(int *)(pmove + 0xbc) * 0xc)) * 0.5 +
             *(float *)(pmove + 0x3c);
  local_4 = *(float *)(pmove + 0x40) + *(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc) +
            1.0;
  *(undefined4 *)(pmove + 0xe4) = 0;
  *(undefined4 *)(pmove + 0xe8) = 0xffffffff;
  local_8 = local_10;
  iVar1 = (**(code **)((int)&__DT_REL[0x115f].r_info + pmove))(&local_c,&local_14);
  if (iVar1 + 0xeU < 0xc) {
    *(int *)(pmove + 0xe8) = iVar1;
    *(undefined4 *)(pmove + 0xe4) = 1;
    local_10 = (*(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc) +
               *(float *)(pmove + 0x4f52c + *(int *)(pmove + 0xbc) * 0xc)) * 0.5;
    local_4 = local_10 + *(float *)(pmove + 0x40);
    iVar1 = (**(code **)((int)&__DT_REL[0x115f].r_info + pmove))(&local_c,0);
    if (iVar1 + 0xeU < 0xc) {
      *(undefined4 *)(pmove + 0xe4) = 2;
      local_4 = *(float *)(pmove + 0x40) + *(float *)(pmove + 0x88);
      iVar1 = (**(code **)((int)&__DT_REL[0x115f].r_info + pmove))(&local_c,0);
      if (iVar1 + 0xeU < 0xc) {
        *(undefined4 *)(pmove + 0xe4) = 3;
      }
    }
    if (local_14 + 0xeU < 6) {
      local_10 = (float)*(int *)(pmove + 0xe4) * 50.0;
      VectorMA(pmove + 0x74,local_10,&current_table_138 + (-9 - local_14) * 0xc,pmove + 0x74);
    }
  }
  return 1 < *(int *)(pmove + 0xe4);
}


// PM_CheckWaterJump  @ 00124ae0
void PM_CheckWaterJump(void)

{
  float fVar1;
  int iVar2;
  code *pcVar3;
  longdouble lVar4;
  undefined1 auStack_74 [8];
  float fStack_6c;
  float fStack_68;
  undefined1 auStack_58 [8];
  float fStack_50;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined4 local_c;
  float local_8;
  float local_4;
  
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (-180.0 <= *(float *)(pmove + 100))) {
    local_30 = *(float *)(pmove + 0x5c);
    local_2c = *(float *)(pmove + 0x60);
    local_28 = 0.0;
    lVar4 = (longdouble)VectorNormalize(&local_30);
    fVar1 = (float)lVar4;
    local_24 = *(float *)(pmove + 0x14);
    local_20 = *(float *)(pmove + 0x18);
    local_1c = 0.0;
    VectorNormalize(&local_24);
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
       (fVar1 = local_28 * local_1c + local_2c * local_20 + local_30 * local_24,
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
      local_c = *(undefined4 *)(pmove + 0x38);
      local_8 = *(float *)(pmove + 0x3c);
      local_4 = *(float *)(pmove + 0x40) + 8.0;
      VectorMA(&local_c,0x41c00000,&local_24,local_18);
      iVar2 = *(int *)(pmove + 0xbc);
      *(undefined4 *)(pmove + 0xbc) = 2;
      pcVar3 = *(code **)((int)&__DT_REL[0x1161].r_offset + pmove);
      (*pcVar3)(auStack_74,&local_c,local_18,0,0xffffffff);
      if ((0x3f < (byte)((1.0 < fStack_68 | (byte)((ushort)((ushort)NAN(fStack_68) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fStack_68 == 1.0) << 0xe) >> 8)) - 1)) &&
         (fStack_50 = ABS(fStack_50),
         0x3f < (byte)((0.1 < fStack_50 | (byte)((ushort)((ushort)NAN(fStack_50) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fStack_50 == 0.1) << 0xe) >> 8)) - 1))) {
        local_8 = (*(float *)(pmove + 0x4f52c + iVar2 * 0xc) - 8.0) + local_8;
        VectorMA(&local_c,0x41c00000,auStack_74,local_18);
        VectorMA(&vec3_origin,0xc2480000,auStack_58,pmove + 0x68);
        (**(code **)((int)&__DT_REL[0x1161].r_offset + pmove))
                  (pcVar3,&local_c,local_18,0,0xffffffff);
        if ((byte)((byte)((ushort)((ushort)NAN(fStack_6c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_6c == 1.0) << 0xe) >> 8)) == 0x40) {
          *(undefined4 *)(pmove + 0xcc) = 0x44fa0000;
          *(undefined4 *)(pmove + 100) = 0x43610000;
          *(byte *)(pmove + 200) = *(byte *)(pmove + 200) | 2;
          *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) | 8;
        }
      }
      *(int *)(pmove + 0xbc) = iVar2;
    }
  }
  return;
}


// PM_ClipVelocity  @ 00120b18
byte PM_ClipVelocity(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  byte bVar2;
  
  fVar1 = param_2[2];
  bVar2 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar2 = bVar2 | 2;
  }
  param_4 = (param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2) * param_4;
  fVar1 = *param_1 - param_4 * *param_2;
  *param_3 = fVar1;
  if ((0x3f < (byte)((fVar1 < -0.1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == -0.1) << 0xe) >> 8)) - 1)) && (fVar1 < 0.1))
  {
    *param_3 = 0.0;
  }
  fVar1 = param_1[1] - param_4 * param_2[1];
  param_3[1] = fVar1;
  if ((0x3f < (byte)((fVar1 < -0.1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == -0.1) << 0xe) >> 8)) - 1)) && (fVar1 < 0.1))
  {
    param_3[1] = 0.0;
  }
  fVar1 = param_1[2] - param_4 * param_2[2];
  param_3[2] = fVar1;
  if ((0x3f < (byte)((fVar1 < -0.1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == -0.1) << 0xe) >> 8)) - 1)) && (fVar1 < 0.1))
  {
    param_3[2] = 0.0;
  }
  return bVar2;
}


// PM_CreateStuckTable  @ 00125abc
void PM_CreateStuckTable(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 auStack_c [3];
  
  puVar7 = &rgv3tStuckTable;
  for (iVar5 = 0xa2; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  iVar5 = 0;
  fVar1 = -0.125;
  iVar6 = 0;
  do {
    *(undefined4 *)((int)&rgv3tStuckTable + iVar6) = 0;
    *(undefined4 *)((int)&DAT_001b5da4 + iVar6) = 0;
    *(float *)((int)&DAT_001b5da8 + iVar6) = fVar1;
    iVar6 = iVar6 + 0xc;
    iVar5 = iVar5 + 1;
    fVar1 = fVar1 + 0.125;
  } while ((byte)((fVar1 < 0.125 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40);
  fVar1 = -0.125;
  iVar6 = iVar5 * 0xc;
  do {
    *(undefined4 *)((int)&rgv3tStuckTable + iVar6) = 0;
    *(float *)((int)&DAT_001b5da4 + iVar6) = fVar1;
    *(undefined4 *)((int)&DAT_001b5da8 + iVar6) = 0;
    iVar6 = iVar6 + 0xc;
    iVar5 = iVar5 + 1;
    fVar1 = fVar1 + 0.125;
  } while ((byte)((fVar1 < 0.125 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40);
  fVar1 = -0.125;
  iVar6 = iVar5 * 0xc;
  do {
    *(float *)((int)&rgv3tStuckTable + iVar6) = fVar1;
    *(undefined4 *)((int)&DAT_001b5da4 + iVar6) = 0;
    *(undefined4 *)((int)&DAT_001b5da8 + iVar6) = 0;
    iVar6 = iVar6 + 0xc;
    iVar5 = iVar5 + 1;
    fVar1 = fVar1 + 0.125;
  } while ((byte)((fVar1 < 0.125 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40);
  fVar1 = -0.125;
  do {
    fVar2 = -0.125;
    do {
      fVar3 = -0.125;
      iVar6 = iVar5 * 0xc;
      do {
        iVar8 = iVar5;
        *(float *)((int)&rgv3tStuckTable + iVar6) = fVar1;
        *(float *)((int)&DAT_001b5da4 + iVar6) = fVar2;
        *(float *)((int)&DAT_001b5da8 + iVar6) = fVar3;
        iVar6 = iVar6 + 0xc;
        iVar5 = iVar8 + 1;
        fVar3 = fVar3 + 0.25;
      } while ((byte)((fVar3 < 0.125 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == 0.125) << 0xe) >> 8)) - 1) < 0x40);
      fVar2 = fVar2 + 0.25;
    } while (fVar2 <= 0.125);
    fVar1 = fVar1 + 0.25;
  } while ((byte)((fVar1 < 0.125 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40);
  auStack_c[0] = 0;
  auStack_c[1] = 0x3f800000;
  auStack_c[2] = 0x40c00000;
  (&rgv3tStuckTable)[iVar5 * 3] = 0;
  (&DAT_001b5da4)[iVar5 * 3] = 0;
  (&DAT_001b5da8)[iVar5 * 3] = 0;
  (&DAT_001b5dac)[iVar5 * 3] = 0;
  (&DAT_001b5db0)[iVar5 * 3] = 0;
  (&DAT_001b5db4)[iVar5 * 3] = 0x3f800000;
  (&DAT_001b5db8)[iVar5 * 3] = 0;
  (&DAT_001b5dbc)[iVar5 * 3] = 0;
  (&DAT_001b5dc0)[iVar5 * 3] = 0x40c00000;
  iVar8 = iVar8 + 4;
  fVar1 = -2.0;
  iVar5 = iVar8 * 0xc;
  do {
    *(undefined4 *)((int)&rgv3tStuckTable + iVar5) = 0;
    *(float *)((int)&DAT_001b5da4 + iVar5) = fVar1;
    *(undefined4 *)((int)&DAT_001b5da8 + iVar5) = 0;
    iVar5 = iVar5 + 0xc;
    iVar8 = iVar8 + 1;
    fVar1 = fVar1 + 2.0;
  } while ((byte)((fVar1 < 2.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
  fVar1 = -2.0;
  iVar5 = iVar8 * 0xc;
  do {
    *(float *)((int)&rgv3tStuckTable + iVar5) = fVar1;
    *(undefined4 *)((int)&DAT_001b5da4 + iVar5) = 0;
    *(undefined4 *)((int)&DAT_001b5da8 + iVar5) = 0;
    iVar5 = iVar5 + 0xc;
    iVar8 = iVar8 + 1;
    fVar1 = fVar1 + 2.0;
  } while ((byte)((fVar1 < 2.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
  iVar5 = 0;
  do {
    uVar4 = auStack_c[iVar5];
    fVar1 = -2.0;
    do {
      fVar2 = -2.0;
      iVar6 = iVar8 * 0xc;
      do {
        *(float *)((int)&rgv3tStuckTable + iVar6) = fVar1;
        *(float *)((int)&DAT_001b5da4 + iVar6) = fVar2;
        *(undefined4 *)((int)&DAT_001b5da8 + iVar6) = uVar4;
        iVar6 = iVar6 + 0xc;
        iVar8 = iVar8 + 1;
        fVar2 = fVar2 + 2.0;
      } while ((byte)((fVar2 < 2.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
      fVar1 = fVar1 + 2.0;
    } while ((byte)((fVar1 < 2.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  return;
}


// PM_DrawBBox  @ 0011ebfc
/* WARNING: Removing unreachable block (ram,0x0011ec41) */

void PM_DrawBBox(float *param_1,float *param_2,float *param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  float *pfVar2;
  int iVar3;
  float *local_80;
  uint local_70;
  float local_6c [24];
  float local_c;
  float local_8;
  float local_4;
  
  local_70 = 0;
  local_80 = local_6c + 2;
  pfVar2 = local_6c + 1;
  iVar3 = 0;
  do {
    if ((local_70 & 2) == 0) {
      local_8 = param_2[1] + 0.0;
    }
    else {
      local_8 = param_1[1] - 0.0;
    }
    if ((local_70 & 4) == 0) {
      local_4 = param_2[2] + 0.0;
    }
    else {
      local_4 = param_1[2] - 0.0;
    }
    local_8 = local_8 + param_3[1];
    local_4 = local_4 + param_3[2];
    *(float *)((int)local_6c + iVar3) = *param_2 + 0.0 + *param_3;
    *pfVar2 = local_8;
    *local_80 = local_4;
    uVar1 = local_70 + 1;
    if ((uVar1 & 1) == 0) {
      local_c = *param_2 + 0.0;
    }
    else {
      local_c = *param_1 - 0.0;
    }
    if ((uVar1 & 2) == 0) {
      local_8 = param_2[1] + 0.0;
    }
    else {
      local_8 = param_1[1] - 0.0;
    }
    if ((uVar1 & 4) == 0) {
      local_4 = param_2[2] + 0.0;
    }
    else {
      local_4 = param_1[2] - 0.0;
    }
    local_c = local_c + *param_3;
    local_8 = local_8 + param_3[1];
    local_4 = local_4 + param_3[2];
    *(float *)((int)local_6c + iVar3 + 0xc) = local_c;
    pfVar2[3] = local_8;
    local_80[3] = local_4;
    local_80 = local_80 + 6;
    pfVar2 = pfVar2 + 6;
    iVar3 = iVar3 + 0x18;
    local_70 = local_70 + 2;
  } while ((int)local_70 < 8);
  local_70 = 0;
  iVar3 = 0;
  do {
    PM_DrawRectangle(local_6c + *(int *)((int)&DAT_0015d804 + iVar3) * 3,
                     local_6c + *(int *)((int)&PM_boxpnt + iVar3) * 3,
                     local_6c + *(int *)(&DAT_0015d808 + iVar3) * 3,
                     local_6c + *(int *)(&DAT_0015d80c + iVar3) * 3,param_4,param_5);
    PM_DrawRectangle(local_6c + *(int *)((int)&DAT_0015d814 + iVar3) * 3,
                     local_6c + *(int *)((int)&DAT_0015d810 + iVar3) * 3,
                     local_6c + *(int *)((int)&DAT_0015d818 + iVar3) * 3,
                     local_6c + *(int *)((int)&DAT_0015d81c + iVar3) * 3,param_4,param_5);
    iVar3 = iVar3 + 0x20;
    local_70 = local_70 + 2;
  } while ((int)local_70 < 6);
  return;
}


// PM_DrawPhysEntBBox  @ 0011e2a4
/* WARNING: Removing unreachable block (ram,0x0011e374) */
/* WARNING: Removing unreachable block (ram,0x0011e908) */

void PM_DrawPhysEntBBox(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  uint local_104;
  float *local_e0;
  int iStack_cc;
  int iStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78 [24];
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((param_1 < *(int *)(pmove + 0x24c)) && (0 < param_1)) {
    iVar1 = pmove + 0x250 + param_1 * 0xe0;
    if (*(int *)(iVar1 + 0x30) == 0) {
      local_104 = 0;
      iVar6 = 0;
      local_e0 = local_78 + 2;
      pfVar5 = local_78 + 1;
      do {
        if ((local_104 & 2) == 0) {
          local_14 = *(float *)(iVar1 + 0x48);
        }
        else {
          local_14 = *(float *)(iVar1 + 0x3c);
        }
        if ((local_104 & 4) == 0) {
          local_10 = *(float *)(iVar1 + 0x4c);
        }
        else {
          local_10 = *(float *)(iVar1 + 0x40);
        }
        local_14 = local_14 + *(float *)(iVar1 + 0x28);
        local_10 = local_10 + *(float *)(iVar1 + 0x2c);
        *(float *)((int)local_78 + iVar6) = *(float *)(iVar1 + 0x44) + *(float *)(iVar1 + 0x24);
        *pfVar5 = local_14;
        *local_e0 = local_10;
        uVar3 = local_104 + 1;
        if ((uVar3 & 1) == 0) {
          local_18 = *(float *)(iVar1 + 0x44);
        }
        else {
          local_18 = *(float *)(iVar1 + 0x38);
        }
        if ((uVar3 & 2) == 0) {
          local_14 = *(float *)(iVar1 + 0x48);
        }
        else {
          local_14 = *(float *)(iVar1 + 0x3c);
        }
        if ((uVar3 & 4) == 0) {
          local_10 = *(float *)(iVar1 + 0x4c);
        }
        else {
          local_10 = *(float *)(iVar1 + 0x40);
        }
        local_18 = local_18 + *(float *)(iVar1 + 0x24);
        local_14 = local_14 + *(float *)(iVar1 + 0x28);
        local_10 = local_10 + *(float *)(iVar1 + 0x2c);
        *(float *)((int)local_78 + iVar6 + 0xc) = local_18;
        pfVar5[3] = local_14;
        local_e0[3] = local_10;
        local_e0 = local_e0 + 6;
        pfVar5 = pfVar5 + 6;
        iVar6 = iVar6 + 0x18;
        local_104 = local_104 + 2;
      } while ((int)local_104 < 8);
      local_104 = 0;
      iStack_b8 = 0;
      do {
        PM_DrawRectangle(local_78 + *(int *)((int)&DAT_0015d804 + iStack_b8) * 3,
                         local_78 + *(int *)((int)&PM_boxpnt + iStack_b8) * 3,
                         local_78 + *(int *)(&DAT_0015d808 + iStack_b8) * 3,
                         local_78 + *(int *)(&DAT_0015d80c + iStack_b8) * 3,param_2,param_3);
        PM_DrawRectangle(local_78 + *(int *)((int)&DAT_0015d814 + iStack_b8) * 3,
                         local_78 + *(int *)((int)&DAT_0015d810 + iStack_b8) * 3,
                         local_78 + *(int *)((int)&DAT_0015d818 + iStack_b8) * 3,
                         local_78 + *(int *)((int)&DAT_0015d81c + iStack_b8) * 3,param_2,param_3);
        iStack_b8 = iStack_b8 + 0x20;
        local_104 = local_104 + 2;
      } while ((int)local_104 < 6);
    }
    else {
      local_c = *(float *)(iVar1 + 0x24);
      local_8 = *(float *)(iVar1 + 0x28);
      local_4 = *(float *)(iVar1 + 0x2c);
      (**(code **)((int)&__DT_REL[0x1163].r_info + pmove))
                (*(undefined4 *)(iVar1 + 0x30),&local_84,&local_90);
      local_104 = 0;
      pfVar5 = local_78 + 2;
      local_e0 = local_78 + 1;
      pfVar4 = local_78;
      do {
        if ((local_104 & 2) == 0) {
          local_14 = local_8c + 0.0;
        }
        else {
          local_14 = local_80 - 0.0;
        }
        if ((local_104 & 4) == 0) {
          local_10 = local_88 + 0.0;
        }
        else {
          local_10 = local_7c - 0.0;
        }
        *pfVar4 = local_90 + 0.0;
        *local_e0 = local_14;
        *pfVar5 = local_10;
        uVar3 = local_104 + 1;
        if ((uVar3 & 1) == 0) {
          local_18 = local_90 + 0.0;
        }
        else {
          local_18 = local_84 - 0.0;
        }
        if ((uVar3 & 2) == 0) {
          local_14 = local_8c + 0.0;
        }
        else {
          local_14 = local_80 - 0.0;
        }
        if ((uVar3 & 4) == 0) {
          local_10 = local_88 + 0.0;
        }
        else {
          local_10 = local_7c - 0.0;
        }
        pfVar4[3] = local_18;
        local_e0[3] = local_14;
        pfVar5[3] = local_10;
        pfVar5 = pfVar5 + 6;
        local_e0 = local_e0 + 6;
        pfVar4 = pfVar4 + 6;
        local_104 = local_104 + 2;
      } while ((int)local_104 < 8);
      if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x54)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x54) == 0.0) << 0xe) >> 8)) != 0x40)
          || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x58)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x58) == 0.0) << 0xe) >> 8)) != 0x40
             )) || (fVar2 = *(float *)(iVar1 + 0x5c),
                   (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
        AngleVectorsTranspose(iVar1 + 0x54,&fStack_9c,&fStack_a8,&fStack_b4);
        local_104 = 0;
        pfVar5 = local_78 + 2;
        pfVar4 = local_78 + 1;
        pfVar7 = local_78;
        do {
          local_18 = *pfVar7;
          local_14 = *pfVar4;
          local_10 = *pfVar5;
          *pfVar7 = *pfVar5 * fStack_94 + *pfVar4 * fStack_98 + *pfVar7 * fStack_9c;
          *pfVar4 = local_10 * fStack_a0 + local_14 * fStack_a4 + local_18 * fStack_a8;
          *pfVar5 = local_10 * fStack_ac + local_14 * fStack_b0 + local_18 * fStack_b4;
          local_18 = pfVar7[3];
          local_14 = pfVar4[3];
          local_10 = pfVar5[3];
          pfVar7[3] = pfVar5[3] * fStack_94 + pfVar4[3] * fStack_98 + pfVar7[3] * fStack_9c;
          pfVar4[3] = local_10 * fStack_a0 + local_14 * fStack_a4 + local_18 * fStack_a8;
          pfVar5[3] = local_10 * fStack_ac + local_14 * fStack_b0 + local_18 * fStack_b4;
          pfVar5 = pfVar5 + 6;
          pfVar4 = pfVar4 + 6;
          pfVar7 = pfVar7 + 6;
          local_104 = local_104 + 2;
        } while ((int)local_104 < 8);
      }
      local_104 = 0;
      pfVar5 = local_78 + 2;
      pfVar4 = local_78 + 1;
      pfVar7 = local_78;
      do {
        *pfVar7 = *pfVar7 + local_c;
        *pfVar4 = *pfVar4 + local_8;
        *pfVar5 = *pfVar5 + local_4;
        pfVar7[3] = pfVar7[3] + local_c;
        pfVar4[3] = pfVar4[3] + local_8;
        pfVar5[3] = pfVar5[3] + local_4;
        pfVar7[6] = pfVar7[6] + local_c;
        pfVar4[6] = pfVar4[6] + local_8;
        pfVar5[6] = pfVar5[6] + local_4;
        pfVar7[9] = pfVar7[9] + local_c;
        pfVar4[9] = pfVar4[9] + local_8;
        pfVar5[9] = pfVar5[9] + local_4;
        pfVar5 = pfVar5 + 0xc;
        pfVar4 = pfVar4 + 0xc;
        pfVar7 = pfVar7 + 0xc;
        local_104 = local_104 + 4;
      } while ((int)local_104 < 8);
      local_104 = 0;
      iStack_cc = 0;
      do {
        PM_DrawRectangle(local_78 + *(int *)((int)&DAT_0015d804 + iStack_cc) * 3,
                         local_78 + *(int *)((int)&PM_boxpnt + iStack_cc) * 3,
                         local_78 + *(int *)(&DAT_0015d808 + iStack_cc) * 3,
                         local_78 + *(int *)(&DAT_0015d80c + iStack_cc) * 3,param_2,param_3);
        PM_DrawRectangle(local_78 + *(int *)((int)&DAT_0015d814 + iStack_cc) * 3,
                         local_78 + *(int *)((int)&DAT_0015d810 + iStack_cc) * 3,
                         local_78 + *(int *)((int)&DAT_0015d818 + iStack_cc) * 3,
                         local_78 + *(int *)((int)&DAT_0015d81c + iStack_cc) * 3,param_2,param_3);
        iStack_cc = iStack_cc + 0x20;
        local_104 = local_104 + 2;
      } while ((int)local_104 < 6);
    }
  }
  return;
}


// PM_DrawRectangle  @ 0011e234
void PM_DrawRectangle(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  PM_ParticleLine(param_1,param_2,param_5,param_6,0);
  PM_ParticleLine(param_2,param_4,param_5,param_6,0);
  PM_ParticleLine(param_4,param_3,param_5,param_6,0);
  PM_ParticleLine(param_3,param_1,param_5,param_6,0);
  return;
}


// PM_DropPunchAngle  @ 00125194
void PM_DropPunchAngle(undefined4 param_1)

{
  float fVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)VectorNormalize(param_1);
  fVar1 = (float)(lVar2 - ((longdouble)10.0 + (longdouble)0.5 * lVar2) *
                          (longdouble)*(float *)(pmove + 0x10));
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    fVar1 = 0.0;
  }
  VectorScale(param_1,fVar1,param_1);
  return;
}


// PM_Duck  @ 00123650
void PM_Duck(void)

{
  float fVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 unaff_EDI;
  longdouble lVar4;
  undefined4 local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48 [17];
  float local_4;
  
  uVar2 = *(ushort *)("PrimaryAttack__6CTFRpg" + pmove + 3);
  uVar3 = *(uint *)(pmove + 200);
  if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 4U) == 0) {
    *(byte *)(pmove + 200) = *(byte *)(pmove + 200) & 0xfb;
  }
  else {
    *(byte *)(pmove + 200) = *(byte *)(pmove + 200) | 4;
  }
  if (*(int *)(pmove + 0x204) != 0) {
    return;
  }
  if (*(int *)(pmove + 0xd0) != 0) {
    return;
  }
  if ((*(byte *)(pmove + 0xb9) & 0x40) != 0) {
    *(float *)("Holster__6CTFRpgi" + pmove + 7) =
         *(float *)("Holster__6CTFRpgi" + pmove + 7) * 0.333;
    *(float *)("Holster__6CTFRpgi" + pmove + 0xb) =
         *(float *)("Holster__6CTFRpgi" + pmove + 0xb) * 0.333;
    local_4 = *(float *)("Holster__6CTFRpgi" + pmove + 0xf) * 0.333;
    *(float *)("Holster__6CTFRpgi" + pmove + 0xf) = local_4;
  }
  if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 4U) == 0) {
    if ((*(int *)(pmove + 0x90) == 0) && ((*(byte *)(pmove + 0xb9) & 0x40) == 0)) {
      return;
    }
    if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 4U) == 0) {
      local_54 = *(float *)(pmove + 0x38);
      local_50 = *(float *)(pmove + 0x3c);
      local_4c = *(float *)(pmove + 0x40);
      if (*(int *)(pmove + 0xe0) != -1) {
        local_54 = (*(float *)((int)&__DT_REL[0x1151].r_offset + pmove) -
                   *(float *)((int)&__DT_REL[0x114f].r_info + pmove)) + local_54;
        local_50 = (*(float *)((int)&__DT_REL[0x1151].r_info + pmove) -
                   *(float *)((int)&__DT_REL[0x1150].r_offset + pmove)) + local_50;
        local_4c = (*(float *)((int)&__DT_REL[0x1152].r_offset + pmove) -
                   *(float *)((int)&__DT_REL[0x1150].r_info + pmove)) + local_4c;
      }
      (**(code **)((int)&__DT_REL[0x1161].r_offset + pmove))
                (local_48,&local_54,&local_54,0,0xffffffff);
      if (local_48[0] != 0) {
        return;
      }
      *(undefined4 *)(pmove + 0xbc) = 0;
      (**(code **)((int)&__DT_REL[0x1161].r_offset + pmove))
                (local_48,&local_54,&local_54,0,0xffffffff);
      if (local_4c != 0.0) {
        *(undefined4 *)(pmove + 0xbc) = 1;
        return;
      }
      *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) & 0xbf;
      *(undefined4 *)(pmove + 0x90) = 0;
      *(undefined4 *)(pmove + 0x88) = 0x41e00000;
      *(undefined4 *)(pmove + 0x8c) = 0;
      *(undefined4 *)(pmove + 0x38) = unaff_EDI;
      *(undefined4 *)(pmove + 0x3c) = local_58;
      *(float *)(pmove + 0x40) = local_54;
      PM_CatagorizePosition();
      return;
    }
  }
  if ((((uint)uVar2 & (uVar2 ^ uVar3) & 4) != 0) && ((*(byte *)(pmove + 0xb9) & 0x40) == 0)) {
    *(undefined4 *)(pmove + 0x8c) = 0x447a0000;
    *(undefined4 *)(pmove + 0x90) = 1;
  }
  fVar1 = 1.0 - *(float *)(pmove + 0x8c) * 0.001;
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    fVar1 = 1.0 - *(float *)(pmove + 0x8c) * 0.001;
    local_4 = fVar1;
  }
  else {
    fVar1 = 0.0;
  }
  if (*(int *)(pmove + 0x90) != 0) {
    if ((*(float *)(pmove + 0x8c) * 0.001 <= 0.6) || (*(int *)(pmove + 0xe0) == -1)) {
      *(undefined4 *)(pmove + 0xbc) = 1;
      *(undefined4 *)(pmove + 0x88) = 0x41400000;
      *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) | 0x40;
      *(undefined4 *)(pmove + 0x90) = 0;
      if (*(int *)(pmove + 0xe0) != -1) {
        *(float *)(pmove + 0x38) =
             *(float *)(pmove + 0x38) -
             (*(float *)((int)&__DT_REL[0x1151].r_offset + pmove) -
             *(float *)((int)&__DT_REL[0x114f].r_info + pmove));
        *(float *)(pmove + 0x3c) =
             *(float *)(pmove + 0x3c) -
             (*(float *)((int)&__DT_REL[0x1151].r_info + pmove) -
             *(float *)((int)&__DT_REL[0x1150].r_offset + pmove));
        *(float *)(pmove + 0x40) =
             *(float *)(pmove + 0x40) -
             (*(float *)((int)&__DT_REL[0x1152].r_offset + pmove) -
             *(float *)((int)&__DT_REL[0x1150].r_info + pmove));
        PM_FixPlayerCrouchStuck(1);
        PM_CatagorizePosition();
      }
    }
    else {
      lVar4 = (longdouble)PM_SplineFraction(fVar1,0x40200000);
      *(float *)(pmove + 0x88) =
           (float)((longdouble)-6.0 * lVar4 + (longdouble)28.0 * ((longdouble)1.0 - lVar4));
    }
  }
  return;
}


// PM_FindTextureType  @ 0011fb1c
int PM_FindTextureType(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  if (pm_shared_initialized == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("pm_shared_initialized","/home/jihad/valve/goldsrc/pm_shared/pm_shared.c",0x105,
                  "PM_FindTextureType");
  }
  local_8 = 0;
  iVar3 = gcTextures + -1;
  while( true ) {
    if (iVar3 < local_8) {
      return 0x43;
    }
    iVar2 = (local_8 + iVar3) / 2;
    iVar1 = strncasecmp(param_1,(char *)((int)&grgszTextureName + iVar2 * 0xd),0xc);
    if (iVar1 == 0) break;
    if (iVar1 < 1) {
      if (iVar1 < 0) {
        iVar3 = iVar2 + -1;
      }
    }
    else {
      local_8 = iVar2 + 1;
    }
  }
  return (int)(char)(&grgchTextureType)[iVar2];
}


// PM_FixPlayerCrouchStuck  @ 0012350c
void PM_FixPlayerCrouchStuck(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (**(code **)((int)&__DT_REL[0x115c].r_info + pmove))(pmove + 0x38,0);
  if (iVar5 != -1) {
    uVar1 = *(undefined4 *)(pmove + 0x38);
    uVar2 = *(undefined4 *)(pmove + 0x3c);
    uVar3 = *(undefined4 *)(pmove + 0x40);
    iVar5 = 0;
    do {
      fVar4 = (float)param_1;
      *(float *)(pmove + 0x40) = fVar4 + *(float *)(pmove + 0x40);
      iVar6 = (**(code **)((int)&__DT_REL[0x115c].r_info + pmove))(pmove + 0x38,0);
      if (iVar6 == -1) {
        return;
      }
      *(float *)(pmove + 0x40) = fVar4 + *(float *)(pmove + 0x40);
      iVar6 = (**(code **)((int)&__DT_REL[0x115c].r_info + pmove))(pmove + 0x38,0);
      if (iVar6 == -1) {
        return;
      }
      *(float *)(pmove + 0x40) = fVar4 + *(float *)(pmove + 0x40);
      iVar6 = (**(code **)((int)&__DT_REL[0x115c].r_info + pmove))(pmove + 0x38,0);
      if (iVar6 == -1) {
        return;
      }
      iVar5 = iVar5 + 3;
    } while (iVar5 < 0x24);
    *(undefined4 *)(pmove + 0x38) = uVar1;
    *(undefined4 *)(pmove + 0x3c) = uVar2;
    *(undefined4 *)(pmove + 0x40) = uVar3;
  }
  return;
}


// PM_FixupGravityVelocity  @ 00120cc4
void PM_FixupGravityVelocity(void)

{
  float fVar1;
  float fVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = *(float *)(pmove + 0xc0);
    fVar2 = 1.0;
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar2 = fVar1;
    }
    *(float *)(pmove + 100) =
         *(float *)(pmove + 100) -
         fVar2 * **(float **)((int)&__DT_REL[0x114f].r_offset + pmove) * *(float *)(pmove + 0x10) *
         0.5;
    PM_CheckVelocity();
  }
  return;
}


// PM_FlyMove  @ 00120d50
undefined4 PM_FlyMove(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  code *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  float *pfVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  float *pfVar16;
  undefined4 auStack_148 [12];
  int aiStack_118 [2];
  float fStack_110;
  int aiStack_10c [5];
  int local_e8 [4];
  byte local_d8 [4];
  float local_d4 [3];
  int local_c8;
  float local_c4 [8];
  float local_a4 [13];
  float afStack_70 [24];
  float afStack_10 [4];
  
  puVar9 = &stack0xffffff08;
  while( true ) {
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0x5c)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(pmove + 0x5c) == 0.0) << 0xe) >> 8)) == 0x40) &&
        ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0x60)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(pmove + 0x60) == 0.0) << 0xe) >> 8)) == 0x40)) &&
       (fVar2 = *(float *)(pmove + 100), puVar11 = puVar9,
       (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40)) goto LAB_00121543;
    *(float *)(puVar9 + 0x3c) =
         *(float *)(puVar9 + 0x2c) * *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x38);
    *(float *)(puVar9 + 0x40) =
         *(float *)(puVar9 + 0x2c) * *(float *)(pmove + 0x60) + *(float *)(pmove + 0x3c);
    *(float *)(puVar9 + 0x44) =
         *(float *)(puVar9 + 0x2c) * *(float *)(pmove + 100) + *(float *)(pmove + 0x40);
    *(undefined4 *)(puVar9 + -4) = 0xffffffff;
    *(undefined4 *)(puVar9 + -8) = 0;
    *(undefined1 **)(puVar9 + -0xc) = puVar9 + 0x3c;
    *(int *)(puVar9 + -0x10) = pmove + 0x38;
    *(undefined1 **)(puVar9 + -0x14) = puVar9 + 0x48;
    pcVar5 = *(code **)((int)&__DT_REL[0x1161].r_offset + pmove);
    *(undefined4 *)(puVar9 + -0x18) = 0x120e79;
    (*pcVar5)();
    *(float *)(puVar9 + 0x24) = *(float *)(puVar9 + 0x24) + *(float *)(puVar9 + 0x54);
    if (*(int *)(puVar9 + 0x44) != 0) {
      *(undefined4 *)(pmove + 0x5c) = vec3_origin;
      *(undefined4 *)(pmove + 0x60) = DAT_0015d864;
      *(undefined4 *)(pmove + 100) = DAT_0015d868;
      return 4;
    }
    if (0.0 < *(float *)(puVar9 + 0x54)) {
      *(undefined4 *)(pmove + 0x38) = *(undefined4 *)(puVar9 + 0x58);
      *(undefined4 *)(pmove + 0x3c) = *(undefined4 *)(puVar9 + 0x5c);
      *(undefined4 *)(pmove + 0x40) = *(undefined4 *)(puVar9 + 0x60);
      *(undefined4 *)(puVar9 + 0x94) = *(undefined4 *)(pmove + 0x5c);
      *(undefined4 *)(puVar9 + 0x98) = *(undefined4 *)(pmove + 0x60);
      *(undefined4 *)(puVar9 + 0x9c) = *(undefined4 *)(pmove + 100);
      *(undefined4 *)(puVar9 + 0x2c) = 0;
    }
    fVar2 = *(float *)(puVar9 + 0x54);
    puVar11 = puVar9 + -4;
    if ((byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) == 0x40) goto LAB_00121543;
    *(int *)(puVar9 + 0x10) = pmove + 0x5c;
    *(int *)(puVar9 + -8) = pmove + 0x5c;
    puVar10 = (undefined4 *)(puVar9 + 0x44);
    puVar13 = (undefined4 *)(puVar9 + -0x4c);
    for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar13 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar13 = puVar13 + 1;
    }
    *(undefined4 *)(puVar9 + -0x50) = 0x120f87;
    PM_AddToTouched();
    puVar11 = puVar9 + -4;
    if (0.7 < *(float *)(puVar9 + 0x6c)) {
      puVar9[0x20] = puVar9[0x20] | 1;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(puVar9 + 0x6c)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(puVar9 + 0x6c) == 0.0) << 0xe) >> 8)) == 0x40) {
      puVar9[0x20] = puVar9[0x20] | 2;
    }
    *(float *)(puVar9 + 0x28) =
         *(float *)(puVar9 + 0x28) - *(float *)(puVar9 + 0x28) * *(float *)(puVar9 + 0x54);
    if (4 < *(int *)(puVar9 + 0x2c)) break;
    iVar7 = *(int *)(puVar9 + 0x2c) * 0xc;
    *(undefined4 *)(puVar9 + iVar7 + 0xac) = *(undefined4 *)(puVar9 + 100);
    *(undefined4 *)(puVar9 + iVar7 + 0xb0) = *(undefined4 *)(puVar9 + 0x68);
    *(undefined4 *)(puVar9 + iVar7 + 0xb4) = *(undefined4 *)(puVar9 + 0x6c);
    *(int *)(puVar9 + 0x2c) = *(int *)(puVar9 + 0x2c) + 1;
    if ((*(int *)(pmove + 0xdc) == 3) &&
       ((*(int *)(pmove + 0xe0) == -1 ||
        (fVar2 = *(float *)(pmove + 0xc4),
        (byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) != 0x40)))) {
      iVar7 = 0;
      if (0 < *(int *)(puVar9 + 0x2c)) {
        *(undefined1 **)(puVar9 + 0x1c) = puVar9 + 0x88;
        puVar11 = puVar9 + 0xac;
        iVar14 = 0;
        do {
          if (*(float *)(puVar9 + iVar14 + 0xb4) <= 0.7) {
            *(float *)(puVar9 + 0x34) =
                 (1.0 - *(float *)(pmove + 0xc4)) *
                 *(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x2c) + 1.0;
            *(undefined4 *)(puVar9 + -8) = *(undefined4 *)(puVar9 + 0x34);
            *(undefined4 *)(puVar9 + -0xc) = *(undefined4 *)(puVar9 + 0x1c);
            *(undefined1 **)(puVar9 + -0x10) = puVar11;
            *(undefined1 **)(puVar9 + 0x10) = puVar9 + 0x94;
            *(undefined1 **)(puVar9 + -0x14) = puVar9 + 0x94;
            *(undefined4 *)(puVar9 + -0x18) = 0x12110c;
            PM_ClipVelocity();
          }
          else {
            *(undefined4 *)(puVar9 + -8) = 0x3f800000;
            *(undefined4 *)(puVar9 + -0xc) = *(undefined4 *)(puVar9 + 0x1c);
            *(undefined1 **)(puVar9 + -0x10) = puVar11;
            *(undefined1 **)(puVar9 + 0x10) = puVar9 + 0x94;
            *(undefined1 **)(puVar9 + -0x14) = puVar9 + 0x94;
            *(undefined4 *)(puVar9 + -0x18) = 0x121092;
            PM_ClipVelocity();
            *(undefined4 *)(puVar9 + 0x94) = *(undefined4 *)(puVar9 + 0x88);
            *(undefined4 *)(puVar9 + 0x98) = *(undefined4 *)(puVar9 + 0x8c);
            *(undefined4 *)(puVar9 + 0x9c) = *(undefined4 *)(puVar9 + 0x90);
          }
          puVar11 = puVar11 + 0xc;
          iVar14 = iVar14 + 0xc;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(puVar9 + 0x2c));
      }
      *(undefined4 *)(pmove + 0x5c) = *(undefined4 *)(puVar9 + 0x88);
      *(undefined4 *)(pmove + 0x60) = *(undefined4 *)(puVar9 + 0x8c);
      *(undefined4 *)(pmove + 100) = *(undefined4 *)(puVar9 + 0x90);
      *(undefined4 *)(puVar9 + 0x94) = *(undefined4 *)(puVar9 + 0x88);
      *(undefined4 *)(puVar9 + 0x98) = *(undefined4 *)(puVar9 + 0x8c);
      *(undefined4 *)(puVar9 + 0x9c) = *(undefined4 *)(puVar9 + 0x90);
      uVar6 = FUN_00121534();
      return uVar6;
    }
    iVar7 = 0;
    if (0 < *(int *)(puVar9 + 0x2c)) {
      do {
        *(undefined4 *)(puVar9 + -8) = 0x3f800000;
        *(int *)(puVar9 + -0xc) = pmove + 0x5c;
        *(undefined1 **)(puVar9 + -0x10) = puVar9 + 0xac + iVar7 * 0xc;
        *(undefined1 **)(puVar9 + -0x14) = puVar9 + 0x94;
        *(undefined4 *)(puVar9 + -0x18) = 0x1211c1;
        PM_ClipVelocity();
        iVar14 = 0;
        if (0 < *(int *)(puVar9 + 0x2c)) {
          *(undefined1 **)(puVar9 + 0x18) = puVar9 + 0xac;
          *(undefined1 **)(puVar9 + 0x14) = puVar9 + 0xb0;
          *(undefined4 *)(puVar9 + 0xc) = 0;
          uVar15 = *(uint *)(puVar9 + 0x2c) & 3;
          if (uVar15 == 0) {
LAB_00121310:
            pfVar16 = (float *)(puVar9 + *(int *)(puVar9 + 0xc) + 0xb4);
            pfVar12 = (float *)(*(int *)(puVar9 + 0xc) + *(int *)(puVar9 + 0x14));
            *(int *)(puVar9 + 0xc) = *(int *)(puVar9 + 0xc) + *(int *)(puVar9 + 0x18);
            iVar8 = iVar14;
            do {
              if (((((iVar8 != iVar7) &&
                    (iVar14 = iVar8,
                    *(float *)(pmove + 100) * *pfVar16 +
                    *(float *)(pmove + 0x60) * *pfVar12 +
                    *(float *)(pmove + 0x5c) * **(float **)(puVar9 + 0xc) < 0.0)) ||
                   ((iVar14 = iVar8 + 1, iVar14 != iVar7 &&
                    (*(float *)(pmove + 100) * pfVar16[3] +
                     *(float *)(pmove + 0x60) * pfVar12[3] +
                     *(float *)(pmove + 0x5c) * *(float *)(*(int *)(puVar9 + 0xc) + 0xc) < 0.0))))
                  || ((iVar14 = iVar8 + 2, iVar14 != iVar7 &&
                      (*(float *)(pmove + 100) * pfVar16[6] +
                       *(float *)(pmove + 0x60) * pfVar12[6] +
                       *(float *)(pmove + 0x5c) * *(float *)(*(int *)(puVar9 + 0xc) + 0x18) < 0.0)))
                  ) || ((iVar14 = iVar8 + 3, iVar14 != iVar7 &&
                        (*(float *)(pmove + 100) * pfVar16[9] +
                         *(float *)(pmove + 0x60) * pfVar12[9] +
                         *(float *)(pmove + 0x5c) * *(float *)(*(int *)(puVar9 + 0xc) + 0x24) < 0.0)
                        ))) break;
              pfVar16 = pfVar16 + 0xc;
              pfVar12 = pfVar12 + 0xc;
              *(int *)(puVar9 + 0xc) = *(int *)(puVar9 + 0xc) + 0x30;
              iVar14 = iVar8 + 4;
              iVar8 = iVar14;
            } while (iVar14 < *(int *)(puVar9 + 0x2c));
          }
          else {
            if (1 < uVar15) {
              if (2 < uVar15) {
                if ((iVar7 != 0) &&
                   (*(float *)(pmove + 100) * *(float *)(puVar9 + 0xb4) +
                    *(float *)(pmove + 0x60) * *(float *)(puVar9 + 0xb0) +
                    *(float *)(pmove + 0x5c) * *(float *)(puVar9 + 0xac) < 0.0)) goto LAB_0012141e;
                *(int *)(puVar9 + 0xc) = *(int *)(puVar9 + 0xc) + 0xc;
                iVar14 = 1;
              }
              if ((iVar14 != iVar7) &&
                 (*(int *)(puVar9 + 0x10) = pmove,
                 *(float *)(*(int *)(puVar9 + 0x10) + 100) *
                 *(float *)(puVar9 + *(int *)(puVar9 + 0xc) + 0xb4) +
                 *(float *)(*(int *)(puVar9 + 0x10) + 0x60) *
                 *(float *)(*(int *)(puVar9 + 0x14) + *(int *)(puVar9 + 0xc)) +
                 *(float *)(pmove + 0x5c) *
                 *(float *)(*(int *)(puVar9 + 0x18) + *(int *)(puVar9 + 0xc)) < 0.0))
              goto LAB_0012141e;
              *(int *)(puVar9 + 0xc) = *(int *)(puVar9 + 0xc) + 0xc;
              iVar14 = iVar14 + 1;
            }
            if ((iVar14 == iVar7) ||
               (*(int *)(puVar9 + 0x10) = pmove,
               0.0 <= *(float *)(*(int *)(puVar9 + 0x10) + 100) *
                      *(float *)(puVar9 + *(int *)(puVar9 + 0xc) + 0xb4) +
                      *(float *)(*(int *)(puVar9 + 0x10) + 0x60) *
                      *(float *)(*(int *)(puVar9 + 0x14) + *(int *)(puVar9 + 0xc)) +
                      *(float *)(pmove + 0x5c) *
                      *(float *)(*(int *)(puVar9 + 0x18) + *(int *)(puVar9 + 0xc)))) {
              *(int *)(puVar9 + 0xc) = *(int *)(puVar9 + 0xc) + 0xc;
              iVar14 = iVar14 + 1;
              if (iVar14 < *(int *)(puVar9 + 0x2c)) goto LAB_00121310;
            }
          }
        }
LAB_0012141e:
      } while ((iVar14 != *(int *)(puVar9 + 0x2c)) &&
              (iVar7 = iVar7 + 1, iVar7 < *(int *)(puVar9 + 0x2c)));
    }
    if (iVar7 == *(int *)(puVar9 + 0x2c)) {
      if (*(int *)(puVar9 + 0x2c) != 2) break;
      *(undefined1 **)(puVar9 + -8) = puVar9 + 0xe8;
      *(undefined1 **)(puVar9 + -0xc) = puVar9 + 0xb8;
      *(undefined1 **)(puVar9 + -0x10) = puVar9 + 0xac;
      *(undefined4 *)(puVar9 + -0x14) = 0x121491;
      CrossProduct();
      fVar2 = *(float *)(pmove + 0x5c);
      fVar3 = *(float *)(pmove + 0x60);
      fVar4 = *(float *)(pmove + 100);
      *(int *)(puVar9 + -0x14) = pmove + 0x5c;
      *(float *)(puVar9 + -0x18) =
           *(float *)(puVar9 + 0xf0) * fVar4 +
           *(float *)(puVar9 + 0xec) * fVar3 + *(float *)(puVar9 + 0xe8) * fVar2;
      *(undefined1 **)(puVar9 + -0x1c) = puVar9 + 0xe8;
      *(undefined4 *)(puVar9 + -0x20) = 0x1214cb;
      VectorScale();
    }
    if (*(float *)(pmove + 100) * *(float *)(puVar9 + 0xa8) +
        *(float *)(pmove + 0x60) * *(float *)(puVar9 + 0xa4) +
        *(float *)(pmove + 0x5c) * *(float *)(puVar9 + 0xa0) <= 0.0) {
      *(undefined4 *)(pmove + 0x5c) = vec3_origin;
      *(undefined4 *)(pmove + 0x60) = DAT_0015d864;
      goto LAB_00121522;
    }
    *(int *)(puVar9 + 0x30) = *(int *)(puVar9 + 0x30) + 1;
    piVar1 = (int *)(puVar9 + 0x30);
    puVar9 = puVar9 + -4;
    if (3 < *piVar1) {
LAB_00121543:
      if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(puVar11 + 0x28)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(puVar11 + 0x28) == 0.0) << 0xe) >> 8)) == 0x40)
      {
        *(undefined4 *)(pmove + 0x5c) = vec3_origin;
        *(undefined4 *)(pmove + 0x60) = DAT_0015d864;
        *(undefined4 *)(pmove + 100) = DAT_0015d868;
      }
      return *(undefined4 *)(puVar11 + 0x24);
    }
  }
  *(undefined4 *)(pmove + 0x5c) = vec3_origin;
  *(undefined4 *)(pmove + 0x60) = DAT_0015d864;
LAB_00121522:
  *(undefined4 *)(pmove + 100) = DAT_0015d868;
  puVar11 = puVar9 + -4;
  goto LAB_00121543;
}


// PM_Friction  @ 00121cd0
void PM_Friction(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uStack_88;
  undefined1 local_6c [68];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  iVar4 = pmove;
  puVar5 = (undefined4 *)&stack0xffffff7c;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40) {
    pfVar1 = (float *)(pmove + 0x5c);
    fVar2 = SQRT(*(float *)(pmove + 100) * *(float *)(pmove + 100) +
                 *(float *)(pmove + 0x60) * *(float *)(pmove + 0x60) +
                 *(float *)(pmove + 0x5c) * *(float *)(pmove + 0x5c));
    if (0.1 <= fVar2) {
      if (*(int *)(pmove + 0xe0) != -1) {
        local_28 = (*(float *)(pmove + 0x5c) / fVar2) * 16.0 + *(float *)(pmove + 0x38);
        local_24 = (*(float *)(pmove + 0x60) / fVar2) * 16.0 + *(float *)(pmove + 0x3c);
        local_14 = *(float *)(pmove + 0x40) +
                   *(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc);
        local_20 = local_14 - 34.0;
        uStack_88 = 0xffffffff;
        local_1c = local_28;
        local_18 = local_24;
        (**(code **)((int)&__DT_REL[0x1161].r_offset + pmove))(local_6c,&local_1c,&local_28,0);
        puVar5 = &uStack_88;
      }
      fVar2 = *(float *)((int)puVar5 + 0x14) - *(float *)((int)puVar5 + 0x10);
      if (0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
        fVar2 = 0.0;
      }
      fVar2 = fVar2 / *(float *)((int)puVar5 + 0x14);
      fVar3 = fVar2 * *pfVar1;
      *(float *)((int)puVar5 + 0x78) = fVar3;
      *(float *)((int)puVar5 + 0x7c) = fVar2 * *(float *)(iVar4 + 0x60);
      *(float *)((int)puVar5 + 0x80) = fVar2 * *(float *)(iVar4 + 100);
      *(float *)(pmove + 0x5c) = fVar3;
      *(undefined4 *)(pmove + 0x60) = *(undefined4 *)((int)puVar5 + 0x7c);
      *(undefined4 *)(pmove + 100) = *(undefined4 *)((int)puVar5 + 0x80);
    }
  }
  return;
}


// PM_GetInfo  @ 00125f50
undefined4 PM_GetInfo(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (*(int *)((int)&__DT_SYMTAB[0xc1e].st_name + pmove) < param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 * 0xe0 + 0x247a8 + pmove);
  }
  return uVar1;
}


// PM_GetRandomStuckOffsets  @ 00122914
int PM_GetRandomStuckOffsets(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2 * 4 + param_1 * 8;
  iVar2 = *(int *)(rgStuckLast + iVar1);
  *(int *)(rgStuckLast + iVar1) = *(int *)(rgStuckLast + iVar1) + 1;
  iVar2 = iVar2 % 0x36;
  *param_3 = (&rgv3tStuckTable)[iVar2 * 3];
  param_3[1] = (&DAT_001b5da4)[iVar2 * 3];
  param_3[2] = (&DAT_001b5da8)[iVar2 * 3];
  return iVar2;
}


// PM_InWater  @ 00122568
bool PM_InWater(void)

{
  return 1 < *(int *)(pmove + 0xe4);
}


// PM_Init  @ 00125f94
void PM_Init(undefined4 param_1)

{
  if (pm_shared_initialized != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!pm_shared_initialized","/home/jihad/valve/goldsrc/pm_shared/pm_shared.c",0xd06,
                  "PM_Init");
  }
  pmove = param_1;
  PM_CreateStuckTable();
  PM_InitTextureTypes();
  pm_shared_initialized = 1;
  return;
}


// PM_InitTextureTypes  @ 0011f8c8
void PM_InitTextureTypes(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *local_214;
  undefined4 local_204;
  char local_200 [512];
  
  if (bTextureTypeInit_98 == 0) {
    puVar6 = &grgszTextureName;
    for (iVar4 = 0x680; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = (undefined4 *)&grgchTextureType;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    gcTextures = 0;
    pcVar7 = local_200;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7[2] = '\0';
      pcVar7[3] = '\0';
      pcVar7 = pcVar7 + 4;
    }
    uVar1 = (**(code **)((int)&__DT_REL[0x1165].r_offset + pmove))("sound/materials.txt");
    iVar4 = (**(code **)((int)&__DT_REL[0x1165].r_info + pmove))("sound/materials.txt",5,0);
    if (iVar4 != 0) {
      local_204 = 0;
LAB_0011fab3:
      do {
        do {
          do {
            do {
              do {
                iVar3 = (**(code **)((int)&__DT_REL[0x1166].r_info + pmove))
                                  (iVar4,uVar1,&local_204,local_200,0x1ff);
                if ((iVar3 == 0) || (0x1ff < gcTextures)) {
                  (**(code **)((int)&__DT_REL[0x1166].r_offset + pmove))(iVar4);
                  PM_SortTextures();
                  bTextureTypeInit_98 = 1;
                  return;
                }
              } while (local_200[0] == '\0');
              iVar3 = 0;
              do {
                iVar5 = iVar3;
                if ((*(byte *)(__ctype_b + 1 + local_200[iVar3] * 2) & 0x20) == 0) break;
                iVar5 = iVar3 + 1;
                iVar2 = iVar3 + 1;
                iVar3 = iVar5;
              } while (local_200[iVar2] != '\0');
            } while (((local_200[iVar5] == '\0') || (local_200[iVar5] == '/')) ||
                    ((*(byte *)(__ctype_b + 1 + local_200[iVar5] * 2) & 4) == 0));
            (&grgchTextureType)[gcTextures] =
                 *(undefined1 *)(__ctype_toupper + local_200[iVar5] * 4);
            iVar3 = iVar5 + 1;
          } while (local_200[iVar5 + 1] == '\0');
          do {
            iVar5 = iVar3;
            if ((*(byte *)(__ctype_b + 1 + local_200[iVar3] * 2) & 0x20) == 0) break;
            iVar5 = iVar3 + 1;
            iVar2 = iVar3 + 1;
            iVar3 = iVar5;
          } while (local_200[iVar2] != '\0');
        } while (local_200[iVar5] == '\0');
        iVar3 = iVar5;
        if ((*(byte *)(__ctype_b + 1 + local_200[iVar5] * 2) & 0x20) == 0) {
          local_214 = local_200 + iVar5;
          do {
            local_214 = local_214 + 1;
            iVar3 = iVar3 + 1;
            if (*local_214 == '\0') goto LAB_0011fab3;
          } while ((*(byte *)(__ctype_b + 1 + *local_214 * 2) & 0x20) == 0);
        }
        if (local_200[iVar3] != '\0') {
          iVar2 = iVar5 + 0xc;
          if (iVar3 < iVar5 + 0xc) {
            iVar2 = iVar3;
          }
          local_200[iVar2] = '\0';
          iVar3 = gcTextures * 0xd;
          gcTextures = gcTextures + 1;
          strcpy((char *)((int)&grgszTextureName + iVar3),local_200 + iVar5);
        }
      } while( true );
    }
  }
  return;
}


// PM_Jump  @ 001246dc
void PM_Jump(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  longdouble lVar5;
  
  if (*(int *)(pmove + 0xd0) == 0) {
    uVar2 = (**(code **)((int)&__DT_REL[0x115b].r_info + pmove))(pmove + 0x4f3f0,&UNK_001456d0);
    iVar3 = __strtol_internal(uVar2,0,10,0);
    if ((iVar3 == 1) && (*(int *)(pmove + 0xd4) == 5)) {
      return;
    }
    fVar1 = *(float *)(pmove + 0xcc);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(float *)(pmove + 0xcc) =
           *(float *)(pmove + 0xcc) - (float)(byte)"CanHolster__6CTFRpg"[pmove + 0xd];
      fVar1 = *(float *)(pmove + 0xcc);
      if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
      *(undefined4 *)(pmove + 0xcc) = 0;
      return;
    }
    if (1 < *(int *)(pmove + 0xe4)) {
      *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
      if (*(int *)(pmove + 0xe8) == -3) {
        *(undefined4 *)(pmove + 100) = 0x42c80000;
        FUN_0012481f();
        return;
      }
      if (*(int *)(pmove + 0xe8) == -4) {
        *(undefined4 *)(pmove + 100) = 0x42a00000;
      }
      else {
        *(undefined4 *)(pmove + 100) = 0x42480000;
      }
      fVar1 = *(float *)(pmove + 0xac);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        return;
      }
      *(undefined4 *)(pmove + 0xac) = 0x447a0000;
      uVar2 = (**(code **)((int)&__DT_REL[0x1162].r_offset + pmove))(0,3);
      switch(uVar2) {
      case 0:
        pcVar4 = "player/pl_wade1.wav";
        break;
      case 1:
        pcVar4 = "player/pl_wade2.wav";
        break;
      case 2:
        pcVar4 = "player/pl_wade3.wav";
        break;
      case 3:
        pcVar4 = "player/pl_wade4.wav";
        break;
      default:
        return;
      }
      (**(code **)((int)&__DT_REL[0x1167].r_info + pmove))(4,pcVar4,0x3f800000,0x3f4ccccd,0,100);
      return;
    }
    if (*(int *)(pmove + 0xe0) != -1) {
      if ((*(byte *)(pmove + 200) & 2) != 0) {
        return;
      }
      *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
      if (iVar3 != 1) {
        uVar2 = PM_MapTextureTypeStepType((int)*(char *)(pmove + 0x1f0),0x3f800000);
        PM_PlayStepSound(uVar2);
      }
      else {
        (**(code **)((int)&__DT_REL[0x1167].r_info + pmove))
                  (4,"player/plyrjmp8.wav",0x3f000000,0x3f4ccccd,0,100);
      }
      uVar2 = (**(code **)((int)&__DT_REL[0x115b].r_info + pmove))(pmove + 0x4f3f0,&UNK_001456e8);
      iVar3 = __strtol_internal(uVar2,0,10,0);
      if ((((*(int *)(pmove + 0x90) == 0) && ((*(byte *)(pmove + 0xb9) & 0x40) == 0)) ||
          (iVar3 != 1)) ||
         (((("PrimaryAttack__6CTFRpg"[pmove + 3] & 4U) == 0 || (*(float *)(pmove + 0x8c) <= 0.0)) ||
          (lVar5 = (longdouble)Length(pmove + 0x5c), lVar5 <= (longdouble)50.0)))) {
        fVar1 = 72000.0;
      }
      else {
        *(undefined4 *)(pmove + 0xa0) = 0xc0a00000;
        *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x14) * 350.0 * 1.6;
        *(float *)(pmove + 0x60) = *(float *)(pmove + 0x18) * 350.0 * 1.6;
        fVar1 = 89600.0;
      }
      *(float *)(pmove + 100) = SQRT(fVar1);
      PM_FixupGravityVelocity();
      *(byte *)(pmove + 200) = *(byte *)(pmove + 200) | 2;
      return;
    }
  }
  *(byte *)(pmove + 200) = *(byte *)(pmove + 200) | 2;
  return;
}


// PM_Ladder  @ 00123e98
int PM_Ladder(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_14;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = 0;
  if (0 < *(int *)(&__DT_SYMTAB[0x89d].st_info + pmove)) {
    local_14 = 0x20f54;
    do {
      iVar3 = local_14 + pmove;
      if (((*(int *)(iVar3 + 0x30) != 0) &&
          (iVar1 = (**(code **)((int)&__DT_REL[0x1163].r_offset + pmove))
                             (*(undefined4 *)(iVar3 + 0x30)), iVar1 == 0)) &&
         (*(int *)(iVar3 + 100) == -0x10)) {
        iVar1 = (**(code **)((int)&__DT_REL[0x1164].r_offset + pmove))(iVar3,&local_c);
        local_c = *(float *)(pmove + 0x38) - local_c;
        local_8 = *(float *)(pmove + 0x3c) - local_8;
        local_4 = *(float *)(pmove + 0x40) - local_4;
        iVar1 = (**(code **)((int)&__DT_REL[0x1160].r_info + pmove))
                          (iVar1,*(undefined4 *)(iVar1 + 8),&local_c);
        if (iVar1 != -1) {
          return iVar3;
        }
      }
      local_14 = local_14 + 0xe0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(&__DT_SYMTAB[0x89d].st_info + pmove));
  }
  return 0;
}


// PM_LadderMove  @ 00123a74
void PM_LadderMove(int param_1)

{
  float fVar1;
  int iVar2;
  float local_c8;
  float local_c4;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  undefined1 local_98 [12];
  float local_8c;
  float local_88;
  float local_84;
  undefined1 local_80 [12];
  undefined1 local_74 [12];
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined1 local_44 [16];
  float local_34;
  float local_24;
  float local_20;
  float local_1c;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(pmove + 0xdc) != 8) {
    (**(code **)((int)&__DT_REL[0x1163].r_info + pmove))
              (*(undefined4 *)(param_1 + 0x30),&local_5c,&local_68);
    local_c = local_5c + local_68;
    local_8 = local_58 + local_64;
    local_4 = local_54 + local_60;
    VectorScale(&local_c,0x3f000000,&local_c);
    *(undefined4 *)(pmove + 0xdc) = 5;
    local_50 = *(undefined4 *)(pmove + 0x38);
    local_4c = *(undefined4 *)(pmove + 0x3c);
    local_48 = (*(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc) - 1.0) +
               *(float *)(pmove + 0x40);
    iVar2 = (**(code **)((int)&__DT_REL[0x115f].r_info + pmove))(&local_50,0);
    *(undefined4 *)(pmove + 0xc0) = 0;
    (**(code **)((int)&__DT_REL[0x1164].r_info + pmove))(param_1,pmove + 0x38,&local_c,local_44);
    if ((byte)(1.0 < local_34 | (byte)((ushort)((ushort)NAN(local_34) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_34 == 1.0) << 0xe) >> 8)) != 0x40) {
      local_c4 = 0.0;
      local_c8 = 0.0;
      AngleVectors(pmove + 0x44,local_74,local_80,0);
      if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 0x10U) != 0) {
        local_c4 = -200.0;
      }
      if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 8U) != 0) {
        local_c4 = local_c4 + 200.0;
      }
      if (("PrimaryAttack__6CTFRpg"[pmove + 4] & 2U) != 0) {
        local_c8 = -200.0;
      }
      if (("PrimaryAttack__6CTFRpg"[pmove + 4] & 4U) != 0) {
        local_c8 = local_c8 + 200.0;
      }
      if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 2U) == 0) {
        if (((byte)((byte)((ushort)((ushort)NAN(local_c4) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_c4 == 0.0) << 0xe) >> 8)) == 0x40) &&
           ((byte)(local_c8 < 0.0 | (byte)((ushort)((ushort)NAN(local_c8) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_c8 == 0.0) << 0xe) >> 8)) == 0x40)) {
          *(undefined4 *)(pmove + 0x5c) = 0;
          *(undefined4 *)(pmove + 0x60) = 0;
          *(undefined4 *)(pmove + 100) = 0;
        }
        else {
          VectorScale(local_74,local_c4,&local_8c);
          VectorMA(&local_8c,local_c8,local_80,&local_8c);
          local_bc = 0;
          local_b8 = 0;
          local_b4 = 0x3f800000;
          CrossProduct(&local_bc,&local_24,local_98);
          VectorNormalize(local_98);
          fVar1 = local_84 * local_1c + local_88 * local_20 + local_8c * local_24;
          VectorScale(&local_24,fVar1,&local_a4);
          local_b0 = local_8c - local_a4;
          local_ac = local_88 - local_a0;
          local_a8 = local_84 - local_9c;
          CrossProduct(&local_24,local_98,&local_bc);
          VectorMA(&local_b0,-fVar1,&local_bc,pmove + 0x5c);
          if ((iVar2 == -2) && (0.0 < fVar1)) {
            VectorMA(pmove + 0x5c,0x43480000,&local_24,pmove + 0x5c);
          }
        }
      }
      else {
        *(undefined4 *)(pmove + 0xdc) = 3;
        VectorScale(&local_24,0x43870000,pmove + 0x5c);
      }
    }
  }
  return;
}


// PM_MapTextureTypeStepType  @ 00120338
undefined4 PM_MapTextureTypeStepType(undefined1 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  default:
    uVar1 = 0;
    break;
  case 0x44:
    uVar1 = 2;
    break;
  case 0x47:
    uVar1 = 4;
    break;
  case 0x4d:
    uVar1 = 1;
    break;
  case 0x53:
    uVar1 = 6;
    break;
  case 0x54:
    uVar1 = 5;
    break;
  case 0x56:
    uVar1 = 3;
  }
  return uVar1;
}


// PM_Move  @ 00125ea8
void PM_Move(int param_1,int param_2)

{
  if (pm_shared_initialized == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("pm_shared_initialized","/home/jihad/valve/goldsrc/pm_shared/pm_shared.c",0xce5,
                  "PM_Move");
  }
  pmove = param_1;
  PM_PlayerMove(param_2 != 0);
  if (*(int *)(pmove + 0xe0) == -1) {
    *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) & 0xfd;
  }
  else {
    *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) | 2;
  }
  if ((*(int *)(pmove + 8) == 0) && (*(int *)(pmove + 0xdc) == 3)) {
    *(undefined4 *)(pmove + 0xc4) = 0x3f800000;
  }
  return;
}


// PM_NoClip  @ 001245d8
void PM_NoClip(void)

{
  float fVar1;
  float fVar2;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = *(float *)("Holster__6CTFRpgi" + pmove + 7);
  fVar2 = *(float *)("Holster__6CTFRpgi" + pmove + 0xb);
  VectorNormalize(pmove + 0x14);
  VectorNormalize(pmove + 0x20);
  local_c = fVar2 * *(float *)(pmove + 0x20) + fVar1 * *(float *)(pmove + 0x14);
  local_8 = fVar2 * *(float *)(pmove + 0x24) + fVar1 * *(float *)(pmove + 0x18);
  local_4 = fVar1 * *(float *)(pmove + 0x1c) + fVar2 * *(float *)(pmove + 0x28) +
            *(float *)("Holster__6CTFRpgi" + pmove + 0xf);
  VectorMA(pmove + 0x38,*(undefined4 *)(pmove + 0x10),&local_c,pmove + 0x38);
  *(undefined4 *)(pmove + 0x5c) = 0;
  *(undefined4 *)(pmove + 0x60) = 0;
  *(undefined4 *)(pmove + 100) = 0;
  return;
}


// PM_ParticleLine  @ 0011e128
void PM_ParticleLine(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4,
                    float param_5)

{
  float fVar1;
  longdouble lVar2;
  float local_28;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_18 = *param_2 - *param_1;
  local_14 = param_2[1] - param_1[1];
  local_10 = param_2[2] - param_1[2];
  lVar2 = (longdouble)VectorNormalize(&local_18);
  fVar1 = (float)lVar2;
  local_28 = 0.0;
  if (0.0 <= fVar1) {
    do {
      local_c = local_28 * local_18 + *param_1;
      local_8 = local_28 * local_14 + param_1[1];
      local_4 = local_28 * local_10 + param_1[2];
      (**(code **)((int)&__DT_REL[0x115c].r_offset + pmove))
                (&local_c,param_3,param_4,0,(int)ROUND(param_5));
      local_28 = local_28 + 2.0;
    } while ((byte)((local_28 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(local_28) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_28 == fVar1) << 0xe) >> 8)) - 1) < 0x40);
  }
  return;
}


// PM_Physics_Toss  @ 00124218
void PM_Physics_Toss(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 **ppuVar4;
  undefined4 **ppuVar5;
  undefined1 *local_74;
  undefined4 *puStack_70;
  undefined1 local_54 [4];
  undefined1 local_50 [8];
  int local_48;
  undefined1 local_44 [12];
  float local_38;
  undefined1 local_28 [8];
  float local_20;
  undefined4 local_18;
  
  puStack_70 = (undefined4 *)0x12422e;
  PM_CheckWater();
  if (0.0 < *(float *)(pmove + 100)) {
    *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
  }
  if (*(int *)(pmove + 0xe0) != -1) {
    puStack_70 = &vec3_origin;
    local_74 = (undefined1 *)(pmove + 0x74);
    iVar3 = VectorCompare();
    if (iVar3 != 0) {
      puStack_70 = &vec3_origin;
      local_74 = (undefined1 *)(pmove + 0x5c);
      iVar3 = VectorCompare();
      if (iVar3 != 0) {
        return;
      }
    }
  }
  puStack_70 = (undefined4 *)0x1242a2;
  PM_CheckVelocity();
  if (((*(int *)(pmove + 0xdc) != 5) && (*(int *)(pmove + 0xdc) != 0xb)) &&
     (*(int *)(pmove + 0xdc) != 9)) {
    puStack_70 = (undefined4 *)0x1242ca;
    PM_AddGravity();
  }
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) + *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) + *(float *)(pmove + 0x7c);
  puStack_70 = (undefined4 *)0x124302;
  PM_CheckVelocity();
  local_74 = *(undefined1 **)(pmove + 0x10);
  puStack_70 = (undefined4 *)local_50;
  VectorScale(pmove + 0x5c);
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) - *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) - *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) - *(float *)(pmove + 0x7c);
  PM_PushEntity(local_44,local_50);
  PM_CheckVelocity();
  if (local_48 == 0) {
    ppuVar5 = &puStack_70;
    if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
      if (*(int *)(pmove + 0xdc) == 10) {
        local_74 = (undefined1 *)(2.0 - *(float *)(pmove + 0xc4));
      }
      else {
        local_74 = (undefined1 *)0x3f800000;
        if (*(int *)(pmove + 0xdc) == 0xb) {
          local_74 = (undefined1 *)0x40000000;
        }
      }
      PM_ClipVelocity(pmove + 0x5c,local_28,pmove + 0x5c);
      ppuVar4 = &puStack_70;
      ppuVar5 = &puStack_70;
      if (0.7 < local_20) {
        fVar2 = **(float **)((int)&__DT_REL[0x114f].r_offset + pmove) * *(float *)(pmove + 0x10);
        fVar1 = *(float *)(pmove + 100);
        if (0x3f < (byte)((fVar2 < fVar1 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
          *(undefined4 *)(pmove + 0xe0) = local_18;
          *(undefined4 *)(pmove + 100) = 0;
        }
        if ((*(float *)(pmove + 100) * *(float *)(pmove + 100) +
             *(float *)(pmove + 0x60) * *(float *)(pmove + 0x60) +
             *(float *)(pmove + 0x5c) * *(float *)(pmove + 0x5c) < 900.0) ||
           (1 < *(int *)(pmove + 0xdc) - 10U)) {
          *(undefined4 *)(pmove + 0xe0) = local_18;
          *(undefined4 *)(pmove + 0x5c) = vec3_origin;
          *(undefined4 *)(pmove + 0x60) = DAT_0015d864;
          *(undefined4 *)(pmove + 100) = DAT_0015d868;
        }
        else {
          local_74 = local_54;
          VectorScale(pmove + 0x5c,(1.0 - local_38) * *(float *)(pmove + 0x10) * 0.9);
          PM_PushEntity(&local_48,local_54);
          ppuVar4 = (undefined4 **)&local_74;
        }
        *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) - *(float *)((int)ppuVar4 + 0xc);
        *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) - *(float *)((int)ppuVar4 + 0x10);
        *(float *)(pmove + 100) = *(float *)(pmove + 100) - *(float *)((int)ppuVar4 + 0x14);
        ppuVar5 = ppuVar4;
      }
    }
    *(undefined4 *)((int)ppuVar5 + -4) = 0x1245d0;
    PM_CheckWater();
  }
  else {
    *(undefined4 *)(pmove + 0xe0) = local_18;
    *(undefined4 *)(pmove + 0x5c) = vec3_origin;
    *(undefined4 *)(pmove + 0x60) = DAT_0015d864;
    *(undefined4 *)(pmove + 100) = DAT_0015d868;
  }
  return;
}


// PM_PlayStepSound  @ 0011fbd0
void PM_PlayStepSound(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  longdouble lVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(uint *)(pmove + 0x98) = (uint)(*(int *)(pmove + 0x98) == 0);
  if (*(int *)((int)&__DT_REL[0x1167].r_offset + pmove) != 0) {
    iVar1 = (**(code **)((int)&__DT_REL[0x1162].r_offset + pmove))(0,1);
    iVar1 = iVar1 + *(int *)(pmove + 0x98) * 2;
    if ((*(int *)(pmove + 8) == 0) ||
       (*(int *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x40) != 0)) {
      local_c = *(undefined4 *)(pmove + 0x5c);
      local_8 = *(undefined4 *)(pmove + 0x60);
      local_4 = 0;
      if ((*(int *)(pmove + 8) == 0) ||
         ((g_onladder != 0 || (lVar4 = (longdouble)Length(&local_c), (longdouble)220.0 < lVar4)))) {
        switch(param_1) {
        default:
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_step1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_step3.wav";
            break;
          case 2:
            pcVar3 = "player/pl_step2.wav";
            break;
          case 3:
            pcVar3 = "player/pl_step4.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
          break;
        case 1:
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_metal1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_metal3.wav";
            break;
          case 2:
            pcVar3 = "player/pl_metal2.wav";
            break;
          case 3:
            pcVar3 = "player/pl_metal4.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
          break;
        case 2:
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_dirt1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_dirt3.wav";
            break;
          case 2:
            pcVar3 = "player/pl_dirt2.wav";
            break;
          case 3:
            pcVar3 = "player/pl_dirt4.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
          break;
        case 3:
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_duct1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_duct3.wav";
            break;
          case 2:
            pcVar3 = "player/pl_duct2.wav";
            break;
          case 3:
            pcVar3 = "player/pl_duct4.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
          break;
        case 4:
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_grate1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_grate3.wav";
            break;
          case 2:
            pcVar3 = "player/pl_grate2.wav";
            break;
          case 3:
            pcVar3 = "player/pl_grate4.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
          break;
        case 5:
          iVar2 = (**(code **)((int)&__DT_REL[0x1162].r_offset + pmove))(0,4);
          if (iVar2 == 0) {
            iVar1 = 4;
          }
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_tile1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_tile3.wav";
            break;
          case 2:
            pcVar3 = "player/pl_tile2.wav";
            break;
          case 3:
            pcVar3 = "player/pl_tile4.wav";
            break;
          case 4:
            pcVar3 = "player/pl_tile5.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
          break;
        case 6:
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_slosh1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_slosh3.wav";
            break;
          case 2:
            pcVar3 = "player/pl_slosh2.wav";
            break;
          case 3:
            pcVar3 = "player/pl_slosh4.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
          break;
        case 7:
          if (iSkipStep_103 == 0) {
            iSkipStep_103 = 1;
            return;
          }
          iSkipStep_103 = iSkipStep_103 + 1;
          if (iSkipStep_103 == 4) {
            iSkipStep_103 = 0;
          }
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_wade1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_wade2.wav";
            break;
          case 2:
            pcVar3 = "player/pl_wade3.wav";
            break;
          case 3:
            pcVar3 = "player/pl_wade4.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
          break;
        case 8:
          switch(iVar1) {
          case 0:
            pcVar3 = "player/pl_ladder1.wav";
            break;
          case 1:
            pcVar3 = "player/pl_ladder3.wav";
            break;
          case 2:
            pcVar3 = "player/pl_ladder2.wav";
            break;
          case 3:
            pcVar3 = "player/pl_ladder4.wav";
            break;
          default:
            goto switchD_0011fcfe_default;
          }
        }
        (**(code **)((int)&__DT_REL[0x1167].r_info + pmove))(4,pcVar3,param_2,0x3f4ccccd,0,100);
      }
    }
  }
switchD_0011fcfe_default:
  return;
}


// PM_PlayWaterSounds  @ 00124fdc
void PM_PlayWaterSounds(void)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (((*(int *)(pmove + 0xec) == 0) && (*(int *)(pmove + 0xe4) != 0)) ||
     ((*(int *)(pmove + 0xec) != 0 && (*(int *)(pmove + 0xe4) == 0)))) {
    uVar1 = (**(code **)((int)&__DT_REL[0x1162].r_offset + pmove))(0,3);
    switch(uVar1) {
    case 0:
      pcVar2 = "player/pl_wade1.wav";
      break;
    case 1:
      pcVar2 = "player/pl_wade2.wav";
      break;
    case 2:
      pcVar2 = "player/pl_wade3.wav";
      break;
    case 3:
      pcVar2 = "player/pl_wade4.wav";
      break;
    default:
      goto switchD_0012504e_default;
    }
    (**(code **)((int)&__DT_REL[0x1167].r_info + pmove))(4,pcVar2,0x3f800000,0x3f4ccccd,0,100);
  }
switchD_0012504e_default:
  return;
}


// PM_PlayerMove  @ 001255c0
void PM_PlayerMove(undefined4 param_1)

{
  char *pcVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  *(undefined4 *)(pmove + 4) = param_1;
  PM_CheckParamters();
  pcVar1 = "SecondaryAttack__6CTFRpg" + pmove + 2;
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  *(float *)(pmove + 0x10) = (float)(byte)"CanHolster__6CTFRpg"[pmove + 0xd] * 0.001;
  PM_ReduceTimers();
  AngleVectors(pmove + 0x44,pmove + 0x14,pmove + 0x20,pmove + 0x2c);
  if ((*(int *)(pmove + 0xd8) == 0) && (*(int *)(pmove + 0x1fc) < 1)) {
    if (((*(int *)(pmove + 0xdc) == 8) || (*(int *)(pmove + 0xdc) == 0)) ||
       (iVar3 = PM_CheckStuck(), iVar3 == 0)) {
      PM_CatagorizePosition();
      *(undefined4 *)(pmove + 0xec) = *(undefined4 *)(pmove + 0xe4);
      if (*(int *)(pmove + 0xe0) == -1) {
        *(float *)(pmove + 0x9c) = -*(float *)(pmove + 100);
      }
      g_onladder = 0;
      if (((*(int *)(pmove + 0xd0) == 0) && ((*(byte *)(pmove + 0xbb) & 1) == 0)) &&
         (iVar4 = PM_Ladder(), iVar4 != 0)) {
        g_onladder = 1;
      }
      PM_UpdateStepSound();
      PM_Duck();
      if ((*(int *)(pmove + 0xd0) == 0) && ((*(byte *)(pmove + 0xbb) & 1) == 0)) {
        if (iVar4 == 0) {
          if ((*(int *)(pmove + 0xdc) != 3) && (*(int *)(pmove + 0xdc) != 8)) {
            *(undefined4 *)(pmove + 0xdc) = 3;
          }
        }
        else {
          PM_LadderMove(iVar4);
        }
      }
      if ((*(int *)(pmove + 0xe0) != -1) && (("PrimaryAttack__6CTFRpg"[pmove + 3] & 0x20U) != 0)) {
        VectorScale(pmove + 0x5c,0x3e99999a,pmove + 0x5c);
      }
      switch(*(undefined4 *)(pmove + 0xdc)) {
      case 0:
        break;
      default:
        (**(code **)((int)&__DT_REL[0x115d].r_info + pmove))
                  ("Bogus pmove player movetype %i on (%i) 0=cl 1=sv\n",
                   *(undefined4 *)(pmove + 0xdc),*(undefined4 *)(pmove + 4));
        break;
      case 3:
        iVar3 = PM_InWater();
        if (iVar3 == 0) {
          func_0x0007e7d4();
        }
        fVar2 = *(float *)(pmove + 0xcc);
        if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
          if (*(int *)(pmove + 0xe4) < 2) {
            if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 2U) == 0) {
              *(byte *)(pmove + 200) = *(byte *)(pmove + 200) & 0xfd;
            }
            else if (iVar4 == 0) {
              PM_Jump();
            }
            if (*(int *)(pmove + 0xe0) != -1) {
              *(undefined4 *)(pmove + 100) = 0;
              func_0x0007b244();
            }
            PM_CheckVelocity();
            if (*(int *)(pmove + 0xe0) == -1) {
              func_0x0007d6d4();
            }
            else {
              func_0x0007b8b4();
            }
            PM_CatagorizePosition();
            *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) - *(float *)(pmove + 0x74);
            *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) - *(float *)(pmove + 0x78);
            *(float *)(pmove + 100) = *(float *)(pmove + 100) - *(float *)(pmove + 0x7c);
            PM_CheckVelocity();
            iVar4 = PM_InWater();
            if (iVar4 == 0) {
              PM_FixupGravityVelocity();
            }
            if (*(int *)(pmove + 0xe0) != -1) {
              *(undefined4 *)(pmove + 100) = 0;
            }
            PM_CheckFalling();
          }
          else {
            if (*(int *)(pmove + 0xe4) == 2) {
              func_0x0007cd34();
            }
            fVar2 = *(float *)(pmove + 100);
            if ((0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                               (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) &&
               (fVar2 = *(float *)(pmove + 0xcc),
               (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
              *(undefined4 *)(pmove + 0xcc) = 0;
            }
            if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 2U) == 0) {
              *(byte *)(pmove + 200) = *(byte *)(pmove + 200) & 0xfd;
            }
            else {
              PM_Jump();
            }
            PM_WaterMove();
            *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) - *(float *)(pmove + 0x74);
            *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) - *(float *)(pmove + 0x78);
            *(float *)(pmove + 100) = *(float *)(pmove + 100) - *(float *)(pmove + 0x7c);
            PM_CatagorizePosition();
          }
          PM_PlayWaterSounds();
        }
        else {
          func_0x0007bdc4();
          PM_FlyMove();
          PM_CheckWater();
        }
        break;
      case 5:
        PM_CheckWater();
        if (("PrimaryAttack__6CTFRpg"[pmove + 3] & 2U) == 0) {
          *(byte *)(pmove + 200) = *(byte *)(pmove + 200) & 0xfd;
        }
        else if (iVar4 == 0) {
          PM_Jump();
        }
        *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x74);
        *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) + *(float *)(pmove + 0x78);
        *(float *)(pmove + 100) = *(float *)(pmove + 100) + *(float *)(pmove + 0x7c);
        PM_FlyMove();
        *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) - *(float *)(pmove + 0x74);
        *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) - *(float *)(pmove + 0x78);
        *(float *)(pmove + 100) = *(float *)(pmove + 100) - *(float *)(pmove + 0x7c);
        break;
      case 6:
      case 10:
        func_0x0007ca54();
        break;
      case 8:
        func_0x0007cf74();
      }
    }
  }
  else {
    PM_SpectatorMove();
    PM_CatagorizePosition();
  }
  return;
}


// PM_PushEntity  @ 001240f0
float * PM_PushEntity(float *param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float afStack_bc [13];
  undefined4 uStack_88;
  float *pfStack_84;
  int iStack_80;
  float *pfStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  float local_50;
  float local_4c;
  float local_48 [5];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_50 = *(float *)(pmove + 0x38) + *param_2;
  local_4c = *(float *)(pmove + 0x3c) + param_2[1];
  local_48[0] = *(float *)(pmove + 0x40) + param_2[2];
  uStack_74 = 0xffffffff;
  iStack_78 = 0;
  pfStack_7c = &local_50;
  iStack_80 = pmove + 0x38;
  uStack_88 = 0x12417c;
  pfStack_84 = local_48 + 1;
  (**(code **)((int)&__DT_REL[0x1161].r_offset + pmove))();
  *(undefined4 *)(pmove + 0x38) = local_34;
  *(undefined4 *)(pmove + 0x3c) = local_30;
  *(undefined4 *)(pmove + 0x40) = local_2c;
  if ((0x3f < (byte)((1.0 < local_48[4] | (byte)((ushort)((ushort)NAN(local_48[4]) << 10) >> 8) |
                     (byte)((ushort)((ushort)(local_48[4] == 1.0) << 0xe) >> 8)) - 1)) &&
     (local_48[0] == 0.0)) {
    iStack_78 = pmove + 0x5c;
    pfVar2 = local_48 + 1;
    pfVar3 = afStack_bc;
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar3 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      pfVar3 = pfVar3 + 1;
    }
    PM_AddToTouched();
  }
  pfVar2 = local_48;
  pfVar3 = param_1;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  return param_1;
}


// PM_ReduceTimers  @ 001254b4
void PM_ReduceTimers(void)

{
  float fVar1;
  
  if ((0 < *(int *)(pmove + 0x94)) &&
     (*(int *)(pmove + 0x94) =
           *(int *)(pmove + 0x94) - (uint)(byte)"CanHolster__6CTFRpg"[pmove + 0xd],
     *(int *)(pmove + 0x94) < 0)) {
    *(undefined4 *)(pmove + 0x94) = 0;
  }
  if (0.0 < *(float *)(pmove + 0x8c)) {
    *(float *)(pmove + 0x8c) =
         *(float *)(pmove + 0x8c) - (float)(byte)"CanHolster__6CTFRpg"[pmove + 0xd];
    fVar1 = *(float *)(pmove + 0x8c);
    if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
      *(undefined4 *)(pmove + 0x8c) = 0;
    }
  }
  if (0.0 < *(float *)(pmove + 0xac)) {
    *(float *)(pmove + 0xac) =
         *(float *)(pmove + 0xac) - (float)(byte)"CanHolster__6CTFRpg"[pmove + 0xd];
    fVar1 = *(float *)(pmove + 0xac);
    if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
      *(undefined4 *)(pmove + 0xac) = 0;
    }
  }
  return;
}


// PM_ResetStuckOffsets  @ 001229b0
void PM_ResetStuckOffsets(int param_1,int param_2)

{
  *(undefined4 *)(rgStuckLast + param_2 * 4 + param_1 * 8) = 0;
  return;
}


// PM_ShowClipBox  @ 0011e124
void PM_ShowClipBox(void)

{
  return;
}


// PM_SortTextures  @ 0011f83c
void PM_SortTextures(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  iVar2 = 0;
  if (0 < gcTextures) {
    local_8 = 0;
    do {
      iVar3 = iVar2 + 1;
      if (iVar3 < gcTextures) {
        iVar4 = iVar3 * 0xd;
        do {
          iVar1 = strcasecmp((char *)((int)&grgszTextureName + local_8),
                             (char *)((int)&grgszTextureName + iVar4));
          if (0 < iVar1) {
            PM_SwapTextures(iVar2,iVar3);
          }
          iVar4 = iVar4 + 0xd;
          iVar3 = iVar3 + 1;
        } while (iVar3 < gcTextures);
      }
      local_8 = local_8 + 0xd;
      iVar2 = iVar2 + 1;
    } while (iVar2 < gcTextures);
  }
  return;
}


// PM_SpectatorMove  @ 00123058
void PM_SpectatorMove(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float local_c;
  float fStack_8;
  float fStack_4;
  
  if (*(int *)(pmove + 0x200) == 0) {
    lVar5 = (longdouble)Length(pmove + 0x5c);
    lVar6 = (longdouble)1.0;
    if ((byte)((lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
      iVar4 = *(int *)((int)&__DT_REL[0x114f].r_offset + pmove);
      lVar6 = lVar5;
      if (lVar5 < (longdouble)*(float *)(iVar4 + 4)) {
        lVar6 = (longdouble)*(float *)(iVar4 + 4);
      }
      lVar6 = lVar5 - (lVar6 * (longdouble)
                               (*(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x1c)
                               * 1.5) * (longdouble)*(float *)(pmove + 0x10) + (longdouble)0.0);
      lVar7 = (longdouble)0.0;
      if (0x3f < (byte)((lVar7 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar6 = lVar7;
      }
      VectorScale(pmove + 0x5c,(float)(lVar6 / lVar5),pmove + 0x5c);
    }
    else {
      *(undefined4 *)(pmove + 0x5c) = vec3_origin;
      *(undefined4 *)(pmove + 0x60) = DAT_0015d864;
      *(undefined4 *)(pmove + 100) = DAT_0015d868;
    }
    fVar1 = *(float *)("Holster__6CTFRpgi" + pmove + 7);
    fVar2 = *(float *)("Holster__6CTFRpgi" + pmove + 0xb);
    VectorNormalize(pmove + 0x14);
    VectorNormalize(pmove + 0x20);
    fStack_18 = fVar2 * *(float *)(pmove + 0x20) + fVar1 * *(float *)(pmove + 0x14);
    fStack_14 = fVar2 * *(float *)(pmove + 0x24) + fVar1 * *(float *)(pmove + 0x18);
    fStack_10 = fVar1 * *(float *)(pmove + 0x1c) + fVar2 * *(float *)(pmove + 0x28) +
                *(float *)("Holster__6CTFRpgi" + pmove + 0xf);
    local_c = fStack_18;
    fStack_8 = fStack_14;
    fStack_4 = fStack_10;
    lVar6 = (longdouble)VectorNormalize(&fStack_18);
    lVar5 = (longdouble)*(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0xc);
    if (0x3f < (byte)((lVar6 < lVar5 |
                       (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1)) {
      VectorScale(&local_c,(float)((longdouble)
                                   *(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) +
                                             0xc) / lVar6),&local_c);
      lVar6 = (longdouble)*(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0xc);
    }
    lVar5 = lVar6 - ((longdouble)*(float *)(pmove + 100) * (longdouble)fStack_10 +
                    (longdouble)*(float *)(pmove + 0x60) * (longdouble)fStack_14 +
                    (longdouble)*(float *)(pmove + 0x5c) * (longdouble)fStack_18);
    if ((longdouble)0.0 < lVar5) {
      lVar6 = (longdouble)*(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x10) *
              (longdouble)*(float *)(pmove + 0x10) * lVar6;
      if (lVar5 < lVar6) {
        lVar6 = lVar5;
      }
      *(float *)(pmove + 0x5c) =
           (float)(lVar6 * (longdouble)fStack_18 + (longdouble)*(float *)(pmove + 0x5c));
      *(float *)(pmove + 0x60) =
           (float)(lVar6 * (longdouble)fStack_14 + (longdouble)*(float *)(pmove + 0x60));
      *(float *)(pmove + 100) =
           (float)(lVar6 * (longdouble)fStack_10 + (longdouble)*(float *)(pmove + 100));
      VectorMA(pmove + 0x38,*(undefined4 *)(pmove + 0x10),pmove + 0x5c,pmove + 0x38);
    }
  }
  else {
    iVar4 = 0;
    if (0 < *(int *)(pmove + 0x24c)) {
      iVar3 = 0;
      do {
        if (*(int *)(iVar3 + 0x2a0 + pmove) == *(int *)(pmove + 0x200)) break;
        iVar3 = iVar3 + 0xe0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(pmove + 0x24c));
    }
    if (iVar4 != *(int *)(pmove + 0x24c)) {
      local_3c = vec3_origin;
      local_38 = DAT_0015d864;
      local_34 = DAT_0015d868;
      if (*(int *)(pmove + 0x1fc) == 1) {
        local_20 = *(undefined4 *)(iVar4 * 0xe0 + pmove + 0x2a8);
        local_1c = *(undefined4 *)(iVar4 * 0xe0 + pmove + 0x2ac);
        local_24 = 0;
      }
      else {
        local_24 = *(undefined4 *)(pmove + 0x44);
        local_20 = *(undefined4 *)(pmove + 0x48);
        local_1c = *(undefined4 *)(pmove + 0x4c);
      }
      GetChaseOrigin(&local_24,iVar4,&local_3c,&local_30);
      *(undefined4 *)(pmove + 0x38) = local_30;
      *(undefined4 *)(pmove + 0x3c) = local_2c;
      *(undefined4 *)(pmove + 0x40) = local_28;
      *(undefined4 *)(pmove + 0x44) = local_24;
      *(undefined4 *)(pmove + 0x48) = local_20;
      *(undefined4 *)(pmove + 0x4c) = local_1c;
      *(undefined4 *)(pmove + 0x5c) = vec3_origin;
      *(undefined4 *)(pmove + 0x60) = DAT_0015d864;
      *(undefined4 *)(pmove + 100) = DAT_0015d868;
    }
  }
  return;
}


// PM_SplineFraction  @ 001234e0
longdouble PM_SplineFraction(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 * (longdouble)param_2;
  lVar2 = lVar1 * lVar1;
  return (longdouble)3.0 * lVar2 - (lVar2 + lVar2) * lVar1;
}


// PM_SwapTextures  @ 0011f7ac
void PM_SwapTextures(int param_1,int param_2)

{
  undefined1 uVar1;
  char *__src;
  char *__src_00;
  char local_10 [16];
  
  __src_00 = (char *)((int)&grgszTextureName + param_1 * 0xd);
  strcpy(local_10,__src_00);
  uVar1 = (&grgchTextureType)[param_1];
  __src = (char *)((int)&grgszTextureName + param_2 * 0xd);
  strcpy(__src_00,__src);
  (&grgchTextureType)[param_1] = (&grgchTextureType)[param_2];
  strcpy(__src,local_10);
  (&grgchTextureType)[param_2] = uVar1;
  return;
}


// PM_UpdateStepSound  @ 001204f0
void PM_UpdateStepSound(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  bool bVar5;
  longdouble lVar6;
  float local_44;
  float local_40;
  float local_3c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  if (0 < *(int *)(pmove + 0x94)) {
    return;
  }
  if ((*(byte *)(pmove + 0xb9) & 0x10) != 0) {
    return;
  }
  PM_CatagorizeTextureType();
  lVar6 = (longdouble)Length(pmove + 0x5c);
  fVar1 = (float)lVar6;
  bVar4 = *(int *)(pmove + 0xdc) == 5;
  if (((*(byte *)(pmove + 0xb9) & 0x40) != 0) || (bVar4)) {
    local_40 = 60.0;
    local_3c = 80.0;
    local_44 = 100.0;
  }
  else {
    local_40 = 120.0;
    local_3c = 210.0;
    local_44 = 0.0;
  }
  if ((!bVar4) && (*(int *)(pmove + 0xe0) == -1)) {
    return;
  }
  lVar6 = (longdouble)Length(pmove + 0x5c);
  if (lVar6 <= (longdouble)0.0) {
    return;
  }
  if ((fVar1 < local_40) && (*(int *)(pmove + 0x94) != 0)) {
    return;
  }
  bVar5 = (byte)(fVar1 < local_3c |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_3c)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == local_3c) << 0xe) >> 8)) == 1;
  local_c = *(undefined4 *)(pmove + 0x38);
  local_8 = *(undefined4 *)(pmove + 0x3c);
  local_18 = *(undefined4 *)(pmove + 0x38);
  local_14 = *(undefined4 *)(pmove + 0x3c);
  fVar1 = *(float *)(pmove + 0x4f52c + *(int *)(pmove + 0xbc) * 0xc) -
          *(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc);
  local_4 = *(float *)(pmove + 0x40) - fVar1 * 0.3;
  local_10 = *(float *)(pmove + 0x40) - fVar1 * 0.5;
  if (bVar4) {
    uVar3 = 8;
    fVar1 = 0.35;
    *(undefined4 *)(pmove + 0x94) = 0x15e;
    goto LAB_0012088a;
  }
  iVar2 = (**(code **)((int)&__DT_REL[0x115f].r_info + pmove))(&local_c,0);
  if (iVar2 == -3) {
    uVar3 = 7;
    fVar1 = 0.65;
    *(undefined4 *)(pmove + 0x94) = 600;
    goto LAB_0012088a;
  }
  iVar2 = (**(code **)((int)&__DT_REL[0x115f].r_info + pmove))(&local_18,0);
  if (iVar2 == -3) {
    uVar3 = 6;
LAB_00120764:
    fVar1 = 0.5;
    if (bVar5) {
      fVar1 = 0.2;
    }
    goto LAB_00120776;
  }
  uVar3 = PM_MapTextureTypeStepType((int)*(char *)(pmove + 0x1f0));
  switch(*(undefined1 *)(pmove + 0x1f0)) {
  default:
    goto LAB_00120764;
  case 0x44:
    fVar1 = 0.55;
    if (bVar5) {
      fVar1 = 0.25;
    }
    break;
  case 0x53:
    fVar1 = 0.5;
    if (!bVar5) {
      *(undefined4 *)(pmove + 0x94) = 300;
      goto LAB_0012088a;
    }
    fVar1 = 0.2;
    goto LAB_00120872;
  case 0x56:
    fVar1 = 0.7;
    if (bVar5) {
      fVar1 = 0.4;
    }
  }
LAB_00120776:
  if (!bVar5) {
    FUN_00120880();
    return;
  }
LAB_00120872:
  *(undefined4 *)(pmove + 0x94) = 400;
LAB_0012088a:
  *(int *)(pmove + 0x94) = (int)ROUND(local_44 + (float)*(int *)(pmove + 0x94));
  if ((*(byte *)(pmove + 0xb9) & 0x40) != 0) {
    fVar1 = fVar1 * 0.35;
  }
  PM_PlayStepSound(uVar3,fVar1);
  return;
}


// PM_WalkMove  @ 0012167c
void PM_WalkMove(void)

{
  int iVar1;
  code *pcVar2;
  float fVar3;
  float fVar4;
  longdouble lVar5;
  longdouble lVar6;
  float local_ac;
  float local_a8;
  undefined1 local_a4 [8];
  undefined4 local_9c;
  float local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  float local_88;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  local_a8 = *(float *)("Holster__6CTFRpgi" + pmove + 7);
  local_ac = *(float *)("Holster__6CTFRpgi" + pmove + 0xb);
  *(undefined4 *)(pmove + 0x1c) = 0;
  *(undefined4 *)(pmove + 0x28) = 0;
  VectorNormalize(pmove + 0x14);
  VectorNormalize(pmove + 0x20);
  local_18 = local_ac * *(float *)(pmove + 0x20) + local_a8 * *(float *)(pmove + 0x14);
  local_a8 = local_a8 * *(float *)(pmove + 0x18);
  local_14 = local_a8 + local_ac * *(float *)(pmove + 0x24);
  local_4 = 0;
  local_10 = 0;
  local_c = local_18;
  local_8 = local_14;
  lVar5 = (longdouble)VectorNormalize(&local_18);
  lVar6 = (longdouble)*(float *)(pmove + 500);
  if (0x3f < (byte)((lVar5 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar6)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar6) << 0xe) >> 8)) - 1)) {
    VectorScale(&local_c,(float)((longdouble)*(float *)(pmove + 500) / lVar5),&local_c);
    lVar5 = (longdouble)*(float *)(pmove + 500);
  }
  *(undefined4 *)(pmove + 100) = 0;
  PM_Accelerate(&local_18,(float)lVar5,
                *(undefined4 *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x10));
  *(undefined4 *)(pmove + 100) = 0;
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) + *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) + *(float *)(pmove + 0x7c);
  lVar6 = (longdouble)Length(pmove + 0x5c);
  lVar5 = (longdouble)1.0;
  if (0x3f < (byte)((lVar5 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar6)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar6) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(pmove + 0x5c) = 0;
    *(undefined4 *)(pmove + 0x60) = 0;
    *(undefined4 *)(pmove + 100) = 0;
    return;
  }
  iVar1 = *(int *)(pmove + 0xe0);
  local_30 = *(float *)(pmove + 0x5c) * *(float *)(pmove + 0x10) + *(float *)(pmove + 0x38);
  local_2c = *(float *)(pmove + 0x60) * *(float *)(pmove + 0x10) + *(float *)(pmove + 0x3c);
  local_28 = *(undefined4 *)(pmove + 0x40);
  pcVar2 = *(code **)((int)&__DT_REL[0x1161].r_offset + pmove);
  local_24 = local_30;
  local_20 = local_2c;
  local_1c = local_28;
  (*pcVar2)(local_a4,pmove + 0x38,&local_24,0,0xffffffff);
  if ((byte)((byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_98 == 1.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(pmove + 0x38) = local_94;
    *(undefined4 *)(pmove + 0x3c) = local_90;
    *(undefined4 *)(pmove + 0x40) = local_8c;
    return;
  }
  if ((iVar1 == -1) && (*(int *)(pmove + 0xe4) == 0)) {
    return;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) != 0x40) {
    return;
  }
  local_40 = *(undefined4 *)(pmove + 0x38);
  local_3c = *(undefined4 *)(pmove + 0x3c);
  local_38 = *(undefined4 *)(pmove + 0x40);
  local_4c = *(undefined4 *)(pmove + 0x5c);
  local_48 = *(float *)(pmove + 0x60);
  local_44 = *(float *)(pmove + 100);
  PM_FlyMove();
  local_58 = *(undefined4 *)(pmove + 0x38);
  local_54 = *(undefined4 *)(pmove + 0x3c);
  local_50 = *(undefined4 *)(pmove + 0x40);
  local_64 = *(undefined4 *)(pmove + 0x5c);
  local_60 = *(float *)(pmove + 0x60);
  local_5c = *(float *)(pmove + 100);
  *(undefined4 *)(pmove + 0x38) = local_40;
  *(undefined4 *)(pmove + 0x3c) = local_3c;
  *(undefined4 *)(pmove + 0x40) = local_38;
  *(undefined4 *)(pmove + 0x5c) = local_4c;
  *(float *)(pmove + 0x60) = local_48;
  *(float *)(pmove + 100) = local_44;
  local_28 = *(undefined4 *)(pmove + 0x38);
  local_24 = *(float *)(pmove + 0x3c);
  local_20 = *(float *)(pmove + 0x40) +
             *(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x30);
  (**(code **)((int)&__DT_REL[0x1161].r_offset + pmove))
            (&local_a8,pmove + 0x38,&local_28,0,0xffffffff);
  if ((local_a8 == 0.0) && (local_ac == 0.0)) {
    *(float *)(pmove + 0x38) = local_98;
    *(undefined4 *)(pmove + 0x3c) = local_94;
    *(undefined4 *)(pmove + 0x40) = local_90;
  }
  PM_FlyMove();
  local_2c = *(float *)(pmove + 0x38);
  local_28 = *(undefined4 *)(pmove + 0x3c);
  local_24 = *(float *)(pmove + 0x40) -
             *(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x30);
  (**(code **)((int)&__DT_REL[0x1161].r_offset + pmove))
            (&local_ac,pmove + 0x38,&local_2c,0,0xffffffff);
  if (0.7 <= local_88) {
    if ((local_ac == 0.0) && (pcVar2 == (code *)0x0)) {
      *(undefined4 *)(pmove + 0x38) = local_9c;
      *(float *)(pmove + 0x3c) = local_98;
      *(undefined4 *)(pmove + 0x40) = local_94;
    }
    *(undefined4 *)(pmove + 0x2c) = *(undefined4 *)(pmove + 0x38);
    *(undefined4 *)(pmove + 0x30) = *(undefined4 *)(pmove + 0x3c);
    *(undefined4 *)(pmove + 0x34) = *(undefined4 *)(pmove + 0x40);
    fVar3 = *(float *)(pmove + 0x2c) - local_48;
    fVar4 = *(float *)(pmove + 0x30) - local_44;
    if ((local_5c - local_44) * (local_5c - local_44) +
        (local_60 - local_48) * (local_60 - local_48) <= fVar4 * fVar4 + fVar3 * fVar3)
    goto LAB_00121cb3;
  }
  *(float *)(pmove + 0x38) = local_60;
  *(float *)(pmove + 0x3c) = local_5c;
  *(undefined4 *)(pmove + 0x40) = local_58;
  *(undefined4 *)(pmove + 0x5c) = local_6c;
  *(undefined4 *)(pmove + 0x60) = local_68;
LAB_00121cb3:
  *(undefined4 *)(pmove + 100) = local_64;
  return;
}


// PM_WaterJump  @ 00123f94
void PM_WaterJump(void)

{
  float fVar1;
  
  if (10000.0 < *(float *)(pmove + 0xcc)) {
    *(undefined4 *)(pmove + 0xcc) = 0x461c4000;
  }
  fVar1 = *(float *)(pmove + 0xcc);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    *(float *)(pmove + 0xcc) =
         *(float *)(pmove + 0xcc) - (float)(byte)"CanHolster__6CTFRpg"[pmove + 0xd];
    if ((*(float *)(pmove + 0xcc) < 0.0) || (*(int *)(pmove + 0xe4) == 0)) {
      *(undefined4 *)(pmove + 0xcc) = 0;
      *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) & 0xf7;
    }
    *(undefined4 *)(pmove + 0x5c) = *(undefined4 *)(pmove + 0x68);
    *(undefined4 *)(pmove + 0x60) = *(undefined4 *)(pmove + 0x6c);
  }
  return;
}


// PM_WaterMove  @ 00121fbc
void PM_WaterMove(void)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fStack_8c;
  float fStack_88;
  int iStack_84;
  int aiStack_80 [4];
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fStack_18 = *(float *)(pmove + 0x20) * *(float *)("Holster__6CTFRpgi" + pmove + 0xb) +
              *(float *)(pmove + 0x14) * *(float *)("Holster__6CTFRpgi" + pmove + 7);
  fStack_14 = *(float *)(pmove + 0x24) * *(float *)("Holster__6CTFRpgi" + pmove + 0xb) +
              *(float *)(pmove + 0x18) * *(float *)("Holster__6CTFRpgi" + pmove + 7);
  fStack_10 = *(float *)(pmove + 0x28) * *(float *)("Holster__6CTFRpgi" + pmove + 0xb) +
              *(float *)(pmove + 0x1c) * *(float *)("Holster__6CTFRpgi" + pmove + 7);
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)("Holster__6CTFRpgi" + pmove + 7)) << 10) >> 8)
              | (byte)((ushort)((ushort)(*(float *)("Holster__6CTFRpgi" + pmove + 7) == 0.0) << 0xe)
                      >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)("Holster__6CTFRpgi" + pmove + 0xb)) << 10) >> 8
                    ) |
             (byte)((ushort)((ushort)(*(float *)("Holster__6CTFRpgi" + pmove + 0xb) == 0.0) << 0xe)
                   >> 8)) == 0x40)) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)("Holster__6CTFRpgi" + pmove + 0xf)) << 10) >> 8)
            | (byte)((ushort)((ushort)(*(float *)("Holster__6CTFRpgi" + pmove + 0xf) == 0.0) << 0xe)
                    >> 8)) == 0x40)) {
    fStack_10 = fStack_10 - 60.0;
  }
  else {
    fStack_10 = fStack_10 + *(float *)("Holster__6CTFRpgi" + pmove + 0xf);
  }
  fStack_c = fStack_18;
  fStack_8 = fStack_14;
  fStack_4 = fStack_10;
  lVar2 = (longdouble)VectorNormalize(&fStack_18);
  fStack_88 = (float)lVar2;
  fVar1 = *(float *)(pmove + 500);
  if (0x3f < (byte)((fStack_88 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(fStack_88) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_88 == fVar1) << 0xe) >> 8)) - 1)) {
    VectorScale(&fStack_c,*(float *)(pmove + 500) / fStack_88,&fStack_c);
    fStack_88 = *(float *)(pmove + 500);
  }
  fStack_88 = fStack_88 * 0.8;
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) + *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) + *(float *)(pmove + 0x7c);
  uStack_3c = *(undefined4 *)(pmove + 0x5c);
  uStack_38 = *(undefined4 *)(pmove + 0x60);
  uStack_34 = *(undefined4 *)(pmove + 100);
  lVar2 = (longdouble)VectorNormalize(&uStack_3c);
  lVar3 = (longdouble)0.0;
  if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) == 0x40) {
    fStack_8c = 0.0;
  }
  else {
    lVar4 = lVar2 - lVar2 * (longdouble)*(float *)(pmove + 0x10) *
                    (longdouble)*(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x1c)
                    * (longdouble)*(float *)(pmove + 0xc4);
    fStack_8c = (float)lVar4;
    if (lVar4 < lVar3) {
      fStack_8c = 0.0;
    }
    VectorScale(pmove + 0x5c,(float)((longdouble)fStack_8c / lVar2),pmove + 0x5c);
  }
  if (0.1 <= fStack_88) {
    fStack_8c = fStack_88 - fStack_8c;
    if (0.0 < fStack_8c) {
      VectorNormalize(&fStack_c);
      fVar1 = fStack_88 * *(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x10) *
              *(float *)(pmove + 0x10) * *(float *)(pmove + 0xc4);
      if (0x3f < (byte)((fVar1 < fStack_8c |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fStack_8c)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fStack_8c) << 0xe) >> 8)) - 1)) {
        fVar1 = fStack_8c;
      }
      *(float *)(pmove + 0x5c) = fVar1 * fStack_c + *(float *)(pmove + 0x5c);
      *(float *)(pmove + 0x60) = fVar1 * fStack_8 + *(float *)(pmove + 0x60);
      *(float *)(pmove + 100) = fVar1 * fStack_4 + *(float *)(pmove + 100);
    }
    VectorMA(pmove + 0x38,*(undefined4 *)(pmove + 0x10),pmove + 0x5c,&uStack_30);
    uStack_24 = uStack_30;
    uStack_20 = uStack_2c;
    fStack_1c = *(float *)(*(int *)((int)&__DT_REL[0x114f].r_offset + pmove) + 0x30) + 1.0 +
                fStack_28;
    (**(code **)((int)&__DT_REL[0x1161].r_offset + pmove))
              (aiStack_80,&uStack_24,&uStack_30,0,0xffffffff);
    if ((aiStack_80[0] == 0) && (iStack_84 == 0)) {
      *(undefined4 *)(pmove + 0x38) = uStack_70;
      *(undefined4 *)(pmove + 0x3c) = uStack_6c;
      *(undefined4 *)(pmove + 0x40) = uStack_68;
    }
    else {
      PM_FlyMove();
    }
  }
  return;
}


