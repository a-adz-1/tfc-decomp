// UpdateClientData__11CBasePlayer  @ 000db8f4
void UpdateClientData__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int **ppiVar9;
  undefined2 in_FPUControlWord;
  int *piStack_9c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  piStack_9c = (int *)0xdb905;
  if (param_1[0x21f] != 0) {
    param_1[0x21f] = 0;
    gInitHUD = 0;
    piStack_9c = *(int **)(*param_1 + 0x208);
    (*DAT_0019f758)(1,gmsgResetHUD,0);
    piStack_9c = (int *)0x0;
    (*DAT_0019f760)();
    (*DAT_0019f75c)();
    if (param_1[0x220] == 0) {
      piStack_9c = *(int **)(*param_1 + 0x208);
      (*DAT_0019f758)(1,gmsgInitHUD,0);
      piStack_9c = (int *)0xdb9c2;
      (*DAT_0019f75c)();
      piStack_9c = *(int **)(*param_1 + 0x208);
      (*DAT_0019f758)(1,gmsgSetSecAmmoIcon,0);
      piStack_9c = (int *)0x150b08;
      (*DAT_0019f778)();
      (*DAT_0019f75c)();
      (**(code **)(*g_pGameRules + 0x38))(g_pGameRules,param_1);
      param_1[0x220] = 1;
      param_1[0x1ab] = 3;
    }
    piStack_9c = param_1;
    TeamFortress_InitStatusBar__11CBasePlayer();
    iVar6 = 0;
    do {
      param_1[iVar6 + 0x25b] = -1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x20);
  }
  ppiVar9 = (int **)&stack0xffffff68;
  if (param_1[0x368] != 0) {
    piStack_9c = *(int **)(*param_1 + 0x208);
    UTIL_ShowMessage__FPCcP7edict_s(param_1[0x368] + (int)gpGlobals[0x26]);
    param_1[0x368] = 0;
  }
  if (param_1[0x22d] != param_1[0x22e]) {
    piStack_9c = *(int **)(*param_1 + 0x208);
    (*DAT_0019f758)(1,gmsgHideWeapon,0);
    piStack_9c = (int *)param_1[0x22d];
    (*DAT_0019f760)();
    (*DAT_0019f75c)();
    param_1[0x22e] = param_1[0x22d];
  }
  if (param_1[0x22f] != param_1[0x230]) {
    piStack_9c = *(int **)(*param_1 + 0x208);
    (*DAT_0019f758)(1,gmsgSetFOV,0);
    piStack_9c = (int *)param_1[0x22f];
    (*DAT_0019f760)();
    (*DAT_0019f75c)();
    param_1[0x230] = param_1[0x22f];
  }
  iVar6 = *param_1;
  fVar2 = (float)param_1[0x22b];
  fVar1 = *(float *)(iVar6 + 0x160);
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 0x40) {
    if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
      fVar1 = 0.0;
    }
    uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    piStack_9c = *(int **)(iVar6 + 0x208);
    (*DAT_0019f758)(1,gmsgHealth,0);
    piStack_9c = (int *)(int)ROUND(fVar1);
    (*DAT_0019f760)();
    (*DAT_0019f75c)();
    iVar6 = *param_1;
    _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
    uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    param_1[0x22b] = (int)ROUND(*(float *)(iVar6 + 0x160));
  }
  if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar6 + 0x1d8)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(iVar6 + 0x1d8) == 0.0) << 0xe) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar6 + 0x1dc)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(iVar6 + 0x1dc) == 0.0) << 0xe) >> 8)) == 0x40)) &&
     (param_1[0x21e] == param_1[0x197])) goto LAB_000dbe80;
  uStack_1c = *(undefined4 *)(iVar6 + 8);
  uStack_18 = *(undefined4 *)(iVar6 + 0xc);
  uStack_14 = *(undefined4 *)(iVar6 + 0x10);
  piVar5 = *(int **)(iVar6 + 0x18c);
  bVar4 = false;
  if ((piVar5 == (int *)0x0) || (piStack_9c = piVar5, iVar6 = (*DAT_0019f7b8)(), iVar6 == 0)) {
    bVar4 = true;
  }
  ppiVar9 = (int **)&stack0xffffff68;
  if ((!bVar4) && (ppiVar9 = (int **)&stack0xffffff68, *piVar5 == 0)) {
    if (piVar5 == (int *)0x0) {
      piStack_9c = (int *)0x0;
      piVar5 = (int *)(*DAT_0019f7b4)();
      if (piVar5 != (int *)0x0) goto LAB_000dbd15;
      piVar5 = (int *)0x0;
    }
    else {
LAB_000dbd15:
      piVar5 = (int *)piVar5[0x1f];
    }
    ppiVar9 = (int **)&stack0xffffff68;
    if (piVar5 != (int *)0x0) {
      piStack_9c = piVar5;
      (**(code **)(piVar5[0x115] + 0xcc))(&uStack_28);
      uStack_1c = uStack_28;
      uStack_18 = uStack_24;
      uStack_14 = uStack_20;
      ppiVar9 = &piStack_9c;
    }
  }
  *(undefined4 *)((int)ppiVar9 + -4) = *(undefined4 *)(*param_1 + 0x208);
  *(undefined4 *)((int)ppiVar9 + -8) = 0;
  *(undefined4 *)((int)ppiVar9 + -0xc) = gmsgDamage;
  *(undefined4 *)((int)ppiVar9 + -0x10) = 1;
  *(undefined4 *)((int)ppiVar9 + -0x14) = 0xdbd71;
  (*DAT_0019f758)();
  uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
  *(int *)((int)ppiVar9 + -4) = (int)ROUND(*(float *)(*param_1 + 0x1dc));
  *(undefined4 *)((int)ppiVar9 + -8) = 0xdbda5;
  (*DAT_0019f760)();
  _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
  uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
  *(int *)((int)ppiVar9 + -8) = (int)ROUND(*(float *)(*param_1 + 0x1d8));
  *(undefined4 *)((int)ppiVar9 + -0xc) = 0xdbdd6;
  (*DAT_0019f760)();
  *(int *)((int)ppiVar9 + -0xc) = param_1[0x197];
  *(undefined4 *)((int)ppiVar9 + -0x10) = 0xdbdee;
  (*DAT_0019f76c)();
  *(undefined4 *)((int)ppiVar9 + -0x10) = uStack_1c;
  *(undefined4 *)((int)ppiVar9 + -0x14) = 0xdbe05;
  (*DAT_0019f774)();
  *(undefined4 *)((int)ppiVar9 + -0x14) = uStack_18;
  *(undefined4 *)((int)ppiVar9 + -0x18) = 0xdbe1c;
  (*DAT_0019f774)();
  *(undefined4 *)((int)ppiVar9 + -0x18) = uStack_14;
  *(undefined4 *)((int)ppiVar9 + -0x1c) = 0xdbe33;
  (*DAT_0019f774)();
  *(undefined4 *)((int)ppiVar9 + -0x1c) = 0xdbe41;
  (*DAT_0019f75c)();
  *(undefined4 *)(*param_1 + 0x1d8) = 0;
  *(undefined4 *)(*param_1 + 0x1dc) = 0;
  param_1[0x21e] = param_1[0x197];
  param_1[0x197] = param_1[0x197] & 0x7fc000;
