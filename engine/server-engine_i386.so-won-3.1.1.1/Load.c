// Load__7CEnginebPcT2  @ 00099b40
bool Load__7CEnginebPcT2(int *param_1,byte param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  (**(code **)(*param_1 + 0x14))(param_1,1);
  uVar1 = (uint)param_2;
  uVar2 = (**(code **)(*(int *)game + 0x20))(game);
  iVar3 = Sys_InitGame__FPcT0Pvi(param_4,param_3,uVar2,uVar1);
  if (iVar3 != 0) {
    ForceReloadProfile();
  }
  return iVar3 != 0;
}


