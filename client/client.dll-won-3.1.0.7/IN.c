// IN_Accumulate  @ 2701e440
void IN_Accumulate(void)

{
  int iVar1;
  
                    /* 0x1e440  448  IN_Accumulate */
  if (((DAT_27089e3c == 0) && (DAT_2708a148 == 0)) && (DAT_2708a134 != 0)) {
    GetCursorPos((LPPOINT)&DAT_2708a0d8);
    iVar1 = (*DAT_2707c948)();
    DAT_2708a140 = DAT_2708a140 + (DAT_2708a0d8 - iVar1);
    iVar1 = (*DAT_2707c94c)();
    DAT_2708a078 = DAT_2708a078 + (DAT_2708a0dc - iVar1);
    FUN_2701e0f0();
    return;
  }
  return;
}


// IN_ActivateMouse  @ 2701dfa0
void IN_ActivateMouse(void)

{
                    /* 0x1dfa0  449  IN_ActivateMouse */
  if (DAT_2708a010 != 0) {
    if (DAT_2708a07c != 0) {
      DAT_2708a124 = SystemParametersInfoA(4,0,&DAT_270661c4,0);
    }
    DAT_2708a134 = 1;
  }
  return;
}


// IN_ClearStates  @ 2701e4b0
void IN_ClearStates(void)

{
                    /* 0x1e4b0  450  IN_ClearStates */
  if (DAT_2708a134 != 0) {
    DAT_2708a140 = 0;
    DAT_2708a078 = 0;
    DAT_2708a128 = 0;
  }
  return;
}


// IN_DeactivateMouse  @ 2701dfe0
void IN_DeactivateMouse(void)

{
                    /* 0x1dfe0  451  IN_DeactivateMouse */
  if (DAT_2708a010 != 0) {
    if (DAT_2708a124 != 0) {
      SystemParametersInfoA(4,0,&DAT_2708a0a4,0);
    }
    DAT_2708a134 = 0;
  }
  return;
}


// IN_MouseEvent  @ 2701e110
void __cdecl IN_MouseEvent(uint param_1)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x1e110  452  IN_MouseEvent */
  if ((DAT_27089e3c == 0) && (DAT_2708a148 == 0)) {
    iVar2 = 0;
    if (0 < DAT_2708a12c) {
      do {
        uVar1 = 1 << ((byte)iVar2 & 0x1f);
        if (((uVar1 & param_1) != 0) && ((DAT_2708a128 & uVar1) == 0)) {
          (*DAT_2707c988)(iVar2 + 0xf1,1);
        }
        if (((uVar1 & param_1) == 0) && ((DAT_2708a128 & uVar1) != 0)) {
          (*DAT_2707c988)(iVar2 + 0xf1,0);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_2708a12c);
    }
    DAT_2708a128 = param_1;
  }
  return;
}


