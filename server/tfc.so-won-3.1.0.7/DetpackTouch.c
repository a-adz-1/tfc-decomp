// DetpackTouch__8CDetpackP11CBaseEntity  @ 0009a5f8
void DetpackTouch__8CDetpackP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_0009a63e;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_0009a63e:
  iVar1 = (**(code **)(param_2[0x111] + 0x2c))(param_2);
  if ((iVar1 == 2) && (*(int *)(*param_2 + 0x20c) == 1)) {
    iVar1 = (**(code **)(param_2[0x111] + 0x8c))(param_2);
    if (iVar1 != 0) {
      iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(piVar2,param_2);
      if (iVar1 == 0) {
        if (birthday == 1) {
          iVar1 = *(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          iVar3 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          pcVar4 = "#Detpack_disarm_bday";
        }
        else {
          iVar1 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          iVar3 = *(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
          pcVar4 = "#Detpack_disarm";
        }
        UTIL_ClientPrintAll__FiPCcN41(1,pcVar4,iVar3,iVar1,0,0);
        if (piVar2[0x48] == 0) {
          pcVar4 = "SPECTATOR";
        }
        else {
          pcVar4 = (char *)GetTeamName__Fi(piVar2[0x48]);
        }
        uVar5 = (*DAT_001c11f4)(*(undefined4 *)(*piVar2 + 0x208),pcVar4);
        uVar5 = (*DAT_001c11e4)(*(undefined4 *)(*piVar2 + 0x208),uVar5);
        if (param_2[0x48] == 0) {
          pcVar4 = "SPECTATOR";
        }
        else {
          pcVar4 = (char *)GetTeamName__Fi(param_2[0x48],
                                           *(int *)(*piVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                           uVar5);
        }
        uVar5 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar4);
        uVar5 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%u><%s>\" triggered \"Detpack_Disarmed\" against \"%s<%i><%u><%s>\"\n",
                   *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar5);
        TF_AddFrags__11CBasePlayeri(param_2,1);
        dremove__FP11CBaseEntity(param_1);
      }
    }
  }
  return;
}


