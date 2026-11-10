// Explode__10CTFBombletP11TraceResulti  @ 001014e4
void Explode__10CTFBombletP11TraceResulti(int param_1,undefined4 param_2,uint param_3)

{
  undefined2 uVar1;
  
  if (*(short *)(param_1 + 0x6b4) == 0) {
    uVar1 = (*DAT_0019f888)(1,"events/explode/tf_normalgren.sc");
    *(undefined2 *)(param_1 + 0x6b4) = uVar1;
  }
  Explode__8CGrenadeP11TraceResulti(param_1,param_2,param_3 | 0x4000000);
  return;
}


// Explode__13CTFEMPGrenadeP11TraceResulti  @ 00100874
void Explode__13CTFEMPGrenadeP11TraceResulti(void)

{
  FUN_00100882();
  return;
}


// Explode__13CTFGasGrenadeP11TraceResulti  @ 00100e60
void Explode__13CTFGasGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_10);
  if (iVar1 == 0) {
    param_1[0x1b0] = 0x14;
    param_1[3] = -0x10000;
    param_1[4] = (int)GasThePlace__13CTFGasGrenade;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// Explode__14CTFMirvGrenadeP11TraceResulti  @ 0010158c
void Explode__14CTFMirvGrenadeP11TraceResulti(int *param_1,undefined4 param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *param_1;
  local_10 = *(undefined4 *)(iVar2 + 8);
  local_c = *(undefined4 *)(iVar2 + 0xc);
  local_8 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_10);
  if (iVar2 == 0) {
    if ((short)param_1[0x1ad] == 0) {
      uVar1 = (*DAT_0019f888)(1,"events/explode/tf_mirvmain.sc");
      *(undefined2 *)(param_1 + 0x1ad) = uVar1;
    }
    iVar2 = 0;
    do {
      iVar3 = GetClassPtr__H1Z10CTFBomblet_PX01_PX01(0);
      if (iVar3 != 0) {
        uVar1 = (*DAT_0019f888)(1,"events/explode/tf_mirv.sc");
        *(undefined2 *)(iVar3 + 0x6b4) = uVar1;
        LaunchFromMirv__10CTFBombletP14CTFMirvGrenade(iVar3,param_1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    param_3 = param_3 | 0x4000000;
    Explode__8CGrenadeP11TraceResulti(param_1,param_2,param_3);
  }
  return;
}


// Explode__14CTFNailGrenadeP11TraceResulti  @ 000ff688
void Explode__14CTFNailGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  undefined1 local_48 [20];
  undefined1 local_34 [36];
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(float *)(iVar1 + 0x10);
  iVar1 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_10);
  if (iVar1 == 0) {
    if (*(int *)(*param_1 + 0x198) == 0) {
      (*DAT_0019f7b4)(0);
    }
    *(undefined4 *)(*param_1 + 0x108) = 5;
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    iVar1 = *param_1;
    local_8 = *(float *)(iVar1 + 0x10) + 32.0;
    local_10 = *(undefined4 *)(iVar1 + 8);
    local_c = *(undefined4 *)(iVar1 + 0xc);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar1 + 8,&local_10,1,*(undefined4 *)(iVar1 + 0x208),local_48);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,local_34);
    param_1[5] = 0;
    param_1[6] = 0;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
    *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x24) = DAT_0019f664;
    *(undefined4 *)(iVar1 + 0x28) = DAT_0019f668;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.4;
    param_1[3] = -0x10000;
    param_1[4] = (int)NailGrenadeNailEm__14CTFNailGrenade;
  }
  return;
}


