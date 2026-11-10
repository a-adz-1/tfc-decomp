// RemovePlayerItem__11CBaseEntityP15CBasePlayerItem  @ 0010fa04
undefined4 RemovePlayerItem__11CBaseEntityP15CBasePlayerItem(void)

{
  return 0;
}


// RemovePlayerItem__11CBasePlayerP15CBasePlayerItem  @ 000dc338
undefined4 RemovePlayerItem__11CBasePlayerP15CBasePlayerItem(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((int *)param_1[0x22d] == param_2) {
    ResetAutoaim__11CBasePlayer(param_1);
    (**(code **)(param_2[0x111] + 0x128))(param_2,0);
    *(undefined4 *)(*param_2 + 0x104) = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_1[0x22d] = 0;
    *(undefined4 *)(*param_1 + 0xbc) = 0;
    *(undefined4 *)(*param_1 + 0xc0) = 0;
  }
  else if ((int *)param_1[0x22f] == param_2) {
    param_1[0x22f] = 0;
  }
  iVar1 = (**(code **)(param_2[0x111] + 0x114))(param_2);
  piVar3 = (int *)param_1[iVar1 + 0x227];
  if (piVar3 == param_2) {
    iVar1 = (**(code **)(piVar3[0x111] + 0x114))(piVar3);
    param_1[iVar1 + 0x227] = piVar3[0x11a];
    uVar2 = 1;
  }
  else {
    if (piVar3 != (int *)0x0) {
      do {
        if ((int *)piVar3[0x11a] == param_2) break;
        piVar3 = (int *)piVar3[0x11a];
      } while (piVar3 != (int *)0x0);
      if (piVar3 != (int *)0x0) {
        piVar3[0x11a] = param_2[0x11a];
        return 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


