// SwitchWeapon__11CBasePlayerP15CBasePlayerItem  @ 000e4ea4
undefined4 SwitchWeapon__11CBasePlayerP15CBasePlayerItem(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(*(int *)(param_2 + 0x454) + 0x11c))(param_2);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x27b]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)param_1[0x27b] == 0.0) << 0xe) >> 8)) != 0x40) ||
       (fVar1 = (float)param_1[0x27c],
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      param_1[0x27b] = 0;
      param_1[0x27c] = 0;
      param_1[0x27d] = 0;
      (*DAT_0019f818)(*(undefined4 *)(*param_1 + 0x208),0,0);
    }
    param_1[0x27e] = 0;
    iVar2 = param_1[0x237];
    if (iVar2 != 0) {
      (**(code **)(*(int *)(iVar2 + 0x454) + 0x128))(iVar2,0);
    }
    param_1[0x237] = param_2;
    (**(code **)(*(int *)(param_2 + 0x454) + 0x120))(param_2);
    uVar3 = 1;
  }
  return uVar3;
}


// SwitchWeapon__11CBasePlayerPCc  @ 000dd780
undefined4 SwitchWeapon__11CBasePlayerPCc(int *param_1,char *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    for (iVar2 = param_1[iVar4 + 0x231]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x478)) {
      if ((*(char **)(_15CBasePlayerItem_ItemInfoArray + *(int *)(iVar2 + 0x47c) * 0x2c + 0x18) !=
           (char *)0x0) &&
         (iVar3 = strcmp(*(char **)(_15CBasePlayerItem_ItemInfoArray +
                                   *(int *)(iVar2 + 0x47c) * 0x2c + 0x18),param_2), iVar3 == 0)) {
        iVar4 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x11c))(iVar2);
        if (iVar4 == 0) {
          return 0;
        }
        if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x27b]) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)param_1[0x27b] == 0.0) << 0xe) >> 8)) != 0x40) ||
           (fVar1 = (float)param_1[0x27c],
           (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
          param_1[0x27b] = 0;
          param_1[0x27c] = 0;
          param_1[0x27d] = 0;
          (*DAT_0019f818)(*(undefined4 *)(*param_1 + 0x208),0,0);
        }
        param_1[0x27e] = 0;
        iVar4 = param_1[0x237];
        if (iVar4 != 0) {
          (**(code **)(*(int *)(iVar4 + 0x454) + 0x128))(iVar4,0);
        }
        param_1[0x237] = iVar2;
        (**(code **)(*(int *)(iVar2 + 0x454) + 0x120))(iVar2);
        return 1;
      }
    }
    iVar4 = iVar4 + 1;
    if (5 < iVar4) {
      return 0;
    }
  } while( true );
}


