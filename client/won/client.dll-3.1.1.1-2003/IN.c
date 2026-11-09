// IN_Accumulate  @ 27027900
void IN_Accumulate(void)

{
  int iVar1;
  
                    /* 0x27900  504  IN_Accumulate */
  if (((DAT_270b5754 == 0) && (DAT_270b5a18 == 0)) && (DAT_270b5a04 != 0)) {
    GetCursorPos((LPPOINT)&DAT_270b59a8);
    iVar1 = (*DAT_270a8248)();
    DAT_270b5a10 = DAT_270b5a10 + (DAT_270b59a8 - iVar1);
    iVar1 = (*DAT_270a824c)();
    DAT_270b594c = DAT_270b594c + (DAT_270b59ac - iVar1);
    FUN_270275b0();
    return;
  }
  return;
}


// IN_ActivateMouse  @ 27027460
void IN_ActivateMouse(void)

{
                    /* 0x27460  505  IN_ActivateMouse */
  if (DAT_270b58e4 != 0) {
    if (DAT_270b5950 != 0) {
      DAT_270b59f4 = SystemParametersInfoA(4,0,&DAT_27076fdc,0);
    }
    DAT_270b5a04 = 1;
  }
  return;
}


// IN_ClearStates  @ 27027970
void IN_ClearStates(void)

{
                    /* 0x27970  506  IN_ClearStates */
  if (DAT_270b5a04 != 0) {
    DAT_270b5a10 = 0;
    DAT_270b594c = 0;
    DAT_270b59f8 = 0;
  }
  return;
}


// IN_DeactivateMouse  @ 270274a0
void IN_DeactivateMouse(void)

{
                    /* 0x274a0  507  IN_DeactivateMouse */
  if (DAT_270b58e4 != 0) {
    if (DAT_270b59f4 != 0) {
      SystemParametersInfoA(4,0,&DAT_270b5978,0);
    }
    DAT_270b5a04 = 0;
  }
  return;
}


// IN_MouseEvent  @ 270275d0
void __cdecl IN_MouseEvent(uint param_1)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x275d0  508  IN_MouseEvent */
  if ((DAT_270b5754 == 0) && (DAT_270b5a18 == 0)) {
    iVar2 = 0;
    if (0 < DAT_270b59fc) {
      do {
        uVar1 = 1 << ((byte)iVar2 & 0x1f);
        if (((uVar1 & param_1) != 0) && ((DAT_270b59f8 & uVar1) == 0)) {
          (*DAT_270a8288)(iVar2 + 0xf1,1);
        }
        if (((uVar1 & param_1) == 0) && ((DAT_270b59f8 & uVar1) != 0)) {
          (*DAT_270a8288)(iVar2 + 0xf1,0);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_270b59fc);
    }
    DAT_270b59f8 = param_1;
  }
  return;
}


