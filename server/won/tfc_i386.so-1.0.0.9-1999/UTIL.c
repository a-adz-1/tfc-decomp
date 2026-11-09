// UTIL_AngleDiff__Fff  @ 00116730
longdouble UTIL_AngleDiff__Fff(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 - (longdouble)param_2;
  if ((longdouble)param_1 <= (longdouble)param_2) {
    if (lVar1 <= (longdouble)-180.0) {
      lVar1 = (longdouble)360.0 + lVar1;
    }
  }
  else {
    lVar2 = (longdouble)180.0;
    if ((byte)((lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1) < 0x40) {
      lVar1 = lVar1 - (longdouble)360.0;
    }
  }
  return lVar1;
}


// UTIL_AngleDistance__Fff  @ 001178d0
longdouble UTIL_AngleDistance__Fff(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 - (longdouble)param_2;
  if ((longdouble)-180.0 <= lVar1) {
    lVar2 = (longdouble)180.0;
    if ((byte)(lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) == 1) {
      lVar1 = lVar1 - (longdouble)360.0;
    }
  }
  else {
    lVar1 = (longdouble)360.0 + lVar1;
  }
  return lVar1;
}


// UTIL_AngleMod__Ff  @ 00116690
longdouble UTIL_AngleMod__Ff(float param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1;
  if ((longdouble)0 <= lVar1) {
    lVar2 = (longdouble)360.0;
    if ((byte)((lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1) < 0x40) {
      lVar1 = lVar1 - (longdouble)((int)ROUND(lVar1 / lVar2) * 0x168);
    }
  }
  else {
    lVar1 = lVar1 + (longdouble)(((int)ROUND(lVar1 / (longdouble)360.0) * 3 + 3) * 0x78);
  }
  return lVar1;
}


// UTIL_ApproachAngle__Ffff  @ 00117830
longdouble UTIL_ApproachAngle__Ffff(undefined4 param_1,undefined4 param_2,float param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar1 = (longdouble)UTIL_AngleMod__Ff(param_1);
  lVar2 = (longdouble)UTIL_AngleMod__Ff((float)lVar1);
  lVar3 = (longdouble)(float)lVar1 - lVar2;
  if (param_3 < 0.0) {
    param_3 = -param_3;
  }
  if ((longdouble)-180.0 <= lVar3) {
    lVar4 = (longdouble)180.0;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 1) {
      lVar3 = lVar3 - (longdouble)360.0;
    }
  }
  else {
    lVar3 = (longdouble)360.0 + lVar3;
  }
  if (lVar3 <= (longdouble)param_3) {
    if (-(longdouble)param_3 <= lVar3) {
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


// UTIL_Approach__Ffff  @ 001177e0
longdouble UTIL_Approach__Ffff(float param_1,float param_2,float param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  lVar1 = (longdouble)param_1;
  lVar2 = (longdouble)param_2;
  lVar3 = (longdouble)param_3;
  if (lVar1 - lVar2 <= lVar3) {
    if (lVar1 - lVar2 < -lVar3) {
      lVar1 = lVar2 - lVar3;
    }
  }
  else {
    lVar1 = lVar2 + lVar3;
  }
  return lVar1;
}


// UTIL_BloodDecalTrace__FP11TraceResulti  @ 00117da0
void UTIL_BloodDecalTrace__FP11TraceResulti(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = UTIL_ShouldShowBlood__Fi(param_2);
  if (iVar1 != 0) {
    if (param_2 == 0xf7) {
      iVar1 = (*DAT_00175628)(0,5);
      iVar1 = iVar1 + 0xd;
    }
    else {
      iVar1 = (*DAT_00175628)(0,5);
      iVar1 = iVar1 + 0x13;
    }
    UTIL_DecalTrace__FP11TraceResulti(param_1,iVar1);
  }
  return;
}


// UTIL_BloodDrips__FRC6VectorT0ii  @ 00117c00
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
    (*DAT_00175578)(4,0x17,param_1,0);
    (*DAT_00175580)(0x73);
    (*DAT_00175594)(*param_1);
    (*DAT_00175594)(param_1[1]);
    (*DAT_00175594)(param_1[2]);
    (*DAT_00175588)((int)g_sModelIndexBloodSpray);
    (*DAT_00175588)((int)g_sModelIndexBloodDrop);
    (*DAT_00175580)(param_3);
    iVar1 = param_4 / 10;
    if (iVar1 < 3) {
      iVar1 = 3;
    }
    if (iVar1 < 0x10) {
      param_4 = param_4 / 10;
      if (param_4 < 3) {
        param_4 = 3;
      }
    }
    else {
      param_4 = 0x10;
    }
    (*DAT_00175580)(param_4);
    (*DAT_0017557c)();
  }
  return;
}


// UTIL_BloodStream__FRC6VectorT0ii  @ 00117b20
void UTIL_BloodStream__FRC6VectorT0ii
               (undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = UTIL_ShouldShowBlood__Fi(param_3);
  if (iVar1 != 0) {
    if ((g_Language == 1) && (param_3 == 0xf7)) {
      param_3 = 0;
    }
    (*DAT_00175578)(4,0x17,param_1,0);
    (*DAT_00175580)(0x65);
    (*DAT_00175594)(*param_1);
    (*DAT_00175594)(param_1[1]);
    (*DAT_00175594)(param_1[2]);
    (*DAT_00175594)(*param_2);
    (*DAT_00175594)(param_2[1]);
    (*DAT_00175594)(param_2[2]);
    (*DAT_00175580)(param_3);
    if (0xff < param_4) {
      param_4 = 0xff;
    }
    (*DAT_00175580)(param_4);
    (*DAT_0017557c)();
  }
  return;
}


// UTIL_BubbleTrail__FG6VectorT0i  @ 001185d0
void UTIL_BubbleTrail__FG6VectorT0i(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  float local_8;
  
  lVar2 = (longdouble)UTIL_WaterLevel__FRC6Vectorff(param_1,param_1[2],(float)param_1[2] + 256.0);
  lVar2 = lVar2 - (longdouble)(float)param_1[2];
  lVar1 = (longdouble)8.0;
  if ((byte)(lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) == 1) {
    lVar2 = (longdouble)UTIL_WaterLevel__FRC6Vectorff(param_2,param_2[2],(float)param_2[2] + 256.0);
    lVar2 = lVar2 - (longdouble)(float)param_2[2];
    lVar1 = (longdouble)8.0;
    if ((byte)(lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) == 1) {
      return;
    }
    lVar2 = (lVar2 + (longdouble)(float)param_2[2]) - (longdouble)(float)param_1[2];
  }
  local_8 = (float)lVar2;
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(0x72);
  (*DAT_00175594)(*param_1);
  (*DAT_00175594)(param_1[1]);
  (*DAT_00175594)(param_1[2]);
  (*DAT_00175594)(*param_2);
  (*DAT_00175594)(param_2[1]);
  (*DAT_00175594)(param_2[2]);
  (*DAT_00175594)(local_8);
  (*DAT_00175588)((int)g_sModelIndexBubbles);
  (*DAT_00175580)(param_3);
  (*DAT_00175594)(0x41000000);
  (*DAT_0017557c)();
  return;
}


// UTIL_Bubbles__FG6VectorT0i  @ 00118490
void UTIL_Bubbles__FG6VectorT0i(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  longdouble lVar2;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (*param_1 + *param_2) * 0.5;
  local_c = (param_1[1] + param_2[1]) * 0.5;
  local_8 = (param_1[2] + param_2[2]) * 0.5;
  lVar2 = (longdouble)UTIL_WaterLevel__FRC6Vectorff(&local_10,local_8,local_8 + 1024.0);
  fVar1 = param_1[2];
  (*DAT_00175578)(5,0x17,&local_10,0);
  (*DAT_00175580)(0x71);
  (*DAT_00175594)(*param_1);
  (*DAT_00175594)(param_1[1]);
  (*DAT_00175594)(param_1[2]);
  (*DAT_00175594)(*param_2);
  (*DAT_00175594)(param_2[1]);
  (*DAT_00175594)(param_2[2]);
  (*DAT_00175594)((float)(lVar2 - (longdouble)fVar1));
  (*DAT_00175588)((int)g_sModelIndexBubbles);
  (*DAT_00175580)(param_3);
  (*DAT_00175594)(0x41000000);
  (*DAT_0017557c)();
  return;
}


// UTIL_ClampVectorToBox__FRC6VectorT0  @ 00118270
float * UTIL_ClampVectorToBox__FRC6VectorT0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  if (local_10 <= *param_3) {
    if (-*param_3 <= local_10) {
      local_10 = 0.0;
    }
    else {
      local_10 = local_10 + *param_3;
    }
  }
  else {
    local_10 = local_10 - *param_3;
  }
  if (local_c <= param_3[1]) {
    if (-param_3[1] <= local_c) {
      local_c = 0.0;
    }
    else {
      local_c = local_c + param_3[1];
    }
  }
  else {
    local_c = local_c - param_3[1];
  }
  if (local_8 <= param_3[2]) {
    if (-param_3[2] <= local_8) {
      local_8 = 0.0;
    }
    else {
      local_8 = local_8 + param_3[2];
    }
  }
  else {
    local_8 = local_8 - param_3[2];
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
    *param_1 = fVar1 * local_10;
    param_1[1] = fVar1 * local_c;
    param_1[2] = fVar1 * local_8;
  }
  return param_1;
}


// UTIL_ClientPrintAll__FiPCcN41  @ 001172f0
void UTIL_ClientPrintAll__FiPCcN41
               (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
               int param_6)

{
  (*DAT_00175578)(2,gmsgTextMsg,0,0);
  (*DAT_00175580)(param_1);
  (*DAT_00175598)(param_2);
  if (param_3 != 0) {
    (*DAT_00175598)(param_3);
  }
  if (param_4 != 0) {
    (*DAT_00175598)(param_4);
  }
  if (param_5 != 0) {
    (*DAT_00175598)(param_5);
  }
  if (param_6 != 0) {
    (*DAT_00175598)(param_6);
  }
  (*DAT_0017557c)();
  return;
}


// UTIL_ClientProjectile__FRC6VectorT0sii  @ 00118730
void UTIL_ClientProjectile__FRC6VectorT0sii
               (float *param_1,float *param_2,short param_3,uint param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [20];
  undefined1 local_28 [36];
  
  local_4c = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);
  if ((byte)((byte)((ushort)((ushort)NAN(local_4c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_4c == 0.0) << 0xe) >> 8)) == 0x40) {
    local_54 = 0.0;
    local_50 = 0.0;
    local_4c = 1.0;
  }
  else {
    local_4c = 1.0 / local_4c;
    local_54 = local_4c * *param_2;
    local_50 = local_4c * param_2[1];
    local_4c = local_4c * param_2[2];
  }
  local_48 = local_54;
  local_44 = local_50;
  local_40 = local_4c;
  local_58 = *param_1 + local_54 * 4096.0;
  local_54 = param_1[1] + local_50 * 4096.0;
  local_50 = param_1[2] + local_4c * 4096.0;
  uVar1 = (*DAT_001755d4)(param_4,local_3c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(param_1,&local_58,1,uVar1);
  iVar2 = UTIL_PointContents__FRC6Vector(param_1);
  iVar3 = UTIL_PointContents__FRC6Vector(local_28);
  if (iVar2 == iVar3) {
    puVar4 = local_28;
    uVar1 = 4;
  }
  else {
    puVar4 = (undefined1 *)0x0;
    uVar1 = 0;
  }
  (*DAT_00175578)(uVar1,0x17,puVar4,0);
  (*DAT_00175580)(0x77);
  (*DAT_00175594)(*param_1);
  (*DAT_00175594)(param_1[1]);
  (*DAT_00175594)(param_1[2]);
  (*DAT_00175594)(*param_2);
  (*DAT_00175594)(param_2[1]);
  (*DAT_00175594)(param_2[2]);
  (*DAT_00175588)((int)param_3);
  (*DAT_00175580)(param_5);
  (*DAT_00175580)(param_4 & 0xff);
  (*DAT_0017557c)();
  return;
}


// UTIL_DecalTrace__FP11TraceResulti  @ 00117df0
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
  iVar5 = (&DAT_00154ce4)[param_2 * 2];
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
    if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    if ((iVar3 != 0) && (iVar3 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x8c))(iVar3), iVar3 == 0))
    {
      return;
    }
    sVar2 = (*DAT_001755dc)(*(undefined4 *)(param_1 + 0x30));
  }
  uVar4 = 0x68;
  if (sVar2 == 0) {
    uVar4 = 0x74;
    if (iVar5 < 0x100) goto LAB_00117ed8;
    uVar4 = 0x75;
  }
  else {
    if (iVar5 < 0x100) goto LAB_00117ed8;
    uVar4 = 0x76;
  }
  iVar5 = iVar5 + -0x100;
