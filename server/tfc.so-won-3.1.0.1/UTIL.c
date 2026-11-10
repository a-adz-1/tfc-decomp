// UTIL_AngleDiff__Fff  @ 00109e74
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


// UTIL_AngleDistance__Fff  @ 0010b3c4
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


// UTIL_AngleMod__Ff  @ 00109dbc
longdouble UTIL_AngleMod__Ff(float param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1;
  lVar2 = (longdouble)0.0;
  if ((byte)((lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1) < 0x40) {
    if ((longdouble)360.0 <= lVar1) {
      lVar1 = lVar1 - (longdouble)((int)ROUND((longdouble)0.0027777778 * lVar1) * 0x168);
    }
  }
  else {
    lVar1 = lVar1 + (longdouble)(((int)ROUND((longdouble)0.0027777778 * lVar1) * 3 + 3) * 0x78);
  }
  return lVar1;
}


// UTIL_ApproachAngle__Ffff  @ 0010b304
longdouble UTIL_ApproachAngle__Ffff(undefined4 param_1,undefined4 param_2,float param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar1 = (longdouble)UTIL_AngleMod__Ff(param_1);
  lVar2 = (longdouble)UTIL_AngleMod__Ff((float)lVar1);
  lVar3 = (longdouble)(float)lVar1 - lVar2;
  if (0x3f < (byte)((0.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_3 == 0.0) << 0xe) >> 8)) - 1)) {
    param_3 = -param_3;
  }
  lVar4 = (longdouble)-180.0;
  if ((byte)((lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1) < 0x40) {
    if ((longdouble)180.0 < lVar3) {
      lVar3 = lVar3 - (longdouble)360.0;
    }
  }
  else {
    lVar3 = (longdouble)360.0 + lVar3;
  }
  lVar4 = (longdouble)param_3;
  if ((byte)((lVar3 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar4)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar3 == lVar4) << 0xe) >> 8)) - 1) < 0x40) {
    lVar4 = -(longdouble)param_3;
    if ((byte)((lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1) < 0x40) {
      lVar2 = (longdouble)(float)lVar1;
    }
    else {
      lVar2 = lVar2 - (longdouble)param_3;
    }
  }
  else {
    lVar2 = lVar2 + (longdouble)param_3;
  }
  return lVar2;
}


// UTIL_Approach__Ffff  @ 0010b2bc
longdouble UTIL_Approach__Ffff(float param_1,float param_2,float param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar1 = (longdouble)param_1;
  lVar2 = (longdouble)param_2;
  lVar3 = (longdouble)param_3;
  lVar4 = lVar1 - lVar2;
  if ((byte)((lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1) < 0x40) {
    lVar5 = -lVar3;
    if (0x3f < (byte)((lVar5 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
      lVar1 = lVar2 - lVar3;
    }
  }
  else {
    lVar1 = lVar2 + lVar3;
  }
  return lVar1;
}


// UTIL_BloodDecalTrace__FP11TraceResulti  @ 0010b9ec
void UTIL_BloodDecalTrace__FP11TraceResulti(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = UTIL_ShouldShowBlood__Fi(param_2);
  if (iVar1 != 0) {
    if (param_2 == 0xf7) {
      iVar1 = (*DAT_001a7fa8)(0,5);
      iVar1 = iVar1 + 0xd;
    }
    else {
      iVar1 = (*DAT_001a7fa8)(0,5);
      iVar1 = iVar1 + 0x13;
    }
    UTIL_DecalTrace__FP11TraceResulti(param_1,iVar1);
  }
  return;
}


// UTIL_BloodDrips__FRC6VectorT0ii  @ 0010b794
void UTIL_BloodDrips__FRC6VectorT0ii(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = UTIL_ShouldShowBlood__Fi(param_3);
  if (((iVar1 != 0) && (param_3 != -1)) && (param_4 != 0)) {
    if ((g_Language == 1) && (param_3 == 0xf7)) {
      param_3 = 0;
    }
    iVar1 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (iVar1 != 0) {
      param_4 = param_4 * 2;
    }
    if (0xff < param_4) {
      param_4 = 0xff;
    }
    (*DAT_001a7ef8)(4,0x17,param_1,0);
    (*DAT_001a7f00)(0x73);
    (*DAT_001a7f14)(*param_1);
    (*DAT_001a7f14)(param_1[1]);
    (*DAT_001a7f14)(param_1[2]);
    (*DAT_001a7f08)((int)g_sModelIndexBloodSpray);
    (*DAT_001a7f08)((int)g_sModelIndexBloodDrop);
    (*DAT_001a7f00)(param_3);
    iVar1 = param_4 / 10;
    if (iVar1 < 3) {
      iVar1 = 3;
    }
    if (iVar1 < 0x10) {
      iVar1 = 3;
      if (2 < param_4 / 10) {
        iVar1 = param_4 / 10;
      }
    }
    else {
      iVar1 = 0x10;
    }
    (*DAT_001a7f00)(iVar1);
    (*DAT_001a7efc)();
  }
  return;
}


// UTIL_BloodStream__FRC6VectorT0ii  @ 0010b658
void UTIL_BloodStream__FRC6VectorT0ii
               (undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = UTIL_ShouldShowBlood__Fi(param_3);
  if (iVar1 != 0) {
    if ((g_Language == 1) && (param_3 == 0xf7)) {
      param_3 = 0;
    }
    (*DAT_001a7ef8)(4,0x17,param_1,0);
    (*DAT_001a7f00)(0x65);
    (*DAT_001a7f14)(*param_1);
    (*DAT_001a7f14)(param_1[1]);
    (*DAT_001a7f14)(param_1[2]);
    (*DAT_001a7f14)(*param_2);
    (*DAT_001a7f14)(param_2[1]);
    (*DAT_001a7f14)(param_2[2]);
    (*DAT_001a7f00)(param_3);
    if (0xff < param_4) {
      param_4 = 0xff;
    }
    (*DAT_001a7f00)(param_4);
    (*DAT_001a7efc)();
  }
  return;
}


// UTIL_BubbleTrail__FG6VectorT0i  @ 0010c534
void UTIL_BubbleTrail__FG6VectorT0i(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  float fVar1;
  longdouble lVar2;
  float local_4;
  
  lVar2 = (longdouble)UTIL_WaterLevel__FRC6Vectorff(param_1,param_1[2],(float)param_1[2] + 256.0);
  local_4 = (float)(lVar2 - (longdouble)(float)param_1[2]);
  if (local_4 < 8.0) {
    lVar2 = (longdouble)UTIL_WaterLevel__FRC6Vectorff(param_2,param_2[2],(float)param_2[2] + 256.0);
    fVar1 = (float)(lVar2 - (longdouble)(float)param_2[2]);
    if ((byte)(fVar1 < 8.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 8.0) << 0xe) >> 8)) == 1) {
      return;
    }
    local_4 = (fVar1 + (float)param_2[2]) - (float)param_1[2];
  }
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  (*DAT_001a7ef8)(0,0x17,0,0);
  (*DAT_001a7f00)(0x72);
  (*DAT_001a7f14)(*param_1);
  (*DAT_001a7f14)(param_1[1]);
  (*DAT_001a7f14)(param_1[2]);
  (*DAT_001a7f14)(*param_2);
  (*DAT_001a7f14)(param_2[1]);
  (*DAT_001a7f14)(param_2[2]);
  (*DAT_001a7f14)(local_4);
  (*DAT_001a7f08)((int)g_sModelIndexBubbles);
  (*DAT_001a7f00)(param_3);
  (*DAT_001a7f14)(0x41000000);
  (*DAT_001a7efc)();
  return;
}


