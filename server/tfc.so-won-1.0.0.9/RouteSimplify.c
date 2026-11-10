// RouteSimplify__12CBaseMonsterP11CBaseEntity  @ 000c1d10
/* WARNING: Type propagation algorithm not settling */

void RouteSimplify__12CBaseMonsterP11CBaseEntity(int *param_1,undefined4 param_2)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  bool bVar6;
  int local_154;
  int local_144;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float afStack_110 [64];
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = 0xf;
  do {
    bVar6 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar6);
  local_144 = 0;
  iVar3 = param_1[0x160];
  while (((iVar3 < 8 && (param_1[iVar3 * 4 + 0x142] != 0)) &&
         (local_144 = local_144 + 1, -1 < (char)param_1[iVar3 * 4 + 0x142]))) {
    iVar3 = iVar3 + 1;
  }
  if (1 < local_144) {
    local_154 = 0;
    iVar3 = *param_1;
    local_10 = *(float *)(iVar3 + 8);
    local_c = *(float *)(iVar3 + 0xc);
    local_8 = *(float *)(iVar3 + 0x10);
    iVar3 = 0;
    if (0 < local_144 + -1) {
      do {
        iVar4 = ShouldSimplify__Fi(param_1[(iVar3 + param_1[0x160]) * 4 + 0x142]);
        if (iVar4 == 0) {
          iVar4 = iVar3 + param_1[0x160];
          afStack_110[local_154 * 4] = (float)param_1[iVar4 * 4 + 0x13f];
          afStack_110[local_154 * 4 + 1] = (float)param_1[iVar4 * 4 + 0x140];
          afStack_110[local_154 * 4 + 2] = (float)param_1[iVar4 * 4 + 0x141];
          afStack_110[local_154 * 4 + 3] = (float)param_1[iVar4 * 4 + 0x142];
          local_154 = local_154 + 1;
LAB_000c212b:
          local_10 = afStack_110[local_154 * 4];
          local_c = afStack_110[local_154 * 4 + 1];
          local_8 = afStack_110[local_154 * 4 + 2];
          local_154 = local_154 + 1;
        }
        else {
          iVar4 = (**(code **)(param_1[0xf2] + 0x138))
                            (param_1,&local_10,param_1 + (iVar3 + param_1[0x160]) * 4 + 0x143,
                             param_2,0);
          if (iVar4 != 2) {
            iVar4 = iVar3 + param_1[0x160];
            pfVar1 = (float *)(param_1 + iVar4 * 4 + 0x143);
            pfVar2 = (float *)(param_1 + iVar4 * 4 + 0x13f);
            local_11c = (*pfVar1 + *pfVar2) * 0.5;
            local_118 = (pfVar1[1] + pfVar2[1]) * 0.5;
            local_114 = (pfVar1[2] + pfVar2[2]) * 0.5;
            pfVar1 = (float *)(param_1 + iVar4 * 4 + 0x13f);
            local_128 = (*pfVar1 + local_10) * 0.5;
            local_124 = (pfVar1[1] + local_c) * 0.5;
            local_120 = (pfVar1[2] + local_8) * 0.5;
            fVar5 = (float)(param_1[iVar4 * 4 + 0x142] & 0xfffffe7fU | 8);
            iVar4 = (**(code **)(param_1[0xf2] + 0x138))(param_1,&local_10,&local_11c,param_2,0);
            if (iVar4 == 2) {
              afStack_110[local_154 * 4 + 3] = fVar5;
              afStack_110[local_154 * 4] = local_11c;
              afStack_110[local_154 * 4 + 1] = local_118;
              afStack_110[local_154 * 4 + 2] = local_114;
            }
            else {
              iVar4 = (**(code **)(param_1[0xf2] + 0x138))(param_1,&local_128,&local_11c,param_2,0);
              if (iVar4 == 2) {
                afStack_110[local_154 * 4 + 3] = fVar5;
                afStack_110[local_154 * 4] = local_128;
                afStack_110[local_154 * 4 + 1] = local_124;
                afStack_110[local_154 * 4 + 2] = local_120;
                afStack_110[(local_154 + 1) * 4 + 3] = fVar5;
                afStack_110[local_154 * 4U + 4] = local_11c;
                afStack_110[local_154 * 4 + 5] = local_118;
                afStack_110[local_154 * 4 + 6] = local_114;
                local_154 = local_154 + 1;
              }
              else {
                iVar4 = iVar3 + param_1[0x160];
                afStack_110[local_154 * 4] = (float)param_1[iVar4 * 4 + 0x13f];
                afStack_110[local_154 * 4 + 1] = (float)param_1[iVar4 * 4 + 0x140];
                afStack_110[local_154 * 4 + 2] = (float)param_1[iVar4 * 4 + 0x141];
                afStack_110[local_154 * 4 + 3] = (float)param_1[iVar4 * 4 + 0x142];
              }
            }
            goto LAB_000c212b;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_144 + -1);
    }
    iVar3 = iVar3 + param_1[0x160];
    afStack_110[local_154 * 4] = (float)param_1[iVar3 * 4 + 0x13f];
    afStack_110[local_154 * 4 + 1] = (float)param_1[iVar3 * 4 + 0x140];
    afStack_110[local_154 * 4 + 2] = (float)param_1[iVar3 * 4 + 0x141];
    afStack_110[local_154 * 4 + 3] = (float)param_1[iVar3 * 4 + 0x142];
    afStack_110[(local_154 + 1) * 4 + 3] = 0.0;
    param_1[0x160] = 0;
    iVar3 = 0;
    do {
      if (local_154 + 1 <= iVar3) break;
      param_1[iVar3 * 4 + 0x13f] = (int)afStack_110[iVar3 * 4];
      param_1[iVar3 * 4 + 0x140] = (int)afStack_110[iVar3 * 4 + 1];
      param_1[iVar3 * 4 + 0x141] = (int)afStack_110[iVar3 * 4 + 2];
      param_1[iVar3 * 4 + 0x142] = (int)afStack_110[iVar3 * 4 + 3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    if (iVar3 < 8) {
      param_1[iVar3 * 4 + 0x142] = 0;
    }
  }
  return;
}


