// Spawn__10CBreakable  @ 000a7b64
void Spawn__10CBreakable(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 1) == 0) {
    *(undefined4 *)(iVar2 + 0x16c) = 0x3f800000;
  }
  else {
    *(undefined4 *)(iVar2 + 0x16c) = 0;
  }
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  param_1[0x11b] = *(int *)(*param_1 + 0x54);
  *(undefined4 *)(*param_1 + 0x54) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[5] = -0x10000;
  param_1[6] = (int)BreakTouch__10CBreakableP11CBaseEntity;
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  iVar2 = IsBreakable__10CBreakable(param_1);
  if ((iVar2 == 0) && (*(int *)(*param_1 + 0x148) != 0)) {
    pbVar1 = (byte *)(*param_1 + 0x1a7);
    *pbVar1 = *pbVar1 | 2;
  }
  return;
}


// Spawn__10CCineBlood  @ 000b34b4
void Spawn__10CCineBlood(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)BloodStart__10CCineBloodP11CBaseEntityT18USE_TYPEf;
  *(undefined4 *)(*param_1 + 0x160) = 0x41a00000;
  return;
}


// Spawn__10CEnvFunnel  @ 000a32a0
void Spawn__10CEnvFunnel(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  return;
}


// Spawn__10CEnvGlobal  @ 0008d380
void Spawn__10CEnvGlobal(int *param_1)

{
  int iVar1;
  
  if (param_1[0x116] == 0) {
    (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  }
  else if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    iVar1 = Find__12CGlobalStatei(&gGlobalState,param_1[0x116]);
    if (iVar1 == 0) {
      EntityAdd__12CGlobalStateii12GLOBALESTATE
                (&gGlobalState,param_1[0x116],*(undefined4 *)(gpGlobals + 0xc),param_1[0x118]);
    }
  }
  return;
}


// Spawn__10CFuncTrain  @ 000ce5c0
void Spawn__10CFuncTrain(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar1 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar1 + 0x1f8) = 0x42c80000;
    iVar1 = *param_1;
  }
  if (*(int *)(iVar1 + 0x1c8) == 0) {
    (*DAT_0019f794)(1,"FuncTrain with no target");
    iVar1 = *param_1;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x1e0)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x1e0) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar1 + 0x1e0) = 0x40000000;
    iVar1 = *param_1;
  }
  *(undefined4 *)(iVar1 + 0x108) = 7;
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x1a0) & 8) == 0) {
    *(undefined4 *)(iVar1 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(iVar1 + 0x10c) = 0;
  }
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[0x142] = 0;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x13f]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x13f] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x13f] = 0x3f59999a;
  }
  return;
}


// Spawn__10CFurniture  @ 000eab0c
void Spawn__10CFurniture(int *param_1)

{
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x160) = 0x479c4000;
  *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0xb0) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x130) = 0;
  (**(code **)(param_1[0x115] + 0x124))(param_1);
  return;
}


// Spawn__10CGunTarget  @ 000d1240
void Spawn__10CGunTarget(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar1 + 0x1f8) = 0x42c80000;
    iVar1 = *param_1;
  }
  *(undefined4 *)(iVar1 + 0x16c) = 0;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  param_1[0x1a7] = 0;
  *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x1a0) & 1) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)Start__10CGunTarget;
    *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + 0.3;
  }
  return;
}


// Spawn__10CHealthKit  @ 000b5a3c
void Spawn__10CHealthKit(void)

{
  FUN_000b5a46();
  return;
}


// Spawn__10CLaserSpot  @ 001043b4
void Spawn__10CLaserSpot(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 3;
  *(undefined4 *)(*param_1 + 0x15c) = 0xe;
  *(undefined4 *)(*param_1 + 0x14c) = 0x437f0000;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"sprites/laserdot.spr");
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__10CLightning  @ 0009f904
void Spawn__10CLightning(int *param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1[0x120] == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    *(float *)(*param_1 + 0x1e4) = *gpGlobals;
    bVar2 = false;
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x119]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x119] == 0.0) << 0xe) >> 8)) == 0x40) {
      bVar2 = (*(byte *)(*param_1 + 0x1a0) & 8) == 0;
    }
    if (bVar2) {
      iVar1 = *param_1;
      param_1[3] = 0;
      param_1[4] = 0;
      if (0.0 < *(float *)(iVar1 + 0x1e0)) {
        param_1[3] = -0x10000;
        param_1[4] = (int)DamageThink__10CLightning;
        *(float *)(iVar1 + 0x104) = *gpGlobals + 0.1;
        iVar1 = *param_1;
      }
      if (*(int *)(iVar1 + 0x1cc) != 0) {
        if (((*(byte *)(iVar1 + 0x1a0) ^ 1) & 1) == 0) {
          param_1[0x116] = 1;
        }
        else {
          *(undefined4 *)(iVar1 + 0x118) = 0x80;
          param_1[0x116] = 0;
          *(undefined4 *)(*param_1 + 0x104) = 0;
        }
        param_1[7] = -0x10000;
        param_1[8] = (int)ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf;
      }
    }
    else {
      iVar1 = *param_1;
      param_1[0x116] = 0;
      if (*(int *)(iVar1 + 0x1cc) != 0) {
        param_1[7] = -0x10000;
        param_1[8] = (int)StrikeUse__10CLightningP11CBaseEntityT18USE_TYPEf;
      }
      if ((*(int *)(iVar1 + 0x1cc) == 0) || ((*(byte *)(iVar1 + 0x1a0) & 1) != 0)) {
        param_1[3] = -0x10000;
        param_1[4] = (int)StrikeThink__10CLightning;
        *(float *)(iVar1 + 0x104) = *gpGlobals + 1.0;
      }
    }
  }
  return;
}


// Spawn__10CPathTrack  @ 000ccbe8
void Spawn__10CPathTrack(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0x41000000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  local_1c = 0xc1000000;
  local_18 = local_1c;
  local_14 = local_1c;
  local_c = local_10;
  local_8 = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[0x118] = 0;
  param_1[0x119] = 0;
  return;
}


// Spawn__10CRotButton  @ 0008b7a4
void Spawn__10CRotButton(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar6 = ButtonSound__Fi(param_1[0x14b]);
  (*DAT_0019f6a4)(uVar6);
  uVar6 = (*DAT_0019f7ac)(uVar6);
  *(undefined4 *)(*param_1 + 0x1e8) = uVar6;
  AxisDir__11CBaseToggleP9entvars_s(*param_1);
  iVar7 = *param_1;
  if ((*(byte *)(iVar7 + 0x1a0) & 2) != 0) {
    *(float *)(iVar7 + 0x44) = -*(float *)(iVar7 + 0x44);
    *(float *)(iVar7 + 0x48) = -*(float *)(iVar7 + 0x48);
    *(float *)(iVar7 + 0x4c) = -*(float *)(iVar7 + 0x4c);
    iVar7 = *param_1;
  }
  *(undefined4 *)(iVar7 + 0x108) = 7;
  iVar7 = *param_1;
  if ((*(byte *)(iVar7 + 0x1a0) & 1) == 0) {
    *(undefined4 *)(iVar7 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(iVar7 + 0x10c) = 0;
  }
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42200000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x120]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x120] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x120] = 0x3f800000;
  }
  if (0.0 < *(float *)(*param_1 + 0x160)) {
    *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  }
  param_1[0x11d] = 1;
  iVar7 = *param_1;
  fVar1 = (float)param_1[0x11f];
  param_1[0x12a] = *(int *)(iVar7 + 0x50);
  param_1[299] = *(int *)(iVar7 + 0x54);
  param_1[300] = *(int *)(iVar7 + 0x58);
  fVar2 = *(float *)(iVar7 + 0x48);
  fVar3 = *(float *)(iVar7 + 0x4c);
  fVar4 = *(float *)(iVar7 + 0x54);
  fVar5 = *(float *)(iVar7 + 0x58);
  param_1[0x12d] = (int)(*(float *)(iVar7 + 0x44) * fVar1 + *(float *)(iVar7 + 0x50));
  param_1[0x12e] = (int)(fVar2 * fVar1 + fVar4);
  param_1[0x12f] = (int)(fVar1 * fVar3 + fVar5);
  fVar1 = (float)param_1[0x120];
  param_1[0x13e] =
       (uint)((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40);
  param_1[0x13f] = 1;
  if ((*(byte *)(iVar7 + 0x1a1) & 1) == 0) {
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)ButtonUse__11CBaseButtonP11CBaseEntityT18USE_TYPEf;
  }
  else {
    param_1[5] = -0x10000;
    param_1[6] = (int)ButtonTouch__11CBaseButtonP11CBaseEntity;
  }
  return;
}


// Spawn__10CTFGrenade  @ 00103ec4
void Spawn__10CTFGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  longdouble lVar8;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f000000;
  param_1[0x1a8] = 1;
  param_1[0x1a9] = 1;
  (**(code **)(param_1[0x115] + 0x228))(param_1);
  local_10 = 0.0;
  local_c = 0.0;
  local_8 = 0.0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  iVar7 = *param_1;
  fVar1 = gpGlobals[10];
  fVar2 = gpGlobals[0xb];
  fVar3 = gpGlobals[0xc];
  fVar4 = gpGlobals[0xd];
  fVar5 = gpGlobals[0xe];
  fVar6 = gpGlobals[0xf];
  lVar8 = (longdouble)(*DAT_0019f80c)(0xc1200000,0x41200000);
  local_10 = (float)((longdouble)gpGlobals[0x10] * lVar8 +
                    (longdouble)(fVar1 * 600.0 + fVar4 * 200.0));
  local_c = (float)((longdouble)gpGlobals[0x11] * lVar8 +
                   (longdouble)(fVar2 * 600.0 + fVar5 * 200.0));
  local_8 = (float)(lVar8 * (longdouble)gpGlobals[0x12] +
                   (longdouble)(fVar3 * 600.0 + fVar6 * 200.0));
  lVar8 = (longdouble)(*DAT_0019f80c)(0xc1200000,0x41200000);
  fVar1 = gpGlobals[0xe];
  fVar2 = gpGlobals[0xf];
  *(float *)(iVar7 + 0x20) = (float)((longdouble)gpGlobals[0xd] * lVar8 + (longdouble)local_10);
  *(float *)(iVar7 + 0x24) = (float)((longdouble)fVar1 * lVar8 + (longdouble)local_c);
  *(float *)(iVar7 + 0x28) = (float)(lVar8 * (longdouble)fVar2 + (longdouble)local_8);
  iVar7 = *param_1;
  *(undefined4 *)(iVar7 + 0x5c) = 0x43960000;
  *(undefined4 *)(iVar7 + 0x60) = 0x43960000;
  *(undefined4 *)(iVar7 + 100) = 0x43960000;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 2.5;
  param_1[3] = -0x10000;
  param_1[4] = (int)Detonate__8CGrenade;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x42f00000;
  return;
}


// Spawn__10CTFMedikit  @ 0012c9f0
void Spawn__10CTFMedikit(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 3;
  param_1[0x130] = -1;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[0x154] = 2;
  return;
}


// Spawn__10CTFNailgun  @ 0012f720
void Spawn__10CTFNailgun(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 4;
  param_1[0x133] = 0x32;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFRailgun  @ 0012fc94
void Spawn__10CTFRailgun(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_railgun" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 2;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_gauss.mdl");
  param_1[0x133] = 0x11;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFRpgAmmo  @ 00144220
void Spawn__10CTFRpgAmmo(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_rpgammo.mdl");
  Spawn__15CBasePlayerAmmo(param_1);
  return;
}


// Spawn__10CTFShotgun  @ 0013136c
void Spawn__10CTFShotgun(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 8;
  param_1[0x2c] = 0;
  param_1[0x133] = 8;
  param_1[0x136] = 8;
  param_1[0x135] = 1;
  param_1[0x127] = 0x3e800000;
  param_1[0x126] = 0x447a0000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFSpanner  @ 0012d044
void Spawn__10CTFSpanner(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 4;
  param_1[0x130] = -1;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[0x154] = 1;
  return;
}


// Spawn__10CTeamCheck  @ 00111a28
void Spawn__10CTeamCheck(void)

{
  return;
}


// Spawn__10CWeaponBox  @ 00125010
void Spawn__10CWeaponBox(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/backpack.mdl");
  param_1[0x11c] = 0;
  param_1[0x11d] = 0;
  return;
}


// Spawn__10CWorldItem  @ 000b5b18
void Spawn__10CWorldItem(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)0x0;
  switch(param_1[0x116]) {
  case 0x2a:
    iVar4 = *param_1 + 0x50;
    iVar1 = *param_1 + 8;
    pcVar2 = "item_antidote";
    break;
  case 0x2b:
    iVar4 = *param_1 + 0x50;
    iVar1 = *param_1 + 8;
    pcVar2 = "item_security";
    break;
  case 0x2c:
    iVar4 = *param_1 + 0x50;
    iVar1 = *param_1 + 8;
    pcVar2 = "item_battery";
    break;
  case 0x2d:
    iVar4 = *param_1 + 0x50;
    iVar1 = *param_1 + 8;
    pcVar2 = "item_suit";
    break;
  default:
    goto switchD_000b5b46_default;
  }
  piVar3 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s(pcVar2,iVar1,iVar4,0);
switchD_000b5b46_default:
  if (piVar3 == (int *)0x0) {
    (*DAT_0019f794)(1,"unable to create world_item %d\n",param_1[0x116]);
  }
  else {
    *(undefined4 *)(*piVar3 + 0x1c8) = *(undefined4 *)(*param_1 + 0x1c8);
    *(undefined4 *)(*piVar3 + 0x1cc) = *(undefined4 *)(*param_1 + 0x1cc);
    *(undefined4 *)(*piVar3 + 0x1a0) = *(undefined4 *)(*param_1 + 0x1a0);
  }
  (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Spawn__10CXenPLight  @ 001281bc
void Spawn__10CXenPLight(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  longdouble lVar8;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/light.mdl");
  local_10 = 0x42a00000;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  local_8 = 32.0;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  local_1c = 0xc2a00000;
  local_14 = 0.0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  iVar5 = LookupActivity__14CBaseAnimatingi(param_1,1);
  if (iVar5 != -1) {
    *(int *)(*param_1 + 0x128) = iVar5;
    param_1[0x11d] = 1;
    *(undefined4 *)(*param_1 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  lVar8 = (longdouble)(*DAT_0019f80c)(0,0x437f0000);
  *(float *)(*param_1 + 0x130) = (float)lVar8;
  iVar5 = *param_1;
  local_10 = 0;
  local_c = 0;
  local_8 = (*(float *)(iVar5 + 0xe4) + *(float *)(iVar5 + 0xf0)) * 0.5;
  local_14 = local_8 + *(float *)(iVar5 + 0x10);
  local_1c = *(undefined4 *)(iVar5 + 8);
  local_18 = *(undefined4 *)(iVar5 + 0xc);
  piVar6 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/flare3.spr",&local_1c,0);
  iVar5 = *param_1;
  param_1[0x11e] = (int)piVar6;
  fVar1 = *(float *)(iVar5 + 0x150);
  fVar2 = *(float *)(iVar5 + 0x154);
  fVar3 = *(float *)(iVar5 + 0x158);
  fVar4 = *(float *)(iVar5 + 0x14c);
  uVar7 = *(undefined4 *)(iVar5 + 0x15c);
  *(undefined4 *)(*piVar6 + 0x148) = 3;
  *(float *)(*piVar6 + 0x150) = (float)(int)ROUND(fVar1);
  *(float *)(*piVar6 + 0x154) = (float)(int)ROUND(fVar2);
  *(float *)(*piVar6 + 0x158) = (float)(int)ROUND(fVar3);
  *(float *)(*piVar6 + 0x14c) = (float)(int)ROUND(fVar4);
  *(undefined4 *)(*piVar6 + 0x15c) = uVar7;
  piVar6 = (int *)param_1[0x11e];
  iVar5 = *(int *)(*param_1 + 0x208);
  if (iVar5 != 0) {
    uVar7 = (*DAT_0019f7bc)(iVar5);
    *(undefined4 *)(*piVar6 + 0x110) = uVar7;
    *(undefined4 *)(*piVar6 + 0x114) = 1;
    *(int *)(*piVar6 + 0x194) = iVar5;
    *(undefined4 *)(*piVar6 + 0x108) = 0xc;
  }
  return;
}


// Spawn__11CBaseButton  @ 0008aca8
void Spawn__11CBaseButton(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  undefined4 uVar7;
  int iVar8;
  
  uVar7 = ButtonSound__Fi(param_1[0x14b]);
  (*DAT_0019f6a4)(uVar7);
  uVar7 = (*DAT_0019f7ac)(uVar7);
  *(undefined4 *)(*param_1 + 0x1e8) = uVar7;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar8 = *param_1;
  if ((*(byte *)(iVar8 + 0x1a0) & 0x40) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)ButtonSpark__11CBaseButton;
    *(float *)(iVar8 + 0x104) = *gpGlobals + 0.5;
    iVar8 = *param_1;
  }
  SetMovedir__FP9entvars_s(iVar8);
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  iVar8 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar8 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar8 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar8 + 0x1f8) = 0x42200000;
    iVar8 = *param_1;
  }
  *(undefined4 *)(iVar8 + 0x1b0) = 0;
  if (0.0 < *(float *)(*param_1 + 0x160)) {
    *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
    *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x120]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x120] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x120] = 0x3f800000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x121]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x121] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x121] = 0x40800000;
  }
  param_1[0x11d] = 1;
  iVar8 = *param_1;
  param_1[0x124] = *(int *)(iVar8 + 8);
  param_1[0x125] = *(int *)(iVar8 + 0xc);
  param_1[0x126] = *(int *)(iVar8 + 0x10);
  fVar3 = (ABS((*(float *)(iVar8 + 0xf8) - 2.0) * *(float *)(iVar8 + 0x48)) +
           ABS((*(float *)(iVar8 + 0xf4) - 2.0) * *(float *)(iVar8 + 0x44)) +
          ABS((*(float *)(iVar8 + 0xfc) - 2.0) * *(float *)(iVar8 + 0x4c))) - (float)param_1[0x121];
  fVar1 = *(float *)(iVar8 + 0x48);
  fVar2 = *(float *)(iVar8 + 0x4c);
  param_1[0x127] = (int)((float)param_1[0x124] + *(float *)(iVar8 + 0x44) * fVar3);
  fVar4 = (float)param_1[0x127] - (float)param_1[0x124];
  param_1[0x128] = (int)((float)param_1[0x125] + fVar1 * fVar3);
  fVar5 = (float)param_1[0x128] - (float)param_1[0x125];
  param_1[0x129] = (int)(fVar3 * fVar2 + (float)param_1[0x126]);
  fVar1 = (float)param_1[0x129] - (float)param_1[0x126];
  bVar6 = false;
  fVar1 = SQRT(fVar1 * fVar1 + fVar5 * fVar5 + fVar4 * fVar4);
  if (((byte)(fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) ||
     ((*(byte *)(iVar8 + 0x1a0) & 1) != 0)) {
    bVar6 = true;
  }
  if (bVar6) {
    param_1[0x127] = param_1[0x124];
    param_1[0x128] = param_1[0x125];
    param_1[0x129] = param_1[0x126];
  }
  fVar1 = (float)param_1[0x120];
  param_1[0x13e] =
       (uint)((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40);
  param_1[0x13f] = 0;
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)ButtonUse__11CBaseButtonP11CBaseEntityT18USE_TYPEf;
  }
  else {
    param_1[5] = -0x10000;
    param_1[6] = (int)ButtonTouch__11CBaseButtonP11CBaseEntity;
  }
  return;
}