LAB_00117ed8:
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(uVar4);
  (*DAT_00175594)(*(undefined4 *)(param_1 + 0x14));
  (*DAT_00175594)(*(undefined4 *)(param_1 + 0x18));
  (*DAT_00175594)(*(undefined4 *)(param_1 + 0x1c));
  (*DAT_00175580)(iVar5);
  if (sVar2 != 0) {
    (*DAT_00175588)((int)sVar2);
  }
  (*DAT_0017557c)();
  return;
}


// UTIL_DotPoints__FRC6VectorN20  @ 00118b80
longdouble UTIL_DotPoints__FRC6VectorN20(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_28;
  
  local_28 = *param_2 - *param_1;
  fVar1 = param_2[1] - param_1[1];
  fVar2 = SQRT(fVar1 * fVar1 + local_28 * local_28);
  fVar3 = 0.0;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_28 = 0.0;
  }
  else {
    local_28 = (1.0 / fVar2) * local_28;
    fVar3 = (1.0 / fVar2) * fVar1;
  }
  return (longdouble)fVar3 * (longdouble)param_3[1] + (longdouble)local_28 * (longdouble)*param_3;
}


// UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii  @ 00116db0
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
  (*DAT_00175538)(param_1,&local_10,pcVar2,param_4,param_5,param_6,param_7);
  return;
}


// UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i  @ 00116810
int UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i
              (int param_1,int param_2,float *param_3,float *param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar3 = (int *)(*DAT_001755e0)(1);
  iVar6 = 0;
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    for (iVar7 = 1; iVar7 < *(int *)(gpGlobals + 0x94); iVar7 = iVar7 + 1) {
      if ((*piVar3 == 0) &&
         ((((param_5 == 0 || ((param_5 & piVar3[0x98]) != 0)) && (*param_3 <= (float)piVar3[99])) &&
          ((param_3[1] <= (float)piVar3[100] && (param_3[2] <= (float)piVar3[0x65])))))) {
        fVar1 = *param_4;
        fVar2 = (float)piVar3[0x60];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          fVar1 = param_4[1];
          fVar2 = (float)piVar3[0x61];
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            fVar1 = param_4[2];
            fVar2 = (float)piVar3[0x62];
            if ((byte)(fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
              piVar4 = piVar3;
              if ((piVar3 == (int *)0x0) &&
                 (piVar4 = (int *)(*DAT_001755d4)(0), piVar4 == (int *)0x0)) {
                iVar5 = 0;
              }
              else {
                iVar5 = piVar4[0x36];
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
      piVar3 = piVar3 + 0xb2;
    }
  }
  return iVar6;
}


// UTIL_FindEntityByClassname__FP11CBaseEntityPCc  @ 00116b70
void UTIL_FindEntityByClassname__FP11CBaseEntityPCc(undefined4 param_1,undefined4 param_2)

{
  UTIL_FindEntityByString__FP11CBaseEntityPCcT1(param_1,"classname",param_2);
  return;
}


// UTIL_FindEntityByString__FP11CBaseEntityPCcT1  @ 00116af0
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
    uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
  }
  iVar2 = (*DAT_001754f8)(uVar4,param_2,param_3);
  bVar1 = false;
  if (iVar2 == 0) {
LAB_00116b3c:
    bVar1 = true;
  }
  else {
    iVar3 = (*DAT_001755d8)(iVar2);
    if (iVar3 == 0) goto LAB_00116b3c;
  }
  if (bVar1) {
LAB_00116b60:
    uVar4 = 0;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (*DAT_001755d4)(0);
      if (iVar2 == 0) goto LAB_00116b60;
    }
    uVar4 = *(undefined4 *)(iVar2 + 0xd8);
  }
  return uVar4;
}


