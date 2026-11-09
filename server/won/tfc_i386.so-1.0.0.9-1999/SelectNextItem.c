// SelectNextItem__11CBasePlayeri  @ 000dd000
void SelectNextItem__11CBasePlayeri(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x818 + param_2 * 4);
  if (iVar3 != 0) {
    if (iVar3 == *(int *)(param_1 + 0x830)) {
      iVar3 = *(int *)(iVar3 + 0x3ec);
      if (iVar3 == 0) {
        return;
      }
      iVar1 = *(int *)(iVar3 + 0x3ec);
      iVar2 = iVar3;
      while (iVar1 != 0) {
        iVar2 = *(int *)(iVar2 + 0x3ec);
        iVar1 = *(int *)(iVar2 + 0x3ec);
      }
      *(undefined4 *)(iVar2 + 0x3ec) = *(undefined4 *)(param_1 + 0x830);
      *(undefined4 *)(*(int *)(param_1 + 0x830) + 0x3ec) = 0;
      *(int *)(param_1 + 0x818 + param_2 * 4) = iVar3;
    }
    ResetAutoaim__11CBasePlayer(param_1);
    if (*(int *)(param_1 + 0x830) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x120))(*(int *)(param_1 + 0x830));
    }
    *(int *)(param_1 + 0x830) = iVar3;
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x118))(iVar3);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x124))(*(int *)(param_1 + 0x830));
    }
  }
  return;
}