// Spawn__11CBaseEntity  @ 00112f74
void Spawn__11CBaseEntity(void)

{
  return;
}


// Spawn__11CBasePlayer  @ 000d9d8c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__11CBasePlayer(int *param_1)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 in_FPUControlWord;
  longdouble lVar8;
  uint local_38;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  *(int *)*param_1 = (int)"player" - (int)gpGlobals[0x26];
  *(undefined4 *)(*param_1 + 0x160) = 0x42c80000;
  *(undefined4 *)(*param_1 + 0x1bc) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 3;
  *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  *(uint *)(*param_1 + 0x1a4) = *(uint *)(*param_1 + 0x1a4) & 0x100000;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 8;
  *(float *)(*param_1 + 0x1fc) = *gpGlobals + 12.0;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x40000000;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x170) = 0;
  *(undefined4 *)(*param_1 + 0x1d8) = 0;
  *(undefined4 *)(*param_1 + 0x1dc) = 0;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f800000;
  param_1[0x21e] = -1;
  param_1[0x197] = 0;
  param_1[0x1c3] = 0;
  param_1[0x227] = 0;
  param_1[0x22f] = 0;
  *(undefined4 *)(*param_1 + 0x214) = 0;
  param_1[0x230] = -1;
  param_1[0x28e] = 0;
  param_1[0x47] = 0;
  *(undefined4 *)(*param_1 + 0x24c) = 0;
  (*DAT_0019f880)(*(undefined4 *)(*param_1 + 0x208),&DAT_00150933,&DAT_00150931);
  local_38 = 0;
  iVar7 = 0;
  do {
    local_38 = local_38 | ((&teamallies)[iVar7] & 0x1f) << ((char)iVar7 * '\x05' & 0x1fU);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 5);
  sprintf((char *)&local_24,"%u",local_38);
  (*DAT_0019f880)(*(undefined4 *)(*param_1 + 0x208),&DAT_0015093a,&local_24);
  fVar1 = *gpGlobals;
  param_1[0x217] = 0;
  param_1[0x19b] = 0xf7;
  param_1[0x1c7] = 0;
  param_1[0x157] = 0x3f000000;
  param_1[0x196] = 0;
  param_1[0x215] = (int)(fVar1 + 2.0);
  (**(code **)(param_1[0x115] + 0x7c))(param_1);
  *(undefined1 *)(param_1 + 0x290) = 0;
  param_1[0x1b4] = 99;
  param_1[0x22] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x44] = 0x3f800000;
  param_1[0x1b3] = 0x3f800000;
  param_1[0x1bb] = 0;
  param_1[0x28c] = 0;
  param_1[0x28b] = 0;
  param_1[0x10d] = 0;
  param_1[0x10e] = 0;
  param_1[0x10c] = 0;
  param_1[0x10b] = 0;
  fVar1 = *gpGlobals;
  param_1[0x365] = 0;
  param_1[0x37d] = -1;
  param_1[0x37e] = -1;
  param_1[0x380] = -1;
  param_1[0x381] = -1;
  param_1[0x371] = 0;
  param_1[0x72] = 0;
  param_1[99] = (int)(fVar1 + 10.0);
  if (param_1[0xb] != 0) {
    *(int *)(*param_1 + 0x20c) = param_1[0xb];
    param_1[0xb] = 0;
    if (*(int *)(*param_1 + 0x20c) == 10) {
      *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) | 8;
    }
    else {
      *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xf7;
    }
  }
  uVar2 = param_1[0x21];
  if ((uVar2 & 8) == 0) {
    param_1[0x21] = 0;
  }
  else {
    iVar7 = *(int *)(*param_1 + 0x20c);
    do {
      do {
        do {
          lVar8 = (longdouble)(*DAT_0019f80c)(0,0x41100000);
          uVar3 = CONCAT22(in_FPUControlWord,in_FPUControlWord) & 0xfffff3ff;
          local_24 = uVar3 | 0x400;
          uVar4 = local_24;
          local_24._2_2_ = (undefined2)(uVar3 >> 0x10);
          *(int *)(*param_1 + 0x20c) = (int)ROUND((longdouble)1 + ROUND(lVar8));
          in_FPUControlWord = local_24._2_2_;
          local_24 = uVar4;
          iVar5 = IsLegalClass__11CBasePlayeri(param_1,*(undefined4 *)(*param_1 + 0x20c));
        } while (iVar5 == 0);
      } while (*(int *)(*param_1 + 0x20c) == iVar7);
      iVar5 = ClassIsRestricted__Ffi((float)param_1[0x48],*(int *)(*param_1 + 0x20c));
    } while (iVar5 != 0);
    param_1[0x367] = 1;
    param_1[0x23a] = 0;
    param_1[0x21] = 8;
  }
  if ((uVar2 >> 0xc & 1) == 1) {
    *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) | 0x10;
  }
  TeamFortress_ExecClassScript__11CBasePlayer(param_1);
  iVar7 = *param_1;
  if (*(int *)(iVar7 + 0x20c) != 9) {
    Engineer_RemoveBuildings__11CBasePlayer(param_1);
    iVar7 = *param_1;
  }
  *(undefined4 *)(iVar7 + 0x16c) = 0x40000000;
  TeamFortress_PrintClassName__11CBasePlayeri(param_1,*(undefined4 *)(*param_1 + 0x20c));
  TeamFortress_SetEquipment__11CBasePlayer(param_1);
  TeamFortress_SetHealth__11CBasePlayer(param_1);
  TeamFortress_SetSpeed__11CBasePlayer(param_1);
  TeamFortress_SetSkin__11CBasePlayer(param_1);
  param_1[0x370] = 0;
  param_1[0x50] = 0;
  param_1[0x62] = 0;
  param_1[0x36f] = (int)*gpGlobals;
  param_1[0x36e] = -0x40800000;
  param_1[5] = -0x10000;
  param_1[6] = (int)PlayerTouch__11CBasePlayerP11CBaseEntity;
  if (param_1[0x7d] != 0) {
    uVar6 = UTIL_dtos1__Fi(param_1[0x7d],0,0,0);
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_battleid",uVar6);
  }
  (**(code **)(*g_pGameRules + 0x60))(g_pGameRules,param_1);
  uVar6 = LookupActivity__14CBaseAnimatingi(param_1,1);
  *(undefined4 *)(*param_1 + 0x128) = uVar6;
  if ((*(byte *)(*param_1 + 0x1a5) & 0x40) == 0) {
    local_1c = 0x42100000;
    local_10 = 0xc2100000;
  }
  else {
    local_1c = 0x41900000;
    local_10 = 0xc1900000;
  }
  local_20 = 0x41800000;
  local_18 = 0xc1800000;
  local_24 = local_20;
  local_14 = local_18;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_24);
  iVar7 = *param_1;
  local_24 = 0;
  local_1c = 0x41e00000;
  local_20 = 0;
  *(undefined4 *)(iVar7 + 0x174) = 0;
  *(undefined4 *)(iVar7 + 0x178) = 0;
  *(undefined4 *)(iVar7 + 0x17c) = 0x41e00000;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar7 = _FUN_001509b0;
  local_24 = 0;
  local_20 = _FUN_001509b0;
  local_1c = 0;
  param_1[0x1a2] = 0;
  param_1[0x1a3] = iVar7;
  param_1[0x1a4] = 0;
  if (param_1[0x1ad] == -1) {
    (*DAT_0019f794)(1,"Couldn\'t alloc player sound slot!\n");
  }
  param_1[0x226] = 0;
  param_1[0x21f] = 1;
  param_1[0x22e] = -1;
  param_1[0x222] = 0;
  param_1[0x238] = 0;
  param_1[0x22c] = -1;
  param_1[0x2b] = -0x40800000;
  param_1[0x2a] = -0x40800000;
  iVar7 = 0;
  do {
    param_1[iVar7 + 0x23b] = 0;
    iVar5 = iVar7 + 1;
    param_1[iVar7 + 0x25b] = 0;
    iVar7 = iVar5;
  } while (iVar5 < 0x20);
  param_1[0x287] = 0;
  param_1[0x286] = 0;
  (**(code **)(*g_pGameRules + 0x50))(g_pGameRules,param_1);
  return;
}


// Spawn__11CBaseTurret  @ 0011a490
void Spawn__11CBaseTurret(int *param_1)

{
  float fVar1;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  *(undefined4 *)(*param_1 + 0x108) = 5;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  fVar1 = gpGlobals[5];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
  }
  else {
    *(undefined4 *)(*param_1 + 0x16c) = 0;
  }
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  param_1[7] = -0x10000;
  param_1[8] = (int)TurretUse__11CBaseTurretP11CBaseEntityT18USE_TYPEf;
  fVar1 = gpGlobals[5];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0x1b3] = 1;
  }
  if ((*(uint *)(*param_1 + 0x1a0) & 0x60) == 0x20) {
    param_1[0x1b3] = 1;
  }
  ResetSequenceInfo__14CBaseAnimating(param_1);
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  param_1[0x157] = -0x40800000;
  return;
}


// Spawn__11CBloodSplatP9entvars_s  @ 000e585c
void Spawn__11CBloodSplatP9entvars_s(int *param_1,int param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  fVar1 = *(float *)(param_2 + 0x10);
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  *(float *)(iVar3 + 0x10) = fVar1 + 32.0;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(param_2 + 0x74);
  *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(param_2 + 0x78);
  *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(param_2 + 0x7c);
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(param_2 + 0x208);
  param_1[3] = -0x10000;
  param_1[4] = (int)Spray__11CBloodSplat;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


// Spawn__11CCine2Slave  @ 001404e8
void Spawn__11CCine2Slave(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine2_slave.mdl");
  return;
}


// Spawn__11CCineBarney  @ 00140618
void Spawn__11CCineBarney(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-barney.mdl");
  return;
}


// Spawn__11CFireAndDie  @ 00118b18
void Spawn__11CFireAndDie(undefined4 *param_1)

{
  *(int *)*param_1 = (int)"fireanddie" - *(int *)(gpGlobals + 0x98);
  return;
}


// Spawn__11CGibShooter  @ 000a4048
void Spawn__11CGibShooter(int *param_1)

{
  undefined4 uVar1;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x116]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x116] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x116] = 0x3dcccccd;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x11e]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x11e] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x11e] = 0x41c80000;
  }
  SetMovedir__FP9entvars_s(*param_1);
  uVar1 = (*DAT_0019f6b0)(param_1[0x11b]);
  *(undefined4 *)(*param_1 + 0x114) = uVar1;
  return;
}


// Spawn__11CItemHealth  @ 000fbed8
void Spawn__11CItemHealth(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_medkit.mdl");
    Spawn__5CItem(param_1);
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x116]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x116] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x116] = 0x41a00000;
    }
    iVar1 = *param_1;
    if ((*(uint *)(iVar1 + 0x1a0) & 1) == 0) {
      if ((*(uint *)(iVar1 + 0x1a0) & 2) != 0) {
        *(int *)(iVar1 + 0x1e8) = (int)"items/r_item1.wav" - *(int *)(gpGlobals + 0x98);
        param_1[0x117] = 100;
        param_1[0x118] = 1;
        return;
      }
      *(int *)(iVar1 + 0x1e8) = (int)"items/health1.wav" - *(int *)(gpGlobals + 0x98);
      param_1[0x117] = 0x19;
    }
    else {
      *(int *)(iVar1 + 0x1e8) = (int)"items/smallmedkit1.wav" - *(int *)(gpGlobals + 0x98);
      param_1[0x117] = 0xf;
    }
    param_1[0x118] = 0;
  }
  return;
}


// Spawn__11CMiniTurret  @ 0011a8a8
void Spawn__11CMiniTurret(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/miniturret.mdl");
  *(undefined4 *)(*param_1 + 0x160) = DAT_001a1cc0;
  local_10 = 0;
  local_8 = 0x414c0000;
  local_c = 0;
  param_1[0x1a2] = 0;
  param_1[0x1a3] = 0;
  param_1[0x1a4] = 0x414c0000;
  param_1[0x1a7] = 0;
  *(undefined4 *)(*param_1 + 0x17c) = 0x414c0000;
  Spawn__11CBaseTurret(param_1);
  param_1[0x1ac] = 0x10;
  param_1[0x1ab] = 0x20;
  param_1[0x1ad] = -0xf;
  local_10 = 0x41800000;
  local_1c = 0xc1800000;
  local_18 = local_1c;
  local_14 = local_1c;
  local_c = local_10;
  local_8 = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  return;
}


// Spawn__11CNodeViewer  @ 000ca3f0
void Spawn__11CNodeViewer(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iStack_34;
  char *pcStack_30;
  int iStack_2c;
  int iStack_14;
  
  if ((WorldGraph == 0) || (DAT_0019fb24 == 0)) {
    (*DAT_0019f794)(1,"Graph not ready!\n");
    UTIL_Remove__FP11CBaseEntity(param_1);
    return;
  }
  iVar3 = strcmp((char *)(*(int *)*param_1 + gpGlobals[0x26]),"node_viewer_fly");
  if (iVar3 == 0) {
    param_1[0x219] = 3;
    param_1[0x21a] = 2;
    iVar4 = 0x43200000;
    iVar3 = 0x42c80000;
    iVar1 = 0x437f0000;
  }
  else {
    iVar3 = strcmp((char *)(*(int *)*param_1 + gpGlobals[0x26]),"node_viewer_large");
    if (iVar3 != 0) {
      param_1[0x219] = 1;
      param_1[0x21a] = 5;
      param_1[0x21b] = 0x437f0000;
      param_1[0x21c] = 0x43200000;
      param_1[0x21d] = 0x42c80000;
      goto LAB_000ca559;
    }
    param_1[0x219] = 2;
    param_1[0x21a] = 5;
    iVar4 = 0x42c80000;
    iVar3 = 0x437f0000;
    iVar1 = 0x43200000;
  }
  param_1[0x21b] = iVar4;
  param_1[0x21c] = iVar3;
  param_1[0x21d] = iVar1;
LAB_000ca559:
  iVar3 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,param_1[0x21a]);
  param_1[0x116] = iVar3;
  if (iVar3 < 0) {
    (*DAT_0019f794)(1,"No nearby node\n");
  }
  else {
    param_1[0x118] = 0;
    (*DAT_0019f794)(2,"basenode %d\n",iVar3);
    if (DAT_0019fb38 < 0x80) {
      iStack_14 = 0;
      if (0 < DAT_0019fb38) {
        do {
          iStack_34 = iStack_14;
          iVar3 = param_1[0x116] + 1;
          pcStack_30 = (char *)(*(int *)(param_1[0x219] * 8 + DAT_0019fb2c + 0x28 + iStack_14 * 0x58
                                        ) + iRam0019fb34);
          while (0 < iVar3) {
            cVar2 = *pcStack_30;
            if (cVar2 < '\0') {
              if (iVar3 <= -cVar2) {
                FUN_000ca6a0();
                return;
              }
              iVar3 = iVar3 - -cVar2;
              pcStack_30 = pcStack_30 + 1;
            }
            else {
              if (cVar2 + 1 < iVar3) {
                iVar3 = (iVar3 - cVar2) + -1;
              }
              else {
                iStack_34 = pcStack_30[1] + iStack_14;
                if (iStack_34 < DAT_0019fb38) {
                  if (iStack_34 < 0) {
                    iStack_34 = iStack_34 + DAT_0019fb38;
                  }
                }
                else {
                  iStack_34 = iStack_34 - DAT_0019fb38;
                }
                iVar3 = 0;
              }
              pcStack_30 = pcStack_30 + 2;
            }
          }
          AddNode__11CNodeViewerii(param_1,iStack_14,iStack_34);
          iStack_14 = iStack_14 + 1;
        } while (iStack_14 < DAT_0019fb38);
      }
    }
    else {
      FindNodeConnections__11CNodeVieweri(param_1,param_1[0x116]);
      iStack_34 = 0;
      iStack_2c = param_1[0x118];
      do {
        for (; iStack_34 < iStack_2c; iStack_34 = iStack_34 + 1) {
          FindNodeConnections__11CNodeVieweri(param_1,param_1[iStack_34 + 0x119]);
          FindNodeConnections__11CNodeVieweri(param_1,param_1[iStack_34 + 0x199]);
        }
        bVar5 = iStack_2c != param_1[0x118];
        iStack_2c = param_1[0x118];
      } while (bVar5);
    }
    (*DAT_0019f794)(2,"%d nodes\n",param_1[0x118]);
    param_1[0x117] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)DrawThink__11CNodeViewer;
    *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


// Spawn__11CNullEntity  @ 000f6914
void Spawn__11CNullEntity(int *param_1)

