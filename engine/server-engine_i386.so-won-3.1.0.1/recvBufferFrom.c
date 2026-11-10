// recvBufferFrom__10EasySocketPviP11sockaddr_inPii  @ 0009dac4
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
        __assert_fail("theBuf","/home/jihad/valve/goldsrc/utils/crypt/won/EasySocket.cpp",0x529,
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


// recvBufferFrom__10EasySocketPviPlPiT4i  @ 0009db88
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


// recvBufferFrom__10EasySocketPviPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PiT4i  @ 0009dbec
int recvBufferFrom__10EasySocketPviPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PiT4i
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5,
              undefined4 param_6,undefined4 param_7)

{
  uint *puVar1;
  uint16_t uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 local_14 [2];
  uint16_t local_12;
  in_addr local_10;
  
  iVar3 = recvBufferFrom__10EasySocketPviP11sockaddr_inPii
                    (param_1,param_2,param_3,local_14,param_6,param_7);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (param_4 == 0) goto LAB_0009dc82;
  puVar4 = (uint *)inet_ntoa(local_10);
  uVar6 = (uint)puVar4 & 3;
  puVar1 = puVar4;
  if (uVar6 == 0) {
LAB_0009dc4f:
    do {
      puVar5 = puVar1;
      uVar6 = *puVar5;
      if ((char)uVar6 == '\0') goto LAB_0009dc71;
      if ((char)(uVar6 >> 8) == '\0') goto LAB_0009dc70;
      if ((uVar6 & 0xff0000) == 0) goto LAB_0009dc6f;
      puVar1 = puVar5 + 1;
    } while ((uVar6 & 0xff000000) != 0);
    puVar5 = (uint *)((int)puVar5 + 1);
LAB_0009dc6f:
    puVar5 = (uint *)((int)puVar5 + 1);
LAB_0009dc70:
    puVar5 = (uint *)((int)puVar5 + 1);
  }
  else {
    puVar5 = puVar4;
    if ((POPCOUNT(uVar6) & 1U) == 0) {
LAB_0009dc4a:
      if ((char)*puVar5 != '\0') {
        puVar1 = (uint *)((int)puVar5 + 1);
        goto LAB_0009dc4f;
      }
    }
    else if (uVar6 == 2) {
LAB_0009dc45:
      if ((char)*puVar5 != '\0') {
        puVar5 = (uint *)((int)puVar5 + 1);
        goto LAB_0009dc4a;
      }
    }
    else if ((char)*puVar4 != '\0') {
      puVar5 = (uint *)((int)puVar4 + 1);
      goto LAB_0009dc45;
    }
  }
LAB_0009dc71:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_4,0,0xffffffff,puVar4,(int)puVar5 - (int)puVar4);
LAB_0009dc82:
  if (param_5 != (uint *)0x0) {
    uVar2 = ntohs(local_12);
    *param_5 = (uint)uVar2;
  }
  return 0;
}


