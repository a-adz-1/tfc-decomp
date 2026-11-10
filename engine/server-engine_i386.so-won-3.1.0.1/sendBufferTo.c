// sendBufferTo__10EasySocketPCviRC11sockaddr_ini  @ 0009d990
int sendBufferTo__10EasySocketPCviRC11sockaddr_ini
              (int *param_1,void *param_2,size_t param_3,sockaddr *param_4,undefined4 param_5)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  
  if (param_1[1] == 1) {
    iVar1 = 0x3f5;
  }
  else {
    iVar1 = isInvalid__10EasySocket(param_1);
    if ((iVar1 != 0) && (iVar1 = getNewDescriptor__10EasySocket(param_1), iVar1 != 0)) {
      return iVar1;
    }
    if (param_2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("theBuf","/home/jihad/valve/goldsrc/utils/crypt/won/EasySocket.cpp",0x483,
                    "enum ES_ErrorType EasySocket::sendBufferTo(const void *, int, const struct SOCKADDR_IN &, int = 1000)"
                   );
    }
    waitForWrite__10EasySocketi(param_1,param_5);
    sVar2 = sendto(*param_1,param_2,param_3,0,param_4,0x10);
    if (sVar2 == param_3) {
      iVar1 = 0;
    }
    else if ((int)sVar2 < 0) {
      uVar3 = WSAGetLastError__Fv();
      iVar1 = WSAErrorToEnum__10EasySocketi(uVar3);
    }
    else {
      iVar1 = 0x3f3;
    }
  }
  return iVar1;
}


// sendBufferTo__10EasySocketPCviRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii  @ 0009da88
void sendBufferTo__10EasySocketPCviRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined1 local_14 [16];
  
  iVar1 = getSockAddr__10EasySocketR11sockaddr_inRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                    (local_14,param_4,param_5);
  if (iVar1 == 0) {
    sendBufferTo__10EasySocketPCviRC11sockaddr_ini(param_1,param_2,param_3,local_14,param_6);
  }
  return;
}


// sendBufferTo__10EasySocketPCvilii  @ 0009da30
void sendBufferTo__10EasySocketPCvilii
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               uint16_t param_5,undefined4 param_6)

{
  undefined2 local_14;
  uint16_t local_12;
  undefined4 local_10;
  
  memset(&local_14,0,0x10);
  local_14 = 2;
  local_12 = htons(param_5);
  local_10 = param_4;
  sendBufferTo__10EasySocketPCviRC11sockaddr_ini(param_1,param_2,param_3,&local_14,param_6);
  return;
}


