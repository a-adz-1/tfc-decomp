// Think__10CXenPLight  @ 001146f4
void Think__10CXenPLight(int *param_1)

{
  float fVar1;
  float fVar2;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  switch(param_1[0xfd]) {
  case 0x11:
    if (param_1[0xfb] != 0) {
      SetActivity__13CActAnimating8Activity(param_1,0x12);
      LightOff__10CXenPLight(param_1);
    }
    break;
  case 0x12:
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(*param_1 + 0x1e4);
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      SetActivity__13CActAnimating8Activity(param_1,0x13);
      LightOn__10CXenPLight(param_1);
    }
    break;
  case 0x13:
    if (param_1[0xfb] != 0) {
      SetActivity__13CActAnimating8Activity(param_1,1);
    }
  }
  return;
}


// Think__11CBaseEntity  @ 0010050c
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


// Think__11CFireAndDie  @ 00103544
void Think__11CFireAndDie(undefined4 param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Think__12CAutoTrigger  @ 001019ac
void Think__12CAutoTrigger(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xf8] != 0) &&
     (iVar1 = EntityGetState__12CGlobalStatei(&gGlobalState,param_1[0xf8]), iVar1 != 1)) {
    return;
  }
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,param_1[0xf9],0);
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Think__13CCyclerSprite  @ 000a9bb4
void Think__13CCyclerSprite(int *param_1)

{
  float fVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1[0xf6] != 0) {
    fVar1 = (float)param_1[0xf8];
    bVar2 = (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1;
  }
  if (bVar2) {
    Animate__13CCyclerSpritef
              (param_1,(*gpGlobals - (float)param_1[0xf7]) * *(float *)(*param_1 + 0x138));
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0xf7] = (int)*gpGlobals;
  return;
}


// Think__14CFuncTankLaser  @ 000a1f54
void Think__14CFuncTankLaser(int param_1)

{
  float fVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0x454) != 0) {
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(param_1 + 0x458);
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      TurnOff__6CLaser(*(undefined4 *)(param_1 + 0x454));
    }
  }
  Think__9CFuncTank(param_1);
  return;
}


// Think__14CHalfLifeRules  @ 000a388c
void Think__14CHalfLifeRules(void)

{
  return;
}


