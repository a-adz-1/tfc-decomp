// FireSignal__16BaseSystemModuleUi  @ 000cb68c
void FireSignal__16BaseSystemModuleUi(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  uVar1 = 0xcb69a;
  local_8 = (int *)GetFirst__10ObjectList(param_1 + 8);
  while (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 0x14))(local_8,param_1,param_2,uVar1);
    local_8 = (int *)GetNext__10ObjectList(param_1 + 8);
  }
  return;
}


