// UpdateClientData__11CBasePlayer  @ 000d1430
void UpdateClientData__11CBasePlayer(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  float fVar5;
  bool bVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int **ppiVar10;
  undefined2 in_FPUControlWord;
  undefined2 uVar11;
  int *piStack_44;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  piStack_44 = (int *)0xd143c;
  if (param_1[0x1f9] != 0) {
    param_1[0x1f9] = 0;
    gInitHUD = 0;
    piStack_44 = *(int **)(*param_1 + 0x208);
    (*DAT_001a7ef8)(1,gmsgResetHUD,0);
    piStack_44 = (int *)0x0;
    (*DAT_001a7f00)();
    (*DAT_001a7efc)();
    if (param_1[0x1fa] == 0) {
      piStack_44 = *(int **)(*param_1 + 0x208);
      (*DAT_001a7ef8)(1,gmsgInitHUD,0);
      piStack_44 = (int *)0xd14f4;
      (*DAT_001a7efc)();
      piStack_44 = *(int **)(*param_1 + 0x208);
      (*DAT_001a7ef8)(1,gmsgSetSecAmmoIcon,0);
      piStack_44 = (int *)0x13af00;
      (*DAT_001a7f18)();
      (*DAT_001a7efc)();
      (**(code **)(*g_pGameRules + 0x38))(g_pGameRules,param_1);
      param_1[0x1fa] = 1;
    }
    piStack_44 = param_1;
    TeamFortress_InitStatusBar__11CBasePlayer();
    iVar9 = 0x1f;
    piVar7 = param_1 + 0x253;
    do {
      *piVar7 = -1;
      piVar7[-1] = -1;
      piVar7[-2] = -1;
      piVar7[-3] = -1;
      piVar7[-4] = -1;
      piVar7[-5] = -1;
      piVar7[-6] = -1;
      piVar7[-7] = -1;
      piVar7[-8] = -1;
      piVar7[-9] = -1;
      piVar7[-10] = -1;
      piVar7[-0xb] = -1;
      piVar7[-0xc] = -1;
      piVar7[-0xd] = -1;
      piVar7[-0xe] = -1;
      piVar7[-0xf] = -1;
      piVar7 = piVar7 + -0x10;
      iVar9 = iVar9 + -0x10;
    } while (-1 < iVar9);
  }
  ppiVar10 = (int **)&stack0xffffffc0;
  if (param_1[0x207] != param_1[0x208]) {
    piStack_44 = *(int **)(*param_1 + 0x208);
    (*DAT_001a7ef8)(1,gmsgHideWeapon,0);
    piStack_44 = (int *)param_1[0x207];
    (*DAT_001a7f00)();
    (*DAT_001a7efc)();
    param_1[0x208] = param_1[0x207];
  }
  if (param_1[0x209] != param_1[0x20a]) {
    piStack_44 = *(int **)(*param_1 + 0x208);
    (*DAT_001a7ef8)(1,gmsgSetFOV,0);
    piStack_44 = (int *)param_1[0x209];
    (*DAT_001a7f00)();
    (*DAT_001a7efc)();
    param_1[0x20a] = param_1[0x209];
  }
  fVar5 = (float)param_1[0x205];
  fVar1 = *(float *)(*param_1 + 0x160);
  if ((byte)(fVar1 < fVar5 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar5)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar5) << 0xe) >> 8)) != 0x40) {
    if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
      fVar1 = 0.0;
    }
    uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    piStack_44 = *(int **)(*param_1 + 0x208);
    (*DAT_001a7ef8)(1,gmsgHealth,0);
    piStack_44 = (int *)(int)ROUND(fVar1);
    (*DAT_001a7f00)();
    (*DAT_001a7efc)();
    _uStack_4 = CONCAT22(uStack_2,in_FPUControlWord);
    uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    param_1[0x205] = (int)ROUND(*(float *)(*param_1 + 0x160));
  }
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) &&
      (fVar1 = *(float *)(*param_1 + 0x1dc),
      (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) &&
     (param_1[0x1f8] == param_1[0x177])) goto LAB_000d19f5;
  iVar9 = *param_1;
  uStack_18 = *(undefined4 *)(iVar9 + 8);
  uStack_14 = *(undefined4 *)(iVar9 + 0xc);
  uStack_10 = *(undefined4 *)(iVar9 + 0x10);
  piVar7 = *(int **)(iVar9 + 0x18c);
  bVar6 = false;
  if ((piVar7 == (int *)0x0) || (piStack_44 = piVar7, iVar9 = (*DAT_001a7f58)(), iVar9 == 0)) {
    bVar6 = true;
  }
  ppiVar10 = (int **)&stack0xffffffc0;
  if ((!bVar6) && (ppiVar10 = (int **)&stack0xffffffc0, *piVar7 == 0)) {
    if (piVar7 == (int *)0x0) {
      piStack_44 = (int *)0x0;
      piVar7 = (int *)(*DAT_001a7f54)();
      if (piVar7 != (int *)0x0) goto LAB_000d1853;
      piVar7 = (int *)0x0;
    }
    else {
LAB_000d1853:
      piVar7 = (int *)piVar7[0x1f];
    }
    ppiVar10 = (int **)&stack0xffffffc0;
    if (piVar7 != (int *)0x0) {
      piStack_44 = piVar7;
      (**(code **)(piVar7[0xf5] + 0xc4))(&uStack_24);
      uStack_18 = uStack_24;
      uStack_14 = uStack_20;
      ppiVar10 = &piStack_44;
    }
  }
  uVar2 = *(undefined4 *)(*param_1 + 0x208);
  *(undefined4 *)((int)ppiVar10 + 0x14) = uVar2;
  *(undefined4 *)((int)ppiVar10 + -4) = uVar2;
  *(undefined4 *)((int)ppiVar10 + -8) = 0;
  *(undefined4 *)((int)ppiVar10 + -0xc) = gmsgDamage;
  *(undefined4 *)((int)ppiVar10 + -0x10) = 1;
  *(code **)((int)ppiVar10 + 0x14) = DAT_001a7ef8;
  *(undefined4 *)((int)ppiVar10 + -0x14) = 0xd18bb;
  (*DAT_001a7ef8)();
  fVar1 = *(float *)(*param_1 + 0x1dc);
  *(undefined2 *)((int)ppiVar10 + 0x3c) = in_FPUControlWord;
  *(uint *)((int)ppiVar10 + 0x34) =
       CONCAT22((short)((uint)*(undefined4 *)((int)ppiVar10 + 0x3c) >> 0x10),
                CONCAT11(0xc,(char)*(undefined4 *)((int)ppiVar10 + 0x3c)));
  *(int *)((int)ppiVar10 + 0x14) = (int)ROUND(fVar1);
  uVar11 = *(undefined2 *)((int)ppiVar10 + 0x3c);
  *(undefined4 *)((int)ppiVar10 + -4) = *(undefined4 *)((int)ppiVar10 + 0x14);
  *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f00;
  *(undefined4 *)((int)ppiVar10 + -8) = 0xd18f9;
  (*DAT_001a7f00)();
  fVar1 = *(float *)(*param_1 + 0x1d8);
  *(undefined2 *)((int)ppiVar10 + 0x3c) = uVar11;
  *(uint *)((int)ppiVar10 + 0x34) =
       CONCAT22((short)((uint)*(undefined4 *)((int)ppiVar10 + 0x3c) >> 0x10),
                CONCAT11(0xc,(char)*(undefined4 *)((int)ppiVar10 + 0x3c)));
  *(int *)((int)ppiVar10 + 0x14) = (int)ROUND(fVar1);
  *(undefined4 *)((int)ppiVar10 + -8) = *(undefined4 *)((int)ppiVar10 + 0x14);
  *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f00;
  *(undefined4 *)((int)ppiVar10 + -0xc) = 0xd1934;
  (*DAT_001a7f00)();
  *(int *)((int)ppiVar10 + -0xc) = param_1[0x177];
  *(code **)((int)ppiVar10 + 0x14) = pcRam001a7f0c;
  *(undefined4 *)((int)ppiVar10 + -0x10) = 0xd194f;
  (*pcRam001a7f0c)();
  *(undefined4 *)((int)ppiVar10 + -0x10) = *(undefined4 *)((int)ppiVar10 + 0x28);
  *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f14;
  *(undefined4 *)((int)ppiVar10 + -0x14) = 0xd196d;
  (*DAT_001a7f14)();
  *(undefined4 *)((int)ppiVar10 + -0x14) = *(undefined4 *)((int)ppiVar10 + 0x2c);
  *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f14;
  *(undefined4 *)((int)ppiVar10 + -0x18) = 0xd198b;
  (*DAT_001a7f14)();
  *(undefined4 *)((int)ppiVar10 + -0x18) = *(undefined4 *)((int)ppiVar10 + 0x30);
  *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f14;
  *(undefined4 *)((int)ppiVar10 + -0x1c) = 0xd19a9;
  (*DAT_001a7f14)();
  *(code **)((int)ppiVar10 + 0x14) = DAT_001a7efc;
  *(undefined4 *)((int)ppiVar10 + -0x1c) = 0xd19bd;
  (*DAT_001a7efc)();
  *(undefined4 *)(*param_1 + 0x1d8) = 0;
  *(undefined4 *)(*param_1 + 0x1dc) = 0;
  param_1[0x1f8] = param_1[0x177];
  param_1[0x177] = param_1[0x177] & 0xffc000;
  *(byte *)((int)param_1 + 0x5de) = *(byte *)((int)param_1 + 0x5de) & 0x7f;
