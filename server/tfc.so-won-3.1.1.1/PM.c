// PM_Accelerate  @ 00138fcc
void PM_Accelerate(float *param_1,float param_2,float param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  if (((*(int *)(pmove + 0xd0) == 0) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40)) &&
     (fVar4 = param_2 - (*(float *)(pmove + 100) * param_1[2] +
                        *(float *)(pmove + 0x60) * param_1[1] + *(float *)(pmove + 0x5c) * *param_1)
     , 0x3f < (byte)((fVar4 < 0.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) - 1))) {
    fVar3 = param_3 * *(float *)(pmove + 0x10) * param_2 * *(float *)(pmove + 0xc4);
    if (0x3f < (byte)((fVar3 < fVar4 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) - 1)) {
      fVar3 = fVar4;
    }
    iVar5 = 0;
    do {
      iVar2 = iVar5 * 4;
      pfVar1 = param_1 + iVar5;
      iVar5 = iVar5 + 1;
      *(float *)(iVar2 + pmove + 0x5c) = fVar3 * *pfVar1 + *(float *)(iVar2 + pmove + 0x5c);
    } while (iVar5 < 3);
  }
  return;
}


// PM_AddCorrectGravity  @ 00133d98
void PM_AddCorrectGravity(void)

{
  float fVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = *(float *)(pmove + 0xc0);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar1 = 1.0;
    }
    *(float *)(pmove + 100) =
         *(float *)(pmove + 100) -
         fVar1 * **(float **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) *
         *(float *)(pmove + 0x10) * 0.5;
    *(float *)(pmove + 100) =
         *(float *)(pmove + 0x7c) * *(float *)(pmove + 0x10) + *(float *)(pmove + 100);
    *(undefined4 *)(pmove + 0x7c) = 0;
    PM_CheckVelocity();
  }
  return;
}


// PM_AddGravity  @ 001392a0
void PM_AddGravity(void)

{
  float fVar1;
  
  fVar1 = *(float *)(pmove + 0xc0);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = 1.0;
  }
  *(float *)(pmove + 100) =
       *(float *)(pmove + 100) -
       fVar1 * **(float **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) *
       *(float *)(pmove + 0x10);
  *(float *)(pmove + 100) =
       *(float *)(pmove + 0x7c) * *(float *)(pmove + 0x10) + *(float *)(pmove + 100);
  *(undefined4 *)(pmove + 0x7c) = 0;
  PM_CheckVelocity();
  return;
}


// PM_AddToTouched  @ 00138dbc
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
  
  iVar3 = 0;
  if (0 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
    do {
      if (*(int *)("__vt_12CTriggerPush" + iVar3 * 0x44 + pmove + 2) == in_stack_00000034) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc));
  }
  if (iVar3 == *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
    uStack00000038 = *in_stack_00000048;
    uStack0000003c = in_stack_00000048[1];
    uStack00000040 = in_stack_00000048[2];
    if (599 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_offset + pmove))
                ("Too many entities were touched!\n");
    }
    iVar3 = pmove;
    uVar1 = 1;
    pcVar4 = "__vt_12CChangeLevel" +
             (*(int *)("__vt_12CChangeLevel" + pmove + 0xc) * 0x10 +
             *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) * 4 + pmove + 0x10;
    for (iVar2 = 0x11; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4),
        iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)register0x00000010;
      pcVar4 = pcVar4 + 4;
    }
    *(int *)("__vt_12CChangeLevel" + iVar3 + 0xc) =
         *(int *)("__vt_12CChangeLevel" + iVar3 + 0xc) + 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// PM_AirAccelerate  @ 00139094
void PM_AirAccelerate(float *param_1,float param_2,float param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  if ((*(int *)(pmove + 0xd0) == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar4 = param_2;
    if (30.0 < param_2) {
      fVar4 = 30.0;
    }
    fVar4 = fVar4 - (*(float *)(pmove + 100) * param_1[2] +
                    *(float *)(pmove + 0x60) * param_1[1] + *(float *)(pmove + 0x5c) * *param_1);
    if (0.0 < fVar4) {
      fVar3 = param_3 * param_2 * *(float *)(pmove + 0x10) * *(float *)(pmove + 0xc4);
      if (0x3f < (byte)((fVar3 < fVar4 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) - 1)) {
        fVar3 = fVar4;
      }
      iVar5 = 0;
      do {
        iVar2 = iVar5 * 4;
        pfVar1 = param_1 + iVar5;
        iVar5 = iVar5 + 1;
        *(float *)(iVar2 + pmove + 0x5c) = fVar3 * *pfVar1 + *(float *)(iVar2 + pmove + 0x5c);
      } while (iVar5 < 3);
    }
  }
  return;
}


// PM_AirMove  @ 00135244
void PM_AirMove(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  longdouble lVar8;
  float afStack_1c [6];
  
  fVar2 = *(float *)("__vt_11CFireAndDie" + pmove + 0xc);
  fVar3 = *(float *)("__vt_11CFireAndDie" + pmove + 0x10);
  *(undefined4 *)(pmove + 0x1c) = 0;
  *(undefined4 *)(pmove + 0x28) = 0;
  VectorNormalize(pmove + 0x14);
  VectorNormalize(pmove + 0x20);
  pfVar1 = afStack_1c + 3;
  iVar6 = 0;
  do {
    iVar5 = iVar6 + 1;
    pfVar1[iVar6] =
         fVar3 * *(float *)(iVar6 * 4 + 0x20 + pmove) + fVar2 * *(float *)(iVar6 * 4 + 0x14 + pmove)
    ;
    iVar6 = iVar5;
  } while (iVar5 < 2);
  afStack_1c[5] = 0.0;
  afStack_1c[0] = afStack_1c[3];
  afStack_1c[1] = afStack_1c[4];
  afStack_1c[2] = 0.0;
  lVar7 = (longdouble)VectorNormalize(afStack_1c);
  lVar8 = (longdouble)*(float *)(pmove + 500);
  if (0x3f < (byte)((lVar7 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar8)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar7 == lVar8) << 0xe) >> 8)) - 1)) {
    VectorScale(pfVar1,(float)((longdouble)*(float *)(pmove + 500) / lVar7),pfVar1);
    lVar7 = (longdouble)*(float *)(pmove + 500);
  }
  if ((*(int *)(pmove + 0xd0) == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40)) {
    lVar8 = lVar7;
    if ((longdouble)30.0 < lVar7) {
      lVar8 = (longdouble)30.0;
    }
    lVar8 = lVar8 - ((longdouble)*(float *)(pmove + 100) * (longdouble)afStack_1c[2] +
                    (longdouble)*(float *)(pmove + 0x60) * (longdouble)afStack_1c[1] +
                    (longdouble)*(float *)(pmove + 0x5c) * (longdouble)afStack_1c[0]);
    lVar4 = (longdouble)0.0;
    if (0x3f < (byte)((lVar8 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar8 == lVar4) << 0xe) >> 8)) - 1)) {
      lVar7 = (longdouble)
              *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x14) *
              lVar7 * (longdouble)*(float *)(pmove + 0x10) * (longdouble)*(float *)(pmove + 0xc4);
      if (0x3f < (byte)((lVar7 < lVar8 |
                         (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar8)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar7 == lVar8) << 0xe) >> 8)) - 1)) {
        lVar7 = lVar8;
      }
      iVar6 = 0;
      do {
        iVar5 = iVar6 * 4;
        pfVar1 = afStack_1c + iVar6;
        iVar6 = iVar6 + 1;
        *(float *)(iVar5 + pmove + 0x5c) =
             (float)(lVar7 * (longdouble)*pfVar1 + (longdouble)*(float *)(iVar5 + pmove + 0x5c));
      } while (iVar6 < 3);
    }
  }
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) + *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) + *(float *)(pmove + 0x7c);
  PM_FlyMove();
  return;
}


// PM_CalcRoll  @ 001393a8
longdouble PM_CalcRoll(undefined4 param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  undefined1 local_28 [12];
  float local_1c;
  float local_18;
  float local_14;
  undefined1 local_10 [12];
  
  AngleVectors(param_1,local_10,&local_1c,local_28);
  fVar1 = param_2[2] * local_14 + param_2[1] * local_18 + *param_2 * local_1c;
  lVar2 = (longdouble)1;
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    lVar2 = (longdouble)-1.0;
  }
  if ((longdouble)param_4 <= (longdouble)ABS(fVar1)) {
    lVar3 = (longdouble)param_3;
  }
  else {
    lVar3 = ((longdouble)ABS(fVar1) * (longdouble)param_3) / (longdouble)param_4;
  }
  return lVar3 * lVar2;
}


// PM_CatagorizePosition  @ 00135664
void PM_CatagorizePosition(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_9c [12];
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_54 [5];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_2c;
  int local_24;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  PM_CheckWater();
  local_10 = *(undefined4 *)(pmove + 0x38);
  local_c = *(undefined4 *)(pmove + 0x3c);
  local_8 = *(float *)(pmove + 0x40) - 2.0;
  if (*(float *)(pmove + 100) <= 180.0) {
    (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
              (local_54,pmove + 0x38,&local_10,0,0xffffffff);
    if ((byte)((0.7 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_2c == 0.7) << 0xe) >> 8)) - 1) < 0x40) {
      *(int *)(pmove + 0xe0) = local_24;
    }
    else {
      *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
    }
    if (*(int *)(pmove + 0xe0) != -1) {
      *(undefined4 *)(pmove + 0xcc) = 0;
      if (((*(int *)(pmove + 0xe4) < 2) && (local_54[1] == 0)) && (local_54[0] == 0)) {
        *(undefined4 *)(pmove + 0x38) = local_40;
        *(undefined4 *)(pmove + 0x3c) = local_3c;
        *(undefined4 *)(pmove + 0x40) = local_38;
      }
    }
    if (0 < local_24) {
      piVar3 = local_54;
      piVar4 = local_9c;
      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      iVar1 = 0;
      if (0 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
        do {
          if (*(int *)("__vt_12CTriggerPush" + iVar1 * 0x44 + pmove + 2) == local_6c) break;
          iVar1 = iVar1 + 1;
        } while (iVar1 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc));
      }
      if (iVar1 == *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
        local_68 = *(undefined4 *)(pmove + 0x5c);
        local_64 = *(undefined4 *)(pmove + 0x60);
        local_60 = *(undefined4 *)(pmove + 100);
        if (599 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
          (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_offset + pmove))
                    ("Too many entities were touched!\n");
        }
        iVar1 = pmove;
        piVar3 = local_9c;
        piVar4 = (int *)("__vt_12CChangeLevel" +
                        (*(int *)("__vt_12CChangeLevel" + pmove + 0xc) * 0x10 +
                        *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) * 4 + pmove + 0x10);
        for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar4 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar4 = piVar4 + 1;
        }
        *(int *)("__vt_12CChangeLevel" + iVar1 + 0xc) =
             *(int *)("__vt_12CChangeLevel" + iVar1 + 0xc) + 1;
      }
    }
  }
  else {
    *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
  }
  return;
}


// PM_CatagorizeTextureType  @ 00133690
void PM_CatagorizeTextureType(void)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int local_24;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *(undefined4 *)(pmove + 0x38);
  local_c = *(undefined4 *)(pmove + 0x3c);
  local_8 = *(undefined4 *)(pmove + 0x40);
  local_1c = *(undefined4 *)(pmove + 0x38);
  local_18 = *(undefined4 *)(pmove + 0x3c);
  local_14 = *(float *)(pmove + 0x40) - 64.0;
  *(undefined1 *)(pmove + 0xf0) = 0;
  *(undefined1 *)(pmove + 0x1f0) = 0x43;
  pcVar1 = (char *)(**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d5].r_info + pmove))
                             (*(undefined4 *)(pmove + 0xe0),&local_10,&local_1c);
  if (pcVar1 != (char *)0x0) {
    cVar3 = *pcVar1;
    if ((cVar3 == '-') || (cVar3 == '+')) {
      pcVar1 = pcVar1 + 2;
      cVar3 = *pcVar1;
    }
    if ((((cVar3 == '{') || (cVar3 == '!')) || (cVar3 == '~')) || (cVar3 == ' ')) {
      pcVar1 = pcVar1 + 1;
    }
    strcpy((char *)(pmove + 0xf0),pcVar1);
    *(undefined1 *)(pmove + 0xfc) = 0;
    pcVar1 = (char *)(pmove + 0xf0);
    local_24 = 0;
    iVar6 = gcTextures + -1;
    while (local_24 <= iVar6) {
      iVar5 = (local_24 + iVar6) / 2;
      iVar2 = strncasecmp(pcVar1,(char *)((int)&grgszTextureName + iVar5 * 0xd),0xc);
      if (iVar2 == 0) {
        uVar4 = *(undefined1 *)((int)&grgchTextureType + iVar5);
        goto LAB_001337ed;
      }
      if (iVar2 < 1) {
        if (iVar2 < 0) {
          iVar6 = iVar5 + -1;
        }
      }
      else {
        local_24 = iVar5 + 1;
      }
    }
    uVar4 = 0x43;
LAB_001337ed:
    *(undefined1 *)(pmove + 0x1f0) = uVar4;
  }
  return;
}


