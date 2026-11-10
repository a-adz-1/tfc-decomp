// Explode__13CTFEMPGrenadeP11TraceResulti  @ 000fe590
void Explode__13CTFEMPGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),1,"weapons/emp_1.wav",0x3f800000,0x3f4ccccd,0,100);
  (*DAT_00175578)(5,0x17,*param_1 + 8,0);
  (*DAT_00175580)(0x15);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(float *)(*param_1 + 0x10) + 16.0);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)((float)param_1[0x18a] / 0.4 + *(float *)(*param_1 + 0x10) + 16.0);
  (*DAT_00175588)(_13CTFEMPGrenade_BlastTexture);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0);
  (*DAT_00175580)(2);
  (*DAT_00175580)(0x46);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0);
  (*DAT_0017557c)();
  while( true ) {
    iVar1 = UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf(iVar1,*param_1 + 8,param_1[0x18a]);
    if (iVar1 == 0) break;
    (**(code **)(*(int *)(iVar1 + 0x3c8) + 0xf0))(iVar1,*param_1);
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Explode__13CTFGasGrenadeP11TraceResulti  @ 000fe820
void Explode__13CTFGasGrenadeP11TraceResulti(int *param_1)

{
  param_1[0x18b] = 0x14;
  param_1[3] = -0x10000;
  param_1[4] = (int)GasThePlace__13CTFGasGrenade;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


// Explode__14CTFMirvGrenadeP11TraceResulti  @ 000fcfb0
void Explode__14CTFMirvGrenadeP11TraceResulti(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = GetClassPtr__H1Z10CTFBomblet_PX01_PX01(0);
    LaunchFromMirv__10CTFBombletP14CTFMirvGrenade(uVar1,param_1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  Explode__8CGrenadeP11TraceResulti(param_1,param_2,param_3 | 0x4000000);
  return;
}


// Explode__14CTFNailGrenadeP11TraceResulti  @ 000fd3a0
void Explode__14CTFNailGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [20];
  undefined1 local_28 [36];
  
  if (*(int *)(*param_1 + 0x178) == 0) {
    (*DAT_001755d4)(0);
  }
  *(undefined4 *)(*param_1 + 0xe8) = 5;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  iVar1 = *param_1;
  local_48 = *(float *)(iVar1 + 8) + 0.0;
  local_44 = *(float *)(iVar1 + 0xc) + 0.0;
  local_40 = *(float *)(iVar1 + 0x10) + 32.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (iVar1 + 8,&local_48,1,*(undefined4 *)(iVar1 + 0x1e8),local_3c);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,local_28);
  param_1[5] = 0;
  param_1[6] = 0;
  *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x58) = DAT_00175488;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.4;
  param_1[3] = -0x10000;
  param_1[4] = (int)NailGrenadeNailEm__14CTFNailGrenade;
  return;
}


