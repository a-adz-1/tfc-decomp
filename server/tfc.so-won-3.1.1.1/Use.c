// Use__10CBreakableP11CBaseEntityT18USE_TYPEf  @ 000a97e8
void Use__10CBreakableP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = IsBreakable__10CBreakable(param_1);
  if (iVar1 != 0) {
    *(int *)(*param_1 + 0x54) = param_1[0x11b];
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    g_vecAttackDir = *(undefined4 *)(gpGlobals + 0x28);
    DAT_0019f670 = *(undefined4 *)(gpGlobals + 0x2c);
    DAT_0019f674 = *(undefined4 *)(gpGlobals + 0x30);
    Die__10CBreakable(param_1);
  }
  return;
}


// Use__10CEnvFunnelP11CBaseEntityT18USE_TYPEf  @ 000a32e4
void Use__10CEnvFunnelP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  (*DAT_0019f758)(0,0x17,0,0);
  (*DAT_0019f760)(100);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f768)(param_1[0x118]);
  (*DAT_0019f768)((*(byte *)(*param_1 + 0x1a0) & 1) != 0);
  (*DAT_0019f75c)();
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__10CEnvGlobalP11CBaseEntityT18USE_TYPEf  @ 0008d2b0
void Use__10CEnvGlobalP11CBaseEntityT18USE_TYPEf(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = EntityGetState__12CGlobalStatei(&gGlobalState,*(undefined4 *)(param_1 + 0x458));
  switch(*(undefined4 *)(param_1 + 0x45c)) {
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
  iVar1 = Find__12CGlobalStatei(&gGlobalState,*(undefined4 *)(param_1 + 0x458));
  if (iVar1 == 0) {
    EntityAdd__12CGlobalStateii12GLOBALESTATE
              (&gGlobalState,*(undefined4 *)(param_1 + 0x458),*(undefined4 *)(gpGlobals + 0xc),iVar2
              );
  }
  else {
    EntitySetState__12CGlobalStatei12GLOBALESTATE
              (&gGlobalState,*(undefined4 *)(param_1 + 0x458),iVar2);
  }
  return;
}


// Use__10CFuncTrainP11CBaseEntityT18USE_TYPEf  @ 000d245c
void Use__10CFuncTrainP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  uVar1 = *(uint *)(iVar2 + 0x1a0);
  if ((uVar1 & 1) == 0) {
    *(uint *)(iVar2 + 0x1a0) = uVar1 | 1;
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 400) != 0) {
      *(undefined4 *)(iVar2 + 0x1c8) = *(undefined4 *)(*(int *)(iVar2 + 400) + 0x24c);
      iVar2 = *param_1;
    }
    *(undefined4 *)(iVar2 + 0x104) = 0;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x24) = DAT_0019f664;
    *(undefined4 *)(iVar2 + 0x28) = DAT_0019f668;
    iVar2 = *(int *)(*param_1 + 0x1ec);
    if (iVar2 != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,iVar2 + *(int *)(gpGlobals + 0x98),
                 param_1[0x13f],0x3f4ccccd,0,100);
    }
  }
  else {
    *(uint *)(iVar2 + 0x1a0) = uVar1 & 0xfffffffe;
    Next__10CFuncTrain(param_1);
  }
  return;
}


// Use__10CGunTargetP11CBaseEntityT18USE_TYPEf  @ 000d161c
void Use__10CGunTargetP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x1a7]);
  if (iVar1 != 0) {
    if (param_1[0x1a7] == 0) {
      *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
      uVar2 = (**(code **)(param_1[0x115] + 0xac))(param_1);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x141,uVar2);
      iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
      if (iVar1 != 0) {
        *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
        Next__10CGunTarget(param_1);
      }
    }
    else {
      (**(code **)(param_1[0x115] + 0x154))(param_1);
    }
  }
  return;
}


// Use__10CPathTrackP11CBaseEntityT18USE_TYPEf  @ 000ccc58
void Use__10CPathTrackP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  if (param_1[0x11a] == 0) {
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


// Use__10CTeamCheckP11CBaseEntityT18USE_TYPEf  @ 001119a0
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


// Use__11CBaseEntityP11CBaseEntityT18USE_TYPEf  @ 00112c3c
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


// Use__11CGibShooterP11CBaseEntityT18USE_TYPEf  @ 000a40f0
void Use__11CGibShooterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)ShootThink__11CGibShooter;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__11CTestEffectP11CBaseEntityT18USE_TYPEf  @ 000a3c68
void Use__11CTestEffectP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)TestThink__11CTestEffect;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x14a] = (int)*gpGlobals;
  return;
}


// Use__11CWallHealthP11CBaseEntityT18USE_TYPEf  @ 000b543c
void Use__11CWallHealthP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if ((*(byte *)(*param_2 + 0x1a4) & 8) == 0) {
    return;
  }
  if (param_1[0x140] < 1) {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
    Off__11CWallHealth(param_1);
    if (param_1[0x140] < 1) goto LAB_000b54a0;
  }
  if (*(int *)(*param_2 + 0x168) < 0) {
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.25;
    param_1[3] = -0x10000;
    param_1[4] = (int)Off__11CWallHealth;
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x13e];
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
      return;
    }
    iVar3 = param_1[0x141];
    if (iVar3 == 0) {
      param_1[0x141] = 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"items/medshot4.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      iVar3 = param_1[0x141];
      param_1[0x142] = (int)(*gpGlobals + 0.56);
    }
    if (iVar3 == 1) {
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x142];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        param_1[0x141] = 2;
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),6,"items/medcharge4.wav",0x3f800000,0x3f4ccccd,
                   0,100);
      }
    }
    iVar3 = (**(code **)(param_2[0x115] + 0x3c))(param_2,0x3f800000,0);
    if (iVar3 != 0) {
      param_1[0x140] = param_1[0x140] + -1;
    }
    param_1[0x13e] = (int)(*gpGlobals + 0.1);
    return;
  }
LAB_000b54a0:
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x142];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    param_1[0x142] = (int)(fVar1 + 0.62);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/medshotno1.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  return;
}


// Use__12CCineMonsterP11CBaseEntityT18USE_TYPEf  @ 000eb5c4
void Use__12CCineMonsterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x50))(iVar1);
  }
  if (iVar2 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__12CCineMonster;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  else if (*(int *)(iVar2 + 0x694) != 0) {
    param_1[0x1af] = (int)(*gpGlobals + 0.05);
  }
  return;
}