// PM_CheckFalling  @ 00137a4c
void PM_CheckFalling(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (((*(int *)(pmove + 0xe0) != -1) && (*(int *)(pmove + 0xd0) == 0)) &&
     (fVar1 = *(float *)(pmove + 0x9c), 350.0 <= fVar1)) {
    fVar2 = 0.5;
    if (*(int *)(pmove + 0xe4) < 1) {
      if (fVar1 <= 580.0) {
        if (fVar1 <= 290.0) {
          if (0x3f < (byte)((200.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == 200.0) << 0xe) >> 8)) - 1)) {
            fVar2 = 0.0;
          }
        }
        else {
          uVar4 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6c9].r_offset + pmove))
                            (pmove + 0x4f3f0,&DAT_0015bd20);
          iVar3 = __strtol_internal(uVar4,0,10,0);
          if (iVar3 == 1) {
            (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d5].r_offset + pmove))
                      (2,"player/pl_fallpain3.wav",0x3f800000,0x3f4ccccd,0,100);
          }
          fVar2 = 0.85;
        }
      }
      else {
        (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d5].r_offset + pmove))
                  (2,"player/pl_fallpain3.wav",0x3f800000,0x3f4ccccd,0,100);
        fVar2 = 1.0;
      }
    }
    if (0.0 < fVar2) {
      *(undefined4 *)(pmove + 0x94) = 0;
      PM_UpdateStepSound();
      switch(*(undefined1 *)(pmove + 0x1f0)) {
      default:
        uVar4 = 0;
        break;
      case 0x44:
        uVar4 = 2;
        break;
      case 0x47:
        uVar4 = 4;
        break;
      case 0x4d:
        uVar4 = 1;
        break;
      case 0x53:
        uVar4 = 6;
        break;
      case 0x54:
        uVar4 = 5;
        break;
      case 0x56:
        uVar4 = 3;
      }
      PM_PlayStepSound(uVar4,fVar2);
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


// PM_CheckParamters  @ 00137dc4
void PM_CheckParamters(void)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  longdouble lVar8;
  undefined1 auStack_3c [12];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined1 auStack_24 [12];
  float fStack_18;
  float local_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  local_14 = SQRT(*(float *)("__12CChangeLevel" + pmove + 1) *
                  *(float *)("__12CChangeLevel" + pmove + 1) +
                  *(float *)("__vt_11CFireAndDie" + pmove + 0x10) *
                  *(float *)("__vt_11CFireAndDie" + pmove + 0x10) +
                  *(float *)("__vt_11CFireAndDie" + pmove + 0xc) *
                  *(float *)("__vt_11CFireAndDie" + pmove + 0xc));
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
  if (((byte)(0.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (*(float *)(pmove + 500) < local_14)) {
    fVar2 = *(float *)(pmove + 500) / local_14;
    *(float *)("__vt_11CFireAndDie" + pmove + 0xc) =
         *(float *)("__vt_11CFireAndDie" + pmove + 0xc) * fVar2;
    *(float *)("__vt_11CFireAndDie" + pmove + 0x10) =
         *(float *)("__vt_11CFireAndDie" + pmove + 0x10) * fVar2;
    *(float *)("__12CChangeLevel" + pmove + 1) = fVar2 * *(float *)("__12CChangeLevel" + pmove + 1);
  }
  if (((*(uint *)(pmove + 0xb8) & 0x1001000) != 0) || (*(int *)(pmove + 0xd0) != 0)) {
    pcVar1 = "__vt_11CFireAndDie" + pmove + 0xc;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1 = "__vt_11CFireAndDie" + pmove + 0x10;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1 = "__12CChangeLevel" + pmove + 1;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
  }
  iVar7 = pmove + 0xa0;
  lVar8 = (longdouble)VectorNormalize(iVar7);
  fStack_18 = (float)(lVar8 - ((longdouble)10.0 + lVar8 * (longdouble)0.5) *
                              (longdouble)*(float *)(pmove + 0x10));
  if (0x3f < (byte)((0.0 < fStack_18 | (byte)((ushort)((ushort)NAN(fStack_18) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_18 == 0.0) << 0xe) >> 8)) - 1)) {
    fStack_18 = 0.0;
  }
  VectorScale(iVar7,fStack_18,iVar7);
  iVar7 = pmove;
  if (*(int *)(pmove + 0xd0) == 0) {
    fStack_10 = *(float *)("__vt_11CFireAndDie" + pmove) + *(float *)(pmove + 0xa0);
    fStack_c = *(float *)("__vt_11CFireAndDie" + pmove + 4) + *(float *)(pmove + 0xa4);
    fStack_8 = *(float *)("__vt_11CFireAndDie" + pmove + 8) + *(float *)(pmove + 0xa8);
    iVar5 = *(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove);
    fVar2 = *(float *)(iVar5 + 100);
    fVar3 = *(float *)(iVar5 + 0x68);
    AngleVectors(&fStack_10,auStack_24,&fStack_30,auStack_3c);
    fVar6 = *(float *)(iVar7 + 100) * fStack_28 +
            *(float *)(iVar7 + 0x60) * fStack_2c + *(float *)(iVar7 + 0x5c) * fStack_30;
    fVar4 = 1.0;
    if (0x3f < (byte)((0.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) - 1)) {
      fVar4 = -1.0;
    }
    if (ABS(fVar6) < fVar3) {
      fVar2 = (ABS(fVar6) * fVar2) / fVar3;
    }
    *(float *)(pmove + 0x4c) = fVar2 * fVar4 * 4.0;
    *(float *)(pmove + 0x44) = fStack_10;
    *(float *)(pmove + 0x48) = fStack_c;
  }
  else {
    *(undefined4 *)(pmove + 0x44) = *(undefined4 *)(pmove + 0x50);
    *(undefined4 *)(pmove + 0x48) = *(undefined4 *)(pmove + 0x54);
    *(undefined4 *)(pmove + 0x4c) = *(undefined4 *)(pmove + 0x58);
  }
  if (*(int *)(pmove + 0xd0) != 0) {
    *(undefined4 *)(pmove + 0x88) = 0xc1000000;
  }
  fVar2 = *(float *)(pmove + 0x48);
  if (0x3f < (byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1)) {
    *(float *)(pmove + 0x48) = fVar2 - 360.0;
  }
  return;
}


// PM_CheckStuck  @ 00135878
/* WARNING: Removing unreachable block (ram,0x00135db6) */

undefined4 PM_CheckStuck(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  int local_88;
  undefined1 local_6c [68];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar4 = (*(code *)pmove[0x13d57])(pmove + 0xe,local_6c);
  if (iVar4 == -1) {
    uVar5 = 0;
    *(undefined4 *)(rgStuckLast + pmove[1] * 4 + *pmove * 8) = 0;
  }
  else {
    local_10 = (float)pmove[0xe];
    local_c = (float)pmove[0xf];
    local_8 = (float)pmove[0x10];
    if ((pmove[1] == 0) && ((iVar4 == 0 || (pmove[iVar4 * 0x38 + 0xa0] != 0)))) {
      local_88 = 0;
      *(undefined4 *)(rgStuckLast + *pmove * 8) = 0;
      do {
        iVar7 = pmove[1] * 4 + *pmove * 8;
        iVar6 = *(int *)(rgStuckLast + iVar7);
        *(int *)(rgStuckLast + iVar7) = *(int *)(rgStuckLast + iVar7) + 1;
        iVar6 = iVar6 % 0x36;
        local_1c = (float)(&rgv3tStuckTable)[iVar6 * 3];
        local_18 = (float)(&DAT_001ad684)[iVar6 * 3];
        local_14 = (float)(&DAT_001ad688)[iVar6 * 3];
        local_28 = local_1c + local_10;
        local_24 = local_18 + local_c;
        local_20 = local_14 + local_8;
        iVar6 = (*(code *)pmove[0x13d57])(&local_28,local_6c);
        if (iVar6 == -1) {
          *(undefined4 *)(rgStuckLast + pmove[1] * 4 + *pmove * 8) = 0;
          pmove[0xe] = (int)local_28;
          pmove[0xf] = (int)local_24;
          pmove[0x10] = (int)local_20;
          return 0;
        }
        local_88 = local_88 + 1;
      } while (local_88 < 0x36);
    }
    iVar6 = pmove[1];
    lVar8 = (longdouble)(*(code *)pmove[0x13d5b])();
    fVar2 = (float)lVar8 - 0.05;
    iVar6 = (uint)(iVar6 == 0) * 4 + *pmove * 8;
    fVar1 = *(float *)(rgStuckCheckTime_147 + iVar6);
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      *(float *)(rgStuckCheckTime_147 + iVar6) = (float)lVar8;
      (*(code *)pmove[0x13d5c])(iVar4,local_6c);
      iVar6 = pmove[1] * 4 + *pmove * 8;
      iVar4 = *(int *)(rgStuckLast + iVar6);
      *(int *)(rgStuckLast + iVar6) = *(int *)(rgStuckLast + iVar6) + 1;
      iVar4 = iVar4 % 0x36;
      local_1c = (float)(&rgv3tStuckTable)[iVar4 * 3];
      local_18 = (float)(&DAT_001ad684)[iVar4 * 3];
      local_14 = (float)(&DAT_001ad688)[iVar4 * 3];
      local_28 = local_1c + local_10;
      local_24 = local_18 + local_c;
      local_20 = local_14 + local_8;
      iVar6 = (*(code *)pmove[0x13d57])(&local_28,0);
      if (iVar6 == -1) {
        *(undefined4 *)(rgStuckLast + *pmove * 8 + pmove[1] * 4) = 0;
        if (0x1a < iVar4) {
          pmove[0xe] = (int)local_28;
          pmove[0xf] = (int)local_24;
LAB_00135c9f:
          pmove[0x10] = (int)local_20;
        }
        return 0;
      }
      if (((*(byte *)((int)pmove + 0x45476) & 7) != 0) && (pmove[iVar6 * 0x38 + 0x9c] != 0)) {
        fVar1 = 0.0;
        do {
          fVar2 = -8.0;
          do {
            fVar3 = -8.0;
            do {
              local_28 = local_10 + fVar2;
              local_24 = local_c + fVar3;
              local_20 = local_8 + fVar1;
              iVar4 = (*(code *)pmove[0x13d57])(&local_28,0);
              if (iVar4 == -1) {
                pmove[0xe] = (int)local_28;
                pmove[0xf] = (int)local_24;
                goto LAB_00135c9f;
              }
              fVar3 = fVar3 + 8.0;
            } while ((byte)((fVar3 < 8.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar3 == 8.0) << 0xe) >> 8)) - 1) < 0x40);
            fVar2 = fVar2 + 8.0;
          } while ((byte)((fVar2 < 8.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 8.0) << 0xe) >> 8)) - 1) < 0x40);
          fVar1 = fVar1 + 18.0;
        } while ((byte)((fVar1 < 72.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 72.0) << 0xe) >> 8)) - 1) < 0x40);
      }
    }
    uVar5 = 1;
  }
  return uVar5;
}


// PM_CheckVelocity  @ 00133c4c
void PM_CheckVelocity(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if ((*(uint *)(pmove + 0x5c + iVar4 * 4) & nanmask) == nanmask) {
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_info + pmove))
                ("PM  Got a NaN velocity %i\n",iVar4);
      *(undefined4 *)(pmove + 0x5c + iVar4 * 4) = 0;
    }
    iVar1 = iVar4 * 4;
    if ((*(uint *)(pmove + 0x38 + iVar4 * 4) & nanmask) == nanmask) {
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_info + pmove))
                ("PM  Got a NaN origin on %i\n",iVar4);
      *(undefined4 *)(iVar1 + pmove + 0x38) = 0;
    }
    fVar2 = *(float *)(iVar1 + 0x5c + pmove);
    fVar3 = *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x34);
    if (fVar2 <= fVar3) {
      fVar3 = -fVar3;
      if (0x3f < (byte)((fVar3 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1)) {
        (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_offset + pmove))
                  ("PM  Got a velocity too low on %i\n",iVar4);
        fVar2 = -*(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x34);
        goto LAB_00133d7d;
      }
    }
    else {
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_offset + pmove))
                ("PM  Got a velocity too high on %i\n",iVar4);
      fVar2 = *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x34);
LAB_00133d7d:
      *(float *)(iVar1 + 0x5c + pmove) = fVar2;
    }
    iVar4 = iVar4 + 1;
    if (2 < iVar4) {
      return;
    }
  } while( true );
}


// PM_CheckWater  @ 00135460
bool PM_CheckWater(void)

{
  int iVar1;
  int iStack_18;
  float local_14;
  float local_10;
  float local_c;
  float fStack_8;
  
  local_10 = (*(float *)(pmove + 0x4f4f4 + *(int *)(pmove + 0xbc) * 0xc) +
             *(float *)(pmove + 0x4f524 + *(int *)(pmove + 0xbc) * 0xc)) * 0.5 +
             *(float *)(pmove + 0x38);
  local_14 = (*(float *)(pmove + 0x4f4f8 + *(int *)(pmove + 0xbc) * 0xc) +
             *(float *)(pmove + 0x4f528 + *(int *)(pmove + 0xbc) * 0xc)) * 0.5 +
             *(float *)(pmove + 0x3c);
  fStack_8 = *(float *)(pmove + 0x40) + *(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc) +
             1.0;
  *(undefined4 *)(pmove + 0xe4) = 0;
  *(undefined4 *)(pmove + 0xe8) = 0xffffffff;
  local_c = local_14;
  iVar1 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cd].r_offset + pmove))
                    (&local_10,&iStack_18);
  if (iVar1 + 0xeU < 0xc) {
    *(int *)(pmove + 0xe8) = iVar1;
    *(undefined4 *)(pmove + 0xe4) = 1;
    local_14 = (*(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc) +
               *(float *)(pmove + 0x4f52c + *(int *)(pmove + 0xbc) * 0xc)) * 0.5;
    fStack_8 = local_14 + *(float *)(pmove + 0x40);
    iVar1 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cd].r_offset + pmove))(&local_10,0);
    if (iVar1 + 0xeU < 0xc) {
      *(undefined4 *)(pmove + 0xe4) = 2;
      fStack_8 = *(float *)(pmove + 0x40) + *(float *)(pmove + 0x88);
      iVar1 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cd].r_offset + pmove))(&local_10,0);
      if (iVar1 + 0xeU < 0xc) {
        *(undefined4 *)(pmove + 0xe4) = 3;
      }
    }
    if (iStack_18 + 0xeU < 6) {
      local_14 = (float)*(int *)(pmove + 0xe4) * 50.0;
      VectorMA(pmove + 0x74,local_14,&current_table_138 + (-9 - iStack_18) * 0xc,pmove + 0x74);
    }
  }
  return 1 < *(int *)(pmove + 0xe4);
}