{
  (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Spawn__11CPathCorner  @ 000cce10
void Spawn__11CPathCorner(void)

{
  return;
}


// Spawn__11CTFAssaultC  @ 0012a810
void Spawn__11CTFAssaultC(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_ac" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 4;
  param_1[0x133] = 0x19;
  param_1[299] = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__11CTFGoalItem  @ 0010b3f8
void Spawn__11CTFGoalItem(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  iVar2 = param_1[0xbe];
  if ((((iVar2 == -1) && (g_iSkillLevel < 0)) ||
      ((iVar3 = param_1[0xbf], iVar3 == -1 && (0 < g_iSkillLevel)))) ||
     (((1 < iVar2 + 1U && (g_iSkillLevel < iVar2)) || (1 < iVar3 + 1U && iVar3 < g_iSkillLevel)))) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    *(int *)*param_1 = (int)"item_tfgoal" - *(int *)(gpGlobals + 0x98);
    if (*(int *)(*param_1 + 0xb8) != 0) {
      (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
      (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                      *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
      uVar4 = LookupSequence__14CBaseAnimatingPCc(param_1,"not_carried");
      *(undefined4 *)(*param_1 + 0x128) = uVar4;
      if (*(int *)(*param_1 + 0x128) != -1) {
        ResetSequenceInfo__14CBaseAnimating(param_1);
        *(undefined4 *)(*param_1 + 0x130) = 0;
      }
    }
    (*DAT_0019f6a4)("items/itembk2.wav");
    if (*(int *)(*param_1 + 0x1e8) != 0) {
      (*DAT_0019f6a4)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
    }
    if (param_1[0x86] == 0) {
      param_1[0x86] = 2;
    }
    if ((*(byte *)((int)param_1 + 0x229) & 0x20) == 0) {
      *(undefined4 *)(*param_1 + 0x10c) = 1;
    }
    else {
      *(undefined4 *)(*param_1 + 0x10c) = 2;
      bVar5 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0xa0])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0xa0]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN((float)param_1[0xa1])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_0019f664 == (float)param_1[0xa1]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa2];
        bVar5 = (byte)(DAT_0019f668 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar5) {
        param_1[0xa0] = -0x3e800000;
        param_1[0xa1] = -0x3e800000;
        param_1[0xa2] = -0x3e400000;
      }
      bVar5 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0xa3])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0xa3]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN((float)param_1[0xa4])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_0019f664 == (float)param_1[0xa4]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa5];
        bVar5 = (byte)(DAT_0019f668 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar5) {
        param_1[0xa3] = 0x41800000;
        param_1[0xa4] = 0x41800000;
        param_1[0xa5] = 0x42000000;
      }
    }
    if (*(int *)(*param_1 + 0x1d0) == 0) {
      *(int *)(*param_1 + 0x1d0) = (int)"goalitem" - *(int *)(gpGlobals + 0x98);
    }
    fVar1 = (float)param_1[200];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      param_1[200] = 0x42700000;
    }
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,param_1 + 0xa0,param_1 + 0xa3);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    param_1[5] = -0x10000;
    param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
    StartItem__11CTFGoalItem(param_1);
  }
  return;
}


// Spawn__11CTestEffect  @ 000a3cf0
void Spawn__11CTestEffect(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x454) + 0x10))(param_1);
  return;
}


// Spawn__11CWallHealth  @ 000b5800
void Spawn__11CWallHealth(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[0x140] = (int)ROUND(DAT_001a1d20);
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


// Spawn__12CAutoTrigger  @ 00119e40
void Spawn__12CAutoTrigger(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x454) + 0x10))(param_1);
  return;
}


// Spawn__12CChangeLevel  @ 001157a0
void Spawn__12CChangeLevel(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  iVar2 = strcmp((char *)(param_1 + 0x13e),"");
  if (iVar2 == 0) {
    (*DAT_0019f794)(1,"a trigger_changelevel doesn\'t have a map");
  }
  iVar2 = strcmp((char *)(param_1 + 0x146),"");
  if (iVar2 == 0) {
    (*DAT_0019f794)(1,"trigger_changelevel to %s doesn\'t have a landmark",param_1 + 0x13e);
  }
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x1cc) != 0) {
    param_1[7] = -0x10000;
    param_1[8] = (int)UseChangeLevel__12CChangeLevelP11CBaseEntityT18USE_TYPEf;
  }
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x58);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar3) {
    SetMovedir__FP9entvars_s(iVar2);
    iVar2 = *param_1;
  }
  *(undefined4 *)(iVar2 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)TouchChangeLevel__12CChangeLevelP11CBaseEntity;
  }
  return;
}


// Spawn__12CCine3Barney  @ 001403b8
void Spawn__12CCine3Barney(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine3-barney.mdl");
  return;
}


// Spawn__12CCineMonster  @ 000eb68c
void Spawn__12CCineMonster(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  iVar1 = *param_1;
  if ((*(int *)(iVar1 + 0x1cc) == 0) || (param_1[0x1a7] != 0)) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__12CCineMonster;
    *(float *)(iVar1 + 0x104) = *gpGlobals + 1.0;
    iVar1 = *param_1;
    if (*(int *)(iVar1 + 0x1cc) != 0) {
      param_1[0x1af] = (int)(*gpGlobals + 1e+06);
    }
  }
  if ((*(byte *)(iVar1 + 0x1a0) & 0x20) == 0) {
    param_1[0x1b3] = 1;
  }
  else {
    param_1[0x1b3] = 0;
  }
  return;
}


// Spawn__12CCinePanther  @ 001406b0
void Spawn__12CCinePanther(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-panther.mdl");
  return;
}


// Spawn__12CCyclerProbe  @ 000b3888
void Spawn__12CCyclerProbe(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0x41800000;
  iVar1 = *param_1;
  local_1c = 0xc1800000;
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 16.0;
  local_18 = local_1c;
  local_14 = local_1c;
  local_c = local_10;
  local_8 = local_10;
  GenericCyclerSpawn__7CCyclerPcG6VectorT2(param_1,"models/prdroid.mdl",&local_1c,&local_10);
  return;
}


// Spawn__12CEnvBeverage  @ 000a30b8
void Spawn__12CEnvBeverage(int *param_1)

{
  float fVar1;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  *(undefined4 *)(*param_1 + 0x164) = 0;
  fVar1 = *(float *)(*param_1 + 0x160);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x160) = 0x41200000;
  }
  return;
}


// Spawn__12CFuncPlatRot  @ 000d286c
void Spawn__12CFuncPlatRot(int *param_1)

{
  int iVar1;
  
  Setup__9CFuncPlat(param_1);
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1cc) == 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,param_1 + 0x127);
    param_1[0x11d] = 1;
  }
  else {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,param_1 + 0x124);
    param_1[0x11d] = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)PlatUse__9CFuncPlatP11CBaseEntityT18USE_TYPEf;
  }
  SetupRotation__12CFuncPlatRot(param_1);
  return;
}


// Spawn__12CHandGrenade  @ 000b5144
void Spawn__12CHandGrenade(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 0xc;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_grenade.mdl");
  *(undefined4 *)(*param_1 + 0x1e0) = DAT_001a1cfc;
  param_1[0x133] = 5;
  FallInit__15CBasePlayerItem(param_1);
  return;
}


// Spawn__12CItemBattery  @ 00141950
void Spawn__12CItemBattery(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_battery.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__12CItemPowerup  @ 000fd06c
void Spawn__12CItemPowerup(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__5CItem(param_1);
    local_10 = 0x41800000;
    local_1c = 0xc1800000;
    local_14 = 0;
    local_18 = local_1c;
    local_c = local_10;
    local_8 = local_10;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  }
  return;
}


// Spawn__12CMultiSource  @ 0008d188
void Spawn__12CMultiSource(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
  param_1[3] = -0x10000;
  param_1[4] = (int)Register__12CMultiSource;
  return;
}


// Spawn__12CNoBuildArea  @ 000a6c64
void Spawn__12CNoBuildArea(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__12CPointEntity  @ 000f69b4
void Spawn__12CPointEntity(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  return;
}


// Spawn__12CTFAutoRifle  @ 0012ae4c
void Spawn__12CTFAutoRifle(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_autorifle" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 6;
  param_1[0x133] = 5;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__12CTFDispenser  @ 0009ad3c
void Spawn__12CTFDispenser(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(int *)*param_1 = (int)"building_dispenser" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  local_8 = 0x41000000;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  iVar1 = *param_1;
  local_10 = 0;
  local_c = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41000000;
  *(undefined4 *)(*param_1 + 0x1b0) = 0x43160000;
  *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/dispenser.mdl");
  local_10 = 0x41800000;
  local_8 = 0x41c00000;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__12CTFRpgRocket  @ 001038e4
void Spawn__12CTFRpgRocket(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 9;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  param_1[0x1a8] = 1;
  param_1[0x1a9] = 1;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/rpgrocket.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_rpg_rocket" - (int)gpGlobals[0x26];
  param_1[0xfe] = (int)"rocket" - (int)gpGlobals[0x26];
  *(float *)(*param_1 + 0x50) = *(float *)(*param_1 + 0x50) - 30.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  *(float *)(*param_1 + 0x50) = -(*(float *)(*param_1 + 0x50) + 30.0);
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  iVar3 = *param_1;
  fVar1 = gpGlobals[0xb];
  fVar2 = gpGlobals[0xc];
  *(float *)(iVar3 + 0x20) = gpGlobals[10] * 900.0;
  *(float *)(iVar3 + 0x24) = fVar1 * 900.0;
  *(float *)(iVar3 + 0x28) = fVar2 * 900.0;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 5.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__12CTFSentrygun  @ 000ec0a0
void Spawn__12CTFSentrygun(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(int *)*param_1 = (int)FUN_00151e74 - (int)gpGlobals[0x26];
  *(undefined4 *)(*param_1 + 0x160) = 0x43160000;
  *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  *(undefined4 *)(*param_1 + 0x108) = 5;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  local_8 = 0x41b00000;
  *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
  iVar1 = *param_1;
  local_10 = 0;
  local_c = 0;
  *(undefined4 *)(iVar1 + 0x174) = 0;
  *(undefined4 *)(iVar1 + 0x178) = 0;
  *(undefined4 *)(iVar1 + 0x17c) = 0x41b00000;
  param_1[0xfe] = (int)"sentrygun" - (int)gpGlobals[0x26];
  param_1[0x23] = 1;
  param_1[0x28] = 0x2d;
  param_1[0x29] = 0x13b;
  param_1[0x1aa] = 6;
  param_1[0x1b2] = g_vecZero;
  param_1[0x1b3] = DAT_0019f664;
  param_1[0x1b4] = DAT_0019f668;
  param_1[0x33] = 0x19;
  param_1[0x30] = 100;
  param_1[0x38] = 0x14;
  param_1[0x157] = 0x3f333333;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/sentry1.mdl");
  local_10 = 0x41800000;
  local_8 = 0x42400000;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x13f,0);
  param_1[3] = -0x10000;
  param_1[4] = (int)SentryRotate__12CTFSentrygun;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  return;
}


// Spawn__12CTFTimerGoal  @ 0010b2ec
void Spawn__12CTFTimerGoal(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uStack_24;
  char *pcStack_20;
  int *piStack_1c;
  
  piStack_1c = (int *)0x10b2fa;
  iVar2 = param_1[0xbe];
  if ((((iVar2 != -1) || (puVar4 = (undefined4 *)&stack0xffffffe8, -1 < g_iSkillLevel)) &&
      ((iVar3 = param_1[0xbf], iVar3 != -1 ||
       (puVar4 = (undefined4 *)&stack0xffffffe8, g_iSkillLevel < 1)))) &&
     (((iVar2 + 1U < 2 || (puVar4 = (undefined4 *)&stack0xffffffe8, iVar2 <= g_iSkillLevel)) &&
      (puVar4 = (undefined4 *)&stack0xffffffe8, iVar3 + 1U < 2 || g_iSkillLevel <= iVar3)))) {
    piStack_1c = param_1;
    pcStack_20 = (char *)0x10b37a;
    Spawn__7CTFGoal();
    *(char **)*param_1 = "Ainfo_tfgoal_timer" + (1 - *(int *)(gpGlobals + 0x98));
    fVar1 = (float)param_1[0x95];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      *(undefined4 *)(*param_1 + 0x10c) = 0;
      return;
    }
    piStack_1c = (int *)(*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    pcStack_20 = "Timer Goal %s created with no specified time.\n";
    puVar4 = &uStack_24;
    uStack_24 = 1;
    (*DAT_0019f794)();
  }
  *(int **)((int)puVar4 + -4) = param_1;
  *(undefined4 *)((int)puVar4 + -8) = 0x10b3db;
  dremove__FP11CBaseEntity();
  return;
}


// Spawn__12CTriggerHurt  @ 00114b60
void Spawn__12CTriggerHurt(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  iVar2 = *param_1;
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x58);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar3) {
    SetMovedir__FP9entvars_s(iVar2);
    iVar2 = *param_1;
  }
  *(undefined4 *)(iVar2 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  param_1[5] = -0x10000;
  param_1[6] = (int)HurtTouch__12CBaseTriggerP11CBaseEntity;
  if (*(int *)(*param_1 + 0x1cc) == 0) {
    param_1[7] = 0;
    param_1[8] = 0;
  }
  else {
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  }
  if ((*(byte *)((int)param_1 + 0x4f2) & 4) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)RadiationThink__12CTriggerHurt;
    lVar4 = (longdouble)(*DAT_0019f80c)(0,0x3f000000);
    *(float *)(*param_1 + 0x104) = (float)(lVar4 + (longdouble)*gpGlobals);
  }
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 2) != 0) {
    *(undefined4 *)(iVar2 + 0x10c) = 0;
    iVar2 = *param_1;
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar2,iVar2 + 8);
  return;
}


// Spawn__12CTriggerOnce  @ 00118e78
void Spawn__12CTriggerOnce(int param_1)

{
  *(undefined4 *)(param_1 + 0x480) = 0xbf800000;
  Spawn__16CTriggerMultiple(param_1);
  return;
}


// Spawn__12CTriggerPush  @ 00116498
void Spawn__12CTriggerPush(int *param_1)

{
  float fVar1;
  longdouble lVar2;
  int iVar3;
  bool bVar4;
  longdouble lVar5;
  
  iVar3 = *param_1;
  bVar4 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar3 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar3 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar3 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar3 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar3 + 0x58);
    bVar4 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar4) {
    *(undefined4 *)(iVar3 + 0x54) = 0x43b40000;
    iVar3 = *param_1;
  }
  bVar4 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar3 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar3 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar3 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar3 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar3 + 0x58);
    bVar4 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar4) {
    SetMovedir__FP9entvars_s(iVar3);
    iVar3 = *param_1;
  }
  *(undefined4 *)(iVar3 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  lVar5 = (longdouble)(*DAT_0019f784)("showtriggers");
  lVar2 = (longdouble)0;
  if ((byte)((byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar5)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar2 == lVar5) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  iVar3 = *param_1;
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)*(float *)(iVar3 + 0x1f8)) || NAN(lVar2)) <<
                            10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)*(float *)(iVar3 + 0x1f8) == lVar2) << 0xe) >> 8))
      == 0x40) {
    *(undefined4 *)(iVar3 + 0x1f8) = 0x42c80000;
    iVar3 = *param_1;
  }
  if ((*(byte *)(iVar3 + 0x1a0) & 2) != 0) {
    *(undefined4 *)(iVar3 + 0x10c) = 0;
  }
  param_1[7] = -0x10000;
  param_1[8] = (int)ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__12CTriggerSave  @ 00116ad8
void Spawn__12CTriggerSave(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  fVar1 = *(float *)(gpGlobals + 0x14);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    iVar2 = *param_1;
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
         0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
        0x40)) {
      fVar1 = *(float *)(iVar2 + 0x58);
      bVar3 = (byte)(DAT_0019f668 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar3) {
      SetMovedir__FP9entvars_s(iVar2);
      iVar2 = *param_1;
    }
    *(undefined4 *)(iVar2 + 0x10c) = 1;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                    *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
    if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    }
    param_1[5] = -0x10000;
    param_1[6] = (int)SaveTouch__12CTriggerSaveP11CBaseEntity;
  }
  else {
    (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


// Spawn__12CXenSporeMed  @ 00128fac
void Spawn__12CXenSporeMed(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0x110) = 1;
  Spawn__9CXenSpore(param_1);
  local_10 = 0x42200000;
  local_8 = 0x42f00000;
  local_1c = 0xc2200000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__13CButtonTarget  @ 0008c2a0
void Spawn__13CButtonTarget(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
  }
  return;
}


// Spawn__13CCyclerSprite  @ 000b4250
void Spawn__13CCyclerSprite(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x116] = 1;
  param_1[0x117] = (int)*gpGlobals;
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  iVar1 = (*DAT_0019f6b0)(*(undefined4 *)(*param_1 + 0xb4));
  param_1[0x118] = (int)((float)iVar1 - 1.0);
  return;
}


// Spawn__13CEnvExplosion  @ 000a75b8
void Spawn__13CEnvExplosion(int *param_1)

{
  float fVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  fVar1 = (float)(param_1[0x1a7] + -0x32) * 0.6;
  if (fVar1 < 10.0) {
    fVar1 = 10.0;
  }
  param_1[0x1a8] = (int)ROUND(fVar1);
  return;
}


// Spawn__13CFuncConveyor  @ 00087d38
void Spawn__13CFuncConveyor(int *param_1)

{
  int iVar1;
  
  SetMovedir__FP9entvars_s(*param_1);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 2;
  iVar1 = *param_1;
  if (((*(byte *)(iVar1 + 0x1a0) ^ 1) & 1) != 0) {
    *(byte *)(iVar1 + 0x1a4) = *(byte *)(iVar1 + 0x1a4) | 4;
    iVar1 = *param_1;
  }
  if ((*(byte *)(iVar1 + 0x1a0) & 2) != 0) {
    *(undefined4 *)(iVar1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x110) = 0;
    iVar1 = *param_1;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar1 + 0x1f8) = 0x42c80000;
    iVar1 = *param_1;
  }
  UpdateSpeed__13CFuncConveyorf(param_1,*(undefined4 *)(iVar1 + 0x1f8));
  return;
}


