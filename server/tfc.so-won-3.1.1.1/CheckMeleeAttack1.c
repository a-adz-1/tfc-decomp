// CheckMeleeAttack1__12CBaseMonsterff  @ 000c2854
undefined4 CheckMeleeAttack1__12CBaseMonsterff(int param_1,float param_2,float param_3)

{
  int iVar1;
  int *piVar2;
  
  if (((byte)(64.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_3 == 64.0) << 0xe) >> 8)) != 1) && (0.7 <= param_2)) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
    if ((iVar1 != 0) &&
       (piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x4fc), (*(byte *)(*piVar2 + 0x1a5) & 2) != 0)) {
      return 1;
    }
  }
  return 0;
}