// PM_CheckWaterJump  @ 001377e0
void PM_CheckWaterJump(void)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  undefined1 local_78 [16];
  float local_68;
  undefined1 local_58 [8];
  float local_50;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined1 local_1c [12];
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (-180.0 <= *(float *)(pmove + 100))) {
    local_34 = *(float *)(pmove + 0x5c);
    local_30 = *(float *)(pmove + 0x60);
    local_2c = 0.0;
    lVar3 = (longdouble)VectorNormalize(&local_34);
    fVar1 = (float)lVar3;
    local_28 = *(float *)(pmove + 0x14);
    local_24 = *(float *)(pmove + 0x18);
    local_20 = 0.0;
    VectorNormalize(&local_28);
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
       (fVar1 = local_2c * local_20 + local_30 * local_24 + local_34 * local_28,
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
      local_10 = *(undefined4 *)(pmove + 0x38);
      local_c = *(undefined4 *)(pmove + 0x3c);
      local_8 = *(float *)(pmove + 0x40) + 8.0;
      VectorMA(&local_10,0x41c00000,&local_28,local_1c);
      iVar2 = *(int *)(pmove + 0xbc);
      *(undefined4 *)(pmove + 0xbc) = 2;
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
                (local_78,&local_10,local_1c,0,0xffffffff);
      if ((0x3f < (byte)((1.0 < local_68 | (byte)((ushort)((ushort)NAN(local_68) << 10) >> 8) |
                         (byte)((ushort)((ushort)(local_68 == 1.0) << 0xe) >> 8)) - 1)) &&
         (local_50 = ABS(local_50),
         0x3f < (byte)((0.1 < local_50 | (byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
                       (byte)((ushort)((ushort)(local_50 == 0.1) << 0xe) >> 8)) - 1))) {
        local_8 = (*(float *)(pmove + 0x4f52c + iVar2 * 0xc) - 8.0) + local_8;
        VectorMA(&local_10,0x41c00000,&local_28,local_1c);
        VectorMA(&vec3_origin,0xc2480000,local_58,pmove + 0x68);
        (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
                  (local_78,&local_10,local_1c,0,0xffffffff);
        if ((byte)((byte)((ushort)((ushort)NAN(local_68) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_68 == 1.0) << 0xe) >> 8)) == 0x40) {
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


// PM_ClipVelocity  @ 00138e94
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
  bVar9 = 0.0 < fVar1;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar9 = bVar9 | 2;
  }
  fVar2 = *param_1;
  fVar3 = *param_2;
  fVar4 = param_1[1];
  fVar5 = param_2[1];
  fVar6 = param_1[2];
  iVar8 = 0;
  do {
    fVar7 = param_1[iVar8] -
            param_2[iVar8] * (fVar4 * fVar5 + fVar2 * fVar3 + fVar6 * fVar1) * param_4;
    *(float *)(param_3 + iVar8 * 4) = fVar7;
    if ((0x3f < (byte)((fVar7 < -0.1 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar7 == -0.1) << 0xe) >> 8)) - 1)) && (fVar7 < 0.1)
       ) {
      *(undefined4 *)(param_3 + iVar8 * 4) = 0;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 3);
  return bVar9;
}


// PM_CreateStuckTable  @ 001386ec
void PM_CreateStuckTable(void)

{
  undefined4 uVar1;
  float fVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  longdouble lVar9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  int local_4c;
  undefined4 local_10 [3];
  
  iVar7 = 0;
  lVar9 = (longdouble)-0.125;
  lVar10 = (longdouble)0.125;
  puVar8 = &rgv3tStuckTable;
  for (iVar6 = 0xa2; lVar11 = (longdouble)-0.125, iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  do {
    (&rgv3tStuckTable)[iVar7 * 3] = 0;
    (&DAT_001ad684)[iVar7 * 3] = 0;
    (&DAT_001ad688)[iVar7 * 3] = (float)lVar11;
    lVar9 = (longdouble)(float)(lVar9 + lVar10);
    iVar7 = iVar7 + 1;
    lVar11 = lVar9;
  } while ((byte)((lVar9 < lVar10 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar10)) << 10) >> 8)
                  | (byte)((ushort)((ushort)(lVar9 == lVar10) << 0xe) >> 8)) - 1) < 0x40);
  lVar10 = (longdouble)-0.125;
  lVar11 = (longdouble)0.125;
  lVar9 = (longdouble)-0.125;
  do {
    (&rgv3tStuckTable)[iVar7 * 3] = 0;
    iVar6 = iVar7 + 1;
    (&DAT_001ad684)[iVar7 * 3] = (float)lVar9;
    lVar10 = (longdouble)(float)(lVar10 + lVar11);
    (&DAT_001ad688)[iVar7 * 3] = 0;
    iVar7 = iVar6;
    lVar9 = lVar10;
  } while ((byte)((lVar10 < lVar11 |
                   (byte)((ushort)((ushort)(NAN(lVar10) || NAN(lVar11)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar10 == lVar11) << 0xe) >> 8)) - 1) < 0x40);
  lVar10 = (longdouble)-0.125;
  lVar11 = (longdouble)0.125;
  lVar9 = (longdouble)-0.125;
  do {
    (&rgv3tStuckTable)[iVar6 * 3] = (float)lVar9;
    iVar7 = iVar6 + 1;
    (&DAT_001ad684)[iVar6 * 3] = 0;
    lVar10 = (longdouble)(float)(lVar10 + lVar11);
    (&DAT_001ad688)[iVar6 * 3] = 0;
    iVar6 = iVar7;
    lVar9 = lVar10;
  } while ((byte)((lVar10 < lVar11 |
                   (byte)((ushort)((ushort)(NAN(lVar10) || NAN(lVar11)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar10 == lVar11) << 0xe) >> 8)) - 1) < 0x40);
  lVar10 = (longdouble)-0.125;
  lVar9 = (longdouble)-0.125;
  do {
    lVar15 = (longdouble)0.125;
    lVar12 = (longdouble)-0.125;
    lVar11 = (longdouble)-0.125;
    do {
      lVar13 = (longdouble)-0.125;
      lVar14 = (longdouble)-0.125;
      do {
        (&rgv3tStuckTable)[iVar7 * 3] = (float)lVar9;
        (&DAT_001ad684)[iVar7 * 3] = (float)lVar11;
        (&DAT_001ad688)[iVar7 * 3] = (float)lVar14;
        lVar13 = (longdouble)(float)(lVar13 + (longdouble)0.25);
        iVar7 = iVar7 + 1;
        lVar3 = (longdouble)0.125;
        lVar14 = lVar13;
      } while ((byte)((lVar13 < lVar3 |
                       (byte)((ushort)((ushort)(NAN(lVar13) || NAN(lVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar13 == lVar3) << 0xe) >> 8)) - 1) < 0x40);
      lVar12 = (longdouble)(float)(lVar12 + (longdouble)0.25);
      lVar11 = lVar12;
    } while ((byte)((lVar12 < lVar15 |
                     (byte)((ushort)((ushort)(NAN(lVar12) || NAN(lVar15)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(lVar12 == lVar15) << 0xe) >> 8)) - 1) < 0x40);
    lVar10 = (longdouble)(float)((longdouble)0.25 + lVar10);
    lVar9 = lVar10;
  } while (lVar10 <= (longdouble)0.125);
  local_4c = 0;
  do {
    uVar1 = local_10[local_4c];
    (&rgv3tStuckTable)[iVar7 * 3] = 0;
    (&DAT_001ad684)[iVar7 * 3] = 0;
    iVar6 = iVar7 + 1;
    (&DAT_001ad688)[iVar7 * 3] = uVar1;
    local_4c = local_4c + 1;
    iVar7 = iVar6;
  } while (local_4c < 3);
  fVar2 = -2.0;
  do {
    fVar4 = fVar2 + 2.0;
    (&rgv3tStuckTable)[iVar6 * 3] = 0;
    iVar7 = iVar6 + 1;
    (&DAT_001ad684)[iVar6 * 3] = fVar2;
    (&DAT_001ad688)[iVar6 * 3] = 0;
    iVar6 = iVar7;
    fVar2 = fVar4;
  } while ((byte)((fVar4 < 2.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
  fVar2 = -2.0;
  do {
    (&rgv3tStuckTable)[iVar7 * 3] = fVar2;
    fVar2 = fVar2 + 2.0;
    iVar6 = iVar7 + 1;
    (&DAT_001ad684)[iVar7 * 3] = 0;
    (&DAT_001ad688)[iVar7 * 3] = 0;
    iVar7 = iVar6;
  } while ((byte)((fVar2 < 2.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
  local_4c = 0;
  do {
    fVar2 = -2.0;
    uVar1 = local_10[local_4c];
    do {
      iVar7 = iVar6;
      fVar4 = -2.0;
      do {
        fVar5 = fVar4 + 2.0;
        (&rgv3tStuckTable)[iVar7 * 3] = fVar2;
        iVar6 = iVar7 + 1;
        (&DAT_001ad684)[iVar7 * 3] = fVar4;
        (&DAT_001ad688)[iVar7 * 3] = uVar1;
        iVar7 = iVar6;
        fVar4 = fVar5;
      } while ((byte)((fVar5 < 2.0 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar5 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
      fVar2 = fVar2 + 2.0;
    } while ((byte)((fVar2 < 2.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
    local_4c = local_4c + 1;
  } while (local_4c < 3);
  return;
}


// PM_DrawBBox  @ 0013a8a8
void PM_DrawBBox(float *param_1,float *param_2,float *param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float afStack_70 [24];
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  uVar1 = 0;
  do {
    if ((uVar1 & 1) == 0) {
      fStack_10 = *param_2 + 0.0;
    }
    else {
      fStack_10 = *param_1 - 0.0;
    }
    if ((uVar1 & 2) == 0) {
      fStack_c = param_2[1] + 0.0;
    }
    else {
      fStack_c = param_1[1] - 0.0;
    }
    if ((uVar1 & 4) == 0) {
      fStack_8 = param_2[2] + 0.0;
    }
    else {
      fStack_8 = param_1[2] - 0.0;
    }
    fStack_10 = fStack_10 + *param_3;
    fStack_c = fStack_c + param_3[1];
    fStack_8 = fStack_8 + param_3[2];
    uVar2 = uVar1 + 1;
    afStack_70[uVar1 * 3] = fStack_10;
    afStack_70[uVar1 * 3 + 1] = fStack_c;
    afStack_70[uVar1 * 3 + 2] = fStack_8;
    uVar1 = uVar2;
  } while ((int)uVar2 < 8);
  iVar3 = 0;
  do {
    PM_DrawRectangle(afStack_70 + (&DAT_001754a4)[iVar3 * 4] * 3,
                     afStack_70 + (&PM_boxpnt)[iVar3 * 4] * 3,
                     afStack_70 + *(int *)(&DAT_001754a8 + iVar3 * 0x10) * 3,
                     afStack_70 + *(int *)(&DAT_001754ac + iVar3 * 0x10) * 3,param_4,param_5);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  return;
}


// PM_DrawPhysEntBBox  @ 0013a44c
void PM_DrawPhysEntBBox(int param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float local_94;
  float fStack_90;
  float fStack_8c;
  float local_88;
  float fStack_84;
  float fStack_80;
  float afStack_7c [24];
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((param_1 < *(int *)(pmove + 0x24c)) && (0 < param_1)) {
    iVar4 = pmove + 0x250 + param_1 * 0xe0;
    if (*(int *)(iVar4 + 0x30) == 0) {
      uVar5 = 0;
      do {
        if ((uVar5 & 1) == 0) {
          fStack_1c = *(float *)(iVar4 + 0x44);
        }
        else {
          fStack_1c = *(float *)(iVar4 + 0x38);
        }
        if ((uVar5 & 2) == 0) {
          fStack_18 = *(float *)(iVar4 + 0x48);
        }
        else {
          fStack_18 = *(float *)(iVar4 + 0x3c);
        }
        if ((uVar5 & 4) == 0) {
          fStack_14 = *(float *)(iVar4 + 0x4c);
        }
        else {
          fStack_14 = *(float *)(iVar4 + 0x40);
        }
        fStack_1c = fStack_1c + *(float *)(iVar4 + 0x24);
        fStack_18 = fStack_18 + *(float *)(iVar4 + 0x28);
        fStack_14 = fStack_14 + *(float *)(iVar4 + 0x2c);
        uVar2 = uVar5 + 1;
        afStack_7c[uVar5 * 3] = fStack_1c;
        afStack_7c[uVar5 * 3 + 1] = fStack_18;
        afStack_7c[uVar5 * 3 + 2] = fStack_14;
        uVar5 = uVar2;
      } while ((int)uVar2 < 8);
      iVar4 = 0;
      do {
        PM_DrawRectangle(afStack_7c + (&DAT_001754a4)[iVar4 * 4] * 3,
                         afStack_7c + (&PM_boxpnt)[iVar4 * 4] * 3,
                         afStack_7c + *(int *)(&DAT_001754a8 + iVar4 * 0x10) * 3,
                         afStack_7c + *(int *)(&DAT_001754ac + iVar4 * 0x10) * 3,param_2,param_3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 6);
    }
    else {
      local_10 = *(float *)(iVar4 + 0x24);
      local_c = *(float *)(iVar4 + 0x28);
      local_8 = *(float *)(iVar4 + 0x2c);
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d1].r_offset + pmove))
                (*(undefined4 *)(iVar4 + 0x30),&local_88,&local_94);
      uVar5 = 0;
      do {
        if ((uVar5 & 1) == 0) {
          fStack_1c = local_94 + 0.0;
        }
        else {
          fStack_1c = local_88 - 0.0;
        }
        if ((uVar5 & 2) == 0) {
          fStack_18 = fStack_90 + 0.0;
        }
        else {
          fStack_18 = fStack_84 - 0.0;
        }
        if ((uVar5 & 4) == 0) {
          fStack_14 = fStack_8c + 0.0;
        }
        else {
          fStack_14 = fStack_80 - 0.0;
        }
        uVar2 = uVar5 + 1;
        afStack_7c[uVar5 * 3] = fStack_1c;
        afStack_7c[uVar5 * 3 + 1] = fStack_18;
        afStack_7c[uVar5 * 3 + 2] = fStack_14;
        uVar5 = uVar2;
      } while ((int)uVar2 < 8);
      if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar4 + 0x54)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x54) == 0.0) << 0xe) >> 8)) != 0x40)
          || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar4 + 0x58)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x58) == 0.0) << 0xe) >> 8)) != 0x40
             )) || (fVar1 = *(float *)(iVar4 + 0x5c),
                   (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
        AngleVectorsTranspose(iVar4 + 0x54,&fStack_a0,&fStack_ac,&fStack_b8);
        iVar4 = 0;
        do {
          fStack_1c = afStack_7c[iVar4 * 3];
          fStack_18 = afStack_7c[iVar4 * 3 + 1];
          fStack_14 = afStack_7c[iVar4 * 3 + 2];
          afStack_7c[iVar4 * 3] =
               fStack_14 * fStack_98 + fStack_18 * fStack_9c + fStack_1c * fStack_a0;
          afStack_7c[iVar4 * 3 + 1] =
               fStack_14 * fStack_a4 + fStack_18 * fStack_a8 + fStack_1c * fStack_ac;
          iVar3 = iVar4 + 1;
          afStack_7c[iVar4 * 3 + 2] =
               fStack_14 * fStack_b0 + fStack_18 * fStack_b4 + fStack_1c * fStack_b8;
          iVar4 = iVar3;
        } while (iVar3 < 8);
      }
      iVar4 = 0;
      do {
        afStack_7c[iVar4 * 3] = afStack_7c[iVar4 * 3] + local_10;
        afStack_7c[iVar4 * 3 + 1] = afStack_7c[iVar4 * 3 + 1] + local_c;
        iVar3 = iVar4 + 1;
        afStack_7c[iVar4 * 3 + 2] = afStack_7c[iVar4 * 3 + 2] + local_8;
        iVar4 = iVar3;
      } while (iVar3 < 8);
      iVar4 = 0;
      do {
        PM_DrawRectangle(afStack_7c + (&DAT_001754a4)[iVar4 * 4] * 3,
                         afStack_7c + (&PM_boxpnt)[iVar4 * 4] * 3,
                         afStack_7c + *(int *)(&DAT_001754a8 + iVar4 * 0x10) * 3,
                         afStack_7c + *(int *)(&DAT_001754ac + iVar4 * 0x10) * 3,param_2,param_3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 6);
    }
  }
  return;
}


// PM_DrawRectangle  @ 0013a154
void PM_DrawRectangle(float *param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5
                     ,undefined4 param_6)

{
  longdouble lVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_1c [6];
  
  local_1c[0] = *param_2 - *param_1;
  local_1c[1] = param_2[1] - param_1[1];
  local_1c[2] = param_2[2] - param_1[2];
  lVar4 = (longdouble)VectorNormalize(local_1c);
  lVar5 = (longdouble)0;
  if (lVar5 <= lVar4) {
    do {
      iVar3 = 0;
      do {
        iVar2 = iVar3 + 1;
        (local_1c + 3)[iVar3] =
             (float)(lVar5 * (longdouble)local_1c[iVar3] + (longdouble)param_1[iVar3]);
        iVar3 = iVar2;
      } while (iVar2 < 3);
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6c9].r_info + pmove))
                (local_1c + 3,param_5,param_6,0,0);
      lVar5 = lVar5 + (longdouble)2.0;
      lVar1 = (longdouble)(float)lVar4;
    } while ((byte)((lVar5 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar1) << 0xe) >> 8)) - 1) < 0x40);
  }
  local_1c[0] = *param_4 - *param_2;
  local_1c[1] = param_4[1] - param_2[1];
  local_1c[2] = param_4[2] - param_2[2];
  lVar4 = (longdouble)VectorNormalize(local_1c);
  lVar5 = (longdouble)0;
  if (lVar5 <= lVar4) {
    do {
      iVar3 = 0;
      do {
        iVar2 = iVar3 + 1;
        (local_1c + 3)[iVar3] =
             (float)(lVar5 * (longdouble)local_1c[iVar3] + (longdouble)param_2[iVar3]);
        iVar3 = iVar2;
      } while (iVar2 < 3);
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6c9].r_info + pmove))
                (local_1c + 3,param_5,param_6,0,0);
      lVar5 = lVar5 + (longdouble)2.0;
      lVar1 = (longdouble)(float)lVar4;
    } while ((byte)((lVar5 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar1) << 0xe) >> 8)) - 1) < 0x40);
  }
  local_1c[0] = *param_3 - *param_4;
  local_1c[1] = param_3[1] - param_4[1];
  local_1c[2] = param_3[2] - param_4[2];
  lVar4 = (longdouble)VectorNormalize(local_1c);
  lVar5 = (longdouble)0;
  if (lVar5 <= lVar4) {
    do {
      iVar3 = 0;
      do {
        iVar2 = iVar3 + 1;
        (local_1c + 3)[iVar3] =
             (float)(lVar5 * (longdouble)local_1c[iVar3] + (longdouble)param_4[iVar3]);
        iVar3 = iVar2;
      } while (iVar2 < 3);
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6c9].r_info + pmove))
                (local_1c + 3,param_5,param_6,0,0);
      lVar5 = lVar5 + (longdouble)2.0;
      lVar1 = (longdouble)(float)lVar4;
    } while ((byte)((lVar5 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar1) << 0xe) >> 8)) - 1) < 0x40);
  }
  local_1c[0] = *param_1 - *param_3;
  local_1c[1] = param_1[1] - param_3[1];
  local_1c[2] = param_1[2] - param_3[2];
  lVar4 = (longdouble)VectorNormalize(local_1c);
  lVar5 = (longdouble)0;
  if (lVar5 <= lVar4) {
    do {
      iVar3 = 0;
      do {
        iVar2 = iVar3 + 1;
        (local_1c + 3)[iVar3] =
             (float)(lVar5 * (longdouble)local_1c[iVar3] + (longdouble)param_3[iVar3]);
        iVar3 = iVar2;
      } while (iVar2 < 3);
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6c9].r_info + pmove))
                (local_1c + 3,param_5,param_6,0,0);
      lVar5 = lVar5 + (longdouble)2.0;
      lVar1 = (longdouble)(float)lVar4;
    } while ((byte)((lVar5 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar1) << 0xe) >> 8)) - 1) < 0x40);
  }
  return;
}


