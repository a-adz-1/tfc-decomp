// SelectItem__11CBasePlayerPCc  @ 000db134
void SelectItem__11CBasePlayerPCc(int param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_8;
  int local_4;
  
  if (param_2 != (char *)0x0) {
    puVar2 = (undefined4 *)0x0;
    local_4 = 0;
    local_8 = (int *)(param_1 + 0x89c);
    do {
      if (*local_8 == 0) {
LAB_000db1a6:
        if (puVar2 != (undefined4 *)0x0) goto LAB_000db24b;
      }
      else {
        puVar2 = (undefined4 *)*local_8;
        if (puVar2 != (undefined4 *)0x0) {
          do {
            iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),param_2);
            if (iVar1 == 0) break;
            puVar2 = (undefined4 *)puVar2[0x11a];
          } while (puVar2 != (undefined4 *)0x0);
          goto LAB_000db1a6;
        }
      }
      if (local_8[1] == 0) {
LAB_000db1ea:
        if (puVar2 != (undefined4 *)0x0) goto LAB_000db24b;
      }
      else {
        puVar2 = (undefined4 *)local_8[1];
        if (puVar2 != (undefined4 *)0x0) {
          do {
            iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),param_2);
            if (iVar1 == 0) break;
            puVar2 = (undefined4 *)puVar2[0x11a];
          } while (puVar2 != (undefined4 *)0x0);
          goto LAB_000db1ea;
        }
      }
      if (local_8[2] == 0) {
LAB_000db22a:
        if (puVar2 != (undefined4 *)0x0) goto LAB_000db24b;
      }
      else {
        puVar2 = (undefined4 *)local_8[2];
        if (puVar2 != (undefined4 *)0x0) {
          do {
            iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),param_2);
            if (iVar1 == 0) break;
            puVar2 = (undefined4 *)puVar2[0x11a];
          } while (puVar2 != (undefined4 *)0x0);
          goto LAB_000db22a;
        }
      }
      local_8 = local_8 + 3;
      local_4 = local_4 + 3;
    } while (local_4 < 6);
    if (puVar2 != (undefined4 *)0x0) {
LAB_000db24b:
      if (puVar2 != *(undefined4 **)(param_1 + 0x8b4)) {
        iVar1 = (**(code **)(puVar2[0x111] + 0x11c))(puVar2);
        if (iVar1 != 0) {
          ResetAutoaim__11CBasePlayer(param_1);
          if (*(int *)(param_1 + 0x8b4) != 0) {
            (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 0x128))
                      (*(int *)(param_1 + 0x8b4),0);
          }
          *(undefined4 *)(param_1 + 0x8bc) = *(undefined4 *)(param_1 + 0x8b4);
          *(undefined4 **)(param_1 + 0x8b4) = puVar2;
          if (puVar2 != (undefined4 *)0x0) {
            (**(code **)(puVar2[0x111] + 0x120))(puVar2);
            (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 300))
                      (*(int *)(param_1 + 0x8b4));
          }
        }
      }
    }
  }
  return;
}