// UTIL_Bubbles__FG6VectorT0i  @ 0010c388
void UTIL_Bubbles__FG6VectorT0i(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  longdouble lVar2;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = (*param_1 + *param_2) * 0.5;
  local_8 = (param_1[1] + param_2[1]) * 0.5;
  local_4 = (param_1[2] + param_2[2]) * 0.5;
  lVar2 = (longdouble)UTIL_WaterLevel__FRC6Vectorff(&local_c,local_4,local_4 + 1024.0);
  fVar1 = param_1[2];
  (*DAT_001a7ef8)(5,0x17,&local_c,0);
  (*DAT_001a7f00)(0x71);
  (*DAT_001a7f14)(*param_1);
  (*DAT_001a7f14)(param_1[1]);
  (*DAT_001a7f14)(param_1[2]);
  (*DAT_001a7f14)(*param_2);
  (*DAT_001a7f14)(param_2[1]);
  (*DAT_001a7f14)(param_2[2]);
  (*DAT_001a7f14)((float)(lVar2 - (longdouble)fVar1));
  (*DAT_001a7f08)((int)g_sModelIndexBubbles);
  (*DAT_001a7f00)(param_3);
  (*DAT_001a7f14)(0x41000000);
  (*DAT_001a7efc)();
  return;
}


// UTIL_ClampVectorToBox__FRC6VectorT0  @ 0010c134
float * UTIL_ClampVectorToBox__FRC6VectorT0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *param_2;
  local_8 = param_2[1];
  local_4 = param_2[2];
  fVar1 = *param_3;
  if ((byte)((local_c < fVar1 | (byte)((ushort)((ushort)(NAN(local_c) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_c == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
    fVar1 = -*param_3;
    if ((byte)((fVar1 < local_c | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_c)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar1 == local_c) << 0xe) >> 8)) - 1) < 0x40) {
      local_c = 0.0;
    }
    else {
      local_c = local_c + *param_3;
    }
  }
  else {
    local_c = local_c - *param_3;
  }
  fVar1 = param_3[1];
  if ((byte)((local_8 < fVar1 | (byte)((ushort)((ushort)(NAN(local_8) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_8 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
    fVar1 = -param_3[1];
    if ((byte)((fVar1 < local_8 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_8)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar1 == local_8) << 0xe) >> 8)) - 1) < 0x40) {
      local_8 = 0.0;
    }
    else {
      local_8 = local_8 + param_3[1];
    }
  }
  else {
    local_8 = local_8 - param_3[1];
  }
  fVar1 = param_3[2];
  if ((byte)((local_4 < fVar1 | (byte)((ushort)((ushort)(NAN(local_4) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_4 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
    fVar1 = -param_3[2];
    if ((byte)((fVar1 < local_4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_4)) << 10) >> 8)
               | (byte)((ushort)((ushort)(fVar1 == local_4) << 0xe) >> 8)) - 1) < 0x40) {
      local_4 = 0.0;
    }
    else {
      local_4 = local_4 + param_3[2];
    }
  }
  else {
    local_4 = local_4 - param_3[2];
  }
  fVar1 = SQRT(local_4 * local_4 + local_8 * local_8 + local_c * local_c);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 1.0;
  }
  else {
    fVar1 = 1.0 / fVar1;
    *param_1 = fVar1 * local_c;
    param_1[1] = fVar1 * local_8;
    param_1[2] = fVar1 * local_4;
  }
  return param_1;
}


// UTIL_ClientPrintAll__FiPCcN41  @ 0010ac24
void UTIL_ClientPrintAll__FiPCcN41
               (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
               int param_6)

{
  (*DAT_001a7ef8)(2,gmsgTextMsg,0,0);
  (*DAT_001a7f00)(param_1);
  (*DAT_001a7f18)(param_2);
  if (param_3 != 0) {
    (*DAT_001a7f18)(param_3);
  }
  if (param_4 != 0) {
    (*DAT_001a7f18)(param_4);
  }
  if (param_5 != 0) {
    (*DAT_001a7f18)(param_5);
  }
  if (param_6 != 0) {
    (*DAT_001a7f18)(param_6);
  }
  (*DAT_001a7efc)();
  return;
}


// UTIL_ClientProjectile__FRC6VectorT0sii  @ 0010c708
void UTIL_ClientProjectile__FRC6VectorT0sii
               (float *param_1,float *param_2,short param_3,uint param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined1 auStack_38 [20];
  undefined1 auStack_24 [36];
  
  fStack_48 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_48) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_48 == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_50 = 0.0;
    fStack_4c = 0.0;
    fStack_48 = 1.0;
  }
  else {
    fStack_48 = 1.0 / fStack_48;
    fStack_50 = fStack_48 * *param_2;
    fStack_4c = fStack_48 * param_2[1];
    fStack_48 = fStack_48 * param_2[2];
  }
  fStack_44 = fStack_50;
  fStack_40 = fStack_4c;
  fStack_3c = fStack_48;
  fStack_54 = *param_1 + fStack_50 * 4096.0;
  fStack_50 = param_1[1] + fStack_4c * 4096.0;
  fStack_4c = param_1[2] + fStack_48 * 4096.0;
  uVar1 = (*DAT_001a7f54)(param_4,auStack_38);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(param_1,&fStack_54,1,uVar1);
  iVar2 = UTIL_PointContents__FRC6Vector(param_1);
  iVar3 = UTIL_PointContents__FRC6Vector(auStack_24);
  if (iVar2 == iVar3) {
    puVar4 = auStack_24;
    uVar1 = 4;
  }
  else {
    puVar4 = (undefined1 *)0x0;
    uVar1 = 0;
  }
  (*DAT_001a7ef8)(uVar1,0x17,puVar4,0);
  (*DAT_001a7f00)(0x77);
  (*DAT_001a7f14)(*param_1);
  (*DAT_001a7f14)(param_1[1]);
  (*DAT_001a7f14)(param_1[2]);
  (*DAT_001a7f14)(*param_2);
  (*DAT_001a7f14)(param_2[1]);
  (*DAT_001a7f14)(param_2[2]);
  (*DAT_001a7f08)((int)param_3);
  (*DAT_001a7f00)(param_5);
  (*DAT_001a7f00)(param_4 & 0xff);
  (*DAT_001a7efc)();
  return;
}


