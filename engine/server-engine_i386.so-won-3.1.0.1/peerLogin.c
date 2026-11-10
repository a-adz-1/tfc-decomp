// peerLogin__11AuthRequestP15EasyTitanSocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iiiiPP20WON_AuthCertificate1PP18WON_BFSymmetricKeyPUsi  @ 0009abd8
undefined4
peerLogin__11AuthRequestP15EasyTitanSocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iiiiPP20WON_AuthCertificate1PP18WON_BFSymmetricKeyPUsi
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          int param_6,undefined4 param_7,undefined4 *param_8,undefined4 *param_9,int param_10,
          int param_11)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  time_t tVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  int *piVar12;
  char *pcVar13;
  ushort *puVar14;
  bool bVar15;
  ushort local_68;
  short local_66;
  int local_64;
  undefined1 local_60 [12];
  ushort *local_54;
  int local_50;
  undefined1 local_48 [16];
  undefined4 local_38;
  undefined4 local_34;
  ushort *local_2c;
  uint local_28;
  undefined1 local_20 [12];
  undefined1 local_14 [16];
  
  tVar4 = time((time_t *)0x0);
  if ((((*(int *)(param_1 + 0x819c) == 0) || (*(int *)(param_1 + 0x81b0) < tVar4)) ||
      (*(int *)(param_1 + 0x81b0) - tVar4 < 0x1e)) &&
     (iVar5 = getCertificate__11AuthRequesti(param_1,1), iVar5 == 0)) {
    return 0;
  }
  __11WriteBufferUl(local_14,0x100);
  appendLong__11WriteBufferl(local_14,0);
  appendLong__11WriteBufferl(local_14,0xcb);
  appendLong__11WriteBufferl(local_14,0x32);
  appendByte__11WriteBufferc(local_14,(int)(char)param_5);
  appendByte__11WriteBufferc(local_14,(int)(char)param_6);
  appendShort__11WriteBuffers(local_14,(int)(short)param_7);
  sVar1 = GetRawLen__C20WON_AuthFamilyBuffer(*(undefined4 *)(param_1 + 0x819c));
  appendShort__11WriteBuffers(local_14,(int)sVar1);
  uVar2 = GetRawLen__C20WON_AuthFamilyBuffer(*(undefined4 *)(param_1 + 0x819c));
  uVar6 = GetRaw__C20WON_AuthFamilyBuffer(*(undefined4 *)(param_1 + 0x819c),uVar2);
  append__11WriteBufferPCvUl(local_14,uVar6);
  uVar6 = getSize__C11WriteBuffer(local_14);
  setLong__11WriteBufferUll(local_14,0,uVar6);
  __10ReadBuffer(local_20);
  iVar5 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                    (param_1,local_14,0xcb,0,local_20,param_2,0);
  if (iVar5 == 0) {
    ___11WriteBuffer(local_14,2);
    uVar6 = 0;
  }
  else {
    readULong__10ReadBufferPUl(local_20,&local_64);
    if (local_64 == 0x35) {
      readShort__10ReadBufferPs(local_20,&local_66);
      if (param_11 == 0) {
        ___11WriteBuffer(local_14,2);
        uVar6 = 0;
      }
      else {
        iVar5 = getCertificate__11AuthRequesti(param_1,1);
        if (iVar5 == 0) {
          ___11WriteBuffer(local_14,2);
          uVar6 = 0;
        }
        else {
          uVar6 = peerLogin__11AuthRequestP15EasyTitanSocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iiiiPP20WON_AuthCertificate1PP18WON_BFSymmetricKeyPUsi
                            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9
                             ,param_10,0);
          ___11WriteBuffer(local_14,2);
        }
      }
    }
    else if (local_64 == 0x33) {
      uVar7 = readUShort__10ReadBufferPUs(local_20,&local_68);
      uVar6 = getDataPtr__10ReadBuffer(local_20);
      uVar8 = skipBytes__10ReadBufferUl(local_20,local_68);
      uVar8 = uVar7 & 1 & uVar8;
      if (uVar8 == 0) {
        Error_Printf__11AuthRequestiPce(param_1,2,"Invalid message received from peer.");
        ___11WriteBuffer(local_14,2);
        uVar6 = 0;
      }
      else {
        __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_2c,0,0);
        Decrypt__16WON_EGPrivateKeyPCUcUl
                  (&local_38,*(undefined4 *)(param_1 + 0x81ac),uVar6,local_68);
        __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                  (&local_2c,&local_38);
        ___Q216WON_CryptKeyBase11CryptReturn(&local_38,2);
        if ((local_28 < 2) || ((uint)*local_2c != local_28 - 2)) {
          Error_Printf__11AuthRequestiPce(param_1,2,"Invalid message received from peer.");
          ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
          ___11WriteBuffer(local_14,2);
          uVar6 = 0;
        }
        else {
          if (param_6 == 1) {
            if (param_9 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
              __assert_fail("theSessionKeyP",
                            "/home/jihad/valve/goldsrc/utils/crypt/won/AuthRequest.cpp",0x3b0,
                            "int AuthRequest::peerLogin(class EasyTitanSocket *, const class string &, int, int, int, int, class WON_AuthCertificate1 **, class WON_BFSymmetricKey **, short unsigned int *, int = 1)"
                           );
            }
            uVar6 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(local_28 - 2 & 0xffff,local_2c + 1);
            *param_9 = uVar6;
          }
          uVar7 = readUShort__10ReadBufferPUs(local_20,&local_68);
          uVar6 = getDataPtr__10ReadBuffer(local_20);
          uVar9 = skipBytes__10ReadBufferUl(local_20,local_68);
          uVar9 = uVar8 & uVar7 & uVar9;
          if (uVar9 == 0) {
            Error_Printf__11AuthRequestiPce(param_1,2,"Invalid message received from peer.");
            if (param_6 == 1) {
              DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
              *param_9 = 0;
            }
            ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
            ___11WriteBuffer(local_14,2);
            uVar6 = 0;
          }
          else {
            if (param_8 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
              __assert_fail("theServerCertP!=__null",
                            "/home/jihad/valve/goldsrc/utils/crypt/won/AuthRequest.cpp",0x3c7,
                            "int AuthRequest::peerLogin(class EasyTitanSocket *, const class string &, int, int, int, int, class WON_AuthCertificate1 **, class WON_BFSymmetricKey **, short unsigned int *, int = 1)"
                           );
            }
            uVar6 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs(uVar6,local_68);
            *param_8 = uVar6;
            iVar5 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(param_1,uVar6);
            if (iVar5 == 0) {
              DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
              *param_8 = 0;
              ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
              ___11WriteBuffer(local_14,2);
              uVar6 = 0;
            }
            else {
              iVar10 = GetExpireTime__C20WON_AuthFamilyBuffer(*param_8);
              iVar5 = *(int *)(param_1 + 0x81b4);
              tVar4 = time((time_t *)0x0);
              if (iVar10 - iVar5 < tVar4) {
                Error_Printf__11AuthRequestiPce(param_1,2,"The server\'s certificate has expired.");
              }
              rewind__11WriteBuffer(local_14);
              appendLong__11WriteBufferl(local_14,0);
              appendLong__11WriteBufferl(local_14,0xcb);
              appendLong__11WriteBufferl(local_14,0x34);
              uVar6 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
              __11WriteBufferUl(local_48,0x100);
              appendShort__11WriteBuffers(local_48,(int)(short)((short)local_28 + -2));
              append__11WriteBufferPCvUl(local_48,local_2c + 1,local_28 - 2);
              uVar2 = GetKeyLen__C16WON_CryptKeyBase(uVar6);
              uVar11 = GetKey__C16WON_CryptKeyBase(uVar6,uVar2);
              append__11WriteBufferPCvUl(local_48,uVar11);
              uVar11 = GetPubKey__C20WON_AuthCertificate1(*param_8);
              uVar2 = GetPubKeyLen__C20WON_AuthCertificate1(*param_8,uVar11);
              piVar12 = (int *)NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar2);
              if (*piVar12 == 0) {
                __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_38,0,0);
                uVar11 = getSize__C11WriteBuffer(local_48);
                uVar11 = getBuffer__C11WriteBuffer(local_48,uVar11);
                Encrypt__15WON_EGPublicKeyPCvUl(&local_54,piVar12,uVar11);
                __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                          (&local_38,&local_54);
                ___Q216WON_CryptKeyBase11CryptReturn(&local_54,2);
                if (*piVar12 == 0) {
                  DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar12);
                  appendShort__11WriteBuffers(local_14,(int)(short)local_34);
                  append__11WriteBufferPCvUl(local_14,local_38,local_34);
                  uVar11 = getSize__C11WriteBuffer(local_14);
                  setLong__11WriteBufferUll(local_14,0,uVar11);
                  iVar5 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                                    (param_1,local_14,0xcb,0x35,local_20,param_2,0);
                  if (iVar5 == 0) {
                    DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                    *param_8 = 0;
                    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(uVar6);
                    if (param_6 == 1) {
                      DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                      *param_9 = 0;
                    }
                    ___Q216WON_CryptKeyBase11CryptReturn(&local_38,2);
                    ___11WriteBuffer(local_48,2);
                    ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
                    ___11WriteBuffer(local_14,2);
                    uVar6 = 0;
                  }
                  else {
                    uVar7 = readShort__10ReadBufferPs(local_20,&local_66);
                    uVar9 = uVar9 & uVar7;
                    if (uVar9 == 0) {
                      Error_Printf__11AuthRequestiPce
                                (param_1,2,"Error in message received from peer.");
                    }
                    else {
                      if (-1 < local_66) {
                        uVar7 = readUShort__10ReadBufferPUs(local_20,&local_68);
                        uVar11 = getDataPtr__10ReadBuffer(local_20);
                        uVar8 = skipBytes__10ReadBufferUl(local_20,local_68);
                        uVar8 = uVar9 & uVar7 & uVar8;
                        if (param_10 != 0) {
                          uVar7 = readUShort__10ReadBufferPUs(local_20,param_10);
                          uVar8 = uVar8 & uVar7;
                        }
                        if (uVar8 == 0) {
                          Error_Printf__11AuthRequestiPce
                                    (param_1,2,"Error in message received from peer.");
                          DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8)
                          ;
                          *param_8 = 0;
                          DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(uVar6);
                          if (param_6 == 1) {
                            DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                            *param_9 = 0;
                          }
                          ___Q216WON_CryptKeyBase11CryptReturn(&local_38,2);
                          ___11WriteBuffer(local_48,2);
                          ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
                          ___11WriteBuffer(local_14,2);
                          return 0;
                        }
                        __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_54,0,0);
                        Decrypt__16WON_EGPrivateKeyPCUcUl
                                  (local_60,*(undefined4 *)(param_1 + 0x81ac),uVar11,local_68);
                        __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                                  (&local_54,local_60);
                        ___Q216WON_CryptKeyBase11CryptReturn(local_60,2);
                        local_68 = *local_54;
                        if (((uint)local_68 == local_50 - 2U) &&
                           (uVar3 = GetKeyLen__C16WON_CryptKeyBase(uVar6), local_68 == uVar3)) {
                          uVar7 = (uint)local_68;
                          pcVar13 = (char *)GetKey__C16WON_CryptKeyBase(uVar6);
                          bVar15 = true;
                          puVar14 = local_54 + 1;
                          do {
                            if (uVar7 == 0) break;
                            uVar7 = uVar7 - 1;
                            bVar15 = (char)*puVar14 == *pcVar13;
                            puVar14 = (ushort *)((int)puVar14 + 1);
                            pcVar13 = pcVar13 + 1;
                          } while (bVar15);
                          if (bVar15) {
                            DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(uVar6);
                            ___Q216WON_CryptKeyBase11CryptReturn(&local_54,2);
                            ___Q216WON_CryptKeyBase11CryptReturn(&local_38,2);
                            ___11WriteBuffer(local_48,2);
                            ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
                            ___11WriteBuffer(local_14,2);
                            return 1;
                          }
                        }
                        Error_Printf__11AuthRequestiPce
                                  (param_1,2,"Invalid secret returned by peer.");
                        DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                        *param_8 = 0;
                        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(uVar6);
                        if (param_6 == 1) {
                          DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                          *param_9 = 0;
                        }
                        ___Q216WON_CryptKeyBase11CryptReturn(&local_54,2);
                        ___Q216WON_CryptKeyBase11CryptReturn(&local_38,2);
                        ___11WriteBuffer(local_48,2);
                        ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
                        ___11WriteBuffer(local_14,2);
                        return 0;
                      }
                      Error_Printf__11AuthRequestiPce(param_1,2,FUN_000b03e0,(int)local_66);
                    }
                    DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                    *param_8 = 0;
                    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(uVar6);
                    if (param_6 == 1) {
                      DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                      *param_9 = 0;
                    }
                    ___Q216WON_CryptKeyBase11CryptReturn(&local_38,2);
                    ___11WriteBuffer(local_48,2);
                    ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
                    ___11WriteBuffer(local_14,2);
                    uVar6 = 0;
                  }
                }
                else {
                  Error_Printf__11AuthRequestiPce
                            (param_1,2,"Error Encrypting secret data: %s",*piVar12);
                  DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                  *param_8 = 0;
                  DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar12);
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(uVar6);
                  if (param_6 == 1) {
                    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                    *param_9 = 0;
                  }
                  ___Q216WON_CryptKeyBase11CryptReturn(&local_38,2);
                  ___11WriteBuffer(local_48,2);
                  ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
                  ___11WriteBuffer(local_14,2);
                  uVar6 = 0;
                }
              }
              else {
                Error_Printf__11AuthRequestiPce
                          (param_1,2,"Error in Client B\'s public key: %s",*piVar12);
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                *param_8 = 0;
                DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(piVar12);
                DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(uVar6);
                if (param_6 == 1) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                  *param_9 = 0;
                }
                ___11WriteBuffer(local_48,2);
                ___Q216WON_CryptKeyBase11CryptReturn(&local_2c,2);
                ___11WriteBuffer(local_14,2);
                uVar6 = 0;
              }
            }
          }
        }
      }
    }
    else {
      Error_Printf__11AuthRequestiPce(param_1,2,"Invalid message type received from peer.");
      ___11WriteBuffer(local_14,2);
      uVar6 = 0;
    }
  }
  return uVar6;
}


