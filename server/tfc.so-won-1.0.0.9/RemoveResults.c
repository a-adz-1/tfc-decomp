// RemoveResults__FP11CBaseEntityP11CBasePlayer  @ 0010a640
void RemoveResults__FP11CBaseEntityP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  int *piVar10;
  
  iVar9 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
  if (iVar9 == 0) {
    if ((param_2[0xdd] & param_1[0xdd]) == 0) {
      return;
    }
    if ((*(byte *)((int)param_1 + 0x221) & 4) != 0) {
      return;
    }
    param_2[0xdd] = param_2[0xdd] & ~param_1[0xdd];
  }
  iVar9 = *param_1;
  fVar1 = *(float *)(iVar9 + 0x140);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    (**(code **)(param_2[0xf2] + 0x34))
              (param_2,iVar9,iVar9,*(undefined4 *)(iVar9 + 0x140),0x8000000);
  }
  if (*(float *)(*param_1 + 0x140) < 0.0) {
    (**(code **)(param_2[0xf2] + 0x38))(param_2,0.0 - *(float *)(*param_1 + 0x140),0);
  }
  param_2[0x49] = param_2[0x49] - param_1[0x49];
  *(float *)(*param_2 + 0x198) = *(float *)(*param_2 + 0x198) - *(float *)(*param_1 + 0x198);
  *(float *)(*param_2 + 0x19c) = *(float *)(*param_2 + 0x19c) - *(float *)(*param_1 + 0x19c);
  param_2[0xf] = param_2[0xf] & ~param_1[0xf];
  fVar1 = *(float *)(*param_1 + 0x144);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    TF_AddFrags__11CBasePlayeri(param_2,(int)ROUND(fVar1));
  }
  param_2[0x33] = param_2[0x33] - param_1[0x33];
  param_2[0x35] = param_2[0x35] - param_1[0x35];
  param_2[0x39] = param_2[0x39] - param_1[0x39];
  param_2[0x37] = param_2[0x37] - param_1[0x37];
  param_2[0x2f] = param_2[0x2f] - param_1[0x2f];
  iVar9 = param_2[0x31];
  iVar2 = param_1[0x31];
  param_2[0x31] = iVar9 - iVar2;
  if (param_2[0x32] < iVar9 - iVar2) {
    param_2[0x31] = param_2[0x32];
  }
  iVar9 = param_2[0x12];
  iVar2 = param_1[0x12];
  param_2[0x12] = iVar9 - iVar2;
  iVar3 = param_2[0x13];
  iVar4 = param_1[0x13];
  param_2[0x13] = iVar3 - iVar4;
  if (((*(byte *)(param_2 + 0x22) & 1) != 0) && ((iVar3 - iVar4 < 1 || (iVar9 - iVar2 < 1)))) {
    *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) & 0xfe;
    *(byte *)((int)param_2 + 0x89) = *(byte *)((int)param_2 + 0x89) & 0xfb;
    param_2[0x21] = 1;
  }
  bVar5 = false;
  bVar6 = false;
  bVar7 = false;
  bVar8 = false;
  piVar10 = (int *)0x0;
  while (piVar10 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar10,"item_tfgoal"),
        piVar10 != (int *)0x0) {
    if ((*(int *)(*piVar10 + 0x178) == *(int *)(*param_2 + 0x1e8)) && (piVar10 != param_1)) {
      if (0.0 < (float)piVar10[0xe8]) {
        bVar5 = true;
      }
      if (0.0 < (float)piVar10[0xe9]) {
        bVar6 = true;
      }
      if (0.0 < (float)piVar10[0xea]) {
        bVar7 = true;
      }
      if (0.0 < (float)piVar10[0xeb]) {
        bVar8 = true;
      }
    }
  }
  fVar1 = (float)param_1[0xe8];
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) && (!bVar5)) {
    *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) & 0xdf;
    *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 0x10;
    param_2[0xe8] = (int)(*gpGlobals + (float)param_1[0xe8]);
  }
  fVar1 = (float)param_1[0xe9];
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) && (!bVar6)) {
    *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) & 0xbf;
    *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 8;
    param_2[0xe9] = (int)(*gpGlobals + (float)param_1[0xe9]);
  }
  fVar1 = (float)param_1[0xea];
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) && (!bVar7)) {
    *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) & 0x7f;
    *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 0x40;
    param_2[0xea] = (int)(*gpGlobals + (float)param_1[0xea]);
  }
  fVar1 = (float)param_1[0xeb];
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) && (!bVar8)) {
    *(byte *)((int)param_2 + 0x89) = *(byte *)((int)param_2 + 0x89) & 0xfe;
    *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 0x20;
    param_2[0xeb] = (int)(*gpGlobals + (float)param_1[0xeb]);
  }
  TeamFortress_CheckClassStats__11CBasePlayer(param_2);
  return;
}


