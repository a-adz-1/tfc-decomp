// ManagerThink__13CMultiManager  @ 0010fa50
void ManagerThink__13CMultiManager(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x11d];
  iVar4 = param_1[0x11c];
  if (iVar4 < param_1[0x11b]) {
    do {
      if (fVar1 - fVar2 < (float)param_1[iVar4 + 0x12e]) break;
      uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,param_1,3,0);
      FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                (param_1[param_1[0x11c] + 0x11e] + (int)gpGlobals[0x26],uVar3);
      param_1[0x11c] = param_1[0x11c] + 1;
      iVar4 = param_1[0x11c];
    } while (iVar4 < param_1[0x11b]);
    if (param_1[0x11c] < param_1[0x11b]) {
      *(float *)(*param_1 + 0xe4) = (float)param_1[0x11d] + (float)param_1[param_1[0x11c] + 0x12e];
      return;
    }
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf;
  return;
}


