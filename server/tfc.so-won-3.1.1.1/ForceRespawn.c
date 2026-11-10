// ForceRespawn__11CBasePlayer  @ 000e2464
void ForceRespawn__11CBasePlayer(int *param_1)

{
  int *piVar1;
  float fVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  param_1[0x369] = 1;
  (*DAT_0019f758)(2,0x17,0,0);
  (*DAT_0019f760)(0x7d);
  uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(uVar3);
  (*DAT_0019f75c)();
  if (param_1[0x1c] != 0) {
    param_1[0x1c] = 0;
    iVar4 = *param_1;
    local_8 = 0x41e00000;
    *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar4 + 0x24) = DAT_0019f664;
    *(undefined4 *)(iVar4 + 0x28) = DAT_0019f668;
    iVar4 = *param_1;
    local_10 = 0;
    local_c = 0;
    *(undefined4 *)(iVar4 + 0x174) = 0;
    *(undefined4 *)(iVar4 + 0x178) = 0;
    *(undefined4 *)(iVar4 + 0x17c) = 0x41e00000;
    *(undefined4 *)(*param_1 + 0x108) = 3;
    *(undefined4 *)(*param_1 + 0x170) = 0;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    iVar4 = param_1[0x237];
    if (iVar4 != 0) {
      (**(code **)(*(int *)(iVar4 + 0x454) + 0x120))(iVar4);
    }
    *(undefined4 *)(*param_1 + 0x138) = 0xbf800000;
    param_1[0x285] = 0;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
  }
  piVar1 = param_1 + 0x223;
  iVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar4 != 0) {
    iVar4 = __rf__7EHANDLE(piVar1);
    (**(code **)(*(int *)(iVar4 + 0x454) + 0xb8))(iVar4,param_1,param_1,0,0);
    __as__7EHANDLEP11CBaseEntity(piVar1,0);
  }
  param_1[0x217] = 0;
  param_1[0x1c7] = 0;
  param_1[0x1bb] = 0;
  param_1[0x10b] = 0;
  param_1[0x10c] = 0;
  param_1[0x10e] = 0;
  param_1[0x10d] = 0;
  fVar2 = *gpGlobals;
  uVar5 = param_1[0x21];
  param_1[0x72] = 0;
  param_1[0x28c] = 0;
  param_1[0x28b] = 0;
  param_1[0x371] = (int)(fVar2 + 1.0);
  if ((uVar5 & 1) != 0) {
    uVar5 = uVar5 & 0xfffffffe;
    param_1[0x21] = uVar5;
    param_1[0x20] = 1;
  }
  if ((uVar5 & 8) == 0) {
    if ((uVar5 & 0x800) == 0) {
      param_1[0x21] = 0;
    }
    else {
      param_1[0x21] = 0x800;
    }
  }
  else if ((uVar5 & 0x800) == 0) {
    param_1[0x21] = 8;
  }
  else {
    param_1[0x21] = 0x808;
  }
  iVar4 = *(int *)(*param_1 + 0x20c);
  if ((((iVar4 != 0xb) && (iVar4 != 0)) && (iVar4 != 10)) &&
     ((param_1[0xc] != iVar4 && (param_1[0xc] = iVar4, param_1[0x3d] != 0)))) {
    (*DAT_0019f758)(1,9,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f778)(*(undefined4 *)(sClassCfgs + *(int *)(*param_1 + 0x20c) * 4));
    (*DAT_0019f75c)();
  }
  TeamFortress_SetSpeed__11CBasePlayer(param_1);
  (**(code **)(*g_pGameRules + 0x60))(g_pGameRules,param_1);
  uVar6 = LookupActivity__14CBaseAnimatingi(param_1,1);
  *(undefined4 *)(*param_1 + 0x128) = uVar6;
  if ((*(byte *)(*param_1 + 0x1a5) & 0x40) == 0) {
    puVar8 = &uStack_1c;
    uStack_18 = 0x41800000;
    uStack_14 = 0x42100000;
    local_c = 0xc1800000;
    local_8 = 0xc2100000;
    puVar7 = &local_10;
  }
  else {
    puVar8 = &local_10;
    local_c = 0x41800000;
    local_8 = 0x41900000;
    uStack_18 = 0xc1800000;
    uStack_14 = 0xc1900000;
    puVar7 = &uStack_1c;
  }
  uStack_1c = uStack_18;
  local_10 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,puVar7,puVar8);
  return;
}