// UTIL_FindEntityByTargetname__FP11CBaseEntityPCc  @ 00116b90
void UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(undefined4 param_1,undefined4 param_2)

{
  UTIL_FindEntityByString__FP11CBaseEntityPCcT1(param_1,"targetname",param_2);
  return;
}


// UTIL_FindEntityGeneric__FPCcR6Vectorf  @ 00116bb0
int * UTIL_FindEntityGeneric__FPCcR6Vectorf(undefined4 param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  float local_18;
  
  piVar4 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(0,param_1);
  if (piVar4 == (int *)0x0) {
    piVar5 = (int *)0x0;
    local_18 = param_3 * param_3;
    while (piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,param_1),
          piVar5 != (int *)0x0) {
      fVar1 = *(float *)(*piVar5 + 8) - *param_2;
      fVar3 = *(float *)(*piVar5 + 0xc) - param_2[1];
      fVar2 = *(float *)(*piVar5 + 0x10) - param_2[2];
      fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
      fVar1 = fVar1 * fVar1;
      if ((byte)(fVar1 < local_18 |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_18)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == local_18) << 0xe) >> 8)) == 1) {
        piVar4 = piVar5;
        local_18 = fVar1;
      }
    }
  }
  return piVar4;
}


// UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf  @ 00116a70
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
    uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
  }
  iVar2 = (*DAT_00175500)(uVar4,param_2,param_3);
  bVar1 = false;
  if (iVar2 == 0) {
LAB_00116ac1:
    bVar1 = true;
  }
  else {
    iVar3 = (*DAT_001755d8)(iVar2);
    if (iVar3 == 0) goto LAB_00116ac1;
  }
  if (bVar1) {
LAB_00116ae5:
    uVar4 = 0;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (*DAT_001755d4)(0);
      if (iVar2 == 0) goto LAB_00116ae5;
    }
    uVar4 = *(undefined4 *)(iVar2 + 0xd8);
  }
  return uVar4;
}


// UTIL_GetAimVector__FP7edict_sf  @ 00117970
undefined4 *
UTIL_GetAimVector__FP7edict_sf(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (*DAT_00175558)(param_2,param_3,&local_10);
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = local_8;
  return param_1;
}


// UTIL_GetGlobalTrace__Fv  @ 00117600
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


// UTIL_GunshotDecalTrace__FP11TraceResulti  @ 00118030
void UTIL_GunshotDecalTrace__FP11TraceResulti(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  short sVar3;
  
  if (((-1 < param_2) && (iVar2 = (&DAT_00154ce4)[param_2 * 2], -1 < iVar2)) &&
     (fVar1 = *(float *)(param_1 + 0x10),
     (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) {
    (*DAT_00175578)(5,0x17,param_1 + 0x14,0);
    (*DAT_00175580)(0x6d);
    (*DAT_00175594)(*(undefined4 *)(param_1 + 0x14));
    (*DAT_00175594)(*(undefined4 *)(param_1 + 0x18));
    (*DAT_00175594)(*(undefined4 *)(param_1 + 0x1c));
    sVar3 = (*DAT_001755dc)(*(undefined4 *)(param_1 + 0x30));
    (*DAT_00175588)((int)sVar3);
    (*DAT_00175580)(iVar2);
    (*DAT_0017557c)();
  }
  return;
}


// UTIL_IsMasterTriggered__Fi  @ 001179b0
undefined4 UTIL_IsMasterTriggered__Fi(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  if (param_1 != 0) {
    iVar2 = (*DAT_001754f8)(0,"targetname",param_1 + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      if (iVar2 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)(iVar2 + 0xdc);
      }
      iVar3 = strcmp((char *)(*piVar4 + *(int *)(gpGlobals + 0x98)),"multisource");
      if (iVar3 == 0) {
        if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar2 + 0xd8);
        }
        if (iVar2 != 0) {
          uVar5 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x48))(iVar2);
          return uVar5;
        }
      }
    }
    (*DAT_001755b4)(1,"Master was null or not a MultiSource!\n");
  }
  return 1;
}


// UTIL_IsValidEntity__FP7edict_s  @ 00118a50
undefined4 UTIL_IsValidEntity__FP7edict_s(int *param_1)

