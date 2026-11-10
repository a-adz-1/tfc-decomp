// UTIL_AngleDiff__Fff  @ 00122f60
longdouble UTIL_AngleDiff__Fff(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  lVar1 = (longdouble)param_1;
  lVar2 = (longdouble)param_2;
  lVar3 = lVar1 - lVar2;
  if ((byte)((lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) - 1) < 0x40) {
    lVar1 = (longdouble)-180.0;
    if ((byte)(lVar1 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar1 == lVar3) << 0xe) >> 8)) != 1) {
      lVar3 = (longdouble)360.0 + lVar3;
    }
  }
  else if ((longdouble)180.0 <= lVar3) {
    lVar3 = lVar3 - (longdouble)360.0;
  }
  return lVar3;
}


// UTIL_AngleDistance__Fff  @ 00121fdc
longdouble UTIL_AngleDistance__Fff(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 - (longdouble)param_2;
  lVar2 = (longdouble)-180.0;
  if ((byte)((lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1) < 0x40) {
    if ((longdouble)180.0 < lVar1) {
      lVar1 = lVar1 - (longdouble)360.0;
    }
  }
  else {
    lVar1 = (longdouble)360.0 + lVar1;
  }
  return lVar1;
}


// UTIL_AngleMod__Ff  @ 00122fc8
longdouble UTIL_AngleMod__Ff(float param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)param_1;
  lVar1 = (longdouble)0;
  if ((byte)((lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) - 1) < 0x40) {
    if ((longdouble)360.0 <= lVar2) {
      lVar2 = lVar2 - (longdouble)((int)ROUND(lVar2 * (longdouble)0.0027777778) * 0x168);
    }
  }
  else {
    lVar2 = lVar2 + (longdouble)(((int)ROUND(lVar2 * (longdouble)0.0027777778) * 3 + 3) * 0x78);
  }
  return lVar2;
}


// UTIL_ApproachAngle__Ffff  @ 0011e12c
longdouble UTIL_ApproachAngle__Ffff(float param_1,undefined4 param_2,float param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar1 = (longdouble)param_3;
  lVar2 = (longdouble)param_1;
  lVar3 = (longdouble)0;
  if ((byte)((lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) - 1) < 0x40) {
    if ((longdouble)360.0 <= lVar2) {
      lVar2 = lVar2 - (longdouble)((int)ROUND(lVar2 * (longdouble)0.0027777778) * 0x168);
    }
  }
  else {
    lVar2 = lVar2 + (longdouble)(((int)ROUND(lVar2 * (longdouble)0.0027777778) * 3 + 3) * 0x78);
  }
  lVar3 = (longdouble)0;
  if ((byte)((lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) - 1) < 0x40) {
    lVar3 = lVar2;
    if ((longdouble)360.0 <= lVar2) {
      lVar3 = lVar2 - (longdouble)((int)ROUND(lVar2 * (longdouble)0.0027777778) * 0x168);
    }
  }
  else {
    lVar3 = lVar2 + (longdouble)(((int)ROUND(lVar2 * (longdouble)0.0027777778) * 3 + 3) * 0x78);
  }
  lVar4 = lVar2 - lVar3;
  lVar5 = (longdouble)0;
  if (0x3f < (byte)((lVar5 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar1) << 0xe) >> 8)) - 1)) {
    lVar1 = -lVar1;
  }
  lVar5 = (longdouble)-180.0;
  if ((byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1) < 0x40) {
    if ((longdouble)180.0 < lVar4) {
      lVar4 = lVar4 - (longdouble)360.0;
    }
  }
  else {
    lVar4 = (longdouble)360.0 + lVar4;
  }
  if ((byte)((lVar4 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar4 == lVar1) << 0xe) >> 8)) - 1) < 0x40) {
    lVar5 = -lVar1;
    if (0x3f < (byte)((lVar5 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
      lVar2 = lVar3 - lVar1;
    }
  }
  else {
    lVar2 = lVar3 + lVar1;
  }
  return lVar2;
}


// UTIL_Approach__Ffff  @ 00122030
longdouble UTIL_Approach__Ffff(float param_1,float param_2,float param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar1 = (longdouble)param_1;
  lVar2 = (longdouble)param_2;
  lVar3 = lVar1 - lVar2;
  lVar4 = (longdouble)param_3;
  if (lVar3 <= lVar4) {
    lVar5 = -lVar4;
    if (0x3f < (byte)((lVar5 < lVar3 |
                       (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar5 == lVar3) << 0xe) >> 8)) - 1)) {
      lVar1 = lVar2 - lVar4;
    }
  }
  else {
    lVar1 = lVar2 + lVar4;
  }
  return lVar1;
}


// UTIL_BloodDecalTrace__FP11TraceResulti  @ 00121d74
void UTIL_BloodDecalTrace__FP11TraceResulti(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  if (param_2 == -1) {
LAB_00121def:
    bVar1 = false;
  }
  else {
    if (param_2 == 0xf7) {
      lVar3 = (longdouble)(*DAT_0019f784)("violence_hblood");
      lVar4 = (longdouble)0;
      if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 0x40) goto LAB_00121df5;
      goto LAB_00121def;
    }
    lVar4 = (longdouble)(*DAT_0019f784)("violence_ablood");
    bVar1 = true;
    if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40)
    goto LAB_00121def;
  }
  if (!bVar1) {
    return;
  }
LAB_00121df5:
  if (param_2 == 0xf7) {
    iVar2 = (*DAT_0019f808)(0,5);
    iVar2 = iVar2 + 0xd;
  }
  else {
    iVar2 = (*DAT_0019f808)(0,5);
    iVar2 = iVar2 + 0x13;
  }
  UTIL_DecalTrace__FP11TraceResulti(param_1,iVar2);
  return;
}


// UTIL_BloodDrips__FRC6VectorT0ii  @ 0011e5cc
void UTIL_BloodDrips__FRC6VectorT0ii(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  if (param_3 == -1) {
LAB_0011e647:
    bVar1 = false;
  }
  else {
    if (param_3 == 0xf7) {
      lVar3 = (longdouble)(*DAT_0019f784)("violence_hblood");
      lVar4 = (longdouble)0;
      if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 0x40) goto LAB_0011e651;
      goto LAB_0011e647;
    }
    lVar4 = (longdouble)(*DAT_0019f784)("violence_ablood");
    bVar1 = true;
    if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40)
    goto LAB_0011e647;
  }
  if (!bVar1) {
    return;
  }
LAB_0011e651:
  if ((param_3 != -1) && (param_4 != 0)) {
    if ((g_Language == 1) && (param_3 == 0xf7)) {
      param_3 = 0;
    }
    iVar2 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (iVar2 != 0) {
      param_4 = param_4 * 2;
    }
    if (0xff < param_4) {
      param_4 = 0xff;
    }
    (*DAT_0019f758)(4,0x17,param_1,0);
    (*DAT_0019f760)(0x73);
    (*DAT_0019f774)(*param_1);
    (*DAT_0019f774)(param_1[1]);
    (*DAT_0019f774)(param_1[2]);
    (*DAT_0019f768)((int)g_sModelIndexBloodSpray);
    (*DAT_0019f768)((int)g_sModelIndexBloodDrop);
    (*DAT_0019f760)(param_3);
    param_4 = param_4 / 10;
    iVar2 = param_4;
    if (param_4 < 3) {
      iVar2 = 3;
    }
    if (iVar2 < 0x10) {
      iVar2 = 3;
      if (2 < param_4) {
        iVar2 = param_4;
      }
    }
    else {
      iVar2 = 0x10;
    }
    (*DAT_0019f760)(iVar2);
    (*DAT_0019f75c)();
  }
  return;
}


