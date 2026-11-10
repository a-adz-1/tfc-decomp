// SetupRotation__12CFuncPlatRot  @ 000cdb04
void SetupRotation__12CFuncPlatRot(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  
  fVar6 = (float)param_1[0x139];
  if ((byte)(fVar6 < 0.0 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x143] = g_vecZero;
    param_1[0x144] = DAT_0019f664;
    param_1[0x145] = (int)DAT_0019f668;
    param_1[0x140] = g_vecZero;
    param_1[0x141] = DAT_0019f664;
    fVar6 = DAT_0019f668;
  }
  else {
    AxisDir__11CBaseToggleP9entvars_s(*param_1);
    iVar5 = *param_1;
    fVar6 = (float)param_1[0x139];
    param_1[0x143] = *(int *)(iVar5 + 0x50);
    param_1[0x144] = *(int *)(iVar5 + 0x54);
    param_1[0x145] = *(int *)(iVar5 + 0x58);
    fVar1 = *(float *)(iVar5 + 0x48);
    fVar2 = *(float *)(iVar5 + 0x4c);
    fVar3 = *(float *)(iVar5 + 0x54);
    fVar4 = *(float *)(iVar5 + 0x58);
    param_1[0x140] = (int)(*(float *)(iVar5 + 0x44) * fVar6 + *(float *)(iVar5 + 0x50));
    param_1[0x141] = (int)(fVar1 * fVar6 + fVar3);
    fVar6 = fVar6 * fVar2 + fVar4;
  }
  param_1[0x142] = (int)fVar6;
  iVar5 = *param_1;
  if (*(int *)(iVar5 + 0x1cc) != 0) {
    *(int *)(iVar5 + 0x50) = param_1[0x140];
    *(int *)(iVar5 + 0x54) = param_1[0x141];
    *(int *)(iVar5 + 0x58) = param_1[0x142];
  }
  return;
}


