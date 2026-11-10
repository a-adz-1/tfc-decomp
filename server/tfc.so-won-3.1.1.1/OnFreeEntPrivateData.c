// OnFreeEntPrivateData__FP7edict_s  @ 0008ef14
void OnFreeEntPrivateData__FP7edict_s(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x7c), iVar1 != 0)) {
    (**(code **)(*(int *)(iVar1 + 0x454) + 8))(iVar1,2);
  }
  return;
}