// UTIL_BloodStream__FRC6VectorT0ii  @ 0011e430
void UTIL_BloodStream__FRC6VectorT0ii
               (undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  bool bVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  if (param_3 == -1) {
LAB_0011e4ab:
    bVar1 = false;
  }
  else {
    if (param_3 == 0xf7) {
      lVar2 = (longdouble)(*DAT_0019f784)("violence_hblood");
      lVar3 = (longdouble)0;
      if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) != 0x40) goto LAB_0011e4b5;
      goto LAB_0011e4ab;
    }
    lVar3 = (longdouble)(*DAT_0019f784)("violence_ablood");
    bVar1 = true;
    if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)((longdouble)0 == lVar3) << 0xe) >> 8)) == 0x40)
    goto LAB_0011e4ab;
  }
  if (!bVar1) {
    return;
  }
LAB_0011e4b5:
  if ((g_Language == 1) && (param_3 == 0xf7)) {
    param_3 = 0;
  }
  (*DAT_0019f758)(4,0x17,param_1,0);
  (*DAT_0019f760)(0x65);
  (*DAT_0019f774)(*param_1);
  (*DAT_0019f774)(param_1[1]);
  (*DAT_0019f774)(param_1[2]);
  (*DAT_0019f774)(*param_2);
  (*DAT_0019f774)(param_2[1]);
  (*DAT_0019f774)(param_2[2]);
  (*DAT_0019f760)(param_3);
  if (0xff < param_4) {
    param_4 = 0xff;
  }
  (*DAT_0019f760)(param_4);
  (*DAT_0019f75c)();
  return;
}


// UTIL_BubbleTrail__FG6VectorT0i  @ 0011edd0
void UTIL_BubbleTrail__FG6VectorT0i(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  local_1c = (float)param_1[2];
  local_20 = local_1c + 256.0;
  local_10 = *param_1;
  local_c = param_1[1];
  local_8 = local_1c;
  iVar3 = (*DAT_0019f754)(&local_10);
  local_18 = local_1c;
  if ((iVar3 == -3) &&
     (local_8 = local_20, iVar3 = (*DAT_0019f754)(&local_10), local_18 = local_20, iVar3 != -3)) {
    while (fVar1 = local_20 - local_1c, local_18 = local_8,
          (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) {
      local_8 = fVar1 * 0.5 + local_1c;
      iVar3 = (*DAT_0019f754)(&local_10);
      if (iVar3 == -3) {
        local_1c = local_8;
      }
      else {
        local_20 = local_8;
      }
    }
  }
  local_18 = local_18 - (float)param_1[2];
  if (local_18 < 8.0) {
    local_24 = (float)param_2[2];
    local_28 = local_24 + 256.0;
    local_10 = *param_2;
    local_c = param_2[1];
    local_8 = local_24;
    iVar3 = (*DAT_0019f754)(&local_10);
    fVar1 = local_24;
    if ((iVar3 == -3) &&
       (local_8 = local_28, iVar3 = (*DAT_0019f754)(&local_10), fVar1 = local_28, iVar3 != -3)) {
      while (fVar2 = local_28 - local_24, fVar1 = local_8,
            (byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) == 1) {
        local_8 = fVar2 * 0.5 + local_24;
        iVar3 = (*DAT_0019f754)(&local_10);
        if (iVar3 == -3) {
          local_24 = local_8;
        }
        else {
          local_28 = local_8;
        }
      }
    }
    fVar1 = fVar1 - (float)param_2[2];
    if ((byte)(fVar1 < 8.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 8.0) << 0xe) >> 8)) == 1) {
      return;
    }
    local_18 = ((float)param_2[2] + fVar1) - (float)param_1[2];
  }
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  (*DAT_0019f758)(0,0x17,0,0);
  (*DAT_0019f760)(0x72);
  (*DAT_0019f774)(*param_1);
  (*DAT_0019f774)(param_1[1]);
  (*DAT_0019f774)(param_1[2]);
  (*DAT_0019f774)(*param_2);
  (*DAT_0019f774)(param_2[1]);
  (*DAT_0019f774)(param_2[2]);
  (*DAT_0019f774)(local_18);
  (*DAT_0019f768)((int)g_sModelIndexBubbles);
  (*DAT_0019f760)(param_3);
  (*DAT_0019f774)(0x41000000);
  (*DAT_0019f75c)();
  return;
}


// UTIL_Bubbles__FG6VectorT0i  @ 0011eb90
void UTIL_Bubbles__FG6VectorT0i(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_38;
  float local_34;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_1c = *param_1 + *param_2;
  local_18 = param_1[1] + param_2[1];
  local_14 = param_1[2] + param_2[2];
  local_28 = local_1c * 0.5;
  local_24 = local_18 * 0.5;
  local_34 = local_14 * 0.5;
  local_38 = local_34 + 1024.0;
  local_20 = local_34;
  local_10 = local_28;
  local_c = local_24;
  local_8 = local_34;
  iVar3 = (*DAT_0019f754)(&local_28);
  fVar2 = local_34;
  if ((iVar3 == -3) &&
     (local_20 = local_38, iVar3 = (*DAT_0019f754)(&local_28), fVar2 = local_38, iVar3 != -3)) {
    while (fVar1 = local_38 - local_34, fVar2 = local_20,
          (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) {
      local_20 = fVar1 * 0.5 + local_34;
      iVar3 = (*DAT_0019f754)(&local_28);
      if (iVar3 == -3) {
        local_34 = local_20;
      }
      else {
        local_38 = local_20;
      }
    }
  }
  fVar1 = param_1[2];
  (*DAT_0019f758)(5,0x17,&local_10,0);
  (*DAT_0019f760)(0x71);
  (*DAT_0019f774)(*param_1);
  (*DAT_0019f774)(param_1[1]);
  (*DAT_0019f774)(param_1[2]);
  (*DAT_0019f774)(*param_2);
  (*DAT_0019f774)(param_2[1]);
  (*DAT_0019f774)(param_2[2]);
  (*DAT_0019f774)(fVar2 - fVar1);
  (*DAT_0019f768)((int)g_sModelIndexBubbles);
  (*DAT_0019f760)(param_3);
  (*DAT_0019f774)(0x41000000);
  (*DAT_0019f75c)();
  return;
}


// UTIL_ClampVectorToBox__FRC6VectorT0  @ 0011ea58
float * UTIL_ClampVectorToBox__FRC6VectorT0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  fVar1 = *param_3;
  if (local_10 <= fVar1) {
    fVar2 = -fVar1;
    if ((byte)((fVar2 < local_10 |
                (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_10)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == local_10) << 0xe) >> 8)) - 1) < 0x40) {
      local_10 = 0.0;
    }
    else {
      local_10 = fVar1 + local_10;
    }
  }
  else {
    local_10 = local_10 - fVar1;
  }
  fVar1 = param_3[1];
  if (local_c <= fVar1) {
    fVar2 = -fVar1;
    if ((byte)((fVar2 < local_c | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_c)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_c) << 0xe) >> 8)) - 1) < 0x40) {
      local_c = 0.0;
    }
    else {
      local_c = fVar1 + local_c;
    }
  }
  else {
    local_c = local_c - fVar1;
  }
  fVar1 = param_3[2];
  if (local_8 <= fVar1) {
    fVar2 = -fVar1;
    if ((byte)((fVar2 < local_8 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_8)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar2 == local_8) << 0xe) >> 8)) - 1) < 0x40) {
      local_8 = 0.0;
    }
    else {
      local_8 = fVar1 + local_8;
    }
  }
  else {
    local_8 = local_8 - fVar1;
  }
  fVar1 = SQRT(local_8 * local_8 + local_c * local_c + local_10 * local_10);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 1.0;
  }
  else {
    fVar1 = 1.0 / fVar1;
    *param_1 = local_10 * fVar1;
    param_1[1] = local_c * fVar1;
    param_1[2] = fVar1 * local_8;
  }
  return param_1;
}


