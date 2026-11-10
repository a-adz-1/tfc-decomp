// SelectNextItem__11CBasePlayeri  @ 000cf994
void SelectNextItem__11CBasePlayeri(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x82c + param_2 * 4);
  if (iVar3 != 0) {
    if (iVar3 == *(int *)(param_1 + 0x844)) {
      iVar3 = *(int *)(iVar3 + 0x3f8);
      if (iVar3 == 0) {
        return;
      }
      iVar1 = *(int *)(iVar3 + 0x3f8);
      iVar2 = iVar3;
      while (iVar1 != 0) {
        iVar2 = *(int *)(iVar2 + 0x3f8);
        iVar1 = *(int *)(iVar2 + 0x3f8);
      }
      *(undefined4 *)(iVar2 + 0x3f8) = *(undefined4 *)(param_1 + 0x844);
      *(undefined4 *)(*(int *)(param_1 + 0x844) + 0x3f8) = 0;
      *(int *)(param_1 + 0x82c + param_2 * 4) = iVar3;
    }
    ResetAutoaim__11CBasePlayer(param_1);
    if (*(int *)(param_1 + 0x844) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x120))
                (*(int *)(param_1 + 0x844),0);
    }
    *(int *)(param_1 + 0x844) = iVar3;
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x3d4) + 0x118))(iVar3);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x124))(*(int *)(param_1 + 0x844));
    }
  }
  return;
}


