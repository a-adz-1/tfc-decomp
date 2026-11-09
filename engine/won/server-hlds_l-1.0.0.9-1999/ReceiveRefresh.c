// ReceiveRefresh__11AuthRequest  @ 08094910
void ReceiveRefresh__11AuthRequest(int param_1)

{
  int iVar1;
  time_t tVar2;
  undefined2 in_FPUControlWord;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_1028;
  undefined4 local_1024;
  undefined4 local_1020;
  int local_101c;
  undefined2 local_1014;
  undefined2 uStack_1012;
  undefined1 local_1010 [12];
  undefined1 local_1004 [4096];
  
  local_1028 = 0x1000;
  gcc2_compiled_(local_1010);
  local_1024 = 0xca;
  local_1020 = 0x2c;
  iVar1 = recvTMessage__15EasyTitanSocketPcPUlN22i
                    (param_1 + 0x8064,local_1004,&local_1028,&local_1024,&local_1020,0);
  if (iVar1 == 0) {
    setBuffer__10ReadBufferPCcUl(local_1010,local_1004,local_1028);
    *(undefined4 *)(param_1 + 0x8094) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x8098) = 0xffffffff;
    iVar1 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey(param_1,local_1010,0);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x8058) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x8058) = 1;
    tVar2 = time((time_t *)0x0);
    _local_1014 = CONCAT22(uStack_1012,in_FPUControlWord);
    local_101c = (int)ROUND((float)tVar2 + 5.0);
    *(int *)(param_1 + 0x8054) = local_101c;
    *(int *)(param_1 + 0x8050) = *(int *)(param_1 + 0x8050) + -1;
    uVar4 = *(undefined4 *)(param_1 + 4);
    uVar3 = *(undefined4 *)(param_1 + 0x8008);
  }
  else {
    if (iVar1 == 0x3f4) {
      return;
    }
    *(undefined4 *)(param_1 + 0x8058) = 1;
    tVar2 = time((time_t *)0x0);
    _local_1014 = CONCAT22(uStack_1012,in_FPUControlWord);
    local_101c = (int)ROUND((float)tVar2 + 5.0);
    *(int *)(param_1 + 0x8054) = local_101c;
    *(int *)(param_1 + 0x8050) = *(int *)(param_1 + 0x8050) + -1;
    uVar4 = *(undefined4 *)(param_1 + 4);
    uVar3 = *(undefined4 *)(param_1 + 0x8008);
  }
  connect__10EasySocketliii(param_1 + 0x8064,uVar3,uVar4,0,1);
  return;
}


