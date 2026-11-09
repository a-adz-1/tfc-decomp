// BufferReadHeader__8CRestoreP6HEADER  @ 00119f10
void BufferReadHeader__8CRestoreP6HEADER(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = ReadShort__8CRestore(param_1);
  *param_2 = uVar1;
  uVar1 = ReadShort__8CRestore(param_1);
  param_2[1] = uVar1;
  uVar2 = BufferPointer__8CRestore(param_1);
  *(undefined4 *)(param_2 + 2) = uVar2;
  BufferSkipBytes__8CRestorei(param_1,*param_2);
  return;
}


