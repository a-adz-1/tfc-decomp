// CheckParam__13SystemWrapperPc  @ 00097d40
undefined * CheckParam__13SystemWrapperPc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = COM_CheckParm(param_2);
  if (iVar1 == 0) {
    puVar2 = (undefined *)0x0;
  }
  else if (iVar1 + 1 < com_argc) {
    puVar2 = *(undefined **)(iVar1 * 4 + com_argv + 4);
  }
  else {
    puVar2 = &DAT_000e7a97;
  }
  return puVar2;
}


