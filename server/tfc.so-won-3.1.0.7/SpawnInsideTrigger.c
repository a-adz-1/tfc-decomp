// SpawnInsideTrigger__12CPlatTriggerP9CFuncPlat  @ 000cda2c
void SpawnInsideTrigger__12CPlatTriggerP9CFuncPlat(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  param_1[0x112] = (int)param_2;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  iVar2 = *param_1;
  iVar3 = *param_2;
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar3 + 8);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
  piVar4 = (int *)param_1[0x112];
  local_c = *(float *)(*piVar4 + 0xdc) + 25.0;
  local_8 = *(float *)(*piVar4 + 0xe0) + 25.0;
  local_18 = *(float *)(*piVar4 + 0xe8) + 25.0;
  local_14 = *(float *)(*piVar4 + 0xec) + 25.0;
  local_10 = *(float *)(*piVar4 + 0xf0) + 8.0;
  local_4 = local_10 - (((float)piVar4[0x122] - (float)piVar4[0x125]) + 8.0);
  iVar2 = *piVar4;
  fVar1 = *(float *)(iVar2 + 0xf4);
  if ((byte)(50.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 50.0) << 0xe) >> 8)) != 1) {
    local_c = (*(float *)(iVar2 + 0xdc) + *(float *)(iVar2 + 0xe8)) * 0.5;
    local_18 = local_c + 1.0;
  }
  iVar2 = *(int *)param_1[0x112];
  fVar1 = *(float *)(iVar2 + 0xf8);
  if ((byte)(50.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 50.0) << 0xe) >> 8)) != 1) {
    local_8 = (*(float *)(iVar2 + 0xe0) + *(float *)(iVar2 + 0xec)) * 0.5;
    local_14 = local_8 + 1.0;
  }
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_c,&local_18);
  param_1[0x48] = ((int *)param_1[0x112])[0x48];
  *(undefined4 *)(*param_1 + 0x20c) = *(undefined4 *)(*(int *)param_1[0x112] + 0x20c);
  iVar2 = param_1[0x112];
  param_1[0x3a] = *(int *)(iVar2 + 0xe8);
  param_1[0x97] = *(int *)(iVar2 + 0x25c);
  param_1[0x98] = *(int *)(iVar2 + 0x260);
  param_1[0x99] = *(int *)(iVar2 + 0x264);
  param_1[0x9a] = *(int *)(iVar2 + 0x268);
  param_1[0x9b] = *(int *)(iVar2 + 0x26c);
  param_1[0x9c] = *(int *)(iVar2 + 0x270);
  param_1[0x9d] = *(int *)(iVar2 + 0x274);
  param_1[0x9e] = *(int *)(iVar2 + 0x278);
  param_1[0x8a] = *(int *)(iVar2 + 0x228);
  param_1[0x8b] = *(int *)(iVar2 + 0x22c);
  param_1[0x8c] = *(int *)(iVar2 + 0x230);
  param_1[0x8d] = *(int *)(iVar2 + 0x234);
  return;
}


