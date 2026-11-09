// DoItemGroupWork__FP11CBaseEntityP11CBasePlayer  @ 0010b2e0
void DoItemGroupWork__FP11CBaseEntityP11CBasePlayer(int *param_1,undefined4 param_2)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  fVar1 = (float)param_1[199];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x1e0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1e0) == 0.0) << 0xe) >> 8)) == 0x40)
    {
      (*DAT_001755b4)(1,"GoalItem %d has .distance specified, but no .pain_finished\n",param_1[0x84]
                     );
    }
    bVar2 = true;
    iVar4 = 0;
    while (iVar4 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar4,"item_tfgoal"), iVar4 != 0)
    {
      if (!bVar2) goto LAB_0010b3e5;
      if (((byte)((byte)((ushort)((ushort)(NAN((float)param_1[199]) ||
                                          NAN((float)*(int *)(iVar4 + 0x214))) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)param_1[199] == (float)*(int *)(iVar4 + 0x214)) <<
                                0xe) >> 8)) == 0x40) && (*(int *)(iVar4 + 0x218) != 1)) {
        bVar2 = false;
      }
    }
    if ((bVar2) && (iVar4 = Findgoal__Fi((int)ROUND(*(float *)(*param_1 + 0x1e0))), iVar4 != 0)) {
      DoResults__FP11CBaseEntityP11CBasePlayeri(iVar4,param_2,param_1[0x8a] & 2);
    }
  }
LAB_0010b3e5:
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xc6]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xc6] == 0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_001755b4)(1,"GoalItem %d has .speed specified, but no .attack_finished\n",param_1[0x84])
      ;
    }
    bVar2 = true;
    iVar4 = 0;
    piVar5 = (int *)0x0;
LAB_0010b4fe:
    piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
    if (piVar5 != (int *)0x0) {
      if (!bVar2) {
        return;
      }
      if ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(*param_1 + 0x1d8)) ||
                                         NAN((float)piVar5[0x85])) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1d8) == (float)piVar5[0x85]) << 0xe
                               ) >> 8)) == 0x40) {
        if (piVar5[0x86] == 1) {
          if (iVar4 == 0) {
            iVar4 = *(int *)(*piVar5 + 0x178);
            if ((iVar4 == 0) && (iVar4 = (*DAT_001755d4)(0), iVar4 == 0)) {
              iVar4 = 0;
            }
            else {
              iVar4 = *(int *)(iVar4 + 0xd8);
            }
            goto LAB_0010b4fe;
          }
          iVar3 = *(int *)(*piVar5 + 0x178);
          if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(iVar3 + 0xd8);
          }
          if (iVar4 == iVar3) goto LAB_0010b4fe;
        }
        bVar2 = false;
      }
      goto LAB_0010b4fe;
    }
    if ((bVar2) && (iVar4 = Findgoal__Fi((int)ROUND((float)param_1[0xc6])), iVar4 != 0)) {
      DoResults__FP11CBaseEntityP11CBasePlayeri(iVar4,param_2,param_1[0x8a] & 2);
    }
  }
  return;
}


