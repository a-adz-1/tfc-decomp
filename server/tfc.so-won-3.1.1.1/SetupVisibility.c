// SetupVisibility__FP7edict_sT0PPUcT2  @ 0009280c
void SetupVisibility__FP7edict_sT0PPUcT2
               (int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  
  iVar4 = param_2;
  if (param_1 != 0) {
    iVar4 = param_1;
  }
  if ((*(byte *)(param_2 + 0x226) & 0x10) == 0) {
    if ((param_2 == 0) && (param_2 = (*DAT_0019f7b4)(0), param_2 == 0)) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)(param_2 + 0x7c);
    }
    if (*(int *)(*piVar2 + 0x248) != 0) {
      iVar1 = __opP11CBaseEntity__7EHANDLE(piVar2 + 0x1a7);
      if (iVar1 != 0) {
        piVar2 = (int *)__rf__7EHANDLE(piVar2 + 0x1a7);
        iVar4 = *(int *)(*piVar2 + 0x208);
      }
    }
    local_10 = *(float *)(iVar4 + 0x88) + *(float *)(iVar4 + 500);
    local_c = *(float *)(iVar4 + 0x8c) + *(float *)(iVar4 + 0x1f8);
    local_8 = *(float *)(iVar4 + 0x90) + *(float *)(iVar4 + 0x1fc);
    if ((*(byte *)(iVar4 + 0x225) & 0x40) != 0) {
      local_8 = local_8 + -18.0;
    }
    uVar3 = (*DAT_0019f890)(&local_10);
    *param_3 = uVar3;
    uVar3 = (*DAT_0019f894)(&local_10);
    *param_4 = uVar3;
    return;
  }
  *param_3 = 0;
  *param_4 = 0;
  return;
}


