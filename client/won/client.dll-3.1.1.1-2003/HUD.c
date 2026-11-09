// HUD_AddEntity  @ 2701eb90
undefined4 __cdecl HUD_AddEntity(int param_1,int *param_2,uint *param_3)

{
                    /* 0x1eb90  477  HUD_AddEntity */
  if (param_1 == 0) {
    FUN_27022cf0(0,(int)param_2,param_3);
  }
  if (DAT_270c28a8 != 0) {
    FUN_2700add0(&DAT_270a6790,param_1,param_2);
    if (((DAT_270c28a8 == 4) || (*(int *)(DAT_270a76a0 + 0xc) == 0x40000000)) &&
       (*param_2 == DAT_270c28b0)) {
      return 0;
    }
  }
  return 1;
}


// HUD_ConnectionlessPacket  @ 2701dec0
undefined4 HUD_ConnectionlessPacket(void)

{
  undefined4 *in_stack_00000010;
  
                    /* 0x1dec0  478  HUD_ConnectionlessPacket */
  *in_stack_00000010 = 0;
  return 0;
}


// HUD_CreateEntities  @ 2701efc0
void HUD_CreateEntities(void)

{
  undefined *puVar1;
  
                    /* 0x1efc0  479  HUD_CreateEntities */
  FUN_270238e0();
  FUN_2700d830();
  puVar1 = FUN_27019c20();
  FUN_2701a560((int)puVar1);
  return;
}


// HUD_DirectorMessage  @ 2701e0c0
void __cdecl HUD_DirectorMessage(undefined4 param_1,undefined4 param_2)

{
                    /* 0x1e0c0  480  HUD_DirectorMessage */
  FUN_27008870(&DAT_270a6790,param_1,param_2);
  return;
}


// HUD_DrawNormalTriangles  @ 27034220
void HUD_DrawNormalTriangles(void)

{
                    /* 0x34220  481  HUD_DrawNormalTriangles */
  FUN_2700ab70(0x270a6790);
  return;
}


// HUD_Frame  @ 2701e070
void __cdecl HUD_Frame(undefined4 param_1,undefined4 param_2)

{
  undefined *this;
  
                    /* 0x1e070  483  HUD_Frame */
  FUN_270252c0(param_1,param_2);
  this = FUN_27019c20();
  FUN_2701a4d0(this,(double)CONCAT44(param_2,param_1));
  return;
}


