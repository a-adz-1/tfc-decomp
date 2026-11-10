// SetLastWeapon__11CBasePlayer  @ 000e01b8
void SetLastWeapon__11CBasePlayer(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x8bc) = 0;
  if ((*(int *)(param_1 + 0xd80) == 0) && (*(int *)(param_1 + 0x8c0) != 0)) {
    iVar2 = 0;
    do {
      for (iVar3 = *(int *)(param_1 + 0x89c + iVar2 * 4); iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 0x468)) {
        iVar1 = *(int *)(iVar3 + 0x46c) * 0x2c;
        if ((*(int *)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x18) != 0) &&
           (iVar1 = strcmp(*(char **)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x18),
                           *(char **)(param_1 + 0x8c0)), iVar1 == 0)) goto LAB_000e027e;
      }
      for (iVar3 = *(int *)(param_1 + 0x8a0 + iVar2 * 4); iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 0x468)) {
        iVar1 = *(int *)(iVar3 + 0x46c) * 0x2c;
        if ((*(int *)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x18) != 0) &&
           (iVar1 = strcmp(*(char **)(_15CBasePlayerItem_ItemInfoArray + iVar1 + 0x18),
                           *(char **)(param_1 + 0x8c0)), iVar1 == 0)) {
LAB_000e027e:
          *(int *)(param_1 + 0x8bc) = iVar3;
          return;
        }
      }
      iVar2 = iVar2 + 2;
    } while (iVar2 < 6);
  }
  return;
}