LAB_000d19f5:
  if ((param_1[0x21] & 1U) != param_1[0x1f]) {
    *(undefined4 *)((int)ppiVar10 + -4) = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)((int)ppiVar10 + -8) = 0;
    *(undefined4 *)((int)ppiVar10 + -0xc) = gmsgStatusIcon;
    *(undefined4 *)((int)ppiVar10 + -0x10) = 1;
    *(undefined4 *)((int)ppiVar10 + -0x14) = 0xd1a2b;
    (*DAT_001a7ef8)();
    *(uint *)((int)ppiVar10 + -4) = param_1[0x21] & 1;
    *(undefined4 *)((int)ppiVar10 + -8) = 0xd1a46;
    (*DAT_001a7f00)();
    *(undefined4 *)((int)ppiVar10 + -8) = 100;
    *(undefined4 *)((int)ppiVar10 + -0xc) = 0xd1a56;
    (*DAT_001a7f04)();
    *(undefined4 *)((int)ppiVar10 + -0xc) = 0x5f;
    *(undefined4 *)((int)ppiVar10 + -0x10) = 0xd1a66;
    (*DAT_001a7f04)();
    if (param_1[0x15] == 0) {
      pcVar8 = "normalgrenade";
    }
    else {
      pcVar8 = (char *)(param_1[0x15] + (int)gpGlobals[0x26]);
    }
    *(char **)((int)ppiVar10 + -4) = pcVar8;
    *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f18;
    *(undefined4 *)((int)ppiVar10 + -8) = 0xd1aa1;
    (*DAT_001a7f18)();
    *(undefined4 *)((int)ppiVar10 + -8) = 0xff;
    *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f00;
    *(undefined4 *)((int)ppiVar10 + -0xc) = 0xd1aba;
    (*DAT_001a7f00)();
    *(undefined4 *)((int)ppiVar10 + -0xc) = 0xa0;
    *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f00;
    *(undefined4 *)((int)ppiVar10 + -0x10) = 0xd1ad3;
    (*DAT_001a7f00)();
    *(undefined4 *)((int)ppiVar10 + -0x10) = 0;
    *(code **)((int)ppiVar10 + 0x14) = DAT_001a7f00;
    *(undefined4 *)((int)ppiVar10 + -0x14) = 0xd1ae9;
    (*DAT_001a7f00)();
    *(code **)((int)ppiVar10 + 0x14) = DAT_001a7efc;
    *(undefined4 *)((int)ppiVar10 + -0x14) = 0xd1afd;
    (*DAT_001a7efc)();
    param_1[0x1f] = param_1[0x21] & 1;
    if ((*(byte *)(param_1 + 0x21) & 1) == 0) {
      param_1[0x15] = 0;
    }
  }
  if (param_1[0x211] != 0) {
    iVar9 = param_1[0x211];
    iVar3 = *(int *)(iVar9 + 0x3d4);
    *(int **)((int)ppiVar10 + -4) = param_1;
    *(int *)((int)ppiVar10 + -8) = iVar9;
    pcVar4 = *(code **)(iVar3 + 0x144);
    *(undefined4 *)((int)ppiVar10 + -0xc) = 0xd1b3b;
    (*pcVar4)();
  }
  param_1[0x212] = param_1[0x211];
  if ((float)param_1[0x34a] < *gpGlobals) {
    *(int **)((int)ppiVar10 + -4) = param_1;
    *(undefined4 *)((int)ppiVar10 + -8) = 0xd1b67;
    UpdateLowPriorityClientData__11CBasePlayer();
    *(int **)((int)ppiVar10 + -8) = param_1;
    *(undefined4 *)((int)ppiVar10 + -0xc) = 0xd1b6d;
    TeamFortress_UpdateStatusBar__11CBasePlayer();
    *(float *)((int)ppiVar10 + 0x18) = *gpGlobals + 0.2;
    param_1[0x34a] = *(int *)((int)ppiVar10 + 0x18);
  }
  *(int **)((int)ppiVar10 + -4) = param_1;
  *(undefined4 *)((int)ppiVar10 + -8) = 0xd1b94;
  UpdateClientCommandMenu__11CBasePlayer();
  return;
}