// Explode__16CTFNapalmGrenadeP11TraceResulti  @ 000fdfb0
void Explode__16CTFNapalmGrenadeP11TraceResulti(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  float fVar7;
  int iVar8;
  longdouble lVar9;
  undefined4 uVar10;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  param_1[0x18c] = param_3;
  piVar6 = gpGlobals;
  param_1[0x18e] = *gpGlobals;
  param_1[0x18d] = *piVar6;
  InsertSound__9CSoundEntiRC6Vectorif(1,*param_1 + 8,0x400,0x3f000000);
  iVar8 = *param_1;
  *(undefined4 *)(iVar8 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar8 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar8 + 0x28) = DAT_00175488;
  iVar8 = *param_1;
  uVar10 = *(undefined4 *)(iVar8 + 8);
  uVar1 = *(undefined4 *)(iVar8 + 0xc);
  uVar2 = *(undefined4 *)(iVar8 + 0x10);
  fVar3 = *(float *)(param_2 + 0x10);
  if ((byte)(1.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) != 0x40) {
    fVar3 = *(float *)(iVar8 + 0x1c0);
    if (24.0 <= fVar3) {
      iVar8 = *param_1;
      fVar5 = *(float *)(iVar8 + 0x1c0) - 24.0;
      fVar3 = *(float *)(param_2 + 0x28);
      fVar4 = *(float *)(param_2 + 0x18);
      fVar7 = *(float *)(param_2 + 0x1c) + fVar5 * *(float *)(param_2 + 0x2c) * 0.6;
      *(float *)(iVar8 + 8) = *(float *)(param_2 + 0x14) + fVar5 * *(float *)(param_2 + 0x24) * 0.6;
      *(float *)(iVar8 + 0xc) = fVar4 + fVar5 * fVar3 * 0.6;
    }
    else {
      fVar4 = *(float *)(param_2 + 0x28);
      fVar5 = *(float *)(param_2 + 0x18);
      fVar7 = *(float *)(param_2 + 0x1c) + fVar3 * *(float *)(param_2 + 0x2c) * 0.6;
      *(float *)(iVar8 + 8) = *(float *)(param_2 + 0x14) + fVar3 * *(float *)(param_2 + 0x24) * 0.6;
      *(float *)(iVar8 + 0xc) = fVar5 + fVar3 * fVar4 * 0.6;
    }
    *(float *)(iVar8 + 0x10) = fVar7;
  }
  iVar8 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (iVar8 == -2) {
    iVar8 = *param_1;
    *(undefined4 *)(iVar8 + 8) = uVar10;
    *(undefined4 *)(iVar8 + 0xc) = uVar1;
    *(undefined4 *)(iVar8 + 0x10) = uVar2;
    iVar8 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar8 == -2) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
  }
  param_1[0x186] = 0x41f00000;
  (*DAT_00175578)(5,0x17,*param_1 + 8,0);
  (*DAT_00175580)(3);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175588)((int)g_sModelIndexFireball);
  (*DAT_00175580)((int)ROUND((float)param_1[0x186]));
  (*DAT_00175580)(0xf);
  (*DAT_00175580)(3);
  (*DAT_0017557c)();
  lVar9 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
  if ((longdouble)0.5 <= lVar9) {
    uVar10 = 0xc;
  }
  else {
    uVar10 = 0xb;
  }
  UTIL_DecalTrace__FP11TraceResulti(param_2,uVar10);
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  param_1[3] = -0x10000;
  param_1[4] = (int)Burn__16CTFNapalmGrenade;
  *(int *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


// Explode__16CTFNormalGrenadeP11TraceResulti  @ 000fcbd0
void Explode__16CTFNormalGrenadeP11TraceResulti(undefined4 param_1,undefined4 param_2,uint param_3)

{
  Explode__8CGrenadeP11TraceResulti(param_1,param_2,param_3 | 0x4000000);
  return;
}


// Explode__17CTFCaltropGrenadeP11TraceResulti  @ 000fd990
void Explode__17CTFCaltropGrenadeP11TraceResulti(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  ClientPrint__FP9entvars_tiPCcN42(*(int *)(*param_1 + 0x178) + 0xdc,1,"#Caltrop_exc",0,0,0,0);
  iVar4 = 0;
  do {
    uVar1 = GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(0);
    iVar2 = *(int *)(*param_1 + 0x178);
    if (iVar2 == 0) {
      iVar2 = (*DAT_001755d4)(0);
      if (iVar2 != 0) goto LAB_000fd9e8;
      uVar3 = 0;
    }
    else {
LAB_000fd9e8:
      uVar3 = *(undefined4 *)(iVar2 + 0xd8);
    }
    ScatterDrop__10CTFCaltropP11CBaseEntity(uVar1,uVar3);
    iVar4 = iVar4 + 1;
    if (5 < iVar4) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
  } while( true );
}


// Explode__20CTFConcussionGrenadeP11TraceResulti  @ 000fcc50
void Explode__20CTFConcussionGrenadeP11TraceResulti(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = 0;
  iVar1 = (*DAT_00175628)(0,2);
  if (iVar1 == 1) {
    uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar4 = "weapons/concgren_blast2.wav";
  }
  else if (iVar1 < 2) {
    if (iVar1 != 0) goto LAB_000fccf6;
    uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar4 = "weapons/concgren_blast1.wav";
  }
  else {
    if (iVar1 != 2) goto LAB_000fccf6;
    uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar4 = "weapons/concgren_blast3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar2,1,pcVar4,0x3f800000,0x3f4ccccd,0,100);
LAB_000fccf6:
  (*DAT_00175578)(5,0x17,*param_1 + 8,0);
  (*DAT_00175580)(0x15);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(float *)(*param_1 + 0x10) + 16.0);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)((float)param_1[0x18a] / 0.4 + *(float *)(*param_1 + 0x10) + 16.0);
  (*DAT_00175588)(_20CTFConcussionGrenade_BlastTexture);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0);
  (*DAT_00175580)(2);
  (*DAT_00175580)(0x46);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0);
  (*DAT_0017557c)();
  while (iVar3 = UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                           (iVar3,*param_1 + 8,param_1[0x18a]), iVar3 != 0) {
    (**(code **)(*(int *)(iVar3 + 0x3c8) + 0xf8))(iVar3,*param_1,param_1[0x18a]);
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Explode__8CGrenadeG6VectorT1  @ 000b8c70
void Explode__8CGrenadeG6VectorT1(int *param_1)

{
  int iVar1;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [56];
  
  iVar1 = *param_1;
  local_48 = *(float *)(iVar1 + 8) + 0.0;
  local_44 = *(float *)(iVar1 + 0xc) + 0.0;
  local_40 = *(float *)(iVar1 + 0x10) + -32.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (iVar1 + 8,&local_48,1,*(undefined4 *)(iVar1 + 0x1e8),local_3c);
  (**(code **)(param_1[0xf2] + 0x218))(param_1,local_3c,0x40);
  return;
}


// Explode__8CGrenadeP11TraceResulti  @ 000b8cf0
void Explode__8CGrenadeP11TraceResulti(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  longdouble lVar9;
  char *pcVar10;
  undefined4 uVar11;
  
  *(undefined4 *)(*param_1 + 0x98) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  iVar7 = *param_1;
  uVar11 = *(undefined4 *)(iVar7 + 8);
  uVar1 = *(undefined4 *)(iVar7 + 0xc);
  uVar2 = *(undefined4 *)(iVar7 + 0x10);
  fVar3 = *(float *)(param_2 + 0x10);
  if ((byte)(1.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 1.0) << 0xe) >> 8)) != 0x40) {
    fVar3 = *(float *)(iVar7 + 0x1c0);
    if (24.0 <= fVar3) {
      iVar7 = *param_1;
      fVar5 = *(float *)(iVar7 + 0x1c0) - 24.0;
      fVar3 = *(float *)(param_2 + 0x28);
      fVar4 = *(float *)(param_2 + 0x18);
      fVar6 = *(float *)(param_2 + 0x1c) + fVar5 * *(float *)(param_2 + 0x2c) * 0.6;
      *(float *)(iVar7 + 8) = *(float *)(param_2 + 0x14) + fVar5 * *(float *)(param_2 + 0x24) * 0.6;
      *(float *)(iVar7 + 0xc) = fVar4 + fVar5 * fVar3 * 0.6;
    }
    else {
      fVar4 = *(float *)(param_2 + 0x28);
      fVar5 = *(float *)(param_2 + 0x18);
      fVar6 = *(float *)(param_2 + 0x1c) + fVar3 * *(float *)(param_2 + 0x2c) * 0.6;
      *(float *)(iVar7 + 8) = *(float *)(param_2 + 0x14) + fVar3 * *(float *)(param_2 + 0x24) * 0.6;
      *(float *)(iVar7 + 0xc) = fVar5 + fVar3 * fVar4 * 0.6;
    }
    *(float *)(iVar7 + 0x10) = fVar6;
  }
  iVar7 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (iVar7 == -2) {
    iVar7 = *param_1;
    *(undefined4 *)(iVar7 + 8) = uVar11;
    *(undefined4 *)(iVar7 + 0xc) = uVar1;
    *(undefined4 *)(iVar7 + 0x10) = uVar2;
    iVar7 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar7 == -2) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x186]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x186] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x186] = (int)((*(float *)(*param_1 + 0x1c0) - 50.0) * 0.6);
  }
  (*DAT_00175578)(5,0x17,*param_1 + 8,0);
  (*DAT_00175580)(3);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175588)((int)g_sModelIndexFireball);
  (*DAT_00175580)((int)ROUND((float)param_1[0x186]));
  (*DAT_00175580)(0xf);
  (*DAT_00175580)(3);
  (*DAT_0017557c)();
  InsertSound__9CSoundEntiRC6Vectorif(1,*param_1 + 8,0x400,0x40400000);
  if ((*(int *)(*param_1 + 0x178) == 0) || (iVar8 = *(int *)(*param_1 + 0x178), iVar8 == 0)) {
    iVar8 = 0;
  }
  else {
    iVar8 = iVar8 + 0xdc;
  }
  *(undefined4 *)(*param_1 + 0x178) = 0;
  (**(code **)(param_1[0xf2] + 0x1f8))
            (param_1,*param_1,iVar8,*(undefined4 *)(*param_1 + 0x1c0),0,param_3);
  lVar9 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
  if ((longdouble)0.5 <= lVar9) {
    uVar11 = 0xc;
  }
  else {
    uVar11 = 0xb;
  }
  UTIL_DecalTrace__FP11TraceResulti(param_2,uVar11);
  (*DAT_0017562c)(0,0x3f800000);
  iVar8 = (*DAT_00175628)(0,2);
  if (iVar8 == 1) {
    uVar11 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar10 = "weapons/debris2.wav";
  }
  else if (iVar8 < 2) {
    if (iVar8 != 0) goto LAB_000b9116;
    uVar11 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar10 = "weapons/debris1.wav";
  }
  else {
    if (iVar8 != 2) goto LAB_000b9116;
    uVar11 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar10 = "weapons/debris3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar11,2,pcVar10,0x3f0ccccd,0x3f4ccccd,0,100);
LAB_000b9116:
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  param_1[3] = -0x10000;
  param_1[4] = (int)Smoke__8CGrenade;
  iVar8 = *param_1;
  *(undefined4 *)(iVar8 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar8 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar8 + 0x28) = DAT_00175488;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.3;
  if ((iVar7 != -3) && (param_1[0x184] == 0)) {
    iVar7 = (*DAT_00175628)(0,3);
    iVar8 = 0;
    if (0 < iVar7) {
      do {
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,param_2 + 0x24,0);
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar7);
    }
  }
  return;
}


