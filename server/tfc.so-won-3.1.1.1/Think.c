// Think__10CXenPLight  @ 0012845c
void Think__10CXenPLight(int *param_1)

{
  int iVar1;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  switch(param_1[0x11d]) {
  case 0x11:
    if (param_1[0x11b] != 0) {
      iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x12);
      if (iVar1 != -1) {
        *(int *)(*param_1 + 0x128) = iVar1;
        param_1[0x11d] = 0x12;
        *(undefined4 *)(*param_1 + 0x130) = 0;
        ResetSequenceInfo__14CBaseAnimating(param_1);
      }
      LightOff__10CXenPLight(param_1);
    }
    break;
  case 0x12:
    if (*(float *)(*param_1 + 0x1e4) < *gpGlobals) {
      iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x13);
      if (iVar1 != -1) {
        *(int *)(*param_1 + 0x128) = iVar1;
        param_1[0x11d] = 0x13;
        *(undefined4 *)(*param_1 + 0x130) = 0;
        ResetSequenceInfo__14CBaseAnimating(param_1);
      }
      LightOn__10CXenPLight(param_1);
    }
    break;
  case 0x13:
    if ((param_1[0x11b] != 0) && (iVar1 = LookupActivity__14CBaseAnimatingi(param_1,1), iVar1 != -1)
       ) {
      *(int *)(*param_1 + 0x128) = iVar1;
      param_1[0x11d] = 1;
      *(undefined4 *)(*param_1 + 0x130) = 0;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
  }
  return;
}


// Think__11CBaseEntity  @ 00112cdc
void Think__11CBaseEntity(int param_1)

{
  code *pcVar1;
  
  if (*(short *)(param_1 + 0xe) != 0) {
    if (*(short *)(param_1 + 0xe) < 1) {
      pcVar1 = *(code **)(param_1 + 0x10);
    }
    else {
      pcVar1 = *(code **)(*(int *)(*(short *)(param_1 + 0x10) + param_1) + -4 +
                         *(short *)(param_1 + 0xe) * 4);
    }
    (*pcVar1)(*(short *)(param_1 + 0xc) + param_1);
  }
  return;
}


// Think__11CFireAndDie  @ 00118ab4
void Think__11CFireAndDie(undefined4 param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Think__12CAutoTrigger  @ 00119da4
void Think__12CAutoTrigger(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x118] != 0) &&
     (iVar1 = EntityGetState__12CGlobalStatei(&gGlobalState,param_1[0x118]), iVar1 != 1)) {
    return;
  }
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,param_1[0x119],0);
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Think__13CCyclerSprite  @ 000b41b8
void Think__13CCyclerSprite(int *param_1)

{
  float fVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1[0x116] != 0) {
    fVar1 = (float)param_1[0x118];
    bVar2 = (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1;
  }
  if (bVar2) {
    Animate__13CCyclerSpritef
              (param_1,(*gpGlobals - (float)param_1[0x117]) * *(float *)(*param_1 + 0x138));
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x117] = (int)*gpGlobals;
  return;
}


// Think__13CTeamFortress  @ 000fbd98
void Think__13CTeamFortress(int param_1)

{
  Update__13CVoiceGameMgrd(param_1 + 0x18,(double)*(float *)(gpGlobals + 4));
  Think__18CHalfLifeMultiplay(param_1);
  return;
}


// Think__14CFuncTankLaser  @ 000ac30c
void Think__14CFuncTankLaser(int *param_1)

{
  int iVar1;
  float fVar2;
  
  if ((param_1[0x135] != 0) && ((float)param_1[0x136] < *gpGlobals)) {
    TurnOff__6CLaser(param_1[0x135]);
  }
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
  TrackTarget__9CFuncTank(param_1);
  fVar2 = ABS(*(float *)(*param_1 + 0x5c));
  if (((byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) == 1) ||
     (fVar2 = ABS(*(float *)(*param_1 + 0x60)),
     0x3f < (byte)((fVar2 < 1.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) - 1))) {
    StartRotSound__9CFuncTank(param_1);
  }
  else {
    StopRotSound__9CFuncTank(param_1);
  }
  return;
}


// Think__14CHalfLifeRules  @ 000b0114
void Think__14CHalfLifeRules(void)

{
  return;
}