// Explode__16CTFNapalmGrenadeP11TraceResulti  @ 001003e0
void Explode__16CTFNapalmGrenadeP11TraceResulti(int *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined2 uVar4;
  int iVar5;
  float fVar6;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar5 = *param_1;
  local_10 = *(undefined4 *)(iVar5 + 8);
  local_c = *(undefined4 *)(iVar5 + 0xc);
  local_8 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_10);
  if (iVar5 == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x16c) = 0;
    param_1[0x1b1] = param_3;
    param_1[0x1b3] = *gpGlobals;
    param_1[0x1b2] = *gpGlobals;
    InsertSound__9CSoundEntiRC6Vectorif(1,*param_1 + 8,0x400,0x3f000000);
    iVar5 = *param_1;
    *(undefined4 *)(iVar5 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar5 + 0x24) = DAT_0019f664;
    *(undefined4 *)(iVar5 + 0x28) = DAT_0019f668;
    iVar5 = *param_1;
    local_10 = *(undefined4 *)(iVar5 + 8);
    local_c = *(undefined4 *)(iVar5 + 0xc);
    local_8 = *(undefined4 *)(iVar5 + 0x10);
    fVar1 = *(float *)(param_2 + 0x10);
    if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = *(float *)(iVar5 + 0x1e0);
      if ((byte)((24.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 24.0) << 0xe) >> 8)) - 1) < 0x40) {
        fVar1 = fVar1 - 24.0;
        fVar2 = *(float *)(param_2 + 0x28);
        fVar3 = *(float *)(param_2 + 0x18);
        fVar6 = fVar1 * *(float *)(param_2 + 0x2c) * 0.6 + *(float *)(param_2 + 0x1c);
        *(float *)(iVar5 + 8) =
             *(float *)(param_2 + 0x24) * fVar1 * 0.6 + *(float *)(param_2 + 0x14);
        *(float *)(iVar5 + 0xc) = fVar2 * fVar1 * 0.6 + fVar3;
      }
      else {
        fVar2 = *(float *)(param_2 + 0x28);
        fVar3 = *(float *)(param_2 + 0x18);
        fVar6 = *(float *)(param_2 + 0x2c) * fVar1 * 0.6 + *(float *)(param_2 + 0x1c);
        *(float *)(iVar5 + 8) =
             *(float *)(param_2 + 0x24) * fVar1 * 0.6 + *(float *)(param_2 + 0x14);
        *(float *)(iVar5 + 0xc) = fVar2 * fVar1 * 0.6 + fVar3;
      }
      *(float *)(iVar5 + 0x10) = fVar6;
    }
    iVar5 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar5 == -2) {
      iVar5 = *param_1;
      *(undefined4 *)(iVar5 + 8) = local_10;
      *(undefined4 *)(iVar5 + 0xc) = local_c;
      *(undefined4 *)(iVar5 + 0x10) = local_8;
      iVar5 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
      if (iVar5 == -2) {
        UTIL_Remove__FP11CBaseEntity(param_1);
        return;
      }
    }
    if ((short)param_1[0x1ad] == 0) {
      uVar4 = (*DAT_0019f888)(1,"events/explode/tf_fire.sc");
      *(undefined2 *)(param_1 + 0x1ad) = uVar4;
    }
    (*DAT_0019f88c)(0,0,(short)param_1[0x1ad],0,*param_1 + 8,&g_vecZero,0,0,0,0,0,0);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    param_1[3] = -0x10000;
    param_1[4] = (int)Burn__16CTFNapalmGrenade;
    *(int *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


// Explode__16CTFNormalGrenadeP11TraceResulti  @ 001019ec
void Explode__16CTFNormalGrenadeP11TraceResulti(int *param_1,undefined4 param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *param_1;
  local_10 = *(undefined4 *)(iVar2 + 8);
  local_c = *(undefined4 *)(iVar2 + 0xc);
  local_8 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_10);
  if (iVar2 == 0) {
    if ((short)param_1[0x1ad] == 0) {
      uVar1 = (*DAT_0019f888)(1,"events/explode/tf_normalgren.sc");
      *(undefined2 *)(param_1 + 0x1ad) = uVar1;
    }
    Explode__8CGrenadeP11TraceResulti(param_1,param_2,param_3 | 0x4000000);
  }
  return;
}


