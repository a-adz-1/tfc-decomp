// CaltropTouch__10CTFCaltropP11CBaseEntity  @ 001000a4
void CaltropTouch__10CTFCaltropP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *local_14;
  
  iVar2 = *(int *)(*param_1 + 0x198);
  if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = *(int **)(iVar2 + 0x7c);
  }
  iVar2 = (**(code **)(param_2[0x115] + 0xa0))(param_2);
  if (iVar2 == 0) {
    return;
  }
  if ((*(byte *)(*param_2 + 0x1a5) & 2) == 0) {
    return;
  }
  iVar2 = (**(code **)(param_2[0x115] + 0x8c))(param_2);
  if (iVar2 != 0) {
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2);
    if (((iVar2 == 0) || (param_2 == local_14)) ||
       (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) == 0)) {
      param_2[0x68] = (int)((float)param_2[0x68] + 2.0);
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
      iVar1 = *(int *)(*param_1 + 0x198);
      iVar2 = iVar1 + 0x80;
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      (**(code **)(param_2[0x115] + 0x38))(param_2,*param_1,iVar2,0x41200000,0x40000000);
      if (param_2[0x48] == 0) {
        pcVar3 = "SPECTATOR";
      }
      else {
        pcVar3 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
      uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
      if (local_14[0x48] == 0) {
        pcVar3 = "SPECTATOR";
      }
      else {
        pcVar3 = (char *)GetTeamName__Fi(local_14[0x48],
                                         *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                         uVar4);
      }
      uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x198),pcVar3);
      uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x198),uVar4);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Caltrop_Grenade\" against \"%s<%i><%s><%s>\"\n",
                 *(int *)(*local_14 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
    return;
  }
  return;
}


