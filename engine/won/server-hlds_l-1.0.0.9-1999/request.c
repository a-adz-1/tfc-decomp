// request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl  @ 08095430
undefined4
request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
          (int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  undefined4 *__ptr;
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  int local_48;
  int local_44;
  short local_3e [2];
  char cStack_39;
  undefined1 local_38 [4];
  undefined1 local_34 [12];
  void *local_28;
  size_t local_24;
  undefined *local_18;
  undefined1 local_14 [16];
  
  gcc2_compiled_(local_14);
  iVar2 = handleAuth__12TitanRequestP15EasyTitanSocketP11WriteBufferT2Ul
                    (param_1,param_6,local_14,param_2,param_7);
  if (iVar2 == 0) {
    ___11WriteBuffer(local_14);
    uVar3 = 0;
  }
  else {
    uVar3 = getSize__C11WriteBuffer(local_14,0);
    uVar3 = getBuffer__C11WriteBuffer(local_14,uVar3);
    iVar2 = sendBuffer__10EasySocketPCviPii(param_6,uVar3);
    if (iVar2 == 0) {
      iVar2 = recvTMessage__15EasyTitanSocketPcPUlN22i(param_6,param_1 + 8,local_38,0,0);
      if (iVar2 == 0x3f4) {
        printf("Timed out.\n");
        ___11WriteBuffer(local_14,2);
        uVar3 = 0;
      }
      else if (iVar2 == 0) {
        setBuffer__10ReadBufferPCcUl(param_5,param_1 + 0xc);
        readUByte__10ReadBufferPUc(param_5,&cStack_39);
        if (*(int *)(param_1 + 0x8010) != 0) {
          if (cStack_39 == '\x01') {
            printf("Session key has expired...\n");
            DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                      (*(undefined4 *)(param_1 + 0x8020));
            *(undefined4 *)(param_1 + 0x8020) = 0;
            ___11WriteBuffer(local_14,2);
            return 0;
          }
          readUShort__10ReadBufferPUs(param_5);
          if ((short)stack0xffffffc4 != *(short *)(param_1 + 0x8018)) {
            printf("Invalid session Id received.\n");
            ___11WriteBuffer(local_14,2);
            return 0;
          }
        }
        if (cStack_39 == '\x02') {
          if (*(int *)(param_1 + 0x8014) == 0) {
            printf("Error: Received encrypted message on unencrypted channel.\n");
            ___11WriteBuffer(local_14,2);
            return 0;
          }
          __Q216WON_CryptKeyBase11CryptReturnPUcUl(&local_28,0);
          uVar3 = getRemainingSize__10ReadBuffer(param_5);
          uVar3 = getDataPtr__10ReadBuffer(param_5,uVar3);
          Decrypt__18WON_BFSymmetricKeyPCUcUl(local_34,*(undefined4 *)(param_1 + 0x8020),uVar3);
          __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                    (&local_28,local_34);
          ___Q216WON_CryptKeyBase11CryptReturn(local_34,2);
          if (local_28 == (void *)0x0) {
            printf("Error decrypting message: %s\n",**(undefined4 **)(param_1 + 0x8020));
            ___Q216WON_CryptKeyBase11CryptReturn(&local_28,2);
            ___11WriteBuffer(local_14,2);
            return 0;
          }
          memcpy((void *)(param_1 + 8),local_28,local_24);
          setBuffer__10ReadBufferPCcUl(param_5,(void *)(param_1 + 8),local_24);
          ___Q216WON_CryptKeyBase11CryptReturn(&local_28,2);
          puVar5 = &stack0xffffffa8;
        }
        else {
          setBuffer__10ReadBufferPCcUl(param_5,param_1 + 0xc);
          puVar5 = &stack0xffffffac;
        }
        if (*(int *)(param_1 + 0x800c) != 0) {
          *(short **)(puVar5 + -4) = local_3e;
          *(undefined4 *)(puVar5 + -8) = param_5;
          *(undefined4 *)(puVar5 + -0xc) = 0x80957ed;
          iVar2 = readUShort__10ReadBufferPUs();
          if ((iVar2 == 0) || (local_3e[0] != *(short *)(param_1 + 0x801c))) {
            *(char **)(puVar5 + -4) = "Invalid sequence number received.\n";
            *(undefined4 *)(puVar5 + -8) = 0x809580b;
            printf(*(char **)(puVar5 + -4));
            *(undefined4 *)(puVar5 + -8) = 2;
            *(undefined1 **)(puVar5 + -0xc) = local_14;
            *(undefined4 *)(puVar5 + -0x10) = 0x8095816;
            ___11WriteBuffer();
            return 0;
          }
          *(short *)(param_1 + 0x801c) = *(short *)(param_1 + 0x801c) + 1;
        }
        if (param_3 == 0) {
          *(undefined4 *)(puVar5 + -4) = 2;
          *(undefined1 **)(puVar5 + -8) = local_14;
          *(undefined4 *)(puVar5 + -0xc) = 0x8095838;
          ___11WriteBuffer();
          uVar3 = 1;
        }
        else {
          *(int **)(puVar5 + -4) = &local_44;
          *(undefined4 *)(puVar5 + -8) = param_5;
          *(undefined4 *)(puVar5 + -0xc) = 0x809585d;
          iVar2 = readULong__10ReadBufferPUl();
          if (iVar2 == 0) {
            *(char **)(puVar5 + -4) = "Error: no service type.\n";
            *(undefined4 *)(puVar5 + -8) = 0x809586e;
            printf(*(char **)(puVar5 + -4));
            *(undefined4 *)(puVar5 + -8) = 2;
            *(undefined1 **)(puVar5 + -0xc) = local_14;
            *(undefined4 *)(puVar5 + -0x10) = 0x8095879;
            ___11WriteBuffer();
            uVar3 = 0;
          }
          else if (local_44 == param_3) {
            if (param_4 == 0) {
              *(undefined4 *)(puVar5 + -4) = 2;
              *(undefined1 **)(puVar5 + -8) = local_14;
              *(undefined4 *)(puVar5 + -0xc) = 0x80958c1;
              ___11WriteBuffer();
              uVar3 = 1;
            }
            else {
              *(int **)(puVar5 + -4) = &local_48;
              *(undefined4 *)(puVar5 + -8) = param_5;
              *(undefined4 *)(puVar5 + -0xc) = 0x80958dd;
              iVar2 = readULong__10ReadBufferPUl();
              if (iVar2 == 0) {
                *(char **)(puVar5 + -4) = "Error: no message type.\n";
                *(undefined4 *)(puVar5 + -8) = 0x80958ee;
                printf(*(char **)(puVar5 + -4));
                *(undefined4 *)(puVar5 + -8) = 2;
                *(undefined1 **)(puVar5 + -0xc) = local_14;
                *(undefined4 *)(puVar5 + -0x10) = 0x80958f9;
                ___11WriteBuffer();
                uVar3 = 0;
              }
              else if (local_48 == param_4) {
                *(undefined4 *)(puVar5 + -4) = 2;
                *(undefined1 **)(puVar5 + -8) = local_14;
                *(undefined4 *)(puVar5 + -0xc) = 0x809593b;
                ___11WriteBuffer();
                uVar3 = 1;
              }
              else {
                *(char **)(puVar5 + -4) = "Invalid message type received from server.\n";
                *(undefined4 *)(puVar5 + -8) = 0x8095912;
                printf(*(char **)(puVar5 + -4));
                *(undefined4 *)(puVar5 + -8) = 2;
                *(undefined1 **)(puVar5 + -0xc) = local_14;
                *(undefined4 *)(puVar5 + -0x10) = 0x809591d;
                ___11WriteBuffer();
                uVar3 = 0;
              }
            }
          }
          else {
            *(char **)(puVar5 + -4) = "Invalid service type received from server.\n";
            *(undefined4 *)(puVar5 + -8) = 0x8095892;
            printf(*(char **)(puVar5 + -4));
            *(undefined4 *)(puVar5 + -8) = 2;
            *(undefined1 **)(puVar5 + -0xc) = local_14;
            *(undefined4 *)(puVar5 + -0x10) = 0x809589d;
            ___11WriteBuffer();
            uVar3 = 0;
          }
        }
      }
      else {
        ES_ErrorTypeToString__F12ES_ErrorType(&local_18);
        if (*(int *)(local_18 + -0x10) == 0) {
          puVar4 = &DAT_080a91ce;
        }
        else {
          local_18[*(int *)(local_18 + -0x10)] = 0;
          puVar4 = local_18;
        }
        printf("Socket error: %s\n",puVar4);
        __ptr = (undefined4 *)(local_18 + -0x10);
        piVar1 = (int *)(local_18 + -8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          if (*(int *)(local_18 + -0xc) + 0x10U < 0x81) {
            iVar2 = (*(int *)(local_18 + -0xc) + 0x17U >> 3) * 4;
            pthread_mutex_lock((pthread_mutex_t *)
                               _t24__default_alloc_template2b1i0___node_allocator_lock);
            *__ptr = *(undefined4 *)(&DAT_080ab95c + iVar2);
            *(undefined4 **)(&DAT_080ab95c + iVar2) = __ptr;
            pthread_mutex_unlock
                      ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
          }
          else {
            free(__ptr);
          }
        }
        ___11WriteBuffer(local_14,2);
        uVar3 = 0;
      }
    }
    else {
      printf("Error sending message to server.\n");
      ___11WriteBuffer(local_14,2);
      uVar3 = 0;
    }
  }
  return uVar3;
}


// request__12TitanRequestP11WriteBufferUlUlP10ReadBufferUl  @ 08095a50
bool request__12TitanRequestP11WriteBufferUlUlP10ReadBufferUl
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [44];
  
  __15EasyTitanSocketQ210EasySocket10SocketTypeUl(local_30,1,0x8000);
  iVar2 = 0;
  do {
    if (0 < iVar2) {
      printf("Retrying...\n");
    }
    iVar1 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                      (local_30,param_1,*(undefined4 *)(param_1 + 4),5000,1);
    if (iVar1 == 0) {
      iVar1 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                        (param_1,param_2,param_3,param_4,param_5,local_30,0);
      if (iVar1 != 0) break;
    }
    else {
      printf("Error connecting to server.\n");
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  if (iVar2 < 3) {
    ___15EasyTitanSocket(local_30,2);
  }
  else {
    ___15EasyTitanSocket(local_30,2);
  }
  return iVar2 < 3;
}