// UTIL_ClientPrintAll__FiPCcN41  @ 0012251c
void UTIL_ClientPrintAll__FiPCcN41(void)

{
  FUN_00122527();
  return;
}


// UTIL_ClientProjectile__FRC6VectorT0sii  @ 0011f100
void UTIL_ClientProjectile__FRC6VectorT0sii
               (float *param_1,float *param_2,short param_3,uint param_4,undefined4 param_5)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [20];
  undefined1 local_28 [36];
  
  local_54 = *param_2;
  local_50 = param_2[1];
  fVar1 = param_2[2];
  local_4c = SQRT(fVar1 * fVar1 + local_50 * local_50 + local_54 * local_54);
  if ((byte)((byte)((ushort)((ushort)NAN(local_4c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_4c == 0.0) << 0xe) >> 8)) == 0x40) {
    local_54 = 0.0;
    local_50 = 0.0;
    local_4c = 1.0;
  }
  else {
    local_4c = 1.0 / local_4c;
    local_54 = local_54 * local_4c;
    local_50 = local_50 * local_4c;
    local_4c = local_4c * fVar1;
  }
  local_48 = local_54;
  local_44 = local_50;
  local_40 = local_4c;
  local_58 = local_54 * 4096.0 + *param_1;
  local_54 = local_50 * 4096.0 + param_1[1];
  local_50 = local_4c * 4096.0 + param_1[2];
  uVar2 = (*DAT_0019f7b4)(param_4);
  (*DAT_0019f71c)(param_1,&local_58,1,uVar2,local_3c);
  iVar3 = (*DAT_0019f754)(param_1);
  puVar5 = local_28;
  iVar4 = (*DAT_0019f754)(puVar5);
  if (iVar3 == iVar4) {
    uVar2 = 4;
  }
  else {
    puVar5 = (undefined1 *)0x0;
    uVar2 = 0;
  }
  (*DAT_0019f758)(uVar2,0x17,puVar5,0);
  (*DAT_0019f760)(0x77);
  (*DAT_0019f774)(*param_1);
  (*DAT_0019f774)(param_1[1]);
  (*DAT_0019f774)(param_1[2]);
  (*DAT_0019f774)(*param_2);
  (*DAT_0019f774)(param_2[1]);
  (*DAT_0019f774)(param_2[2]);
  (*DAT_0019f768)((int)param_3);
  (*DAT_0019f760)(param_5);
  (*DAT_0019f760)(param_4 & 0xff);
  (*DAT_0019f75c)();
  return;
}


// UTIL_DecalTrace__FP11TraceResulti  @ 0011e7b4
void UTIL_DecalTrace__FP11TraceResulti(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  short local_6;
  
  if (param_2 < 0) {
    return;
  }
  iVar4 = (&DAT_00172864)[param_2 * 2];
  if (iVar4 < 0) {
    return;
  }
  fVar1 = *(float *)(param_1 + 0x10);
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    local_6 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x7c);
    if ((iVar2 != 0) && (iVar2 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x90))(iVar2), iVar2 == 0))
    {
      return;
    }
    local_6 = (*DAT_0019f7bc)(*(undefined4 *)(param_1 + 0x30));
  }
  uVar3 = 0x68;
  if (local_6 == 0) {
    uVar3 = 0x74;
    if (iVar4 < 0x100) goto LAB_0011e888;
    uVar3 = 0x75;
  }
  else {
    if (iVar4 < 0x100) goto LAB_0011e888;
    uVar3 = 0x76;
  }
  iVar4 = iVar4 + -0x100;
LAB_0011e888:
  (*DAT_0019f758)(0,0x17,0,0);
  (*DAT_0019f760)(uVar3);
  (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x14));
  (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x18));
  (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x1c));
  (*DAT_0019f760)(iVar4);
  if (local_6 != 0) {
    (*DAT_0019f768)((int)local_6);
  }
  (*DAT_0019f75c)();
  return;
}


// UTIL_DotPoints__FRC6VectorN20  @ 0011f498
longdouble UTIL_DotPoints__FRC6VectorN20(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float local_28;
  
  local_28 = *param_2 - *param_1;
  fVar1 = param_2[1] - param_1[1];
  fVar2 = SQRT(fVar1 * fVar1 + local_28 * local_28);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = 0.0;
    local_28 = 0.0;
  }
  else {
    local_28 = local_28 * (1.0 / fVar2);
    fVar1 = (1.0 / fVar2) * fVar1;
  }
  return (longdouble)fVar1 * (longdouble)param_3[1] + (longdouble)local_28 * (longdouble)*param_3;
}


// UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii  @ 00122930
void UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
               (undefined4 param_1,undefined4 *param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  char *pcVar2;
  char local_30 [32];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  pcVar2 = param_3;
  if ((param_3 != (char *)0x0) && (*param_3 == '!')) {
    pcVar2 = local_30;
    iVar1 = SENTENCEG_Lookup__FPCcPc(param_3,pcVar2);
    if (iVar1 < 0) {
      return;
    }
  }
  (*DAT_0019f718)(param_1,&local_10,pcVar2,param_4,param_5,param_6,param_7);
  return;
}


// UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i  @ 00122d68
int UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i
              (int param_1,int param_2,float *param_3,float *param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  piVar3 = (int *)(*DAT_0019f7c0)(1);
  iVar6 = 0;
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    local_8 = 1;
    if (1 < *(int *)(gpGlobals + 0x94)) {
      do {
        if ((*piVar3 == 0) && ((param_5 == 0 || ((piVar3[0x89] & param_5) != 0)))) {
          fVar1 = (float)piVar3[0x54];
          fVar2 = *param_3;
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            fVar1 = (float)piVar3[0x55];
            fVar2 = param_3[1];
            if ((byte)(fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
              fVar1 = (float)piVar3[0x56];
              fVar2 = param_3[2];
              if (((((byte)(fVar1 < fVar2 |
                            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
                   ((float)piVar3[0x51] <= *param_4)) && ((float)piVar3[0x52] <= param_4[1])) &&
                 ((float)piVar3[0x53] <= param_4[2])) {
                piVar4 = piVar3;
                if ((piVar3 == (int *)0x0) &&
                   (piVar4 = (int *)(*DAT_0019f7b4)(0), piVar4 == (int *)0x0)) {
                  iVar5 = 0;
                }
                else {
                  iVar5 = piVar4[0x1f];
                }
                if (iVar5 != 0) {
                  *(int *)(param_1 + iVar6 * 4) = iVar5;
                  iVar6 = iVar6 + 1;
                  if (param_2 <= iVar6) {
                    return iVar6;
                  }
                }
              }
            }
          }
        }
        local_8 = local_8 + 1;
        piVar3 = piVar3 + 0xc9;
      } while (local_8 < *(int *)(gpGlobals + 0x94));
    }
  }
  return iVar6;
}


// UTIL_FindEntityByClassname__FP11CBaseEntityPCc  @ 00122bb0
undefined4 UTIL_FindEntityByClassname__FP11CBaseEntityPCc(int *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (int *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(*param_1 + 0x208);
  }
  iVar2 = (*DAT_0019f6d8)(uVar4,"classname",param_2);
  bVar1 = false;
  if (iVar2 == 0) {
LAB_00122c10:
    bVar1 = true;
  }
  else {
    iVar3 = (*DAT_0019f7b8)(iVar2);
    if (iVar3 == 0) goto LAB_00122c10;
  }
  if (bVar1) {
LAB_00122c38:
    uVar4 = 0;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (*DAT_0019f7b4)(0);
      if (iVar2 == 0) goto LAB_00122c38;
    }
    uVar4 = *(undefined4 *)(iVar2 + 0x7c);
  }
  return uVar4;
}