// UTIL_DecalTrace__FP11TraceResulti  @ 0010ba54
void UTIL_DecalTrace__FP11TraceResulti(int param_1,int param_2)

{
  float fVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_2 < 0) {
    return;
  }
  iVar5 = *(int *)(gDecals + param_2 * 8 + 4);
  if (iVar5 < 0) {
    return;
  }
  fVar1 = *(float *)(param_1 + 0x10);
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    sVar2 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x30);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
    if ((iVar3 != 0) && (iVar3 = (**(code **)(*(int *)(iVar3 + 0x3d4) + 0x8c))(iVar3), iVar3 == 0))
    {
      return;
    }
    sVar2 = (*DAT_001a7f5c)(*(undefined4 *)(param_1 + 0x30));
  }
  uVar4 = 0x68;
  if (sVar2 == 0) {
    uVar4 = 0x74;
    if (iVar5 < 0x100) goto LAB_0010bb54;
    uVar4 = 0x75;
  }
  else {
    if (iVar5 < 0x100) goto LAB_0010bb54;
    uVar4 = 0x76;
  }
  iVar5 = iVar5 + -0x100;
LAB_0010bb54:
  (*DAT_001a7ef8)(0,0x17,0,0);
  (*DAT_001a7f00)(uVar4);
  (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x14));
  (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x18));
  (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x1c));
  (*DAT_001a7f00)(iVar5);
  if (sVar2 != 0) {
    (*DAT_001a7f08)((int)sVar2);
  }
  (*DAT_001a7efc)();
  return;
}


// UTIL_DotPoints__FRC6VectorN20  @ 0010cc94
longdouble UTIL_DotPoints__FRC6VectorN20(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float local_24;
  float local_20;
  
  local_24 = *param_2 - *param_1;
  local_20 = param_2[1] - param_1[1];
  fVar1 = SQRT(local_20 * local_20 + local_24 * local_24);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = 0.0;
    local_20 = 0.0;
  }
  else {
    local_24 = (1.0 / fVar1) * local_24;
    local_20 = (1.0 / fVar1) * local_20;
  }
  return (longdouble)local_20 * (longdouble)param_3[1] + (longdouble)local_24 * (longdouble)*param_3
  ;
}


// UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii  @ 0010a5d0
void UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
               (undefined4 param_1,undefined4 *param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  char *pcVar2;
  char local_2c [32];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *param_2;
  local_8 = param_2[1];
  local_4 = param_2[2];
  pcVar2 = param_3;
  if ((param_3 != (char *)0x0) && (*param_3 == '!')) {
    pcVar2 = local_2c;
    iVar1 = SENTENCEG_Lookup__FPCcPc(param_3,pcVar2);
    if (iVar1 < 0) {
      return;
    }
  }
  (*DAT_001a7eb8)(param_1,&local_c,pcVar2,param_4,param_5,param_6,param_7);
  return;
}


// UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i  @ 00109f78
int UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i
              (int param_1,int param_2,float *param_3,float *param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int local_4;
  
  piVar3 = (int *)(*DAT_001a7f60)(1);
  iVar6 = 0;
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    local_4 = 1;
    if (1 < *(int *)(gpGlobals + 0x94)) {
      pfVar7 = (float *)(piVar3 + 0x53);
      do {
        if ((*piVar3 == 0) &&
           ((((param_5 == 0 || ((param_5 & (uint)pfVar7[0x36]) != 0)) && (*param_3 <= pfVar7[1])) &&
            ((param_3[1] <= pfVar7[2] && (param_3[2] <= pfVar7[3])))))) {
          fVar1 = *param_4;
          fVar2 = pfVar7[-2];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            fVar1 = param_4[1];
            fVar2 = pfVar7[-1];
            if ((byte)(fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
              fVar1 = param_4[2];
              fVar2 = *pfVar7;
              if ((byte)(fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
                piVar4 = piVar3;
                if ((piVar3 == (int *)0x0) &&
                   (piVar4 = (int *)(*DAT_001a7f54)(0), piVar4 == (int *)0x0)) {
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
        local_4 = local_4 + 1;
        pfVar7 = pfVar7 + 0xc9;
        piVar3 = piVar3 + 0xc9;
      } while (local_4 < *(int *)(gpGlobals + 0x94));
    }
  }
  return iVar6;
}


// UTIL_FindEntityByClassname__FP11CBaseEntityPCc  @ 0010a344
void UTIL_FindEntityByClassname__FP11CBaseEntityPCc(undefined4 param_1,undefined4 param_2)

{
  UTIL_FindEntityByString__FP11CBaseEntityPCcT1(param_1,"classname",param_2);
  return;
}


// UTIL_FindEntityByString__FP11CBaseEntityPCcT1  @ 0010a2b4
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
  iVar2 = (*DAT_001a7e78)(uVar4,param_2,param_3);
  bVar1 = false;
  if (iVar2 == 0) {
LAB_0010a311:
    bVar1 = true;
  }
  else {
    iVar3 = (*DAT_001a7f58)(iVar2);
    if (iVar3 == 0) goto LAB_0010a311;
  }
  if (bVar1) {
LAB_0010a33c:
    uVar4 = 0;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (*DAT_001a7f54)(0);
      if (iVar2 == 0) goto LAB_0010a33c;
    }
    uVar4 = *(undefined4 *)(iVar2 + 0x7c);
  }
  return uVar4;
}


// UTIL_FindEntityByTargetname__FP11CBaseEntityPCc  @ 0010a36c
void UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(undefined4 param_1,undefined4 param_2)

{
  UTIL_FindEntityByString__FP11CBaseEntityPCcT1(param_1,"targetname",param_2);
  return;
}


// UTIL_FindEntityGeneric__FPCcR6Vectorf  @ 0010a394
int * UTIL_FindEntityGeneric__FPCcR6Vectorf(undefined4 param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  float local_14;
  
  piVar4 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(0,param_1);
  if (piVar4 == (int *)0x0) {
    piVar5 = (int *)0x0;
    local_14 = param_3 * param_3;
    while (piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,param_1),
          piVar5 != (int *)0x0) {
      fVar1 = *(float *)(*piVar5 + 8) - *param_2;
      fVar3 = *(float *)(*piVar5 + 0xc) - param_2[1];
      fVar2 = *(float *)(*piVar5 + 0x10) - param_2[2];
      fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
      fVar1 = fVar1 * fVar1;
      if (fVar1 < local_14) {
        piVar4 = piVar5;
        local_14 = fVar1;
      }
    }
  }
  return piVar4;
}


// UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf  @ 0010a220
undefined4
UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
          (int *param_1,undefined4 param_2,undefined4 param_3)

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
  iVar2 = (*DAT_001a7e80)(uVar4,param_2,param_3);
  bVar1 = false;
  if (iVar2 == 0) {
LAB_0010a282:
    bVar1 = true;
  }
  else {
    iVar3 = (*DAT_001a7f58)(iVar2);
    if (iVar3 == 0) goto LAB_0010a282;
  }
  if (bVar1) {
LAB_0010a2ad:
    uVar4 = 0;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (*DAT_001a7f54)(0);
      if (iVar2 == 0) goto LAB_0010a2ad;
    }
    uVar4 = *(undefined4 *)(iVar2 + 0x7c);
  }
  return uVar4;
}


