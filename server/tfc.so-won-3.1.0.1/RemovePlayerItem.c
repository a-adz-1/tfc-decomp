// RemovePlayerItem__11CBaseEntityP15CBasePlayerItem  @ 001006fc
undefined4 RemovePlayerItem__11CBaseEntityP15CBasePlayerItem(void)

{
  return 0;
}


// RemovePlayerItem__11CBasePlayerP15CBasePlayerItem  @ 000d0c70
undefined4 RemovePlayerItem__11CBasePlayerP15CBasePlayerItem(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((int *)param_1[0x211] == param_2) {
    ResetAutoaim__11CBasePlayer(param_1);
    (**(code **)(param_2[0xf5] + 0x120))(param_2,0);
    *(undefined4 *)(*param_2 + 0x104) = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_1[0x211] = 0;
    *(undefined4 *)(*param_1 + 0xbc) = 0;
    *(undefined4 *)(*param_1 + 0xc0) = 0;
  }
  else if ((int *)param_1[0x213] == param_2) {
    param_1[0x213] = 0;
  }
  iVar1 = (**(code **)(param_2[0xf5] + 0x10c))(param_2);
  piVar3 = (int *)param_1[iVar1 + 0x20b];
  if (piVar3 == param_2) {
    iVar1 = (**(code **)(piVar3[0xf5] + 0x10c))(piVar3);
    param_1[iVar1 + 0x20b] = piVar3[0xfe];
    uVar2 = 1;
  }
  else {
    if (piVar3 != (int *)0x0) {
      do {
        if ((int *)piVar3[0xfe] == param_2) break;
        piVar3 = (int *)piVar3[0xfe];
      } while (piVar3 != (int *)0x0);
      if (piVar3 != (int *)0x0) {
        piVar3[0xfe] = param_2[0xfe];
        return 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


