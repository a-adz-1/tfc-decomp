// Use__10CBreakableP11CBaseEntityT18USE_TYPEf  @ 000a8bb8
void Use__10CBreakableP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = IsBreakable__10CBreakable(param_1);
  if (iVar1 != 0) {
    *(int *)(*param_1 + 0x54) = param_1[0x117];
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    g_vecAttackDir = *(undefined4 *)(gpGlobals + 0x28);
    DAT_001c0ff0 = *(undefined4 *)(gpGlobals + 0x2c);
    DAT_001c0ff4 = *(undefined4 *)(gpGlobals + 0x30);
    Die__10CBreakable(param_1);
  }
  return;
}


// Use__10CEnvFunnelP11CBaseEntityT18USE_TYPEf  @ 000a527c
void Use__10CEnvFunnelP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  (*DAT_001c10d8)(0,0x17,0,0);
  (*DAT_001c10e0)(100);
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001c10e8)(param_1[0x114]);
  (*DAT_001c10e8)((*(byte *)(*param_1 + 0x1a0) & 1) != 0);
  (*DAT_001c10dc)();
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__10CEnvGlobalP11CBaseEntityT18USE_TYPEf  @ 0008a96c
void Use__10CEnvGlobalP11CBaseEntityT18USE_TYPEf(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = EntityGetState__12CGlobalStatei(&gGlobalState,*(undefined4 *)(param_1 + 0x448));
  switch(*(undefined4 *)(param_1 + 0x44c)) {
  case 0:
    iVar2 = 0;
    break;
  case 2:
    iVar2 = 2;
    break;
  default:
    iVar2 = 0;
    if ((iVar1 == 1) || (iVar2 = iVar1, iVar1 != 0)) break;
  case 1:
    iVar2 = 1;
  }
  iVar1 = Find__12CGlobalStatei(&gGlobalState,*(undefined4 *)(param_1 + 0x448));
  if (iVar1 == 0) {
    EntityAdd__12CGlobalStateii12GLOBALESTATE
              (&gGlobalState,*(undefined4 *)(param_1 + 0x448),*(undefined4 *)(gpGlobals + 0xc),iVar2
              );
  }
  else {
    EntitySetState__12CGlobalStatei12GLOBALESTATE
              (&gGlobalState,*(undefined4 *)(param_1 + 0x448),iVar2);
  }
  return;
}


// Use__10CFuncTrainP11CBaseEntityT18USE_TYPEf  @ 000ce7c4
void Use__10CFuncTrainP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 400) != 0) {
      *(undefined4 *)(iVar2 + 0x1c8) = *(undefined4 *)(*(int *)(iVar2 + 400) + 0x24c);
    }
    *(undefined4 *)(*param_1 + 0x104) = 0;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x24) = DAT_001c0fe4;
    *(undefined4 *)(iVar2 + 0x28) = DAT_001c0fe8;
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1ec) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x208),2,
                 *(int *)(iVar2 + 0x1ec) + *(int *)(gpGlobals + 0x98),param_1[0x13b],0x3f4ccccd,0,
                 100);
    }
  }
  else {
    pbVar1 = (byte *)(*param_1 + 0x1a0);
    *pbVar1 = *pbVar1 & 0xfe;
    Next__10CFuncTrain(param_1);
  }
  return;
}


// Use__10CGunTargetP11CBaseEntityT18USE_TYPEf  @ 000d27d8
void Use__10CGunTargetP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x1a3]);
  if (iVar1 != 0) {
    if (param_1[0x1a3] == 0) {
      *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
      uVar2 = (**(code **)(param_1[0x111] + 0xac))(param_1);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x13d,uVar2);
      iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
      if (iVar1 != 0) {
        *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
        Next__10CGunTarget(param_1);
      }
    }
    else {
      (**(code **)(param_1[0x111] + 0x154))(param_1);
    }
  }
  return;
}


// Use__10CPathTrackP11CBaseEntityT18USE_TYPEf  @ 000cc60c
void Use__10CPathTrackP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  if (param_1[0x116] == 0) {
    bVar2 = (*(byte *)(*param_1 + 0x1a0) ^ 1) & 1;
    iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,bVar2);
    if (iVar1 != 0) {
      if (bVar2 == 0) {
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0xfe;
      }
      else {
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
      }
    }
  }
  else {
    uVar3 = (*(uint *)(*param_1 + 0x1a0) >> 0xf ^ 1) & 1;
    iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,uVar3);
    if (iVar1 != 0) {
      if (uVar3 == 0) {
        *(byte *)(*param_1 + 0x1a1) = *(byte *)(*param_1 + 0x1a1) & 0x7f;
      }
      else {
        *(byte *)(*param_1 + 0x1a1) = *(byte *)(*param_1 + 0x1a1) | 0x80;
      }
    }
  }
  return;
}


// Use__10CTeamCheckP11CBaseEntityT18USE_TYPEf  @ 0010eee8
void Use__10CTeamCheckP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5)

{
  if (param_4 == 3) {
    if (*(int *)(param_1 + 0x120) == 1) {
      *(undefined4 *)(param_1 + 0x120) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0x120) = 1;
    }
  }
  else if (((param_4 == 2) && (1.0 <= param_5)) &&
          ((byte)(4.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_5 == 4.0) << 0xe) >> 8)) != 1)) {
    *(int *)(param_1 + 0x120) = (int)ROUND(param_5);
  }
  return;
}


// Use__11CBaseEntityP11CBaseEntityT18USE_TYPEf  @ 0010f770
void Use__11CBaseEntityP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  code *pcVar1;
  
  if (*(short *)(param_1 + 0x1e) != 0) {
    if (*(short *)(param_1 + 0x1e) < 1) {
      pcVar1 = *(code **)(param_1 + 0x20);
    }
    else {
      pcVar1 = *(code **)(*(int *)(*(short *)(param_1 + 0x20) + param_1) + -4 +
                         *(short *)(param_1 + 0x1e) * 4);
    }
    (*pcVar1)(*(short *)(param_1 + 0x1c) + param_1,param_2,param_3,param_4,param_5);
  }
  return;
}


