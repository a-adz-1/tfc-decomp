// sendBufferTo__10EasySocketPCviRC11sockaddr_ini  @ 000d6910
void sendBufferTo__10EasySocketPCviRC11sockaddr_ini
               (int *param_1,void *param_2,size_t param_3,sockaddr *param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_c;
  size_t sStack_8;
  
  if (param_1[1] == 1) {
    FUN_000d69e8();
    return;
  }
  iVar2 = isInvalid__10EasySocket(param_1);
  if (iVar2 != 0) {
    sStack_8 = getNewDescriptor__10EasySocket(param_1);
    uStack_c = 0;
    cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&sStack_8,&uStack_c);
    if (cVar1 != '\0') {
      FUN_000d69e8();
      return;
    }
  }
  waitForWrite__10EasySocketi(param_1,param_5);
  sStack_8 = sendto(*param_1,param_2,param_3,0,param_4,0x10);
  if (sStack_8 == param_3) {
    FUN_000d69e8();
    return;
  }
  if (-1 < (int)sStack_8) {
    FUN_000d69e8();
    return;
  }
  uVar3 = WSAGetLastError__Fv();
  WSAErrorToEnum__10EasySocketi(uVar3);
  FUN_000d69e8();
  return;
}


// sendBufferTo__10EasySocketPCviRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii  @ 000d6a5c
undefined4
sendBufferTo__10EasySocketPCviRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  char cVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [16];
  
  local_18 = getSockAddr__10EasySocketR11sockaddr_inRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                       (local_14,param_4,param_5);
  local_1c = 0;
  cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_18,&local_1c);
  if (cVar1 == '\0') {
    local_18 = sendBufferTo__10EasySocketPCviRC11sockaddr_ini
                         (param_1,param_2,param_3,local_14,param_6);
  }
  return local_18;
}


// sendBufferTo__10EasySocketPCvilii  @ 000d69f0
undefined4
sendBufferTo__10EasySocketPCvilii
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          uint16_t param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined2 local_14;
  uint16_t uStack_12;
  undefined4 uStack_10;
  
  memset(&local_14,0,0x10);
  local_14 = 2;
  uStack_12 = htons(param_5);
  uStack_10 = param_4;
  uVar1 = sendBufferTo__10EasySocketPCviRC11sockaddr_ini(param_1,param_2,param_3,&local_14,param_6);
  return uVar1;
}


