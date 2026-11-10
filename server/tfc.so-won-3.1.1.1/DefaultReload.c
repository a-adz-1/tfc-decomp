// DefaultReload__17CBasePlayerWeaponiif  @ 00125550
undefined4
DefaultReload__17CBasePlayerWeaponiif(int param_1,int param_2,undefined4 param_3,float param_4)

{
  byte *pbVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = *(int **)(param_1 + 0xb0);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)(*(int *)(param_1 + 0x474) + 0x8ec + *(int *)(param_1 + 0x4b8) * 4);
  }
  iVar5 = *piVar2;
  if (iVar5 < 1) {
    uVar3 = 0;
  }
  else {
    iVar4 = param_2 - *(int *)(param_1 + 0x4c0);
    if (iVar4 < iVar5) {
      iVar5 = iVar4;
    }
    if (iVar5 == 0) {
      uVar3 = 0;
    }
    else {
      *(float *)(*(int *)(param_1 + 0x474) + 0x658) = ((float)iVar5 / (float)param_2) * param_4;
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,param_3,0);
      *(undefined4 *)(param_1 + 0x4b0) = 1;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
      *pbVar1 = *pbVar1 | 2;
      uVar3 = 1;
      *(undefined4 *)(param_1 + 0x490) = 0x40400000;
    }
  }
  return uVar3;
}


