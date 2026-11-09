// Key_Bind_f  @ 001b5370
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Bind_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  keyname_t *pkVar6;
  int in_GS_OFFSET;
  char local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: char[1024] cmd@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = Cmd_Argc();
  if (1 < iVar1 - 2U) {
    Con_Printf("bind <key> [command] : attach a command to a key\n");
    goto LAB_001b53bc;
  }
  pcVar2 = Cmd_Argv(1);
                    /* Unresolved local var: keyname_t * kn@[???] */
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    uVar5 = (uint)*pcVar2;
    if (pcVar2[1] == '\0') {
LAB_001b5426:
      if (uVar5 < 0x100) {
        if (iVar1 == 2) {
          pcVar2 = keybindings[uVar5];
          if (pcVar2 == (char *)0x0) {
            pcVar2 = Cmd_Argv(1);
            Con_Printf("\"%s\" is not bound\n",pcVar2);
          }
          else {
            pcVar3 = Cmd_Argv(1);
            Con_Printf("\"%s\" = \"%s\"\n",pcVar3,pcVar2);
          }
        }
        else {
          if (uVar5 == 0x1b) {
            Q_strcpy(local_420,"cancelselect");
          }
          else {
            local_420[0] = '\0';
            pcVar2 = Cmd_Argv(2);
            __strncat_chk(local_420,pcVar2,0x3ff,0x400);
          }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
          if (keybindings[uVar5] != (char *)0x0) {
            iVar1 = Q_strcmp(keybindings[uVar5],local_420);
            if (iVar1 == 0) goto LAB_001b53bc;
            Z_Free(keybindings[uVar5]);
            keybindings[uVar5] = (char *)0x0;
          }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
          iVar1 = Q_strlen(local_420);
          pcVar2 = Z_Malloc(iVar1 + 1);
          Q_strcpy(pcVar2,local_420);
          pcVar2[iVar1] = '\0';
          keybindings[uVar5] = pcVar2;
          iVar1 = strcasecmp(local_420,"toggleconsole");
          if (iVar1 == 0) {
            toggleconsole_key = uVar5;
          }
        }
        goto LAB_001b53bc;
      }
    }
    else {
                    /* Unresolved local var: keyname_t * kn@[???] */
      if (keynames[0].name != (char *)0x0) {
        pkVar6 = keynames;
        pcVar3 = keynames[0].name;
        do {
          iVar4 = Q_strcasecmp(pcVar2,pcVar3);
          if (iVar4 == 0) {
            uVar5 = pkVar6->keynum;
            goto LAB_001b5426;
          }
          pkVar6 = pkVar6 + 1;
          pcVar3 = pkVar6->name;
        } while (pcVar3 != (char *)0x0);
      }
    }
  }
  pcVar2 = Cmd_Argv(1);
  Con_Printf("\"%s\" isn\'t a valid key\n",pcVar2);
LAB_001b53bc:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Key_BindingForKey  @ 001b6a80
char * Key_BindingForKey(int keynum)

{
  if ((uint)keynum < 0x100) {
    return keybindings[keynum];
  }
  return (char *)0x0;
}


// Key_ClearStates  @ 001b6a20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_ClearStates(void)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???] */
  uVar2 = 0;
  do {
    *(undefined4 *)((int)keydown + uVar2) = 0;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)keydown + uVar2 + 4) = 0;
    uVar2 = uVar1;
  } while (uVar1 < 0x400);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)keyGameUIdown + uVar2) = 0;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)keyGameUIdown + uVar2 + 4) = 0;
    uVar2 = uVar1;
  } while (uVar1 < 0x400);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)key_repeats + uVar2) = 0;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)key_repeats + uVar2 + 4) = 0;
    uVar2 = uVar1;
  } while (uVar1 < 0x400);
  return;
}


// Key_Console  @ 001b5840
void Key_Console(int key)

{
  return;
}


// Key_CountBindings  @ 001b5b80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Key_CountBindings(void)

{
  int iVar1;
  char **ppcVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  ppcVar2 = keybindings;
  iVar1 = 0;
  do {
    if (*ppcVar2 != (char *)0x0) {
      iVar1 = (iVar1 + 1) - (uint)(**ppcVar2 == '\0');
    }
    ppcVar2 = ppcVar2 + 1;
  } while (ppcVar2 != (char **)&key_linepos);
  return iVar1;
}