// UTIL_FindEntityByString__FP11CBaseEntityPCcT1  @ 00122c44
undefined4
UTIL_FindEntityByString__FP11CBaseEntityPCcT1(int *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (int *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(*param_1 + 0x208);
  }
  iVar2 = (*DAT_0019f6d8)(uVar4,param_2,param_3);
  bVar1 = false;
  if (iVar2 == 0) {
LAB_00122c9f:
    bVar1 = true;
  }
  else {
    iVar3 = (*DAT_0019f7b8)(iVar2);
    if (iVar3 == 0) goto LAB_00122c9f;
  }
  if (bVar1) {
LAB_00122cc8:
    uVar4 = 0;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (*DAT_0019f7b4)(0);
      if (iVar2 == 0) goto LAB_00122cc8;
    }
    uVar4 = *(undefined4 *)(iVar2 + 0x7c);
  }
  return uVar4;
}


// UTIL_FindEntityByTargetname__FP11CBaseEntityPCc  @ 00122b1c
void UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(void)

{
  FUN_00122b27();
  return;
}


// UTIL_FindEntityGeneric__FPCcR6Vectorf  @ 0011d85c
int * UTIL_FindEntityGeneric__FPCcR6Vectorf(undefined4 param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  float fStack_1c;
  int *piStack_18;
  
  iVar5 = (*DAT_0019f6d8)(0,"targetname",param_1);
  bVar4 = false;
  if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
    bVar4 = true;
  }
  if ((bVar4) || ((iVar5 == 0 && (iVar5 = (*DAT_0019f7b4)(0), iVar5 == 0)))) {
    piStack_18 = (int *)0x0;
  }
  else {
    piStack_18 = *(int **)(iVar5 + 0x7c);
  }
  if (piStack_18 == (int *)0x0) {
    piVar7 = (int *)0x0;
    fStack_1c = param_3 * param_3;
    while( true ) {
      if (piVar7 == (int *)0x0) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(undefined4 *)(*piVar7 + 0x208);
      }
      iVar5 = (*DAT_0019f6d8)(uVar8,"classname",param_1);
      bVar4 = false;
      if ((iVar5 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar5), iVar6 == 0)) {
        bVar4 = true;
      }
      if ((bVar4) || ((iVar5 == 0 && (iVar5 = (*DAT_0019f7b4)(0), iVar5 == 0)))) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = *(int **)(iVar5 + 0x7c);
      }
      if (piVar7 == (int *)0x0) break;
      fVar1 = *(float *)(*piVar7 + 8) - *param_2;
      fVar3 = *(float *)(*piVar7 + 0xc) - param_2[1];
      fVar2 = *(float *)(*piVar7 + 0x10) - param_2[2];
      fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
      fVar1 = fVar1 * fVar1;
      if (fVar1 < fStack_1c) {
        fStack_1c = fVar1;
        piStack_18 = piVar7;
      }
    }
  }
  return piStack_18;
}


// UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf  @ 00122cd4
void UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf(void)

{
  FUN_00122cdf();
  return;
}


// UTIL_GetAimVector__FP7edict_sf  @ 00121f54
undefined4 *
UTIL_GetAimVector__FP7edict_sf(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (*DAT_0019f738)(param_2,param_3,&local_10);
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = local_8;
  return param_1;
}


// UTIL_GetGlobalTrace__Fv  @ 0011dfe0
int * UTIL_GetGlobalTrace__Fv(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  fVar1 = *(float *)(gpGlobals + 0x50);
  fVar2 = *(float *)(gpGlobals + 0x78);
  fVar3 = *(float *)(gpGlobals + 0x7c);
  iVar4 = *(int *)(gpGlobals + 0x54);
  iVar5 = *(int *)(gpGlobals + 0x70);
  iVar6 = *(int *)(gpGlobals + 0x74);
  iVar7 = *(int *)(gpGlobals + 0x58);
  iVar8 = *(int *)(gpGlobals + 0x5c);
  iVar9 = *(int *)(gpGlobals + 0x60);
  iVar10 = *(int *)(gpGlobals + 100);
  iVar11 = *(int *)(gpGlobals + 0x68);
  iVar12 = *(int *)(gpGlobals + 0x6c);
  iVar13 = *(int *)(gpGlobals + 0x80);
  *param_1 = (int)ROUND(*(float *)(gpGlobals + 0x4c));
  param_1[1] = (int)ROUND(fVar1);
  param_1[2] = (int)ROUND(fVar2);
  param_1[3] = (int)ROUND(fVar3);
  param_1[4] = iVar4;
  param_1[5] = iVar7;
  param_1[6] = iVar8;
  param_1[7] = iVar9;
  param_1[8] = iVar5;
  param_1[9] = iVar10;
  param_1[10] = iVar11;
  param_1[0xb] = iVar12;
  param_1[0xc] = iVar6;
  param_1[0xd] = iVar13;
  return param_1;
}


// UTIL_GetNextBestWeapon__FP11CBasePlayerP15CBasePlayerItem  @ 00123080
void UTIL_GetNextBestWeapon__FP11CBasePlayerP15CBasePlayerItem
               (undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*g_pGameRules + 0x1c))(g_pGameRules,param_1,param_2);
  return;
}


// UTIL_GunshotDecalTrace__FP11TraceResulti  @ 0011e948
void UTIL_GunshotDecalTrace__FP11TraceResulti(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  short sVar3;
  
  if (((-1 < param_2) && (iVar2 = (&DAT_00172864)[param_2 * 2], -1 < iVar2)) &&
     (fVar1 = *(float *)(param_1 + 0x10),
     (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) {
    (*DAT_0019f758)(5,0x17,param_1 + 0x14,0);
    (*DAT_0019f760)(0x6d);
    (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x14));
    (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x18));
    (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x1c));
    sVar3 = (*DAT_0019f7bc)(*(undefined4 *)(param_1 + 0x30));
    (*DAT_0019f768)((int)sVar3);
    (*DAT_0019f760)(iVar2);
    (*DAT_0019f75c)();
  }
  return;
}


// UTIL_IsMasterTriggered__Fi  @ 0011e338
undefined4 UTIL_IsMasterTriggered__Fi(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  if (param_1 != 0) {
    iVar2 = (*DAT_0019f6d8)(0,"targetname",param_1 + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      piVar5 = (int *)(iVar2 + 0x80);
      if (iVar2 == 0) {
        piVar5 = (int *)0x0;
      }
      iVar3 = strcmp((char *)(*piVar5 + *(int *)(gpGlobals + 0x98)),"multisource");
      if (iVar3 == 0) {
        if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar2 + 0x7c);
        }
        if (iVar2 != 0) {
          uVar4 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x4c))(iVar2);
          return uVar4;
        }
      }
    }
    (*DAT_0019f794)(1,"Master was null or not a MultiSource!\n");
  }
  return 1;
}


// UTIL_IsValidEntity__FP7edict_s  @ 001217b4
undefined4 UTIL_IsValidEntity__FP7edict_s(int *param_1)

