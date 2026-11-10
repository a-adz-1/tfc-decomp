// EntvarsKeyvalue__FP9entvars_tP14KeyValueData_s  @ 001193c0
void EntvarsKeyvalue__FP9entvars_tP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  longdouble lVar4;
  
  uVar3 = 0;
  while (iVar1 = strcasecmp((&PTR_s_classname_00154604)[uVar3 * 4],*(char **)(param_2 + 4)),
        iVar1 != 0) {
    uVar3 = uVar3 + 1;
    if (0x55 < uVar3) {
      return;
    }
  }
  switch((&gEntvarsDescription)[uVar3 * 4]) {
  case 0:
  case 0xf:
    lVar4 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
    *(float *)((&DAT_00154608)[uVar3 * 4] + param_1) = (float)lVar4;
    break;
  case 1:
  case 0x10:
  case 0x11:
    uVar2 = (*DAT_001755cc)(*(undefined4 *)(param_2 + 8));
    goto LAB_00119462;
  default:
    (*DAT_001755b4)(4,"Bad field in entity!!\n");
    break;
  case 7:
  case 8:
    UTIL_StringToVector__FPfPCc(param_1 + (&DAT_00154608)[uVar3 * 4],*(undefined4 *)(param_2 + 8));
    break;
  case 10:
    uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
LAB_00119462:
    *(undefined4 *)((&DAT_00154608)[uVar3 * 4] + param_1) = uVar2;
  }
  *(undefined4 *)(param_2 + 0xc) = 1;
  return;
}


