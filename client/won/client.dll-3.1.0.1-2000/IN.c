// IN_Accumulate  @ 2701e640
void IN_Accumulate(void)

{
  int iVar1;
  
                    /* 0x1e640  447  IN_Accumulate */
  if (((DAT_2707cf5c == 0) && (DAT_2707d268 == 0)) && (DAT_2707d254 != 0)) {
    GetCursorPos((LPPOINT)&DAT_2707d1f8);
    iVar1 = (*DAT_27073b20)();
    DAT_2707d260 = DAT_2707d260 + (DAT_2707d1f8 - iVar1);
    iVar1 = (*DAT_27073b24)();
    DAT_2707d198 = DAT_2707d198 + (DAT_2707d1fc - iVar1);
    FUN_2701e2f0();
    return;
  }
  return;
}


// IN_ActivateMouse  @ 2701e1a0
void IN_ActivateMouse(void)

{
                    /* 0x1e1a0  448  IN_ActivateMouse */
  if (DAT_2707d130 != 0) {
    if (DAT_2707d19c != 0) {
      DAT_2707d244 = SystemParametersInfoA(4,0,&DAT_270600c8,0);
    }
    DAT_2707d254 = 1;
  }
  return;
}


// IN_ClearStates  @ 2701e6b0
void IN_ClearStates(void)

{
                    /* 0x1e6b0  449  IN_ClearStates */
  if (DAT_2707d254 != 0) {
    DAT_2707d260 = 0;
    DAT_2707d198 = 0;
    DAT_2707d248 = 0;
  }
  return;
}


// IN_DeactivateMouse  @ 2701e1e0
void IN_DeactivateMouse(void)

{
                    /* 0x1e1e0  450  IN_DeactivateMouse */
  if (DAT_2707d130 != 0) {
    if (DAT_2707d244 != 0) {
      SystemParametersInfoA(4,0,&DAT_2707d1c4,0);
    }
    DAT_2707d254 = 0;
  }
  return;
}


// IN_MouseEvent  @ 2701e310
void __cdecl IN_MouseEvent(uint param_1)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x1e310  451  IN_MouseEvent */
  if ((DAT_2707cf5c == 0) && (DAT_2707d268 == 0)) {
    iVar2 = 0;
    if (0 < DAT_2707d24c) {
      do {
        uVar1 = 1 << ((byte)iVar2 & 0x1f);
        if (((uVar1 & param_1) != 0) && ((DAT_2707d248 & uVar1) == 0)) {
          (*DAT_27073b60)(iVar2 + 0xf1,1);
        }
        if (((uVar1 & param_1) == 0) && ((DAT_2707d248 & uVar1) != 0)) {
          (*DAT_27073b60)(iVar2 + 0xf1,0);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_2707d24c);
    }
    DAT_2707d248 = param_1;
  }
  return;
}


