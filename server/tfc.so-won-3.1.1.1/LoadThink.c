// LoadThink__12CRevertSaved  @ 000e484c
void LoadThink__12CRevertSaved(void)

{
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x14)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x14) == 0.0) << 0xe) >> 8)) == 0x40) {
    (*DAT_0019f73c)("reload\n");
  }
  return;
}


