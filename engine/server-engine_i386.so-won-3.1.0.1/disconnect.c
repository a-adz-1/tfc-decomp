// disconnect__10EasySocket  @ 0009dcac
void disconnect__10EasySocket(int *param_1)

{
  int iVar1;
  sockaddr local_14;
  
  param_1[6] = 0;
  if (param_1[1] != 1) {
    memset(&local_14,0,0x10);
    iVar1 = connect(*param_1,&local_14,0x10);
    if (iVar1 == 0) {
      return;
    }
  }
  close__10EasySocket(param_1);
  return;
}


