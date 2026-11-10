// IsAlive__11CBaseEntity  @ 0010f920
bool IsAlive__11CBaseEntity(int *param_1)

{
  float fVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(int *)(*param_1 + 0x170) == 0) {
    fVar1 = *(float *)(*param_1 + 0x160);
    bVar2 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
  }
  return bVar2;
}


// IsAlive__11CBasePlayer  @ 000e4c58
undefined4 IsAlive__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(int *)(*param_1 + 0x170) == 0) || (*(int *)(*param_1 + 0x170) == 5)) &&
     (0.0 < *(float *)(*param_1 + 0x160))) {
    uVar1 = 1;
  }
  return uVar1;
}


// IsAlive__12CBaseMonster  @ 000c2964
bool IsAlive__12CBaseMonster(int *param_1)

{
  return *(int *)(*param_1 + 0x170) != 2;
}


// IsAlive__7CCycler  @ 000b55f0
undefined4 IsAlive__7CCycler(void)

{
  return 0;
}


