// ScheduleInList__12CBaseMonsterPCcPP10Schedule_ti  @ 000a70e0
undefined4
ScheduleInList__12CBaseMonsterPCcPP10Schedule_ti
          (undefined4 *param_1,char *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == (char *)0x0) {
    (*DAT_001755b4)(1,"%s set to unnamed schedule!\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98))
    ;
  }
  else {
    iVar2 = 0;
    if (0 < param_4) {
      do {
        iVar1 = *(int *)(param_3 + iVar2 * 4);
        if (*(int *)(iVar1 + 0x10) == 0) {
          (*DAT_001755b4)(1,"Unnamed schedule!\n");
        }
        else {
          iVar1 = strcasecmp(param_2,*(char **)(iVar1 + 0x10));
          if (iVar1 == 0) {
            return *(undefined4 *)(param_3 + iVar2 * 4);
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_4);
    }
  }
  return 0;
}


