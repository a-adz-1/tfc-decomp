// ItemPreFrame__11CBasePlayer  @ 000e53b8
void ItemPreFrame__11CBasePlayer(int param_1)

{
  float fVar1;
  int iVar2;
  
  fVar1 = *(float *)(param_1 + 0x658);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) &&
     (iVar2 = *(int *)(param_1 + 0x8dc), iVar2 != 0)) {
    (**(code **)(*(int *)(iVar2 + 0x454) + 0x130))(iVar2);
  }
  return;
}


// ItemPreFrame__15CBasePlayerItem  @ 00126684
void ItemPreFrame__15CBasePlayerItem(void)

{
  return;
}


