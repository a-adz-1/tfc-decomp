// SelectNextItem__11CBasePlayeri  @ 000db050
void SelectNextItem__11CBasePlayeri(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x89c + param_2 * 4);
  if (iVar3 != 0) {
    if (iVar3 == *(int *)(param_1 + 0x8b4)) {
      iVar3 = *(int *)(iVar3 + 0x468);
      if (iVar3 == 0) {
        return;
      }
      iVar1 = *(int *)(iVar3 + 0x468);
      iVar2 = iVar3;
      while (iVar1 != 0) {
        iVar2 = *(int *)(iVar2 + 0x468);
        iVar1 = *(int *)(iVar2 + 0x468);
      }
      *(undefined4 *)(iVar2 + 0x468) = *(undefined4 *)(param_1 + 0x8b4);
      *(undefined4 *)(*(int *)(param_1 + 0x8b4) + 0x468) = 0;
      *(int *)(param_1 + 0x89c + param_2 * 4) = iVar3;
    }
    ResetAutoaim__11CBasePlayer(param_1);
    if (*(int *)(param_1 + 0x8b4) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 0x128))
                (*(int *)(param_1 + 0x8b4),0);
    }
    *(int *)(param_1 + 0x8b4) = iVar3;
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x444) + 0x120))(iVar3);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 300))(*(int *)(param_1 + 0x8b4));
    }
  }
  return;
}


