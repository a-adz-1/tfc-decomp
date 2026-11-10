// KickPlayer__FP11CBaseEntity  @ 000eb334
void KickPlayer__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208));
  if (iVar1 != -1) {
    uVar2 = UTIL_VarArgs__FPce("kick # %d\n",iVar1);
    (*DAT_001a7edc)(uVar2);
  }
  return;
}


