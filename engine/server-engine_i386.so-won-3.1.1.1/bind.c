// bind__10EasySocketi  @ 000d5eb0
undefined4 bind__10EasySocketi(int *param_1,uint16_t param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  sockaddr local_14;
  
  iVar2 = isInvalid__10EasySocket(param_1);
  if (iVar2 != 0) {
    local_1c = getNewDescriptor__10EasySocket(param_1);
    local_20 = 0;
    cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_1c,&local_20);
    if (cVar1 != '\0') {
      return local_1c;
    }
  }
  memset(&local_14,0,0x10);
  local_14.sa_family = 2;
  local_14.sa_data._2_4_ = htonl(0);
  local_14.sa_data._0_2_ = htons(param_2);
  local_18 = bind(*param_1,&local_14,0x10);
  if (local_18 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = WSAGetLastError__Fv();
    uVar3 = WSAErrorToEnum__10EasySocketi(uVar3);
  }
  return uVar3;
}