// Use__11CGibShooterP11CBaseEntityT18USE_TYPEf  @ 000a39b4
void Use__11CGibShooterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)ShootThink__11CGibShooter;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__11CTestEffectP11CBaseEntityT18USE_TYPEf  @ 000a4698
void Use__11CTestEffectP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)TestThink__11CTestEffect;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x146] = (int)*gpGlobals;
  return;
}


// Use__11CWallHealthP11CBaseEntityT18USE_TYPEf  @ 000b6370
void Use__11CWallHealthP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if ((*(byte *)(*param_2 + 0x1a4) & 8) == 0) {
    return;
  }
  if (param_1[0x13c] < 1) {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
    Off__11CWallHealth(param_1);
    if (param_1[0x13c] < 1) goto LAB_000b63d3;
  }
  if (*(int *)(*param_2 + 0x168) < 0) {
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.25;
    param_1[3] = -0x10000;
    param_1[4] = (int)Off__11CWallHealth;
    if (*gpGlobals <= (float)param_1[0x13a]) {
      return;
    }
    if (param_1[0x13d] == 0) {
      param_1[0x13d] = 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"items/medshot4.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      param_1[0x13e] = (int)(*gpGlobals + 0.56);
    }
    if ((param_1[0x13d] == 1) && ((float)param_1[0x13e] <= *gpGlobals)) {
      param_1[0x13d] = 2;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"items/medcharge4.wav",0x3f800000,0x3f4ccccd,0,
                 100);
    }
    iVar1 = (**(code **)(param_2[0x111] + 0x3c))(param_2,0x3f800000,0);
    if (iVar1 != 0) {
      param_1[0x13c] = param_1[0x13c] + -1;
    }
    param_1[0x13a] = (int)(*gpGlobals + 0.1);
    return;
  }
LAB_000b63d3:
  if ((float)param_1[0x13e] <= *gpGlobals) {
    param_1[0x13e] = (int)(*gpGlobals + 0.62);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/medshotno1.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  return;
}


// Use__12CCineMonsterP11CBaseEntityT18USE_TYPEf  @ 000e8088
void Use__12CCineMonsterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar1 + 0x444) + 0x50))(iVar1);
  }
  if (iVar2 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__12CCineMonster;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  else if (*(int *)(iVar2 + 0x684) != 0) {
    param_1[0x1ab] = (int)(*gpGlobals + 0.05);
  }
  return;
}


// Use__12CEnvBeverageP11CBaseEntityT18USE_TYPEf  @ 000a540c
void Use__12CEnvBeverageP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = *param_1;
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x164)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x164) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (0.0 < *(float *)(iVar1 + 0x160))) {
    piVar2 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                              ("item_sodacan",iVar1 + 8,iVar1 + 0x50,*(undefined4 *)(iVar1 + 0x208))
    ;
    if (*(int *)(*param_1 + 0x110) == 6) {
      uVar3 = (*DAT_001c1188)(0,5);
      *(undefined4 *)(*piVar2 + 0x110) = uVar3;
    }
    else {
      *(undefined4 *)(*piVar2 + 0x110) = *(undefined4 *)(*param_1 + 0x110);
    }
    *(undefined4 *)(*param_1 + 0x164) = 0x3f800000;
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - 1.0;
  }
  return;
}


// Use__12CMultiSourceP11CBaseEntityT18USE_TYPEf  @ 0008ac50
void Use__12CMultiSourceP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  if (0 < param_1[0x172]) {
    piVar4 = param_1 + 0x112;
    do {
      iVar3 = iVar3 + 1;
      puVar1 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(piVar4);
      if (puVar1 == param_3) break;
      piVar4 = piVar4 + 2;
    } while (iVar3 < param_1[0x172]);
  }
  if (param_1[0x172] < iVar3) {
    (*DAT_001c1114)(1,"MultiSrc:Used by non member %s.\n",
                    *(int *)*param_3 + *(int *)(gpGlobals + 0x98));
  }
  else {
    *(byte *)(param_1 + iVar3 + 0x151) = *(byte *)(param_1 + iVar3 + 0x151) ^ 1;
    iVar3 = (**(code **)(param_1[0x111] + 0x4c))(param_1);
    if (iVar3 != 0) {
      (*DAT_001c1114)(2,"Multisource %s enabled (%d inputs)\n",
                      *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),param_1[0x172]);
      uVar2 = 3;
      if (param_1[0x173] != 0) {
        uVar2 = 1;
      }
      SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,0,uVar2,0);
    }
  }
  return;
}


// Use__12CRevertSavedP11CBaseEntityT18USE_TYPEf  @ 000df514
void Use__12CRevertSavedP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  UTIL_ScreenFadeAll__FRC6Vectorffii
            (iVar1 + 0x150,*(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1dc),
             (int)ROUND(*(float *)(iVar1 + 0x14c)),1);
  *(float *)(*param_1 + 0x104) = (float)param_1[0x112] + *gpGlobals;
  param_1[3] = -0x10000;
  param_1[4] = (int)MessageThink__12CRevertSaved;
  return;
}


// Use__13CButtonTargetP11CBaseEntityT18USE_TYPEf  @ 0008d70c
void Use__13CButtonTargetP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  
  iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi
                    (param_1,param_4,(int)ROUND(*(float *)(*param_1 + 0x130)));
  if (iVar2 != 0) {
    *(float *)(*param_1 + 0x130) = 1.0 - *(float *)(*param_1 + 0x130);
    fVar1 = *(float *)(*param_1 + 0x130);
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf
              (param_1,param_2,
               (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40,0);
  }
  return;
}


