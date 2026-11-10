// Crypt_AuthChallenge1__FPviP15authchallenge_s  @ 000964f4
undefined4
Crypt_AuthChallenge1__FPviP15authchallenge_s(undefined2 *param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  void *__dest;
  void *__src;
  size_t __n;
  undefined1 local_2c [16];
  undefined1 local_1c [12];
  int local_10;
  undefined4 local_c;
  
  if ((gAuthRequest == 0) || (iVar3 = GetCertificate__11AuthRequest(gAuthRequest), iVar3 == 0)) {
    return 0;
  }
  iVar4 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs(param_1 + 1,*param_1);
  if (iVar4 == 0) {
    return 1;
  }
  iVar5 = IsValid__C20WON_AuthFamilyBuffer(iVar4);
  if ((iVar5 != 0) &&
     (iVar5 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(gAuthRequest,iVar4), iVar5 != 0
     )) {
    uVar6 = GetUserId__C20WON_AuthCertificate1(iVar4);
    *(undefined4 *)(param_3 + 0x34) = uVar6;
    uVar6 = GetPubKey__C20WON_AuthCertificate1(iVar4);
    uVar1 = GetPubKeyLen__C20WON_AuthCertificate1(iVar4,uVar6);
    iVar5 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar1);
    if (iVar5 != 0) {
      iVar7 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
      if (iVar7 == 0) {
        DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(iVar5);
        return 1;
      }
      __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_10,0,0);
      uVar1 = GetKeyLen__C16WON_CryptKeyBase(iVar7);
      uVar6 = GetKey__C16WON_CryptKeyBase(iVar7,uVar1);
      Encrypt__15WON_EGPublicKeyPCvUl(local_1c,iVar5,uVar6);
      __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_10,local_1c)
      ;
      ___Q216WON_CryptKeyBase11CryptReturn(local_1c,2);
      if (local_10 == 0) {
        DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(iVar5);
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(iVar7);
        ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
        return 1;
      }
      if (*(int *)(param_3 + 0x30) != 0) {
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int *)(param_3 + 0x30));
        *(undefined4 *)(param_3 + 0x30) = 0;
      }
      *(int *)(param_3 + 0x30) = iVar7;
      __11WriteBufferUl(local_2c,0x100);
      appendLong__11WriteBufferl(local_2c,0xffffffff);
      appendByte__11WriteBufferc(local_2c,0x34);
      sVar2 = GetRawLen__C20WON_AuthFamilyBuffer(iVar3);
      appendShort__11WriteBuffers(local_2c,(int)sVar2);
      uVar1 = GetRawLen__C20WON_AuthFamilyBuffer(iVar3);
      uVar6 = GetRaw__C20WON_AuthFamilyBuffer(iVar3,uVar1);
      append__11WriteBufferPCvUl(local_2c,uVar6);
      appendShort__11WriteBuffers(local_2c,(int)(short)local_c);
      append__11WriteBufferPCvUl(local_2c,local_10,local_c);
      if (*(void **)(param_3 + 0x2c) != (void *)0x0) {
        free(*(void **)(param_3 + 0x2c));
      }
      iVar3 = getSize__C11WriteBuffer(local_2c);
      __dest = malloc(iVar3 + 1);
      *(void **)(param_3 + 0x2c) = __dest;
      __src = (void *)getBuffer__C11WriteBuffer(local_2c);
      __n = getSize__C11WriteBuffer(local_2c);
      memcpy(__dest,__src,__n);
      uVar6 = getSize__C11WriteBuffer(local_2c);
      *(undefined4 *)(param_3 + 0x28) = uVar6;
      ___11WriteBuffer(local_2c,2);
      ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
      return 2;
    }
  }
  DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
  return 1;
}


