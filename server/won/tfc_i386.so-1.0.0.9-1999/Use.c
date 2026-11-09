// Use__10CBreakableP11CBaseEntityT18USE_TYPEf  @ 000b2930
void Use__10CBreakableP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = IsBreakable__10CBreakable(param_1);
  if (iVar1 != 0) {
    *(int *)(*param_1 + 0x54) = param_1[0xf8];
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    g_vecAttackDir = *(undefined4 *)(gpGlobals + 0x28);
    DAT_00175490 = *(undefined4 *)(gpGlobals + 0x2c);
    DAT_00175494 = *(undefined4 *)(gpGlobals + 0x30);
    Die__10CBreakable(param_1);
  }
  return;
}


// Use__10CEnvFunnelP11CBaseEntityT18USE_TYPEf  @ 000afc80
void Use__10CEnvFunnelP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(100);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175588)(param_1[0xf5]);
  (*DAT_00175588)((*(byte *)(*param_1 + 0x180) & 1) != 0);
  (*DAT_0017557c)();
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


// Use__10CEnvGlobalP11CBaseEntityT18USE_TYPEf  @ 0009d690
void Use__10CEnvGlobalP11CBaseEntityT18USE_TYPEf(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = EntityGetState__12CGlobalStatei(&gGlobalState,*(undefined4 *)(param_1 + 0x3cc));
  iVar2 = *(int *)(param_1 + 0x3d0);
  if (iVar2 != 1) {
    if (iVar2 < 2) {
      if (iVar2 == 0) {
        iVar2 = 0;
        goto LAB_0009d702;
      }
    }
    else if (iVar2 == 2) {
      iVar2 = 2;
      goto LAB_0009d702;
    }
    iVar2 = 0;
    if ((iVar1 == 1) || (iVar2 = iVar1, iVar1 != 0)) goto LAB_0009d702;
  }
  iVar2 = 1;
LAB_0009d702:
  iVar1 = Find__12CGlobalStatei(&gGlobalState,*(undefined4 *)(param_1 + 0x3cc));
  if (iVar1 == 0) {
    EntityAdd__12CGlobalStateii12GLOBALESTATE
              (&gGlobalState,*(undefined4 *)(param_1 + 0x3cc),*(undefined4 *)(gpGlobals + 0xc),iVar2
              );
  }
  else {
    EntitySetState__12CGlobalStatei12GLOBALESTATE
              (&gGlobalState,*(undefined4 *)(param_1 + 0x3cc),iVar2);
  }
  return;
}


// Use__10CFuncTrainP11CBaseEntityT18USE_TYPEf  @ 000d2180
void Use__10CFuncTrainP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 1;
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x170) != 0) {
      *(undefined4 *)(iVar2 + 0x1a8) = *(undefined4 *)(*(int *)(iVar2 + 0x170) + 0x288);
    }
    *(undefined4 *)(*param_1 + 0xe4) = 0;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x24) = DAT_00175484;
    *(undefined4 *)(iVar2 + 0x28) = DAT_00175488;
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1cc) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x1e8),2,
                 *(int *)(iVar2 + 0x1cc) + *(int *)(gpGlobals + 0x98),param_1[0x11c],0x3f4ccccd,0,
                 100);
    }
  }
  else {
    pbVar1 = (byte *)(*param_1 + 0x180);
    *pbVar1 = *pbVar1 & 0xfe;
    Next__10CFuncTrain(param_1);
  }
  return;
}


// Use__10CGunTargetP11CBaseEntityT18USE_TYPEf  @ 000d5b70
void Use__10CGunTargetP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x184]);
  if (iVar1 != 0) {
    if (param_1[0x184] == 0) {
      *(undefined4 *)(*param_1 + 0x14c) = 0x40000000;
      uVar2 = (**(code **)(param_1[0xf2] + 0xa4))(param_1);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x11e,uVar2);
      iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11e);
      if (iVar1 != 0) {
        *(undefined4 *)(*param_1 + 0x140) = *(undefined4 *)(*param_1 + 400);
        Next__10CGunTarget(param_1);
      }
    }
    else {
      (**(code **)(param_1[0xf2] + 0x14c))(param_1);
    }
  }
  return;
}


// Use__10CPathTrackP11CBaseEntityT18USE_TYPEf  @ 000d02a0
void Use__10CPathTrackP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1[0xf7] == 0) {
    bVar1 = *(byte *)(*param_1 + 0x180) ^ 1;
    iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,bVar1 & 1);
    if (iVar2 != 0) {
      if ((bVar1 & 1) == 0) {
        *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) & 0xfe;
      }
      else {
        *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 1;
      }
    }
  }
  else {
    uVar3 = (*(uint *)(*param_1 + 0x180) >> 0xf ^ 1) & 1;
    iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,uVar3);
    if (iVar2 != 0) {
      if (uVar3 == 0) {
        *(byte *)(*param_1 + 0x181) = *(byte *)(*param_1 + 0x181) & 0x7f;
      }
      else {
        *(byte *)(*param_1 + 0x181) = *(byte *)(*param_1 + 0x181) | 0x80;
      }
    }
  }
  return;
}


// Use__11CBaseEntityP11CBaseEntityT18USE_TYPEf  @ 0010e1d0
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


// Use__11CGibShooterP11CBaseEntityT18USE_TYPEf  @ 000ae700
void Use__11CGibShooterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)ShootThink__11CGibShooter;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


// Use__11CTestEffectP11CBaseEntityT18USE_TYPEf  @ 000af1e0
void Use__11CTestEffectP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float *pfVar1;
  
  param_1[3] = -0x10000;
  param_1[4] = (int)TestThink__11CTestEffect;
  pfVar1 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[0x127] = (int)*pfVar1;
  return;
}


