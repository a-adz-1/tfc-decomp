// HasNamedPlayerItem__11CBasePlayerPc  @ 000d37c8
undefined4 HasNamedPlayerItem__11CBasePlayerPc(int param_1,char *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    for (puVar1 = *(undefined4 **)(param_1 + 0x82c + iVar3 * 4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[0xfe]) {
      iVar2 = strcmp(param_2,(char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)));
      if (iVar2 == 0) {
        return 1;
      }
    }
    for (puVar1 = *(undefined4 **)(param_1 + 0x830 + iVar3 * 4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[0xfe]) {
      iVar2 = strcmp(param_2,(char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)));
      if (iVar2 == 0) {
        return 1;
      }
    }
    for (puVar1 = *(undefined4 **)(param_1 + 0x834 + iVar3 * 4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[0xfe]) {
      iVar2 = strcmp(param_2,(char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)));
      if (iVar2 == 0) {
        return 1;
      }
    }
    iVar3 = iVar3 + 3;
  } while (iVar3 < 6);
  return 0;
}


