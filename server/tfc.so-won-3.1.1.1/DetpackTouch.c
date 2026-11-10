// DetpackTouch__8CDetpackP11CBaseEntity  @ 00099b18
void DetpackTouch__8CDetpackP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *local_8;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      local_8 = (int *)0x0;
      goto LAB_00099b67;
    }
  }
  local_8 = *(int **)(iVar1 + 0x7c);
LAB_00099b67:
  iVar1 = (**(code **)(param_2[0x115] + 0x2c))(param_2);
  if ((iVar1 == 2) && (*(int *)(*param_2 + 0x20c) == 1)) {
    iVar1 = (**(code **)(param_2[0x115] + 0x8c))(param_2);
    if (iVar1 != 0) {
      iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(local_8,param_2);
      if (iVar1 == 0) {
        if (birthday == 1) {
          iVar1 = *(int *)(*local_8 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          iVar2 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          pcVar3 = "#Detpack_disarm_bday";
        }
        else {
          iVar1 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          iVar2 = *(int *)(*local_8 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          pcVar3 = "#Detpack_disarm";
        }
        UTIL_ClientPrintAll__FiPCcN41(1,pcVar3,iVar2,iVar1,0,0);
        if (local_8[0x48] == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          pcVar3 = (char *)GetTeamName__Fi(local_8[0x48]);
        }
        uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*local_8 + 0x208),pcVar3);
        uVar4 = (*DAT_0019f864)(*(undefined4 *)(*local_8 + 0x208),uVar4);
        if (param_2[0x48] == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],
                                           *(int *)(*local_8 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                           uVar4);
        }
        uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
        uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%s><%s>\" triggered \"Detpack_Disarmed\" against \"%s<%i><%s><%s>\"\n",
                   *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
        TF_AddFrags__11CBasePlayeri(param_2,1);
        dremove__FP11CBaseEntity(param_1);
      }
    }
  }
  return;
}


