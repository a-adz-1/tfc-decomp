// Explode__10CTFBombletP11TraceResulti  @ 000fd698
void Explode__10CTFBombletP11TraceResulti(int param_1,undefined4 param_2,uint param_3)

{
  undefined2 uVar1;
  
  if (*(short *)(param_1 + 0x6a4) == 0) {
    uVar1 = (*DAT_001c1208)(1,"events/explode/tf_normalgren.sc");
    *(undefined2 *)(param_1 + 0x6a4) = uVar1;
  }
  Explode__8CGrenadeP11TraceResulti(param_1,param_2,param_3 | 0x4000000);
  return;
}


// Explode__13CTFEMPGrenadeP11TraceResulti  @ 000feeb0
void Explode__13CTFEMPGrenadeP11TraceResulti(int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = 0;
  iVar2 = *param_1;
  local_c = *(undefined4 *)(iVar2 + 8);
  local_8 = *(undefined4 *)(iVar2 + 0xc);
  local_4 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_c);
  if (iVar2 == 0) {
    if ((short)param_1[0x1a9] == 0) {
      uVar1 = (*DAT_001c1208)(1,"events/explode/tf_emp.sc");
      *(undefined2 *)(param_1 + 0x1a9) = uVar1;
    }
    (*DAT_001c120c)(0,0,(short)param_1[0x1a9],0,*param_1 + 8,&g_vecZero,0,0,0,0,0,0);
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    while( true ) {
      iVar3 = UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf(iVar3,*param_1 + 8,param_1[0x1ab]);
      if (iVar3 == 0) break;
      (**(code **)(*(int *)(iVar3 + 0x444) + 0xf8))(iVar3,*param_1);
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Explode__13CTFGasGrenadeP11TraceResulti  @ 000ff0d8
void Explode__13CTFGasGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = *param_1;
  local_c = *(undefined4 *)(iVar1 + 8);
  uStack_8 = *(undefined4 *)(iVar1 + 0xc);
  uStack_4 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_c);
  if (iVar1 == 0) {
    param_1[0x1ac] = 0x14;
    param_1[3] = -0x10000;
    param_1[4] = (int)GasThePlace__13CTFGasGrenade;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// Explode__14CTFMirvGrenadeP11TraceResulti  @ 000fd2a0
void Explode__14CTFMirvGrenadeP11TraceResulti(int *param_1,undefined4 param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *param_1;
  local_c = *(undefined4 *)(iVar2 + 8);
  local_8 = *(undefined4 *)(iVar2 + 0xc);
  local_4 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_c);
  if (iVar2 == 0) {
    if ((short)param_1[0x1a9] == 0) {
      uVar1 = (*DAT_001c1208)(1,"events/explode/tf_mirvmain.sc");
      *(undefined2 *)(param_1 + 0x1a9) = uVar1;
    }
    iVar2 = GetClassPtr__H1Z10CTFBomblet_PX01_PX01(0);
    if (iVar2 != 0) {
      uVar1 = (*DAT_001c1208)(1,"events/explode/tf_mirv.sc");
      *(undefined2 *)(iVar2 + 0x6a4) = uVar1;
      LaunchFromMirv__10CTFBombletP14CTFMirvGrenade(iVar2,param_1);
    }
    iVar2 = GetClassPtr__H1Z10CTFBomblet_PX01_PX01(0);
    if (iVar2 != 0) {
      uVar1 = (*DAT_001c1208)(1,"events/explode/tf_mirv.sc");
      *(undefined2 *)(iVar2 + 0x6a4) = uVar1;
      LaunchFromMirv__10CTFBombletP14CTFMirvGrenade(iVar2,param_1);
    }
    iVar2 = GetClassPtr__H1Z10CTFBomblet_PX01_PX01(0);
    if (iVar2 != 0) {
      uVar1 = (*DAT_001c1208)(1,"events/explode/tf_mirv.sc");
      *(undefined2 *)(iVar2 + 0x6a4) = uVar1;
      LaunchFromMirv__10CTFBombletP14CTFMirvGrenade(iVar2,param_1);
    }
    iVar2 = GetClassPtr__H1Z10CTFBomblet_PX01_PX01(0);
    if (iVar2 != 0) {
      uVar1 = (*DAT_001c1208)(1,"events/explode/tf_mirv.sc");
      *(undefined2 *)(iVar2 + 0x6a4) = uVar1;
      LaunchFromMirv__10CTFBombletP14CTFMirvGrenade(iVar2,param_1);
    }
    Explode__8CGrenadeP11TraceResulti(param_1,param_2,param_3 | 0x4000000);
  }
  return;
}


// Explode__14CTFNailGrenadeP11TraceResulti  @ 000fd908
void Explode__14CTFNailGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  undefined1 local_44 [20];
  undefined1 local_30 [36];
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar1 = *param_1;
  local_c = *(undefined4 *)(iVar1 + 8);
  local_8 = *(undefined4 *)(iVar1 + 0xc);
  local_4 = *(float *)(iVar1 + 0x10);
  iVar1 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_c);
  if (iVar1 == 0) {
    if (*(int *)(*param_1 + 0x198) == 0) {
      (*DAT_001c1134)(0);
    }
    *(undefined4 *)(*param_1 + 0x108) = 5;
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    iVar1 = *param_1;
    local_c = *(undefined4 *)(iVar1 + 8);
    local_8 = *(undefined4 *)(iVar1 + 0xc);
    local_4 = *(float *)(iVar1 + 0x10) + 32.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar1 + 8,&local_c,1,*(undefined4 *)(iVar1 + 0x208),local_44);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,local_30);
    param_1[5] = 0;
    param_1[6] = 0;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x54) = DAT_001c0fe4;
    *(undefined4 *)(iVar1 + 0x58) = DAT_001c0fe8;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x24) = DAT_001c0fe4;
    *(undefined4 *)(iVar1 + 0x28) = DAT_001c0fe8;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.4;
    param_1[3] = -0x10000;
    param_1[4] = (int)NailGrenadeNailEm__14CTFNailGrenade;
  }
  return;
}


