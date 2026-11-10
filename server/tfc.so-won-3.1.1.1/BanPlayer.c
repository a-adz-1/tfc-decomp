// BanPlayer__FP11CBaseEntity  @ 000fa5bc
void BanPlayer__FP11CBaseEntity(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208));
  uVar1 = UTIL_VarArgs__FPce("banid 30 %s kick\n",uVar1);
  (*DAT_0019f73c)(uVar1);
  uVar1 = UTIL_VarArgs__FPce(FUN_00153954,param_1[0x83] + *(int *)(gpGlobals + 0x98));
  (*DAT_0019f73c)(uVar1);
  iVar2 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208));
  if (iVar2 != -1) {
    uVar1 = UTIL_VarArgs__FPce("kick # %d\n",iVar2);
    (*DAT_0019f73c)(uVar1);
  }
  return;
}


