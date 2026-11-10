// UpdateOnRemove__11CBaseEntity  @ 000f6810
void UpdateOnRemove__11CBaseEntity(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x1a6) & 1) != 0) && (iVar1 = 0, 0 < DAT_0019fb3c)) {
    do {
      if (*(int *)(DAT_0019fb30 + 8 + iVar1 * 0x18) == iVar2) {
        *(undefined4 *)(DAT_0019fb30 + 8 + iVar1 * 0x18) = 0;
        iVar2 = *param_1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0019fb3c);
  }
  if (*(int *)(iVar2 + 4) != 0) {
    EntitySetState__12CGlobalStatei12GLOBALESTATE(&gGlobalState,*(int *)(iVar2 + 4),2);
  }
  return;
}


