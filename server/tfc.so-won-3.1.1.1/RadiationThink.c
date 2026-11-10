// RadiationThink__12CTriggerHurt  @ 00114d08
void RadiationThink__12CTriggerHurt(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar12 = *param_1;
  uVar1 = *(undefined4 *)(iVar12 + 8);
  uVar2 = *(undefined4 *)(iVar12 + 0xc);
  uVar3 = *(undefined4 *)(iVar12 + 0x10);
  uVar4 = *(undefined4 *)(iVar12 + 0x174);
  uVar5 = *(undefined4 *)(iVar12 + 0x178);
  uVar6 = *(undefined4 *)(iVar12 + 0x17c);
  *(float *)(iVar12 + 8) = (*(float *)(iVar12 + 0xc4) + *(float *)(iVar12 + 0xd0)) * 0.5;
  *(float *)(iVar12 + 0xc) = (*(float *)(iVar12 + 200) + *(float *)(iVar12 + 0xd4)) * 0.5;
  *(float *)(iVar12 + 0x10) = (*(float *)(iVar12 + 0xcc) + *(float *)(iVar12 + 0xd8)) * 0.5;
  iVar12 = *param_1;
  *(undefined4 *)(iVar12 + 0x174) = 0;
  *(undefined4 *)(iVar12 + 0x178) = 0;
  *(undefined4 *)(iVar12 + 0x17c) = 0;
  iVar11 = (*DAT_0019f6e4)(*(undefined4 *)(*param_1 + 0x208));
  iVar12 = *param_1;
  *(undefined4 *)(iVar12 + 8) = uVar1;
  *(undefined4 *)(iVar12 + 0xc) = uVar2;
  *(undefined4 *)(iVar12 + 0x10) = uVar3;
  bVar10 = false;
  iVar12 = *param_1;
  *(undefined4 *)(iVar12 + 0x174) = uVar4;
  *(undefined4 *)(iVar12 + 0x178) = uVar5;
  *(undefined4 *)(iVar12 + 0x17c) = uVar6;
  if ((iVar11 == 0) || (iVar12 = (*DAT_0019f7b8)(iVar11), iVar12 == 0)) {
    bVar10 = true;
  }
  if (!bVar10) {
    iVar12 = iVar11 + 0x80;
    iVar13 = iVar12;
    if (iVar11 == 0) {
      iVar13 = 0;
    }
    iVar13 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(iVar13);
    if (iVar11 == 0) {
      iVar12 = 0;
    }
    iVar11 = *param_1;
    fVar7 = (*(float *)(iVar11 + 0xc4) + *(float *)(iVar11 + 0xd0)) * 0.5 -
            (*(float *)(iVar12 + 0xc4) + *(float *)(iVar12 + 0xd0)) * 0.5;
    fVar8 = (*(float *)(iVar11 + 200) + *(float *)(iVar11 + 0xd4)) * 0.5 -
            (*(float *)(iVar12 + 200) + *(float *)(iVar12 + 0xd4)) * 0.5;
    fVar9 = (*(float *)(iVar11 + 0xcc) + *(float *)(iVar11 + 0xd8)) * 0.5 -
            (*(float *)(iVar12 + 0xcc) + *(float *)(iVar12 + 0xd8)) * 0.5;
    fVar7 = SQRT(fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7);
    if (fVar7 <= *(float *)(iVar13 + 0x850)) {
      *(float *)(iVar13 + 0x850) = fVar7;
    }
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.25;
  return;
}