// Use__13CCyclerSpriteP11CBaseEntityT18USE_TYPEf  @ 000b4c20
void Use__13CCyclerSpriteP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[0x112] = (uint)(param_1[0x112] == 0);
  (*DAT_001c1114)(1,"Sprite: %s\n",*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Use__13CEnvExplosionP11CBaseEntityT18USE_TYPEf  @ 000a7718
void Use__13CEnvExplosionP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  undefined4 uVar7;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [16];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_14;
  float local_10;
  float local_c;
  
  *(undefined4 *)(*param_1 + 0xb8) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  iVar4 = *param_1;
  local_5c = *(float *)(iVar4 + 8);
  local_58 = *(float *)(iVar4 + 0xc);
  local_3c = *(float *)(iVar4 + 0x10) + 8.0;
  local_48 = -40.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_54 = local_3c + -40.0;
  local_44 = local_5c;
  local_40 = local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_44,&local_5c,1,*(undefined4 *)(iVar4 + 0x208),local_38);
  if ((byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x10) = *(undefined4 *)(*param_1 + 0x10);
  }
  else {
    iVar4 = *param_1;
    fVar1 = (float)(param_1[0x1a3] + -0x18);
    local_50 = fVar1 * local_14 * 0.6;
    local_4c = fVar1 * local_10 * 0.6;
    local_48 = fVar1 * local_c * 0.6;
    local_5c = local_24 + local_50;
    local_58 = local_20 + local_4c;
    local_54 = local_1c + local_48;
    *(float *)(iVar4 + 8) = local_5c;
    *(float *)(iVar4 + 0xc) = local_58;
    *(float *)(iVar4 + 0x10) = local_54;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0) {
    lVar5 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
    lVar6 = (longdouble)0.5;
    if ((byte)((lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
      uVar7 = 0xc;
    }
    else {
      uVar7 = 0xb;
    }
    UTIL_DecalTrace__FP11TraceResulti(local_38,uVar7);
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 4) == 0) {
    (*DAT_001c10d8)(5,0x17,*param_1 + 8,0);
    (*DAT_001c10e0)(3);
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_001c10e8)((int)g_sModelIndexFireball);
    (*DAT_001c10e0)((char)param_1[0x1a4]);
    (*DAT_001c10e0)(0xf);
    (*DAT_001c10e0)(3);
    (*DAT_001c10dc)();
  }
  else {
    (*DAT_001c10d8)(5,0x17,*param_1 + 8,0);
    (*DAT_001c10e0)(3);
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_001c10e8)((int)g_sModelIndexFireball);
    (*DAT_001c10e0)(0);
    (*DAT_001c10e0)(0xf);
    (*DAT_001c10e0)(3);
    (*DAT_001c10dc)();
  }
  iVar4 = *param_1;
  if (((*(byte *)(iVar4 + 0x1a0) ^ 1) & 1) != 0) {
    (**(code **)(param_1[0x111] + 0x200))(param_1,iVar4,iVar4,(float)param_1[0x1a3],0,0x40);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Smoke__13CEnvExplosion;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
    uVar2 = (*DAT_001c1188)(0,3);
    iVar4 = 0;
    if (0 < (int)uVar2) {
      uVar3 = uVar2 & 3;
      if (uVar3 != 0) {
        if (1 < uVar3) {
          if (2 < uVar3) {
            Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&local_14,0);
          }
          Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&local_14,0);
          iVar4 = (2 < uVar3) + 1;
        }
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&local_14,0);
        iVar4 = iVar4 + 1;
        if ((int)uVar2 <= iVar4) {
          return;
        }
      }
      do {
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&local_14,0);
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&local_14,0);
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&local_14,0);
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&local_14,0);
        iVar4 = iVar4 + 4;
      } while (iVar4 < (int)uVar2);
    }
  }
  return;
}


// Use__13CFuncConveyorP11CBaseEntityT18USE_TYPEf  @ 0008879c
void Use__13CFuncConveyorP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  *(float *)(*param_1 + 0x1f8) = -*(float *)(*param_1 + 0x1f8);
  UpdateSpeed__13CFuncConveyorf(param_1,*(undefined4 *)(*param_1 + 0x1f8));
  return;
}


// Use__13CStripWeaponsP11CBaseEntityT18USE_TYPEf  @ 000df298
void Use__13CStripWeaponsP11CBaseEntityT18USE_TYPEf(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) &&
     (param_2 = (int *)0x0,
     (byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x14)) << 10) >> 8) |
           (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x14) == 0.0) << 0xe) >> 8)) == 0x40)) {
    iVar1 = (*DAT_001c1140)(1);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
      param_2 = (int *)0x0;
    }
    else {
      param_2 = *(int **)(iVar1 + 0x7c);
    }
  }
  if (param_2 != (int *)0x0) {
    RemoveAllItems__11CBasePlayeri(param_2,0);
  }
  return;
}


