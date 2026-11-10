// AllowAutoTargetCrosshair__10CGameRules  @ 000b0344
undefined4 AllowAutoTargetCrosshair__10CGameRules(void)

{
  return 1;
}


// AllowAutoTargetCrosshair__14CHalfLifeRules  @ 000b001c
bool AllowAutoTargetCrosshair__14CHalfLifeRules(void)

{
  return g_iSkillLevel == 1;
}


// AllowAutoTargetCrosshair__18CHalfLifeMultiplay  @ 000afa6c
bool AllowAutoTargetCrosshair__18CHalfLifeMultiplay(void)

{
  return (byte)((byte)((ushort)((ushort)NAN((float)aimcrosshair._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)aimcrosshair._12_4_ == 0.0) << 0xe) >> 8)) != 0x40;
}


