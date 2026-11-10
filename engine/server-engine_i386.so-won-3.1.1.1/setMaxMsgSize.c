// setMaxMsgSize__15EasyTitanSocketUl  @ 000d55c4
void setMaxMsgSize__15EasyTitanSocketUl(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x20) != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    __builtin_vec_delete(*(undefined4 *)(param_1 + 0x20));
  }
  uVar1 = __builtin_vec_new(param_2);
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  *(undefined4 *)(param_1 + 0x24) = param_2;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}


