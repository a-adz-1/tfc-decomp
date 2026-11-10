// UpdateClientData__11CBasePlayer  @ 000dcaf8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateClientData__11CBasePlayer(code *param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  bool bVar5;
  code *pcVar6;
  char *pcVar7;
  int iVar8;
  code **ppcVar9;
  undefined2 in_FPUControlWord;
  undefined2 uVar10;
  code *pcStack_44;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  pcStack_44 = (code *)0xdcb04;
  if (*(int *)(param_1 + 0x854) != 0) {
    *(int *)(param_1 + 0x854) = 0;
    gInitHUD = 0;
    pcStack_44 = *(code **)(*(int *)param_1 + 0x208);
    (*DAT_001c10d8)(1,gmsgResetHUD,0);
    pcStack_44 = (code *)0x0;
    (*DAT_001c10e0)();
    (*DAT_001c10dc)();
    if (*(int *)(param_1 + 0x858) == 0) {
      pcStack_44 = *(code **)(*(int *)param_1 + 0x208);
      (*DAT_001c10d8)(1,gmsgInitHUD,0);
      pcStack_44 = (code *)0xdcbbc;
      (*DAT_001c10dc)();
      pcStack_44 = *(code **)(*(int *)param_1 + 0x208);
      (*DAT_001c10d8)(1,gmsgSetSecAmmoIcon,0);
      pcStack_44 = FUN_0014b860;
      (*DAT_001c10f8)();
      (*DAT_001c10dc)();
      (**(code **)(*g_pGameRules + 0x38))(g_pGameRules,param_1);
      *(int *)(param_1 + 0x858) = 1;
    }
    pcStack_44 = param_1;
    TeamFortress_InitStatusBar__11CBasePlayer();
    iVar8 = 0x1f;
    pcVar6 = param_1 + 0x9c0;
    do {
      *(int *)pcVar6 = -1;
      *(int *)(pcVar6 + -4) = -1;
      *(int *)(pcVar6 + -8) = -1;
      *(int *)(pcVar6 + -0xc) = -1;
      *(int *)(pcVar6 + -0x10) = -1;
      *(int *)(pcVar6 + -0x14) = -1;
      *(int *)(pcVar6 + -0x18) = -1;
      *(int *)(pcVar6 + -0x1c) = -1;
      *(int *)(pcVar6 + -0x20) = -1;
      *(int *)(pcVar6 + -0x24) = -1;
      *(int *)(pcVar6 + -0x28) = -1;
      *(int *)(pcVar6 + -0x2c) = -1;
      *(int *)(pcVar6 + -0x30) = -1;
      *(int *)(pcVar6 + -0x34) = -1;
      *(int *)(pcVar6 + -0x38) = -1;
      *(int *)(pcVar6 + -0x3c) = -1;
      pcVar6 = pcVar6 + -0x40;
      iVar8 = iVar8 + -0x10;
    } while (-1 < iVar8);
  }
  ppcVar9 = (code **)&stack0xffffffc0;
  if (*(int *)(param_1 + 0xd84) != 0) {
    pcStack_44 = *(code **)(*(int *)param_1 + 0x208);
    UTIL_ShowMessage__FPCcP7edict_s(*(int *)(param_1 + 0xd84) + (int)gpGlobals[0x26]);
    *(int *)(param_1 + 0xd84) = 0;
  }
  if (*(int *)(param_1 + 0x88c) != *(int *)(param_1 + 0x890)) {
    pcStack_44 = *(code **)(*(int *)param_1 + 0x208);
    (*DAT_001c10d8)(1,gmsgHideWeapon,0);
    pcStack_44 = *(code **)(param_1 + 0x88c);
    (*DAT_001c10e0)();
    (*DAT_001c10dc)();
    *(int *)(param_1 + 0x890) = *(int *)(param_1 + 0x88c);
  }
  if (*(int *)(param_1 + 0x894) != *(int *)(param_1 + 0x898)) {
    pcStack_44 = *(code **)(*(int *)param_1 + 0x208);
    (*DAT_001c10d8)(1,gmsgSetFOV,0);
    pcStack_44 = *(code **)(param_1 + 0x894);
    (*DAT_001c10e0)();
    (*DAT_001c10dc)();
    *(int *)(param_1 + 0x898) = *(int *)(param_1 + 0x894);
  }
  fVar4 = (float)*(int *)(param_1 + 0x884);
  fVar1 = *(float *)(*(int *)param_1 + 0x160);
  if ((byte)(fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) != 0x40) {
    if (0x3f < (byte)((_FUN_0014b880 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(_FUN_0014b880) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(_FUN_0014b880 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = _FUN_0014b880;
    }
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    pcStack_44 = *(code **)(*(int *)param_1 + 0x208);
    (*DAT_001c10d8)(1,gmsgHealth,0);
    pcStack_44 = (code *)(int)ROUND(fVar1);
    (*DAT_001c10e0)();
    (*DAT_001c10dc)();
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    *(int *)(param_1 + 0x884) = (int)ROUND(*(float *)(*(int *)param_1 + 0x160));
  }
  fVar1 = *(float *)(*(int *)param_1 + 0x1d8);
  if ((((byte)((byte)((ushort)((ushort)(NAN(_FUN_0014b880) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(_FUN_0014b880 == fVar1) << 0xe) >> 8)) == 0x40) &&
      (fVar1 = *(float *)(*(int *)param_1 + 0x1dc),
      (byte)((byte)((ushort)((ushort)(NAN(fVar1) || NAN(_FUN_0014b880)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == _FUN_0014b880) << 0xe) >> 8)) == 0x40)) &&
     (*(int *)(param_1 + 0x850) == *(int *)(param_1 + 0x64c))) goto LAB_000dd0f9;
  iVar8 = *(int *)param_1;
  local_18 = *(undefined4 *)(iVar8 + 8);
  local_14 = *(undefined4 *)(iVar8 + 0xc);
  local_10 = *(undefined4 *)(iVar8 + 0x10);
  pcVar6 = *(code **)(iVar8 + 0x18c);
  bVar5 = false;
  if ((pcVar6 == (code *)0x0) || (pcStack_44 = pcVar6, iVar8 = (*DAT_001c1138)(), iVar8 == 0)) {
    bVar5 = true;
  }
  ppcVar9 = (code **)&stack0xffffffc0;
  if ((!bVar5) && (ppcVar9 = (code **)&stack0xffffffc0, *(int *)pcVar6 == 0)) {
    if (pcVar6 == (code *)0x0) {
      pcStack_44 = (code *)0x0;
      pcVar6 = (code *)(*DAT_001c1134)();
      if (pcVar6 != (code *)0x0) goto LAB_000dcf54;
      pcVar6 = (code *)0x0;
    }
    else {
LAB_000dcf54:
      pcVar6 = *(code **)(pcVar6 + 0x7c);
    }
    ppcVar9 = (code **)&stack0xffffffc0;
    if (pcVar6 != (code *)0x0) {
      pcStack_44 = pcVar6;
      (**(code **)(*(int *)(pcVar6 + 0x444) + 0xcc))(&local_24);
      local_18 = local_24;
      local_14 = local_20;
      ppcVar9 = &pcStack_44;
    }
  }
  uVar2 = *(undefined4 *)(*(int *)param_1 + 0x208);
  *(undefined4 *)((int)ppcVar9 + 0x14) = uVar2;
  *(undefined4 *)((int)ppcVar9 + -4) = uVar2;
  *(undefined4 *)((int)ppcVar9 + -8) = 0;
  *(undefined4 *)((int)ppcVar9 + -0xc) = gmsgDamage;
  *(undefined4 *)((int)ppcVar9 + -0x10) = 1;
  *(code **)((int)ppcVar9 + 0x14) = DAT_001c10d8;
  *(undefined4 *)((int)ppcVar9 + -0x14) = 0xdcfbf;
  (*DAT_001c10d8)();
  fVar1 = *(float *)(*(int *)param_1 + 0x1dc);
  *(undefined2 *)((int)ppcVar9 + 0x3c) = in_FPUControlWord;
  *(uint *)((int)ppcVar9 + 0x34) =
       CONCAT22((short)((uint)*(undefined4 *)((int)ppcVar9 + 0x3c) >> 0x10),
                CONCAT11(0xc,(char)*(undefined4 *)((int)ppcVar9 + 0x3c)));
  *(int *)((int)ppcVar9 + 0x14) = (int)ROUND(fVar1);
  uVar10 = *(undefined2 *)((int)ppcVar9 + 0x3c);
  *(undefined4 *)((int)ppcVar9 + -4) = *(undefined4 *)((int)ppcVar9 + 0x14);
  *(code **)((int)ppcVar9 + 0x14) = DAT_001c10e0;
  *(undefined4 *)((int)ppcVar9 + -8) = 0xdcffd;
  (*DAT_001c10e0)();
  fVar1 = *(float *)(*(int *)param_1 + 0x1d8);
  *(undefined2 *)((int)ppcVar9 + 0x3c) = uVar10;
  *(uint *)((int)ppcVar9 + 0x34) =
       CONCAT22((short)((uint)*(undefined4 *)((int)ppcVar9 + 0x3c) >> 0x10),
                CONCAT11(0xc,(char)*(undefined4 *)((int)ppcVar9 + 0x3c)));
  *(int *)((int)ppcVar9 + 0x14) = (int)ROUND(fVar1);
  *(undefined4 *)((int)ppcVar9 + -8) = *(undefined4 *)((int)ppcVar9 + 0x14);
  *(code **)((int)ppcVar9 + 0x14) = DAT_001c10e0;
  *(undefined4 *)((int)ppcVar9 + -0xc) = 0xdd038;
  (*DAT_001c10e0)();
  *(int *)((int)ppcVar9 + -0xc) = *(int *)(param_1 + 0x64c);
  *(code **)((int)ppcVar9 + 0x14) = DAT_001c10ec;
  *(undefined4 *)((int)ppcVar9 + -0x10) = 0xdd053;
  (*DAT_001c10ec)();
  *(undefined4 *)((int)ppcVar9 + -0x10) = *(undefined4 *)((int)ppcVar9 + 0x28);
  *(code **)((int)ppcVar9 + 0x14) = DAT_001c10f4;
  *(undefined4 *)((int)ppcVar9 + -0x14) = 0xdd071;
  (*DAT_001c10f4)();
  *(undefined4 *)((int)ppcVar9 + -0x14) = *(undefined4 *)((int)ppcVar9 + 0x2c);
  *(code **)((int)ppcVar9 + 0x14) = DAT_001c10f4;
  *(undefined4 *)((int)ppcVar9 + -0x18) = 0xdd08f;
  (*DAT_001c10f4)();
  *(undefined4 *)((int)ppcVar9 + -0x18) = *(undefined4 *)((int)ppcVar9 + 0x30);
  *(code **)((int)ppcVar9 + 0x14) = DAT_001c10f4;
  *(undefined4 *)((int)ppcVar9 + -0x1c) = 0xdd0ad;
  (*DAT_001c10f4)();
  *(code **)((int)ppcVar9 + 0x14) = DAT_001c10dc;
  *(undefined4 *)((int)ppcVar9 + -0x1c) = 0xdd0c1;
  (*DAT_001c10dc)();
  *(undefined4 *)(*(int *)param_1 + 0x1d8) = 0;
  *(undefined4 *)(*(int *)param_1 + 0x1dc) = 0;
  *(int *)(param_1 + 0x850) = *(int *)(param_1 + 0x64c);
  *(uint *)(param_1 + 0x64c) = *(uint *)(param_1 + 0x64c) & 0xffc000;
  param_1[0x64e] = (code)((byte)param_1[0x64e] & 0x7f);
LAB_000dd0f9:
  if ((*(uint *)(param_1 + 0x84) & 1) != *(uint *)(param_1 + 0x7c)) {
    *(undefined4 *)((int)ppcVar9 + -4) = *(undefined4 *)(*(int *)param_1 + 0x208);
    *(undefined4 *)((int)ppcVar9 + -8) = 0;
    *(undefined4 *)((int)ppcVar9 + -0xc) = gmsgStatusIcon;
    *(undefined4 *)((int)ppcVar9 + -0x10) = 1;
    *(undefined4 *)((int)ppcVar9 + -0x14) = 0xdd12f;
    (*DAT_001c10d8)();
    *(uint *)((int)ppcVar9 + -4) = *(uint *)(param_1 + 0x84) & 1;
    *(undefined4 *)((int)ppcVar9 + -8) = 0xdd14a;
    (*DAT_001c10e0)();
    *(undefined4 *)((int)ppcVar9 + -8) = 100;
    *(undefined4 *)((int)ppcVar9 + -0xc) = 0xdd15a;
    (*DAT_001c10e4)();
    *(undefined4 *)((int)ppcVar9 + -0xc) = 0x5f;
    *(undefined4 *)((int)ppcVar9 + -0x10) = 0xdd16a;
    (*DAT_001c10e4)();
    if (*(int *)(param_1 + 0x54) == 0) {
      pcVar7 = "normalgrenade";
    }
    else {
      pcVar7 = (char *)(*(int *)(param_1 + 0x54) + (int)gpGlobals[0x26]);
    }
    *(char **)((int)ppcVar9 + -4) = pcVar7;
    *(code **)((int)ppcVar9 + 0x14) = DAT_001c10f8;
    *(undefined4 *)((int)ppcVar9 + -8) = 0xdd1a5;
    (*DAT_001c10f8)();
    *(undefined4 *)((int)ppcVar9 + -8) = 0xff;
    *(code **)((int)ppcVar9 + 0x14) = DAT_001c10e0;
    *(undefined4 *)((int)ppcVar9 + -0xc) = 0xdd1be;
    (*DAT_001c10e0)();
    *(undefined4 *)((int)ppcVar9 + -0xc) = 0xa0;
    *(code **)((int)ppcVar9 + 0x14) = DAT_001c10e0;
    *(undefined4 *)((int)ppcVar9 + -0x10) = 0xdd1d7;
    (*DAT_001c10e0)();
    *(undefined4 *)((int)ppcVar9 + -0x10) = 0;
    *(code **)((int)ppcVar9 + 0x14) = DAT_001c10e0;
    *(undefined4 *)((int)ppcVar9 + -0x14) = 0xdd1ed;
    (*DAT_001c10e0)();
    *(code **)((int)ppcVar9 + 0x14) = DAT_001c10dc;
    *(undefined4 *)((int)ppcVar9 + -0x14) = 0xdd201;
    (*DAT_001c10dc)();
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x84) & 1;
    if (((byte)param_1[0x84] & 1) == 0) {
      *(int *)(param_1 + 0x54) = 0;
    }
  }
  if (*(int *)(param_1 + 0x8b4) != 0) {
    iVar8 = *(int *)(param_1 + 0x8b4);
    iVar3 = *(int *)(iVar8 + 0x444);
    *(code **)((int)ppcVar9 + -4) = param_1;
    *(int *)((int)ppcVar9 + -8) = iVar8;
    pcVar6 = *(code **)(iVar3 + 0x14c);
    *(undefined4 *)((int)ppcVar9 + -0xc) = 0xdd23f;
    (*pcVar6)();
  }
  *(int *)(param_1 + 0x8b8) = *(int *)(param_1 + 0x8b4);
  if (*(float *)(param_1 + 0xda8) < *gpGlobals) {
    *(code **)((int)ppcVar9 + -4) = param_1;
    *(undefined4 *)((int)ppcVar9 + -8) = 0xdd26b;
    UpdateLowPriorityClientData__11CBasePlayer();
    *(code **)((int)ppcVar9 + -8) = param_1;
    *(undefined4 *)((int)ppcVar9 + -0xc) = 0xdd271;
    TeamFortress_UpdateStatusBar__11CBasePlayer();
    *(float *)((int)ppcVar9 + 0x18) = *gpGlobals + 0.2;
    *(int *)(param_1 + 0xda8) = *(int *)((int)ppcVar9 + 0x18);
  }
  *(code **)((int)ppcVar9 + -4) = param_1;
  *(undefined4 *)((int)ppcVar9 + -8) = 0xdd298;
  UpdateClientCommandMenu__11CBasePlayer();
  return;
}


// UpdateClientData__15CBasePlayerItemP11CBasePlayer  @ 00121fd8
undefined4 UpdateClientData__15CBasePlayerItemP11CBasePlayer(void)

{
  return 0;
}


// UpdateClientData__17CBasePlayerWeaponP11CBasePlayer  @ 00120414
undefined4 UpdateClientData__17CBasePlayerWeaponP11CBasePlayer(int param_1,int *param_2)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (uint)(param_2[0x22d] == param_1);
  bVar2 = param_2[0x218] == 0;
  if (((param_1 == param_2[0x22d]) || (param_1 == param_2[0x22e])) &&
     (param_2[0x22d] != param_2[0x22e])) {
    bVar2 = true;
  }
  if ((*(int *)(param_1 + 0x4b0) != *(int *)(param_1 + 0x4b4)) ||
     (uVar1 != *(uint *)(param_1 + 0x4b8))) {
    bVar2 = true;
  }
  if (bVar2) {
    (*DAT_001c10d8)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10e0)(uVar1);
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x46c));
    (*DAT_001c10e0)(*(undefined4 *)(param_1 + 0x4b0));
    (*DAT_001c10dc)();
    *(undefined4 *)(param_1 + 0x4b4) = *(undefined4 *)(param_1 + 0x4b0);
    *(uint *)(param_1 + 0x4b8) = uVar1;
    param_2[0x218] = 1;
  }
  if (*(int *)(param_1 + 0x468) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x468) + 0x444) + 0x14c))
              (*(int *)(param_1 + 0x468),param_2);
  }
  return 1;
}


