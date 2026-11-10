// DispatchObjectCollsionBox__FP7edict_s  @ 0008eed4
void DispatchObjectCollsionBox__FP7edict_s(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
  }
  if (iVar1 == 0) {
    SetObjectCollisionBox__FP9entvars_s(param_1 + 0x80);
  }
  else {
    (**(code **)(*(int *)(iVar1 + 0x454) + 0x28))(iVar1);
  }
  return;
}