{
  undefined4 uVar1;
  
  if (((param_1 == (int *)0x0) || (*param_1 != 0)) ||
     ((*(byte *)((int)param_1 + 0x263) & 0x40) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// UTIL_LogPrintf__FPce  @ 00118b50
void UTIL_LogPrintf__FPce(char *param_1)

{
  vsprintf(string_747,param_1,&stack0x00000008);
  (*DAT_001755b4)(5,&DAT_0014cd60,string_747);
  return;
}


// UTIL_MakeAimVectors__FRC6Vector  @ 00116d00
void UTIL_MakeAimVectors__FRC6Vector(float *param_1)

{
  float local_10;
  float local_c;
  float local_8;
  
  local_c = param_1[1];
  local_8 = param_1[2];
  local_10 = -*param_1;
  (*DAT_0017550c)(&local_10);
  return;
}


// UTIL_MakeInvVectors__FRC6VectorP12globalvars_t  @ 00116d30
void UTIL_MakeInvVectors__FRC6VectorP12globalvars_t(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  (*DAT_0017550c)(param_1);
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


// UTIL_MakeVectors__FRC6Vector  @ 00116ce0
void UTIL_MakeVectors__FRC6Vector(undefined4 param_1)

{
  (*DAT_0017550c)(param_1);
  return;
}


// UTIL_MonstersInSphere__FPP11CBaseEntityiRC6Vectorf  @ 00116950
int UTIL_MonstersInSphere__FPP11CBaseEntityiRC6Vectorf
              (int param_1,int param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar3 = (int *)(*DAT_001755e0)(1);
  iVar6 = 0;
  param_4 = param_4 * param_4;
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    for (iVar7 = 1; iVar7 < *(int *)(gpGlobals + 0x94); iVar7 = iVar7 + 1) {
      if ((((*piVar3 == 0) && ((*(byte *)(piVar3 + 0x98) & 0x28) != 0)) &&
          (fVar1 = (*param_3 - (float)piVar3[0x39]) * (*param_3 - (float)piVar3[0x39]),
          fVar1 <= param_4)) &&
         ((fVar1 = (param_3[1] - (float)piVar3[0x3a]) * (param_3[1] - (float)piVar3[0x3a]) + fVar1,
          fVar1 <= param_4 &&
          (fVar2 = param_3[2] - ((float)piVar3[0x62] + (float)piVar3[0x65]) * 0.5,
          fVar2 * fVar2 + fVar1 <= param_4)))) {
        piVar4 = piVar3;
        if ((piVar3 == (int *)0x0) && (piVar4 = (int *)(*DAT_001755d4)(0), piVar4 == (int *)0x0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = piVar4[0x36];
        }
        if (iVar5 != 0) {
          *(int *)(param_1 + iVar6 * 4) = iVar5;
          iVar6 = iVar6 + 1;
          if (param_2 <= iVar6) {
            return iVar6;
          }
        }
      }
      piVar3 = piVar3 + 0xb2;
    }
  }
  return iVar6;
}


// UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi  @ 001167d0
void UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  (*DAT_001754ec)(param_1,&local_10,param_3,param_4);
  return;
}


// UTIL_ParticleEffect__FRC6VectorT0UlUl  @ 00117790
void UTIL_ParticleEffect__FRC6VectorT0UlUl
               (undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  (*DAT_00175568)(param_1,param_2,(float)param_3,(float)param_4);
  return;
}


// UTIL_PlayerByIndex__Fi  @ 00116c60
undefined4 UTIL_PlayerByIndex__Fi(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((0 < param_1) && (param_1 <= *(int *)(gpGlobals + 0x90))) &&
     (iVar1 = (*DAT_001755e0)(param_1), iVar1 != 0)) {
    if (*(char *)(*(int *)(iVar1 + 0x28c) + *(int *)(gpGlobals + 0x98)) == '\0') {
      uVar2 = 0;
    }
    else if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0xd8);
    }
  }
  return uVar2;
}


// UTIL_PlayerDecalTrace__FP11TraceResultiii  @ 00117f60
void UTIL_PlayerDecalTrace__FP11TraceResultiii
               (int param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  short sVar2;
  
  if (((param_4 != 0) || ((-1 < param_3 && (param_3 = (&DAT_00154ce4)[param_3 * 2], -1 < param_3))))
     && (fVar1 = *(float *)(param_1 + 0x10),
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) {
    (*DAT_00175578)(0,0x17,0,0);
    (*DAT_00175580)(0x70);
    (*DAT_00175580)(param_2);
    (*DAT_00175594)(*(undefined4 *)(param_1 + 0x14));
    (*DAT_00175594)(*(undefined4 *)(param_1 + 0x18));
    (*DAT_00175594)(*(undefined4 *)(param_1 + 0x1c));
    sVar2 = (*DAT_001755dc)(*(undefined4 *)(param_1 + 0x30));
    (*DAT_00175588)((int)sVar2);
    (*DAT_00175580)(param_3);
    (*DAT_0017557c)();
  }
  return;
}


// UTIL_PointContents__FRC6Vector  @ 00117b00
void UTIL_PointContents__FRC6Vector(undefined4 param_1)

{
  (*DAT_00175574)(param_1);
  return;
}


// UTIL_PrecacheOtherWeapon__FPCc  @ 0011a620
void UTIL_PrecacheOtherWeapon__FPCc(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  undefined4 *puVar5;
  char *local_30 [4];
  char *local_20;
  int local_10;
  
  iVar2 = (*DAT_0017551c)(param_1 - *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar2 + 0xdc;
    }
    iVar3 = *(int *)(iVar3 + 0x1e8);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0xc))(iVar3);
      memset(local_30,0,0x2c);
      iVar3 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x110))(iVar3,local_30);
      if (iVar3 != 0) {
        ppcVar4 = local_30;
        puVar5 = &_15CBasePlayerItem_ItemInfoArray + local_10 * 0xb;
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *ppcVar4;
          ppcVar4 = ppcVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        if ((local_30[2] != (char *)0x0) && (*local_30[2] != '\0')) {
          AddAmmoNameToAmmoRegistry__FPCc(local_30[2]);
        }
        if ((local_20 != (char *)0x0) && (*local_20 != '\0')) {
          AddAmmoNameToAmmoRegistry__FPCc(local_20);
        }
        memset(local_30,0,0x2c);
      }
    }
    (*DAT_00175518)(iVar2);
    return;
  }
  (*DAT_001755b4)(1,"NULL Ent in UTIL_PrecacheOtherWeapon\n");
  return;
}


