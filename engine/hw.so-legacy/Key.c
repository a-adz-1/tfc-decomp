// Key_Bind_f  @ 00205130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Bind_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  keyname_t *pkVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint local_41c [259];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int b@[DW_OP_reg6(ESI)]
                       Unresolved local var: char[1024] cmd@[???] */
  iVar1 = Cmd_Argc();
  if (1 < iVar1 - 2U) {
    Con_Printf("bind <key> [command] : attach a command to a key\n");
    return;
  }
  pcVar2 = Cmd_Argv(1);
                    /* Unresolved local var: keyname_t * kn@[???] */
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    if (pcVar2[1] == '\0') {
      uVar10 = (uint)*pcVar2;
LAB_002051f0:
      if (uVar10 < 0x100) {
        if (iVar1 == 2) {
          pcVar2 = keybindings[uVar10];
          if (pcVar2 != (char *)0x0) {
            pcVar6 = Cmd_Argv(1);
            Con_Printf("\"%s\" = \"%s\"\n",pcVar6,pcVar2);
            return;
          }
          pcVar2 = Cmd_Argv(1);
          Con_Printf("\"%s\" is not bound\n",pcVar2);
          return;
        }
        if (uVar10 == 0x1b) {
          Q_strcpy((char *)local_41c,"cancelselect");
        }
        else {
          local_41c[0]._0_1_ = 0;
          puVar9 = local_41c;
          do {
            puVar8 = puVar9;
            uVar4 = *puVar8 + 0xfefefeff & ~*puVar8;
            uVar5 = uVar4 & 0x80808080;
            puVar9 = puVar8 + 1;
          } while (uVar5 == 0);
          if ((uVar4 & 0x8080) == 0) {
            puVar9 = (uint *)((int)puVar8 + 6);
            uVar5 = uVar5 >> 0x10;
          }
          pcVar2 = Cmd_Argv(2);
          strncat((char *)local_41c,pcVar2,
                  0x3ff - (int)((int)puVar9 +
                               ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)local_41c)));
        }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
        if (keybindings[uVar10] != (char *)0x0) {
          iVar1 = Q_strcmp(keybindings[uVar10],(char *)local_41c);
          if (iVar1 == 0) {
            return;
          }
          Z_Free(keybindings[uVar10]);
          keybindings[uVar10] = (char *)0x0;
        }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
        iVar1 = Q_strlen((char *)local_41c);
        pcVar2 = Z_Malloc(iVar1 + 1);
        Q_strcpy(pcVar2,(char *)local_41c);
        pcVar2[iVar1] = '\0';
        keybindings[uVar10] = pcVar2;
        iVar1 = strcasecmp((char *)local_41c,"toggleconsole");
        if (iVar1 != 0) {
          return;
        }
        toggleconsole_key = uVar10;
        return;
      }
    }
    else {
                    /* Unresolved local var: keyname_t * kn@[???] */
      if (keynames[0].name != (char *)0x0) {
        pkVar7 = keynames;
        pcVar6 = keynames[0].name;
        do {
          iVar3 = Q_strcasecmp(pcVar2,pcVar6);
          if (iVar3 == 0) {
            uVar10 = pkVar7->keynum;
            goto LAB_002051f0;
          }
          pkVar7 = pkVar7 + 1;
          pcVar6 = pkVar7->name;
        } while (pcVar6 != (char *)0x0);
      }
    }
  }
  pcVar2 = Cmd_Argv(1);
  Con_Printf("\"%s\" isn\'t a valid key\n",pcVar2);
  return;
}


// Key_BindingForKey  @ 00206760
char * Key_BindingForKey(int keynum)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if ((uint)keynum < 0x100) {
    pcVar1 = keybindings[keynum];
  }
  return pcVar1;
}


