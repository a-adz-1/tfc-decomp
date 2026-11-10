// FAllowFlashlight__14CHalfLifeRules  @ 000b09a0
undefined4 FAllowFlashlight__14CHalfLifeRules(void)

{
  return 1;
}


// FAllowFlashlight__18CHalfLifeMultiplay  @ 000afdac
bool FAllowFlashlight__18CHalfLifeMultiplay(void)

{
  return (byte)((byte)((ushort)((ushort)NAN((float)flashlight._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)flashlight._12_4_ == 0.0) << 0xe) >> 8)) != 0x40;
}