// Use__11CWallHealthP11CBaseEntityT18USE_TYPEf  @ 000bd020
void Use__11CWallHealthP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if ((*(byte *)(*param_2 + 0x184) & 8) == 0) {
    return;
  }
  if (param_1[0x11d] < 1) {
    *(undefined4 *)(*param_1 + 0x110) = 0x3f800000;
    Off__11CWallHealth(param_1);
    if (param_1[0x11d] < 1) goto LAB_000bd077;
  }
  if (*(int *)(*param_2 + 0x148) < 0) {
    *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 0.25;
    param_1[3] = -0x10000;
    param_1[4] = (int)Off__11CWallHealth;
    if (*gpGlobals <= (float)param_1[0x11b]) {
      return;
    }
    if (param_1[0x11e] == 0) {
      param_1[0x11e] = 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),3,"items/medshot4.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      param_1[0x11f] = (int)(*gpGlobals + 0.56);
    }
    if (param_1[0x11e] == 1) {
      fVar1 = (float)param_1[0x11f];
      fVar2 = *gpGlobals;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        param_1[0x11e] = 2;
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),6,"items/medcharge4.wav",0x3f800000,0x3f4ccccd,
                   0,100);
      }
    }
    iVar3 = (**(code **)(param_2[0xf2] + 0x38))(param_2,0x3f800000,0);
    if (iVar3 != 0) {
      param_1[0x11d] = param_1[0x11d] + -1;
    }
    param_1[0x11b] = (int)(*gpGlobals + 0.1);
    return;
  }
LAB_000bd077:
  fVar1 = (float)param_1[0x11f];
  fVar2 = *gpGlobals;
  if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    param_1[0x11f] = (int)(*gpGlobals + 0.62);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),3,"items/medshotno1.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  return;
}


// Use__12CCineMonsterP11CBaseEntityT18USE_TYPEf  @ 000e7100
void Use__12CCineMonsterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11e);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x4c))(iVar1);
  }
  if (iVar2 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__12CCineMonster;
    *(float *)(*param_1 + 0xe4) = *gpGlobals;
  }
  else if (*(int *)(iVar2 + 0x608) != 0) {
    param_1[0x18c] = (int)(*gpGlobals + 0.05);
  }
  return;
}


// Use__12CEnvBeverageP11CBaseEntityT18USE_TYPEf  @ 000afdb0
void Use__12CEnvBeverageP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x144)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x144) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (0.0 < *(float *)(iVar3 + 0x140))) {
    piVar1 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                              ("item_sodacan",iVar3 + 8,iVar3 + 0x50,*(undefined4 *)(iVar3 + 0x1e8))
    ;
    if (*(int *)(*param_1 + 0xf0) == 6) {
      uVar2 = (*DAT_00175628)(0,5);
      iVar3 = *piVar1;
    }
    else {
      iVar3 = *piVar1;
      uVar2 = *(undefined4 *)(*param_1 + 0xf0);
    }
    *(undefined4 *)(iVar3 + 0xf0) = uVar2;
    *(undefined4 *)(*param_1 + 0x144) = 0x3f800000;
    *(float *)(*param_1 + 0x140) = *(float *)(*param_1 + 0x140) - 1.0;
  }
  return;
}


// Use__12CMultiSourceP11CBaseEntityT18USE_TYPEf  @ 0009d920
void Use__12CMultiSourceP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < param_1[0x153]) {
    do {
      iVar1 = iVar4 * 2;
      iVar4 = iVar4 + 1;
      puVar2 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + iVar1 + 0xf3);
      if (puVar2 == param_3) break;
    } while (iVar4 < param_1[0x153]);
  }
  if (param_1[0x153] < iVar4) {
    (*DAT_001755b4)(1,FUN_0012b560,*(int *)*param_3 + *(int *)(gpGlobals + 0x98));
  }
  else {
    *(byte *)(param_1 + iVar4 + 0x132) = *(byte *)(param_1 + iVar4 + 0x132) ^ 1;
    iVar4 = (**(code **)(param_1[0xf2] + 0x48))(param_1);
    if (iVar4 != 0) {
      (*DAT_001755b4)(2,"Multisource %s enabled (%d inputs)\n",
                      *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98),param_1[0x153]);
      uVar3 = 3;
      if (param_1[0x154] != 0) {
        uVar3 = 1;
      }
      SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,0,uVar3,0);
    }
  }
  return;
}


// Use__12CRevertSavedP11CBaseEntityT18USE_TYPEf  @ 000e00c0
void Use__12CRevertSavedP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  UTIL_ScreenFadeAll__FRC6Vectorffii
            (iVar1 + 0x130,*(undefined4 *)(iVar1 + 0x1b8),*(undefined4 *)(iVar1 + 0x1bc),
             (int)ROUND(*(float *)(iVar1 + 300)),1);
  *(float *)(*param_1 + 0xe4) = (float)param_1[0xf3] + *gpGlobals;
  param_1[3] = -0x10000;
  param_1[4] = (int)MessageThink__12CRevertSaved;
  return;
}


// Use__13CButtonTargetP11CBaseEntityT18USE_TYPEf  @ 0009ffe0
void Use__13CButtonTargetP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  
  iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi
                    (param_1,param_4,(int)ROUND(*(float *)(*param_1 + 0x110)));
  if (iVar2 != 0) {
    *(float *)(*param_1 + 0x110) = 1.0 - *(float *)(*param_1 + 0x110);
    fVar1 = *(float *)(*param_1 + 0x110);
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf
              (param_1,param_2,
               (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40,0);
  }
  return;
}


