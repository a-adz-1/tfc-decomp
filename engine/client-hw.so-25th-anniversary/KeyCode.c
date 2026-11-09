// KeyCode_VGUIToVirtualKey  @ 001dc120
int32 KeyCode_VGUIToVirtualKey(KeyCode keyCode)

{
  uint uVar1;
  uint uVar2;
  vgui_to_virtual_t *pvVar3;
  vgui_to_virtual_t *pvVar4;
  
  if (!vgui2::InitVGUIToVKTranslationTable::bInitted) {
    vgui2::InitVGUIToVKTranslationTable::bInitted = true;
    uVar1 = 0;
    do {
      *(undefined4 *)((int)s_pVGUIToVirtualKey + uVar1) = 0;
      uVar2 = uVar1 + 8;
      *(undefined4 *)((int)s_pVGUIToVirtualKey + uVar1 + 4) = 0;
      uVar1 = uVar2;
    } while (uVar2 < 0x400);
    pvVar3 = keyMap;
    do {
                    /* Unresolved local var: int i@[???] */
      pvVar4 = pvVar3 + 1;
      s_pVGUIToVirtualKey[pvVar3->vguiKeyCode] = pvVar3->sdlKeyCode;
      pvVar3 = pvVar4;
    } while (pvVar4 != (vgui_to_virtual_t *)"family");
  }
  if (0xff < keyCode) {
    return -1;
  }
  return s_pVGUIToVirtualKey[keyCode];
}


// KeyCode_VirtualKeyToVGUI  @ 001db970
KeyCode KeyCode_VirtualKeyToVGUI(int keyCode)

