// Think__10CXenPLight  @ 0011e4e0
void Think__10CXenPLight(int *param_1)

{
  int iVar1;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  iVar1 = param_1[0xfa];
  if (iVar1 == 0x11) {
    if (param_1[0xf8] != 0) {
      SetActivity__13CActAnimating8Activity(param_1,0x12);
      LightOff__10CXenPLight(param_1);
    }
  }
  else if (0x11 < iVar1) {
    if (iVar1 == 0x12) {
      if (*(float *)(*param_1 + 0x1c4) < *gpGlobals) {
        SetActivity__13CActAnimating8Activity(param_1,0x13);
        LightOn__10CXenPLight(param_1);
      }
    }
    else if ((iVar1 == 0x13) && (param_1[0xf8] != 0)) {
      SetActivity__13CActAnimating8Activity(param_1,1);
    }
  }
  return;
}


// Think__11CBaseEntity  @ 0010e280
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


// Think__11CFireAndDie  @ 00110e90
void Think__11CFireAndDie(undefined4 param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Think__12CAutoTrigger  @ 0010f5b0
void Think__12CAutoTrigger(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xf5] != 0) &&
     (iVar1 = EntityGetState__12CGlobalStatei(&gGlobalState,param_1[0xf5]), iVar1 != 1)) {
    return;
  }
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,param_1[0xf6],0);
  if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Think__13CCyclerSprite  @ 000bbc30
void Think__13CCyclerSprite(int *param_1)

{
  float fVar1;
  bool bVar2;
  float *pfVar3;
  
  bVar2 = false;
  if ((param_1[0xf3] != 0) &&
     (fVar1 = (float)param_1[0xf5],
     (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1)) {
    bVar2 = true;
  }
  if (bVar2) {
    Animate__13CCyclerSpritef
              (param_1,(*gpGlobals - (float)param_1[0xf4]) * *(float *)(*param_1 + 0x118));
  }
  pfVar3 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[0xf4] = (int)*pfVar3;
  return;
}


// Think__14CFuncTankLaser  @ 000b5dd0
void Think__14CFuncTankLaser(int param_1)

{
  if (*(int *)(param_1 + 0x448) != 0) {
    if (*(float *)(param_1 + 0x44c) < *gpGlobals) {
      TurnOff__6CLaser(*(undefined4 *)(param_1 + 0x448));
    }
  }
  Think__9CFuncTank(param_1);
  return;
}


// Think__14CHalfLifeRules  @ 000b6f00
void Think__14CHalfLifeRules(void)

{
  return;
}


// Think__14CTargetCDAudio  @ 001102b0
void Think__14CTargetCDAudio(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = (*DAT_001755e0)(1);
  if (iVar5 != 0) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.5;
    iVar2 = *param_1;
    fVar1 = *(float *)(iVar5 + 0xe4) - *(float *)(iVar2 + 8);
    fVar4 = *(float *)(iVar5 + 0xe8) - *(float *)(iVar2 + 0xc);
    fVar3 = *(float *)(iVar5 + 0xec) - *(float *)(iVar2 + 0x10);
    fVar3 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
    fVar1 = *(float *)(iVar2 + 0x124);
    if ((byte)((fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      Play__14CTargetCDAudio(param_1);
    }
  }
  return;
}


// Think__17CFuncTankControls  @ 000b6270
void Think__17CFuncTankControls(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar3 = (*DAT_001754f8)(iVar3,"targetname",
                            *(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar3 == 0) || (iVar2 = (*DAT_001755d8)(iVar3), iVar2 == 0)) {
      bVar1 = true;
    }
  } while ((!bVar1) &&
          (iVar2 = strncmp((char *)(*(int *)(iVar3 + 0xdc) + *(int *)(gpGlobals + 0x98)),"func_tank"
                           ,9), iVar2 != 0));
  bVar1 = false;
  if ((iVar3 == 0) || (iVar2 = (*DAT_001755d8)(iVar3), iVar2 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    param_1[0xf3] = iVar3;
    return;
  }
  (*DAT_001755b4)(1,"No tank %s\n",*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Think__17CInfoIntermission  @ 000e0260
void Think__17CInfoIntermission(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar3 = (*DAT_001754f8)(0,"targetname",*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
  bVar2 = false;
  if (iVar3 != 0) {
    iVar4 = (*DAT_001755d8)(iVar3);
    if (iVar4 != 0) goto LAB_000e02ae;
  }
  bVar2 = true;
LAB_000e02ae:
  if (!bVar2) {
    iVar4 = *param_1;
    fStack_1c = *(float *)(iVar3 + 0xe4) - *(float *)(iVar4 + 8);
    fStack_18 = *(float *)(iVar3 + 0xe8) - *(float *)(iVar4 + 0xc);
    fVar1 = *(float *)(iVar3 + 0xec) - *(float *)(iVar4 + 0x10);
    fStack_14 = SQRT(fVar1 * fVar1 + fStack_18 * fStack_18 + fStack_1c * fStack_1c);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_1c = 0.0;
      fStack_18 = 0.0;
      fStack_14 = 1.0;
    }
    else {
      fStack_14 = 1.0 / fStack_14;
      fStack_1c = fStack_14 * fStack_1c;
      fStack_18 = fStack_14 * fStack_18;
      fStack_14 = fStack_14 * fVar1;
    }
    UTIL_VecToAngles__FRC6Vector(&uStack_10,&fStack_1c);
    *(undefined4 *)(iVar4 + 0x74) = uStack_10;
    *(undefined4 *)(iVar4 + 0x78) = uStack_c;
    *(undefined4 *)(iVar4 + 0x7c) = uStack_8;
    *(float *)(*param_1 + 0x74) = -*(float *)(*param_1 + 0x74);
  }
  return;
}


// Think__18CHalfLifeMultiplay  @ 000b72b0
void Think__18CHalfLifeMultiplay(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = fraglimit._12_4_;
  if (g_fGameOver == 0) {
    fVar1 = (float)timelimit._12_4_ * 60.0;
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
       (fVar2 = *gpGlobals,
       0x3f < (byte)((fVar1 < fVar2 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))) {
      if ((byte)((float)fraglimit._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)fraglimit._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)fraglimit._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
        for (iVar5 = 1; iVar5 <= (int)gpGlobals[0x24]; iVar5 = iVar5 + 1) {
          iVar4 = (*DAT_001755e0)(iVar5);
          if ((iVar4 != 0) &&
             (fVar1 = *(float *)(iVar4 + 0x220),
             (byte)(((float)uVar3 < fVar1 |
                     (byte)((ushort)((ushort)(NAN((float)uVar3) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)uVar3 == fVar1) << 0xe) >> 8)) - 1) < 0x40))
          goto LAB_000b7348;
        }
      }
    }
    else {
LAB_000b7348:
      (**(code **)(*param_1 + 0xe0))(param_1);
    }
  }
  else {
    fVar1 = (float)param_1[1];
    fVar2 = *gpGlobals;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      if (param_1[2] == 0) {
        fVar2 = (float)param_1[1] + 120.0;
        fVar1 = *gpGlobals;
        if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) {
          return;
        }
      }
      (**(code **)(*param_1 + 0xe4))(param_1);
    }
  }
  return;
}


