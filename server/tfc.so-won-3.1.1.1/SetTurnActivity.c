// SetTurnActivity__12CBaseMonster  @ 000e8ff0
void SetTurnActivity__12CBaseMonster(int param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  lVar3 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
  fVar1 = (float)lVar3;
  if (((byte)(-45.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == -45.0) << 0xe) >> 8)) != 1) &&
     (iVar2 = LookupActivity__14CBaseAnimatingi(param_1,0x10), iVar2 != -1)) {
    *(undefined4 *)(param_1 + 0x56c) = 0x10;
    return;
  }
  if ((45.0 < fVar1) && (iVar2 = LookupActivity__14CBaseAnimatingi(param_1,0xf), iVar2 != -1)) {
    *(undefined4 *)(param_1 + 0x56c) = 0xf;
  }
  return;
}