// UTIL_PrecacheOther__FPCc  @ 00118a80
void UTIL_PrecacheOther__FPCc(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (*DAT_0017551c)(param_1 - *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar2 + 0xdc;
    }
    iVar3 = *(int *)(iVar3 + 0x1e8);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    if (iVar3 != 0) {
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0xc))(iVar3);
    }
    (*DAT_00175518)(iVar2);
    return;
  }
  (*DAT_001755b4)(1,"NULL Ent in UTIL_PrecacheOther\n");
  return;
}


// UTIL_RandomBloodVector__Fv  @ 00117d40
float * UTIL_RandomBloodVector__Fv(float *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  lVar1 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
  lVar2 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
  lVar3 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
  *param_1 = (float)lVar1;
  param_1[1] = (float)lVar2;
  param_1[2] = (float)lVar3;
  return param_1;
}


// UTIL_Remove__FP11CBaseEntity  @ 00118a20
void UTIL_Remove__FP11CBaseEntity(int *param_1)

{
  if (param_1 != (int *)0x0) {
    UpdateOnRemove__11CBaseEntity(param_1);
    *(byte *)(*param_1 + 0x187) = *(byte *)(*param_1 + 0x187) | 0x40;
    *(undefined4 *)(*param_1 + 0x1ac) = 0;
  }
  return;
}


// UTIL_Ricochet__FRC6Vectorf  @ 00118150
void UTIL_Ricochet__FRC6Vectorf(undefined4 *param_1,float param_2)

{
  (*DAT_00175578)(4,0x17,param_1,0);
  (*DAT_00175580)(0x6f);
  (*DAT_00175594)(*param_1);
  (*DAT_00175594)(param_1[1]);
  (*DAT_00175594)(param_1[2]);
  (*DAT_00175580)((int)ROUND(param_2 * 10.0));
  (*DAT_0017557c)();
  return;
}


// UTIL_ScreenFadeAll__FRC6Vectorffii  @ 00117200
void UTIL_ScreenFadeAll__FRC6Vectorffii
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined1 local_10 [12];
  
  UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii
            (local_10,param_1,param_2,param_3,param_4,param_5);
  piVar1 = (int *)(*DAT_001755e0)(1);
  if ((piVar1 != (int *)0x0) && (iVar2 = 0, 0 < *(int *)(gpGlobals + 0x90))) {
    do {
      if ((*piVar1 == 0) && ((*(byte *)(piVar1 + 0x98) & 8) != 0)) {
        UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s(local_10,piVar1);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0xb2;
    } while (iVar2 < *(int *)(gpGlobals + 0x90));
  }
  return;
}


// UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii  @ 001170c0
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


// UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s  @ 00117170
void UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s(undefined2 *param_1,undefined4 param_2)

{
  (*DAT_00175578)(1,gmsgFade,0,param_2);
  (*DAT_00175588)(*param_1);
  (*DAT_00175588)(param_1[1]);
  (*DAT_00175588)((int)(short)param_1[2]);
  (*DAT_00175580)(*(undefined1 *)(param_1 + 3));
  (*DAT_00175580)(*(undefined1 *)((int)param_1 + 7));
  (*DAT_00175580)(*(undefined1 *)(param_1 + 4));
  (*DAT_00175580)(*(undefined1 *)((int)param_1 + 9));
  (*DAT_0017557c)();
  return;
}


// UTIL_ScreenFade__FP7edict_sRC6Vectorffii  @ 00117290
void UTIL_ScreenFade__FP7edict_sRC6Vectorffii
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined1 auStack_10 [12];
  
  if (((param_1 != (int *)0x0) && (*param_1 == 0)) && ((*(byte *)(param_1 + 0x98) & 8) != 0)) {
    UTIL_ScreenFadeBuild__FR10ScreenFadeRC6Vectorffii
              (auStack_10,param_2,param_3,param_4,param_5,param_6);
    UTIL_ScreenFadeWrite__FR10ScreenFadeP7edict_s(auStack_10,param_1);
  }
  return;
}


// UTIL_ScreenShakeAll__FRC6Vectorfff  @ 00117090
void UTIL_ScreenShakeAll__FRC6Vectorfff
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  UTIL_ScreenShake__FRC6Vectorffff(param_1,param_2,param_3,param_4,0);
  return;
}


