// RadiationThink__12CTriggerHurt  @ 00110470
void RadiationThink__12CTriggerHurt(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  
  iVar12 = *param_1;
  uVar2 = *(undefined4 *)(iVar12 + 8);
  uVar3 = *(undefined4 *)(iVar12 + 0xc);
  uVar4 = *(undefined4 *)(iVar12 + 0x10);
  uVar5 = *(undefined4 *)(iVar12 + 0x154);
  uVar6 = *(undefined4 *)(iVar12 + 0x158);
  uVar7 = *(undefined4 *)(iVar12 + 0x15c);
  *(float *)(iVar12 + 8) = (*(float *)(iVar12 + 0xa4) + *(float *)(iVar12 + 0xb0)) * 0.5;
  *(float *)(iVar12 + 0xc) = (*(float *)(iVar12 + 0xa8) + *(float *)(iVar12 + 0xb4)) * 0.5;
  *(float *)(iVar12 + 0x10) = (*(float *)(iVar12 + 0xac) + *(float *)(iVar12 + 0xb8)) * 0.5;
  iVar12 = *param_1;
  *(float *)(iVar12 + 0x154) = *(float *)(iVar12 + 0x154) * 0.0;
  *(float *)(iVar12 + 0x158) = *(float *)(iVar12 + 0x158) * 0.0;
  *(float *)(iVar12 + 0x15c) = *(float *)(iVar12 + 0x15c) * 0.0;
  iVar11 = (*DAT_00175504)(*(undefined4 *)(*param_1 + 0x1e8));
  iVar12 = *param_1;
  *(undefined4 *)(iVar12 + 8) = uVar2;
  *(undefined4 *)(iVar12 + 0xc) = uVar3;
  *(undefined4 *)(iVar12 + 0x10) = uVar4;
  iVar12 = *param_1;
  *(undefined4 *)(iVar12 + 0x154) = uVar5;
  *(undefined4 *)(iVar12 + 0x158) = uVar6;
  *(undefined4 *)(iVar12 + 0x15c) = uVar7;
  bVar10 = false;
  if ((iVar11 == 0) || (iVar12 = (*DAT_001755d8)(iVar11), iVar12 == 0)) {
    bVar10 = true;
  }
  if (!bVar10) {
    if (iVar11 == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = iVar11 + 0xdc;
    }
    iVar12 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(iVar12);
    if (iVar11 == 0) {
      iVar11 = 0;
    }
    else {
      iVar11 = iVar11 + 0xdc;
    }
    fVar1 = (*(float *)(*param_1 + 0xa4) + *(float *)(*param_1 + 0xb0)) * 0.5 -
            (*(float *)(iVar11 + 0xa4) + *(float *)(iVar11 + 0xb0)) * 0.5;
    fVar8 = (*(float *)(*param_1 + 0xa8) + *(float *)(*param_1 + 0xb4)) * 0.5 -
            (*(float *)(iVar11 + 0xa8) + *(float *)(iVar11 + 0xb4)) * 0.5;
    fVar9 = (*(float *)(*param_1 + 0xac) + *(float *)(*param_1 + 0xb8)) * 0.5 -
            (*(float *)(iVar11 + 0xac) + *(float *)(iVar11 + 0xb8)) * 0.5;
    fVar8 = SQRT(fVar9 * fVar9 + fVar8 * fVar8 + fVar1 * fVar1);
    fVar1 = *(float *)(iVar12 + 0x7a4);
    if ((byte)((fVar8 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar8) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar8 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      *(float *)(iVar12 + 0x7a4) = fVar8;
    }
  }
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.25;
  return;
}