// UTIL_GetAimVector__FP7edict_sf  @ 0010b46c
undefined4 *
UTIL_GetAimVector__FP7edict_sf(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (*DAT_001a7ed8)(param_2,param_3,&local_c);
  *param_1 = local_c;
  param_1[1] = local_8;
  param_1[2] = local_4;
  return param_1;
}


// UTIL_GetGlobalTrace__Fv  @ 0010b05c
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


// UTIL_GetNextBestWeapon__FP11CBasePlayerP15CBasePlayerItem  @ 00109d88
void UTIL_GetNextBestWeapon__FP11CBasePlayerP15CBasePlayerItem
               (undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*g_pGameRules + 0x1c))(g_pGameRules,param_1,param_2);
  return;
}


// UTIL_GunshotDecalTrace__FP11TraceResulti  @ 0010bd58
void UTIL_GunshotDecalTrace__FP11TraceResulti(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  short sVar3;
  
  if ((-1 < param_2) && (iVar2 = *(int *)(gDecals + param_2 * 8 + 4), -1 < iVar2)) {
    fVar1 = *(float *)(param_1 + 0x10);
    if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
      (*DAT_001a7ef8)(5,0x17,param_1 + 0x14,0);
      (*DAT_001a7f00)(0x6d);
      (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x14));
      (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x18));
      (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x1c));
      sVar3 = (*DAT_001a7f5c)(*(undefined4 *)(param_1 + 0x30));
      (*DAT_001a7f08)((int)sVar3);
      (*DAT_001a7f00)(iVar2);
      (*DAT_001a7efc)();
    }
  }
  return;
}


// UTIL_IsMasterTriggered__Fi  @ 0010b4c4
undefined4 UTIL_IsMasterTriggered__Fi(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  if (param_1 != 0) {
    iVar2 = (*DAT_001a7e78)(0,"targetname",param_1 + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      piVar5 = (int *)(iVar2 + 0x80);
      if (iVar2 == 0) {
        piVar5 = (int *)0x0;
      }
      iVar3 = strcmp((char *)(*piVar5 + *(int *)(gpGlobals + 0x98)),"multisource");
      if (iVar3 == 0) {
        if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar2 + 0x7c);
        }
        if (iVar2 != 0) {
          uVar4 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x48))(iVar2);
          return uVar4;
        }
      }
    }
    (*DAT_001a7f34)(1,"Master was null or not a MultiSource!\n");
  }
  return 1;
}


// UTIL_IsValidEntity__FP7edict_s  @ 0010cb58
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


// UTIL_LogPrintf__FPce  @ 0010cc50
void UTIL_LogPrintf__FPce(char *param_1)

{
  vsprintf(string_799,param_1,&stack0x00000008);
  (*DAT_001a7f34)(5,&DAT_001429c0,string_799);
  return;
}


// UTIL_MakeAimVectors__FRC6Vector  @ 0010a4f8
void UTIL_MakeAimVectors__FRC6Vector(float *param_1)

{
  float local_c;
  float local_8;
  float local_4;
  
  local_8 = param_1[1];
  local_4 = param_1[2];
  local_c = -*param_1;
  (*DAT_001a7e8c)(&local_c);
  return;
}


// UTIL_MakeInvVectors__FRC6VectorP12globalvars_t  @ 0010a540
void UTIL_MakeInvVectors__FRC6VectorP12globalvars_t(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  (*DAT_001a7e8c)(param_1);
  *(float *)(param_2 + 0x40) = *(float *)(param_2 + 0x40) * -1.0;
  *(float *)(param_2 + 0x44) = *(float *)(param_2 + 0x44) * -1.0;
  *(float *)(param_2 + 0x48) = *(float *)(param_2 + 0x48) * -1.0;
  uVar1 = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_2 + 0x40) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_2 + 0x34) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 0x48);
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_2 + 0x38) = uVar1;
  return;
}


// UTIL_MakeVectors__FRC6Vector  @ 0010a4d4
void UTIL_MakeVectors__FRC6Vector(undefined4 param_1)

{
  (*DAT_001a7e8c)(param_1);
  return;
}


// UTIL_MonstersInSphere__FPP11CBaseEntityiRC6Vectorf  @ 0010a0cc
int UTIL_MonstersInSphere__FPP11CBaseEntityiRC6Vectorf
              (int param_1,int param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int local_c;
  
  piVar3 = (int *)(*DAT_001a7f60)(1);
  iVar6 = 0;
  param_4 = param_4 * param_4;
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    local_c = 1;
    if (1 < *(int *)(gpGlobals + 0x94)) {
      pfVar7 = (float *)(piVar3 + 0x53);
      do {
        if ((((*piVar3 == 0) && (((uint)pfVar7[0x36] & 0x28) != 0)) &&
            (fVar1 = (*param_3 - pfVar7[-0x31]) * (*param_3 - pfVar7[-0x31]), fVar1 <= param_4)) &&
           ((fVar1 = (param_3[1] - pfVar7[-0x30]) * (param_3[1] - pfVar7[-0x30]) + fVar1,
            fVar1 <= param_4 &&
            (fVar2 = param_3[2] - (*pfVar7 + pfVar7[3]) * 0.5, fVar2 * fVar2 + fVar1 <= param_4))))
        {
          piVar4 = piVar3;
          if ((piVar3 == (int *)0x0) && (piVar4 = (int *)(*DAT_001a7f54)(0), piVar4 == (int *)0x0))
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
        pfVar7 = pfVar7 + 0xc9;
        piVar3 = piVar3 + 0xc9;
      } while (local_c < *(int *)(gpGlobals + 0x94));
    }
  }
  return iVar6;
}


// UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi  @ 00109f20
void UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *param_2;
  local_8 = param_2[1];
  local_4 = param_2[2];
  (*DAT_001a7e6c)(param_1,&local_c,param_3,param_4);
  return;
}


