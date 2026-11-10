// EntityIndex__18CSaveRestoreBufferP11CBaseEntity  @ 00121704
undefined4 EntityIndex__18CSaveRestoreBufferP11CBaseEntity(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = EntityIndex__18CSaveRestoreBufferP9entvars_s(param_1,*param_2);
  }
  return uVar1;
}


// EntityIndex__18CSaveRestoreBufferP7edict_s  @ 0012164c
int EntityIndex__18CSaveRestoreBufferP7edict_s(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (param_2 != 0)) {
    iVar2 = 0;
    if (0 < *(int *)(iVar1 + 0x20)) {
      do {
        if (*(int *)(*(int *)(iVar1 + 0x28) + 4 + iVar2 * 0x18) == param_2) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(iVar1 + 0x20));
    }
  }
  return -1;
}


// EntityIndex__18CSaveRestoreBufferP9entvars_s  @ 001216cc
undefined4 EntityIndex__18CSaveRestoreBufferP9entvars_s(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = EntityIndex__18CSaveRestoreBufferP7edict_s(param_1,*(undefined4 *)(param_2 + 0x208));
  }
  return uVar1;
}


// EntityIndex__18CSaveRestoreBufferi  @ 00121690
void EntityIndex__18CSaveRestoreBufferi(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_0019f7b4)(param_2);
  EntityIndex__18CSaveRestoreBufferP7edict_s(param_1,uVar1);
  return;
}


