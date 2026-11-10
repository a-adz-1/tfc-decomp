// SetupRotation__12CFuncPlatRot  @ 000d1d30
void SetupRotation__12CFuncPlatRot(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  
  fVar6 = (float)param_1[0x116];
  if ((byte)(0.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x120] = g_vecZero;
    param_1[0x121] = DAT_00175484;
    param_1[0x122] = (int)DAT_00175488;
    param_1[0x11d] = g_vecZero;
    param_1[0x11e] = DAT_00175484;
    fVar6 = DAT_00175488;
  }
  else {
    AxisDir__11CBaseToggleP9entvars_t(*param_1);
    iVar5 = *param_1;
    param_1[0x120] = *(int *)(iVar5 + 0x50);
    param_1[0x121] = *(int *)(iVar5 + 0x54);
    param_1[0x122] = *(int *)(iVar5 + 0x58);
    fVar6 = (float)param_1[0x116];
    fVar1 = *(float *)(iVar5 + 0x48);
    fVar2 = *(float *)(iVar5 + 0x4c);
    fVar3 = *(float *)(iVar5 + 0x54);
    fVar4 = *(float *)(iVar5 + 0x58);
    param_1[0x11d] = (int)(*(float *)(iVar5 + 0x50) + fVar6 * *(float *)(iVar5 + 0x44));
    param_1[0x11e] = (int)(fVar3 + fVar6 * fVar1);
    fVar6 = fVar4 + fVar6 * fVar2;
  }
  param_1[0x11f] = (int)fVar6;
  iVar5 = *param_1;
  if (*(int *)(iVar5 + 0x1ac) != 0) {
    *(int *)(iVar5 + 0x50) = param_1[0x11d];
    *(int *)(iVar5 + 0x54) = param_1[0x11e];
    *(int *)(iVar5 + 0x58) = param_1[0x11f];
  }
  return;
}


