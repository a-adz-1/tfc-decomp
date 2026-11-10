// DispatchBlocked__FP7edict_sT0  @ 000a0670
void DispatchBlocked__FP7edict_sT0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xd8);
  }
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0xd8);
  }
  if (iVar2 != 0) {
    (**(code **)(*(int *)(iVar2 + 0x3c8) + 0xb4))(iVar2,uVar1);
  }
  return;
}


