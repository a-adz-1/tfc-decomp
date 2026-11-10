// EntityIndex__18CSaveRestoreBufferP11CBaseEntity  @ 00118ce0
undefined4 EntityIndex__18CSaveRestoreBufferP11CBaseEntity(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = EntityIndex__18CSaveRestoreBufferP9entvars_t(param_1,*param_2);
  }
  return uVar1;
}


// EntityIndex__18CSaveRestoreBufferP7edict_s  @ 00118d70
int EntityIndex__18CSaveRestoreBufferP7edict_s(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*param_1 != 0) && (param_2 != 0)) {
    iVar1 = 0;
    iVar2 = *param_1;
    if (0 < *(int *)(iVar2 + 0x20)) {
      do {
        if (*(int *)(*(int *)(iVar2 + 0x28) + 4 + iVar1 * 0x18) == param_2) {
          return iVar1;
        }
        iVar1 = iVar1 + 1;
        iVar2 = *param_1;
      } while (iVar1 < *(int *)(iVar2 + 0x20));
    }
  }
  return -1;
}


// EntityIndex__18CSaveRestoreBufferP9entvars_t  @ 00118d10
undefined4 EntityIndex__18CSaveRestoreBufferP9entvars_t(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = EntityIndex__18CSaveRestoreBufferP7edict_s(param_1,*(undefined4 *)(param_2 + 0x1e8));
  }
  return uVar1;
}


// EntityIndex__18CSaveRestoreBufferi  @ 00118d40
void EntityIndex__18CSaveRestoreBufferi(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001755d4)(param_2);
  EntityIndex__18CSaveRestoreBufferP7edict_s(param_1,uVar1);
  return;
}