// Think__14CTargetCDAudio  @ 00114ab0
void Think__14CTargetCDAudio(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = (*DAT_0019f7c0)(1);
  if (iVar5 != 0) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
    iVar1 = *param_1;
    fVar2 = *(float *)(iVar5 + 0x88) - *(float *)(iVar1 + 8);
    fVar4 = *(float *)(iVar5 + 0x8c) - *(float *)(iVar1 + 0xc);
    fVar3 = *(float *)(iVar5 + 0x90) - *(float *)(iVar1 + 0x10);
    if (SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2) <= *(float *)(iVar1 + 0x144)) {
      Play__14CTargetCDAudio(param_1);
    }
  }
  return;
}


// Think__17CFuncTankControls  @ 000abb54
void Think__17CFuncTankControls(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar3 = (*DAT_0019f6d8)(iVar3,"targetname",
                            *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar3 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar3), iVar2 == 0)) {
      bVar1 = true;
    }
  } while ((!bVar1) &&
          (iVar2 = strncmp((char *)(*(int *)(iVar3 + 0x80) + *(int *)(gpGlobals + 0x98)),"func_tank"
                           ,9), iVar2 != 0));
  bVar1 = false;
  if ((iVar3 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar3), iVar2 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
    param_1[0x116] = iVar3;
    return;
  }
  (*DAT_0019f794)(1,"No tank %s\n",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Think__17CInfoIntermission  @ 000dda24
void Think__17CInfoIntermission(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = (*DAT_0019f6d8)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  bVar2 = false;
  if (iVar3 != 0) {
    iVar4 = (*DAT_0019f7b8)(iVar3);
    if (iVar4 != 0) goto LAB_000dda8f;
  }
  bVar2 = true;
LAB_000dda8f:
  if (!bVar2) {
    iVar4 = *param_1;
    local_1c = *(float *)(iVar3 + 0x88) - *(float *)(iVar4 + 8);
    local_18 = *(float *)(iVar3 + 0x8c) - *(float *)(iVar4 + 0xc);
    fVar1 = *(float *)(iVar3 + 0x90) - *(float *)(iVar4 + 0x10);
    local_14 = SQRT(fVar1 * fVar1 + local_18 * local_18 + local_1c * local_1c);
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 1.0;
    }
    else {
      local_14 = 1.0 / local_14;
      local_1c = local_1c * local_14;
      local_18 = local_18 * local_14;
      local_14 = local_14 * fVar1;
    }
    UTIL_VecToAngles__FRC6Vector(&local_10,&local_1c);
    *(undefined4 *)(iVar4 + 0x74) = local_10;
    *(undefined4 *)(iVar4 + 0x78) = local_c;
    *(undefined4 *)(iVar4 + 0x7c) = local_8;
    *(float *)(*param_1 + 0x74) = -*(float *)(*param_1 + 0x74);
  }
  return;
}


// Think__18CHalfLifeMultiplay  @ 000ad910
void Think__18CHalfLifeMultiplay(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  int local_14;
  
  uVar3 = fraglimit._12_4_;
  local_14 = 0;
  iVar6 = 0;
  if (g_fGameOver == 0) {
    fVar1 = (float)timelimit._12_4_ * 60.0;
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      local_14 = (int)ROUND(fVar1 - *gpGlobals);
    }
    if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
       (*gpGlobals < fVar1)) {
      if ((byte)(0.0 < (float)fraglimit._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)fraglimit._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)fraglimit._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
        iVar6 = 9999;
        iVar5 = 1;
        if (0 < (int)gpGlobals[0x24]) {
          do {
            iVar4 = (*DAT_0019f7c0)(iVar5);
            if (iVar4 != 0) {
              if ((float)uVar3 <= *(float *)(iVar4 + 0x1e4)) goto LAB_000ada95;
              iVar4 = (int)ROUND((float)uVar3 - *(float *)(iVar4 + 0x1e4));
              if (iVar4 < iVar6) {
                iVar6 = iVar4;
              }
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 <= (int)gpGlobals[0x24]);
        }
      }
      if (iVar6 != last_frags_738) {
        uVar3 = UTIL_VarArgs__FPce(&DAT_0014bd51,iVar6);
        (*DAT_0019f8c4)(fragsleft,uVar3);
      }
      fVar1 = (float)last_time_739;
      if ((byte)((float)timeleft._12_4_ < fVar1 |
                 (byte)((ushort)((ushort)(NAN((float)timeleft._12_4_) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)timeleft._12_4_ == fVar1) << 0xe) >> 8)) != 0x40) {
        uVar3 = UTIL_VarArgs__FPce(&DAT_0014bd51,local_14);
        (*DAT_0019f8c4)(timeleft,uVar3);
      }
      last_time_739 = local_14;
      last_frags_738 = iVar6;
    }
    else {
LAB_000ada95:
      (**(code **)(*param_1 + 0xe0))(param_1);
    }
  }
  else {
    lVar7 = (longdouble)(*DAT_0019f784)("mp_chattime");
    if ((int)ROUND(lVar7) < 1) {
      (*DAT_0019f790)("mp_chattime",&DAT_0014bd4f);
    }
    else if (0x78 < (int)ROUND(lVar7)) {
      uVar3 = UTIL_dtos1__Fi(0x78);
      (*DAT_0019f790)("mp_chattime",uVar3);
    }
    fVar2 = (float)param_1[2] + (float)mp_chattime._12_4_;
    param_1[1] = (int)fVar2;
    fVar1 = *gpGlobals;
    if ((0x3f < (byte)((fVar1 < fVar2 |
                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) &&
       ((param_1[3] != 0 ||
        (fVar2 = (float)param_1[2] + 120.0,
        0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))))) {
      (**(code **)(*param_1 + 0xe4))(param_1);
    }
  }
  return;
}


