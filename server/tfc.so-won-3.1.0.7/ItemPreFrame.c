// ItemPreFrame__11CBasePlayer  @ 000dc688
void ItemPreFrame__11CBasePlayer(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x648);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) &&
     (*(int *)(param_1 + 0x8b4) != 0)) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 0x130))(*(int *)(param_1 + 0x8b4));
  }
  return;
}


// ItemPreFrame__15CBasePlayerItem  @ 00121ff0
void ItemPreFrame__15CBasePlayerItem(void)

{
  return;
}


