// FlameThink__8CTFFlame  @ 000e64e4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FlameThink__8CTFFlame(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 **ppuVar5;
  undefined1 *puVar6;
  int *piVar7;
  undefined4 *puStack_50;
  int *piStack_4c;
  int *piStack_48;
  int iStack_44;
  int iStack_40;
  char *pcStack_3c;
  int *piStack_38;
  int *local_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  ppuVar5 = (undefined4 **)&stack0xffffffcc;
  puVar6 = &stack0xffffffcc;
  iVar4 = *(int *)(*param_1 + 0x198) + 0x80;
  if (*(int *)(*param_1 + 0x198) == 0) {
    iVar4 = 0;
  }
  iVar4 = *(int *)(iVar4 + 0x208);
  if (iVar4 == 0) {
    piStack_38 = (int *)0x0;
    pcStack_3c = (char *)0xe652c;
    iVar4 = (*DAT_0019f7b4)();
    if (iVar4 != 0) goto LAB_000e6535;
    local_18 = (int *)0x0;
  }
  else {
LAB_000e6535:
    local_18 = *(int **)(iVar4 + 0x7c);
  }
  iVar4 = *(int *)(*param_1 + 400) + 0x80;
  if (*(int *)(*param_1 + 400) == 0) {
    iVar4 = 0;
  }
  iVar4 = *(int *)(iVar4 + 0x208);
  if (iVar4 == 0) {
    piStack_38 = (int *)0x0;
    pcStack_3c = (char *)0xe6578;
    iVar4 = (*DAT_0019f7b4)();
    if (iVar4 != 0) goto LAB_000e6581;
    piVar7 = (int *)0x0;
  }
  else {
LAB_000e6581:
    piVar7 = *(int **)(iVar4 + 0x7c);
  }
  piStack_38 = (int *)0x0;
  pcStack_3c = (char *)(*piVar7 + 8);
  iStack_40 = 0x17;
  iStack_44 = 4;
  piStack_48 = (int *)0xe65a4;
  (*DAT_0019f758)();
  piStack_38 = (int *)0x79;
  pcStack_3c = (char *)0xe65b7;
  (*DAT_0019f760)();
  piStack_38 = *(int **)(*piVar7 + 0x208);
  pcStack_3c = (char *)0xe65d1;
  piStack_38 = (int *)(*DAT_0019f7bc)();
  pcStack_3c = (char *)0xe65df;
  (*DAT_0019f768)();
  pcStack_3c = (char *)(int)g_sModelIndexPlayerFlame;
  iStack_40 = 0xe65f7;
  (*DAT_0019f768)();
  iStack_40 = 5;
  iStack_44 = 0xe6607;
  (*DAT_0019f760)();
  iStack_44 = 0x32;
  piStack_48 = (int *)0xe6617;
  (*DAT_0019f760)();
  piStack_48 = (int *)0xe6625;
  (*DAT_0019f75c)();
  fVar1 = (float)piVar7[0x72];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar2 = *(float *)(*piVar7 + 0x160);
    if ((byte)((1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (((*(byte *)(piVar7 + 0xe) & 0x10) != 0) && (0.0 < *(float *)(*piVar7 + 0x1bc))) {
        piVar7[0x72] = (int)(fVar1 - 1.0);
        puVar6 = &stack0xffffffcc;
        goto LAB_000e674b;
      }
      if ((*(byte *)((int)piVar7 + 0x86) & 2) != 0) {
        *(float *)(*param_1 + 0x160) = (float)_FUN_00151718 + *gpGlobals;
        *(byte *)((int)piVar7 + 0x86) = *(byte *)((int)piVar7 + 0x86) & 0xfd;
      }
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x1a7];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
LAB_000e68e6:
        *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
        return;
      }
      fVar2 = *(float *)(*param_1 + 0x160);
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        pcStack_3c = (char *)0xe6767;
        piStack_38 = piVar7;
        iVar4 = (**(code **)(piVar7[0x115] + 0x8c))();
        if (iVar4 != 0) {
          piStack_38 = (int *)0x8;
          pcStack_3c = (char *)((float)piVar7[0x72] + (float)piVar7[0x72]);
          iStack_44 = *param_1;
          iStack_40 = *(int *)(iStack_44 + 0x198) + 0x80;
          if (*(int *)(iStack_44 + 0x198) == 0) {
            iStack_40 = 0;
          }
          piStack_4c = (int *)0xe67a9;
          piStack_48 = piVar7;
          (**(code **)(piVar7[0x115] + 0x38))();
          puStack_50 = (undefined4 *)0xe67b8;
          piStack_4c = piVar7;
          iVar4 = (**(code **)(piVar7[0x115] + 0x8c))();
          if (iVar4 == 0) {
            piStack_38 = (int *)0x1516a2;
            pcStack_3c = (char *)piVar7[0x48];
            if (pcStack_3c == (char *)0x0) {
              pcStack_3c = "SPECTATOR";
            }
            else {
              iStack_40 = 0xe67da;
              pcStack_3c = (char *)GetTeamName__Fi();
            }
            iStack_40 = *(undefined4 *)(*piVar7 + 0x208);
            iStack_44 = 0xe6802;
            iStack_40 = (*DAT_0019f8dc)();
            iStack_44 = *(undefined4 *)(*piVar7 + 0x208);
            piStack_48 = (int *)0xe681f;
            iStack_44 = (*DAT_0019f864)();
            piStack_48 = (int *)(*(int *)(*piVar7 + 0x1d0) + (int)gpGlobals[0x26]);
            piStack_4c = (int *)local_18[0x48];
            if (piStack_4c == (int *)0x0) {
              piStack_4c = (int *)0x1516b8;
            }
            else {
              puStack_50 = (undefined4 *)0xe6851;
              piStack_4c = (int *)GetTeamName__Fi();
            }
            puStack_50 = *(undefined4 **)(*local_18 + 0x208);
            puStack_50 = (undefined4 *)(*DAT_0019f8dc)();
            uVar3 = (*DAT_0019f864)(*(undefined4 *)(*local_18 + 0x208));
            UTIL_LogPrintf__FPce
                      ("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                       *(int *)(*local_18 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
          }
        }
        param_1[0x1a7] = (int)(*gpGlobals + 1.0);
        goto LAB_000e68e6;
      }
    }
    else {
      piStack_4c = (int *)*param_1;
      uStack_10 = *(undefined4 *)((int)piStack_4c + 8);
      uStack_c = *(undefined4 *)((int)piStack_4c + 0xc);
      uStack_8 = *(undefined4 *)((int)piStack_4c + 0x10);
      piStack_38 = (int *)0x4000008;
      pcStack_3c = (char *)0x0;
      iStack_40 = 0x41200000;
      iStack_44 = 0x41200000;
      piStack_48 = piStack_4c;
      if (local_18 != (int *)0x0) {
        piStack_48 = (int *)*local_18;
      }
      puStack_50 = &uStack_10;
      ppuVar5 = &puStack_50;
      RadiusDamage__FG6VectorP9entvars_sT1ffii();
    }
    piVar7[0x72] = 0;
    puVar6 = (undefined1 *)ppuVar5;
  }
LAB_000e674b:
  *(int **)(puVar6 + -4) = param_1;
  *(undefined4 *)(puVar6 + -8) = 0xe6751;
  FlameDestroy__8CTFFlame();
  return;
}


