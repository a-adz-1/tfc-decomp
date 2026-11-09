// UpdateClientData__11CBasePlayer  @ 000de6e0
void UpdateClientData__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  int *piVar7;
  int **ppiVar8;
  undefined2 in_FPUControlWord;
  int *piStack_40;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int *local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  if (param_1[500] != 0) {
    param_1[500] = 0;
    gInitHUD = 0;
    piStack_40 = *(int **)(*param_1 + 0x1e8);
    (*DAT_00175578)(1,gmsgResetHUD,0);
    piStack_40 = (int *)0x0;
    (*DAT_00175580)();
    (*DAT_0017557c)();
    if (param_1[0x1f5] == 0) {
      piStack_40 = *(int **)(*param_1 + 0x1e8);
      (*DAT_00175578)(1,gmsgInitHUD,0);
      piStack_40 = (int *)0xde76c;
      (*DAT_0017557c)();
      piStack_40 = *(int **)(*param_1 + 0x1e8);
      (*DAT_00175578)(1,gmsgSetSecAmmoIcon,0);
      piStack_40 = (int *)0x13a3d8;
      (*DAT_00175598)();
      (*DAT_0017557c)();
      (**(code **)(*g_pGameRules + 0x38))(g_pGameRules,param_1);
      param_1[0x1f5] = 1;
    }
    piStack_40 = param_1;
    TeamFortress_InitStatusBar__11CBasePlayer();
  }
  ppiVar8 = (int **)&stack0xffffffc4;
  if (param_1[0x202] != param_1[0x203]) {
    piStack_40 = *(int **)(*param_1 + 0x1e8);
    (*DAT_00175578)(1,gmsgHideWeapon,0);
    piStack_40 = (int *)param_1[0x202];
    (*DAT_00175580)();
    (*DAT_0017557c)();
    param_1[0x203] = param_1[0x202];
  }
  if (param_1[0x204] != param_1[0x205]) {
    piStack_40 = *(int **)(*param_1 + 0x1e8);
    (*DAT_00175578)(1,gmsgSetFOV,0);
    piStack_40 = (int *)param_1[0x204];
    (*DAT_00175580)();
    (*DAT_0017557c)();
    param_1[0x205] = param_1[0x204];
  }
  fVar2 = (float)param_1[0x200];
  fVar1 = *(float *)(*param_1 + 0x140);
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 0x40) {
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      piVar7 = (int *)(int)ROUND(fVar1);
      local_10 = piVar7;
    }
    else {
      piVar7 = (int *)0x0;
    }
    piStack_40 = *(int **)(*param_1 + 0x1e8);
    (*DAT_00175578)(1,gmsgHealth,0);
    piStack_40 = piVar7;
    (*DAT_00175580)();
    (*DAT_0017557c)();
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = (int *)CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    param_1[0x200] = (int)ROUND(*(float *)(*param_1 + 0x140));
  }
  fVar1 = *(float *)(*param_1 + 0x1b8);
  if ((((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) &&
      (fVar1 = *(float *)(*param_1 + 0x1bc),
      (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) &&
     (param_1[499] == param_1[0x174])) goto LAB_000deab0;
  iVar6 = *param_1;
  local_1c = *(undefined4 *)(iVar6 + 8);
  local_18 = *(undefined4 *)(iVar6 + 0xc);
  local_14 = *(undefined4 *)(iVar6 + 0x10);
  piVar7 = *(int **)(iVar6 + 0x16c);
  bVar5 = false;
  if ((piVar7 == (int *)0x0) || (piStack_40 = piVar7, iVar6 = (*DAT_001755d8)(), iVar6 == 0)) {
    bVar5 = true;
  }
  ppiVar8 = (int **)&stack0xffffffc4;
  if ((!bVar5) && (ppiVar8 = (int **)&stack0xffffffc4, *piVar7 == 0)) {
    if (piVar7 == (int *)0x0) {
      piStack_40 = (int *)0x0;
      piVar7 = (int *)(*DAT_001755d4)();
      if (piVar7 != (int *)0x0) goto LAB_000de993;
      piVar7 = (int *)0x0;
    }
    else {
LAB_000de993:
      piVar7 = (int *)piVar7[0x36];
    }
    ppiVar8 = (int **)&stack0xffffffc4;
    if (piVar7 != (int *)0x0) {
      piStack_40 = piVar7;
      (**(code **)(piVar7[0xf2] + 0xc4))(&local_28);
      local_1c = local_28;
      local_18 = local_24;
      local_14 = local_20;
      ppiVar8 = &piStack_40;
    }
  }
  *(undefined4 *)((int)ppiVar8 + -4) = *(undefined4 *)(*param_1 + 0x1e8);
  *(undefined4 *)((int)ppiVar8 + -8) = 0;
  *(undefined4 *)((int)ppiVar8 + -0xc) = gmsgDamage;
  *(undefined4 *)((int)ppiVar8 + -0x10) = 1;
  *(undefined4 *)((int)ppiVar8 + -0x14) = 0xde9e9;
  (*DAT_00175578)();
  local_10 = (int *)CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
  *(int *)((int)ppiVar8 + -4) = (int)ROUND(*(float *)(*param_1 + 0x1bc));
  *(undefined4 *)((int)ppiVar8 + -8) = 0xdea13;
  (*DAT_00175580)();
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  local_10 = (int *)CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
  *(int *)((int)ppiVar8 + -8) = (int)ROUND(*(float *)(*param_1 + 0x1b8));
  *(undefined4 *)((int)ppiVar8 + -0xc) = 0xdea3a;
  (*DAT_00175580)();
  *(int *)((int)ppiVar8 + -0xc) = param_1[0x174];
  *(undefined4 *)((int)ppiVar8 + -0x10) = 0xdea48;
  (*DAT_0017558c)();
  *(undefined4 *)((int)ppiVar8 + -0x10) = local_1c;
  *(undefined4 *)((int)ppiVar8 + -0x14) = 0xdea58;
  (*DAT_00175594)();
  *(undefined4 *)((int)ppiVar8 + -0x14) = local_18;
  *(undefined4 *)((int)ppiVar8 + -0x18) = 0xdea68;
  (*DAT_00175594)();
  *(undefined4 *)((int)ppiVar8 + -0x18) = local_14;
  *(undefined4 *)((int)ppiVar8 + -0x1c) = 0xdea78;
  (*DAT_00175594)();
  *(undefined4 *)((int)ppiVar8 + -0x1c) = 0xdea7f;
  (*DAT_0017557c)();
  *(undefined4 *)(*param_1 + 0x1b8) = 0;
  *(undefined4 *)(*param_1 + 0x1bc) = 0;
  param_1[499] = param_1[0x174];
  param_1[0x174] = param_1[0x174] & 0xffc000;
LAB_000deab0:
  if (param_1[0x20c] != 0) {
    iVar6 = param_1[0x20c];
    iVar3 = *(int *)(iVar6 + 0x3c8);
    *(int **)((int)ppiVar8 + -4) = param_1;
    *(int *)((int)ppiVar8 + -8) = iVar6;
    pcVar4 = *(code **)(iVar3 + 0x144);
    *(undefined4 *)((int)ppiVar8 + -0xc) = 0xdeacf;
    (*pcVar4)();
  }
  param_1[0x20d] = param_1[0x20c];
  fVar1 = (float)param_1[0x33e];
  fVar2 = *gpGlobals;
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
    *(int **)((int)ppiVar8 + -4) = param_1;
    *(undefined4 *)((int)ppiVar8 + -8) = 0xdeafb;
    UpdateLowPriorityClientData__11CBasePlayer();
    *(int **)((int)ppiVar8 + -8) = param_1;
    *(undefined4 *)((int)ppiVar8 + -0xc) = 0xdeb01;
    TeamFortress_UpdateStatusBar__11CBasePlayer();
    param_1[0x33e] = (int)(*gpGlobals + 0.2);
  }
  return;
}


// UpdateClientData__15CBasePlayerItemP11CBasePlayer  @ 0011cbe0
undefined4 UpdateClientData__15CBasePlayerItemP11CBasePlayer(void)

{
  return 0;
}


// UpdateClientData__17CBasePlayerWeaponP11CBasePlayer  @ 0011b600
undefined4 UpdateClientData__17CBasePlayerWeaponP11CBasePlayer(int param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(param_2[0x20c] == param_1);
  if ((((param_2[0x1f7] == 0) || (param_2[0x20c] != param_2[0x20d])) ||
      (*(int *)(param_1 + 0x410) != *(int *)(param_1 + 0x414))) ||
     (uVar1 != *(uint *)(param_1 + 0x418))) {
    (*DAT_00175578)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175580)(uVar1);
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x3f0));
    (*DAT_00175580)(*(undefined4 *)(param_1 + 0x410));
    (*DAT_0017557c)();
    *(undefined4 *)(param_1 + 0x414) = *(undefined4 *)(param_1 + 0x410);
    *(uint *)(param_1 + 0x418) = uVar1;
    param_2[0x1f7] = 1;
  }
  if (*(int *)(param_1 + 0x3ec) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x3ec) + 0x3c8) + 0x144))
              (*(int *)(param_1 + 0x3ec),param_2);
  }
  return 1;
}


