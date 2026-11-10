// Cmd_AddCommand  @ 10003fa0
void Cmd_AddCommand(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  
                    /* 0x3fa0  3  Cmd_AddCommand */
  if (DAT_100c1560 != 0) {
    FUN_10085dc0(s_Cmd_AddCommand_after_host_initia_100bf2d0);
  }
  pcVar1 = (char *)Cvar_VariableString(param_1);
  puVar3 = DAT_100bf160;
  if (*pcVar1 != '\0') {
    Con_Printf(s_Cmd_AddCommand___s_already_defin_100bf2f8,param_1);
    return;
  }
  while( true ) {
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)FUN_1002c680(0x10);
      puVar3[1] = param_1;
      puVar3[2] = param_2;
      *puVar3 = DAT_100bf160;
      puVar3[3] = 0;
      DAT_100bf160 = puVar3;
      return;
    }
    iVar2 = FUN_10060510(param_1,puVar3[1]);
    if (iVar2 == 0) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  Con_Printf(s_Cmd_AddCommand___s_already_defin_100bf328,param_1);
  return;
}


// Cmd_Argc  @ 10003e90
undefined4 Cmd_Argc(void)

{
                    /* 0x3e90  4  Cmd_Argc */
  return DAT_100dff18;
}


// Cmd_Args  @ 10003ec0
undefined4 Cmd_Args(void)

{
                    /* 0x3ec0  5  Cmd_Args */
  return DAT_100bf15c;
}


// Cmd_Argv  @ 10003ea0
undefined * Cmd_Argv(uint param_1)

{
                    /* 0x3ea0  6  Cmd_Argv */
  if (DAT_100dff18 <= param_1) {
    return PTR_DAT_100bf158;
  }
  return (undefined *)(&DAT_100dff20)[param_1];
}


