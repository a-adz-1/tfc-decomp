// SelectLastItem__11CBasePlayer  @ 000e59c8
void SelectLastItem__11CBasePlayer(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x8e4) != 0) {
    iVar1 = *(int *)(param_1 + 0x8dc);
    if ((iVar1 != 0) && (iVar1 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x124))(iVar1), iVar1 == 0))
    {
      return;
    }
    if (*(int *)(param_1 + 0x8e4) != *(int *)(param_1 + 0x8dc)) {
      ResetAutoaim__11CBasePlayer(param_1);
      iVar1 = *(int *)(param_1 + 0x8dc);
      uVar2 = 0;
      if (iVar1 != 0) {
        (**(code **)(*(int *)(iVar1 + 0x454) + 0x128))(iVar1,0);
        uVar2 = *(undefined4 *)(param_1 + 0x8dc);
      }
      iVar1 = *(int *)(param_1 + 0x8e4);
      *(int *)(param_1 + 0x8dc) = iVar1;
      *(undefined4 *)(param_1 + 0x8e4) = uVar2;
      (**(code **)(*(int *)(iVar1 + 0x454) + 0x120))(iVar1);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x8dc) + 0x454) + 300))(*(int *)(param_1 + 0x8dc));
    }
  }
  return;
}


