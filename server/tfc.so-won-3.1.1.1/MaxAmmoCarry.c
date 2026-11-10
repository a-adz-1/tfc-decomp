// MaxAmmoCarry__Fi  @ 00123328
undefined4 MaxAmmoCarry__Fi(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = iVar3 * 0x2c;
    if ((*(char **)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 8) != (char *)0x0) &&
       (iVar2 = strcmp((char *)(param_1 + *(int *)(gpGlobals + 0x98)),
                       *(char **)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 8)), iVar2 == 0)) {
      return *(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0xc);
    }
    if ((*(char **)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x10) != (char *)0x0) &&
       (iVar2 = strcmp((char *)(param_1 + *(int *)(gpGlobals + 0x98)),
                       *(char **)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x10)), iVar2 == 0))
    break;
    iVar3 = iVar3 + 1;
    if (0x1f < iVar3) {
      (*DAT_0019f794)(1,"MaxAmmoCarry() doesn\'t recognize \'%s\'!\n",
                      param_1 + *(int *)(gpGlobals + 0x98));
      return 0xffffffff;
    }
  }
  return *(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x14);
}