// Think__19CTriggerMonsterJump  @ 0010fff0
void Think__19CTriggerMonsterJump(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


// Think__5CGlow  @ 000ade60
void Think__5CGlow(int *param_1)

{
  float *pfVar1;
  
  Animate__5CGlowf(param_1,(*gpGlobals - (float)param_1[0xf3]) * *(float *)(*param_1 + 0x118));
  pfVar1 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[0xf3] = (int)*pfVar1;
  return;
}


// Think__7CCycler  @ 000bb920
void Think__7CCycler(int *param_1)

{
  float *pfVar1;
  
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  if (param_1[0x184] != 0) {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  }
  pfVar1 = gpGlobals;
  if ((param_1[0xf8] != 0) && (param_1[0xf9] == 0)) {
    *(float *)(*param_1 + 0x114) = *gpGlobals;
    *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
    param_1[0xf8] = 0;
    param_1[0xf7] = (int)*pfVar1;
    *(undefined4 *)(*param_1 + 0x110) = 0;
    if (param_1[0x184] == 0) {
      *(undefined4 *)(*param_1 + 0x118) = 0;
    }
  }
  return;
}


// Think__7CShower  @ 000b17a0
void Think__7CShower(int *param_1)

{
  float fVar1;
  
  UTIL_Sparks__FRC6Vector(*param_1 + 8);
  *(float *)(*param_1 + 0x1d8) = *(float *)(*param_1 + 0x1d8) - 0.1;
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  else {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
  return;
}


// Think__8CXenHair  @ 0011e780
void Think__8CXenHair(int *param_1)

{
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.5;
  return;
}


// Think__8CXenTree  @ 0011edd0
void Think__8CXenTree(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  DispatchAnimEvents__14CBaseAnimatingf(param_1,(float)lVar1);
  if (((param_1[0xfa] != 1) && (param_1[0xfa] == 0x1e)) && (param_1[0xf8] != 0)) {
    SetActivity__13CActAnimating8Activity(param_1,1);
    lVar1 = (longdouble)(*DAT_0017562c)(0x3f19999a,0x3fb33333);
    *(float *)(*param_1 + 0x118) = (float)lVar1;
  }
  return;
}


// Think__9CEnvSound  @ 000ec470
void Think__9CEnvSound(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  short local_1c;
  float local_18 [2];
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  iVar3 = (*DAT_00175504)(*(undefined4 *)(*param_1 + 0x1e8));
  bVar2 = false;
  if ((iVar3 == 0) || (iVar4 = (*DAT_001755d8)(iVar3), iVar4 == 0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = iVar3 + 0xdc;
    }
    iVar4 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(iVar4);
    bVar2 = false;
    if ((*(int *)(iVar4 + 0x63c) == 0) ||
       (iVar5 = (*DAT_001755d8)(*(int *)(iVar4 + 0x63c)), iVar5 == 0)) {
      bVar2 = true;
    }
    if ((bVar2) || (*(int *)(iVar4 + 0x63c) != *(int *)(*param_1 + 0x1e8))) {
      if (iVar3 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar3 + 0xdc;
      }
      iVar5 = FEnvSoundInRange__FP9entvars_tT0Pf(*param_1,iVar5,local_18);
      if ((iVar5 != 0) &&
         ((fVar1 = *(float *)(iVar4 + 0x644),
          (byte)(local_18[0] < fVar1 |
                 (byte)((ushort)((ushort)(NAN(local_18[0]) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_18[0] == fVar1) << 0xe) >> 8)) == 1 ||
          ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar4 + 0x644)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x644) == 0.0) << 0xe) >> 8)) == 0x40))
         )) {
        *(undefined4 *)(iVar4 + 0x63c) = *(undefined4 *)(*param_1 + 0x1e8);
        *(int *)(iVar4 + 0x640) = param_1[0xf4];
        *(float *)(iVar4 + 0x644) = local_18[0];
        (*DAT_00175578)(1,0x25,0,iVar3);
        _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
        local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        local_1c = (short)(int)ROUND((float)param_1[0xf4]);
        (*DAT_00175588)((int)local_1c);
        (*DAT_0017557c)();
      }
