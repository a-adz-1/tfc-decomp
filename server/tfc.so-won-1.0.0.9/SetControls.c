// SetControls__15CFuncTrackTrainP9entvars_t  @ 000d3af0
void SetControls__15CFuncTrackTrainP9entvars_t(int *param_1,int param_2)

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
  fVar1 = *(float *)(param_2 + 0xc0);
  fVar2 = *(float *)(param_2 + 0xc4);
  param_1[0xf9] = (int)(*(float *)(param_2 + 0xbc) + fVar4);
  param_1[0xfa] = (int)(fVar1 + fVar5);
  param_1[0xfb] = (int)(fVar2 + fVar6);
  fVar1 = *(float *)(param_2 + 0xcc);
  fVar2 = *(float *)(param_2 + 0xd0);
  param_1[0xfc] = (int)(*(float *)(param_2 + 200) + fVar4);
  param_1[0xfd] = (int)(fVar1 + fVar5);
  param_1[0xfe] = (int)(fVar2 + fVar6);
  return;
}


