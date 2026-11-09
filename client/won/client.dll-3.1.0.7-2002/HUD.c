// HUD_AddEntity  @ 270159d0
undefined4 __cdecl HUD_AddEntity(int param_1,int param_2,uint *param_3)

{
                    /* 0x159d0  423  HUD_AddEntity */
  if (param_1 == 0) {
    FUN_27019790(0,param_2,param_3);
  }
  return 1;
}


// HUD_ConnectionlessPacket  @ 27014d80
undefined4 HUD_ConnectionlessPacket(void)

{
  undefined4 *in_stack_00000010;
  
                    /* 0x14d80  424  HUD_ConnectionlessPacket */
  *in_stack_00000010 = 0;
  return 0;
}


// HUD_CreateEntities  @ 27015cd0
void HUD_CreateEntities(void)

{
                    /* 0x15cd0  425  HUD_CreateEntities */
  FUN_2701a390();
  FUN_27006bd0();
  return;
}


// HUD_Frame  @ 27014ea0
void __cdecl HUD_Frame(undefined4 param_1,undefined4 param_2)

{
                    /* 0x14ea0  428  HUD_Frame */
  FUN_2701beb0(param_1,param_2);
  return;
}


// HUD_GetHullBounds  @ 27014d60
undefined4 __cdecl HUD_GetHullBounds(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x14d60  429  HUD_GetHullBounds */
  uVar1 = 0;
  if (((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) {
    uVar1 = 1;
  }
  return uVar1;
}


// HUD_GetStudioModelInterface  @ 27016de0
undefined4 __cdecl HUD_GetStudioModelInterface(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0x16de0  430  HUD_GetStudioModelInterface */
  if (param_1 != 1) {
    return 0;
  }
  *param_2 = &DAT_270655f8;
  puVar2 = &DAT_27092870;
  for (iVar1 = 0x2b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_27016dd0();
  return 1;
}


// HUD_GetUserEntity  @ 270166a0
undefined4 HUD_GetUserEntity(void)

{
                    /* 0x166a0  431  HUD_GetUserEntity */
  return 0;
}


// HUD_Init  @ 27014e30
undefined4 HUD_Init(void)

{
                    /* 0x14e30  432  HUD_Init */
  FUN_2701da30();
  FUN_27018250((int *)&DAT_2707bf70);
  FUN_2702e7b0();
  return 1;
}


// HUD_Key_Event  @ 2701cf10
undefined4 __cdecl HUD_Key_Event(int param_1,int param_2,byte *param_3)

{
  undefined4 uVar1;
  
                    /* 0x1cf10  433  HUD_Key_Event */
  if (DAT_2707ca24 != (void *)0x0) {
    uVar1 = FUN_270373e0(DAT_2707ca24,param_1,param_2,param_3);
    return uVar1;
  }
  return 1;
}


// HUD_PlayerMove  @ 27014db0
void __cdecl HUD_PlayerMove(int param_1,int param_2)

{
                    /* 0x14db0  434  HUD_PlayerMove */
  FUN_270256d0(param_1,param_2);
  return;
}


// HUD_PlayerMoveInit  @ 27014d90
void __cdecl HUD_PlayerMoveInit(undefined4 param_1)

{
                    /* 0x14d90  435  HUD_PlayerMoveInit */
  FUN_27025740(param_1);
  return;
}


// HUD_PlayerMoveTexture  @ 27014da0
void __cdecl HUD_PlayerMoveTexture(byte *param_1)

{
                    /* 0x14da0  436  HUD_PlayerMoveTexture */
  FUN_27020920(param_1);
  return;
}


// HUD_PostRunCmd  @ 27008610
void __cdecl
HUD_PostRunCmd(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7)

{
                    /* 0x8610  437  HUD_PostRunCmd */
  DAT_2707ca2c = param_4;
  if ((DAT_27080e28 != 0) && (*(float *)(DAT_27080e28 + 0xc) != 0.0)) {
    if (*(int *)(param_2 + 0x2ec) == 0) {
      FUN_27007de0(param_1,param_2,param_3,(double)CONCAT44(param_6,param_5),param_7);
      DAT_27080e30 = *(undefined4 *)(param_2 + 0x1b4);
      return;
    }
    DAT_27080e30 = *(undefined4 *)(param_2 + 0x1b4);
    return;
  }
  *(undefined4 *)(param_2 + 0x1b4) = DAT_27080e30;
  DAT_2707719c = 0;
  DAT_27080e30 = *(undefined4 *)(param_2 + 0x1b4);
  return;
}


// HUD_ProcessPlayerState  @ 27015a50
void __cdecl HUD_ProcessPlayerState(int param_1,int param_2)

{
  int *piVar1;
  
                    /* 0x15a50  438  HUD_ProcessPlayerState */
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
  piVar1 = (int *)(*DAT_2707c994)();
  if (*(int *)(param_1 + 4) == *piVar1) {
    DAT_27096c90 = *(undefined4 *)(param_1 + 0xa8);
    DAT_27096d9c = *(undefined4 *)(param_1 + 0xa4);
    DAT_27096d94 = *(undefined4 *)(param_2 + 0x104);
    DAT_27096d98 = *(undefined4 *)(param_2 + 0x108);
  }
  return;
}


// HUD_Redraw  @ 27014e50
undefined4 __cdecl HUD_Redraw(float param_1,int param_2)

{
                    /* 0x14e50  439  HUD_Redraw */
  FUN_2701aa80(&DAT_2707bf70,param_1,param_2);
  return 1;
}


// HUD_Reset  @ 27014e90
undefined4 HUD_Reset(void)

{
                    /* 0x14e90  440  HUD_Reset */
  FUN_27018640(&DAT_2707bf70);
  return 1;
}


// HUD_StudioEvent  @ 27015ce0
void __cdecl HUD_StudioEvent(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
                    /* 0x15ce0  442  HUD_StudioEvent */
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0x1389:
    puVar1 = (undefined4 *)((int)DAT_2707ca14 + 0x4c);
    uVar2 = FUN_2703b15e(DAT_2707ca14,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb60,uVar2);
    return;
  case 0x138a:
    uVar4 = 100;
    uVar3 = 0xffffff9c;
    puVar1 = (undefined4 *)((int)DAT_2707ca14 + 0x84);
    uVar2 = FUN_2703b15e(DAT_2707ca14,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb60,uVar2,uVar3,uVar4);
    return;
  case 0x138c:
    (*DAT_2707c9c4)(param_1 + 0xc,0x3f800000,param_2 + 0xb60);
    break;
  case 0x1393:
    puVar1 = (undefined4 *)((int)DAT_2707ca14 + 0x4c);
    uVar2 = FUN_2703b15e(DAT_2707ca14,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb6c,uVar2);
    return;
  case 0x139d:
    puVar1 = (undefined4 *)((int)DAT_2707ca14 + 0x4c);
    uVar2 = FUN_2703b15e(DAT_2707ca14,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb78,uVar2);
    return;
  case 0x13a7:
    puVar1 = (undefined4 *)((int)DAT_2707ca14 + 0x4c);
    uVar2 = FUN_2703b15e(DAT_2707ca14,(byte *)(param_1 + 0xc));
    (*(code *)*puVar1)(param_2 + 0xb84,uVar2);
    return;
  }
  return;
}


// HUD_TempEntUpdate  @ 27015e30
void __cdecl
HUD_TempEntUpdate(double param_1,double param_2,double param_3,uint *param_4,int *param_5,
                 undefined *param_6,undefined *param_7)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  code *pcVar8;
  float *pfVar9;
  undefined1 *puVar10;
  uint *puVar11;
  float10 fVar12;
  float10 fVar13;
  longlong lVar14;
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
  
                    /* 0x15e30  443  HUD_TempEntUpdate */
  if (*param_5 != 0) {
    (**(code **)(DAT_2707ca18 + 0x28))(0,1);
    (**(code **)(DAT_2707ca18 + 0x2c))();
    (**(code **)(DAT_2707ca18 + 0x34))(0xffffffff);
    DAT_2707cd68 = DAT_2707cd68 + 1 & 0x1f;
    puVar11 = (uint *)*param_5;
    if (0.0 < param_1) {
      puStack_94 = (uint *)0x0;
      fStack_90 = (float)((float10)param_2 * (float10)5.5);
      fVar2 = (float)-((float10)param_1 * (float10)param_3);
      fStack_8c = (float)(-((float10)param_1 * (float10)param_3) * (float10)0.5);
      puVar6 = puStack_94;
      while (puVar5 = puVar11, puStack_94 = puVar6, puVar5 != (uint *)0x0) {
        puVar11 = (uint *)puVar5[0xb];
        if (0.0 <= (float)puVar5[1] - (float)param_2) {
LAB_27015f9e:
          pfVar1 = (float *)(puVar5 + 0x2e3);
          puVar5[0x6c] = puVar5[0x2e3];
          puVar5[0x6d] = puVar5[0x2e4];
          puVar5[0x6e] = puVar5[0x2e5];
          puStack_94 = puVar5;
          if ((*puVar5 & 0x20000) == 0) {
            uVar4 = *puVar5;
            if ((uVar4 & 0x8000) == 0) {
              if ((uVar4 & 1) == 0) {
                if ((uVar4 & 0x400) == 0) {
                  iVar7 = 3;
                  pfVar9 = pfVar1;
                  do {
                    iVar7 = iVar7 + -1;
                    *pfVar9 = pfVar9[-0x2cc] * (float)param_1 + *pfVar9;
                    pfVar9 = pfVar9 + 1;
                  } while (iVar7 != 0);
                  goto LAB_270161bb;
                }
                fVar13 = (float10)fsin((float10)param_2 * (float10)20.0 + (float10)(int)puVar5);
                *pfVar1 = (float)((float10)(float)puVar5[0x17] * (float10)param_1 +
                                  fVar13 * (float10)8.0 + (float10)*pfVar1);
                fVar13 = (float10)fsin((float10)param_2 * (float10)30.0 + (float10)(int)puVar5);
                puVar5[0x2e4] =
                     (uint)(float)((float10)(float)puVar5[0x18] * (float10)param_1 +
                                   fVar13 * (float10)4.0 + (float10)(float)puVar5[0x2e4]);
              }
              else {
                fVar13 = (float10)(float)puVar5[0x17] * (float10)param_1 + (float10)(float)puVar5[3]
                ;
                puVar5[3] = (uint)(float)fVar13;
                puVar5[4] = (uint)((float)puVar5[0x18] * (float)param_1 + (float)puVar5[4]);
                fVar12 = (float10)fsin((float10)(float)puVar5[0x74] * (float10)param_2 +
                                       (float10)(float)puVar5[0x19]);
                *pfVar1 = (float)(fVar13 + (float10)(float)puVar5[0xd5] * (float10)10.0 * fVar12);
                fVar13 = (float10)fsin((float10)fStack_90 + (float10)(float)puVar5[0x19] +
                                       (float10)0.7);
                puVar5[0x2e4] =
                     (uint)(float)((float10)(float)puVar5[0xd5] * (float10)8.0 * fVar13 +
                                  (float10)(float)puVar5[4]);
              }
              puVar5[0x2e5] = (uint)((float)puVar5[0x19] * (float)param_1 + (float)puVar5[0x2e5]);
            }
            else {
              iVar7 = (*DAT_2707c99c)((int)(short)puVar5[0xd]);
              *pfVar1 = *(float *)(iVar7 + 0xb48) + (float)puVar5[0xe];
              puVar5[0x2e4] = (uint)(*(float *)(iVar7 + 0xb4c) + (float)puVar5[0xf]);
              puVar5[0x2e5] = (uint)(*(float *)(iVar7 + 0xb50) + (float)puVar5[0x10]);
            }
          }
          else if ((float)puVar5[0x23] < (float)param_2) {
            (**(code **)(DAT_2707ca14 + 0x84))(pfVar1,8,0xffffff38,200);
            fVar3 = (float)puVar5[0x2b];
            puVar5[0x2b] = (uint)(fVar3 - 0.1);
            if (0.0 < fVar3 - 0.1) {
              puVar5[1] = (uint)(float)((float10)param_2 + (float10)0.5);
              puVar5[0x23] = (uint)(float)((float10)param_2 + (float10)0.1);
            }
            else {
              puVar5[1] = (uint)(float)param_2;
            }
          }
LAB_270161bb:
          if ((*puVar5 & 0x100) == 0) {
            if (((*puVar5 & 0x800) != 0) &&
               (fVar13 = (float10)param_1 * (float10)10.0 + (float10)(float)puVar5[0xc9],
               puVar5[0xc9] = (uint)(float)fVar13, (float10)(float)puVar5[2] <= fVar13)) {
              lVar14 = __ftol();
              puVar5[0xc9] = (uint)((float)puVar5[0xc9] - (float)(int)lVar14);
            }
LAB_27016263:
            if ((*puVar5 & 4) != 0) {
              puVar5[0x2e6] = (uint)((float)puVar5[0x1a] * (float)param_1 + (float)puVar5[0x2e6]);
              puVar5[0x2e7] = (uint)((float)puVar5[0x1b] * (float)param_1 + (float)puVar5[0x2e7]);
              puVar5[0x2e8] = (uint)((float)puVar5[0x1c] * (float)param_1 + (float)puVar5[0x2e8]);
              puVar5[0x2db] = puVar5[0x2e6];
              puVar5[0x2dc] = puVar5[0x2e7];
              puVar5[0x2dd] = puVar5[0x2e8];
            }
            uVar4 = *puVar5;
            if ((uVar4 & 0x1020) != 0) {
              if ((uVar4 & 0x1000) == 0) {
                if ((uVar4 & 0x20) != 0) {
                  (**(code **)(DAT_2707ca18 + 0x38))(2);
                  (**(code **)(DAT_2707ca18 + 0x3c))(puVar5 + 0x6c,pfVar1,10,0xffffffff,auStack_44);
                  if (fStack_34 != 1.0) {
                    fStack_a0 = fStack_24;
                    fStack_a4 = fStack_34;
                    fStack_9c = fStack_20;
                    fStack_98 = fStack_1c;
                    if ((*puVar5 & 0x20000) != 0) {
                      pfVar9 = (float *)(puVar5 + 0x17);
                      FUN_2702af30(pfVar9,0.6,pfVar9);
                      fVar13 = FUN_270204d0(pfVar9);
                      if (fVar13 < (float10)10.0) {
                        puVar5[0x2b] = 0;
                      }
                    }
                    pcVar8 = (code *)puVar5[9];
                    if (pcVar8 != (code *)0x0) {
                      puVar10 = auStack_44;
                      goto LAB_27016437;
                    }
                    goto LAB_2701643e;
                  }
                }
              }
              else {
                (**(code **)(DAT_2707ca18 + 0x38))(2);
                (**(code **)(DAT_2707ca18 + 0x3c))(puVar5 + 0x6c,pfVar1,2,0xffffffff,auStack_88);
                if ((fStack_78 != 1.0) &&
                   ((iVar7 = (**(code **)(DAT_2707ca18 + 0x24))(iStack_58), iStack_58 == 0 ||
                    (*(int *)(iVar7 + 0x50) != (int)(short)puVar5[0xd])))) {
                  fStack_a0 = fStack_68;
                  pcVar8 = (code *)puVar5[9];
                  fStack_a4 = fStack_78;
                  fStack_9c = fStack_64;
                  fStack_98 = fStack_60;
                  if (pcVar8 != (code *)0x0) {
                    puVar10 = auStack_88;
LAB_27016437:
                    (*pcVar8)(puVar5,puVar10);
                  }
LAB_2701643e:
                  if (fStack_a4 != 1.0) {
                    pfVar9 = (float *)(puVar5 + 0x17);
                    FUN_2702af60((float *)(puVar5 + 0x6c),fStack_a4 * (float)param_1,pfVar9,pfVar1);
                    fStack_b4 = (float)puVar5[7];
                    if (((((*puVar5 & 10) != 0) && (fStack_b4 = fStack_b4 * 0.5, 0.9 < fStack_98))
                        && ((float)puVar5[0x19] <= 0.0)) && (fVar2 * 3.0 <= (float)puVar5[0x19])) {
                      fStack_b4 = 0.0;
                      *puVar5 = *puVar5 & 0xffffffc1;
                      puVar5[0x2e6] = 0;
                      puVar5[0x2e8] = 0;
                    }
                    if (puVar5[8] != 0) {
                      (*(code *)param_7)(puVar5,fStack_b4);
                    }
                    if ((*puVar5 & 0x4000) == 0) {
                      if (fStack_b4 != 0.0) {
                        FUN_2702af60(pfVar9,(fStack_a0 * *pfVar9 +
                                            fStack_98 * (float)puVar5[0x19] +
                                            fStack_9c * (float)puVar5[0x18]) * -2.0,&fStack_a0,
                                     pfVar9);
                        puVar5[0x2e7] = (uint)-(float)puVar5[0x2e7];
                      }
                      if (fStack_b4 != 1.0) {
                        FUN_2702af30(pfVar9,fStack_b4,pfVar9);
                        FUN_2702af30((float *)(puVar5 + 0x2e6),0.9,(float *)(puVar5 + 0x2e6));
                      }
                    }
                    else {
                      puVar5[1] = (uint)(float)param_2;
                      *puVar5 = *puVar5 & 0xffffff7f;
                    }
                  }
                }
              }
            }
            if (((*puVar5 & 0x40) != 0) && (DAT_2707cd68 == puVar5[0xcc])) {
              pfVar9 = (float *)(**(code **)(DAT_2707ca14 + 0x100))(0);
              *pfVar9 = *pfVar1;
              pfVar9[1] = (float)puVar5[0x2e4];
              pfVar9[2] = (float)puVar5[0x2e5];
              pfVar9[3] = 60.0;
              pfVar9[5] = (float)((float10)param_2 + (float10)0.01);
              *(undefined1 *)(pfVar9 + 4) = 0xff;
              *(undefined1 *)((int)pfVar9 + 0x11) = 0x78;
              *(undefined1 *)((int)pfVar9 + 0x12) = 0;
            }
            if ((*puVar5 & 0x10) != 0) {
              (**(code **)(DAT_2707ca14 + 0x78))(puVar5 + 0x6c,pfVar1,1);
            }
            fVar3 = fVar2;
            if (((*puVar5 & 2) != 0) || (fVar3 = fStack_8c, (*puVar5 & 8) != 0)) {
              puVar5[0x19] = (uint)(fVar3 + (float)puVar5[0x19]);
            }
            if (((*puVar5 & 0x80000) != 0) && ((code *)puVar5[10] != (code *)0x0)) {
              (*(code *)puVar5[10])(puVar5,(float)param_1,(float)param_2);
            }
            puVar6 = puStack_94;
            if ((((*puVar5 & 0x40000) == 0) &&
                (iVar7 = (*(code *)param_6)(puVar5 + 0x11), puVar6 = puStack_94, iVar7 == 0)) &&
               ((*puVar5 & 0x2000) == 0)) {
              puVar5[1] = (uint)(float)param_2;
              *puVar5 = *puVar5 & 0xffffff7f;
            }
          }
          else {
            fVar3 = (float)puVar5[0xd5] * (float)param_1 + (float)puVar5[0xc9];
            puVar5[0xc9] = (uint)fVar3;
            if (fVar3 < (float)puVar5[2]) goto LAB_27016263;
            lVar14 = __ftol();
            puVar5[0xc9] = (uint)((float)puVar5[0xc9] - (float)(int)lVar14);
            if ((*puVar5 & 0x10000) != 0) goto LAB_27016263;
            puVar5[1] = (uint)(float)param_2;
            puVar6 = puStack_94;
          }
        }
        else {
          if ((*puVar5 & 0x80) != 0) {
            if (puVar5[0xcf] == 0) {
              puVar5[0xcf] = 2;
            }
            lVar14 = __ftol();
            puVar5[0xd0] = (uint)lVar14;
            if (0 < (int)(uint)lVar14) goto LAB_27015f9e;
          }
          puVar5[0xb] = *param_4;
          *param_4 = (uint)puVar5;
          if (puVar6 == (uint *)0x0) {
            *param_5 = (int)puVar11;
            puVar6 = puStack_94;
          }
          else {
            puVar6[0xb] = (uint)puVar11;
            puVar6 = puStack_94;
          }
        }
      }
    }
    else if (puVar11 != (uint *)0x0) {
      do {
        if ((*puVar11 & 0x40000) == 0) {
          (*(code *)param_6)(puVar11 + 0x11);
        }
        puVar11 = (uint *)puVar11[0xb];
      } while (puVar11 != (uint *)0x0);
      (**(code **)(DAT_2707ca18 + 0x30))();
      return;
    }
    (**(code **)(DAT_2707ca18 + 0x30))();
  }
  return;
}


// HUD_TxferLocalOverrides  @ 27015a00
void __cdecl HUD_TxferLocalOverrides(int param_1,undefined4 *param_2)

{
                    /* 0x15a00  444  HUD_TxferLocalOverrides */
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x104) = param_2[99];
  *(undefined4 *)(param_1 + 0x108) = param_2[100];
  *(undefined4 *)(param_1 + 0x10c) = param_2[0x65];
  *(undefined4 *)(param_1 + 0x110) = param_2[0x66];
  return;
}


