// DoGroupWork__FP11CBaseEntityP11CBasePlayer  @ 0010d864
void DoGroupWork__FP11CBaseEntityP11CBasePlayer(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  if (*(int *)(param_1 + 0x3fc) != 0) {
    if (*(int *)(param_1 + 0x34) == 0) {
      (*DAT_0019f794)(1,"Goal %d has .all_active specified, but no .last_impulse\n",
                      *(undefined4 *)(param_1 + 0x210));
    }
    else {
      bVar3 = true;
      iVar5 = 0;
      while (iVar5 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar5,"info_tfgoal"), iVar5 != 0
            ) {
        if (!bVar3) goto LAB_0010d96e;
        if ((*(int *)(iVar5 + 0x214) == *(int *)(param_1 + 0x3fc)) && (*(int *)(iVar5 + 0x218) != 1)
           ) {
          bVar3 = false;
        }
      }
      if (bVar3) {
        iVar5 = *(int *)(param_1 + 0x34);
        iVar4 = 0;
        do {
          iVar4 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar4,"info_tfgoal");
          if (iVar4 == 0) {
            (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar5);
            iVar4 = 0;
            break;
          }
        } while (*(int *)(iVar4 + 0x210) != iVar5);
        if (iVar4 != 0) {
          DoResults__FP11CBaseEntityP11CBasePlayeri(iVar4,param_2,*(uint *)(param_1 + 0x230) & 2);
        }
      }
    }
  }
LAB_0010d96e:
  if (*(int *)(param_1 + 0x26c) != 0) {
    iVar5 = 0;
    while (iVar5 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar5,"info_tfgoal"), iVar5 != 0)
    {
      if ((*(int *)(iVar5 + 0x214) == *(int *)(param_1 + 0x26c)) &&
         (iVar4 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(iVar5,param_2,param_1),
         iVar4 != 0)) {
        if ((param_1 == iVar5) || (*(int *)(iVar5 + 0x27c) == 1)) {
          uVar7 = 1;
        }
        else if (param_1 == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(uint *)(param_1 + 0x230) & 2;
        }
        DoResults__FP11CBaseEntityP11CBasePlayeri(iVar5,param_2,uVar7);
      }
    }
  }
  if (*(int *)(param_1 + 0x270) != 0) {
    piVar6 = (int *)0x0;
    while (piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"info_tfgoal"),
          piVar6 != (int *)0x0) {
      if ((piVar6[0x85] == *(int *)(param_1 + 0x270)) && (piVar6[0x86] == 1)) {
        iVar5 = (**(code **)(piVar6[0x115] + 0x2c))(piVar6);
        if (iVar5 != 0x81) {
          if (((*(byte *)((int)piVar6 + 0x229) & 0x20) == 0) ||
             ((iVar5 = (**(code **)(piVar6[0x115] + 0x2c))(piVar6), iVar5 != 0x80 &&
              (iVar5 = (**(code **)(piVar6[0x115] + 0x2c))(piVar6), iVar5 != 0x82)))) {
            *(undefined4 *)(*piVar6 + 0x10c) = 1;
          }
          else {
            *(undefined4 *)(*piVar6 + 0x10c) = 2;
          }
        }
        piVar6[0x86] = 2;
        if (*(char *)(*(int *)(*piVar6 + 0xb8) + (int)gpGlobals[0x26]) != '*') {
          pbVar1 = (byte *)(*piVar6 + 0x118);
          *pbVar1 = *pbVar1 & 0x7f;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x274) != 0) {
    piVar6 = (int *)0x0;
    while (piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"info_tfgoal"),
          piVar6 != (int *)0x0) {
      if (piVar6[0x85] == *(int *)(param_1 + 0x274)) {
        *(undefined4 *)(*piVar6 + 0x10c) = 0;
        piVar6[0x86] = 3;
        *(byte *)(*piVar6 + 0x118) = *(byte *)(*piVar6 + 0x118) | 0x80;
      }
    }
  }
  if (*(int *)(param_1 + 0x278) != 0) {
    piVar6 = (int *)0x0;
    while (piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"info_tfgoal"),
          piVar6 != (int *)0x0) {
      if ((piVar6[0x85] == *(int *)(param_1 + 0x278)) && (piVar6[0x86] == 3)) {
        fVar2 = (float)piVar6[0x95];
        if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
          if (((*(byte *)((int)piVar6 + 0x229) & 0x20) == 0) ||
             (iVar5 = strcmp((char *)(*(int *)*piVar6 + (int)gpGlobals[0x26]),"item_tfgoal"),
             iVar5 != 0)) {
            *(undefined4 *)(*piVar6 + 0x10c) = 1;
          }
          else {
            *(undefined4 *)(*piVar6 + 0x10c) = 2;
          }
        }
        else {
          *(float *)(*piVar6 + 0x104) = *gpGlobals + fVar2;
        }
        piVar6[0x86] = 2;
        if (*(char *)(*(int *)(*piVar6 + 0xb8) + (int)gpGlobals[0x26]) != '*') {
          pbVar1 = (byte *)(*piVar6 + 0x118);
          *pbVar1 = *pbVar1 & 0x7f;
        }
      }
    }
  }
  return;
}