// Spawn__13CFuncRotating  @ 00087fcc
void Spawn__13CFuncRotating(int *param_1)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  param_1[0x119] = 0x42c60000;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x118]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x118] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x118] = 0x3f800000;
  }
  param_1[0x117] = 0x3f4ccccd;
  if (*(char *)(*param_1 + 0x1a0) < '\0') {
    param_1[0x117] = 0x40000000;
  }
  else {
    uVar2 = *(uint *)(*param_1 + 0x1a0);
    if ((uVar2 & 0x100) == 0) {
      if ((uVar2 & 0x200) != 0) {
        param_1[0x117] = 0x3f4ccccd;
      }
    }
    else {
      param_1[0x117] = 0x3fa00000;
    }
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x116]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x116] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x116] = 0x3f800000;
  }
  iVar4 = *param_1;
  if ((*(uint *)(iVar4 + 0x1a0) & 4) == 0) {
    if ((*(uint *)(iVar4 + 0x1a0) & 8) == 0) {
      uVar3 = 0;
      local_c = 0x3f800000;
    }
    else {
      uVar3 = 0x3f800000;
      local_c = 0;
    }
    local_8 = 0;
  }
  else {
    uVar3 = 0;
    local_c = 0;
    local_8 = 0x3f800000;
  }
  *(undefined4 *)(iVar4 + 0x44) = uVar3;
  *(undefined4 *)(iVar4 + 0x48) = local_c;
  *(undefined4 *)(iVar4 + 0x4c) = local_8;
  iVar4 = *param_1;
  if ((*(byte *)(iVar4 + 0x1a0) & 2) != 0) {
    *(float *)(iVar4 + 0x44) = -*(float *)(iVar4 + 0x44);
    *(float *)(iVar4 + 0x48) = -*(float *)(iVar4 + 0x48);
    *(float *)(iVar4 + 0x4c) = -*(float *)(iVar4 + 0x4c);
    iVar4 = *param_1;
  }
  if ((*(byte *)(iVar4 + 0x1a0) & 0x40) == 0) {
    *(undefined4 *)(iVar4 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(iVar4 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x110) = 0xffffffff;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[7] = -0x10000;
  param_1[8] = (int)RotatingUse__13CFuncRotatingP11CBaseEntityT18USE_TYPEf;
  iVar4 = *param_1;
  fVar1 = *(float *)(iVar4 + 0x1f8);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(iVar4 + 0x1f8) = 0;
    iVar4 = *param_1;
  }
  if ((*(byte *)(iVar4 + 0x1a0) & 1) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_CallUseToggle__11CBaseEntity;
    *(float *)(iVar4 + 0x104) = *(float *)(iVar4 + 0x100) + 1.5;
    iVar4 = *param_1;
  }
  if ((*(byte *)(iVar4 + 0x1a0) & 0x20) != 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)HurtTouch__13CFuncRotatingP11CBaseEntity;
  }
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  return;
}


// Spawn__13CItemAntidote  @ 001416cc
void Spawn__13CItemAntidote(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_antidote.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CItemArmorRed  @ 000fd79c
void Spawn__13CItemArmorRed(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/r_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0x117] = 0x43480000;
    param_1[0x118] = 0x3f4ccccd;
  }
  return;
}


// Spawn__13CItemLongJump  @ 001414b0
void Spawn__13CItemLongJump(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_longjump.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CItemSecurity  @ 001415ac
void Spawn__13CItemSecurity(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_security.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CMultiManager  @ 00114408
void Spawn__13CMultiManager(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  int local_14;
  int local_8;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf;
  param_1[3] = -0x10000;
  param_1[4] = (int)ManagerThink__13CMultiManager;
  local_14 = param_1[0x13e];
  do {
    bVar3 = false;
    local_8 = 1;
    if (1 < local_14) {
      do {
        fVar1 = (float)param_1[local_8 + 0x151];
        if (fVar1 < (float)param_1[local_8 + 0x150]) {
          iVar2 = param_1[local_8 + 0x141];
          bVar3 = true;
          param_1[local_8 + 0x141] = param_1[local_8 + 0x140];
          param_1[local_8 + 0x151] = param_1[local_8 + 0x150];
          param_1[local_8 + 0x140] = iVar2;
          param_1[local_8 + 0x150] = (int)fVar1;
          local_14 = param_1[0x13e];
        }
        local_8 = local_8 + 1;
      } while (local_8 < local_14);
    }
  } while (bVar3);
  return;
}


// Spawn__13CTriggerRelay  @ 00119bdc
void Spawn__13CTriggerRelay(void)

{
  return;
}


// Spawn__13CWeaponCycler  @ 000b3918
void Spawn__13CWeaponCycler(int *param_1)

{
  int iVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  param_1[0x134] = *(int *)(iVar1 + 0xb8);
  param_1[0x135] = *(int *)(iVar1 + 0xb4);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,iVar1 + 8);
  local_10 = 0x41800000;
  uStack_1c = 0xc1800000;
  uStack_14 = 0;
  uStack_18 = uStack_1c;
  uStack_c = local_10;
  uStack_8 = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_1c,&local_10);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CBaseSpectator  @ 000f349c
void Spawn__14CBaseSpectator(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x1a4) = 0x4000000;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 8;
  param_1[1] = 0;
  return;
}


// Spawn__14CCineScientist  @ 001407e0
void Spawn__14CCineScientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-scientist.mdl");
  return;
}


// Spawn__14CGenericCycler  @ 00140d28
void Spawn__14CGenericCycler(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0xc1800000;
  local_8 = 0;
  local_1c = 0x41800000;
  local_14 = 0x42900000;
  local_18 = local_1c;
  local_c = local_10;
  GenericCyclerSpawn__7CCyclerPcG6VectorT2
            (param_1,*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98),&local_10,&local_1c);
  return;
}


// Spawn__14CItemAmmoCells  @ 000fd180
void Spawn__14CItemAmmoCells(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0x117] = (int)("?models/w_battery.mdl" + (1 - *(int *)(gpGlobals + 0x98)));
    param_1[0x118] = (int)("?models/w_battery.mdl" + (1 - *(int *)(gpGlobals + 0x98)));
    *(int *)(*param_1 + 0x1d0) = (int)"cells" - *(int *)(gpGlobals + 0x98);
    param_1[0x37] = 5;
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__14CItemAmmoNails  @ 000fd430
void Spawn__14CItemAmmoNails(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0x117] = (int)"models/w_crossbow_clip.mdl" - *(int *)(gpGlobals + 0x98);
    param_1[0x118] = (int)"models/w_crossbow_clip.mdl" - *(int *)(gpGlobals + 0x98);
    *(int *)(*param_1 + 0x1d0) = (int)"nails" - *(int *)(gpGlobals + 0x98);
    param_1[0x35] = 0x19;
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__14CMomentaryDoor  @ 0009e8e8
void Spawn__14CMomentaryDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  SetMovedir__FP9entvars_s(*param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar4 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar4 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar4 + 0x1f8) = 0x42c80000;
    iVar4 = *param_1;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar4 + 0x1e0)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x1e0) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar4 + 0x1e0) = 0x40000000;
    iVar4 = *param_1;
  }
  param_1[0x124] = *(int *)(iVar4 + 8);
  param_1[0x125] = *(int *)(iVar4 + 0xc);
  param_1[0x126] = *(int *)(iVar4 + 0x10);
  fVar3 = (ABS((*(float *)(iVar4 + 0xf8) - 2.0) * *(float *)(iVar4 + 0x48)) +
           ABS((*(float *)(iVar4 + 0xf4) - 2.0) * *(float *)(iVar4 + 0x44)) +
          ABS((*(float *)(iVar4 + 0xfc) - 2.0) * *(float *)(iVar4 + 0x4c))) - (float)param_1[0x121];
  fVar1 = *(float *)(iVar4 + 0x48);
  fVar2 = *(float *)(iVar4 + 0x4c);
  param_1[0x127] = (int)(fVar3 * *(float *)(iVar4 + 0x44) + (float)param_1[0x124]);
  param_1[0x128] = (int)(fVar3 * fVar1 + (float)param_1[0x125]);
  param_1[0x129] = (int)(fVar3 * fVar2 + (float)param_1[0x126]);
  if ((*(byte *)(iVar4 + 0x1a0) & 1) != 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar4,param_1 + 0x127);
    param_1[0x127] = param_1[0x124];
    param_1[0x128] = param_1[0x125];
    param_1[0x129] = param_1[0x126];
    iVar4 = *param_1;
    param_1[0x124] = *(int *)(iVar4 + 8);
    param_1[0x125] = *(int *)(iVar4 + 0xc);
    param_1[0x126] = *(int *)(iVar4 + 0x10);
  }
  param_1[5] = 0;
  param_1[6] = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  return;
}


// Spawn__14CNoGrenadeArea  @ 00111818
void Spawn__14CNoGrenadeArea(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__14CTFIncendiaryC  @ 0012ed90
void Spawn__14CTFIncendiaryC(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 8;
  param_1[0x2c] = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_rpg.mdl");
  param_1[0x133] = 0x32;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CTFNailgunNail  @ 00102de8
void Spawn__14CTFNailgunNail(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 9;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/rpgrocket.mdl");
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_1c,&uStack_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_nailgun_nail" - (int)gpGlobals[0x26];
  param_1[0xfe] = (int)"nails" - (int)gpGlobals[0x26];
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  iVar3 = *param_1;
  fVar1 = gpGlobals[0xb];
  fVar2 = gpGlobals[0xc];
  *(float *)(iVar3 + 0x20) = gpGlobals[10] * 1000.0;
  *(float *)(iVar3 + 0x24) = fVar1 * 1000.0;
  *(float *)(iVar3 + 0x28) = fVar2 * 1000.0;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 6.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__14CTFSniperRifle  @ 00132284
void Spawn__14CTFSniperRifle(int *param_1)

{
  param_1[0x128] = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 6;
  param_1[0x133] = 5;
  param_1[0x129] = -0x40800000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CTargetCDAudio  @ 00119108
void Spawn__14CTargetCDAudio(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  if (0.0 < *(float *)(*param_1 + 0x144)) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  }
  return;
}


// Spawn__14CTelefragDeath  @ 00117940
void Spawn__14CTelefragDeath(int *param_1)

{
  int iVar1;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_1c = 0x41800000;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  local_14 = 0x42100000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
  local_28 = 0x40800000;
  local_10 = 0x41a00000;
  local_8 = 0x42200000;
  local_34 = 0xc1a00000;
  local_2c = 0xc2200000;
  local_30 = local_34;
  local_24 = local_28;
  local_20 = local_28;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_34,&local_10);
  param_1[5] = -0x10000;
  param_1[6] = (int)DeathTouch__14CTelefragDeathP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  return;
}


// Spawn__14CTriggerCamera  @ 00117d68
void Spawn__14CTriggerCamera(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x108) = 8;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 2;
  param_1[0x123] = *(int *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x124]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x124] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x124] = 0x43fa0000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x125]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x125] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x125] = 0x43fa0000;
  }
  return;
}


// Spawn__14CTriggerVolume  @ 00118be8
void Spawn__14CTriggerVolume(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xb8) = 0;
  *(undefined4 *)(*param_1 + 0xb4) = 0;
  return;
}


// Spawn__14CXenSporeLarge  @ 00128b64
void Spawn__14CXenSporeLarge(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  *(undefined4 *)(*param_1 + 0x110) = 2;
  Spawn__9CXenSpore(param_1);
  fStack_10 = 48.0;
  fStack_8 = 240.0;
  fStack_1c = -48.0;
  fStack_14 = 110.0;
  fStack_18 = fStack_1c;
  fStack_c = fStack_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&fStack_1c,&fStack_10);
  (*DAT_0019f6f0)(*param_1 + 0x50,&fStack_1c,&fStack_10,0);
  uVar3 = 0;
  do {
    uStack_28 = 0xc1400000;
    uStack_20 = 0;
    uStack_34 = 0x41400000;
    uStack_2c = 0x42f00000;
    fStack_44 = (float)(&_14CXenSporeLarge_m_hullSizes)[uVar3 * 3];
    fStack_4c = fStack_1c * fStack_44;
    fStack_48 = fStack_18 * fStack_44;
    fStack_44 = fStack_44 * fStack_14;
    fStack_50 = (float)(&DAT_001ad544)[uVar3 * 3];
    fStack_58 = fStack_10 * fStack_50;
    fStack_40 = fStack_4c + fStack_58;
    fStack_54 = fStack_c * fStack_50;
    fStack_3c = fStack_48 + fStack_54;
    fStack_50 = fStack_50 * fStack_8;
    fStack_38 = fStack_44 + fStack_50;
    uStack_30 = uStack_34;
    uStack_24 = uStack_28;
    piVar2 = (int *)GetClassPtr__H1Z8CXenHull_PX01_PX01(0);
    iVar1 = *param_1;
    fStack_64 = *(float *)(iVar1 + 8) + fStack_40;
    fStack_60 = *(float *)(iVar1 + 0xc) + fStack_3c;
    fStack_5c = *(float *)(iVar1 + 0x10) + fStack_38;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,&fStack_64);
    (*DAT_0019f6a8)(*(undefined4 *)(*piVar2 + 0x208),
                    *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    *(undefined4 *)(*piVar2 + 0x10c) = 2;
    *(char **)*piVar2 = "Bxen_hull" + (1 - *(int *)(gpGlobals + 0x98));
    *(undefined4 *)(*piVar2 + 0x108) = 0;
    *(undefined4 *)(*piVar2 + 0x198) = *(undefined4 *)(*param_1 + 0x208);
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*piVar2,&uStack_28,&uStack_34);
    *(undefined4 *)(*piVar2 + 0x14c) = 0;
    uVar3 = uVar3 + 1;
    *(undefined4 *)(*piVar2 + 0x148) = 2;
  } while (uVar3 < 5);
  return;
}


// Spawn__14CXenSporeSmall  @ 0012901c
void Spawn__14CXenSporeSmall(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0x110) = 0;
  Spawn__9CXenSpore(param_1);
  local_10 = 0x41800000;
  local_8 = 0x42800000;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__15CAmbientGeneric  @ 000ef1f0
void Spawn__15CAmbientGeneric(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(*param_1 + 0x1a0);
  if ((uVar5 & 1) == 0) {
    if ((uVar5 & 2) == 0) {
      if (((uVar5 & 4) == 0) && ((uVar5 & 8) != 0)) {
        param_1[0x116] = 0x3f4ccccd;
      }
      else {
        param_1[0x116] = 0x3fa00000;
      }
    }
    else {
      param_1[0x116] = 0x40000000;
    }
  }
  else {
    param_1[0x116] = 0;
  }
  iVar1 = *param_1;
  puVar4 = (uint *)(*(int *)(iVar1 + 0x1d4) + (int)gpGlobals[0x26]);
  if (*(int *)(iVar1 + 0x1d4) == 0) goto LAB_000ef2af;
  uVar5 = (uint)puVar4 & 3;
  puVar2 = puVar4;
  if (uVar5 == 0) {
LAB_000ef289:
    do {
      puVar3 = puVar2;
      uVar5 = *puVar3;
      if ((char)uVar5 == '\0') goto LAB_000ef2ab;
      if ((char)(uVar5 >> 8) == '\0') goto LAB_000ef2aa;
      if ((uVar5 & 0xff0000) == 0) goto LAB_000ef2a9;
      puVar2 = puVar3 + 1;
    } while ((uVar5 & 0xff000000) != 0);
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_000ef2a9:
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_000ef2aa:
    puVar3 = (uint *)((int)puVar3 + 1);
  }
  else {
    puVar3 = puVar4;
    if ((POPCOUNT(uVar5) & 1U) == 0) {
LAB_000ef284:
      if ((char)*puVar3 != '\0') {
        puVar2 = (uint *)((int)puVar3 + 1);
        goto LAB_000ef289;
      }
    }
    else if (uVar5 == 2) {
LAB_000ef27f:
      if ((char)*puVar3 != '\0') {
        puVar3 = (uint *)((int)puVar3 + 1);
        goto LAB_000ef284;
      }
    }
    else if ((char)*puVar4 != '\0') {
      puVar3 = (uint *)((int)puVar4 + 1);
      goto LAB_000ef27f;
    }
  }
LAB_000ef2ab:
  if (puVar3 != puVar4) {
    *(undefined4 *)(iVar1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)RampThink__15CAmbientGeneric;
    *(undefined4 *)(*param_1 + 0x104) = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf;
    param_1[0x130] = 0;
    if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
      param_1[0x131] = 1;
    }
    else {
      param_1[0x131] = 0;
    }
    (**(code **)(param_1[0x115] + 0x10))();
    return;
  }
LAB_000ef2af:
  (*DAT_0019f794)(4,"EMPTY AMBIENT AT: %f, %f, %f\n",(double)*(float *)(iVar1 + 8),
                  (double)*(float *)(iVar1 + 0xc),(double)*(float *)(iVar1 + 0x10));
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__15CBasePlayerAmmo  @ 001253e4
void Spawn__15CBasePlayerAmmo(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0x108) = 6;
  local_10 = 0x41800000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  local_8 = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerAmmoP11CBaseEntity;
  return;
}


// Spawn__15CCine2Scientist  @ 00140748
void Spawn__15CCine2Scientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine2-scientist.mdl");
  return;
}


// Spawn__15CCine3Scientist  @ 00140450
void Spawn__15CCine3Scientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine3-scientist.mdl");
  return;
}