LAB_000ec660:
      iVar3 = *param_1;
      fVar1 = 0.75;
      goto LAB_000ec67b;
    }
    fVar1 = *(float *)(iVar4 + 0x640);
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
       (fVar1 = *(float *)(iVar4 + 0x644),
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + 0xdc;
      }
      iVar3 = FEnvSoundInRange__FP9entvars_tT0Pf(*param_1,iVar3,local_18);
      if (iVar3 != 0) {
        *(float *)(iVar4 + 0x644) = local_18[0];
        goto LAB_000ec660;
      }
      *(undefined4 *)(iVar4 + 0x644) = 0;
      *(undefined4 *)(iVar4 + 0x640) = 0;
    }
  }
  iVar3 = *param_1;
  fVar1 = 1.25;
LAB_000ec67b:
  *(float *)(iVar3 + 0xe4) = fVar1 + *gpGlobals;
  return;
}


// Think__9CFuncTank  @ 000b4a60
void Think__9CFuncTank(int *param_1)

{
  int iVar1;
  float fVar2;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  TrackTarget__9CFuncTank(param_1);
  fVar2 = ABS(*(float *)(*param_1 + 0x5c));
  if (((byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) == 1) ||
     (1.0 < ABS(*(float *)(*param_1 + 0x60)))) {
    StartRotSound__9CFuncTank(param_1);
  }
  else {
    StopRotSound__9CFuncTank(param_1);
  }
  return;
}


