// getCertificate__11AuthRequesti  @ 00099af4
undefined4 getCertificate__11AuthRequesti(int param_1)

{
  undefined *puVar1;
  uint *puVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  uint *puVar8;
  undefined4 uVar9;
  time_t tVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  char *pcVar14;
  undefined4 *puVar15;
  short local_1c2;
  uint local_1c0;
  ushort local_1bc;
  short local_1ba;
  int local_1b8;
  undefined4 local_1b4;
  undefined2 local_1b0;
  undefined1 local_1ac [16];
  undefined4 local_19c;
  undefined1 local_9c [16];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c [12];
  undefined1 local_70 [12];
  undefined4 *local_64;
  undefined4 local_60;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined *local_38;
  undefined *local_34;
  undefined1 local_30 [44];
  
  __15EasyTitanSocketQ210EasySocket10SocketTypeUl(local_30,1,0x8000);
  *(undefined4 *)(param_1 + 0x81f4) = 0;
  iVar5 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                    (local_30,param_1,*(undefined4 *)(param_1 + 4),5000,1);
  if (iVar5 != 0) {
    ES_ErrorTypeToString__F12ES_ErrorType(&local_34,iVar5);
    if (*(int *)(local_34 + -0x10) == 0) {
      puVar6 = &DAT_000aff03;
    }
    else {
      local_34[*(int *)(local_34 + -0x10)] = 0;
      puVar6 = local_34;
    }
    Error_Printf__11AuthRequestiPce(param_1,1,"Error connecting to Auth server: %s",puVar6);
    iVar5 = *(int *)(local_34 + -8);
    *(int *)(local_34 + -8) = iVar5 + -1;
    if (iVar5 == 1) {
      if (*(int *)(local_34 + -0xc) + 0x10U < 0x81) {
        iVar5 = (*(int *)(local_34 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *(undefined4 *)(local_34 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar5);
        *(undefined **)(&DAT_000b3e5c + iVar5) = local_34 + -0x10;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free(local_34 + -0x10);
      }
    }
    ___15EasyTitanSocket(local_30,2);
    return 0;
  }
  if ((*(int *)(param_1 + 0x8198) == 0) &&
     (iVar5 = getPublicKeys__11AuthRequestP15EasyTitanSocket(param_1,local_30), iVar5 == 0)) {
    Error_Printf__11AuthRequestiPce(param_1,1,"Could not obtain pkey block");
    ___15EasyTitanSocket(local_30,2);
    return 0;
  }
  if (*(int *)(param_1 + 0x81a4) != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int *)(param_1 + 0x81a4));
    *(undefined4 *)(param_1 + 0x81a4) = 0;
  }
  if (*(int *)(param_1 + 0x81a0) == 0) {
    uVar7 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
  }
  else {
    uVar7 = GetKey__C16WON_CryptKeyBase(*(int *)(param_1 + 0x81a0));
    uVar3 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a0),uVar7);
    uVar7 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(uVar3);
  }
  *(undefined4 *)(param_1 + 0x81a4) = uVar7;
  if (*(int **)(param_1 + 0x81a4) == (int *)0x0) {
    Error_Printf__11AuthRequestiPce(param_1,2,"Unable to generate WON session key");
    ___15EasyTitanSocket(local_30,2);
    return 0;
  }
  if (**(int **)(param_1 + 0x81a4) != 0) {
    Error_Printf__11AuthRequestiPce(param_1,2,"Unable to generate WON session key");
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(undefined4 *)(param_1 + 0x81a4))
    ;
    *(undefined4 *)(param_1 + 0x81a4) = 0;
    ___15EasyTitanSocket(local_30,2);
    return 0;
  }
  __11WriteBufferUl(local_48,0x100);
  appendLong__11WriteBufferl(local_48,0);
  appendLong__11WriteBufferl(local_48,0xca);
  appendLong__11WriteBufferl(local_48,0x28);
  sVar4 = GetBlockId__C23WON_AuthPublicKeyBlock1(*(undefined4 *)(param_1 + 0x8198));
  appendShort__11WriteBuffers(local_48,(int)sVar4);
  appendByte__11WriteBufferc(local_48,*(int *)(param_1 + 0x81ac) == 0);
  __11WriteBufferUl(local_58,0x100);
  sVar4 = GetBlockId__C23WON_AuthPublicKeyBlock1(*(undefined4 *)(param_1 + 0x8198));
  appendShort__11WriteBuffers(local_58,(int)sVar4);
  sVar4 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a4));
  appendShort__11WriteBuffers(local_58,(int)sVar4);
  uVar3 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a4));
  uVar7 = GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a4),uVar3);
  append__11WriteBufferPCvUl(local_58,uVar7);
  puVar13 = (uint *)(param_1 + 0x812c);
  if (force_to_data[0xc] == '\0') {
    force_to_data._8_4_ = force_to_data._8_4_ + 1;
    local_38 = &DAT_000b1f78;
  }
  else {
    local_38 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (force_to_data);
  }
  uVar12 = (uint)puVar13 & 3;
  puVar2 = puVar13;
  if (uVar12 != 0) {
    puVar8 = puVar13;
    if ((POPCOUNT(uVar12) & 1U) != 0) {
      if (uVar12 != 2) {
        if (*(char *)puVar13 == '\0') goto LAB_00099eaf;
        puVar8 = (uint *)(param_1 + 0x812d);
      }
      if ((char)*puVar8 == '\0') goto LAB_00099eaf;
      puVar8 = (uint *)((int)puVar8 + 1);
    }
    if ((char)*puVar8 == '\0') goto LAB_00099eaf;
    puVar2 = (uint *)((int)puVar8 + 1);
  }
  do {
    puVar8 = puVar2;
    uVar12 = *puVar8;
    if ((char)uVar12 == '\0') goto LAB_00099eaf;
    if ((char)(uVar12 >> 8) == '\0') goto LAB_00099eae;
    if ((uVar12 & 0xff0000) == 0) goto LAB_00099ead;
    puVar2 = puVar8 + 1;
  } while ((uVar12 & 0xff000000) != 0);
  puVar8 = (uint *)((int)puVar8 + 1);
