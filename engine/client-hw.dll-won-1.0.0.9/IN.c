// IN_ActivateMouse  @ 10020af0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IN_ActivateMouse(void)

{
                    /* 0x20af0  32  IN_ActivateMouse */
  _DAT_10423018 = 1;
  if (DAT_10a3e75c != 0) {
    if (DAT_1042301c != 0) {
      DAT_10423064 = SystemParametersInfoA(4,0,&DAT_100c7e40,0);
    }
    DAT_10423068 = 1;
  }
  return;
}


// IN_ClearStates  @ 100211d0
void IN_ClearStates(void)

{
                    /* 0x211d0  33  IN_ClearStates */
  if (DAT_10423068 != 0) {
    DAT_10a3e7fc = 0;
    DAT_10a3e7cc = 0;
    DAT_10a3e7f0 = 0;
  }
  return;
}


// IN_DeactivateMouse  @ 10020b40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IN_DeactivateMouse(void)

{
                    /* 0x20b40  34  IN_DeactivateMouse */
  _DAT_10423018 = 0;
  if (DAT_10a3e75c != 0) {
    if (DAT_10423064 != 0) {
      SystemParametersInfoA(4,0,&DAT_10423020,0);
    }
    DAT_10423068 = 0;
  }
  return;
}


// IN_HideMouse  @ 10020ae0
void IN_HideMouse(void)

{
                    /* 0x20ae0  35  IN_HideMouse */
  return;
}


// IN_MouseEvent  @ 10020da0
void IN_MouseEvent(uint param_1)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x20da0  36  IN_MouseEvent */
  if (DAT_10423068 != 0) {
    iVar1 = 0;
    if (0 < DAT_10a3e7f4) {
      do {
        uVar2 = 1 << ((byte)iVar1 & 0x1f);
        if (((uVar2 & param_1) != 0) && ((DAT_10a3e7f0 & uVar2) == 0)) {
          Key_Event(iVar1 + 200,1);
        }
        if (((uVar2 & param_1) == 0) && ((DAT_10a3e7f0 & uVar2) != 0)) {
          Key_Event(iVar1 + 200,0);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_10a3e7f4);
      DAT_10a3e7f0 = param_1;
      return;
    }
    DAT_10a3e7f0 = param_1;
  }
  return;
}


// IN_ShowMouse  @ 10020ad0
void IN_ShowMouse(void)

{
                    /* 0x20ad0  37  IN_ShowMouse */
  return;
}


// IN_UpdateClipCursor  @ 10020ac0
void IN_UpdateClipCursor(void)

{
                    /* 0x20ac0  38  IN_UpdateClipCursor */
  return;
}


