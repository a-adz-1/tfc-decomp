// verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer  @ 000d1428
undefined4 verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 auStackY_44 [2];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  if (*(int *)(param_1 + 0x8198) == 0) {
    Error_Printf__11AuthRequestiPce(param_1,2,"Need public key block.");
  }
  else {
    iVar1 = IsValid__C20WON_AuthFamilyBuffer(param_2);
    if (iVar1 == 0) {
      Error_Printf__11AuthRequestiPce(param_1,2,"Buffer is invalid.");
    }
    else {
      __Q223WON_AuthPublicKeyBlock112PubKeyReturn(&local_c);
      puVar2 = &stack0xffffffd4;
      local_10 = 0;
      while( true ) {
        *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(param_1 + 0x8198);
        *(undefined4 *)(puVar2 + -0x14) = 0xd14af;
        iVar1 = GetNumKeys__C23WON_AuthPublicKeyBlock1();
        if (iVar1 <= local_10) break;
        if (local_10 == 0) {
          *(undefined4 *)(puVar2 + -0xc) = *(undefined4 *)(param_1 + 0x8198);
          *(undefined4 **)(puVar2 + -0x10) = &local_18;
          *(undefined4 *)(puVar2 + -0x14) = 0xd14d9;
          GetFirstKey__C23WON_AuthPublicKeyBlock1();
          local_c = local_18;
          local_8 = local_14;
        }
        else {
          *(undefined4 *)(puVar2 + -0xc) = *(undefined4 *)(param_1 + 0x8198);
          *(undefined4 **)(puVar2 + -0x10) = &local_20;
          *(undefined4 *)(puVar2 + -0x14) = 0xd14ff;
          GetNextKey__C23WON_AuthPublicKeyBlock1();
          local_c = local_20;
          local_8 = local_1c;
        }
        *(uint *)(puVar2 + -0xc) = local_8 & 0xffff;
        *(undefined4 *)(puVar2 + -0x10) = local_c;
        *(undefined4 *)(puVar2 + -0x14) = param_2;
        *(undefined4 *)(puVar2 + -0x18) = 0xd1525;
        iVar1 = Verify__C20WON_AuthFamilyBufferPCUcUs();
        puVar2 = puVar2 + -4;
        if (iVar1 != 0) {
          return 1;
        }
        local_10 = local_10 + 1;
      }
    }
  }
  return 0;
}


