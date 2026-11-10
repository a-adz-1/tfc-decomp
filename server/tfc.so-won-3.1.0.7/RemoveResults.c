// RemoveResults__FP11CBaseEntityP11CBasePlayer  @ 0010a290
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
    if ((param_2[0xfc] & param_1[0xfc]) == 0) {
      return;
    }
    if ((*(byte *)((int)param_1 + 0x229) & 4) != 0) {
      return;
    }
    param_2[0xfc] = param_2[0xfc] & ~param_1[0xfc];
  }
  iVar9 = *param_1;
  if (0.0 < *(float *)(iVar9 + 0x160)) {
    (**(code **)(param_2[0x111] + 0x38))
              (param_2,iVar9,iVar9,*(undefined4 *)(iVar9 + 0x160),0x8000000);
  }
  fVar1 = *(float *)(*param_1 + 0x160);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    (**(code **)(param_2[0x111] + 0x3c))(param_2,-*(float *)(*param_1 + 0x160),0);
  }
  param_2[0x49] = param_2[0x49] - param_1[0x49];
  *(float *)(*param_2 + 0x1b8) = *(float *)(*param_2 + 0x1b8) - *(float *)(*param_1 + 0x1b8);
  *(float *)(*param_2 + 0x1bc) = *(float *)(*param_2 + 0x1bc) - *(float *)(*param_1 + 0x1bc);
  param_2[0xe] = param_2[0xe] & ~param_1[0xe];
  fVar1 = *(float *)(*param_1 + 0x164);
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
  iVar9 = param_2[0x11];
  iVar2 = param_1[0x11];
  param_2[0x11] = iVar9 - iVar2;
  iVar3 = param_2[0x12];
  iVar4 = param_1[0x12];
  param_2[0x12] = iVar3 - iVar4;
  if (((*(byte *)(param_2 + 0x21) & 1) != 0) && ((iVar3 - iVar4 < 1 || (iVar9 - iVar2 < 1)))) {
    *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xfe;
    *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) & 0xfb;
    param_2[0x20] = 1;
  }
  bVar5 = false;
  bVar6 = false;
  bVar7 = false;
  bVar8 = false;
  piVar10 = (int *)0x0;
  while (piVar10 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar10,"item_tfgoal"),
        piVar10 != (int *)0x0) {
    if ((*(int *)(*piVar10 + 0x198) == *(int *)(*param_2 + 0x208)) && (piVar10 != param_1)) {
      fVar1 = (float)piVar10[0x107];
      if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        bVar5 = true;
      }
      fVar1 = (float)piVar10[0x108];
      if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        bVar6 = true;
      }
      fVar1 = (float)piVar10[0x109];
      if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        bVar7 = true;
      }
      fVar1 = (float)piVar10[0x10a];
      if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        bVar8 = true;
      }
    }
  }
  if ((0.0 < (float)param_1[0x107]) && (!bVar5)) {
    *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xdf;
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x10;
    param_2[0x107] = (int)(*gpGlobals + (float)param_1[0x107]);
  }
  if ((0.0 < (float)param_1[0x108]) && (!bVar6)) {
    *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xbf;
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 8;
    param_2[0x108] = (int)(*gpGlobals + (float)param_1[0x108]);
  }
  if ((0.0 < (float)param_1[0x109]) && (!bVar7)) {
    *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0x7f;
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x40;
    param_2[0x109] = (int)(*gpGlobals + (float)param_1[0x109]);
  }
  if ((0.0 < (float)param_1[0x10a]) && (!bVar8)) {
    *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) & 0xfe;
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x20;
    param_2[0x10a] = (int)(*gpGlobals + (float)param_1[0x10a]);
  }
  TeamFortress_CheckClassStats__11CBasePlayer(param_2);
  return;
}