// Key_ClearStates  @ 002066d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_ClearStates(void)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???] */
  uVar1 = 0;
  do {
    *(undefined4 *)((int)keydown + uVar1) = 0;
    *(undefined4 *)((int)keydown + uVar1 + 4) = 0;
    *(undefined4 *)((int)keydown + uVar1 + 8) = 0;
    *(undefined4 *)((int)keydown + uVar1 + 0xc) = 0;
    uVar1 = uVar1 + 0x10;
  } while (uVar1 < 0x400);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)keyGameUIdown + uVar1) = 0;
    *(undefined4 *)((int)keyGameUIdown + uVar1 + 4) = 0;
    *(undefined4 *)((int)keyGameUIdown + uVar1 + 8) = 0;
    *(undefined4 *)((int)keyGameUIdown + uVar1 + 0xc) = 0;
    uVar1 = uVar1 + 0x10;
  } while (uVar1 < 0x400);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)key_repeats + uVar1) = 0;
    *(undefined4 *)((int)key_repeats + uVar1 + 4) = 0;
    *(undefined4 *)((int)key_repeats + uVar1 + 8) = 0;
    *(undefined4 *)((int)key_repeats + uVar1 + 0xc) = 0;
    uVar1 = uVar1 + 0x10;
  } while (uVar1 < 0x400);
  return;
}


// Key_Console  @ 00205790
void Key_Console(int key)

{
  return;
}


// Key_CountBindings  @ 00205be0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Key_CountBindings(void)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (keybindings[iVar2] != (char *)0x0) {
      iVar1 = (iVar1 + 1) - (uint)(*keybindings[iVar2] == '\0');
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x100);
  return iVar1;
}


// Key_Escape_f  @ 00205980
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
      Sys_Error("Bad key_dest");
      return;
    }
    Key_Message(0x1b);
    return;
  }
  VGuiWrap2_HideGameUI();
  giActive = 2;
  return;
}


// Key_Event  @ 002061e0
void Key_Event(int key,qboolean down)

