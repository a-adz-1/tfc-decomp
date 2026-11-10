// Use__10CBreakableP11CBaseEntityT18USE_TYPEf  @ 0009e1e0
void Use__10CBreakableP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = IsBreakable__10CBreakable(param_1);
  if (iVar1 != 0) {
    *(int *)(*param_1 + 0x54) = param_1[0xfb];
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    g_vecAttackDir = *(undefined4 *)(gpGlobals + 0x28);
    DAT_001a7e10 = *(undefined4 *)(gpGlobals + 0x2c);
    DAT_001a7e14 = *(undefined4 *)(gpGlobals + 0x30);
    Die__10CBreakable(param_1);
  }
  return;
}


// Use__10CEnvFunnelP11CBaseEntityT18USE_TYPEf  @ 0009acfc
void Use__10CEnvFunnelP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  (*DAT_001a7ef8)(0,0x17,0,0);
  (*DAT_001a7f00)(100);
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001a7f08)(param_1[0xf8]);
  (*DAT_001a7f08)((*(byte *)(*param_1 + 0x1a0) & 1) != 0);
  (*DAT_001a7efc)();
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__10CEnvGlobalP11CBaseEntityT18USE_TYPEf  @ 00082968
void Use__10CEnvGlobalP11CBaseEntityT18USE_TYPEf(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = EntityGetState__12CGlobalStatei(&gGlobalState,*(undefined4 *)(param_1 + 0x3d8));
  switch(*(undefined4 *)(param_1 + 0x3dc)) {
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
  iVar1 = Find__12CGlobalStatei(&gGlobalState,*(undefined4 *)(param_1 + 0x3d8));
  if (iVar1 == 0) {
    EntityAdd__12CGlobalStateii12GLOBALESTATE
              (&gGlobalState,*(undefined4 *)(param_1 + 0x3d8),*(undefined4 *)(gpGlobals + 0xc),iVar2
              );
  }
  else {
    EntitySetState__12CGlobalStatei12GLOBALESTATE
              (&gGlobalState,*(undefined4 *)(param_1 + 0x3d8),iVar2);
  }
  return;
}


// Use__10CFuncTrainP11CBaseEntityT18USE_TYPEf  @ 000c3464
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
    *(undefined4 *)(iVar2 + 0x24) = DAT_001a7e04;
    *(undefined4 *)(iVar2 + 0x28) = DAT_001a7e08;
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1ec) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x208),2,
                 *(int *)(iVar2 + 0x1ec) + *(int *)(gpGlobals + 0x98),param_1[0x11f],0x3f4ccccd,0,
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


// Use__10CGunTargetP11CBaseEntityT18USE_TYPEf  @ 000c7478
void Use__10CGunTargetP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x187]);
  if (iVar1 != 0) {
    if (param_1[0x187] == 0) {
      *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
      uVar2 = (**(code **)(param_1[0xf5] + 0xa4))(param_1);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x121,uVar2);
      iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
      if (iVar1 != 0) {
        *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
        Next__10CGunTarget(param_1);
      }
    }
    else {
      (**(code **)(param_1[0xf5] + 0x14c))(param_1);
    }
  }
  return;
}


// Use__10CPathTrackP11CBaseEntityT18USE_TYPEf  @ 000c12ec
void Use__10CPathTrackP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  if (param_1[0xfa] == 0) {
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


// Use__11CBaseEntityP11CBaseEntityT18USE_TYPEf  @ 00100468
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


// Use__11CGibShooterP11CBaseEntityT18USE_TYPEf  @ 00099434
void Use__11CGibShooterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)ShootThink__11CGibShooter;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__11CTestEffectP11CBaseEntityT18USE_TYPEf  @ 0009a118
void Use__11CTestEffectP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)TestThink__11CTestEffect;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x12a] = (int)*gpGlobals;
  return;
}


