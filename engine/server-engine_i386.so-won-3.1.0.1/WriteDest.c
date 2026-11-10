// WriteDest_Parm  @ 0006fe84
undefined1 * WriteDest_Parm(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  switch(param_1) {
  case 0:
    puVar2 = &DAT_00186fa4;
    break;
  case 1:
  case 8:
    iVar1 = NUM_FOR_EDICT(gMsgEntity);
    if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
      Host_Error("WriteDest_Parm: not a client");
    }
    if (param_1 == 1) {
      puVar2 = (undefined1 *)(DAT_001ab4e4 + -0x4fe0 + iVar1 * 0x5054);
    }
    else {
      puVar2 = (undefined1 *)(DAT_001ab4e4 + -0x2b44 + iVar1 * 0x5054);
    }
    break;
  case 2:
    puVar2 = &DAT_00187f54;
    break;
  case 3:
    puVar2 = &DAT_0018a2c4;
    break;
  case 4:
  case 5:
    puVar2 = &DAT_00189eb4;
    break;
  default:
    Host_Error("WriteDest_Parm: bad destination=%d",param_1);
    puVar2 = (undefined1 *)0x0;
  }
  return puVar2;
}


