// dcast__C14__si_type_infoRC9type_infoiPvPC9type_infoT3  @ 001278b0
undefined4
dcast__C14__si_type_infoRC9type_infoiPvPC9type_infoT3
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  char cVar1;
  
  cVar1 = __eq__C9type_infoRC9type_info(param_1,param_2);
  if (cVar1 == '\0') {
    param_4 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 4) + 0xc))
                        (*(int *)(param_1 + 8),param_2,param_3,param_4,param_5,param_6);
  }
  return param_4;
}


// dcast__C16__user_type_infoRC9type_infoiPvPC9type_infoT3  @ 00127880
undefined4
dcast__C16__user_type_infoRC9type_infoiPvPC9type_infoT3
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = __eq__C9type_infoRC9type_info(param_1,param_2);
  uVar2 = 0;
  if (cVar1 != '\0') {
    uVar2 = param_4;
  }
  return uVar2;
}


// dcast__C17__class_type_infoRC9type_infoiPvPC9type_infoT3  @ 00127920
void dcast__C17__class_type_infoRC9type_infoiPvPC9type_infoT3(void)

{
  FUN_0012792e();
  return;
}


