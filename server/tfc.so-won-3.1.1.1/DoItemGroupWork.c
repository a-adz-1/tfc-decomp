// DoItemGroupWork__FP11CBaseEntityP11CBasePlayer  @ 0010dc54
void DoItemGroupWork__FP11CBaseEntityP11CBasePlayer(int *param_1,undefined4 param_2)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iStack_14;
  
  fVar1 = (float)param_1[0xce];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x200)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x200) == 0.0) << 0xe) >> 8)) == 0x40)
    {
      (*DAT_0019f794)(1,"GoalItem %d has .distance specified, but no .pain_finished\n",param_1[0x84]
                     );
    }
    bVar2 = true;
    iVar3 = 0;
    while (iVar3 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar3,"item_tfgoal"), iVar3 != 0)
    {
      if (!bVar2) goto LAB_0010dda9;
      if (((byte)((byte)((ushort)((ushort)(NAN((float)param_1[0xce]) ||
                                          NAN((float)*(int *)(iVar3 + 0x214))) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)param_1[0xce] == (float)*(int *)(iVar3 + 0x214)) <<
                                0xe) >> 8)) == 0x40) && (*(int *)(iVar3 + 0x218) != 1)) {
        bVar2 = false;
      }
    }
    if (bVar2) {
      fVar1 = *(float *)(*param_1 + 0x200);
      iVar3 = 0;
      do {
        iVar3 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar3,"info_tfgoal");
        if (iVar3 == 0) {
          (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",(int)ROUND(fVar1));
          iVar3 = 0;
          break;
        }
      } while (*(int *)(iVar3 + 0x210) != (int)ROUND(fVar1));
      if (iVar3 != 0) {
        DoResults__FP11CBaseEntityP11CBasePlayeri(iVar3,param_2,param_1[0x8c] & 2);
      }
    }
  }
LAB_0010dda9:
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xcd]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xcd] == 0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_0019f794)(1,"GoalItem %d has .speed specified, but no .attack_finished\n",param_1[0x84])
      ;
    }
    iStack_14 = 0;
    bVar2 = true;
    piVar4 = (int *)0x0;
LAB_0010debd:
    piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"item_tfgoal");
    if (piVar4 != (int *)0x0) {
      if (!bVar2) {
        return;
      }
      if ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(*param_1 + 0x1f8)) ||
                                         NAN((float)piVar4[0x85])) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1f8) == (float)piVar4[0x85]) << 0xe
                               ) >> 8)) == 0x40) {
        if (piVar4[0x86] == 1) {
          if (iStack_14 == 0) {
            iVar3 = *(int *)(*piVar4 + 0x198);
            if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
              iStack_14 = 0;
            }
            else {
              iStack_14 = *(int *)(iVar3 + 0x7c);
            }
            goto LAB_0010debd;
          }
          iVar3 = *(int *)(*piVar4 + 0x198);
          if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(iVar3 + 0x7c);
          }
          if (iStack_14 == iVar3) goto LAB_0010debd;
        }
        bVar2 = false;
      }
      goto LAB_0010debd;
    }
    if (bVar2) {
      fVar1 = (float)param_1[0xcd];
      iVar3 = 0;
      do {
        iVar3 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar3,"info_tfgoal");
        if (iVar3 == 0) {
          (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",(int)ROUND(fVar1));
          iVar3 = 0;
          break;
        }
      } while (*(int *)(iVar3 + 0x210) != (int)ROUND(fVar1));
      if (iVar3 != 0) {
        DoResults__FP11CBaseEntityP11CBasePlayeri(iVar3,param_2,param_1[0x8c] & 2);
      }
    }
  }
  return;
}


