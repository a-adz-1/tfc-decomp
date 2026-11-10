// recvBuffer__10EasySocketPviPii  @ 0808e870
undefined4
recvBuffer__10EasySocketPviPii(int *param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  ssize_t sVar6;
  int iVar7;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("theBuf","/e/quiver/goldsrc/common/EasySocket.cpp",0x420,
                  "enum ES_ErrorType EasySocket::recvBuffer(void *, int, int * = 0, int = 1000)");
  }
  iVar3 = isInvalid__10EasySocket(param_1);
  if (iVar3 == 0) {
    iVar3 = GetTickCount();
    bVar2 = false;
    iVar7 = 0;
    bVar1 = false;
    do {
      if (param_3 <= iVar7) break;
      iVar5 = GetTickCount();
      if ((uint)(iVar5 - iVar3) < param_5) {
        iVar5 = param_5 - (iVar5 - iVar3);
      }
      else {
        iVar5 = 0;
        bVar1 = true;
      }
      iVar5 = waitForRead__10EasySocketi(param_1,iVar5);
      if (iVar5 == 1) {
        sVar6 = recv(*param_1,(void *)(param_2 + iVar7),param_3 - iVar7,0);
        if (sVar6 < 0) {
          uVar4 = WSAGetLastError__Fv();
          uVar4 = WSAErrorToEnum__10EasySocketi(uVar4);
          return uVar4;
        }
        if (sVar6 == 0) {
          bVar1 = true;
        }
        iVar7 = iVar7 + sVar6;
        bVar2 = true;
        if (param_1[1] != 1) {
          bVar1 = true;
        }
      }
    } while (!bVar1);
    if (param_4 != (int *)0x0) {
      *param_4 = iVar7;
    }
    if (bVar2) {
      if (param_1[1] == 1) {
        if (iVar7 == 0) {
          return 0x3f6;
        }
        if (iVar7 < param_3) {
          return 0x3ed;
        }
      }
      uVar4 = 0;
    }
    else {
      uVar4 = 0x3f4;
    }
  }
  else {
    uVar4 = 0x3eb;
  }
  return uVar4;
}