// PM_DropPunchAngle  @ 00139430
void PM_DropPunchAngle(undefined4 param_1)

{
  float fVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)VectorNormalize(param_1);
  fVar1 = (float)(lVar2 - ((longdouble)10.0 + lVar2 * (longdouble)0.5) *
                          (longdouble)*(float *)(pmove + 0x10));
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    fVar1 = 0.0;
  }
  VectorScale(param_1,fVar1,param_1);
  return;
}


// PM_Duck  @ 001363c8
void PM_Duck(void)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  
  uVar2 = *(ushort *)("__12CChangeLevel" + pmove + 7);
  uVar3 = *(uint *)(pmove + 200);
  if (("__12CChangeLevel"[pmove + 7] & 4U) == 0) {
    uVar6 = uVar3 & 0xfffffffb;
  }
  else {
    uVar6 = uVar3 | 4;
  }
  *(uint *)(pmove + 200) = uVar6;
  if ((*(int *)(pmove + 0x204) == 0) && (*(int *)(pmove + 0xd0) == 0)) {
    if ((*(byte *)(pmove + 0xb9) & 0x40) != 0) {
      *(float *)("__vt_11CFireAndDie" + pmove + 0xc) =
           *(float *)("__vt_11CFireAndDie" + pmove + 0xc) * 0.333;
      *(float *)("__vt_11CFireAndDie" + pmove + 0x10) =
           *(float *)("__vt_11CFireAndDie" + pmove + 0x10) * 0.333;
      *(float *)("__12CChangeLevel" + pmove + 1) =
           *(float *)("__12CChangeLevel" + pmove + 1) * 0.333;
    }
    if (("__12CChangeLevel"[pmove + 7] & 4U) != 0) {
      if ((((uVar3 ^ uVar2) & (uint)uVar2 & 4) != 0) && ((*(byte *)(pmove + 0xb9) & 0x40) == 0)) {
        *(undefined4 *)(pmove + 0x8c) = 0x447a0000;
        *(undefined4 *)(pmove + 0x90) = 1;
      }
      fVar4 = 1.0 - *(float *)(pmove + 0x8c) * 0.001;
      if (fVar4 < 0.0) {
        fVar4 = 0.0;
      }
      if (*(int *)(pmove + 0x90) == 0) {
        return;
      }
      if ((0.6 < *(float *)(pmove + 0x8c) * 0.001) && (*(int *)(pmove + 0xe0) != -1)) {
        fVar4 = fVar4 * 2.5;
        fVar5 = fVar4 * fVar4;
        fVar4 = fVar5 * 3.0 - (fVar5 + fVar5) * fVar4;
        *(float *)(pmove + 0x88) = fVar4 * -6.0 + (1.0 - fVar4) * 28.0;
        return;
      }
      *(undefined4 *)(pmove + 0xbc) = 1;
      *(undefined4 *)(pmove + 0x88) = 0x41400000;
      *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) | 0x40;
      *(undefined4 *)(pmove + 0x90) = 0;
      if (*(int *)(pmove + 0xe0) == -1) {
        return;
      }
      iVar7 = 0;
      do {
        iVar1 = iVar7 * 4;
        iVar7 = iVar7 + 1;
        *(float *)(iVar1 + pmove + 0x38) =
             *(float *)(iVar1 + pmove + 0x38) -
             (*(float *)(iVar1 + 0x4f500 + pmove) - *(float *)(iVar1 + 0x4f4f4 + pmove));
      } while (iVar7 < 3);
      PM_FixPlayerCrouchStuck(1);
      PM_CatagorizePosition();
      return;
    }
    if (*(int *)(pmove + 0x90) != 0) {
      PM_UnDuck();
      return;
    }
  }
  if ((*(byte *)(pmove + 0xb9) & 0x40) == 0) {
    return;
  }
  FUN_00136624();
  return;
}


// PM_FindTextureType  @ 00138bec
int PM_FindTextureType(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
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
  return (int)*(char *)((int)&grgchTextureType + iVar2);
}


// PM_FixPlayerCrouchStuck  @ 0013619c
void PM_FixPlayerCrouchStuck(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ca].r_offset + pmove))(pmove + 0x38,0);
  if (iVar4 != -1) {
    uVar1 = *(undefined4 *)(pmove + 0x38);
    uVar2 = *(undefined4 *)(pmove + 0x3c);
    uVar3 = *(undefined4 *)(pmove + 0x40);
    iVar4 = 0;
    do {
      *(float *)(pmove + 0x40) = (float)param_1 + *(float *)(pmove + 0x40);
      iVar5 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ca].r_offset + pmove))(pmove + 0x38,0);
      if (iVar5 == -1) {
        return;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x24);
    *(undefined4 *)(pmove + 0x38) = uVar1;
    *(undefined4 *)(pmove + 0x3c) = uVar2;
    *(undefined4 *)(pmove + 0x40) = uVar3;
  }
  return;
}


// PM_FixupGravityVelocity  @ 00138f4c
void PM_FixupGravityVelocity(void)

{
  float fVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = *(float *)(pmove + 0xc0);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar1 = 1.0;
    }
    *(float *)(pmove + 100) =
         *(float *)(pmove + 100) -
         fVar1 * **(float **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) *
         *(float *)(pmove + 0x10) * 0.5;
    PM_CheckVelocity();
  }
  return;
}


// PM_FlyMove  @ 00133e3c
uint PM_FlyMove(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  code *pcVar6;
  float fVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int aiStack_198 [2];
  float local_190;
  int aiStack_18c [5];
  int local_168;
  uint uVar14;
  float local_11c;
  float local_118;
  int local_114;
  int local_110;
  int local_108 [12];
  int local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  float local_c0 [3];
  int local_b4 [4];
  float local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_70 [4];
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
  
  puVar9 = &stack0xfffffe88;
  uVar14 = 0;
  local_114 = 0;
  local_70[3] = *(float *)(pmove + 0x5c);
  local_60 = *(float *)(pmove + 0x60);
  local_5c = *(float *)(pmove + 100);
  local_58 = *(float *)(pmove + 0x5c);
  local_54 = *(float *)(pmove + 0x60);
  local_11c = 0.0;
  local_50 = *(float *)(pmove + 100);
  local_110 = 0;
  local_118 = *(float *)(pmove + 0x10);
  do {
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0x5c)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(pmove + 0x5c) == 0.0) << 0xe) >> 8)) == 0x40) &&
        ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0x60)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(pmove + 0x60) == 0.0) << 0xe) >> 8)) == 0x40)) &&
       (fVar1 = *(float *)(pmove + 100),
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) goto LAB_00134669;
    iVar8 = 0;
    do {
      iVar10 = iVar8 + 1;
      local_c0[iVar8] =
           local_118 * *(float *)(iVar8 * 4 + 0x5c + pmove) + *(float *)(iVar8 * 4 + 0x38 + pmove);
      iVar8 = iVar10;
    } while (iVar10 < 3);
    *(undefined4 *)(puVar9 + -4) = 0xffffffff;
    *(undefined4 *)(puVar9 + -8) = 0;
    *(float **)(puVar9 + -0xc) = local_c0;
    *(int *)(puVar9 + -0x10) = pmove + 0x38;
    *(int **)(puVar9 + -0x14) = local_b4;
    pcVar6 = *(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove);
    *(undefined4 *)(puVar9 + -0x18) = 0x133f7e;
    (*pcVar6)();
    local_11c = local_11c + local_a4;
    if (local_b4[0] != 0) {
      *(undefined4 *)(pmove + 0x5c) = vec3_origin;
      *(undefined4 *)(pmove + 0x60) = DAT_0017548c;
      *(undefined4 *)(pmove + 100) = DAT_00175490;
      return 4;
    }
    if (0.0 < local_a4) {
      *(undefined4 *)(pmove + 0x38) = local_a0;
      *(undefined4 *)(pmove + 0x3c) = local_9c;
      *(undefined4 *)(pmove + 0x40) = local_98;
      local_70[3] = *(float *)(pmove + 0x5c);
      local_60 = *(float *)(pmove + 0x60);
      local_114 = 0;
      local_5c = *(float *)(pmove + 100);
    }
    if ((byte)(1.0 < local_a4 | (byte)((ushort)((ushort)NAN(local_a4) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_a4 == 1.0) << 0xe) >> 8)) == 0x40) goto LAB_00134669;
    piVar11 = local_b4;
    piVar12 = local_108;
    for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
      *piVar12 = *piVar11;
      piVar11 = piVar11 + 1;
      piVar12 = piVar12 + 1;
    }
    iVar8 = 0;
    if (0 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
      do {
        if (*(int *)("__vt_12CTriggerPush" + iVar8 * 0x44 + pmove + 2) == local_d8) break;
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc));
    }
    if (iVar8 == *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
      local_d4 = *(undefined4 *)(pmove + 0x5c);
      local_d0 = *(undefined4 *)(pmove + 0x60);
      local_cc = *(undefined4 *)(pmove + 100);
      if (599 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
        *(char **)(puVar9 + -8) = "Too many entities were touched!\n";
        pcVar6 = *(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_offset + pmove);
        *(undefined4 *)(puVar9 + -0xc) = 0x134146;
        (*pcVar6)();
      }
      iVar8 = pmove;
      piVar11 = local_108;
      piVar12 = (int *)("__vt_12CChangeLevel" +
                       (*(int *)("__vt_12CChangeLevel" + pmove + 0xc) * 0x10 +
                       *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) * 4 + pmove + 0x10);
      for (iVar10 = 0x11; iVar10 != 0; iVar10 = iVar10 + -1) {
        *piVar12 = *piVar11;
        piVar11 = piVar11 + 1;
        piVar12 = piVar12 + 1;
      }
      *(int *)("__vt_12CChangeLevel" + iVar8 + 0xc) =
           *(int *)("__vt_12CChangeLevel" + iVar8 + 0xc) + 1;
    }
    if (0.7 < local_8c) {
      uVar14 = uVar14 | 1;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_8c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_8c == 0.0) << 0xe) >> 8)) == 0x40) {
      uVar14 = uVar14 | 2;
    }
    local_118 = local_118 - local_118 * local_a4;
    if (4 < local_114) {
LAB_0013461e:
      *(undefined4 *)(pmove + 0x5c) = vec3_origin;
      *(undefined4 *)(pmove + 0x60) = DAT_0017548c;
      *(undefined4 *)(pmove + 100) = DAT_00175490;
      goto LAB_00134669;
    }
    local_4c[local_114 * 3] = local_94;
    local_4c[local_114 * 3 + 1] = local_90;
    local_4c[local_114 * 3 + 2] = local_8c;
    local_114 = local_114 + 1;
    if ((*(int *)(pmove + 0xdc) == 3) &&
       ((*(int *)(pmove + 0xe0) == -1 ||
        (fVar1 = *(float *)(pmove + 0xc4),
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)))) {
      if (0 < local_114) {
        iVar8 = 0;
        do {
          if (local_4c[iVar8 * 3 + 2] <= 0.7) {
            fVar1 = *(float *)(pmove + 0xc4);
            fVar2 = *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x2c
                              );
            fVar3 = local_4c[iVar8 * 3];
            fVar4 = local_4c[iVar8 * 3 + 1];
            fVar5 = local_4c[iVar8 * 3 + 2];
            iVar10 = 0;
            do {
              fVar7 = local_70[iVar10 + 3] -
                      (local_4c + iVar8 * 3)[iVar10] *
                      (local_5c * fVar5 + local_60 * fVar4 + local_70[3] * fVar3) *
                      ((1.0 - fVar1) * fVar2 + 1.0);
              local_70[iVar10] = fVar7;
              if ((0x3f < (byte)((fVar7 < -0.1 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
                                 (byte)((ushort)((ushort)(fVar7 == -0.1) << 0xe) >> 8)) - 1)) &&
                 (fVar7 < 0.1)) {
                local_70[iVar10] = 0.0;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < 3);
          }
          else {
            fVar1 = local_4c[iVar8 * 3];
            fVar2 = local_4c[iVar8 * 3 + 1];
            iVar10 = 0;
            fVar3 = local_4c[iVar8 * 3 + 2];
            do {
              fVar4 = local_70[iVar10 + 3] -
                      (local_4c + iVar8 * 3)[iVar10] *
                      (local_5c * fVar3 + local_60 * fVar2 + local_70[3] * fVar1);
              local_70[iVar10] = fVar4;
              if ((0x3f < (byte)((fVar4 < -0.1 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                                 (byte)((ushort)((ushort)(fVar4 == -0.1) << 0xe) >> 8)) - 1)) &&
                 (fVar4 < 0.1)) {
                local_70[iVar10] = 0.0;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < 3);
            local_70[3] = local_70[0];
            local_60 = local_70[1];
            local_5c = local_70[2];
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < local_114);
      }
      *(float *)(pmove + 0x5c) = local_70[0];
      *(float *)(pmove + 0x60) = local_70[1];
      *(float *)(pmove + 100) = local_70[2];
      local_70[3] = local_70[0];
      local_60 = local_70[1];
      local_5c = local_70[2];
      uVar14 = FUN_00134654();
      return uVar14;
    }
    iVar8 = 0;
    if (0 < local_114) {
      do {
        iVar10 = pmove + 0x5c;
        fVar1 = local_4c[iVar8 * 3];
        fVar2 = local_4c[iVar8 * 3 + 1];
        iVar13 = 0;
        fVar3 = local_4c[iVar8 * 3 + 2];
        do {
          fVar4 = local_70[iVar13 + 3] -
                  (local_4c + iVar8 * 3)[iVar13] *
                  (local_5c * fVar3 + local_60 * fVar2 + local_70[3] * fVar1);
          *(float *)(iVar10 + iVar13 * 4) = fVar4;
          if ((0x3f < (byte)((fVar4 < -0.1 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar4 == -0.1) << 0xe) >> 8)) - 1)) &&
             (fVar4 < 0.1)) {
            *(undefined4 *)(iVar10 + iVar13 * 4) = 0;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < 3);
        local_168 = 0;
        if (0 < local_114) {
          do {
            if ((local_168 != iVar8) &&
               (fVar1 = *(float *)(pmove + 100) * local_4c[local_168 * 3 + 2] +
                        *(float *)(pmove + 0x60) * local_4c[local_168 * 3 + 1] +
                        *(float *)(pmove + 0x5c) * local_4c[local_168 * 3],
               (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) break;
            local_168 = local_168 + 1;
          } while (local_168 < local_114);
        }
      } while ((local_168 != local_114) && (iVar8 = iVar8 + 1, iVar8 < local_114));
    }
    if (iVar8 == local_114) {
      if (local_114 != 2) goto LAB_0013461e;
      *(float **)(puVar9 + -8) = &local_10;
      *(undefined1 **)(puVar9 + -0xc) = local_40;
      *(float **)(puVar9 + -0x10) = local_4c;
      *(undefined4 *)(puVar9 + -0x14) = 0x1345ba;
      CrossProduct();
      fVar1 = *(float *)(pmove + 0x5c);
      fVar2 = *(float *)(pmove + 0x60);
      fVar3 = *(float *)(pmove + 100);
      *(int *)(puVar9 + -0x14) = pmove + 0x5c;
      *(float *)(puVar9 + -0x18) = local_8 * fVar3 + local_c * fVar2 + local_10 * fVar1;
      *(float **)(puVar9 + -0x1c) = &local_10;
      *(undefined4 *)(puVar9 + -0x20) = 0x1345ec;
      VectorScale();
    }
    puVar9 = puVar9 + -4;
    if (*(float *)(pmove + 100) * local_50 +
        *(float *)(pmove + 0x60) * local_54 + *(float *)(pmove + 0x5c) * local_58 <= 0.0)
    goto LAB_0013461e;
    local_110 = local_110 + 1;
    if (3 < local_110) {
LAB_00134669:
      if ((byte)((byte)((ushort)((ushort)NAN(local_11c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_11c == 0.0) << 0xe) >> 8)) == 0x40) {
        *(undefined4 *)(pmove + 0x5c) = vec3_origin;
        *(undefined4 *)(pmove + 0x60) = DAT_0017548c;
        *(undefined4 *)(pmove + 100) = DAT_00175490;
      }
      return uVar14;
    }
  } while( true );
}