// Spawn__15CFuncTrackTrain  @ 000cfe6c
void Spawn__15CFuncTrackTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x119] = 0x42c80000;
  }
  else {
    param_1[0x119] = (int)fVar1;
  }
  *(undefined4 *)(*param_1 + 0x1f8) = 0;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x24) = DAT_0019f664;
  *(undefined4 *)(iVar2 + 0x28) = DAT_0019f668;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar2 + 100) = DAT_0019f668;
  *(int *)(*param_1 + 0x184) = (int)ROUND((float)param_1[0x119]);
  iVar2 = *param_1;
  param_1[0x11a] = 0x3f800000;
  if (*(int *)(iVar2 + 0x1c8) == 0) {
    (*DAT_0019f794)(1,"FuncTrain with no target");
    iVar2 = *param_1;
  }
  if ((*(byte *)(iVar2 + 0x1a0) & 8) == 0) {
    *(undefined4 *)(iVar2 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(iVar2 + 0x10c) = 0;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar2 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,iVar2 + 0xdc,iVar2 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 8);
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = *param_1;
  param_1[0x11c] = *(int *)(iVar2 + 0xdc);
  param_1[0x11d] = *(int *)(iVar2 + 0xe0);
  param_1[0x11e] = *(int *)(iVar2 + 0xe4);
  param_1[0x11f] = *(int *)(iVar2 + 0xe8);
  param_1[0x120] = *(int *)(iVar2 + 0xec);
  param_1[0x121] = *(int *)(iVar2 + 0xf0);
  param_1[0x121] = (int)((float)param_1[0x121] + 72.0);
  *(byte *)(iVar2 + 0x1a6) = *(byte *)(iVar2 + 0x1a6) & 0xdf;
  *(float *)(*param_1 + 0x104) = *(float *)(iVar2 + 0x100) + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__15CFuncTrackTrain;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  return;
}


// Spawn__15CFuncWallToggle  @ 00089eec
void Spawn__15CFuncWallToggle(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 2;
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    TurnOff__15CFuncWallToggle(param_1);
  }
  return;
}


// Spawn__15CGenericMonster  @ 000b03d4
void Spawn__15CGenericMonster(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = strcmp((char *)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98)),
                 "models/player.mdl");
  if (iVar1 != 0) {
    iVar1 = strcmp((char *)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98)),
                   "models/holo.mdl");
    if (iVar1 != 0) {
      puVar3 = &local_1c;
      local_18 = 0x41800000;
      local_14 = 0x42900000;
      local_c = 0xc1800000;
      local_8 = 0;
      puVar2 = &local_10;
      goto LAB_000b04e1;
    }
  }
  puVar3 = &local_10;
  local_c = 0x41800000;
  local_8 = 0x42100000;
  local_18 = 0xc1800000;
  local_14 = 0xc2100000;
  puVar2 = &local_1c;
LAB_000b04e1:
  local_1c = local_18;
  local_10 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,puVar2,puVar3);
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 4;
  param_1[0x19b] = 0xf7;
  *(undefined4 *)(*param_1 + 0x160) = 0x41000000;
  param_1[0x15d] = 0;
  param_1[0x157] = 0x3f000000;
  (**(code **)(param_1[0x115] + 0x124))(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 4) != 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x16c) = 0;
  }
  return;
}


// Spawn__15CItemAmmoShells  @ 000fd588
void Spawn__15CItemAmmoShells(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0x117] = (int)"models/w_shotbox.mdl" - *(int *)(gpGlobals + 0x98);
    param_1[0x118] = (int)"models/w_shotbox.mdl" - *(int *)(gpGlobals + 0x98);
    *(int *)(*param_1 + 0x1d0) = (int)"shells" - *(int *)(gpGlobals + 0x98);
    param_1[0x33] = 0x14;
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__15CItemArmorGreen  @ 000fda24
void Spawn__15CItemArmorGreen(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/g_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0x117] = 0x42c80000;
    param_1[0x118] = 0x3e99999a;
  }
  return;
}


// Spawn__15CTFFlamethrower  @ 0012da34
void Spawn__15CTFFlamethrower(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 10;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_egon.mdl");
  param_1[0x133] = 0x32;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__15CTFPrimeGrenade  @ 00101bb8
void Spawn__15CTFPrimeGrenade(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (**(code **)(param_1[0x115] + 0x228))(param_1);
  (**(code **)(param_1[0x115] + 0x238))(param_1);
  (**(code **)(param_1[0x115] + 0x23c))(param_1);
  (**(code **)(param_1[0x115] + 0x240))(param_1);
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  param_1[0x1a8] = 0;
  param_1[0x1a9] = 1;
  param_1[0x1ac] = 0;
  param_1[0x1ab] = 0;
  param_1[0x1aa] = 0;
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_00101c8e;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_00101c8e:
  param_1[0x48] = *(int *)(iVar1 + 0x120);
  return;
}


// Spawn__15CTFSuperShotgun  @ 00131134
void Spawn__15CTFSuperShotgun(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 8;
  param_1[0x2c] = 0;
  param_1[0x133] = 8;
  param_1[0x136] = 8;
  param_1[0x135] = 1;
  param_1[0x127] = 0x3e800000;
  param_1[0x126] = 0x447a0000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[0x133] = 0x10;
  param_1[0x136] = 0x10;
  param_1[0x135] = 2;
  param_1[0x127] = 0x3ec00000;
  return;
}


// Spawn__15CTriggerCDAudio  @ 001149b4
void Spawn__15CTriggerCDAudio(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  iVar2 = *param_1;
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x58);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar3) {
    SetMovedir__FP9entvars_s(iVar2);
    iVar2 = *param_1;
  }
  *(undefined4 *)(iVar2 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  return;
}


// Spawn__15CTriggerCounter  @ 00118cf0
void Spawn__15CTriggerCounter(int param_1)

{
  *(undefined4 *)(param_1 + 0x480) = 0xbf800000;
  if (*(int *)(param_1 + 0x4c0) == 0) {
    *(undefined4 *)(param_1 + 0x4c0) = 2;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0xffff0000;
  *(code **)(param_1 + 0x20) = CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  return;
}


// Spawn__15CTriggerGravity  @ 00116d80
void Spawn__15CTriggerGravity(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  iVar2 = *param_1;
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x58);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar3) {
    SetMovedir__FP9entvars_s(iVar2);
    iVar2 = *param_1;
  }
  *(undefined4 *)(iVar2 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  param_1[5] = -0x10000;
  param_1[6] = (int)GravityTouch__15CTriggerGravityP11CBaseEntity;
  return;
}


// Spawn__16CFuncIllusionary  @ 00089a64
void Spawn__16CFuncIllusionary(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Spawn__16CFuncMonsterClip  @ 00089908
void Spawn__16CFuncMonsterClip(int *param_1)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 2;
  lVar2 = (longdouble)(*DAT_0019f784)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar2) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x118) = 0x80;
  }
  *(byte *)(*param_1 + 0x1a6) = *(byte *)(*param_1 + 0x1a6) | 0x80;
  return;
}


// Spawn__16CFuncMortarField  @ 000c3f8c
void Spawn__16CFuncMortarField(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  param_1[7] = -0x10000;
  param_1[8] = (int)FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  return;
}


// Spawn__16CFuncTrackChange  @ 000d03d8
void Spawn__16CFuncTrackChange(int *param_1)

{
  int iVar1;
  
  Setup__9CFuncPlat(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 0x10) != 0) {
    param_1[0x129] = *(int *)(*param_1 + 0x10);
  }
  SetupRotation__12CFuncPlatRot(param_1);
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x1a0) & 8) == 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,param_1 + 0x124);
    param_1[0x11d] = 0;
    iVar1 = *param_1;
    *(int *)(iVar1 + 0x50) = param_1[0x140];
    *(int *)(iVar1 + 0x54) = param_1[0x141];
    *(int *)(iVar1 + 0x58) = param_1[0x142];
    param_1[0x14d] = 1;
  }
  else {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,param_1 + 0x127);
    param_1[0x11d] = 1;
    iVar1 = *param_1;
    *(int *)(iVar1 + 0x50) = param_1[0x143];
    *(int *)(iVar1 + 0x54) = param_1[0x144];
    *(int *)(iVar1 + 0x58) = param_1[0x145];
    param_1[0x14d] = 0;
  }
  param_1[0x14e] = 1;
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 2.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__16CFuncTrackChange;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  return;
}


// Spawn__16CItemAmmoRockets  @ 000fd2d8
void Spawn__16CItemAmmoRockets(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0x117] = (int)"models/w_rpgammo.mdl" - *(int *)(gpGlobals + 0x98);
    param_1[0x118] = (int)"models/w_rpgammo.mdl" - *(int *)(gpGlobals + 0x98);
    *(int *)(*param_1 + 0x1d0) = (int)"rockets" - *(int *)(gpGlobals + 0x98);
    param_1[0x39] = 5;
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__16CItemArmorYellow  @ 000fd8e0
void Spawn__16CItemArmorYellow(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/y_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0x117] = 0x43160000;
    param_1[0x118] = 0x3f19999a;
  }
  return;
}


// Spawn__16CItemPowerupQuad  @ 000fcba8
void Spawn__16CItemPowerupQuad(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__5CItem(param_1);
    local_10 = 0x41800000;
    local_1c = 0xc1800000;
    local_14 = 0;
    local_18 = local_1c;
    local_c = local_10;
    local_8 = local_10;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x116]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x116] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x116] = 0x42700000;
  }
  param_1[0x10d] = 0x41f00000;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/quad.mdl");
  *(int *)(*param_1 + 0x1d0) = (int)"Quad Damage" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1e8) = (int)"items/damage.wav" - *(int *)(gpGlobals + 0x98);
  param_1[0x22] = 0x400000;
  return;
}


// Spawn__16CRenderFxManager  @ 00119844
void Spawn__16CRenderFxManager(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  return;
}


// Spawn__16CTFSentrygunBase  @ 000eb904
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__16CTFSentrygunBase(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)*param_1 = (int)"building_sentrygun_base" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  local_8 = 0x41000000;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  iVar1 = *param_1;
  local_10 = 0;
  local_c = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41000000;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/base.mdl");
  local_10 = _FUN_00151e68;
  local_8 = 0x42400000;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__16CTriggerMultiple  @ 00115158
void Spawn__16CTriggerMultiple(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x120]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x120] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x120] = 0x3e4ccccd;
    }
    iVar2 = *param_1;
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
         0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
        0x40)) {
      fVar1 = *(float *)(iVar2 + 0x58);
      bVar3 = (byte)(DAT_0019f668 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar3) {
      SetMovedir__FP9entvars_s(iVar2);
      iVar2 = *param_1;
    }
    *(undefined4 *)(iVar2 + 0x10c) = 1;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                    *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
    if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    }
    param_1[5] = -0x10000;
    param_1[6] = (int)MultiTouch__12CBaseTriggerP11CBaseEntity;
  }
  return;
}


// Spawn__16CTriggerTeleport  @ 001169c8
void Spawn__16CTriggerTeleport(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  iVar2 = *param_1;
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x58);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar3) {
    SetMovedir__FP9entvars_s(iVar2);
    iVar2 = *param_1;
  }
  *(undefined4 *)(iVar2 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  param_1[5] = -0x10000;
  param_1[6] = (int)TeleportTouch__12CBaseTriggerP11CBaseEntity;
  return;
}


// Spawn__17CFrictionModifier  @ 0011a0f4
void Spawn__17CFrictionModifier(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x108) = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)ChangeFriction__17CFrictionModifierP11CBaseEntity;
  return;
}


// Spawn__17CFuncTankControls  @ 000abd10
void Spawn__17CFuncTankControls(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  return;
}


// Spawn__17CInfoIntermission  @ 000e4768
void Spawn__17CInfoIntermission(int *param_1)

{
  int iVar1;
  
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x74) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x78) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x7c) = DAT_0019f668;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 2.0;
  return;
}


// Spawn__17CScriptedSentence  @ 000eae8c
void Spawn__17CScriptedSentence(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  iVar2 = *param_1;
  param_1[0x145] = 1;
  if (*(int *)(iVar2 + 0x1cc) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)FindThink__17CScriptedSentence;
    *(float *)(iVar2 + 0x104) = *gpGlobals + 1.0;
    iVar2 = *param_1;
  }
  switch(*(undefined4 *)(iVar2 + 0x184)) {
  default:
    param_1[0x143] = 0x40000000;
    break;
  case 1:
    param_1[0x143] = 0x3fa00000;
    break;
  case 2:
    param_1[0x143] = 0x3f4ccccd;
    break;
  case 3:
    param_1[0x143] = 0;
  }
  *(undefined4 *)(*param_1 + 0x184) = 0;
  fVar1 = (float)param_1[0x144];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    param_1[0x144] = 0x3f800000;
  }
  return;
}


// Spawn__18CCine2HeavyWeapons  @ 00140580
void Spawn__18CCine2HeavyWeapons(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine2_hvyweapons.mdl");
  return;
}


// Spawn__18CFuncTrainControls  @ 000d1fec
void Spawn__18CFuncTrainControls(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + gpGlobals[0x26]);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__18CFuncTrainControls;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Spawn__18CTFGrenadeLauncher  @ 0012e670
void Spawn__18CTFGrenadeLauncher(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 4;
  param_1[0x134] = 8;
  param_1[0x135] = 10;
  param_1[0x136] = 0;
  param_1[0x137] = 4;
  param_1[0x138] = 5;
  param_1[0x133] = 0x32;
  param_1[0x127] = 0x3f2aaaab;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__18CTriggerEndSection  @ 00116c1c
void Spawn__18CTriggerEndSection(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  fVar1 = *(float *)(gpGlobals + 0x14);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    iVar2 = *param_1;
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
         0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
        0x40)) {
      fVar1 = *(float *)(iVar2 + 0x58);
      bVar3 = (byte)(DAT_0019f668 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar3) {
      SetMovedir__FP9entvars_s(iVar2);
      iVar2 = *param_1;
    }
    *(undefined4 *)(iVar2 + 0x10c) = 1;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                    *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
    if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    }
    param_1[7] = -0x10000;
    param_1[8] = (int)EndSectionUse__18CTriggerEndSectionP11CBaseEntityT18USE_TYPEf;
    if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
      param_1[5] = -0x10000;
      param_1[6] = (int)EndSectionTouch__18CTriggerEndSectionP11CBaseEntity;
    }
  }
  else {
    (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


// Spawn__19CItemPowerupRadsuit  @ 000fc978
void Spawn__19CItemPowerupRadsuit(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__5CItem(param_1);
    local_10 = 0x41800000;
    local_1c = 0xc1800000;
    local_14 = 0;
    local_18 = local_1c;
    local_c = local_10;
    local_8 = local_10;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x116]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x116] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x116] = 0x42700000;
  }
  param_1[0x10e] = 0x41f00000;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_suit.mdl");
  *(int *)(*param_1 + 0x1d0) = (int)"Biosuit" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1e8) = (int)"FVox/HEV_logon.wav" - *(int *)(gpGlobals + 0x98);
  param_1[0x22] = 0x200000;
  return;
}


// Spawn__19CMomentaryRotButton  @ 0008b9e8
void Spawn__19CMomentaryRotButton(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  
  AxisDir__11CBaseToggleP9entvars_s(*param_1);
  iVar7 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar7 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar7 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar7 + 0x1f8) = 0x42c80000;
    iVar7 = *param_1;
  }
  fVar1 = (float)param_1[0x11f];
  if (0.0 <= fVar1) {
    param_1[0x141] = *(int *)(iVar7 + 0x50);
    param_1[0x142] = *(int *)(iVar7 + 0x54);
    param_1[0x143] = *(int *)(iVar7 + 0x58);
    fVar2 = *(float *)(iVar7 + 0x48);
    fVar3 = *(float *)(iVar7 + 0x4c);
    fVar4 = *(float *)(iVar7 + 0x54);
    fVar5 = *(float *)(iVar7 + 0x58);
    param_1[0x144] = (int)(*(float *)(iVar7 + 0x44) * fVar1 + *(float *)(iVar7 + 0x50));
    param_1[0x145] = (int)(fVar2 * fVar1 + fVar4);
    param_1[0x146] = (int)(fVar3 * fVar1 + fVar5);
    param_1[0x13f] = -1;
  }
  else {
    fVar2 = *(float *)(iVar7 + 0x48);
    fVar3 = *(float *)(iVar7 + 0x4c);
    fVar4 = *(float *)(iVar7 + 0x54);
    fVar5 = *(float *)(iVar7 + 0x58);
    param_1[0x141] = (int)(*(float *)(iVar7 + 0x44) * fVar1 + *(float *)(iVar7 + 0x50));
    param_1[0x142] = (int)(fVar2 * fVar1 + fVar4);
    param_1[0x143] = (int)(fVar3 * fVar1 + fVar5);
    param_1[0x144] = *(int *)(iVar7 + 0x50);
    param_1[0x145] = *(int *)(iVar7 + 0x54);
    param_1[0x146] = *(int *)(iVar7 + 0x58);
    param_1[0x13f] = 1;
    param_1[0x11f] = (int)-fVar1;
  }
  iVar7 = *param_1;
  if ((*(byte *)(iVar7 + 0x1a0) & 1) == 0) {
    *(undefined4 *)(iVar7 + 0x10c) = 0;
  }
  else {
    *(undefined4 *)(iVar7 + 0x10c) = 4;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  uVar6 = ButtonSound__Fi(param_1[0x147]);
  (*DAT_0019f6a4)(uVar6);
  uVar6 = (*DAT_0019f7ac)(uVar6);
  *(undefined4 *)(*param_1 + 0x1e8) = uVar6;
  param_1[0x13e] = 0;
  return;
}


// Spawn__19CTFPipebombLauncher  @ 0012e150
void Spawn__19CTFPipebombLauncher(int *param_1)

{
  undefined2 uVar1;
  
  param_1[0x2c] = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 4;
  param_1[0x134] = 8;
  param_1[0x135] = 10;
  param_1[0x136] = 0;
  param_1[0x137] = 4;
  param_1[0x138] = 5;
  param_1[0x133] = 0x32;
  param_1[0x127] = 0x3f2aaaab;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[0x134] = 9;
  param_1[0x135] = 0xb;
  param_1[0x136] = 1;
  param_1[0x137] = 6;
  param_1[0x138] = 7;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_pipel.sc");
  *(undefined2 *)(param_1 + 0x139) = uVar1;
  return;
}


// Spawn__19CTriggerMonsterJump  @ 00114854
void Spawn__19CTriggerMonsterJump(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  longdouble lVar4;
  
  SetMovedir__FP9entvars_s(*param_1);
  iVar2 = *param_1;
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x50))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x54))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x54)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x58);
    bVar3 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar3) {
    SetMovedir__FP9entvars_s(iVar2);
    iVar2 = *param_1;
  }
  *(undefined4 *)(iVar2 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  lVar4 = (longdouble)(*DAT_0019f784)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  *(undefined4 *)(*param_1 + 0x104) = 0;
  *(undefined4 *)(*param_1 + 0x1f8) = 0x43480000;
  param_1[0x131] = 0x43160000;
  if (*(int *)(*param_1 + 0x1cc) != 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  }
  return;
}