// Use__12CEnvBeverageP11CBaseEntityT18USE_TYPEf  @ 000a3128
void Use__12CEnvBeverageP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x164)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x164) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (0.0 < *(float *)(iVar2 + 0x160))) {
    piVar1 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                              ("item_sodacan",iVar2 + 8,iVar2 + 0x50,*(undefined4 *)(iVar2 + 0x208))
    ;
    iVar2 = *(int *)(*param_1 + 0x110);
    if (iVar2 == 6) {
      iVar2 = (*DAT_0019f808)(0,5);
    }
    *(int *)(*piVar1 + 0x110) = iVar2;
    *(undefined4 *)(*param_1 + 0x164) = 0x3f800000;
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - 1.0;
  }
  return;
}


// Use__12CMultiSourceP11CBaseEntityT18USE_TYPEf  @ 0008d08c
void Use__12CMultiSourceP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < param_1[0x176]) {
    iVar4 = 0;
    do {
      iVar1 = iVar4 * 2;
      iVar4 = iVar4 + 1;
      puVar2 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(param_1 + iVar1 + 0x116);
      if (puVar2 == param_3) break;
    } while (iVar4 < param_1[0x176]);
  }
  if (param_1[0x176] < iVar4) {
    (*DAT_0019f794)(1,"MultiSrc:Used by non member %s.\n",
                    *(int *)*param_3 + *(int *)(gpGlobals + 0x98));
  }
  else {
    *(byte *)(param_1 + iVar4 + 0x155) = *(byte *)(param_1 + iVar4 + 0x155) ^ 1;
    iVar4 = (**(code **)(param_1[0x115] + 0x4c))(param_1);
    if (iVar4 != 0) {
      (*DAT_0019f794)(2,"Multisource %s enabled (%d inputs)\n",
                      *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),param_1[0x176]);
      uVar3 = 3;
      if (param_1[0x177] != 0) {
        uVar3 = 1;
      }
      SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,0,uVar3,0);
    }
  }
  return;
}


// Use__12CRevertSavedP11CBaseEntityT18USE_TYPEf  @ 000e4920
void Use__12CRevertSavedP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  UTIL_ScreenFadeAll__FRC6Vectorffii
            (iVar1 + 0x150,*(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1dc),
             (int)ROUND(*(float *)(iVar1 + 0x14c)),1);
  *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x116];
  param_1[3] = -0x10000;
  param_1[4] = (int)MessageThink__12CRevertSaved;
  return;
}


// Use__13CButtonTargetP11CBaseEntityT18USE_TYPEf  @ 0008c208
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
               (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40,0);
  }
  return;
}


// Use__13CCyclerSpriteP11CBaseEntityT18USE_TYPEf  @ 000b4154
void Use__13CCyclerSpriteP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  param_1[0x116] = (uint)(param_1[0x116] == 0);
  (*DAT_0019f794)(1,"Sprite: %s\n",*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Use__13CEnvExplosionP11CBaseEntityT18USE_TYPEf  @ 000a6fa4
void Use__13CEnvExplosionP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_18;
  float local_14;
  float local_10;
  
  *(undefined4 *)(*param_1 + 0xb8) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  iVar2 = *param_1;
  local_40 = *(float *)(iVar2 + 0x10) + 8.0;
  local_60 = *(float *)(iVar2 + 8);
  local_5c = *(float *)(iVar2 + 0xc);
  local_4c = -40.0;
  local_58 = local_40 + -40.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_48 = local_60;
  local_44 = local_5c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&local_60,1,*(undefined4 *)(iVar2 + 0x208),local_3c);
  if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x10) = *(undefined4 *)(*param_1 + 0x10);
  }
  else {
    iVar2 = *param_1;
    fVar1 = (float)(param_1[0x1a7] + -0x18);
    local_54 = local_18 * fVar1 * 0.6;
    local_60 = local_54 + local_28;
    local_50 = local_14 * fVar1 * 0.6;
    local_5c = local_50 + local_24;
    local_4c = fVar1 * local_10 * 0.6;
    local_58 = local_4c + local_20;
    *(float *)(iVar2 + 8) = local_60;
    *(float *)(iVar2 + 0xc) = local_5c;
    *(float *)(iVar2 + 0x10) = local_58;
  }
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 0x10) == 0) {
    lVar4 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
    lVar5 = (longdouble)0.5;
    if ((byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1) < 0x40) {
      UTIL_DecalTrace__FP11TraceResulti(local_3c,0xc);
      iVar2 = *param_1;
    }
    else {
      UTIL_DecalTrace__FP11TraceResulti(local_3c,0xb);
      iVar2 = *param_1;
    }
  }
  if ((*(byte *)(iVar2 + 0x1a0) & 4) == 0) {
    (*DAT_0019f758)(5,0x17,iVar2 + 8,0);
    (*DAT_0019f760)(3);
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_0019f768)((int)g_sModelIndexFireball);
    (*DAT_0019f760)((char)param_1[0x1a8]);
    (*DAT_0019f760)(0xf);
    (*DAT_0019f760)(3);
    (*DAT_0019f75c)();
  }
  else {
    (*DAT_0019f758)(5,0x17,iVar2 + 8,0);
    (*DAT_0019f760)(3);
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_0019f768)((int)g_sModelIndexFireball);
    (*DAT_0019f760)(0);
    (*DAT_0019f760)(0xf);
    (*DAT_0019f760)(3);
    (*DAT_0019f75c)();
  }
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x1a0) ^ 1) & 1) != 0) {
    (**(code **)(param_1[0x115] + 0x200))(param_1,iVar2,iVar2,(float)param_1[0x1a7],0,0x40);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Smoke__13CEnvExplosion;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
    iVar2 = (*DAT_0019f808)(0,3);
    if (0 < iVar2) {
      iVar3 = 0;
      do {
        Create__11CBaseEntityPcRC6VectorT2P7edict_s("spark_shower",*param_1 + 8,&local_18,0);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
  }
  return;
}


// Use__13CFuncConveyorP11CBaseEntityT18USE_TYPEf  @ 00089bf8
void Use__13CFuncConveyorP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(float *)(*param_1 + 0x1f8) = -*(float *)(*param_1 + 0x1f8);
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x1f8);
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    *(undefined4 *)(iVar2 + 0x150) = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 0x150) = 0x3f800000;
  }
  *(float *)(*param_1 + 0x154) = (float)((int)ROUND(ABS(fVar1) * 16.0) >> 8);
  *(float *)(*param_1 + 0x158) = (float)((int)ROUND(ABS(fVar1) * 16.0) & 0xff);
  return;
}