{
  undefined4 uVar1;
  
  if (((param_1 == (int *)0x0) || (*param_1 != 0)) ||
     ((*(byte *)((int)param_1 + 0x227) & 0x40) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// UTIL_LogPrintf__FPce  @ 0011f450
void UTIL_LogPrintf__FPce(char *param_1)

{
  vsprintf(string_803,param_1,&stack0x00000008);
  (*DAT_0019f794)(5,&DAT_00158ee0,string_803);
  return;
}


// UTIL_MakeAimVectors__FRC6Vector  @ 00122a40
void UTIL_MakeAimVectors__FRC6Vector(float *param_1)

{
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = -*param_1;
  local_c = param_1[1];
  local_8 = param_1[2];
  (*DAT_0019f6ec)(&local_10);
  return;
}


// UTIL_MakeInvVectors__FRC6VectorP12globalvars_t  @ 001229bc
void UTIL_MakeInvVectors__FRC6VectorP12globalvars_t(void)

{
  FUN_001229c9();
  return;
}


// UTIL_MakeVectors__FRC6Vector  @ 00122a84
void UTIL_MakeVectors__FRC6Vector(undefined4 param_1)

{
  (*DAT_0019f6ec)(param_1);
  return;
}


// UTIL_MonstersInSphere__FPP11CBaseEntityiRC6Vectorf  @ 0011d71c
int UTIL_MonstersInSphere__FPP11CBaseEntityiRC6Vectorf
              (int param_1,int param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_c;
  
  piVar3 = (int *)(*DAT_0019f7c0)(1);
  iVar6 = 0;
  param_4 = param_4 * param_4;
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    local_c = 1;
    if (1 < *(int *)(gpGlobals + 0x94)) {
      do {
        if ((((*piVar3 == 0) && ((*(byte *)(piVar3 + 0x89) & 0x28) != 0)) &&
            (fVar2 = (*param_3 - (float)piVar3[0x22]) * (*param_3 - (float)piVar3[0x22]),
            fVar2 <= param_4)) &&
           ((fVar2 = (param_3[1] - (float)piVar3[0x23]) * (param_3[1] - (float)piVar3[0x23]) + fVar2
            , fVar2 <= param_4 &&
            (fVar1 = param_3[2] - ((float)piVar3[0x53] + (float)piVar3[0x56]) * 0.5,
            fVar1 * fVar1 + fVar2 <= param_4)))) {
          piVar4 = piVar3;
          if ((piVar3 == (int *)0x0) && (piVar4 = (int *)(*DAT_0019f7b4)(0), piVar4 == (int *)0x0))
          {
            iVar5 = 0;
          }
          else {
            iVar5 = piVar4[0x1f];
          }
          if (iVar5 != 0) {
            *(int *)(param_1 + iVar6 * 4) = iVar5;
            iVar6 = iVar6 + 1;
            if (param_2 <= iVar6) {
              return iVar6;
            }
          }
        }
        local_c = local_c + 1;
        piVar3 = piVar3 + 0xc9;
      } while (local_c < *(int *)(gpGlobals + 0x94));
    }
  }
  return iVar6;
}


// UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi  @ 00122ec4
void UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_10 = *param_2;
  uStack_c = param_2[1];
  uStack_8 = param_2[2];
  (*pcRam0019f6cc)(param_1,&uStack_10,param_3,param_4);
  return;
}


// UTIL_ParametricRocket__FP9entvars_sG6VectorT1P7edict_s  @ 00102734
void UTIL_ParametricRocket__FP9entvars_sG6VectorT1P7edict_s
               (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [20];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  *(undefined4 *)(param_1 + 0x8c) = *param_2;
  *(undefined4 *)(param_1 + 0x90) = param_2[1];
  *(undefined4 *)(param_1 + 0x94) = param_2[2];
  UTIL_MakeVectors__FRC6Vector(param_3);
  local_48 = gpGlobals[10] * 8192.0 + *(float *)(param_1 + 0x8c);
  local_44 = gpGlobals[0xb] * 8192.0 + *(float *)(param_1 + 0x90);
  local_40 = gpGlobals[0xc] * 8192.0 + *(float *)(param_1 + 0x94);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_1 + 0x8c,&local_48,1,param_4,local_3c);
  *(undefined4 *)(param_1 + 0x80) = local_28;
  *(undefined4 *)(param_1 + 0x84) = local_24;
  fVar1 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0x8c);
  *(undefined4 *)(param_1 + 0x88) = local_20;
  fVar3 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0x90);
  fVar2 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0x94);
  fVar4 = *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x28) +
          *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x24) +
          *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x20);
  fVar5 = SQRT(fVar4);
  if ((byte)((fVar5 < 0.0 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) / SQRT(fVar4);
  }
  *(float *)(param_1 + 0x9c) = *gpGlobals;
  *(float *)(param_1 + 0x98) = *gpGlobals + fVar1;
  return;
}


// UTIL_ParticleBox__FP11CBasePlayerPfT1fUcUcUc  @ 00120784
void UTIL_ParticleBox__FP11CBasePlayerPfT1fUcUcUc
               (int *param_1,undefined4 *param_2,undefined4 *param_3,float param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  (*DAT_0019f758)(8,0x17,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(0x1f);
  (*DAT_0019f774)(*param_2);
  (*DAT_0019f774)(param_2[1]);
  (*DAT_0019f774)(param_2[2]);
  (*DAT_0019f774)(*param_3);
  (*DAT_0019f774)(param_3[1]);
  (*DAT_0019f774)(param_3[2]);
  (*DAT_0019f768)((int)ROUND((double)(int)(short)(int)ROUND(param_4) * 10.0));
  (*DAT_0019f760)(param_5);
  (*DAT_0019f760)(param_6);
  (*DAT_0019f760)(param_7);
  (*DAT_0019f75c)();
  return;
}


// UTIL_ParticleEffect__FRC6VectorT0UlUl  @ 00122078
void UTIL_ParticleEffect__FRC6VectorT0UlUl
               (undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  (*DAT_0019f748)(param_1,param_2,(float)param_3,(float)param_4);
  return;
}


// UTIL_ParticleLine__FP11CBasePlayerPfT1fUcUcUc  @ 00120914
void UTIL_ParticleLine__FP11CBasePlayerPfT1fUcUcUc(void)

{
  FUN_00120922();
  return;
}


// UTIL_PlayerByIndex__Fi  @ 00122aac
undefined4 UTIL_PlayerByIndex__Fi(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((0 < param_1) && (param_1 <= *(int *)(gpGlobals + 0x90))) &&
     (iVar1 = (*DAT_0019f7c0)(param_1), iVar1 != 0)) {
    if (*(char *)(*(int *)(iVar1 + 0x250) + *(int *)(gpGlobals + 0x98)) == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0x7c);
    }
  }
  return uVar2;
}


// UTIL_PlayerDecalTrace__FP11TraceResultiii  @ 00121c44
void UTIL_PlayerDecalTrace__FP11TraceResultiii
               (int param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  short sVar2;
  
  if (((param_4 != 0) || ((-1 < param_3 && (param_3 = (&DAT_00172864)[param_3 * 2], -1 < param_3))))
     && (fVar1 = *(float *)(param_1 + 0x10),
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) {
    (*DAT_0019f758)(0,0x17,0,0);
    (*DAT_0019f760)(0x70);
    (*DAT_0019f760)(param_2);
    (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x14));
    (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x18));
    (*DAT_0019f774)(*(undefined4 *)(param_1 + 0x1c));
    sVar2 = (*DAT_0019f7bc)(*(undefined4 *)(param_1 + 0x30));
    (*DAT_0019f768)((int)sVar2);
    (*DAT_0019f760)(param_3);
    (*DAT_0019f75c)();
  }
  return;
}


// UTIL_PointContents__FRC6Vector  @ 00121ebc
void UTIL_PointContents__FRC6Vector(undefined4 param_1)

{
  (*DAT_0019f754)(param_1);
  return;
}


