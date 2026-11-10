// handlePeerLogin__12TitanRequestUlP15EasyTitanSocket  @ 000d0210
undefined4
handlePeerLogin__12TitanRequestUlP15EasyTitanSocket(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x8010) == 0) {
    local_8 = 1;
  }
  else {
    local_8 = 2;
  }
  local_c = (uint)(*(int *)(param_1 + 0x8014) != 0);
  local_10 = (uint)(*(int *)(param_1 + 0x800c) == 0);
  *(undefined2 *)(param_1 + 0x801c) = 1;
  *(undefined2 *)(param_1 + 0x801a) = 1;
  if (*(int *)(param_1 + 0x8020) != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(undefined4 *)(param_1 + 0x8020))
    ;
    *(undefined4 *)(param_1 + 0x8020) = 0;
  }
  iVar1 = peerLogin__11AuthRequestP15EasyTitanSocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iiiiPP20WON_AuthCertificate1PP18WON_BFSymmetricKeyPUsi
                    (*(undefined4 *)(param_1 + 0x8024),param_3,param_1,*(undefined4 *)(param_1 + 4),
                     local_8,local_c,local_10,&local_14,param_1 + 0x8020,param_1 + 0x8018,1);
  if (iVar1 == 0) {
    printf("Unable to authenticate.\n");
    uVar2 = 0;
  }
  else {
    iVar1 = GetCommunityId__C20WON_AuthCertificate1(local_14);
    if ((iVar1 == param_2) || (param_2 == 0)) {
      DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_14);
      uVar2 = 1;
    }
    else {
      printf("Invalid community returned by certificate.\n");
      DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_14);
      uVar2 = 0;
    }
  }
  return uVar2;
}


