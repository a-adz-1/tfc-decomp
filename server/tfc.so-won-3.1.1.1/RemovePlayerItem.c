// RemovePlayerItem__11CBaseEntityP15CBasePlayerItem  @ 00112ef0
undefined4 RemovePlayerItem__11CBaseEntityP15CBasePlayerItem(void)

{
  return 0;
}


// RemovePlayerItem__11CBasePlayerP15CBasePlayerItem  @ 000e5518
undefined4 RemovePlayerItem__11CBasePlayerP15CBasePlayerItem(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if ((int *)param_1[0x237] == param_2) {
    ResetAutoaim__11CBasePlayer(param_1);
    (**(code **)(param_2[0x115] + 0x128))(param_2,0);
    *(undefined4 *)(*param_2 + 0x104) = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_1[0x237] = 0;
    *(undefined4 *)(*param_1 + 0xbc) = 0;
    *(undefined4 *)(*param_1 + 0xc0) = 0;
  }
  else if ((int *)param_1[0x239] == param_2) {
    param_1[0x239] = 0;
  }
  iVar2 = (**(code **)(param_2[0x115] + 0x114))(param_2);
  piVar4 = (int *)param_1[iVar2 + 0x231];
  if (piVar4 == param_2) {
    iVar2 = (**(code **)(piVar4[0x115] + 0x114))(piVar4);
    param_1[iVar2 + 0x231] = piVar4[0x11e];
LAB_000e5610:
    uVar3 = 1;
  }
  else {
    if (piVar4 != (int *)0x0) {
      do {
        piVar1 = (int *)piVar4[0x11e];
        if (piVar1 == param_2) break;
        piVar4 = piVar1;
      } while (piVar1 != (int *)0x0);
      if (piVar4 != (int *)0x0) {
        piVar4[0x11e] = param_2[0x11e];
        goto LAB_000e5610;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


