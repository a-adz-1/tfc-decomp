// request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl  @ 00098144
undefined4
request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
          (int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  void *__dest;
  undefined1 *puVar4;
  int local_48;
  int local_44;
  short local_3e;
  short local_3c;
  char local_39;
  undefined1 local_38 [4];
  undefined1 local_34 [12];
  void *local_28;
  size_t local_24;
  undefined *local_18;
  undefined1 local_14 [16];
  
  __11WriteBufferUl(local_14);
  iVar1 = handleAuth__12TitanRequestP15EasyTitanSocketP11WriteBufferT2Ul
                    (param_1,param_6,local_14,param_2,param_7);
  if (iVar1 == 0) {
    ___11WriteBuffer(local_14);
    uVar2 = 0;
  }
  else {
    uVar2 = getSize__C11WriteBuffer(local_14,0);
    uVar2 = getBuffer__C11WriteBuffer(local_14,uVar2);
    iVar1 = sendBuffer__10EasySocketPCviPii(param_6,uVar2);
    if (iVar1 == 0) {
      __dest = (void *)(param_1 + 8);
      iVar1 = recvTMessage__15EasyTitanSocketPcPUlN22i(param_6,__dest,local_38,0,0);
      if (iVar1 == 0x3f4) {
        printf("Timed out.\n");
        ___11WriteBuffer(local_14,2);
        uVar2 = 0;
      }
      else if (iVar1 == 0) {
        setBuffer__10ReadBufferPCcUl(param_5,param_1 + 0xc);
        readUByte__10ReadBufferPUc(param_5,&local_39);
        if (*(int *)(param_1 + 0x8010) != 0) {
          if (local_39 == '\x01') {
            printf("Session key has expired...\n");
            DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                      (*(undefined4 *)(param_1 + 0x8020));
            *(undefined4 *)(param_1 + 0x8020) = 0;
            ___11WriteBuffer(local_14,2);
            return 0;
          }
          readUShort__10ReadBufferPUs(param_5);
          if (local_3c != *(short *)(param_1 + 0x8018)) {
            printf("Invalid session Id received.\n");
            ___11WriteBuffer(local_14,2);
            return 0;
          }
        }
        if (local_39 == '\x02') {
          if (*(int *)(param_1 + 0x8014) == 0) {
            printf("Error: Received encrypted message on unencrypted channel.\n");
            ___11WriteBuffer(local_14,2);
            return 0;
          }
          __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_28,0);
          uVar2 = getRemainingSize__10ReadBuffer(param_5);
          uVar2 = getDataPtr__10ReadBuffer(param_5,uVar2);
          Decrypt__18WON_BFSymmetricKeyPCUcUl(local_34,*(undefined4 *)(param_1 + 0x8020),uVar2);
          __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                    (&local_28,local_34);
          ___Q216WON_CryptKeyBase11CryptReturn(local_34,2);
          if (local_28 == (void *)0x0) {
            printf("Error decrypting message: %s\n",**(undefined4 **)(param_1 + 0x8020));
            ___Q216WON_CryptKeyBase11CryptReturn(&local_28,2);
            ___11WriteBuffer(local_14,2);
            return 0;
          }
          memcpy(__dest,local_28,local_24);
          setBuffer__10ReadBufferPCcUl(param_5,__dest,local_24);
          ___Q216WON_CryptKeyBase11CryptReturn(&local_28,2);
          puVar4 = &stack0xffffff98;
        }
        else {
          setBuffer__10ReadBufferPCcUl(param_5,param_1 + 0xc);
          puVar4 = &stack0xffffff9c;
        }
        if (*(int *)(param_1 + 0x800c) != 0) {
          *(short **)(puVar4 + -4) = &local_3e;
          *(undefined4 *)(puVar4 + -8) = param_5;
          *(undefined4 *)(puVar4 + -0xc) = 0x984ad;
          iVar1 = readUShort__10ReadBufferPUs();
          if ((iVar1 == 0) || (local_3e != *(short *)(param_1 + 0x801c))) {
            *(char **)(puVar4 + -4) = "Invalid sequence number received.\n";
            *(undefined4 *)(puVar4 + -8) = 0x984ce;
            printf(*(char **)(puVar4 + -4));
            *(undefined4 *)(puVar4 + -8) = 2;
            *(undefined1 **)(puVar4 + -0xc) = local_14;
            *(undefined4 *)(puVar4 + -0x10) = 0x984d6;
            ___11WriteBuffer();
            return 0;
          }
          *(short *)(param_1 + 0x801c) = local_3e + 1;
        }
        if (param_3 == 0) {
          *(undefined4 *)(puVar4 + -4) = 2;
          *(undefined1 **)(puVar4 + -8) = local_14;
          *(undefined4 *)(puVar4 + -0xc) = 0x984f9;
          ___11WriteBuffer();
          uVar2 = 1;
        }
        else {
          *(int **)(puVar4 + -4) = &local_44;
          *(undefined4 *)(puVar4 + -8) = param_5;
          *(undefined4 *)(puVar4 + -0xc) = 0x98511;
          iVar1 = readULong__10ReadBufferPUl();
          if (iVar1 == 0) {
            *(char **)(puVar4 + -4) = "Error: no service type.\n";
            *(undefined4 *)(puVar4 + -8) = 0x98522;
            printf(*(char **)(puVar4 + -4));
            *(undefined4 *)(puVar4 + -8) = 2;
            *(undefined1 **)(puVar4 + -0xc) = local_14;
            *(undefined4 *)(puVar4 + -0x10) = 0x9852a;
            ___11WriteBuffer();
            uVar2 = 0;
          }
          else if (local_44 == param_3) {
            if (param_4 == 0) {
              *(undefined4 *)(puVar4 + -4) = 2;
              *(undefined1 **)(puVar4 + -8) = local_14;
              *(undefined4 *)(puVar4 + -0xc) = 0x98566;
              ___11WriteBuffer();
              uVar2 = 1;
            }
            else {
              *(int **)(puVar4 + -4) = &local_48;
              *(undefined4 *)(puVar4 + -8) = param_5;
              *(undefined4 *)(puVar4 + -0xc) = 0x9857d;
              iVar1 = readULong__10ReadBufferPUl();
              if (iVar1 == 0) {
                *(char **)(puVar4 + -4) = "Error: no message type.\n";
                *(undefined4 *)(puVar4 + -8) = 0x9858e;
                printf(*(char **)(puVar4 + -4));
                *(undefined4 *)(puVar4 + -8) = 2;
                *(undefined1 **)(puVar4 + -0xc) = local_14;
                *(undefined4 *)(puVar4 + -0x10) = 0x98596;
                ___11WriteBuffer();
                uVar2 = 0;
              }
              else if (local_48 == param_4) {
                *(undefined4 *)(puVar4 + -4) = 2;
                *(undefined1 **)(puVar4 + -8) = local_14;
                *(undefined4 *)(puVar4 + -0xc) = 0x985cc;
                ___11WriteBuffer();
                uVar2 = 1;
              }
              else {
                *(char **)(puVar4 + -4) = "Invalid message type received from server.\n";
                *(undefined4 *)(puVar4 + -8) = 0x985b2;
                printf(*(char **)(puVar4 + -4));
                *(undefined4 *)(puVar4 + -8) = 2;
                *(undefined1 **)(puVar4 + -0xc) = local_14;
                *(undefined4 *)(puVar4 + -0x10) = 0x985ba;
                ___11WriteBuffer();
                uVar2 = 0;
              }
            }
          }
          else {
            *(char **)(puVar4 + -4) = "Invalid service type received from server.\n";
            *(undefined4 *)(puVar4 + -8) = 0x98546;
            printf(*(char **)(puVar4 + -4));
            *(undefined4 *)(puVar4 + -8) = 2;
            *(undefined1 **)(puVar4 + -0xc) = local_14;
            *(undefined4 *)(puVar4 + -0x10) = 0x9854e;
            ___11WriteBuffer();
            uVar2 = 0;
          }
        }
      }
      else {
        ES_ErrorTypeToString__F12ES_ErrorType(&local_18);
        if (*(int *)(local_18 + -0x10) == 0) {
          puVar3 = &DAT_000afa4e;
        }
        else {
          local_18[*(int *)(local_18 + -0x10)] = 0;
          puVar3 = local_18;
        }
        printf("Socket error: %s\n",puVar3);
        iVar1 = *(int *)(local_18 + -8);
        *(int *)(local_18 + -8) = iVar1 + -1;
        if (iVar1 == 1) {
          if (*(int *)(local_18 + -0xc) + 0x10U < 0x81) {
            iVar1 = (*(int *)(local_18 + -0xc) + 0x17U >> 3) * 4;
            pthread_mutex_lock((pthread_mutex_t *)
                               _t24__default_alloc_template2b1i0___node_allocator_lock);
            *(undefined4 *)(local_18 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar1);
            *(undefined **)(&DAT_000b3e5c + iVar1) = local_18 + -0x10;
            pthread_mutex_unlock
                      ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
          }
          else {
            free(local_18 + -0x10);
          }
        }
        ___11WriteBuffer(local_14,2);
        uVar2 = 0;
      }
    }
    else {
      printf("Error sending message to server.\n");
      ___11WriteBuffer(local_14,2);
      uVar2 = 0;
    }
  }
  return uVar2;
}


