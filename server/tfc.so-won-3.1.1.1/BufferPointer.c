// BufferPointer__8CRestore  @ 00120c78
undefined4 BufferPointer__8CRestore(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*param_1 + 4);
  }
  return uVar1;
}


