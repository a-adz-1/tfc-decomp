// Launcher_AuthChallenge1__FPviP15authchallenge_t  @ 08096090
undefined4
Launcher_AuthChallenge1__FPviP15authchallenge_t(undefined2 *param_1,undefined4 param_2,int param_3)

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
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                  (*(undefined4 *)(param_3 + 0x30));
        *(undefined4 *)(param_3 + 0x30) = 0;
      }
      *(int *)(param_3 + 0x30) = iVar7;
      gcc2_compiled_(local_2c,0x100);
      appendLong__11WriteBufferl(local_2c,0xffffffff);
      appendByte__11WriteBufferc(local_2c,0x34);
      sVar2 = GetRawLen__C20WON_AuthFamilyBuffer(iVar3);
      appendShort__11WriteBuffers(local_2c,(int)sVar2);
      uVar1 = GetRawLen__C20WON_AuthFamilyBuffer(iVar3);
      uVar6 = GetRaw__C20WON_AuthFamilyBuffer(iVar3,uVar1);
      append__11WriteBufferPCvUl(local_2c,uVar6);
      appendShort__11WriteBuffers(local_2c,(int)(short)local_c);
      append__11WriteBufferPCvUl(local_2c,local_10,local_c);
      if (*(int *)(param_3 + 0x2c) != 0) {
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


// Launcher_AuthChallenge2__FPviP15authchallenge_t  @ 080963e0
undefined4
Launcher_AuthChallenge2__FPviP15authchallenge_t(ushort *param_1,undefined4 param_2,int param_3)

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
  iVar4 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs(param_1 + 1,uVar1);
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
      gcc2_compiled_(local_2c,0x100);
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
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                  (*(undefined4 *)(param_3 + 0x30));
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
        gcc2_compiled_(local_3c,0x100);
        appendLong__11WriteBufferl(local_3c,0xffffffff);
        appendByte__11WriteBufferc(local_3c,0x35);
        appendShort__11WriteBuffers(local_3c,(int)(short)local_c);
        append__11WriteBufferPCvUl(local_3c,local_10,local_c);
        if (*(int *)(param_3 + 0x2c) != 0) {
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


// Launcher_AuthComplete__FPviP15authchallenge_t  @ 08096970
undefined4
Launcher_AuthComplete__FPviP15authchallenge_t(undefined2 *param_1,undefined4 param_2,int param_3)

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
  gcc2_compiled_(local_2c,0x100);
  appendLong__11WriteBufferl(local_2c,0xffffffff);
  appendByte__11WriteBufferc(local_2c,0x36);
  appendShort__11WriteBuffers(local_2c,(int)local_30);
  append__11WriteBufferPCvUl(local_2c,uVar9,local_30);
  if (*(int *)(param_3 + 0x2c) != 0) {
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


// Launcher_AuthRequest__FPviP15authchallenge_t  @ 08095f40
undefined4
Launcher_AuthRequest__FPviP15authchallenge_t(undefined4 param_1,undefined4 param_2,int param_3)

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
    gcc2_compiled_(local_14,0x100);
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
      if (*(int *)(param_3 + 0x2c) != 0) {
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


// Launcher_BFEncrypt__FPviT0Pi  @ 08095e20
undefined4
Launcher_BFEncrypt__FPviT0Pi(undefined4 param_1,undefined4 param_2,void *param_3,size_t *param_4)

{
  undefined4 uVar1;
  undefined1 local_1c [12];
  void *local_10;
  size_t local_c;
  
  if (gConnectionKey == 0) {
    uVar1 = 0;
  }
  else {
    __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_10,0,0);
    Encrypt__18WON_BFSymmetricKeyPCvUl(local_1c,gConnectionKey,param_1,param_2);
    __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(&local_10,local_1c);
    ___Q216WON_CryptKeyBase11CryptReturn(local_1c,2);
    if (local_10 == (void *)0x0) {
      ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
      uVar1 = 1;
    }
    else {
      memcpy(param_3,local_10,local_c);
      *param_4 = local_c;
      ___Q216WON_CryptKeyBase11CryptReturn(&local_10,2);
      uVar1 = 2;
    }
  }
  return uVar1;
}


// Launcher_DecodeAuthComplete__FPviP15authchallenge_t  @ 08096c90
undefined4
Launcher_DecodeAuthComplete__FPviP15authchallenge_t(ushort *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  ushort *puVar5;
  bool bVar6;
  
  uVar4 = (uint)*param_1;
  if (*(int *)(param_3 + 0x30) != 0) {
    uVar1 = *(undefined4 *)(param_3 + 0x30);
    uVar2 = GetKeyLen__C16WON_CryptKeyBase(uVar1);
    if (uVar4 == (uVar2 & 0xffff)) {
      pcVar3 = (char *)GetKey__C16WON_CryptKeyBase(uVar1);
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
  }
  return 1;
}


// Launcher_DeleteAuthData__FP15authchallenge_t  @ 08095d70
void Launcher_DeleteAuthData__FP15authchallenge_t(int param_1)

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


// Launcher_GetCertificate__FPvPi  @ 08089550
undefined4 Launcher_GetCertificate__FPvPi(void *param_1,uint *param_2)

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


// Launcher_GetConnectionKey__FPvPi  @ 08095db0
undefined4 Launcher_GetConnectionKey__FPvPi(void *param_1,uint *param_2)

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


// Launcher_GetRawBFKey__FPvT0Pi  @ 08095d10
undefined4 Launcher_GetRawBFKey__FPvT0Pi(int param_1,void *param_2,uint *param_3)

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


// Launcher_InitCmds__Fv  @ 08089470
void Launcher_InitCmds__Fv(void)

{
  return;
}


// Launcher_RequestNewClientCertificate__Fv  @ 080895d0
undefined4 Launcher_RequestNewClientCertificate__Fv(void)

{
  return 1;
}


// Launcher_ValidateClientCertificate__FPvi  @ 080894f0
undefined4 Launcher_ValidateClientCertificate__FPvi(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  if ((gAuthRequest != 0) &&
     (iVar1 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs(param_1,param_2), iVar1 != 0)) {
    iVar2 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(gAuthRequest,iVar1);
    DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(iVar1);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}


// Launcher_VerifyMessage__FiPUciPciT1  @ 08089400
undefined4
Launcher_VerifyMessage__FiPUciPciT1
          (undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)NewEGPublicKey__16WON_CryptFactoryUsPCUc(param_1,param_2);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == 0) {
      iVar2 = Verify__15WON_EGPublicKeyPCUcUlPCvUl(piVar1,param_6,param_5,param_4,param_3);
      DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar1);
      if (iVar2 != 0) {
        return param_4;
      }
    }
    else {
      DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar1);
    }
  }
  return 0;
}


