// connect__10EasySocketRC11sockaddr_ini  @ 000d5f94
undefined4 connect__10EasySocketRC11sockaddr_ini(int *param_1,sockaddr *param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_1[1] == 1) {
    disconnect__10EasySocket(param_1);
  }
  if (*param_1 == -1) {
    local_c = getNewDescriptor__10EasySocket(param_1);
    local_10 = 0;
    cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_c,&local_10);
    if (cVar1 != '\0') {
      return local_c;
    }
  }
  local_8 = connect(*param_1,param_2,0x10);
  if (local_8 == -1) {
    uVar2 = WSAGetLastError__Fv();
    local_c = WSAErrorToEnum__10EasySocketi(uVar2);
    local_14 = 0xb;
    cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_c,&local_14);
    if (cVar1 != '\0') {
      return local_c;
    }
  }
  param_1[6] = 1;
  param_1[2] = *(int *)param_2;
  param_1[3] = *(int *)(param_2->sa_data + 2);
  param_1[4] = *(int *)(param_2->sa_data + 6);
  param_1[5] = *(int *)(param_2->sa_data + 10);
  if (param_3 != 0) {
    local_18 = 1;
    cVar1 = __ne__H1ZQ210EasySocket10SocketType_RCX01T0_b(param_1 + 1,&local_18);
    if (cVar1 == '\0') {
      iVar3 = waitForWrite__10EasySocketi(param_1,param_3);
      if (iVar3 != 0) {
        return 0;
      }
      disconnect__10EasySocket(param_1);
      return 0x3f4;
    }
  }
  return 0;
}


// connect__10EasySocketRC11sockaddr_inii  @ 000d60e0
int connect__10EasySocketRC11sockaddr_inii
              (undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  while( true ) {
    if (param_4 <= local_c) {
      return local_8;
    }
    local_8 = connect__10EasySocketRC11sockaddr_ini(param_1,param_2,param_3);
    if (local_8 == 0) break;
    param_3 = param_3 * 2;
    local_c = local_c + 1;
  }
  return 0;
}


// connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii  @ 000d61ac
undefined4
connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  char cVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [16];
  
  local_18 = getSockAddr__10EasySocketR11sockaddr_inRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                       (local_14,param_2,param_3);
  local_1c = 0;
  cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_18,&local_1c);
  if (cVar1 == '\0') {
    local_18 = connect__10EasySocketRC11sockaddr_inii(param_1,local_14,param_4,param_5);
  }
  return local_18;
}


// connect__10EasySocketliii  @ 000d6148
undefined4
connect__10EasySocketliii
          (undefined4 param_1,undefined4 param_2,uint16_t param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  undefined2 local_14;
  uint16_t local_12;
  undefined4 local_10;
  
  memset(&local_14,0,0x10);
  local_14 = 2;
  local_12 = htons(param_3);
  local_10 = param_2;
  uVar1 = connect__10EasySocketRC11sockaddr_inii(param_1,&local_14,param_4,param_5);
  return uVar1;
}


