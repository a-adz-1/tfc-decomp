// sendBuffer__10EasySocketPCviPii  @ 0808e770
undefined4
sendBuffer__10EasySocketPCviPii(int *param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ssize_t sVar5;
  int iVar6;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("theBuf","/e/quiver/goldsrc/common/EasySocket.cpp",0x3d2,
                  "enum ES_ErrorType EasySocket::sendBuffer(const void *, int, int * = 0, int = 1000)"
                 );
  }
  iVar2 = isInvalid__10EasySocket(param_1);
  if (iVar2 == 0) {
    iVar2 = GetTickCount();
    bVar1 = false;
    iVar6 = 0;
    do {
      if (param_3 <= iVar6) break;
      iVar4 = GetTickCount();
      if ((uint)(iVar4 - iVar2) < param_5) {
        iVar4 = param_5 - (iVar4 - iVar2);
      }
      else {
        iVar4 = 0;
        bVar1 = true;
      }
      iVar4 = waitForWrite__10EasySocketi(param_1,iVar4);
      if (iVar4 == 1) {
        sVar5 = send(*param_1,(void *)(param_2 + iVar6),param_3 - iVar6,0);
        if (sVar5 < 0) {
          uVar3 = WSAGetLastError__Fv();
          uVar3 = WSAErrorToEnum__10EasySocketi(uVar3);
          return uVar3;
        }
        iVar6 = iVar6 + sVar5;
      }
    } while (!bVar1);
    if (param_4 != (int *)0x0) {
      *param_4 = iVar6;
    }
    if (iVar6 < param_3) {
      uVar3 = 0x3ec;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0x3eb;
  }
  return uVar3;
}