LAB_00099ead:
  puVar8 = (uint *)((int)puVar8 + 1);
LAB_00099eae:
  puVar8 = (uint *)((int)puVar8 + 1);
LAB_00099eaf:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (&local_38,0,0xffffffff,puVar13,(int)puVar8 - (int)puVar13);
  appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
            (local_58,&local_38);
  puVar1 = local_38;
  puVar6 = local_38 + -0x10;
  iVar5 = *(int *)(local_38 + -8);
  *(int *)(local_38 + -8) = iVar5 + -1;
  if (iVar5 == 1) {
    if (*(int *)(local_38 + -0xc) + 0x10U < 0x81) {
      iVar5 = (*(int *)(local_38 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(puVar1 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar5);
      *(undefined **)(&DAT_000b3e5c + iVar5) = puVar6;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(puVar6);
    }
  }
  GetFirstKey__C23WON_AuthPublicKeyBlock1(&local_1b4,*(undefined4 *)(param_1 + 0x8198));
  uVar7 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(local_1b0,local_1b4);
  uVar9 = getSize__C11WriteBuffer(local_58);
  uVar9 = getBuffer__C11WriteBuffer(local_58,uVar9);
  Encrypt__15WON_EGPublicKeyPCvUl(&local_64,uVar7,uVar9);
  DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(uVar7);
  if (local_64 == (undefined4 *)0x0) {
    Error_Printf__11AuthRequestiPce(param_1,2,"Error encrypting login data.");
    ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
    ___11WriteBuffer(local_58,2);
    ___11WriteBuffer(local_48,2);
    ___15EasyTitanSocket(local_30,2);
    uVar7 = 0;
  }
  else {
    appendShort__11WriteBuffers(local_48,(int)(short)local_60);
    append__11WriteBufferPCvUl(local_48,local_64,local_60);
    uVar7 = getSize__C11WriteBuffer(local_48);
    setLong__11WriteBufferUll(local_48,0,uVar7);
    __10ReadBuffer(local_70);
    iVar5 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                      (param_1,local_48,0xca,0,local_70,local_30,0);
    if (iVar5 == 0) {
      Error_Printf__11AuthRequestiPce
                (param_1,1,"Could not communicate with WON, check your internet connection");
      ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
      ___11WriteBuffer(local_58,2);
      ___11WriteBuffer(local_48,2);
      ___15EasyTitanSocket(local_30,2);
      uVar7 = 0;
    }
    else {
      readULong__10ReadBufferPUl(local_70,&local_1b8);
      if (local_1b8 == 0x2c) {
        iVar5 = readShort__10ReadBufferPs(local_70,&local_1ba);
        if ((iVar5 == 0) || (local_1ba == 0)) {
          Error_Printf__11AuthRequestiPce(param_1,2,FUN_000affe0);
          ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
          ___11WriteBuffer(local_58,2);
          ___11WriteBuffer(local_48,2);
          ___15EasyTitanSocket(local_30,2);
          uVar7 = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0x81f8) = 0;
          *(int *)(param_1 + 0x81fc) = (int)local_1ba;
          iVar5 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
                            (param_1,local_70,*(undefined4 *)(param_1 + 0x81a4));
          if (iVar5 == 2) {
            uVar7 = getCertificate__11AuthRequesti(param_1,0);
            ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
            ___11WriteBuffer(local_58,2);
            ___11WriteBuffer(local_48,2);
            ___15EasyTitanSocket(local_30,2);
          }
          else {
            ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
            ___11WriteBuffer(local_58,2);
            ___11WriteBuffer(local_48,2);
            ___15EasyTitanSocket(local_30,2);
            uVar7 = 0;
          }
        }
      }
      else if (local_1b8 == 0x29) {
        uVar12 = readUShort__10ReadBufferPUs(local_70,&local_1bc);
        uVar7 = getTheRest__10ReadBufferPUl(local_70,&local_1c0);
        if (((uVar12 & 1) == 0) || (local_1bc != local_1c0)) {
          Error_Printf__11AuthRequestiPce(param_1,2,"Error in challenge message.");
          ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
          ___11WriteBuffer(local_58,2);
          ___11WriteBuffer(local_48,2);
          ___15EasyTitanSocket(local_30,2);
          uVar7 = 0;
        }
        else {
          Decrypt__18WON_BFSymmetricKeyPCUcUl
                    (local_7c,*(undefined4 *)(param_1 + 0x81a4),uVar7,(uint)local_1bc);
          __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                    (&local_64,local_7c);
          ___Q216WON_CryptKeyBase11CryptReturn(local_7c,2);
          if (local_64 == (undefined4 *)0x0) {
            Error_Printf__11AuthRequestiPce(param_1,2,"Error in challenge seed encryption.");
            ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
            ___11WriteBuffer(local_58,2);
            ___11WriteBuffer(local_48,2);
            ___15EasyTitanSocket(local_30,2);
            uVar7 = 0;
          }
          else {
            local_8c = *local_64;
            local_88 = local_64[1];
            local_84 = local_64[2];
            local_80 = local_64[3];
            if (*(int *)(param_1 + 0x81a0) != 0) {
              DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                        (*(int *)(param_1 + 0x81a0));
              *(undefined4 *)(param_1 + 0x81a0) = 0;
            }
            uVar7 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,&local_8c);
            *(undefined4 *)(param_1 + 0x81a0) = uVar7;
            storeServerKey__11AuthRequest(param_1);
            pcVar14 = "engine_i386.so";
            puVar15 = &local_19c;
            for (iVar5 = 3; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar15 = *(undefined4 *)pcVar14;
              pcVar14 = pcVar14 + 4;
              puVar15 = puVar15 + 1;
            }
            *(undefined2 *)puVar15 = *(undefined2 *)pcVar14;
            *(char *)((int)puVar15 + 2) = pcVar14[2];
            iVar5 = MD5_Hash_File__FPUcPciPUi(local_9c,&local_19c,0,0);
            if (iVar5 == 0) {
              Error_Printf__11AuthRequestiPce(param_1,2,"Validation failure - 2.");
              ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
              ___11WriteBuffer(local_58,2);
              ___11WriteBuffer(local_48,2);
              ___15EasyTitanSocket(local_30,2);
              uVar7 = 0;
            }
            else {
              __11WriteBufferUl(local_1ac,0x100);
              append__11WriteBufferPCvUl(local_1ac,local_9c,0x10);
              iVar5 = ComputeSeededMD5andCRCForFileGroup__11AuthRequestPUcPcPUi
                                (param_1,local_9c,&local_19c,&local_8c);
              if (iVar5 == 0) {
                Error_Printf__11AuthRequestiPce(param_1,2,"Validation failure - 3.");
                ___11WriteBuffer(local_1ac,2);
                ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                ___11WriteBuffer(local_58,2);
                ___11WriteBuffer(local_48,2);
                ___15EasyTitanSocket(local_30,2);
                uVar7 = 0;
              }
              else {
                append__11WriteBufferPCvUl(local_1ac,local_9c,0x10);
                rewind__11WriteBuffer(local_48);
                appendLong__11WriteBufferl(local_48,0);
                appendLong__11WriteBufferl(local_48,0xca);
                appendLong__11WriteBufferl(local_48,0x2a);
                uVar7 = getSize__C11WriteBuffer(local_1ac);
                uVar7 = getBuffer__C11WriteBuffer(local_1ac,uVar7);
                Encrypt__18WON_BFSymmetricKeyPCvUl(local_7c,*(undefined4 *)(param_1 + 0x81a4),uVar7)
                ;
                __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                          (&local_64,local_7c);
                ___Q216WON_CryptKeyBase11CryptReturn(local_7c,2);
                if (local_64 == (undefined4 *)0x0) {
                  Error_Printf__11AuthRequestiPce(param_1,2,"Error encrypting checksum response.");
                  ___11WriteBuffer(local_1ac,2);
                  ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                  ___11WriteBuffer(local_58,2);
                  ___11WriteBuffer(local_48,2);
                  ___15EasyTitanSocket(local_30,2);
                  uVar7 = 0;
                }
                else {
                  appendShort__11WriteBuffers(local_48,(int)(short)local_60);
                  append__11WriteBufferPCvUl(local_48,local_64,local_60);
                  uVar7 = getSize__C11WriteBuffer(local_48);
                  setLong__11WriteBufferUll(local_48,0,uVar7);
                  iVar5 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                                    (param_1,local_48,0xca,0x2c,local_70,local_30,0);
                  if (iVar5 == 0) {
                    Error_Printf__11AuthRequestiPce(param_1,1,FUN_000b0100);
                    ___11WriteBuffer(local_1ac,2);
                    ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                    ___11WriteBuffer(local_58,2);
                    ___11WriteBuffer(local_48,2);
                    ___15EasyTitanSocket(local_30,2);
                    uVar7 = 0;
                  }
                  else {
                    readShort__10ReadBufferPs(local_70,&local_1c2);
                    *(undefined4 *)(param_1 + 0x81f8) = 1;
                    *(int *)(param_1 + 0x81fc) = (int)local_1c2;
                    iVar5 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
                                      (param_1,local_70,*(undefined4 *)(param_1 + 0x81a4));
                    if ((iVar5 == 0) || (local_1c2 != 0)) {
                      ___11WriteBuffer(local_1ac,2);
                      ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                      ___11WriteBuffer(local_58,2);
                      ___11WriteBuffer(local_48,2);
                      ___15EasyTitanSocket(local_30,2);
                      uVar7 = 0;
                    }
                    else {
                      *(undefined4 *)(param_1 + 0x8194) = 1;
                      tVar10 = time((time_t *)0x0);
                      iVar5 = GetExpireTime__C20WON_AuthFamilyBuffer
                                        (*(undefined4 *)(param_1 + 0x819c));
                      iVar11 = GetIssueTime__C20WON_AuthFamilyBuffer
                                         (*(undefined4 *)(param_1 + 0x819c));
                      *(time_t *)(param_1 + 0x81b0) = tVar10 + (iVar5 - iVar11);
                      iVar5 = GetIssueTime__C20WON_AuthFamilyBuffer
                                        (*(undefined4 *)(param_1 + 0x819c));
                      tVar10 = time((time_t *)0x0);
                      *(int *)(param_1 + 0x81b4) = iVar5 - tVar10;
                      ___11WriteBuffer(local_1ac,2);
                      ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                      ___11WriteBuffer(local_58,2);
                      ___11WriteBuffer(local_48,2);
                      ___15EasyTitanSocket(local_30,2);
                      uVar7 = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
        ___11WriteBuffer(local_58,2);
        ___11WriteBuffer(local_48,2);
        ___15EasyTitanSocket(local_30,2);
        uVar7 = 0;
      }
    }
  }
  return uVar7;
}