// Think__14CTargetCDAudio  @ 0010284c
void Think__14CTargetCDAudio(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = (*DAT_001a7f60)(1);
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


// Think__17CFuncTankControls  @ 000a27f0
void Think__17CFuncTankControls(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar3 = (*DAT_001a7e78)(iVar3,"targetname",
                            *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar3 == 0) || (iVar2 = (*DAT_001a7f58)(iVar3), iVar2 == 0)) {
      bVar1 = true;
    }
  } while ((!bVar1) &&
          (iVar2 = strncmp((char *)(*(int *)(iVar3 + 0x80) + *(int *)(gpGlobals + 0x98)),"func_tank"
                           ,9), iVar2 != 0));
  bVar1 = false;
  if ((iVar3 == 0) || (iVar2 = (*DAT_001a7f58)(iVar3), iVar2 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
    param_1[0xf6] = iVar3;
    return;
  }
  (*DAT_001a7f34)(1,"No tank %s\n",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Think__17CInfoIntermission  @ 000d3fec
void Think__17CInfoIntermission(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = (*DAT_001a7e78)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  bVar2 = false;
  if (iVar3 != 0) {
    iVar4 = (*DAT_001a7f58)(iVar3);
    if (iVar4 != 0) goto LAB_000d4055;
  }
  bVar2 = true;
LAB_000d4055:
  if (!bVar2) {
    iVar4 = *param_1;
    local_18 = *(float *)(iVar3 + 0x88) - *(float *)(iVar4 + 8);
    local_14 = *(float *)(iVar3 + 0x8c) - *(float *)(iVar4 + 0xc);
    fVar1 = *(float *)(iVar3 + 0x90) - *(float *)(iVar4 + 0x10);
    local_10 = SQRT(fVar1 * fVar1 + local_14 * local_14 + local_18 * local_18);
    if ((byte)((byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_18 = 0.0;
      local_14 = 0.0;
      local_10 = 1.0;
    }
    else {
      local_10 = 1.0 / local_10;
      local_18 = local_10 * local_18;
      local_14 = local_10 * local_14;
      local_10 = local_10 * fVar1;
    }
    UTIL_VecToAngles__FRC6Vector(&local_c,&local_18);
    *(float *)(iVar4 + 0x74) = local_10;
    *(undefined4 *)(iVar4 + 0x78) = local_c;
    *(undefined4 *)(iVar4 + 0x7c) = local_8;
    *(float *)(*param_1 + 0x74) = -*(float *)(*param_1 + 0x74);
  }
  return;
}


// Think__18CHalfLifeMultiplay  @ 000a3bcc
void Think__18CHalfLifeMultiplay(int *param_1)

{
  float fVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_10;
  
  uVar4 = fraglimit._12_4_;
  iVar6 = 0;
  if (g_fGameOver == 0) {
    fVar1 = (float)timelimit._12_4_ * 60.0;
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_10 = 0;
    }
    else {
      local_10 = (int)ROUND(fVar1 - *gpGlobals);
    }
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
       (*gpGlobals < fVar1)) {
      if ((byte)((float)fraglimit._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)fraglimit._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)fraglimit._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
        iVar6 = 9999;
        for (iVar5 = 1; iVar5 <= (int)gpGlobals[0x24]; iVar5 = iVar5 + 1) {
          iVar3 = (*DAT_001a7f60)(iVar5);
          if (iVar3 != 0) {
            fVar1 = *(float *)(iVar3 + 0x1e4);
            if ((byte)(((float)uVar4 < fVar1 |
                        (byte)((ushort)((ushort)(NAN((float)uVar4) || NAN(fVar1)) << 10) >> 8) |
                       (byte)((ushort)((ushort)((float)uVar4 == fVar1) << 0xe) >> 8)) - 1) < 0x40)
            goto LAB_000a3cbb;
            iVar3 = (int)ROUND((float)uVar4 - *(float *)(iVar3 + 0x1e4));
            if (iVar3 < iVar6) {
              iVar6 = iVar3;
            }
          }
        }
      }
      if (iVar6 != last_frags_734) {
        uVar4 = UTIL_VarArgs__FPce(&DAT_00135f23,iVar6);
        (*DAT_001a8064)(fragsleft,uVar4);
      }
      fVar1 = (float)last_time_735;
      if ((byte)((float)timeleft._12_4_ < fVar1 |
                 (byte)((ushort)((ushort)(NAN((float)timeleft._12_4_) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)timeleft._12_4_ == fVar1) << 0xe) >> 8)) != 0x40) {
        uVar4 = UTIL_VarArgs__FPce(&DAT_00135f23,local_10);
        (*DAT_001a8064)(timeleft,uVar4);
      }
      last_frags_734 = iVar6;
      last_time_735 = local_10;
      return;
    }
LAB_000a3cbb:
    pcVar2 = *(code **)(*param_1 + 0xe0);
  }
  else {
    if (*gpGlobals <= (float)param_1[1]) {
      return;
    }
    if ((param_1[2] == 0) && (*gpGlobals <= (float)param_1[1] + 120.0)) {
      return;
    }
    pcVar2 = *(code **)(*param_1 + 0xe4);
  }
  (*pcVar2)(param_1);
  return;
}


// Think__19CTriggerMonsterJump  @ 001024e4
void Think__19CTriggerMonsterJump(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


// Think__23CDispenserRefillThinker  @ 000922a8
void Think__23CDispenserRefillThinker(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0xf8);
  iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0xf6);
  bVar4 = false;
  if ((piVar5 == (int *)0x0) || (iVar6 == 0)) {
    bVar4 = true;
  }
  else {
    fVar2 = *gpGlobals + 1.5;
    fVar1 = *(float *)(iVar6 + 0x620);
    if ((((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) ||
        (fVar1 = *(float *)(*piVar5 + 8) - (float)param_1[0xfa],
        fVar3 = *(float *)(*piVar5 + 0xc) - (float)param_1[0xfb],
        fVar2 = *(float *)(*piVar5 + 0x10) - (float)param_1[0xfc],
        fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1),
        (byte)(24.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 24.0) << 0xe) >> 8)) == 1)) ||
       (iVar6 = RefillPlayer__12CTFDispenserP11CBasePlayer(iVar6,piVar5), iVar6 == 0))
    goto LAB_0009238c;
  }
  if (!bVar4) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
    return;
  }
LAB_0009238c:
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Think__5CGlow  @ 00098a58
void Think__5CGlow(int *param_1)

{
  Animate__5CGlowf(param_1,(*gpGlobals - (float)param_1[0xf6]) * *(float *)(*param_1 + 0x138));
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0xf6] = (int)*gpGlobals;
  return;
}


