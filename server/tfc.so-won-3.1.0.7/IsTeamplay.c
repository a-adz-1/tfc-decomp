// IsTeamplay__10CGameRules  @ 000b0a54
undefined4 IsTeamplay__10CGameRules(void)

{
  return 0;
}


// IsTeamplay__13CTeamFortress  @ 000f9118
bool IsTeamplay__13CTeamFortress(void)

{
  float fVar1;
  
  fVar1 = *(float *)(gpGlobals + 0x1c);
  return (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
}


// IsTeamplay__17CHalfLifeTeamplay  @ 000f74d8
undefined4 IsTeamplay__17CHalfLifeTeamplay(void)

{
  return 1;
}


