// CaltropTouch__10CTFCaltropP11CBaseEntity  @ 000fe57c
void CaltropTouch__10CTFCaltropP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  iVar1 = (**(code **)(param_2[0x111] + 0xa0))(param_2);
  if (iVar1 == 0) {
    return;
  }
  if ((*(byte *)(*param_2 + 0x1a5) & 2) == 0) {
    return;
  }
  iVar1 = (**(code **)(param_2[0x111] + 0x8c))(param_2);
  if (iVar1 != 0) {
    iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2);
    if (((iVar1 == 0) || (param_2 == piVar2)) ||
       (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) == 0)) {
      param_2[0x68] = (int)((float)param_2[0x68] + 2.0);
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
      iVar1 = *(int *)(*param_1 + 0x198) + 0x80;
      if (*(int *)(*param_1 + 0x198) == 0) {
        iVar1 = 0;
      }
      (**(code **)(param_2[0x111] + 0x38))(param_2,*param_1,iVar1,0x41200000,0x40000000);
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
    return;
  }
  return;
}


