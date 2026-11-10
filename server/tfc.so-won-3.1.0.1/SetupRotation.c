// SetupRotation__12CFuncPlatRot  @ 000c2ef8
void SetupRotation__12CFuncPlatRot(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  
  fVar6 = (float)param_1[0x119];
  if ((byte)(0.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x123] = g_vecZero;
    param_1[0x124] = DAT_001a7e04;
    param_1[0x125] = (int)DAT_001a7e08;
    param_1[0x120] = g_vecZero;
    param_1[0x121] = DAT_001a7e04;
    fVar6 = DAT_001a7e08;
  }
  else {
    AxisDir__11CBaseToggleP9entvars_s(*param_1);
    iVar5 = *param_1;
    param_1[0x123] = *(int *)(iVar5 + 0x50);
    param_1[0x124] = *(int *)(iVar5 + 0x54);
    param_1[0x125] = *(int *)(iVar5 + 0x58);
    fVar6 = (float)param_1[0x119];
    fVar1 = *(float *)(iVar5 + 0x48);
    fVar2 = *(float *)(iVar5 + 0x4c);
    fVar3 = *(float *)(iVar5 + 0x54);
    fVar4 = *(float *)(iVar5 + 0x58);
    param_1[0x120] = (int)(*(float *)(iVar5 + 0x50) + fVar6 * *(float *)(iVar5 + 0x44));
    param_1[0x121] = (int)(fVar3 + fVar6 * fVar1);
    fVar6 = fVar4 + fVar6 * fVar2;
  }
  param_1[0x122] = (int)fVar6;
  iVar5 = *param_1;
  if (*(int *)(iVar5 + 0x1cc) != 0) {
    *(int *)(iVar5 + 0x50) = param_1[0x120];
    *(int *)(iVar5 + 0x54) = param_1[0x121];
    *(int *)(iVar5 + 0x58) = param_1[0x122];
  }
  return;
}


