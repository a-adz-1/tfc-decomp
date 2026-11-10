// SpawnInsideTrigger__12CPlatTriggerP9CFuncPlat  @ 000d15c0
void SpawnInsideTrigger__12CPlatTriggerP9CFuncPlat(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  param_1[0xf3] = (int)param_2;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  iVar1 = *param_1;
  iVar2 = *param_2;
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
  piVar3 = (int *)param_1[0xf3];
  local_10 = *(float *)(*piVar3 + 0xbc) + 25.0;
  local_c = *(float *)(*piVar3 + 0xc0) + 25.0;
  local_1c = *(float *)(*piVar3 + 200) + 25.0;
  local_18 = *(float *)(*piVar3 + 0xcc) + 25.0;
  local_14 = *(float *)(*piVar3 + 0xd0) + 8.0;
  local_8 = local_14 - (((float)piVar3[0x103] - (float)piVar3[0x106]) + 8.0);
  iVar1 = *piVar3;
  if (*(float *)(iVar1 + 0xd4) <= 50.0) {
    local_10 = (*(float *)(iVar1 + 0xbc) + *(float *)(iVar1 + 200)) * 0.5;
    local_1c = local_10 + 1.0;
  }
  iVar1 = *(int *)param_1[0xf3];
  if (*(float *)(iVar1 + 0xd8) <= 50.0) {
    local_c = (*(float *)(iVar1 + 0xc0) + *(float *)(iVar1 + 0xcc)) * 0.5;
    local_18 = local_c + 1.0;
  }
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_10,&local_1c);
  iVar1 = param_1[0xf3];
  param_1[0x48] = *(int *)(iVar1 + 0x120);
  param_1[0xb] = *(int *)(iVar1 + 0x2c);
  param_1[0x3a] = *(int *)(iVar1 + 0xe8);
  param_1[0x95] = *(int *)(iVar1 + 0x254);
  param_1[0x96] = *(int *)(iVar1 + 600);
  param_1[0x97] = *(int *)(iVar1 + 0x25c);
  param_1[0x98] = *(int *)(iVar1 + 0x260);
  param_1[0x99] = *(int *)(iVar1 + 0x264);
  param_1[0x9a] = *(int *)(iVar1 + 0x268);
  param_1[0x9b] = *(int *)(iVar1 + 0x26c);
  param_1[0x9c] = *(int *)(iVar1 + 0x270);
  param_1[0x88] = *(int *)(iVar1 + 0x220);
  param_1[0x89] = *(int *)(iVar1 + 0x224);
  param_1[0x8a] = *(int *)(iVar1 + 0x228);
  param_1[0x8b] = *(int *)(iVar1 + 0x22c);
  return;
}


