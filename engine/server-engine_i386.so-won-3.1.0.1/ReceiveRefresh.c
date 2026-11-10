// ReceiveRefresh__11AuthRequest  @ 0009c114
void ReceiveRefresh__11AuthRequest(int param_1)

{
  int iVar1;
  time_t tVar2;
  undefined4 local_101c;
  undefined4 local_1018;
  undefined4 local_1014;
  undefined1 local_1010 [12];
  undefined1 local_1004 [4096];
  
  local_101c = 0x1000;
  __10ReadBuffer(local_1010);
  local_1018 = 0xca;
  local_1014 = 0x2c;
  iVar1 = recvTMessage__15EasyTitanSocketPcPUlN22i
                    (param_1 + 0x81c8,local_1004,&local_101c,&local_1018,&local_1014,0);
  if (iVar1 == 0) {
    setBuffer__10ReadBufferPCcUl(local_1010,local_1004,local_101c);
    *(undefined4 *)(param_1 + 0x81f8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x81fc) = 0xffffffff;
    iVar1 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey(param_1,local_1010,0);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x8190) = 0;
      return;
    }
  }
  else if (iVar1 == 0x3f4) {
    return;
  }
  *(undefined4 *)(param_1 + 0x8190) = 1;
  tVar2 = time((time_t *)0x0);
  *(time_t *)(param_1 + 0x81b8) = tVar2 + 5;
  *(int *)(param_1 + 0x81bc) = *(int *)(param_1 + 0x81bc) + -1;
  connect__10EasySocketliii
            (param_1 + 0x81c8,*(undefined4 *)(param_1 + 0x8008),*(undefined4 *)(param_1 + 4),0,1);
  return;
}


