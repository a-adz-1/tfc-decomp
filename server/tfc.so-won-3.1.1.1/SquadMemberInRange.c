// SquadMemberInRange__13CSquadMonsterRC6Vectorf  @ 000f5160
undefined4 SquadMemberInRange__13CSquadMonsterRC6Vectorf(int *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a7);
  if (iVar3 != 0) {
    piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x1a7);
    if (piVar4 != (int *)0x0) {
      param_1 = piVar4;
    }
    iVar3 = 0;
    do {
      piVar4 = param_1;
      if (iVar3 < 4) {
        piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + iVar3 * 2 + 0x1a9);
      }
      if ((piVar4 != (int *)0x0) &&
         (fVar1 = *param_2 - *(float *)(*piVar4 + 8), fVar2 = param_2[1] - *(float *)(*piVar4 + 0xc)
         , fVar1 = SQRT(fVar2 * fVar2 + fVar1 * fVar1),
         (byte)((fVar1 < param_3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_3)) << 10) >> 8)
                | (byte)((ushort)((ushort)(fVar1 == param_3) << 0xe) >> 8)) - 1) < 0x40)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
  }
  return 0;
}