// Explode__16CTFNapalmGrenadeP11TraceResulti  @ 000fe8cc
void Explode__16CTFNapalmGrenadeP11TraceResulti(int *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined2 uVar4;
  int iVar5;
  float fVar6;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar5 = *param_1;
  local_c = *(undefined4 *)(iVar5 + 8);
  local_8 = *(undefined4 *)(iVar5 + 0xc);
  local_4 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_c);
  if (iVar5 == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x16c) = 0;
    param_1[0x1ad] = param_3;
    param_1[0x1af] = *gpGlobals;
    param_1[0x1ae] = *gpGlobals;
    InsertSound__9CSoundEntiRC6Vectorif(1,*param_1 + 8,0x400,0x3f000000);
    iVar5 = *param_1;
    *(undefined4 *)(iVar5 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar5 + 0x24) = DAT_001c0fe4;
    *(undefined4 *)(iVar5 + 0x28) = DAT_001c0fe8;
    iVar5 = *param_1;
    local_c = *(undefined4 *)(iVar5 + 8);
    local_8 = *(undefined4 *)(iVar5 + 0xc);
    local_4 = *(undefined4 *)(iVar5 + 0x10);
    fVar1 = *(float *)(param_2 + 0x10);
    if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = *(float *)(iVar5 + 0x1e0);
      if ((byte)((24.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 24.0) << 0xe) >> 8)) - 1) < 0x40) {
        iVar5 = *param_1;
        fVar3 = *(float *)(iVar5 + 0x1e0) - 24.0;
        fVar1 = *(float *)(param_2 + 0x28);
        fVar2 = *(float *)(param_2 + 0x18);
        fVar6 = *(float *)(param_2 + 0x1c) + fVar3 * *(float *)(param_2 + 0x2c) * 0.6;
        *(float *)(iVar5 + 8) =
             *(float *)(param_2 + 0x14) + fVar3 * *(float *)(param_2 + 0x24) * 0.6;
        *(float *)(iVar5 + 0xc) = fVar2 + fVar3 * fVar1 * 0.6;
      }
      else {
        fVar2 = *(float *)(param_2 + 0x28);
        fVar3 = *(float *)(param_2 + 0x18);
        fVar6 = *(float *)(param_2 + 0x1c) + fVar1 * *(float *)(param_2 + 0x2c) * 0.6;
        *(float *)(iVar5 + 8) =
             *(float *)(param_2 + 0x14) + fVar1 * *(float *)(param_2 + 0x24) * 0.6;
        *(float *)(iVar5 + 0xc) = fVar3 + fVar1 * fVar2 * 0.6;
      }
      *(float *)(iVar5 + 0x10) = fVar6;
    }
    iVar5 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar5 == -2) {
      iVar5 = *param_1;
      *(undefined4 *)(iVar5 + 8) = local_c;
      *(undefined4 *)(iVar5 + 0xc) = local_8;
      *(undefined4 *)(iVar5 + 0x10) = local_4;
      iVar5 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
      if (iVar5 == -2) {
        UTIL_Remove__FP11CBaseEntity(param_1);
        return;
      }
    }
    if ((short)param_1[0x1a9] == 0) {
      uVar4 = (*DAT_001c1208)(1,"events/explode/tf_fire.sc");
      *(undefined2 *)(param_1 + 0x1a9) = uVar4;
    }
    (*DAT_001c120c)(0,0,(short)param_1[0x1a9],0,*param_1 + 8,&g_vecZero,0,0,0,0,0,0);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    param_1[3] = -0x10000;
    param_1[4] = (int)Burn__16CTFNapalmGrenade;
    *(int *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


// Explode__16CTFNormalGrenadeP11TraceResulti  @ 000fcf10
void Explode__16CTFNormalGrenadeP11TraceResulti(int *param_1,undefined4 param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *param_1;
  local_c = *(undefined4 *)(iVar2 + 8);
  local_8 = *(undefined4 *)(iVar2 + 0xc);
  local_4 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_c);
  if (iVar2 == 0) {
    if ((short)param_1[0x1a9] == 0) {
      uVar1 = (*DAT_001c1208)(1,"events/explode/tf_normalgren.sc");
      *(undefined2 *)(param_1 + 0x1a9) = uVar1;
    }
    Explode__8CGrenadeP11TraceResulti(param_1,param_2,param_3 | 0x4000000);
  }
  return;
}


