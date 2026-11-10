// SetupVisibility__FP7edict_sT0PPUcT2  @ 0008a944
void SetupVisibility__FP7edict_sT0PPUcT2
               (int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = param_2;
  if (param_1 != 0) {
    iVar4 = param_1;
  }
  if (param_2 == 0) {
    param_2 = (*DAT_001a7f54)(0);
    if (param_2 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_0008a98a;
    }
  }
  piVar2 = *(int **)(param_2 + 0x7c);
LAB_0008a98a:
  if (*(int *)(*piVar2 + 0x248) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar2 + 0x33f);
    if (iVar1 != 0) {
      piVar2 = (int *)__rf__7EHANDLE(piVar2 + 0x33f);
      iVar4 = *(int *)(*piVar2 + 0x208);
    }
  }
  local_c = *(float *)(iVar4 + 0x88) + *(float *)(iVar4 + 500);
  local_8 = *(float *)(iVar4 + 0x8c) + *(float *)(iVar4 + 0x1f8);
  local_4 = *(float *)(iVar4 + 0x90) + *(float *)(iVar4 + 0x1fc);
  if ((*(byte *)(iVar4 + 0x225) & 0x40) != 0) {
    local_4 = local_4 + -18.0;
  }
  uVar3 = (*DAT_001a8030)(&local_c);
  *param_3 = uVar3;
  uVar3 = (*DAT_001a8034)(&local_c);
  *param_4 = uVar3;
  return;
}


