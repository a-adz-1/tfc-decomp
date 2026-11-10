// SelectLastItem__11CBasePlayer  @ 000db2e8
void SelectLastItem__11CBasePlayer(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x8bc) != 0) {
    if ((*(int *)(param_1 + 0x8b4) != 0) &&
       (iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 0x124))
                          (*(int *)(param_1 + 0x8b4)), iVar2 == 0)) {
      return;
    }
    if (*(int *)(param_1 + 0x8bc) != *(int *)(param_1 + 0x8b4)) {
      ResetAutoaim__11CBasePlayer(param_1);
      if (*(int *)(param_1 + 0x8b4) != 0) {
        (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 0x128))
                  (*(int *)(param_1 + 0x8b4),0);
      }
      uVar1 = *(undefined4 *)(param_1 + 0x8b4);
      iVar2 = *(int *)(param_1 + 0x8bc);
      *(int *)(param_1 + 0x8b4) = iVar2;
      *(undefined4 *)(param_1 + 0x8bc) = uVar1;
      (**(code **)(*(int *)(iVar2 + 0x444) + 0x120))(iVar2);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 300))(*(int *)(param_1 + 0x8b4));
    }
  }
  return;
}