// Use__11CWallHealthP11CBaseEntityT18USE_TYPEf  @ 000ab2d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Use__11CWallHealthP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if ((*(byte *)(*param_2 + 0x1a4) & 8) == 0) {
    return;
  }
  if (param_1[0x120] < 1) {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
    Off__11CWallHealth(param_1);
    if (param_1[0x120] < 1) goto LAB_000ab333;
  }
  if (*(int *)(*param_2 + 0x168) < 0) {
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.25;
    param_1[3] = -0x10000;
    param_1[4] = (int)Off__11CWallHealth;
    if (*gpGlobals <= (float)param_1[0x11e]) {
      return;
    }
    if (param_1[0x121] == 0) {
      param_1[0x121] = 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"items/medshot4.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      param_1[0x122] = (int)(*gpGlobals + 0.56);
    }
    if ((param_1[0x121] == 1) && ((float)param_1[0x122] <= *gpGlobals)) {
      param_1[0x121] = 2;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"items/medcharge4.wav",0x3f800000,0x3f4ccccd,0,
                 100);
    }
    iVar1 = (**(code **)(param_2[0xf5] + 0x38))(param_2,0x3f800000,0);
    if (iVar1 != 0) {
      param_1[0x120] = param_1[0x120] + -1;
    }
    param_1[0x11e] = (int)(*gpGlobals + 0.1);
    return;
  }
LAB_000ab333:
  if ((float)param_1[0x122] <= *gpGlobals) {
    param_1[0x122] = (int)((float)_FUN_00136bc0 + *gpGlobals);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/medshotno1.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  return;
}


// Use__12CCineMonsterP11CBaseEntityT18USE_TYPEf  @ 000dbfec
void Use__12CCineMonsterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x4c))(iVar1);
  }
  if (iVar2 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__12CCineMonster;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  else if (*(int *)(iVar2 + 0x614) != 0) {
    param_1[399] = (int)(*gpGlobals + 0.05);
  }
  return;
}


// Use__12CEnvBeverageP11CBaseEntityT18USE_TYPEf  @ 0009ae8c
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
      uVar3 = (*DAT_001a7fa8)(0,5);
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


// Use__12CMultiSourceP11CBaseEntityT18USE_TYPEf  @ 00082c4c
void Use__12CMultiSourceP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  if (0 < param_1[0x156]) {
    piVar4 = param_1 + 0xf6;
    do {
      iVar3 = iVar3 + 1;
      puVar1 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(piVar4);
      if (puVar1 == param_3) break;
      piVar4 = piVar4 + 2;
    } while (iVar3 < param_1[0x156]);
  }
  if (param_1[0x156] < iVar3) {
    (*DAT_001a7f34)(1,"MultiSrc:Used by non member %s.\n",
                    *(int *)*param_3 + *(int *)(gpGlobals + 0x98));
  }
  else {
    *(byte *)(param_1 + iVar3 + 0x135) = *(byte *)(param_1 + iVar3 + 0x135) ^ 1;
    iVar3 = (**(code **)(param_1[0xf5] + 0x48))(param_1);
    if (iVar3 != 0) {
      (*DAT_001a7f34)(2,"Multisource %s enabled (%d inputs)\n",
                      *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),param_1[0x156]);
      uVar2 = 3;
      if (param_1[0x157] != 0) {
        uVar2 = 1;
      }
      SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,0,uVar2,0);
    }
  }
  return;
}


// Use__12CRevertSavedP11CBaseEntityT18USE_TYPEf  @ 000d3e10
void Use__12CRevertSavedP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  UTIL_ScreenFadeAll__FRC6Vectorffii
            (iVar1 + 0x150,*(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1dc),
             (int)ROUND(*(float *)(iVar1 + 0x14c)),1);
  *(float *)(*param_1 + 0x104) = (float)param_1[0xf6] + *gpGlobals;
  param_1[3] = -0x10000;
  param_1[4] = (int)MessageThink__12CRevertSaved;
  return;
}


// Use__13CButtonTargetP11CBaseEntityT18USE_TYPEf  @ 00085708
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


