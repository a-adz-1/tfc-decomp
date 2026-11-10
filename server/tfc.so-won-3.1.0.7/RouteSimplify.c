// RouteSimplify__12CBaseMonsterP11CBaseEntity  @ 000baaa4
void RouteSimplify__12CBaseMonsterP11CBaseEntity(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float *local_15c;
  float *local_158;
  float *local_154;
  uint *local_150;
  uint *local_14c;
  int local_144;
  int local_140;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c [3];
  uint local_100;
  float local_fc [60];
  float local_c;
  float local_8;
  float local_4;
  
  local_140 = 0;
  iVar7 = param_1[0x17f];
  iVar3 = local_140;
  if (7 < iVar7) goto LAB_000bab8e;
  piVar2 = param_1 + iVar7 * 4 + 0x161;
  uVar1 = 8U - iVar7 & 3;
  if (iVar7 < 8) {
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          if ((*piVar2 == 0) || (local_140 = 1, iVar3 = local_140, (char)*piVar2 < '\0'))
          goto LAB_000bab8e;
          piVar2 = piVar2 + 4;
          iVar7 = iVar7 + 1;
        }
        iVar3 = local_140;
        if ((*piVar2 == 0) || (local_140 = local_140 + 1, iVar3 = local_140, (char)*piVar2 < '\0'))
        goto LAB_000bab8e;
        piVar2 = piVar2 + 4;
        iVar7 = iVar7 + 1;
      }
      goto LAB_000bab2a;
    }
  }
  else {
LAB_000bab2a:
    iVar3 = local_140;
    if ((*piVar2 == 0) || (local_140 = local_140 + 1, iVar3 = local_140, (char)*piVar2 < '\0'))
    goto LAB_000bab8e;
    piVar2 = piVar2 + 4;
    iVar7 = iVar7 + 1;
    if (7 < iVar7) goto LAB_000bab8e;
  }
  do {
    iVar3 = local_140;
    if (((((*piVar2 == 0) || (iVar3 = local_140 + 1, (char)*piVar2 < '\0')) || (piVar2[4] == 0)) ||
        ((iVar3 = local_140 + 2, (char)piVar2[4] < '\0' || (piVar2[8] == 0)))) ||
       ((iVar3 = local_140 + 3, (char)piVar2[8] < '\0' ||
        ((piVar2[0xc] == 0 ||
         (local_140 = local_140 + 4, iVar3 = local_140, (char)piVar2[0xc] < '\0')))))) break;
    piVar2 = piVar2 + 0x10;
    iVar7 = iVar7 + 4;
  } while (iVar7 < 8);