// Crypt_AuthChallenge2__FPviP15authchallenge_s  @ 000967b4
undefined4
Crypt_AuthChallenge2__FPviP15authchallenge_s(ushort *param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  void *__dest;
  void *__src;
  size_t __n;
  undefined2 *puVar9;
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined1 local_1c [12];
  int local_10;
  uint local_c;
  
  uVar1 = *param_1;
  if ((gAuthRequest == 0) || (iVar4 = GetCertificate__11AuthRequest(gAuthRequest), iVar4 == 0)) {
    return 0;
  }
  iVar4 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs(param_1 + 1,(uint)uVar1);
  if (iVar4 == 0) {
    return 1;
  }
  puVar9 = (undefined2 *)((int)(param_1 + 1) + (uint)uVar1);
  iVar5 = IsValid__C20WON_AuthFamilyBuffer(iVar4);
  if ((iVar5 != 0) &&
     (iVar5 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(gAuthRequest,iVar4), iVar5 != 0
     )) {
    uVar6 = GetPubKey__C20WON_AuthCertificate1(iVar4);
    uVar2 = GetPubKeyLen__C20WON_AuthCertificate1(iVar4,uVar6);
    piVar7 = (int *)NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar2);
    if (piVar7 != (int *)0x0) {
      piVar8 = (int *)GetPrivateKey__11AuthRequest(gAuthRequest);
      if (piVar8 == (int *)0x0) {
        DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar7);
        return 1;
      }
      uVar2 = *puVar9;
      __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_10,0,0);
      Decrypt__16WON_EGPrivateKeyPCUcUl(local_1c,piVar8,puVar9 + 1,uVar2);
      __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_10,local_1c)
      ;
      ___Q216WON_CryptKeyBase11CryptReturn(local_1c,2);
      if ((local_10 == 0) || (*piVar8 != 0)) {
        DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar7);
        ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
        return 1;
      }
      if (gConnectionKey != 0) {
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(gConnectionKey);
        gConnectionKey = 0;
      }
      gConnectionKey = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(local_c & 0xffff,local_10);
      if (gConnectionKey == 0) {
        DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar7);
        ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
        return 1;
      }
      __11WriteBufferUl(local_2c,0x100);
      iVar5 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
      if (iVar5 == 0) {
        DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar7);
        ___11WriteBuffer(local_2c,2);
        ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
        return 1;
      }
      appendShort__11WriteBuffers(local_2c,(int)(short)local_c);
      append__11WriteBufferPCvUl(local_2c,local_10,local_c);
      sVar3 = GetKeyLen__C16WON_CryptKeyBase(iVar5);
      appendShort__11WriteBuffers(local_2c,(int)sVar3);
      uVar2 = GetKeyLen__C16WON_CryptKeyBase(iVar5);
      uVar6 = GetKey__C16WON_CryptKeyBase(iVar5,uVar2);
      append__11WriteBufferPCvUl(local_2c,uVar6);
      if (*(int *)(param_3 + 0x30) != 0) {
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int *)(param_3 + 0x30));
        *(undefined4 *)(param_3 + 0x30) = 0;
      }
      *(int *)(param_3 + 0x30) = iVar5;
      uVar6 = getSize__C11WriteBuffer(local_2c);
      uVar6 = getBuffer__C11WriteBuffer(local_2c,uVar6);
      Encrypt__15WON_EGPublicKeyPCvUl(local_1c,piVar7,uVar6);
      __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_10,local_1c)
      ;
      ___Q216WON_CryptKeyBase11CryptReturn(local_1c,2);
      if ((local_10 != 0) && (*piVar7 == 0)) {
        __11WriteBufferUl(local_3c,0x100);
        appendLong__11WriteBufferl(local_3c,0xffffffff);
        appendByte__11WriteBufferc(local_3c,0x35);
        appendShort__11WriteBuffers(local_3c,(int)(short)local_c);
        append__11WriteBufferPCvUl(local_3c,local_10,local_c);
        if (*(void **)(param_3 + 0x2c) != (void *)0x0) {
          free(*(void **)(param_3 + 0x2c));
        }
        iVar5 = getSize__C11WriteBuffer(local_3c);
        __dest = malloc(iVar5 + 1);
        *(void **)(param_3 + 0x2c) = __dest;
        __src = (void *)getBuffer__C11WriteBuffer(local_3c);
        __n = getSize__C11WriteBuffer(local_3c);
        memcpy(__dest,__src,__n);
        uVar6 = getSize__C11WriteBuffer(local_3c);
        *(undefined4 *)(param_3 + 0x28) = uVar6;
        DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar7);
        ___11WriteBuffer(local_3c,2);
        ___11WriteBuffer(local_2c,2);
        ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
        return 2;
      }
      DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
      DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar7);
      DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(iVar5);
      ___11WriteBuffer(local_2c,2);
      ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
      return 1;
    }
  }
  DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar4);
  return 1;
}


// Crypt_AuthComplete__FPviP15authchallenge_s  @ 00096c4c
undefined4
Crypt_AuthComplete__FPviP15authchallenge_s(undefined2 *param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  void *__dest;
  void *__src;
  size_t __n;
  bool bVar10;
  bool bVar11;
  short local_30;
  ushort local_2e;
  undefined1 local_2c [16];
  undefined1 local_1c [12];
  int local_10;
  undefined4 local_c;
  
  uVar1 = *param_1;
  if ((gAuthRequest == 0) || (iVar3 = GetCertificate__11AuthRequest(gAuthRequest), iVar3 == 0)) {
    return 0;
  }
  piVar4 = (int *)GetPrivateKey__11AuthRequest(gAuthRequest);
  if (piVar4 == (int *)0x0) {
    return 1;
  }
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_10,0,0);
  Decrypt__16WON_EGPrivateKeyPCUcUl(local_1c,piVar4,param_1 + 1,uVar1);
  __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_10,local_1c);
  ___Q216WON_CryptKeyBase11CryptReturn(local_1c,2);
  if ((local_10 == 0) || (*piVar4 != 0)) {
    ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
    return 1;
  }
  __10ReadBufferPCcUl(local_1c,local_10,local_c);
  iVar3 = *(int *)(param_3 + 0x30);
  if (iVar3 == 0) {
    ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
    return 1;
  }
  uVar5 = readUShort__10ReadBufferPUs(local_1c,&local_2e);
  pbVar6 = (byte *)getDataPtr__10ReadBuffer(local_1c);
  uVar7 = skipBytes__10ReadBufferUl(local_1c,local_2e);
  if (((uVar7 & uVar5 & 1) == 0) ||
     (uVar2 = GetKeyLen__C16WON_CryptKeyBase(iVar3), local_2e != uVar2)) {
    ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
    return 1;
  }
  uVar7 = (uint)local_2e;
  pbVar8 = (byte *)GetKey__C16WON_CryptKeyBase(iVar3);
  bVar10 = false;
  uVar5 = 0;
  bVar11 = true;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    bVar10 = *pbVar8 < *pbVar6;
    bVar11 = *pbVar8 == *pbVar6;
    pbVar8 = pbVar8 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar11);
  if (!bVar11) {
    uVar5 = -(uint)bVar10 | 1;
  }
  if (uVar5 != 0) {
    ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
    return 1;
  }
  readUShort__10ReadBufferPUs(local_1c,&local_30);
  uVar9 = getDataPtr__10ReadBuffer(local_1c);
  skipBytes__10ReadBufferUl(local_1c,local_30);
  __11WriteBufferUl(local_2c,0x100);
  appendLong__11WriteBufferl(local_2c,0xffffffff);
  appendByte__11WriteBufferc(local_2c,0x36);
  appendShort__11WriteBuffers(local_2c,(int)local_30);
  append__11WriteBufferPCvUl(local_2c,uVar9,local_30);
  if (*(void **)(param_3 + 0x2c) != (void *)0x0) {
    free(*(void **)(param_3 + 0x2c));
  }
  iVar3 = getSize__C11WriteBuffer(local_2c);
  __dest = malloc(iVar3 + 1);
  *(void **)(param_3 + 0x2c) = __dest;
  __src = (void *)getBuffer__C11WriteBuffer(local_2c);
  __n = getSize__C11WriteBuffer(local_2c);
  memcpy(__dest,__src,__n);
  uVar9 = getSize__C11WriteBuffer(local_2c);
  *(undefined4 *)(param_3 + 0x28) = uVar9;
  ___11WriteBuffer(local_2c,2);
  ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
  return 2;
}