// Use__13CTriggerRelayP11CBaseEntityT18USE_TYPEf  @ 001111fc
void Use__13CTriggerRelayP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,param_1[0x114],0);
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Use__14CFuncTrackAutoP11CBaseEntityT18USE_TYPEf  @ 000d2094
void Use__14CFuncTrackAutoP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if (*(int *)(param_1 + 0x528) != 0) {
    if (*(int *)(param_1 + 0x464) == 0) {
      iVar2 = *(int *)(param_1 + 0x508);
    }
    else {
      iVar2 = 0;
      if (*(int *)(param_1 + 0x464) == 1) {
        iVar2 = *(int *)(param_1 + 0x50c);
      }
    }
    iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
    if (iVar1 == 0) {
      iVar2 = EvaluateTrain__16CFuncTrackChangeP10CPathTrack(param_1,iVar2);
      *(int *)(param_1 + 0x520) = iVar2;
      if ((iVar2 == 2) && (*(int *)(param_1 + 0x464) != *(int *)(param_1 + 0x524))) {
        *(undefined4 *)(param_1 + 0x528) = 0;
        if (*(int *)(param_1 + 0x464) == 0) {
          pcVar3 = *(code **)(*(int *)(param_1 + 0x444) + 0x114);
        }
        else {
          pcVar3 = *(code **)(*(int *)(param_1 + 0x444) + 0x110);
        }
        (*pcVar3)(param_1);
      }
    }
    else {
      if (iVar2 != 0) {
        iVar2 = GetNext__10CPathTrack(iVar2);
        if ((iVar2 != 0) && (*(int *)(*(int *)(param_1 + 0x510) + 0x448) != iVar2)) {
          iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi
                            (param_1,param_4,*(undefined4 *)(param_1 + 0x524));
          if (iVar2 != 0) {
            if (*(int *)(param_1 + 0x524) == 0) {
              *(undefined4 *)(param_1 + 0x524) = 1;
            }
            else {
              *(undefined4 *)(param_1 + 0x524) = 0;
            }
          }
        }
      }
      (**(code **)(*(int *)(param_1 + 0x444) + 0x120))(param_1,*(undefined4 *)(param_1 + 0x524));
    }
  }
  return;
}


// Use__14CMomentaryDoorP11CBaseEntityT18USE_TYPEf  @ 0009f810
void Use__14CMomentaryDoorP11CBaseEntityT18USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((param_4 == 2) &&
     (((param_2 != 0 &&
       (iVar4 = (**(code **)(*(int *)(param_2 + 0x444) + 0x2c))(param_2), iVar4 != 2)) ||
      (iVar4 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar4 != 0))
     )) {
    if (1.0 < param_5) {
      param_5 = 1.0;
    }
    fStack_14 = param_5 * ((float)param_1[0x124] - (float)param_1[0x121]);
    fStack_10 = param_5 * ((float)param_1[0x125] - (float)param_1[0x122]);
    fStack_c = (float)param_1[0x120] + param_5 * ((float)param_1[0x123] - (float)param_1[0x120]);
    fStack_8 = (float)param_1[0x121] + fStack_14;
    fStack_4 = (float)param_1[0x122] + fStack_10;
    iVar4 = *param_1;
    fVar1 = fStack_c - *(float *)(iVar4 + 8);
    fVar2 = fStack_8 - *(float *)(iVar4 + 0xc);
    fVar3 = fStack_4 - *(float *)(iVar4 + 0x10);
    fStack_18 = SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
    fVar3 = fStack_18 * 10.0;
    if ((byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = *(float *)(iVar4 + 0x104);
      fVar2 = *(float *)(iVar4 + 0x100);
      if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) ||
         ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),6,
                   *(int *)(*param_1 + 0x1ec) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,
                   100);
      }
      fStack_18 = fStack_c;
      fStack_14 = fStack_8;
      fStack_10 = fStack_4;
      LinearMove__11CBaseToggleG6Vectorf(param_1,&fStack_18,fVar3);
    }
  }
  return;
}


// Use__14CTargetCDAudioP11CBaseEntityT18USE_TYPEf  @ 00111ee0
void Use__14CTargetCDAudioP11CBaseEntityT18USE_TYPEf(undefined4 param_1)

{
  Play__14CTargetCDAudio(param_1);
  return;
}


// Use__14CTriggerCameraP11CBaseEntityT18USE_TYPEf  @ 00114aac
void Use__14CTriggerCameraP11CBaseEntityT18USE_TYPEf
               (int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar3 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x122]);
  if (iVar3 != 0) {
    iVar3 = param_1[0x122];
    param_1[0x122] = (uint)(iVar3 == 0);
    if ((iVar3 == 0) == 0) {
      param_1[0x11b] = (int)*gpGlobals;
    }
    else {
      if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) {
        iVar3 = (*DAT_001c1140)(1);
        if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
          param_2 = (int *)0x0;
        }
        else {
          param_2 = *(int **)(iVar3 + 0x7c);
        }
      }
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x114,param_2);
      param_1[0x11b] = (int)(*gpGlobals + (float)param_1[0x11a]);
      *(int *)(*param_1 + 0x1f8) = param_1[0x11f];
      param_1[0x11e] = param_1[0x11f];
      if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
        uVar4 = (**(code **)(param_1[0x111] + 0xac))(param_1);
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x116,uVar4);
      }
      else {
        param_1[0x116] = param_1[0x114];
        param_1[0x117] = param_1[0x115];
      }
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x116);
      if (iVar3 != 0) {
        if ((*(byte *)(*param_1 + 0x1a0) & 4) != 0) {
          EnableControl__11CBasePlayeri(param_2,0);
        }
        if (param_1[0x119] == 0) {
          param_1[0x118] = 0;
        }
        else {
          iVar3 = (*DAT_001c1058)(0,"targetname",param_1[0x119] + (int)gpGlobals[0x26]);
          if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(iVar3 + 0x7c);
          }
          param_1[0x118] = iVar3;
        }
        param_1[0x11c] = (int)*gpGlobals;
        if (param_1[0x118] != 0) {
          fVar1 = *(float *)(*(int *)param_1[0x118] + 0x1f8);
          if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
            param_1[0x11e] = (int)fVar1;
          }
          lVar5 = (longdouble)(**(code **)(*(int *)(param_1[0x118] + 0x444) + 0x68))(param_1[0x118])
          ;
          param_1[0x11c] = (int)(float)(lVar5 + (longdouble)(float)param_1[0x11c]);
        }
        if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
          iVar3 = *param_1;
          fStack_c = 0.0;
          fStack_8 = 0.0;
          fStack_4 = 0.0;
          *(undefined4 *)(iVar3 + 0x20) = 0;
          *(undefined4 *)(iVar3 + 0x24) = 0;
          *(undefined4 *)(iVar3 + 0x28) = 0;
        }
        else {
          iVar3 = *param_2;
          fStack_c = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
          fStack_8 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x178);
          fStack_4 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x17c);
          UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,&fStack_c);
          *(float *)(*param_1 + 0x50) = -*(float *)(*param_2 + 0x50);
          *(undefined4 *)(*param_1 + 0x54) = *(undefined4 *)(*param_2 + 0x54);
          *(undefined4 *)(*param_1 + 0x58) = 0;
          iVar3 = *param_1;
          iVar2 = *param_2;
          *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
          *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
          *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar2 + 0x28);
        }
        (*DAT_001c1190)(*(undefined4 *)(*param_2 + 0x208),*(undefined4 *)(*param_1 + 0x208));
        (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),
                        *(int *)(*param_2 + 0xb8) + (int)gpGlobals[0x26]);
        param_1[3] = -0x10000;
        param_1[4] = (int)FollowTarget__14CTriggerCamera;
        *(float *)(*param_1 + 0x104) = *gpGlobals;
        param_1[0x11d] = 0;
        Move__14CTriggerCamera(param_1);
      }
    }
  }
  return;
}


