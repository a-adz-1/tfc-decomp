// CineThink__12CCineMonster  @ 000e78a0
void CineThink__12CCineMonster(int *param_1)

{
  int iVar1;
  
  iVar1 = FindEntity__12CCineMonster(param_1);
  if (iVar1 == 0) {
    CancelScript__12CCineMonster(param_1);
    (*DAT_001755b4)(2,"script \"%s\" can\'t find monster \"%s\"\n",
                    *(int *)(*param_1 + 0x1ac) + (int)gpGlobals[0x26],
                    param_1[0x186] + (int)gpGlobals[0x26]);
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  }
  else {
    (**(code **)(param_1[0xf2] + 0x214))(param_1);
    (*DAT_001755b4)(2,"script \"%s\" using monster \"%s\"\n",
                    *(int *)(*param_1 + 0x1ac) + (int)gpGlobals[0x26],
                    param_1[0x186] + (int)gpGlobals[0x26]);
  }
  return;
}


// CineThink__18CLegacyCineMonster  @ 000bb210
void CineThink__18CLegacyCineMonster(int *param_1)

{
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x114)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x114) == 0.0) << 0xe) >> 8)) == 0x40) {
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  if ((*(int *)(*param_1 + 0x180) == 0) || (param_1[0xf8] == 0)) {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  }
  else {
    Die__18CLegacyCineMonster(param_1);
  }
  return;
}


