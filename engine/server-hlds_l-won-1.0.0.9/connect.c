// connect__10EasySocketRC11sockaddr_ini  @ 0808e240
int connect__10EasySocketRC11sockaddr_ini(int *param_1,sockaddr *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[1] == 1) {
    disconnect__10EasySocket(param_1);
  }
  if ((*param_1 == -1) && (iVar1 = getNewDescriptor__10EasySocket(param_1), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = connect(*param_1,param_2,0x10);
  if (iVar1 == -1) {
    uVar2 = WSAGetLastError__Fv();
    iVar1 = WSAErrorToEnum__10EasySocketi(uVar2);
    if (iVar1 != 0xb) {
      return iVar1;
    }
  }
  param_1[6] = 1;
  param_1[2] = *(int *)param_2;
  param_1[3] = *(int *)(param_2->sa_data + 2);
  param_1[4] = *(int *)(param_2->sa_data + 6);
  param_1[5] = *(int *)(param_2->sa_data + 10);
  if (((param_3 != 0) && (param_1[1] == 1)) &&
     (iVar1 = waitForWrite__10EasySocketi(param_1,param_3), iVar1 == 0)) {
    disconnect__10EasySocket(param_1);
    return 0x3f4;
  }
  return 0;
}


// connect__10EasySocketRC11sockaddr_inii  @ 0808e2f0
void connect__10EasySocketRC11sockaddr_inii
               (undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_4) {
    do {
      iVar1 = connect__10EasySocketRC11sockaddr_ini(param_1,param_2,param_3);
      if (iVar1 == 0) {
        return;
      }
      param_3 = param_3 * 2;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_4);
  }
  return;
}


// connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii  @ 0808e3a0
void connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined1 local_14 [16];
  
  iVar1 = getSockAddr__10EasySocketR11sockaddr_inRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                    (local_14,param_2,param_3);
  if (iVar1 == 0) {
    connect__10EasySocketRC11sockaddr_inii(param_1,local_14,param_4,param_5);
  }
  return;
}


// connect__10EasySocketliii  @ 0808e340
void connect__10EasySocketliii
               (undefined4 param_1,undefined4 param_2,uint16_t param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined2 local_14;
  uint16_t local_12;
  undefined4 local_10;
  
  memset(&local_14,0,0x10);
  local_14 = 2;
  local_12 = htons(param_3);
  local_10 = param_2;
  connect__10EasySocketRC11sockaddr_inii(param_1,&local_14,param_4,param_5);
  return;
}