// Use__13CCyclerSpriteP11CBaseEntityT18USE_TYPEf  @ 000bbcb0
void Use__13CCyclerSpriteP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[0xf3] = (uint)(param_1[0xf3] == 0);
  (*DAT_001755b4)(1,"Sprite: %s\n",*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  return;
}


// Use__13CEnvExplosionP11CBaseEntityT18USE_TYPEf  @ 000b1a10
void Use__13CEnvExplosionP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  undefined4 uVar5;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  *(undefined4 *)(*param_1 + 0x98) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  iVar2 = *param_1;
  fStack_48 = *(float *)(iVar2 + 8) + 0.0;
  fStack_44 = *(float *)(iVar2 + 0xc) + 0.0;
  fStack_40 = *(float *)(iVar2 + 0x10) + 8.0;
  fStack_54 = 0.0;
  fStack_50 = 0.0;
  fStack_4c = -40.0;
  fStack_60 = fStack_48 + 0.0;
  fStack_5c = fStack_44 + 0.0;
  fStack_58 = fStack_40 + -40.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_48,&fStack_60,1,*(undefined4 *)(iVar2 + 0x1e8),auStack_3c);
  if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x10) = *(undefined4 *)(*param_1 + 0x10);
  }
  else {
    iVar2 = *param_1;
    fVar1 = (float)(param_1[0x184] + -0x18);
    fStack_54 = fVar1 * fStack_18 * 0.6;
    fStack_50 = fVar1 * fStack_14 * 0.6;
    fStack_4c = fVar1 * fStack_10 * 0.6;
    fStack_60 = fStack_28 + fStack_54;
    fStack_5c = fStack_24 + fStack_50;
    fStack_58 = fStack_20 + fStack_4c;
    *(float *)(iVar2 + 8) = fStack_60;
    *(float *)(iVar2 + 0xc) = fStack_5c;
    *(float *)(iVar2 + 0x10) = fStack_58;
  }
  if ((*(byte *)(*param_1 + 0x180) & 0x10) == 0) {
    lVar4 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
    if ((longdouble)0.5 <= lVar4) {
      uVar5 = 0xc;
    }
    else {
      uVar5 = 0xb;
    }
    UTIL_DecalTrace__FP11TraceResulti(auStack_3c,uVar5);
  }
  if ((*(byte *)(*param_1 + 0x180) & 4) == 0) {
    (*DAT_00175578)(5,0x17,*param_1 + 8,0);
    (*DAT_00175580)(3);
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_00175588)((int)g_sModelIndexFireball);
    (*DAT_00175580)((char)param_1[0x185]);
    (*DAT_00175580)(0xf);
    (*DAT_00175580)(3);
    (*DAT_0017557c)();
  }
  else {
    (*DAT_00175578)(5,0x17,*param_1 + 8,0);
    (*DAT_00175580)(3);
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_00175588)((int)g_sModelIndexFireball);
    (*DAT_00175580)(0);
    (*DAT_00175580)(0xf);
    (*DAT_00175580)(3);
    (*DAT_0017557c)();
  }
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x180) ^ 1) & 1) != 0) {
    (**(code **)(param_1[0xf2] + 0x1f8))(param_1,iVar2,iVar2,(float)param_1[0x184],0,0x40);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Smoke__13CEnvExplosion;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.3;
  if ((*(byte *)(*param_1 + 0x180) & 0x20) == 0) {
    iVar2 = (*DAT_00175628)(0,3);
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&fStack_18,0);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
  }
  return;
}


// Use__13CFuncConveyorP11CBaseEntityT18USE_TYPEf  @ 0009b960
void Use__13CFuncConveyorP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  *(float *)(*param_1 + 0x1d8) = -*(float *)(*param_1 + 0x1d8);
  UpdateSpeed__13CFuncConveyorf(param_1,*(undefined4 *)(*param_1 + 0x1d8));
  return;
}


// Use__13CStripWeaponsP11CBaseEntityT18USE_TYPEf  @ 000dfe80
void Use__13CStripWeaponsP11CBaseEntityT18USE_TYPEf(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x184) & 8) == 0)) &&
     (param_2 = (int *)0x0,
     (byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x14)) << 10) >> 8) |
           (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x14) == 0.0) << 0xe) >> 8)) == 0x40)) {
    iVar1 = (*DAT_001755e0)(1);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
      param_2 = (int *)0x0;
    }
    else {
      param_2 = *(int **)(iVar1 + 0xd8);
    }
  }
  if (param_2 != (int *)0x0) {
    RemoveAllItems__11CBasePlayeri(param_2,0);
  }
  return;
}


// Use__13CTriggerRelayP11CBaseEntityT18USE_TYPEf  @ 0010f740
void Use__13CTriggerRelayP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,param_1[0xf5],0);
  if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Use__14CFuncTrackAutoP11CBaseEntityT18USE_TYPEf  @ 000d54c0
