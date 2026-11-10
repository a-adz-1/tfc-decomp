// WriteDest_Parm  @ 0008b7c0
undefined * WriteDest_Parm(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  switch(param_1) {
  case 0:
    puVar2 = &DAT_003a78c8;
    break;
  case 1:
  case 8:
    iVar1 = NUM_FOR_EDICT(gMsgEntity);
    if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
      Host_Error("WriteDest_Parm: not a client");
    }
    if (param_1 == 1) {
      puVar2 = (undefined *)(iVar1 * 0x4eec + DAT_00524284 + -0x4e78);
    }
    else {
      puVar2 = (undefined *)(iVar1 * 0x4eec + DAT_00524284 + -0x2a40);
    }
    break;
  case 2:
    puVar2 = &DAT_003a887c;
    break;
  case 3:
    puVar2 = &DAT_003aa058;
    break;
  case 4:
  case 5:
    puVar2 = &DAT_003a9830;
    break;
  default:
    Host_Error("WriteDest_Parm: bad destination=%d",param_1);
    puVar2 = (undefined *)0x0;
    break;
  case 9:
    puVar2 = &DAT_003a9c44;
  }
  return puVar2;
}


