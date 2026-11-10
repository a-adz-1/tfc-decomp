// setType__10EasySocketQ210EasySocket10SocketType  @ 000d5de8
void setType__10EasySocketQ210EasySocket10SocketType(int param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = __ne__H1ZQ210EasySocket10SocketType_RCX01T0_b(param_1 + 4,&param_2);
  if (cVar1 != '\0') {
    close__10EasySocket(param_1);
  }
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}