// UTIL_ParametricRocket__FP9entvars_sG6VectorT1P7edict_s  @ 000f2764
void UTIL_ParametricRocket__FP9entvars_sG6VectorT1P7edict_s
               (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [20];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  *(undefined4 *)(param_1 + 0x8c) = *param_2;
  *(undefined4 *)(param_1 + 0x90) = param_2[1];
  *(undefined4 *)(param_1 + 0x94) = param_2[2];
  UTIL_MakeVectors__FRC6Vector(param_3);
  local_44 = *(float *)(param_1 + 0x8c) + gpGlobals[10] * 8192.0;
  local_40 = *(float *)(param_1 + 0x90) + gpGlobals[0xb] * 8192.0;
  local_3c = *(float *)(param_1 + 0x94) + gpGlobals[0xc] * 8192.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_1 + 0x8c,&local_44,1,param_4,local_38);
  *(undefined4 *)(param_1 + 0x80) = local_24;
  *(undefined4 *)(param_1 + 0x84) = local_20;
  *(undefined4 *)(param_1 + 0x88) = local_1c;
  fVar4 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0x8c);
  fVar5 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0x90);
  fVar6 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0x94);
  fVar1 = 0.0;
  fVar2 = *(float *)(param_1 + 0x20);
  fVar3 = *(float *)(param_1 + 0x24);
  fVar7 = SQRT(*(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x28) +
               fVar3 * fVar3 + fVar2 * fVar2);
  if (0x3f < (byte)((fVar7 < 0.0 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar7 == 0.0) << 0xe) >> 8)) - 1)) {
    fVar1 = SQRT(fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4) /
            SQRT(*(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x28) +
                 fVar3 * *(float *)(param_1 + 0x24) + fVar2 * *(float *)(param_1 + 0x20));
  }
  *(float *)(param_1 + 0x9c) = *gpGlobals;
  *(float *)(param_1 + 0x98) = fVar1 + *gpGlobals;
  return;
}


// UTIL_ParticleBox__FP11CBasePlayerPfT1fUcUcUc  @ 0010ef34
void UTIL_ParticleBox__FP11CBasePlayerPfT1fUcUcUc
               (int *param_1,undefined4 *param_2,undefined4 *param_3,float param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  (*DAT_001a7ef8)(8,0x17,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(0x1f);
  (*DAT_001a7f14)(*param_2);
  (*DAT_001a7f14)(param_2[1]);
  (*DAT_001a7f14)(param_2[2]);
  (*DAT_001a7f14)(*param_3);
  (*DAT_001a7f14)(param_3[1]);
  (*DAT_001a7f14)(param_3[2]);
  (*DAT_001a7f08)((int)ROUND((double)(int)(short)(int)ROUND(param_4) * 10.0));
  (*DAT_001a7f00)(param_5);
  (*DAT_001a7f00)(param_6);
  (*DAT_001a7f00)(param_7);
  (*DAT_001a7efc)();
  return;
}


// UTIL_ParticleEffect__FRC6VectorT0UlUl  @ 0010b260
void UTIL_ParticleEffect__FRC6VectorT0UlUl
               (undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  (*DAT_001a7ee8)(param_1,param_2,(float)param_3,(float)param_4);
  return;
}


// UTIL_ParticleLine__FP11CBasePlayerPfT1fUcUcUc  @ 0010ed8c
void UTIL_ParticleLine__FP11CBasePlayerPfT1fUcUcUc
               (int *param_1,undefined4 *param_2,undefined4 *param_3,float param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  (*DAT_001a7ef8)(8,0x17,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(0x1e);
  (*DAT_001a7f14)(*param_2);
  (*DAT_001a7f14)(param_2[1]);
  (*DAT_001a7f14)(param_2[2]);
  (*DAT_001a7f14)(*param_3);
  (*DAT_001a7f14)(param_3[1]);
  (*DAT_001a7f14)(param_3[2]);
  (*DAT_001a7f08)((int)ROUND((double)(int)(short)(int)ROUND(param_4) * 10.0));
  (*DAT_001a7f00)(param_5);
  (*DAT_001a7f00)(param_6);
  (*DAT_001a7f00)(param_7);
  (*DAT_001a7efc)();
  return;
}


// UTIL_PlayerByIndex__Fi  @ 0010a444
undefined4 UTIL_PlayerByIndex__Fi(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((0 < param_1) && (param_1 <= *(int *)(gpGlobals + 0x90))) &&
     (iVar1 = (*DAT_001a7f60)(param_1), iVar1 != 0)) {
    if (*(char *)(*(int *)(iVar1 + 0x250) + *(int *)(gpGlobals + 0x98)) == '\0') {
      uVar2 = 0;
    }
    else if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0x7c);
    }
  }
  return uVar2;
}


// UTIL_PlayerDecalTrace__FP11TraceResultiii  @ 0010bc34
void UTIL_PlayerDecalTrace__FP11TraceResultiii
               (int param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  short sVar2;
  
  if (((param_4 != 0) ||
      ((-1 < param_3 && (param_3 = *(int *)(gDecals + param_3 * 8 + 4), -1 < param_3)))) &&
     (fVar1 = *(float *)(param_1 + 0x10),
     (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) {
    (*DAT_001a7ef8)(0,0x17,0,0);
    (*DAT_001a7f00)(0x70);
    (*DAT_001a7f00)(param_2);
    (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x14));
    (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x18));
    (*DAT_001a7f14)(*(undefined4 *)(param_1 + 0x1c));
    sVar2 = (*DAT_001a7f5c)(*(undefined4 *)(param_1 + 0x30));
    (*DAT_001a7f08)((int)sVar2);
    (*DAT_001a7f00)(param_3);
    (*DAT_001a7efc)();
  }
  return;
}


// UTIL_PointContents__FRC6Vector  @ 0010b630
void UTIL_PointContents__FRC6Vector(undefined4 param_1)

{
  (*DAT_001a7ef4)(param_1);
  return;
}