// UTIL_PrecacheOtherWeapon__FPCc  @ 001235a8
void UTIL_PrecacheOtherWeapon__FPCc(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_30 [2];
  char *local_28;
  char *local_20;
  int local_10;
  
  iVar2 = (*DAT_0019f6fc)(param_1 - *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    (*DAT_0019f794)(1,"NULL Ent in UTIL_PrecacheOtherWeapon\n");
    return;
  }
  iVar3 = iVar2 + 0x80;
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  iVar3 = *(int *)(iVar3 + 0x208);
  if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar3 + 0x7c);
  }
  if (iVar3 != 0) {
    (**(code **)(*(int *)(iVar3 + 0x454) + 0x10))(iVar3);
    memset(local_30,0,0x2c);
    iVar3 = (**(code **)(*(int *)(iVar3 + 0x454) + 0x118))(iVar3,local_30);
    if (iVar3 != 0) {
      puVar5 = local_30;
      puVar6 = (undefined4 *)(_15CBasePlayerItem_ItemInfoArray + local_10 * 0x2c);
      for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      if ((local_28 != (char *)0x0) && (*local_28 != '\0')) {
        iVar3 = 0;
        do {
          if (((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar3 * 2] != (char *)0x0) &&
             (iVar4 = strcasecmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar3 * 2],local_28),
             iVar4 == 0)) goto LAB_00123732;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x20);
        giAmmoIndex = giAmmoIndex + 1;
        if (0x1f < giAmmoIndex) {
          giAmmoIndex = 0;
        }
        (&_15CBasePlayerItem_AmmoInfoArray)[giAmmoIndex * 2] = local_28;
        (&DAT_001acde4)[giAmmoIndex * 2] = giAmmoIndex;
      }
LAB_00123732:
      if ((local_20 != (char *)0x0) && (*local_20 != '\0')) {
        iVar3 = 0;
        do {
          if (((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar3 * 2] != (char *)0x0) &&
             (iVar4 = strcasecmp((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar3 * 2],local_20),
             iVar4 == 0)) goto LAB_001237a2;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x20);
        giAmmoIndex = giAmmoIndex + 1;
        if (0x1f < giAmmoIndex) {
          giAmmoIndex = 0;
        }
        (&_15CBasePlayerItem_AmmoInfoArray)[giAmmoIndex * 2] = local_20;
        (&DAT_001acde4)[giAmmoIndex * 2] = giAmmoIndex;
      }
LAB_001237a2:
      memset(local_30,0,0x2c);
    }
  }
  (*DAT_0019f6f8)(iVar2);
  return;
}


// UTIL_PrecacheOther__FPCc  @ 0011f378
void UTIL_PrecacheOther__FPCc(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (*DAT_0019f6fc)(param_1 - *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    iVar3 = *(int *)(iVar3 + 0x208);
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x454) + 0x10))(iVar3);
    }
    (*DAT_0019f6f8)(iVar2);
    return;
  }
  (*DAT_0019f794)(1,"NULL Ent in UTIL_PrecacheOther\n");
  return;
}


// UTIL_RandomBloodVector__Fv  @ 00121e3c
float * UTIL_RandomBloodVector__Fv(float *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  lVar1 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
  lVar2 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
  lVar3 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
  *param_1 = (float)lVar1;
  param_1[1] = (float)lVar2;
  param_1[2] = (float)lVar3;
  return param_1;
}


// UTIL_Remove__FP11CBaseEntity  @ 001217dc
void UTIL_Remove__FP11CBaseEntity(int *param_1)

{
  if (param_1 != (int *)0x0) {
    UpdateOnRemove__11CBaseEntity(param_1);
    *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x40;
    *(undefined4 *)(*param_1 + 0x1cc) = 0;
  }
  return;
}


// UTIL_Ricochet__FRC6Vectorf  @ 00121ae0
void UTIL_Ricochet__FRC6Vectorf(undefined4 *param_1,float param_2)

{
  (*DAT_0019f758)(4,0x17,param_1,0);
  (*DAT_0019f760)(0x6f);
  (*DAT_0019f774)(*param_1);
  (*DAT_0019f774)(param_1[1]);
  (*DAT_0019f774)(param_1[2]);
  (*DAT_0019f760)((int)ROUND(param_2 * 10.0));
  (*DAT_0019f75c)();
  return;
}


// UTIL_ScreenFadeAll__FRC6Vectorffii  @ 0011dc00
void UTIL_ScreenFadeAll__FRC6Vectorffii
               (float *param_1,float param_2,float param_3,undefined1 param_4,short param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  
  uVar4 = (uint)ROUND(param_2 * 4096.0);
  if ((int)uVar4 < 0) {
    uVar4 = 0;
  }
  if (0xffff < (int)uVar4) {
    uVar4 = 0xffff;
  }
  uVar5 = (uint)ROUND(param_3 * 4096.0);
  if ((int)uVar5 < 0) {
    uVar5 = 0;
  }
  if (0xffff < (int)uVar5) {
    uVar5 = 0xffff;
  }
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  piVar6 = (int *)(*DAT_0019f7c0)(1);
  if (piVar6 != (int *)0x0) {
    iVar7 = 0;
    if (0 < *(int *)(gpGlobals + 0x90)) {
      do {
        if ((*piVar6 == 0) && ((*(byte *)(piVar6 + 0x89) & 8) != 0)) {
          (*DAT_0019f758)(1,gmsgFade,0,piVar6);
          (*DAT_0019f768)(uVar4 & 0xffff);
          (*DAT_0019f768)(uVar5 & 0xffff);
          (*DAT_0019f768)((int)param_5);
          (*DAT_0019f760)((int)ROUND(fVar1) & 0xff);
          (*DAT_0019f760)((int)ROUND(fVar2) & 0xff);
          (*DAT_0019f760)((int)ROUND(fVar3) & 0xff);
          (*DAT_0019f760)(param_4);
          (*DAT_0019f75c)();
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 0xc9;
      } while (iVar7 < *(int *)(gpGlobals + 0x90));
    }
  }
  return;
}


// UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii  @ 001226d4
void UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii
               (undefined2 *param_1,float *param_2,float param_3,float param_4,undefined1 param_5,
               undefined2 param_6)

{
  int iVar1;
  
  iVar1 = (int)ROUND(param_3 * 4096.0);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (0xffff < iVar1) {
    iVar1 = 0xffff;
  }
  *param_1 = (short)iVar1;
  iVar1 = (int)ROUND(param_4 * 4096.0);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (0xffff < iVar1) {
    iVar1 = 0xffff;
  }
  param_1[1] = (short)iVar1;
  *(char *)(param_1 + 3) = (char)(int)ROUND(*param_2);
  *(char *)((int)param_1 + 7) = (char)(int)ROUND(param_2[1]);
  *(char *)(param_1 + 4) = (char)(int)ROUND(param_2[2]);
  *(undefined1 *)((int)param_1 + 9) = param_5;
  param_1[2] = param_6;
  return;
}


// UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s  @ 001225f8
void UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s(undefined2 *param_1,undefined4 param_2)

{
  (*DAT_0019f758)(1,gmsgFade,0,param_2);
  (*DAT_0019f768)(*param_1);
  (*DAT_0019f768)(param_1[1]);
  (*DAT_0019f768)((int)(short)param_1[2]);
  (*DAT_0019f760)(*(undefined1 *)(param_1 + 3));
  (*DAT_0019f760)(*(undefined1 *)((int)param_1 + 7));
  (*DAT_0019f760)(*(undefined1 *)(param_1 + 4));
  (*DAT_0019f760)(*(undefined1 *)((int)param_1 + 9));
  (*DAT_0019f75c)();
  return;
}


// UTIL_ScreenFade__FP7edict_sRC6Vectorffii  @ 0011de10
void UTIL_ScreenFade__FP7edict_sRC6Vectorffii
               (int *param_1,float *param_2,float param_3,float param_4,undefined1 param_5,
               short param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  
  if (((param_1 != (int *)0x0) && (*param_1 == 0)) && ((*(byte *)(param_1 + 0x89) & 8) != 0)) {
    uVar4 = (uint)ROUND(param_3 * 4096.0);
    if ((int)uVar4 < 0) {
      uVar4 = 0;
    }
    if (0xffff < (int)uVar4) {
      uVar4 = 0xffff;
    }
    uVar5 = (uint)ROUND(param_4 * 4096.0);
    if ((int)uVar5 < 0) {
      uVar5 = 0;
    }
    if (0xffff < (int)uVar5) {
      uVar5 = 0xffff;
    }
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    (*DAT_0019f758)(1,gmsgFade,0,param_1);
    (*DAT_0019f768)(uVar4 & 0xffff);
    (*DAT_0019f768)(uVar5 & 0xffff);
    (*DAT_0019f768)((int)param_6);
    (*DAT_0019f760)((int)ROUND(fVar1) & 0xff);
    (*DAT_0019f760)((int)ROUND(fVar2) & 0xff);
    (*DAT_0019f760)((int)ROUND(fVar3) & 0xff);
    (*DAT_0019f760)(param_5);
    (*DAT_0019f75c)();
  }
  return;
}


// UTIL_ScreenShakeAll__FRC6Vectorfff  @ 001227c4
void UTIL_ScreenShakeAll__FRC6Vectorfff
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  UTIL_ScreenShake__FRC6Vectorffff(param_1,param_2,param_3,param_4,0);
  return;
}


