// Jump__11CBasePlayer  @ 000cbffc
void Jump__11CBasePlayer(int *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar1 = *param_1;
  if (((((*(byte *)(iVar1 + 0x1a5) & 8) == 0) && (*(int *)(iVar1 + 0x1c0) < 2)) &&
      ((*(byte *)(param_1 + 0x191) & 2) != 0)) &&
     (((*(byte *)(iVar1 + 0x1a5) & 2) != 0 && (*(int *)(iVar1 + 0x19c) != 0)))) {
    UTIL_MakeVectors__FRC6Vector(iVar1 + 0x50);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,2);
    if ((((*(byte *)(*param_1 + 0x1a5) & 0x40) != 0) || ((*(byte *)(param_1 + 0x19e) & 8) != 0)) &&
       ((param_1[0x201] != 0 && (iVar1 = *param_1, (*(byte *)(iVar1 + 0x180) & 4) != 0)))) {
      fVar3 = *gpGlobals - (float)param_1[0x1a4];
      if (0x3f < (byte)((1.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) - 1)) {
        if (50.0 < SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                        *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                        *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20))) {
          SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,3);
        }
      }
    }
    iVar1 = *param_1;
    iVar2 = *(int *)(iVar1 + 0x19c);
    if (((iVar2 != 0) && (iVar2 != -0x80)) && ((*(byte *)(iVar2 + 0x224) & 4) != 0)) {
      *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) + *(float *)(iVar1 + 0x2c);
      *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x24) + *(float *)(iVar1 + 0x30);
      *(float *)(iVar1 + 0x28) = *(float *)(iVar1 + 0x28) + *(float *)(iVar1 + 0x34);
    }
  }
  return;
}