// UTIL_PrecacheOtherWeapon__FPCc  @ 0010f72c
void UTIL_PrecacheOtherWeapon__FPCc(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  undefined4 *puVar5;
  char *local_2c [4];
  char *local_1c;
  int local_c;
  
  iVar2 = (*DAT_001a7e9c)(param_1 - *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    iVar3 = *(int *)(iVar3 + 0x208);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x3d4) + 0xc))(iVar3);
      memset(local_2c,0,0x2c);
      iVar3 = (**(code **)(*(int *)(iVar3 + 0x3d4) + 0x110))(iVar3,local_2c);
      if (iVar3 != 0) {
        ppcVar4 = local_2c;
        puVar5 = (undefined4 *)(_15CBasePlayerItem_ItemInfoArray + local_c * 0x2c);
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *ppcVar4;
          ppcVar4 = ppcVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        if ((local_2c[2] != (char *)0x0) && (*local_2c[2] != '\0')) {
          AddAmmoNameToAmmoRegistry__FPCc(local_2c[2]);
        }
        if ((local_1c != (char *)0x0) && (*local_1c != '\0')) {
          AddAmmoNameToAmmoRegistry__FPCc(local_1c);
        }
        memset(local_2c,0,0x2c);
      }
    }
    (*DAT_001a7e98)(iVar2);
    return;
  }
  (*DAT_001a7f34)(1,"NULL Ent in UTIL_PrecacheOtherWeapon\n");
  return;
}


// UTIL_PrecacheOther__FPCc  @ 0010cb7c
void UTIL_PrecacheOther__FPCc(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (*DAT_001a7e9c)(param_1 - *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    iVar3 = *(int *)(iVar3 + 0x208);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x3d4) + 0xc))(iVar3);
    }
    (*DAT_001a7e98)(iVar2);
    return;
  }
  (*DAT_001a7f34)(1,"NULL Ent in UTIL_PrecacheOther\n");
  return;
}


// UTIL_RandomBloodVector__Fv  @ 0010b968
float * UTIL_RandomBloodVector__Fv(float *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  lVar1 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
  lVar2 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
  lVar3 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
  *param_1 = (float)lVar1;
  param_1[1] = (float)lVar2;
  param_1[2] = (float)lVar3;
  return param_1;
}


// UTIL_Remove__FP11CBaseEntity  @ 0010cb20
void UTIL_Remove__FP11CBaseEntity(int *param_1)

{
  if (param_1 != (int *)0x0) {
    UpdateOnRemove__11CBaseEntity(param_1);
    *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x40;
    *(undefined4 *)(*param_1 + 0x1cc) = 0;
  }
  return;
}


// UTIL_Ricochet__FRC6Vectorf  @ 0010bef0
void UTIL_Ricochet__FRC6Vectorf(undefined4 *param_1,float param_2)

{
  (*DAT_001a7ef8)(4,0x17,param_1,0);
  (*DAT_001a7f00)(0x6f);
  (*DAT_001a7f14)(*param_1);
  (*DAT_001a7f14)(param_1[1]);
  (*DAT_001a7f14)(param_1[2]);
  (*DAT_001a7f00)((int)ROUND(param_2 * 10.0));
  (*DAT_001a7efc)();
  return;
}


// UTIL_ScreenFadeAll__FRC6Vectorffii  @ 0010ab24
void UTIL_ScreenFadeAll__FRC6Vectorffii
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined1 local_c [12];
  
  UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii(local_c,param_1,param_2,param_3,param_4,param_5)
  ;
  piVar1 = (int *)(*DAT_001a7f60)(1);
  if (piVar1 != (int *)0x0) {
    for (iVar2 = 0; iVar2 < *(int *)(gpGlobals + 0x90); iVar2 = iVar2 + 1) {
      if ((*piVar1 == 0) && ((*(byte *)(piVar1 + 0x89) & 8) != 0)) {
        UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s(local_c,piVar1);
      }
      piVar1 = piVar1 + 0xc9;
    }
  }
  return;
}


// UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii  @ 0010a980
void UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii
               (undefined2 *param_1,float *param_2,undefined4 param_3,undefined4 param_4,
               undefined1 param_5,undefined2 param_6)

{
  undefined2 uVar1;
  
  uVar1 = FixedUnsigned16__Fff(param_3,0x45800000);
  *param_1 = uVar1;
  uVar1 = FixedUnsigned16__Fff(param_4,0x45800000);
  param_1[1] = uVar1;
  *(char *)(param_1 + 3) = (char)(int)ROUND(*param_2);
  *(char *)((int)param_1 + 7) = (char)(int)ROUND(param_2[1]);
  *(char *)(param_1 + 4) = (char)(int)ROUND(param_2[2]);
  *(undefined1 *)((int)param_1 + 9) = param_5;
  param_1[2] = param_6;
  return;
}


// UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s  @ 0010aa4c
void UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s(undefined2 *param_1,undefined4 param_2)

{
  (*DAT_001a7ef8)(1,gmsgFade,0,param_2);
  (*DAT_001a7f08)(*param_1);
  (*DAT_001a7f08)(param_1[1]);
  (*DAT_001a7f08)((int)(short)param_1[2]);
  (*DAT_001a7f00)(*(undefined1 *)(param_1 + 3));
  (*DAT_001a7f00)(*(undefined1 *)((int)param_1 + 7));
  (*DAT_001a7f00)(*(undefined1 *)(param_1 + 4));
  (*DAT_001a7f00)(*(undefined1 *)((int)param_1 + 9));
  (*DAT_001a7efc)();
  return;
}


// UTIL_ScreenFade__FP7edict_sRC6Vectorffii  @ 0010abbc
void UTIL_ScreenFade__FP7edict_sRC6Vectorffii
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined1 local_c [12];
  
  if (((param_1 != (int *)0x0) && (*param_1 == 0)) && ((*(byte *)(param_1 + 0x89) & 8) != 0)) {
    UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii
              (local_c,param_2,param_3,param_4,param_5,param_6);
    UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s(local_c,param_1);
  }
  return;
}


// UTIL_ScreenShakeAll__FRC6Vectorfff  @ 0010a944
void UTIL_ScreenShakeAll__FRC6Vectorfff
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  UTIL_ScreenShake__FRC6Vectorffff(param_1,param_2,param_3,param_4,0);
  return;
}


// UTIL_ScreenShakeOne__FP7edict_sfff  @ 0010a874
void UTIL_ScreenShakeOne__FP7edict_sfff
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar1 = FixedUnsigned16__Fff(param_4,0x45800000);
  uVar2 = FixedUnsigned16__Fff(param_3,0x43800000);
  uVar3 = FixedUnsigned16__Fff(param_2,0x45800000);
  (*DAT_001a7ef8)(1,gmsgShake,0,param_1);
  (*DAT_001a7f08)(uVar3);
  (*DAT_001a7f08)(uVar1);
  (*DAT_001a7f08)(uVar2);
  (*DAT_001a7efc)();
  return;
}


