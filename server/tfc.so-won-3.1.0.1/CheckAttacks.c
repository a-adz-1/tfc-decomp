// CheckAttacks__12CBaseMonsterP11CBaseEntityf  @ 000b006c
void CheckAttacks__12CBaseMonsterP11CBaseEntityf(int *param_1,int *param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  float local_24;
  float local_20;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  local_24 = *(float *)(*param_2 + 8) - *(float *)(*param_1 + 8);
  local_20 = *(float *)(*param_2 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar1 = SQRT(local_20 * local_20 + local_24 * local_24);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = 0.0;
    local_20 = 0.0;
  }
  else {
    local_24 = (1.0 / fVar1) * local_24;
    local_20 = (1.0 / fVar1) * local_20;
  }
  fVar1 = local_20 * *(float *)(gpGlobals + 0x2c) + local_24 * *(float *)(gpGlobals + 0x28);
  *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) & 0xc3;
  if ((*(byte *)((int)param_1 + 0x5d5) & 8) != 0) {
    iVar2 = (**(code **)(param_1[0xf5] + 0x150))(param_1,fVar1,param_3);
    if (iVar2 != 0) {
      *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) | 4;
    }
  }
  if ((*(byte *)((int)param_1 + 0x5d5) & 0x10) != 0) {
    iVar2 = (**(code **)(param_1[0xf5] + 0x154))(param_1,fVar1,param_3);
    if (iVar2 != 0) {
      *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) | 0x10;
    }
  }
  if ((*(byte *)((int)param_1 + 0x5d5) & 0x20) != 0) {
    iVar2 = (**(code **)(param_1[0xf5] + 0x158))(param_1,fVar1,param_3);
    if (iVar2 != 0) {
      *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) | 8;
    }
  }
  if ((*(byte *)((int)param_1 + 0x5d5) & 0x40) != 0) {
    iVar2 = (**(code **)(param_1[0xf5] + 0x15c))(param_1,fVar1,param_3);
    if (iVar2 != 0) {
      *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) | 0x20;
    }
  }
  return;
}


