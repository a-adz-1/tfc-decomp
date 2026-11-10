// ReceiveRefresh__11AuthRequest  @ 000d4e1c
void ReceiveRefresh__11AuthRequest(int param_1)

{
  char cVar1;
  time_t tVar2;
  int iVar3;
  undefined4 local_1024;
  undefined4 local_1020;
  undefined4 local_101c;
  int local_1018;
  undefined1 local_1014 [12];
  undefined4 local_1008;
  undefined1 local_1004 [4096];
  
  local_1008 = 0x1000;
  __10ReadBuffer(local_1014);
  local_101c = 0xca;
  local_1020 = 0x2c;
  local_1018 = recvTMessage__15EasyTitanSocketPcPUlN22i
                         (param_1 + 0x81c8,local_1004,&local_1008,&local_101c,&local_1020,0);
  local_1024 = 0;
  cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_1018,&local_1024);
  if (cVar1 == '\0') {
    setBuffer__10ReadBufferPCcUl(local_1014,local_1004,local_1008);
    *(undefined4 *)(param_1 + 0x81f8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x81fc) = 0xffffffff;
    iVar3 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey(param_1,local_1014,0);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x8190) = 1;
      tVar2 = time((time_t *)0x0);
      *(time_t *)(param_1 + 0x81b8) = tVar2 + 5;
      *(int *)(param_1 + 0x81bc) = *(int *)(param_1 + 0x81bc) + -1;
      connect__10EasySocketliii
                (param_1 + 0x81c8,*(undefined4 *)(param_1 + 0x8008),*(undefined4 *)(param_1 + 4),0,1
                );
    }
    else {
      *(undefined4 *)(param_1 + 0x8190) = 0;
    }
  }
  else if (local_1018 != 0x3f4) {
    *(undefined4 *)(param_1 + 0x8190) = 1;
    tVar2 = time((time_t *)0x0);
    *(time_t *)(param_1 + 0x81b8) = tVar2 + 5;
    *(int *)(param_1 + 0x81bc) = *(int *)(param_1 + 0x81bc) + -1;
    connect__10EasySocketliii
              (param_1 + 0x81c8,*(undefined4 *)(param_1 + 0x8008),*(undefined4 *)(param_1 + 4),0,1);
  }
  return;
}