// HUD_GetHullBounds  @ 2701dea0
undefined4 __cdecl HUD_GetHullBounds(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x1dea0  484  HUD_GetHullBounds */
  uVar1 = 0;
  if (((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) {
    uVar1 = 1;
  }
  return uVar1;
}


// HUD_GetStudioModelInterface  @ 27020110
undefined4 __cdecl HUD_GetStudioModelInterface(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0x20110  485  HUD_GetStudioModelInterface */
  if (param_1 != 1) {
    return 0;
  }
  *param_2 = &DAT_270763d0;
  puVar2 = &DAT_270be270;
  for (iVar1 = 0x2b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_27020100();
  return 1;
}


// HUD_GetUserEntity  @ 2701f9a0
undefined4 HUD_GetUserEntity(void)

{
                    /* 0x1f9a0  486  HUD_GetUserEntity */
  return 0;
}


// HUD_Init  @ 2701e000
undefined4 HUD_Init(void)

{
                    /* 0x1e000  487  HUD_Init */
  FUN_27026ef0();
  FUN_27021700((int *)&DAT_270a65e8);
  FUN_270381d0();
  return 1;
}


// HUD_Key_Event  @ 27026310
undefined4 __cdecl HUD_Key_Event(int param_1,int param_2,char *param_3)

{
  undefined4 uVar1;
  
                    /* 0x26310  488  HUD_Key_Event */
  if (DAT_270a835c != (void *)0x0) {
    uVar1 = FUN_270411e0(DAT_270a835c,param_1,param_2,param_3);
    return uVar1;
  }
  return 1;
}


// HUD_PostRunCmd  @ 2700f2c0
void __cdecl
HUD_PostRunCmd(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7)

{
                    /* 0xf2c0  492  HUD_PostRunCmd */
  DAT_270a836c = param_4;
  if ((DAT_270ac76c != 0) && (*(float *)(DAT_270ac76c + 0xc) != 0.0)) {
    if (*(int *)(param_2 + 0x2ec) == 0) {
      FUN_2700ea40(param_1,param_2,param_3,(double)CONCAT44(param_6,param_5),param_7);
      DAT_270ac774 = *(undefined4 *)(param_2 + 0x1b4);
      return;
    }
    DAT_270ac774 = *(undefined4 *)(param_2 + 0x1b4);
    return;
  }
  *(undefined4 *)(param_2 + 0x1b4) = DAT_270ac774;
  DAT_27088740 = 0;
  DAT_270ac774 = *(undefined4 *)(param_2 + 0x1b4);
  return;
}


// HUD_ProcessPlayerState  @ 2701ec50
void __cdecl HUD_ProcessPlayerState(int param_1,int param_2)

{
  int *piVar1;
  
                    /* 0x1ec50  493  HUD_ProcessPlayerState */
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 0x70);
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_2 + 0x74);
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_2 + 0x78);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
  *(undefined2 *)(param_1 + 0x38) = *(undefined2 *)(param_2 + 0x38);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_2 + 0xb4);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined2 *)(param_1 + 0x3a) = *(undefined2 *)(param_2 + 0x3a);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
  *(undefined1 *)(param_1 + 0x50) = *(undefined1 *)(param_2 + 0x50);
  *(undefined1 *)(param_1 + 0x51) = *(undefined1 *)(param_2 + 0x51);
  *(undefined1 *)(param_1 + 0x52) = *(undefined1 *)(param_2 + 0x52);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x68);
  *(undefined2 *)(param_1 + 0x6c) = *(undefined2 *)(param_2 + 0x6c);
  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_2 + 0xbc);
  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_2 + 0xc0);
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_2 + 0xc4);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_2 + 0x9c);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0xa0);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_2 + 0xb8);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_2 + 0xb0);
  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_2 + 200);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0xa8);
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_2 + 0xa4);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_2 + 0x114);
  piVar1 = (int *)(*DAT_270a8294)();
  if (*(int *)(param_1 + 4) == *piVar1) {
    DAT_270c27a0 = *(undefined4 *)(param_1 + 0xa8);
    DAT_270c28b4 = *(undefined4 *)(param_1 + 0xa4);
    DAT_270c28a8 = *(undefined4 *)(param_2 + 0x104);
    DAT_270c28b0 = *(undefined4 *)(param_2 + 0x108);
    DAT_270c28ac = *(undefined4 *)(param_2 + 0x10c);
  }
  return;
}


// HUD_Redraw  @ 2701e020
undefined4 __cdecl HUD_Redraw(float param_1,int param_2)

{
                    /* 0x1e020  494  HUD_Redraw */
  FUN_27023ef0(&DAT_270a65e8,param_1,param_2);
  return 1;
}


// HUD_Reset  @ 2701e060
undefined4 HUD_Reset(void)

{
                    /* 0x1e060  495  HUD_Reset */
  FUN_27021be0(&DAT_270a65e8);
  return 1;
}


// HUD_StudioEvent  @ 2701efe0
void __cdecl HUD_StudioEvent(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
                    /* 0x1efe0  497  HUD_StudioEvent */
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0x1389:
    puVar1 = (undefined4 *)((int)DAT_270a8314 + 0x4c);
    uVar2 = FUN_27046a72(DAT_270a8314,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb60,uVar2);
    return;
  case 0x138a:
    uVar4 = 100;
    uVar3 = 0xffffff9c;
    puVar1 = (undefined4 *)((int)DAT_270a8314 + 0x84);
    uVar2 = FUN_27046a72(DAT_270a8314,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb60,uVar2,uVar3,uVar4);
    return;
  case 0x138c:
    (*DAT_270a82c4)(param_1 + 0xc,0x3f800000,param_2 + 0xb60);
    break;
  case 0x1393:
    puVar1 = (undefined4 *)((int)DAT_270a8314 + 0x4c);
    uVar2 = FUN_27046a72(DAT_270a8314,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb6c,uVar2);
    return;
  case 0x139d:
    puVar1 = (undefined4 *)((int)DAT_270a8314 + 0x4c);
    uVar2 = FUN_27046a72(DAT_270a8314,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb78,uVar2);
    return;
  case 0x13a7:
    puVar1 = (undefined4 *)((int)DAT_270a8314 + 0x4c);
    uVar2 = FUN_27046a72(DAT_270a8314,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb84,uVar2);
    return;
  }
  return;
}


