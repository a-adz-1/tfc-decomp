// TakeHealth__11CBaseEntityfi  @ 000a1000
undefined4 TakeHealth__11CBaseEntityfi(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  fVar1 = *(float *)(*param_1 + 0x14c);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
     (*(float *)(*param_1 + 400) <= *(float *)(*param_1 + 0x140))) {
    uVar3 = 0;
  }
  else {
    *(float *)(*param_1 + 0x140) = param_2 + *(float *)(*param_1 + 0x140);
    iVar2 = *param_1;
    if (*(float *)(iVar2 + 400) < *(float *)(iVar2 + 0x140)) {
      *(undefined4 *)(iVar2 + 0x140) = *(undefined4 *)(iVar2 + 400);
    }
    uVar3 = 1;
  }
  return uVar3;
}


// TakeHealth__11CBasePlayerfi  @ 000d6970
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 TakeHealth__11CBasePlayerfi(int *param_1,float param_2,uint param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  
  if ((param_3 & 0x1000000) == 0) {
    uVar3 = TakeHealth__12CBaseMonsterfi(param_1,param_2,param_3);
  }
  else {
    param_1[0x174] = param_1[0x174] & ~(param_3 & 0xff003fff);
    *(float *)(*param_1 + 0x140) = param_2 + *(float *)(*param_1 + 0x140);
    uVar3 = 1;
  }
  fVar1 = (float)param_1[0x68];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    fVar2 = *(float *)(*param_1 + 400) - _FUN_00139780;
    fVar1 = *(float *)(*param_1 + 0x140);
    if ((byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      param_1[0x68] = 0;
    }
    else {
      param_1[0x68] = (int)((float)param_1[0x68] - (param_2 + *(float *)(*param_1 + 0x140)) / 20.0);
    }
    if ((float)param_1[0x68] < 1.0) {
      param_1[0x68] = 0;
    }
    TeamFortress_SetSpeed__11CBasePlayer(param_1);
    uVar3 = 1;
  }
  return uVar3;
}


// TakeHealth__12CBaseMonsterfi  @ 000a55a0
undefined4 TakeHealth__12CBaseMonsterfi(int *param_1,undefined4 param_2,uint param_3)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = *(float *)(*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar2 = 0;
  }
  else {
    param_1[0x174] = param_1[0x174] & ~(param_3 & 0xff003fff);
    uVar2 = TakeHealth__11CBaseEntityfi(param_1,param_2,param_3);
  }
  return uVar2;
}


