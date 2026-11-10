// SelectItem__11CBasePlayerPCc  @ 000cfa78
void SelectItem__11CBasePlayerPCc(int param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_8;
  int local_4;
  
  if (param_2 != (char *)0x0) {
    puVar2 = (undefined4 *)0x0;
    local_4 = 0;
    local_8 = (int *)(param_1 + 0x82c);
    do {
      if (*local_8 == 0) {
LAB_000cfaea:
        if (puVar2 != (undefined4 *)0x0) goto LAB_000cfb8f;
      }
      else {
        puVar2 = (undefined4 *)*local_8;
        if (puVar2 != (undefined4 *)0x0) {
          do {
            iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),param_2);
            if (iVar1 == 0) break;
            puVar2 = (undefined4 *)puVar2[0xfe];
          } while (puVar2 != (undefined4 *)0x0);
          goto LAB_000cfaea;
        }
      }
      if (local_8[1] == 0) {
LAB_000cfb2e:
        if (puVar2 != (undefined4 *)0x0) goto LAB_000cfb8f;
      }
      else {
        puVar2 = (undefined4 *)local_8[1];
        if (puVar2 != (undefined4 *)0x0) {
          do {
            iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),param_2);
            if (iVar1 == 0) break;
            puVar2 = (undefined4 *)puVar2[0xfe];
          } while (puVar2 != (undefined4 *)0x0);
          goto LAB_000cfb2e;
        }
      }
      if (local_8[2] == 0) {
LAB_000cfb6e:
        if (puVar2 != (undefined4 *)0x0) goto LAB_000cfb8f;
      }
      else {
        puVar2 = (undefined4 *)local_8[2];
        if (puVar2 != (undefined4 *)0x0) {
          do {
            iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),param_2);
            if (iVar1 == 0) break;
            puVar2 = (undefined4 *)puVar2[0xfe];
          } while (puVar2 != (undefined4 *)0x0);
          goto LAB_000cfb6e;
        }
      }
      local_8 = local_8 + 3;
      local_4 = local_4 + 3;
    } while (local_4 < 6);
    if (puVar2 != (undefined4 *)0x0) {
LAB_000cfb8f:
      if (puVar2 != *(undefined4 **)(param_1 + 0x844)) {
        iVar1 = (**(code **)(puVar2[0xf5] + 0x114))(puVar2);
        if (iVar1 != 0) {
          ResetAutoaim__11CBasePlayer(param_1);
          if (*(int *)(param_1 + 0x844) != 0) {
            (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x120))
                      (*(int *)(param_1 + 0x844),0);
          }
          *(undefined4 *)(param_1 + 0x84c) = *(undefined4 *)(param_1 + 0x844);
          *(undefined4 **)(param_1 + 0x844) = puVar2;
          if (puVar2 != (undefined4 *)0x0) {
            (**(code **)(puVar2[0xf5] + 0x118))(puVar2);
            (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x124))
                      (*(int *)(param_1 + 0x844));
          }
        }
      }
    }
  }
  return;
}


