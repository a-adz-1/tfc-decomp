// verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer  @ 08091220
undefined4 verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 auStackY_40 [2];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x802c) == 0) {
    Error_Printf__11AuthRequestiPce(param_1,2,"Need public key block.");
  }
  else {
    iVar1 = IsValid__C20WON_AuthFamilyBuffer(param_2);
    puVar3 = &stack0xffffffd4;
    if (iVar1 == 0) {
      Error_Printf__11AuthRequestiPce(param_1,2,"Buffer is invalid.");
    }
    else {
      local_c = 0;
      local_8 = (uint)local_8._2_2_ << 0x10;
      iVar1 = 0;
      while( true ) {
        *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(param_1 + 0x802c);
        *(undefined4 *)(puVar3 + -8) = 0x8091318;
        iVar2 = GetNumKeys__C23WON_AuthPublicKeyBlock1();
        if (iVar2 <= iVar1) break;
        if (iVar1 == 0) {
          *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(param_1 + 0x802c);
          *(undefined4 **)(puVar3 + -8) = &local_14;
          *(undefined4 *)(puVar3 + -0xc) = 0x80912c4;
          GetFirstKey__C23WON_AuthPublicKeyBlock1();
          local_c = local_14;
          local_8 = local_10;
        }
        else {
          *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(param_1 + 0x802c);
          *(undefined4 **)(puVar3 + -8) = &local_1c;
          *(undefined4 *)(puVar3 + -0xc) = 0x80912dd;
          GetNextKey__C23WON_AuthPublicKeyBlock1();
          local_c = local_1c;
          local_8 = local_18;
        }
        *(uint *)(puVar3 + -8) = local_8 & 0xffff;
        *(undefined4 *)(puVar3 + -0xc) = local_c;
        *(undefined4 *)(puVar3 + -0x10) = param_2;
        *(undefined4 *)(puVar3 + -0x14) = 0x8091300;
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


