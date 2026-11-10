// GetMonsterPointer__11CBaseEntityP7edict_s  @ 0010f590
undefined4 GetMonsterPointer__11CBaseEntityP7edict_s(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    param_2 = (*DAT_001c1134)(0);
    if (param_2 == 0) {
      iVar2 = 0;
      goto LAB_0010f5c6;
    }
  }
  iVar2 = *(int *)(param_2 + 0x7c);
LAB_0010f5c6:
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x50))(iVar2);
  }
  return uVar1;
}


// GetMonsterPointer__11CBaseEntityP9entvars_s  @ 0010f5e0
undefined4 GetMonsterPointer__11CBaseEntityP9entvars_s(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_2 + 0x208);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_0010f61a;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_0010f61a:
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x444) + 0x50))(iVar1);
  }
  return uVar2;
}


