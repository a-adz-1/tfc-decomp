// readUByte__10ReadBufferPUc  @ 08090770
bool readUByte__10ReadBufferPUc(int *param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[2];
  iVar1 = param_1[1];
  if (iVar2 != iVar1) {
    *param_2 = *(undefined1 *)(param_1[1] + *param_1);
    param_1[1] = param_1[1] + 1;
  }
  return iVar2 != iVar1;
}


