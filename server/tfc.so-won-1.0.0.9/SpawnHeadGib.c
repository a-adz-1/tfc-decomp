// SpawnHeadGib__4CGibP9entvars_t  @ 000a3f50
void SpawnHeadGib__4CGibP9entvars_t(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  char *pcVar11;
  float local_38;
  float local_1c;
  float local_18;
  float local_14;
  
  piVar5 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
  if (g_Language == 1) {
    pcVar11 = "models/germangibs.mdl";
  }
  else {
    pcVar11 = "models/hgibs.mdl";
  }
  Spawn__4CGibPCc(piVar5,pcVar11);
  *(undefined4 *)(*piVar5 + 0xf4) = 0;
  if (param_1 == 0) goto LAB_000a4289;
  iVar6 = *piVar5;
  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 0x158);
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_1 + 0x15c);
  *(float *)(iVar6 + 8) = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x154);
  *(float *)(iVar6 + 0xc) = fVar1 + fVar2;
  *(float *)(iVar6 + 0x10) = fVar3 + fVar4;
  iVar6 = (*DAT_00175504)(*(undefined4 *)(*piVar5 + 0x1e8));
  iVar7 = (*DAT_00175628)(0,100);
  if ((iVar7 < 6) && (iVar6 != 0)) {
    iVar7 = *piVar5;
    local_1c = (*(float *)(iVar6 + 0xe4) + *(float *)(iVar6 + 0x230)) - *(float *)(*piVar5 + 8);
    local_18 = (*(float *)(iVar6 + 0xe8) + *(float *)(iVar6 + 0x234)) - *(float *)(*piVar5 + 0xc);
    fVar1 = (*(float *)(iVar6 + 0xec) + *(float *)(iVar6 + 0x238)) - *(float *)(*piVar5 + 0x10);
    local_14 = SQRT(fVar1 * fVar1 + local_18 * local_18 + local_1c * local_1c);
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 1.0;
    }
    else {
      local_14 = 1.0 / local_14;
      local_1c = local_14 * local_1c;
      local_18 = local_14 * local_18;
      local_14 = local_14 * fVar1;
    }
    *(float *)(iVar7 + 0x20) = local_1c * 300.0;
    *(float *)(iVar7 + 0x24) = local_18 * 300.0;
    *(float *)(iVar7 + 0x28) = local_14 * 300.0;
    *(float *)(*piVar5 + 0x28) = *(float *)(*piVar5 + 0x28) + 100.0;
  }
  else {
    iVar6 = *piVar5;
    lVar10 = (longdouble)(*DAT_0017562c)(0xc2c80000,0x42c80000);
    lVar8 = (longdouble)(*DAT_0017562c)(0xc2c80000,0x42c80000);
    lVar9 = (longdouble)(*DAT_0017562c)(0x43480000,0x43960000);
    *(float *)(iVar6 + 0x20) = (float)lVar10;
    *(float *)(iVar6 + 0x24) = (float)lVar8;
    *(float *)(iVar6 + 0x28) = (float)lVar9;
  }
  lVar10 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43480000);
  *(float *)(*piVar5 + 0x5c) = (float)lVar10;
  lVar10 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43960000);
  *(float *)(*piVar5 + 0x60) = (float)lVar10;
  iVar6 = *(int *)(param_1 + 0x1e8);
  if (iVar6 == 0) {
    iVar6 = (*DAT_001755d4)(0);
    if (iVar6 != 0) goto LAB_000a41ba;
    iVar6 = 0;
  }
  else {
LAB_000a41ba:
    iVar6 = *(int *)(iVar6 + 0xd8);
  }
  iVar6 = (**(code **)(*(int *)(iVar6 + 0x3c8) + 0x40))(iVar6);
  piVar5[0xf3] = iVar6;
  fVar1 = *(float *)(param_1 + 0x140);
  if ((byte)(-50.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == -50.0) << 0xe) >> 8)) == 1) {
    iVar6 = *piVar5;
    fVar1 = 0.7;
LAB_000a425b:
    local_38 = *(float *)(iVar6 + 0x20) * fVar1;
    fVar2 = *(float *)(iVar6 + 0x24) * fVar1;
    fVar1 = fVar1 * *(float *)(iVar6 + 0x28);
  }
  else {
    fVar1 = *(float *)(param_1 + 0x140);
    if ((byte)(-200.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -200.0) << 0xe) >> 8)) != 1) {
      iVar6 = *piVar5;
      fVar1 = 4.0;
      goto LAB_000a425b;
    }
    iVar6 = *piVar5;
    local_38 = *(float *)(iVar6 + 0x20) + *(float *)(iVar6 + 0x20);
    fVar2 = *(float *)(iVar6 + 0x24) + *(float *)(iVar6 + 0x24);
    fVar1 = *(float *)(iVar6 + 0x28) + *(float *)(iVar6 + 0x28);
  }
  *(float *)(iVar6 + 0x20) = local_38;
  *(float *)(iVar6 + 0x24) = fVar2;
  *(float *)(iVar6 + 0x28) = fVar1;
LAB_000a4289:
  LimitVelocity__4CGib(piVar5);
  return;
}


