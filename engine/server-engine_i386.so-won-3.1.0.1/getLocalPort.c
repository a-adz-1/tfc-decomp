// getLocalPort__10EasySocket  @ 0009ceb0
uint16_t getLocalPort__10EasySocket(int *param_1)

{
  uint16_t uVar1;
  int iVar2;
  socklen_t local_18;
  sockaddr local_14;
  
  iVar2 = isInvalid__10EasySocket(param_1);
  if (iVar2 == 0) {
    local_18 = 0x10;
    iVar2 = getsockname(*param_1,&local_14,&local_18);
    if (iVar2 == 0) {
      uVar1 = ntohs(local_14.sa_data._0_2_);
      return uVar1;
    }
  }
  return 0;
}


