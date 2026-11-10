// UpdateStats__FP11CBasePlayer  @ 000d351c
void UpdateStats__FP11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  FILE *__stream;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  longdouble lVar12;
  undefined1 *puVar14;
  undefined8 uVar13;
  float local_cc;
  undefined1 local_b0 [8];
  undefined4 local_a8;
  int local_84 [32];
  
  piVar8 = param_1 + 0x23b;
  piVar10 = local_84;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar10 = *piVar8;
    piVar8 = piVar8 + 1;
    piVar10 = piVar10 + 1;
  }
  if (*gpGlobals < DAT_0016728c) {
    DAT_00167284 = DAT_00167288;
    DAT_0016728c = *gpGlobals;
  }
  DAT_00167288 = (*gpGlobals - DAT_0016728c) + DAT_00167288;
  iVar7 = 0;
  DAT_0016728c = *gpGlobals;
  do {
    iVar9 = param_1[iVar7 + 0x231];
    if (iVar9 != 0) {
      do {
        puVar14 = local_b0;
        memset(local_b0,0,0x2c);
        uVar13 = CONCAT44(puVar14,local_b0);
        iVar6 = iVar9;
        (**(code **)(*(int *)(iVar9 + 0x454) + 0x118))();
        iVar6 = GetAmmoIndex__11CBasePlayerPCc(local_a8,iVar6,uVar13);
        if (-1 < iVar6) {
          piVar8 = local_84 + iVar6;
          *piVar8 = *piVar8 + *(int *)(iVar9 + 0x4c0);
        }
        iVar9 = *(int *)(iVar9 + 0x478);
      } while (iVar9 != 0);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 6);
  local_cc = 0.0;
  iVar7 = 1;
  do {
    lVar12 = (longdouble)AmmoDamage__FPCc((&_15CBasePlayerItem_AmmoInfoArray)[iVar7 * 2]);
    pfVar5 = gpGlobals;
    piVar8 = local_84 + iVar7;
    iVar7 = iVar7 + 1;
    local_cc = (float)(lVar12 * (longdouble)*piVar8 + (longdouble)local_cc);
  } while (iVar7 < 0x20);
  fVar1 = *(float *)(*param_1 + 0x1bc);
  fVar1 = fVar1 + fVar1 + *(float *)(*param_1 + 0x160);
  fVar2 = ABS(local_cc - (float)gStats);
  fVar3 = ABS(fVar1 - DAT_00167278);
  bVar11 = false;
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    bVar11 = (byte)(0.0 < DAT_00167278 | (byte)((ushort)((ushort)NAN(DAT_00167278) << 10) >> 8) |
                   (byte)((ushort)((ushort)(DAT_00167278 == 0.0) << 0xe) >> 8)) == 1;
  }
  if ((((byte)(10.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 10.0) << 0xe) >> 8)) != 1) &&
      ((byte)((fVar3 < 10.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 10.0) << 0xe) >> 8)) - 1) < 0x40)) || (bVar11)) {
    if ((((byte)(DAT_00167280 < 0.0 | (byte)((ushort)((ushort)NAN(DAT_00167280) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_00167280 == 0.0) << 0xe) >> 8)) != 0x40) &&
        ((byte)(DAT_00167280 < DAT_00167288 |
                (byte)((ushort)((ushort)(NAN(DAT_00167280) || NAN(DAT_00167288)) << 10) >> 8) |
               (byte)((ushort)((ushort)(DAT_00167280 == DAT_00167288) << 0xe) >> 8)) == 1)) ||
       (bVar11)) {
      lVar12 = (longdouble)(*DAT_0019f784)("skill");
      fVar4 = DAT_00167284;
      fVar2 = pfVar5[3];
      fVar3 = pfVar5[0x26];
      __stream = fopen("stats.txt","a");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%6.2f, %6.2f, %6.2f, %s, %2d\n",(double)fVar4,(double)fVar1,
                (double)local_cc,(int)fVar2 + (int)fVar3,(int)ROUND(lVar12));
        fclose(__stream);
      }
      gStats = (int)ROUND(local_cc);
      DAT_0016727c = DAT_00167288;
      DAT_00167280 = 0.0;
      DAT_00167278 = fVar1;
    }
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(DAT_00167280) << 10) >> 8) |
              (byte)((ushort)((ushort)(DAT_00167280 == 0.0) << 0xe) >> 8)) == 0x40) {
      DAT_00167284 = DAT_00167288;
    }
    gStats = (int)ROUND(local_cc);
    DAT_00167280 = DAT_00167288 + 3.0;
    DAT_00167278 = fVar1;
  }
  return;
}


