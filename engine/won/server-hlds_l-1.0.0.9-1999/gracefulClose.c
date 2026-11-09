// gracefulClose__10EasySocketi  @ 0808ed60
undefined4 gracefulClose__10EasySocketi(int *param_1,uint param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  ssize_t sVar5;
  undefined1 local_3ec [1000];
  
  if (*param_1 == -1) {
    uVar2 = 0x3eb;
  }
  else {
    iVar3 = shutdown(*param_1,1);
    if (iVar3 == 0) {
      iVar3 = GetTickCount();
      bVar1 = false;
      do {
        iVar4 = GetTickCount();
        if (param_2 < (uint)(iVar4 - iVar3)) {
          iVar4 = 0;
          bVar1 = true;
        }
        else {
          iVar4 = param_2 - (iVar4 - iVar3);
        }
        iVar4 = waitForRead__10EasySocketi(param_1,iVar4);
        if (iVar4 == 0) {
          return 0x3f4;
        }
        sVar5 = recv(*param_1,local_3ec,1000,0);
        if (sVar5 == 0) break;
        if (sVar5 < 0) goto LAB_0808edb0;
      } while (!bVar1);
      close__10EasySocket(param_1);
      uVar2 = 0;
    }
    else {
LAB_0808edb0:
      uVar2 = WSAGetLastError__Fv();
      uVar2 = WSAErrorToEnum__10EasySocketi(uVar2);
    }
  }
  return uVar2;
}