LAB_000dbe80:
  if ((param_1[0x21] & 1U) != param_1[0x1f]) {
    *(undefined4 *)((int)ppiVar9 + -4) = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)((int)ppiVar9 + -8) = 0;
    *(undefined4 *)((int)ppiVar9 + -0xc) = gmsgStatusIcon;
    *(undefined4 *)((int)ppiVar9 + -0x10) = 1;
    *(undefined4 *)((int)ppiVar9 + -0x14) = 0xdbebc;
    (*DAT_0019f758)();
    *(uint *)((int)ppiVar9 + -4) = param_1[0x21] & 1;
    *(undefined4 *)((int)ppiVar9 + -8) = 0xdbeda;
    (*DAT_0019f760)();
    *(undefined4 *)((int)ppiVar9 + -8) = 100;
    *(undefined4 *)((int)ppiVar9 + -0xc) = 0xdbeea;
    (*DAT_0019f764)();
    *(undefined4 *)((int)ppiVar9 + -0xc) = 0x5f;
    *(undefined4 *)((int)ppiVar9 + -0x10) = 0xdbefa;
    (*DAT_0019f764)();
    if (param_1[0x15] == 0) {
      pcVar7 = "normalgrenade";
    }
    else {
      pcVar7 = (char *)(param_1[0x15] + (int)gpGlobals[0x26]);
    }
    *(char **)((int)ppiVar9 + -4) = pcVar7;
    *(undefined4 *)((int)ppiVar9 + -8) = 0xdbf2f;
    (*DAT_0019f778)();
    *(undefined4 *)((int)ppiVar9 + -8) = 0xff;
    *(undefined4 *)((int)ppiVar9 + -0xc) = 0xdbf42;
    (*DAT_0019f760)();
    *(undefined4 *)((int)ppiVar9 + -0xc) = 0xa0;
    *(undefined4 *)((int)ppiVar9 + -0x10) = 0xdbf55;
    (*DAT_0019f760)();
    *(undefined4 *)((int)ppiVar9 + -0x10) = 0;
    *(undefined4 *)((int)ppiVar9 + -0x14) = 0xdbf65;
    (*DAT_0019f760)();
    *(undefined4 *)((int)ppiVar9 + -0x14) = 0xdbf73;
    (*DAT_0019f75c)();
    param_1[0x1f] = param_1[0x21] & 1U;
    if ((param_1[0x21] & 1U) == 0) {
      param_1[0x15] = 0;
    }
  }
  iVar6 = param_1[0x237];
  iVar8 = 0;
  if (iVar6 != 0) {
    iVar8 = *(int *)(iVar6 + 0x454);
    *(int **)((int)ppiVar9 + -4) = param_1;
    *(int *)((int)ppiVar9 + -8) = iVar6;
    pcVar3 = *(code **)(iVar8 + 0x14c);
    *(undefined4 *)((int)ppiVar9 + -0xc) = 0xdbfab;
    (*pcVar3)();
    iVar8 = param_1[0x237];
  }
  param_1[0x238] = iVar8;
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x371];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    *(int **)((int)ppiVar9 + -4) = param_1;
    *(undefined4 *)((int)ppiVar9 + -8) = 0xdbfe2;
    UpdateLowPriorityClientData__11CBasePlayer();
    *(int **)((int)ppiVar9 + -8) = param_1;
    *(undefined4 *)((int)ppiVar9 + -0xc) = 0xdbfe8;
    TeamFortress_UpdateStatusBar__11CBasePlayer();
    param_1[0x371] = (int)(*gpGlobals + 0.2);
  }
  *(int **)((int)ppiVar9 + -4) = param_1;
  *(undefined4 *)((int)ppiVar9 + -8) = 0xdc013;
  UpdateClientCommandMenu__11CBasePlayer();
  return;
}