// request__12TitanRequestP11WriteBufferUlUlP10ReadBufferUl  @ 0009869c
bool request__12TitanRequestP11WriteBufferUlUlP10ReadBufferUl
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_30 [44];
  
  __15EasyTitanSocketQ210EasySocket10SocketTypeUl(local_30,1,0x8000);
  iVar3 = 0;
  iVar1 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                    (local_30,param_1,*(undefined4 *)(param_1 + 4),5000,1);
  if (iVar1 == 0) {
    iVar1 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                      (param_1,param_2,param_3,param_4,param_5,local_30,0);
    if (iVar1 != 0) goto LAB_000987e1;
  }
  else {
    printf("Error connecting to server.\n");
  }
  iVar1 = 1;
  do {
    if (0 < iVar1) {
      printf("Retrying...\n");
    }
    iVar3 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                      (local_30,param_1,*(undefined4 *)(param_1 + 4),5000,1);
    if (iVar3 == 0) {
      iVar2 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                        (param_1,param_2,param_3,param_4,param_5,local_30,0);
      iVar3 = iVar1;
      if (iVar2 != 0) break;
    }
    else {
      printf("Error connecting to server.\n");
    }
    if (0 < iVar1 + 1) {
      printf("Retrying...\n");
    }
    iVar3 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                      (local_30,param_1,*(undefined4 *)(param_1 + 4),5000,1);
    if (iVar3 == 0) {
      iVar2 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                        (param_1,param_2,param_3,param_4,param_5,local_30,0);
      iVar3 = iVar1 + 1;
      if (iVar2 != 0) break;
    }
    else {
      printf("Error connecting to server.\n");
    }
    iVar1 = iVar1 + 2;
    iVar3 = iVar1;
  } while (iVar1 < 3);
LAB_000987e1:
  if (iVar3 < 3) {
    ___15EasyTitanSocket(local_30,2);
  }
  else {
    ___15EasyTitanSocket(local_30,2);
  }
  return iVar3 < 3;
}


