// UpdateOnRemove__11CBaseEntity  @ 000e6b64
void UpdateOnRemove__11CBaseEntity(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (((*(byte *)(*param_1 + 0x1a6) & 1) != 0) && (0 < DAT_001a82bc)) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      if (*(int *)(DAT_001a82b0 + 8 + iVar1) == *param_1) {
        *(undefined4 *)(DAT_001a82b0 + 8 + iVar1) = 0;
      }
      iVar1 = iVar1 + 0x18;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_001a82bc);
  }
  if (*(int *)(*param_1 + 4) != 0) {
    EntitySetState__12CGlobalStatei12GLOBALESTATE(&gGlobalState,*(undefined4 *)(*param_1 + 4),2);
  }
  return;
}