// Use__13CStripWeaponsP11CBaseEntityT18USE_TYPEf  @ 000e4b7c
void Use__13CStripWeaponsP11CBaseEntityT18USE_TYPEf(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) &&
     (param_2 = (int *)0x0,
     (byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x14)) << 10) >> 8) |
           (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x14) == 0.0) << 0xe) >> 8)) == 0x40)) {
    iVar1 = (*DAT_0019f7c0)(1);
    if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
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


// Use__13CTriggerRelayP11CBaseEntityT18USE_TYPEf  @ 00119b98
void Use__13CTriggerRelayP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,param_1[0x118],0);
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Use__14CFuncTrackAutoP11CBaseEntityT18USE_TYPEf  @ 000d10e8
void Use__14CFuncTrackAutoP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x538) != 0) {
    if (*(int *)(param_1 + 0x474) == 0) {
      iVar2 = *(int *)(param_1 + 0x518);
    }
    else {
      iVar2 = 0;
      if (*(int *)(param_1 + 0x474) == 1) {
        iVar2 = *(int *)(param_1 + 0x51c);
      }
    }
    iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
    if (iVar1 == 0) {
      iVar2 = EvaluateTrain__16CFuncTrackChangeP10CPathTrack(param_1,iVar2);
      *(int *)(param_1 + 0x530) = iVar2;
      if ((iVar2 == 2) && (*(int *)(param_1 + 0x474) != *(int *)(param_1 + 0x534))) {
        *(undefined4 *)(param_1 + 0x538) = 0;
        if (*(int *)(param_1 + 0x474) == 0) {
          (**(code **)(*(int *)(param_1 + 0x454) + 0x114))(param_1);
        }
        else {
          (**(code **)(*(int *)(param_1 + 0x454) + 0x110))(param_1);
        }
      }
    }
    else {
      if (iVar2 != 0) {
        iVar2 = GetNext__10CPathTrack(iVar2);
        if ((iVar2 != 0) && (*(int *)(*(int *)(param_1 + 0x520) + 0x458) != iVar2)) {
          iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi
                            (param_1,param_4,*(undefined4 *)(param_1 + 0x534));
          if (iVar2 != 0) {
            if (*(int *)(param_1 + 0x534) == 0) {
              *(undefined4 *)(param_1 + 0x534) = 1;
            }
            else {
              *(undefined4 *)(param_1 + 0x534) = 0;
            }
          }
        }
      }
      (**(code **)(*(int *)(param_1 + 0x454) + 0x120))(param_1,*(undefined4 *)(param_1 + 0x534));
    }
  }
  return;
}


// Use__14CMomentaryDoorP11CBaseEntityT18USE_TYPEf  @ 0009ec7c
void Use__14CMomentaryDoorP11CBaseEntityT18USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if ((param_4 == 2) &&
     (((param_2 != 0 &&
       (iVar4 = (**(code **)(*(int *)(param_2 + 0x454) + 0x2c))(param_2), iVar4 != 2)) ||
      (iVar4 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar4 != 0))
     )) {
    if (1.0 < param_5) {
      param_5 = 1.0;
    }
    fStack_10 = (float)param_1[0x124] + ((float)param_1[0x127] - (float)param_1[0x124]) * param_5;
    fStack_18 = ((float)param_1[0x128] - (float)param_1[0x125]) * param_5;
    fStack_c = (float)param_1[0x125] + fStack_18;
    fStack_14 = ((float)param_1[0x129] - (float)param_1[0x126]) * param_5;
    fStack_8 = (float)param_1[0x126] + fStack_14;
    iVar4 = *param_1;
    fVar3 = fStack_10 - *(float *)(iVar4 + 8);
    fVar2 = fStack_c - *(float *)(iVar4 + 0xc);
    fVar1 = fStack_8 - *(float *)(iVar4 + 0x10);
    fStack_1c = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
    fVar3 = fStack_1c * 10.0;
    if ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = *(float *)(iVar4 + 0x104);
      fVar2 = *(float *)(iVar4 + 0x100);
      if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) ||
         ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar4 + 0x208),6,
                   *(int *)(iVar4 + 0x1ec) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100)
        ;
      }
      fStack_1c = fStack_10;
      fStack_18 = fStack_c;
      fStack_14 = fStack_8;
      LinearMove__11CBaseToggleG6Vectorf(param_1,&fStack_1c,fVar3);
    }
  }
  return;
}


// Use__14CTargetCDAudioP11CBaseEntityT18USE_TYPEf  @ 001190e8
void Use__14CTargetCDAudioP11CBaseEntityT18USE_TYPEf(undefined4 param_1)

{
  Play__14CTargetCDAudio(param_1);
  return;
}


