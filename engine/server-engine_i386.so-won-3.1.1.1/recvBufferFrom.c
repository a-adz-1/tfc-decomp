// recvBufferFrom__10EasySocketPviP11sockaddr_inPii  @ 000d6ad8
undefined4
recvBufferFrom__10EasySocketPviP11sockaddr_inPii
          (int *param_1,void *param_2,size_t param_3,sockaddr *param_4,ssize_t *param_5,
          undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  sockaddr local_1c;
  socklen_t local_c;
  ssize_t local_8;
  
  if (param_1[1] == 1) {
    uVar1 = 0x3f5;
  }
  else {
    iVar2 = isInvalid__10EasySocket(param_1);
    if (iVar2 == 0) {
      local_c = 0x10;
      if (param_4 == (sockaddr *)0x0) {
        param_4 = &local_1c;
      }
      iVar2 = waitForRead__10EasySocketi(param_1,param_6);
      if (iVar2 == 0) {
        uVar1 = 0x3f4;
      }
      else {
        local_8 = recvfrom(*param_1,param_2,param_3,0,param_4,&local_c);
        if (local_8 < 0) {
          uVar1 = WSAGetLastError__Fv();
          uVar1 = WSAErrorToEnum__10EasySocketi(uVar1);
        }
        else {
          if (param_5 != (ssize_t *)0x0) {
            *param_5 = local_8;
          }
          uVar1 = 0;
        }
      }
    }
    else {
      uVar1 = 0x3eb;
    }
  }
  return uVar1;
}


// recvBufferFrom__10EasySocketPviPlPiT4i  @ 000d6ba4
undefined4
recvBufferFrom__10EasySocketPviPlPiT4i
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
          uint *param_5,undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  uint16_t uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [2];
  uint16_t local_12;
  undefined4 local_10;
  
  local_18 = recvBufferFrom__10EasySocketPviP11sockaddr_inPii
                       (param_1,param_2,param_3,local_14,param_6,param_7);
  local_1c = 0;
  cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_18,&local_1c);
  if (cVar1 == '\0') {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_10;
    }
    if (param_5 != (uint *)0x0) {
      uVar2 = ntohs(local_12);
      *param_5 = (uint)uVar2;
    }
    local_18 = 0;
  }
  return local_18;
}


// recvBufferFrom__10EasySocketPviPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PiT4i  @ 000d6c3c
undefined4
recvBufferFrom__10EasySocketPviPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PiT4i
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5,
          undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  uint16_t uVar2;
  char *pcVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [2];
  uint16_t uStack_12;
  in_addr iStack_10;
  
  local_18 = recvBufferFrom__10EasySocketPviP11sockaddr_inPii
                       (param_1,param_2,param_3,local_14,param_6,param_7);
  local_1c = 0;
  cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_18,&local_1c);
  if (cVar1 == '\0') {
    if (param_4 != 0) {
      pcVar3 = inet_ntoa(iStack_10);
      __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_4,pcVar3);
    }
    if (param_5 != (uint *)0x0) {
      uVar2 = ntohs(uStack_12);
      *param_5 = (uint)uVar2;
    }
    local_18 = 0;
  }
  return local_18;
}