// UTIL_ScreenShakeOne__FP7edict_sfff  @ 00116ff0
void UTIL_ScreenShakeOne__FP7edict_sfff
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar1 = FixedUnsigned16__Fff(param_4,0x45800000);
  uVar2 = FixedUnsigned16__Fff(param_3,0x43800000);
  uVar3 = FixedUnsigned16__Fff(param_2,0x45800000);
  (*DAT_00175578)(1,gmsgShake,0,param_1);
  (*DAT_00175588)(uVar3);
  (*DAT_00175588)(uVar1);
  (*DAT_00175588)(uVar2);
  (*DAT_0017557c)();
  return;
}


// UTIL_ScreenShake__FRC6Vectorffff  @ 00116e70
void UTIL_ScreenShake__FRC6Vectorffff
               (float *param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int *piVar6;
  int iVar7;
  
  uVar3 = FixedUnsigned16__Fff(param_4,0x45800000);
  uVar4 = FixedUnsigned16__Fff(param_3,0x43800000);
  piVar6 = (int *)(*DAT_001755e0)(1);
  if (piVar6 != (int *)0x0) {
    for (iVar7 = 0; iVar7 < *(int *)(gpGlobals + 0x90); iVar7 = iVar7 + 1) {
      if (((*piVar6 == 0) && ((*(byte *)(piVar6 + 0x98) & 8) != 0)) &&
         ((*(byte *)((int)piVar6 + 0x261) & 2) != 0)) {
        if ((param_5 <= 0.0) ||
           (fVar2 = SQRT((param_1[2] - (float)piVar6[0x3b]) * (param_1[2] - (float)piVar6[0x3b]) +
                         (param_1[1] - (float)piVar6[0x3a]) * (param_1[1] - (float)piVar6[0x3a]) +
                         (*param_1 - (float)piVar6[0x39]) * (*param_1 - (float)piVar6[0x39])),
           fVar1 = 0.0,
           (byte)(fVar2 < param_5 |
                  (byte)((ushort)((ushort)(NAN(fVar2) || NAN(param_5)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == param_5) << 0xe) >> 8)) == 1)) {
          fVar1 = param_2;
        }
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          uVar5 = FixedUnsigned16__Fff(fVar1,0x45800000);
          (*DAT_00175578)(1,gmsgShake,0,piVar6);
          (*DAT_00175588)(uVar5);
          (*DAT_00175588)(uVar3);
          (*DAT_00175588)(uVar4);
          (*DAT_0017557c)();
        }
      }
      piVar6 = piVar6 + 0xb2;
    }
  }
  return;
}


// UTIL_SetOrigin__FP9entvars_tRC6Vector  @ 00117770
void UTIL_SetOrigin__FP9entvars_tRC6Vector(int param_1,undefined4 param_2)

{
  (*DAT_00175530)(*(undefined4 *)(param_1 + 0x1e8),param_2);
  return;
}


// UTIL_SetSize__FP9entvars_tRC6VectorT1  @ 00117730
void UTIL_SetSize__FP9entvars_tRC6VectorT1(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*DAT_001754d4)(*(undefined4 *)(param_1 + 0x1e8),param_2,param_3);
  return;
}


// UTIL_ShouldShowBlood__Fi  @ 00117aa0
undefined4 UTIL_ShouldShowBlood__Fi(int param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  char *pcVar3;
  
  if (param_1 != -1) {
    if (param_1 == 0xf7) {
      pcVar3 = "violence_hblood";
    }
    else {
      pcVar3 = "violence_ablood";
    }
    lVar2 = (longdouble)(*DAT_001755a4)(pcVar3);
    lVar1 = (longdouble)0;
    if ((byte)(lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) != 0x40) {
      return 1;
    }
  }
  return 0;
}


// UTIL_ShowMessageAll__FPCc  @ 00117500
void UTIL_ShowMessageAll__FPCc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*DAT_001755e0)(1);
  if (iVar1 != 0) {
    for (iVar2 = 0; iVar2 < *(int *)(gpGlobals + 0x90); iVar2 = iVar2 + 1) {
      UTIL_ShowMessage__FPCcP7edict_s(param_1,iVar1);
      iVar1 = iVar1 + 0x2c8;
    }
  }
  return;
}


// UTIL_ShowMessage__FPCcP7edict_s  @ 001174b0
void UTIL_ShowMessage__FPCcP7edict_s(undefined4 param_1,int *param_2)

{
  if (((param_2 != (int *)0x0) && (*param_2 == 0)) && ((*(byte *)(param_2 + 0x98) & 8) != 0)) {
    (*DAT_00175578)(1,gmsgHudText,0,param_2);
    (*DAT_00175598)(param_1);
    (*DAT_0017557c)();
  }
  return;
}


// UTIL_Sparks__FRC6Vector  @ 001180f0
void UTIL_Sparks__FRC6Vector(undefined4 *param_1)

{
  (*DAT_00175578)(4,0x17,param_1,0);
  (*DAT_00175580)(9);
  (*DAT_00175594)(*param_1);
  (*DAT_00175594)(param_1[1]);
  (*DAT_00175594)(param_1[2]);
  (*DAT_0017557c)();
  return;
}


// UTIL_SplineFraction__Fff  @ 00117920
longdouble UTIL_SplineFraction__Fff(float param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)param_1 * (longdouble)param_2;
  lVar2 = lVar1 * lVar1;
  return (longdouble)3.0 * lVar2 - (lVar2 + lVar2) * lVar1;
}


