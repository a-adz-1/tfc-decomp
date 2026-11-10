// refreshCertificate__11AuthRequest  @ 000d45cc
void refreshCertificate__11AuthRequest(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  time_t tVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_40 [12];
  undefined1 local_34 [12];
  int local_28;
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  __11WriteBufferUl(local_14,0x100);
  appendLong__11WriteBufferl(local_14,0);
  appendLong__11WriteBufferl(local_14,0xca);
  appendLong__11WriteBufferl(local_14,0x2b);
  uVar1 = GetUserId__C20WON_AuthCertificate1(*(undefined4 *)(param_1 + 0x819c));
  appendLong__11WriteBufferl(local_14,uVar1);
  __11WriteBufferUl(local_24,0x100);
  for (local_28 = 0; local_28 < 6; local_28 = local_28 + 1) {
    iVar3 = rand();
    *(char *)(local_28 + param_1 + 0x81c0) = (char)iVar3 + (char)(iVar3 / 0xff);
    appendByte__11WriteBufferc(local_24,(int)*(char *)(local_28 + param_1 + 0x81c0));
  }
  uVar1 = GetUserId__C20WON_AuthCertificate1(*(undefined4 *)(param_1 + 0x819c));
  appendLong__11WriteBufferl(local_24,uVar1);
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_34,0,0);
  uVar1 = getSize__C11WriteBuffer(local_24);
  uVar2 = getBuffer__C11WriteBuffer(local_24);
  Encrypt__18WON_BFSymmetricKeyPCvUl(local_40,*(undefined4 *)(param_1 + 0x81a0),uVar2,uVar1);
  __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(local_34,local_40);
  ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
  iVar3 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_34);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x81bc) = 0xffffffff;
    ___Q216WON_CryptKeyBase11CryptReturn(local_34,2);
    ___11WriteBuffer(local_24,2);
    ___11WriteBuffer(local_14,2);
  }
  else {
    uVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_34);
    uVar2 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_34);
    append__11WriteBufferPCvUl(local_14,uVar2,uVar1);
    uVar1 = getSize__C11WriteBuffer(local_14);
    setLong__11WriteBufferUll(local_14,0,uVar1);
    uVar6 = 0;
    uVar5 = 0;
    uVar1 = getSize__C11WriteBuffer(local_14);
    uVar2 = getBuffer__C11WriteBuffer(local_14);
    iVar3 = sendBuffer__10EasySocketPCviPii(param_1 + 0x81c8,uVar2,uVar1,uVar5,uVar6);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x8190) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0x8190) = 1;
      tVar4 = time((time_t *)0x0);
      *(time_t *)(param_1 + 0x81b8) = tVar4 + 5;
      *(int *)(param_1 + 0x81bc) = *(int *)(param_1 + 0x81bc) + -1;
      connect__10EasySocketliii
                (param_1 + 0x81c8,*(undefined4 *)(param_1 + 0x8008),*(undefined4 *)(param_1 + 4),0,1
                );
    }
    ___Q216WON_CryptKeyBase11CryptReturn(local_34,2);
    ___11WriteBuffer(local_24,2);
    ___11WriteBuffer(local_14,2);
  }
  return;
}