// Use__13CCyclerSpriteP11CBaseEntityT18USE_TYPEf  @ 000a9c50
void Use__13CCyclerSpriteP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[0xf6] = (uint)(param_1[0xf6] == 0);
  (*DAT_001a7f34)(1,"Sprite: %s\n",*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Use__13CEnvExplosionP11CBaseEntityT18USE_TYPEf  @ 0009cd80
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
    fVar1 = (float)(param_1[0x187] + -0x18);
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
    lVar5 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
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
    (*DAT_001a7ef8)(5,0x17,*param_1 + 8,0);
    (*DAT_001a7f00)(3);
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_001a7f08)((int)g_sModelIndexFireball);
    (*DAT_001a7f00)((char)param_1[0x188]);
    (*DAT_001a7f00)(0xf);
    (*DAT_001a7f00)(3);
    (*DAT_001a7efc)();
  }
  else {
    (*DAT_001a7ef8)(5,0x17,*param_1 + 8,0);
    (*DAT_001a7f00)(3);
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_001a7f08)((int)g_sModelIndexFireball);
    (*DAT_001a7f00)(0);
    (*DAT_001a7f00)(0xf);
    (*DAT_001a7f00)(3);
    (*DAT_001a7efc)();
  }
  iVar4 = *param_1;
  if (((*(byte *)(iVar4 + 0x1a0) ^ 1) & 1) != 0) {
    (**(code **)(param_1[0xf5] + 0x1f8))(param_1,iVar4,iVar4,(float)param_1[0x187],0,0x40);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Smoke__13CEnvExplosion;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
    uVar2 = (*DAT_001a7fa8)(0,3);
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


// Use__13CFuncConveyorP11CBaseEntityT18USE_TYPEf  @ 00080878
void Use__13CFuncConveyorP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  *(float *)(*param_1 + 0x1f8) = -*(float *)(*param_1 + 0x1f8);
  UpdateSpeed__13CFuncConveyorf(param_1,*(undefined4 *)(*param_1 + 0x1f8));
  return;
}


// Use__13CStripWeaponsP11CBaseEntityT18USE_TYPEf  @ 000d3b94
void Use__13CStripWeaponsP11CBaseEntityT18USE_TYPEf(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) &&
     (param_2 = (int *)0x0,
     (byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x14)) << 10) >> 8) |
           (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x14) == 0.0) << 0xe) >> 8)) == 0x40)) {
    iVar1 = (*DAT_001a7f60)(1);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
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


// Use__13CTriggerRelayP11CBaseEntityT18USE_TYPEf  @ 00101b4c
void Use__13CTriggerRelayP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,param_1[0xf8],0);
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Use__14CFuncTrackAutoP11CBaseEntityT18USE_TYPEf  @ 000c6d34
void Use__14CFuncTrackAutoP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if (*(int *)(param_1 + 0x4b8) != 0) {
    if (*(int *)(param_1 + 0x3f4) == 0) {
      iVar2 = *(int *)(param_1 + 0x498);
    }
    else {
      iVar2 = 0;
      if (*(int *)(param_1 + 0x3f4) == 1) {
        iVar2 = *(int *)(param_1 + 0x49c);
      }
    }
    iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
    if (iVar1 == 0) {
      iVar2 = EvaluateTrain__16CFuncTrackChangeP10CPathTrack(param_1,iVar2);
      *(int *)(param_1 + 0x4b0) = iVar2;
      if ((iVar2 == 2) && (*(int *)(param_1 + 0x3f4) != *(int *)(param_1 + 0x4b4))) {
        *(undefined4 *)(param_1 + 0x4b8) = 0;
        if (*(int *)(param_1 + 0x3f4) == 0) {
          pcVar3 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x10c);
        }
        else {
          pcVar3 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x108);
        }
        (*pcVar3)(param_1);
      }
    }
    else {
      if (iVar2 != 0) {
        iVar2 = GetNext__10CPathTrack(iVar2);
        if ((iVar2 != 0) && (*(int *)(*(int *)(param_1 + 0x4a0) + 0x3d8) != iVar2)) {
          iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi
                            (param_1,param_4,*(undefined4 *)(param_1 + 0x4b4));
          if (iVar2 != 0) {
            if (*(int *)(param_1 + 0x4b4) == 0) {
              *(undefined4 *)(param_1 + 0x4b4) = 1;
            }
            else {
              *(undefined4 *)(param_1 + 0x4b4) = 0;
            }
          }
        }
      }
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x118))(param_1,*(undefined4 *)(param_1 + 0x4b4));
    }
  }
  return;
}