{
  KeyCode KVar1;
  uint uVar2;
  uint uVar3;
  int32 *piVar4;
  int32 *piVar5;
  
  if (!vgui2::InitKeyTranslationTable::bInitted) {
    vgui2::InitKeyTranslationTable::bInitted = true;
    uVar2 = 0;
    do {
      *(undefined4 *)((int)s_pVirtualKeyToVGUI + uVar2) = 0;
      uVar3 = uVar2 + 8;
      *(undefined4 *)((int)s_pVirtualKeyToVGUI + uVar2 + 4) = 0;
      uVar2 = uVar3;
    } while (uVar3 < 0x400);
    piVar4 = &keyMap[0].sdlKeyCode;
    do {
                    /* Unresolved local var: int i@[???] */
      piVar5 = piVar4 + 3;
      s_pVirtualKeyToVGUI[*piVar4] = ((vgui_to_virtual_t *)(piVar4 + -2))->vguiKeyCode;
      piVar4 = piVar5;
    } while (piVar5 != (int *)0x27291c);
  }
  if (keyCode == 0x4000002b) {
    return KEY_TAB;
  }
  if (0x4000002b < keyCode) {
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
            KVar1 = KEY_MINUS;
            if (keyCode != 0x4000002d) {
              if (keyCode != 0x4000002e) {
                return KEY_NONE;
              }
              return KEY_EQUAL;
            }
          }
          else {
            KVar1 = KEY_CAPSLOCK;
            if (keyCode != 0x40000039) {
              if (keyCode != 0x4000003a) {
                return KEY_NONE;
              }
              return KEY_F1;
            }
          }
        }
        else {
          if (keyCode == 0x4000003e) {
            return KEY_F5;
          }
          if (0x4000003e < keyCode) {
            if (keyCode != 0x40000040) {
              return (uint)(0x40000040 < keyCode) * 2 + KEY_F6;
            }
            return KEY_F7;
          }
          KVar1 = KEY_F3;
          if (keyCode != 0x4000003c) {
            if (keyCode != 0x4000003d) {
              return KEY_NONE;
            }
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
            KVar1 = KEY_F10;
            if (keyCode != 0x40000043) {
              if (keyCode != 0x40000044) {
                return KEY_NONE;
              }
              return KEY_F11;
            }
          }
          else {
            if (keyCode == 0x40000048) {
              return KEY_BREAK;
            }
            KVar1 = KEY_INSERT;
            if ((keyCode < 0x40000049) && (KVar1 = KEY_SCROLLLOCK, keyCode != 0x40000047)) {
              return KEY_NONE;
            }
          }
        }
        else {
          if (keyCode == 0x4000004d) {
            return KEY_END;
          }
          if (0x4000004d < keyCode) {
            if (keyCode != 0x4000004f) {
              KVar1 = KEY_LEFT;
              if (keyCode < 0x40000050) {
                KVar1 = KEY_PAGEDOWN;
              }
              return KVar1;
            }
            return KEY_RIGHT;
          }
          KVar1 = KEY_PAGEUP;
          if (keyCode != 0x4000004b) {
            if (keyCode != 0x4000004c) {
              return KEY_NONE;
            }
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
            if (keyCode != 0x40000056) {
              return (uint)(0x40000056 < keyCode) * 2 + KEY_PAD_MULTIPLY;
            }
            return KEY_PAD_MINUS;
          }
          KVar1 = KEY_UP;
          if (keyCode != 0x40000052) {
            if (keyCode != 0x40000053) {
              return KEY_NONE;
            }
            return KEY_NUMLOCK;
          }
        }
        else {
          if (keyCode == 0x4000005b) {
            return KEY_PAD_3;
          }
          if (0x4000005b < keyCode) {
            if (keyCode != 0x4000005d) {
              return (uint)(0x4000005d < keyCode) * 2 + KEY_PAD_4;
            }
            return KEY_PAD_5;
          }
          KVar1 = KEY_PAD_1;
          if (keyCode != 0x40000059) {
            if (keyCode != 0x4000005a) {
              return KEY_NONE;
            }
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
            KVar1 = KEY_PAD_8;
            if (keyCode != 0x40000060) {
              if (keyCode != 0x40000061) {
                return KEY_NONE;
              }
              return KEY_PAD_9;
            }
          }
          else {
            if (keyCode == 0x400000dc) {
              return KEY_PAD_DECIMAL;
            }
            KVar1 = KEY_LCONTROL;
            if ((keyCode != 0x400000e0) && (KVar1 = KEY_PAD_DECIMAL, keyCode != 0x40000063)) {
              return KEY_NONE;
            }
          }
        }
        else {
          if (keyCode == 0x400000e4) {
            return KEY_RCONTROL;
          }
          if (keyCode < 0x400000e5) {
            KVar1 = KEY_LALT;
            if (keyCode != 0x400000e2) {
              if (keyCode != 0x400000e3) {
                return KEY_NONE;
              }
              return KEY_LWIN;
            }
          }
          else {
            if (keyCode == 0x400000e6) {
              return KEY_RALT;
            }
            KVar1 = KEY_RSHIFT;
            if (0x400000e5 < keyCode) {
              if (keyCode != 0x400000e7) {
                return KEY_NONE;
              }
              return KEY_RWIN;
            }
          }
        }
      }
    }
    return KVar1;
  }
  if (keyCode == 0x61) {
    return KEY_A;
  }
  if (0x61 < keyCode) {
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
        if (100 < keyCode) {
          if (keyCode == 0x65) {
            return KEY_E;
          }
          if (keyCode != 0x66) {
            return KEY_NONE;
          }
          return KEY_F;
        }
        if (keyCode == 0x62) {
          return KEY_B;
        }
        if (keyCode != 99) {
          return KEY_NONE;
        }
        return KEY_C;
      }
      if (keyCode == 0x6a) {
        return KEY_J;
      }
      if (0x6a < keyCode) {
        if (keyCode != 0x6c) {
          return (uint)(0x6c < keyCode) * 2 + KEY_K;
        }
        return KEY_L;
      }
      if (keyCode == 0x68) {
        return KEY_H;
      }
      if (keyCode != 0x69) {
        return KEY_NONE;
      }
      return KEY_I;
    }
    if (keyCode == 0x75) {
      return KEY_U;
    }
    if (0x75 < keyCode) {
      if (keyCode == 0x78) {
        return KEY_X;
      }
      if (keyCode < 0x79) {
        if (keyCode == 0x76) {
          return KEY_V;
        }
        if (keyCode != 0x77) {
          return KEY_NONE;
        }
        return KEY_W;
      }
      if (keyCode == 0x7a) {
        return KEY_Z;
      }
      if (keyCode < 0x7a) {
        return KEY_Y;
      }
      if (keyCode != 0x7f) {
        return KEY_NONE;
      }
      return KEY_DELETE;
    }
    if (keyCode == 0x71) {
      return KEY_Q;
    }
    if (0x71 < keyCode) {
      if (keyCode != 0x73) {
        return (uint)(0x73 < keyCode) * 2 + KEY_R;
      }
      return KEY_S;
    }
    if (keyCode == 0x6f) {
      return KEY_O;
    }
    if (keyCode != 0x70) {
      return KEY_NONE;
    }
    return KEY_P;
  }
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
      if (0xd < keyCode) {
        if (keyCode == 0x1b) {
          return KEY_ESCAPE;
        }
        if (keyCode != 0x20) {
          return KEY_NONE;
        }
        return KEY_SPACE;
      }
      if (keyCode == 8) {
        return KEY_BACKSPACE;
      }
      if (keyCode != 9) {
        return KEY_NONE;
      }
      return KEY_TAB;
    }
    if (keyCode == 0x2e) {
      return KEY_PERIOD;
    }
    if (0x2e < keyCode) {
      if (keyCode != 0x30) {
        KVar1 = KEY_1;
        if (keyCode < 0x31) {
          KVar1 = KEY_SLASH;
        }
        return KVar1;
      }
      return KEY_0;
    }
    if (keyCode == 0x2c) {
      return KEY_COMMA;
    }
    if (keyCode != 0x2d) {
      return KEY_NONE;
    }
    return KEY_MINUS;
  }
  if (keyCode == 0x39) {
    return KEY_9;
  }
  if (0x39 < keyCode) {
    if (keyCode == 0x5b) {
      return KEY_LBRACKET;
    }
    if (keyCode < 0x5c) {
      if (keyCode == 0x3b) {
        return KEY_SEMICOLON;
      }
      if (keyCode != 0x3d) {
        return KEY_NONE;
      }
      return KEY_EQUAL;
    }
    if (keyCode == 0x5d) {
      return KEY_RBRACKET;
    }
    if (keyCode < 0x5d) {
      return KEY_BACKSLASH;
    }
    if (keyCode != 0x60) {
      return KEY_NONE;
    }
    return KEY_BACKQUOTE;
  }
  if (keyCode == 0x35) {
    return KEY_5;
  }
  if (0x35 < keyCode) {
    if (keyCode != 0x37) {
      return (uint)(0x37 < keyCode) * 2 + KEY_6;
    }
    return KEY_7;
  }
  if (keyCode == 0x33) {
    return KEY_3;
  }
  if (keyCode != 0x34) {
    return KEY_NONE;
  }
  return KEY_4;
}


