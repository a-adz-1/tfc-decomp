// SelectNextItem__11CBasePlayeri  @ 000e5a84
void SelectNextItem__11CBasePlayeri(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 * 4 + param_1 + 0x8c4);
  if (iVar3 != 0) {
    if (iVar3 == *(int *)(param_1 + 0x8dc)) {
      iVar3 = *(int *)(iVar3 + 0x478);
      if (iVar3 == 0) {
        return;
      }
      iVar1 = *(int *)(iVar3 + 0x478);
      iVar2 = iVar3;
      while (iVar1 != 0) {
        iVar2 = *(int *)(iVar2 + 0x478);
        iVar1 = *(int *)(iVar2 + 0x478);
      }
      *(int *)(iVar2 + 0x478) = *(int *)(param_1 + 0x8dc);
      *(undefined4 *)(*(int *)(param_1 + 0x8dc) + 0x478) = 0;
      *(int *)(param_2 * 4 + param_1 + 0x8c4) = iVar3;
    }
    ResetAutoaim__11CBasePlayer(param_1);
    iVar1 = *(int *)(param_1 + 0x8dc);
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 0x454) + 0x128))(iVar1,0);
    }
    *(int *)(param_1 + 0x8dc) = iVar3;
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x454) + 0x120))(iVar3);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x8dc) + 0x454) + 300))(*(int *)(param_1 + 0x8dc));
    }
  }
  return;
}


