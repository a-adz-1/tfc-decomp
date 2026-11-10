// CineThink__12CCineMonster  @ 000e9b08
void CineThink__12CCineMonster(int *param_1)

{
  int iVar1;
  
  iVar1 = FindEntity__12CCineMonster(param_1);
  if (iVar1 == 0) {
    CancelScript__12CCineMonster(param_1);
    (*DAT_0019f794)(2,"script \"%s\" can\'t find monster \"%s\"\n",
                    *(int *)(*param_1 + 0x1cc) + (int)gpGlobals[0x26],
                    param_1[0x1a9] + (int)gpGlobals[0x26]);
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  }
  else {
    (**(code **)(param_1[0x115] + 0x21c))(param_1);
    (*DAT_0019f794)(2,"script \"%s\" using monster \"%s\"\n",
                    *(int *)(*param_1 + 0x1cc) + (int)gpGlobals[0x26],
                    param_1[0x1a9] + (int)gpGlobals[0x26]);
  }
  return;
}


// CineThink__18CLegacyCineMonster  @ 000b35cc
void CineThink__18CLegacyCineMonster(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x134)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x134) == 0.0) << 0xe) >> 8)) == 0x40) {
    ResetSequenceInfo__14CBaseAnimating(param_1);
    iVar1 = *param_1;
  }
  *(float *)(iVar1 + 0x104) = *gpGlobals + 1.0;
  if ((*(int *)(*param_1 + 0x1a0) == 0) || (param_1[0x11b] == 0)) {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  return;
}