void Use__14CFuncTrackAutoP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x4ac) != 0) {
    if (*(int *)(param_1 + 1000) == 0) {
      iVar2 = *(int *)(param_1 + 0x48c);
    }
    else {
      iVar2 = 0;
      if (*(int *)(param_1 + 1000) == 1) {
        iVar2 = *(int *)(param_1 + 0x490);
      }
    }
    iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
    if (iVar1 == 0) {
      iVar2 = EvaluateTrain__16CFuncTrackChangeP10CPathTrack(param_1,iVar2);
      *(int *)(param_1 + 0x4a4) = iVar2;
      if ((iVar2 == 2) && (*(int *)(param_1 + 1000) != *(int *)(param_1 + 0x4a8))) {
        *(undefined4 *)(param_1 + 0x4ac) = 0;
        if (*(int *)(param_1 + 1000) == 0) {
          (**(code **)(*(int *)(param_1 + 0x3c8) + 0x10c))(param_1);
        }
        else {
          (**(code **)(*(int *)(param_1 + 0x3c8) + 0x108))(param_1);
        }
      }
    }
    else {
      if (iVar2 != 0) {
        iVar2 = GetNext__10CPathTrack(iVar2);
        if ((iVar2 != 0) && (*(int *)(*(int *)(param_1 + 0x494) + 0x3cc) != iVar2)) {
          iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi
                            (param_1,param_4,*(undefined4 *)(param_1 + 0x4a8));
          if (iVar2 != 0) {
            if (*(int *)(param_1 + 0x4a8) == 0) {
              *(undefined4 *)(param_1 + 0x4a8) = 1;
            }
            else {
              *(undefined4 *)(param_1 + 0x4a8) = 0;
            }
          }
        }
      }
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x118))(param_1,*(undefined4 *)(param_1 + 0x4a8));
    }
  }
  return;
}


// Use__14CMomentaryDoorP11CBaseEntityT18USE_TYPEf  @ 000aaf40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Use__14CMomentaryDoorP11CBaseEntityT18USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((param_4 == 2) &&
     ((iVar4 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x28))(param_2), iVar4 != 2 ||
      (iVar4 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar4 != 0))
     )) {
    if ((byte)(1.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_5 == 1.0) << 0xe) >> 8)) == 1) {
      param_5 = 1.0;
    }
    local_18 = param_5 * ((float)param_1[0x105] - (float)param_1[0x102]);
    local_14 = param_5 * ((float)param_1[0x106] - (float)param_1[0x103]);
    local_10 = (float)param_1[0x101] + param_5 * ((float)param_1[0x104] - (float)param_1[0x101]);
    local_c = (float)param_1[0x102] + local_18;
    local_8 = (float)param_1[0x103] + local_14;
    iVar4 = *param_1;
    fVar3 = local_10 - *(float *)(iVar4 + 8);
    fVar2 = local_c - *(float *)(iVar4 + 0xc);
    fVar1 = local_8 - *(float *)(iVar4 + 0x10);
    local_1c = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
    fVar3 = _FUN_0012e680 * local_1c;
    if ((byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = *(float *)(iVar4 + 0xe4);
      fVar2 = *(float *)(iVar4 + 0xe0);
      if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) ||
         ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),6,
                   *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,
                   100);
      }
      local_1c = local_10;
      local_18 = local_c;
      local_14 = local_8;
      LinearMove__11CBaseToggleG6Vectorf(param_1,&local_1c,fVar3);
    }
  }
  return;
}


// Use__14CTargetCDAudioP11CBaseEntityT18USE_TYPEf  @ 001102a0
void Use__14CTargetCDAudioP11CBaseEntityT18USE_TYPEf(undefined4 param_1)

{
  Play__14CTargetCDAudio(param_1);
  return;
}


// Use__14CTriggerCameraP11CBaseEntityT18USE_TYPEf  @ 00112730
void Use__14CTriggerCameraP11CBaseEntityT18USE_TYPEf
               (int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x103]);
  if (iVar3 != 0) {
    iVar3 = param_1[0x103];
    param_1[0x103] = (uint)(iVar3 == 0);
    if ((iVar3 == 0) == 0) {
      param_1[0xfc] = (int)*gpGlobals;
    }
    else {
      if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x184) & 8) == 0)) {
        iVar3 = (*DAT_001755e0)(1);
        if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
          param_2 = (int *)0x0;
        }
        else {
          param_2 = *(int **)(iVar3 + 0xd8);
        }
      }
      __as__7EHANDLEP11CBaseEntity(param_1 + 0xf5,param_2);
      param_1[0xfc] = (int)(*gpGlobals + (float)param_1[0xfb]);
      *(int *)(*param_1 + 0x1d8) = param_1[0x100];
      param_1[0xff] = param_1[0x100];
      if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
        uVar4 = (**(code **)(param_1[0xf2] + 0xa4))(param_1);
        __as__7EHANDLEP11CBaseEntity(param_1 + 0xf7,uVar4);
      }
      else {
        param_1[0xf7] = param_1[0xf5];
        param_1[0xf8] = param_1[0xf6];
      }
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0xf7);
      if (iVar3 != 0) {
        if ((*(byte *)(*param_1 + 0x180) & 4) != 0) {
          EnableControl__11CBasePlayeri(param_2,0);
        }
        if (param_1[0xfa] == 0) {
          param_1[0xf9] = 0;
        }
        else {
          iVar3 = (*DAT_001754f8)(0,"targetname",param_1[0xfa] + (int)gpGlobals[0x26]);
          if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(iVar3 + 0xd8);
          }
          param_1[0xf9] = iVar3;
        }
        param_1[0xfd] = (int)*gpGlobals;
        if (param_1[0xf9] != 0) {
          fVar1 = *(float *)(*(int *)param_1[0xf9] + 0x1d8);
          if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
            param_1[0xff] = (int)fVar1;
          }
          lVar5 = (longdouble)(**(code **)(*(int *)(param_1[0xf9] + 0x3c8) + 100))(param_1[0xf9]);
          param_1[0xfd] = (int)(float)(lVar5 + (longdouble)(float)param_1[0xfd]);
        }
        if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
          iVar3 = *param_1;
          local_10 = 0.0;
          local_c = 0.0;
          local_8 = 0.0;
          *(undefined4 *)(iVar3 + 0x20) = 0;
          *(undefined4 *)(iVar3 + 0x24) = 0;
          *(undefined4 *)(iVar3 + 0x28) = 0;
        }
        else {
          iVar3 = *param_2;
          local_10 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
          local_c = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x158);
          local_8 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x15c);
          UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,&local_10);
          *(float *)(*param_1 + 0x50) = -*(float *)(*param_2 + 0x50);
          *(undefined4 *)(*param_1 + 0x54) = *(undefined4 *)(*param_2 + 0x54);
          *(undefined4 *)(*param_1 + 0x58) = 0;
          iVar3 = *param_1;
          iVar2 = *param_2;
          *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
          *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
          *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar2 + 0x28);
        }
        (*DAT_00175630)(*(undefined4 *)(*param_2 + 0x1e8),*(undefined4 *)(*param_1 + 0x1e8));
        (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                        *(int *)(*param_2 + 0x98) + (int)gpGlobals[0x26]);
        param_1[3] = -0x10000;
        param_1[4] = (int)FollowTarget__14CTriggerCamera;
        *(float *)(*param_1 + 0xe4) = *gpGlobals;
        param_1[0xfe] = 0;
        Move__14CTriggerCamera(param_1);
      }
    }
  }
  return;
}