// Spawn__20CTFFlamethrowerBurst  @ 0010315c
void Spawn__20CTFFlamethrowerBurst(int *param_1)

{
  int iVar1;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 9;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/rpgrocket.mdl");
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0.0;
  local_18 = 0.0;
  local_14 = 0.0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_flamethrower_burst" - (int)gpGlobals[0x26];
  param_1[0xfe] = (int)"flames" - (int)gpGlobals[0x26];
  *(float *)(*param_1 + 0x50) = *(float *)(*param_1 + 0x50) - 30.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  *(float *)(*param_1 + 0x50) = -(*(float *)(*param_1 + 0x50) + 30.0);
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  iVar1 = *param_1;
  local_1c = gpGlobals[10] * 600.0;
  local_18 = gpGlobals[0xb] * 600.0;
  local_14 = gpGlobals[0xc] * 600.0;
  *(float *)(iVar1 + 0x20) = local_1c;
  *(float *)(iVar1 + 0x24) = local_18;
  *(float *)(iVar1 + 0x28) = local_14;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x198));
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__20CTFIncendiaryCRocket  @ 001034b0
void Spawn__20CTFIncendiaryCRocket(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 9;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/rpgrocket.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_rpg_rocket" - (int)gpGlobals[0x26];
  param_1[0xfe] = (int)"rocket" - (int)gpGlobals[0x26];
  *(float *)(*param_1 + 0x50) = *(float *)(*param_1 + 0x50) - 30.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  *(float *)(*param_1 + 0x50) = -(*(float *)(*param_1 + 0x50) + 30.0);
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  iVar3 = *param_1;
  fVar1 = gpGlobals[0xb];
  fVar2 = gpGlobals[0xc];
  *(float *)(iVar3 + 0x20) = gpGlobals[10] * 600.0;
  *(float *)(iVar3 + 0x24) = fVar1 * 600.0;
  *(float *)(iVar3 + 0x28) = fVar2 * 600.0;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 5.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__20CTriggerChangeTarget  @ 00117f90
void Spawn__20CTriggerChangeTarget(void)

{
  return;
}


// Spawn__22CItemPowerupInvincible  @ 000fc860
void Spawn__22CItemPowerupInvincible(int *param_1)

{
  int iVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__5CItem(param_1);
    uStack_10 = 0x41800000;
    uStack_1c = 0xc1800000;
    uStack_14 = 0;
    uStack_18 = uStack_1c;
    uStack_c = uStack_10;
    uStack_8 = uStack_10;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_1c,&uStack_10);
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x116]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x116] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x116] = 0x43960000;
  }
  param_1[0x10b] = 0x41f00000;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/pent.mdl");
  *(int *)(*param_1 + 0x1d0) = (int)"Pentagram of Protection" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1e8) = (int)"items/protect.wav" - *(int *)(gpGlobals + 0x98);
  param_1[0x22] = 0x100000;
  return;
}


// Spawn__23CDispenserRefillThinker  @ 0009c864
void Spawn__23CDispenserRefillThinker(undefined4 *param_1)

{
  *(char **)*param_1 = "zCtimer" + (2 - *(int *)(gpGlobals + 0x98));
  param_1[0x10a] = 0xe;
  return;
}


// Spawn__24CItemPowerupInvisibility  @ 000fca90
void Spawn__24CItemPowerupInvisibility(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    Spawn__5CItem(param_1);
    local_10 = 0x41800000;
    local_1c = 0xc1800000;
    local_14 = 0;
    local_18 = local_1c;
    local_c = local_10;
    local_8 = local_10;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x116]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x116] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x116] = 0x43960000;
  }
  param_1[0x10c] = 0x41f00000;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/invis.mdl");
  *(int *)(*param_1 + 0x1d0) = (int)"Ring of Shadows" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1e8) = (int)"items/inv1.wav" - *(int *)(gpGlobals + 0x98);
  param_1[0x22] = 0x80000;
  return;
}


// Spawn__4CGibPCc  @ 000962b0
void Spawn__4CGibPCc(int *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f0ccccd;
  *(undefined4 *)(*param_1 + 0x14c) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x148) = 0;
  *(undefined4 *)(*param_1 + 0x15c) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(int *)*param_1 = (int)&DAT_00149414 - (int)gpGlobals[0x26];
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),param_2);
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 4.0;
  param_1[0x119] = 0x41c80000;
  param_1[3] = -0x10000;
  param_1[4] = (int)WaitTillLand__4CGib;
  param_1[5] = -0x10000;
  param_1[6] = (int)BounceGibTouch__4CGibP11CBaseEntity;
  param_1[0x118] = 9;
  param_1[0x117] = 5;
  return;
}


// Spawn__5CBeam  @ 000a5854
void Spawn__5CBeam(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  return;
}


// Spawn__5CFade  @ 000a37d0
void Spawn__5CFade(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


// Spawn__5CGlow  @ 000a1af4
void Spawn__5CGlow(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  iVar2 = (*DAT_0019f6b0)(*(undefined4 *)(*param_1 + 0xb4));
  fVar1 = (float)iVar2 - 1.0;
  param_1[0x117] = (int)fVar1;
  if (0x3f < (byte)((fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) - 1)) {
    fVar1 = *(float *)(*param_1 + 0x138);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    }
  }
  param_1[0x116] = (int)*gpGlobals;
  return;
}


// Spawn__5CItem  @ 000b5c28
void Spawn__5CItem(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity();
  if (iVar1 != 0) {
    *(undefined4 *)(*param_1 + 0x108) = 6;
    *(undefined4 *)(*param_1 + 0x10c) = 1;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    UTIL_SetSize__FP9entvars_sRC6VectorT1();
    param_1[5] = -0x10000;
    param_1[6] = (int)ItemTouch__5CItemP11CBaseEntity;
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x116]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x116] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x116] = 0x41a00000;
    }
    iVar1 = (*DAT_0019f708)();
    if (iVar1 != 0) {
      return;
    }
    param_1 = (int *)*param_1;
    (*DAT_0019f794)(4,"Item %s fell out of level at %f,%f,%f",*param_1 + *(int *)(gpGlobals + 0x98),
                    (double)(float)param_1[2],(double)(float)param_1[3],(double)(float)param_1[4]);
  }
  UTIL_Remove__FP11CBaseEntity();
  return;
}


// Spawn__6CBlood  @ 000a3b2c
void Spawn__6CBlood(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  SetMovedir__FP9entvars_s(*param_1);
  return;
}


// Spawn__6CDecal  @ 00127ffc
void Spawn__6CDecal(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((-1 < *(int *)(iVar2 + 0x110)) &&
     ((fVar1 = (float)gpGlobals[5],
      (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 ||
      ((*(byte *)(iVar2 + 0x1a1) & 8) == 0)))) {
    if (*(int *)(iVar2 + 0x1cc) == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)StaticDecal__6CDecal;
      *(undefined4 *)(iVar2 + 0x104) = *gpGlobals;
      return;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
    param_1[7] = -0x10000;
    param_1[8] = (int)TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf;
    return;
  }
  (*DAT_0019f6f8)(*(undefined4 *)(iVar2 + 0x208));
  return;
}


// Spawn__6CLaser  @ 000a14d8
void Spawn__6CLaser(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  
  if (*(int *)(*param_1 + 0xb8) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    (**(code **)(param_1[0x115] + 0x10))(param_1);
    param_1[3] = -0x10000;
    param_1[4] = (int)StrikeThink__6CLaser;
    *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x20;
    iVar8 = *param_1;
    *(uint *)(iVar8 + 0x148) = *(uint *)(iVar8 + 0x148) & 0xf0;
    iVar5 = *param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar8 + 8);
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
    iVar5 = *param_1;
    *(undefined4 *)(iVar5 + 0x50) = *(undefined4 *)(iVar8 + 8);
    *(undefined4 *)(iVar5 + 0x54) = *(undefined4 *)(iVar8 + 0xc);
    *(undefined4 *)(iVar5 + 0x58) = *(undefined4 *)(iVar8 + 0x10);
    *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xfff;
    *(uint *)(*param_1 + 0x110) = *(uint *)(*param_1 + 0x110) & 0xfff;
    RelinkBeam__5CBeam(param_1);
    if ((param_1[0x116] == 0) && (param_1[0x117] != 0)) {
      iVar8 = SpriteCreate__7CSpritePCcRC6Vectori
                        (param_1[0x117] + *(int *)(gpGlobals + 0x98),*param_1 + 8,1);
      param_1[0x116] = iVar8;
    }
    else {
      param_1[0x116] = 0;
    }
    piVar6 = (int *)param_1[0x116];
    if (piVar6 != (int *)0x0) {
      iVar8 = *param_1;
      fVar1 = *(float *)(iVar8 + 0x150);
      fVar2 = *(float *)(iVar8 + 0x154);
      fVar3 = *(float *)(iVar8 + 0x158);
      fVar4 = *(float *)(iVar8 + 0x14c);
      uVar7 = *(undefined4 *)(iVar8 + 0x15c);
      *(undefined4 *)(*piVar6 + 0x148) = 3;
      *(float *)(*piVar6 + 0x150) = (float)(int)ROUND(fVar1);
      *(float *)(*piVar6 + 0x154) = (float)(int)ROUND(fVar2);
      *(float *)(*piVar6 + 0x158) = (float)(int)ROUND(fVar3);
      *(float *)(*piVar6 + 0x14c) = (float)(int)ROUND(fVar4);
      *(undefined4 *)(*piVar6 + 0x15c) = uVar7;
    }
    if ((*(int *)(*param_1 + 0x1cc) == 0) || (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) == 0)) {
      TurnOn__6CLaser(param_1);
    }
    else {
      TurnOff__6CLaser(param_1);
    }
  }
  return;
}


// Spawn__6CLight  @ 000b698c
void Spawn__6CLight(int *param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1cc) == 0) {
    (*DAT_0019f6f8)(*(undefined4 *)(iVar1 + 0x208));
  }
  else if (0x1f < param_1[0x116]) {
    if ((*(byte *)(iVar1 + 0x1a0) & 1) == 0) {
      if (param_1[0x117] == 0) {
        puVar2 = &DAT_0014cc3f;
      }
      else {
        puVar2 = (undefined *)(param_1[0x117] + *(int *)(gpGlobals + 0x98));
      }
    }
    else {
      puVar2 = &DAT_0014cc3d;
    }
    (*DAT_0019f74c)(param_1[0x116],puVar2);
  }
  return;
}


// Spawn__6CShake  @ 000a394c
void Spawn__6CShake(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    *(undefined4 *)(*param_1 + 0x1e0) = 0;
  }
  return;
}


// Spawn__6CTFAxe  @ 0012d220
void Spawn__6CTFAxe(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 5;
  param_1[0x130] = -1;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__6CTFRpg  @ 001304e4
void Spawn__6CTFRpg(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 8;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_rpg.mdl");
  param_1[0x133] = 0x32;
  param_1[0x127] = 0x3fa00000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__6CWorld  @ 00126e64
void Spawn__6CWorld(int param_1)

{
  char *__src;
  int iVar1;
  int iVar2;
  longdouble lVar3;
  int local_8;
  
  g_fGameOver = 0;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x10))(param_1);
  lVar3 = (longdouble)(*DAT_0019f784)("sv_cheats");
  g_flWeaponCheat = (float)lVar3;
  memset(&g_IpStorage,0,0x100);
  number_of_teams = 0;
  CTF_Map = 0;
  birthday = 0;
  christmas = 0;
  num_world_flames = 0;
  team_menu_string = 0;
  toggleflags = 0;
  g_bFirstClient = 0;
  TeamFortress_TeamSetColor__Fi(0);
  iVar1 = 0;
  do {
    (&teamallies)[iVar1] = 0;
    (&g_pLastSpawns)[iVar1] = 0;
    (&teamadvantage)[iVar1] = 0x3f800000;
    iVar2 = iVar1 + 1;
    (&team_names)[iVar1] = 0;
    iVar1 = iVar2;
  } while (iVar2 < 5);
  local_8 = 0;
  __src = (char *)UTIL_VarArgs__FPce("maps/%s.txt",
                                     *(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98));
  strcpy(maptext_755,__src);
  iVar1 = (*DAT_0019f81c)(maptext_755,&local_8);
  if ((iVar1 != 0) && (local_8 != 0)) {
    (*pcRam0019f860)(maptext_755);
  }
  (*DAT_0019f820)(iVar1);
  return;
}


// Spawn__7CCycler  @ 000b4674
void Spawn__7CCycler(int *param_1)

{
  float fVar1;
  int iVar2;
  
  InitBoneControllers__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x160) = 0x479c4000;
  *(undefined4 *)(*param_1 + 0xb0) = 0x40a00000;
  *(undefined4 *)(*param_1 + 0xac) = *(undefined4 *)(*param_1 + 0x54);
  (**(code **)(param_1[0x115] + 0x118))(param_1,0x168);
  param_1[0x118] = 0x42960000;
  param_1[0x119] = 0;
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x104) + 1.0;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  iVar2 = *param_1;
  if ((*(int *)(iVar2 + 0x128) == 0) &&
     (fVar1 = *(float *)(iVar2 + 0x130),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    param_1[0x1a7] = 1;
  }
  else {
    param_1[0x1a7] = 0;
    *(undefined4 *)(iVar2 + 0x138) = 0;
  }
  return;
}


// Spawn__7CLadder  @ 00118614
void Spawn__7CLadder(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x108) = 7;
  return;
}


// Spawn__7CMortar  @ 000c3e44
void Spawn__7CMortar(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x43480000;
  param_1[3] = -0x10000;
  param_1[4] = (int)MortarExplode__7CMortar;
  *(undefined4 *)(*param_1 + 0x104) = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  return;
}


// Spawn__7CSentry  @ 0011c378
void Spawn__7CSentry(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/sentry.mdl");
  *(undefined4 *)(*param_1 + 0x160) = DAT_001a1cc4;
  local_10 = 0;
  local_8 = 0x42400000;
  local_c = 0;
  param_1[0x1a2] = 0;
  param_1[0x1a3] = 0;
  param_1[0x1a4] = 0x42400000;
  *(undefined4 *)(*param_1 + 0x17c) = 0x42400000;
  param_1[0x1b8] = 0x49742400;
  param_1[0x1a7] = 0x49742400;
  Spawn__11CBaseTurret(param_1);
  param_1[0x1ac] = 0x40;
  param_1[0x1ab] = 0x40;
  param_1[0x1ad] = -0x3c;
  local_10 = 0x41800000;
  local_8 = 0x42800000;
  local_1c = 0xc1800000;
  local_14 = 0xc2800000;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[5] = -0x10000;
  param_1[6] = (int)SentryTouch__7CSentryP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  return;
}


// Spawn__7CShower  @ 000a6e14
void Spawn__7CShower(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar3 = *param_1;
  lVar4 = (longdouble)(*DAT_0019f80c)(0x43480000,0x43960000);
  fVar1 = *(float *)(*param_1 + 0x54);
  fVar2 = *(float *)(*param_1 + 0x58);
  *(float *)(iVar3 + 0x20) = (float)((longdouble)*(float *)(*param_1 + 0x50) * lVar4);
  *(float *)(iVar3 + 0x24) = (float)((longdouble)fVar1 * lVar4);
  *(float *)(iVar3 + 0x28) = (float)(lVar4 * (longdouble)fVar2);
  lVar4 = (longdouble)(*DAT_0019f80c)(0xc2c80000,0x42c80000);
  *(float *)(*param_1 + 0x20) = (float)(lVar4 + (longdouble)*(float *)(*param_1 + 0x20));
  lVar4 = (longdouble)(*DAT_0019f80c)(0xc2c80000,0x42c80000);
  *(float *)(*param_1 + 0x24) = (float)(lVar4 + (longdouble)*(float *)(*param_1 + 0x24));
  fVar1 = *(float *)(*param_1 + 0x28);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    fVar1 = fVar1 - 200.0;
  }
  else {
    fVar1 = fVar1 + 200.0;
  }
  *(float *)(*param_1 + 0x28) = fVar1;
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/grenade.mdl");
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  lVar4 = (longdouble)(*DAT_0019f80c)(0x3f000000,0x3fc00000);
  *(float *)(*param_1 + 0x1f8) = (float)lVar4;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar3 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar3 + 0x58) = DAT_0019f668;
  return;
}


// Spawn__7CSprite  @ 000a1c10
void Spawn__7CSprite(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar2 = (*DAT_0019f6b0)(*(undefined4 *)(*param_1 + 0xb4));
  param_1[0x117] = (int)((float)iVar2 - 1.0);
  if ((*(int *)(*param_1 + 0x1cc) == 0) || (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) == 0)) {
    TurnOn__7CSprite(param_1);
  }
  else {
    TurnOff__7CSprite(param_1);
  }
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x54);
  if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x58)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x58) == 0.0) << 0xe) >> 8)) == 0x40)) {
    *(float *)(iVar2 + 0x58) = fVar1;
    *(undefined4 *)(*param_1 + 0x54) = 0;
  }
  return;
}


