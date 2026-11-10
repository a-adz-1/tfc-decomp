// ManagerThink__13CMultiManager  @ 0011452c
void ManagerThink__13CMultiManager(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  fVar2 = *gpGlobals - (float)param_1[0x140];
  iVar4 = param_1[0x13f];
  iVar5 = param_1[0x13e];
  if (iVar4 < iVar5) {
    do {
      fVar1 = (float)param_1[iVar4 + 0x151];
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) break;
      uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x132,param_1,3,0);
      FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                (param_1[param_1[0x13f] + 0x141] + (int)gpGlobals[0x26],uVar3);
      iVar4 = param_1[0x13f];
      param_1[0x13f] = iVar4 + 1;
      iVar4 = iVar4 + 1;
      iVar5 = param_1[0x13e];
    } while (iVar4 < iVar5);
    if (param_1[0x13f] < iVar5) {
      *(float *)(*param_1 + 0x104) = (float)param_1[0x140] + (float)param_1[param_1[0x13f] + 0x151];
      return;
    }
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf;
  return;
}