// Key_Escape_f  @ 001b52b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Escape_f(void)

{
  if ((giSubState & 0x10U) != 0) {
                    /* Unresolved local var: int giStateInfo@[???] */
    Cbuf_AddText("disconnect\n");
    giActive = 2;
    giStateInfo = 2;
    giSubState = 1;
    Cbuf_Execute();
    return;
  }
  if (key_dest != key_game) {
    if (key_dest != key_message) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Bad key_dest");
    }
                    /* Unresolved local var: qboolean bResetMessage@[???] */
    key_dest = key_game;
    chat_bufferlen = 0;
    chat_buffer[0] = '\0';
    Q_strcpy(message_type,"say");
    message_type_is_privileged = true;
    return;
  }
  VGuiWrap2_HideGameUI();
  giActive = 2;
  return;
}


// Key_Event  @ 001b6470
void Key_Event(int key,qboolean down)

{
  keyname_t *pkVar1;
  int iVar2;
  byte bVar3;
  char *pcVar4;
  keyname_t *pkVar5;
  qboolean qVar6;
  int in_GS_OFFSET;
  char *pcVar7;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: char * kb@[???]
                       Unresolved local var: char[1024] cmd@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (0xff < key) goto LAB_001b64a7;
  (*g_engdstAddrs.Key_Event)(&key,(int *)&down);
  keydown[key] = down;
  if (((keydown[0x85] != false) && (keydown[0x84] != false)) && (keydown[0x94] != false)) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("ctrl-alt-del pressed");
  }
  if (key_dest == key_game) {
    if ((down != false) || (keyGameUIdown[key] != false)) {
      iVar2 = ClientDLL_Key_Event((uint)(down != false),key,keybindings[key]);
      if (iVar2 == 0) {
        if (key_repeats[key] == 0) {
          if (down != false) {
            keyGameUIdown[key] = true;
            goto LAB_001b64a7;
          }
        }
        else if (down != false) goto LAB_001b64a7;
        key_repeats[key] = 0;
        keyGameUIdown[key] = false;
        goto LAB_001b64a7;
      }
      goto LAB_001b663e;
    }
LAB_001b6565:
    key_repeats[key] = 0;
    keyGameUIdown[key] = false;
    iVar2 = key;
    if (key == 0x86) {
      qVar6 = false;
LAB_001b6822:
      iVar2 = 0x86;
      shift_down = qVar6;
LAB_001b682d:
      if (qVar6 != false) goto LAB_001b66ae;
    }
    pcVar4 = keybindings[iVar2];
    if ((pcVar4 != (char *)0x0) && (*pcVar4 == '+')) {
      __snprintf_chk(local_410,0x400,1,0x400,&DAT_0026ef43,pcVar4 + 1,iVar2);
      Cbuf_AddText(local_410);
    }
    if (((key == keyshift[key]) || (pcVar4 = keybindings[keyshift[key]], pcVar4 == (char *)0x0)) ||
       (*pcVar4 != '+')) goto LAB_001b64a7;
    pcVar4 = pcVar4 + 1;
    pcVar7 = "-%s %i\n";
LAB_001b65cf:
    __snprintf_chk(local_410,0x400,1,0x400,pcVar7,pcVar4,key);
    Cbuf_AddText(local_410);
  }
  else {
LAB_001b663e:
    if (down == false) goto LAB_001b6565;
    iVar2 = key_repeats[key];
    bVar3 = 1;
    key_repeats[key] = iVar2 + 1;
    if (key - 0x95U < 0x14) {
      bVar3 = (byte)(0x82003 >> ((byte)(key - 0x95U) & 0x1f)) & 1 ^ 1;
    }
    if (((key & 0xffffff7fU) != 0x7f && 1 < iVar2 + 1) && (bVar3 != 0)) goto LAB_001b64a7;
    iVar2 = key;
    if (key < 200) {
      qVar6 = down;
      if (key != 0x86) goto LAB_001b66ae;
      goto LAB_001b6822;
    }
    if (keybindings[key] == (char *)0x0) {
                    /* Unresolved local var: keyname_t * kn@[???] */
      if (keynames[0].name == (char *)0x0) {
LAB_001b69ee:
        pcVar4 = "<UNKNOWN KEYNUM>";
      }
      else {
        pcVar4 = keynames[0].name;
        if (keynames[0].keynum != key) {
          pkVar5 = keynames;
          do {
            pcVar4 = pkVar5[1].name;
            if (pcVar4 == (char *)0x0) goto LAB_001b69ee;
            pkVar1 = pkVar5 + 1;
            pkVar5 = pkVar5 + 1;
          } while (pkVar1->keynum != key);
        }
      }
      Con_Printf("%s is unbound.\n",pcVar4);
      qVar6 = down;
      iVar2 = key;
      if (key == 0x86) goto LAB_001b6822;
      goto LAB_001b682d;
    }
LAB_001b66ae:
    if (((((byte)giSubState & 0x10) != 0) && (iVar2 != 0x1b)) ||
       ((iVar2 == 0x1b && ((key_dest == key_game && (iVar2 = VGui_GameUIKeyPressed(), iVar2 != 0))))
       )) goto LAB_001b64a7;
    if ((cls.demoplayback == false) ||
       (((cls.spectator != false || (down == false)) || (consolekeys[key] == false)))) {
      if (key_dest == key_menu) {
LAB_001b68bf:
        if (menubound[key] != false) {
LAB_001b67a9:
          pcVar4 = keybindings[key];
          if (pcVar4 == (char *)0x0) goto LAB_001b64a7;
          if (*pcVar4 != '+') {
            iVar2 = strncasecmp(pcVar4,"toggleconsole",4);
            if (((iVar2 != 0) || (keydown[0x86] == false)) || (con_shifttoggleconsole.value != 0.0))
            {
              Cbuf_AddText(pcVar4);
              Cbuf_AddText("\n");
            }
            goto LAB_001b64a7;
          }
          pcVar7 = "%s %i\n";
          goto LAB_001b65cf;
        }
      }
      else if ((key_dest == key_game) && ((con_forcedup == false || (consolekeys[key] == false))))
      goto LAB_001b67a9;
      if (down == false) goto LAB_001b64a7;
    }
    else {
      if (key_dest == key_game) {
        Con_ToggleConsole_f();
        goto LAB_001b64a7;
      }
      if (key_dest == key_menu) goto LAB_001b68bf;
    }
    if (shift_down != 0) {
      key = keyshift[key];
    }
    if (key_dest != key_game) {
      if (key_dest != key_message) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Bad key_dest");
      }
      Key_Message(key);
    }
  }
