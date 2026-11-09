// DecalGunshot__FP11TraceResulti  @ 0011a3d0
void DecalGunshot__FP11TraceResulti(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(param_1 + 0x30);
  uStack_18 = 0x11a3e2;
  iVar2 = UTIL_IsValidEntity__FP7edict_s();
  if (iVar2 == 0) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x30) + 0xdc;
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar2 = 0;
  }
  if (*(int *)(iVar2 + 0xec) != 4) {
    iVar2 = *(int *)(param_1 + 0x30) + 0xdc;
    if (*(int *)(param_1 + 0x30) == 0) {
      iVar2 = 0;
    }
    if (*(int *)(iVar2 + 0xe8) != 0xd) {
      return;
    }
  }
  uVar3 = 0;
  iStack_14 = *(int *)(param_1 + 0x30);
  bVar1 = false;
  if (iStack_14 == 0) {
LAB_0011a43b:
    bVar1 = true;
  }
  else {
    uStack_18 = 0x11a434;
    iVar2 = (*DAT_001755d8)();
    if (iVar2 == 0) goto LAB_0011a43b;
  }
  if (!bVar1) {
    iVar2 = *(int *)(param_1 + 0x30);
    if (iVar2 == 0) {
      iStack_14 = 0;
      uStack_18 = 0x11a454;
      iVar2 = (*DAT_001755d4)();
      if (iVar2 == 0) {
        uVar3 = 0;
        goto LAB_0011a474;
      }
    }
    uVar3 = *(undefined4 *)(iVar2 + 0xd8);
  }
LAB_0011a474:
  switch(param_2) {
  default:
    iStack_14 = 2;
    uStack_1c = 0x11a498;
    uStack_18 = uVar3;
    uStack_1c = DamageDecal__FP11CBaseEntityi();
    piVar4 = &uStack_1c;
    break;
  case 5:
    iStack_14 = 0x80;
    uStack_1c = 0x11a4cb;
    uStack_18 = uVar3;
    uStack_1c = DamageDecal__FP11CBaseEntityi();
    UTIL_DecalTrace__FP11TraceResulti(param_1);
    return;
  case 7:
    piVar4 = &iStack_14;
    iStack_14 = 0x2a;
    break;
  case 10:
    iStack_14 = 2;
    uStack_1c = 0x11a4a8;
    uStack_18 = uVar3;
    uStack_1c = DamageDecal__FP11CBaseEntityi();
    piVar4 = &uStack_1c;
  }
  *(int *)((int)piVar4 + -4) = param_1;
  *(undefined4 *)((int)piVar4 + -8) = 0x11a4b8;
  UTIL_GunshotDecalTrace__FP11TraceResulti();
  return;
}


