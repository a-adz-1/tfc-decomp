// RouteSimplify__12CBaseMonsterP11CBaseEntity  @ 000af844
void RouteSimplify__12CBaseMonsterP11CBaseEntity(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float *pfStack_15c;
  float *pfStack_158;
  float *pfStack_154;
  uint *puStack_150;
  uint *puStack_14c;
  int iStack_144;
  int iStack_140;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float afStack_10c [3];
  uint uStack_100;
  float afStack_fc [60];
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iStack_140 = 0;
  iVar7 = param_1[0x163];
  iVar3 = iStack_140;
  if (7 < iVar7) goto LAB_000af92e;
  piVar2 = param_1 + iVar7 * 4 + 0x145;
  uVar1 = 8U - iVar7 & 3;
  if (iVar7 < 8) {
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          if ((*piVar2 == 0) || (iStack_140 = 1, iVar3 = iStack_140, (char)*piVar2 < '\0'))
          goto LAB_000af92e;
          piVar2 = piVar2 + 4;
          iVar7 = iVar7 + 1;
        }
        iVar3 = iStack_140;
        if ((*piVar2 == 0) ||
           (iStack_140 = iStack_140 + 1, iVar3 = iStack_140, (char)*piVar2 < '\0'))
        goto LAB_000af92e;
        piVar2 = piVar2 + 4;
        iVar7 = iVar7 + 1;
      }
      goto LAB_000af8ca;
    }
  }
  else {
LAB_000af8ca:
    iVar3 = iStack_140;
    if ((*piVar2 == 0) || (iStack_140 = iStack_140 + 1, iVar3 = iStack_140, (char)*piVar2 < '\0'))
    goto LAB_000af92e;
    piVar2 = piVar2 + 4;
    iVar7 = iVar7 + 1;
    if (7 < iVar7) goto LAB_000af92e;
  }
  do {
    iVar3 = iStack_140;
    if (((((*piVar2 == 0) || (iVar3 = iStack_140 + 1, (char)*piVar2 < '\0')) || (piVar2[4] == 0)) ||
        ((iVar3 = iStack_140 + 2, (char)piVar2[4] < '\0' || (piVar2[8] == 0)))) ||
       ((iVar3 = iStack_140 + 3, (char)piVar2[8] < '\0' ||
        ((piVar2[0xc] == 0 ||
         (iStack_140 = iStack_140 + 4, iVar3 = iStack_140, (char)piVar2[0xc] < '\0')))))) break;
    piVar2 = piVar2 + 0x10;
    iVar7 = iVar7 + 4;
  } while (iVar7 < 8);
