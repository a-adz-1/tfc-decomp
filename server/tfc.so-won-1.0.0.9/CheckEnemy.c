// CheckEnemy__12CBaseMonsterP11CBaseEntity  @ 000c25c0
undefined4 CheckEnemy__12CBaseMonsterP11CBaseEntity(int *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  bool bVar12;
  longdouble lVar13;
  float local_40;
  
  uVar11 = 0;
  *(byte *)((int)param_1 + 0x46e) = *(byte *)((int)param_1 + 0x46e) & 0xf7;
  iVar8 = (**(code **)(param_1[0xf2] + 0xd8))(param_1,param_2);
  if (iVar8 == 0) {
    *(byte *)(param_1 + 0x11b) = *(byte *)(param_1 + 0x11b) | 0x20;
  }
  else {
    *(byte *)(param_1 + 0x11b) = *(byte *)(param_1 + 0x11b) & 0xdf;
  }
  iVar8 = (**(code **)(param_2[0xf2] + 0x88))(param_2);
  if (iVar8 == 0) {
    *(byte *)((int)param_1 + 0x46e) = *(byte *)((int)param_1 + 0x46e) | 0x10;
    *(byte *)(param_1 + 0x11b) = *(byte *)(param_1 + 0x11b) & 0xcf;
    return 0;
  }
  iVar8 = *param_2;
  fVar9 = *(float *)(iVar8 + 8);
  fVar2 = *(float *)(iVar8 + 0xc);
  iVar3 = *param_1;
  fVar4 = fVar9 - *(float *)(iVar3 + 8);
  fVar6 = fVar2 - *(float *)(iVar3 + 0xc);
  fVar5 = *(float *)(iVar8 + 0x10) - *(float *)(iVar3 + 0x10);
  local_40 = SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4);
  fVar4 = *(float *)(iVar8 + 0xdc) * 0.5 + *(float *)(iVar8 + 0x10);
  fVar5 = fVar9 - *(float *)(iVar3 + 8);
  fVar7 = fVar2 - *(float *)(iVar3 + 0xc);
  fVar6 = fVar4 - *(float *)(iVar3 + 0x10);
  fVar5 = SQRT(fVar6 * fVar6 + fVar7 * fVar7 + fVar5 * fVar5);
  if (((byte)(fVar5 < local_40 | (byte)((ushort)((ushort)(NAN(fVar5) || NAN(local_40)) << 10) >> 8)
             | (byte)((ushort)((ushort)(fVar5 == local_40) << 0xe) >> 8)) == 1) ||
     (fVar9 = fVar9 - *(float *)(*param_1 + 8), fVar2 = fVar2 - *(float *)(*param_1 + 0xc),
     fVar4 = (fVar4 - *(float *)(*param_2 + 0xdc)) - *(float *)(*param_1 + 0x10),
     fVar5 = SQRT(fVar4 * fVar4 + fVar2 * fVar2 + fVar9 * fVar9),
     (byte)(fVar5 < local_40 | (byte)((ushort)((ushort)(NAN(fVar5) || NAN(local_40)) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar5 == local_40) << 0xe) >> 8)) == 1)) {
    local_40 = fVar5;
  }
  if ((*(byte *)(param_1 + 0x11b) & 0x10) == 0) {
    if (((*(byte *)(param_1 + 0x11b) & 0x30) != 0) || (256.0 < local_40)) goto LAB_000c28db;
    iVar8 = *param_2;
    param_1[0x16e] = *(int *)(iVar8 + 8);
    param_1[0x16f] = *(int *)(iVar8 + 0xc);
    fVar9 = *(float *)(iVar8 + 0x10);
  }
  else {
    uVar11 = 1;
    iVar8 = *param_2;
    param_1[0x16e] = *(int *)(iVar8 + 8);
    param_1[0x16f] = *(int *)(iVar8 + 0xc);
    param_1[0x170] = *(int *)(iVar8 + 0x10);
    iVar8 = (**(code **)(param_2[0xf2] + 0x4c))(param_2);
    if (iVar8 != 0) {
      iVar8 = (**(code **)(*(int *)(iVar8 + 0x3c8) + 0x130))(iVar8,param_1);
      if (iVar8 == 0) {
        *(byte *)((int)param_1 + 0x46e) = *(byte *)((int)param_1 + 0x46e) & 0xf7;
      }
      else {
        *(byte *)((int)param_1 + 0x46e) = *(byte *)((int)param_1 + 0x46e) | 8;
      }
    }
    bVar12 = false;
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_2 + 0x20)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(*param_2 + 0x20) == 0.0) << 0xe) >> 8)) == 0x40)
       && (fVar9 = *(float *)(*param_2 + 0x24),
          (byte)((byte)((ushort)((ushort)NAN(fVar9) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar9 == 0.0) << 0xe) >> 8)) == 0x40)) {
      fVar9 = *(float *)(*param_2 + 0x28);
      bVar12 = (byte)(fVar9 < 0.0 | (byte)((ushort)((ushort)NAN(fVar9) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar9 == 0.0) << 0xe) >> 8)) == 0x40;
    }
    if (bVar12) goto LAB_000c28db;
    lVar13 = (longdouble)(*DAT_0017562c)(0xbd4ccccd,0);
    iVar8 = *param_2;
    fVar2 = *(float *)(iVar8 + 0x24);
    fVar9 = (float)param_1[0x170] - (float)(lVar13 * (longdouble)*(float *)(iVar8 + 0x28));
    param_1[0x16e] =
         (int)(float)((longdouble)(float)param_1[0x16e] -
                     lVar13 * (longdouble)*(float *)(iVar8 + 0x20));
    param_1[0x16f] = (int)(float)((longdouble)(float)param_1[0x16f] - lVar13 * (longdouble)fVar2);
  }
  uVar11 = 1;
  param_1[0x170] = (int)fVar9;
