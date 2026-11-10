// BanPlayer__FP11CBaseEntity  @ 000f43c0
void BanPlayer__FP11CBaseEntity(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = UTIL_VarArgs__FPce("addip 30 %s\n",*(int *)(param_1 + 0x20c) + *(int *)(gpGlobals + 0x98))
  ;
  (*DAT_0017555c)(uVar1);
  KickPlayer__FP11CBaseEntity(param_1);
  return;
}