// Use__14CTriggerCameraP11CBaseEntityT18USE_TYPEf  @ 00116fac
void Use__14CTriggerCameraP11CBaseEntityT18USE_TYPEf
               (int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  longdouble lVar6;
  float local_10;
  float local_c;
  float local_8;
  
  iVar4 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x126]);
  if (iVar4 != 0) {
    iVar4 = param_1[0x126];
    param_1[0x126] = (uint)(iVar4 == 0);
    if ((iVar4 == 0) == 0) {
      param_1[0x11f] = (int)*gpGlobals;
    }
    else {
      if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) {
        iVar4 = (*DAT_0019f7c0)(1);
        if ((iVar4 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
          param_2 = (int *)0x0;
        }
        else {
          param_2 = *(int **)(iVar4 + 0x7c);
        }
      }
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x118,param_2);
      param_1[0x11f] = (int)(*gpGlobals + (float)param_1[0x11e]);
      *(int *)(*param_1 + 0x1f8) = param_1[0x123];
      param_1[0x122] = param_1[0x123];
      if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
        uVar5 = (**(code **)(param_1[0x115] + 0xac))(param_1);
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x11a,uVar5);
      }
      else {
        param_1[0x11a] = param_1[0x118];
        param_1[0x11b] = param_1[0x119];
      }
      iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11a);
      if (iVar4 != 0) {
        if ((*(byte *)(*param_1 + 0x1a0) & 4) != 0) {
          EnableControl__11CBasePlayeri(param_2,0);
        }
        if (param_1[0x11d] == 0) {
          param_1[0x11c] = 0;
        }
        else {
          iVar4 = (*DAT_0019f6d8)(0,"targetname",param_1[0x11d] + (int)gpGlobals[0x26]);
          if ((iVar4 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
            iVar4 = 0;
          }
          else {
            iVar4 = *(int *)(iVar4 + 0x7c);
          }
          param_1[0x11c] = iVar4;
        }
        piVar2 = (int *)param_1[0x11c];
        param_1[0x120] = (int)*gpGlobals;
        if (piVar2 != (int *)0x0) {
          fVar1 = *(float *)(*piVar2 + 0x1f8);
          if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
            param_1[0x122] = (int)fVar1;
          }
          lVar6 = (longdouble)(**(code **)(piVar2[0x115] + 0x68))(piVar2);
          param_1[0x120] = (int)(float)(lVar6 + (longdouble)(float)param_1[0x120]);
        }
        iVar4 = *param_1;
        if ((*(byte *)(iVar4 + 0x1a0) & 1) == 0) {
          local_10 = 0.0;
          local_c = 0.0;
          local_8 = 0.0;
          *(undefined4 *)(iVar4 + 0x20) = 0;
          *(undefined4 *)(iVar4 + 0x24) = 0;
          uVar5 = 0;
        }
        else {
          iVar3 = *param_2;
          local_10 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
          local_c = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x178);
          local_8 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x17c);
          UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar4,&local_10);
          *(float *)(*param_1 + 0x50) = -*(float *)(*param_2 + 0x50);
          *(undefined4 *)(*param_1 + 0x54) = *(undefined4 *)(*param_2 + 0x54);
          *(undefined4 *)(*param_1 + 0x58) = 0;
          iVar4 = *param_1;
          iVar3 = *param_2;
          *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
          *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(iVar3 + 0x24);
          uVar5 = *(undefined4 *)(iVar3 + 0x28);
        }
        *(undefined4 *)(iVar4 + 0x28) = uVar5;
        (*DAT_0019f810)(*(undefined4 *)(*param_2 + 0x208),*(undefined4 *)(*param_1 + 0x208));
        (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                        *(int *)(*param_2 + 0xb8) + (int)gpGlobals[0x26]);
        param_1[3] = -0x10000;
        param_1[4] = (int)FollowTarget__14CTriggerCamera;
        *(float *)(*param_1 + 0x104) = *gpGlobals;
        param_1[0x121] = 0;
        Move__14CTriggerCamera(param_1);
      }
    }
  }
  return;
}


// Use__15CFuncTrackTrainP11CBaseEntityT18USE_TYPEf  @ 000ceb9c
void Use__15CFuncTrackTrainP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (param_4 == 2) {
    fVar1 = param_5 * 0.25 +
            (float)((int)ROUND(*(float *)(*param_1 + 0x1f8) * 4.0) /
                   (int)ROUND((float)param_1[0x119])) * 0.25;
    fVar2 = 1.0;
    if ((fVar1 <= 1.0) &&
       (fVar2 = fVar1,
       0x3f < (byte)((-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) - 1))) {
      fVar2 = -1.0;
    }
    if (((*(byte *)(*param_1 + 0x1a0) & 4) != 0) &&
       (0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      fVar2 = 0.0;
    }
    *(float *)(*param_1 + 0x1f8) = (float)param_1[0x119] * fVar2;
    Next__15CFuncTrackTrain(param_1);
    (*DAT_0019f794)(2,"TRAIN(%s), speed to %.2f\n",
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
      iVar3 = *param_1;
      if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x1f8)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
        *(float *)(iVar3 + 0x1f8) = (float)param_1[0x119] * (float)param_1[0x11a];
        Next__15CFuncTrackTrain(param_1);
      }
      else {
        *(undefined4 *)(iVar3 + 0x1f8) = 0;
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x24) = DAT_0019f664;
        *(undefined4 *)(iVar3 + 0x28) = DAT_0019f668;
        iVar3 = *param_1;
        *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
        *(undefined4 *)(iVar3 + 0x60) = DAT_0019f664;
        *(undefined4 *)(iVar3 + 100) = DAT_0019f668;
        StopSound__15CFuncTrackTrain(param_1);
        param_1[3] = 0;
        param_1[4] = 0;
      }
    }
  }
  return;
}


// Use__15CFuncWallToggleP11CBaseEntityT18USE_TYPEf  @ 00089dd0
void Use__15CFuncWallToggleP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = *(int *)(*param_1 + 0x10c) != 0;
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,bVar2);
  if (iVar1 != 0) {
    if (bVar2) {
      *(undefined4 *)(*param_1 + 0x10c) = 0;
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    }
    else {
      *(undefined4 *)(*param_1 + 0x10c) = 4;
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
    }
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  }
  return;
}


// Use__15CTriggerCDAudioP11CBaseEntityT18USE_TYPEf  @ 001193cc
void Use__15CTriggerCDAudioP11CBaseEntityT18USE_TYPEf(undefined4 param_1)

{
  PlayTrack__15CTriggerCDAudio(param_1);
  return;
}


// Use__16CFuncMonsterClipP11CBaseEntityT18USE_TYPEf  @ 000899ec
void Use__16CFuncMonsterClipP11CBaseEntityT18USE_TYPEf(void)

{
  return;
}


// Use__16CFuncTrackChangeP11CBaseEntityT18USE_TYPEf  @ 000d1c30
void Use__16CFuncTrackChangeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  uVar1 = param_1[0x11d];
  if (1 < uVar1) {
    return;
  }
  if (uVar1 == 0) {
    iVar2 = param_1[0x146];
  }
  else {
    if (uVar1 != 1) {
      param_1[0x14c] = 1;
      goto LAB_000d1c8a;
    }
    iVar2 = param_1[0x147];
  }
  iVar2 = EvaluateTrain__16CFuncTrackChangeP10CPathTrack(param_1,iVar2);
  param_1[0x14c] = iVar2;
LAB_000d1c8a:
  if (param_1[0x14c] == 1) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),2,"buttons/button11.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  else {
    param_1[0x14e] = 0;
    if (param_1[0x11d] == 0) {
      pcVar3 = *(code **)(param_1[0x115] + 0x114);
    }
    else {
      pcVar3 = *(code **)(param_1[0x115] + 0x110);
    }
    (*pcVar3)(param_1);
  }
  return;
}