LAB_000bab8e:
  local_140 = iVar3;
  if (1 < local_140) {
    local_144 = 0;
    iVar7 = *param_1;
    local_c = *(float *)(iVar7 + 8);
    local_8 = *(float *)(iVar7 + 0xc);
    local_4 = *(float *)(iVar7 + 0x10);
    iVar7 = 0;
    if (0 < local_140 + -1) {
      do {
        iVar3 = ShouldSimplify__Fi(param_1[(iVar7 + param_1[0x17f]) * 4 + 0x161]);
        if (iVar3 == 0) {
          iVar3 = iVar7 + param_1[0x17f];
          local_10c[local_144 * 4] = (float)param_1[iVar3 * 4 + 0x15e];
          local_10c[local_144 * 4 + 1] = (float)param_1[iVar3 * 4 + 0x15f];
          local_10c[local_144 * 4 + 2] = (float)param_1[iVar3 * 4 + 0x160];
          (&local_100)[local_144 * 4] = param_1[iVar3 * 4 + 0x161];
          local_144 = local_144 + 1;
LAB_000baf22:
          local_c = local_10c[local_144 * 4];
          local_8 = local_10c[local_144 * 4 + 1];
          local_4 = local_10c[local_144 * 4 + 2];
          local_144 = local_144 + 1;
        }
        else {
          iVar3 = (**(code **)(param_1[0x111] + 0x140))
                            (param_1,&local_c,param_1 + (iVar7 + param_1[0x17f]) * 4 + 0x162,param_2
                             ,0);
          if (iVar3 != 2) {
            iVar3 = iVar7 + param_1[0x17f];
            pfVar4 = (float *)(param_1 + iVar3 * 4 + 0x162);
            pfVar5 = (float *)(param_1 + iVar3 * 4 + 0x15e);
            local_118 = (*pfVar4 + *pfVar5) * 0.5;
            local_114 = (pfVar4[1] + pfVar5[1]) * 0.5;
            local_110 = (pfVar4[2] + pfVar5[2]) * 0.5;
            pfVar4 = (float *)(param_1 + iVar3 * 4 + 0x15e);
            local_124 = (*pfVar4 + local_c) * 0.5;
            local_120 = (pfVar4[1] + local_8) * 0.5;
            local_11c = (pfVar4[2] + local_4) * 0.5;
            uVar1 = param_1[iVar3 * 4 + 0x161] & 0xfffffe7fU | 8;
            iVar3 = (**(code **)(param_1[0x111] + 0x140))(param_1,&local_c,&local_118,param_2,0);
            if (iVar3 == 2) {
              (&local_100)[local_144 * 4] = uVar1;
              local_10c[local_144 * 4] = local_118;
              local_10c[local_144 * 4 + 1] = local_114;
              local_10c[local_144 * 4 + 2] = local_110;
            }
            else {
              iVar3 = (**(code **)(param_1[0x111] + 0x140))(param_1,&local_124,&local_118,param_2,0)
              ;
              if (iVar3 == 2) {
                (&local_100)[local_144 * 4] = uVar1;
                local_10c[local_144 * 4] = local_124;
                local_10c[local_144 * 4 + 1] = local_120;
                local_10c[local_144 * 4 + 2] = local_11c;
                (&local_100)[(local_144 + 1) * 4] = uVar1;
                local_fc[local_144 * 4] = local_118;
                local_fc[local_144 * 4 + 1] = local_114;
                local_fc[local_144 * 4 + 2] = local_110;
                local_144 = local_144 + 1;
              }
              else {
                iVar3 = iVar7 + param_1[0x17f];
                local_10c[local_144 * 4] = (float)param_1[iVar3 * 4 + 0x15e];
                local_10c[local_144 * 4 + 1] = (float)param_1[iVar3 * 4 + 0x15f];
                local_10c[local_144 * 4 + 2] = (float)param_1[iVar3 * 4 + 0x160];
                (&local_100)[local_144 * 4] = param_1[iVar3 * 4 + 0x161];
              }
            }
            goto LAB_000baf22;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < local_140 + -1);
    }
    iVar7 = iVar7 + param_1[0x17f];
    local_10c[local_144 * 4] = (float)param_1[iVar7 * 4 + 0x15e];
    local_10c[local_144 * 4 + 1] = (float)param_1[iVar7 * 4 + 0x15f];
    local_10c[local_144 * 4 + 2] = (float)param_1[iVar7 * 4 + 0x160];
    (&local_100)[local_144 * 4] = param_1[iVar7 * 4 + 0x161];
    local_144 = local_144 + 1;
    local_150 = &local_100;
    local_150[local_144 * 4] = 0;
    param_1[0x17f] = 0;
    iVar7 = 0;
    local_14c = (uint *)(param_1 + 0x161);
    local_154 = (float *)(param_1 + 0x160);
    local_158 = local_10c + 2;
    pfVar6 = (float *)(param_1 + 0x15f);
    local_15c = local_10c + 1;
    pfVar5 = (float *)(param_1 + 0x15e);
    pfVar4 = local_10c;
    do {
      iVar3 = iVar7;
      if (local_144 <= iVar7) break;
      *pfVar5 = *pfVar4;
      *pfVar6 = *local_15c;
      *local_154 = *local_158;
      *local_14c = *local_150;
      iVar3 = iVar7 + 1;
      if (local_144 <= iVar7 + 1) break;
      pfVar5[4] = pfVar4[4];
      pfVar6[4] = local_15c[4];
      local_154[4] = local_158[4];
      local_14c[4] = local_150[4];
      iVar3 = iVar7 + 2;
      if (local_144 <= iVar7 + 2) break;
      pfVar5[8] = pfVar4[8];
      pfVar6[8] = local_15c[8];
      local_154[8] = local_158[8];
      local_14c[8] = local_150[8];
      iVar3 = iVar7 + 3;
      if (local_144 <= iVar7 + 3) break;
      pfVar5[0xc] = pfVar4[0xc];
      pfVar6[0xc] = local_15c[0xc];
      local_154[0xc] = local_158[0xc];
      local_14c[0xc] = local_150[0xc];
      local_14c = local_14c + 0x10;
      local_150 = local_150 + 0x10;
      local_154 = local_154 + 0x10;
      local_158 = local_158 + 0x10;
      pfVar6 = pfVar6 + 0x10;
      local_15c = local_15c + 0x10;
      pfVar5 = pfVar5 + 0x10;
      pfVar4 = pfVar4 + 0x10;
      iVar7 = iVar7 + 4;
      iVar3 = iVar7;
    } while (iVar7 < 8);
    if (iVar3 < 8) {
      param_1[iVar3 * 4 + 0x161] = 0;
    }
  }
  return;
}


