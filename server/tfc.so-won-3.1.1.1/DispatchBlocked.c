// DispatchBlocked__FP7edict_sT0  @ 0008ef48
void DispatchBlocked__FP7edict_sT0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x7c);
  }
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x7c);
  }
  if (iVar2 != 0) {
    (**(code **)(*(int *)(iVar2 + 0x454) + 0xbc))(iVar2,uVar1);
  }
  return;
}


