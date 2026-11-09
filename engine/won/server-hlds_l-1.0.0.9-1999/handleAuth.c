// handleAuth__12TitanRequestP15EasyTitanSocketP11WriteBufferT2Ul  @ 08095160
undefined4
handleAuth__12TitanRequestP15EasyTitanSocketP11WriteBufferT2Ul
          (int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iStack_40;
  undefined1 local_2c [12];
  int local_20;
  undefined4 local_1c;
  undefined1 local_14 [16];
  
  if (*(int *)(param_1 + 0x8024) == 0) {
    iStack_40 = param_4;
    uVar1 = getSize__C11WriteBuffer();
    uVar1 = getBuffer__C11WriteBuffer(param_4,uVar1);
    append__11WriteBufferPCvUl(param_3,uVar1);
  }
  else {
    iStack_40 = 0x100;
    gcc2_compiled_(local_14);
    if ((*(int *)(param_1 + 0x8010) == 0) || (*(int *)(param_1 + 0x8020) == 0)) {
      iStack_40 = param_2;
      iVar2 = handlePeerLogin__12TitanRequestUlP15EasyTitanSocket(param_1,param_5);
      if (iVar2 == 0) {
        iStack_40 = 2;
        ___11WriteBuffer(local_14);
        return 0;
      }
    }
    piVar4 = (int *)&stack0xffffffc4;
    iStack_40 = 0;
    appendLong__11WriteBufferl(param_3);
    if (*(int *)(param_1 + 0x8014) != 0) {
      iStack_40 = 2;
      appendByte__11WriteBufferc(param_3);
    }
    if (*(int *)(param_1 + 0x8010) != 0) {
      iStack_40 = (int)*(short *)(param_1 + 0x8018);
      appendShort__11WriteBuffers(param_3);
    }
    iVar2 = 0;
    if (*(int *)(param_1 + 0x800c) != 0) {
      iStack_40 = (int)*(short *)(param_1 + 0x801a);
      *(short *)(param_1 + 0x801a) = *(short *)(param_1 + 0x801a) + 1;
      setShort__11WriteBufferUls(param_4,2);
      iVar2 = 2;
    }
    if (*(int *)(param_1 + 0x8014) == 0) {
      iStack_40 = param_4;
      iVar2 = getSize__C11WriteBuffer();
      iVar2 = getBuffer__C11WriteBuffer(param_4,iVar2 + -4);
      append__11WriteBufferPCvUl(param_3,iVar2 + 4);
    }
    else {
      iStack_40 = 0;
      __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_20,0);
      iVar3 = getSize__C11WriteBuffer(param_4);
      iVar3 = getBuffer__C11WriteBuffer(param_4,iVar3 - iVar2);
      Encrypt__18WON_BFSymmetricKeyPCvUl(local_2c,*(undefined4 *)(param_1 + 0x8020),iVar3 + iVar2);
      __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_20,local_2c)
      ;
      ___Q216WON_CryptKeyBase11CryptReturn(local_2c,2);
      if (local_20 == 0) {
        printf("Error encrypting: %s\n",**(undefined4 **)(param_1 + 0x8020));
        ___Q216WON_CryptKeyBase11CryptReturn(&local_20,2);
        ___11WriteBuffer(local_14,2);
        return 0;
      }
      append__11WriteBufferPCvUl(param_3,local_20,local_1c);
      ___Q216WON_CryptKeyBase11CryptReturn(&local_20,2);
      piVar4 = &iStack_40;
    }
    *(undefined4 *)((int)piVar4 + -4) = param_3;
    *(undefined4 *)((int)piVar4 + -8) = 0x8095392;
    uVar1 = getSize__C11WriteBuffer();
    *(undefined4 *)((int)piVar4 + -8) = uVar1;
    *(undefined4 *)((int)piVar4 + -0xc) = 0;
    *(undefined4 *)((int)piVar4 + -0x10) = param_3;
    *(undefined4 *)((int)piVar4 + -0x14) = 0x809539e;
    setLong__11WriteBufferUll();
    *(undefined4 *)((int)piVar4 + -0x14) = 2;
    *(undefined1 **)((int)piVar4 + -0x18) = local_14;
    *(undefined4 *)((int)piVar4 + -0x1c) = 0x80953a9;
    ___11WriteBuffer();
  }
  return 1;
}


