// GetMonsterPointer__11CBaseEntityP7edict_s  @ 0010dfb0
undefined4 GetMonsterPointer__11CBaseEntityP7edict_s(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    param_2 = (*DAT_001755d4)(0);
    if (param_2 == 0) {
      iVar2 = 0;
      goto LAB_0010dfe2;
    }
  }
  iVar2 = *(int *)(param_2 + 0xd8);
LAB_0010dfe2:
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x4c))(iVar2);
  }
  return uVar1;
}


// GetMonsterPointer__11CBaseEntityP9entvars_t  @ 0010e010
undefined4 GetMonsterPointer__11CBaseEntityP9entvars_t(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_2 + 0x1e8);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_0010e042;
    }
  }
  iVar1 = *(int *)(iVar1 + 0xd8);
LAB_0010e042:
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x4c))(iVar1);
  }
  return uVar2;
}


