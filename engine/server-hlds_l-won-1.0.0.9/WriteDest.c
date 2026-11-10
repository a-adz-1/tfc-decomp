// WriteDest_Parm  @ 0806e980
undefined * WriteDest_Parm(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  
  switch(param_1) {
  case 0:
    puVar2 = &DAT_08140444;
    break;
  case 1:
    iVar1 = NUM_FOR_EDICT(gMsgEntity);
    if ((iVar1 < 1) || (svs < iVar1)) {
      Host_Error("WriteDest_Parm: not a client");
    }
    puVar2 = (undefined *)(DAT_0816dd10 + -0x5240 + iVar1 * 0x52b8);
    break;
  case 2:
    puVar2 = &DAT_081413f8;
    break;
  case 3:
    puVar2 = &DAT_08143774;
    break;
  case 4:
  case 5:
    puVar2 = &DAT_08143360;
    break;
  default:
    Host_Error("WriteDest_Parm: bad destination=%d",param_1);
    puVar2 = (undefined *)0x0;
  }
  return puVar2;
}


