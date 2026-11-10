// CheckEnemy__12CBaseMonsterP11CBaseEntity  @ 000bc1b4
undefined4 CheckEnemy__12CBaseMonsterP11CBaseEntity(int *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float fVar10;
  undefined4 uVar11;
  uint uVar12;
  bool bVar13;
  longdouble lVar14;
  undefined4 uVar15;
  float local_40;
  
  uVar15 = 0;
  *(byte *)((int)param_1 + 0x4fa) = *(byte *)((int)param_1 + 0x4fa) & 0xf7;
  iVar9 = (**(code **)(param_1[0x115] + 0xe0))(param_1,param_2);
  if (iVar9 == 0) {
    *(byte *)(param_1 + 0x13e) = *(byte *)(param_1 + 0x13e) | 0x20;
  }
  else {
    *(byte *)(param_1 + 0x13e) = *(byte *)(param_1 + 0x13e) & 0xdf;
  }
  iVar9 = (**(code **)(param_2[0x115] + 0x8c))(param_2);
  if (iVar9 == 0) {
    param_1[0x13e] = param_1[0x13e] & 0xffffffcfU | 0x100000;
    return 0;
  }
  iVar9 = *param_2;
  fVar10 = *(float *)(iVar9 + 8);
  fVar2 = *(float *)(iVar9 + 0xc);
  iVar3 = *param_1;
  fVar6 = fVar10 - *(float *)(iVar3 + 8);
  fVar4 = fVar2 - *(float *)(iVar3 + 0xc);
  fVar5 = *(float *)(iVar9 + 0x10) - *(float *)(iVar3 + 0x10);
  fVar7 = SQRT(fVar5 * fVar5 + fVar4 * fVar4 + fVar6 * fVar6);
  fVar8 = *(float *)(iVar9 + 0xfc) * 0.5 + *(float *)(iVar9 + 0x10);
  fVar5 = fVar10 - *(float *)(iVar3 + 8);
  fVar6 = fVar2 - *(float *)(iVar3 + 0xc);
  fVar4 = fVar8 - *(float *)(iVar3 + 0x10);
  local_40 = SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5);
  if (((byte)(local_40 < fVar7 | (byte)((ushort)((ushort)(NAN(local_40) || NAN(fVar7)) << 10) >> 8)
             | (byte)((ushort)((ushort)(local_40 == fVar7) << 0xe) >> 8)) != 1) &&
     (fVar10 = fVar10 - *(float *)(iVar3 + 8), fVar2 = fVar2 - *(float *)(iVar3 + 0xc),
     fVar4 = (fVar8 - *(float *)(iVar9 + 0xfc)) - *(float *)(iVar3 + 0x10),
     local_40 = SQRT(fVar4 * fVar4 + fVar2 * fVar2 + fVar10 * fVar10), fVar7 <= local_40)) {
    local_40 = fVar7;
  }
  if ((param_1[0x13e] & 0x10U) == 0) {
    if (((param_1[0x13e] & 0x30U) != 0) ||
       ((byte)(256.0 < local_40 | (byte)((ushort)((ushort)NAN(local_40) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_40 == 256.0) << 0xe) >> 8)) == 1)) goto LAB_000bc4b4;
    iVar9 = *param_2;
    param_1[0x191] = *(int *)(iVar9 + 8);
    param_1[0x192] = *(int *)(iVar9 + 0xc);
    fVar10 = *(float *)(iVar9 + 0x10);
  }
  else {
    uVar15 = 1;
    iVar9 = *param_2;
    param_1[0x191] = *(int *)(iVar9 + 8);
    param_1[0x192] = *(int *)(iVar9 + 0xc);
    param_1[0x193] = *(int *)(iVar9 + 0x10);
    iVar9 = (**(code **)(param_2[0x115] + 0x50))(param_2);
    if (iVar9 != 0) {
      iVar9 = (**(code **)(*(int *)(iVar9 + 0x454) + 0x138))(iVar9,param_1);
      if (iVar9 == 0) {
        *(byte *)((int)param_1 + 0x4fa) = *(byte *)((int)param_1 + 0x4fa) & 0xf7;
      }
      else {
        *(byte *)((int)param_1 + 0x4fa) = *(byte *)((int)param_1 + 0x4fa) | 8;
      }
    }
    bVar13 = false;
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_2 + 0x20)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(*param_2 + 0x20) == 0.0) << 0xe) >> 8)) == 0x40)
       && (fVar10 = *(float *)(*param_2 + 0x24),
          (byte)((byte)((ushort)((ushort)NAN(fVar10) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar10 == 0.0) << 0xe) >> 8)) == 0x40)) {
      fVar10 = *(float *)(*param_2 + 0x28);
      bVar13 = (byte)(fVar10 < 0.0 | (byte)((ushort)((ushort)NAN(fVar10) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar10 == 0.0) << 0xe) >> 8)) == 0x40;
    }
    if (bVar13) goto LAB_000bc4b4;
    lVar14 = (longdouble)(*DAT_0019f80c)(0xbd4ccccd,0);
    iVar9 = *param_2;
    fVar2 = *(float *)(iVar9 + 0x24);
    fVar10 = (float)((longdouble)(float)param_1[0x193] -
                    lVar14 * (longdouble)*(float *)(iVar9 + 0x28));
    param_1[0x191] =
         (int)(float)((longdouble)(float)param_1[0x191] -
                     (longdouble)*(float *)(iVar9 + 0x20) * lVar14);
    param_1[0x192] = (int)(float)((longdouble)(float)param_1[0x192] - (longdouble)fVar2 * lVar14);
  }
  uVar15 = 1;
  param_1[0x193] = (int)fVar10;