// HUD_TxferPredictionData  @ 27015bd0
void __cdecl
HUD_TxferPredictionData
          (int param_1,int param_2,int param_3,int param_4,undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  
                    /* 0x15bd0  445  HUD_TxferPredictionData */
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
  if ((*(int *)(param_4 + 0x18c) != 0) || (DAT_270655b4 = 0, iVar1 == 0)) {
    DAT_270655b4 = 1;
  }
  *(undefined4 *)(param_3 + 0x18c) = *(undefined4 *)(param_4 + 0x18c);
  *(undefined4 *)(param_3 + 400) = *(undefined4 *)(param_4 + 400);
  *(undefined4 *)(param_3 + 0x194) = *(undefined4 *)(param_4 + 0x194);
  *(undefined4 *)(param_3 + 0x198) = *(undefined4 *)(param_4 + 0x198);
  for (iVar1 = 0x2c0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_5 = *param_6;
    param_6 = param_6 + 1;
    param_5 = param_5 + 1;
  }
  return;
}


// HUD_UpdateClientData  @ 27014e70
void __cdecl HUD_UpdateClientData(undefined4 *param_1)

{
                    /* 0x14e70  446  HUD_UpdateClientData */
  FUN_2701e810();
  FUN_2701bf10(&DAT_2707bf70,param_1);
  return;
}


// HUD_VidInit  @ 27014e10
undefined4 HUD_VidInit(void)

{
                    /* 0x14e10  447  HUD_VidInit */
  FUN_27018640(&DAT_2707bf70);
  FUN_2702de40();
  return 1;
}


