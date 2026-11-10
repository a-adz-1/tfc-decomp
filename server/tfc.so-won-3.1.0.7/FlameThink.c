// FlameThink__8CTFFlame  @ 000e50c4
void FlameThink__8CTFFlame(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar5 = *(int *)(*param_1 + 0x198) + 0x80;
  if (*(int *)(*param_1 + 0x198) == 0) {
    iVar5 = 0;
  }
  iVar5 = *(int *)(iVar5 + 0x208);
  if ((iVar5 == 0) && (iVar5 = (*DAT_001c1134)(0), iVar5 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar5 + 0x7c);
  }
  iVar5 = *(int *)(*param_1 + 400) + 0x80;
  if (*(int *)(*param_1 + 400) == 0) {
    iVar5 = 0;
  }
  iVar5 = *(int *)(iVar5 + 0x208);
  if ((iVar5 == 0) && (iVar5 = (*DAT_001c1134)(0), iVar5 == 0)) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = *(int **)(iVar5 + 0x7c);
  }
  (*DAT_001c10d8)(4,0x17,*piVar7 + 8,0);
  (*DAT_001c10e0)(0x79);
  uVar3 = (*DAT_001c113c)(*(undefined4 *)(*piVar7 + 0x208));
  (*DAT_001c10e8)(uVar3);
  (*DAT_001c10e8)((int)g_sModelIndexPlayerFlame);
  (*DAT_001c10e0)(5);
  (*DAT_001c10e0)(0x32);
  (*DAT_001c10dc)();
  fVar1 = (float)piVar7[0x72];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = *(float *)(*piVar7 + 0x160);
    if (0x3f < (byte)((1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) - 1)) {
      iVar5 = *param_1;
      local_c = *(undefined4 *)(iVar5 + 8);
      local_8 = *(undefined4 *)(iVar5 + 0xc);
      local_4 = *(undefined4 *)(iVar5 + 0x10);
      if (piVar6 == (int *)0x0) {
        iVar5 = *param_1;
      }
      else {
        iVar5 = *piVar6;
      }
      RadiusDamage__FG6VectorP9entvars_sT1ffii
                (&local_c,*param_1,iVar5,0x41200000,0x41200000,0,0x4000008);
      piVar7[0x72] = 0;
      FlameDestroy__8CTFFlame(param_1);
      return;
    }
    if (((*(byte *)(piVar7 + 0xe) & 0x10) == 0) || (*(float *)(*piVar7 + 0x1bc) <= 0.0)) {
      if ((*(byte *)((int)piVar7 + 0x86) & 2) != 0) {
        *(float *)(*param_1 + 0x160) = *gpGlobals + 5.0;
        *(byte *)((int)piVar7 + 0x86) = *(byte *)((int)piVar7 + 0x86) & 0xfd;
      }
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x1a3];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        if (*(float *)(*param_1 + 0x160) < *gpGlobals) {
          piVar7[0x72] = 0;
          goto LAB_000e536f;
        }
        iVar5 = (**(code **)(piVar7[0x111] + 0x8c))(piVar7);
        if (iVar5 != 0) {
          iVar5 = *(int *)(*param_1 + 0x198) + 0x80;
          if (*(int *)(*param_1 + 0x198) == 0) {
            iVar5 = 0;
          }
          (**(code **)(piVar7[0x111] + 0x38))
                    (piVar7,*param_1,iVar5,(float)piVar7[0x72] + (float)piVar7[0x72],8);
          iVar5 = (**(code **)(piVar7[0x111] + 0x8c))(piVar7);
          if (iVar5 == 0) {
            if (piVar7[0x48] == 0) {
              pcVar4 = "SPECTATOR";
            }
            else {
              pcVar4 = (char *)GetTeamName__Fi(piVar7[0x48],"flames");
            }
            uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*piVar7 + 0x208),pcVar4);
            uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*piVar7 + 0x208),uVar3);
            if (piVar6[0x48] == 0) {
              pcVar4 = "SPECTATOR";
            }
            else {
              pcVar4 = (char *)GetTeamName__Fi(piVar6[0x48],
                                               *(int *)(*piVar7 + 0x1d0) + (int)gpGlobals[0x26],
                                               uVar3);
            }
            uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*piVar6 + 0x208),pcVar4);
            uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*piVar6 + 0x208),uVar3);
            UTIL_LogPrintf__FPce
                      ("\"%s<%i><%u><%s>\" killed \"%s<%i><%u><%s>\" with \"%s\"\n",
                       *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
          }
        }
        param_1[0x1a3] = (int)(*gpGlobals + 1.0);
      }
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
      return;
    }
    piVar7[0x72] = (int)((float)piVar7[0x72] - 1.0);
  }
LAB_000e536f:
  FlameDestroy__8CTFFlame(param_1);
  return;
}


