// IsAlive__11CBaseEntity  @ 00112e00
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


// IsAlive__11CBasePlayer  @ 000e60c4
undefined4 IsAlive__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = *(int *)(*param_1 + 0x170);
  if (((iVar1 == 0) || (iVar1 == 5)) && (0.0 < *(float *)(*param_1 + 0x160))) {
    uVar2 = 1;
  }
  return uVar2;
}


// IsAlive__12CBaseMonster  @ 000c3274
bool IsAlive__12CBaseMonster(int *param_1)

{
  return *(int *)(*param_1 + 0x170) != 2;
}


// IsAlive__7CCycler  @ 000b4984
undefined4 IsAlive__7CCycler(void)

{
  return 0;
}