// Use__15CFuncTrackTrainP11CBaseEntityT18USE_TYPEf  @ 000cf6d8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Use__15CFuncTrackTrainP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (param_4 == 2) {
    fVar1 = param_5 * 0.25 +
            (float)((int)ROUND(*(float *)(*param_1 + 0x1f8) * 4.0) /
                   (int)ROUND((float)param_1[0x115])) * 0.25;
    fVar2 = 1.0;
    if (((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) ||
       (fVar2 = _FUN_0014a440,
       0x3f < (byte)((_FUN_0014a440 < fVar1 |
                      (byte)((ushort)((ushort)(NAN(_FUN_0014a440) || NAN(fVar1)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(_FUN_0014a440 == fVar1) << 0xe) >> 8)) - 1))) {
      fVar1 = fVar2;
    }
    if (((*(byte *)(*param_1 + 0x1a0) & 4) != 0) &&
       (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
      fVar1 = 0.0;
    }
    *(float *)(*param_1 + 0x1f8) = fVar1 * (float)param_1[0x115];
    Next__15CFuncTrackTrain(param_1);
    (*DAT_001c1114)(2,"TRAIN(%s), speed to %.2f\n",
                    *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                    (double)*(float *)(*param_1 + 0x1f8));
  }
  else {
    iVar3 = ShouldToggle__11CBaseEntity8USE_TYPEi
                      (param_1,param_4,
                       (byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x1f8)) << 10) >> 8)
                             | (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1f8) == 0.0) << 0xe)
                                     >> 8)) != 0x40);
    if (iVar3 != 0) {
      fVar1 = *(float *)(*param_1 + 0x1f8);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        *(float *)(*param_1 + 0x1f8) = (float)param_1[0x115] * (float)param_1[0x116];
        Next__15CFuncTrackTrain(param_1);
      }
      else {
        *(undefined4 *)(*param_1 + 0x1f8) = 0;
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x24) = DAT_001c0fe4;
        *(undefined4 *)(iVar3 + 0x28) = DAT_001c0fe8;
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x60) = DAT_001c0fe4;
        *(undefined4 *)(iVar3 + 100) = DAT_001c0fe8;
        StopSound__15CFuncTrackTrain(param_1);
        param_1[3] = 0;
        param_1[4] = 0;
      }
    }
  }
  return;
}


// Use__15CFuncWallToggleP11CBaseEntityT18USE_TYPEf  @ 000885f8
void Use__15CFuncWallToggleP11CBaseEntityT18USE_TYPEf
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = IsOn__15CFuncWallToggle(param_1);
  iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,iVar1);
  if (iVar2 != 0) {
    if (iVar1 == 0) {
      TurnOn__15CFuncWallToggle(param_1);
    }
    else {
      TurnOff__15CFuncWallToggle(param_1);
    }
  }
  return;
}


// Use__15CTriggerCDAudioP11CBaseEntityT18USE_TYPEf  @ 00111cdc
void Use__15CTriggerCDAudioP11CBaseEntityT18USE_TYPEf(undefined4 param_1)

{
  PlayTrack__15CTriggerCDAudio(param_1);
  return;
}


// Use__16CFuncMonsterClipP11CBaseEntityT18USE_TYPEf  @ 0008a564
void Use__16CFuncMonsterClipP11CBaseEntityT18USE_TYPEf(void)

{
  return;
}


// Use__16CFuncTrackChangeP11CBaseEntityT18USE_TYPEf  @ 000d1d7c
void Use__16CFuncTrackChangeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (1 < (uint)param_1[0x119]) {
    return;
  }
  if (param_1[0x119] == 0) {
    iVar1 = param_1[0x142];
  }
  else {
    if (param_1[0x119] != 1) {
      param_1[0x148] = 1;
      goto LAB_000d1dda;
    }
    iVar1 = param_1[0x143];
  }
  iVar1 = EvaluateTrain__16CFuncTrackChangeP10CPathTrack(param_1,iVar1);
  param_1[0x148] = iVar1;
LAB_000d1dda:
  if (param_1[0x148] == 1) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),2,"buttons/button11.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  else {
    param_1[0x14a] = 0;
    if (param_1[0x119] == 0) {
      pcVar2 = *(code **)(param_1[0x111] + 0x114);
    }
    else {
      pcVar2 = *(code **)(param_1[0x111] + 0x110);
    }
    (*pcVar2)(param_1);
  }
  return;
}


