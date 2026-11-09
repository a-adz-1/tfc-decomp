// KeyCode_VGUIToVirtualKey  @ 00225d70
int32 KeyCode_VGUIToVirtualKey(KeyCode keyCode)

{
  int32 *piVar1;
  KeyCode *pKVar2;
  int iVar3;
  uint uVar4;
  vgui_to_virtual_t *pvVar5;
  
  if (!vgui2::InitVGUIToVKTranslationTable::lexical_block_0::bInitted) {
    vgui2::InitVGUIToVKTranslationTable::lexical_block_0::bInitted = true;
    uVar4 = 0;
    do {
      *(undefined4 *)((int)s_pVGUIToVirtualKey + uVar4) = 0;
      *(undefined4 *)((int)s_pVGUIToVirtualKey + uVar4 + 4) = 0;
      *(undefined4 *)((int)s_pVGUIToVirtualKey + uVar4 + 8) = 0;
      *(undefined4 *)((int)s_pVGUIToVirtualKey + uVar4 + 0xc) = 0;
      uVar4 = uVar4 + 0x10;
    } while (uVar4 < 0x400);
    pvVar5 = keyMap;
    do {
      pKVar2 = &pvVar5->vguiKeyCode;
                    /* Unresolved local var: int i@[???] */
      piVar1 = &pvVar5->sdlKeyCode;
      pvVar5 = pvVar5 + 1;
      s_pVGUIToVirtualKey[*pKVar2] = *piVar1;
    } while (pvVar5 != (vgui_to_virtual_t *)&DAT_00297394);
  }
  iVar3 = -1;
  if (keyCode < 0x100) {
    iVar3 = s_pVGUIToVirtualKey[keyCode];
  }
  return iVar3;
}


// KeyCode_VirtualKeyToVGUI  @ 00225590
KeyCode KeyCode_VirtualKeyToVGUI(int keyCode)