// PM_Friction  @ 00134d10
void PM_Friction(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  float local_74;
  undefined1 auStack_70 [16];
  float fStack_60;
  float local_2c;
  float local_28;
  float fStack_24;
  float local_20;
  float local_1c;
  float fStack_18;
  float local_14;
  
  iVar7 = pmove;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40) {
    pfVar1 = (float *)(pmove + 0x5c);
    fVar3 = SQRT(*(float *)(pmove + 100) * *(float *)(pmove + 100) +
                 *(float *)(pmove + 0x60) * *(float *)(pmove + 0x60) +
                 *(float *)(pmove + 0x5c) * *(float *)(pmove + 0x5c));
    if (0.1 <= fVar3) {
      local_74 = 0.0;
      if (*(int *)(pmove + 0xe0) != -1) {
        local_2c = (*(float *)(pmove + 0x5c) / fVar3) * 16.0 + *(float *)(pmove + 0x38);
        local_28 = (*(float *)(pmove + 0x60) / fVar3) * 16.0 + *(float *)(pmove + 0x3c);
        fStack_18 = *(float *)(pmove + 0x40) +
                    *(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc);
        fStack_24 = fStack_18 - 34.0;
        local_20 = local_2c;
        local_1c = local_28;
        local_14 = fVar3;
        (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
                  (auStack_70,&local_20,&local_2c,0,0xffffffff);
        if ((byte)((byte)((ushort)((ushort)NAN(fStack_60) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_60 == 1.0) << 0xe) >> 8)) == 0x40) {
          iVar5 = *(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove);
          fVar4 = *(float *)(iVar5 + 0x1c) * *(float *)(iVar5 + 0x20);
        }
        else {
          fVar4 = *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x1c);
        }
        fVar2 = *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 4);
        fVar6 = fVar3;
        if (0x3f < (byte)((fVar2 < fVar3 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
          fVar6 = fVar2;
        }
        local_74 = fVar4 * *(float *)(pmove + 0xc4) * fVar6 * *(float *)(pmove + 0x10) + 0.0;
      }
      local_74 = fVar3 - local_74;
      if (0x3f < (byte)((0.0 < local_74 | (byte)((ushort)((ushort)NAN(local_74) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_74 == 0.0) << 0xe) >> 8)) - 1)) {
        local_74 = 0.0;
      }
      local_74 = local_74 / fVar3;
      fVar3 = *(float *)(iVar7 + 0x60);
      fVar4 = *(float *)(iVar7 + 100);
      *(float *)(pmove + 0x5c) = *pfVar1 * local_74;
      *(float *)(pmove + 0x60) = fVar3 * local_74;
      *(float *)(pmove + 100) = fVar4 * local_74;
    }
  }
  return;
}


// PM_GetPhysEntInfo  @ 001394f0
undefined4 PM_GetPhysEntInfo(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (*(int *)(pmove + 0x24c) < param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 * 0xe0 + 0x2a0 + pmove);
  }
  return uVar1;
}


// PM_GetRandomStuckOffsets  @ 0013919c
int PM_GetRandomStuckOffsets(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2 * 4 + param_1 * 8;
  iVar2 = *(int *)(rgStuckLast + iVar1);
  *(int *)(rgStuckLast + iVar1) = *(int *)(rgStuckLast + iVar1) + 1;
  iVar2 = iVar2 % 0x36;
  *param_3 = (&rgv3tStuckTable)[iVar2 * 3];
  param_3[1] = (&DAT_001ad684)[iVar2 * 3];
  param_3[2] = (&DAT_001ad688)[iVar2 * 3];
  return iVar2;
}


// PM_GetVisEntInfo  @ 001394a8
undefined4 PM_GetVisEntInfo(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (*(int *)((int)&__DT_SYMTAB[0xba2].st_value + pmove) < param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 * 0xe0 + 0x247a8 + pmove);
  }
  return uVar1;
}


// PM_InWater  @ 0013916c
bool PM_InWater(void)

{
  return 1 < *(int *)(pmove + 0xe4);
}


// PM_Init  @ 00138b3c
void PM_Init(undefined4 param_1)

{
  pmove = param_1;
  PM_CreateStuckTable();
  PM_InitTextureTypes();
  pm_shared_initialized = 1;
  return;
}


// PM_InitTextureTypes  @ 00132bd8
void PM_InitTextureTypes(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 local_208;
  char local_204 [512];
  
  if (bTextureTypeInit_98 == 0) {
    puVar8 = &grgszTextureName;
    for (iVar7 = 0x680; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    puVar8 = &grgchTextureType;
    for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    gcTextures = 0;
    pcVar9 = local_204;
    for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
      pcVar9[0] = '\0';
      pcVar9[1] = '\0';
      pcVar9[2] = '\0';
      pcVar9[3] = '\0';
      pcVar9 = pcVar9 + 4;
    }
    uVar4 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d2].r_info + pmove))
                      ("sound/materials.txt");
    iVar7 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d3].r_offset + pmove))
                      ("sound/materials.txt",5,0);
    if (iVar7 != 0) {
      local_208 = 0;
LAB_00132e29:
      do {
        do {
          do {
            do {
              do {
                iVar6 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d4].r_offset + pmove))
                                  (iVar7,uVar4,&local_208,local_204,0x1ff);
                if ((iVar6 == 0) || (0x1ff < gcTextures)) {
                  (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d3].r_info + pmove))(iVar7);
                  PM_SortTextures();
                  bTextureTypeInit_98 = 1;
                  return;
                }
                iVar6 = 0;
              } while (local_204[0] == '\0');
              do {
                if ((*(byte *)(__ctype_b + 1 + local_204[iVar6] * 2) & 0x20) == 0) break;
                iVar6 = iVar6 + 1;
              } while (local_204[iVar6] != '\0');
              cVar2 = local_204[iVar6];
            } while (((cVar2 == '\0') || (cVar2 == '/')) ||
                    ((*(byte *)(__ctype_b + 1 + cVar2 * 2) & 4) == 0));
            iVar6 = iVar6 + 1;
            *(undefined1 *)((int)&grgchTextureType + gcTextures) =
                 *(undefined1 *)(__ctype_toupper + cVar2 * 4);
          } while (local_204[iVar6] == '\0');
          do {
            if ((*(byte *)(__ctype_b + 1 + local_204[iVar6] * 2) & 0x20) == 0) break;
            iVar6 = iVar6 + 1;
          } while (local_204[iVar6] != '\0');
        } while (local_204[iVar6] == '\0');
        bVar3 = *(byte *)(__ctype_b + 1 + local_204[iVar6] * 2);
        iVar1 = iVar6;
        while ((bVar3 & 0x20) == 0) {
          iVar1 = iVar1 + 1;
          if (local_204[iVar1] == '\0') goto LAB_00132e29;
          bVar3 = *(byte *)(__ctype_b + 1 + local_204[iVar1] * 2);
        }
        if (local_204[iVar1] != '\0') {
          iVar5 = iVar6 + 0xc;
          if (iVar1 < iVar6 + 0xc) {
            iVar5 = iVar1;
          }
          local_204[iVar5] = '\0';
          iVar1 = gcTextures * 0xd;
          gcTextures = gcTextures + 1;
          strcpy((char *)((int)&grgszTextureName + iVar1),local_204 + iVar6);
        }
      } while( true );
    }
  }
  return;
}


// PM_Jump  @ 001372a4
void PM_Jump(void)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  longdouble lVar6;
  longdouble lVar7;
  
  if (*(int *)(pmove + 0xd0) != 0) {
LAB_001374bf:
    *(byte *)(pmove + 200) = *(byte *)(pmove + 200) | 2;
    switchD_00137416::default();
    return;
  }
  uVar3 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6c9].r_offset + pmove))
                    (pmove + 0x4f3f0,&DAT_0015bd20);
  iVar4 = __strtol_internal(uVar3,0,10,0);
  if ((iVar4 != 1) || (*(int *)(pmove + 0xd4) != 5)) {
    lVar7 = (longdouble)0;
    lVar6 = (longdouble)*(float *)(pmove + 0xcc);
    if ((byte)(lVar6 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar7)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar6 == lVar7) << 0xe) >> 8)) == 0x40) {
      if (*(int *)(pmove + 0xe4) < 2) {
        if (*(int *)(pmove + 0xe0) == -1) goto LAB_001374bf;
        if ((*(byte *)(pmove + 200) & 2) == 0) {
          *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
          lVar6 = (longdouble)*(float *)(pmove + 500) * (longdouble)1.7;
          if ((0x3f < (byte)((lVar6 < lVar7 |
                              (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar7)) << 10) >> 8) |
                             (byte)((ushort)((ushort)(lVar6 == lVar7) << 0xe) >> 8)) - 1)) &&
             (lVar7 = (longdouble)Length(pmove + 0x5c), lVar6 < lVar7)) {
            VectorScale(pmove + 0x5c,(float)((longdouble)0.65 * (lVar6 / lVar7)),pmove + 0x5c);
          }
          if (iVar4 == 1) {
            (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d5].r_offset + pmove))
                      (4,"player/plyrjmp8.wav",0x3f000000,0x3f4ccccd,0,100);
          }
          else {
            switch(*(undefined1 *)(pmove + 0x1f0)) {
            default:
              uVar3 = 0;
              break;
            case 0x44:
              uVar3 = 2;
              break;
            case 0x47:
              uVar3 = 4;
              break;
            case 0x4d:
              uVar3 = 1;
              break;
            case 0x53:
              uVar3 = 6;
              break;
            case 0x54:
              uVar3 = 5;
              break;
            case 0x56:
              uVar3 = 3;
            }
            PM_PlayStepSound(uVar3,0x3f800000);
          }
          uVar3 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6c9].r_offset + pmove))
                            (pmove + 0x4f3f0,&DAT_0015bd38);
          iVar4 = __strtol_internal(uVar3,0,10,0);
          if ((*(int *)(pmove + 0x90) == 0) && ((*(byte *)(pmove + 0xb9) & 0x40) == 0)) {
            *(undefined4 *)(pmove + 100) = 0x43862a01;
          }
          else {
            if ((iVar4 != 1) ||
               (((("__12CChangeLevel"[pmove + 7] & 4U) == 0 || (*(float *)(pmove + 0x8c) <= 0.0)) ||
                (lVar7 = (longdouble)Length(pmove + 0x5c), lVar7 <= (longdouble)50.0)))) {
              fVar2 = 72000.0;
            }
            else {
              iVar4 = 0;
              *(undefined4 *)(pmove + 0xa0) = 0xc0a00000;
              do {
                iVar1 = iVar4 * 4;
                iVar4 = iVar4 + 1;
                *(float *)(iVar1 + 0x5c + pmove) = *(float *)(iVar1 + 0x14 + pmove) * 350.0 * 1.6;
              } while (iVar4 < 2);
              fVar2 = 89600.0;
            }
            *(float *)(pmove + 100) = SQRT(fVar2);
          }
          if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40
             ) {
            fVar2 = *(float *)(pmove + 0xc0);
            if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
              fVar2 = 1.0;
            }
            *(float *)(pmove + 100) =
                 *(float *)(pmove + 100) -
                 fVar2 * **(float **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) *
                 *(float *)(pmove + 0x10) * 0.5;
            PM_CheckVelocity();
          }
          *(byte *)(pmove + 200) = *(byte *)(pmove + 200) | 2;
          switchD_00137416::default();
          return;
        }
      }
      else {
        *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
        if (*(int *)(pmove + 0xe8) == -3) {
          *(undefined4 *)(pmove + 100) = 0x42c80000;
        }
        else if (*(int *)(pmove + 0xe8) == -4) {
          *(undefined4 *)(pmove + 100) = 0x42a00000;
        }
        else {
          *(undefined4 *)(pmove + 100) = 0x42480000;
        }
        fVar2 = *(float *)(pmove + 0xac);
        if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
          *(undefined4 *)(pmove + 0xac) = 0x447a0000;
          uVar3 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cf].r_info + pmove))(0,3);
          switch(uVar3) {
          case 0:
            pcVar5 = "player/pl_wade1.wav";
            break;
          case 1:
            pcVar5 = "player/pl_wade2.wav";
            break;
          case 2:
            pcVar5 = "player/pl_wade3.wav";
            break;
          case 3:
            pcVar5 = "player/pl_wade4.wav";
            break;
          default:
            goto code_r0x001377d4;
          }
          (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d5].r_offset + pmove))
                    (4,pcVar5,0x3f800000,0x3f4ccccd,0,100);
          switchD_00137416::default();
          return;
        }
      }
    }
    else {
      *(float *)(pmove + 0xcc) =
           (float)(lVar6 - (longdouble)(byte)"__vt_14CTriggerVolume"[pmove + 0x14]);
      lVar6 = (longdouble)*(float *)(pmove + 0xcc);
      if (0x3f < (byte)((lVar7 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) - 1)) {
        *(float *)(pmove + 0xcc) = (float)lVar7;
        switchD_00137416::default();
        return;
      }
    }
  }
code_r0x001377d4:
  return;
}


// PM_Ladder  @ 001369f8
int PM_Ladder(void)

{
  int iVar1;
  int iVar2;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_14 = 0;
  if (0 < *(int *)((int)&__DT_SYMTAB[0x822].st_name + pmove)) {
    do {
      iVar1 = pmove + 0x20f54 + local_14 * 0xe0;
      if (((*(int *)(iVar1 + 0x30) != 0) &&
          (iVar2 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d0].r_info + pmove))
                             (*(int *)(iVar1 + 0x30)), iVar2 == 0)) &&
         (*(int *)(iVar1 + 100) == -0x10)) {
        iVar2 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d1].r_info + pmove))(iVar1,&local_10)
        ;
        local_10 = *(float *)(pmove + 0x38) - local_10;
        local_c = *(float *)(pmove + 0x3c) - local_c;
        local_8 = *(float *)(pmove + 0x40) - local_8;
        iVar2 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_offset + pmove))
                          (iVar2,*(undefined4 *)(iVar2 + 8),&local_10);
        if (iVar2 != -1) {
          return iVar1;
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)((int)&__DT_SYMTAB[0x822].st_name + pmove));
  }
  return 0;
}


