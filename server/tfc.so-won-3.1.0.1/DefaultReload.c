// DefaultReload__17CBasePlayerWeaponiif  @ 00110e94
undefined4
DefaultReload__17CBasePlayerWeaponiif(int param_1,int param_2,undefined4 param_3,float param_4)

{
  byte *pbVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0xb0) == 0) {
    piVar2 = (int *)(*(int *)(param_1 + 0x3f4) + 0x850 + *(int *)(param_1 + 0x438) * 4);
  }
  else {
    piVar2 = *(int **)(param_1 + 0xb0);
  }
  if (*piVar2 < 1) {
    uVar3 = 0;
  }
  else {
    iVar5 = param_2 - *(int *)(param_1 + 0x440);
    iVar4 = *piVar2;
    if (iVar5 < *piVar2) {
      iVar4 = iVar5;
    }
    if (iVar4 == 0) {
      uVar3 = 0;
    }
    else {
      *(float *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = ((float)iVar4 / (float)param_2) * param_4;
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,param_3,0);
      *(undefined4 *)(param_1 + 0x430) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      *(undefined4 *)(param_1 + 0x410) = 0x40400000;
      uVar3 = 1;
    }
  }
  return uVar3;
}