LAB_000bc4b4:
  fVar10 = (float)param_1[0x19e];
  if ((byte)(local_40 < fVar10 | (byte)((ushort)((ushort)(NAN(local_40) || NAN(fVar10)) << 10) >> 8)
            | (byte)((ushort)((ushort)(local_40 == fVar10) << 0xe) >> 8)) == 1) {
    uVar12 = param_1[0x13e] & 0xffffff7f;
  }
  else {
    uVar12 = param_1[0x13e] | 0x80;
  }
  param_1[0x13e] = uVar12;
  iVar9 = (**(code **)(param_1[0x115] + 0x1bc))(param_1);
  if (iVar9 != 0) {
    uVar11 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f,local_40);
    CheckAttacks__12CBaseMonsterP11CBaseEntityf(param_1,uVar11);
  }
  if (param_1[0x182] == 2) {
    for (iVar9 = param_1[0x183]; iVar9 < 8; iVar9 = iVar9 + 1) {
      if (param_1[iVar9 * 4 + 0x165] == 0x82) {
        pfVar1 = (float *)(param_1 + iVar9 * 4 + 0x162);
        fVar10 = SQRT((pfVar1[2] - (float)param_1[0x193]) * (pfVar1[2] - (float)param_1[0x193]) +
                      (pfVar1[1] - (float)param_1[0x192]) * (pfVar1[1] - (float)param_1[0x192]) +
                      (*pfVar1 - (float)param_1[0x191]) * (*pfVar1 - (float)param_1[0x191]));
        if ((byte)(80.0 < fVar10 | (byte)((ushort)((ushort)NAN(fVar10) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar10 == 80.0) << 0xe) >> 8)) == 1) {
          FRefreshRoute__12CBaseMonster(param_1);
          return uVar15;
        }
      }
    }
  }
  return uVar15;
}


// CheckEnemy__13CSquadMonsterP11CBaseEntity  @ 000f4b84
int CheckEnemy__13CSquadMonsterP11CBaseEntity(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
  iVar2 = CheckEnemy__12CBaseMonsterP11CBaseEntity(param_1,uVar1);
  iVar6 = param_1 + 0x69c;
  iVar3 = __opP11CBaseEntity__7EHANDLE(iVar6);
  if (iVar3 != 0) {
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
    iVar5 = __opP11CBaseEntity__7EHANDLE(iVar6);
    iVar3 = param_1;
    if (iVar5 != 0) {
      iVar3 = iVar5;
    }
    iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x4fc);
    if (iVar4 == iVar3) {
      if (iVar2 == 0) {
        iVar3 = __opP11CBaseEntity__7EHANDLE(iVar6);
        iVar6 = param_1;
        if (iVar3 != 0) {
          iVar6 = iVar3;
        }
        if (iVar6 != 0) {
          *(undefined4 *)(param_1 + 0x644) = *(undefined4 *)(iVar6 + 0x644);
          *(undefined4 *)(param_1 + 0x648) = *(undefined4 *)(iVar6 + 0x648);
          *(undefined4 *)(param_1 + 0x64c) = *(undefined4 *)(iVar6 + 0x64c);
        }
      }
      else {
        iVar3 = __opP11CBaseEntity__7EHANDLE(iVar6);
        iVar6 = param_1;
        if (iVar3 != 0) {
          iVar6 = iVar3;
        }
        if (iVar6 != 0) {
          *(undefined4 *)(iVar6 + 0x644) = *(undefined4 *)(param_1 + 0x644);
          *(undefined4 *)(iVar6 + 0x648) = *(undefined4 *)(param_1 + 0x648);
          *(undefined4 *)(iVar6 + 0x64c) = *(undefined4 *)(param_1 + 0x64c);
        }
      }
    }
  }
  return iVar2;
}