LAB_001b64a7:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Key_EventStub  @ 001b6a00
void Key_EventStub(int key,qboolean down)

{
  if (g_fUseDInput != false) {
    return;
  }
  Key_Event(key,down);
  return;
}


// Key_Init  @ 001b5d60
/* WARNING: Removing unreachable block (ram,0x001b63f7) */
/* WARNING: Removing unreachable block (ram,0x001b6428) */
/* WARNING: Removing unreachable block (ram,0x001b640a) */
/* WARNING: Removing unreachable block (ram,0x001b5dae) */
/* WARNING: Removing unreachable block (ram,0x001b5db7) */
/* WARNING: Removing unreachable block (ram,0x001b6419) */
/* WARNING: Removing unreachable block (ram,0x001b5dcb) */
/* WARNING: Removing unreachable block (ram,0x001b5de0) */
/* WARNING: Removing unreachable block (ram,0x001b5fb3) */
/* WARNING: Removing unreachable block (ram,0x001b5fc4) */
/* WARNING: Removing unreachable block (ram,0x001b643b) */
/* WARNING: Removing unreachable block (ram,0x001b5fd8) */
/* WARNING: Removing unreachable block (ram,0x001b5ff1) */
/* WARNING: Removing unreachable block (ram,0x001b644e) */
/* WARNING: Removing unreachable block (ram,0x001b63b0) */
/* WARNING: Removing unreachable block (ram,0x001b5e24) */
/* WARNING: Removing unreachable block (ram,0x001b5e38) */
/* WARNING: Removing unreachable block (ram,0x001b5e4c) */
/* WARNING: Removing unreachable block (ram,0x001b604c) */
/* WARNING: Removing unreachable block (ram,0x001b605b) */
/* WARNING: Removing unreachable block (ram,0x001b606a) */
/* WARNING: Removing unreachable block (ram,0x001b615c) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Init(void)

{
  char (*pacVar1) [256];
  char (*pacVar2) [256];
  uint uVar3;
  qboolean *pqVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
                    /* Unresolved local var: int i@[???] */
  pacVar1 = key_lines;
  do {
    (*pacVar1)[0] = 0x5d;
    pacVar2 = pacVar1 + 1;
    (*pacVar1)[1] = 0;
    pacVar1 = pacVar2;
  } while (pacVar2 != (char (*) [256])keyGameUIdown);
  key_linepos = 1;
  pqVar4 = consolekeys + 0x20;
  uVar3 = 0;
  do {
    uVar3 = uVar3 + 1;
    *pqVar4 = true;
    pqVar4[1] = true;
    pqVar4[2] = true;
    pqVar4[3] = true;
    pqVar4 = pqVar4 + 4;
  } while (uVar3 < 0x18);
  consolekeys[0xd] = true;
  consolekeys[0xa9] = true;
  consolekeys[9] = true;
  consolekeys[0x82] = true;
  consolekeys[0xa3] = true;
  consolekeys[0x83] = true;
  consolekeys[0x96] = true;
  consolekeys[0xa2] = true;
  consolekeys[0x95] = true;
  consolekeys[0xa8] = true;
  consolekeys[0x97] = true;
  consolekeys[0xa0] = true;
  consolekeys[0xac] = true;
  consolekeys[0xae] = true;
  consolekeys[0xad] = true;
  consolekeys[0xa4] = true;
  consolekeys[0xb0] = true;
  consolekeys[0xb1] = false;
  consolekeys[0xa5] = true;
  consolekeys[0x80] = true;
  consolekeys[0xa1] = true;
  consolekeys[0x81] = true;
  consolekeys[0xa7] = true;
  consolekeys[0x7f] = true;
  consolekeys[0x98] = true;
  consolekeys[0xa6] = true;
  consolekeys[0x86] = true;
  consolekeys[0x84] = true;
  consolekeys[0x20] = true;
  consolekeys[0x85] = true;
  consolekeys[0x60] = false;
  consolekeys[0x7e] = false;
  iVar6 = 0;
  iVar7 = 1;
  iVar8 = 2;
  iVar9 = 3;
  piVar5 = keyshift;
  uVar3 = 0;
  do {
    uVar3 = uVar3 + 1;
    *piVar5 = iVar6;
    piVar5[1] = iVar7;
    piVar5[2] = iVar8;
    piVar5[3] = iVar9;
    piVar5 = piVar5 + 4;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 4;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 4;
  } while (uVar3 < 0x40);
  keyshift[0x7a] = 0x5a;
  keyshift[0x79] = 0x59;
  keyshift[0x78] = 0x58;
  keyshift[0x77] = 0x57;
  keyshift[0x76] = 0x56;
  keyshift[0x75] = 0x55;
  keyshift[0x74] = 0x54;
  keyshift[0x73] = 0x53;
  keyshift[0x72] = 0x52;
  keyshift[0x71] = 0x51;
  keyshift[0x70] = 0x50;
  keyshift[0x6f] = 0x4f;
  keyshift[0x6e] = 0x4e;
  keyshift[0x6d] = 0x4d;
  keyshift[0x6c] = 0x4c;
  keyshift[0x6b] = 0x4b;
  keyshift[0x6a] = 0x4a;
  keyshift[0x69] = 0x49;
  keyshift[0x68] = 0x48;
  keyshift[0x67] = 0x47;
  keyshift[0x66] = 0x46;
  keyshift[0x65] = 0x45;
  keyshift[100] = 0x44;
  keyshift[99] = 0x43;
  keyshift[0x62] = 0x42;
  keyshift[0x61] = 0x41;
  keyshift[0x31] = 0x21;
  keyshift[0x38] = 0x2a;
  keyshift[0x39] = 0x28;
  keyshift[0x30] = 0x29;
  keyshift[0x2d] = 0x5f;
  keyshift[0x3d] = 0x2b;
  keyshift[0x2c] = 0x3c;
  keyshift[0x60] = 0x7e;
  keyshift[0x5c] = 0x7c;
  menubound[0x1b] = true;
  menubound[0x87] = true;
  menubound[0x88] = true;
  keyshift[0x32] = 0x40;
  keyshift[0x33] = 0x23;
  keyshift[0x34] = 0x24;
  keyshift[0x35] = 0x25;
  keyshift[0x36] = 0x5e;
  keyshift[0x37] = 0x26;
  menubound[0x89] = true;
  keyshift[0x2e] = 0x3e;
  keyshift[0x2f] = 0x3f;
  keyshift[0x3b] = 0x3a;
  keyshift[0x27] = 0x22;
  keyshift[0x5b] = 0x7b;
  keyshift[0x5d] = 0x7d;
  menubound[0x90] = true;
  menubound[0x8b] = true;
  menubound[0x8a] = true;
  menubound[0x8c] = true;
  menubound[0x8d] = true;
  menubound[0x8e] = true;
  menubound[0x8f] = true;
  menubound[0x91] = true;
  menubound[0x92] = true;
  Cmd_AddCommandWithFlags("bind",Key_Bind_f,8);
  Cmd_AddCommandWithFlags("unbind",Key_Unbind_f,8);
  Cmd_AddCommandWithFlags("unbindall",Key_Unbindall_f,8);
  Cmd_AddCommand("escape",Key_Escape_f);
  return;
}