// Think__9CSoundEnt  @ 000ee040
void Think__9CSoundEnt(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.3;
  iVar5 = -1;
  iVar4 = param_1[0xf4];
  while (iVar4 != -1) {
    fVar1 = (float)param_1[iVar4 * 8 + 0xfc];
    fVar2 = *gpGlobals;
    if (((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) &&
       ((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) != 0x40)) {
      iVar3 = param_1[iVar4 * 8 + 0xfd];
      FreeSound__9CSoundEntii(iVar4,iVar5);
      iVar4 = iVar3;
    }
    else {
      iVar5 = iVar4;
      iVar4 = param_1[iVar4 * 8 + 0xfd];
    }
  }
  if (param_1[0xf6] != 0) {
    iVar5 = ISoundsInList__9CSoundEnti(param_1,2);
    uVar6 = ISoundsInList__9CSoundEnti(param_1,1,iVar5 - param_1[0xf5]);
    uVar6 = ISoundsInList__9CSoundEnti(param_1,2,uVar6);
    (*DAT_001755b4)(2,"Soundlist: %d / %d  (%d)\n",uVar6);
    iVar5 = ISoundsInList__9CSoundEnti(param_1,2);
    param_1[0xf5] = iVar5;
  }
  return;
}


// Think__9CSprayCan  @ 000dd390
void Think__9CSprayCan(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 **ppuVar5;
  undefined1 *puStack_80;
  undefined1 *local_7c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [56];
  
  if (*(int *)(*param_1 + 0x178) == 0) {
    local_7c = (undefined1 *)0x0;
  }
  else {
    local_7c = *(undefined1 **)(*(int *)(*param_1 + 0x178) + 0xd8);
  }
  if (local_7c == (undefined1 *)0x0) {
    iVar3 = -1;
  }
  else {
    puStack_80 = (undefined1 *)0xdd3bc;
    iVar3 = GetCustomDecalFrames__11CBasePlayer();
  }
  local_7c = *(undefined1 **)(*param_1 + 0x178);
  puStack_80 = (undefined1 *)0xdd3e5;
  uVar4 = (*DAT_001755dc)();
  local_7c = (undefined1 *)(*param_1 + 0x50);
  puStack_80 = (undefined1 *)0xdd3f6;
  UTIL_MakeVectors__FRC6Vector();
  iVar2 = *param_1;
  local_48 = *(float *)(iVar2 + 8) + gpGlobals[10] * 128.0;
  local_44 = *(float *)(iVar2 + 0xc) + gpGlobals[0xb] * 128.0;
  local_40 = *(float *)(iVar2 + 0x10) + gpGlobals[0xc] * 128.0;
  puStack_80 = *(undefined1 **)(iVar2 + 0x178);
  local_7c = local_3c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(iVar2 + 8,&local_48,1);
  if (iVar3 == -1) {
    local_7c = (undefined1 *)0xa;
    ppuVar5 = &puStack_80;
    puStack_80 = local_3c;
    UTIL_DecalTrace__FP11TraceResulti();
  }
  else {
    local_7c = (undefined1 *)0x1;
    puStack_80 = (undefined1 *)(int)ROUND(*(float *)(*param_1 + 0x110));
    UTIL_PlayerDecalTrace__FP11TraceResultiii(local_3c,uVar4);
    fVar1 = *(float *)(*param_1 + 0x110);
    local_7c = (undefined1 *)(iVar3 + -1);
    ppuVar5 = (undefined1 **)&stack0xffffff88;
    *(float *)(*param_1 + 0x110) = fVar1 + 1.0;
    if (fVar1 < (float)(int)local_7c) goto LAB_000dd4cd;
  }
  *(int **)((int)ppuVar5 + -4) = param_1;
  *(undefined4 *)((int)ppuVar5 + -8) = 0xdd4cd;
  UTIL_Remove__FP11CBaseEntity();
LAB_000dd4cd:
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


// Think__9CWreckage  @ 000bc1c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Think__9CWreckage(int *param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  pfVar3 = gpGlobals;
  local_8 = (float)_FUN_001331c0 + *gpGlobals;
  *(float *)(*param_1 + 0xe4) = local_8;
  fVar1 = *(float *)(*param_1 + 0x1c4);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar2 = *pfVar3;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
    lVar5 = (longdouble)(*DAT_0017562c)(0,*(float *)(*param_1 + 0x1c4) - (float)param_1[0x184]);
    lVar6 = (longdouble)*(float *)(*param_1 + 0x1c4) - (longdouble)*gpGlobals;
    if ((byte)(lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) == 1) {
      return;
    }
  }
  lVar5 = (longdouble)
          (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xa4),*(undefined4 *)(*param_1 + 0xb0));
  local_14 = (float)lVar5;
  lVar5 = (longdouble)
          (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xa8),*(undefined4 *)(*param_1 + 0xb4));
  local_10 = (float)lVar5;
  lVar5 = (longdouble)
          (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xac),*(undefined4 *)(*param_1 + 0xb8));
  local_c = (float)lVar5;
  (*DAT_00175578)(4,0x17,&local_14,0);
  (*DAT_00175580)(5);
  (*DAT_00175594)(local_14);
  (*DAT_00175594)(local_10);
  (*DAT_00175594)(local_c);
  (*DAT_00175588)((int)g_sModelIndexSmoke);
  iVar4 = (*DAT_00175628)(0,0x31);
  (*DAT_00175580)(iVar4 + 0x32);
  iVar4 = (*DAT_00175628)(0,3);
  (*DAT_00175580)(iVar4 + 8);
  (*DAT_0017557c)();
  return;
}


// Think__9CXenSpore  @ 0011f290
void Think__9CXenSpore(int *param_1)

{
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