{
  keyname_t *pkVar1;
  int iVar2;
  qboolean qVar3;
  char *pcVar4;
  char *__format;
  char local_40c [1032];
  
                    /* Unresolved local var: char * kb@[???]
                       Unresolved local var: char[1024] cmd@[???] */
  if (0xff < key) {
    return;
  }
  (*g_engdstAddrs.Key_Event)(&key,(int *)&down);
  keydown[key] = down;
  if (((keydown[0x85] != false) && (keydown[0x84] != false)) && (keydown[0x94] != false)) {
    Sys_Error("ctrl-alt-del pressed");
  }
  if (key_dest == key_game) {
    if ((down != false) || (keyGameUIdown[key] != false)) {
      iVar2 = ClientDLL_Key_Event((uint)(down != false),key,keybindings[key]);
      if (iVar2 == 0) {
        if (key_repeats[key] == 0) {
          if (down != false) {
            keyGameUIdown[key] = true;
            return;
          }
        }
        else if (down != false) {
          return;
        }
        key_repeats[key] = 0;
        keyGameUIdown[key] = false;
        return;
      }
      goto LAB_00206354;
    }
LAB_00206285:
    key_repeats[key] = 0;
    keyGameUIdown[key] = false;
    qVar3 = false;
LAB_00206299:
    if (key == 0x86) {
      shift_down = qVar3;
    }
    if (qVar3 == false) {
      pcVar4 = keybindings[key];
      if ((pcVar4 != (char *)0x0) && (*pcVar4 == '+')) {
        snprintf(local_40c,0x400,"-%s %i\n",pcVar4 + 1,key);
        Cbuf_AddText(local_40c);
      }
      if (key == keyshift[key]) {
        return;
      }
      pcVar4 = keybindings[keyshift[key]];
      if (pcVar4 == (char *)0x0) {
        return;
      }
      if (*pcVar4 != '+') {
        return;
      }
      pcVar4 = pcVar4 + 1;
      __format = "-%s %i\n";
      goto LAB_002062fb;
    }
  }
  else {
LAB_00206354:
    if (down == false) goto LAB_00206285;
    iVar2 = key_repeats[key];
    key_repeats[key] = iVar2 + 1;
    if ((key == 0xff) || (key == 0x7f)) {
LAB_0020637b:
      qVar3 = down;
      if (199 < key) {
        if (keybindings[key] != (char *)0x0) goto LAB_00206395;
                    /* Unresolved local var: keyname_t * kn@[???] */
        if (keynames[0].name == (char *)0x0) {
LAB_0020667e:
          pcVar4 = "<UNKNOWN KEYNUM>";
        }
        else {
          pkVar1 = keynames;
          pcVar4 = keynames[0].name;
          iVar2 = keynames[0].keynum;
          while (pkVar1 = pkVar1 + 1, iVar2 != key) {
            pcVar4 = pkVar1->name;
            if (pcVar4 == (char *)0x0) goto LAB_0020667e;
            iVar2 = pkVar1->keynum;
          }
        }
        Con_Printf("%s is unbound.\n",pcVar4);
        qVar3 = down;
      }
      goto LAB_00206299;
    }
    if ((key != 0x96) && (((key != 0xa2 && (key != 0x95)) && (key != 0xa8)))) {
      if (1 < iVar2 + 1) {
        return;
      }
      goto LAB_0020637b;
    }
  }
LAB_00206395:
  if ((((byte)giSubState & 0x10) != 0) && (key != 0x1b)) {
    return;
  }
  if (((key_dest == key_game) && (key == 0x1b)) && (iVar2 = VGui_GameUIKeyPressed(), iVar2 != 0)) {
    return;
  }
  if ((((cls.demoplayback != false) && (cls.spectator == false)) && (down != false)) &&
     ((consolekeys[key] != false && (key_dest == key_game)))) {
    Con_ToggleConsole_f();
    return;
  }
  if (key_dest == key_menu) {
    if (menubound[key] == false) goto LAB_002064f6;
  }
  else if ((key_dest != key_game) || ((con_forcedup != false && (consolekeys[key] != false)))) {
LAB_002064f6:
    if (down == false) {
      return;
    }
    if (shift_down != 0) {
      key = keyshift[key];
    }
    if (key_dest == key_game) {
      return;
    }
    if (key_dest != key_message) {
      Sys_Error("Bad key_dest");
      return;
    }
    Key_Message(key);
    return;
  }
  pcVar4 = keybindings[key];
  if (pcVar4 == (char *)0x0) {
    return;
  }
  if (*pcVar4 != '+') {
    iVar2 = strncasecmp(pcVar4,"toggleconsole",4);
    if (((iVar2 == 0) && (keydown[0x86] != false)) && (con_shifttoggleconsole.value == 0.0)) {
      return;
    }
    Cbuf_AddText(pcVar4);
    Cbuf_AddText("\n");
    return;
  }
  __format = "%s %i\n";
LAB_002062fb:
  snprintf(local_40c,0x400,__format,pcVar4,key);
  Cbuf_AddText(local_40c);
  return;
}


// Key_EventStub  @ 002066b0
void Key_EventStub(int key,qboolean down)

{
  if (g_fUseDInput != false) {
    return;
  }
  Key_Event(key,down);
  return;
}


// Key_Init  @ 00205df0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Init(void)

