// PlayFootstepSounds__10CGameRulesP11CBasePlayerf  @ 000b030c
undefined4 PlayFootstepSounds__10CGameRulesP11CBasePlayerf(void)

{
  return 1;
}


// PlayFootstepSounds__18CHalfLifeMultiplayP11CBasePlayerf  @ 000af730
undefined4 PlayFootstepSounds__18CHalfLifeMultiplayP11CBasePlayerf(undefined4 param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((g_footsteps == 0) ||
     (fVar1 = *(float *)(g_footsteps + 0xc),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    iVar3 = IsOnLadder__11CBasePlayer(param_2);
    if (iVar3 == 0) {
      fVar1 = *(float *)(*param_2 + 0x20);
      fVar2 = *(float *)(*param_2 + 0x24);
      if (SQRT(fVar2 * fVar2 + fVar1 * fVar1) <= 220.0) goto LAB_000af7a0;
    }
    uVar4 = 1;
  }
  else {
LAB_000af7a0:
    uVar4 = 0;
  }
  return uVar4;
}