// Explode__17CTFCaltropGrenadeP11TraceResulti  @ 000ffd1c
void Explode__17CTFCaltropGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    local_10 = *(undefined4 *)(iVar1 + 8);
    local_c = *(undefined4 *)(iVar1 + 0xc);
    local_8 = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_10);
    if (iVar1 != 0) {
      return;
    }
  }
  ClientPrint__FP9entvars_siPCcN42(*(int *)(*param_1 + 0x198) + 0x80,1,"#Caltrop_exc",0,0,0,0);
  iVar1 = 0;
  do {
    uVar3 = GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(0);
    iVar4 = *(int *)(*param_1 + 0x198);
    if ((iVar4 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar4 + 0x7c);
    }
    ScatterDrop__10CTFCaltropP11CBaseEntity(uVar3,uVar5);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Explode__20CTFConcussionGrenadeP11TraceResulti  @ 00101800
void Explode__20CTFConcussionGrenadeP11TraceResulti(int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *param_1;
  local_10 = *(undefined4 *)(iVar2 + 8);
  local_c = *(undefined4 *)(iVar2 + 0xc);
  local_8 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = InNoGrenadeZone__8CGrenadeG6Vector(param_1,&local_10);
  if (iVar2 == 0) {
    iVar2 = 0;
    if ((short)param_1[0x1ad] == 0) {
      uVar1 = (*DAT_0019f888)(1,"events/explode/tf_concuss.sc");
      *(undefined2 *)(param_1 + 0x1ad) = uVar1;
    }
    (*DAT_0019f88c)(0,0,(short)param_1[0x1ad],0,*param_1 + 8,&g_vecZero,0,0,0,0,0,0);
    while( true ) {
      iVar2 = UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf(iVar2,*param_1 + 8,param_1[0x1af]);
      if (iVar2 == 0) break;
      (**(code **)(*(int *)(iVar2 + 0x454) + 0x100))(iVar2,*param_1,param_1[0x1af]);
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Explode__8CGrenadeG6VectorT1  @ 000b1e8c
void Explode__8CGrenadeG6VectorT1(int *param_1)

{
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  undefined1 local_3c [56];
  
  iVar1 = *param_1;
  local_40 = *(float *)(iVar1 + 0x10) + -32.0;
  local_48 = *(undefined4 *)(iVar1 + 8);
  local_44 = *(undefined4 *)(iVar1 + 0xc);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (iVar1 + 8,&local_48,1,*(undefined4 *)(iVar1 + 0x208),local_3c);
  (**(code **)(param_1[0x115] + 0x220))(param_1,local_3c,0x40);
  return;
}


// Explode__8CGrenadeP11TraceResulti  @ 000b0828
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Explode__8CGrenadeP11TraceResulti(int *param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  bool bVar9;
  longdouble lVar10;
  longdouble lVar11;
  undefined4 uVar12;
  int local_88;
  int *local_3c;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0xb8) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  iVar5 = *param_1;
  local_10 = *(undefined4 *)(iVar5 + 8);
  local_c = *(undefined4 *)(iVar5 + 0xc);
  local_8 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = *(int *)(iVar5 + 0x198);
  if ((iVar5 == 0) && (iVar5 = (*DAT_0019f7b4)(0), iVar5 == 0)) {
    local_3c = (int *)0x0;
  }
  else {
    local_3c = *(int **)(iVar5 + 0x7c);
  }
  bVar9 = false;
  local_88 = *param_1;
  iVar5 = *local_3c;
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar5 + 8)) || NAN(*(float *)(local_88 + 8)))
                             << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(iVar5 + 8) == *(float *)(local_88 + 8)) << 0xe) >>
                   8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar5 + 0xc)) ||
                                     NAN(*(float *)(local_88 + 0xc))) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar5 + 0xc) == *(float *)(local_88 + 0xc)) << 0xe)
                  >> 8)) == 0x40)) {
    fVar1 = *(float *)(local_88 + 0x10);
    fVar2 = *(float *)(iVar5 + 0x10);
    bVar9 = (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar9) {
    g_iGrenadeInHand = 1;
    local_88 = *param_1;
  }
  fVar1 = *(float *)(param_2 + 0x10);
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = *(float *)(param_2 + 0x28);
    fVar2 = *(float *)(param_2 + 0x2c);
    fVar3 = *(float *)(param_2 + 0x18);
    fVar4 = *(float *)(param_2 + 0x1c);
    *(float *)(local_88 + 8) = *(float *)(param_2 + 0x24) * 32.0 + *(float *)(param_2 + 0x14);
    *(float *)(local_88 + 0xc) = fVar1 * 32.0 + fVar3;
    *(float *)(local_88 + 0x10) = fVar2 * 32.0 + fVar4;
    local_88 = *param_1;
  }
  iVar5 = UTIL_PointContents__FRC6Vector(local_88 + 8);
  if (iVar5 == -2) {
    iVar5 = *param_1;
    *(undefined4 *)(iVar5 + 8) = local_10;
    *(undefined4 *)(iVar5 + 0xc) = local_c;
    *(undefined4 *)(iVar5 + 0x10) = local_8;
    iVar5 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar5 == -2) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
  }
  if ((local_3c[0x48] != param_1[0x48]) && (param_1[0x48] != 0)) {
    UTIL_Remove__FP11CBaseEntity(param_1);
    return;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1aa]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x1aa] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x1aa] = (int)((float)_FUN_0014c170 * (*(float *)(*param_1 + 0x1e0) - 50.0));
  }
  if ((short)param_1[0x1ad] == 0) {
    (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
    (*DAT_0019f760)(3);
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_0019f768)((int)g_sModelIndexFireball);
    (*DAT_0019f760)((int)ROUND((float)param_1[0x1aa]));
    (*DAT_0019f760)(0xf);
    (*DAT_0019f760)(3);
    (*DAT_0019f75c)();
  }
  else {
    (*DAT_0019f88c)(0,0,(short)param_1[0x1ad],0,&local_10,&g_vecZero,0,0,0,0,0,0);
  }
  InsertSound__9CSoundEntiRC6Vectorif(1,*param_1 + 8,0x400,0x40400000);
  iVar7 = 0;
  iVar6 = *(int *)(*param_1 + 0x198);
  if (iVar6 != 0) {
    iVar7 = iVar6 + 0x80;
  }
  *(undefined4 *)(*param_1 + 0x198) = 0;
  (**(code **)(param_1[0x115] + 0x200))
            (param_1,*param_1,iVar7,*(undefined4 *)(*param_1 + 0x1e0),0,param_3);
  g_iGrenadeInHand = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  param_1[3] = -0x10000;
  param_1[4] = (int)Smoke__8CGrenade;
  iVar6 = *param_1;
  *(undefined4 *)(iVar6 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar6 + 0x24) = DAT_0019f664;
  *(undefined4 *)(iVar6 + 0x28) = DAT_0019f668;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  if ((short)param_1[0x1ad] != 0) {
    return;
  }
  lVar10 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
  lVar11 = (longdouble)0.5;
  if ((byte)((lVar11 < lVar10 | (byte)((ushort)((ushort)(NAN(lVar11) || NAN(lVar10)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar11 == lVar10) << 0xe) >> 8)) - 1) < 0x40) {
    uVar12 = 0xc;
  }
  else {
    uVar12 = 0xb;
  }
  UTIL_DecalTrace__FP11TraceResulti(param_2,uVar12);
  (*DAT_0019f80c)(0,0x3f800000);
  iVar6 = (*DAT_0019f808)(0,2);
  if (iVar6 == 1) {
    uVar12 = *(undefined4 *)(*param_1 + 0x208);
    pcVar8 = "weapons/debris2.wav";
  }
  else if (iVar6 < 2) {
    if (iVar6 != 0) goto LAB_000b0dcb;
    uVar12 = *(undefined4 *)(*param_1 + 0x208);
    pcVar8 = "weapons/debris1.wav";
  }
  else {
    if (iVar6 != 2) goto LAB_000b0dcb;
    uVar12 = *(undefined4 *)(*param_1 + 0x208);
    pcVar8 = "weapons/debris3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar12,2,pcVar8,0x3f0ccccd,0x3f4ccccd,0,100);
LAB_000b0dcb:
  if (((iVar5 != -3) && (param_1[0x1a8] == 0)) && (iVar5 = (*DAT_0019f808)(0,3), 0 < iVar5)) {
    iVar6 = 0;
    do {
      Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2 + 0x24,0);
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  return;
}