// Use__16CRenderFxManagerP11CBaseEntityT18USE_TYPEf  @ 001117a0
void Use__16CRenderFxManagerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar4 = 0;
LAB_001117c8:
    iVar4 = (*DAT_001c1058)(iVar4,"targetname",
                            *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar2 = false;
    if (iVar4 == 0) {
LAB_00111814:
      bVar2 = true;
    }
    else {
      iVar3 = (*DAT_001c1138)(iVar4);
      if (iVar3 == 0) goto LAB_00111814;
    }
    if (!bVar2) {
      iVar3 = iVar4 + 0x80;
      if (iVar4 == 0) {
        iVar3 = 0;
      }
      if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
        *(undefined4 *)(iVar3 + 0x15c) = *(undefined4 *)(*param_1 + 0x15c);
      }
      if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
        *(undefined4 *)(iVar3 + 0x14c) = *(undefined4 *)(*param_1 + 0x14c);
      }
      if ((*(byte *)(*param_1 + 0x1a0) & 4) == 0) {
        *(undefined4 *)(iVar3 + 0x148) = *(undefined4 *)(*param_1 + 0x148);
      }
      iVar1 = *param_1;
      if ((*(byte *)(iVar1 + 0x1a0) & 8) == 0) {
        *(undefined4 *)(iVar3 + 0x150) = *(undefined4 *)(iVar1 + 0x150);
        *(undefined4 *)(iVar3 + 0x154) = *(undefined4 *)(iVar1 + 0x154);
        *(undefined4 *)(iVar3 + 0x158) = *(undefined4 *)(iVar1 + 0x158);
      }
      goto LAB_001117c8;
    }
  }
  return;
}


// Use__17CFuncTankControlsP11CBaseEntityT18USE_TYPEf  @ 000ad19c
void Use__17CFuncTankControlsP11CBaseEntityT18USE_TYPEf
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if (((param_2 == 0) ||
      (iVar1 = (**(code **)(*(int *)(param_2 + 0x444) + 0x2c))(param_2), iVar1 == 2)) &&
     (iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar1 == 0))
  {
    return;
  }
  if (*(int *)(param_1 + 0x448) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x448) + 0x444) + 0xb8))
              (*(int *)(param_1 + 0x448),param_2,param_3,param_4,param_5);
  }
  return;
}


// Use__17CScriptedSentenceP11CBaseEntityT18USE_TYPEf  @ 000e9864
void Use__17CScriptedSentenceP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  if (param_1[0x141] != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)FindThink__17CScriptedSentence;
    *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


// Use__18CLegacyCineMonsterP11CBaseEntityT18USE_TYPEf  @ 000b3e84
void Use__18CLegacyCineMonsterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x134) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)CineThink__18CLegacyCineMonster;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__19CMomentaryRotButtonP11CBaseEntityT18USE_TYPEf  @ 0008cbf4
void Use__19CMomentaryRotButtonP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0x13d);
  *(float *)(*param_1 + 0xac) = (float)(lVar1 / (longdouble)(float)param_1[0x11b]);
  UpdateAllButtons__19CMomentaryRotButtonfi(param_1,*(undefined4 *)(*param_1 + 0xac),1);
  UpdateTarget__19CMomentaryRotButtonf(param_1,*(undefined4 *)(*param_1 + 0xac));
  return;
}


// Use__20CTriggerChangeTargetP11CBaseEntityT18USE_TYPEf  @ 001147c8
void Use__20CTriggerChangeTargetP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                            (0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98))
  ;
  if (piVar1 != (int *)0x0) {
    *(int *)(*piVar1 + 0x1c8) = param_1[0x114];
    iVar2 = (**(code **)(piVar1[0x111] + 0x50))(piVar1);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 4) = 0;
    }
  }
  return;
}


// Use__5CFadeP11CBaseEntityT18USE_TYPEf  @ 000a4e74
void Use__5CFadeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = (*(byte *)(*param_1 + 0x1a0) ^ 1) & 1;
  if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
    bVar2 = bVar2 | 2;
  }
  iVar1 = *param_1;
  UTIL_ScreenFadeAll__FRC6Vectorffii
            (iVar1 + 0x150,*(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1dc),
             (int)ROUND(*(float *)(iVar1 + 0x14c)),bVar2);
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return;
}


// Use__6CBloodP11CBaseEntityT18USE_TYPEf  @ 000a498c
void Use__6CBloodP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  undefined2 in_FPUControlWord;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  undefined1 auStack_6c [16];
  float fStack_5c;
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [8];
  undefined4 uStack_4;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
    Direction__6CBlood(&fStack_18,param_1);
    BloodPosition__6CBloodP11CBaseEntity(auStack_10,param_1,param_1);
    uStack_24 = (float)CONCAT22(uStack_24._2_2_,in_FPUControlWord);
    uStack_2c = CONCAT22(uStack_24._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    UTIL_BloodDrips__FRC6VectorT0ii
              (auStack_10,&fStack_18,*(undefined4 *)(*param_1 + 0x184),
               (int)ROUND(*(float *)(*param_1 + 0x1e0)));
  }
  else {
    Direction__6CBlood(auStack_c,param_1);
    BloodPosition__6CBloodP11CBaseEntity(&fStack_1c,param_1,param_1);
    uStack_24 = (float)CONCAT22(uStack_24._2_2_,in_FPUControlWord);
    uStack_2c = CONCAT22(uStack_24._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    UTIL_BloodStream__FRC6VectorT0ii
              (&fStack_1c,auStack_c,*(undefined4 *)(*param_1 + 0x184),
               (int)ROUND(*(float *)(*param_1 + 0x1e0)));
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 8) != 0) {
    Direction__6CBlood(&fStack_20,param_1);
    BloodPosition__6CBloodP11CBaseEntity(&fStack_18,param_1,uStack_4);
    fVar1 = *(float *)(*param_1 + 0x1e0);
    fStack_78 = fStack_1c + fVar1 * fStack_28 + fVar1 * fStack_28;
    fStack_74 = fStack_18 + fVar1 * uStack_24 + fVar1 * uStack_24;
    fStack_70 = fStack_14 + fVar1 * fStack_20 + fVar1 * fStack_20;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&fStack_18,&fStack_78,1,0,auStack_6c);
    if ((byte)(1.0 < fStack_5c | (byte)((ushort)((ushort)NAN(fStack_5c) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_5c == 1.0) << 0xe) >> 8)) != 0x40) {
      UTIL_BloodDecalTrace__FP11TraceResulti(auStack_6c,*(undefined4 *)(*param_1 + 0x184));
    }
  }
  return;
}