{
  char (*pacVar1) [256];
  qboolean *pqVar2;
  int *piVar3;
  qboolean qVar4;
  qboolean qVar5;
  qboolean qVar6;
  qboolean qVar7;
  
                    /* Unresolved local var: int i@[???] */
  pacVar1 = key_lines;
  do {
    (*pacVar1)[0] = 0x5d;
    (*pacVar1)[1] = 0;
    pacVar1 = pacVar1 + 1;
  } while (pacVar1 != (char (*) [256])keyGameUIdown);
  pqVar2 = consolekeys + 0x20;
  key_linepos = 1;
  do {
    *pqVar2 = true;
    pqVar2[1] = true;
    pqVar2[2] = true;
    pqVar2[3] = true;
    pqVar2 = pqVar2 + 4;
  } while (pqVar2 != consolekeys + 0x80);
  consolekeys[9] = true;
  consolekeys[0x82] = true;
  qVar4 = false;
  qVar5 = true;
  qVar6 = 2;
  qVar7 = 3;
  consolekeys[0xa3] = true;
  consolekeys[0x83] = true;
  consolekeys[0xa5] = true;
  consolekeys[0x80] = true;
  consolekeys[0xa7] = true;
  consolekeys[0x7f] = true;
  consolekeys[0x96] = true;
  consolekeys[0xa2] = true;
  consolekeys[0x95] = true;
  consolekeys[0xa8] = true;
  consolekeys[0x98] = true;
  consolekeys[0xa6] = true;
  consolekeys[0x86] = true;
  consolekeys[0x84] = true;
  consolekeys[0x20] = true;
  consolekeys[0x85] = true;
  consolekeys[0xad] = true;
  consolekeys[0xa4] = true;
  consolekeys[0xd] = true;
  consolekeys[0xa9] = true;
  consolekeys[0xb0] = true;
  consolekeys[0xa1] = true;
  consolekeys[0x81] = true;
  consolekeys[0xb1] = false;
  consolekeys[0x97] = true;
  consolekeys[0xa0] = true;
  consolekeys[0x60] = false;
  consolekeys[0x7e] = false;
  piVar3 = keyshift;
  consolekeys[0xac] = true;
  consolekeys[0xae] = true;
  do {
    *piVar3 = qVar4;
    piVar3[1] = qVar5;
    piVar3[2] = qVar6;
    piVar3[3] = qVar7;
    piVar3 = piVar3 + 4;
    qVar4 = qVar4 + 4;
    qVar5 = qVar5 + 4;
    qVar6 = qVar6 + 4;
    qVar7 = qVar7 + 4;
  } while ((qboolean *)piVar3 != consolekeys);
  keyshift[0x62] = 0x42;
  keyshift[99] = 0x43;
  keyshift[100] = 0x44;
  keyshift[0x65] = 0x45;
  keyshift[0x66] = 0x46;
  keyshift[0x67] = 0x47;
  keyshift[0x78] = 0x58;
  keyshift[0x79] = 0x59;
  keyshift[0x68] = 0x48;
  keyshift[0x69] = 0x49;
  keyshift[0x6a] = 0x4a;
  keyshift[0x6b] = 0x4b;
  keyshift[0x7a] = 0x5a;
  keyshift[0x31] = 0x21;
  keyshift[0x6c] = 0x4c;
  keyshift[0x6d] = 0x4d;
  keyshift[0x6e] = 0x4e;
  keyshift[0x6f] = 0x4f;
  keyshift[0x34] = 0x24;
  keyshift[0x35] = 0x25;
  keyshift[0x70] = 0x50;
  keyshift[0x71] = 0x51;
  keyshift[0x72] = 0x52;
  keyshift[0x73] = 0x53;
  keyshift[0x36] = 0x5e;
  keyshift[0x37] = 0x26;
  keyshift[0x74] = 0x54;
  keyshift[0x75] = 0x55;
  keyshift[0x76] = 0x56;
  keyshift[0x77] = 0x57;
  keyshift[0x38] = 0x2a;
  keyshift[0x39] = 0x28;
  keyshift[0x3d] = 0x2b;
  keyshift[0x2c] = 0x3c;
  keyshift[0x2e] = 0x3e;
  keyshift[0x2f] = 0x3f;
  keyshift[0x61] = 0x41;
  keyshift[0x32] = 0x40;
  keyshift[0x3b] = 0x3a;
  keyshift[0x33] = 0x23;
  keyshift[0x30] = 0x29;
  keyshift[0x27] = 0x22;
  keyshift[0x2d] = 0x5f;
  keyshift[0x5b] = 0x7b;
  menubound[0x88] = true;
  menubound[0x89] = true;
  menubound[0x8a] = true;
  menubound[0x8b] = true;
  keyshift[0x60] = 0x7e;
  menubound[0x8c] = true;
  menubound[0x8d] = true;
  menubound[0x8e] = true;
  menubound[0x8f] = true;
  keyshift[0x5c] = 0x7c;
  menubound[0x1b] = true;
  menubound[0x87] = true;
  menubound[0x90] = true;
  keyshift[0x5d] = 0x7d;
  menubound[0x91] = true;
  menubound[0x92] = true;
  Cmd_AddCommandWithFlags("bind",Key_Bind_f,8);
  Cmd_AddCommandWithFlags("unbind",Key_Unbind_f,8);
  Cmd_AddCommandWithFlags("unbindall",Key_Unbindall_f,8);
  Cmd_AddCommand("escape",Key_Escape_f);
  return;
}


