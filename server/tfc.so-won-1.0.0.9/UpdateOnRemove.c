// UpdateOnRemove__11CBaseEntity  @ 000f0310
void UpdateOnRemove__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if (((*(byte *)(*param_1 + 0x186) & 1) != 0) && (iVar1 = 0, 0 < DAT_001758dc)) {
    do {
      if (*(int *)(DAT_001758d0 + 8 + iVar1 * 0x18) == *param_1) {
        *(undefined4 *)(DAT_001758d0 + 8 + iVar1 * 0x18) = 0;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_001758dc);
  }
  if (*(int *)(*param_1 + 4) != 0) {
    EntitySetState__12CGlobalStatei12GLOBALESTATE(&gGlobalState,*(undefined4 *)(*param_1 + 4),2);
  }
  return;
}


