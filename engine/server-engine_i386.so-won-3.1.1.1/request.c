// request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl  @ 000d06d4
/* WARNING: Type propagation algorithm not settling */

undefined4
request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
          (int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  size_t __n;
  void *__src;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_70;
  short local_4e;
  undefined1 local_4c [12];
  undefined1 local_40 [12];
  undefined1 local_34 [3];
  char cStack_31;
  undefined1 local_30 [4];
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20 [2];
  undefined1 local_18 [16];
  int local_8;
  
  __11WriteBufferUl(local_18,0x100);
  iVar2 = handleAuth__12TitanRequestP15EasyTitanSocketP11WriteBufferT2Ul
                    (param_1,param_6,local_18,param_2,param_7);
  if (iVar2 == 0) {
    ___11WriteBuffer(local_18,2);
    uVar3 = 0;
  }
  else {
    uVar7 = 1000;
    uVar6 = 0;
    uVar3 = getSize__C11WriteBuffer(local_18);
    uVar4 = getBuffer__C11WriteBuffer(local_18);
    local_8 = sendBuffer__10EasySocketPCviPii(param_6,uVar4,uVar3,uVar6,uVar7);
    local_20[1] = 0;
    cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_8,local_20 + 1);
    if (cVar1 == '\0') {
      local_8 = recvTMessage__15EasyTitanSocketPcPUlN22i(param_6,param_1 + 8,local_20,0,0,8000);
      if (local_8 == 0x3f4) {
        printf("Timed out.\n");
        ___11WriteBuffer(local_18,2);
        uVar3 = 0;
      }
      else {
        local_2c = 0;
        cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_8,&local_2c);
        if (cVar1 == '\0') {
          setBuffer__10ReadBufferPCcUl(param_5,param_1 + 0xc,local_20[0] + -4);
          readUByte__10ReadBufferPUc(param_5,&cStack_31);
          if (*(int *)(param_1 + 0x8010) != 0) {
            if (cStack_31 == '\x01') {
              printf("Session key has expired...\n");
              DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                        (*(undefined4 *)(param_1 + 0x8020));
              *(undefined4 *)(param_1 + 0x8020) = 0;
              ___11WriteBuffer(local_18,2);
              return 0;
            }
            readUShort__10ReadBufferPUs(param_5,local_34);
            if ((short)_local_34 != *(short *)(param_1 + 0x8018)) {
              printf("Invalid session Id received.\n");
              ___11WriteBuffer(local_18,2);
              return 0;
            }
          }
          if (cStack_31 == '\x02') {
            if (*(int *)(param_1 + 0x8014) == 0) {
              printf("Error: Received encrypted message on unencrypted channel.\n");
              ___11WriteBuffer(local_18,2);
              return 0;
            }
            __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_40,0,0);
            uStack_70 = getRemainingSize__10ReadBuffer(param_5);
            uVar3 = getDataPtr__10ReadBuffer(param_5);
            Decrypt__18WON_BFSymmetricKeyPCUcUl(local_4c,*(undefined4 *)(param_1 + 0x8020),uVar3);
            __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                      (local_40,local_4c);
            ___Q216WON_CryptKeyBase11CryptReturn(local_4c,2);
            iVar2 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_40);
            if (iVar2 == 0) {
              uVar3 = GetLastError__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8020));
              printf("Error decrypting message: %s\n",uVar3);
              ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
              ___11WriteBuffer(local_18,2);
              return 0;
            }
            __n = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_40);
            __src = (void *)GetData__CQ216WON_CryptKeyBase11CryptReturn(local_40);
            memcpy((void *)(param_1 + 8),__src,__n);
            uVar3 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_40);
            setBuffer__10ReadBufferPCcUl(param_5,param_1 + 8,uVar3);
            ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
            puVar5 = &uStack_70;
          }
          else {
            setBuffer__10ReadBufferPCcUl(param_5,param_1 + 0xc,local_20[0] + -4);
            puVar5 = (undefined4 *)&stack0xffffff94;
          }
          if (*(int *)(param_1 + 0x800c) != 0) {
            *(short **)((int)puVar5 + -0xc) = &local_4e;
            *(undefined4 *)((int)puVar5 + -0x10) = param_5;
            *(undefined4 *)((int)puVar5 + -0x14) = 0xd0b2f;
            iVar2 = readUShort__10ReadBufferPUs();
            if ((iVar2 == 0) || (local_4e != *(short *)(param_1 + 0x801c))) {
              *(char **)((int)puVar5 + -0x10) = "Invalid sequence number received.\n";
              *(undefined4 *)((int)puVar5 + -0x14) = 0xd0b55;
              printf(*(char **)((int)puVar5 + -0x10));
              *(undefined4 *)((int)puVar5 + -0xc) = 2;
              *(undefined1 **)((int)puVar5 + -0x10) = local_18;
              *(undefined4 *)((int)puVar5 + -0x14) = 0xd0b66;
              ___11WriteBuffer();
              return 0;
            }
            *(short *)(param_1 + 0x801c) = *(short *)(param_1 + 0x801c) + 1;
          }
          if (param_3 == 0) {
            *(undefined4 *)((int)puVar5 + -0xc) = 2;
            *(undefined1 **)((int)puVar5 + -0x10) = local_18;
            *(undefined4 *)((int)puVar5 + -0x14) = 0xd0b8b;
            ___11WriteBuffer();
            uVar3 = 1;
          }
          else {
            *(int **)((int)puVar5 + -0xc) = &local_24;
            *(undefined4 *)((int)puVar5 + -0x10) = param_5;
            *(undefined4 *)((int)puVar5 + -0x14) = 0xd0ba8;
            iVar2 = readULong__10ReadBufferPUl();
            if (iVar2 == 0) {
              *(char **)((int)puVar5 + -0x10) = "Error: no service type.\n";
              *(undefined4 *)((int)puVar5 + -0x14) = 0xd0bbe;
              printf(*(char **)((int)puVar5 + -0x10));
              *(undefined4 *)((int)puVar5 + -0xc) = 2;
              *(undefined1 **)((int)puVar5 + -0x10) = local_18;
              *(undefined4 *)((int)puVar5 + -0x14) = 0xd0bcf;
              ___11WriteBuffer();
              uVar3 = 0;
            }
            else if (local_24 == param_3) {
              if (param_4 == 0) {
                *(undefined4 *)((int)puVar5 + -0xc) = 2;
                *(undefined1 **)((int)puVar5 + -0x10) = local_18;
                *(undefined4 *)((int)puVar5 + -0x14) = 0xd0c20;
                ___11WriteBuffer();
                uVar3 = 1;
              }
              else {
                *(int **)((int)puVar5 + -0xc) = &local_28;
                *(undefined4 *)((int)puVar5 + -0x10) = param_5;
                *(undefined4 *)((int)puVar5 + -0x14) = 0xd0c40;
                iVar2 = readULong__10ReadBufferPUl();
                if (iVar2 == 0) {
                  *(char **)((int)puVar5 + -0x10) = "Error: no message type.\n";
                  *(undefined4 *)((int)puVar5 + -0x14) = 0xd0c56;
                  printf(*(char **)((int)puVar5 + -0x10));
                  *(undefined4 *)((int)puVar5 + -0xc) = 2;
                  *(undefined1 **)((int)puVar5 + -0x10) = local_18;
                  *(undefined4 *)((int)puVar5 + -0x14) = 0xd0c67;
                  ___11WriteBuffer();
                  uVar3 = 0;
                }
                else if (local_28 == param_4) {
                  *(undefined4 *)((int)puVar5 + -0xc) = 2;
                  *(undefined1 **)((int)puVar5 + -0x10) = local_18;
                  *(undefined4 *)((int)puVar5 + -0x14) = 0xd0cb2;
                  ___11WriteBuffer();
                  uVar3 = 1;
                }
                else {
                  *(char **)((int)puVar5 + -0x10) = "Invalid message type received from server.\n";
                  *(undefined4 *)((int)puVar5 + -0x14) = 0xd0c89;
                  printf(*(char **)((int)puVar5 + -0x10));
                  *(undefined4 *)((int)puVar5 + -0xc) = 2;
                  *(undefined1 **)((int)puVar5 + -0x10) = local_18;
                  *(undefined4 *)((int)puVar5 + -0x14) = 0xd0c9a;
                  ___11WriteBuffer();
                  uVar3 = 0;
                }
              }
            }
            else {
              *(char **)((int)puVar5 + -0x10) = "Invalid service type received from server.\n";
              *(undefined4 *)((int)puVar5 + -0x14) = 0xd0bf1;
              printf(*(char **)((int)puVar5 + -0x10));
              *(undefined4 *)((int)puVar5 + -0xc) = 2;
              *(undefined1 **)((int)puVar5 + -0x10) = local_18;
              *(undefined4 *)((int)puVar5 + -0x14) = 0xd0c02;
              ___11WriteBuffer();
              uVar3 = 0;
            }
          }
        }
        else {
          ES_ErrorTypeToString__F12ES_ErrorType(local_30,local_8);
          uVar3 = c_str__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                            (local_30);
          printf("Socket error: %s\n",uVar3);
          ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (local_30,2);
          ___11WriteBuffer(local_18,2);
          uVar3 = 0;
        }
      }
    }
    else {
      printf("Error sending message to server.\n");
      ___11WriteBuffer(local_18,2);
      uVar3 = 0;
    }
  }
  return uVar3;
}


// request__12TitanRequestP11WriteBufferUlUlP10ReadBufferUl  @ 000d0dc8
bool request__12TitanRequestP11WriteBufferUlUlP10ReadBufferUl
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined1 local_30 [44];
  
  __15EasyTitanSocketQ210EasySocket10SocketTypeUl(local_30,1,0x8000);
  for (local_38 = 0; local_38 < 3; local_38 = local_38 + 1) {
    if (0 < local_38) {
      printf("Retrying...\n");
    }
    local_34 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                         (local_30,param_1,*(undefined4 *)(param_1 + 4),5000,1);
    local_3c = 0;
    cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_34,&local_3c);
    if (cVar1 == '\0') {
      iVar2 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                        (param_1,param_2,param_3,param_4,param_5,local_30,0);
      if (iVar2 != 0) break;
    }
    else {
      printf("Error connecting to server.\n");
    }
  }
  iVar2 = local_38;
  if (local_38 < 3) {
    ___15EasyTitanSocket(local_30,2);
  }
  else {
    ___15EasyTitanSocket(local_30,2);
  }
  return iVar2 < 3;
}