LAB_000af92e:
  iStack_140 = iVar3;
  if (1 < iStack_140) {
    iStack_144 = 0;
    iVar7 = *param_1;
    fStack_c = *(float *)(iVar7 + 8);
    fStack_8 = *(float *)(iVar7 + 0xc);
    fStack_4 = *(float *)(iVar7 + 0x10);
    iVar7 = 0;
    if (0 < iStack_140 + -1) {
      do {
        iVar3 = ShouldSimplify__Fi(param_1[(iVar7 + param_1[0x163]) * 4 + 0x145]);
        if (iVar3 == 0) {
          iVar3 = iVar7 + param_1[0x163];
          afStack_10c[iStack_144 * 4] = (float)param_1[iVar3 * 4 + 0x142];
          afStack_10c[iStack_144 * 4 + 1] = (float)param_1[iVar3 * 4 + 0x143];
          afStack_10c[iStack_144 * 4 + 2] = (float)param_1[iVar3 * 4 + 0x144];
          (&uStack_100)[iStack_144 * 4] = param_1[iVar3 * 4 + 0x145];
          iStack_144 = iStack_144 + 1;
LAB_000afcc2:
          fStack_c = afStack_10c[iStack_144 * 4];
          fStack_8 = afStack_10c[iStack_144 * 4 + 1];
          fStack_4 = afStack_10c[iStack_144 * 4 + 2];
          iStack_144 = iStack_144 + 1;
        }
        else {
          iVar3 = (**(code **)(param_1[0xf5] + 0x138))
                            (param_1,&fStack_c,param_1 + (iVar7 + param_1[0x163]) * 4 + 0x146,
                             param_2,0);
          if (iVar3 != 2) {
            iVar3 = iVar7 + param_1[0x163];
            pfVar4 = (float *)(param_1 + iVar3 * 4 + 0x146);
            pfVar5 = (float *)(param_1 + iVar3 * 4 + 0x142);
            fStack_118 = (*pfVar4 + *pfVar5) * 0.5;
            fStack_114 = (pfVar4[1] + pfVar5[1]) * 0.5;
            fStack_110 = (pfVar4[2] + pfVar5[2]) * 0.5;
            pfVar4 = (float *)(param_1 + iVar3 * 4 + 0x142);
            fStack_124 = (*pfVar4 + fStack_c) * 0.5;
            fStack_120 = (pfVar4[1] + fStack_8) * 0.5;
            fStack_11c = (pfVar4[2] + fStack_4) * 0.5;
            uVar1 = param_1[iVar3 * 4 + 0x145] & 0xfffffe7fU | 8;
            iVar3 = (**(code **)(param_1[0xf5] + 0x138))(param_1,&fStack_c,&fStack_118,param_2,0);
            if (iVar3 == 2) {
              (&uStack_100)[iStack_144 * 4] = uVar1;
              afStack_10c[iStack_144 * 4] = fStack_118;
              afStack_10c[iStack_144 * 4 + 1] = fStack_114;
              afStack_10c[iStack_144 * 4 + 2] = fStack_110;
            }
            else {
              iVar3 = (**(code **)(param_1[0xf5] + 0x138))
                                (param_1,&fStack_124,&fStack_118,param_2,0);
              if (iVar3 == 2) {
                (&uStack_100)[iStack_144 * 4] = uVar1;
                afStack_10c[iStack_144 * 4] = fStack_124;
                afStack_10c[iStack_144 * 4 + 1] = fStack_120;
                afStack_10c[iStack_144 * 4 + 2] = fStack_11c;
                (&uStack_100)[(iStack_144 + 1) * 4] = uVar1;
                afStack_fc[iStack_144 * 4] = fStack_118;
                afStack_fc[iStack_144 * 4 + 1] = fStack_114;
                afStack_fc[iStack_144 * 4 + 2] = fStack_110;
                iStack_144 = iStack_144 + 1;
              }
              else {
                iVar3 = iVar7 + param_1[0x163];
                afStack_10c[iStack_144 * 4] = (float)param_1[iVar3 * 4 + 0x142];
                afStack_10c[iStack_144 * 4 + 1] = (float)param_1[iVar3 * 4 + 0x143];
                afStack_10c[iStack_144 * 4 + 2] = (float)param_1[iVar3 * 4 + 0x144];
                (&uStack_100)[iStack_144 * 4] = param_1[iVar3 * 4 + 0x145];
              }
            }
            goto LAB_000afcc2;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iStack_140 + -1);
    }
    iVar7 = iVar7 + param_1[0x163];
    afStack_10c[iStack_144 * 4] = (float)param_1[iVar7 * 4 + 0x142];
    afStack_10c[iStack_144 * 4 + 1] = (float)param_1[iVar7 * 4 + 0x143];
    afStack_10c[iStack_144 * 4 + 2] = (float)param_1[iVar7 * 4 + 0x144];
    (&uStack_100)[iStack_144 * 4] = param_1[iVar7 * 4 + 0x145];
    iStack_144 = iStack_144 + 1;
    puStack_150 = &uStack_100;
    puStack_150[iStack_144 * 4] = 0;
    param_1[0x163] = 0;
    iVar7 = 0;
    puStack_14c = (uint *)(param_1 + 0x145);
    pfStack_154 = (float *)(param_1 + 0x144);
    pfStack_158 = afStack_10c + 2;
    pfVar6 = (float *)(param_1 + 0x143);
    pfStack_15c = afStack_10c + 1;
    pfVar5 = (float *)(param_1 + 0x142);
    pfVar4 = afStack_10c;
    do {
      iVar3 = iVar7;
      if (iStack_144 <= iVar7) break;
      *pfVar5 = *pfVar4;
      *pfVar6 = *pfStack_15c;
      *pfStack_154 = *pfStack_158;
      *puStack_14c = *puStack_150;
      iVar3 = iVar7 + 1;
      if (iStack_144 <= iVar7 + 1) break;
      pfVar5[4] = pfVar4[4];
      pfVar6[4] = pfStack_15c[4];
      pfStack_154[4] = pfStack_158[4];
      puStack_14c[4] = puStack_150[4];
      iVar3 = iVar7 + 2;
      if (iStack_144 <= iVar7 + 2) break;
      pfVar5[8] = pfVar4[8];
      pfVar6[8] = pfStack_15c[8];
      pfStack_154[8] = pfStack_158[8];
      puStack_14c[8] = puStack_150[8];
      iVar3 = iVar7 + 3;
      if (iStack_144 <= iVar7 + 3) break;
      pfVar5[0xc] = pfVar4[0xc];
      pfVar6[0xc] = pfStack_15c[0xc];
      pfStack_154[0xc] = pfStack_158[0xc];
      puStack_14c[0xc] = puStack_150[0xc];
      puStack_14c = puStack_14c + 0x10;
      puStack_150 = puStack_150 + 0x10;
      pfStack_154 = pfStack_154 + 0x10;
      pfStack_158 = pfStack_158 + 0x10;
      pfVar6 = pfVar6 + 0x10;
      pfStack_15c = pfStack_15c + 0x10;
      pfVar5 = pfVar5 + 0x10;
      pfVar4 = pfVar4 + 0x10;
      iVar7 = iVar7 + 4;
      iVar3 = iVar7;
    } while (iVar7 < 8);
    if (iVar3 < 8) {
      param_1[iVar3 * 4 + 0x145] = 0;
    }
  }
  return;
}


