// DefaultReload__17CBasePlayerWeaponiif  @ 0011bb10
undefined4
DefaultReload__17CBasePlayerWeaponiif(int param_1,int param_2,undefined4 param_3,float param_4)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0xb0) == 0) {
    piVar2 = (int *)(*(int *)(param_1 + 1000) + 0x83c + *(int *)(param_1 + 0x408) * 4);
  }
  else {
    piVar2 = *(int **)(param_1 + 0xb0);
  }
  if (0 < *piVar2) {
    iVar4 = param_2 - *(int *)(param_1 + 0x410);
    iVar3 = *piVar2;
    if (iVar4 < *piVar2) {
      iVar3 = iVar4;
    }
    if (iVar3 != 0) {
      *(float *)(*(int *)(param_1 + 1000) + 0x5cc) =
           ((float)iVar3 / (float)param_2) * param_4 + *gpGlobals;
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,param_3);
      *(undefined4 *)(param_1 + 0x41c) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
      *pbVar1 = *pbVar1 | 2;
      *(float *)(param_1 + 0x404) = *gpGlobals + 3.0;
      return 1;
    }
  }
  return 0;
}