// Key_KeynumToString  @ 001b5a40
char * Key_KeynumToString(int keynum)

{
  keyname_t *pkVar1;
  char *pcVar2;
  keyname_t *pkVar3;
  
                    /* Unresolved local var: keyname_t * kn@[???] */
  if (keynum == -1) {
    return "<KEY NOT FOUND>";
  }
  if (keynum - 0x21U < 0x5e) {
    Key_KeynumToString::tinystr[0] = (char)keynum;
    Key_KeynumToString::tinystr[1] = '\0';
    return Key_KeynumToString::tinystr;
  }
                    /* Unresolved local var: keyname_t * kn@[???] */
  if (keynames[0].name == (char *)0x0) {
LAB_001b5a7e:
    pcVar2 = "<UNKNOWN KEYNUM>";
  }
  else {
    pcVar2 = keynames[0].name;
    if (keynum != keynames[0].keynum) {
      pkVar3 = keynames;
      do {
        pcVar2 = pkVar3[1].name;
        if (pcVar2 == (char *)0x0) goto LAB_001b5a7e;
        pkVar1 = pkVar3 + 1;
        pkVar3 = pkVar3 + 1;
      } while (keynum != pkVar1->keynum);
    }
  }
  return pcVar2;
}


// Key_Message  @ 001b58a0
void Key_Message(int key)

