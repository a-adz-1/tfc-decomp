// MaxAmmoCarry__Fi  @ 0011a1d0
undefined4 MaxAmmoCarry__Fi(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = iVar3 * 0x2c;
    if ((*(int *)(&DAT_00182a88 + iVar1) != 0) &&
       (iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + param_1),
                       *(char **)(&DAT_00182a88 + iVar1)), iVar2 == 0)) {
      return *(undefined4 *)(&DAT_00182a8c + iVar1);
    }
    iVar1 = iVar3 * 0x2c;
    if ((*(int *)(&DAT_00182a90 + iVar1) != 0) &&
       (iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + param_1),
                       *(char **)(&DAT_00182a90 + iVar1)), iVar2 == 0)) break;
    iVar3 = iVar3 + 1;
    if (0x1f < iVar3) {
      (*DAT_001755b4)(1,"MaxAmmoCarry() doesn\'t recognize \'%s\'!\n",
                      param_1 + *(int *)(gpGlobals + 0x98));
      return 0xffffffff;
    }
  }
  return *(undefined4 *)(&DAT_00182a94 + iVar1);
}


