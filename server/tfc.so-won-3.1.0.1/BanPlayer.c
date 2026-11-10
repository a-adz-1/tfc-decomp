// BanPlayer__FP11CBaseEntity  @ 000eb388
void BanPlayer__FP11CBaseEntity(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001a8014)(*(undefined4 *)(*param_1 + 0x208));
  uVar1 = UTIL_VarArgs__FPce("banid 30 %d kick\n",uVar1);
  (*DAT_001a7edc)(uVar1);
  uVar1 = UTIL_VarArgs__FPce("addip 30 %s\n",param_1[0x83] + *(int *)(gpGlobals + 0x98));
  (*DAT_001a7edc)(uVar1);
  KickPlayer__FP11CBaseEntity(param_1);
  return;
}