// Use__14CMomentaryDoorP11CBaseEntityT18USE_TYPEf  @ 00095310
void Use__14CMomentaryDoorP11CBaseEntityT18USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((param_4 == 2) &&
     (((param_2 != 0 &&
       (iVar4 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x28))(param_2), iVar4 != 2)) ||
      (iVar4 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar4 != 0))
     )) {
    if (1.0 < param_5) {
      param_5 = 1.0;
    }
    local_14 = param_5 * ((float)param_1[0x108] - (float)param_1[0x105]);
    local_10 = param_5 * ((float)param_1[0x109] - (float)param_1[0x106]);
    fStack_c = (float)param_1[0x104] + param_5 * ((float)param_1[0x107] - (float)param_1[0x104]);
    fStack_8 = (float)param_1[0x105] + local_14;
    fStack_4 = (float)param_1[0x106] + local_10;
    iVar4 = *param_1;
    fVar1 = fStack_c - *(float *)(iVar4 + 8);
    fVar2 = fStack_8 - *(float *)(iVar4 + 0xc);
    fVar3 = fStack_4 - *(float *)(iVar4 + 0x10);
    local_18 = SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
    fVar3 = local_18 * 10.0;
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
      local_18 = fStack_c;
      local_14 = fStack_8;
      local_10 = fStack_4;
      LinearMove__11CBaseToggleG6Vectorf(param_1,&local_18,fVar3);
    }
  }
  return;
}


// Use__14CTargetCDAudioP11CBaseEntityT18USE_TYPEf  @ 00102830
void Use__14CTargetCDAudioP11CBaseEntityT18USE_TYPEf(undefined4 param_1)

{
  Play__14CTargetCDAudio(param_1);
  return;
}


// Use__14CTriggerCameraP11CBaseEntityT18USE_TYPEf  @ 001053fc
void Use__14CTriggerCameraP11CBaseEntityT18USE_TYPEf
               (int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x106]);
  if (iVar3 != 0) {
    iVar3 = param_1[0x106];
    param_1[0x106] = (uint)(iVar3 == 0);
    if ((iVar3 == 0) == 0) {
      param_1[0xff] = (int)*gpGlobals;
    }
    else {
      if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) {
        iVar3 = (*DAT_001a7f60)(1);
        if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
          param_2 = (int *)0x0;
        }
        else {
          param_2 = *(int **)(iVar3 + 0x7c);
        }
      }
      __as__7EHANDLEP11CBaseEntity(param_1 + 0xf8,param_2);
      param_1[0xff] = (int)(*gpGlobals + (float)param_1[0xfe]);
      *(int *)(*param_1 + 0x1f8) = param_1[0x103];
      param_1[0x102] = param_1[0x103];
      if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
        uVar4 = (**(code **)(param_1[0xf5] + 0xa4))(param_1);
        __as__7EHANDLEP11CBaseEntity(param_1 + 0xfa,uVar4);
      }
      else {
        param_1[0xfa] = param_1[0xf8];
        param_1[0xfb] = param_1[0xf9];
      }
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0xfa);
      if (iVar3 != 0) {
        if ((*(byte *)(*param_1 + 0x1a0) & 4) != 0) {
          EnableControl__11CBasePlayeri(param_2,0);
        }
        if (param_1[0xfd] == 0) {
          param_1[0xfc] = 0;
        }
        else {
          iVar3 = (*DAT_001a7e78)(0,"targetname",param_1[0xfd] + (int)gpGlobals[0x26]);
          if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(iVar3 + 0x7c);
          }
          param_1[0xfc] = iVar3;
        }
        param_1[0x100] = (int)*gpGlobals;
        if (param_1[0xfc] != 0) {
          fVar1 = *(float *)(*(int *)param_1[0xfc] + 0x1f8);
          if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
            param_1[0x102] = (int)fVar1;
          }
          lVar5 = (longdouble)(**(code **)(*(int *)(param_1[0xfc] + 0x3d4) + 100))(param_1[0xfc]);
          param_1[0x100] = (int)(float)(lVar5 + (longdouble)(float)param_1[0x100]);
        }
        if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
          iVar3 = *param_1;
          local_c = 0.0;
          local_8 = 0.0;
          local_4 = 0.0;
          *(undefined4 *)(iVar3 + 0x20) = 0;
          *(undefined4 *)(iVar3 + 0x24) = 0;
          *(undefined4 *)(iVar3 + 0x28) = 0;
        }
        else {
          iVar3 = *param_2;
          local_c = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
          local_8 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x178);
          local_4 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x17c);
          UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,&local_c);
          *(float *)(*param_1 + 0x50) = -*(float *)(*param_2 + 0x50);
          *(undefined4 *)(*param_1 + 0x54) = *(undefined4 *)(*param_2 + 0x54);
          *(undefined4 *)(*param_1 + 0x58) = 0;
          iVar3 = *param_1;
          iVar2 = *param_2;
          *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
          *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
          *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar2 + 0x28);
        }
        (*DAT_001a7fb0)(*(undefined4 *)(*param_2 + 0x208),*(undefined4 *)(*param_1 + 0x208));
        (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                        *(int *)(*param_2 + 0xb8) + (int)gpGlobals[0x26]);
        param_1[3] = -0x10000;
        param_1[4] = (int)FollowTarget__14CTriggerCamera;
        *(float *)(*param_1 + 0x104) = *gpGlobals;
        param_1[0x101] = 0;
        Move__14CTriggerCamera(param_1);
      }
    }
  }
  return;
}


