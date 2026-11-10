// close__10EasySocket  @ 000d6ea8
void close__10EasySocket(int *param_1)

{
  int iVar1;
  
  iVar1 = isInvalid__10EasySocket(param_1);
  if (iVar1 == 0) {
    close(*param_1);
  }
  *param_1 = -1;
  param_1[6] = 0;
  return;
}


// close__3ios  @ 000525a0
void close__3ios(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 1) & 0x20) == 0) {
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 0x4c) + 0x30))(iVar1);
    }
  }
  else {
    close__7filebuf(iVar1);
  }
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 4;
  return;
}