// Use__15CFuncTrackTrainP11CBaseEntityT18USE_TYPEf  @ 000d2f50
void Use__15CFuncTrackTrainP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (param_4 == 2) {
    fVar1 = param_5 * 0.25 +
            (float)((int)ROUND(*(float *)(*param_1 + 0x1d8) * 4.0) /
                   (int)ROUND((float)param_1[0xf6])) * 0.25;
    fVar2 = 1.0;
    if (((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) ||
       (fVar2 = -1.0, fVar1 < -1.0)) {
      fVar1 = fVar2;
    }
    if (((*(byte *)(*param_1 + 0x180) & 4) != 0) && (fVar1 < 0.0)) {
      fVar1 = 0.0;
    }
    *(float *)(*param_1 + 0x1d8) = fVar1 * (float)param_1[0xf6];
    Next__15CFuncTrackTrain(param_1);
    (*DAT_001755b4)(2,"TRAIN(%s), speed to %.2f\n",
                    *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98),
                    (double)*(float *)(*param_1 + 0x1d8));
  }
  else {
    iVar3 = ShouldToggle__11CBaseEntity8USE_TYPEi
                      (param_1,param_4,
                       (byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x1d8)) << 10) >> 8)
                             | (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1d8) == 0.0) << 0xe)
                                     >> 8)) != 0x40);
    if (iVar3 != 0) {
      fVar1 = *(float *)(*param_1 + 0x1d8);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        *(float *)(*param_1 + 0x1d8) = (float)param_1[0xf6] * (float)param_1[0xf7];
        Next__15CFuncTrackTrain(param_1);
      }
      else {
        *(undefined4 *)(*param_1 + 0x1d8) = 0;
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x24) = DAT_00175484;
        *(undefined4 *)(iVar3 + 0x28) = DAT_00175488;
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x60) = DAT_00175484;
        *(undefined4 *)(iVar3 + 100) = DAT_00175488;
        StopSound__15CFuncTrackTrain(param_1);
        param_1[3] = 0;
        param_1[4] = 0;
      }
    }
  }
  return;
}


// Use__15CFuncWallToggleP11CBaseEntityT18USE_TYPEf  @ 0009b7f0
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


// Use__15CTriggerCDAudioP11CBaseEntityT18USE_TYPEf  @ 00110100
void Use__15CTriggerCDAudioP11CBaseEntityT18USE_TYPEf(undefined4 param_1)

{
  PlayTrack__15CTriggerCDAudio(param_1);
  return;
}


// Use__16CFuncMonsterClipP11CBaseEntityT18USE_TYPEf  @ 0009d3b0
void Use__16CFuncMonsterClipP11CBaseEntityT18USE_TYPEf(void)

{
  return;
}


// Use__16CFuncTrackChangeP11CBaseEntityT18USE_TYPEf  @ 000d51a0
void Use__16CFuncTrackChangeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (1 < (uint)param_1[0xfa]) {
    return;
  }
  if (param_1[0xfa] == 0) {
    iVar1 = param_1[0x123];
  }
  else {
    if (param_1[0xfa] != 1) {
      param_1[0x129] = 1;
      goto LAB_000d520a;
    }
    iVar1 = param_1[0x124];
  }
  iVar1 = EvaluateTrain__16CFuncTrackChangeP10CPathTrack(param_1,iVar1);
  param_1[0x129] = iVar1;
LAB_000d520a:
  if (param_1[0x129] == 1) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),2,"buttons/button11.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  else {
    param_1[299] = 0;
    if (param_1[0xfa] == 0) {
      pcVar2 = *(code **)(param_1[0xf2] + 0x10c);
    }
    else {
      pcVar2 = *(code **)(param_1[0xf2] + 0x108);
    }
    (*pcVar2)(param_1);
  }
  return;
}


