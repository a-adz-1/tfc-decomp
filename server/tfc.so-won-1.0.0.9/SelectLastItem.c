// SelectLastItem__11CBasePlayer  @ 000dd1d0
void SelectLastItem__11CBasePlayer(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x838) != 0) {
    if ((*(int *)(param_1 + 0x830) != 0) &&
       (iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x11c))
                          (*(int *)(param_1 + 0x830)), iVar2 == 0)) {
      return;
    }
    ResetAutoaim__11CBasePlayer(param_1);
    if (*(int *)(param_1 + 0x830) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x120))(*(int *)(param_1 + 0x830));
    }
    uVar1 = *(undefined4 *)(param_1 + 0x830);
    iVar2 = *(int *)(param_1 + 0x838);
    *(int *)(param_1 + 0x830) = iVar2;
    *(undefined4 *)(param_1 + 0x838) = uVar1;
    (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x118))(iVar2);
    (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x124))(*(int *)(param_1 + 0x830));
  }
  return;
}


