// getLocalPort__10EasySocket  @ 000d5c18
uint16_t getLocalPort__10EasySocket(int *param_1)

{
  uint16_t uVar1;
  int iVar2;
  socklen_t local_1c;
  int local_18;
  sockaddr local_14;
  
  iVar2 = isInvalid__10EasySocket(param_1);
  if (iVar2 == 0) {
    local_1c = 0x10;
    local_18 = getsockname(*param_1,&local_14,&local_1c);
    if (local_18 == 0) {
      uVar1 = ntohs(local_14.sa_data._0_2_);
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