// UpdateClientData__15CBasePlayerItemP11CBasePlayer  @ 00126658
undefined4 UpdateClientData__15CBasePlayerItemP11CBasePlayer(void)

{
  return 0;
}


// UpdateClientData__17CBasePlayerWeaponP11CBasePlayer  @ 001241c0
undefined4 UpdateClientData__17CBasePlayerWeaponP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = param_2[0x237];
  uVar2 = (uint)(iVar1 == param_1);
  bVar3 = param_2[0x222] == 0;
  if (((param_1 == iVar1) || (param_1 == param_2[0x238])) && (iVar1 != param_2[0x238])) {
    bVar3 = true;
  }
  if ((*(int *)(param_1 + 0x4c0) != *(int *)(param_1 + 0x4c4)) ||
     (uVar2 != *(uint *)(param_1 + 0x4c8))) {
    bVar3 = true;
  }
  if (bVar3) {
    (*DAT_0019f758)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(uVar2);
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x47c));
    (*DAT_0019f760)(*(undefined4 *)(param_1 + 0x4c0));
    (*DAT_0019f75c)();
    *(undefined4 *)(param_1 + 0x4c4) = *(undefined4 *)(param_1 + 0x4c0);
    *(uint *)(param_1 + 0x4c8) = uVar2;
    param_2[0x222] = 1;
  }
  iVar1 = *(int *)(param_1 + 0x478);
  if (iVar1 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x454) + 0x14c))(iVar1,param_2);
  }
  return 1;
}


