// EntityIndex__18CSaveRestoreBufferP11CBaseEntity  @ 0011c94c
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


// EntityIndex__18CSaveRestoreBufferP7edict_s  @ 0011c9e8
int EntityIndex__18CSaveRestoreBufferP7edict_s(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*param_1 != 0) && (param_2 != 0)) {
    iVar3 = 0;
    iVar1 = *param_1;
    if (0 < *(int *)(iVar1 + 0x20)) {
      iVar2 = 0;
      do {
        if (*(int *)(*(int *)(iVar1 + 0x28) + iVar2 + 4) == param_2) {
          return iVar3;
        }
        iVar2 = iVar2 + 0x18;
        iVar3 = iVar3 + 1;
        iVar1 = *param_1;
      } while (iVar3 < *(int *)(iVar1 + 0x20));
    }
  }
  return -1;
}


// EntityIndex__18CSaveRestoreBufferP9entvars_s  @ 0011c97c
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


// EntityIndex__18CSaveRestoreBufferi  @ 0011c9b0
void EntityIndex__18CSaveRestoreBufferi(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001c1134)(param_2);
  EntityIndex__18CSaveRestoreBufferP7edict_s(param_1,uVar1);
  return;
}


