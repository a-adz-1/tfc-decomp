// CheckMeleeAttack1__12CBaseMonsterff  @ 000c2340
undefined4 CheckMeleeAttack1__12CBaseMonsterff(int param_1,float param_2,float param_3)

{
  int iVar1;
  int *piVar2;
  
  if ((param_3 <= 64.0) &&
     ((byte)((0.7 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 0.7) << 0xe) >> 8)) - 1) < 0x40)) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
    if ((iVar1 != 0) &&
       (piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x470), (*(byte *)(*piVar2 + 0x185) & 2) != 0)) {
      return 1;
    }
  }
  return 0;
}


