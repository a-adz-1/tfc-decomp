// Cvar_CompleteVariable  @ 1006a570
undefined4 Cvar_CompleteVariable(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* 0x6a570  11  Cvar_CompleteVariable */
  uVar4 = 0;
  iVar2 = FUN_10060490(param_1);
  puVar1 = DAT_10983fb4;
  if (iVar2 == 0) {
    return 0;
  }
  do {
    if (puVar1 == (undefined4 *)0x0) {
      return uVar4;
    }
    iVar3 = FUN_10060540(param_1,*puVar1,iVar2);
    if (iVar3 == 0) {
      iVar3 = FUN_10060490(*puVar1);
      if (iVar3 == iVar2) {
        return *puVar1;
      }
      uVar4 = *puVar1;
    }
    puVar1 = (undefined4 *)puVar1[4];
  } while( true );
}


// Cvar_Set  @ 1006a5e0
void Cvar_Set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
                    /* 0x6a5e0  12  Cvar_Set */
  iVar1 = FUN_1006a4b0(param_1);
  if (iVar1 == 0) {
    Con_DPrintf(s_Cvar_Set__variable__s_not_found_100d56c0,param_1);
    return;
  }
  iVar2 = FUN_10060510(*(undefined4 *)(iVar1 + 4),param_2);
  if ((*(uint *)(iVar1 + 8) & 2) != 0) {
    if (DAT_1099e680 == 0) {
      uVar3 = FUN_10060300(param_1,param_2,0x200);
      FUN_10065640(uVar3);
      uVar3 = FUN_10060300();
      FUN_1000b860(s_fullserverinfo___s__100d56e4,uVar3);
      if (DAT_1099e680 == 0) goto LAB_1006a6b0;
    }
    FUN_10065640(&DAT_109a2c14,param_1,param_2,0xc4);
    if ((iVar2 != 0) && (2 < DAT_1099e680)) {
      FUN_10060b00(&DAT_1099e6ec,4);
      uVar3 = FUN_100626e0(s_setinfo___s____s__100d56fc,param_1,param_2);
      FUN_10062180(&DAT_1099e6ec,uVar3);
    }
  }
LAB_1006a6b0:
  if (((*(uint *)(iVar1 + 8) & 4) != 0) && (iVar2 != 0)) {
    FUN_10017b40(s___s______s__100d5710,param_1,param_2);
  }
  FUN_1002c050(*(undefined4 *)(iVar1 + 4));
  iVar2 = FUN_10060490(param_2);
  uVar3 = FUN_1002c100(iVar2 + 1);
  *(undefined4 *)(iVar1 + 4) = uVar3;
  FUN_10060440(uVar3,param_2);
  fVar4 = (float10)FUN_100606b0(*(undefined4 *)(iVar1 + 4));
  *(float *)(iVar1 + 0xc) = (float)fVar4;
  return;
}


// Cvar_SetValue  @ 1006a710
void Cvar_SetValue(undefined4 param_1,float param_2)

{
  char local_20 [32];
  
                    /* 0x6a710  13  Cvar_SetValue */
  _sprintf(local_20,&DAT_100d5720,(double)param_2);
  Cvar_Set(param_1,local_20);
  return;
}


// Cvar_VariableInt  @ 1006a520
undefined4 Cvar_VariableInt(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x6a520  14  Cvar_VariableInt */
  iVar1 = FUN_1006a4b0(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_10060600(*(undefined4 *)(iVar1 + 4));
  return uVar2;
}


// Cvar_VariableString  @ 1006a550
undefined * Cvar_VariableString(undefined4 param_1)

{
  int iVar1;
  
                    /* 0x6a550  15  Cvar_VariableString */
  iVar1 = FUN_1006a4b0(param_1);
  if (iVar1 == 0) {
    return PTR_DAT_100d56b8;
  }
  return *(undefined **)(iVar1 + 4);
}


// Cvar_VariableValue  @ 1006a4f0
float10 Cvar_VariableValue(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
                    /* 0x6a4f0  16  Cvar_VariableValue */
  iVar1 = FUN_1006a4b0(param_1);
  if (iVar1 == 0) {
    return (float10)0.0;
  }
  fVar2 = (float10)FUN_100606b0(*(undefined4 *)(iVar1 + 4));
  return fVar2;
}


