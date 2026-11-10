// SetLastWeapon__11CBasePlayer  @ 000e456c
void SetLastWeapon__11CBasePlayer(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x8e4) = 0;
  if ((*(int *)(param_1 + 0xd9c) == 0) && (*(int *)(param_1 + 0x8e8) != 0)) {
    iVar3 = 0;
    do {
      for (iVar1 = *(int *)(param_1 + 0x8c4 + iVar3 * 4); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 0x478)) {
        if ((*(char **)(_15CBasePlayerItem_ItemInfoArray + *(int *)(iVar1 + 0x47c) * 0x2c + 0x18) !=
             (char *)0x0) &&
           (iVar2 = strcmp(*(char **)(_15CBasePlayerItem_ItemInfoArray +
                                     *(int *)(iVar1 + 0x47c) * 0x2c + 0x18),
                           *(char **)(param_1 + 0x8e8)), iVar2 == 0)) {
          *(int *)(param_1 + 0x8e4) = iVar1;
          return;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
  }
  return;
}