// HUD_TempEntUpdate  @ 2701f130
void __cdecl
HUD_TempEntUpdate(double param_1,double param_2,double param_3,uint *param_4,int *param_5,
                 undefined *param_6,undefined *param_7)

{
  float *pfVar1;
  float fVar2;
  uint *puVar3;
  uint uVar4;
  float fVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  code *pcVar9;
  float *pfVar10;
  undefined1 *puVar11;
  float10 fVar12;
  float10 fVar13;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar14;
  longlong lVar15;
  float fStack_b4;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  uint *puStack_94;
  float fStack_90;
  float fStack_8c;
  undefined1 auStack_88 [16];
  float fStack_78;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  int iStack_58;
  undefined1 auStack_44 [16];
  float fStack_34;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
                    /* 0x1f130  498  HUD_TempEntUpdate */
  if (*param_5 == 0) {
    return;
  }
  (**(code **)(DAT_270a8318 + 0x28))(0,1);
  (**(code **)(DAT_270a8318 + 0x2c))();
  (**(code **)(DAT_270a8318 + 0x34))(0xffffffff);
  DAT_270a86a8 = DAT_270a86a8 + 1 & 0x1f;
  puVar3 = (uint *)*param_5;
  if (param_1 < 0.0 == (param_1 == 0.0)) {
    puStack_94 = (uint *)0x0;
    fStack_90 = (float)((float10)param_2 * (float10)5.5);
    fVar2 = (float)-((float10)param_1 * (float10)param_3);
    fStack_8c = (float)(-((float10)param_1 * (float10)param_3) * (float10)0.5);
    puVar7 = puStack_94;
    while (puVar6 = puVar3, puStack_94 = puVar7, puVar6 != (uint *)0x0) {
      puVar3 = (uint *)puVar6[0xb];
      if (0.0 <= (float)puVar6[1] - (float)param_2) {
LAB_2701f290:
        pfVar1 = (float *)(puVar6 + 0x2e3);
        puVar6[0x6c] = puVar6[0x2e3];
        uVar4 = *puVar6;
        puVar6[0x6d] = puVar6[0x2e4];
        puVar6[0x6e] = puVar6[0x2e5];
        puStack_94 = puVar6;
        if ((uVar4 & 0x20000) == 0) {
          if ((char)(uVar4 >> 8) < '\0') {
            iVar8 = (*DAT_270a829c)((int)(short)puVar6[0xd]);
            *pfVar1 = *(float *)(iVar8 + 0xb48) + (float)puVar6[0xe];
            puVar6[0x2e4] = (uint)(*(float *)(iVar8 + 0xb4c) + (float)puVar6[0xf]);
            puVar6[0x2e5] = (uint)(*(float *)(iVar8 + 0xb50) + (float)puVar6[0x10]);
          }
          else {
            if ((uVar4 & 1) == 0) {
              if ((uVar4 & 0x400) == 0) {
                iVar8 = 3;
                pfVar10 = pfVar1;
                do {
                  iVar8 = iVar8 + -1;
                  *pfVar10 = pfVar10[-0x2cc] * (float)param_1 + *pfVar10;
                  pfVar10 = pfVar10 + 1;
                } while (iVar8 != 0);
                goto LAB_2701f4a9;
              }
              fVar14 = (float10)fsin((float10)param_2 * (float10)20.0 + (float10)(int)puVar6);
              *pfVar1 = (float)((float10)(float)puVar6[0x17] * (float10)param_1 +
                                fVar14 * (float10)8.0 + (float10)*pfVar1);
              fVar14 = (float10)fsin((float10)param_2 * (float10)30.0 + (float10)(int)puVar6);
              puVar6[0x2e4] =
                   (uint)(float)((float10)(float)puVar6[0x18] * (float10)param_1 +
                                 fVar14 * (float10)4.0 + (float10)(float)puVar6[0x2e4]);
            }
            else {
              fVar14 = (float10)(float)puVar6[0x17] * (float10)param_1 + (float10)(float)puVar6[3];
              puVar6[3] = (uint)(float)fVar14;
              fVar12 = (float10)(float)puVar6[0x18] * (float10)param_1 + (float10)(float)puVar6[4];
              puVar6[4] = (uint)(float)fVar12;
              fVar13 = (float10)fsin((float10)(float)puVar6[0x74] * (float10)param_2 +
                                     (float10)(float)puVar6[0x19]);
              *pfVar1 = (float)((float10)(float)puVar6[0xd5] * (float10)10.0 * fVar13 + fVar14);
              fVar14 = (float10)fsin((float10)fStack_90 + (float10)(float)puVar6[0x19] +
                                     (float10)0.7);
              puVar6[0x2e4] =
                   (uint)(float)((float10)(float)puVar6[0xd5] * (float10)8.0 * fVar14 + fVar12);
            }
            puVar6[0x2e5] = (uint)((float)puVar6[0x19] * (float)param_1 + (float)puVar6[0x2e5]);
          }
        }
        else if ((float)puVar6[0x23] < (float)param_2) {
          (**(code **)(DAT_270a8314 + 0x84))(pfVar1,8,0xffffff38,200);
          fVar5 = (float)puVar6[0x2b] - 0.1;
          puVar6[0x2b] = (uint)fVar5;
          if (fVar5 < 0.0 == (fVar5 == 0.0)) {
            puVar6[1] = (uint)(float)((float10)param_2 + (float10)0.5);
            puVar6[0x23] = (uint)(float)((float10)param_2 + (float10)0.1);
          }
          else {
            puVar6[1] = (uint)(float)param_2;
          }
        }
LAB_2701f4a9:
        uVar4 = *puVar6;
        if ((uVar4 & 0x100) == 0) {
          if (((uVar4 & 0x800) != 0) &&
             (fVar14 = (float10)param_1 * (float10)10.0 + (float10)(float)puVar6[0xc9],
             puVar6[0xc9] = (uint)(float)fVar14, (float10)(float)puVar6[2] <= fVar14)) {
            lVar15 = __ftol();
            puVar6[0xc9] = (uint)(float)(extraout_ST0_00 - (float10)(int)lVar15);
          }
LAB_2701f548:
          if ((uVar4 & 4) != 0) {
            puVar6[0x2e6] = (uint)((float)puVar6[0x1a] * (float)param_1 + (float)puVar6[0x2e6]);
            puVar6[0x2e7] = (uint)((float)puVar6[0x1b] * (float)param_1 + (float)puVar6[0x2e7]);
            puVar6[0x2e8] = (uint)((float)puVar6[0x1c] * (float)param_1 + (float)puVar6[0x2e8]);
            puVar6[0x2db] = puVar6[0x2e6];
            puVar6[0x2dc] = puVar6[0x2e7];
            puVar6[0x2dd] = puVar6[0x2e8];
          }
          uVar4 = *puVar6;
          if ((uVar4 & 0x1020) != 0) {
            if ((uVar4 & 0x1000) == 0) {
              if ((uVar4 & 0x20) != 0) {
                (**(code **)(DAT_270a8318 + 0x38))(2);
                (**(code **)(DAT_270a8318 + 0x3c))(puVar6 + 0x6c,pfVar1,10,0xffffffff,auStack_44);
                if (fStack_34 != 1.0) {
                  fStack_a0 = fStack_24;
                  fStack_a4 = fStack_34;
                  fStack_9c = fStack_20;
                  fStack_98 = fStack_1c;
                  if ((*puVar6 & 0x20000) != 0) {
                    pfVar10 = (float *)(puVar6 + 0x17);
                    FUN_27029b20(pfVar10,0.6,pfVar10);
                    fVar14 = FUN_27034260((int)pfVar10);
                    if (fVar14 < (float10)10.0) {
                      puVar6[0x2b] = 0;
                    }
                  }
                  pcVar9 = (code *)puVar6[9];
                  if (pcVar9 != (code *)0x0) {
                    puVar11 = auStack_44;
                    goto LAB_2701f71c;
                  }
                  goto LAB_2701f723;
                }
              }
            }
            else {
              (**(code **)(DAT_270a8318 + 0x38))(2);
              (**(code **)(DAT_270a8318 + 0x3c))(puVar6 + 0x6c,pfVar1,2,0xffffffff,auStack_88);
              if ((fStack_78 != 1.0) &&
                 ((iVar8 = (**(code **)(DAT_270a8318 + 0x24))(iStack_58), iStack_58 == 0 ||
                  (*(int *)(iVar8 + 0x50) != (int)(short)puVar6[0xd])))) {
                fStack_a0 = fStack_68;
                pcVar9 = (code *)puVar6[9];
                fStack_a4 = fStack_78;
                fStack_9c = fStack_64;
                fStack_98 = fStack_60;
                if (pcVar9 != (code *)0x0) {
                  puVar11 = auStack_88;
LAB_2701f71c:
                  (*pcVar9)(puVar6,puVar11);
                }
LAB_2701f723:
                if (fStack_a4 != 1.0) {
                  pfVar10 = (float *)(puVar6 + 0x17);
                  FUN_27029a10((float *)(puVar6 + 0x6c),fStack_a4 * (float)param_1,pfVar10,pfVar1);
                  fStack_b4 = (float)puVar6[7];
                  if (((((*puVar6 & 10) != 0) && (fStack_b4 = fStack_b4 * 0.5, 0.9 < fStack_98)) &&
                      ((float)puVar6[0x19] < 0.0 != ((float)puVar6[0x19] == 0.0))) &&
                     (fVar5 = fVar2 * 3.0,
                     fVar5 < (float)puVar6[0x19] != (fVar5 == (float)puVar6[0x19]))) {
                    fStack_b4 = 0.0;
                    *puVar6 = *puVar6 & 0xffffffc1;
                    puVar6[0x2e6] = 0;
                    puVar6[0x2e8] = 0;
                  }
                  if (puVar6[8] != 0) {
                    (*(code *)param_7)(puVar6,fStack_b4);
                  }
                  if ((*puVar6 & 0x4000) == 0) {
                    if (fStack_b4 != 0.0) {
                      FUN_27029a10(pfVar10,(fStack_a0 * *pfVar10 +
                                           fStack_98 * (float)puVar6[0x19] +
                                           fStack_9c * (float)puVar6[0x18]) * -2.0,&fStack_a0,
                                   pfVar10);
                      puVar6[0x2e7] = (uint)-(float)puVar6[0x2e7];
                    }
                    if (fStack_b4 != 1.0) {
                      FUN_27029b20(pfVar10,fStack_b4,pfVar10);
                      FUN_27029b20((float *)(puVar6 + 0x2e6),0.9,(float *)(puVar6 + 0x2e6));
                    }
                  }
                  else {
                    puVar6[1] = (uint)(float)param_2;
                    *puVar6 = *puVar6 & 0xffffff7f;
                  }
                }
              }
            }
          }
          if (((*puVar6 & 0x40) != 0) && (DAT_270a86a8 == puVar6[0xcc])) {
            pfVar10 = (float *)(**(code **)(DAT_270a8314 + 0x100))(0);
            *pfVar10 = *pfVar1;
            pfVar10[1] = (float)puVar6[0x2e4];
            pfVar10[2] = (float)puVar6[0x2e5];
            pfVar10[3] = 60.0;
            pfVar10[5] = (float)((float10)param_2 + (float10)0.01);
            *(undefined1 *)(pfVar10 + 4) = 0xff;
            *(undefined1 *)((int)pfVar10 + 0x11) = 0x78;
            *(undefined1 *)((int)pfVar10 + 0x12) = 0;
          }
          if ((*puVar6 & 0x10) != 0) {
            (**(code **)(DAT_270a8314 + 0x78))(puVar6 + 0x6c,pfVar1,1);
          }
          fVar5 = fVar2;
          if (((*puVar6 & 2) != 0) || (fVar5 = fStack_8c, (*puVar6 & 8) != 0)) {
            puVar6[0x19] = (uint)(fVar5 + (float)puVar6[0x19]);
          }
          if (((*puVar6 & 0x80000) != 0) && ((code *)puVar6[10] != (code *)0x0)) {
            (*(code *)puVar6[10])(puVar6,(float)param_1,(float)param_2);
          }
          puVar7 = puStack_94;
          if ((((*puVar6 & 0x40000) == 0) &&
              (iVar8 = (*(code *)param_6)(puVar6 + 0x11), puVar7 = puStack_94, iVar8 == 0)) &&
             ((*puVar6 & 0x2000) == 0)) {
            puVar6[1] = (uint)(float)param_2;
            *puVar6 = *puVar6 & 0xffffff7f;
          }
        }
        else {
          fVar5 = (float)puVar6[0xd5] * (float)param_1 + (float)puVar6[0xc9];
          puVar6[0xc9] = (uint)fVar5;
          if (fVar5 < (float)puVar6[2]) goto LAB_2701f548;
          lVar15 = __ftol();
          puVar6[0xc9] = (uint)(float)(extraout_ST0 - (float10)(int)lVar15);
          if ((uVar4 & 0x10000) != 0) goto LAB_2701f548;
          puVar6[1] = (uint)(float)param_2;
          puVar7 = puStack_94;
        }
      }
      else {
        if ((char)(byte)*puVar6 < '\0') {
          if (puVar6[0xcf] == 0) {
            puVar6[0xcf] = 2;
          }
          lVar15 = __ftol();
          puVar6[0xd0] = (uint)lVar15;
          if (0 < (int)(uint)lVar15) goto LAB_2701f290;
        }
        puVar6[0xb] = *param_4;
        *param_4 = (uint)puVar6;
        if (puVar7 == (uint *)0x0) {
          *param_5 = (int)puVar3;
          puVar7 = puStack_94;
        }
        else {
          puVar7[0xb] = (uint)puVar3;
          puVar7 = puStack_94;
        }
      }
    }
  }
  else {
    for (; puVar3 != (uint *)0x0; puVar3 = (uint *)puVar3[0xb]) {
      if ((*puVar3 & 0x40000) == 0) {
        (*(code *)param_6)(puVar3 + 0x11);
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x2701f988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_270a8318 + 0x30))();
  return;
}


// HUD_TxferLocalOverrides  @ 2701ec00
void __cdecl HUD_TxferLocalOverrides(int param_1,undefined4 *param_2)

{
                    /* 0x1ec00  499  HUD_TxferLocalOverrides */
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x104) = param_2[99];
  *(undefined4 *)(param_1 + 0x108) = param_2[100];
  *(undefined4 *)(param_1 + 0x10c) = param_2[0x65];
  *(undefined4 *)(param_1 + 0x110) = param_2[0x66];
  return;
}