// Use__16CRenderFxManagerP11CBaseEntityT18USE_TYPEf  @ 0011462c
void Use__16CRenderFxManagerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x1c8) != 0) {
    iVar4 = 0;
LAB_00114658:
    iVar4 = (*DAT_0019f6d8)(iVar4,"targetname",*(int *)(iVar2 + 0x1c8) + *(int *)(gpGlobals + 0x98))
    ;
    bVar1 = false;
    if (iVar4 == 0) {
LAB_001146a6:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_0019f7b8)(iVar4);
      if (iVar2 == 0) goto LAB_001146a6;
    }
    if (!bVar1) {
      iVar3 = iVar4 + 0x80;
      if (iVar4 == 0) {
        iVar3 = 0;
      }
      iVar2 = *param_1;
      if (((*(byte *)(iVar2 + 0x1a0) ^ 1) & 1) != 0) {
        *(undefined4 *)(iVar3 + 0x15c) = *(undefined4 *)(iVar2 + 0x15c);
        iVar2 = *param_1;
      }
      if ((*(byte *)(iVar2 + 0x1a0) & 2) == 0) {
        *(undefined4 *)(iVar3 + 0x14c) = *(undefined4 *)(iVar2 + 0x14c);
        iVar2 = *param_1;
      }
      if ((*(byte *)(iVar2 + 0x1a0) & 4) == 0) {
        *(undefined4 *)(iVar3 + 0x148) = *(undefined4 *)(iVar2 + 0x148);
        iVar2 = *param_1;
      }
      if ((*(byte *)(iVar2 + 0x1a0) & 8) == 0) {
        *(undefined4 *)(iVar3 + 0x150) = *(undefined4 *)(iVar2 + 0x150);
        *(undefined4 *)(iVar3 + 0x154) = *(undefined4 *)(iVar2 + 0x154);
        *(undefined4 *)(iVar3 + 0x158) = *(undefined4 *)(iVar2 + 0x158);
        iVar2 = *param_1;
      }
      goto LAB_00114658;
    }
  }
  return;
}


// Use__17CFuncTankControlsP11CBaseEntityT18USE_TYPEf  @ 000abdbc
void Use__17CFuncTankControlsP11CBaseEntityT18USE_TYPEf
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if (((param_2 == 0) ||
      (iVar1 = (**(code **)(*(int *)(param_2 + 0x454) + 0x2c))(param_2), iVar1 == 2)) &&
     (iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar1 == 0))
  {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x458);
  if (iVar1 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x454) + 0xb8))(iVar1,param_2,param_3,param_4,param_5);
  }
  return;
}


// Use__17CScriptedSentenceP11CBaseEntityT18USE_TYPEf  @ 000eaf78
void Use__17CScriptedSentenceP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  if (param_1[0x145] != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)FindThink__17CScriptedSentence;
    *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


// Use__18CLegacyCineMonsterP11CBaseEntityT18USE_TYPEf  @ 000b36cc
void Use__18CLegacyCineMonsterP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x134) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)CineThink__18CLegacyCineMonster;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Use__19CMomentaryRotButtonP11CBaseEntityT18USE_TYPEf  @ 0008c898
void Use__19CMomentaryRotButtonP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0x141);
  *(float *)(*param_1 + 0xac) = (float)(lVar1 / (longdouble)(float)param_1[0x11f]);
  UpdateAllButtons__19CMomentaryRotButtonfi(param_1,*(undefined4 *)(*param_1 + 0xac),1);
  UpdateTarget__19CMomentaryRotButtonf(param_1,*(undefined4 *)(*param_1 + 0xac));
  return;
}


// Use__20CTriggerChangeTargetP11CBaseEntityT18USE_TYPEf  @ 00117f20
void Use__20CTriggerChangeTargetP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                            (0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98))
  ;
  if (piVar1 != (int *)0x0) {
    *(int *)(*piVar1 + 0x1c8) = param_1[0x118];
    iVar2 = (**(code **)(piVar1[0x115] + 0x50))(piVar1);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 4) = 0;
    }
  }
  return;
}


// Use__5CFadeP11CBaseEntityT18USE_TYPEf  @ 000a3748
void Use__5CFadeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = *param_1;
  bVar2 = (*(byte *)(iVar1 + 0x1a0) ^ 1) & 1;
  if ((*(byte *)(iVar1 + 0x1a0) & 2) != 0) {
    bVar2 = bVar2 | 2;
  }
  UTIL_ScreenFadeAll__FRC6Vectorffii
            (iVar1 + 0x150,*(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1dc),
             (int)ROUND(*(float *)(iVar1 + 0x14c)),bVar2);
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return;
}