// Spawn__7CTFGoal  @ 0010ae3c
void Spawn__7CTFGoal(int *param_1)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = param_1[0xbe];
  if ((((iVar4 == -1) && (g_iSkillLevel < 0)) ||
      ((iVar2 = param_1[0xbf], iVar2 == -1 && (0 < g_iSkillLevel)))) ||
     (((1 < iVar4 + 1U && (g_iSkillLevel < iVar4)) || (1 < iVar2 + 1U && iVar2 < g_iSkillLevel)))) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    *(int *)*param_1 = (int)"info_tfgoal" - *(int *)(gpGlobals + 0x98);
    iVar4 = *param_1;
    if (*(int *)(iVar4 + 0xb8) != 0) {
      pcVar3 = (char *)(*(int *)(iVar4 + 0xb8) + *(int *)(gpGlobals + 0x98));
      if (*pcVar3 == '*') {
        *(byte *)(iVar4 + 0x118) = *(byte *)(iVar4 + 0x118) | 0x80;
      }
      (*g_engfuncs)(pcVar3);
      (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                      *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
      iVar4 = *param_1;
    }
    if (*(int *)(iVar4 + 0x1e8) != 0) {
      (*DAT_0019f6a4)(*(int *)(iVar4 + 0x1e8) + *(int *)(gpGlobals + 0x98));
    }
    (*DAT_0019f6a4)("items/protect.wav");
    (*DAT_0019f6a4)("items/protect2.wav");
    (*DAT_0019f6a4)("items/protect3.wav");
    (*DAT_0019f6a4)("FVox/HEV_logon.wav");
    (*DAT_0019f6a4)("FVox/hev_shutdown.wav");
    (*DAT_0019f6a4)("items/inv1.wav");
    (*DAT_0019f6a4)("items/inv2.wav");
    (*DAT_0019f6a4)("items/inv3.wav");
    (*DAT_0019f6a4)("items/damage.wav");
    (*DAT_0019f6a4)("items/damage2.wav");
    (*DAT_0019f6a4)("items/damage3.wav");
    *(undefined4 *)(*param_1 + 0x10c) = 1;
    if (param_1[0x86] == 0) {
      param_1[0x86] = 2;
    }
    bVar5 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0xa0])) << 10) >> 8) |
               (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0xa0]) << 0xe) >> 8)) == 0x40)
       && ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN((float)param_1[0xa1])) << 10) >>
                        8) |
                 (byte)((ushort)((ushort)(DAT_0019f664 == (float)param_1[0xa1]) << 0xe) >> 8)) ==
           0x40)) {
      fVar1 = (float)param_1[0xa2];
      bVar5 = (byte)(DAT_0019f668 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar5) {
      bVar5 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0xa3])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0xa3]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN((float)param_1[0xa4])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_0019f664 == (float)param_1[0xa4]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa5];
        bVar5 = (byte)(DAT_0019f668 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (!bVar5) {
        UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,param_1 + 0xa0,param_1 + 0xa3);
      }
    }
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    StartGoal__7CTFGoal(param_1);
  }
  return;
}


// Spawn__7CTurret  @ 0011a6a4
void Spawn__7CTurret(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/turret.mdl");
  *(undefined4 *)(*param_1 + 0x160) = DAT_001a1cbc;
  uStack_10 = 0;
  uStack_8 = 0x414c0000;
  uStack_c = 0;
  param_1[0x1a2] = 0;
  param_1[0x1a3] = 0;
  param_1[0x1a4] = 0x414c0000;
  param_1[0x1a7] = 0x40a00000;
  *(undefined4 *)(*param_1 + 0x17c) = 0x414c0000;
  Spawn__11CBaseTurret(param_1);
  uStack_10 = 0x42000000;
  param_1[0x1ac] = 0x10;
  param_1[0x1ab] = 0x20;
  param_1[0x1ad] = -0xf;
  uStack_8 = 0x41800000;
  uStack_1c = 0xc2000000;
  uStack_14 = 0xc1800000;
  uStack_18 = uStack_1c;
  uStack_c = uStack_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_1c,&uStack_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  piVar2 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/flare3.spr",*param_1 + 8,0);
  param_1[0x1a9] = (int)piVar2;
  *(undefined4 *)(*piVar2 + 0x148) = 3;
  *(undefined4 *)(*piVar2 + 0x150) = 0x437f0000;
  *(undefined4 *)(*piVar2 + 0x154) = 0;
  *(undefined4 *)(*piVar2 + 0x158) = 0;
  *(undefined4 *)(*piVar2 + 0x14c) = 0;
  *(undefined4 *)(*piVar2 + 0x15c) = 0xe;
  piVar2 = (int *)param_1[0x1a9];
  iVar1 = *(int *)(*param_1 + 0x208);
  if (iVar1 != 0) {
    uVar3 = (*DAT_0019f7bc)(iVar1);
    *(undefined4 *)(*piVar2 + 0x110) = uVar3;
    *(undefined4 *)(*piVar2 + 0x114) = 2;
    *(int *)(*piVar2 + 0x194) = iVar1;
    *(undefined4 *)(*piVar2 + 0x108) = 0xc;
  }
  param_1[0x1aa] = 0;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  return;
}


// Spawn__8CAirtank  @ 00086838
void Spawn__8CAirtank(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 5;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_oxygen.mdl");
  local_10 = 0x41800000;
  local_8 = 0x42100000;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)TankTouch__8CAirtankP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)TankThink__8CAirtank;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x160) = 0x41a00000;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x42480000;
  param_1[0x1ae] = 1;
  return;
}


// Spawn__8CCrowbar  @ 00098374
void Spawn__8CCrowbar(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 1;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_crowbar.mdl");
  param_1[0x130] = -1;
  FallInit__15CBasePlayerItem(param_1);
  return;
}


// Spawn__8CDeadHEV  @ 000e4ca0
void Spawn__8CDeadHEV(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  (*g_engfuncs)("models/player.mdl");
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/player.mdl");
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0xb0) = 0x41000000;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x114) = 1;
  param_1[0x19b] = 0xf7;
  uVar1 = LookupSequence__14CBaseAnimatingPCc
                    (param_1,*(undefined4 *)(_8CDeadHEV_m_szPoses + param_1[0x1a7] * 4));
  *(undefined4 *)(*param_1 + 0x128) = uVar1;
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x128) == -1) {
    (*DAT_0019f794)(1,"Dead hevsuit with bad pose\n");
    *(undefined4 *)(*param_1 + 0x128) = 0;
    *(undefined4 *)(*param_1 + 0x118) = 1;
    iVar2 = *param_1;
  }
  *(undefined4 *)(iVar2 + 0x160) = 0x41000000;
  (**(code **)(param_1[0x115] + 0x128))(param_1);
  return;
}


// Spawn__8CDetpack  @ 000999c4
void Spawn__8CDetpack(int *param_1)

{
  char *pcVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  float fStack_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x1af] = 0;
  param_1[0x1ae] = 0;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  param_1[0x1b0] = 0;
  if (birthday == 0) {
    pcVar1 = "models/detpack.mdl";
  }
  else {
    pcVar1 = "models/presentlg.mdl";
  }
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),pcVar1);
  param_1[5] = -0x10000;
  param_1[6] = (int)DetpackTouch__8CDetpackP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)DetpackThink__8CDetpack;
  fStack_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = fStack_8;
  uStack_14 = 0x40800000;
  uStack_20 = 0xc0800000;
  uStack_1c = uStack_20;
  uStack_18 = uStack_20;
  uStack_10 = uStack_14;
  uStack_c = uStack_14;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_20,&uStack_14);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[0x42] = 0;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"weapons/mine_activate.wav",0x3f800000,0x3f4ccccd,0
             ,100);
  return;
}


// Spawn__8CGrenade  @ 000b1c58
void Spawn__8CGrenade(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(char **)*param_1 = "?grenade" + (1 - *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/grenade.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[0x1a8] = 0;
  param_1[0x1a7] = 0;
  param_1[0x1ab] = 0;
  param_1[0x1aa] = 0;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x42c80000;
  param_1[0x1ac] = 0;
  *(undefined2 *)(param_1 + 0x1ad) = 0;
  return;
}


// Spawn__8CMessage  @ 000a35f4
void Spawn__8CMessage(int *param_1)

{
  float fVar1;
  int iVar2;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  iVar2 = *param_1;
  switch(*(undefined4 *)(iVar2 + 0x184)) {
  default:
    *(undefined4 *)(iVar2 + 0x1f8) = 0x40000000;
    break;
  case 1:
    *(undefined4 *)(iVar2 + 0x1f8) = 0x3fa00000;
    break;
  case 2:
    *(undefined4 *)(iVar2 + 0x1f8) = 0x3f4ccccd;
    break;
  case 3:
    *(undefined4 *)(iVar2 + 0x1f8) = 0;
  }
  *(undefined4 *)(*param_1 + 0x184) = 0;
  fVar1 = *(float *)(*param_1 + 0x144);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(*param_1 + 0x144) = 0x3f800000;
  }
  return;
}


// Spawn__8CNodeEnt  @ 000c681c
void Spawn__8CNodeEnt(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  if (WorldGraph == 0) {
    if (DAT_0019fb38 == 0) {
      uVar4 = GetClassPtr__H1Z9CTestHull_PX01_PX01(0);
      Spawn__9CTestHullP9entvars_s(uVar4,*param_1);
    }
    iVar6 = DAT_0019fb2c;
    if (0x3ff < DAT_0019fb38) {
      (*DAT_0019f794)(2,"cNodes > MAX_NODES\n");
      return;
    }
    iVar5 = DAT_0019fb38 * 0x58;
    puVar1 = (undefined4 *)(DAT_0019fb2c + iVar5);
    iVar3 = *param_1;
    *puVar1 = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar6 + 4 + iVar5) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar6 + 8 + iVar5) = *(undefined4 *)(iVar3 + 0x10);
    puVar2 = (undefined4 *)(DAT_0019fb2c + DAT_0019fb38 * 0x58);
    puVar1[3] = *puVar2;
    puVar1[4] = puVar2[1];
    puVar1[5] = puVar2[2];
    *(undefined4 *)(DAT_0019fb2c + 0x54 + DAT_0019fb38 * 0x58) = *(undefined4 *)(*param_1 + 0x54);
    *(short *)(DAT_0019fb2c + 0x50 + DAT_0019fb38 * 0x58) = (short)param_1[0x116];
    *(undefined2 *)(DAT_0019fb2c + 0x52 + DAT_0019fb38 * 0x58) =
         *(undefined2 *)((int)param_1 + 0x45a);
    iVar6 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"info_node_air");
    if (iVar6 == 0) {
      *(undefined4 *)(DAT_0019fb2c + 0x1c + DAT_0019fb38 * 0x58) = 2;
    }
    else {
      *(undefined4 *)(DAT_0019fb2c + 0x1c + DAT_0019fb38 * 0x58) = 0;
    }
    DAT_0019fb38 = DAT_0019fb38 + 1;
  }
  (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Spawn__8CRotDoor  @ 0009e684
void Spawn__8CRotDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  AxisDir__11CBaseToggleP9entvars_s(*param_1);
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x1a0) & 2) != 0) {
    *(float *)(iVar6 + 0x44) = -*(float *)(iVar6 + 0x44);
    *(float *)(iVar6 + 0x48) = -*(float *)(iVar6 + 0x48);
    *(float *)(iVar6 + 0x4c) = -*(float *)(iVar6 + 0x4c);
    iVar6 = *param_1;
  }
  param_1[0x12a] = *(int *)(iVar6 + 0x50);
  param_1[299] = *(int *)(iVar6 + 0x54);
  param_1[300] = *(int *)(iVar6 + 0x58);
  fVar1 = (float)param_1[0x11f];
  fVar2 = *(float *)(iVar6 + 0x48);
  fVar3 = *(float *)(iVar6 + 0x4c);
  fVar4 = *(float *)(iVar6 + 0x54);
  fVar5 = *(float *)(iVar6 + 0x58);
  param_1[0x12d] = (int)(*(float *)(iVar6 + 0x44) * fVar1 + *(float *)(iVar6 + 0x50));
  param_1[0x12e] = (int)(fVar2 * fVar1 + fVar4);
  param_1[0x12f] = (int)(fVar1 * fVar3 + fVar5);
  if ((*(byte *)(iVar6 + 0x1a0) & 8) == 0) {
    *(undefined4 *)(iVar6 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(iVar6 + 0x10c) = 0;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar6 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar6 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar6 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar6 + 0x1f8) = 0x42c80000;
    iVar6 = *param_1;
  }
  if ((*(byte *)(iVar6 + 0x1a0) & 1) != 0) {
    *(int *)(iVar6 + 0x50) = param_1[0x12d];
    *(int *)(iVar6 + 0x54) = param_1[0x12e];
    *(int *)(iVar6 + 0x58) = param_1[0x12f];
    param_1[0x12d] = param_1[0x12a];
    param_1[0x12e] = param_1[299];
    param_1[0x12f] = param_1[300];
    param_1[0x12a] = param_1[0x12a];
    param_1[299] = param_1[299];
    param_1[300] = param_1[300];
    iVar6 = *param_1;
    *(float *)(iVar6 + 0x44) = -*(float *)(iVar6 + 0x44);
    *(float *)(iVar6 + 0x48) = -*(float *)(iVar6 + 0x48);
    *(float *)(iVar6 + 0x4c) = -*(float *)(iVar6 + 0x4c);
  }
  param_1[0x11d] = 1;
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  else {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  return;
}


// Spawn__8CSpeaker  @ 000f1a3c
void Spawn__8CSpeaker(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  iVar1 = *param_1;
  puVar4 = (uint *)(*(int *)(iVar1 + 0x1d4) + (int)gpGlobals[0x26]);
  if (param_1[0x116] == 0) {
    if (*(int *)(iVar1 + 0x1d4) != 0) {
      uVar5 = (uint)puVar4 & 3;
      puVar2 = puVar4;
      if (uVar5 == 0) {
LAB_000f1a9c:
        do {
          puVar3 = puVar2;
          uVar5 = *puVar3;
          if ((char)uVar5 == '\0') goto LAB_000f1abe;
          if ((char)(uVar5 >> 8) == '\0') goto LAB_000f1abd;
          if ((uVar5 & 0xff0000) == 0) goto LAB_000f1abc;
          puVar2 = puVar3 + 1;
        } while ((uVar5 & 0xff000000) != 0);
        puVar3 = (uint *)((int)puVar3 + 1);
LAB_000f1abc:
        puVar3 = (uint *)((int)puVar3 + 1);
LAB_000f1abd:
        puVar3 = (uint *)((int)puVar3 + 1);
      }
      else {
        puVar3 = puVar4;
        if ((POPCOUNT(uVar5) & 1U) == 0) {
LAB_000f1a97:
          if ((char)*puVar3 != '\0') {
            puVar2 = (uint *)((int)puVar3 + 1);
            goto LAB_000f1a9c;
          }
        }
        else if (uVar5 == 2) {
LAB_000f1a92:
          if ((char)*puVar3 != '\0') {
            puVar3 = (uint *)((int)puVar3 + 1);
            goto LAB_000f1a97;
          }
        }
        else if ((char)*puVar4 != '\0') {
          puVar3 = (uint *)((int)puVar4 + 1);
          goto LAB_000f1a92;
        }
      }
LAB_000f1abe:
      if (puVar3 != puVar4) goto LAB_000f1b28;
    }
    (*DAT_0019f794)(4,"SPEAKER with no Level/Sentence! at: %f, %f, %f\n",
                    (double)*(float *)(iVar1 + 8),(double)*(float *)(iVar1 + 0xc),
                    (double)*(float *)(iVar1 + 0x10));
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
LAB_000f1b28:
    *(undefined4 *)(iVar1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SpeakerThink__8CSpeaker;
    *(undefined4 *)(*param_1 + 0x104) = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf;
    (**(code **)(param_1[0x115] + 0x10))();
  }
  return;
}


// Spawn__8CTFFlame  @ 000e63d4
void Spawn__8CTFFlame(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_fire" - (int)gpGlobals[0x26];
  param_1[0xfe] = (int)"flames" - (int)gpGlobals[0x26];
  *(float *)(*param_1 + 0x160) = *gpGlobals + 5.0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x88;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  param_1[0x1a7] = *(int *)(*param_1 + 0x104);
  param_1[3] = -0x10000;
  param_1[4] = (int)FlameThink__8CTFFlame;
  return;
}


// Spawn__8CTFKnife  @ 0012ccbc
void Spawn__8CTFKnife(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 0x17;
  param_1[0x130] = -1;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[0x154] = 0;
  return;
}


// Spawn__8CTFSpawn  @ 0010ac4c
void Spawn__8CTFSpawn(int *param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = param_1[0xbe];
  if ((((iVar3 == -1) && (g_iSkillLevel < 0)) ||
      ((iVar1 = param_1[0xbf], iVar1 == -1 && (0 < g_iSkillLevel)))) ||
     (((1 < iVar3 + 1U && (g_iSkillLevel < iVar3)) || (1 < iVar1 + 1U && iVar1 < g_iSkillLevel)))) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    iVar3 = param_1[0x48];
    if ((iVar3 - 1U < 4) || (param_1[0x88] != 0)) {
      fVar2 = (float)iVar3;
      if (0x3f < (byte)((fVar2 < number_of_teams |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(number_of_teams)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == number_of_teams) << 0xe) >> 8)) - 1)) {
        number_of_teams = fVar2;
      }
      param_1 = (int *)*param_1;
      iVar3 = (int)"info_player_teamspawn" - *(int *)(gpGlobals + 0x98);
      *param_1 = iVar3;
      param_1[0x74] = iVar3;
    }
    else {
      (*DAT_0019f794)(1,"Teamspawnpoint with an invalid team_no of %d\n",iVar3);
    }
  }
  return;
}