// UpdateClientData__FPC7edict_siP12clientdata_s  @ 00094738
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
  uVar1 = (*DAT_001c102c)(*(int *)(param_1 + 0x13c) + *(int *)(gpGlobals + 0x98));
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
  __src = (char *)(*DAT_001c1204)(param_1);
  strcpy((char *)(param_3 + 0x23),__src);
  param_3[0x17] = *(undefined4 *)(param_1 + 0x290);
  param_3[0x18] = *(undefined4 *)(param_1 + 0x294);
  param_3[0x19] = *(undefined4 *)(param_1 + 0x298);
  param_3[0x21] = *(undefined4 *)(param_1 + 0x29c);
  param_3[99] = *(undefined4 *)(param_1 + 0x2c4);
  param_3[100] = *(undefined4 *)(param_1 + 0x2c8);
  param_3[0x65] = *(undefined4 *)(param_1 + 0x2cc);
  param_3[0x66] = *(undefined4 *)(param_1 + 0x2d0);
  param_3[0x22] = *(undefined4 *)(param_1 + 0x1f0);
  if (param_2 != 0) {
    iVar2 = *(int *)(param_1 + 0x288);
    if ((iVar2 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
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
      param_3[0x1f] = *(undefined4 *)(iVar2 + 0x648);
      if ((*(int *)(iVar2 + 0x8b4) != 0) &&
         (iVar2 = (**(code **)(*(int *)(*(int *)(iVar2 + 0x8b4) + 0x444) + 0x150))
                            (*(int *)(iVar2 + 0x8b4)), iVar2 != 0)) {
        memset(local_38,0,0x2c);
        (**(code **)(*(int *)(iVar2 + 0x444) + 0x118))(iVar2,local_38);
        param_3[0x1a] = local_18;
      }
    }
    return;
  }
  return;
}