// UpdateClientData__15CBasePlayerItemP11CBasePlayer  @ 00112428
undefined4 UpdateClientData__15CBasePlayerItemP11CBasePlayer(void)

{
  return 0;
}


// UpdateClientData__17CBasePlayerWeaponP11CBasePlayer  @ 001108c4
undefined4 UpdateClientData__17CBasePlayerWeaponP11CBasePlayer(int param_1,int *param_2)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (uint)(param_2[0x211] == param_1);
  bVar2 = param_2[0x1fc] == 0;
  if (((param_1 == param_2[0x211]) || (param_1 == param_2[0x212])) &&
     (param_2[0x211] != param_2[0x212])) {
    bVar2 = true;
  }
  if ((*(int *)(param_1 + 0x440) != *(int *)(param_1 + 0x444)) ||
     (uVar1 != *(uint *)(param_1 + 0x448))) {
    bVar2 = true;
  }
  if (bVar2) {
    (*DAT_001a7ef8)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f00)(uVar1);
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x3fc));
    (*DAT_001a7f00)(*(undefined4 *)(param_1 + 0x440));
    (*DAT_001a7efc)();
    *(undefined4 *)(param_1 + 0x444) = *(undefined4 *)(param_1 + 0x440);
    *(uint *)(param_1 + 0x448) = uVar1;
    param_2[0x1fc] = 1;
  }
  if (*(int *)(param_1 + 0x3f8) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x3f8) + 0x3d4) + 0x144))
              (*(int *)(param_1 + 0x3f8),param_2);
  }
  return 1;
}