// Use__16CRenderFxManagerP11CBaseEntityT18USE_TYPEf  @ 0010fc70
void Use__16CRenderFxManagerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(*param_1 + 0x1a8) != 0) {
    iVar4 = 0;
LAB_0010fc8c:
    iVar4 = (*DAT_001754f8)(iVar4,"targetname",
                            *(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
    bVar2 = false;
    if (iVar4 == 0) {
LAB_0010fcc8:
      bVar2 = true;
    }
    else {
      iVar3 = (*DAT_001755d8)(iVar4);
      if (iVar3 == 0) goto LAB_0010fcc8;
    }
    if (!bVar2) {
      if (iVar4 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar4 + 0xdc;
      }
      if (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) != 0) {
        *(undefined4 *)(iVar3 + 0x13c) = *(undefined4 *)(*param_1 + 0x13c);
      }
      if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
        *(undefined4 *)(iVar3 + 300) = *(undefined4 *)(*param_1 + 300);
      }
      if ((*(byte *)(*param_1 + 0x180) & 4) == 0) {
        *(undefined4 *)(iVar3 + 0x128) = *(undefined4 *)(*param_1 + 0x128);
      }
      iVar1 = *param_1;
      if ((*(byte *)(iVar1 + 0x180) & 8) == 0) {
        *(undefined4 *)(iVar3 + 0x130) = *(undefined4 *)(iVar1 + 0x130);
        *(undefined4 *)(iVar3 + 0x134) = *(undefined4 *)(iVar1 + 0x134);
        *(undefined4 *)(iVar3 + 0x138) = *(undefined4 *)(iVar1 + 0x138);
      }
      goto LAB_0010fc8c;
    }
  }
  return;
}


// Use__17CFuncTankControlsP11CBaseEntityT18USE_TYPEf  @ 000b6200
void Use__17CFuncTankControlsP11CBaseEntityT18USE_TYPEf
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x28))(param_2);
  if ((iVar1 == 2) &&
     (iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar1 == 0))
  {
    return;
  }
  if (*(int *)(param_1 + 0x3cc) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x3cc) + 0x3c8) + 0xb0))
              (*(int *)(param_1 + 0x3cc),param_2,param_3,param_4,param_5);
  }
  return;
}


// Use__17CScriptedSentenceP11CBaseEntityT18USE_TYPEf  @ 000e8750
void Use__17CScriptedSentenceP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  if (param_1[0x122] != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)FindThink__17CScriptedSentence;
    *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  }
  return;
}


// Use__18CLegacyCineMonsterP11CBaseEntityT18USE_TYPEf  @ 000bb180
void Use__18CLegacyCineMonsterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x114) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)CineThink__18CLegacyCineMonster;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


// Use__19CMomentaryRotButtonP11CBaseEntityT18USE_TYPEf  @ 0009f5e0
void Use__19CMomentaryRotButtonP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x180),*param_1 + 0x50,param_1 + 0x11e);
  *(float *)(*param_1 + 0x8c) = (float)(lVar1 / (longdouble)(float)param_1[0xfc]);
  UpdateAllButtons__19CMomentaryRotButtonfi(param_1,*(undefined4 *)(*param_1 + 0x8c),1);
  UpdateTarget__19CMomentaryRotButtonf(param_1,*(undefined4 *)(*param_1 + 0x8c));
  return;
}


// Use__20CTriggerChangeTargetP11CBaseEntityT18USE_TYPEf  @ 00112490
void Use__20CTriggerChangeTargetP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                            (0,"targetname",*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98))
  ;
  if (piVar1 != (int *)0x0) {
    *(int *)(*piVar1 + 0x1a8) = param_1[0xf5];
    iVar2 = (**(code **)(piVar1[0xf2] + 0x4c))(piVar1);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 4) = 0;
    }
  }
  return;
}


// Use__5CFadeP11CBaseEntityT18USE_TYPEf  @ 000af8e0
void Use__5CFadeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = ((*(byte *)(*param_1 + 0x180) ^ 1) & 1) != 0;
  if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
    bVar2 = bVar2 | 2;
  }
  iVar1 = *param_1;
  UTIL_ScreenFadeAll__FRC6Vectorffii
            (iVar1 + 0x130,*(undefined4 *)(iVar1 + 0x1b8),*(undefined4 *)(iVar1 + 0x1bc),
             (int)ROUND(*(float *)(iVar1 + 300)),bVar2);
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return;
}


// Use__6CBloodP11CBaseEntityT18USE_TYPEf  @ 000af490
void Use__6CBloodP11CBaseEntityT18USE_TYPEf(int *param_1,undefined4 param_2)

{
  float fVar1;
  undefined2 in_FPUControlWord;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined1 auStack_60 [16];
  float fStack_50;
  undefined4 local_28;
  undefined2 local_20;
  undefined2 uStack_1e;
  float local_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
    Direction__6CBlood(&local_1c,param_1);
    BloodPosition__6CBloodP11CBaseEntity(&local_10,param_1,param_2);
    _local_20 = CONCAT22(uStack_1e,in_FPUControlWord);
    local_28 = CONCAT22(uStack_1e,CONCAT11(0xc,(char)in_FPUControlWord));
    UTIL_BloodDrips__FRC6VectorT0ii
              (&local_10,&local_1c,*(undefined4 *)(*param_1 + 0x164),
               (int)ROUND(*(float *)(*param_1 + 0x1c0)));
  }
  else {
    Direction__6CBlood(&local_10,param_1);
    BloodPosition__6CBloodP11CBaseEntity(&local_1c,param_1,param_2);
    _local_20 = CONCAT22(uStack_1e,in_FPUControlWord);
    local_28 = CONCAT22(uStack_1e,CONCAT11(0xc,(char)in_FPUControlWord));
    UTIL_BloodStream__FRC6VectorT0ii
              (&local_1c,&local_10,*(undefined4 *)(*param_1 + 0x164),
               (int)ROUND(*(float *)(*param_1 + 0x1c0)));
  }
  if ((*(byte *)(*param_1 + 0x180) & 8) != 0) {
    Direction__6CBlood(&local_1c,param_1);
    BloodPosition__6CBloodP11CBaseEntity(&local_10,param_1,param_2);
    fVar1 = *(float *)(*param_1 + 0x1c0);
    fStack_6c = local_10 + fVar1 * local_1c + fVar1 * local_1c;
    fStack_68 = fStack_c + fVar1 * fStack_18 + fVar1 * fStack_18;
    fStack_64 = fStack_8 + fVar1 * fStack_14 + fVar1 * fStack_14;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_10,&fStack_6c,1,0,auStack_60);
    if ((byte)(1.0 < fStack_50 | (byte)((ushort)((ushort)NAN(fStack_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_50 == 1.0) << 0xe) >> 8)) != 0x40) {
      UTIL_BloodDecalTrace__FP11TraceResulti(auStack_60,*(undefined4 *)(*param_1 + 0x164));
    }
  }
  return;
}