// Crypt_AuthRequest__FPviP15authchallenge_s  @ 000963e0
undefined4
Crypt_AuthRequest__FPviP15authchallenge_s(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *__dest;
  void *__src;
  size_t __n;
  undefined1 local_14 [16];
  
  if (gAuthRequest == 0) {
    uVar3 = 0;
  }
  else {
    __11WriteBufferUl(local_14,0x100);
    iVar4 = GetCertificate__11AuthRequest(gAuthRequest);
    if (iVar4 == 0) {
      ___11WriteBuffer(local_14,2);
      uVar3 = 0;
    }
    else {
      appendLong__11WriteBufferl(local_14,0xffffffff);
      appendByte__11WriteBufferc(local_14,0x33);
      sVar1 = GetRawLen__C20WON_AuthFamilyBuffer(iVar4);
      appendShort__11WriteBuffers(local_14,(int)sVar1);
      uVar2 = GetRawLen__C20WON_AuthFamilyBuffer(iVar4);
      uVar3 = GetRaw__C20WON_AuthFamilyBuffer(iVar4,uVar2);
      append__11WriteBufferPCvUl(local_14,uVar3);
      if (*(void **)(param_3 + 0x2c) != (void *)0x0) {
        free(*(void **)(param_3 + 0x2c));
      }
      iVar4 = getSize__C11WriteBuffer(local_14);
      __dest = malloc(iVar4 + 1);
      *(void **)(param_3 + 0x2c) = __dest;
      __src = (void *)getBuffer__C11WriteBuffer(local_14);
      __n = getSize__C11WriteBuffer(local_14);
      memcpy(__dest,__src,__n);
      uVar3 = getSize__C11WriteBuffer(local_14);
      *(undefined4 *)(param_3 + 0x28) = uVar3;
      ___11WriteBuffer(local_14,2);
      uVar3 = 2;
    }
  }
  return uVar3;
}


// Crypt_CreateKey__FiPCUcPPv  @ 00097204
undefined4 Crypt_CreateKey__FiPCUcPPv(undefined2 param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == (int *)0x0) {
LAB_0009722a:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      iVar1 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(param_1,0);
      if (iVar1 == 0) goto LAB_0009722a;
    }
    else {
      iVar1 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(param_1,param_2);
    }
    *param_3 = iVar1;
    uVar2 = 1;
  }
  return uVar2;
}


// Crypt_DecodeAuthComplete__FPviP15authchallenge_s  @ 00096ee8
undefined4
Crypt_DecodeAuthComplete__FPviP15authchallenge_s(ushort *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  ushort *puVar5;
  bool bVar6;
  
  uVar4 = (uint)*param_1;
  iVar1 = *(int *)(param_3 + 0x30);
  if ((iVar1 != 0) && (uVar2 = GetKeyLen__C16WON_CryptKeyBase(iVar1), uVar4 == (uVar2 & 0xffff))) {
    pcVar3 = (char *)GetKey__C16WON_CryptKeyBase(iVar1);
    bVar6 = true;
    puVar5 = param_1 + 1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      bVar6 = (char)*puVar5 == *pcVar3;
      puVar5 = (ushort *)((int)puVar5 + 1);
      pcVar3 = pcVar3 + 1;
    } while (bVar6);
    if (bVar6) {
      return 2;
    }
  }
  return 1;
}


// Crypt_Decrypt__FPCvT0iPvPi  @ 00097348
undefined4
Crypt_Decrypt__FPCvT0iPvPi
          (int param_1,undefined4 param_2,undefined4 param_3,void *param_4,size_t *param_5)

{
  undefined4 uVar1;
  undefined1 local_1c [12];
  void *local_10;
  size_t local_c;
  
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_10,0,0);
  if (param_1 == 0) {
    ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
    uVar1 = 0;
  }
  else {
    Decrypt__18WON_BFSymmetricKeyPCUcUl(local_1c,param_1,param_2,param_3);
    __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_10,local_1c);
    ___Q216WON_CryptKeyBase11CryptReturn(local_1c,2);
    if (local_10 == (void *)0x0) {
      ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
      uVar1 = 0;
    }
    else {
      memcpy(param_4,local_10,local_c);
      *param_5 = local_c;
      ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
      uVar1 = 1;
    }
  }
  return uVar1;
}


// Crypt_DeleteAuthData__FP15authchallenge_s  @ 0009634c
void Crypt_DeleteAuthData__FP15authchallenge_s(int param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int *)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    free(*(void **)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return;
}


// Crypt_DeleteKey__FPPv  @ 0009724c
void Crypt_DeleteKey__FPPv(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_1);
    *param_1 = 0;
  }
  return;
}


// Crypt_DestroyAuthObject__Fv  @ 00094c2c
void Crypt_DestroyAuthObject__Fv(void)

{
  if (gAuthRequest != 0) {
    (**(code **)(*(int *)(gAuthRequest + 0x8028) + 8))(gAuthRequest,3);
    gAuthRequest = 0;
  }
  return;
}


// Crypt_Encrypt__FPCvT0iPvPi  @ 00097270
undefined4
Crypt_Encrypt__FPCvT0iPvPi
          (int param_1,undefined4 param_2,undefined4 param_3,void *param_4,size_t *param_5)

