// GetMonsterPointer__11CBaseEntityP7edict_s  @ 00112a24
undefined4 GetMonsterPointer__11CBaseEntityP7edict_s(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    param_2 = (*DAT_0019f7b4)(0);
    if (param_2 == 0) {
      iVar2 = 0;
      goto LAB_00112a5a;
    }
  }
  iVar2 = *(int *)(param_2 + 0x7c);
LAB_00112a5a:
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x50))(iVar2);
  }
  return uVar1;
}


// GetMonsterPointer__11CBaseEntityP9entvars_s  @ 00112a78
undefined4 GetMonsterPointer__11CBaseEntityP9entvars_s(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_2 + 0x208);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_00112ab6;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_00112ab6:
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x50))(iVar1);
  }
  return uVar2;
}