// Use__6CBloodP11CBaseEntityT18USE_TYPEf  @ 000a2900
void Use__6CBloodP11CBaseEntityT18USE_TYPEf(int *param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float **ppfVar4;
  float **ppfVar5;
  undefined1 *puVar6;
  undefined2 in_FPUControlWord;
  int aiStack_c8 [9];
  float *pfStack_a4;
  float local_6c;
  float local_68;
  float local_64;
  undefined1 local_60 [16];
  float local_50;
  undefined4 local_28;
  undefined2 local_20;
  undefined2 uStack_1e;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  ppfVar4 = (float **)&stack0xffffff60;
  ppfVar5 = (float **)&stack0xffffff60;
  pfStack_a4 = (float *)0xa2911;
  iVar2 = *param_1;
  uVar3 = *(uint *)(iVar2 + 0x1a0);
  if ((uVar3 & 2) == 0) {
    if ((uVar3 & 1) == 0) {
      local_1c = *(float *)(iVar2 + 0x44);
      local_18 = *(float *)(iVar2 + 0x48);
      local_14 = *(float *)(iVar2 + 0x4c);
    }
    else {
      ppfVar5 = &pfStack_a4;
      pfStack_a4 = &local_1c;
      UTIL_RandomBloodVector__Fv();
    }
    *(undefined4 *)((int)ppfVar5 + -4) = param_2;
    *(int **)((int)ppfVar5 + -8) = param_1;
    *(float **)((int)ppfVar5 + -0xc) = &local_10;
    *(undefined4 *)((int)ppfVar5 + -0x10) = 0xa29ea;
    BloodPosition__6CBloodP11CBaseEntity();
    iVar2 = *param_1;
    _local_20 = CONCAT22(uStack_1e,in_FPUControlWord);
    local_28 = CONCAT22(uStack_1e,CONCAT11(0xc,(char)in_FPUControlWord));
    *(int *)((int)ppfVar5 + -8) = (int)ROUND(*(float *)(iVar2 + 0x1e0));
    *(undefined4 *)((int)ppfVar5 + -0xc) = *(undefined4 *)(iVar2 + 0x184);
    *(float **)((int)ppfVar5 + -0x10) = &local_1c;
    *(float **)((int)ppfVar5 + -0x14) = &local_10;
    *(undefined4 *)((int)ppfVar5 + -0x18) = 0xa2a2a;
    UTIL_BloodDrips__FRC6VectorT0ii();
  }
  else {
    if ((uVar3 & 1) == 0) {
      local_10 = *(float *)(iVar2 + 0x44);
      local_c = *(float *)(iVar2 + 0x48);
      local_8 = *(float *)(iVar2 + 0x4c);
    }
    else {
      ppfVar4 = &pfStack_a4;
      pfStack_a4 = &local_10;
      UTIL_RandomBloodVector__Fv();
    }
    *(undefined4 *)((int)ppfVar4 + -4) = param_2;
    *(int **)((int)ppfVar4 + -8) = param_1;
    *(float **)((int)ppfVar4 + -0xc) = &local_1c;
    *(undefined4 *)((int)ppfVar4 + -0x10) = 0xa296a;
    BloodPosition__6CBloodP11CBaseEntity();
    iVar2 = *param_1;
    _local_20 = CONCAT22(uStack_1e,in_FPUControlWord);
    local_28 = CONCAT22(uStack_1e,CONCAT11(0xc,(char)in_FPUControlWord));
    *(int *)((int)ppfVar4 + -8) = (int)ROUND(*(float *)(iVar2 + 0x1e0));
    *(undefined4 *)((int)ppfVar4 + -0xc) = *(undefined4 *)(iVar2 + 0x184);
    *(float **)((int)ppfVar4 + -0x10) = &local_10;
    *(float **)((int)ppfVar4 + -0x14) = &local_1c;
    *(undefined4 *)((int)ppfVar4 + -0x18) = 0xa29aa;
    UTIL_BloodStream__FRC6VectorT0ii();
    ppfVar5 = ppfVar4;
  }
  puVar6 = (undefined1 *)((int)ppfVar5 + -4);
  iVar2 = *param_1;
  if ((*(uint *)(iVar2 + 0x1a0) & 8) != 0) {
    if ((*(uint *)(iVar2 + 0x1a0) & 1) == 0) {
      local_1c = *(float *)(iVar2 + 0x44);
      local_18 = *(float *)(iVar2 + 0x48);
      local_14 = *(float *)(iVar2 + 0x4c);
    }
    else {
      puVar6 = (undefined1 *)((int)ppfVar5 + -8);
      *(float **)((int)ppfVar5 + -8) = &local_1c;
      *(undefined4 *)((int)ppfVar5 + -0xc) = 0xa2a4c;
      UTIL_RandomBloodVector__Fv();
    }
    *(undefined4 *)(puVar6 + -4) = param_2;
    *(int **)(puVar6 + -8) = param_1;
    *(float **)(puVar6 + -0xc) = &local_10;
    *(undefined4 *)(puVar6 + -0x10) = 0xa2a73;
    BloodPosition__6CBloodP11CBaseEntity();
    fVar1 = *(float *)(*param_1 + 0x1e0);
    local_6c = local_1c * fVar1 + local_1c * fVar1 + local_10;
    local_68 = local_18 * fVar1 + local_18 * fVar1 + local_c;
    local_64 = fVar1 * local_14 + fVar1 * local_14 + local_8;
    *(undefined1 **)(puVar6 + -8) = local_60;
    *(undefined4 *)(puVar6 + -0xc) = 0;
    *(undefined4 *)(puVar6 + -0x10) = 1;
    *(float **)(puVar6 + -0x14) = &local_6c;
    *(float **)(puVar6 + -0x18) = &local_10;
    *(undefined4 *)(puVar6 + -0x1c) = 0xa2ad6;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
    if ((byte)(1.0 < local_50 | (byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) != 0x40) {
      *(undefined4 *)(puVar6 + -8) = *(undefined4 *)(*param_1 + 0x184);
      *(undefined1 **)(puVar6 + -0xc) = local_60;
      *(undefined4 *)(puVar6 + -0x10) = 0xa2afc;
      UTIL_BloodDecalTrace__FP11TraceResulti();
    }
  }
  return;
}


// Use__6CLaserP11CBaseEntityT18USE_TYPEf  @ 000a4c20
void Use__6CLaserP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = -1 < *(char *)(*param_1 + 0x118);
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,bVar2);
  if (iVar1 != 0) {
    if (bVar2) {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
      *(undefined4 *)(*param_1 + 0x104) = 0;
      if (param_1[0x116] != 0) {
        TurnOff__7CSprite(param_1[0x116]);
      }
    }
    else {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
      if (param_1[0x116] != 0) {
        TurnOn__7CSprite(param_1[0x116]);
      }
      *(undefined4 *)(*param_1 + 0x1e4) = *gpGlobals;
      *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
    }
  }
  return;
}


// Use__6CLightP11CBaseEntityT18USE_TYPEf  @ 000b68c8
void Use__6CLightP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  if (0x1f < param_1[0x116]) {
    iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi
                      (param_1,param_4,(*(byte *)(*param_1 + 0x1a0) ^ 1) & 1);
    if (iVar1 != 0) {
      if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
        (*DAT_0019f74c)(param_1[0x116],&DAT_0014cc3d);
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
      }
      else {
        if (param_1[0x117] == 0) {
          puVar2 = &DAT_0014cc3f;
        }
        else {
          puVar2 = (undefined *)(param_1[0x117] + *(int *)(gpGlobals + 0x98));
        }
        (*DAT_0019f74c)(param_1[0x116],puVar2);
        *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0xfe;
      }
    }
  }
  return;
}


// Use__6CShakeP11CBaseEntityT18USE_TYPEf  @ 000a38f4
void Use__6CShakeP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  UTIL_ScreenShake__FRC6Vectorffff
            (iVar1 + 8,*(undefined4 *)(iVar1 + 0x144),*(undefined4 *)(iVar1 + 0x1dc),
             *(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1e0));
  return;
}