// Use__15CFuncTrackTrainP11CBaseEntityT18USE_TYPEf  @ 000c4378
void Use__15CFuncTrackTrainP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (param_4 == 2) {
    fVar1 = param_5 * 0.25 +
            (float)((int)ROUND(*(float *)(*param_1 + 0x1f8) * 4.0) /
                   (int)ROUND((float)param_1[0xf9])) * 0.25;
    fVar2 = 1.0;
    if (((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) ||
       (fVar2 = -1.0,
       0x3f < (byte)((-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) - 1))) {
      fVar1 = fVar2;
    }
    if (((*(byte *)(*param_1 + 0x1a0) & 4) != 0) &&
       (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
      fVar1 = 0.0;
    }
    *(float *)(*param_1 + 0x1f8) = fVar1 * (float)param_1[0xf9];
    Next__15CFuncTrackTrain(param_1);
    (*DAT_001a7f34)(2,"TRAIN(%s), speed to %.2f\n",
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
        *(float *)(*param_1 + 0x1f8) = (float)param_1[0xf9] * (float)param_1[0xfa];
        Next__15CFuncTrackTrain(param_1);
      }
      else {
        *(undefined4 *)(*param_1 + 0x1f8) = 0;
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x24) = DAT_001a7e04;
        *(undefined4 *)(iVar3 + 0x28) = DAT_001a7e08;
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x60) = DAT_001a7e04;
        *(undefined4 *)(iVar3 + 100) = DAT_001a7e08;
        StopSound__15CFuncTrackTrain(param_1);
        param_1[3] = 0;
        param_1[4] = 0;
      }
    }
  }
  return;
}


// Use__15CFuncWallToggleP11CBaseEntityT18USE_TYPEf  @ 000806d4
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


// Use__15CTriggerCDAudioP11CBaseEntityT18USE_TYPEf  @ 0010262c
void Use__15CTriggerCDAudioP11CBaseEntityT18USE_TYPEf(undefined4 param_1)

{
  PlayTrack__15CTriggerCDAudio(param_1);
  return;
}


// Use__16CFuncMonsterClipP11CBaseEntityT18USE_TYPEf  @ 00082600
void Use__16CFuncMonsterClipP11CBaseEntityT18USE_TYPEf(void)

{
  return;
}


// Use__16CFuncTrackChangeP11CBaseEntityT18USE_TYPEf  @ 000c6a1c
void Use__16CFuncTrackChangeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (1 < (uint)param_1[0xfd]) {
    return;
  }
  if (param_1[0xfd] == 0) {
    iVar1 = param_1[0x126];
  }
  else {
    if (param_1[0xfd] != 1) {
      param_1[300] = 1;
      goto LAB_000c6a7a;
    }
    iVar1 = param_1[0x127];
  }
  iVar1 = EvaluateTrain__16CFuncTrackChangeP10CPathTrack(param_1,iVar1);
  param_1[300] = iVar1;