// UTIL_ScreenShakeOne__FP7edict_sfff  @ 00122804
void UTIL_ScreenShakeOne__FP7edict_sfff
               (undefined4 param_1,float param_2,float param_3,float param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (uint)ROUND(param_4 * 4096.0);
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  if (0xffff < (int)uVar1) {
    uVar1 = 0xffff;
  }
  uVar2 = (uint)ROUND(param_3 * 256.0);
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  if (0xffff < (int)uVar2) {
    uVar2 = 0xffff;
  }
  uVar3 = (uint)ROUND(param_2 * 4096.0);
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  if (0xffff < (int)uVar3) {
    uVar3 = 0xffff;
  }
  (*DAT_0019f758)(1,gmsgShake,0,param_1);
  (*DAT_0019f768)(uVar3 & 0xffff);
  (*DAT_0019f768)(uVar1 & 0xffff);
  (*DAT_0019f768)(uVar2 & 0xffff);
  (*DAT_0019f75c)();
  return;
}


// UTIL_ScreenShake__FRC6Vectorffff  @ 0011d9e0
void UTIL_ScreenShake__FRC6Vectorffff
               (float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = (uint)ROUND(param_4 * 4096.0);
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  if (0xffff < (int)uVar3) {
    uVar3 = 0xffff;
  }
  uVar4 = (uint)ROUND(param_3 * 256.0);
  if ((int)uVar4 < 0) {
    uVar4 = 0;
  }
  if (0xffff < (int)uVar4) {
    uVar4 = 0xffff;
  }
  piVar2 = (int *)(*DAT_0019f7c0)(1);
  if ((piVar2 != (int *)0x0) && (iVar6 = 0, 0 < *(int *)(gpGlobals + 0x90))) {
    do {
      if ((*piVar2 == 0) && (((piVar2[0x89] & 8U) != 0 && ((piVar2[0x89] & 0x200U) != 0)))) {
        if ((param_5 <= 0.0) ||
           (fVar1 = 0.0,
           SQRT((param_1[2] - (float)piVar2[0x24]) * (param_1[2] - (float)piVar2[0x24]) +
                (param_1[1] - (float)piVar2[0x23]) * (param_1[1] - (float)piVar2[0x23]) +
                (*param_1 - (float)piVar2[0x22]) * (*param_1 - (float)piVar2[0x22])) < param_5)) {
          fVar1 = param_2;
        }
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          uVar5 = (uint)ROUND(fVar1 * 4096.0);
          if ((int)uVar5 < 0) {
            uVar5 = 0;
          }
          if (0xffff < (int)uVar5) {
            uVar5 = 0xffff;
          }
          (*DAT_0019f758)(1,gmsgShake,0,piVar2);
          (*DAT_0019f768)(uVar5 & 0xffff);
          (*DAT_0019f768)(uVar3 & 0xffff);
          (*DAT_0019f768)(uVar4 & 0xffff);
          (*DAT_0019f75c)();
        }
      }
      iVar6 = iVar6 + 1;
      piVar2 = piVar2 + 0xc9;
    } while (iVar6 < *(int *)(gpGlobals + 0x90));
  }
  return;
}


// UTIL_SetGroupTrace__Fii  @ 001231c0
void UTIL_SetGroupTrace__Fii(undefined4 param_1,undefined4 param_2)

{
  g_groupmask = param_1;
  g_groupop = param_2;
  (*DAT_0019f8bc)(param_1,param_2);
  return;
}


// UTIL_SetOrigin__FP9entvars_sRC6Vector  @ 001220d0
void UTIL_SetOrigin__FP9entvars_sRC6Vector(int param_1,undefined4 param_2)

{
  (*DAT_0019f710)(*(undefined4 *)(param_1 + 0x208),param_2);
  return;
}


// UTIL_SetSize__FP9entvars_sRC6VectorT1  @ 00122128
void UTIL_SetSize__FP9entvars_sRC6VectorT1(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*DAT_0019f6b4)(*(undefined4 *)(param_1 + 0x208),param_2,param_3);
  return;
}


// UTIL_SharedRandomFloat__FUiff  @ 0011d5e4
longdouble UTIL_SharedRandomFloat__FUiff(int param_1,float param_2,float param_3)

{
  uint uVar1;
  longdouble lVar2;
  int local_10;
  
  lVar2 = (longdouble)param_2;
  uVar1 = (*(int *)(seed_table + ((int)param_2 + param_1 + (int)param_3 & 0xffU) * 4) * 0x10dcd +
           *(int *)(seed_table +
                   (*(int *)(seed_table + ((int)param_2 + param_1 + (int)param_3 & 0xffU) * 4) *
                    0x10dcd & 0xffU) * 4) + 1) * 0x10dcd;
  glSeed = uVar1 + *(int *)(seed_table + (uVar1 & 0xff) * 4) + 1;
  local_10 = (int)(longlong)ROUND((longdouble)param_3 - lVar2);
  if (local_10 != 0) {
    glSeed = glSeed * 0x10dcd + *(int *)(seed_table + (glSeed * 0x10dcd & 0xff) * 4) + 1;
    lVar2 = (longdouble)((float)(glSeed & 0xffff) * 1.5258789e-05) *
            (longdouble)((longlong)ROUND((longdouble)param_3 - lVar2) & 0xffffffff) + lVar2;
  }
  return lVar2;
}


// UTIL_SharedRandomLong__FUiii  @ 00123208
int UTIL_SharedRandomLong__FUiii(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = (param_3 - param_2) + 1;
  glSeed = *(uint *)(seed_table + (param_2 + param_1 + param_3 & 0xffU) * 4);
  if (uVar1 != 1) {
    glSeed = glSeed * 0x10dcd + *(int *)(seed_table + (glSeed * 0x10dcd & 0xff) * 4) + 1;
    param_2 = (glSeed & 0xfffffff) % uVar1 + param_2;
  }
  return param_2;
}


// UTIL_ShouldShowBlood__Fi  @ 00121ee8
undefined4 UTIL_ShouldShowBlood__Fi(int param_1)

{
  longdouble lVar1;
  char *pcVar2;
  longdouble lVar3;
  
  if (param_1 != -1) {
    if (param_1 == 0xf7) {
      pcVar2 = "violence_hblood";
    }
    else {
      pcVar2 = "violence_ablood";
    }
    lVar3 = (longdouble)(*DAT_0019f784)(pcVar2);
    lVar1 = (longdouble)0;
    if ((byte)(lVar1 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar1 == lVar3) << 0xe) >> 8)) != 0x40) {
      return 1;
    }
  }
  return 0;
}