// Use__6CLaserP11CBaseEntityT18USE_TYPEf  @ 000adba0
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


// Use__6CLightP11CBaseEntityT18USE_TYPEf  @ 000bdb80
void Use__6CLightP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  if (0x1f < param_1[0xf3]) {
    iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi
                      (param_1,param_4,(*(byte *)(*param_1 + 0x180) ^ 1) & 1);
    if (iVar1 != 0) {
      if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
        (*DAT_0017556c)(param_1[0xf3],&DAT_001345ed);
        *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 1;
      }
      else {
        if (param_1[0xf4] == 0) {
          puVar2 = &DAT_001345ef;
        }
        else {
          puVar2 = (undefined *)(param_1[0xf4] + *(int *)(gpGlobals + 0x98));
        }
        (*DAT_0017556c)(param_1[0xf3],puVar2);
        *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) & 0xfe;
      }
    }
  }
  return;
}


// Use__6CShakeP11CBaseEntityT18USE_TYPEf  @ 000af7a0
void Use__6CShakeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  UTIL_ScreenShake__FRC6Vectorffff
            (iVar1 + 8,*(undefined4 *)(iVar1 + 0x124),*(undefined4 *)(iVar1 + 0x1bc),
             *(undefined4 *)(iVar1 + 0x1b8),*(undefined4 *)(iVar1 + 0x1c0));
  return;
}


// Use__7CCyclerP11CBaseEntityT18USE_TYPEf  @ 000bb9c0
void Use__7CCyclerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x184];
  param_1[0x184] = (uint)(iVar1 == 0);
  if ((iVar1 == 0) == 0) {
    *(undefined4 *)(*param_1 + 0x118) = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
  }
  return;
}


// Use__7CSpriteP11CBaseEntityT18USE_TYPEf  @ 000ae4c0
void Use__7CSpriteP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = *(int *)(*param_1 + 0xf8) != 0x80;
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


// Use__7CTFGoalP11CBaseEntityT18USE_TYPEf  @ 0010dc40
void Use__7CTFGoalP11CBaseEntityT18USE_TYPEf(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x28))(param_2);
  if (iVar1 == 2) {
    *(undefined4 *)(param_1 + 0x274) = 1;
    ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_3);
  }
  return;
}


// Use__8CMessageP11CBaseEntityT18USE_TYPEf  @ 000afb50
void Use__8CMessageP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
    if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x184) & 8) == 0)) {
      iVar1 = (*DAT_001755e0)(1);
    }
    else {
      iVar1 = *(int *)(*param_2 + 0x1e8);
    }
    if (iVar1 != 0) {
      UTIL_ShowMessage__FPCcP7edict_s(*(int *)(*param_1 + 0x1b4) + *(int *)(gpGlobals + 0x98),iVar1)
      ;
    }
  }
  else {
    UTIL_ShowMessageAll__FPCc(*(int *)(*param_1 + 0x1b4) + *(int *)(gpGlobals + 0x98));
  }
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1c8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),4,*(int *)(iVar1 + 0x1c8) + *(int *)(gpGlobals + 0x98)
               ,*(undefined4 *)(iVar1 + 0x124),*(undefined4 *)(iVar1 + 0x1d8),0,100);
  }
  if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return;
}


// Use__9CBaseDoorP11CBaseEntityT18USE_TYPEf  @ 000a9cb0
void Use__9CBaseDoorP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  if (((*(byte *)(param_1 + 0x88) & 8) == 0) ||
     ((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 8.0) << 0xe) >> 8)) == 0x40)) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x10f,param_2);
    if ((param_1[0xfa] == 1) ||
       (((*(byte *)(*param_1 + 0x180) & 0x20) != 0 && (param_1[0xfa] == 0)))) {
      DoorActivate__9CBaseDoor(param_1);
    }
  }
  return;
}


// Use__9CBubblingP11CBaseEntityT18USE_TYPEf  @ 000ab3c0
void Use__9CBubblingP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0xf6]);
  if (iVar1 != 0) {
    param_1[0xf6] = (uint)(param_1[0xf6] == 0);
  }
  if (param_1[0xf6] == 0) {
    param_1[3] = 0;
    param_1[4] = 0;
    *(undefined4 *)(*param_1 + 0xe4) = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)FizzThink__9CBubbling;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  return;
}


// Use__9CFuncTankP11CBaseEntityT18USE_TYPEf  @ 000b48a0
void Use__9CFuncTankP11CBaseEntityT18USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,int param_4,float param_5)