LAB_000c6a7a:
  if (param_1[300] == 1) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),2,"buttons/button11.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  else {
    param_1[0x12e] = 0;
    if (param_1[0xfd] == 0) {
      pcVar2 = *(code **)(param_1[0xf5] + 0x10c);
    }
    else {
      pcVar2 = *(code **)(param_1[0xf5] + 0x108);
    }
    (*pcVar2)(param_1);
  }
  return;
}


// Use__16CRenderFxManagerP11CBaseEntityT18USE_TYPEf  @ 001020f0
void Use__16CRenderFxManagerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar4 = 0;
LAB_00102118:
    iVar4 = (*DAT_001a7e78)(iVar4,"targetname",
                            *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar2 = false;
    if (iVar4 == 0) {
LAB_00102164:
      bVar2 = true;
    }
    else {
      iVar3 = (*DAT_001a7f58)(iVar4);
      if (iVar3 == 0) goto LAB_00102164;
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
      goto LAB_00102118;
    }
  }
  return;
}


// Use__17CFuncTankControlsP11CBaseEntityT18USE_TYPEf  @ 000a2774
void Use__17CFuncTankControlsP11CBaseEntityT18USE_TYPEf
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if (((param_2 == 0) ||
      (iVar1 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x28))(param_2), iVar1 == 2)) &&
     (iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar1 == 0))
  {
    return;
  }
  if (*(int *)(param_1 + 0x3d8) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x3d8) + 0x3d4) + 0xb0))
              (*(int *)(param_1 + 0x3d8),param_2,param_3,param_4,param_5);
  }
  return;
}


// Use__17CScriptedSentenceP11CBaseEntityT18USE_TYPEf  @ 000dd7c8
void Use__17CScriptedSentenceP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  if (param_1[0x125] != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)FindThink__17CScriptedSentence;
    *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


// Use__18CLegacyCineMonsterP11CBaseEntityT18USE_TYPEf  @ 000a8ef4
void Use__18CLegacyCineMonsterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x134) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)CineThink__18CLegacyCineMonster;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__19CMomentaryRotButtonP11CBaseEntityT18USE_TYPEf  @ 00084bf0
void Use__19CMomentaryRotButtonP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0x121);
  *(float *)(*param_1 + 0xac) = (float)(lVar1 / (longdouble)(float)param_1[0xff]);
  UpdateAllButtons__19CMomentaryRotButtonfi(param_1,*(undefined4 *)(*param_1 + 0xac),1);
  UpdateTarget__19CMomentaryRotButtonf(param_1,*(undefined4 *)(*param_1 + 0xac));
  return;
}


// Use__20CTriggerChangeTargetP11CBaseEntityT18USE_TYPEf  @ 00105118
void Use__20CTriggerChangeTargetP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                            (0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98))
  ;
  if (piVar1 != (int *)0x0) {
    *(int *)(*piVar1 + 0x1c8) = param_1[0xf8];
    iVar2 = (**(code **)(piVar1[0xf5] + 0x4c))(piVar1);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 4) = 0;
    }
  }
  return;
}


// Use__5CFadeP11CBaseEntityT18USE_TYPEf  @ 0009a8f4
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


