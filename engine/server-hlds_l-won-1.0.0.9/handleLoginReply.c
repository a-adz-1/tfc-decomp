// handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey  @ 08091710
undefined4
handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
          (int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int aiStackY_60 [5];
  ushort local_32;
  uint local_2c;
  ushort local_26;
  byte local_23;
  ushort local_22;
  undefined1 local_20 [12];
  undefined *local_14;
  int local_10;
  ushort local_c;
  
  bVar3 = false;
  local_32 = 0;
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_10,0,0);
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    local_14 = &force_to_data;
  }
  else {
    local_14 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (
                         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                         );
  }
  local_2c = readUShort__10ReadBufferPUs(param_2,&local_22);
  local_2c = local_2c & 1;
  puVar10 = &stack0xffffffc0;
  for (; local_32 < local_22; local_32 = local_32 + 1) {
    *(byte **)(puVar10 + -4) = &local_23;
    *(undefined4 *)(puVar10 + -8) = param_2;
    *(undefined4 *)(puVar10 + -0xc) = 0x809179d;
    uVar4 = readUByte__10ReadBufferPUc();
    *(ushort **)(puVar10 + -0xc) = &local_26;
    *(undefined4 *)(puVar10 + -0x10) = param_2;
    *(undefined4 *)(puVar10 + -0x14) = 0x80917ad;
    uVar5 = readUShort__10ReadBufferPUs();
    *(undefined4 *)(puVar10 + -0x14) = param_2;
    *(undefined4 *)(puVar10 + -0x18) = 0x80917b9;
    uVar8 = getDataPtr__10ReadBuffer();
    *(uint *)(puVar10 + -0x18) = (uint)local_26;
    *(undefined4 *)(puVar10 + -0x1c) = param_2;
    *(undefined4 *)(puVar10 + -0x20) = 0x80917cb;
    uVar6 = skipBytes__10ReadBufferUl();
    local_2c = local_2c & uVar4 & uVar5 & uVar6;
    if (local_2c == 0) goto LAB_08091d6a;
    puVar9 = puVar10;
    if (local_23 == 2) {
      if (param_3 != 0) {
        *(uint *)(puVar10 + -4) = (uint)local_26;
        *(undefined4 *)(puVar10 + -8) = uVar8;
        *(int *)(puVar10 + -0xc) = param_3;
        *(undefined1 **)(puVar10 + -0x10) = local_20;
        *(undefined4 *)(puVar10 + -0x14) = 0x809194f;
        Decrypt__18WON_BFSymmetricKeyPCUcUl();
        *(undefined1 **)(puVar10 + -0x14) = local_20;
        *(int **)(puVar10 + -0x18) = &local_10;
        *(undefined4 *)(puVar10 + -0x1c) = 0x8091959;
        __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn();
        *(undefined4 *)(puVar10 + -8) = 2;
        *(undefined1 **)(puVar10 + -0xc) = local_20;
        *(undefined4 *)(puVar10 + -0x10) = 0x809197b;
        ___Q216WON_CryptKeyBase11CryptReturn();
        if (local_10 == 0) {
          *(char **)(puVar10 + -8) = "Error decrypting private key.";
          *(undefined4 *)(puVar10 + -0xc) = 2;
          *(int *)(puVar10 + -0x10) = param_1;
          *(undefined4 *)(puVar10 + -0x14) = 0x8091995;
          Error_Printf__11AuthRequestiPce();
          puVar1 = (undefined4 *)(local_14 + -0x10);
          piVar2 = (int *)(local_14 + -8);
          *piVar2 = *piVar2 + -1;
          if (*piVar2 == 0) {
            if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
              iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
              *(undefined1 **)(puVar10 + -0x14) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar10 + -0x18) = 0x80919d7;
              pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -0x14));
              *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
              *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
              *(undefined1 **)(puVar10 + -0x14) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar10 + -0x18) = 0x80919f2;
              pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -0x14));
            }
            else {
              *(undefined4 **)(puVar10 + -0x14) = puVar1;
              *(undefined4 *)(puVar10 + -0x18) = 0x80919b5;
              free(*(void **)(puVar10 + -0x14));
            }
          }
          *(undefined4 *)(puVar10 + -0x14) = 2;
          *(int **)(puVar10 + -0x18) = &local_10;
          *(undefined4 *)(puVar10 + -0x1c) = 0x8091a00;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
        if (*(int *)(param_1 + 0x8040) != 0) {
          *(undefined4 *)(puVar10 + -8) = *(undefined4 *)(param_1 + 0x8040);
          *(undefined4 *)(puVar10 + -0xc) = 0x8091a25;
          DeleteEGPrivateKey__16WON_CryptFactoryP16WON_EGPrivateKey();
        }
        *(int *)(puVar10 + -8) = local_10;
        *(uint *)(puVar10 + -0xc) = (uint)local_c;
        *(undefined4 *)(puVar10 + -0x10) = 0x8091a38;
        iVar7 = NewEGPrivateKey__16WON_CryptFactoryUsPCUc();
        *(int *)(param_1 + 0x8040) = iVar7;
        if (iVar7 == 0) {
          *(char **)(puVar10 + -8) =
               "int AuthRequest::handleLoginReply(class ReadBuffer *, class WON_BFSymmetricKey *)";
          *(undefined4 *)(puVar10 + -0xc) = 0x1e1;
          *(char **)(puVar10 + -0x10) = "/e/quiver/goldsrc/common/authrequest.cpp";
          *(char **)(puVar10 + -0x14) = "mPrivateKey";
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar10 + -0x18) = &UNK_08091a5e;
          __assert_fail(*(char **)(puVar10 + -0x14),*(char **)(puVar10 + -0x10),
                        *(uint *)(puVar10 + -0xc),*(char **)(puVar10 + -8));
        }
        puVar9 = puVar10 + -4;
        if (**(int **)(param_1 + 0x8040) != 0) {
          *(int *)(puVar10 + -8) = **(int **)(param_1 + 0x8040);
          *(char **)(puVar10 + -0xc) = "Error constructing private key: %s";
          *(undefined4 *)(puVar10 + -0x10) = 2;
          *(int *)(puVar10 + -0x14) = param_1;
          *(undefined4 *)(puVar10 + -0x18) = 0x8091a7e;
          Error_Printf__11AuthRequestiPce();
          puVar1 = (undefined4 *)(local_14 + -0x10);
          piVar2 = (int *)(local_14 + -8);
          *piVar2 = *piVar2 + -1;
          if (*piVar2 == 0) {
            if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
              iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
              *(undefined1 **)(puVar10 + -0x18) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar10 + -0x1c) = 0x8091ab7;
              pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -0x18));
              *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
              *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
              *(undefined1 **)(puVar10 + -0x18) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar10 + -0x1c) = 0x8091ad2;
              pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -0x18));
            }
            else {
              *(undefined4 **)(puVar10 + -0x18) = puVar1;
              *(undefined4 *)(puVar10 + -0x1c) = 0x8091a9e;
              free(*(void **)(puVar10 + -0x18));
            }
          }
          *(undefined4 *)(puVar10 + -0x18) = 2;
          *(int **)(puVar10 + -0x1c) = &local_10;
          *(undefined4 *)(puVar10 + -0x20) = 0x8091ae0;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
      }
    }
    else if (local_23 < 2) {
      if (local_23 == 1) {
        if (*(int *)(param_1 + 0x8030) != 0) {
          *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(param_1 + 0x8030);
          *(undefined4 *)(puVar10 + -8) = 0x8091835;
          DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1();
        }
        *(uint *)(puVar10 + -4) = (uint)local_26;
        *(undefined4 *)(puVar10 + -8) = uVar8;
        *(undefined4 *)(puVar10 + -0xc) = 0x8091845;
        iVar7 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs();
        *(int *)(param_1 + 0x8030) = iVar7;
        if (iVar7 == 0) {
          *(char **)(puVar10 + -4) =
               "int AuthRequest::handleLoginReply(class ReadBuffer *, class WON_BFSymmetricKey *)";
          *(undefined4 *)(puVar10 + -8) = 0x1c9;
          *(char **)(puVar10 + -0xc) = "/e/quiver/goldsrc/common/authrequest.cpp";
          *(char **)(puVar10 + -0x10) = "mCertificate";
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar10 + -0x14) = &UNK_0809186b;
          __assert_fail(*(char **)(puVar10 + -0x10),*(char **)(puVar10 + -0xc),
                        *(uint *)(puVar10 + -8),*(char **)(puVar10 + -4));
        }
        *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(param_1 + 0x8030);
        *(int *)(puVar10 + -8) = param_1;
        *(undefined4 *)(puVar10 + -0xc) = 0x809187d;
        iVar7 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer();
        if (iVar7 == 0) {
          *(char **)(puVar10 + -4) = "Verification of certificate failed.";
          *(undefined4 *)(puVar10 + -8) = 2;
          *(int *)(puVar10 + -0xc) = param_1;
          *(undefined4 *)(puVar10 + -0x10) = 0x8091895;
          Error_Printf__11AuthRequestiPce();
          puVar1 = (undefined4 *)(local_14 + -0x10);
          piVar2 = (int *)(local_14 + -8);
          *piVar2 = *piVar2 + -1;
          if (*piVar2 == 0) {
            if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
              iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
              *(undefined1 **)(puVar10 + -0x10) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar10 + -0x14) = 0x80918d7;
              pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -0x10));
              *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
              *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
              *(undefined1 **)(puVar10 + -0x10) =
                   _t24__default_alloc_template2b1i0___node_allocator_lock;
              *(undefined4 *)(puVar10 + -0x14) = 0x80918f2;
              pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -0x10));
            }
            else {
              *(undefined4 **)(puVar10 + -0x10) = puVar1;
              *(undefined4 *)(puVar10 + -0x14) = 0x80918b5;
              free(*(void **)(puVar10 + -0x10));
            }
          }
          *(undefined4 *)(puVar10 + -0x10) = 2;
          *(int **)(puVar10 + -0x14) = &local_10;
          *(undefined4 *)(puVar10 + -0x18) = 0x8091900;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
        *(undefined4 *)(param_1 + 0x8094) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x8098) = 0xffffffff;
      }
    }
    else if (local_23 == 3) {
      bVar3 = true;
      if (*(int *)(param_1 + 0x803c) == 0) {
        *(char **)(puVar10 + -4) = "Error: need auth verifier key.";
        *(undefined4 *)(puVar10 + -8) = 2;
        *(int *)(puVar10 + -0xc) = param_1;
        *(undefined4 *)(puVar10 + -0x10) = 0x8091b11;
        Error_Printf__11AuthRequestiPce();
        puVar1 = (undefined4 *)(local_14 + -0x10);
        piVar2 = (int *)(local_14 + -8);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
            iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
            *(undefined1 **)(puVar10 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091b57;
            pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -0x10));
            *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
            *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
            *(undefined1 **)(puVar10 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091b72;
            pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -0x10));
          }
          else {
            *(undefined4 **)(puVar10 + -0x10) = puVar1;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091b31;
            free(*(void **)(puVar10 + -0x10));
          }
        }
        *(undefined4 *)(puVar10 + -0x10) = 2;
        *(int **)(puVar10 + -0x14) = &local_10;
        *(undefined4 *)(puVar10 + -0x18) = 0x8091b80;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
      if (*(int *)(param_1 + 0x802c) != 0) {
        *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(param_1 + 0x802c);
        *(undefined4 *)(puVar10 + -8) = 0x8091ba5;
        DeleteAuthPublicKeyBlock1__15WON_AuthFactoryP23WON_AuthPublicKeyBlock1();
      }
      *(uint *)(puVar10 + -4) = (uint)local_26;
      *(undefined4 *)(puVar10 + -8) = uVar8;
      *(undefined4 *)(puVar10 + -0xc) = 0x8091bb5;
      iVar7 = NewAuthPublicKeyBlock1__15WON_AuthFactoryPCUcUs();
      *(int *)(param_1 + 0x802c) = iVar7;
      if (iVar7 == 0) {
        *(char **)(puVar10 + -4) =
             "int AuthRequest::handleLoginReply(class ReadBuffer *, class WON_BFSymmetricKey *)";
        *(undefined4 *)(puVar10 + -8) = 500;
        *(char **)(puVar10 + -0xc) = "/e/quiver/goldsrc/common/authrequest.cpp";
        *(char **)(puVar10 + -0x10) = "mPublicKeyBlock";
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar10 + -0x14) = &UNK_08091bdb;
        __assert_fail(*(char **)(puVar10 + -0x10),*(char **)(puVar10 + -0xc),*(uint *)(puVar10 + -8)
                      ,*(char **)(puVar10 + -4));
      }
      if (*(int *)(param_1 + 0x803c) == 0) {
        *(char **)(puVar10 + -4) = "Error: need auth verifier key.";
        *(undefined4 *)(puVar10 + -8) = 2;
        *(int *)(puVar10 + -0xc) = param_1;
        *(undefined4 *)(puVar10 + -0x10) = 0x8091bfa;
        Error_Printf__11AuthRequestiPce();
        puVar1 = (undefined4 *)(local_14 + -0x10);
        piVar2 = (int *)(local_14 + -8);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
            iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
            *(undefined1 **)(puVar10 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091c37;
            pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -0x10));
            *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
            *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
            *(undefined1 **)(puVar10 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091c52;
            pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -0x10));
          }
          else {
            *(undefined4 **)(puVar10 + -0x10) = puVar1;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091c1a;
            free(*(void **)(puVar10 + -0x10));
          }
        }
        *(undefined4 *)(puVar10 + -0x10) = 2;
        *(int **)(puVar10 + -0x14) = &local_10;
        *(undefined4 *)(puVar10 + -0x18) = 0x8091c60;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
      *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(param_1 + 0x803c);
      *(undefined4 *)(puVar10 + -8) = 0x8091c7c;
      uVar4 = GetKeyLen__C16WON_CryptKeyBase();
      *(uint *)(puVar10 + -8) = uVar4 & 0xffff;
      *(undefined4 *)(puVar10 + -0xc) = *(undefined4 *)(param_1 + 0x803c);
      *(undefined4 *)(puVar10 + -0x10) = 0x8091c8e;
      uVar8 = GetKey__C16WON_CryptKeyBase();
      *(undefined4 *)(puVar10 + -0xc) = uVar8;
      *(undefined4 *)(puVar10 + -0x10) = *(undefined4 *)(param_1 + 0x802c);
      *(undefined4 *)(puVar10 + -0x14) = 0x8091c9e;
      iVar7 = Verify__C20WON_AuthFamilyBufferPCUcUs();
      if (iVar7 == 0) {
        *(char **)(puVar10 + -4) = "Verification of public key block failed.";
        *(undefined4 *)(puVar10 + -8) = 2;
        *(int *)(puVar10 + -0xc) = param_1;
        *(undefined4 *)(puVar10 + -0x10) = 0x8091cb6;
        Error_Printf__11AuthRequestiPce();
        puVar1 = (undefined4 *)(local_14 + -0x10);
        piVar2 = (int *)(local_14 + -8);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
            iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
            *(undefined1 **)(puVar10 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091cf7;
            pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -0x10));
            *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
            *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
            *(undefined1 **)(puVar10 + -0x10) =
                 _t24__default_alloc_template2b1i0___node_allocator_lock;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091d12;
            pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -0x10));
          }
          else {
            *(undefined4 **)(puVar10 + -0x10) = puVar1;
            *(undefined4 *)(puVar10 + -0x14) = 0x8091cd6;
            free(*(void **)(puVar10 + -0x10));
          }
        }
        *(undefined4 *)(puVar10 + -0x10) = 2;
        *(int **)(puVar10 + -0x14) = &local_10;
        *(undefined4 *)(puVar10 + -0x18) = 0x8091d20;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
    }
    else if (local_23 == 4) {
      *(undefined4 *)(param_1 + 0x8090) = 1;
      *(uint *)(puVar10 + -4) = (uint)local_26;
      *(undefined4 *)(puVar10 + -8) = uVar8;
      *(undefined4 *)(puVar10 + -0xc) = 0xffffffff;
      *(undefined4 *)(puVar10 + -0x10) = 0;
      *(undefined ***)(puVar10 + -0x14) = &local_14;
      *(undefined4 *)(puVar10 + -0x18) = 0x8091d4f;
      replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                ();
    }
    puVar10 = puVar9;
  }
  if (local_2c == 0) {
LAB_08091d6a:
    puVar1 = (undefined4 *)(local_14 + -0x10);
    piVar2 = (int *)(local_14 + -8);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
        iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
        *(undefined1 **)(puVar10 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar10 + -8) = 0x8091da7;
        pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -4));
        *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
        *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
        *(undefined1 **)(puVar10 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar10 + -8) = 0x8091dc2;
        pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -4));
      }
      else {
        *(undefined4 **)(puVar10 + -4) = puVar1;
        *(undefined4 *)(puVar10 + -8) = 0x8091d8a;
        free(*(void **)(puVar10 + -4));
      }
    }
    *(undefined4 *)(puVar10 + -4) = 2;
    *(int **)(puVar10 + -8) = &local_10;
    *(undefined4 *)(puVar10 + -0xc) = 0x8091dd0;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar8 = 0;
  }
  else if (bVar3) {
    puVar1 = (undefined4 *)(local_14 + -0x10);
    piVar2 = (int *)(local_14 + -8);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
        iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
        *(undefined1 **)(puVar10 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar10 + -8) = 0x8091e27;
        pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -4));
        *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
        *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
        *(undefined1 **)(puVar10 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar10 + -8) = 0x8091e42;
        pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -4));
      }
      else {
        *(undefined4 **)(puVar10 + -4) = puVar1;
        *(undefined4 *)(puVar10 + -8) = 0x8091e06;
        free(*(void **)(puVar10 + -4));
      }
    }
    *(undefined4 *)(puVar10 + -4) = 2;
    *(int **)(puVar10 + -8) = &local_10;
    *(undefined4 *)(puVar10 + -0xc) = 0x8091e50;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar8 = 2;
  }
  else {
    puVar1 = (undefined4 *)(local_14 + -0x10);
    piVar2 = (int *)(local_14 + -8);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      if (*(int *)(local_14 + -0xc) + 0x10U < 0x81) {
        iVar7 = (*(int *)(local_14 + -0xc) + 0x17U >> 3) * 4;
        *(undefined1 **)(puVar10 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar10 + -8) = 0x8091ea7;
        pthread_mutex_lock(*(pthread_mutex_t **)(puVar10 + -4));
        *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar7);
        *(undefined4 **)(&DAT_080ab95c + iVar7) = puVar1;
        *(undefined1 **)(puVar10 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar10 + -8) = 0x8091ec2;
        pthread_mutex_unlock(*(pthread_mutex_t **)(puVar10 + -4));
      }
      else {
        *(undefined4 **)(puVar10 + -4) = puVar1;
        *(undefined4 *)(puVar10 + -8) = 0x8091e80;
        free(*(void **)(puVar10 + -4));
      }
    }
    *(undefined4 *)(puVar10 + -4) = 2;
    *(int **)(puVar10 + -8) = &local_10;
    *(undefined4 *)(puVar10 + -0xc) = 0x8091ed0;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar8 = 1;
  }
  return uVar8;
}