LAB_000c28db:
  if (local_40 < (float)param_1[0x17b]) {
    *(byte *)(param_1 + 0x11b) = *(byte *)(param_1 + 0x11b) & 0x7f;
  }
  else {
    *(byte *)(param_1 + 0x11b) = *(byte *)(param_1 + 0x11b) | 0x80;
  }
  iVar8 = (**(code **)(param_1[0xf2] + 0x1b4))(param_1);
  if (iVar8 != 0) {
    uVar10 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c,local_40);
    CheckAttacks__12CBaseMonsterP11CBaseEntityf(param_1,uVar10);
  }
  if (param_1[0x15f] == 2) {
    for (iVar8 = param_1[0x160]; iVar8 < 8; iVar8 = iVar8 + 1) {
      if ((param_1[iVar8 * 4 + 0x142] == 0x82) &&
         (pfVar1 = (float *)(param_1 + iVar8 * 4 + 0x13f),
         80.0 < SQRT((pfVar1[2] - (float)param_1[0x170]) * (pfVar1[2] - (float)param_1[0x170]) +
                     (pfVar1[1] - (float)param_1[0x16f]) * (pfVar1[1] - (float)param_1[0x16f]) +
                     (*pfVar1 - (float)param_1[0x16e]) * (*pfVar1 - (float)param_1[0x16e])))) {
        FRefreshRoute__12CBaseMonster(param_1);
        return uVar11;
      }
    }
  }
  return uVar11;
}


// CheckEnemy__13CSquadMonsterP11CBaseEntity  @ 000efac0
int CheckEnemy__13CSquadMonsterP11CBaseEntity(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
  iVar2 = CheckEnemy__12CBaseMonsterP11CBaseEntity(param_1,uVar1);
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
  if (iVar3 != 0) {
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
    iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
    iVar3 = param_1;
    if (iVar5 != 0) {
      iVar3 = iVar5;
    }
    iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x470);
    if (iVar4 == iVar3) {
      if (iVar2 == 0) {
        SquadCopyEnemyInfo__13CSquadMonster(param_1);
      }
      else {
        SquadPasteEnemyInfo__13CSquadMonster(param_1);
      }
    }
  }
  return iVar2;
}