// UpdateClientData__FPC7edict_siP12clientdata_s  @ 0008bc88
void UpdateClientData__FPC7edict_siP12clientdata_s(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  char *__src;
  int iVar2;
  undefined2 in_FPUControlWord;
  undefined1 local_38 [32];
  undefined4 local_18;
  int local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  param_3[10] = *(undefined4 *)(param_1 + 0x224);
  param_3[0x10] = *(undefined4 *)(param_1 + 0x1e0);
  uVar1 = (*DAT_001a7e4c)(*(int *)(param_1 + 0x13c) + *(int *)(gpGlobals + 0x98));
  param_3[6] = uVar1;
  param_3[0xb] = *(undefined4 *)(param_1 + 0x240);
  param_3[0xc] = *(undefined4 *)(param_1 + 0x244);
  param_3[0x12] = *(undefined4 *)(param_1 + 0x1e8);
  *param_3 = *(undefined4 *)(param_1 + 0x88);
  param_3[1] = *(undefined4 *)(param_1 + 0x8c);
  param_3[2] = *(undefined4 *)(param_1 + 0x90);
  param_3[3] = *(undefined4 *)(param_1 + 0xa0);
  param_3[4] = *(undefined4 *)(param_1 + 0xa4);
  param_3[5] = *(undefined4 *)(param_1 + 0xa8);
  param_3[0xd] = *(undefined4 *)(param_1 + 500);
  param_3[0xe] = *(undefined4 *)(param_1 + 0x1f8);
  param_3[0xf] = *(undefined4 *)(param_1 + 0x1fc);
  param_3[7] = *(undefined4 *)(param_1 + 0xe8);
  param_3[8] = *(undefined4 *)(param_1 + 0xec);
  param_3[9] = *(undefined4 *)(param_1 + 0xf0);
  param_3[0x11] = *(undefined4 *)(param_1 + 0x2a0);
  param_3[0x13] = *(undefined4 *)(param_1 + 0x2a4);
  param_3[0x14] = *(undefined4 *)(param_1 + 0x2ac);
  param_3[0x15] = *(undefined4 *)(param_1 + 0x2a8);
  _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
  local_c = (int)ROUND(*(float *)(param_1 + 0x234));
  param_3[0x16] = local_c;
  __src = (char *)(*DAT_001a8024)(param_1);
  strcpy((char *)(param_3 + 0x23),__src);
  param_3[0x17] = *(undefined4 *)(param_1 + 0x290);
  param_3[0x18] = *(undefined4 *)(param_1 + 0x294);
  param_3[0x19] = *(undefined4 *)(param_1 + 0x298);
  param_3[0x21] = *(undefined4 *)(param_1 + 0x29c);
  param_3[99] = *(undefined4 *)(param_1 + 0x2c4);
  param_3[100] = *(undefined4 *)(param_1 + 0x2c8);
  param_3[0x65] = *(undefined4 *)(param_1 + 0x2cc);
  param_3[0x22] = *(undefined4 *)(param_1 + 0x1f0);
  if (param_2 != 0) {
    iVar2 = *(int *)(param_1 + 0x288);
    if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 != 0) {
      param_3[0x1b] = *(undefined4 *)(iVar2 + 0xcc);
      param_3[0x1c] = *(undefined4 *)(iVar2 + 0xd4);
      param_3[0x1d] = *(undefined4 *)(iVar2 + 0xdc);
      param_3[0x1e] = *(undefined4 *)(iVar2 + 0xe4);
      param_3[0x1f] = *(undefined4 *)(iVar2 + 0x5d8);
      if ((*(int *)(iVar2 + 0x844) != 0) &&
         (iVar2 = (**(code **)(*(int *)(*(int *)(iVar2 + 0x844) + 0x3d4) + 0x148))
                            (*(int *)(iVar2 + 0x844)), iVar2 != 0)) {
        memset(local_38,0,0x2c);
        (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x110))(iVar2,local_38);
        param_3[0x1a] = local_18;
      }
    }
    return;
  }
  return;
}