// Key_KeynumToString  @ 00205aa0
char * Key_KeynumToString(int keynum)

{
  char *pcVar1;
  keyname_t *pkVar2;
  
                    /* Unresolved local var: keyname_t * kn@[???] */
  pcVar1 = "<KEY NOT FOUND>";
  if (keynum != -1) {
    if (0x5d < keynum - 0x21U) {
                    /* Unresolved local var: keyname_t * kn@[???] */
      if (keynames[0].name != (char *)0x0) {
        pkVar2 = keynames;
        if (keynum == keynames[0].keynum) {
          return keynames[0].name;
        }
        while (pkVar2 = pkVar2 + 1, pkVar2->name != (char *)0x0) {
          if (keynum == pkVar2->keynum) {
            return pkVar2->name;
          }
        }
      }
      return "<UNKNOWN KEYNUM>";
    }
    Key_KeynumToString::tinystr[0] = (char)keynum;
    pcVar1 = Key_KeynumToString::tinystr;
    Key_KeynumToString::tinystr[1] = '\0';
  }
  return pcVar1;
}


// Key_Message  @ 00205810
void Key_Message(int key)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  qboolean qVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  code *pcVar9;
  
                    /* Unresolved local var: qboolean bResetMessage@[???] */
  if ((key == 0xa9) || (key == 0xd)) {
                    /* Unresolved local var: _func_void_char_ptr * pfnAddText@[???]
                       Unresolved local var: char * temp@[???] */
    if (chat_buffer[0] != '\0') {
      pcVar3 = chat_buffer;
      cVar1 = chat_buffer[0];
      do {
        if (cVar1 == ';') {
          *pcVar3 = ',';
        }
        if (pcVar3 == (char *)0xffffffff) break;
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      } while (cVar1 != '\0');
    }
    pcVar9 = Cbuf_AddText;
    if (message_type_is_privileged == false) {
      pcVar9 = Cbuf_AddFilteredText;
    }
    (*pcVar9)(message_type);
    (*pcVar9)(&DAT_00294258);
    (*pcVar9)(chat_buffer);
    (*pcVar9)(&DAT_00294296);
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
    iVar2 = Q_UnicodeLength(chat_buffer);
    pcVar3 = Q_UnicodeAdvance(chat_buffer,iVar2 + -1);
    if (pcVar3 != (char *)0x0) {
      *pcVar3 = '\0';
    }
    qVar4 = Q_UnicodeValidate(chat_buffer);
    if (qVar4 == 0) {
      chat_buffer[0] = '\0';
    }
    puVar8 = (uint *)chat_buffer;
    do {
      puVar7 = puVar8;
      uVar5 = *puVar7 + 0xfefefeff & ~*puVar7;
      uVar6 = uVar5 & 0x80808080;
      puVar8 = puVar7 + 1;
    } while (uVar6 == 0);
    if ((uVar5 & 0x8080) == 0) {
      puVar8 = (uint *)((int)puVar7 + 6);
      uVar6 = uVar6 >> 0x10;
    }
    chat_bufferlen = (int)puVar8 + (-0x1373503 - (uint)CARRY1((byte)uVar6,(byte)uVar6));
    return;
  }
  key_dest = key_game;
  chat_bufferlen = 0;
  chat_buffer[0] = '\0';
  Q_strcpy(message_type,"say");
  message_type_is_privileged = true;
  return;
}


// Key_NameForBinding  @ 00205cc0
char * Key_NameForBinding(char *pBinding)

