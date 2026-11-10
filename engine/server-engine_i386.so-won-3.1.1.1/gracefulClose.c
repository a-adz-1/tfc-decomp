// gracefulClose__10EasySocketi  @ 000d6d5c
undefined4 gracefulClose__10EasySocketi(int *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_400 [1000];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*param_1 == -1) {
    uVar1 = 0x3eb;
  }
  else {
    local_8 = shutdown(*param_1,1);
    if (local_8 == 0) {
      local_c = GetTickCount__10EasySocket(param_1);
      local_18 = 0;
      do {
        while( true ) {
          if (local_18 != 0) {
            close__10EasySocket(param_1);
            return 0;
          }
          local_10 = GetTickCount__10EasySocket(param_1);
          if (param_2 < (uint)(local_10 - local_c)) {
            local_14 = 0;
            local_18 = 1;
          }
          else {
            local_14 = param_2 - (local_10 - local_c);
          }
          iVar2 = waitForRead__10EasySocketi(param_1,local_14);
          if (iVar2 == 0) {
            return 0x3f4;
          }
          local_8 = recv(*param_1,local_400,1000,0);
          if (local_8 != 0) break;
          local_18 = 1;
        }
      } while (-1 < local_8);
      uVar1 = WSAGetLastError__Fv();
      uVar1 = WSAErrorToEnum__10EasySocketi(uVar1);
    }
    else {
      uVar1 = WSAGetLastError__Fv();
      uVar1 = WSAErrorToEnum__10EasySocketi(uVar1);
    }
  }
  return uVar1;
}


