// handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey  @ 000d1a24
undefined4
handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
          (int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int aiStackY_70 [5];
  uint uStack_50;
  undefined1 local_34 [12];
  undefined1 local_28 [4];
  undefined1 local_24 [12];
  undefined4 local_18;
  byte local_13;
  ushort local_12;
  ushort local_10;
  ushort local_e;
  int local_c;
  uint local_8;
  
  local_8 = 1;
  local_c = 0;
  local_12 = 0;
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_24,0,0);
  __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(local_28);
  uVar2 = readUShort__10ReadBufferPUs(param_2,&local_e);
  local_8 = local_8 & uVar2;
  puVar5 = &stack0xffffffb4;
  for (; local_12 < local_e; local_12 = local_12 + 1) {
    *(byte **)(puVar5 + -0xc) = &local_13;
    *(undefined4 *)(puVar5 + -0x10) = param_2;
    *(undefined4 *)(puVar5 + -0x14) = 0xd1aa0;
    uVar2 = readUByte__10ReadBufferPUc();
    local_8 = local_8 & uVar2;
    *(ushort **)(puVar5 + -0xc) = &local_10;
    *(undefined4 *)(puVar5 + -0x10) = param_2;
    *(undefined4 *)(puVar5 + -0x14) = 0xd1ab8;
    uVar2 = readUShort__10ReadBufferPUs();
    local_8 = local_8 & uVar2;
    *(undefined4 *)(puVar5 + -0x10) = param_2;
    *(undefined4 *)(puVar5 + -0x14) = 0xd1acc;
    local_18 = getDataPtr__10ReadBuffer();
    *(uint *)(puVar5 + -0xc) = (uint)local_10;
    *(undefined4 *)(puVar5 + -0x10) = param_2;
    *(undefined4 *)(puVar5 + -0x14) = 0xd1ae7;
    uVar2 = skipBytes__10ReadBufferUl();
    local_8 = local_8 & uVar2;
    if (local_8 == 0) break;
    puVar6 = puVar5;
    if (local_13 == 2) {
      if (param_3 != 0) {
        *(uint *)(puVar5 + -4) = (uint)local_10;
        *(undefined4 *)(puVar5 + -8) = local_18;
        *(int *)(puVar5 + -0xc) = param_3;
        *(undefined1 **)(puVar5 + -0x10) = local_34;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1c04;
        Decrypt__18WON_BFSymmetricKeyPCUcUl();
        *(undefined1 **)(puVar5 + -0x10) = local_34;
        *(undefined1 **)(puVar5 + -0x14) = local_24;
        *(undefined4 *)(puVar5 + -0x18) = 0xd1c17;
        __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn();
        *(undefined4 *)(puVar5 + -0x10) = 2;
        *(undefined1 **)(puVar5 + -0x14) = local_34;
        *(undefined4 *)(puVar5 + -0x18) = 0xd1c32;
        ___Q216WON_CryptKeyBase11CryptReturn();
        *(undefined1 **)(puVar5 + -0x14) = local_24;
        *(undefined4 *)(puVar5 + -0x18) = 0xd1c41;
        iVar3 = GetData__CQ216WON_CryptKeyBase11CryptReturn();
        if (iVar3 == 0) {
          *(code **)(puVar5 + -0xc) = FUN_000ef1c4;
          *(undefined4 *)(puVar5 + -0x10) = 2;
          *(int *)(puVar5 + -0x14) = param_1;
          *(undefined4 *)(puVar5 + -0x18) = 0xd1c5a;
          Error_Printf__11AuthRequestiPce();
          *(undefined4 *)(puVar5 + -0x10) = 2;
          *(undefined1 **)(puVar5 + -0x14) = local_28;
          *(undefined4 *)(puVar5 + -0x18) = 0xd1c6b;
          ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
          *(undefined4 *)(puVar5 + -0x10) = 2;
          *(undefined1 **)(puVar5 + -0x14) = local_24;
          *(undefined4 *)(puVar5 + -0x18) = 0xd1c7c;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
        if (*(int *)(param_1 + 0x81ac) != 0) {
          *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(param_1 + 0x81ac);
          *(undefined4 *)(puVar5 + -0x18) = 0xd1ca0;
          DeleteEGPrivateKey__16WON_CryptFactoryP16WON_EGPrivateKey();
        }
        *(undefined1 **)(puVar5 + -0x1c) = local_24;
        *(undefined4 *)(puVar5 + -0x20) = 0xd1cb2;
        uVar4 = GetData__CQ216WON_CryptKeyBase11CryptReturn();
        *(undefined4 *)(puVar5 + -0x10) = uVar4;
        *(undefined1 **)(puVar5 + -0x20) = local_24;
        *(undefined4 *)(puVar5 + -0x24) = 0xd1cc4;
        uVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn();
        *(uint *)(puVar5 + -0x14) = (uint)uVar1;
        *(undefined4 *)(puVar5 + -0x18) = 0xd1cd4;
        uVar4 = NewEGPrivateKey__16WON_CryptFactoryUsPCUc();
        *(undefined4 *)(param_1 + 0x81ac) = uVar4;
        *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(param_1 + 0x81ac);
        *(undefined4 *)(puVar5 + -0x18) = 0xd1cee;
        iVar3 = GetLastError__C16WON_CryptKeyBase();
        puVar6 = puVar5 + -4;
        if (iVar3 != 0) {
          *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(param_1 + 0x81ac);
          *(undefined4 *)(puVar5 + -0x18) = 0xd1d06;
          uVar4 = GetLastError__C16WON_CryptKeyBase();
          *(undefined4 *)(puVar5 + -8) = uVar4;
          *(char **)(puVar5 + -0xc) = "Error constructing private key: %s";
          *(undefined4 *)(puVar5 + -0x10) = 2;
          *(int *)(puVar5 + -0x14) = param_1;
          *(undefined4 *)(puVar5 + -0x18) = 0xd1d19;
          Error_Printf__11AuthRequestiPce();
          *(undefined4 *)(puVar5 + -0x10) = 2;
          *(undefined1 **)(puVar5 + -0x14) = local_28;
          *(undefined4 *)(puVar5 + -0x18) = 0xd1d2a;
          ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
          *(undefined4 *)(puVar5 + -0x10) = 2;
          *(undefined1 **)(puVar5 + -0x14) = local_24;
          *(undefined4 *)(puVar5 + -0x18) = 0xd1d3b;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
      }
    }
    else if (local_13 < 3) {
      if (local_13 == 1) {
        if (*(int *)(param_1 + 0x819c) != 0) {
          *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(param_1 + 0x819c);
          *(undefined4 *)(puVar5 + -0x14) = 0xd1b4c;
          DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1();
        }
        *(uint *)(puVar5 + -0xc) = (uint)local_10;
        *(undefined4 *)(puVar5 + -0x10) = local_18;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1b62;
        uVar4 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs();
        *(undefined4 *)(param_1 + 0x819c) = uVar4;
        *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(param_1 + 0x819c);
        *(int *)(puVar5 + -0x10) = param_1;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1b7d;
        iVar3 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer();
        if (iVar3 == 0) {
          *(char **)(puVar5 + -8) = "Verification of certificate failed.";
          *(undefined4 *)(puVar5 + -0xc) = 2;
          *(int *)(puVar5 + -0x10) = param_1;
          *(undefined4 *)(puVar5 + -0x14) = 0xd1b96;
          Error_Printf__11AuthRequestiPce();
          *(undefined4 *)(puVar5 + -0xc) = 2;
          *(undefined1 **)(puVar5 + -0x10) = local_28;
          *(undefined4 *)(puVar5 + -0x14) = 0xd1ba7;
          ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
          *(undefined4 *)(puVar5 + -0xc) = 2;
          *(undefined1 **)(puVar5 + -0x10) = local_24;
          *(undefined4 *)(puVar5 + -0x14) = 0xd1bb8;
          ___Q216WON_CryptKeyBase11CryptReturn();
          return 0;
        }
        *(undefined4 *)(param_1 + 0x81f8) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x81fc) = 0xffffffff;
      }
    }
    else if (local_13 == 3) {
      local_c = 1;
      if (*(int *)(param_1 + 0x81a8) == 0) {
        *(char **)(puVar5 + -8) = "Error: need auth verifier key.";
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(int *)(puVar5 + -0x10) = param_1;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1d70;
        Error_Printf__11AuthRequestiPce();
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(undefined1 **)(puVar5 + -0x10) = local_28;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1d81;
        ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(undefined1 **)(puVar5 + -0x10) = local_24;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1d92;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
      if (*(int *)(param_1 + 0x8198) != 0) {
        *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(param_1 + 0x8198);
        *(undefined4 *)(puVar5 + -0x14) = 0xd1db4;
        DeleteAuthPublicKeyBlock1__15WON_AuthFactoryP23WON_AuthPublicKeyBlock1();
      }
      *(uint *)(puVar5 + -0xc) = (uint)local_10;
      *(undefined4 *)(puVar5 + -0x10) = local_18;
      *(undefined4 *)(puVar5 + -0x14) = 0xd1dca;
      uVar4 = NewAuthPublicKeyBlock1__15WON_AuthFactoryPCUcUs();
      *(undefined4 *)(param_1 + 0x8198) = uVar4;
      if (*(int *)(param_1 + 0x81a8) == 0) {
        *(char **)(puVar5 + -8) = "Error: need auth verifier key.";
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(int *)(puVar5 + -0x10) = param_1;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1dee;
        Error_Printf__11AuthRequestiPce();
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(undefined1 **)(puVar5 + -0x10) = local_28;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1dff;
        ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(undefined1 **)(puVar5 + -0x10) = local_24;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1e10;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
      *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(param_1 + 0x81a8);
      *(undefined4 *)(puVar5 + -0x18) = 0xd1e2e;
      uVar1 = GetKeyLen__C16WON_CryptKeyBase();
      *(uint *)(puVar5 + -8) = (uint)uVar1;
      *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(param_1 + 0x81a8);
      *(undefined4 *)(puVar5 + -0x1c) = 0xd1e48;
      uVar4 = GetKey__C16WON_CryptKeyBase();
      *(undefined4 *)(puVar5 + -0xc) = uVar4;
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(param_1 + 0x8198);
      *(undefined4 *)(puVar5 + -0x14) = 0xd1e5a;
      iVar3 = Verify__C20WON_AuthFamilyBufferPCUcUs();
      if (iVar3 == 0) {
        *(char **)(puVar5 + -8) = "Verification of public key block failed.";
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(int *)(puVar5 + -0x10) = param_1;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1e73;
        Error_Printf__11AuthRequestiPce();
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(undefined1 **)(puVar5 + -0x10) = local_28;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1e84;
        ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
        *(undefined4 *)(puVar5 + -0xc) = 2;
        *(undefined1 **)(puVar5 + -0x10) = local_24;
        *(undefined4 *)(puVar5 + -0x14) = 0xd1e95;
        ___Q216WON_CryptKeyBase11CryptReturn();
        return 0;
      }
    }
    else if (local_13 == 4) {
      *(undefined4 *)(param_1 + 0x81f4) = 1;
      *(uint *)(puVar5 + -8) = (uint)local_10;
      *(undefined4 *)(puVar5 + -0xc) = local_18;
      *(undefined1 **)(puVar5 + -0x10) = local_28;
      *(undefined4 *)(puVar5 + -0x14) = 0xd1ec9;
      assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi();
      if (Callback_GetLocalizedString != (code *)0x0) {
        if (*(int *)(param_1 + 0x81f8) == -1) {
          *(undefined4 *)(puVar5 + -0x14) = 0x1b7;
          *(undefined4 *)(puVar5 + -0x18) = 0xd204b;
          uVar4 = (*Callback_GetLocalizedString)();
          *(undefined4 *)(puVar5 + -8) = uVar4;
          *(undefined4 *)(puVar5 + -0xc) = 2;
          *(int *)(puVar5 + -0x10) = param_1;
          *(undefined4 *)(puVar5 + -0x14) = 0xd2059;
          Error_Printf__11AuthRequestiPce();
        }
        else {
          switch(*(undefined4 *)(param_1 + 0x81fc)) {
          case 0xfffffa1a:
            *(undefined4 *)(puVar5 + -0x14) = 0x1b3;
            *(undefined4 *)(puVar5 + -0x18) = 0xd1ff7;
            uVar4 = (*Callback_GetLocalizedString)();
            *(undefined4 *)(puVar5 + -8) = uVar4;
            *(undefined4 *)(puVar5 + -0xc) = 4;
            *(int *)(puVar5 + -0x10) = param_1;
            *(undefined4 *)(puVar5 + -0x14) = 0xd2005;
            Error_Printf__11AuthRequestiPce();
            break;
          default:
            *(undefined4 *)(puVar5 + -0x14) = 0x1b7;
            *(undefined4 *)(puVar5 + -0x18) = 0xd201f;
            uVar4 = (*Callback_GetLocalizedString)();
            *(undefined4 *)(puVar5 + -8) = uVar4;
            *(undefined4 *)(puVar5 + -0xc) = 2;
            *(int *)(puVar5 + -0x10) = param_1;
            *(undefined4 *)(puVar5 + -0x14) = 0xd202d;
            Error_Printf__11AuthRequestiPce();
            break;
          case 0xfffffa20:
            *(undefined4 *)(puVar5 + -0x14) = 0x1b2;
            *(undefined4 *)(puVar5 + -0x18) = 0xd1fcf;
            uVar4 = (*Callback_GetLocalizedString)();
            *(undefined4 *)(puVar5 + -8) = uVar4;
            *(undefined4 *)(puVar5 + -0xc) = 8;
            *(int *)(puVar5 + -0x10) = param_1;
            *(undefined4 *)(puVar5 + -0x14) = 0xd1fdd;
            Error_Printf__11AuthRequestiPce();
            break;
          case 0xfffffa21:
            *(undefined4 *)(puVar5 + -0x14) = 0x1cb;
            *(undefined4 *)(puVar5 + -0x18) = 0xd1fa7;
            uVar4 = (*Callback_GetLocalizedString)();
            *(undefined4 *)(puVar5 + -8) = uVar4;
            *(undefined4 *)(puVar5 + -0xc) = 0x10;
            *(int *)(puVar5 + -0x10) = param_1;
            *(undefined4 *)(puVar5 + -0x14) = 0xd1fb5;
            Error_Printf__11AuthRequestiPce();
            break;
          case 0xfffffa22:
            *(undefined4 *)(puVar5 + -0x14) = 0x1cd;
            *(undefined4 *)(puVar5 + -0x18) = 0xd1f7b;
            uVar4 = (*Callback_GetLocalizedString)();
            *(undefined4 *)(puVar5 + -8) = uVar4;
            *(undefined4 *)(puVar5 + -0xc) = 0x20;
            *(int *)(puVar5 + -0x10) = param_1;
            *(undefined4 *)(puVar5 + -0x14) = 0xd1f89;
            Error_Printf__11AuthRequestiPce();
            break;
          case 0xfffffa23:
            if (*(int *)(param_1 + 0x81f8) == 0) {
              *(undefined4 *)(puVar5 + -0x14) = 0x1b3;
              *(undefined4 *)(puVar5 + -0x18) = 0xd1f20;
              uVar4 = (*Callback_GetLocalizedString)();
              *(undefined4 *)(puVar5 + -8) = uVar4;
              *(undefined4 *)(puVar5 + -0xc) = 4;
              *(int *)(puVar5 + -0x10) = param_1;
              *(undefined4 *)(puVar5 + -0x14) = 0xd1f2e;
              Error_Printf__11AuthRequestiPce();
            }
            else if (*(int *)(param_1 + 0x81f8) == 1) {
              *(undefined4 *)(puVar5 + -0x14) = 0x1b2;
              *(undefined4 *)(puVar5 + -0x18) = 0xd1f50;
              uVar4 = (*Callback_GetLocalizedString)();
              *(undefined4 *)(puVar5 + -8) = uVar4;
              *(undefined4 *)(puVar5 + -0xc) = 8;
              *(int *)(puVar5 + -0x10) = param_1;
              *(undefined4 *)(puVar5 + -0x14) = 0xd1f5e;
              Error_Printf__11AuthRequestiPce();
            }
          }
        }
      }
    }
    puVar5 = puVar6;
  }
  if (local_8 == 0) {
    *(undefined4 *)(puVar5 + -0xc) = 2;
    *(undefined1 **)(puVar5 + -0x10) = local_28;
    *(undefined4 *)(puVar5 + -0x14) = 0xd2084;
    ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
    *(undefined4 *)(puVar5 + -0xc) = 2;
    *(undefined1 **)(puVar5 + -0x10) = local_24;
    *(undefined4 *)(puVar5 + -0x14) = 0xd2095;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar4 = 0;
  }
  else if (local_c == 0) {
    *(undefined4 *)(puVar5 + -0xc) = 2;
    *(undefined1 **)(puVar5 + -0x10) = local_28;
    *(undefined4 *)(puVar5 + -0x14) = 0xd20e6;
    ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
    *(undefined4 *)(puVar5 + -0xc) = 2;
    *(undefined1 **)(puVar5 + -0x10) = local_24;
    *(undefined4 *)(puVar5 + -0x14) = 0xd20f7;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar4 = 1;
  }
  else {
    *(undefined4 *)(puVar5 + -0xc) = 2;
    *(undefined1 **)(puVar5 + -0x10) = local_28;
    *(undefined4 *)(puVar5 + -0x14) = 0xd20b8;
    ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
    *(undefined4 *)(puVar5 + -0xc) = 2;
    *(undefined1 **)(puVar5 + -0x10) = local_24;
    *(undefined4 *)(puVar5 + -0x14) = 0xd20c9;
    ___Q216WON_CryptKeyBase11CryptReturn();
    uVar4 = 2;
  }
  return uVar4;
}


