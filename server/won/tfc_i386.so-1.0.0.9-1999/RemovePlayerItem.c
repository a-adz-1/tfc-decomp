// RemovePlayerItem__11CBaseEntityP15CBasePlayerItem  @ 0010e4b0
undefined4 RemovePlayerItem__11CBaseEntityP15CBasePlayerItem(void)

{
  return 0;
}


// RemovePlayerItem__11CBasePlayerP15CBasePlayerItem  @ 000de080
undefined4 RemovePlayerItem__11CBasePlayerP15CBasePlayerItem(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((int *)param_1[0x20c] == param_2) {
    ResetAutoaim__11CBasePlayer(param_1);
    (**(code **)(param_2[0xf2] + 0x120))(param_2);
    *(undefined4 *)(*param_2 + 0xe4) = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_1[0x20c] = 0;
    *(undefined4 *)(*param_1 + 0x9c) = 0;
    *(undefined4 *)(*param_1 + 0xa0) = 0;
  }
  else if ((int *)param_1[0x20e] == param_2) {
    param_1[0x20e] = 0;
  }
  iVar1 = (**(code **)(param_2[0xf2] + 0x10c))(param_2);
  piVar3 = (int *)param_1[iVar1 + 0x206];
  if (piVar3 == param_2) {
    iVar1 = (**(code **)(piVar3[0xf2] + 0x10c))(piVar3);
    param_1[iVar1 + 0x206] = piVar3[0xfb];
LAB_000de16c:
    uVar2 = 1;
  }
  else {
    if (piVar3 != (int *)0x0) {
      do {
        if ((int *)piVar3[0xfb] == param_2) break;
        piVar3 = (int *)piVar3[0xfb];
      } while (piVar3 != (int *)0x0);
      if (piVar3 != (int *)0x0) {
        piVar3[0xfb] = param_2[0xfb];
        goto LAB_000de16c;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


