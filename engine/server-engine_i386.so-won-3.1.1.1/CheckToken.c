// CheckToken__9TokenLinePc  @ 000cafe8
undefined * CheckToken__9TokenLinePc(int param_1,char *param_2)

{
  int iVar1;
  undefined *local_c;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x1200) <= local_8) {
      return (undefined *)0x0;
    }
    if ((*(int *)(local_8 * 4 + param_1 + 0x1000) != 0) &&
       (iVar1 = strcmp(param_2,*(char **)(local_8 * 4 + param_1 + 0x1000)), iVar1 == 0)) break;
    local_8 = local_8 + 1;
  }
  if (local_8 + 1 != *(int *)(param_1 + 0x1200)) {
    return *(undefined **)((local_8 + 1) * 4 + param_1 + 0x1000);
  }
  local_c = &DAT_000ee4f2;
  return local_c;
}


