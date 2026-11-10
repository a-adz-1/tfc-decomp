// RouteSimplify__12CBaseMonsterP11CBaseEntity  @ 000bb9c8
/* WARNING: Type propagation algorithm not settling */

void RouteSimplify__12CBaseMonsterP11CBaseEntity(int *param_1,undefined4 param_2)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  float fVar4;
  bool bVar5;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_144;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float afStack_110 [64];
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = 0xf;
  do {
    bVar5 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar5);
  iStack_174 = 0;
  iVar3 = param_1[0x183];
  while (((iVar3 < 8 && (param_1[iVar3 * 4 + 0x165] != 0)) &&
         (iStack_174 = iStack_174 + 1, -1 < (char)param_1[iVar3 * 4 + 0x165]))) {
    iVar3 = iVar3 + 1;
  }
  if (1 < iStack_174) {
    iStack_16c = 0;
    iStack_144 = 0;
    iVar3 = *param_1;
    fStack_10 = *(float *)(iVar3 + 8);
    fStack_c = *(float *)(iVar3 + 0xc);
    fStack_8 = *(float *)(iVar3 + 0x10);
    if (0 < iStack_174 + -1) {
      do {
        iVar3 = iStack_144 + param_1[0x183];
        if (((param_1[iVar3 * 4 + 0x165] & 0xffffff7fU) == 0x10) ||
           ((param_1[iVar3 * 4 + 0x165] & 0x100U) != 0)) {
          afStack_110[iStack_16c * 4] = (float)param_1[iVar3 * 4 + 0x162];
          afStack_110[iStack_16c * 4 + 1] = (float)param_1[iVar3 * 4 + 0x163];
          afStack_110[iStack_16c * 4 + 2] = (float)param_1[iVar3 * 4 + 0x164];
          afStack_110[iStack_16c * 4 + 3] = (float)param_1[iVar3 * 4 + 0x165];
          iStack_170 = (iStack_16c + 1) * 0x10;
          iStack_16c = iStack_16c + 1;
LAB_000bbe9f:
          iStack_16c = iStack_16c + 1;
          fStack_10 = *(float *)((int)afStack_110 + iStack_170);
          fStack_c = *(float *)((int)afStack_110 + iStack_170 + 4);
          fStack_8 = *(float *)((int)afStack_110 + iStack_170 + 8);
        }
        else {
          iVar3 = (**(code **)(param_1[0x115] + 0x140))
                            (param_1,&fStack_10,param_1 + iVar3 * 4 + 0x166,param_2,0);
          if (iVar3 != 2) {
            iVar3 = iStack_144 + param_1[0x183];
            pfVar1 = (float *)(param_1 + iVar3 * 4 + 0x166);
            pfVar2 = (float *)(param_1 + iVar3 * 4 + 0x162);
            fStack_11c = (*pfVar1 + *pfVar2) * 0.5;
            fStack_118 = (pfVar1[1] + pfVar2[1]) * 0.5;
            fStack_114 = (pfVar1[2] + pfVar2[2]) * 0.5;
            pfVar1 = (float *)(param_1 + iVar3 * 4 + 0x162);
            fStack_128 = (*pfVar1 + fStack_10) * 0.5;
            fStack_124 = (pfVar1[1] + fStack_c) * 0.5;
            fStack_120 = (pfVar1[2] + fStack_8) * 0.5;
            fVar4 = (float)(param_1[iVar3 * 4 + 0x165] & 0xfffffe7fU | 8);
            iVar3 = (**(code **)(param_1[0x115] + 0x140))(param_1,&fStack_10,&fStack_11c,param_2,0);
            if (iVar3 == 2) {
              iStack_170 = iStack_16c * 0x10;
              afStack_110[iStack_16c * 4 + 3] = fVar4;
              afStack_110[iStack_16c * 4] = fStack_11c;
              afStack_110[iStack_16c * 4 + 1] = fStack_118;
              afStack_110[iStack_16c * 4 + 2] = fStack_114;
            }
            else {
              iVar3 = (**(code **)(param_1[0x115] + 0x140))
                                (param_1,&fStack_128,&fStack_11c,param_2,0);
              if (iVar3 == 2) {
                afStack_110[iStack_16c * 4 + 3] = fVar4;
                afStack_110[iStack_16c * 4] = fStack_128;
                afStack_110[iStack_16c * 4 + 1] = fStack_124;
                afStack_110[iStack_16c * 4 + 2] = fStack_120;
                iVar3 = iStack_16c + 1;
                iStack_170 = iVar3 * 0x10;
                afStack_110[iVar3 * 4 + 3] = fVar4;
                afStack_110[iStack_16c * 4 + 4] = fStack_11c;
                afStack_110[iStack_16c * 4 + 5] = fStack_118;
                afStack_110[iStack_16c * 4 + 6] = fStack_114;
                iStack_16c = iVar3;
              }
              else {
                iStack_170 = iStack_16c * 0x10;
                iVar3 = iStack_144 + param_1[0x183];
                afStack_110[iStack_16c * 4] = (float)param_1[iVar3 * 4 + 0x162];
                afStack_110[iStack_16c * 4 + 1] = (float)param_1[iVar3 * 4 + 0x163];
                afStack_110[iStack_16c * 4 + 2] = (float)param_1[iVar3 * 4 + 0x164];
                afStack_110[iStack_16c * 4 + 3] = (float)param_1[iVar3 * 4 + 0x165];
              }
            }
            goto LAB_000bbe9f;
          }
        }
        iStack_144 = iStack_144 + 1;
      } while (iStack_144 < iStack_174 + -1);
    }
    iStack_144 = iStack_144 + param_1[0x183];
    afStack_110[iStack_16c * 4] = (float)param_1[iStack_144 * 4 + 0x162];
    afStack_110[iStack_16c * 4 + 1] = (float)param_1[iStack_144 * 4 + 0x163];
    afStack_110[iStack_16c * 4 + 2] = (float)param_1[iStack_144 * 4 + 0x164];
    afStack_110[iStack_16c * 4 + 3] = (float)param_1[iStack_144 * 4 + 0x165];
    iStack_144 = 0;
    afStack_110[(iStack_16c + 1) * 4 + 3] = 0.0;
    param_1[0x183] = 0;
    do {
      if (iStack_16c + 1 <= iStack_144) break;
      param_1[iStack_144 * 4 + 0x162] = (int)afStack_110[iStack_144 * 4];
      param_1[iStack_144 * 4 + 0x163] = (int)afStack_110[iStack_144 * 4 + 1];
      param_1[iStack_144 * 4 + 0x164] = (int)afStack_110[iStack_144 * 4 + 2];
      param_1[iStack_144 * 4 + 0x165] = (int)afStack_110[iStack_144 * 4 + 3];
      iStack_144 = iStack_144 + 1;
    } while (iStack_144 < 8);
    if (iStack_144 < 8) {
      param_1[iStack_144 * 4 + 0x165] = 0;
    }
  }
  return;
}