// PM_LadderMove  @ 00136638
void PM_LadderMove(int param_1)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  float fStack_c8;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  undefined1 auStack_9c [12];
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  undefined1 auStack_84 [12];
  undefined1 auStack_78 [12];
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  undefined1 auStack_48 [16];
  float fStack_38;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (*(int *)(pmove + 0xdc) != 8) {
    (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d1].r_offset + pmove))
              (*(undefined4 *)(param_1 + 0x30),&fStack_60,&fStack_6c);
    fStack_10 = fStack_60 + fStack_6c;
    fStack_c = fStack_5c + fStack_68;
    fStack_8 = fStack_58 + fStack_64;
    VectorScale(&fStack_10,0x3f000000,&fStack_10);
    *(undefined4 *)(pmove + 0xdc) = 5;
    uStack_54 = *(undefined4 *)(pmove + 0x38);
    uStack_50 = *(undefined4 *)(pmove + 0x3c);
    fStack_4c = (*(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc) - 1.0) +
                *(float *)(pmove + 0x40);
    iVar3 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cd].r_offset + pmove))(&uStack_54,0);
    *(undefined4 *)(pmove + 0xc0) = 0;
    (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d2].r_offset + pmove))
              (param_1,pmove + 0x38,&fStack_10,auStack_48);
    if ((byte)(1.0 < fStack_38 | (byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_38 == 1.0) << 0xe) >> 8)) != 0x40) {
      fStack_c8 = 0.0;
      AngleVectors(pmove + 0x44,auStack_78,auStack_84,0);
      uVar2 = *(ushort *)("__12CChangeLevel" + pmove + 7);
      fVar1 = fStack_c8;
      if ((uVar2 & 0x10) != 0) {
        fVar1 = -200.0;
      }
      if ((uVar2 & 8) != 0) {
        fVar1 = fVar1 + 200.0;
      }
      if ((uVar2 & 0x200) != 0) {
        fStack_c8 = -200.0;
      }
      if ((uVar2 & 0x400) != 0) {
        fStack_c8 = fStack_c8 + 200.0;
      }
      if ((uVar2 & 2) == 0) {
        if (((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) &&
           ((byte)(fStack_c8 < 0.0 | (byte)((ushort)((ushort)NAN(fStack_c8) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_c8 == 0.0) << 0xe) >> 8)) == 0x40)) {
          *(undefined4 *)(pmove + 0x5c) = 0;
          *(undefined4 *)(pmove + 0x60) = 0;
          *(undefined4 *)(pmove + 100) = 0;
        }
        else {
          VectorScale(auStack_78,fVar1,&fStack_90);
          VectorMA(&fStack_90,fStack_c8,auStack_84,&fStack_90);
          uStack_c0 = 0;
          uStack_bc = 0;
          uStack_b8 = 0x3f800000;
          CrossProduct(&uStack_c0,&fStack_28,auStack_9c);
          VectorNormalize(auStack_9c);
          fVar1 = fStack_88 * fStack_20 + fStack_8c * fStack_24 + fStack_90 * fStack_28;
          VectorScale(&fStack_28,fVar1,&fStack_a8);
          fStack_b4 = fStack_90 - fStack_a8;
          fStack_b0 = fStack_8c - fStack_a4;
          fStack_ac = fStack_88 - fStack_a0;
          CrossProduct(&fStack_28,auStack_9c,&uStack_c0);
          VectorMA(&fStack_b4,-fVar1,&uStack_c0,pmove + 0x5c);
          if ((iVar3 == -2) &&
             (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
            VectorMA(pmove + 0x5c,0x43480000,&fStack_28,pmove + 0x5c);
          }
        }
      }
      else {
        *(undefined4 *)(pmove + 0xdc) = 3;
        VectorScale(&fStack_28,0x43870000,pmove + 0x5c);
      }
    }
  }
  return;
}


// PM_MapTextureTypeStepType  @ 00138d0c
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


// PM_Move  @ 00138b74
void PM_Move(int param_1,int param_2)

{
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


// PM_NoClip  @ 001371b4
void PM_NoClip(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_10 [3];
  
  fVar1 = *(float *)("__vt_11CFireAndDie" + pmove + 0xc);
  fVar2 = *(float *)("__vt_11CFireAndDie" + pmove + 0x10);
  VectorNormalize(pmove + 0x14);
  VectorNormalize(pmove + 0x20);
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 1;
    local_10[iVar3] =
         fVar2 * *(float *)(iVar3 * 4 + 0x20 + pmove) + fVar1 * *(float *)(iVar3 * 4 + 0x14 + pmove)
    ;
    iVar3 = iVar4;
  } while (iVar4 < 3);
  local_10[2] = local_10[2] + *(float *)("__12CChangeLevel" + pmove + 1);
  VectorMA(pmove + 0x38,*(undefined4 *)(pmove + 0x10),local_10,pmove + 0x38);
  *(undefined4 *)(pmove + 0x5c) = 0;
  *(undefined4 *)(pmove + 0x60) = 0;
  *(undefined4 *)(pmove + 100) = 0;
  return;
}


// PM_ParticleLine  @ 0013a9d8
void PM_ParticleLine(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4,
                    float param_5)

{
  longdouble lVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_1c [6];
  
  local_1c[0] = *param_2 - *param_1;
  local_1c[1] = param_2[1] - param_1[1];
  local_1c[2] = param_2[2] - param_1[2];
  lVar4 = (longdouble)VectorNormalize(local_1c);
  lVar5 = (longdouble)0;
  if (lVar5 <= lVar4) {
    do {
      iVar2 = 0;
      do {
        iVar3 = iVar2 + 1;
        (local_1c + 3)[iVar2] =
             (float)(lVar5 * (longdouble)local_1c[iVar2] + (longdouble)param_1[iVar2]);
        iVar2 = iVar3;
      } while (iVar3 < 3);
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6c9].r_info + pmove))
                (local_1c + 3,param_3,param_4,0,(int)ROUND(param_5));
      lVar5 = lVar5 + (longdouble)2.0;
      lVar1 = (longdouble)(float)lVar4;
    } while ((byte)((lVar5 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar1) << 0xe) >> 8)) - 1) < 0x40);
  }
  return;
}


// PM_Physics_Toss  @ 00136da0
void PM_Physics_Toss(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 **ppuVar7;
  undefined4 **ppuVar8;
  undefined4 *local_7c;
  undefined4 *puStack_78;
  int local_68;
  undefined4 local_54 [3];
  int local_48 [4];
  float local_38;
  float local_28 [4];
  undefined4 local_18;
  
  puStack_78 = (undefined4 *)0x136dba;
  PM_CheckWater();
  if (0.0 < *(float *)(pmove + 100)) {
    *(undefined4 *)(pmove + 0xe0) = 0xffffffff;
  }
  if (*(int *)(pmove + 0xe0) != -1) {
    puStack_78 = &vec3_origin;
    local_7c = (undefined4 *)(pmove + 0x74);
    iVar6 = VectorCompare();
    if (iVar6 != 0) {
      puStack_78 = &vec3_origin;
      local_7c = (undefined4 *)(pmove + 0x5c);
      iVar6 = VectorCompare();
      if (iVar6 != 0) {
        return;
      }
    }
  }
  puStack_78 = (undefined4 *)0x136e22;
  PM_CheckVelocity();
  iVar6 = *(int *)(pmove + 0xdc);
  if (((iVar6 != 5) && (iVar6 != 0xb)) && (iVar6 != 9)) {
    fVar1 = *(float *)(pmove + 0xc0);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar1 = 1.0;
    }
    *(float *)(pmove + 100) =
         *(float *)(pmove + 100) -
         fVar1 * **(float **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) *
         *(float *)(pmove + 0x10);
    *(float *)(pmove + 100) =
         *(float *)(pmove + 0x7c) * *(float *)(pmove + 0x10) + *(float *)(pmove + 100);
    *(undefined4 *)(pmove + 0x7c) = 0;
    puStack_78 = (undefined4 *)0x136e9c;
    PM_CheckVelocity();
  }
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) + *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) + *(float *)(pmove + 0x7c);
  puStack_78 = (undefined4 *)0x136ed4;
  PM_CheckVelocity();
  local_7c = *(undefined4 **)(pmove + 0x10);
  puStack_78 = local_54;
  VectorScale(pmove + 0x5c);
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) - *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) - *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) - *(float *)(pmove + 0x7c);
  PM_PushEntity(local_48,local_54);
  PM_CheckVelocity();
  ppuVar8 = &puStack_78;
  ppuVar7 = &puStack_78;
  if (local_48[0] == 0) {
    if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
      if (*(int *)(pmove + 0xdc) == 10) {
        fVar1 = 2.0 - *(float *)(pmove + 0xc4);
      }
      else {
        fVar1 = 2.0;
        if (*(int *)(pmove + 0xdc) != 0xb) {
          fVar1 = 1.0;
        }
      }
      iVar6 = pmove + 0x5c;
      fVar2 = *(float *)(pmove + 0x5c);
      fVar3 = *(float *)(pmove + 0x60);
      fVar4 = *(float *)(pmove + 100);
      local_68 = 0;
      do {
        fVar5 = *(float *)(iVar6 + local_68 * 4) -
                local_28[local_68] *
                (fVar4 * local_28[2] + fVar3 * local_28[1] + fVar2 * local_28[0]) * fVar1;
        *(float *)(iVar6 + local_68 * 4) = fVar5;
        if ((0x3f < (byte)((fVar5 < -0.1 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                           (byte)((ushort)((ushort)(fVar5 == -0.1) << 0xe) >> 8)) - 1)) &&
           (fVar5 < 0.1)) {
          *(undefined4 *)(iVar6 + local_68 * 4) = 0;
        }
        local_68 = local_68 + 1;
      } while (local_68 < 3);
      ppuVar8 = &puStack_78;
      if (0.7 < local_28[2]) {
        fVar2 = **(float **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) *
                *(float *)(pmove + 0x10);
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
          *(undefined4 *)(pmove + 0x60) = DAT_0017548c;
          *(undefined4 *)(pmove + 100) = DAT_00175490;
        }
        else {
          local_7c = local_54;
          VectorScale(pmove + 0x5c,(1.0 - local_38) * *(float *)(pmove + 0x10) * 0.9);
          PM_PushEntity(local_48,local_54);
          ppuVar7 = &local_7c;
        }
        *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) - 0.0;
        *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) - 0.0;
        *(float *)(pmove + 100) = *(float *)(pmove + 100) - 0.0;
        ppuVar8 = ppuVar7;
      }
    }
    *(undefined4 *)((int)ppuVar8 + -4) = 0x1371a8;
    PM_CheckWater();
  }
  else {
    *(undefined4 *)(pmove + 0xe0) = local_18;
    *(undefined4 *)(pmove + 0x5c) = vec3_origin;
    *(undefined4 *)(pmove + 0x60) = DAT_0017548c;
    *(undefined4 *)(pmove + 100) = DAT_00175490;
  }
  return;
}


// PM_PlayStepSound  @ 00132e98
void PM_PlayStepSound(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  longdouble lVar5;
  longdouble lVar6;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(uint *)(pmove + 0x98) = (uint)(*(int *)(pmove + 0x98) == 0);
  if (*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d4].r_info + pmove) == 0) {
    return;
  }
  iVar1 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cf].r_info + pmove))(0,1);
  iVar1 = iVar1 + *(int *)(pmove + 0x98) * 2;
  if ((*(int *)(pmove + 8) != 0) &&
     (*(int *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x40) == 0)) {
    return;
  }
  local_10 = *(undefined4 *)(pmove + 0x5c);
  local_c = *(undefined4 *)(pmove + 0x60);
  local_8 = 0;
  if ((*(int *)(pmove + 8) != 0) && (g_onladder == 0)) {
    lVar5 = (longdouble)Length(&local_10);
    lVar6 = (longdouble)220.0;
    if ((byte)((lVar5 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar6)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar5 == lVar6) << 0xe) >> 8)) - 1) < 0x40) {
      return;
    }
  }
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
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 3:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    default:
      goto switchD_00132fc2_default;
    }
    break;
  case 1:
    switch(iVar1) {
    case 0:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 1:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 2:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 3:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    default:
      return;
    }
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
      goto switchD_00132fc2_default;
    }
    break;
  case 3:
    switch(iVar1) {
    case 0:
      pcVar3 = "player/pl_duct1.wav";
      break;
    case 1:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 2:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 3:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    default:
      goto switchD_00132fc2_default;
    }
    break;
  case 4:
    switch(iVar1) {
    case 0:
      pcVar3 = "player/pl_grate1.wav";
      break;
    case 1:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 2:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 3:
      pcVar3 = "player/pl_grate4.wav";
      break;
    default:
      goto switchD_00132fc2_default;
    }
    break;
  case 5:
    iVar2 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cf].r_info + pmove))(0,4);
    if (iVar2 == 0) {
      iVar1 = 4;
    }
    switch(iVar1) {
    case 0:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 1:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 2:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 3:
      pcVar3 = "player/pl_tile4.wav";
      break;
    case 4:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    default:
      goto switchD_00132fc2_default;
    }
    break;
  case 6:
    switch(iVar1) {
    case 0:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 1:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 2:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 3:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    default:
      return;
    }
  case 7:
    if (iSkipStep_103 != 0) {
      bVar4 = iSkipStep_103 == 3;
      iSkipStep_103 = iSkipStep_103 + 1;
      if (bVar4) {
        iSkipStep_103 = 0;
      }
      switch(iVar1) {
      case 0:
        FUN_00133675(0x3f4ccccd,0,100);
        return;
      case 1:
        FUN_00133675(0x3f4ccccd,0,100);
        return;
      case 2:
        FUN_00133675(0x3f4ccccd,0,100);
        return;
      case 3:
        FUN_00133675(0x3f4ccccd,0,100);
        return;
      default:
        return;
      }
    }
    iSkipStep_103 = 1;
    return;
  case 8:
    switch(iVar1) {
    case 0:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 1:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 2:
      FUN_00133675(0x3f4ccccd,0,100);
      return;
    case 3:
      pcVar3 = "player/pl_ladder4.wav";
      break;
    default:
      goto switchD_00132fc2_default;
    }
  }
  (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d5].r_offset + pmove))
            (4,pcVar3,param_2,0x3f4ccccd,0,100);
switchD_00132fc2_default:
  return;
}


// PM_PlayWaterSounds  @ 00137cbc
void PM_PlayWaterSounds(void)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (*(int *)(pmove + 0xec) == 0) {
    if (*(int *)(pmove + 0xe4) == 0) {
      return;
    }
  }
  else if (*(int *)(pmove + 0xe4) != 0) {
    return;
  }
  uVar1 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cf].r_info + pmove))(0,3);
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
    goto switchD_00137d20_default;
  }
  (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6d5].r_offset + pmove))
            (4,pcVar2,0x3f800000,0x3f4ccccd,0,100);
switchD_00137d20_default:
  return;
}


// PM_PlayerMove  @ 001381d4
void PM_PlayerMove(undefined4 param_1)

{
  char *pcVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  *(undefined4 *)(pmove + 4) = param_1;
  PM_CheckParamters();
  pcVar1 = "__vt_12CChangeLevel" + pmove + 0xc;
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  *(float *)(pmove + 0x10) = (float)(byte)"__vt_14CTriggerVolume"[pmove + 0x14] * 0.001;
  PM_ReduceTimers();
  AngleVectors(pmove + 0x44,pmove + 0x14,pmove + 0x20,pmove + 0x2c);
  iVar4 = 0;
  if ((*(int *)(pmove + 0xd8) != 0) || (0 < *(int *)(pmove + 0x1fc))) {
    PM_SpectatorMove();
    PM_CatagorizePosition();
    switchD_001383b2::caseD_0();
    return;
  }
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
    if ((*(int *)(pmove + 0xe0) != -1) && (("__12CChangeLevel"[pmove + 7] & 0x20U) != 0)) {
      VectorScale(pmove + 0x5c,0x3e99999a,pmove + 0x5c);
    }
    switch(*(undefined4 *)(pmove + 0xdc)) {
    case 0:
      break;
    default:
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_offset + pmove))
                ("Bogus pmove player movetype %i on (%i) 0=cl 1=sv\n",*(undefined4 *)(pmove + 0xdc),
                 *(undefined4 *)(pmove + 4));
      switchD_001383b2::caseD_0();
      return;
    case 3:
      if (*(int *)(pmove + 0xe4) < 2) {
        PM_AddCorrectGravity();
      }
      fVar2 = *(float *)(pmove + 0xcc);
      if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
        PM_WaterJump();
        PM_FlyMove();
        PM_CheckWater();
        switchD_001383b2::caseD_0();
        return;
      }
      if (*(int *)(pmove + 0xe4) < 2) {
        if (("__12CChangeLevel"[pmove + 7] & 2U) == 0) {
          *(byte *)(pmove + 200) = *(byte *)(pmove + 200) & 0xfd;
        }
        else if (iVar4 == 0) {
          PM_Jump();
        }
        if (*(int *)(pmove + 0xe0) != -1) {
          *(undefined4 *)(pmove + 100) = 0;
          PM_Friction();
        }
        PM_CheckVelocity();
        if (*(int *)(pmove + 0xe0) == -1) {
          PM_AirMove();
        }
        else {
          func_0x000830d4();
        }
        PM_CatagorizePosition();
        *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) - *(float *)(pmove + 0x74);
        *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) - *(float *)(pmove + 0x78);
        *(float *)(pmove + 100) = *(float *)(pmove + 100) - *(float *)(pmove + 0x7c);
        PM_CheckVelocity();
        if ((*(int *)(pmove + 0xe4) < 2) &&
           ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40))
        {
          fVar2 = *(float *)(pmove + 0xc0);
          if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
            fVar2 = 1.0;
          }
          *(float *)(pmove + 100) =
               *(float *)(pmove + 100) -
               fVar2 * **(float **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) *
               *(float *)(pmove + 0x10) * 0.5;
          PM_CheckVelocity();
        }
        if (*(int *)(pmove + 0xe0) != -1) {
          *(undefined4 *)(pmove + 100) = 0;
        }
        PM_CheckFalling();
      }
      else {
        if (*(int *)(pmove + 0xe4) == 2) {
          PM_CheckWaterJump();
        }
        if ((*(float *)(pmove + 100) < 0.0) &&
           (fVar2 = *(float *)(pmove + 0xcc),
           (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
          *(undefined4 *)(pmove + 0xcc) = 0;
        }
        if (("__12CChangeLevel"[pmove + 7] & 2U) == 0) {
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
      break;
    case 5:
      PM_CheckWater();
      if (("__12CChangeLevel"[pmove + 7] & 2U) == 0) {
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
      switchD_001383b2::caseD_0();
      return;
    case 6:
    case 10:
      PM_Physics_Toss();
      switchD_001383b2::caseD_0();
      return;
    case 8:
      PM_NoClip();
      switchD_001383b2::caseD_0();
      return;
    }
  }
  return;
}


// PM_PreventMegaBunnyJumping  @ 0013931c
void PM_PreventMegaBunnyJumping(void)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)*(float *)(pmove + 500) * (longdouble)1.7;
  if (((longdouble)0 < lVar2) && (lVar1 = (longdouble)Length(pmove + 0x5c), lVar2 < lVar1)) {
    VectorScale(pmove + 0x5c,(float)((longdouble)0.65 * (lVar2 / lVar1)),pmove + 0x5c);
  }
  return;
}


