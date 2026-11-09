// DispatchObjectCollsionBox__FP7edict_s  @ 000a0d60
void DispatchObjectCollsionBox__FP7edict_s(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xd8);
  }
  if (iVar1 == 0) {
    SetObjectCollisionBox__FP9entvars_t(param_1 + 0xdc);
  }
  else {
    (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x24))(iVar1);
  }
  return;
}