{
  vgui_to_virtual_t *pvVar1;
  int iVar2;
  uint uVar3;
  int32 *piVar4;
  KeyCode KVar5;
  
  if (!vgui2::InitKeyTranslationTable::lexical_block_0::bInitted) {
    vgui2::InitKeyTranslationTable::lexical_block_0::bInitted = true;
    uVar3 = 0;
    do {
      *(undefined4 *)((int)s_pVirtualKeyToVGUI + uVar3) = 0;
      *(undefined4 *)((int)s_pVirtualKeyToVGUI + uVar3 + 4) = 0;
      *(undefined4 *)((int)s_pVirtualKeyToVGUI + uVar3 + 8) = 0;
      *(undefined4 *)((int)s_pVirtualKeyToVGUI + uVar3 + 0xc) = 0;
      uVar3 = uVar3 + 0x10;
    } while (uVar3 < 0x400);
    piVar4 = &keyMap[0].sdlKeyCode;
    do {
                    /* Unresolved local var: int i@[???] */
      iVar2 = *piVar4;
      pvVar1 = (vgui_to_virtual_t *)(piVar4 + -2);
      piVar4 = piVar4 + 3;
      s_pVirtualKeyToVGUI[iVar2] = pvVar1->vguiKeyCode;
    } while (piVar4 != (int32 *)"m Vera Sans");
  }
  if (keyCode == 0x4000002b) {
    return KEY_TAB;
  }
  if (keyCode < 0x4000002c) {
    if (keyCode == 0x61) {
      return KEY_A;
    }
    if (keyCode < 0x62) {
      if (keyCode == 0x32) {
        return KEY_2;
      }
      if (keyCode < 0x33) {
        if (keyCode == 0x27) {
          return KEY_APOSTROPHE;
        }
        if (keyCode < 0x28) {
          if (keyCode == 0xd) {
            return KEY_ENTER;
          }
          if (keyCode < 0xe) {
            if (keyCode == 8) {
              return KEY_BACKSPACE;
            }
            if (keyCode == 9) {
              return KEY_TAB;
            }
          }
          else {
            if (keyCode == 0x1b) {
              return KEY_ESCAPE;
            }
            if (keyCode == 0x20) {
              return KEY_SPACE;
            }
          }
        }
        else {
          if (keyCode == 0x2e) {
            return KEY_PERIOD;
          }
          if (0x2e < keyCode) {
            if (keyCode == 0x30) {
              return KEY_0;
            }
            KVar5 = KEY_SLASH;
            if (0x30 < keyCode) {
              KVar5 = KEY_1;
            }
            return KVar5;
          }
          if (keyCode == 0x2c) {
            return KEY_COMMA;
          }
          if (keyCode == 0x2d) {
            return KEY_MINUS;
          }
        }
      }
      else {
        if (keyCode == 0x39) {
          return KEY_9;
        }
        if (keyCode < 0x3a) {
          if (keyCode == 0x35) {
            return KEY_5;
          }
          if (0x35 < keyCode) {
            if (keyCode == 0x37) {
              return KEY_7;
            }
            return (uint)(0x37 < keyCode) * 2 + KEY_6;
          }
          if (keyCode == 0x33) {
            return KEY_3;
          }
          if (keyCode == 0x34) {
            return KEY_4;
          }
        }
        else {
          if (keyCode == 0x5b) {
            return KEY_LBRACKET;
          }
          if (keyCode < 0x5c) {
            if (keyCode == 0x3b) {
              return KEY_SEMICOLON;
            }
            if (keyCode == 0x3d) {
              return KEY_EQUAL;
            }
          }
          else {
            if (keyCode == 0x5d) {
              return KEY_RBRACKET;
            }
            if (keyCode < 0x5d) {
              return KEY_BACKSLASH;
            }
            if (keyCode == 0x60) {
              return KEY_BACKQUOTE;
            }
          }
        }
      }
    }
    else {
      if (keyCode == 0x6e) {
        return KEY_N;
      }
      if (keyCode < 0x6f) {
        if (keyCode == 0x67) {
          return KEY_G;
        }
        if (keyCode < 0x68) {
          if (keyCode == 100) {
            return KEY_D;
          }
          if (keyCode < 0x65) {
            if (keyCode == 0x62) {
              return KEY_B;
            }
            if (keyCode == 99) {
              return KEY_C;
            }
            return KEY_NONE;
          }
          if (keyCode == 0x65) {
            return KEY_E;
          }
          if (keyCode == 0x66) {
            return KEY_F;
          }
        }
        else {
          if (keyCode == 0x6a) {
            return KEY_J;
          }
          if (0x6a < keyCode) {
            if (keyCode == 0x6c) {
              return KEY_L;
            }
            return (uint)(0x6c < keyCode) * 2 + KEY_K;
          }
          if (keyCode == 0x68) {
            return KEY_H;
          }
          if (keyCode == 0x69) {
            return KEY_I;
          }
        }
      }
      else {
        if (keyCode == 0x75) {
          return KEY_U;
        }
        if (keyCode < 0x76) {
          if (keyCode == 0x71) {
            return KEY_Q;
          }
          if (0x71 < keyCode) {
            if (keyCode == 0x73) {
              return KEY_S;
            }
            return (uint)(0x73 < keyCode) * 2 + KEY_R;
          }
          if (keyCode == 0x6f) {
            return KEY_O;
          }
          if (keyCode == 0x70) {
            return KEY_P;
          }
        }
        else {
          if (keyCode == 0x78) {
            return KEY_X;
          }
          if (keyCode < 0x79) {
            if (keyCode == 0x76) {
              return KEY_V;
            }
            if (keyCode == 0x77) {
              return KEY_W;
            }
          }
          else {
            if (keyCode == 0x7a) {
              return KEY_Z;
            }
            if (keyCode < 0x7a) {
              return KEY_Y;
            }
            if (keyCode == 0x7f) {
              return KEY_DELETE;
            }
          }
        }
      }
    }
  }
  else {
    if (keyCode == 0x40000051) {
      return KEY_DOWN;
    }
    if (keyCode < 0x40000052) {
      if (keyCode == 0x40000042) {
        return KEY_F9;
      }
      if (keyCode < 0x40000043) {
        if (keyCode == 0x4000003b) {
          return KEY_F2;
        }
        if (keyCode < 0x4000003c) {
          if (keyCode == 0x40000035) {
            return KEY_BACKQUOTE;
          }
          if (keyCode < 0x40000036) {
            if (keyCode == 0x4000002d) {
              return KEY_MINUS;
            }
            if (keyCode == 0x4000002e) {
              return KEY_EQUAL;
            }
            return KEY_NONE;
          }
          if (keyCode == 0x40000039) {
            return KEY_CAPSLOCK;
          }
          if (keyCode == 0x4000003a) {
            return KEY_F1;
          }
        }
        else {
          if (keyCode == 0x4000003e) {
            return KEY_F5;
          }
          if (0x4000003e < keyCode) {
            if (keyCode == 0x40000040) {
              return KEY_F7;
            }
            return (uint)(0x40000040 < keyCode) * 2 + KEY_F6;
          }
          if (keyCode == 0x4000003c) {
            return KEY_F3;
          }
          if (keyCode == 0x4000003d) {
            return KEY_F4;
          }
        }
      }
      else {
        if (keyCode == 0x4000004a) {
          return KEY_HOME;
        }
        if (keyCode < 0x4000004b) {
          if (keyCode == 0x40000045) {
            return KEY_F12;
          }
          if (keyCode < 0x40000046) {
            if (keyCode == 0x40000043) {
              return KEY_F10;
            }
            if (keyCode == 0x40000044) {
              return KEY_F11;
            }
          }
          else {
            if (keyCode == 0x40000048) {
              return KEY_BREAK;
            }
            if (0x40000048 < keyCode) {
              return KEY_INSERT;
            }
            if (keyCode == 0x40000047) {
              return KEY_SCROLLLOCK;
            }
          }
        }
        else {
          if (keyCode == 0x4000004d) {
            return KEY_END;
          }
          if (0x4000004d < keyCode) {
            if (keyCode == 0x4000004f) {
              return KEY_RIGHT;
            }
            KVar5 = KEY_PAGEDOWN;
            if (0x4000004f < keyCode) {
              KVar5 = KEY_LEFT;
            }
            return KVar5;
          }
          if (keyCode == 0x4000004b) {
            return KEY_PAGEUP;
          }
          if (keyCode == 0x4000004c) {
            return KEY_DELETE;
          }
        }
      }
    }
    else {
      if (keyCode == 0x4000005f) {
        return KEY_PAD_7;
      }
      if (keyCode < 0x40000060) {
        if (keyCode == 0x40000058) {
          return KEY_PAD_ENTER;
        }
        if (keyCode < 0x40000059) {
          if (keyCode == 0x40000054) {
            return KEY_PAD_DIVIDE;
          }
          if (0x40000054 < keyCode) {
            if (keyCode == 0x40000056) {
              return KEY_PAD_MINUS;
            }
            return (uint)(0x40000056 < keyCode) * 2 + KEY_PAD_MULTIPLY;
          }
          if (keyCode == 0x40000052) {
            return KEY_UP;
          }
          if (keyCode == 0x40000053) {
            return KEY_NUMLOCK;
          }
        }
        else {
          if (keyCode == 0x4000005b) {
            return KEY_PAD_3;
          }
          if (0x4000005b < keyCode) {
            if (keyCode == 0x4000005d) {
              return KEY_PAD_5;
            }
            return (uint)(0x4000005d < keyCode) * 2 + KEY_PAD_4;
          }
          if (keyCode == 0x40000059) {
            return KEY_PAD_1;
          }
          if (keyCode == 0x4000005a) {
            return KEY_PAD_2;
          }
        }
      }
      else {
        if (keyCode == 0x400000e1) {
          return KEY_LSHIFT;
        }
        if (keyCode < 0x400000e2) {
          if (keyCode == 0x40000062) {
            return KEY_PAD_0;
          }
          if (keyCode < 0x40000063) {
            if (keyCode == 0x40000060) {
              return KEY_PAD_8;
            }
            if (keyCode == 0x40000061) {
              return KEY_PAD_9;
            }
          }
          else {
            if (keyCode == 0x400000dc) {
              return KEY_PAD_DECIMAL;
            }
            if (keyCode == 0x400000e0) {
              return KEY_LCONTROL;
            }
            if (keyCode == 0x40000063) {
              return KEY_PAD_DECIMAL;
            }
          }
        }
        else {
          if (keyCode == 0x400000e4) {
            return KEY_RCONTROL;
          }
          if (keyCode < 0x400000e5) {
            if (keyCode == 0x400000e2) {
              return KEY_LALT;
            }
            if (keyCode == 0x400000e3) {
              return KEY_LWIN;
            }
          }
          else {
            if (keyCode == 0x400000e6) {
              return KEY_RALT;
            }
            if (keyCode < 0x400000e6) {
              return KEY_RSHIFT;
            }
            if (keyCode == 0x400000e7) {
              return KEY_RWIN;
            }
          }
        }
      }
    }
  }
  return KEY_NONE;
}


