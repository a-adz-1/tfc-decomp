// SetLine__9TokenLinePCc  @ 000cad98
uint SetLine__9TokenLinePCc(char *param_1,char *param_2)

{
  size_t sVar1;
  void *pvVar2;
  uint uVar3;
  char *local_8;
  
  param_1[0x1200] = '\0';
  param_1[0x1201] = '\0';
  param_1[0x1202] = '\0';
  param_1[0x1203] = '\0';
  if ((param_2 == (char *)0x0) || (sVar1 = strlen(param_2), 0x7fe < sVar1)) {
    memset(param_1 + 0x800,0,0x800);
    pvVar2 = memset(param_1,0,0x800);
    uVar3 = (uint)pvVar2 & 0xffffff00;
  }
  else {
    strncpy(param_1 + 0x800,param_2,0x7ff);
    param_1[0xfff] = '\0';
    strncpy(param_1,param_2,0x7ff);
    param_1[0x7ff] = '\0';
    local_8 = param_1;
    while ((*local_8 != '\0' && (*(int *)(param_1 + 0x1200) < 0x80))) {
      for (; (*local_8 != '\0' && ((*local_8 < '!' || (*local_8 == '\x7f')))); local_8 = local_8 + 1
          ) {
      }
      if (*local_8 != '\0') {
        *(char **)(param_1 + *(int *)(param_1 + 0x1200) * 4 + 0x1000) = local_8;
        if (*local_8 == '\"') {
          local_8 = local_8 + 1;
          *(char **)(param_1 + *(int *)(param_1 + 0x1200) * 4 + 0x1000) = local_8;
          for (; (*local_8 != '\0' && (*local_8 != '\"')); local_8 = local_8 + 1) {
          }
        }
        else {
          *(char **)(param_1 + *(int *)(param_1 + 0x1200) * 4 + 0x1000) = local_8;
          for (; ((*local_8 != '\0' && (' ' < *local_8)) && (*local_8 < '\x7f'));
              local_8 = local_8 + 1) {
          }
        }
        *(int *)(param_1 + 0x1200) = *(int *)(param_1 + 0x1200) + 1;
        if (*local_8 != '\0') {
          *local_8 = '\0';
          local_8 = local_8 + 1;
        }
      }
    }
    uVar3 = CONCAT31((int3)((uint)local_8 >> 8),*(int *)(param_1 + 0x1200) != 0x80);
  }
  return uVar3;
}


