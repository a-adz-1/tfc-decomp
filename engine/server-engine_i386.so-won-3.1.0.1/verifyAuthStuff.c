// verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer  @ 00098d0c
undefined4 verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 auStackY_44 [2];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x8198) == 0) {
    Error_Printf__11AuthRequestiPce(param_1,2,"Need public key block.");
  }
  else {
    iVar1 = IsValid__C20WON_AuthFamilyBuffer(param_2);
    puVar3 = &stack0xffffffd0;
    if (iVar1 == 0) {
      Error_Printf__11AuthRequestiPce(param_1,2,"Buffer is invalid.");
    }
    else {
      local_c = 0;
      iVar1 = 0;
      local_8 = (uint)local_8._2_2_ << 0x10;
      while( true ) {
        *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(param_1 + 0x8198);
        *(undefined4 *)(puVar3 + -8) = 0x98deb;
        iVar2 = GetNumKeys__C23WON_AuthPublicKeyBlock1();
        if (iVar2 <= iVar1) break;
        if (iVar1 == 0) {
          *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(param_1 + 0x8198);
          *(undefined4 **)(puVar3 + -8) = &local_14;
          *(undefined4 *)(puVar3 + -0xc) = 0x98d98;
          GetFirstKey__C23WON_AuthPublicKeyBlock1();
          local_c = local_14;
          local_8 = local_10;
        }
        else {
          *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(param_1 + 0x8198);
          *(undefined4 **)(puVar3 + -8) = &local_1c;
          *(undefined4 *)(puVar3 + -0xc) = 0x98db0;
          GetNextKey__C23WON_AuthPublicKeyBlock1();
          local_c = local_1c;
          local_8 = local_18;
        }
        *(uint *)(puVar3 + -8) = local_8 & 0xffff;
        *(undefined4 *)(puVar3 + -0xc) = local_c;
        *(undefined4 *)(puVar3 + -0x10) = param_2;
        *(undefined4 *)(puVar3 + -0x14) = 0x98dd3;
        iVar2 = Verify__C20WON_AuthFamilyBufferPCUcUs();
        puVar3 = puVar3 + -4;
        if (iVar2 != 0) {
          return 1;
        }
        iVar1 = iVar1 + 1;
      }
    }
  }
  return 0;
}


