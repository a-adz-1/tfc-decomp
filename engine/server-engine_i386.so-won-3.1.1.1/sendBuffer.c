// sendBuffer__10EasySocketPCviPii  @ 000d6624
void sendBuffer__10EasySocketPCviPii
               (int *param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ssize_t sVar4;
  undefined4 uVar5;
  undefined4 uStack_18;
  undefined4 uStack_c;
  
  iVar2 = isInvalid__10EasySocket(param_1);
  if (iVar2 != 0) {
    FUN_000d6754();
    return;
  }
  iVar2 = GetTickCount__10EasySocket(param_1);
  bVar1 = false;
  uStack_18 = 0;
  while( true ) {
    if (bVar1) {
      FUN_000d6730();
      return;
    }
    if (param_3 <= uStack_18) break;
    iVar3 = GetTickCount__10EasySocket(param_1);
    if ((uint)(iVar3 - iVar2) < param_5) {
      uStack_c = param_5 - (iVar3 - iVar2);
    }
    else {
      uStack_c = 0;
      bVar1 = true;
    }
    iVar3 = waitForWrite__10EasySocketi(param_1,uStack_c);
    if (iVar3 == 1) {
      sVar4 = send(*param_1,(void *)(param_2 + uStack_18),param_3 - uStack_18,0);
      if (sVar4 < 0) {
        uVar5 = WSAGetLastError__Fv();
        WSAErrorToEnum__10EasySocketi(uVar5);
        FUN_000d6754();
        return;
      }
      uStack_18 = uStack_18 + sVar4;
    }
  }
  FUN_000d6730();
  return;
}


