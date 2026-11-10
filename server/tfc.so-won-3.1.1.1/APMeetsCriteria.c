// APMeetsCriteria__FP11CBaseEntityT0  @ 0010c878
undefined4 APMeetsCriteria__FP11CBaseEntityT0(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  
  if ((param_2 != (int *)0x0) && (iVar3 = (**(code **)(param_2[0x115] + 0x2c))(param_2), iVar3 == 2)
     ) {
    if ((param_1[0x48] != 0) && (param_1[0x48] != param_2[0x48])) {
      return 0;
    }
    if ((param_1[0x88] != 0) &&
       (iVar3 = GetTeamCheckTeam__FPCc(param_1[0x88] + *(int *)(gpGlobals + 0x98)),
       param_2[0x48] != iVar3)) {
      return 0;
    }
    if ((*(int *)(*param_1 + 0x20c) != 0) &&
       (*(int *)(*param_1 + 0x20c) != *(int *)(*param_2 + 0x20c))) {
      return 0;
    }
    iVar3 = param_1[0x3a];
    if (iVar3 != 0) {
      piVar5 = (int *)0x0;
      do {
        piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
        if (piVar5 == (int *)0x0) {
          (*DAT_0019f794)(1,"Could not find an item with a goal_no of %d.\n",iVar3);
          piVar5 = (int *)0x0;
          break;
        }
      } while (piVar5[0x84] != iVar3);
      if (piVar5 == (int *)0x0) {
        return 0;
      }
      if (*(int *)(*piVar5 + 0x198) != *(int *)(*param_2 + 0x208)) {
        return 0;
      }
    }
  }
  iVar3 = param_1[0x8f];
  if (iVar3 != 0) {
    iVar6 = 0;
    do {
      iVar6 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar6,"info_tfgoal");
      if (iVar6 == 0) {
        (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar3);
        iVar6 = 0;
        break;
      }
    } while (*(int *)(iVar6 + 0x210) != iVar3);
    if (iVar6 == 0) {
      return 0;
    }
    if (*(int *)(iVar6 + 0x218) != 1) {
      return 0;
    }
  }
  iVar3 = param_1[0x90];
  if (iVar3 != 0) {
    iVar6 = 0;
    do {
      iVar6 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar6,"info_tfgoal");
      if (iVar6 == 0) {
        (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar3);
        iVar6 = 0;
        break;
      }
    } while (*(int *)(iVar6 + 0x210) != iVar3);
    if (iVar6 == 0) {
      return 0;
    }
    if (*(int *)(iVar6 + 0x218) != 2) {
      return 0;
    }
  }
  iVar3 = param_1[0x91];
  if (iVar3 != 0) {
    iVar6 = 0;
    do {
      iVar6 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar6,"info_tfgoal");
      if (iVar6 == 0) {
        (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar3);
        iVar6 = 0;
        break;
      }
    } while (*(int *)(iVar6 + 0x210) != iVar3);
    if (iVar6 == 0) {
      return 0;
    }
    if (*(int *)(iVar6 + 0x218) != 3) {
      return 0;
    }
  }
  iVar3 = param_1[0x92];
  if (iVar3 == 0) {
LAB_0010cb1b:
    iVar3 = param_1[0x93];
    if (iVar3 == 0) {
LAB_0010cb5b:
      iVar3 = param_1[0x94];
      if (iVar3 == 0) {
LAB_0010cb9b:
        iVar3 = param_1[0xae];
        if (iVar3 != 0) {
          piVar5 = (int *)0x0;
          do {
            piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
            if (piVar5 == (int *)0x0) {
              (*DAT_0019f794)(1,"Could not find an item with a goal_no of %d.\n",iVar3);
              piVar5 = (int *)0x0;
              break;
            }
          } while (piVar5[0x84] != iVar3);
          if (piVar5 == (int *)0x0) {
            return 0;
          }
          if (piVar5[0x86] != 1) {
            iVar3 = *piVar5;
            bVar4 = false;
            if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) ||
                                                NAN(*(float *)(iVar3 + 8))) << 10) >> 8) |
                       (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8))
                                      << 0xe) >> 8)) == 0x40) &&
               ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) ||
                                               NAN(*(float *)(iVar3 + 0xc))) << 10) >> 8) |
                      (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc))
                                     << 0xe) >> 8)) == 0x40)) {
              fVar1 = *(float *)(iVar3 + 0x10);
              fVar2 = *(float *)(iVar3 + 0x1c);
              bVar4 = (byte)(fVar2 < fVar1 |
                             (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
            }
            if (bVar4) {
              return 0;
            }
          }
        }
        iVar3 = param_1[0xaf];
        if (iVar3 != 0) {
          piVar5 = (int *)0x0;
          do {
            piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
            if (piVar5 == (int *)0x0) {
              (*DAT_0019f794)(1,"Could not find an item with a goal_no of %d.\n",iVar3);
              piVar5 = (int *)0x0;
              break;
            }
          } while (piVar5[0x84] != iVar3);
          if (piVar5 == (int *)0x0) {
            return 0;
          }
          if (piVar5[0x86] == 1) {
            return 0;
          }
          iVar3 = *piVar5;
          bVar4 = false;
          if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) ||
                                              NAN(*(float *)(iVar3 + 8))) << 10) >> 8) |
                     (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8)) <<
                                    0xe) >> 8)) == 0x40) &&
             ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) ||
                                             NAN(*(float *)(iVar3 + 0xc))) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc)) <<
                                   0xe) >> 8)) == 0x40)) {
            fVar1 = *(float *)(iVar3 + 0x10);
            fVar2 = *(float *)(iVar3 + 0x1c);
            bVar4 = (byte)(fVar2 < fVar1 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
          }
          if (!bVar4) {
            return 0;
          }
        }
        if ((param_2 != (int *)0x0) &&
           (iVar3 = (**(code **)(param_2[0x115] + 0x2c))(param_2), iVar3 == 2)) {
          iVar3 = param_1[0xaa];
          if (iVar3 != 0) {
            piVar5 = (int *)0x0;
            do {
              piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
              if (piVar5 == (int *)0x0) {
                return 0;
              }
            } while ((piVar5[0x85] != iVar3) ||
                    (*(int *)(*piVar5 + 0x198) != *(int *)(*param_2 + 0x208)));
          }
          iVar3 = param_1[0xab];
          if (iVar3 != 0) {
            piVar5 = (int *)0x0;
            do {
              piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
              if (piVar5 == (int *)0x0) {
                return 1;
              }
            } while ((piVar5[0x85] != iVar3) ||
                    (*(int *)(*piVar5 + 0x198) != *(int *)(*param_2 + 0x208)));
            return 0;
          }
        }
        return 1;
      }
      iVar6 = 0;
      do {
        iVar6 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar6,"info_tfgoal");
        if (iVar6 == 0) goto LAB_0010cb9b;
      } while ((*(int *)(iVar6 + 0x214) != iVar3) || (*(int *)(iVar6 + 0x218) == 3));
    }
    else {
      iVar6 = 0;
      do {
        iVar6 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar6,"info_tfgoal");
        if (iVar6 == 0) goto LAB_0010cb5b;
      } while ((*(int *)(iVar6 + 0x214) != iVar3) || (*(int *)(iVar6 + 0x218) == 2));
    }
  }
  else {
    iVar6 = 0;
    do {
      iVar6 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar6,"info_tfgoal");
      if (iVar6 == 0) goto LAB_0010cb1b;
    } while ((*(int *)(iVar6 + 0x214) != iVar3) || (*(int *)(iVar6 + 0x218) == 1));
  }
  return 0;
}


