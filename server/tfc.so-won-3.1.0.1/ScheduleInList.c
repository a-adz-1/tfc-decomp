// ScheduleInList__12CBaseMonsterPCcPP10Schedule_ti  @ 00090110
int ScheduleInList__12CBaseMonsterPCcPP10Schedule_ti
              (undefined4 *param_1,char *param_2,int *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == (char *)0x0) {
    (*DAT_001a7f34)(1,"%s set to unnamed schedule!\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98))
    ;
    return 0;
  }
  iVar3 = 0;
  if (0 < (int)param_4) {
    uVar1 = param_4 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          if (*(int *)(*param_3 + 0x10) == 0) {
            (*DAT_001a7f34)(1,"Unnamed schedule!\n");
          }
          else {
            iVar3 = strcasecmp(param_2,*(char **)(*param_3 + 0x10));
            if (iVar3 == 0) {
              return *param_3;
            }
          }
          param_3 = param_3 + 1;
          iVar3 = 1;
        }
        if (*(int *)(*param_3 + 0x10) == 0) {
          (*DAT_001a7f34)(1,"Unnamed schedule!\n");
        }
        else {
          iVar2 = strcasecmp(param_2,*(char **)(*param_3 + 0x10));
          if (iVar2 == 0) {
            return *param_3;
          }
        }
        param_3 = param_3 + 1;
        iVar3 = iVar3 + 1;
      }
      if (*(int *)(*param_3 + 0x10) == 0) {
        (*DAT_001a7f34)(1,"Unnamed schedule!\n");
      }
      else {
        iVar2 = strcasecmp(param_2,*(char **)(*param_3 + 0x10));
        if (iVar2 == 0) {
          return *param_3;
        }
      }
      param_3 = param_3 + 1;
      iVar3 = iVar3 + 1;
      if ((int)param_4 <= iVar3) {
        return 0;
      }
    }
    do {
      if (*(int *)(*param_3 + 0x10) == 0) {
        (*DAT_001a7f34)(1,"Unnamed schedule!\n");
      }
      else {
        iVar2 = strcasecmp(param_2,*(char **)(*param_3 + 0x10));
        if (iVar2 == 0) {
          return *param_3;
        }
      }
      if (*(int *)(param_3[1] + 0x10) == 0) {
        (*DAT_001a7f34)(1,"Unnamed schedule!\n");
      }
      else {
        iVar2 = strcasecmp(param_2,*(char **)(param_3[1] + 0x10));
        if (iVar2 == 0) {
          return param_3[1];
        }
      }
      if (*(int *)(param_3[2] + 0x10) == 0) {
        (*DAT_001a7f34)(1,"Unnamed schedule!\n");
      }
      else {
        iVar2 = strcasecmp(param_2,*(char **)(param_3[2] + 0x10));
        if (iVar2 == 0) {
          return param_3[2];
        }
      }
      if (*(int *)(param_3[3] + 0x10) == 0) {
        (*DAT_001a7f34)(1,"Unnamed schedule!\n");
      }
      else {
        iVar2 = strcasecmp(param_2,*(char **)(param_3[3] + 0x10));
        if (iVar2 == 0) {
          return param_3[3];
        }
      }
      param_3 = param_3 + 4;
      iVar3 = iVar3 + 4;
    } while (iVar3 < (int)param_4);
  }
  return 0;
}