// Use__6CLaserP11CBaseEntityT18USE_TYPEf  @ 000a2c78
void Use__6CLaserP11CBaseEntityT18USE_TYPEf
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = IsOn__6CLaser(param_1);
  iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,iVar1);
  if (iVar2 != 0) {
    if (iVar1 == 0) {
      TurnOn__6CLaser(param_1);
    }
    else {
      TurnOff__6CLaser(param_1);
    }
  }
  return;
}


// Use__6CLightP11CBaseEntityT18USE_TYPEf  @ 000b70d0
void Use__6CLightP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  if (0x1f < param_1[0x112]) {
    iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi
                      (param_1,param_4,(*(byte *)(*param_1 + 0x1a0) ^ 1) & 1);
    if (iVar1 != 0) {
      if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
        (*DAT_001c10cc)(param_1[0x112],&DAT_00147725);
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
      }
      else {
        if (param_1[0x113] == 0) {
          puVar2 = &DAT_00147727;
          iVar1 = param_1[0x112];
        }
        else {
          puVar2 = (undefined *)(param_1[0x113] + *(int *)(gpGlobals + 0x98));
          iVar1 = param_1[0x112];
        }
        (*DAT_001c10cc)(iVar1,puVar2);
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0xfe;
      }
    }
  }
  return;
}


// Use__6CShakeP11CBaseEntityT18USE_TYPEf  @ 000a4d20
void Use__6CShakeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  UTIL_ScreenShake__FRC6Vectorffff
            (iVar1 + 8,*(undefined4 *)(iVar1 + 0x144),*(undefined4 *)(iVar1 + 0x1dc),
             *(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1e0));
  return;
}


// Use__7CCyclerP11CBaseEntityT18USE_TYPEf  @ 000b48c8
void Use__7CCyclerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x1a3];
  param_1[0x1a3] = (uint)(iVar1 == 0);
  if ((iVar1 == 0) == 0) {
    *(undefined4 *)(*param_1 + 0x138) = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  }
  return;
}


// Use__7CSpriteP11CBaseEntityT18USE_TYPEf  @ 000a3728
void Use__7CSpriteP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = *(int *)(*param_1 + 0x118) != 0x80;
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,bVar2);
  if (iVar1 != 0) {
    if (bVar2) {
      TurnOff__7CSprite(param_1);
    }
    else {
      TurnOn__7CSprite(param_1);
    }
  }
  return;
}


// Use__7CTFGoalP11CBaseEntityT18USE_TYPEf  @ 0010e9f4
void Use__7CTFGoalP11CBaseEntityT18USE_TYPEf(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = (**(code **)(*(int *)(param_2 + 0x444) + 0x2c))(param_2);
    if (iVar1 != 2) {
      param_2 = 0;
    }
    if ((param_2 != 0) &&
       (iVar1 = (**(code **)(*(int *)(param_2 + 0x444) + 0x2c))(param_2), iVar1 != 2)) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x27c) = 1;
  ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_3);
  return;
}


// Use__8CMessageP11CBaseEntityT18USE_TYPEf  @ 000a5128
void Use__8CMessageP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
    if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) {
      iVar1 = (*DAT_001c1140)(1);
    }
    else {
      iVar1 = *(int *)(*param_2 + 0x208);
    }
    if (iVar1 != 0) {
      UTIL_ShowMessage__FPCcP7edict_s(*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98),iVar1)
      ;
    }
  }
  else {
    UTIL_ShowMessageAll__FPCc(*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98));
  }
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1e8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),4,*(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98)
               ,*(undefined4 *)(iVar1 + 0x144),*(undefined4 *)(iVar1 + 0x1f8),0,100);
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return;
}


// Use__8CTeamSetP11CBaseEntityT18USE_TYPEf  @ 0010ef94
void Use__8CTeamSetP11CBaseEntityT18USE_TYPEf(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0x120) == 0) {
    fVar2 = 0.0;
    uVar1 = 3;
  }
  else {
    fVar2 = (float)*(int *)(param_1 + 0x120);
    uVar1 = 2;
  }
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2,uVar1,fVar2);
  return;
}


// Use__9CBaseDoorP11CBaseEntityT18USE_TYPEf  @ 0009e308
void Use__9CBaseDoorP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  if (((*(byte *)(param_1 + 0x8a) & 8) == 0) ||
     ((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 8.0) << 0xe) >> 8)) == 0x40)) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x12e,param_2);
    if ((param_1[0x119] != 1) &&
       (((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0 || (param_1[0x119] != 0)))) {
      if ((char)param_1[0x146] != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 0x146) = 1;
    }
    DoorActivate__9CBaseDoor(param_1);
  }
  return;
}


// Use__9CBubblingP11CBaseEntityT18USE_TYPEf  @ 0009fdb0
void Use__9CBubblingP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x115]);
  if (iVar1 != 0) {
    param_1[0x115] = (uint)(param_1[0x115] == 0);
  }
  if (param_1[0x115] == 0) {
    param_1[3] = 0;
    param_1[4] = 0;
    *(undefined4 *)(*param_1 + 0x104) = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)FizzThink__9CBubbling;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// Use__9CFuncTankP11CBaseEntityT18USE_TYPEf  @ 000ab088
void Use__9CFuncTankP11CBaseEntityT18USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,int param_4,float param_5)