// UTIL_ScreenShake__FRC6Vectorffff  @ 0010a6a0
void UTIL_ScreenShake__FRC6Vectorffff
               (float *param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  float fVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  
  uVar2 = FixedUnsigned16__Fff(param_4,0x45800000);
  uVar3 = FixedUnsigned16__Fff(param_3,0x43800000);
  piVar5 = (int *)(*DAT_001a7f60)(1);
  if ((piVar5 != (int *)0x0) && (iVar6 = 0, 0 < *(int *)(gpGlobals + 0x90))) {
    pfVar7 = (float *)(piVar5 + 0x24);
    do {
      if (((*piVar5 == 0) && (((uint)pfVar7[0x65] & 8) != 0)) &&
         ((*(byte *)((int)pfVar7 + 0x195) & 2) != 0)) {
        if ((param_5 <= 0.0) ||
           (fVar1 = 0.0,
           SQRT((param_1[2] - *pfVar7) * (param_1[2] - *pfVar7) +
                (param_1[1] - pfVar7[-1]) * (param_1[1] - pfVar7[-1]) +
                (*param_1 - pfVar7[-2]) * (*param_1 - pfVar7[-2])) < param_5)) {
          fVar1 = param_2;
        }
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          uVar4 = FixedUnsigned16__Fff(fVar1,0x45800000);
          (*DAT_001a7ef8)(1,gmsgShake,0,piVar5);
          (*DAT_001a7f08)(uVar4);
          (*DAT_001a7f08)(uVar2);
          (*DAT_001a7f08)(uVar3);
          (*DAT_001a7efc)();
        }
      }
      iVar6 = iVar6 + 1;
      pfVar7 = pfVar7 + 0xc9;
      piVar5 = piVar5 + 0xc9;
    } while (iVar6 < *(int *)(gpGlobals + 0x90));
  }
  return;
}


// UTIL_SetGroupTrace__Fii  @ 00109c4c
void UTIL_SetGroupTrace__Fii(undefined4 param_1,undefined4 param_2)

{
  g_groupmask = param_1;
  g_groupop = param_2;
  (*DAT_001a805c)(param_1,param_2);
  return;
}


// UTIL_SetOrigin__FP9entvars_sRC6Vector  @ 0010b230
void UTIL_SetOrigin__FP9entvars_sRC6Vector(int param_1,undefined4 param_2)

{
  (*DAT_001a7eb0)(*(undefined4 *)(param_1 + 0x208),param_2);
  return;
}


// UTIL_SetSize__FP9entvars_sRC6VectorT1  @ 0010b1d8
void UTIL_SetSize__FP9entvars_sRC6VectorT1(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*DAT_001a7e54)(*(undefined4 *)(param_1 + 0x208),param_2,param_3);
  return;
}


// UTIL_SharedRandomFloat__FUiff  @ 00109b98
longdouble UTIL_SharedRandomFloat__FUiff(int param_1,float param_2,float param_3)

{
  ushort uVar1;
  longdouble lVar2;
  int local_c;
  
  U_Srand__FUi((int)param_2 + param_1 + (int)param_3);
  U_Random__Fv();
  U_Random__Fv();
  local_c = (int)(longlong)ROUND(param_3 - param_2);
  if (local_c == 0) {
    lVar2 = (longdouble)param_2;
  }
  else {
    uVar1 = U_Random__Fv();
    lVar2 = (longdouble)((longlong)ROUND(param_3 - param_2) & 0xffffffff) *
            (longdouble)((float)uVar1 * 1.5258789e-05) + (longdouble)param_2;
  }
  return lVar2;
}


// UTIL_SharedRandomLong__FUiii  @ 00109b50
int UTIL_SharedRandomLong__FUiii(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  U_Srand__FUi(param_1 + param_2 + param_3);
  uVar2 = (param_3 - param_2) + 1;
  if (uVar2 != 1) {
    uVar1 = U_Random__Fv();
    param_2 = uVar1 % uVar2 + param_2;
  }
  return param_2;
}


// UTIL_ShouldShowBlood__Fi  @ 0010b5bc
undefined4 UTIL_ShouldShowBlood__Fi(int param_1)

{
  char *pcVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  if (param_1 != -1) {
    if (param_1 == 0xf7) {
      pcVar1 = "violence_hblood";
    }
    else {
      pcVar1 = "violence_ablood";
    }
    lVar2 = (longdouble)(*DAT_001a7f24)(pcVar1);
    lVar3 = (longdouble)0.0;
    if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) != 0x40) {
      return 1;
    }
  }
  return 0;
}


// UTIL_ShowMessageAll__FPCc  @ 0010af20
void UTIL_ShowMessageAll__FPCc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*DAT_001a7f60)(1);
  if (iVar1 != 0) {
    for (iVar2 = 0; iVar2 < *(int *)(gpGlobals + 0x90); iVar2 = iVar2 + 1) {
      UTIL_ShowMessage__FPCcP7edict_s(param_1,iVar1);
      iVar1 = iVar1 + 0x324;
    }
  }
  return;
}


// UTIL_ShowMessage__FPCcP7edict_s  @ 0010aeb8
void UTIL_ShowMessage__FPCcP7edict_s(undefined4 param_1,int *param_2)

{
  if (((param_2 != (int *)0x0) && (*param_2 == 0)) && ((*(byte *)(param_2 + 0x89) & 8) != 0)) {
    (*DAT_001a7ef8)(1,gmsgHudText,0,param_2);
    (*DAT_001a7f18)(param_1);
    (*DAT_001a7efc)();
  }
  return;
}


// UTIL_Sparks__FRC6Vector  @ 0010be5c
void UTIL_Sparks__FRC6Vector(undefined4 *param_1)

{
  (*DAT_001a7ef8)(4,0x17,param_1,0);
  (*DAT_001a7f00)(9);
  (*DAT_001a7f14)(*param_1);
  (*DAT_001a7f14)(param_1[1]);
  (*DAT_001a7f14)(param_1[2]);
  (*DAT_001a7efc)();
  return;
}


// UTIL_SplineFraction__Fff  @ 0010b414
longdouble UTIL_SplineFraction__Fff(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 * (longdouble)param_2;
  lVar2 = lVar1 * lVar1;
  return (longdouble)3.0 * lVar2 - (lVar2 + lVar2) * lVar1;
}


// UTIL_StringToVector__FPfPCc  @ 0010bfc4
void UTIL_StringToVector__FPfPCc(float *param_1,char *param_2)

