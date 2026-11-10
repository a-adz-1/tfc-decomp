// SelectItem__11CBasePlayerPCc  @ 000da66c
void SelectItem__11CBasePlayerPCc(int param_1,char *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (param_2 != (char *)0x0) {
    puVar4 = (undefined4 *)0x0;
    iVar5 = 0;
    do {
      puVar1 = *(undefined4 **)(param_1 + 0x8c4 + iVar5 * 4);
      while ((puVar1 != (undefined4 *)0x0 &&
             (iVar2 = strcmp((char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)),param_2),
             puVar4 = puVar1, iVar2 != 0))) {
        puVar1 = (undefined4 *)puVar1[0x11e];
        puVar4 = puVar1;
      }
      if (puVar4 != (undefined4 *)0x0) {
        if (puVar4 == *(undefined4 **)(param_1 + 0x8dc)) {
          return;
        }
        iVar5 = (**(code **)(puVar4[0x115] + 0x11c))(puVar4);
        if (iVar5 == 0) {
          return;
        }
        ResetAutoaim__11CBasePlayer(param_1);
        iVar5 = *(int *)(param_1 + 0x8dc);
        uVar3 = 0;
        if (iVar5 != 0) {
          (**(code **)(*(int *)(iVar5 + 0x454) + 0x128))(iVar5,0);
          uVar3 = *(undefined4 *)(param_1 + 0x8dc);
        }
        *(undefined4 *)(param_1 + 0x8e4) = uVar3;
        *(undefined4 **)(param_1 + 0x8dc) = puVar4;
        if (puVar4 == (undefined4 *)0x0) {
          return;
        }
        (**(code **)(puVar4[0x115] + 0x120))(puVar4);
        (**(code **)(*(int *)(*(int *)(param_1 + 0x8dc) + 0x454) + 300))(*(int *)(param_1 + 0x8dc));
        return;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 6);
  }
  return;
}


