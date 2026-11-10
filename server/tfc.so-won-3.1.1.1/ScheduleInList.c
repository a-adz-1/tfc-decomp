// ScheduleInList__12CBaseMonsterPCcPP10Schedule_ti  @ 000998f4
undefined4
ScheduleInList__12CBaseMonsterPCcPP10Schedule_ti
          (undefined4 *param_1,char *param_2,int param_3,int param_4)

{
  char *__s2;
  int iVar1;
  int iVar2;
  
  if (param_2 == (char *)0x0) {
    (*DAT_0019f794)(1,"%s set to unnamed schedule!\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98))
    ;
  }
  else {
    iVar2 = 0;
    if (0 < param_4) {
      do {
        __s2 = *(char **)(*(int *)(param_3 + iVar2 * 4) + 0x10);
        if (__s2 == (char *)0x0) {
          (*DAT_0019f794)(1,"Unnamed schedule!\n");
        }
        else {
          iVar1 = strcasecmp(param_2,__s2);
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


