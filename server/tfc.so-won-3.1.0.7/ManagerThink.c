// ManagerThink__13CMultiManager  @ 00111558
void ManagerThink__13CMultiManager(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  
  fVar2 = *gpGlobals - (float)param_1[0x13c];
  iVar4 = param_1[0x13b];
  if (iVar4 < param_1[0x13a]) {
    do {
      fVar1 = (float)param_1[iVar4 + 0x14d];
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) break;
      uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x12e,param_1,3,0);
      FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                (param_1[param_1[0x13b] + 0x13d] + (int)gpGlobals[0x26],uVar3);
      param_1[0x13b] = param_1[0x13b] + 1;
      iVar4 = param_1[0x13b];
    } while (iVar4 < param_1[0x13a]);
    if (param_1[0x13b] < param_1[0x13a]) {
      *(float *)(*param_1 + 0x104) = (float)param_1[0x13c] + (float)param_1[param_1[0x13b] + 0x14d];
      return;
    }
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf;
  return;
}