// Think__7CCycler  @ 000a983c
void Think__7CCycler(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (param_1[0x187] != 0) {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  }
  if ((param_1[0xfb] != 0) && (param_1[0xfc] == 0)) {
    *(float *)(*param_1 + 0x134) = *gpGlobals;
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
    param_1[0xfb] = 0;
    param_1[0xfa] = (int)*gpGlobals;
    *(undefined4 *)(*param_1 + 0x130) = 0;
    if (param_1[0x187] == 0) {
      *(undefined4 *)(*param_1 + 0x138) = 0;
    }
  }
  return;
}


// Think__7CShower  @ 0009caac
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


// Think__8CXenHair  @ 00114a28
void Think__8CXenHair(int *param_1)

{
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  return;
}


// Think__8CXenTree  @ 00115358
void Think__8CXenTree(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  DispatchAnimEvents__14CBaseAnimatingf(param_1,(float)lVar1);
  if (((param_1[0xfd] != 1) && (param_1[0xfd] == 0x1e)) && (param_1[0xfb] != 0)) {
    SetActivity__13CActAnimating8Activity(param_1,1);
    lVar1 = (longdouble)(*DAT_001a7fac)(0x3f19999a,0x3fb33333);
    *(float *)(*param_1 + 0x138) = (float)lVar1;
  }
  return;
}


// Think__9CEnvSound  @ 000e1fec
void Think__9CEnvSound(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  short local_18;
  float local_14 [2];
  undefined4 local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  iVar3 = (*DAT_001a7e84)(*(undefined4 *)(*param_1 + 0x208));
  bVar2 = false;
  if ((iVar3 == 0) || (iVar4 = (*DAT_001a7f58)(iVar3), iVar4 == 0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    iVar4 = iVar3 + 0x80;
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    iVar4 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(iVar4);
    bVar2 = false;
    if ((*(int *)(iVar4 + 0x64c) == 0) ||
       (iVar5 = (*DAT_001a7f58)(*(int *)(iVar4 + 0x64c)), iVar5 == 0)) {
      bVar2 = true;
    }
    if ((bVar2) || (*(int *)(iVar4 + 0x64c) != *(int *)(*param_1 + 0x208))) {
      iVar5 = iVar3 + 0x80;
      if (iVar3 == 0) {
        iVar5 = 0;
      }
      iVar5 = FEnvSoundInRange__FP9entvars_sT0Pf(*param_1,iVar5,local_14);
      if ((iVar5 != 0) &&
         ((fVar1 = *(float *)(iVar4 + 0x654),
          (byte)(local_14[0] < fVar1 |
                 (byte)((ushort)((ushort)(NAN(local_14[0]) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_14[0] == fVar1) << 0xe) >> 8)) == 1 ||
          ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar4 + 0x654)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x654) == 0.0) << 0xe) >> 8)) == 0x40))
         )) {
        *(undefined4 *)(iVar4 + 0x64c) = *(undefined4 *)(*param_1 + 0x208);
        *(int *)(iVar4 + 0x650) = param_1[0xf7];
        *(float *)(iVar4 + 0x654) = local_14[0];
        (*DAT_001a7ef8)(1,0x25,0,iVar3);
        _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
        local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
        local_18 = (short)(int)ROUND((float)param_1[0xf7]);
        (*DAT_001a7f08)((int)local_18);
        (*DAT_001a7efc)();
      }
LAB_000e2240:
      iVar3 = *param_1;
      fVar1 = *gpGlobals + 0.75;
      goto LAB_000e2272;
    }
    fVar1 = *(float *)(iVar4 + 0x650);
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
       (fVar1 = *(float *)(iVar4 + 0x654),
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      iVar5 = iVar3 + 0x80;
      if (iVar3 == 0) {
        iVar5 = 0;
      }
      iVar3 = FEnvSoundInRange__FP9entvars_sT0Pf(*param_1,iVar5,local_14);
      if (iVar3 != 0) {
        *(float *)(iVar4 + 0x654) = local_14[0];
        goto LAB_000e2240;
      }
      *(undefined4 *)(iVar4 + 0x654) = 0;
      *(undefined4 *)(iVar4 + 0x650) = 0;
    }
  }
  iVar3 = *param_1;
  fVar1 = *gpGlobals + 1.25;
LAB_000e2272:
  *(float *)(iVar3 + 0x104) = fVar1;
  return;
}


// Think__9CFuncTank  @ 000a0800
void Think__9CFuncTank(int *param_1)

