// TakeHealth__11CBaseEntityfi  @ 0008ec40
undefined4 TakeHealth__11CBaseEntityfi(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *param_1;
  fVar1 = *(float *)(iVar3 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = *(float *)(iVar3 + 0x160);
    fVar2 = *(float *)(iVar3 + 0x1b0);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      *(float *)(iVar3 + 0x160) = fVar1 + param_2;
      iVar3 = *param_1;
      if (*(float *)(iVar3 + 0x1b0) < *(float *)(iVar3 + 0x160)) {
        *(float *)(iVar3 + 0x160) = *(float *)(iVar3 + 0x1b0);
      }
      return 1;
    }
  }
  return 0;
}


// TakeHealth__11CBasePlayerfi  @ 000e5e64
undefined4 TakeHealth__11CBasePlayerfi(int *param_1,float param_2,uint param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  
  if ((param_3 & 0x1000000) == 0) {
    uVar3 = TakeHealth__12CBaseMonsterfi(param_1,param_2,param_3);
  }
  else {
    param_1[0x197] = param_1[0x197] & ~(param_3 & 0xff003fff);
    uVar3 = 1;
    *(float *)(*param_1 + 0x160) = param_2 + *(float *)(*param_1 + 0x160);
  }
  if (0.0 < (float)param_1[0x68]) {
    fVar2 = *(float *)(*param_1 + 0x1b0) - 5.0;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      param_1[0x68] = (int)((float)param_1[0x68] - (fVar1 + param_2) * 0.05);
    }
    else {
      param_1[0x68] = 0;
    }
    fVar1 = (float)param_1[0x68];
    if (0x3f < (byte)((1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) - 1)) {
      param_1[0x68] = 0;
    }
    TeamFortress_SetSpeed__11CBasePlayer(param_1);
    uVar3 = 1;
  }
  return uVar3;
}


// TakeHealth__12CBaseMonsterfi  @ 000972dc
undefined4 TakeHealth__12CBaseMonsterfi(int *param_1,undefined4 param_2,uint param_3)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar2 = 0;
  }
  else if (*(int *)(*param_1 + 0x170) == 0) {
    param_1[0x197] = param_1[0x197] & ~(param_3 & 0xff003fff);
    uVar2 = TakeHealth__11CBaseEntityfi(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


