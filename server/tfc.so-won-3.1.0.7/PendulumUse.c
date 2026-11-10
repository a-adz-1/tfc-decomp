// PendulumUse__9CPendulumP11CBaseEntityT18USE_TYPEf  @ 00089e58
void PendulumUse__9CPendulumP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x1f8);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
    param_1[0x114] = *gpGlobals;
    param_1[3] = -0x10000;
    param_1[4] = (int)Swing__9CPendulum;
    param_1[0x117] = param_1[0x116];
  }
  else if ((*(byte *)(iVar2 + 0x1a0) & 0x10) == 0) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x60) = DAT_001c0fe4;
    *(undefined4 *)(iVar2 + 100) = DAT_001c0fe8;
  }
  else {
    lVar3 = (longdouble)
            AxisDelta__11CBaseToggleiRC6VectorT2
                      (*(undefined4 *)(iVar2 + 0x1a0),iVar2 + 0x50,param_1 + 0x11b);
    iVar2 = *param_1;
    fVar1 = (float)param_1[0x116];
    *(float *)(iVar2 + 0x5c) = fVar1 * *(float *)(iVar2 + 0x44);
    *(float *)(iVar2 + 0x60) = fVar1 * *(float *)(iVar2 + 0x48);
    *(float *)(iVar2 + 100) = fVar1 * *(float *)(iVar2 + 0x4c);
    *(float *)(*param_1 + 0x104) =
         (float)(lVar3 / (longdouble)(float)param_1[0x116] +
                (longdouble)*(float *)(*param_1 + 0x100));
    param_1[3] = -0x10000;
    param_1[4] = (int)Stop__9CPendulum;
  }
  return;
}


