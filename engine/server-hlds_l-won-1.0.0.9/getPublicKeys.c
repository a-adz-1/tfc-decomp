// getPublicKeys__11AuthRequestP15EasyTitanSocket  @ 08091330
undefined4 getPublicKeys__11AuthRequestP15EasyTitanSocket(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_28;
  ushort local_24;
  short local_22;
  undefined1 local_20 [12];
  undefined1 local_14 [16];
  
  gcc2_compiled_(local_14,0x100);
  gcc2_compiled_(local_20);
  appendLong__11WriteBufferl(local_14,0);
  appendLong__11WriteBufferl(local_14,0xca);
  appendLong__11WriteBufferl(local_14,1);
  uVar2 = getSize__C11WriteBuffer(local_14);
  setLong__11WriteBufferUll(local_14,0,uVar2);
  iVar3 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                    (param_1,local_14,0xca,2,local_20,param_2,0);
  if (iVar3 == 0) {
    ___11WriteBuffer(local_14,2);
    uVar2 = 0;
  }
  else {
    uVar4 = readShort__10ReadBufferPs(local_20,&local_22);
    uVar5 = readUShort__10ReadBufferPUs(local_20,&local_24);
    uVar2 = getTheRest__10ReadBufferPUl(local_20,&local_28);
    if ((((uVar4 & 1 & uVar5) == 0) || (local_22 != 0)) || (local_24 != local_28)) {
      Error_Printf__11AuthRequestiPce(param_1,2,"Error in public key block message.");
      ___11WriteBuffer(local_14,2);
      uVar2 = 0;
    }
    else {
      if (*(int *)(param_1 + 0x802c) != 0) {
        DeleteAuthPublicKeyBlock1__15WON_AuthFactoryP23WON_AuthPublicKeyBlock1
                  (*(undefined4 *)(param_1 + 0x802c));
      }
      iVar3 = NewAuthPublicKeyBlock1__15WON_AuthFactoryPCUcUs(uVar2,local_24);
      *(int *)(param_1 + 0x802c) = iVar3;
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("mPublicKeyBlock","/e/quiver/goldsrc/common/authrequest.cpp",0x15b,
                      "int AuthRequest::getPublicKeys(class EasyTitanSocket *)");
      }
      if (*(int *)(param_1 + 0x803c) == 0) {
        Error_Printf__11AuthRequestiPce(param_1,2,"Error: need auth verifier key.");
        ___11WriteBuffer(local_14,2);
        uVar2 = 0;
      }
      else {
        uVar1 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x803c));
        uVar2 = GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x803c),uVar1);
        iVar3 = Verify__C20WON_AuthFamilyBufferPCUcUs(*(undefined4 *)(param_1 + 0x802c),uVar2);
        if (iVar3 == 0) {
          Error_Printf__11AuthRequestiPce(param_1,2,"Verification of public key block failed.");
          ___11WriteBuffer(local_14,2);
          uVar2 = 0;
        }
        else {
          ___11WriteBuffer(local_14,2);
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}