{
  uint uVar1;
  float *pfVar2;
  float *pfVar3;
  uint uVar4;
  char *pcVar5;
  longdouble lVar6;
  char local_80 [128];
  
  pcVar5 = local_80;
  strcpy(pcVar5,param_2);
  uVar4 = 0;
  lVar6 = (longdouble)__strtod_internal(pcVar5,0,0);
  *param_1 = (float)lVar6;
  if (local_80[0] != '\0') {
    do {
      if (*pcVar5 == ' ') break;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar5 != '\0');
    if (*pcVar5 != '\0') {
      pcVar5 = pcVar5 + 1;
      uVar4 = 1;
      lVar6 = (longdouble)__strtod_internal(pcVar5,0,0);
      param_1[1] = (float)lVar6;
      if (*pcVar5 != '\0') {
        do {
          if (*pcVar5 == ' ') break;
          pcVar5 = pcVar5 + 1;
        } while (*pcVar5 != '\0');
        if (*pcVar5 != '\0') {
          pcVar5 = pcVar5 + 1;
          uVar4 = 2;
          lVar6 = (longdouble)__strtod_internal(pcVar5,0,0);
          param_1[2] = (float)lVar6;
          if (*pcVar5 != '\0') {
            do {
              if (*pcVar5 == ' ') break;
              pcVar5 = pcVar5 + 1;
            } while (*pcVar5 != '\0');
            if (*pcVar5 != '\0') {
              uVar4 = 3;
            }
          }
        }
      }
    }
  }
  if (1 < uVar4) {
    return;
  }
  uVar4 = uVar4 + 1;
  if (2 < uVar4) {
    return;
  }
  pfVar2 = param_1 + uVar4;
  uVar1 = 3 - uVar4 & 3;
  if (uVar4 < 3) {
    pfVar3 = pfVar2;
    if (uVar1 == 0) goto LAB_0010c104;
    if (1 < uVar1) {
      if (2 < uVar1) {
        *pfVar2 = 0.0;
        pfVar2 = pfVar2 + 1;
      }
      *pfVar2 = 0.0;
      pfVar2 = pfVar2 + 1;
    }
  }
  *pfVar2 = 0.0;
  pfVar2 = pfVar2 + 1;
  pfVar3 = pfVar2;
  if ((int)(param_1 + 2) < (int)pfVar2) {
    return;
  }
LAB_0010c104:
  do {
    *pfVar2 = 0.0;
    pfVar2[1] = 0.0;
    pfVar2[2] = 0.0;
    pfVar2[3] = 0.0;
    pfVar2 = pfVar2 + 4;
    pfVar3 = pfVar3 + 4;
  } while ((int)pfVar3 <= (int)(param_1 + 2));
  return;
}


// UTIL_StripToken__FPCcPc  @ 0010cd94
void UTIL_StripToken__FPCcPc(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while ((cVar1 != '\0' && (*param_1 != '#'))) {
    *(char *)(iVar2 + param_2) = *param_1;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    cVar1 = *param_1;
  }
  *(undefined1 *)(iVar2 + param_2) = 0;
  return;
}


// UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult  @ 0010b00c
void UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  (*DAT_001a7ec8)(param_1,param_2,param_3 == 1,param_4,param_5,param_6);
  return;
}


// UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult  @ 0010af7c
void UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
               undefined4 param_6)

{
  ushort uVar1;
  
  uVar1 = (ushort)(param_3 == 1);
  if (param_4 != 0) {
    uVar1 = CONCAT11(1,param_3 == 1);
  }
  (*DAT_001a7ebc)(param_1,param_2,uVar1,param_5,param_6);
  return;
}


// UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult  @ 0010afc8
void UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5)

{
  (*DAT_001a7ebc)(param_1,param_2,param_3 == 1,param_4,param_5);
  return;
}


// UTIL_UnsetGroupTrace__Fv  @ 00109c90
void UTIL_UnsetGroupTrace__Fv(void)

{
  g_groupmask = 0;
  g_groupop = 0;
  (*DAT_001a805c)(0,0);
  return;
}


// UTIL_UserTracer__FRC6VectorT0fif  @ 0010c9a4
void UTIL_UserTracer__FRC6VectorT0fif
               (undefined4 *param_1,undefined4 *param_2,float param_3,undefined1 param_4,
               float param_5)

{
  uint local_c;
  
  (*DAT_001a7ef8)(5,0x17,param_1,0);
  (*DAT_001a7f00)(0x7f);
  (*DAT_001a7f14)(*param_1);
  (*DAT_001a7f14)(param_1[1]);
  (*DAT_001a7f14)(param_1[2]);
  (*DAT_001a7f14)(*param_2);
  (*DAT_001a7f14)(param_2[1]);
  (*DAT_001a7f14)(param_2[2]);
  local_c = (uint)(longlong)ROUND(param_3 * 10.0);
  (*DAT_001a7f00)(local_c & 0xff);
  (*DAT_001a7f00)(param_4);
  local_c = (uint)(longlong)ROUND(param_5 * 10.0);
  (*DAT_001a7f00)(local_c & 0xff);
  (*DAT_001a7efc)();
  return;
}


// UTIL_VarArgs__FPce  @ 0010b440
void UTIL_VarArgs__FPce(void)

{
  FUN_0010b447();
  return;
}


// UTIL_VecToAngles__FRC6Vector  @ 00109ed4
undefined4 * UTIL_VecToAngles__FRC6Vector(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (*DAT_001a7e68)(param_2,&local_c);
  *param_1 = local_c;
  param_1[1] = local_8;
  param_1[2] = local_4;
  return param_1;
}


// UTIL_VecToYaw__FRC6Vector  @ 0010b20c
void UTIL_VecToYaw__FRC6Vector(undefined4 param_1)

{
  (*DAT_001a7e64)(param_1);
  return;
}


// UTIL_WaterLevel__FRC6Vectorff  @ 0010c2b0
longdouble UTIL_WaterLevel__FRC6Vectorff(undefined4 *param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_c = *param_1;
  local_8 = param_1[1];
  local_4 = param_2;
  iVar2 = UTIL_PointContents__FRC6Vector(&local_c);
  if (iVar2 == -3) {
    local_4 = param_3;
    iVar2 = UTIL_PointContents__FRC6Vector(&local_c);
    if (iVar2 == -3) {
      lVar3 = (longdouble)param_3;
    }
    else {
      while( true ) {
        fVar1 = param_3 - param_2;
        if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 1) break;
        local_4 = fVar1 * 0.5 + param_2;
        iVar2 = UTIL_PointContents__FRC6Vector(&local_c);
        if (iVar2 == -3) {
          param_2 = local_4;
        }
        else {
          param_3 = local_4;
        }
      }
      lVar3 = (longdouble)local_4;
    }
  }
  else {
    lVar3 = (longdouble)param_2;
  }
  return lVar3;
}


// UTIL_dtos1__Fi  @ 0010adf8
void UTIL_dtos1__Fi(void)

{
  FUN_0010adff();
  return;
}


// UTIL_dtos2__Fi  @ 0010ae28
undefined8 * UTIL_dtos2__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_709,"%d",param_1);
  return &buf_709;
}


// UTIL_dtos3__Fi  @ 0010ae58
undefined8 * UTIL_dtos3__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_712,"%d",param_1);
  return &buf_712;
}


// UTIL_dtos4__Fi  @ 0010ae88
undefined8 * UTIL_dtos4__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_715,"%d",param_1);
  return &buf_715;
}