// Think__19CTriggerMonsterJump  @ 00119548
void Think__19CTriggerMonsterJump(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


// Think__23CDispenserRefillThinker  @ 0009bce4
void Think__23CDispenserRefillThinker(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x118);
  iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x116);
  bVar4 = false;
  if ((piVar5 == (int *)0x0) || (iVar6 == 0)) {
    bVar4 = true;
  }
  else {
    fVar2 = *gpGlobals + 1.5;
    fVar1 = *(float *)(iVar6 + 0x6a0);
    if ((((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) ||
        (fVar1 = *(float *)(*piVar5 + 8) - (float)param_1[0x11a],
        fVar3 = *(float *)(*piVar5 + 0xc) - (float)param_1[0x11b],
        fVar2 = *(float *)(*piVar5 + 0x10) - (float)param_1[0x11c],
        fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1),
        (byte)(24.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 24.0) << 0xe) >> 8)) == 1)) ||
       (iVar6 = RefillPlayer__12CTFDispenserP11CBasePlayer(iVar6,piVar5), iVar6 == 0))
    goto LAB_0009bdbe;
  }
  if (!bVar4) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
    return;
  }
LAB_0009bdbe:
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Think__5CGlow  @ 000a49b4
void Think__5CGlow(int *param_1)

{
  Animate__5CGlowf(param_1,(*gpGlobals - (float)param_1[0x116]) * *(float *)(*param_1 + 0x138));
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x116] = (int)*gpGlobals;
  return;
}


// Think__7CCycler  @ 000b45b8
void Think__7CCycler(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (param_1[0x1a7] != 0) {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  }
  if ((param_1[0x11b] != 0) && (param_1[0x11c] == 0)) {
    *(float *)(*param_1 + 0x134) = *gpGlobals;
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
    param_1[0x11b] = 0;
    param_1[0x11a] = (int)*gpGlobals;
    *(undefined4 *)(*param_1 + 0x130) = 0;
    if (param_1[0x1a7] == 0) {
      *(undefined4 *)(*param_1 + 0x138) = 0;
    }
  }
  return;
}


// Think__7CShower  @ 000a7868
void Think__7CShower(int *param_1)