// Explode__17CTFCaltropGrenadeP11TraceResulti  @ 000fe0c4
void Explode__17CTFCaltropGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    local_c = *(undefined4 *)(iVar1 + 8);
    local_8 = *(undefined4 *)(iVar1 + 0xc);
    local_4 = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_c);
    if (iVar1 != 0) {
      return;
    }
  }
  ClientPrint__FP9entvars_siPCcN42(*(int *)(*param_1 + 0x198) + 0x80,1,"#Caltrop_exc",0,0,0,0);
  iVar1 = 0;
  do {
    uVar3 = GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(0);
    iVar4 = *(int *)(*param_1 + 0x198);
    if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar4 + 0x7c);
    }
    ScatterDrop__10CTFCaltropP11CBaseEntity(uVar3,uVar5);
    uVar3 = GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(0);
    iVar4 = *(int *)(*param_1 + 0x198);
    if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar4 + 0x7c);
    }
    ScatterDrop__10CTFCaltropP11CBaseEntity(uVar3,uVar5);
    uVar3 = GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(0);
    iVar4 = *(int *)(*param_1 + 0x198);
    if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar4 + 0x7c);
    }
    ScatterDrop__10CTFCaltropP11CBaseEntity(uVar3,uVar5);
    iVar1 = iVar1 + 3;
  } while (iVar1 < 6);
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Explode__20CTFConcussionGrenadeP11TraceResulti  @ 000fd014
void Explode__20CTFConcussionGrenadeP11TraceResulti(int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *param_1;
  local_c = *(undefined4 *)(iVar2 + 8);
  local_8 = *(undefined4 *)(iVar2 + 0xc);
  local_4 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_c);
  if (iVar2 == 0) {
    iVar2 = 0;
    if ((short)param_1[0x1a9] == 0) {
      uVar1 = (*DAT_001c1208)(1,"events/explode/tf_concuss.sc");
      *(undefined2 *)(param_1 + 0x1a9) = uVar1;
    }
    (*DAT_001c120c)(0,0,(short)param_1[0x1a9],0,*param_1 + 8,&g_vecZero,0,0,0,0,0,0);
    while( true ) {
      iVar2 = UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf(iVar2,*param_1 + 8,param_1[0x1ab]);
      if (iVar2 == 0) break;
      (**(code **)(*(int *)(iVar2 + 0x444) + 0x100))(iVar2,*param_1,param_1[0x1ab]);
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Explode__8CGrenadeG6VectorT1  @ 000b0d74
void Explode__8CGrenadeG6VectorT1(int *param_1)

{
  int iVar1;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  undefined1 local_38 [56];
  
  iVar1 = *param_1;
  local_44 = *(undefined4 *)(iVar1 + 8);
  local_40 = *(undefined4 *)(iVar1 + 0xc);
  local_3c = *(float *)(iVar1 + 0x10) + -32.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (iVar1 + 8,&local_44,1,*(undefined4 *)(iVar1 + 0x208),local_38);
  (**(code **)(param_1[0x111] + 0x220))(param_1,local_38,0x40);
  return;
}


// Explode__8CGrenadeP11TraceResulti  @ 000b0f90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Explode__8CGrenadeP11TraceResulti(int *param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  code *pcVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  longdouble lVar13;
  longdouble lVar14;
  undefined4 uVar15;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0xb8) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  iVar6 = *param_1;
  local_c = *(undefined4 *)(iVar6 + 8);
  local_8 = *(undefined4 *)(iVar6 + 0xc);
  local_4 = *(undefined4 *)(iVar6 + 0x10);
  iVar6 = *(int *)(iVar6 + 0x198);
  if ((iVar6 == 0) && (iVar6 = (*DAT_001c1134)(0), iVar6 == 0)) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = *(int **)(iVar6 + 0x7c);
  }
  iVar6 = *param_1;
  bVar12 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(*piVar9 + 8)) || NAN(*(float *)(iVar6 + 8)))
                             << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(*piVar9 + 8) == *(float *)(iVar6 + 8)) << 0xe) >> 8
                   )) == 0x40) &&
     (fVar1 = *(float *)(*piVar9 + 0xc),
     (byte)((byte)((ushort)((ushort)(NAN(fVar1) || NAN(*(float *)(iVar6 + 0xc))) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == *(float *)(iVar6 + 0xc)) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(iVar6 + 0x10);
    fVar2 = *(float *)(*piVar9 + 0x10);
    bVar12 = (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar12) {
    g_iGrenadeInHand = 1;
  }
  fVar1 = *(float *)(param_2 + 0x10);
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
    iVar6 = *param_1;
    fVar1 = *(float *)(param_2 + 0x28);
    fVar2 = *(float *)(param_2 + 0x2c);
    fVar3 = *(float *)(param_2 + 0x18);
    fVar4 = *(float *)(param_2 + 0x1c);
    *(float *)(iVar6 + 8) = *(float *)(param_2 + 0x14) + *(float *)(param_2 + 0x24) * 32.0;
    *(float *)(iVar6 + 0xc) = fVar3 + fVar1 * 32.0;
    *(float *)(iVar6 + 0x10) = fVar4 + fVar2 * 32.0;
  }
  iVar6 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (iVar6 == -2) {
    iVar6 = *param_1;
    *(undefined4 *)(iVar6 + 8) = local_c;
    *(undefined4 *)(iVar6 + 0xc) = local_8;
    *(undefined4 *)(iVar6 + 0x10) = local_4;
    iVar6 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar6 == -2) goto LAB_000b1207;
  }
  if ((piVar9[0x48] != param_1[0x48]) && (param_1[0x48] != 0)) {
LAB_000b1207:
    UTIL_Remove__FP11CBaseEntity(param_1);
    return;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1a6]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x1a6] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x1a6] = (int)((float)_FUN_00146b80 * (*(float *)(*param_1 + 0x1e0) - 50.0));
  }
  if ((short)param_1[0x1a9] == 0) {
    (*DAT_001c10d8)(5,0x17,*param_1 + 8,0);
    (*DAT_001c10e0)(3);
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_001c10e8)((int)g_sModelIndexFireball);
    (*DAT_001c10e0)((int)ROUND((float)param_1[0x1a6]));
    (*DAT_001c10e0)(0xf);
    (*DAT_001c10e0)(3);
    (*DAT_001c10dc)();
  }
  else {
    (*DAT_001c120c)(0,0,(short)param_1[0x1a9],0,&local_c,&g_vecZero,0,0,0,0,0,0);
  }
  InsertSound__9CSoundEntiRC6Vectorif(1,*param_1 + 8,0x400,0x40400000);
  if ((*(int *)(*param_1 + 0x198) == 0) ||
     (iVar5 = *(int *)(*param_1 + 0x198), iVar11 = iVar5 + 0x80, iVar5 == 0)) {
    iVar11 = 0;
  }
  *(undefined4 *)(*param_1 + 0x198) = 0;
  (**(code **)(param_1[0x111] + 0x200))
            (param_1,*param_1,iVar11,*(undefined4 *)(*param_1 + 0x1e0),0,param_3);
  g_iGrenadeInHand = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  param_1[3] = -0x10000;
  param_1[4] = (int)Smoke__8CGrenade;
  iVar11 = *param_1;
  *(undefined4 *)(iVar11 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar11 + 0x24) = DAT_001c0fe4;
  *(undefined4 *)(iVar11 + 0x28) = DAT_001c0fe8;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  if ((short)param_1[0x1a9] != 0) {
    return;
  }
  lVar13 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
  lVar14 = (longdouble)0.5;
  if ((byte)((lVar14 < lVar13 | (byte)((ushort)((ushort)(NAN(lVar14) || NAN(lVar13)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar14 == lVar13) << 0xe) >> 8)) - 1) < 0x40) {
    uVar15 = 0xc;
  }
  else {
    uVar15 = 0xb;
  }
  UTIL_DecalTrace__FP11TraceResulti(param_2,uVar15);
  (*DAT_001c118c)(0,0x3f800000);
  iVar11 = (*DAT_001c1188)(0,2);
  if (iVar11 == 1) {
    uVar15 = *(undefined4 *)(*param_1 + 0x208);
    pcVar8 = (code *)"weapons/debris2.wav";
  }
  else if (iVar11 < 2) {
    if (iVar11 != 0) goto LAB_000b171f;
    uVar15 = *(undefined4 *)(*param_1 + 0x208);
    pcVar8 = (code *)0x146b28;
  }
  else {
    if (iVar11 != 2) goto LAB_000b171f;
    uVar15 = *(undefined4 *)(*param_1 + 0x208);
    pcVar8 = FUN_00146b50;
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar15,2,pcVar8,0x3f0ccccd,0x3f4ccccd,0,100);
LAB_000b171f:
  if (iVar6 == -3) {
    return;
  }
  if (param_1[0x1a4] != 0) {
    return;
  }
  uVar7 = (*DAT_001c1188)(0,3);
  iVar6 = 0;
  if ((int)uVar7 < 1) {
    return;
  }
  param_2 = param_2 + 0x24;
  uVar10 = uVar7 & 3;
  if (uVar10 != 0) {
    if (1 < uVar10) {
      if (2 < uVar10) {
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2,0);
      }
      Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2,0);
      iVar6 = (2 < uVar10) + 1;
    }
    Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2,0);
    iVar6 = iVar6 + 1;
    if ((int)uVar7 <= iVar6) {
      return;
    }
  }
  do {
    Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2,0);
    Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2,0);
    Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2,0);
    Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2,0);
    iVar6 = iVar6 + 4;
  } while (iVar6 < (int)uVar7);
  return;
}


