// bind__10EasySocketi  @ 0009d11c
int bind__10EasySocketi(int *param_1,uint16_t param_2)

{
  int iVar1;
  undefined4 uVar2;
  sockaddr local_14;
  
  iVar1 = isInvalid__10EasySocket(param_1);
  if ((iVar1 != 0) && (iVar1 = getNewDescriptor__10EasySocket(param_1), iVar1 != 0)) {
    return iVar1;
  }
  memset(&local_14,0,0x10);
  local_14.sa_family = 2;
  local_14.sa_data._2_4_ = htonl(0);
  local_14.sa_data._0_2_ = htons(param_2);
  iVar1 = bind(*param_1,&local_14,0x10);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    uVar2 = WSAGetLastError__Fv();
    iVar1 = WSAErrorToEnum__10EasySocketi(uVar2);
  }
  return iVar1;
}


