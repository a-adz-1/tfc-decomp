// handleAuth__12TitanRequestP15EasyTitanSocketP11WriteBufferT2Ul  @ 000d0358
undefined4
handleAuth__12TitanRequestP15EasyTitanSocketP11WriteBufferT2Ul
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iStack_50;
  undefined1 local_30 [12];
  undefined1 local_24 [12];
  int local_18;
  undefined1 local_14 [16];
  
  if (*(int *)(param_1 + 0x8024) == 0) {
    uVar2 = getSize__C11WriteBuffer(param_4);
    uVar3 = getBuffer__C11WriteBuffer(param_4);
    append__11WriteBufferPCvUl(param_3,uVar3,uVar2);
    uVar2 = 1;
  }
  else {
    __11WriteBufferUl(local_14,0x100);
    if (((*(int *)(param_1 + 0x8010) == 0) ||
        ((*(int *)(param_1 + 0x8010) != 0 && (*(int *)(param_1 + 0x8020) == 0)))) &&
       (iVar4 = handlePeerLogin__12TitanRequestUlP15EasyTitanSocket(param_1,param_5,param_2),
       iVar4 == 0)) {
      ___11WriteBuffer(local_14,2);
      uVar2 = 0;
    }
    else {
      appendLong__11WriteBufferl(param_3,0);
      if (*(int *)(param_1 + 0x8014) != 0) {
        appendByte__11WriteBufferc(param_3,2);
      }
      if (*(int *)(param_1 + 0x8010) != 0) {
        appendShort__11WriteBuffers(param_3,(int)*(short *)(param_1 + 0x8018));
      }
      local_18 = 0;
      if (*(int *)(param_1 + 0x800c) != 0) {
        sVar1 = *(short *)(param_1 + 0x801a);
        *(short *)(param_1 + 0x801a) = *(short *)(param_1 + 0x801a) + 1;
        setShort__11WriteBufferUls(param_4,2,(int)sVar1);
        local_18 = 2;
      }
      if (*(int *)(param_1 + 0x8014) == 0) {
        iVar4 = getSize__C11WriteBuffer(param_4);
        iVar4 = iVar4 + -4;
        iVar5 = getBuffer__C11WriteBuffer(param_4);
        append__11WriteBufferPCvUl(param_3,iVar5 + 4,iVar4);
        piVar6 = (int *)&stack0xffffffb4;
      }
      else {
        __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_24,0,0);
        iStack_50 = getSize__C11WriteBuffer(param_4);
        iStack_50 = iStack_50 - local_18;
        iVar4 = getBuffer__C11WriteBuffer(param_4);
        Encrypt__18WON_BFSymmetricKeyPCvUl
                  (local_30,*(undefined4 *)(param_1 + 0x8020),iVar4 + local_18);
        __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                  (local_24,local_30);
        ___Q216WON_CryptKeyBase11CryptReturn(local_30,2);
        iVar4 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_24);
        if (iVar4 == 0) {
          uVar2 = GetLastError__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8020));
          printf("Error encrypting: %s\n",uVar2);
          ___Q216WON_CryptKeyBase11CryptReturn(local_24,2);
          ___11WriteBuffer(local_14,2);
          return 0;
        }
        uVar2 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_24);
        uVar3 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_24);
        append__11WriteBufferPCvUl(param_3,uVar3,uVar2);
        ___Q216WON_CryptKeyBase11CryptReturn(local_24,2);
        piVar6 = &iStack_50;
      }
      *(undefined4 *)((int)piVar6 + -0x14) = param_3;
      *(undefined4 *)((int)piVar6 + -0x18) = 0xd0624;
      uVar2 = getSize__C11WriteBuffer();
      *(undefined4 *)((int)piVar6 + -8) = uVar2;
      *(undefined4 *)((int)piVar6 + -0xc) = 0;
      *(undefined4 *)((int)piVar6 + -0x10) = param_3;
      *(undefined4 *)((int)piVar6 + -0x14) = 0xd0635;
      setLong__11WriteBufferUll();
      *(undefined4 *)((int)piVar6 + -0xc) = 2;
      *(undefined1 **)((int)piVar6 + -0x10) = local_14;
      *(undefined4 *)((int)piVar6 + -0x14) = 0xd0646;
      ___11WriteBuffer();
      uVar2 = 1;
    }
  }
  return uVar2;
}