{
  byte *pbVar1;
  int iVar2;
  
  if ((*(byte *)(*param_1 + 0x180) & 0x20) == 0) {
    iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,*(byte *)(*param_1 + 0x180) & 1);
    if (iVar2 != 0) {
      if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
        *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 1;
        *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 0.1;
        param_1[0x100] = 0;
      }
      else {
        pbVar1 = (byte *)(*param_1 + 0x180);
        *pbVar1 = *pbVar1 & 0xfe;
        param_1[0x100] = 0;
        StopRotSound__9CFuncTank(param_1);
      }
    }
  }
  else {
    iVar2 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x28))(param_2);
    if (iVar2 == 2) {
      iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar2 != 0) {
        if (((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_5 == 2.0) << 0xe) >> 8)) == 0x40) &&
           (param_4 == 2)) {
          ControllerPostFrame__9CFuncTank(param_1);
        }
        else if ((param_1[0xf3] == 0) && (param_4 != 0)) {
          __as__7EHANDLEP11CBaseEntity(param_2 + 0x7e0,param_1);
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


// Use__9CFuncWallP11CBaseEntityT18USE_TYPEf  @ 0009b6d0
void Use__9CFuncWallP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi
                    (param_1,param_4,(int)ROUND(*(float *)(*param_1 + 0x110)));
  if (iVar1 != 0) {
    *(float *)(*param_1 + 0x110) = 1.0 - *(float *)(*param_1 + 0x110);
  }
  return;
}


// Use__9CPushableP11CBaseEntityT18USE_TYPEf  @ 000b3890
void Use__9CPushableP11CBaseEntityT18USE_TYPEf
               (int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  float fVar1;
  bool bVar2;
  
  if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x184) & 8) == 0)) {
    if (*(char *)(*param_1 + 0x180) < '\0') {
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
       (byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(DAT_00175484 == fVar1) << 0xe) >> 8)) == 0x40)) {
      fVar1 = *(float *)(*param_2 + 0x28);
      bVar2 = (byte)(DAT_00175488 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar2) {
      Move__9CPushableP11CBaseEntityi(param_1,param_2,0);
    }
  }
  return;
}


// Use__9CRechargeP11CBaseEntityT18USE_TYPEf  @ 000bab80
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
  if (param_1[0x11d] < 1) {
    *(undefined4 *)(*param_1 + 0x110) = 0x3f800000;
    Off__9CRecharge(param_1);
    if (param_1[0x11d] < 1) goto LAB_000babe7;
  }
  if (*(int *)(*param_2 + 0x148) < 0) {
    *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 0.25;
    param_1[3] = -0x10000;
    param_1[4] = (int)Off__9CRecharge;
    if (*gpGlobals <= (float)param_1[0x11b]) {
      return;
    }
    if (param_2 == (int *)0x0) {
      return;
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x10f,param_2);
    piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x10f);
    if ((*(byte *)(*piVar5 + 0x184) & 8) == 0) {
      return;
    }
    if (param_1[0x11e] == 0) {
      param_1[0x11e] = 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),3,"items/suitchargeok1.wav",0x3f59999a,0x3f4ccccd
                 ,0,100);
      param_1[0x11f] = (int)(*gpGlobals + 0.56);
    }
    if (param_1[0x11e] == 1) {
      fVar1 = (float)param_1[0x11f];
      fVar2 = *gpGlobals;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        param_1[0x11e] = 2;
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),6,"items/suitcharge1.wav",0x3f59999a,0x3f4ccccd
                   ,0,100);
      }
    }
    piVar5 = param_1 + 0x10f;
    piVar6 = (int *)__rf__7EHANDLE(piVar5);
    iVar4 = *piVar6;
    iVar7 = __rf__7EHANDLE(piVar5);
    fVar1 = *(float *)(iVar4 + 0x19c);
    fVar2 = *(float *)(iVar7 + 0xf0);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      param_1[0x11d] = param_1[0x11d] + -1;
      piVar6 = (int *)__rf__7EHANDLE(piVar5);
      *(float *)(*piVar6 + 0x19c) = *(float *)(*piVar6 + 0x19c) + 1.0;
      piVar6 = (int *)__rf__7EHANDLE(piVar5);
      iVar4 = *piVar6;
      iVar7 = __rf__7EHANDLE(piVar5);
      if (*(float *)(iVar7 + 0xf0) < *(float *)(iVar4 + 0x19c)) {
        piVar6 = (int *)__rf__7EHANDLE(piVar5);
        iVar4 = __rf__7EHANDLE(piVar5);
        *(undefined4 *)(*piVar6 + 0x19c) = *(undefined4 *)(iVar4 + 0xf0);
      }
      piVar5 = param_1 + 0x10f;
      piVar6 = (int *)__rf__7EHANDLE(piVar5);
      iVar4 = *piVar6;
      piVar6 = (int *)__rf__7EHANDLE(piVar5);
      fVar1 = *(float *)(*piVar6 + 0x198);
      if ((byte)(0.8 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.8) << 0xe) >> 8)) == 1) {
        piVar5 = (int *)__rf__7EHANDLE(piVar5);
        uVar3 = *(undefined4 *)(*piVar5 + 0x198);
      }
      else {
        uVar3 = 0x3f4ccccd;
      }
      *(undefined4 *)(iVar4 + 0x198) = uVar3;
    }
    param_1[0x11b] = (int)(*gpGlobals + 0.1);
    return;
  }
LAB_000babe7:
  fVar1 = (float)param_1[0x11f];
  fVar2 = *gpGlobals;
  if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    param_1[0x11f] = (int)(*gpGlobals + 0.62);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),3,"items/suitchargeno1.wav",0x3f59999a,0x3f4ccccd,0
               ,100);
  }
  return;
}