{
  char cVar1;
  int iVar2;
  keyname_t *pkVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  iVar4 = 0;
  (*g_engdstAddrs.Key_LookupBinding)(&pBinding);
  do {
    if ((keybindings[iVar4] != (char *)0x0) && (cVar1 = *keybindings[iVar4], cVar1 != '\0')) {
      if (cVar1 == '+') {
        iVar2 = Q_strlen(pBinding);
        iVar2 = Q_strncasecmp(keybindings[iVar4] + 1,pBinding,iVar2);
        if (iVar2 == 0) {
                    /* Unresolved local var: keyname_t * kn@[???] */
          if (iVar4 - 0x21U < 0x5e) {
LAB_00205dd0:
            Key_KeynumToString::tinystr[0] = (char)iVar4;
            Key_KeynumToString::tinystr[1] = '\0';
            return Key_KeynumToString::tinystr;
          }
                    /* Unresolved local var: keyname_t * kn@[???] */
          if (keynames[0].name != (char *)0x0) {
            pkVar3 = keynames;
            if (iVar4 == keynames[0].keynum) {
              return keynames[0].name;
            }
            while( true ) {
              pkVar3 = pkVar3 + 1;
              if (pkVar3->name == (char *)0x0) break;
              if (iVar4 == pkVar3->keynum) {
                return pkVar3->name;
              }
            }
          }
          goto LAB_00205d7e;
        }
      }
      else {
        iVar2 = Q_strlen(pBinding);
        iVar2 = Q_strncasecmp(keybindings[iVar4],pBinding,iVar2);
        if (iVar2 == 0) {
          if (iVar4 - 0x21U < 0x5e) goto LAB_00205dd0;
          if (keynames[0].name != (char *)0x0) {
            pkVar3 = keynames;
            if (keynames[0].keynum == iVar4) {
              return keynames[0].name;
            }
            while( true ) {
              pkVar3 = pkVar3 + 1;
              if (pkVar3->name == (char *)0x0) break;
              if (pkVar3->keynum == iVar4) {
                return pkVar3->name;
              }
            }
          }
LAB_00205d7e:
                    /* Unresolved local var: keyname_t * kn@[???] */
          return "<UNKNOWN KEYNUM>";
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 0x100) {
      return (char *)0x0;
    }
  } while( true );
}


// Key_SetBinding  @ 00205b10
void Key_SetBinding(int keynum,char *binding)

{
  int iVar1;
  char *dest;
  
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  if (((binding != (char *)0x0) && (keynum != -1)) && (keynum < 0x100)) {
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


// Key_Shutdown  @ 00206780
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Shutdown(void)

{
  char **ppcVar1;
  
                    /* Unresolved local var: int i@[???] */
  ppcVar1 = keybindings;
  do {
    *(undefined1 (*) [16])ppcVar1 = (undefined1  [16])0x0;
    ppcVar1 = (char **)((int)ppcVar1 + 0x10);
  } while (ppcVar1 != (char **)&key_linepos);
  return;
}


// Key_StringToKeynum  @ 00205a20
int Key_StringToKeynum(char *str)

{
  int iVar1;
  char *s2;
  keyname_t *pkVar2;
  
                    /* Unresolved local var: keyname_t * kn@[???] */
  if (str == (char *)0x0) {
    return -1;
  }
  iVar1 = -1;
                    /* Unresolved local var: keyname_t * kn@[???] */
  if (((*str != '\0') && (iVar1 = (int)*str, str[1] != '\0')) &&
     (iVar1 = -1, keynames[0].name != (char *)0x0)) {
    pkVar2 = keynames;
    s2 = keynames[0].name;
    do {
      iVar1 = Q_strcasecmp(str,s2);
      if (iVar1 == 0) {
        return pkVar2->keynum;
      }
      pkVar2 = pkVar2 + 1;
      s2 = pkVar2->name;
    } while (s2 != (char *)0x0);
    return -1;
  }
  return iVar1;
}


// Key_Unbind_f  @ 002053a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Unbind_f(void)

{
  int iVar1;
  char *pcVar2;
  char *s2;
  int iVar3;
  keyname_t *pkVar4;
  
                    /* Unresolved local var: int b@[DW_OP_reg3(EBX)] */
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("unbind <key> : remove commands from a key\n");
    return;
  }
  pcVar2 = Cmd_Argv(1);
                    /* Unresolved local var: keyname_t * kn@[???] */
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    if (pcVar2[1] == '\0') {
      iVar1 = (int)*pcVar2;
LAB_00205440:
      if (iVar1 != -1) {
        if (iVar1 == 0x1b) {
          Con_Printf("Can\'t unbind ESCAPE key\n");
          return;
        }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
        if (0xff < iVar1) {
          return;
        }
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
        if (iVar3 != 0) {
          return;
        }
        toggleconsole_key = iVar1;
        return;
      }
    }
    else {
                    /* Unresolved local var: keyname_t * kn@[???] */
      if (keynames[0].name != (char *)0x0) {
        pkVar4 = keynames;
        s2 = keynames[0].name;
        do {
          iVar1 = Q_strcasecmp(pcVar2,s2);
          if (iVar1 == 0) {
            iVar1 = pkVar4->keynum;
            goto LAB_00205440;
          }
          pkVar4 = pkVar4 + 1;
          s2 = pkVar4->name;
        } while (s2 != (char *)0x0);
      }
    }
  }
                    /* Unresolved local var: int b@[???] */
  pcVar2 = Cmd_Argv(1);
  Con_Printf("\"%s\" isn\'t a valid key\n",pcVar2);
  return;
}


// Key_Unbindall_f  @ 00204e80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Key_Unbindall_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
LAB_00204e9d:
  do {
    iVar3 = iVar1;
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
    if (((keybindings[iVar3] != (char *)0x0) && (iVar3 != 0x1b)) &&
       (iVar1 = Q_strcmp(keybindings[iVar3],""), iVar1 != 0)) {
      Z_Free(keybindings[iVar3]);
      keybindings[iVar3] = (char *)0x0;
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
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
        goto LAB_00204e9d;
      }
    }
    iVar1 = iVar3 + 1;
  } while (iVar3 + 1 != 0x100);
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  if (keybindings[0x7e] == (char *)0x0) {
LAB_002050c1:
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
      goto LAB_002050c1;
    }
  }
                    /* Unresolved local var: char * newbinding@[???]
                       Unresolved local var: int l@[???] */
  if (keybindings[0x60] != (char *)0x0) {
    iVar1 = Q_strcmp(keybindings[0x60],"toggleconsole");
    if (iVar1 == 0) goto LAB_00204f9c;
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
LAB_00204f9c:
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


// Key_UpLine  @ 00205700
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


// Key_WriteBindings  @ 00205c10
void Key_WriteBindings(FileHandle_t f)

{
  int iVar1;
  char *pcVar2;
  keyname_t *pkVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???] */
  iVar5 = 0;
  do {
    while ((pcVar2 = keybindings[iVar5], pcVar2 == (char *)0x0 || (*pcVar2 == '\0'))) {
      iVar5 = iVar5 + 1;
      if (iVar5 == 0x100) {
        return;
      }
    }
                    /* Unresolved local var: keyname_t * kn@[???] */
    if (iVar5 - 0x21U < 0x5e) {
      Key_KeynumToString::tinystr[0] = (char)iVar5;
      pcVar4 = Key_KeynumToString::tinystr;
      Key_KeynumToString::tinystr[1] = '\0';
    }
    else {
                    /* Unresolved local var: keyname_t * kn@[???] */
      if (keynames[0].name == (char *)0x0) {
LAB_00205c6e:
        pcVar4 = "<UNKNOWN KEYNUM>";
      }
      else {
        pkVar3 = keynames;
        pcVar4 = keynames[0].name;
        iVar1 = keynames[0].keynum;
        while (pkVar3 = pkVar3 + 1, iVar5 != iVar1) {
          pcVar4 = pkVar3->name;
          if (pcVar4 == (char *)0x0) goto LAB_00205c6e;
          iVar1 = pkVar3->keynum;
        }
      }
    }
    iVar5 = iVar5 + 1;
    FS_FPrintf(f,"bind \"%s\" \"%s\"\n",pcVar4,pcVar2);
    if (iVar5 == 0x100) {
      return;
    }
  } while( true );
}


