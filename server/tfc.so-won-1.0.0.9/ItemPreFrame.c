// ItemPreFrame__11CBasePlayer  @ 000de390
void ItemPreFrame__11CBasePlayer(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *gpGlobals;
  fVar2 = *(float *)(param_1 + 0x5cc);
  if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
     (*(int *)(param_1 + 0x830) != 0)) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x128))(*(int *)(param_1 + 0x830));
  }
  return;
}


// ItemPreFrame__15CBasePlayerItem  @ 0011cc20
void ItemPreFrame__15CBasePlayerItem(void)

{
  return;
}


