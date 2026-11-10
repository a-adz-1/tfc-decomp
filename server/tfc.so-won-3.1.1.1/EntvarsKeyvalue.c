// EntvarsKeyvalue__FP9entvars_sP14KeyValueData_s  @ 0011f654
void EntvarsKeyvalue__FP9entvars_sP14KeyValueData_s(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *__dest;
  longdouble lVar6;
  char local_88;
  char local_87 [131];
  
  uVar5 = 0;
  while( true ) {
    iVar2 = strcasecmp((&PTR_s_classname_00171c44)[uVar5 * 4],*(char **)(param_2 + 4));
    if (iVar2 == 0) break;
    uVar5 = uVar5 + 1;
    if (0x55 < uVar5) {
      return;
    }
  }
  switch((&gEntvarsDescription)[uVar5 * 4]) {
  case 0:
  case 0xf:
    lVar6 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)((&DAT_00171c48)[uVar5 * 4] + param_1) = (float)lVar6;
    break;
  case 1:
  case 0x10:
  case 0x11:
    uVar3 = (*DAT_0019f7ac)(*(undefined4 *)(param_2 + 8));
    goto LAB_0011f742;
  default:
    (*DAT_0019f794)(4,"Bad field in entity!!\n");
    break;
  case 7:
  case 8:
    iVar2 = (&DAT_00171c48)[uVar5 * 4];
    __dest = &local_88;
    strcpy(__dest,*(char **)(param_2 + 8));
    iVar4 = 0;
    do {
      lVar6 = (longdouble)__strtod_internal(__dest,0,0);
      *(float *)(param_1 + iVar2 + iVar4 * 4) = (float)lVar6;
      cVar1 = *__dest;
      if (cVar1 == '\0') break;
      do {
        if (cVar1 == ' ') break;
        __dest = __dest + 1;
        cVar1 = *__dest;
      } while (cVar1 != '\0');
      if (cVar1 == '\0') break;
      __dest = __dest + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    if (iVar4 < 2) {
      while (iVar4 = iVar4 + 1, iVar4 < 3) {
        *(undefined4 *)(param_1 + iVar2 + iVar4 * 4) = 0;
      }
    }
    break;
  case 10:
    uVar3 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
LAB_0011f742:
    *(undefined4 *)((&DAT_00171c48)[uVar5 * 4] + param_1) = uVar3;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