{
  undefined4 uVar1;
  undefined1 local_1c [12];
  void *local_10;
  size_t local_c;
  
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_10,0,0);
  if (param_1 == 0) {
    ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
    uVar1 = 0;
  }
  else {
    Encrypt__18WON_BFSymmetricKeyPCvUl(local_1c,param_1,param_2,param_3);
    __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_10,local_1c);
    ___Q216WON_CryptKeyBase11CryptReturn(local_1c,2);
    if (local_10 == (void *)0x0) {
      ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
      uVar1 = 0;
    }
    else {
      memcpy(param_4,local_10,local_c);
      *param_5 = local_c;
      ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
      uVar1 = 1;
    }
  }
  return uVar1;
}


// Crypt_GetAuthObject__Fv  @ 000949b4
undefined4 Crypt_GetAuthObject__Fv(void)

{
  return gAuthRequest;
}


// Crypt_GetCertificate__FPvPi  @ 0009442c
undefined4 Crypt_GetCertificate__FPvPi(void *param_1,uint *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  void *__src;
  uint __n;
  
  if (gAuthRequest == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = GetCertificate__11AuthRequest(gAuthRequest);
    if (iVar3 != 0) {
      uVar1 = GetRawLen__C20WON_AuthFamilyBuffer(iVar3);
      __n = (uint)uVar1;
      *param_2 = __n;
      if (__n != 0) {
        __src = (void *)GetRaw__C20WON_AuthFamilyBuffer(iVar3);
        memcpy(param_1,__src,__n);
        return 2;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


// Crypt_GetConnectionKey__FPvPi  @ 00096388
undefined4 Crypt_GetConnectionKey__FPvPi(void *param_1,uint *param_2)

{
  ushort uVar1;
  void *__src;
  uint uVar2;
  undefined4 uVar3;
  
  if (gConnectionKey == 0) {
    uVar3 = 0;
  }
  else {
    __src = (void *)GetKey__C16WON_CryptKeyBase(gConnectionKey);
    uVar2 = GetKeyLen__C16WON_CryptKeyBase(gConnectionKey);
    memcpy(param_1,__src,uVar2 & 0xffff);
    uVar1 = GetKeyLen__C16WON_CryptKeyBase(gConnectionKey);
    *param_2 = (uint)uVar1;
    uVar3 = 2;
  }
  return uVar3;
}


// Crypt_GetNewCertificate__Fv  @ 00094490
int Crypt_GetNewCertificate__Fv(void)

{
  undefined *puVar1;
  undefined *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int local_124;
  int local_120;
  undefined *local_11c;
  undefined *local_118;
  undefined1 local_114 [272];
  
  local_124 = 0;
  __11CServerList(local_114);
  local_120 = 2;
  do {
    ResetAuthList__11CServerList(local_114);
    while (iVar4 = FillInNextAuthServer__11CServerList(local_114), iVar4 != 0) {
      if (gAuthRequest != 0) {
        puVar6 = (uint *)GetAuthServerAddress__11CServerList(local_114);
        if (force_to_data[0xc] == '\0') {
          force_to_data._8_4_ = force_to_data._8_4_ + 1;
          local_11c = &DAT_000b1f78;
        }
        else {
          local_11c = (undefined *)
                      clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                (force_to_data);
        }
        uVar10 = (uint)puVar6 & 3;
        puVar3 = puVar6;
        if (uVar10 == 0) {
LAB_000946dc:
          do {
            puVar7 = puVar3;
            uVar10 = *puVar7;
            if ((char)uVar10 == '\0') goto LAB_000946fe;
            if ((char)(uVar10 >> 8) == '\0') goto LAB_000946fd;
            if ((uVar10 & 0xff0000) == 0) goto LAB_000946fc;
            puVar3 = puVar7 + 1;
          } while ((uVar10 & 0xff000000) != 0);
          puVar7 = (uint *)((int)puVar7 + 1);
LAB_000946fc:
          puVar7 = (uint *)((int)puVar7 + 1);
LAB_000946fd:
          puVar7 = (uint *)((int)puVar7 + 1);
        }
        else {
          puVar7 = puVar6;
          if ((POPCOUNT(uVar10) & 1U) == 0) {
LAB_000946d7:
            if ((char)*puVar7 != '\0') {
              puVar3 = (uint *)((int)puVar7 + 1);
              goto LAB_000946dc;
            }
          }
          else if (uVar10 == 2) {
LAB_000946d2:
            if ((char)*puVar7 != '\0') {
              puVar7 = (uint *)((int)puVar7 + 1);
              goto LAB_000946d7;
            }
          }
          else if ((char)*puVar6 != '\0') {
            puVar7 = (uint *)((int)puVar6 + 1);
            goto LAB_000946d2;
          }
        }
LAB_000946fe:
        replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                  (&local_11c,0,0xffffffff,puVar6,(int)puVar7 - (int)puVar6);
        uVar5 = GetAuthServerPort__11CServerList(local_114);
        setAddrAndPort__11AuthRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                  (gAuthRequest,&local_11c,uVar5);
        puVar2 = local_11c;
        puVar1 = local_11c + -0x10;
        iVar4 = *(int *)(local_11c + -8);
        *(int *)(local_11c + -8) = iVar4 + -1;
        if (iVar4 == 1) {
          if (*(int *)(local_11c + -0xc) + 0x10U < 0x81) {
            iVar4 = (*(int *)(local_11c + -0xc) + 0x17U >> 3) * 4;
            pthread_mutex_lock((pthread_mutex_t *)
                               _t24__default_alloc_template2b1i0___node_allocator_lock);
            *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar4);
            *(undefined **)(&DAT_000b3e5c + iVar4) = puVar1;
            pthread_mutex_unlock
                      ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
          }
          else {
            free(puVar1);
          }
        }
        goto LAB_0009479e;
      }
      uVar5 = __builtin_new(0x8404);
      puVar6 = (uint *)GetAuthServerAddress__11CServerList(local_114);
      if (force_to_data[0xc] == '\0') {
        force_to_data._8_4_ = force_to_data._8_4_ + 1;
        local_118 = &DAT_000b1f78;
      }
      else {
        local_118 = (undefined *)
                    clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                              (force_to_data);
      }
      uVar10 = (uint)puVar6 & 3;
      puVar3 = puVar6;
      if (uVar10 == 0) {
LAB_00094578:
        do {
          puVar7 = puVar3;
          uVar10 = *puVar7;
          if ((char)uVar10 == '\0') goto LAB_0009459a;
          if ((char)(uVar10 >> 8) == '\0') goto LAB_00094599;
          if ((uVar10 & 0xff0000) == 0) goto LAB_00094598;
          puVar3 = puVar7 + 1;
        } while ((uVar10 & 0xff000000) != 0);
        puVar7 = (uint *)((int)puVar7 + 1);
LAB_00094598:
        puVar7 = (uint *)((int)puVar7 + 1);
LAB_00094599:
        puVar7 = (uint *)((int)puVar7 + 1);
      }
      else {
        puVar7 = puVar6;
        if ((POPCOUNT(uVar10) & 1U) == 0) {
LAB_00094573:
          if ((char)*puVar7 != '\0') {
            puVar3 = (uint *)((int)puVar7 + 1);
            goto LAB_00094578;
          }
        }
        else if (uVar10 == 2) {
LAB_0009456e:
          if ((char)*puVar7 != '\0') {
            puVar7 = (uint *)((int)puVar7 + 1);
            goto LAB_00094573;
          }
        }
        else if ((char)*puVar6 != '\0') {
          puVar7 = (uint *)((int)puVar6 + 1);
          goto LAB_0009456e;
        }
      }
LAB_0009459a:
      replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                (&local_118,0,0xffffffff,puVar6,(int)puVar7 - (int)puVar6);
      uVar8 = GetAuthServerPort__11CServerList(local_114);
      iVar9 = __11AuthRequestPCcT1RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                        (uVar5,g_szExeName,g_szGUID,&local_118,uVar8);
      puVar2 = local_118;
      puVar1 = local_118 + -0x10;
      iVar4 = *(int *)(local_118 + -8);
      *(int *)(local_118 + -8) = iVar4 + -1;
      if (iVar4 == 1) {
        if (*(int *)(local_118 + -0xc) + 0x10U < 0x81) {
          iVar4 = (*(int *)(local_118 + -0xc) + 0x17U >> 3) * 4;
          pthread_mutex_lock((pthread_mutex_t *)
                             _t24__default_alloc_template2b1i0___node_allocator_lock);
          *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar4);
          *(undefined **)(&DAT_000b3e5c + iVar4) = puVar1;
          pthread_mutex_unlock
                    ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
        }
        else {
          free(puVar1);
        }
      }
      gAuthRequest = iVar9;
      if (iVar9 != 0) {
LAB_0009479e:
        iVar4 = getAuthVerifierKey__11AuthRequestPCc(gAuthRequest,"kver.kp");
        if (iVar4 != 0) {
          iVar4 = getCertificate__11AuthRequesti(gAuthRequest,1);
          if ((iVar4 != 0) && (iVar4 = GetCertificate__11AuthRequest(gAuthRequest), iVar4 != 0)) {
            local_124 = 1;
            break;
          }
          iVar4 = ReceivedResponse__11AuthRequest(gAuthRequest);
          if (iVar4 != 0) {
            local_120 = 0;
          }
        }
      }
    }
    local_120 = local_120 + -1;
    if ((local_120 < 0) || (local_124 != 0)) {
      if ((gAuthRequest != 0) && (local_124 == 0)) {
        if (Callback_Printf != (code *)0x0) {
          uVar5 = GetLastError__11AuthRequest(gAuthRequest);
          (*Callback_Printf)(&DAT_000aefcc,uVar5);
        }
        if (Callback_AuthFailure != (code *)0x0) {
          (*Callback_AuthFailure)();
        }
      }
      ___11CServerList(local_114,2);
      return local_124;
    }
  } while( true );
}


// Crypt_GetRawBFKey__FPvT0Pi  @ 000962fc
undefined4 Crypt_GetRawBFKey__FPvT0Pi(int param_1,void *param_2,uint *param_3)

{
  ushort uVar1;
  void *__src;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    __src = (void *)GetKey__C16WON_CryptKeyBase(param_1);
    uVar2 = GetKeyLen__C16WON_CryptKeyBase(param_1);
    memcpy(param_2,__src,uVar2 & 0xffff);
    uVar1 = GetKeyLen__C16WON_CryptKeyBase(param_1);
    *param_3 = (uint)uVar1;
    uVar3 = 2;
  }
  return uVar3;
}


// Crypt_GetUserId__Fv  @ 000943fc
undefined4 Crypt_GetUserId__Fv(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((gAuthRequest != 0) && (iVar1 = GetCertificate__11AuthRequest(gAuthRequest), iVar1 != 0)) {
    uVar2 = GetUserId__C20WON_AuthCertificate1(iVar1);
    return uVar2;
  }
  return 0xffffffff;
}


// Crypt_Initialize__FP13crypt_parms_s  @ 00096210
void Crypt_Initialize__FP13crypt_parms_s(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    g_isDedicated = *param_1;
    strcpy(g_szGUID,(char *)param_1[2]);
    strcpy(g_szServerFile,(char *)param_1[3]);
    strcpy(g_szBaseDir,(char *)param_1[1]);
    strcpy(g_szExeName,(char *)param_1[4]);
    Callback_Printf = param_1[5];
    Callback_AuthFailure = param_1[6];
    Callback_GetLocalizedString = (code *)param_1[7];
    if (Callback_GetLocalizedString == (code *)0x0) {
      Callback_GetLocalizedString = STUB_Callback_GetLocalizedString__FUi;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("crypt_parms","/home/jihad/valve/goldsrc/utils/crypt/cryptapi.cpp",0x33,
                "void Crypt_Initialize(struct crypt_parms_s *)");
}


// Crypt_InstanceAuthObject__Fv  @ 000949c0
int Crypt_InstanceAuthObject__Fv(void)

{
  undefined *__ptr;
  int iVar1;
  undefined *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined *local_118;
  undefined1 local_114 [272];
  
  __11CServerList(local_114);
  iVar8 = gAuthRequest;
  if (gAuthRequest != 0) goto LAB_00094b56;
  uVar4 = __builtin_new(0x8404);
  puVar5 = (uint *)GetAuthServerAddress__11CServerList(local_114);
  if (force_to_data[0xc] == '\0') {
    force_to_data._8_4_ = force_to_data._8_4_ + 1;
    local_118 = &DAT_000b1f78;
  }
  else {
    local_118 = (undefined *)
                clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                          (force_to_data);
  }
  uVar9 = (uint)puVar5 & 3;
  puVar3 = puVar5;
  if (uVar9 == 0) {
LAB_00094a68:
    do {
      puVar6 = puVar3;
      uVar9 = *puVar6;
      if ((char)uVar9 == '\0') goto LAB_00094a8a;
      if ((char)(uVar9 >> 8) == '\0') goto LAB_00094a89;
      if ((uVar9 & 0xff0000) == 0) goto LAB_00094a88;
      puVar3 = puVar6 + 1;
    } while ((uVar9 & 0xff000000) != 0);
    puVar6 = (uint *)((int)puVar6 + 1);
LAB_00094a88:
    puVar6 = (uint *)((int)puVar6 + 1);
LAB_00094a89:
    puVar6 = (uint *)((int)puVar6 + 1);
  }
  else {
    puVar6 = puVar5;
    if ((POPCOUNT(uVar9) & 1U) == 0) {
LAB_00094a63:
      if ((char)*puVar6 != '\0') {
        puVar3 = (uint *)((int)puVar6 + 1);
        goto LAB_00094a68;
      }
    }
    else if (uVar9 == 2) {
LAB_00094a5e:
      if ((char)*puVar6 != '\0') {
        puVar6 = (uint *)((int)puVar6 + 1);
        goto LAB_00094a63;
      }
    }
    else if ((char)*puVar5 != '\0') {
      puVar6 = (uint *)((int)puVar5 + 1);
      goto LAB_00094a5e;
    }
  }
LAB_00094a8a:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (&local_118,0,0xffffffff,puVar5,(int)puVar6 - (int)puVar5);
  uVar7 = GetAuthServerPort__11CServerList(local_114);
  iVar8 = __11AuthRequestPCcT1RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                    (uVar4,g_szExeName,g_szGUID,&local_118,uVar7);
  puVar2 = local_118;
  __ptr = local_118 + -0x10;
  iVar1 = *(int *)(local_118 + -8);
  *(int *)(local_118 + -8) = iVar1 + -1;
  if (iVar1 == 1) {
    if (*(int *)(local_118 + -0xc) + 0x10U < 0x81) {
      iVar1 = (*(int *)(local_118 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar1);
      *(undefined **)(&DAT_000b3e5c + iVar1) = __ptr;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(__ptr);
    }
  }
LAB_00094b56:
  gAuthRequest = iVar8;
  iVar8 = gAuthRequest;
  ___11CServerList(local_114,2);
  return iVar8;
}


// Crypt_IsAuthenticated__Fv  @ 00094c58
undefined4 Crypt_IsAuthenticated__Fv(void)

{
  int iVar1;
  
  if ((gAuthRequest != 0) && (iVar1 = GetCertificate__11AuthRequest(gAuthRequest), iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// Crypt_MD5_File__FPUcPc  @ 000962b4
void Crypt_MD5_File__FPUcPc(undefined4 param_1,undefined4 param_2)

{
  MD5_Hash_File__FPUcPciPUi(param_1,param_2,0,0);
  return;
}


// Crypt_ParseServers__FPc  @ 00094e5c
/* WARNING: Removing unreachable block (ram,0x000950eb) */
/* WARNING: Removing unreachable block (ram,0x000950ed) */
/* WARNING: Removing unreachable block (ram,0x000950f2) */
/* WARNING: Removing unreachable block (ram,0x000950f6) */
/* WARNING: Removing unreachable block (ram,0x000950f7) */
/* WARNING: Removing unreachable block (ram,0x000950fb) */
/* WARNING: Removing unreachable block (ram,0x000950fc) */
/* WARNING: Removing unreachable block (ram,0x00095100) */
/* WARNING: Removing unreachable block (ram,0x00094fdb) */
/* WARNING: Removing unreachable block (ram,0x00094fdd) */
/* WARNING: Removing unreachable block (ram,0x00094fe2) */
/* WARNING: Removing unreachable block (ram,0x00094fe6) */
/* WARNING: Removing unreachable block (ram,0x00094fe7) */
/* WARNING: Removing unreachable block (ram,0x00094feb) */
/* WARNING: Removing unreachable block (ram,0x00094fec) */
/* WARNING: Removing unreachable block (ram,0x00094ff0) */
/* WARNING: Removing unreachable block (ram,0x00094f57) */
/* WARNING: Removing unreachable block (ram,0x00094f59) */
/* WARNING: Removing unreachable block (ram,0x00094f5e) */
/* WARNING: Removing unreachable block (ram,0x00094f62) */
/* WARNING: Removing unreachable block (ram,0x00094f63) */
/* WARNING: Removing unreachable block (ram,0x00094f67) */
/* WARNING: Removing unreachable block (ram,0x00094f68) */
/* WARNING: Removing unreachable block (ram,0x00094f6c) */
/* WARNING: Removing unreachable block (ram,0x0009505b) */
/* WARNING: Removing unreachable block (ram,0x0009505d) */
/* WARNING: Removing unreachable block (ram,0x00095062) */
/* WARNING: Removing unreachable block (ram,0x00095066) */
/* WARNING: Removing unreachable block (ram,0x00095067) */
/* WARNING: Removing unreachable block (ram,0x0009506b) */
/* WARNING: Removing unreachable block (ram,0x0009506c) */
/* WARNING: Removing unreachable block (ram,0x00095070) */
/* WARNING: Removing unreachable block (ram,0x0009515f) */
/* WARNING: Removing unreachable block (ram,0x00095161) */
/* WARNING: Removing unreachable block (ram,0x00095166) */
/* WARNING: Removing unreachable block (ram,0x0009516a) */
/* WARNING: Removing unreachable block (ram,0x0009516b) */
/* WARNING: Removing unreachable block (ram,0x0009516f) */
/* WARNING: Removing unreachable block (ram,0x00095170) */
/* WARNING: Removing unreachable block (ram,0x00095174) */

int * Crypt_ParseServers__FPc(undefined4 param_1)

{
  uint *puVar1;
  uint16_t uVar2;
  FILE *__stream;
  size_t __size;
  void *__ptr;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int *piVar10;
  int local_258;
  undefined1 local_254 [2];
  uint16_t local_252;
  in_addr local_250;
  char local_244 [256];
  char local_144 [64];
  char local_104 [256];
  
  local_258 = 0;
  sprintf(local_104,"%s/%s",g_szBaseDir,param_1);
  __stream = fopen(local_104,"rb");
  if (__stream == (FILE *)0x0) {
    sprintf(local_104,"valve/%s",param_1);
    __stream = fopen(local_104,"rb");
    if (__stream == (FILE *)0x0) {
      return (int *)0;
    }
  }
  fseek(__stream,0,2);
  __size = ftell(__stream);
  fseek(__stream,0,0);
  if ((__size - 1 < 0x4000) && (__ptr = malloc(__size + 1), __ptr != (void *)0x0)) {
    fread(__ptr,__size,1,__stream);
    fclose(__stream);
    *(undefined1 *)(__size + (int)__ptr) = 0;
    pvVar6 = __ptr;
LAB_00094f40:
    uVar3 = Crypt_Parse__FPc(pvVar6);
    puVar1 = (uint *)&com_token;
    do {
      puVar4 = puVar1;
      uVar8 = *puVar4;
      if ((char)uVar8 == '\0') goto LAB_00094f8f;
      if ((char)(uVar8 >> 8) == '\0') goto LAB_00094f8e;
      if ((uVar8 & 0xff0000) == 0) goto LAB_00094f8d;
      puVar1 = puVar4 + 1;
    } while ((uVar8 & 0xff000000) != 0);
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_00094f8d:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_00094f8e:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_00094f8f:
    if (puVar4 != (uint *)&com_token) {
      iVar5 = strcasecmp(&com_token,"Auth");
      pvVar6 = (void *)Crypt_Parse__FPc(uVar3);
      puVar1 = (uint *)&com_token;
      do {
        puVar4 = puVar1;
        uVar8 = *puVar4;
        if ((char)uVar8 == '\0') goto LAB_00095013;
        if ((char)(uVar8 >> 8) == '\0') goto LAB_00095012;
        if ((uVar8 & 0xff0000) == 0) goto LAB_00095011;
        puVar1 = puVar4 + 1;
      } while ((uVar8 & 0xff000000) != 0);
      puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095011:
      puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095012:
      puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095013:
      if ((puVar4 != (uint *)&com_token) && (iVar7 = strcasecmp(&com_token,"{"), iVar7 == 0)) {
        do {
          pvVar6 = (void *)Crypt_Parse__FPc(pvVar6);
          puVar1 = (uint *)&com_token;
          do {
            puVar4 = puVar1;
            uVar8 = *puVar4;
            if ((char)uVar8 == '\0') goto LAB_00095093;
            if ((char)(uVar8 >> 8) == '\0') goto LAB_00095092;
            if ((uVar8 & 0xff0000) == 0) goto LAB_00095091;
            puVar1 = puVar4 + 1;
          } while ((uVar8 & 0xff000000) != 0);
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095091:
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095092:
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095093:
          if ((puVar4 == (uint *)&com_token) || (iVar7 = strcasecmp(&com_token,"}"), iVar7 == 0))
          goto LAB_00094f40;
          sprintf(local_244,"%s",&com_token);
          pvVar6 = (void *)Crypt_Parse__FPc(pvVar6);
          puVar1 = (uint *)&com_token;
          do {
            puVar4 = puVar1;
            uVar8 = *puVar4;
            if ((char)uVar8 == '\0') goto LAB_00095123;
            if ((char)(uVar8 >> 8) == '\0') goto LAB_00095122;
            if ((uVar8 & 0xff0000) == 0) goto LAB_00095121;
            puVar1 = puVar4 + 1;
          } while ((uVar8 & 0xff000000) != 0);
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095121:
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095122:
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095123:
          if ((puVar4 == (uint *)&com_token) || (iVar7 = strcasecmp(&com_token,":"), iVar7 != 0))
          goto LAB_00094f40;
          pvVar6 = (void *)Crypt_Parse__FPc(pvVar6);
          puVar1 = (uint *)&com_token;
          do {
            puVar4 = puVar1;
            uVar8 = *puVar4;
            if ((char)uVar8 == '\0') goto LAB_00095197;
            if ((char)(uVar8 >> 8) == '\0') goto LAB_00095196;
            if ((uVar8 & 0xff0000) == 0) goto LAB_00095195;
            puVar1 = puVar4 + 1;
          } while ((uVar8 & 0xff000000) != 0);
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095195:
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095196:
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00095197:
          if (puVar4 == (uint *)&com_token) goto LAB_00094f40;
          uVar8 = __strtol_internal(&com_token,0,10,0);
          sprintf(local_144,"%s:%i",local_244,uVar8);
          memset(local_254,0,0x10);
          iVar7 = Crypt_ResolveStringAddress__FPcP8sockaddr(local_144,local_254);
          if (iVar7 != 0) {
            uVar2 = ntohs(local_252);
            uVar8 = (uint)uVar2;
            if (uVar8 == 0) {
              uVar8 = 0x1b59;
            }
            pcVar9 = inet_ntoa(local_250);
            sprintf(local_244,"%s",pcVar9);
          }
          if (iVar5 == 0) {
            piVar10 = (int *)__builtin_new(0x48);
            strcpy((char *)(piVar10 + 1),local_244);
            *(short *)(piVar10 + 0x11) = (short)uVar8;
            *piVar10 = local_258;
            local_258 = (int)piVar10;
          }
        } while( true );
      }
    }
    free(__ptr);
  }
  else {
    fclose(__stream);
    local_258 = 0;
  }
  return (int *)local_258;
}


// Crypt_Parse__FPc  @ 00094d4c
char * Crypt_Parse__FPc(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  com_token = '\0';
  if (param_1 == (char *)0x0) {
LAB_00094d61:
    param_1 = (char *)0x0;
  }
  else {
    while( true ) {
      for (; cVar1 = *param_1, cVar1 < '!'; param_1 = param_1 + 1) {
        if (cVar1 == '\0') goto LAB_00094d61;
      }
      if ((cVar1 != '/') || (param_1[1] != '/')) break;
      for (; (*param_1 != '\0' && (*param_1 != '\n')); param_1 = param_1 + 1) {
      }
    }
    if (cVar1 == '\"') {
      param_1 = param_1 + 1;
      pcVar2 = &com_token;
      while( true ) {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        if ((cVar1 == '\"') || (cVar1 == '\0')) break;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
      }
      *pcVar2 = '\0';
    }
    else {
      com_token = cVar1;
      if (((((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == ')')) ||
          ((cVar1 == '(' || (cVar1 == '\'')))) || (cVar1 == ':')) {
        DAT_000e5a01._0_1_ = 0;
        param_1 = param_1 + 1;
      }
      else {
        param_1 = param_1 + 1;
        iVar3 = 1;
        cVar1 = *param_1;
        if (((cVar1 != '{') && (cVar1 != '}')) &&
           ((cVar1 != ')' && (((cVar1 != '(' && (cVar1 != '\'')) && (cVar1 != ':')))))) {
          while (' ' < cVar1) {
            (&com_token)[iVar3] = cVar1;
            param_1 = param_1 + 1;
            iVar3 = iVar3 + 1;
            cVar1 = *param_1;
            if ((((cVar1 == '{') || (cVar1 == '}')) ||
                ((cVar1 == ')' || ((cVar1 == '(' || (cVar1 == '\'')))))) || (cVar1 == ':')) break;
          }
        }
        (&com_token)[iVar3] = 0;
      }
    }
  }
  return param_1;
}


// Crypt_ResolveStringAddress__FPcP8sockaddr  @ 00094c80
undefined4 Crypt_ResolveStringAddress__FPcP8sockaddr(char *param_1,undefined2 *param_2)

{
  char cVar1;
  uint16_t uVar2;
  in_addr_t iVar3;
  hostent *phVar4;
  char *pcVar5;
  char local_84 [128];
  
  memset(param_2,0,0x10);
  *param_2 = 2;
  param_2[1] = 0;
  strcpy(local_84,param_1);
  pcVar5 = local_84;
  cVar1 = local_84[0];
  while (cVar1 != '\0') {
    if (*pcVar5 == ':') {
      *pcVar5 = '\0';
      uVar2 = __strtol_internal(pcVar5 + 1,0,10,0);
      uVar2 = htons(uVar2);
      param_2[1] = uVar2;
    }
    pcVar5 = pcVar5 + 1;
    cVar1 = *pcVar5;
  }
  if (((byte)(local_84[0] - 0x30U) < 10) && (pcVar5 = strstr(local_84,"."), pcVar5 != (char *)0x0))
  {
    iVar3 = inet_addr(local_84);
  }
  else {
    phVar4 = gethostbyname(local_84);
    if (phVar4 == (hostent *)0x0) {
      return 0;
    }
    iVar3 = *(in_addr_t *)*phVar4->h_addr_list;
  }
  *(in_addr_t *)(param_2 + 2) = iVar3;
  return 1;
}


// Crypt_ReturnAPI  @ 000962cc
undefined4 Crypt_ReturnAPI(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == 1) {
    uVar1 = 1;
    puVar3 = &cryptapi;
    for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Crypt_ServiceAuthRefresh__Fd  @ 00096f40
void Crypt_ServiceAuthRefresh__Fd(double param_1)

{
  if ((gAuthRequest != 0) && (15.0 <= param_1 - tLastService_384)) {
    tLastService_384 = param_1;
    HandleAuthRefresh__11AuthRequest(gAuthRequest);
  }
  return;
}


// Crypt_Shutdown__Fv  @ 000962a8
void Crypt_Shutdown__Fv(void)

{
  DeleteAuthObject__Fv();
  return;
}


