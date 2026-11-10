// CheckEnemy__12CBaseMonsterP11CBaseEntity  @ 000bb4dc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CheckEnemy__12CBaseMonsterP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  undefined4 uVar8;
  float *pfVar9;
  float *pfVar10;
  bool bVar11;
  longdouble lVar12;
  float *local_50;
  int *local_4c;
  int local_48;
  undefined4 local_40;
  float local_3c;
  
  local_40 = 0;
  *(byte *)((int)param_1 + 0x4ea) = *(byte *)((int)param_1 + 0x4ea) & 0xf7;
  iVar6 = (**(code **)(param_1[0x111] + 0xe0))(param_1,param_2);
  if (iVar6 == 0) {
    *(byte *)(param_1 + 0x13a) = *(byte *)(param_1 + 0x13a) | 0x20;
  }
  else {
    *(byte *)(param_1 + 0x13a) = *(byte *)(param_1 + 0x13a) & 0xdf;
  }
  iVar6 = (**(code **)(param_2[0x111] + 0x8c))(param_2);
  if (iVar6 == 0) {
    *(byte *)((int)param_1 + 0x4ea) = *(byte *)((int)param_1 + 0x4ea) | 0x10;
    *(byte *)(param_1 + 0x13a) = *(byte *)(param_1 + 0x13a) & 0xcf;
    return 0;
  }
  fVar7 = *(float *)(*param_2 + 8);
  fVar1 = *(float *)(*param_2 + 0xc);
  fVar2 = *(float *)(*param_2 + 0x10);
  iVar6 = *param_1;
  fVar3 = fVar7 - *(float *)(iVar6 + 8);
  fVar5 = fVar1 - *(float *)(iVar6 + 0xc);
  fVar4 = fVar2 - *(float *)(iVar6 + 0x10);
  local_3c = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3);
  fVar2 = *(float *)(*param_2 + 0xfc) * 0.5 + fVar2;
  fVar3 = fVar7 - *(float *)(iVar6 + 8);
  fVar5 = fVar1 - *(float *)(iVar6 + 0xc);
  fVar4 = fVar2 - *(float *)(iVar6 + 0x10);
  fVar3 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3);
  if (((byte)(fVar3 < local_3c | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(local_3c)) << 10) >> 8)
             | (byte)((ushort)((ushort)(fVar3 == local_3c) << 0xe) >> 8)) == 1) ||
     (fVar7 = fVar7 - *(float *)(*param_1 + 8), fVar1 = fVar1 - *(float *)(*param_1 + 0xc),
     fVar2 = (fVar2 - *(float *)(*param_2 + 0xfc)) - *(float *)(*param_1 + 0x10),
     fVar3 = SQRT(fVar2 * fVar2 + fVar1 * fVar1 + fVar7 * fVar7), fVar3 < local_3c)) {
    local_3c = fVar3;
  }
  if ((*(byte *)(param_1 + 0x13a) & 0x10) == 0) {
    if (((*(byte *)(param_1 + 0x13a) & 0x30) == 0) &&
       ((byte)(_FUN_001487a0 < local_3c |
               (byte)((ushort)((ushort)(NAN(_FUN_001487a0) || NAN(local_3c)) << 10) >> 8) |
              (byte)((ushort)((ushort)(_FUN_001487a0 == local_3c) << 0xe) >> 8)) != 1)) {
      iVar6 = *param_2;
      param_1[0x18d] = *(int *)(iVar6 + 8);
      param_1[0x18e] = *(int *)(iVar6 + 0xc);
      fVar7 = *(float *)(iVar6 + 0x10);
      goto LAB_000bb824;
    }
  }
  else {
    local_40 = 1;
    iVar6 = *param_2;
    param_1[0x18d] = *(int *)(iVar6 + 8);
    param_1[0x18e] = *(int *)(iVar6 + 0xc);
    param_1[399] = *(int *)(iVar6 + 0x10);
    iVar6 = (**(code **)(param_2[0x111] + 0x50))(param_2);
    if (iVar6 != 0) {
      iVar6 = (**(code **)(*(int *)(iVar6 + 0x444) + 0x138))(iVar6,param_1);
      if (iVar6 == 0) {
        *(byte *)((int)param_1 + 0x4ea) = *(byte *)((int)param_1 + 0x4ea) & 0xf7;
      }
      else {
        *(byte *)((int)param_1 + 0x4ea) = *(byte *)((int)param_1 + 0x4ea) | 8;
      }
    }
    bVar11 = false;
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_2 + 0x20)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(*param_2 + 0x20) == 0.0) << 0xe) >> 8)) == 0x40)
       && (fVar7 = *(float *)(*param_2 + 0x24),
          (byte)((byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar7 == 0.0) << 0xe) >> 8)) == 0x40)) {
      fVar7 = *(float *)(*param_2 + 0x28);
      bVar11 = (byte)(fVar7 < 0.0 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar7 == 0.0) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar11) {
      lVar12 = (longdouble)(*DAT_001c118c)(0xbd4ccccd,0);
      iVar6 = *param_2;
      fVar1 = *(float *)(iVar6 + 0x24);
      fVar7 = (float)param_1[399] - (float)(lVar12 * (longdouble)*(float *)(iVar6 + 0x28));
      param_1[0x18d] =
           (int)(float)((longdouble)(float)param_1[0x18d] -
                       lVar12 * (longdouble)*(float *)(iVar6 + 0x20));
      param_1[0x18e] = (int)(float)((longdouble)(float)param_1[0x18e] - lVar12 * (longdouble)fVar1);
LAB_000bb824:
      local_40 = 1;
      param_1[399] = (int)fVar7;
    }
  }
  fVar7 = (float)param_1[0x19a];
  if ((byte)(local_3c < fVar7 | (byte)((ushort)((ushort)(NAN(local_3c) || NAN(fVar7)) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_3c == fVar7) << 0xe) >> 8)) == 1) {
    *(byte *)(param_1 + 0x13a) = *(byte *)(param_1 + 0x13a) & 0x7f;
  }
  else {
    *(byte *)(param_1 + 0x13a) = *(byte *)(param_1 + 0x13a) | 0x80;
  }
  iVar6 = (**(code **)(param_1[0x111] + 0x1bc))(param_1);
  if (iVar6 != 0) {
    uVar8 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b,local_3c);
    CheckAttacks__12CBaseMonsterP11CBaseEntityf(param_1,uVar8);
  }
  if (param_1[0x17e] != 2) {
    return local_40;
  }
  iVar6 = param_1[0x17f];
  if (7 < iVar6) {
    return local_40;
  }
  local_48 = iVar6 * 0x10;
  pfVar10 = (float *)(param_1 + iVar6 * 4 + 0x160);
  local_50 = (float *)(param_1 + iVar6 * 4 + 0x15f);
  pfVar9 = (float *)(param_1 + iVar6 * 4 + 0x15e);
  if ((7 < iVar6) || ((8U - iVar6 & 1) != 0)) {
    if ((param_1[iVar6 * 4 + 0x161] == 0x82) &&
       (80.0 < SQRT((*pfVar10 - (float)param_1[399]) * (*pfVar10 - (float)param_1[399]) +
                    (*local_50 - (float)param_1[0x18e]) * (*local_50 - (float)param_1[0x18e]) +
                    (*pfVar9 - (float)param_1[0x18d]) * (*pfVar9 - (float)param_1[0x18d]))))
    goto LAB_000bb847;
    pfVar10 = pfVar10 + 4;
    local_50 = local_50 + 4;
    pfVar9 = pfVar9 + 4;
    local_48 = local_48 + 0x10;
    iVar6 = iVar6 + 1;
    if (7 < iVar6) {
      return local_40;
    }
  }
  local_4c = (int *)((int)param_1 + local_48 + 0x584);
  while (((*local_4c != 0x82 ||
          (SQRT((*pfVar10 - (float)param_1[399]) * (*pfVar10 - (float)param_1[399]) +
                (*local_50 - (float)param_1[0x18e]) * (*local_50 - (float)param_1[0x18e]) +
                (*pfVar9 - (float)param_1[0x18d]) * (*pfVar9 - (float)param_1[0x18d])) <= 80.0)) &&
         ((local_4c[4] != 0x82 ||
          (SQRT((pfVar10[4] - (float)param_1[399]) * (pfVar10[4] - (float)param_1[399]) +
                (local_50[4] - (float)param_1[0x18e]) * (local_50[4] - (float)param_1[0x18e]) +
                (pfVar9[4] - (float)param_1[0x18d]) * (pfVar9[4] - (float)param_1[0x18d])) <= 80.0))
         ))) {
    pfVar10 = pfVar10 + 8;
    local_50 = local_50 + 8;
    pfVar9 = pfVar9 + 8;
    local_4c = local_4c + 8;
    iVar6 = iVar6 + 2;
    if (7 < iVar6) {
      return local_40;
    }
  }
LAB_000bb847:
  FRefreshRoute__12CBaseMonster(param_1);
  return local_40;
}


// CheckEnemy__13CSquadMonsterP11CBaseEntity  @ 000f2c20
int CheckEnemy__13CSquadMonsterP11CBaseEntity(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
  iVar2 = CheckEnemy__12CBaseMonsterP11CBaseEntity(param_1,uVar1);
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
  if (iVar3 != 0) {
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
    iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
    iVar3 = param_1;
    if (iVar5 != 0) {
      iVar3 = iVar5;
    }
    iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x4ec);
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


