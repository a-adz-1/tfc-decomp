// handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey  @ 000991d8
undefined4
handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
          (int param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  int aiStackY_64 [5];
  ushort local_32;
  uint local_2c;
  ushort local_26;
  byte local_23;
  ushort local_22;
  undefined1 local_20 [12];
  undefined *local_14;
  int local_10;
  ushort local_c;
  
  bVar4 = false;
  local_32 = 0;
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_10,0,0);
  if (force_to_data[0xc] == '\0') {
    force_to_data._8_4_ = force_to_data._8_4_ + 1;
    local_14 = &DAT_000b1f78;
  }
  else {
    local_14 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (force_to_data);
  }
  local_2c = readUShort__10ReadBufferPUs(param_2,&local_22);
  local_2c = local_2c & 1;
  puVar12 = &stack0xffffffbc;
  for (; puVar1 = local_14, local_32 < local_22; local_32 = local_32 + 1) {
    *(byte **)(puVar12 + -4) = &local_23;
    *(undefined4 *)(puVar12 + -8) = param_2;
    *(undefined4 *)(puVar12 + -0xc) = 0x99255;
    uVar5 = readUByte__10ReadBufferPUc();
    *(ushort **)(puVar12 + -0xc) = &local_26;
    *(undefined4 *)(puVar12 + -0x10) = param_2;
    *(undefined4 *)(puVar12 + -0x14) = 0x99265;
    uVar6 = readUShort__10ReadBufferPUs();
    *(undefined4 *)(puVar12 + -0x14) = param_2;
    *(undefined4 *)(puVar12 + -0x18) = 0x99271;
    uVar10 = getDataPtr__10ReadBuffer();
    *(uint *)(puVar12 + -0x18) = (uint)local_26;
    *(undefined4 *)(puVar12 + -0x1c) = param_2;
    *(undefined4 *)(puVar12 + -0x20) = 0x99283;
    uVar7 = skipBytes__10ReadBufferUl();
    local_2c = local_2c & uVar5 & uVar6 & uVar7;
    if (local_2c == 0) goto LAB_0009982f;
    puVar11 = puVar12;
    if (local_23 == 2) {
      if (param_3 != 0) {
        *(uint *)(puVar12 + -4) = (uint)local_26;
        *(undefined4 *)(puVar12 + -8) = uVar10;
        *(int *)(puVar12 + -0xc) = param_3;
        *(undefined1 **)(puVar12 + -0x10) = local_20;
        *(undefined4 *)(puVar12 + -0x14) = 0x993d7;
        Decrypt__18WON_BFSymmetricKeyPCUcUl();
        *(undefined1 **)(puVar12 + -0x14) = local_20;
        *(int **)(puVar12 + -0x18) = &local_10;
        *(undefined4 *)(puVar12 + -0x1c) = 0x993e1;
        __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn();
        *(undefined4 *)(puVar12 + -8) = 2;
        *(undefined1 **)(puVar12 + -0xc) = local_20;
        *(undefined4 *)(puVar12 + -0x10) = 0x993f8;
        ___Q216WON_CryptKeyBase11CryptReturn();
        if (local_10 == 0) {
          *(char **)(puVar12 + -8) = "Error decrypting private key.";
          *(undefined4 *)(puVar12 + -0xc) = 2;
          *(int *)(puVar12 + -0x10) = param_1;
          *(undefined4 *)(puVar12 + -0x14) = 0x9940f;
          Error_Printf__11AuthRequestiPce();
          puVar2 = local_14;
          puVar1 = local_14 + -0x10;
          iVar8 = *(int *)(local_14 + -8);
          *(int *)(local_14 + -8) = iVar8 + -1;
          if (iVar8 == 1) {
            if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
              iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
              *(undefined1 **)(puVar12 + -0x14) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar12 + -0x18) = 0x9944f;
              pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -0x14));
              *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
              *(undefined **)(&DAT_000b3e5c + iVar8) = puVar1;
              *(undefined1 **)(puVar12 + -0x14) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar12 + -0x18) = 0x9946b;
              pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -0x14));
            }
            else {
              *(undefined **)(puVar12 + -0x14) = puVar1;
              *(undefined4 *)(puVar12 + -0x18) = 0x99436;
              free(*(void **)(puVar12 + -0x14));
            }
          }
          *(undefined4 *)(puVar12 + -0x14) = 2;
          *(int **)(puVar12 + -0x18) = &local_10;
          *(undefined4 *)(puVar12 + -0x1c) = 0x99479;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
        if (*(int *)(param_1 + 0x81ac) != 0) {
          *(int *)(puVar12 + -8) = *(int *)(param_1 + 0x81ac);
          *(undefined4 *)(puVar12 + -0xc) = 0x99490;
          DeleteEGPrivateKey__16WON_CryptFactoryP16WON_EGPrivateKey();
        }
        *(int *)(puVar12 + -8) = local_10;
        *(uint *)(puVar12 + -0xc) = (uint)local_c;
        *(undefined4 *)(puVar12 + -0x10) = 0x994a3;
        piVar9 = (int *)NewEGPrivateKey__16WON_CryptFactoryUsPCUc();
        *(int **)(param_1 + 0x81ac) = piVar9;
        if (piVar9 == (int *)0x0) {
          *(char **)(puVar12 + -8) =
               "int AuthRequest::handleLoginReply(class ReadBuffer *, class WON_BFSymmetricKey *)";
          *(undefined4 *)(puVar12 + -0xc) = 0x1cf;
          *(char **)(puVar12 + -0x10) = "/home/jihad/valve/goldsrc/utils/crypt/won/AuthRequest.cpp";
          *(char **)(puVar12 + -0x14) = "m_PrivateKey";
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar12 + -0x18) = &UNK_000994c9;
          __assert_fail(*(char **)(puVar12 + -0x14),*(char **)(puVar12 + -0x10),
                        *(uint *)(puVar12 + -0xc),*(char **)(puVar12 + -8));
        }
        puVar11 = puVar12 + -4;
        if (*piVar9 != 0) {
          *(int *)(puVar12 + -8) = *piVar9;
          *(char **)(puVar12 + -0xc) = "Error constructing private key: %s";
          *(undefined4 *)(puVar12 + -0x10) = 2;
          *(int *)(puVar12 + -0x14) = param_1;
          *(undefined4 *)(puVar12 + -0x18) = 0x994e4;
          Error_Printf__11AuthRequestiPce();
          puVar2 = local_14;
          puVar1 = local_14 + -0x10;
          iVar8 = *(int *)(local_14 + -8);
          *(int *)(local_14 + -8) = iVar8 + -1;
          if (iVar8 == 1) {
            if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
              iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
              *(undefined1 **)(puVar12 + -0x18) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar12 + -0x1c) = 0x99527;
              pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -0x18));
              *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
              *(undefined **)(&DAT_000b3e5c + iVar8) = puVar1;
              *(undefined1 **)(puVar12 + -0x18) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar12 + -0x1c) = 0x99543;
              pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -0x18));
            }
            else {
              *(undefined **)(puVar12 + -0x18) = puVar1;
              *(undefined4 *)(puVar12 + -0x1c) = 0x9950b;
              free(*(void **)(puVar12 + -0x18));
            }
          }
          *(undefined4 *)(puVar12 + -0x18) = 2;
          *(int **)(puVar12 + -0x1c) = &local_10;
          *(undefined4 *)(puVar12 + -0x20) = 0x99551;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
      }
    }
    else if (local_23 < 2) {
      if (local_23 == 1) {
        if (*(int *)(param_1 + 0x819c) != 0) {
          *(int *)(puVar12 + -4) = *(int *)(param_1 + 0x819c);
          *(undefined4 *)(puVar12 + -8) = 0x992d8;
          DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1();
        }
        *(uint *)(puVar12 + -4) = (uint)local_26;
        *(undefined4 *)(puVar12 + -8) = uVar10;
        *(undefined4 *)(puVar12 + -0xc) = 0x992e8;
        iVar8 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs();
        *(int *)(param_1 + 0x819c) = iVar8;
        if (iVar8 == 0) {
          *(char **)(puVar12 + -4) =
               "int AuthRequest::handleLoginReply(class ReadBuffer *, class WON_BFSymmetricKey *)";
          *(undefined4 *)(puVar12 + -8) = 0x1b5;
          *(char **)(puVar12 + -0xc) = "/home/jihad/valve/goldsrc/utils/crypt/won/AuthRequest.cpp";
          *(char **)(puVar12 + -0x10) = "m_pCertificate";
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar12 + -0x14) = &UNK_0009930e;
          __assert_fail(*(char **)(puVar12 + -0x10),*(char **)(puVar12 + -0xc),
                        *(uint *)(puVar12 + -8),*(char **)(puVar12 + -4));
        }
        *(int *)(puVar12 + -4) = iVar8;
        *(int *)(puVar12 + -8) = param_1;
        *(undefined4 *)(puVar12 + -0xc) = 0x99317;
        iVar8 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer();
        if (iVar8 == 0) {
          *(char **)(puVar12 + -4) = "Verification of certificate failed.";
          *(undefined4 *)(puVar12 + -8) = 2;
          *(int *)(puVar12 + -0xc) = param_1;
          *(undefined4 *)(puVar12 + -0x10) = 0x9932b;
          Error_Printf__11AuthRequestiPce();
          puVar2 = local_14;
          puVar1 = local_14 + -0x10;
          iVar8 = *(int *)(local_14 + -8);
          *(int *)(local_14 + -8) = iVar8 + -1;
          if (iVar8 == 1) {
            if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
              iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
              *(undefined1 **)(puVar12 + -0x10) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar12 + -0x14) = 0x9936b;
              pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -0x10));
              *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
              *(undefined **)(&DAT_000b3e5c + iVar8) = puVar1;
              *(undefined1 **)(puVar12 + -0x10) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar12 + -0x14) = 0x99387;
              pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -0x10));
            }
            else {
              *(undefined **)(puVar12 + -0x10) = puVar1;
              *(undefined4 *)(puVar12 + -0x14) = 0x99352;
              free(*(void **)(puVar12 + -0x10));
            }
          }
          *(undefined4 *)(puVar12 + -0x10) = 2;
          *(int **)(puVar12 + -0x14) = &local_10;
          *(undefined4 *)(puVar12 + -0x18) = 0x99395;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
        *(undefined4 *)(param_1 + 0x81f8) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x81fc) = 0xffffffff;
      }
    }
    else if (local_23 == 3) {
      bVar4 = true;
      if (*(int *)(param_1 + 0x81a8) == 0) {
        *(char **)(puVar12 + -4) = "Error: need auth verifier key.";
        *(undefined4 *)(puVar12 + -8) = 2;
        *(int *)(puVar12 + -0xc) = param_1;
        *(undefined4 *)(puVar12 + -0x10) = 0x99579;
        Error_Printf__11AuthRequestiPce();
        puVar2 = local_14;
        puVar1 = local_14 + -0x10;
        iVar8 = *(int *)(local_14 + -8);
        *(int *)(local_14 + -8) = iVar8 + -1;
        if (iVar8 == 1) {
          if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
            iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
            *(undefined1 **)(puVar12 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar12 + -0x14) = 0x995bb;
            pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -0x10));
            *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
            *(undefined **)(&DAT_000b3e5c + iVar8) = puVar1;
            *(undefined1 **)(puVar12 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar12 + -0x14) = 0x995d7;
            pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -0x10));
          }
          else {
            *(undefined **)(puVar12 + -0x10) = puVar1;
            *(undefined4 *)(puVar12 + -0x14) = 0x995a0;
            free(*(void **)(puVar12 + -0x10));
          }
        }
        *(undefined4 *)(puVar12 + -0x10) = 2;
        *(int **)(puVar12 + -0x14) = &local_10;
        *(undefined4 *)(puVar12 + -0x18) = 0x995e5;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
      if (*(int *)(param_1 + 0x8198) != 0) {
        *(int *)(puVar12 + -4) = *(int *)(param_1 + 0x8198);
        *(undefined4 *)(puVar12 + -8) = 0x995fc;
        DeleteAuthPublicKeyBlock1__15WON_AuthFactoryP23WON_AuthPublicKeyBlock1();
      }
      *(uint *)(puVar12 + -4) = (uint)local_26;
      *(undefined4 *)(puVar12 + -8) = uVar10;
      *(undefined4 *)(puVar12 + -0xc) = 0x9960c;
      iVar8 = NewAuthPublicKeyBlock1__15WON_AuthFactoryPCUcUs();
      *(int *)(param_1 + 0x8198) = iVar8;
      if (iVar8 == 0) {
        *(char **)(puVar12 + -4) =
             "int AuthRequest::handleLoginReply(class ReadBuffer *, class WON_BFSymmetricKey *)";
        *(undefined4 *)(puVar12 + -8) = 0x1e4;
        *(char **)(puVar12 + -0xc) = "/home/jihad/valve/goldsrc/utils/crypt/won/AuthRequest.cpp";
        *(char **)(puVar12 + -0x10) = "m_pPublicKeyBlock";
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar12 + -0x14) = &UNK_00099632;
        __assert_fail(*(char **)(puVar12 + -0x10),*(char **)(puVar12 + -0xc),*(uint *)(puVar12 + -8)
                      ,*(char **)(puVar12 + -4));
      }
      if (*(int *)(param_1 + 0x81a8) == 0) {
        *(char **)(puVar12 + -4) = "Error: need auth verifier key.";
        *(undefined4 *)(puVar12 + -8) = 2;
        *(int *)(puVar12 + -0xc) = param_1;
        *(undefined4 *)(puVar12 + -0x10) = 0x9964b;
        Error_Printf__11AuthRequestiPce();
        puVar2 = local_14;
        puVar1 = local_14 + -0x10;
        iVar8 = *(int *)(local_14 + -8);
        *(int *)(local_14 + -8) = iVar8 + -1;
        if (iVar8 == 1) {
          if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
            iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
            *(undefined1 **)(puVar12 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar12 + -0x14) = 0x9968b;
            pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -0x10));
            *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
            *(undefined **)(&DAT_000b3e5c + iVar8) = puVar1;
            *(undefined1 **)(puVar12 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar12 + -0x14) = 0x996a7;
            pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -0x10));
          }
          else {
            *(undefined **)(puVar12 + -0x10) = puVar1;
            *(undefined4 *)(puVar12 + -0x14) = 0x99672;
            free(*(void **)(puVar12 + -0x10));
          }
        }
        *(undefined4 *)(puVar12 + -0x10) = 2;
        *(int **)(puVar12 + -0x14) = &local_10;
        *(undefined4 *)(puVar12 + -0x18) = 0x996b5;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
      *(int *)(puVar12 + -4) = *(int *)(param_1 + 0x81a8);
      *(undefined4 *)(puVar12 + -8) = 0x996c2;
      uVar5 = GetKeyLen__C16WON_CryptKeyBase();
      *(uint *)(puVar12 + -8) = uVar5 & 0xffff;
      *(undefined4 *)(puVar12 + -0xc) = *(undefined4 *)(param_1 + 0x81a8);
      *(undefined4 *)(puVar12 + -0x10) = 0x996d4;
      uVar10 = GetKey__C16WON_CryptKeyBase();
      *(undefined4 *)(puVar12 + -0xc) = uVar10;
      *(undefined4 *)(puVar12 + -0x10) = *(undefined4 *)(param_1 + 0x8198);
      *(undefined4 *)(puVar12 + -0x14) = 0x996e4;
      iVar8 = Verify__C20WON_AuthFamilyBufferPCUcUs();
      if (iVar8 == 0) {
        *(char **)(puVar12 + -4) = "Verification of public key block failed.";
        *(undefined4 *)(puVar12 + -8) = 2;
        *(int *)(puVar12 + -0xc) = param_1;
        *(undefined4 *)(puVar12 + -0x10) = 0x996fc;
        Error_Printf__11AuthRequestiPce();
        puVar2 = local_14;
        puVar1 = local_14 + -0x10;
        iVar8 = *(int *)(local_14 + -8);
        *(int *)(local_14 + -8) = iVar8 + -1;
        if (iVar8 == 1) {
          if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
            iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
            *(undefined1 **)(puVar12 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar12 + -0x14) = 0x9973f;
            pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -0x10));
            *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
            *(undefined **)(&DAT_000b3e5c + iVar8) = puVar1;
            *(undefined1 **)(puVar12 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar12 + -0x14) = 0x9975b;
            pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -0x10));
          }
          else {
            *(undefined **)(puVar12 + -0x10) = puVar1;
            *(undefined4 *)(puVar12 + -0x14) = 0x99723;
            free(*(void **)(puVar12 + -0x10));
          }
        }
        *(undefined4 *)(puVar12 + -0x10) = 2;
        *(int **)(puVar12 + -0x14) = &local_10;
        *(undefined4 *)(puVar12 + -0x18) = 0x99769;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
    }
    else if (local_23 == 4) {
      *(undefined4 *)(param_1 + 0x81f4) = 1;
      *(uint *)(puVar12 + -4) = (uint)local_26;
      *(undefined4 *)(puVar12 + -8) = uVar10;
      *(undefined4 *)(puVar12 + -0xc) = 0xffffffff;
      *(undefined4 *)(puVar12 + -0x10) = 0;
      *(undefined ***)(puVar12 + -0x14) = &local_14;
      *(undefined4 *)(puVar12 + -0x18) = 0x9978f;
      replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                ();
      if (Callback_GetLocalizedString != (code *)0x0) {
        iVar8 = *(int *)(param_1 + 0x81f8);
        if (iVar8 == -1) {
          *(undefined4 *)(puVar12 + -4) = 0x1b7;
          *(undefined4 *)(puVar12 + -8) = 0x9980b;
          uVar10 = (*Callback_GetLocalizedString)();
          *(undefined4 *)(puVar12 + -8) = uVar10;
          *(undefined4 *)(puVar12 + -0xc) = 2;
        }
        else {
          iVar3 = *(int *)(param_1 + 0x81fc);
          if (iVar3 != -0x5de) {
            if (iVar3 < -0x5dd) {
              if (iVar3 == -0x5df) {
                *(undefined4 *)(puVar12 + -4) = 0x1cb;
                *(undefined4 *)(puVar12 + -8) = 0x997ff;
                uVar10 = (*Callback_GetLocalizedString)();
                *(undefined4 *)(puVar12 + -8) = uVar10;
                *(undefined4 *)(puVar12 + -0xc) = 0x10;
                goto LAB_0009980e;
              }
            }
            else if (iVar3 == -0x5dd) {
              if (iVar8 == 0) {
                *(undefined4 *)(puVar12 + -4) = 0x1b3;
                *(undefined4 *)(puVar12 + -8) = 0x997d2;
                uVar10 = (*Callback_GetLocalizedString)();
                *(undefined4 *)(puVar12 + -8) = uVar10;
                *(undefined4 *)(puVar12 + -0xc) = 4;
              }
              else {
                if (iVar8 != 1) goto LAB_00099817;
                *(undefined4 *)(puVar12 + -4) = 0x1b2;
                *(undefined4 *)(puVar12 + -8) = 0x997e4;
                uVar10 = (*Callback_GetLocalizedString)();
                *(undefined4 *)(puVar12 + -8) = uVar10;
                *(undefined4 *)(puVar12 + -0xc) = 8;
              }
              goto LAB_0009980e;
            }
            goto LAB_00099817;
          }
          *(undefined4 *)(puVar12 + -4) = 0x1cd;
          *(undefined4 *)(puVar12 + -8) = 0x997f3;
          uVar10 = (*Callback_GetLocalizedString)();
          *(undefined4 *)(puVar12 + -8) = uVar10;
          *(undefined4 *)(puVar12 + -0xc) = 0x20;
        }
LAB_0009980e:
        *(int *)(puVar12 + -0x10) = param_1;
        *(undefined4 *)(puVar12 + -0x14) = 0x99814;
        Error_Printf__11AuthRequestiPce();
      }
    }