// HUD_TxferPredictionData  @ 2701edf0
void __cdecl
HUD_TxferPredictionData
          (int param_1,int param_2,int param_3,int param_4,undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  
                    /* 0x1edf0  500  HUD_TxferPredictionData */
  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_2 + 0xcc);
  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_2 + 0xd8);
  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_2 + 0xd4);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0xa8);
  *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)(param_4 + 0x18);
  *(undefined4 *)(param_3 + 0x68) = *(undefined4 *)(param_4 + 0x68);
  *(undefined4 *)(param_3 + 0x6c) = *(undefined4 *)(param_4 + 0x6c);
  *(undefined4 *)(param_3 + 0x70) = *(undefined4 *)(param_4 + 0x70);
  *(undefined4 *)(param_3 + 0x74) = *(undefined4 *)(param_4 + 0x74);
  *(undefined4 *)(param_3 + 0x78) = *(undefined4 *)(param_4 + 0x78);
  *(undefined4 *)(param_3 + 0x7c) = *(undefined4 *)(param_4 + 0x7c);
  *(undefined4 *)(param_3 + 0x60) = *(undefined4 *)(param_4 + 0x60);
  *(undefined4 *)(param_3 + 100) = *(undefined4 *)(param_4 + 100);
  *(undefined4 *)(param_3 + 0x80) = *(undefined4 *)(param_4 + 0x80);
  *(undefined4 *)(param_3 + 0x5c) = *(undefined4 *)(param_4 + 0x5c);
  iVar1 = *(int *)(param_4 + 0x88);
  *(int *)(param_3 + 0x88) = iVar1;
  if ((*(int *)(param_4 + 0x18c) != 0) || (DAT_27076390 = 0, iVar1 == 0)) {
    DAT_27076390 = 1;
  }
  *(undefined4 *)(param_3 + 0x18c) = *(undefined4 *)(param_4 + 0x18c);
  *(undefined4 *)(param_3 + 400) = *(undefined4 *)(param_4 + 400);
  *(undefined4 *)(param_3 + 0x194) = *(undefined4 *)(param_4 + 0x194);
  iVar1 = (*DAT_270a8328)();
  if (iVar1 != 0) {
    *(undefined4 *)(param_3 + 0x18c) = DAT_270c28a8;
    *(undefined4 *)(param_3 + 400) = DAT_270c28b0;
    *(undefined4 *)(param_3 + 0x194) = DAT_270c28ac;
  }
  *(undefined4 *)(param_3 + 0x198) = *(undefined4 *)(param_4 + 0x198);
  *(undefined4 *)(param_3 + 0x1a0) = *(undefined4 *)(param_4 + 0x1a0);
  *(undefined4 *)(param_3 + 0x1a4) = *(undefined4 *)(param_4 + 0x1a4);
  *(undefined4 *)(param_3 + 0x1ac) = *(undefined4 *)(param_4 + 0x1ac);
  *(undefined4 *)(param_3 + 0x1b0) = *(undefined4 *)(param_4 + 0x1b0);
  *(undefined4 *)(param_3 + 0x1b4) = *(undefined4 *)(param_4 + 0x1b4);
  *(undefined4 *)(param_3 + 0x1b8) = *(undefined4 *)(param_4 + 0x1b8);
  *(undefined4 *)(param_3 + 0x1bc) = *(undefined4 *)(param_4 + 0x1bc);
  *(undefined4 *)(param_3 + 0x1c0) = *(undefined4 *)(param_4 + 0x1c0);
  *(undefined4 *)(param_3 + 0x1c4) = *(undefined4 *)(param_4 + 0x1c4);
  *(undefined4 *)(param_3 + 0x1c8) = *(undefined4 *)(param_4 + 0x1c8);
  *(undefined4 *)(param_3 + 0x1cc) = *(undefined4 *)(param_4 + 0x1cc);
  *(undefined4 *)(param_3 + 0x1d0) = *(undefined4 *)(param_4 + 0x1d0);
  *(undefined4 *)(param_3 + 0x1d4) = *(undefined4 *)(param_4 + 0x1d4);
  *(undefined4 *)(param_3 + 0x1d8) = *(undefined4 *)(param_4 + 0x1d8);
  for (iVar1 = 0x2c0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_5 = *param_6;
    param_6 = param_6 + 1;
    param_5 = param_5 + 1;
  }
  return;
}


// HUD_UpdateClientData  @ 2701e040
void __cdecl HUD_UpdateClientData(undefined4 *param_1)

{
                    /* 0x1e040  501  HUD_UpdateClientData */
  FUN_27027cb0();
  FUN_27025320(&DAT_270a65e8,param_1);
  return;
}


// HUD_VidInit  @ 2701dfe0
undefined4 HUD_VidInit(void)

{
                    /* 0x1dfe0  502  HUD_VidInit */
  FUN_27021be0(&DAT_270a65e8);
  FUN_270371b0();
  return 1;
}


// HUD_VoiceStatus  @ 2701e0a0
void __cdecl HUD_VoiceStatus(int param_1,int param_2)

{
  undefined *this;
  
                    /* 0x1e0a0  503  HUD_VoiceStatus */
  this = FUN_27019c20();
  FUN_2701a720(this,param_1,param_2);
  return;
}