{
  int iVar1;
  char *pcVar2;
  qboolean qVar3;
  code *pcVar4;
  
                    /* Unresolved local var: qboolean bResetMessage@[???] */
  if ((key == 0xd) || (key == 0xa9)) {
    pcVar2 = chat_buffer;
    do {
      if (*pcVar2 == '\0') break;
      if (*pcVar2 == ';') {
        *pcVar2 = ',';
      }
                    /* Unresolved local var: char * temp@[???] */
      pcVar2 = pcVar2 + 1;
    } while (pcVar2 != (char *)0x0);
                    /* Unresolved local var: _func_void_char_ptr * pfnAddText@[???] */
    pcVar4 = Cbuf_AddFilteredText;
    if (message_type_is_privileged != false) {
      pcVar4 = Cbuf_AddText;
    }
    (*pcVar4)(message_type);
    (*pcVar4)(&DAT_0026eee3);
    (*pcVar4)(chat_buffer);
    (*pcVar4)(&DAT_0026ef14);
  }
  else if (key != 0x1b) {
    if (key != 0x7f) {
      return;
    }
    if (chat_bufferlen == 0) {
      return;
    }
                    /* Unresolved local var: char * pTruncPoint@[???]
                       Unresolved local var: int nStrLen@[???] */
    iVar1 = Q_UnicodeLength(chat_buffer);
    pcVar2 = Q_UnicodeAdvance(chat_buffer,iVar1 + -1);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    qVar3 = Q_UnicodeValidate(chat_buffer);
    if (qVar3 == 0) {
      chat_buffer[0] = '\0';
    }
    chat_bufferlen = strlen(chat_buffer);
    return;
  }
  key_dest = key_game;
  chat_bufferlen = 0;
  chat_buffer[0] = '\0';
  Q_strcpy(message_type,"say");
  message_type_is_privileged = true;
  return;
}


