// IsTeamplay__10CGameRules  @ 000a5ce4
undefined4 IsTeamplay__10CGameRules(void)

{
  return 0;
}


// IsTeamplay__13CTeamFortress  @ 000ec2cc
bool IsTeamplay__13CTeamFortress(void)

{
  float fVar1;
  
  fVar1 = *(float *)(gpGlobals + 0x1c);
  return (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
}


// IsTeamplay__17CHalfLifeTeamplay  @ 000ea728
undefined4 IsTeamplay__17CHalfLifeTeamplay(void)

{
  return 1;
}