// Spawn__8CTFTranq  @ 001329cc
void Spawn__8CTFTranq(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_tranq" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  param_1[0x11f] = 2;
  param_1[0x133] = 0x11;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__8CTeamSet  @ 0011197c
void Spawn__8CTeamSet(void)

{
  return;
}


// Spawn__8CXenHair  @ 00128604
void Spawn__8CXenHair(int *param_1)

{
  longdouble lVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/hair.mdl");
  local_10 = 0x40800000;
  local_8 = 0x42000000;
  local_1c = 0xc0800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  *(undefined4 *)(*param_1 + 0x128) = 0;
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
    lVar1 = (longdouble)(*DAT_0019f80c)(0,0x437f0000);
    *(float *)(*param_1 + 0x130) = (float)lVar1;
    lVar1 = (longdouble)(*DAT_0019f80c)(0x3f333333,0x3fb33333);
    *(float *)(*param_1 + 0x138) = (float)lVar1;
  }
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  lVar1 = (longdouble)(*DAT_0019f80c)(0x3dcccccd,0x3ecccccd);
  *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


// Spawn__8CXenTree  @ 00128730
void Spawn__8CXenTree(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  longdouble lVar4;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/tree.mdl");
  fStack_10 = 30.0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  fStack_8 = 188.0;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  fStack_1c = -30.0;
  fStack_14 = 0.0;
  fStack_18 = fStack_1c;
  fStack_c = fStack_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&fStack_1c,&fStack_10);
  iVar2 = LookupActivity__14CBaseAnimatingi(param_1,1);
  if (iVar2 != -1) {
    *(int *)(*param_1 + 0x128) = iVar2;
    param_1[0x11d] = 1;
    *(undefined4 *)(*param_1 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  fStack_20 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = fStack_20;
  lVar4 = (longdouble)(*DAT_0019f80c)(0,0x437f0000);
  *(float *)(*param_1 + 0x130) = (float)lVar4;
  lVar4 = (longdouble)(*DAT_0019f80c)(0x3f333333,0x3fb33333);
  *(float *)(*param_1 + 0x138) = (float)lVar4;
  (*DAT_0019f6f0)(*param_1 + 0x50,&fStack_1c,0,0);
  fStack_2c = fStack_1c * 64.0;
  fStack_28 = fStack_18 * 64.0;
  fStack_24 = fStack_14 * 64.0;
  iVar2 = *param_1;
  fStack_1c = fStack_2c + *(float *)(iVar2 + 8);
  fStack_18 = fStack_28 + *(float *)(iVar2 + 0xc);
  fStack_14 = fStack_24 + *(float *)(iVar2 + 0x10);
  uVar1 = *(undefined4 *)(iVar2 + 0x208);
  fStack_10 = fStack_1c;
  fStack_c = fStack_18;
  fStack_8 = fStack_14;
  piVar3 = (int *)GetClassPtr__H1Z15CXenTreeTrigger_PX01_PX01(0);
  iVar2 = *piVar3;
  *(float *)(iVar2 + 8) = fStack_1c;
  *(float *)(iVar2 + 0xc) = fStack_18;
  *(float *)(iVar2 + 0x10) = fStack_14;
  *(int *)*piVar3 = (int)"xen_ttrigger" - (int)gpGlobals[0x26];
  fStack_2c = 24.0;
  *(undefined4 *)(*piVar3 + 0x10c) = 1;
  fStack_24 = 128.0;
  *(undefined4 *)(*piVar3 + 0x108) = 0;
  *(undefined4 *)(*piVar3 + 0x198) = uVar1;
  param_1[0x11e] = (int)piVar3;
  fStack_10 = -24.0;
  fStack_8 = 0.0;
  fStack_28 = fStack_2c;
  fStack_c = fStack_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*piVar3,&fStack_10,&fStack_2c);
  return;
}


// Spawn__9CBaseDoor  @ 0009d014
void Spawn__9CBaseDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  SetMovedir__FP9entvars_s(*param_1);
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0x110) == 0) {
    if ((*(byte *)(iVar4 + 0x1a0) & 8) == 0) {
      *(undefined4 *)(iVar4 + 0x10c) = 4;
    }
    else {
      *(undefined4 *)(iVar4 + 0x10c) = 0;
    }
  }
  else {
    *(undefined4 *)(iVar4 + 0x10c) = 0;
    *(byte *)(*param_1 + 0x1a3) = *(byte *)(*param_1 + 0x1a3) | 0x80;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar4 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar4 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(iVar4 + 0x1f8) = 0x42c80000;
    iVar4 = *param_1;
  }
  param_1[0x124] = *(int *)(iVar4 + 8);
  param_1[0x125] = *(int *)(iVar4 + 0xc);
  param_1[0x126] = *(int *)(iVar4 + 0x10);
  fVar3 = (ABS((*(float *)(iVar4 + 0xf8) - 2.0) * *(float *)(iVar4 + 0x48)) +
           ABS((*(float *)(iVar4 + 0xf4) - 2.0) * *(float *)(iVar4 + 0x44)) +
          ABS((*(float *)(iVar4 + 0xfc) - 2.0) * *(float *)(iVar4 + 0x4c))) - (float)param_1[0x121];
  fVar1 = *(float *)(iVar4 + 0x48);
  fVar2 = *(float *)(iVar4 + 0x4c);
  param_1[0x127] = (int)(fVar3 * *(float *)(iVar4 + 0x44) + (float)param_1[0x124]);
  param_1[0x128] = (int)(fVar3 * fVar1 + (float)param_1[0x125]);
  param_1[0x129] = (int)(fVar3 * fVar2 + (float)param_1[0x126]);
  if ((*(byte *)(iVar4 + 0x1a0) & 1) != 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar4,param_1 + 0x127);
    param_1[0x127] = param_1[0x124];
    param_1[0x128] = param_1[0x125];
    iVar4 = *param_1;
    param_1[0x129] = param_1[0x126];
    param_1[0x124] = *(int *)(iVar4 + 8);
    param_1[0x125] = *(int *)(iVar4 + 0xc);
    param_1[0x126] = *(int *)(iVar4 + 0x10);
  }
  param_1[0x11d] = 1;
  param_1[0x149] = 0;
  *(undefined1 *)(param_1 + 0x14a) = 0;
  *(undefined1 *)((int)param_1 + 0x529) = 0;
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  else {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  return;
}


// Spawn__9CBubbling  @ 0009f3e4
void Spawn__9CBubbling(int *param_1)

{
  uint uVar1;
  float fVar2;
  undefined4 uVar3;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 2;
  uVar1 = (uint)ROUND(ABS(*(float *)(*param_1 + 0x1f8)));
  *(float *)(*param_1 + 0x150) = (float)((int)uVar1 >> 8);
  *(float *)(*param_1 + 0x154) = (float)(uVar1 & 0xff);
  uVar3 = 0;
  fVar2 = *(float *)(*param_1 + 0x1f8);
  if (0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
    uVar3 = 0x3f800000;
  }
  *(undefined4 *)(*param_1 + 0x158) = uVar3;
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) == 0) {
    param_1[0x119] = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)FizzThink__9CBubbling;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 2.0;
    param_1[0x119] = 1;
  }
  return;
}


// Spawn__9CEnvLight  @ 000b66c4
void Spawn__9CEnvLight(int *param_1)

{
  int iVar1;
  undefined *puVar2;
  char local_44 [64];
  
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  sprintf(local_44,"%f",SUB84((double)*(float *)(gpGlobals + 0x28),0),
          (int)((ulonglong)(double)*(float *)(gpGlobals + 0x28) >> 0x20));
  (*DAT_0019f790)("sv_skyvec_x",local_44);
  sprintf(local_44,"%f",(double)*(float *)(gpGlobals + 0x2c));
  (*DAT_0019f790)("sv_skyvec_y",local_44);
  sprintf(local_44,"%f",SUB84((double)*(float *)(gpGlobals + 0x30),0),
          (int)((ulonglong)(double)*(float *)(gpGlobals + 0x30) >> 0x20));
  (*DAT_0019f790)();
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1cc) == 0) {
    (*DAT_0019f6f8)(*(undefined4 *)(iVar1 + 0x208));
  }
  else if (0x1f < param_1[0x116]) {
    if ((*(byte *)(iVar1 + 0x1a0) & 1) == 0) {
      if (param_1[0x117] == 0) {
        puVar2 = &DAT_0014cc3f;
      }
      else {
        puVar2 = (undefined *)(param_1[0x117] + *(int *)(gpGlobals + 0x98));
      }
    }
    else {
      puVar2 = &DAT_0014cc3d;
    }
    (*DAT_0019f74c)(param_1[0x116],puVar2);
  }
  return;
}


// Spawn__9CEnvSound  @ 000f27f4
void Spawn__9CEnvSound(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_0019f80c)(0,0x3f000000);
  *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


// Spawn__9CEnvSpark  @ 0008bf7c
void Spawn__9CEnvSpark(int *param_1)

{
  float fVar1;
  longdouble lVar2;
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  if ((*(uint *)(*param_1 + 0x1a0) & 0x20) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SparkThink__9CEnvSpark;
  }
  else if ((*(uint *)(*param_1 + 0x1a0) & 0x40) == 0) {
    param_1[7] = -0x10000;
    param_1[8] = (int)SparkStart__9CEnvSparkP11CBaseEntityT18USE_TYPEf;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)SparkThink__9CEnvSpark;
    param_1[7] = -0x10000;
    param_1[8] = (int)SparkStop__9CEnvSparkP11CBaseEntityT18USE_TYPEf;
  }
  lVar2 = (longdouble)(*DAT_0019f80c)(0,0x3fc00000);
  *(float *)(*param_1 + 0x104) = (float)((longdouble)0.1 + lVar2 + (longdouble)*gpGlobals);
  fVar1 = (float)param_1[0x116];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    param_1[0x116] = 0x3fc00000;
  }
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  return;
}


// Spawn__9CFuncPlat  @ 000d2dec
void Spawn__9CFuncPlat(int *param_1)

{
  int iVar1;
  
  Setup__9CFuncPlat(param_1);
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1cc) == 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,param_1 + 0x127);
    param_1[0x11d] = 1;
  }
  else {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,param_1 + 0x124);
    param_1[0x11d] = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)PlatUse__9CFuncPlatP11CBaseEntityT18USE_TYPEf;
  }
  return;
}


// Spawn__9CFuncTank  @ 000a9c74
void Spawn__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_38;
  float fStack_34;
  float fStack_30;
  float local_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float local_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar6 = *param_1;
  param_1[0x11b] = *(int *)(iVar6 + 0x54);
  param_1[0x11f] = *(int *)(iVar6 + 0x50);
  if ((*(byte *)(iVar6 + 0x1a0) & 1) != 0) {
    local_8 = *(float *)(iVar6 + 0x100) + 1.0;
    *(float *)(iVar6 + 0x104) = local_8;
  }
  (*DAT_0019f6f0)(*param_1 + 0x50,&local_20,&local_2c,&local_38);
  fVar1 = (float)param_1[0x129];
  iVar6 = *param_1;
  fVar2 = *(float *)(iVar6 + 0xc);
  fVar3 = *(float *)(iVar6 + 0x10);
  fVar4 = (float)param_1[0x12a];
  fVar5 = (float)param_1[299];
  param_1[0x131] =
       (int)(local_20 * fVar1 + *(float *)(iVar6 + 8) + local_2c * fVar4 + local_38 * fVar5);
  param_1[0x132] = (int)(fStack_1c * fVar1 + fVar2 + fStack_28 * fVar4 + fStack_34 * fVar5);
  param_1[0x133] = (int)(fVar1 * fStack_18 + fVar3 + fVar4 * fStack_24 + fVar5 * fStack_30);
  fVar1 = (float)param_1[0x124];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    param_1[0x124] = 0x3f800000;
  }
  if (5 < (uint)param_1[0x134]) {
    param_1[0x134] = 0;
  }
  iVar6 = *param_1;
  *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(iVar6 + 8);
  *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar6 + 0xc);
  *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar6 + 0x10);
  return;
}


// Spawn__9CFuncWall  @ 0008a074
void Spawn__9CFuncWall(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 2;
  return;
}


// Spawn__9CItemAmmo  @ 000fc400
void Spawn__9CItemAmmo(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  Spawn__5CItem(param_1);
  Precache__9CItemAmmo(param_1);
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x1a0) & 1) == 0) {
    (*DAT_0019f6a8)(*(undefined4 *)(iVar1 + 0x208),param_1[0x117] + *(int *)(gpGlobals + 0x98));
  }
  else {
    (*DAT_0019f6a8)(*(undefined4 *)(iVar1 + 0x208),param_1[0x118] + *(int *)(gpGlobals + 0x98));
    param_1[0x33] = param_1[0x33] << 1;
    param_1[0x35] = param_1[0x35] << 1;
    param_1[0x39] = param_1[0x39] << 1;
    param_1[0x37] = param_1[0x37] << 1;
  }
  local_10 = 0x41800000;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  local_8 = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__9CItemSoda  @ 000a2f50
void Spawn__9CItemSoda(int *param_1)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/can.mdl");
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_1c,&uStack_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)CanThink__9CItemSoda;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  return;
}


// Spawn__9CItemSuit  @ 00141a9c
void Spawn__9CItemSuit(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/w_suit.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__9CPendulum  @ 00088d8c
void Spawn__9CPendulum(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  AxisDir__11CBaseToggleP9entvars_s(*param_1);
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x1a0) & 8) == 0) {
    *(undefined4 *)(iVar6 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(iVar6 + 0x10c) = 0;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  fVar1 = (float)param_1[0x117];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar6 = *param_1;
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar6 + 0x1f8)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(iVar6 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(iVar6 + 0x1f8) = 0x42c80000;
      iVar6 = *param_1;
      fVar1 = (float)param_1[0x117];
    }
    param_1[0x116] =
         (int)((*(float *)(iVar6 + 0x1f8) * *(float *)(iVar6 + 0x1f8)) / (ABS(fVar1) + ABS(fVar1)));
    param_1[0x11a] = *(int *)(iVar6 + 0x1f8);
    param_1[0x11f] = *(int *)(iVar6 + 0x50);
    param_1[0x120] = *(int *)(iVar6 + 0x54);
    param_1[0x121] = *(int *)(iVar6 + 0x58);
    fVar1 = fVar1 * 0.5;
    fVar2 = *(float *)(iVar6 + 0x48);
    fVar3 = *(float *)(iVar6 + 0x4c);
    fVar4 = *(float *)(iVar6 + 0x54);
    fVar5 = *(float *)(iVar6 + 0x58);
    param_1[0x11c] = (int)(*(float *)(iVar6 + 0x44) * fVar1 + *(float *)(iVar6 + 0x50));
    param_1[0x11d] = (int)(fVar2 * fVar1 + fVar4);
    param_1[0x11e] = (int)(fVar1 * fVar3 + fVar5);
    if ((*(byte *)(iVar6 + 0x1a0) & 1) != 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_CallUseToggle__11CBaseEntity;
      *(float *)(iVar6 + 0x104) = *gpGlobals + 0.1;
    }
    *(undefined4 *)(*param_1 + 0x1f8) = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)PendulumUse__9CPendulumP11CBaseEntityT18USE_TYPEf;
    if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
      param_1[5] = -0x10000;
      param_1[6] = (int)RopeTouch__9CPendulumP11CBaseEntity;
    }
  }
  return;
}


// Spawn__9CPushable  @ 000a8f04
void Spawn__9CPushable(int *param_1)

{
  int iVar1;
  
  if (*(char *)(*param_1 + 0x1a0) < '\0') {
    Spawn__10CBreakable(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0x10))(param_1);
  }
  *(undefined4 *)(*param_1 + 0x108) = 0xd;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  if (399.0 < *(float *)(iVar1 + 0x120)) {
    *(undefined4 *)(iVar1 + 0x120) = 0x43c78000;
    iVar1 = *param_1;
  }
  param_1[0x11f] = (int)(400.0 - *(float *)(iVar1 + 0x120));
  *(byte *)(iVar1 + 0x1a5) = *(byte *)(iVar1 + 0x1a5) | 0x80;
  *(undefined4 *)(*param_1 + 0x120) = 0;
  *(float *)(*param_1 + 0x10) = *(float *)(*param_1 + 0x10) + 1.0;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x110) =
       (int)ROUND((*(float *)(iVar1 + 0xe8) - *(float *)(iVar1 + 0xdc)) *
                  (float)*(int *)(iVar1 + 0x110) *
                  (*(float *)(iVar1 + 0xec) - *(float *)(iVar1 + 0xe0)) * 0.0005);
  param_1[0x120] = 0;
  return;
}


// Spawn__9CRecharge  @ 000b2e98
void Spawn__9CRecharge(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[0x140] = (int)ROUND(DAT_001a1d18);
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


// Spawn__9CSoundEnt  @ 000f3198
void Spawn__9CSoundEnt(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  Initialize__9CSoundEnt(param_1);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  return;
}


// Spawn__9CSprayCanP9entvars_s  @ 000da784
void Spawn__9CSprayCanP9entvars_s(int *param_1,int param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  fVar1 = *(float *)(param_2 + 0x10);
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  *(float *)(iVar3 + 0x10) = fVar1 + 32.0;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(param_2 + 0x74);
  *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(param_2 + 0x78);
  *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(param_2 + 0x7c);
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(param_2 + 0x208);
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,"player/sprayer.wav",0x3f800000,0x3f4ccccd,0,100);
  return;
}


// Spawn__9CTFDetect  @ 001121e0
void Spawn__9CTFDetect(void)

{
  return;
}


// Spawn__9CTestHullP9entvars_s  @ 000c66f8
void Spawn__9CTestHullP9entvars_s(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),FUN_0014e978);
  local_10 = 0x41800000;
  local_8 = 0x42900000;
  local_1c = 0xc1800000;
  local_14 = 0;
  local_18 = local_1c;
  local_c = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_10);
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 4;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x160) = 0x42480000;
  *(undefined4 *)(*param_1 + 0xb0) = 0x41000000;
  if (WorldGraph == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)DropDelay__9CTestHull;
    fVar1 = *gpGlobals + 1.0;
    iVar2 = *param_1;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    iVar2 = *param_1;
    fVar1 = *gpGlobals;
  }
  *(float *)(iVar2 + 0x104) = fVar1;
  *(undefined4 *)(*param_1 + 0x148) = 2;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  return;
}


// Spawn__9CWreckage  @ 000b3c6c
void Spawn__9CWreckage(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (*(int *)(*param_1 + 0xb8) != 0) {
    (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]);
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                    *(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]);
  }
  param_1[0x1a7] = (int)ROUND(*gpGlobals);
  return;
}


// Spawn__9CXenSpore  @ 00128eb4
void Spawn__9CXenSpore(int *param_1)

{
  longdouble lVar1;
  
  (**(code **)(param_1[0x115] + 0x10))(param_1);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(undefined4 *)(_9CXenSpore_pModelNames + *(int *)(*param_1 + 0x110) * 4));
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  lVar1 = (longdouble)(*DAT_0019f80c)(0,0x437f0000);
  *(float *)(*param_1 + 0x130) = (float)lVar1;
  lVar1 = (longdouble)(*DAT_0019f80c)(0x3f333333,0x3fb33333);
  *(float *)(*param_1 + 0x138) = (float)lVar1;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  lVar1 = (longdouble)(*DAT_0019f80c)(0x3dcccccd,0x3ecccccd);
  *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