// Key_NameForBinding  @ 001b5c50
char * Key_NameForBinding(char *pBinding)

{
  char cVar1;
  char *pcVar2;
  keyname_t *pkVar3;
  int iVar4;
  keyname_t *pkVar5;
  int iVar6;
  
                    /* Unresolved local var: int i@[???] */
  iVar6 = 0;
  (*g_engdstAddrs.Key_LookupBinding)(&pBinding);
  do {
    if ((keybindings[iVar6] != (char *)0x0) && (cVar1 = *keybindings[iVar6], cVar1 != '\0')) {
      if (cVar1 == '+') {
        iVar4 = Q_strlen(pBinding);
        iVar4 = Q_strncasecmp(keybindings[iVar6] + 1,pBinding,iVar4);
        if (iVar4 == 0) {
                    /* Unresolved local var: keyname_t * kn@[???] */
          if (iVar6 - 0x21U < 0x5e) {
LAB_001b5d1f:
            Key_KeynumToString::tinystr[0] = (char)iVar6;
            Key_KeynumToString::tinystr[1] = '\0';
            return Key_KeynumToString::tinystr;
          }
                    /* Unresolved local var: keyname_t * kn@[???] */
          if (keynames[0].name != (char *)0x0) {
            if (iVar6 == keynames[0].keynum) {
              return keynames[0].name;
            }
            pkVar5 = keynames;
            while( true ) {
              pcVar2 = pkVar5[1].name;
              if (pcVar2 == (char *)0x0) break;
              pkVar3 = pkVar5 + 1;
              pkVar5 = pkVar5 + 1;
              if (pkVar3->keynum == iVar6) {
                return pcVar2;
              }
            }
          }
          goto LAB_001b5d09;
        }
      }
      else {
        iVar4 = Q_strlen(pBinding);
        iVar4 = Q_strncasecmp(keybindings[iVar6],pBinding,iVar4);
        if (iVar4 == 0) {
                    /* Unresolved local var: keyname_t * kn@[???] */
          if (iVar6 - 0x21U < 0x5e) goto LAB_001b5d1f;
                    /* Unresolved local var: keyname_t * kn@[???] */
          if (keynames[0].name != (char *)0x0) {
            if (keynames[0].keynum == iVar6) {
              return keynames[0].name;
            }
            pkVar5 = keynames;
            while( true ) {
              pcVar2 = pkVar5[1].name;
              if (pcVar2 == (char *)0x0) break;
              pkVar3 = pkVar5 + 1;
              pkVar5 = pkVar5 + 1;
              if (pkVar3->keynum == iVar6) {
                return pcVar2;
              }
            }
          }
LAB_001b5d09:
          return "<UNKNOWN KEYNUM>";
        }
      }
    }
    iVar6 = iVar6 + 1;
    if (iVar6 == 0x100) {
      return (char *)0x0;
    }
  } while( true );
}


// Key_SetBinding  @ 001b5ab0
void Key_SetBinding(int keynum,char *binding)

{
  int iVar1;
  char *dest;
  
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  if ((keynum != -1 && keynum < 0x100) && (binding != (char *)0x0)) {
    if (keybindings[keynum] != (char *)0x0) {
      iVar1 = Q_strcmp(keybindings[keynum],binding);
      if (iVar1 == 0) {
        return;
      }
      Z_Free(keybindings[keynum]);
      keybindings[keynum] = (char *)0x0;
    }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
    iVar1 = Q_strlen(binding);
    dest = Z_Malloc(iVar1 + 1);
    Q_strcpy(dest,binding);
    dest[iVar1] = '\0';
    keybindings[keynum] = dest;
    iVar1 = strcasecmp(binding,"toggleconsole");
    if (iVar1 == 0) {
      toggleconsole_key = keynum;
    }
  }
  return;
}


// Key_Shutdown  @ 001b6aa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Shutdown(void)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???] */
  uVar1 = 0;
  do {
    *(undefined4 *)((int)keybindings + uVar1) = 0;
    uVar2 = uVar1 + 8;
    *(undefined4 *)((int)keybindings + uVar1 + 4) = 0;
    uVar1 = uVar2;
  } while (uVar2 < 0x400);
  return;
}


// Key_StringToKeynum  @ 001b59d0
int Key_StringToKeynum(char *str)