// PM_PushEntity  @ 00136bb8
int * PM_PushEntity(int *param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_9c [12];
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_54;
  float local_50;
  float local_4c;
  int local_48 [4];
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_54 = *(float *)(pmove + 0x38) + *param_2;
  local_50 = *(float *)(pmove + 0x3c) + param_2[1];
  local_4c = *(float *)(pmove + 0x40) + param_2[2];
  (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
            (local_48,pmove + 0x38,&local_54,0,0xffffffff);
  *(undefined4 *)(pmove + 0x38) = local_34;
  *(undefined4 *)(pmove + 0x3c) = local_30;
  *(undefined4 *)(pmove + 0x40) = local_2c;
  if ((0x3f < (byte)((1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                     (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) - 1)) &&
     (local_48[0] == 0)) {
    piVar3 = local_48;
    piVar4 = local_9c;
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    iVar1 = 0;
    if (0 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
      do {
        if (*(int *)("__vt_12CTriggerPush" + iVar1 * 0x44 + pmove + 2) == local_6c) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc));
    }
    if (iVar1 == *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
      local_68 = *(undefined4 *)(pmove + 0x5c);
      local_64 = *(undefined4 *)(pmove + 0x60);
      local_60 = *(undefined4 *)(pmove + 100);
      if (599 < *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) {
        (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cb].r_offset + pmove))
                  ("Too many entities were touched!\n");
      }
      iVar1 = pmove;
      piVar3 = local_9c;
      piVar4 = (int *)("__vt_12CChangeLevel" +
                      (*(int *)("__vt_12CChangeLevel" + pmove + 0xc) * 0x10 +
                      *(int *)("__vt_12CChangeLevel" + pmove + 0xc)) * 4 + pmove + 0x10);
      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      *(int *)("__vt_12CChangeLevel" + iVar1 + 0xc) =
           *(int *)("__vt_12CChangeLevel" + iVar1 + 0xc) + 1;
    }
  }
  piVar3 = local_48;
  piVar4 = param_1;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  return param_1;
}


// PM_ReduceTimers  @ 001380d8
void PM_ReduceTimers(void)

{
  float fVar1;
  
  if ((0 < *(int *)(pmove + 0x94)) &&
     (*(uint *)(pmove + 0x94) =
           *(int *)(pmove + 0x94) - (uint)(byte)"__vt_14CTriggerVolume"[pmove + 0x14],
     *(int *)(pmove + 0x94) < 0)) {
    *(undefined4 *)(pmove + 0x94) = 0;
  }
  fVar1 = *(float *)(pmove + 0x8c);
  if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(float *)(pmove + 0x8c) = fVar1 - (float)(byte)"__vt_14CTriggerVolume"[pmove + 0x14];
    fVar1 = *(float *)(pmove + 0x8c);
    if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
      *(undefined4 *)(pmove + 0x8c) = 0;
    }
  }
  fVar1 = *(float *)(pmove + 0xac);
  if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(float *)(pmove + 0xac) = fVar1 - (float)(byte)"__vt_14CTriggerVolume"[pmove + 0x14];
    fVar1 = *(float *)(pmove + 0xac);
    if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
      *(undefined4 *)(pmove + 0xac) = 0;
    }
  }
  return;
}


// PM_ResetStuckOffsets  @ 00139234
void PM_ResetStuckOffsets(int param_1,int param_2)

{
  *(undefined4 *)(rgStuckLast + param_2 * 4 + param_1 * 8) = 0;
  return;
}


// PM_ShowClipBox  @ 0013aabc
void PM_ShowClipBox(void)

{
  return;
}


// PM_SortTextures  @ 00132ae0
void PM_SortTextures(void)

{
  undefined1 uVar1;
  char *__s2;
  int iVar2;
  char *__s1;
  int iVar3;
  int local_1c;
  int local_18;
  char local_14 [16];
  
  local_18 = 0;
  if (0 < gcTextures) {
    iVar2 = gcTextures;
    do {
      iVar3 = local_18 + 1;
      if (iVar3 < iVar2) {
        local_1c = iVar3;
        do {
          __s2 = (char *)((int)&grgszTextureName + local_1c * 0xd);
          __s1 = (char *)((int)&grgszTextureName + local_18 * 0xd);
          iVar2 = strcasecmp(__s1,__s2);
          if (0 < iVar2) {
            strcpy(local_14,__s1);
            uVar1 = *(undefined1 *)((int)&grgchTextureType + local_18);
            strcpy(__s1,__s2);
            *(undefined1 *)((int)&grgchTextureType + local_18) =
                 *(undefined1 *)((int)&grgchTextureType + local_1c);
            strcpy(__s2,local_14);
            *(undefined1 *)((int)&grgchTextureType + local_1c) = uVar1;
          }
          local_1c = local_1c + 1;
          iVar2 = gcTextures;
        } while (local_1c < gcTextures);
      }
      local_18 = iVar3;
    } while (iVar3 < iVar2);
  }
  return;
}


// PM_SpectatorMove  @ 00135e04
void PM_SpectatorMove(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  float local_1c [6];
  
  if (*(int *)(pmove + 0x1fc) == 3) {
    lVar6 = (longdouble)Length(pmove + 0x5c);
    lVar8 = (longdouble)1;
    if ((byte)((lVar8 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar6)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar8 == lVar6) << 0xe) >> 8)) - 1) < 0x40) {
      lVar7 = (longdouble)
              *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 4);
      lVar8 = lVar6;
      if (0x3f < (byte)((lVar7 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar8 = lVar7;
      }
      lVar7 = lVar6 - lVar8 * (longdouble)
                              (*(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info +
                                                  pmove) + 0x1c) * 1.5) *
                      (longdouble)*(float *)(pmove + 0x10);
      lVar8 = (longdouble)0;
      if (0x3f < (byte)((lVar8 < lVar7 |
                         (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1)) {
        lVar7 = lVar8;
      }
      VectorScale(pmove + 0x5c,(float)(lVar7 / lVar6),pmove + 0x5c);
    }
    else {
      *(undefined4 *)(pmove + 0x5c) = vec3_origin;
      *(undefined4 *)(pmove + 0x60) = DAT_0017548c;
      *(undefined4 *)(pmove + 100) = DAT_00175490;
    }
    fVar2 = *(float *)("__vt_11CFireAndDie" + pmove + 0xc);
    fVar3 = *(float *)("__vt_11CFireAndDie" + pmove + 0x10);
    VectorNormalize(pmove + 0x14);
    VectorNormalize(pmove + 0x20);
    pfVar1 = local_1c + 3;
    iVar5 = 0;
    do {
      iVar4 = iVar5 + 1;
      pfVar1[iVar5] =
           fVar3 * *(float *)(iVar5 * 4 + 0x20 + pmove) +
           fVar2 * *(float *)(iVar5 * 4 + 0x14 + pmove);
      iVar5 = iVar4;
    } while (iVar4 < 3);
    local_1c[2] = local_1c[5] + *(float *)("__12CChangeLevel" + pmove + 1);
    local_1c[0] = local_1c[3];
    local_1c[1] = local_1c[4];
    local_1c[5] = local_1c[2];
    lVar6 = (longdouble)VectorNormalize(local_1c);
    lVar8 = (longdouble)
            *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0xc);
    if (0x3f < (byte)((lVar6 < lVar8 |
                       (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar8)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar6 == lVar8) << 0xe) >> 8)) - 1)) {
      VectorScale(pfVar1,(float)((longdouble)
                                 *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info +
                                                    pmove) + 0xc) / lVar6),pfVar1);
      lVar6 = (longdouble)
              *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0xc);
    }
    lVar8 = lVar6 - ((longdouble)*(float *)(pmove + 100) * (longdouble)local_1c[2] +
                    (longdouble)*(float *)(pmove + 0x60) * (longdouble)local_1c[1] +
                    (longdouble)*(float *)(pmove + 0x5c) * (longdouble)local_1c[0]);
    if ((longdouble)0 < lVar8) {
      lVar6 = (longdouble)
              *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x10) *
              (longdouble)*(float *)(pmove + 0x10) * lVar6;
      if (lVar8 < lVar6) {
        lVar6 = lVar8;
      }
      iVar5 = 0;
      do {
        iVar4 = iVar5 * 4;
        pfVar1 = local_1c + iVar5;
        iVar5 = iVar5 + 1;
        *(float *)(iVar4 + pmove + 0x5c) =
             (float)(lVar6 * (longdouble)*pfVar1 + (longdouble)*(float *)(iVar4 + pmove + 0x5c));
      } while (iVar5 < 3);
      VectorMA(pmove + 0x38,*(undefined4 *)(pmove + 0x10),pmove + 0x5c,pmove + 0x38);
    }
  }
  else if (0 < *(int *)(pmove + 0x200)) {
    iVar5 = 0;
    if (0 < *(int *)(pmove + 0x24c)) {
      do {
        if (*(int *)(iVar5 * 0xe0 + pmove + 0x2a0) == *(int *)(pmove + 0x200)) break;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(pmove + 0x24c));
    }
    if (iVar5 != *(int *)(pmove + 0x24c)) {
      iVar5 = iVar5 * 0xe0;
      *(undefined4 *)(pmove + 0x44) = *(undefined4 *)(iVar5 + 0x2a4 + pmove);
      *(undefined4 *)(pmove + 0x48) = *(undefined4 *)(iVar5 + 0x2a8 + pmove);
      *(undefined4 *)(pmove + 0x4c) = *(undefined4 *)(iVar5 + 0x2ac + pmove);
      *(undefined4 *)(pmove + 0x38) = *(undefined4 *)(iVar5 + 0x274 + pmove);
      *(undefined4 *)(pmove + 0x3c) = *(undefined4 *)(iVar5 + 0x278 + pmove);
      *(undefined4 *)(pmove + 0x40) = *(undefined4 *)(iVar5 + 0x27c + pmove);
      *(undefined4 *)(pmove + 0x5c) = vec3_origin;
      *(undefined4 *)(pmove + 0x60) = DAT_0017548c;
      *(undefined4 *)(pmove + 100) = DAT_00175490;
    }
  }
  return;
}


// PM_SplineFraction  @ 0013926c
longdouble PM_SplineFraction(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 * (longdouble)param_2;
  lVar2 = lVar1 * lVar1;
  return (longdouble)3.0 * lVar2 - (lVar2 + lVar2) * lVar1;
}


// PM_SwapTextures  @ 00138c78
void PM_SwapTextures(int param_1,int param_2)

{
  undefined1 uVar1;
  char *__src;
  char *__src_00;
  char local_14 [16];
  
  __src_00 = (char *)((int)&grgszTextureName + param_1 * 0xd);
  strcpy(local_14,__src_00);
  uVar1 = *(undefined1 *)((int)&grgchTextureType + param_1);
  __src = (char *)((int)&grgszTextureName + param_2 * 0xd);
  strcpy(__src_00,__src);
  *(undefined1 *)((int)&grgchTextureType + param_1) =
       *(undefined1 *)((int)&grgchTextureType + param_2);
  strcpy(__src,local_14);
  *(undefined1 *)((int)&grgchTextureType + param_2) = uVar1;
  return;
}


// PM_UnDuck  @ 00136268
void PM_UnDuck(void)

{
  int iVar1;
  int iVar2;
  float local_54 [3];
  undefined1 local_48 [4];
  int iStack_44;
  
  local_54[0] = *(float *)(pmove + 0x38);
  local_54[1] = (float)*(undefined4 *)(pmove + 0x3c);
  local_54[2] = (float)*(undefined4 *)(pmove + 0x40);
  if (*(int *)(pmove + 0xe0) != -1) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      local_54[iVar1] =
           (*(float *)(iVar1 * 4 + 0x4f500 + pmove) - *(float *)(iVar1 * 4 + 0x4f4f4 + pmove)) +
           local_54[iVar1];
      iVar1 = iVar2;
    } while (iVar2 < 3);
  }
  (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
            (local_48,local_54,local_54,0,0xffffffff);
  if (iStack_44 == 0) {
    *(undefined4 *)(pmove + 0xbc) = 0;
    (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
              (local_48,local_54,local_54,0,0xffffffff);
    if (iStack_44 == 0) {
      *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) & 0xbf;
      *(undefined4 *)(pmove + 0x90) = 0;
      *(undefined4 *)(pmove + 0x88) = 0x41e00000;
      *(undefined4 *)(pmove + 0x8c) = 0;
      *(float *)(pmove + 0x38) = local_54[0];
      *(float *)(pmove + 0x3c) = local_54[1];
      *(float *)(pmove + 0x40) = local_54[2];
      PM_CatagorizePosition();
    }
    else {
      *(undefined4 *)(pmove + 0xbc) = 1;
    }
  }
  return;
}


// PM_UpdateStepSound  @ 00133808
void PM_UpdateStepSound(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  bool bVar5;
  longdouble lVar6;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
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
    local_44 = 60.0;
    local_40 = 80.0;
    local_48 = 100.0;
  }
  else {
    local_44 = 120.0;
    local_40 = 210.0;
    local_48 = 0.0;
  }
  if ((!bVar4) && (*(int *)(pmove + 0xe0) == -1)) {
    return;
  }
  lVar6 = (longdouble)Length(pmove + 0x5c);
  if (lVar6 <= (longdouble)0) {
    return;
  }
  if ((fVar1 < local_44) && (*(int *)(pmove + 0x94) != 0)) {
    return;
  }
  bVar5 = (byte)(fVar1 < local_40 |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_40)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == local_40) << 0xe) >> 8)) == 1;
  local_10 = *(undefined4 *)(pmove + 0x38);
  local_c = *(undefined4 *)(pmove + 0x3c);
  local_1c = *(undefined4 *)(pmove + 0x38);
  local_18 = *(undefined4 *)(pmove + 0x3c);
  fVar1 = *(float *)(pmove + 0x4f52c + *(int *)(pmove + 0xbc) * 0xc) -
          *(float *)(pmove + 0x4f4fc + *(int *)(pmove + 0xbc) * 0xc);
  local_8 = *(float *)(pmove + 0x40) - fVar1 * 0.3;
  local_14 = *(float *)(pmove + 0x40) - fVar1 * 0.5;
  if (bVar4) {
    uVar3 = 8;
    fVar1 = 0.35;
    *(undefined4 *)(pmove + 0x94) = 0x15e;
    goto LAB_00133be6;
  }
  iVar2 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cd].r_offset + pmove))(&local_10,0);
  if (iVar2 == -3) {
    uVar3 = 7;
    fVar1 = 0.65;
    *(undefined4 *)(pmove + 0x94) = 600;
    goto LAB_00133be6;
  }
  iVar2 = (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6cd].r_offset + pmove))(&local_1c,0);
  if (iVar2 == -3) {
    uVar3 = 6;
    fVar1 = 0.5;
    if (bVar5) {
      fVar1 = 0.2;
    }
    goto LAB_00133a4d;
  }
  switch(*(undefined1 *)(pmove + 0x1f0)) {
  default:
    uVar3 = 0;
    break;
  case 0x44:
    uVar3 = 2;
    break;
  case 0x47:
    uVar3 = 4;
    break;
  case 0x4d:
    uVar3 = 1;
    break;
  case 0x53:
    uVar3 = 6;
    break;
  case 0x54:
    uVar3 = 5;
    break;
  case 0x56:
    uVar3 = 3;
  }
  switch(*(undefined1 *)(pmove + 0x1f0)) {
  default:
    fVar1 = 0.5;
    if (bVar5) {
      fVar1 = 0.2;
    }
    break;
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
      goto LAB_00133be6;
    }
    fVar1 = 0.2;
    goto LAB_00133bd0;
  case 0x56:
    fVar1 = 0.7;
    if (bVar5) {
      fVar1 = 0.4;
    }
  }
