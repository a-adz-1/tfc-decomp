// SetControls__15CFuncTrackTrainP9entvars_s  @ 000d0474
void SetControls__15CFuncTrackTrainP9entvars_s(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar3 = *param_1;
  fVar4 = *(float *)(param_2 + 8) - *(float *)(iVar3 + 0x14);
  fVar5 = *(float *)(param_2 + 0xc) - *(float *)(iVar3 + 0x18);
  fVar6 = *(float *)(param_2 + 0x10) - *(float *)(iVar3 + 0x1c);
  fVar1 = *(float *)(param_2 + 0xe0);
  fVar2 = *(float *)(param_2 + 0xe4);
  param_1[0x118] = (int)(*(float *)(param_2 + 0xdc) + fVar4);
  param_1[0x119] = (int)(fVar1 + fVar5);
  param_1[0x11a] = (int)(fVar2 + fVar6);
  fVar1 = *(float *)(param_2 + 0xec);
  fVar2 = *(float *)(param_2 + 0xf0);
  param_1[0x11b] = (int)(*(float *)(param_2 + 0xe8) + fVar4);
  param_1[0x11c] = (int)(fVar1 + fVar5);
  param_1[0x11d] = (int)(fVar2 + fVar6);
  return;
}


