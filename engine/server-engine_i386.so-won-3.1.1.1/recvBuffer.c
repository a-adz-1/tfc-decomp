// recvBuffer__10EasySocketPviPii  @ 000d675c
void recvBuffer__10EasySocketPviPii(int *param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_24;
  ssize_t local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = isInvalid__10EasySocket(param_1);
  if (iVar2 != 0) {
    FUN_000d6908();
    return;
  }
  local_8 = GetTickCount__10EasySocket(param_1);
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  while ((local_14 == 0 && (local_1c < param_3))) {
    local_10 = GetTickCount__10EasySocket(param_1);
    if ((uint)(local_10 - local_8) < param_5) {
      local_c = param_5 - (local_10 - local_8);
    }
    else {
      local_c = 0;
      local_14 = 1;
    }
    iVar2 = waitForRead__10EasySocketi(param_1,local_c);
    if (iVar2 == 1) {
      local_20 = recv(*param_1,(void *)(param_2 + local_1c),param_3 - local_1c,0);
      if (local_20 < 0) {
        uVar3 = WSAGetLastError__Fv();
        WSAErrorToEnum__10EasySocketi(uVar3);
        FUN_000d6908();
        return;
      }
      if (local_20 == 0) {
        local_14 = 1;
      }
      local_1c = local_1c + local_20;
      local_18 = 1;
      local_24 = 1;
      cVar1 = __ne__H1ZQ210EasySocket10SocketType_RCX01T0_b(param_1 + 1,&local_24);
      if (cVar1 != '\0') {
        local_14 = 1;
      }
    }
  }
  if (param_4 != (int *)0x0) {
    *param_4 = local_1c;
  }
  if (local_18 != 0) {
    if (param_1[1] != 1) {
      FUN_000d6908();
      return;
    }
    if (local_1c != 0) {
      if (param_3 <= local_1c) {
        FUN_000d6908();
        return;
      }
      FUN_000d6908();
      return;
    }
    FUN_000d6908();
    return;
  }
  FUN_000d6908();
  return;
}


