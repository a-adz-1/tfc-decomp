// SelectItem__11CBasePlayerPCc  @ 000dd0e0
void SelectItem__11CBasePlayerPCc(int param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 != (char *)0x0) {
    puVar2 = (undefined4 *)0x0;
    iVar3 = 0;
    do {
      if (*(int *)(iVar3 * 4 + param_1 + 0x818) == 0) {
LAB_000dd13f:
        if (puVar2 != (undefined4 *)0x0) goto LAB_000dd14d;
      }
      else {
        puVar2 = *(undefined4 **)(iVar3 * 4 + param_1 + 0x818);
        if (puVar2 != (undefined4 *)0x0) {
          do {
            iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),param_2);
            if (iVar1 == 0) break;
            puVar2 = (undefined4 *)puVar2[0xfb];
          } while (puVar2 != (undefined4 *)0x0);
          goto LAB_000dd13f;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    if (puVar2 != (undefined4 *)0x0) {
LAB_000dd14d:
      if (puVar2 != *(undefined4 **)(param_1 + 0x830)) {
        ResetAutoaim__11CBasePlayer(param_1);
        if (*(int *)(param_1 + 0x830) != 0) {
          (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x120))
                    (*(int *)(param_1 + 0x830));
        }
        *(undefined4 *)(param_1 + 0x838) = *(undefined4 *)(param_1 + 0x830);
        *(undefined4 **)(param_1 + 0x830) = puVar2;
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)(puVar2[0xf2] + 0x118))(puVar2);
          (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x124))
                    (*(int *)(param_1 + 0x830));
        }
      }
    }
  }
  return;
}


