// MaxAmmoCarry__Fi  @ 0010f0dc
undefined4 MaxAmmoCarry__Fi(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *local_c;
  int *local_8;
  int local_4;
  
  local_4 = 0;
  iVar2 = 0;
  local_c = (int *)(_15CBasePlayerItem_ItemInfoArray + 8);
  local_8 = local_c;
  while ((iVar3 = iVar2, *local_c == 0 ||
         (iVar1 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + param_1),(char *)*local_8),
         iVar1 != 0))) {
    if ((*(int *)(_15CBasePlayerItem_ItemInfoArray + iVar2 + 0x10) != 0) &&
       (iVar1 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + param_1),
                       *(char **)(_15CBasePlayerItem_ItemInfoArray + iVar2 + 0x10)), iVar1 == 0)) {
LAB_0010f230:
      return *(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar3 + 0x14);
    }
    iVar3 = iVar2 + 0x2c;
    if ((local_c[0xb] != 0) &&
       (iVar1 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + param_1),(char *)local_8[0xb]),
       iVar1 == 0)) break;
    if ((*(int *)(_15CBasePlayerItem_ItemInfoArray + iVar2 + 0x3c) != 0) &&
       (iVar1 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + param_1),
                       *(char **)(_15CBasePlayerItem_ItemInfoArray + iVar2 + 0x3c)), iVar1 == 0))
    goto LAB_0010f230;
    local_8 = local_8 + 0x16;
    local_c = local_c + 0x16;
    iVar2 = iVar2 + 0x58;
    local_4 = local_4 + 2;
    if (0x1f < local_4) {
      (*DAT_001a7f34)(1,"MaxAmmoCarry() doesn\'t recognize \'%s\'!\n",
                      param_1 + *(int *)(gpGlobals + 0x98));
      return 0xffffffff;
    }
  }
  return *(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar3 + 0xc);
}


