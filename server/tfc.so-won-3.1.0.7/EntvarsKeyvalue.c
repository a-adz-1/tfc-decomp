// EntvarsKeyvalue__FP9entvars_sP14KeyValueData_s  @ 0011d5ec
void EntvarsKeyvalue__FP9entvars_sP14KeyValueData_s(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  longdouble lVar5;
  
  uVar3 = 0;
  iVar4 = 0;
  do {
    iVar1 = strcasecmp(*(char **)((int)&PTR_s_classname_0016cb24 + iVar4),*(char **)(param_2 + 4));
    if (iVar1 == 0) {
      switch(*(undefined4 *)((int)&gEntvarsDescription + iVar4)) {
      case 0:
      case 0xf:
        lVar5 = (longdouble)__strtod_internal(*(undefined4 *)(param_2 + 8),0,0);
        *(float *)(*(int *)((int)&DAT_0016cb28 + iVar4) + param_1) = (float)lVar5;
        break;
      case 1:
      case 0x10:
      case 0x11:
        uVar2 = (*DAT_001c112c)(*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(*(int *)((int)&DAT_0016cb28 + iVar4) + param_1) = uVar2;
        break;
      default:
        (*DAT_001c1114)(4,"Bad field in entity!!\n");
        break;
      case 7:
      case 8:
        UTIL_StringToVector__FPfPCc
                  (param_1 + *(int *)((int)&DAT_0016cb28 + iVar4),*(undefined4 *)(param_2 + 8));
        break;
      case 10:
        uVar2 = __strtol_internal(*(undefined4 *)(param_2 + 8),0,10,0);
        *(undefined4 *)(*(int *)((int)&DAT_0016cb28 + iVar4) + param_1) = uVar2;
      }
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
    iVar4 = iVar4 + 0x10;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x56);
  return;
}