{
  UTIL_Sparks__FRC6Vector(*param_1 + 8);
  *(float *)(*param_1 + 0x1f8) = *(float *)(*param_1 + 0x1f8) - 0.1;
  if (*(float *)(*param_1 + 0x1f8) <= 0.0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  return;
}


// Think__8CXenHair  @ 0012996c
void Think__8CXenHair(int *param_1)

{
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  return;
}


// Think__8CXenTree  @ 001293f4
void Think__8CXenTree(int *param_1)

{
  int iVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  DispatchAnimEvents__14CBaseAnimatingf(param_1,(float)lVar2);
  if (((param_1[0x11d] != 1) && (param_1[0x11d] == 0x1e)) && (param_1[0x11b] != 0)) {
    iVar1 = LookupActivity__14CBaseAnimatingi(param_1,1);
    if (iVar1 != -1) {
      *(int *)(*param_1 + 0x128) = iVar1;
      param_1[0x11d] = 1;
      *(undefined4 *)(*param_1 + 0x130) = 0;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
    lVar2 = (longdouble)(*DAT_0019f80c)(0x3f19999a,0x3fb33333);
    *(float *)(*param_1 + 0x138) = (float)lVar2;
  }
  return;
}


// Think__9CEnvSound  @ 000f04bc
void Think__9CEnvSound(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 in_FPUControlWord;
  short local_24;
  float local_18 [2];
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  iVar3 = (*DAT_0019f6e4)(*(undefined4 *)(*param_1 + 0x208));
  bVar2 = false;
  if ((iVar3 == 0) || (iVar4 = (*DAT_0019f7b8)(iVar3), iVar4 == 0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    iVar4 = iVar3 + 0x80;
    iVar6 = iVar4;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    iVar6 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(iVar6);
    bVar2 = false;
    if ((*(int *)(iVar6 + 0x6e0) == 0) ||
       (iVar5 = (*DAT_0019f7b8)(*(int *)(iVar6 + 0x6e0)), iVar5 == 0)) {
      bVar2 = true;
    }
    if ((bVar2) || (*(int *)(iVar6 + 0x6e0) != *(int *)(*param_1 + 0x208))) {
      if (iVar3 == 0) {
        iVar4 = 0;
      }
      iVar4 = FEnvSoundInRange__FP9entvars_sT0Pf(*param_1,iVar4,local_18);
      if ((iVar4 != 0) &&
         ((fVar1 = *(float *)(iVar6 + 0x6e8), local_18[0] < fVar1 ||
          ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)))) {
        *(undefined4 *)(iVar6 + 0x6e0) = *(undefined4 *)(*param_1 + 0x208);
        *(int *)(iVar6 + 0x6e4) = param_1[0x117];
        *(float *)(iVar6 + 0x6e8) = local_18[0];
        (*DAT_0019f758)(1,0x25,0,iVar3);
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_24 = (short)(int)ROUND((float)param_1[0x117]);
        (*DAT_0019f768)((int)local_24);
        (*DAT_0019f75c)();
      }
LAB_000f06b9:
      iVar3 = *param_1;
      fVar1 = 0.75;
      goto LAB_000f06e3;
    }
    fVar1 = *(float *)(iVar6 + 0x6e4);
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
       (fVar1 = *(float *)(iVar6 + 0x6e8),
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      if (iVar3 == 0) {
        iVar4 = 0;
      }
      iVar3 = FEnvSoundInRange__FP9entvars_sT0Pf(*param_1,iVar4,local_18);
      if (iVar3 != 0) {
        *(float *)(iVar6 + 0x6e8) = local_18[0];
        goto LAB_000f06b9;
      }
      *(undefined4 *)(iVar6 + 0x6e8) = 0;
      *(undefined4 *)(iVar6 + 0x6e4) = 0;
    }
  }
  iVar3 = *param_1;
  fVar1 = 1.25;
LAB_000f06e3:
  *(float *)(iVar3 + 0x104) = fVar1 + *gpGlobals;
  return;
}


// Think__9CFuncTank  @ 000ac7fc
void Think__9CFuncTank(int *param_1)

{
  int iVar1;
  float fVar2;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
  TrackTarget__9CFuncTank(param_1);
  fVar2 = ABS(*(float *)(*param_1 + 0x5c));
  if (((byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) == 1) ||
     (fVar2 = ABS(*(float *)(*param_1 + 0x60)),
     0x3f < (byte)((fVar2 < 1.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) - 1))) {
    StartRotSound__9CFuncTank(param_1);
  }
  else {
    StopRotSound__9CFuncTank(param_1);
  }
  return;
}


// Think__9CSoundEnt  @ 000f2b2c
void Think__9CSoundEnt(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_c;
  
  local_c = -1;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  iVar3 = param_1[0x117];
  while (iVar2 = iVar3, iVar2 != -1) {
    fVar1 = (float)param_1[iVar2 * 8 + 0x11f];
    if ((*gpGlobals < fVar1) ||
       ((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40)) {
      iVar3 = param_1[iVar2 * 8 + 0x120];
      local_c = iVar2;
    }
    else {
      iVar3 = param_1[iVar2 * 8 + 0x120];
      FreeSound__9CSoundEntii(iVar2,local_c);
    }
  }
  if (param_1[0x119] != 0) {
    iVar3 = ISoundsInList__9CSoundEnti(param_1,2);
    uVar4 = ISoundsInList__9CSoundEnti(param_1,1,iVar3 - param_1[0x118]);
    uVar4 = ISoundsInList__9CSoundEnti(param_1,2,uVar4);
    (*DAT_0019f794)(2,"Soundlist: %d / %d  (%d)\n",uVar4);
    iVar3 = ISoundsInList__9CSoundEnti(param_1,2);
    param_1[0x118] = iVar3;
  }
  return;
}


// Think__9CSprayCan  @ 000da85c
void Think__9CSprayCan(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 **ppuVar5;
  undefined1 *puStack_84;
  undefined1 *local_80;
  int local_6c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [56];
  
  ppuVar5 = (undefined1 **)&stack0xffffff84;
  iVar4 = *param_1;
  local_80 = (undefined1 *)0x0;
  if (*(int *)(iVar4 + 0x198) != 0) {
    local_80 = *(undefined1 **)(*(int *)(iVar4 + 0x198) + 0x7c);
  }
  if (local_80 == (undefined1 *)0x0) {
    local_6c = -1;
  }
  else {
    puStack_84 = (undefined1 *)0xda88f;
    local_6c = GetCustomDecalFrames__11CBasePlayer();
    iVar4 = *param_1;
  }
  local_80 = *(undefined1 **)(iVar4 + 0x198);
  puStack_84 = (undefined1 *)0xda8b8;
  uVar3 = (*DAT_0019f7bc)();
  local_80 = (undefined1 *)(*param_1 + 0x50);
  puStack_84 = (undefined1 *)0xda8c9;
  UTIL_MakeVectors__FRC6Vector();
  iVar4 = *param_1;
  local_48 = gpGlobals[10] * 128.0 + *(float *)(iVar4 + 8);
  local_44 = gpGlobals[0xb] * 128.0 + *(float *)(iVar4 + 0xc);
  local_40 = gpGlobals[0xc] * 128.0 + *(float *)(iVar4 + 0x10);
  puStack_84 = *(undefined1 **)(iVar4 + 0x198);
  local_80 = local_3c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(iVar4 + 8,&local_48,1);
  if (local_6c == -1) {
    local_80 = (undefined1 *)0xa;
    ppuVar5 = &puStack_84;
    puStack_84 = local_3c;
    UTIL_DecalTrace__FP11TraceResulti();
  }
  else {
    local_80 = (undefined1 *)0x1;
    puStack_84 = (undefined1 *)(int)ROUND(*(float *)(*param_1 + 0x130));
    UTIL_PlayerDecalTrace__FP11TraceResultiii(local_3c,uVar3);
    fVar1 = *(float *)(*param_1 + 0x130);
    local_80 = (undefined1 *)(local_6c + -1);
    *(float *)(*param_1 + 0x130) = fVar1 + 1.0;
    fVar2 = (float)(int)local_80;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) goto LAB_000da9a8;
  }
  *(int **)((int)ppuVar5 + -4) = param_1;
  *(undefined4 *)((int)ppuVar5 + -8) = 0xda9a8;
  UTIL_Remove__FP11CBaseEntity();
LAB_000da9a8:
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


// Think__9CWreckage  @ 000b3a0c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Think__9CWreckage(int *param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float local_8;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_8 = (float)_FUN_0014c700 + *gpGlobals;
  *(float *)(*param_1 + 0x104) = local_8;
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x1e4);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if (fVar1 < *gpGlobals) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
    lVar3 = (longdouble)(*DAT_0019f80c)(0,fVar1 - (float)param_1[0x1a7]);
    iVar2 = *param_1;
    lVar4 = (longdouble)*(float *)(iVar2 + 0x1e4) - (longdouble)*gpGlobals;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 1) {
      return;
    }
  }
  lVar3 = (longdouble)(*DAT_0019f80c)(*(undefined4 *)(iVar2 + 0xc4),*(undefined4 *)(iVar2 + 0xd0));
  fStack_14 = (float)lVar3;
  lVar3 = (longdouble)
          (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 200),*(undefined4 *)(*param_1 + 0xd4));
  fStack_10 = (float)lVar3;
  lVar3 = (longdouble)
          (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 0xcc),*(undefined4 *)(*param_1 + 0xd8));
  fStack_c = (float)lVar3;
  (*DAT_0019f758)(4,0x17,&fStack_14,0);
  (*DAT_0019f760)(5);
  (*DAT_0019f774)(fStack_14);
  (*DAT_0019f774)(fStack_10);
  (*DAT_0019f774)(fStack_c);
  (*DAT_0019f768)((int)g_sModelIndexSmoke);
  iVar2 = (*DAT_0019f808)(0,0x31);
  (*DAT_0019f760)(iVar2 + 0x32);
  iVar2 = (*DAT_0019f808)(0,3);
  (*DAT_0019f760)(iVar2 + 8);
  (*DAT_0019f75c)();
  return;
}


// Think__9CXenSpore  @ 00128e28
void Think__9CXenSpore(int *param_1)

{
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