// UTIL_StringToVector__FPfPCc  @ 001181e0
void UTIL_StringToVector__FPfPCc(int param_1,char *param_2)

{
  char *__dest;
  int iVar1;
  longdouble lVar2;
  char local_84 [128];
  
  __dest = local_84;
  strcpy(__dest,param_2);
  iVar1 = 0;
  do {
    lVar2 = (longdouble)__strtod_internal(__dest,0,0);
    *(float *)(param_1 + iVar1 * 4) = (float)lVar2;
    if (*__dest == '\0') break;
    do {
      if (*__dest == ' ') break;
      __dest = __dest + 1;
    } while (*__dest != '\0');
    if (*__dest == '\0') break;
    __dest = __dest + 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  if (iVar1 < 2) {
    while (iVar1 = iVar1 + 1, iVar1 < 3) {
      *(undefined4 *)(param_1 + iVar1 * 4) = 0;
    }
  }
  return;
}


// UTIL_StripToken__FPCcPc  @ 00118c50
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


// UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult  @ 001175c0
void UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  (*DAT_00175548)(param_1,param_2,param_3 == 1,param_4,param_5,param_6);
  return;
}


// UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult  @ 00117550
void UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
               undefined4 param_6)

{
  ushort uVar1;
  
  uVar1 = (ushort)(param_3 == 1);
  if (param_4 != 0) {
    uVar1 = CONCAT11(1,param_3 == 1);
  }
  (*DAT_0017553c)(param_1,param_2,uVar1,param_5,param_6);
  return;
}


// UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult  @ 00117590
void UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5)

{
  (*DAT_0017553c)(param_1,param_2,param_3 == 1,param_4,param_5);
  return;
}


// UTIL_UserTracer__FRC6VectorT0fif  @ 00118910
void UTIL_UserTracer__FRC6VectorT0fif
               (undefined4 *param_1,undefined4 *param_2,float param_3,undefined1 param_4,
               float param_5)

{
  uint local_10;
  
  (*DAT_00175578)(5,0x17,param_1,0);
  (*DAT_00175580)(0x7f);
  (*DAT_00175594)(*param_1);
  (*DAT_00175594)(param_1[1]);
  (*DAT_00175594)(param_1[2]);
  (*DAT_00175594)(*param_2);
  (*DAT_00175594)(param_2[1]);
  (*DAT_00175594)(param_2[2]);
  local_10 = (uint)(longlong)ROUND(param_3 * 10.0);
  (*DAT_00175580)(local_10 & 0xff);
  (*DAT_00175580)(param_4);
  local_10 = (uint)(longlong)ROUND(param_5 * 10.0);
  (*DAT_00175580)(local_10 & 0xff);
  (*DAT_0017557c)();
  return;
}


// UTIL_VarArgs__FPce  @ 00117950
undefined1 * UTIL_VarArgs__FPce(char *param_1)

{
  vsprintf(string_698,param_1,&stack0x00000008);
  return string_698;
}


// UTIL_VecToAngles__FRC6Vector  @ 00116790
undefined4 * UTIL_VecToAngles__FRC6Vector(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (*DAT_001754e8)(param_2,&local_10);
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = local_8;
  return param_1;
}


// UTIL_VecToYaw__FRC6Vector  @ 00117750
void UTIL_VecToYaw__FRC6Vector(undefined4 param_1)

{
  (*DAT_001754e4)(param_1);
  return;
}


// UTIL_WaterLevel__FRC6Vectorff  @ 001183b0
longdouble UTIL_WaterLevel__FRC6Vectorff(undefined4 *param_1,float param_2,float param_3)

{
  float fVar1;
  byte bVar3;
  int iVar2;
  longdouble lVar4;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  local_8 = param_2;
  iVar2 = UTIL_PointContents__FRC6Vector(&local_10);
  if (iVar2 == -3) {
    local_8 = param_3;
    iVar2 = UTIL_PointContents__FRC6Vector(&local_10);
    if (iVar2 == -3) {
      lVar4 = (longdouble)param_3;
    }
    else {
      fVar1 = param_3 - param_2;
      bVar3 = 1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8);
      while (bVar3 == 1) {
        local_8 = fVar1 * 0.5 + param_2;
        iVar2 = UTIL_PointContents__FRC6Vector(&local_10);
        if (iVar2 == -3) {
          param_2 = local_8;
        }
        else {
          param_3 = local_8;
        }
        fVar1 = param_3 - param_2;
        bVar3 = 1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8);
      }
      lVar4 = (longdouble)local_8;
    }
  }
  else {
    lVar4 = (longdouble)param_2;
  }
  return lVar4;
}


// UTIL_dtos1__Fi  @ 00117430
undefined8 * UTIL_dtos1__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_654,"%d",param_1);
  return &buf_654;
}


// UTIL_dtos2__Fi  @ 00117450
undefined8 * UTIL_dtos2__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_657,"%d",param_1);
  return &buf_657;
}


// UTIL_dtos3__Fi  @ 00117470
undefined8 * UTIL_dtos3__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_660,"%d",param_1);
  return &buf_660;
}


// UTIL_dtos4__Fi  @ 00117490
undefined8 * UTIL_dtos4__Fi(undefined4 param_1)

{
  sprintf((char *)&buf_663,"%d",param_1);
  return &buf_663;
}


