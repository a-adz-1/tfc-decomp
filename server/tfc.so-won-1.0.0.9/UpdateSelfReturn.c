// UpdateSelfReturn__19CMomentaryRotButtonf  @ 0009fac0
void UpdateSelfReturn__19CMomentaryRotButtonf(int *param_1,float param_2)

{
  int iVar1;
  float fVar2;
  
  if (0.0 < param_2) {
    iVar1 = *param_1;
    fVar2 = -(float)param_1[0x11d];
    *(float *)(iVar1 + 0x5c) = fVar2 * *(float *)(iVar1 + 0x44);
    *(float *)(iVar1 + 0x60) = fVar2 * *(float *)(iVar1 + 0x48);
    *(float *)(iVar1 + 100) = fVar2 * *(float *)(iVar1 + 0x4c);
    *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 0.1;
  }
  else {
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
    *(undefined4 *)(iVar1 + 100) = DAT_00175488;
    iVar1 = *param_1;
    *(int *)(iVar1 + 0x50) = param_1[0x11e];
    *(int *)(iVar1 + 0x54) = param_1[0x11f];
    *(int *)(iVar1 + 0x58) = param_1[0x120];
    *(undefined4 *)(*param_1 + 0xe4) = 0xbf800000;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  return;
}


