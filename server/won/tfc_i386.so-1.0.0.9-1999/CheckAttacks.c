// CheckAttacks__12CBaseMonsterP11CBaseEntityf  @ 000c23f0
void CheckAttacks__12CBaseMonsterP11CBaseEntityf(int *param_1,int *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fStack_28;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  fStack_28 = *(float *)(*param_2 + 8) - *(float *)(*param_1 + 8);
  fVar1 = *(float *)(*param_2 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar2 = SQRT(fVar1 * fVar1 + fStack_28 * fStack_28);
  fVar3 = 0.0;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_28 = 0.0;
  }
  else {
    fStack_28 = (1.0 / fVar2) * fStack_28;
    fVar3 = (1.0 / fVar2) * fVar1;
  }
  fVar1 = fVar3 * *(float *)(gpGlobals + 0x2c) + fStack_28 * *(float *)(gpGlobals + 0x28);
  *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) & 0xc3;
  if (((*(byte *)((int)param_1 + 0x5c9) & 8) != 0) &&
     (iVar4 = (**(code **)(param_1[0xf2] + 0x150))(param_1,fVar1,param_3), iVar4 != 0)) {
    *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 4;
  }
  if (((*(byte *)((int)param_1 + 0x5c9) & 0x10) != 0) &&
     (iVar4 = (**(code **)(param_1[0xf2] + 0x154))(param_1,fVar1,param_3), iVar4 != 0)) {
    *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 0x10;
  }
  if (((*(byte *)((int)param_1 + 0x5c9) & 0x20) != 0) &&
     (iVar4 = (**(code **)(param_1[0xf2] + 0x158))(param_1,fVar1,param_3), iVar4 != 0)) {
    *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 8;
  }
  if (((*(byte *)((int)param_1 + 0x5c9) & 0x40) != 0) &&
     (iVar4 = (**(code **)(param_1[0xf2] + 0x15c))(param_1,fVar1,param_3), iVar4 != 0)) {
    *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 0x20;
  }
  return;
}


