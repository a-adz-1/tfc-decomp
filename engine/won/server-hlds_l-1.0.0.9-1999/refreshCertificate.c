// refreshCertificate__11AuthRequest  @ 080941a0
void refreshCertificate__11AuthRequest(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  time_t tVar3;
  int iVar4;
  char local_50;
  undefined1 local_3c [12];
  int local_30;
  undefined4 local_2c;
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  gcc2_compiled_(local_14,0x100);
  appendLong__11WriteBufferl(local_14,0);
  appendLong__11WriteBufferl(local_14,0xca);
  appendLong__11WriteBufferl(local_14,0x2b);
  uVar1 = GetUserId__C20WON_AuthCertificate1(*(undefined4 *)(param_1 + 0x8030));
  appendLong__11WriteBufferl(local_14,uVar1);
  gcc2_compiled_(local_24,0x100);
  iVar4 = 0;
  do {
    iVar2 = rand();
    local_50 = (char)(iVar2 / 0xff);
    local_50 = local_50 + (char)iVar2;
    *(char *)(iVar4 + param_1 + 0x805c) = local_50;
    appendByte__11WriteBufferc(local_24,(int)local_50);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  uVar1 = GetUserId__C20WON_AuthCertificate1(*(undefined4 *)(param_1 + 0x8030));
  appendLong__11WriteBufferl(local_24,uVar1);
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_30,0,0);
  uVar1 = getSize__C11WriteBuffer(local_24);
  uVar1 = getBuffer__C11WriteBuffer(local_24,uVar1);
  Encrypt__18WON_BFSymmetricKeyPCvUl(local_3c,*(undefined4 *)(param_1 + 0x8034),uVar1);
  __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_30,local_3c);
  ___Q216WON_CryptKeyBase11CryptReturn(local_3c,2);
  if (local_30 == 0) {
    *(undefined4 *)(param_1 + 0x8050) = 0xffffffff;
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
    iVar4 = sendBuffer__10EasySocketPCviPii(param_1 + 0x8064,uVar1);
    if (iVar4 == 0) {
      *(undefined4 *)(param_1 + 0x8058) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0x8058) = 1;
      tVar3 = time((time_t *)0x0);
      *(int *)(param_1 + 0x8054) = (int)ROUND((float)tVar3 + 5.0);
      *(int *)(param_1 + 0x8050) = *(int *)(param_1 + 0x8050) + -1;
      connect__10EasySocketliii
                (param_1 + 0x8064,*(undefined4 *)(param_1 + 0x8008),*(undefined4 *)(param_1 + 4),0,1
                );
    }
    ___Q216WON_CryptKeyBase11CryptReturn(&local_30,2);
    ___11WriteBuffer(local_24,2);
    ___11WriteBuffer(local_14,2);
  }
  return;
}