// Use__7CCyclerP11CBaseEntityT18USE_TYPEf  @ 000b4578
void Use__7CCyclerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x1a7];
  param_1[0x1a7] = (uint)(iVar1 == 0);
  if ((iVar1 == 0) == 0) {
    *(undefined4 *)(*param_1 + 0x138) = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  }
  return;
}


// Use__7CSpriteP11CBaseEntityT18USE_TYPEf  @ 000a42a8
void Use__7CSpriteP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = *(int *)(*param_1 + 0x118) != 0x80;
  iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,bVar3);
  if (iVar2 != 0) {
    if (bVar3) {
      *(undefined4 *)(*param_1 + 0x118) = 0x80;
      *(undefined4 *)(*param_1 + 0x104) = 0;
    }
    else {
      *(undefined4 *)(*param_1 + 0x118) = 0;
      iVar2 = *param_1;
      fVar1 = *(float *)(iVar2 + 0x138);
      if ((((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
          (fVar1 = (float)param_1[0x117],
          (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1)) ||
         ((*(byte *)(iVar2 + 0x1a0) & 2) != 0)) {
        param_1[3] = -0x10000;
        param_1[4] = (int)AnimateThink__7CSprite;
        *(int *)(*param_1 + 0x104) = *gpGlobals;
        iVar2 = *param_1;
        param_1[0x116] = *gpGlobals;
      }
      *(undefined4 *)(iVar2 + 0x130) = 0;
    }
  }
  return;
}


// Use__7CTFGoalP11CBaseEntityT18USE_TYPEf  @ 00111a30
void Use__7CTFGoalP11CBaseEntityT18USE_TYPEf(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    iVar1 = (**(code **)(*(int *)(param_2 + 0x454) + 0x2c))(param_2);
    if (iVar1 != 2) {
      param_2 = 0;
    }
    if ((param_2 != 0) &&
       (iVar1 = (**(code **)(*(int *)(param_2 + 0x454) + 0x2c))(param_2), iVar1 != 2)) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x27c) = 1;
  iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_3);
  if (iVar1 != 0) {
    if ((param_3 == param_1) || (*(int *)(param_1 + 0x27c) == 1)) {
      uVar2 = 1;
    }
    else if (param_3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(param_3 + 0x230) & 2;
    }
    DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,param_2,uVar2);
  }
  return;
}


// Use__8CMessageP11CBaseEntityT18USE_TYPEf  @ 000a34b0
void Use__8CMessageP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 2) == 0) {
    if ((param_2 == (int *)0x0) || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)) {
      iVar1 = (*DAT_0019f7c0)(1);
      iVar2 = *param_1;
    }
    else {
      iVar1 = *(int *)(*param_2 + 0x208);
    }
    if (iVar1 == 0) goto LAB_000a3545;
    UTIL_ShowMessage__FPCcP7edict_s(*(int *)(iVar2 + 0x1d4) + *(int *)(gpGlobals + 0x98),iVar1);
  }
  else {
    UTIL_ShowMessageAll__FPCc(*(int *)(iVar2 + 0x1d4) + *(int *)(gpGlobals + 0x98));
  }
  iVar2 = *param_1;
LAB_000a3545:
  if (*(int *)(iVar2 + 0x1e8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar2 + 0x208),4,*(int *)(iVar2 + 0x1e8) + *(int *)(gpGlobals + 0x98)
               ,*(undefined4 *)(iVar2 + 0x144),*(undefined4 *)(iVar2 + 0x1f8),0,100);
    iVar2 = *param_1;
  }
  if ((*(byte *)(iVar2 + 0x1a0) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return;
}


// Use__8CTeamSetP11CBaseEntityT18USE_TYPEf  @ 00111934
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


// Use__9CBaseDoorP11CBaseEntityT18USE_TYPEf  @ 0009f0fc
void Use__9CBaseDoorP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  if (((*(byte *)(param_1 + 0x8a) & 8) == 0) ||
     ((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 8.0) << 0xe) >> 8)) == 0x40)) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x132,param_2);
    if ((param_1[0x11d] != 1) &&
       (((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0 || (param_1[0x11d] != 0)))) {
      if ((char)param_1[0x14a] != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 0x14a) = 1;
    }
    DoorActivate__9CBaseDoor(param_1);
  }
  return;
}


// Use__9CBubblingP11CBaseEntityT18USE_TYPEf  @ 000a58a8
void Use__9CBubblingP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x119]);
  if (iVar1 != 0) {
    param_1[0x119] = (uint)(param_1[0x119] == 0);
  }
  if (param_1[0x119] == 0) {
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


// Use__9CFuncTankP11CBaseEntityT18USE_TYPEf  @ 000aa5ec
void Use__9CFuncTankP11CBaseEntityT18USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,int param_4,float param_5)

