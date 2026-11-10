// refreshCertificate__11AuthRequest  @ 0009b90c
void refreshCertificate__11AuthRequest(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  time_t tVar3;
  char *pcVar4;
  char local_50;
  undefined1 local_3c [12];
  int local_30;
  undefined4 local_2c;
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  __11WriteBufferUl(local_14,0x100);
  appendLong__11WriteBufferl(local_14,0);
  appendLong__11WriteBufferl(local_14,0xca);
  appendLong__11WriteBufferl(local_14,0x2b);
  uVar1 = GetUserId__C20WON_AuthCertificate1(*(undefined4 *)(param_1 + 0x819c));
  appendLong__11WriteBufferl(local_14,uVar1);
  __11WriteBufferUl(local_24,0x100);
  pcVar4 = (char *)(param_1 + 0x81c0);
  do {
    iVar2 = rand();
    local_50 = (char)(iVar2 / 0xff);
    local_50 = local_50 + (char)iVar2;
    *pcVar4 = local_50;
    appendByte__11WriteBufferc(local_24,(int)local_50);
    pcVar4 = pcVar4 + 1;
  } while ((int)pcVar4 <= param_1 + 0x81c5);
  uVar1 = GetUserId__C20WON_AuthCertificate1(*(undefined4 *)(param_1 + 0x819c));
  appendLong__11WriteBufferl(local_24,uVar1);
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_30,0,0);
  uVar1 = getSize__C11WriteBuffer(local_24);
  uVar1 = getBuffer__C11WriteBuffer(local_24,uVar1);
  Encrypt__18WON_BFSymmetricKeyPCvUl(local_3c,*(undefined4 *)(param_1 + 0x81a0),uVar1);
  __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_30,local_3c);
  ___Q216WON_CryptKeyBase11CryptReturn(local_3c,2);
  if (local_30 == 0) {
    *(undefined4 *)(param_1 + 0x81bc) = 0xffffffff;
    ___Q216WON_CryptKeyBase11CryptReturn(&local_30,2);
    ___11WriteBuffer(local_24,2);
    ___11WriteBuffer(local_14,2);
  }
  else {
    append__11WriteBufferPCvUl(local_14,local_30,local_2c);
    uVar1 = getSize__C11WriteBuffer(local_14);
    setLong__11WriteBufferUll(local_14,0,uVar1);
    uVar1 = getSize__C11WriteBuffer(local_14,0,0);
    uVar1 = getBuffer__C11WriteBuffer(local_14,uVar1);
    iVar2 = sendBuffer__10EasySocketPCviPii(param_1 + 0x81c8,uVar1);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x8190) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0x8190) = 1;
      tVar3 = time((time_t *)0x0);
      *(time_t *)(param_1 + 0x81b8) = tVar3 + 5;
      *(int *)(param_1 + 0x81bc) = *(int *)(param_1 + 0x81bc) + -1;
      connect__10EasySocketliii
                (param_1 + 0x81c8,*(undefined4 *)(param_1 + 0x8008),*(undefined4 *)(param_1 + 4),0,1
                );
    }
    ___Q216WON_CryptKeyBase11CryptReturn(&local_30,2);
    ___11WriteBuffer(local_24,2);
    ___11WriteBuffer(local_14,2);
  }
  return;
}


