// HasNamedPlayerItem__11CBasePlayerPc  @ 000deecc
undefined4 HasNamedPlayerItem__11CBasePlayerPc(int param_1,char *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    for (puVar1 = *(undefined4 **)(param_1 + 0x89c + iVar3 * 4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[0x11a]) {
      iVar2 = strcmp(param_2,(char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)));
      if (iVar2 == 0) {
        return 1;
      }
    }
    for (puVar1 = *(undefined4 **)(param_1 + 0x8a0 + iVar3 * 4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[0x11a]) {
      iVar2 = strcmp(param_2,(char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)));
      if (iVar2 == 0) {
        return 1;
      }
    }
    for (puVar1 = *(undefined4 **)(param_1 + 0x8a4 + iVar3 * 4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[0x11a]) {
      iVar2 = strcmp(param_2,(char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)));
      if (iVar2 == 0) {
        return 1;
      }
    }
    iVar3 = iVar3 + 3;
  } while (iVar3 < 6);
  return 0;
}