{
  uint uVar1;
  int iVar2;
  
  if ((*(uint *)(*param_1 + 0x1a0) & 0x20) == 0) {
    iVar2 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,*(uint *)(*param_1 + 0x1a0) & 1);
    if (iVar2 != 0) {
      iVar2 = *param_1;
      uVar1 = *(uint *)(iVar2 + 0x1a0);
      if ((uVar1 & 1) == 0) {
        *(uint *)(iVar2 + 0x1a0) = uVar1 | 1;
        *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
        param_1[0x123] = 0;
      }
      else {
        *(uint *)(iVar2 + 0x1a0) = uVar1 & 0xfffffffe;
        param_1[0x123] = 0;
        StopRotSound__9CFuncTank(param_1);
      }
    }
  }
  else {
    iVar2 = (**(code **)(*(int *)(param_2 + 0x454) + 0x2c))(param_2);
    if (iVar2 == 2) {
      iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar2 != 0) {
        if (((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_5 == 2.0) << 0xe) >> 8)) == 0x40) &&
           (param_4 == 2)) {
          ControllerPostFrame__9CFuncTank(param_1);
        }
        else if (param_1[0x116] == 0) {
          if (param_4 != 0) {
            __as__7EHANDLEP11CBaseEntity(param_2 + 0x88c,param_1);
            if (param_1[0x116] == 0) {
              (*DAT_0019f794)(1,"using TANK!\n");
              param_1[0x116] = param_2;
              iVar2 = *(int *)(param_2 + 0x8dc);
              if (iVar2 != 0) {
                (**(code **)(*(int *)(iVar2 + 0x454) + 0x128))(iVar2,0);
                *(undefined4 *)(*(int *)param_1[0x116] + 0xc0) = 0;
              }
              *(byte *)(param_1[0x116] + 0x8b4) = *(byte *)(param_1[0x116] + 0x8b4) | 1;
              iVar2 = *(int *)param_1[0x116];
              param_1[0x118] = *(int *)(iVar2 + 8);
              param_1[0x119] = *(int *)(iVar2 + 0xc);
              param_1[0x11a] = *(int *)(iVar2 + 0x10);
              *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
            }
          }
        }
        else {
          iVar2 = *(int *)(param_1[0x116] + 0x8dc);
          if (iVar2 != 0) {
            (**(code **)(*(int *)(iVar2 + 0x454) + 0x120))(iVar2);
          }
          (*DAT_0019f794)(1,"stopped using TANK\n");
          *(byte *)(param_1[0x116] + 0x8b4) = *(byte *)(param_1[0x116] + 0x8b4) & 0xfe;
          *(undefined4 *)(*param_1 + 0x104) = 0;
          iVar2 = *param_1;
          param_1[0x116] = 0;
          if ((*(byte *)(iVar2 + 0x1a0) & 1) != 0) {
            *(float *)(iVar2 + 0x104) = *(float *)(iVar2 + 0x100) + 1.0;
          }
        }
      }
    }
  }
  return;
}


// Use__9CFuncWallP11CBaseEntityT18USE_TYPEf  @ 0008a014
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


// Use__9CPushableP11CBaseEntityT18USE_TYPEf  @ 000a94a4
void Use__9CPushableP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  if ((param_2 == (int *)0x0) || (iVar2 = *param_2, (*(byte *)(iVar2 + 0x1a4) & 8) == 0)) {
    if (*(char *)(*param_1 + 0x1a0) < '\0') {
      iVar2 = IsBreakable__10CBreakable(param_1);
      if (iVar2 != 0) {
        *(int *)(*param_1 + 0x54) = param_1[0x11b];
        UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
        g_vecAttackDir = *(undefined4 *)(gpGlobals + 0x28);
        DAT_0019f670 = *(undefined4 *)(gpGlobals + 0x2c);
        DAT_0019f674 = *(undefined4 *)(gpGlobals + 0x30);
        Die__10CBreakable(param_1);
      }
    }
  }
  else {
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x20))) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x20)) << 0xe) >> 8)) ==
         0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x24))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x24)) << 0xe) >> 8)) ==
        0x40)) {
      fVar1 = *(float *)(iVar2 + 0x28);
      bVar3 = (byte)(DAT_0019f668 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar3) {
      Move__9CPushableP11CBaseEntityi(param_1,param_2,0);
    }
  }
  return;
}


// Use__9CRechargeP11CBaseEntityT18USE_TYPEf  @ 000b29c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Use__9CRechargeP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  iVar4 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"player");
  if (iVar4 != 0) {
    return;
  }
  if (param_1[0x140] < 1) {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
    Off__9CRecharge(param_1);
    if (param_1[0x140] < 1) goto LAB_000b2a3e;
  }
  if (*(int *)(*param_2 + 0x168) < 0) {
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.25;
    param_1[3] = -0x10000;
    param_1[4] = (int)Off__9CRecharge;
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x13e];
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
      return;
    }
    if (param_2 == (int *)0x0) {
      return;
    }
    piVar7 = param_1 + 0x132;
    __as__7EHANDLEP11CBaseEntity(piVar7,param_2);
    piVar5 = (int *)__rf__7EHANDLE(piVar7);
    if ((*(byte *)(*piVar5 + 0x1a4) & 8) == 0) {
      return;
    }
    iVar4 = param_1[0x141];
    if (iVar4 == 0) {
      param_1[0x141] = 1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"items/suitchargeok1.wav",0x3f59999a,0x3f4ccccd
                 ,0,100);
      iVar4 = param_1[0x141];
      param_1[0x142] = (int)(*gpGlobals + 0.56);
    }
    if (iVar4 == 1) {
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x142];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        param_1[0x141] = 2;
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),6,"items/suitcharge1.wav",0x3f59999a,0x3f4ccccd
                   ,0,100);
      }
    }
    piVar5 = (int *)__rf__7EHANDLE(piVar7);
    iVar4 = *piVar5;
    iVar6 = __rf__7EHANDLE(piVar7);
    fVar1 = *(float *)(iVar6 + 0xf0);
    fVar2 = *(float *)(iVar4 + 0x1bc);
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      param_1[0x140] = param_1[0x140] + -1;
      piVar5 = (int *)__rf__7EHANDLE(piVar7);
      *(float *)(*piVar5 + 0x1bc) = *(float *)(*piVar5 + 0x1bc) + 1.0;
      piVar5 = (int *)__rf__7EHANDLE(piVar7);
      iVar4 = *piVar5;
      iVar6 = __rf__7EHANDLE(piVar7);
      if (*(float *)(iVar6 + 0xf0) < *(float *)(iVar4 + 0x1bc)) {
        piVar5 = (int *)__rf__7EHANDLE(piVar7);
        iVar4 = __rf__7EHANDLE(piVar7);
        *(undefined4 *)(*piVar5 + 0x1bc) = *(undefined4 *)(iVar4 + 0xf0);
      }
      piVar5 = (int *)__rf__7EHANDLE(piVar7);
      iVar4 = *piVar5;
      piVar5 = (int *)__rf__7EHANDLE(piVar7);
      if ((double)*(float *)(*piVar5 + 0x1b8) <= _FUN_0014c400) {
        uVar3 = 0x3f4ccccd;
      }
      else {
        piVar5 = (int *)__rf__7EHANDLE(piVar7);
        uVar3 = *(undefined4 *)(*piVar5 + 0x1b8);
      }
      *(undefined4 *)(iVar4 + 0x1b8) = uVar3;
    }
    param_1[0x13e] = (int)(*gpGlobals + 0.1);
    return;
  }
LAB_000b2a3e:
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x142];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    param_1[0x142] = (int)(fVar1 + 0.62);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/suitchargeno1.wav",0x3f59999a,0x3f4ccccd,0
               ,100);
  }
  return;
}