{
  byte *pbVar1;
  int iVar2;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
    iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,*(byte *)(*param_1 + 0x1a0) & 1);
    if (iVar2 != 0) {
      if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
        *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
        param_1[0x11f] = 0;
      }
      else {
        pbVar1 = (byte *)(*param_1 + 0x1a0);
        *pbVar1 = *pbVar1 & 0xfe;
        param_1[0x11f] = 0;
        StopRotSound__9CFuncTank(param_1);
      }
    }
  }
  else {
    iVar2 = (**(code **)(*(int *)(param_2 + 0x444) + 0x2c))(param_2);
    if (iVar2 == 2) {
      iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar2 != 0) {
        if (((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_5 == 2.0) << 0xe) >> 8)) == 0x40) &&
           (param_4 == 2)) {
          ControllerPostFrame__9CFuncTank(param_1);
        }
        else if ((param_1[0x112] == 0) && (param_4 != 0)) {
          __as__7EHANDLEP11CBaseEntity(param_2 + 0x864,param_1);
          StartControl__9CFuncTankP11CBasePlayer(param_1,param_2);
        }
        else {
          StopControl__9CFuncTank(param_1);
        }
      }
    }
  }
  return;
}


// Use__9CFuncWallP11CBaseEntityT18USE_TYPEf  @ 000884b4
void Use__9CFuncWallP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi
                    (param_1,param_4,(int)ROUND(*(float *)(*param_1 + 0x130)));
  if (iVar1 != 0) {
    *(float *)(*param_1 + 0x130) = 1.0 - *(float *)(*param_1 + 0x130);
  }
  return;
}


// Use__9CPushableP11CBaseEntityT18USE_TYPEf  @ 000a9ee0
void Use__9CPushableP11CBaseEntityT18USE_TYPEf
               (int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  float fVar1;
  bool bVar2;
  
  if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) {
    if (*(char *)(*param_1 + 0x1a0) < '\0') {
      Use__10CBreakableP11CBaseEntityT18USE_TYPEf(param_1,param_2,param_3,param_4,param_5);
    }
  }
  else {
    bVar2 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_2 + 0x20))) << 10)
                      >> 8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_2 + 0x20)) << 0xe) >> 8)) ==
         0x40) &&
       (fVar1 = *(float *)(*param_2 + 0x24),
       (byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(DAT_001c0fe4 == fVar1) << 0xe) >> 8)) == 0x40)) {
      fVar1 = *(float *)(*param_2 + 0x28);
      bVar2 = (byte)(DAT_001c0fe8 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar2) {
      Move__9CPushableP11CBaseEntityi(param_1,param_2,0);
    }
  }
  return;
}


// Use__9CRechargeP11CBaseEntityT18USE_TYPEf  @ 000b379c
void Use__9CRechargeP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  iVar4 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"player");
  if (iVar4 != 0) {
    return;
  }
  if (param_1[0x13c] < 1) {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
    Off__9CRecharge(param_1);
    if (param_1[0x13c] < 1) goto LAB_000b3814;
  }
  if (*(int *)(*param_2 + 0x168) < 0) {
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.25;
    param_1[3] = -0x10000;
    param_1[4] = (int)Off__9CRecharge;
    if (*gpGlobals <= (float)param_1[0x13a]) {
      return;
    }
    if (param_2 == (int *)0x0) {
      return;
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x12e,param_2);
    piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x12e);
    if ((*(byte *)(*piVar5 + 0x1a4) & 8) == 0) {
      return;
    }
    if (param_1[0x13d] == 0) {
      param_1[0x13d] = 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"items/suitchargeok1.wav",0x3f59999a,0x3f4ccccd
                 ,0,100);
      param_1[0x13e] = (int)(*gpGlobals + 0.56);
    }
    if ((param_1[0x13d] == 1) && ((float)param_1[0x13e] <= *gpGlobals)) {
      param_1[0x13d] = 2;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"items/suitcharge1.wav",0x3f59999a,0x3f4ccccd,0
                 ,100);
    }
    piVar5 = param_1 + 0x12e;
    piVar6 = (int *)__rf__7EHANDLE(piVar5);
    iVar4 = *piVar6;
    iVar7 = __rf__7EHANDLE(piVar5);
    if (*(float *)(iVar4 + 0x1bc) < *(float *)(iVar7 + 0xf0)) {
      param_1[0x13c] = param_1[0x13c] + -1;
      piVar6 = (int *)__rf__7EHANDLE(piVar5);
      *(float *)(*piVar6 + 0x1bc) = *(float *)(*piVar6 + 0x1bc) + 1.0;
      piVar6 = (int *)__rf__7EHANDLE(piVar5);
      iVar4 = *piVar6;
      iVar7 = __rf__7EHANDLE(piVar5);
      fVar1 = *(float *)(iVar4 + 0x1bc);
      fVar2 = *(float *)(iVar7 + 0xf0);
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        piVar6 = (int *)__rf__7EHANDLE(piVar5);
        iVar4 = __rf__7EHANDLE(piVar5);
        *(undefined4 *)(*piVar6 + 0x1bc) = *(undefined4 *)(iVar4 + 0xf0);
      }
      piVar5 = param_1 + 0x12e;
      piVar6 = (int *)__rf__7EHANDLE(piVar5);
      iVar4 = *piVar6;
      piVar6 = (int *)__rf__7EHANDLE(piVar5);
      if (*(float *)(*piVar6 + 0x1b8) <= 0.8) {
        uVar3 = 0x3f4ccccd;
      }
      else {
        piVar5 = (int *)__rf__7EHANDLE(piVar5);
        uVar3 = *(undefined4 *)(*piVar5 + 0x1b8);
      }
      *(undefined4 *)(iVar4 + 0x1b8) = uVar3;
    }
    param_1[0x13a] = (int)(*gpGlobals + 0.1);
    return;
  }
LAB_000b3814:
  if ((float)param_1[0x13e] <= *gpGlobals) {
    param_1[0x13e] = (int)(*gpGlobals + 0.62);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/suitchargeno1.wav",0x3f59999a,0x3f4ccccd,0
               ,100);
  }
  return;
}