// Use__6CBloodP11CBaseEntityT18USE_TYPEf  @ 0009a40c
void Use__6CBloodP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  undefined2 in_FPUControlWord;
  float local_78;
  float local_74;
  float local_70;
  undefined1 local_6c [16];
  float local_5c;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined1 local_10 [4];
  undefined1 local_c [8];
  undefined4 local_4;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
    Direction__6CBlood(&local_18,param_1);
    BloodPosition__6CBloodP11CBaseEntity(local_10,param_1,param_1);
    local_24 = (float)CONCAT22(local_24._2_2_,in_FPUControlWord);
    local_2c = CONCAT22(local_24._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    UTIL_BloodDrips__FRC6VectorT0ii
              (local_10,&local_18,*(undefined4 *)(*param_1 + 0x184),
               (int)ROUND(*(float *)(*param_1 + 0x1e0)));
  }
  else {
    Direction__6CBlood(local_c,param_1);
    BloodPosition__6CBloodP11CBaseEntity(&local_1c,param_1,param_1);
    local_24 = (float)CONCAT22(local_24._2_2_,in_FPUControlWord);
    local_2c = CONCAT22(local_24._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    UTIL_BloodStream__FRC6VectorT0ii
              (&local_1c,local_c,*(undefined4 *)(*param_1 + 0x184),
               (int)ROUND(*(float *)(*param_1 + 0x1e0)));
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 8) != 0) {
    Direction__6CBlood(&local_20,param_1);
    BloodPosition__6CBloodP11CBaseEntity(&local_18,param_1,local_4);
    fVar1 = *(float *)(*param_1 + 0x1e0);
    local_78 = local_1c + fVar1 * local_28 + fVar1 * local_28;
    local_74 = local_18 + fVar1 * local_24 + fVar1 * local_24;
    local_70 = local_14 + fVar1 * local_20 + fVar1 * local_20;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_18,&local_78,1,0,local_6c);
    if ((byte)(1.0 < local_5c | (byte)((ushort)((ushort)NAN(local_5c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_5c == 1.0) << 0xe) >> 8)) != 0x40) {
      UTIL_BloodDecalTrace__FP11TraceResulti(local_6c,*(undefined4 *)(*param_1 + 0x184));
    }
  }
  return;
}


// Use__6CLaserP11CBaseEntityT18USE_TYPEf  @ 000986f8
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


// Use__6CLightP11CBaseEntityT18USE_TYPEf  @ 000abfb0
void Use__6CLightP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  if (0x1f < param_1[0xf6]) {
    iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi
                      (param_1,param_4,(*(byte *)(*param_1 + 0x1a0) ^ 1) & 1);
    if (iVar1 != 0) {
      if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
        (*DAT_001a7eec)(param_1[0xf6],&DAT_00136e65);
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
      }
      else {
        if (param_1[0xf7] == 0) {
          puVar2 = &DAT_00136e67;
          iVar1 = param_1[0xf6];
        }
        else {
          puVar2 = (undefined *)(param_1[0xf7] + *(int *)(gpGlobals + 0x98));
          iVar1 = param_1[0xf6];
        }
        (*DAT_001a7eec)(iVar1,puVar2);
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0xfe;
      }
    }
  }
  return;
}


// Use__6CShakeP11CBaseEntityT18USE_TYPEf  @ 0009a7a0
void Use__6CShakeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  UTIL_ScreenShake__FRC6Vectorffff
            (iVar1 + 8,*(undefined4 *)(iVar1 + 0x144),*(undefined4 *)(iVar1 + 0x1dc),
             *(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1e0));
  return;
}


// Use__7CCyclerP11CBaseEntityT18USE_TYPEf  @ 000a98f8
void Use__7CCyclerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x187];
  param_1[0x187] = (uint)(iVar1 == 0);
  if ((iVar1 == 0) == 0) {
    *(undefined4 *)(*param_1 + 0x138) = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  }
  return;
}


// Use__7CSpriteP11CBaseEntityT18USE_TYPEf  @ 000991a8
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


// Use__7CTFGoalP11CBaseEntityT18USE_TYPEf  @ 000ffea8
void Use__7CTFGoalP11CBaseEntityT18USE_TYPEf(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x28))(param_2);
    if (iVar1 != 2) {
      param_2 = 0;
    }
    if ((param_2 != 0) &&
       (iVar1 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x28))(param_2), iVar1 != 2)) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x274) = 1;
  ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_3);
  return;
}


// Use__8CMessageP11CBaseEntityT18USE_TYPEf  @ 0009aba8
void Use__8CMessageP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
    if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) {
      iVar1 = (*DAT_001a7f60)(1);
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


// Use__9CBaseDoorP11CBaseEntityT18USE_TYPEf  @ 00093e08
void Use__9CBaseDoorP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  if (((*(byte *)(param_1 + 0x88) & 8) == 0) ||
     ((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 8.0) << 0xe) >> 8)) == 0x40)) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x112,param_2);
    if ((param_1[0xfd] != 1) &&
       (((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0 || (param_1[0xfd] != 0)))) {
      if ((char)param_1[0x12a] != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 0x12a) = 1;
    }
    DoorActivate__9CBaseDoor(param_1);
  }
  return;
}


