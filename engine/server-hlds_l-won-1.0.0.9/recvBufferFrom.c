// recvBufferFrom__10EasySocketPviP11sockaddr_inPii  @ 0808eb20
undefined4
recvBufferFrom__10EasySocketPviP11sockaddr_inPii
          (int *param_1,void *param_2,size_t param_3,sockaddr *param_4,ssize_t *param_5,
          undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  ssize_t sVar3;
  socklen_t local_18;
  sockaddr local_14;
  
  if (param_1[1] == 1) {
    uVar1 = 0x3f5;
  }
  else {
    iVar2 = isInvalid__10EasySocket(param_1);
    if (iVar2 == 0) {
      if (param_2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("theBuf","/e/quiver/goldsrc/common/EasySocket.cpp",0x526,
                      "enum ES_ErrorType EasySocket::recvBufferFrom(void *, int, struct SOCKADDR_IN *, int * = 0, int = 1000)"
                     );
      }
      local_18 = 0x10;
      if (param_4 == (sockaddr *)0x0) {
        param_4 = &local_14;
      }
      iVar2 = waitForRead__10EasySocketi(param_1,param_6);
      if (iVar2 == 0) {
        uVar1 = 0x3f4;
      }
      else {
        sVar3 = recvfrom(*param_1,param_2,param_3,0,param_4,&local_18);
        if (sVar3 < 0) {
          uVar1 = WSAGetLastError__Fv();
          uVar1 = WSAErrorToEnum__10EasySocketi(uVar1);
        }
        else {
          if (param_5 != (ssize_t *)0x0) {
            *param_5 = sVar3;
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


// recvBufferFrom__10EasySocketPviPlPiT4i  @ 0808ec10
int recvBufferFrom__10EasySocketPviPlPiT4i
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
              uint *param_5,undefined4 param_6,undefined4 param_7)

{
  uint16_t uVar1;
  int iVar2;
  undefined1 local_14 [2];
  uint16_t local_12;
  undefined4 local_10;
  
  iVar2 = recvBufferFrom__10EasySocketPviP11sockaddr_inPii
                    (param_1,param_2,param_3,local_14,param_6,param_7);
  if (iVar2 == 0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_10;
    }
    if (param_5 != (uint *)0x0) {
      uVar1 = ntohs(local_12);
      *param_5 = (uint)uVar1;
    }
    iVar2 = 0;
  }
  return iVar2;
}


// recvBufferFrom__10EasySocketPviPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PiT4i  @ 0808ec80
int recvBufferFrom__10EasySocketPviPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PiT4i
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5,
              undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  uint16_t uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_14 [2];
  uint16_t local_12;
  in_addr local_10;
  
  iVar3 = recvBufferFrom__10EasySocketPviP11sockaddr_inPii
                    (param_1,param_2,param_3,local_14,param_6,param_7);
  if (iVar3 == 0) {
    if (param_4 != 0) {
      pcVar4 = inet_ntoa(local_10);
      uVar5 = 0xffffffff;
      pcVar6 = pcVar4;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                (param_4,0,0xffffffff,pcVar4,~uVar5 - 1);
    }
    if (param_5 != (uint *)0x0) {
      uVar2 = ntohs(local_12);
      *param_5 = (uint)uVar2;
    }
    iVar3 = 0;
  }
  return iVar3;
}


