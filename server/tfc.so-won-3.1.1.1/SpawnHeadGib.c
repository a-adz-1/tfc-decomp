// SpawnHeadGib__4CGibP9entvars_s  @ 00094ef4
void SpawnHeadGib__4CGibP9entvars_s(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  longdouble lVar9;
  longdouble lVar10;
  longdouble lVar11;
  float local_38;
  float local_1c;
  float local_18;
  float local_14;
  
  piVar5 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
  if (g_Language == 1) {
    pcVar6 = "models/germangibs.mdl";
  }
  else {
    pcVar6 = "models/hgibs.mdl";
  }
  Spawn__4CGibPCc(piVar5,pcVar6);
  *(undefined4 *)(*piVar5 + 0x114) = 0;
  if (param_1 == 0) goto LAB_0009525d;
  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 0x178);
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_1 + 0x17c);
  iVar7 = *piVar5;
  *(float *)(iVar7 + 8) = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x174);
  *(float *)(iVar7 + 0xc) = fVar1 + fVar2;
  *(float *)(iVar7 + 0x10) = fVar3 + fVar4;
  iVar7 = (*DAT_0019f6e4)(*(undefined4 *)(*piVar5 + 0x208));
  iVar8 = (*DAT_0019f808)(0,100);
  if ((iVar8 < 6) && (iVar7 != 0)) {
    iVar8 = *piVar5;
    local_1c = (*(float *)(iVar7 + 0x88) + *(float *)(iVar7 + 500)) - *(float *)(*piVar5 + 8);
    local_18 = (*(float *)(iVar7 + 0x8c) + *(float *)(iVar7 + 0x1f8)) - *(float *)(*piVar5 + 0xc);
    fVar1 = (*(float *)(iVar7 + 0x90) + *(float *)(iVar7 + 0x1fc)) - *(float *)(*piVar5 + 0x10);
    local_14 = SQRT(fVar1 * fVar1 + local_18 * local_18 + local_1c * local_1c);
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 1.0;
    }
    else {
      local_14 = 1.0 / local_14;
      local_1c = local_1c * local_14;
      local_18 = local_18 * local_14;
      local_14 = local_14 * fVar1;
    }
    *(float *)(iVar8 + 0x20) = local_1c * 300.0;
    *(float *)(iVar8 + 0x24) = local_18 * 300.0;
    *(float *)(iVar8 + 0x28) = local_14 * 300.0;
    *(float *)(*piVar5 + 0x28) = *(float *)(*piVar5 + 0x28) + 100.0;
  }
  else {
    iVar7 = *piVar5;
    lVar11 = (longdouble)(*DAT_0019f80c)(0xc2c80000,0x42c80000);
    lVar9 = (longdouble)(*DAT_0019f80c)(0xc2c80000,0x42c80000);
    lVar10 = (longdouble)(*DAT_0019f80c)(0x43480000,0x43960000);
    *(float *)(iVar7 + 0x20) = (float)lVar11;
    *(float *)(iVar7 + 0x24) = (float)lVar9;
    *(float *)(iVar7 + 0x28) = (float)lVar10;
  }
  lVar11 = (longdouble)(*DAT_0019f80c)(0x42c80000,0x43480000);
  *(float *)(*piVar5 + 0x5c) = (float)lVar11;
  lVar11 = (longdouble)(*DAT_0019f80c)(0x42c80000,0x43960000);
  *(float *)(*piVar5 + 0x60) = (float)lVar11;
  iVar7 = *(int *)(param_1 + 0x208);
  if (iVar7 == 0) {
    iVar7 = (*DAT_0019f7b4)(0);
    if (iVar7 != 0) goto LAB_000951ab;
    iVar7 = 0;
  }
  else {
LAB_000951ab:
    iVar7 = *(int *)(iVar7 + 0x7c);
  }
  iVar7 = (**(code **)(*(int *)(iVar7 + 0x454) + 0x44))(iVar7);
  piVar5[0x116] = iVar7;
  fVar1 = *(float *)(param_1 + 0x160);
  if ((byte)((fVar1 < -50.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == -50.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (fVar1 <= -200.0) {
      iVar7 = *piVar5;
      fVar1 = 4.0;
      goto LAB_0009522f;
    }
    iVar7 = *piVar5;
    local_38 = *(float *)(iVar7 + 0x20) + *(float *)(iVar7 + 0x20);
    fVar2 = *(float *)(iVar7 + 0x24) + *(float *)(iVar7 + 0x24);
    fVar1 = *(float *)(iVar7 + 0x28) + *(float *)(iVar7 + 0x28);
  }
  else {
    iVar7 = *piVar5;
    fVar1 = 0.7;
LAB_0009522f:
    local_38 = *(float *)(iVar7 + 0x20) * fVar1;
    fVar2 = *(float *)(iVar7 + 0x24) * fVar1;
    fVar1 = fVar1 * *(float *)(iVar7 + 0x28);
  }
  *(float *)(iVar7 + 0x20) = local_38;
  *(float *)(iVar7 + 0x24) = fVar2;
  *(float *)(iVar7 + 0x28) = fVar1;
LAB_0009525d:
  LimitVelocity__4CGib(piVar5);
  return;
}


