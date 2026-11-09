// FlameThink__8CTFFlame  @ 000e4830
void FlameThink__8CTFFlame(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 **ppuVar6;
  undefined1 *puVar7;
  undefined4 *puStack_40;
  int iStack_3c;
  int *piStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*(int *)(*param_1 + 0x178) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*param_1 + 0x178) + 0xdc;
  }
  iVar3 = *(int *)(iVar3 + 0x1e8);
  if (iVar3 == 0) {
    uStack_28 = 0;
    iStack_2c = 0xe4869;
    iVar3 = (*DAT_001755d4)();
    if (iVar3 != 0) goto LAB_000e4872;
    piVar4 = (int *)0x0;
  }
  else {
LAB_000e4872:
    piVar4 = *(int **)(iVar3 + 0xd8);
  }
  if (*(int *)(*param_1 + 0x170) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*param_1 + 0x170) + 0xdc;
  }
  iVar3 = *(int *)(iVar3 + 0x1e8);
  if (iVar3 == 0) {
    uStack_28 = 0;
    iStack_2c = 0xe48b9;
    iVar3 = (*DAT_001755d4)();
    if (iVar3 != 0) goto LAB_000e48c2;
    piVar5 = (int *)0x0;
  }
  else {
LAB_000e48c2:
    piVar5 = *(int **)(iVar3 + 0xd8);
  }
  iStack_2c = *piVar5 + 8;
  uStack_28 = 0;
  iStack_30 = 0x17;
  iStack_34 = 4;
  piStack_38 = (int *)0xe48e7;
  (*DAT_00175578)();
  uStack_28 = 0x79;
  iStack_2c = 0xe48f3;
  (*DAT_00175580)();
  uStack_28 = *(undefined4 *)(*piVar5 + 0x1e8);
  iStack_2c = 0xe4906;
  uStack_28 = (*DAT_001755dc)();
  iStack_2c = 0xe4913;
  (*DAT_00175588)();
  iStack_2c = (int)g_sModelIndexPlayerFlame;
  iStack_30 = 0xe4922;
  (*DAT_00175588)();
  iStack_30 = 5;
  iStack_34 = 0xe492b;
  (*DAT_00175580)();
  iStack_34 = 0x32;
  piStack_38 = (int *)0xe4934;
  (*DAT_00175580)();
  piStack_38 = (int *)0xe493b;
  (*DAT_0017557c)();
  ppuVar6 = (undefined4 **)&stack0xffffffdc;
  fVar1 = (float)piVar5[0x72];
  puVar7 = &stack0xffffffdc;
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if (1.0 <= *(float *)(*piVar5 + 0x140)) {
      if (((*(byte *)(piVar5 + 0xf) & 0x10) != 0) &&
         (fVar1 = *(float *)(*piVar5 + 0x19c),
         (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
        piVar5[0x72] = (int)((float)piVar5[0x72] - 1.0);
        puVar7 = &stack0xffffffdc;
        goto LAB_000e4a4e;
      }
      if ((*(byte *)((int)piVar5 + 0x8a) & 2) != 0) {
        *(float *)(*param_1 + 0x140) = *gpGlobals + 4.5;
        *(byte *)((int)piVar5 + 0x8a) = *(byte *)((int)piVar5 + 0x8a) & 0xfd;
      }
      if (*gpGlobals < (float)param_1[0x184]) {
LAB_000e4aaf:
        *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.2;
        return;
      }
      fVar1 = *(float *)(*param_1 + 0x140);
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        uStack_28 = 8;
        iStack_2c = piVar5[0x72];
        if (*(int *)(*param_1 + 0x178) == 0) {
          iStack_30 = 0;
        }
        else {
          iStack_30 = *(int *)(*param_1 + 0x178) + 0xdc;
        }
        iStack_34 = *param_1;
        iStack_3c = 0xe4aa0;
        piStack_38 = piVar5;
        (**(code **)(piVar5[0xf2] + 0x34))();
        param_1[0x184] = (int)(*gpGlobals + 1.0);
        goto LAB_000e4aaf;
      }
    }
    else {
      iVar3 = *param_1;
      uStack_10 = *(undefined4 *)(iVar3 + 8);
      uStack_c = *(undefined4 *)(iVar3 + 0xc);
      uStack_8 = *(undefined4 *)(iVar3 + 0x10);
      uStack_28 = 0x4000008;
      iStack_2c = 0;
      iStack_30 = 0x41200000;
      iStack_34 = 0x41200000;
      if (piVar4 == (int *)0x0) {
        piStack_38 = (int *)*param_1;
      }
      else {
        piStack_38 = (int *)*piVar4;
      }
      iStack_3c = *param_1;
      puStack_40 = &uStack_10;
      ppuVar6 = &puStack_40;
      RadiusDamage__FG6VectorP9entvars_tT1ffii();
    }
    piVar5[0x72] = 0;
    puVar7 = (undefined1 *)ppuVar6;
  }
LAB_000e4a4e:
  *(int **)(puVar7 + -4) = param_1;
  *(undefined4 *)(puVar7 + -8) = 0xe4a54;
  FlameDestroy__8CTFFlame();
  return;
}