{
  char *pcVar1;
  int iVar2;
  keyname_t *pkVar3;
  
                    /* Unresolved local var: keyname_t * kn@[???] */
  if ((str != (char *)0x0) && (*str != '\0')) {
    if (str[1] == '\0') {
      return (int)*str;
    }
                    /* Unresolved local var: keyname_t * kn@[???] */
    if (keynames[0].name != (char *)0x0) {
      pkVar3 = keynames;
      pcVar1 = keynames[0].name;
      do {
        iVar2 = Q_strcasecmp(str,pcVar1);
        if (iVar2 == 0) {
          return pkVar3->keynum;
        }
        pkVar3 = pkVar3 + 1;
        pcVar1 = pkVar3->name;
      } while (pcVar1 != (char *)0x0);
    }
  }
  return -1;
}


// Key_Unbind_f  @ 001b4e60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Unbind_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  keyname_t *pkVar5;
  
                    /* Unresolved local var: int b@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("unbind <key> : remove commands from a key\n");
    return;
  }
  pcVar2 = Cmd_Argv(1);
                    /* Unresolved local var: keyname_t * kn@[???] */
  if ((pcVar2 != (char *)0x0) && (iVar1 = (int)*pcVar2, *pcVar2 != '\0')) {
    if (pcVar2[1] == '\0') {
LAB_001b4ec3:
      if (iVar1 != -1) {
        if (iVar1 == 0x1b) {
          Con_Printf("Can\'t unbind ESCAPE key\n");
        }
        else {
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
          if (iVar1 < 0x100) {
            if (keybindings[iVar1] != (char *)0x0) {
              iVar3 = Q_strcmp(keybindings[iVar1],"");
              if (iVar3 == 0) {
                return;
              }
              Z_Free(keybindings[iVar1]);
              keybindings[iVar1] = (char *)0x0;
            }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
            iVar3 = Q_strlen("");
            pcVar2 = Z_Malloc(iVar3 + 1);
            Q_strcpy(pcVar2,"");
            pcVar2[iVar3] = '\0';
            keybindings[iVar1] = pcVar2;
            iVar3 = strcasecmp("","toggleconsole");
            if (iVar3 == 0) {
              toggleconsole_key = iVar1;
            }
          }
        }
        return;
      }
    }
    else {
                    /* Unresolved local var: keyname_t * kn@[???] */
      if (keynames[0].name != (char *)0x0) {
        pkVar5 = keynames;
        pcVar4 = keynames[0].name;
        do {
          iVar1 = Q_strcasecmp(pcVar2,pcVar4);
          if (iVar1 == 0) {
            iVar1 = pkVar5->keynum;
            goto LAB_001b4ec3;
          }
          pkVar5 = pkVar5 + 1;
          pcVar4 = pkVar5->name;
        } while (pcVar4 != (char *)0x0);
      }
    }
  }
                    /* Unresolved local var: int b@[???] */
  pcVar2 = Cmd_Argv(1);
  Con_Printf("\"%s\" isn\'t a valid key\n",pcVar2);
  return;
}


