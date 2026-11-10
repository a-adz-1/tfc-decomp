// PlayFootstepSounds__10CGameRulesP11CBasePlayerf  @ 000b8930
undefined4 PlayFootstepSounds__10CGameRulesP11CBasePlayerf(void)

{
  return 1;
}


// PlayFootstepSounds__18CHalfLifeMultiplayP11CBasePlayerf  @ 000b8480
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PlayFootstepSounds__18CHalfLifeMultiplayP11CBasePlayerf(undefined4 param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((byte)(0.0 < (float)footsteps._12_4_ |
             (byte)((ushort)((ushort)NAN((float)footsteps._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)footsteps._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
LAB_000b84e0:
    uVar4 = 0;
  }
  else {
    iVar3 = IsOnLadder__11CBasePlayer(param_2);
    if (iVar3 == 0) {
      fVar1 = *(float *)(*param_2 + 0x20);
      fVar2 = *(float *)(*param_2 + 0x24);
      fVar1 = SQRT(fVar2 * fVar2 + fVar1 * fVar1);
      if ((byte)(_FUN_00131f1c < fVar1 |
                 (byte)((ushort)((ushort)(NAN(_FUN_00131f1c) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(_FUN_00131f1c == fVar1) << 0xe) >> 8)) != 1)
      goto LAB_000b84e0;
    }
    uVar4 = 1;
  }
  return uVar4;
}


