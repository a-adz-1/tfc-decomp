// SquadMemberInRange__13CSquadMonsterRC6Vectorf  @ 000f33d8
undefined4 SquadMemberInRange__13CSquadMonsterRC6Vectorf(int *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *local_14;
  
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a3);
  if (iVar3 != 0) {
    piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x1a3);
    local_14 = param_1;
    if (piVar4 != (int *)0x0) {
      local_14 = piVar4;
    }
    piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(local_14 + 0x1a5);
    if ((piVar4 != (int *)0x0) &&
       (fVar1 = *param_2 - *(float *)(*piVar4 + 8), fVar2 = param_2[1] - *(float *)(*piVar4 + 0xc),
       fVar1 = SQRT(fVar2 * fVar2 + fVar1 * fVar1),
       (byte)((fVar1 < param_3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == param_3) << 0xe) >> 8)) - 1) < 0x40)) {
      return 1;
    }
    piVar4 = local_14 + 0x1a7;
    iVar3 = 1;
    do {
      piVar5 = local_14;
      if (iVar3 < 4) {
        piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4);
      }
      if ((piVar5 != (int *)0x0) &&
         (fVar1 = *param_2 - *(float *)(*piVar5 + 8), fVar2 = param_2[1] - *(float *)(*piVar5 + 0xc)
         , fVar1 = SQRT(fVar2 * fVar2 + fVar1 * fVar1),
         (byte)((fVar1 < param_3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_3)) << 10) >> 8)
                | (byte)((ushort)((ushort)(fVar1 == param_3) << 0xe) >> 8)) - 1) < 0x40)) {
        return 1;
      }
      piVar5 = local_14;
      if (iVar3 + 1 < 4) {
        piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4 + 2);
      }
      if ((piVar5 != (int *)0x0) &&
         (fVar1 = *param_2 - *(float *)(*piVar5 + 8), fVar2 = param_2[1] - *(float *)(*piVar5 + 0xc)
         , fVar1 = SQRT(fVar2 * fVar2 + fVar1 * fVar1),
         (byte)((fVar1 < param_3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_3)) << 10) >> 8)
                | (byte)((ushort)((ushort)(fVar1 == param_3) << 0xe) >> 8)) - 1) < 0x40)) {
        return 1;
      }
      piVar4 = piVar4 + 4;
      iVar3 = iVar3 + 2;
    } while (iVar3 < 5);
  }
  return 0;
}