LAB_00133a4d:
  if (!bVar5) {
    FUN_00133bdc();
    return;
  }
LAB_00133bd0:
  *(undefined4 *)(pmove + 0x94) = 400;
LAB_00133be6:
  *(int *)(pmove + 0x94) = (int)ROUND(local_48 + (float)*(int *)(pmove + 0x94));
  if ((*(byte *)(pmove + 0xb9) & 0x40) != 0) {
    fVar1 = fVar1 * 0.35;
  }
  PM_PlayStepSound(uVar3,fVar1);
  return;
}


// PM_WalkMove  @ 001346cc
void PM_WalkMove(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  int iStack_a8;
  int iStack_a4;
  float fStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  float fStack_80;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  float fStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  float fStack_34;
  float fStack_30;
  undefined4 uStack_2c;
  float local_28;
  float fStack_24;
  float fStack_20;
  float local_1c [6];
  
  fVar2 = *(float *)("__vt_11CFireAndDie" + pmove + 0xc);
  fVar3 = *(float *)("__vt_11CFireAndDie" + pmove + 0x10);
  *(undefined4 *)(pmove + 0x1c) = 0;
  *(undefined4 *)(pmove + 0x28) = 0;
  VectorNormalize(pmove + 0x14);
  VectorNormalize(pmove + 0x20);
  pfVar1 = local_1c + 3;
  iVar5 = 0;
  do {
    iVar4 = iVar5 + 1;
    pfVar1[iVar5] =
         fVar3 * *(float *)(iVar5 * 4 + 0x20 + pmove) + fVar2 * *(float *)(iVar5 * 4 + 0x14 + pmove)
    ;
    iVar5 = iVar4;
  } while (iVar4 < 2);
  local_1c[5] = 0.0;
  local_1c[0] = local_1c[3];
  local_1c[1] = local_1c[4];
  local_1c[2] = 0.0;
  lVar6 = (longdouble)VectorNormalize(local_1c);
  lVar7 = (longdouble)*(float *)(pmove + 500);
  if (0x3f < (byte)((lVar6 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar7)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar6 == lVar7) << 0xe) >> 8)) - 1)) {
    VectorScale(pfVar1,(float)((longdouble)*(float *)(pmove + 500) / lVar6),pfVar1);
    lVar6 = (longdouble)*(float *)(pmove + 500);
  }
  *(undefined4 *)(pmove + 100) = 0;
  if (((*(int *)(pmove + 0xd0) == 0) &&
      (lVar7 = (longdouble)0.0,
      (byte)((byte)((ushort)((ushort)(NAN(lVar7) || NAN((longdouble)*(float *)(pmove + 0xcc))) << 10
                            ) >> 8) |
            (byte)((ushort)((ushort)(lVar7 == (longdouble)*(float *)(pmove + 0xcc)) << 0xe) >> 8))
      == 0x40)) &&
     (lVar8 = lVar6 - ((longdouble)*(float *)(pmove + 100) * (longdouble)local_1c[2] +
                      (longdouble)*(float *)(pmove + 0x60) * (longdouble)local_1c[1] +
                      (longdouble)*(float *)(pmove + 0x5c) * (longdouble)local_1c[0]),
     0x3f < (byte)((lVar8 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1))) {
    lVar7 = (longdouble)
            *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x10) *
            (longdouble)*(float *)(pmove + 0x10) * lVar6 * (longdouble)*(float *)(pmove + 0xc4);
    if (0x3f < (byte)((lVar7 < lVar8 |
                       (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar8)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar7 == lVar8) << 0xe) >> 8)) - 1)) {
      lVar7 = lVar8;
    }
    iVar5 = 0;
    do {
      iVar4 = iVar5 * 4;
      pfVar1 = local_1c + iVar5;
      iVar5 = iVar5 + 1;
      *(float *)(iVar4 + pmove + 0x5c) =
           (float)(lVar7 * (longdouble)*pfVar1 + (longdouble)*(float *)(iVar4 + pmove + 0x5c));
    } while (iVar5 < 3);
  }
  *(undefined4 *)(pmove + 100) = 0;
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) + *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) + *(float *)(pmove + 0x7c);
  lVar7 = (longdouble)Length(pmove + 0x5c);
  if ((longdouble)1.0 <= lVar7) {
    fStack_34 = *(float *)(pmove + 0x5c) * *(float *)(pmove + 0x10) + *(float *)(pmove + 0x38);
    iVar5 = *(int *)(pmove + 0xe0);
    fStack_30 = *(float *)(pmove + 0x60) * *(float *)(pmove + 0x10) + *(float *)(pmove + 0x3c);
    uStack_2c = *(undefined4 *)(pmove + 0x40);
    local_28 = fStack_34;
    fStack_24 = fStack_30;
    fStack_20 = (float)uStack_2c;
    (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
              (&iStack_a8,pmove + 0x38,&local_28,0,0xffffffff);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_98) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_98 == 1.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(pmove + 0x38) = uStack_94;
      *(undefined4 *)(pmove + 0x3c) = uStack_90;
      *(undefined4 *)(pmove + 0x40) = uStack_8c;
    }
    else if (((iVar5 != -1) || (*(int *)(pmove + 0xe4) != 0)) &&
            ((byte)((byte)((ushort)((ushort)NAN(*(float *)(pmove + 0xcc)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(pmove + 0xcc) == 0.0) << 0xe) >> 8)) == 0x40)
            ) {
      fStack_40 = *(float *)(pmove + 0x38);
      fStack_3c = *(float *)(pmove + 0x3c);
      uStack_38 = *(undefined4 *)(pmove + 0x40);
      uStack_4c = *(undefined4 *)(pmove + 0x5c);
      uStack_48 = *(undefined4 *)(pmove + 0x60);
      uStack_44 = *(undefined4 *)(pmove + 100);
      PM_FlyMove();
      fStack_58 = *(float *)(pmove + 0x38);
      fStack_54 = *(float *)(pmove + 0x3c);
      uStack_50 = *(undefined4 *)(pmove + 0x40);
      uStack_64 = *(undefined4 *)(pmove + 0x5c);
      uStack_60 = *(undefined4 *)(pmove + 0x60);
      uStack_5c = *(undefined4 *)(pmove + 100);
      *(float *)(pmove + 0x38) = fStack_40;
      *(float *)(pmove + 0x3c) = fStack_3c;
      *(undefined4 *)(pmove + 0x40) = uStack_38;
      *(undefined4 *)(pmove + 0x5c) = uStack_4c;
      *(undefined4 *)(pmove + 0x60) = uStack_48;
      *(undefined4 *)(pmove + 100) = uStack_44;
      local_28 = *(float *)(pmove + 0x38);
      fStack_24 = *(float *)(pmove + 0x3c);
      fStack_20 = *(float *)(pmove + 0x40) +
                  *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x30);
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
                (&iStack_a8,pmove + 0x38,&local_28,0,0xffffffff);
      if ((iStack_a4 == 0) && (iStack_a8 == 0)) {
        *(undefined4 *)(pmove + 0x38) = uStack_94;
        *(undefined4 *)(pmove + 0x3c) = uStack_90;
        *(undefined4 *)(pmove + 0x40) = uStack_8c;
      }
      PM_FlyMove();
      local_28 = *(float *)(pmove + 0x38);
      fStack_24 = *(float *)(pmove + 0x3c);
      fStack_20 = *(float *)(pmove + 0x40) -
                  *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x30);
      (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
                (&iStack_a8,pmove + 0x38,&local_28,0,0xffffffff);
      if (0.7 <= fStack_80) {
        if ((iStack_a4 == 0) && (iStack_a8 == 0)) {
          *(undefined4 *)(pmove + 0x38) = uStack_94;
          *(undefined4 *)(pmove + 0x3c) = uStack_90;
          *(undefined4 *)(pmove + 0x40) = uStack_8c;
        }
        *(undefined4 *)(pmove + 0x2c) = *(undefined4 *)(pmove + 0x38);
        *(undefined4 *)(pmove + 0x30) = *(undefined4 *)(pmove + 0x3c);
        *(undefined4 *)(pmove + 0x34) = *(undefined4 *)(pmove + 0x40);
        fVar2 = *(float *)(pmove + 0x2c) - fStack_40;
        fVar3 = *(float *)(pmove + 0x30) - fStack_3c;
        if ((fStack_54 - fStack_3c) * (fStack_54 - fStack_3c) +
            (fStack_58 - fStack_40) * (fStack_58 - fStack_40) <= fVar3 * fVar3 + fVar2 * fVar2) {
          *(undefined4 *)(pmove + 100) = uStack_5c;
          return;
        }
      }
      *(float *)(pmove + 0x38) = fStack_58;
      *(float *)(pmove + 0x3c) = fStack_54;
      *(undefined4 *)(pmove + 0x40) = uStack_50;
      *(undefined4 *)(pmove + 0x5c) = uStack_64;
      *(undefined4 *)(pmove + 0x60) = uStack_60;
      *(undefined4 *)(pmove + 100) = uStack_5c;
    }
  }
  else {
    *(undefined4 *)(pmove + 0x5c) = 0;
    *(undefined4 *)(pmove + 0x60) = 0;
    *(undefined4 *)(pmove + 100) = 0;
  }
  return;
}


// PM_WaterJump  @ 00136af4
void PM_WaterJump(void)

{
  float fVar1;
  
  if (10000.0 < *(float *)(pmove + 0xcc)) {
    *(undefined4 *)(pmove + 0xcc) = 0x461c4000;
  }
  fVar1 = *(float *)(pmove + 0xcc);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    *(float *)(pmove + 0xcc) = fVar1 - (float)(byte)"__vt_14CTriggerVolume"[pmove + 0x14];
    if ((*(float *)(pmove + 0xcc) < 0.0) || (*(int *)(pmove + 0xe4) == 0)) {
      *(undefined4 *)(pmove + 0xcc) = 0;
      *(byte *)(pmove + 0xb9) = *(byte *)(pmove + 0xb9) & 0xf7;
    }
    *(undefined4 *)(pmove + 0x5c) = *(undefined4 *)(pmove + 0x68);
    *(undefined4 *)(pmove + 0x60) = *(undefined4 *)(pmove + 0x6c);
  }
  return;
}


// PM_WaterMove  @ 00134ee0
void PM_WaterMove(void)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  float fStack_8c;
  int iStack_84;
  int iStack_80;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float local_1c;
  undefined4 uStack_18;
  float fStack_14;
  float local_10 [3];
  
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 1;
    local_10[iVar3] =
         *(float *)(iVar3 * 4 + 0x20 + pmove) * *(float *)("__vt_11CFireAndDie" + pmove + 0x10) +
         *(float *)(iVar3 * 4 + 0x14 + pmove) * *(float *)("__vt_11CFireAndDie" + pmove + 0xc);
    iVar3 = iVar2;
  } while (iVar2 < 3);
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)("__vt_11CFireAndDie" + pmove + 0xc)) << 10) >>
                     8) |
              (byte)((ushort)((ushort)(*(float *)("__vt_11CFireAndDie" + pmove + 0xc) == 0.0) << 0xe
                             ) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)("__vt_11CFireAndDie" + pmove + 0x10)) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(*(float *)("__vt_11CFireAndDie" + pmove + 0x10) == 0.0) << 0xe
                            ) >> 8)) == 0x40)) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)("__12CChangeLevel" + pmove + 1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)("__12CChangeLevel" + pmove + 1) == 0.0) << 0xe) >> 8
                  )) == 0x40)) {
    fStack_14 = local_10[2] - 60.0;
  }
  else {
    fStack_14 = local_10[2] + *(float *)("__12CChangeLevel" + pmove + 1);
  }
  local_1c = local_10[0];
  uStack_18 = local_10[1];
  local_10[2] = fStack_14;
  lVar4 = (longdouble)VectorNormalize(&local_1c);
  fStack_8c = (float)lVar4;
  lVar5 = (longdouble)*(float *)(pmove + 500);
  if (0x3f < (byte)((lVar4 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar5)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar4 == lVar5) << 0xe) >> 8)) - 1)) {
    VectorScale(local_10,(float)((longdouble)*(float *)(pmove + 500) / lVar4),local_10);
    fStack_8c = *(float *)(pmove + 500);
  }
  fStack_8c = fStack_8c * 0.8;
  *(float *)(pmove + 0x5c) = *(float *)(pmove + 0x5c) + *(float *)(pmove + 0x74);
  *(float *)(pmove + 0x60) = *(float *)(pmove + 0x60) + *(float *)(pmove + 0x78);
  *(float *)(pmove + 100) = *(float *)(pmove + 100) + *(float *)(pmove + 0x7c);
  uStack_40 = *(undefined4 *)(pmove + 0x5c);
  uStack_3c = *(undefined4 *)(pmove + 0x60);
  uStack_38 = *(undefined4 *)(pmove + 100);
  lVar4 = (longdouble)VectorNormalize(&uStack_40);
  lVar5 = (longdouble)0;
  if ((byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) == 0x40) {
    lVar6 = (longdouble)0;
  }
  else {
    lVar6 = lVar4 - (longdouble)*(float *)(pmove + 0x10) * lVar4 *
                    (longdouble)
                    *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x1c
                              ) * (longdouble)*(float *)(pmove + 0xc4);
    if (lVar6 < lVar5) {
      lVar6 = lVar5;
    }
    VectorScale(pmove + 0x5c,(float)(lVar6 / lVar4),pmove + 0x5c);
  }
  if (0.1 <= fStack_8c) {
    lVar6 = (longdouble)fStack_8c - lVar6;
    if ((longdouble)0 < lVar6) {
      VectorNormalize(local_10);
      lVar5 = (longdouble)fStack_8c *
              (longdouble)
              *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x10) *
              (longdouble)*(float *)(pmove + 0x10) * (longdouble)*(float *)(pmove + 0xc4);
      if (0x3f < (byte)((lVar5 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar5 == lVar6) << 0xe) >> 8)) - 1)) {
        lVar5 = lVar6;
      }
      iVar3 = 0;
      do {
        iVar2 = iVar3 * 4;
        pfVar1 = local_10 + iVar3;
        iVar3 = iVar3 + 1;
        *(float *)(iVar2 + pmove + 0x5c) =
             (float)(lVar5 * (longdouble)*pfVar1 + (longdouble)*(float *)(iVar2 + pmove + 0x5c));
      } while (iVar3 < 3);
    }
    VectorMA(pmove + 0x38,*(undefined4 *)(pmove + 0x10),pmove + 0x5c,&uStack_34);
    uStack_28 = uStack_34;
    uStack_24 = uStack_30;
    fStack_20 = *(float *)(*(int *)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6bc].r_info + pmove) + 0x30) +
                1.0 + fStack_2c;
    (**(code **)((int)&Elf32_Rel_ARRAY_0004bf0c[0x6ce].r_info + pmove))
              (&iStack_84,&uStack_28,&uStack_34,0,0xffffffff);
    if ((iStack_80 == 0) && (iStack_84 == 0)) {
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


