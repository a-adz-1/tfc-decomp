// BestVisibleEnemy__12CBaseMonster  @ 000be484
int * BestVisibleEnemy__12CBaseMonster(int *param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int local_2c;
  int local_28;
  int *local_24;
  
  local_28 = 0x2000;
  local_24 = (int *)0x0;
  local_2c = 0;
  for (piVar1 = (int *)param_1[2]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
    iVar6 = (**(code **)(piVar1[0x115] + 0x8c))(piVar1);
    if ((iVar6 != 0) &&
       (((*(byte *)(*piVar1 + 0x1a4) & 8) == 0 ||
        (iVar6 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,piVar1,0), iVar6 != 0)
        ))) {
      iVar6 = (**(code **)(param_1[0x115] + 0x120))(param_1,piVar1);
      if (local_2c < iVar6) {
        local_2c = (**(code **)(param_1[0x115] + 0x120))(param_1,piVar1);
        iVar6 = *piVar1;
        iVar2 = *param_1;
        fVar3 = *(float *)(iVar6 + 8) - *(float *)(iVar2 + 8);
        fVar5 = *(float *)(iVar6 + 0xc) - *(float *)(iVar2 + 0xc);
        fVar4 = *(float *)(iVar6 + 0x10) - *(float *)(iVar2 + 0x10);
        local_28 = (int)ROUND(SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3));
        local_24 = piVar1;
      }
      else {
        iVar6 = (**(code **)(param_1[0x115] + 0x120))(param_1,piVar1);
        if (iVar6 == local_2c) {
          iVar6 = *piVar1;
          iVar2 = *param_1;
          fVar3 = *(float *)(iVar6 + 8) - *(float *)(iVar2 + 8);
          fVar5 = *(float *)(iVar6 + 0xc) - *(float *)(iVar2 + 0xc);
          fVar4 = *(float *)(iVar6 + 0x10) - *(float *)(iVar2 + 0x10);
          iVar6 = (int)ROUND(SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3));
          if (iVar6 <= local_28) {
            local_2c = (**(code **)(param_1[0x115] + 0x120))(param_1,piVar1);
            local_28 = iVar6;
            local_24 = piVar1;
          }
        }
      }
    }
  }
  return local_24;
}


