// handlePeerLogin__12TitanRequestUlP15EasyTitanSocket  @ 00097db4
undefined4
handlePeerLogin__12TitanRequestUlP15EasyTitanSocket(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x8024) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("mAuthRequest","/home/jihad/valve/goldsrc/utils/crypt/won/TitanRequest.cpp",0x36,
                  "int TitanRequest::handlePeerLogin(long unsigned int, class EasyTitanSocket *)");
  }
  uVar3 = 1;
  if (*(int *)(param_1 + 0x8010) != 0) {
    uVar3 = 2;
  }
  iVar2 = *(int *)(param_1 + 0x8014);
  iVar1 = *(int *)(param_1 + 0x800c);
  *(undefined2 *)(param_1 + 0x801c) = 1;
  *(undefined2 *)(param_1 + 0x801a) = 1;
  if (*(int *)(param_1 + 0x8020) != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int *)(param_1 + 0x8020));
    *(undefined4 *)(param_1 + 0x8020) = 0;
  }
  iVar2 = peerLogin__11AuthRequestP15EasyTitanSocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iiiiPP20WON_AuthCertificate1PP18WON_BFSymmetricKeyPUsi
                    (*(undefined4 *)(param_1 + 0x8024),param_3,param_1,*(undefined4 *)(param_1 + 4),
                     uVar3,iVar2 != 0,iVar1 == 0,&local_8,param_1 + 0x8020,param_1 + 0x8018,1);
  if (iVar2 == 0) {
    printf("Unable to authenticate.\n");
    uVar3 = 0;
  }
  else {
    iVar2 = GetCommunityId__C20WON_AuthCertificate1(local_8);
    if ((iVar2 == param_2) || (param_2 == 0)) {
      DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_8);
      uVar3 = 1;
    }
    else {
      printf("Invalid community returned by certificate.\n");
      DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_8);
      uVar3 = 0;
    }
  }
  return uVar3;
}