{
  int iVar1;
  float fVar2;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
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


// Think__9CSoundEnt  @ 000e3f18
void Think__9CSoundEnt(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  iVar4 = -1;
  iVar3 = param_1[0xf7];
  while (iVar3 != -1) {
    fVar1 = (float)param_1[iVar3 * 8 + 0xff];
    if ((*gpGlobals < fVar1) ||
       ((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40)) {
      iVar4 = iVar3;
      iVar3 = param_1[iVar3 * 8 + 0x100];
    }
    else {
      iVar2 = param_1[iVar3 * 8 + 0x100];
      FreeSound__9CSoundEntii(iVar3,iVar4);
      iVar3 = iVar2;
    }
  }
  if (param_1[0xf9] != 0) {
    iVar4 = ISoundsInList__9CSoundEnti(param_1,2);
    uVar5 = ISoundsInList__9CSoundEnti(param_1,1,iVar4 - param_1[0xf8]);
    uVar5 = ISoundsInList__9CSoundEnti(param_1,2,uVar5);
    (*DAT_001a7f34)(2,"Soundlist: %d / %d  (%d)\n",uVar5);
    iVar4 = ISoundsInList__9CSoundEnti(param_1,2);
    param_1[0xf8] = iVar4;
  }
  return;
}


// Think__9CSprayCan  @ 000cfe08
void Think__9CSprayCan(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [56];
  
  iVar5 = 0;
  if (*(int *)(*param_1 + 0x198) != 0) {
    iVar5 = *(int *)(*(int *)(*param_1 + 0x198) + 0x7c);
  }
  if (iVar5 == 0) {
    iVar5 = -1;
  }
  else {
    iVar5 = GetCustomDecalFrames__11CBasePlayer(iVar5);
  }
  uVar4 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x198));
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  iVar2 = *param_1;
  local_44 = *(float *)(iVar2 + 8) + gpGlobals[10] * 128.0;
  local_40 = *(float *)(iVar2 + 0xc) + gpGlobals[0xb] * 128.0;
  local_3c = *(float *)(iVar2 + 0x10) + gpGlobals[0xc] * 128.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (iVar2 + 8,&local_44,1,*(undefined4 *)(iVar2 + 0x198),local_38);
  if (iVar5 == -1) {
    UTIL_DecalTrace__FP11TraceResulti(local_38,10);
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    UTIL_PlayerDecalTrace__FP11TraceResultiii
              (local_38,uVar4,(int)ROUND(*(float *)(*param_1 + 0x130)),1);
    fVar1 = *(float *)(*param_1 + 0x130);
    *(float *)(*param_1 + 0x130) = fVar1 + 1.0;
    fVar3 = (float)(iVar5 + -1);
    if ((byte)(fVar1 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar3) << 0xe) >> 8)) != 1) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


// Think__9CWreckage  @ 000aa1f4
void Think__9CWreckage(int *param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_4 = *gpGlobals + 0.2;
  *(float *)(*param_1 + 0x104) = local_4;
  fVar1 = *(float *)(*param_1 + 0x1e4);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if (fVar1 < *gpGlobals) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
    lVar3 = (longdouble)(*DAT_001a7fac)(0,*(float *)(*param_1 + 0x1e4) - (float)param_1[0x187]);
    lVar4 = (longdouble)*(float *)(*param_1 + 0x1e4) - (longdouble)*gpGlobals;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 1) {
      return;
    }
  }
  lVar3 = (longdouble)
          (*DAT_001a7fac)(*(undefined4 *)(*param_1 + 0xc4),*(undefined4 *)(*param_1 + 0xd0));
  local_10 = (float)lVar3;
  lVar3 = (longdouble)
          (*DAT_001a7fac)(*(undefined4 *)(*param_1 + 200),*(undefined4 *)(*param_1 + 0xd4));
  local_c = (float)lVar3;
  lVar3 = (longdouble)
          (*DAT_001a7fac)(*(undefined4 *)(*param_1 + 0xcc),*(undefined4 *)(*param_1 + 0xd8));
  local_8 = (float)lVar3;
  (*DAT_001a7ef8)(4,0x17,&local_10,0);
  (*DAT_001a7f00)(5);
  (*DAT_001a7f14)(local_10);
  (*DAT_001a7f14)(local_c);
  (*DAT_001a7f14)(local_8);
  (*DAT_001a7f08)((int)g_sModelIndexSmoke);
  iVar2 = (*DAT_001a7fa8)(0,0x31);
  (*DAT_001a7f00)(iVar2 + 0x32);
  iVar2 = (*DAT_001a7fa8)(0,3);
  (*DAT_001a7f00)(iVar2 + 8);
  (*DAT_001a7efc)();
  return;
}


// Think__9CXenSpore  @ 00115aa4
void Think__9CXenSpore(int *param_1)

{
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


