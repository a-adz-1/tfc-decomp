// SetupRotation__12CFuncPlatRot  @ 000ce258
void SetupRotation__12CFuncPlatRot(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  
  fVar6 = (float)param_1[0x135];
  if ((byte)(0.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x13f] = g_vecZero;
    param_1[0x140] = DAT_001c0fe4;
    param_1[0x141] = (int)DAT_001c0fe8;
    param_1[0x13c] = g_vecZero;
    param_1[0x13d] = DAT_001c0fe4;
    fVar6 = DAT_001c0fe8;
  }
  else {
    AxisDir__11CBaseToggleP9entvars_s(*param_1);
    iVar5 = *param_1;
    param_1[0x13f] = *(int *)(iVar5 + 0x50);
    param_1[0x140] = *(int *)(iVar5 + 0x54);
    param_1[0x141] = *(int *)(iVar5 + 0x58);
    fVar6 = (float)param_1[0x135];
    fVar1 = *(float *)(iVar5 + 0x48);
    fVar2 = *(float *)(iVar5 + 0x4c);
    fVar3 = *(float *)(iVar5 + 0x54);
    fVar4 = *(float *)(iVar5 + 0x58);
    param_1[0x13c] = (int)(*(float *)(iVar5 + 0x50) + fVar6 * *(float *)(iVar5 + 0x44));
    param_1[0x13d] = (int)(fVar3 + fVar6 * fVar1);
    fVar6 = fVar4 + fVar6 * fVar2;
  }
  param_1[0x13e] = (int)fVar6;
  iVar5 = *param_1;
  if (*(int *)(iVar5 + 0x1cc) != 0) {
    *(int *)(iVar5 + 0x50) = param_1[0x13c];
    *(int *)(iVar5 + 0x54) = param_1[0x13d];
    *(int *)(iVar5 + 0x58) = param_1[0x13e];
  }
  return;
}


