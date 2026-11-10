// SelectLastItem__11CBasePlayer  @ 000cfc2c
void SelectLastItem__11CBasePlayer(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x84c) != 0) {
    if ((*(int *)(param_1 + 0x844) != 0) &&
       (iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x11c))
                          (*(int *)(param_1 + 0x844)), iVar2 == 0)) {
      return;
    }
    ResetAutoaim__11CBasePlayer(param_1);
    if (*(int *)(param_1 + 0x844) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x120))
                (*(int *)(param_1 + 0x844),0);
    }
    uVar1 = *(undefined4 *)(param_1 + 0x844);
    iVar2 = *(int *)(param_1 + 0x84c);
    *(int *)(param_1 + 0x844) = iVar2;
    *(undefined4 *)(param_1 + 0x84c) = uVar1;
    (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x118))(iVar2);
    (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x124))(*(int *)(param_1 + 0x844));
  }
  return;
}