LAB_00099817:
    puVar12 = puVar11;
  }
  if (local_2c == 0) {
LAB_0009982f:
    puVar2 = local_14;
    puVar1 = local_14 + -0x10;
    iVar8 = *(int *)(local_14 + -8);
    *(int *)(local_14 + -8) = iVar8 + -1;
    if (iVar8 == 1) {
      if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
        iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
        *(undefined1 **)(puVar12 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar12 + -8) = 0x9986f;
        pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -4));
        *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
        *(undefined **)(&DAT_000b3e5c + iVar8) = puVar1;
        *(undefined1 **)(puVar12 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar12 + -8) = 0x9988b;
        pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -4));
      }
      else {
        *(undefined **)(puVar12 + -4) = puVar1;
        *(undefined4 *)(puVar12 + -8) = 0x99856;
        free(*(void **)(puVar12 + -4));
      }
    }
    *(undefined4 *)(puVar12 + -4) = 2;
    *(int **)(puVar12 + -8) = &local_10;
    *(undefined4 *)(puVar12 + -0xc) = 0x99899;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar10 = 0;
  }
  else if (bVar4) {
    puVar2 = local_14 + -0x10;
    iVar8 = *(int *)(local_14 + -8);
    *(int *)(local_14 + -8) = iVar8 + -1;
    if (iVar8 == 1) {
      if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
        iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
        *(undefined1 **)(puVar12 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar12 + -8) = 0x998e7;
        pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -4));
        *(undefined4 *)(puVar1 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
        *(undefined **)(&DAT_000b3e5c + iVar8) = puVar2;
        *(undefined1 **)(puVar12 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar12 + -8) = 0x99903;
        pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -4));
      }
      else {
        *(undefined **)(puVar12 + -4) = puVar2;
        *(undefined4 *)(puVar12 + -8) = 0x998cd;
        free(*(void **)(puVar12 + -4));
      }
    }
    *(undefined4 *)(puVar12 + -4) = 2;
    *(int **)(puVar12 + -8) = &local_10;
    *(undefined4 *)(puVar12 + -0xc) = 0x99911;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar10 = 2;
  }
  else {
    puVar2 = local_14 + -0x10;
    iVar8 = *(int *)(local_14 + -8);
    *(int *)(local_14 + -8) = iVar8 + -1;
    if (iVar8 == 1) {
      if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
        iVar8 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
        *(undefined1 **)(puVar12 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar12 + -8) = 0x9995f;
        pthread_mutex_lock(*(pthread_mutex_t **)(puVar12 + -4));
        *(undefined4 *)(puVar1 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar8);
        *(undefined **)(&DAT_000b3e5c + iVar8) = puVar2;
        *(undefined1 **)(puVar12 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar12 + -8) = 0x9997b;
        pthread_mutex_unlock(*(pthread_mutex_t **)(puVar12 + -4));
      }
      else {
        *(undefined **)(puVar12 + -4) = puVar2;
        *(undefined4 *)(puVar12 + -8) = 0x99943;
        free(*(void **)(puVar12 + -4));
      }
    }
    *(undefined4 *)(puVar12 + -4) = 2;
    *(int **)(puVar12 + -8) = &local_10;
    *(undefined4 *)(puVar12 + -0xc) = 0x99989;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar10 = 1;
  }
  return uVar10;
}


