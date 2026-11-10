// ItemPreFrame__11CBasePlayer  @ 000d0fc0
void ItemPreFrame__11CBasePlayer(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x5d8);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) &&
     (*(int *)(param_1 + 0x844) != 0)) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x128))(*(int *)(param_1 + 0x844));
  }
  return;
}


// ItemPreFrame__15CBasePlayerItem  @ 00112440
void ItemPreFrame__15CBasePlayerItem(void)

{
  return;
}