// UTIL_ShowMessageAll__FPCc  @ 00122238
void UTIL_ShowMessageAll__FPCc(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*DAT_0019f7c0)(1);
  if ((piVar1 != (int *)0x0) && (iVar2 = 0, 0 < *(int *)(gpGlobals + 0x90))) {
    do {
      if ((piVar1 != (int *)0x0) && ((*piVar1 == 0 && ((*(byte *)(piVar1 + 0x89) & 8) != 0)))) {
        (*DAT_0019f758)(1,gmsgHudText,0,piVar1);
        (*DAT_0019f778)(param_1);
        (*DAT_0019f75c)();
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0xc9;
    } while (iVar2 < *(int *)(gpGlobals + 0x90));
  }
  return;
}


// UTIL_ShowMessage__FPCcP7edict_s  @ 001222f4
void UTIL_ShowMessage__FPCcP7edict_s(undefined4 param_1,int *param_2)

{
  if (((param_2 != (int *)0x0) && (*param_2 == 0)) && ((*(byte *)(param_2 + 0x89) & 8) != 0)) {
    (*DAT_0019f758)(1,gmsgHudText,0,param_2);
    (*DAT_0019f778)(param_1);
    (*DAT_0019f75c)();
  }
  return;
}


// UTIL_Sparks__FRC6Vector  @ 00121bac
void UTIL_Sparks__FRC6Vector(undefined4 *param_1)

{
  (*DAT_0019f758)(4,0x17,param_1,0);
  (*DAT_0019f760)(9);
  (*DAT_0019f774)(*param_1);
  (*DAT_0019f774)(param_1[1]);
  (*DAT_0019f774)(param_1[2]);
  (*DAT_0019f75c)();
  return;
}


// UTIL_SplineFraction__Fff  @ 00121fa8
longdouble UTIL_SplineFraction__Fff(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 * (longdouble)param_2;
  lVar2 = lVar1 * lVar1;
  return (longdouble)3.0 * lVar2 - (lVar2 + lVar2) * lVar1;
}


// UTIL_StringToVector__FPfPCc  @ 00121a4c
void UTIL_StringToVector__FPfPCc(int param_1,char *param_2)

{
  char cVar1;
  char *__dest;
  int iVar2;
  longdouble lVar3;
  char local_84;
  char local_83 [127];
  
  __dest = &local_84;
  strcpy(__dest,param_2);
  iVar2 = 0;
  do {
    lVar3 = (longdouble)__strtod_internal(__dest,0,0);
    *(float *)(param_1 + iVar2 * 4) = (float)lVar3;
    cVar1 = *__dest;
    if (cVar1 == '\0') break;
    do {
      if (cVar1 == ' ') break;
      __dest = __dest + 1;
      cVar1 = *__dest;
    } while (cVar1 != '\0');
    if (cVar1 == '\0') break;
    __dest = __dest + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  if (iVar2 < 2) {
    while (iVar2 = iVar2 + 1, iVar2 < 3) {
      *(undefined4 *)(param_1 + iVar2 * 4) = 0;
    }
  }
  return;
}


// UTIL_StripToken__FPCcPc  @ 00121784
void UTIL_StripToken__FPCcPc(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while ((cVar1 != '\0' && (param_1[iVar2] != '#'))) {
    *(char *)(iVar2 + param_2) = param_1[iVar2];
    iVar2 = iVar2 + 1;
    cVar1 = param_1[iVar2];
  }
  *(undefined1 *)(iVar2 + param_2) = 0;
  return;
}


// UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult  @ 00122160
void UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  (*pcRam0019f728)(param_1,param_2,param_3 == 1,param_4,param_5,param_6);
  return;
}


// UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult  @ 001221f0
void UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
               undefined4 param_6)

{
  ushort uVar1;
  
  uVar1 = (ushort)(param_3 == 1);
  if (param_4 != 0) {
    uVar1 = CONCAT11(1,param_3 == 1);
  }
  (*DAT_0019f71c)(param_1,param_2,uVar1,param_5,param_6);
  return;
}


// UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult  @ 001221ac
void UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5)

{
  (*DAT_0019f71c)(param_1,param_2,param_3 == 1,param_4,param_5);
  return;
}


// UTIL_UnsetGroupTrace__Fv  @ 0012317c
void UTIL_UnsetGroupTrace__Fv(void)

{
  g_groupmask = 0;
  g_groupop = 0;
  (*DAT_0019f8bc)(0,0);
  return;
}


// UTIL_UserTracer__FRC6VectorT0fif  @ 00121818
void UTIL_UserTracer__FRC6VectorT0fif
               (undefined4 *param_1,undefined4 *param_2,float param_3,undefined1 param_4,
               float param_5)

{
  uint uStack_10;
  
  (*DAT_0019f758)(5,0x17,param_1,0);
  (*DAT_0019f760)(0x7f);
  (*DAT_0019f774)(*param_1);
  (*DAT_0019f774)(param_1[1]);
  (*DAT_0019f774)(param_1[2]);
  (*DAT_0019f774)(*param_2);
  (*DAT_0019f774)(param_2[1]);
  (*DAT_0019f774)(param_2[2]);
  uStack_10 = (uint)(longlong)ROUND(param_3 * 10.0);
  (*DAT_0019f760)(uStack_10 & 0xff);
  (*DAT_0019f760)(param_4);
  uStack_10 = (uint)(longlong)ROUND(param_5 * 10.0);
  (*DAT_0019f760)(uStack_10 & 0xff);
  (*DAT_0019f75c)();
  return;
}


// UTIL_VarArgs__FPce  @ 0011e308
undefined1 * UTIL_VarArgs__FPce(char *param_1)

{
  vsprintf(string_754,param_1,&stack0x00000008);
  return string_754;
}


// UTIL_VecToAngles__FRC6Vector  @ 00122f18
undefined4 * UTIL_VecToAngles__FRC6Vector(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (*pcRam0019f6c8)(param_2,&uStack_10);
  *param_1 = uStack_10;
  param_1[1] = uStack_c;
  param_1[2] = uStack_8;
  return param_1;
}


// UTIL_VecToYaw__FRC6Vector  @ 00122100
void UTIL_VecToYaw__FRC6Vector(undefined4 param_1)

{
  (*pcRam0019f6c4)(param_1);
  return;
}


// UTIL_WaterLevel__FRC6Vectorff  @ 00121980
longdouble UTIL_WaterLevel__FRC6Vectorff(undefined4 *param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  local_8 = param_2;
  iVar2 = (*DAT_0019f754)(&local_10);
  if (iVar2 == -3) {
    local_8 = param_3;
    iVar2 = (*DAT_0019f754)(&local_10);
    if (iVar2 == -3) {
      lVar3 = (longdouble)param_3;
    }
    else {
      while (fVar1 = param_3 - param_2,
            (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) {
        local_8 = fVar1 * 0.5 + param_2;
        iVar2 = (*DAT_0019f754)(&local_10);
        if (iVar2 == -3) {
          param_2 = local_8;
        }
        else {
          param_3 = local_8;
        }
      }
      lVar3 = (longdouble)local_8;
    }
  }
  else {
    lVar3 = (longdouble)param_2;
  }
  return lVar3;
}


// UTIL_dtos1__Fi  @ 001223fc
undefined8 * UTIL_dtos1__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_710,"%d",param_1);
  return &buf_710;
}


// UTIL_dtos2__Fi  @ 001223c8
undefined8 * UTIL_dtos2__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_713,"%d",param_1);
  return &buf_713;
}


// UTIL_dtos3__Fi  @ 00122394
void UTIL_dtos3__Fi(void)

{
  FUN_0012239e();
  return;
}


// UTIL_dtos4__Fi  @ 00122360
undefined8 * UTIL_dtos4__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_719,"%d",param_1);
  return &buf_719;
}


