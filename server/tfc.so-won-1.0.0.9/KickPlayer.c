// KickPlayer__FP11CBaseEntity  @ 000f4380
void KickPlayer__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*DAT_00175684)(*(undefined4 *)(*param_1 + 0x1e8));
  if (iVar1 != -1) {
    uVar2 = UTIL_VarArgs__FPce("kick # %d\n",iVar1);
    (*DAT_0017555c)(uVar2);
  }
  return;
}


