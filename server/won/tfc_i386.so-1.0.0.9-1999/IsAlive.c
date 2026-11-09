// IsAlive__11CBaseEntity  @ 0010e3a0
undefined4 IsAlive__11CBaseEntity(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(int *)(*param_1 + 0x150) == 0) &&
     (fVar1 = *(float *)(*param_1 + 0x140),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
    uVar2 = 1;
  }
  return uVar2;
}


// IsAlive__11CBasePlayer  @ 000e4480
undefined4 IsAlive__11CBasePlayer(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((*(int *)(*param_1 + 0x150) == 0) || (*(int *)(*param_1 + 0x150) == 99)) &&
     (fVar1 = *(float *)(*param_1 + 0x140),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
    uVar2 = 1;
  }
  return uVar2;
}


// IsAlive__12CBaseMonster  @ 000c8920
bool IsAlive__12CBaseMonster(int *param_1)

{
  return *(int *)(*param_1 + 0x150) != 2;
}


// IsAlive__7CCycler  @ 000bc490
undefined4 IsAlive__7CCycler(void)

{
  return 0;
}