// Use__9CBubblingP11CBaseEntityT18USE_TYPEf  @ 00095850
void Use__9CBubblingP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0xf9]);
  if (iVar1 != 0) {
    param_1[0xf9] = (uint)(param_1[0xf9] == 0);
  }
  if (param_1[0xf9] == 0) {
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


// Use__9CFuncTankP11CBaseEntityT18USE_TYPEf  @ 000a0660
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
        param_1[0x103] = 0;
      }
      else {
        pbVar1 = (byte *)(*param_1 + 0x1a0);
        *pbVar1 = *pbVar1 & 0xfe;
        param_1[0x103] = 0;
        StopRotSound__9CFuncTank(param_1);
      }
    }
  }
  else {
    iVar2 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x28))(param_2);
    if (iVar2 == 2) {
      iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar2 != 0) {
        if (((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_5 == 2.0) << 0xe) >> 8)) == 0x40) &&
           (param_4 == 2)) {
          ControllerPostFrame__9CFuncTank(param_1);
        }
        else if ((param_1[0xf6] == 0) && (param_4 != 0)) {
          __as__7EHANDLEP11CBaseEntity(param_2 + 0x7f4,param_1);
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


// Use__9CFuncWallP11CBaseEntityT18USE_TYPEf  @ 00080590
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


// Use__9CPushableP11CBaseEntityT18USE_TYPEf  @ 0009f4f8
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
       (byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(DAT_001a7e04 == fVar1) << 0xe) >> 8)) == 0x40)) {
      fVar1 = *(float *)(*param_2 + 0x28);
      bVar2 = (byte)(DAT_001a7e08 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar2) {
      Move__9CPushableP11CBaseEntityi(param_1,param_2,0);
    }
  }
  return;
}


// Use__9CRechargeP11CBaseEntityT18USE_TYPEf  @ 000a882c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  if (param_1[0x120] < 1) {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
    Off__9CRecharge(param_1);
    if (param_1[0x120] < 1) goto LAB_000a88a4;
  }
  if (*(int *)(*param_2 + 0x168) < 0) {
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.25;
    param_1[3] = -0x10000;
    param_1[4] = (int)Off__9CRecharge;
    if (*gpGlobals <= (float)param_1[0x11e]) {
      return;
    }
    if (param_2 == (int *)0x0) {
      return;
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x112,param_2);
    piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x112);
    if ((*(byte *)(*piVar5 + 0x1a4) & 8) == 0) {
      return;
    }
    if (param_1[0x121] == 0) {
      param_1[0x121] = 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"items/suitchargeok1.wav",0x3f59999a,0x3f4ccccd
                 ,0,100);
      param_1[0x122] = (int)((float)_FUN_00136580 + *gpGlobals);
    }
    if ((param_1[0x121] == 1) && ((float)param_1[0x122] <= *gpGlobals)) {
      param_1[0x121] = 2;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"items/suitcharge1.wav",0x3f59999a,0x3f4ccccd,0
                 ,100);
    }
    piVar5 = param_1 + 0x112;
    piVar6 = (int *)__rf__7EHANDLE(piVar5);
    iVar4 = *piVar6;
    iVar7 = __rf__7EHANDLE(piVar5);
    if (*(float *)(iVar4 + 0x1bc) < *(float *)(iVar7 + 0xf0)) {
      param_1[0x120] = param_1[0x120] + -1;
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
      piVar5 = param_1 + 0x112;
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
    param_1[0x11e] = (int)(*gpGlobals + 0.1);
    return;
  }
LAB_000a88a4:
  if ((float)param_1[0x122] <= *gpGlobals) {
    param_1[0x122] = (int)(*gpGlobals + 0.62);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/suitchargeno1.wav",0x3f59999a,0x3f4ccccd,0
               ,100);
  }
  return;
}


