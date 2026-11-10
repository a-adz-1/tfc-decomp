// CheckAttacks__12CBaseMonsterP11CBaseEntityf  @ 000bc000
void CheckAttacks__12CBaseMonsterP11CBaseEntityf(int *param_1,int *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fStack_28;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  fStack_28 = *(float *)(*param_2 + 8) - *(float *)(*param_1 + 8);
  fVar1 = *(float *)(*param_2 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar2 = SQRT(fVar1 * fVar1 + fStack_28 * fStack_28);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = 0.0;
    fStack_28 = 0.0;
  }
  else {
    fStack_28 = fStack_28 * (1.0 / fVar2);
    fVar1 = (1.0 / fVar2) * fVar1;
  }
  fVar1 = fVar1 * *(float *)(gpGlobals + 0x2c) + fStack_28 * *(float *)(gpGlobals + 0x28);
  *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) & 0xc3;
  if (((*(byte *)((int)param_1 + 0x655) & 8) != 0) &&
     (iVar3 = (**(code **)(param_1[0x115] + 0x158))(param_1,fVar1,param_3), iVar3 != 0)) {
    *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) | 4;
  }
  if (((*(byte *)((int)param_1 + 0x655) & 0x10) != 0) &&
     (iVar3 = (**(code **)(param_1[0x115] + 0x15c))(param_1,fVar1,param_3), iVar3 != 0)) {
    *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) | 0x10;
  }
  if (((*(byte *)((int)param_1 + 0x655) & 0x20) != 0) &&
     (iVar3 = (**(code **)(param_1[0x115] + 0x160))(param_1,fVar1,param_3), iVar3 != 0)) {
    *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) | 8;
  }
  if (((*(byte *)((int)param_1 + 0x655) & 0x40) != 0) &&
     (iVar3 = (**(code **)(param_1[0x115] + 0x164))(param_1,fVar1,param_3), iVar3 != 0)) {
    *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) | 0x20;
  }
  return;
}