// Key_Unbindall_f  @ 001b5000
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Unbindall_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
LAB_001b501d:
  do {
    iVar3 = iVar1;
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
    if (((iVar3 != 0x1b) && (keybindings[iVar3] != (char *)0x0)) &&
       (iVar1 = Q_strcmp(keybindings[iVar3],""), iVar1 != 0)) {
      Z_Free(keybindings[iVar3]);
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
      keybindings[iVar3] = (char *)0x0;
      iVar1 = Q_strlen("");
      pcVar2 = Z_Malloc(iVar1 + 1);
      Q_strcpy(pcVar2,"");
      pcVar2[iVar1] = '\0';
      keybindings[iVar3] = pcVar2;
      iVar1 = strcasecmp("","toggleconsole");
      if (iVar1 == 0) {
        iVar1 = iVar3 + 1;
        toggleconsole_key = iVar3;
        if (iVar3 + 1 == 0x100) break;
        goto LAB_001b501d;
      }
    }
    iVar1 = iVar3 + 1;
  } while (iVar3 + 1 != 0x100);
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  if (keybindings[0x7e] == (char *)0x0) {
LAB_001b5241:
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
    iVar1 = Q_strlen("toggleconsole");
    pcVar2 = Z_Malloc(iVar1 + 1);
    Q_strcpy(pcVar2,"toggleconsole");
    pcVar2[iVar1] = '\0';
    keybindings[0x7e] = pcVar2;
    iVar1 = strcasecmp("toggleconsole","toggleconsole");
    if (iVar1 == 0) {
      toggleconsole_key = 0x7e;
    }
  }
  else {
    iVar1 = Q_strcmp(keybindings[0x7e],"toggleconsole");
    if (iVar1 != 0) {
      Z_Free(keybindings[0x7e]);
      keybindings[0x7e] = (char *)0x0;
      goto LAB_001b5241;
    }
  }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  if (keybindings[0x60] != (char *)0x0) {
    iVar1 = Q_strcmp(keybindings[0x60],"toggleconsole");
    if (iVar1 == 0) goto LAB_001b511c;
    Z_Free(keybindings[0x60]);
    keybindings[0x60] = (char *)0x0;
  }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  iVar1 = Q_strlen("toggleconsole");
  pcVar2 = Z_Malloc(iVar1 + 1);
  Q_strcpy(pcVar2,"toggleconsole");
  pcVar2[iVar1] = '\0';
  keybindings[0x60] = pcVar2;
  iVar1 = strcasecmp("toggleconsole","toggleconsole");
  if (iVar1 == 0) {
    toggleconsole_key = 0x60;
  }
LAB_001b511c:
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  if (keybindings[0x1b] != (char *)0x0) {
    iVar1 = Q_strcmp(keybindings[0x1b],"cancelselect");
    if (iVar1 == 0) {
      return;
    }
    Z_Free(keybindings[0x1b]);
    keybindings[0x1b] = (char *)0x0;
  }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  iVar1 = Q_strlen("cancelselect");
  pcVar2 = Z_Malloc(iVar1 + 1);
  Q_strcpy(pcVar2,"cancelselect");
  pcVar2[iVar1] = '\0';
  keybindings[0x1b] = pcVar2;
  iVar1 = strcasecmp("cancelselect","toggleconsole");
  if (iVar1 != 0) {
    return;
  }
  toggleconsole_key = 0x1b;
  return;
}


// Key_UpLine  @ 001b57b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_UpLine(void)

{
  do {
    history_line = history_line - 1U & 0x1f;
    if (history_line == edit_line) {
      history_line = history_line + 1U & 0x1f;
      break;
    }
  } while (key_lines[history_line][1] == '\0');
  snprintf(key_lines[edit_line],0x100,"%s",key_lines + history_line);
  key_linepos = Q_strlen(key_lines[edit_line]);
  return;
}


// Key_WriteBindings  @ 001b5bb0
void Key_WriteBindings(FileHandle_t f)

{
  char *pcVar1;
  keyname_t *pkVar2;
  keyname_t *pkVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  
                    /* Unresolved local var: int i@[???] */
  iVar6 = 0;
  cVar5 = '\0';
  do {
    pcVar1 = keybindings[iVar6];
    if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
                    /* Unresolved local var: keyname_t * kn@[???] */
      if (iVar6 - 0x21U < 0x5e) {
        pcVar4 = Key_KeynumToString::tinystr;
        Key_KeynumToString::tinystr[1] = '\0';
        Key_KeynumToString::tinystr[0] = cVar5;
      }
      else {
                    /* Unresolved local var: keyname_t * kn@[???] */
        if (keynames[0].name == (char *)0x0) {
LAB_001b5c06:
          pcVar4 = "<UNKNOWN KEYNUM>";
        }
        else {
          pcVar4 = keynames[0].name;
          if (keynames[0].keynum != iVar6) {
            pkVar3 = keynames;
            do {
              pcVar4 = pkVar3[1].name;
              if (pcVar4 == (char *)0x0) goto LAB_001b5c06;
              pkVar2 = pkVar3 + 1;
              pkVar3 = pkVar3 + 1;
            } while (iVar6 != pkVar2->keynum);
          }
        }
      }
      FS_FPrintf(f,"bind \"%s\" \"%s\"\n",pcVar4,pcVar1);
    }
    iVar6 = iVar6 + 1;
    cVar5 = cVar5 + '\x01';
    if (iVar6 == 0x100) {
      return;
    }
  } while( true );
}