// UpdateClientData__FPC7edict_siP12clientdata_s  @ 000938b4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateClientData__FPC7edict_siP12clientdata_s(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  char *__src;
  int iVar5;
  undefined2 in_FPUControlWord;
  int local_44;
  int *local_40;
  undefined1 local_3c [32];
  undefined4 local_1c;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  iVar5 = param_1 + 0x80;
  iVar1 = *(int *)(param_1 + 0x288);
  if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
    local_40 = (int *)0x0;
  }
  else {
    local_40 = *(int **)(iVar1 + 0x7c);
  }
  local_44 = 0;
  iVar1 = iVar5;
  if (*(int *)(*local_40 + 0x244) == 4) {
    iVar2 = __opi__7EHANDLE(local_40 + 0x1a7);
    if (iVar2 != 0) {
      piVar3 = (int *)__rf__7EHANDLE(local_40 + 0x1a7);
      iVar1 = *piVar3;
      iVar2 = *(int *)(iVar1 + 0x208);
      local_44 = iVar5;
      if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
        local_40 = (int *)0x0;
      }
      else {
        local_40 = *(int **)(iVar2 + 0x7c);
      }
    }
  }
  param_3[10] = *(undefined4 *)(iVar1 + 0x1a4);
  param_3[0x10] = *(undefined4 *)(iVar1 + 0x160);
  uVar4 = (*DAT_0019f6ac)(*(int *)(iVar1 + 0xbc) + *(int *)(gpGlobals + 0x98));
  param_3[6] = uVar4;
  param_3[0xb] = *(undefined4 *)(iVar1 + 0x1c0);
  param_3[0xc] = *(undefined4 *)(iVar1 + 0x1c4);
  param_3[0x12] = *(undefined4 *)(iVar1 + 0x168);
  *param_3 = *(undefined4 *)(iVar1 + 8);
  param_3[1] = *(undefined4 *)(iVar1 + 0xc);
  param_3[2] = *(undefined4 *)(iVar1 + 0x10);
  param_3[3] = *(undefined4 *)(iVar1 + 0x20);
  param_3[4] = *(undefined4 *)(iVar1 + 0x24);
  param_3[5] = *(undefined4 *)(iVar1 + 0x28);
  param_3[0xd] = *(undefined4 *)(iVar1 + 0x174);
  param_3[0xe] = *(undefined4 *)(iVar1 + 0x178);
  param_3[0xf] = *(undefined4 *)(iVar1 + 0x17c);
  param_3[7] = *(undefined4 *)(iVar1 + 0x68);
  param_3[8] = *(undefined4 *)(iVar1 + 0x6c);
  param_3[9] = *(undefined4 *)(iVar1 + 0x70);
  param_3[0x11] = *(undefined4 *)(iVar1 + 0x220);
  param_3[0x13] = *(undefined4 *)(iVar1 + 0x224);
  param_3[0x14] = *(undefined4 *)(iVar1 + 0x22c);
  param_3[0x15] = *(undefined4 *)(iVar1 + 0x228);
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  local_10 = (int)ROUND(*(float *)(iVar1 + 0x1b4));
  param_3[0x16] = local_10;
  __src = (char *)(*_DAT_0019f884)(param_1);
  strcpy((char *)(param_3 + 0x23),__src);
  param_3[0x17] = *(undefined4 *)(iVar1 + 0x210);
  param_3[0x18] = *(undefined4 *)(iVar1 + 0x214);
  param_3[0x19] = *(undefined4 *)(iVar1 + 0x218);
  param_3[0x21] = *(undefined4 *)(iVar1 + 0x21c);
  if (local_44 == 0) {
    param_3[99] = *(undefined4 *)(iVar1 + 0x244);
    param_3[100] = *(undefined4 *)(iVar1 + 0x248);
    param_3[0x65] = *(undefined4 *)(iVar1 + 0x24c);
    param_3[0x66] = *(undefined4 *)(iVar1 + 0x250);
  }
  else {
    param_3[99] = *(undefined4 *)(local_44 + 0x244);
    param_3[100] = *(undefined4 *)(local_44 + 0x248);
    param_3[0x65] = *(undefined4 *)(local_44 + 0x248);
  }
  param_3[0x22] = *(undefined4 *)(iVar1 + 0x170);
  if ((param_2 != 0) && (local_40 != (int *)0x0)) {
    param_3[0x1b] = local_40[0x33];
    param_3[0x1c] = local_40[0x35];
    param_3[0x1d] = local_40[0x37];
    param_3[0x1e] = local_40[0x39];
    param_3[0x1f] = local_40[0x196];
    iVar1 = local_40[0x237];
    if ((iVar1 != 0) && (iVar1 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x150))(iVar1), iVar1 != 0))
    {
      memset(local_3c,0,0x2c);
      (**(code **)(*(int *)(iVar1 + 0x454) + 0x118))(iVar1,local_3c);
      param_3[0x1a] = local_1c;
    }
  }
  return;
}


