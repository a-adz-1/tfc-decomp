// Spawn__10CBreakable  @ 0009d9e0
void Spawn__10CBreakable(void)

{
  FUN_0009d9e8();
  return;
}


// Spawn__10CCineBlood  @ 000a9434
void Spawn__10CCineBlood(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)BloodStart__10CCineBloodP11CBaseEntityT18USE_TYPEf;
  *(undefined4 *)(*param_1 + 0x160) = 0x41a00000;
  return;
}


// Spawn__10CEnvFunnel  @ 0009adfc
void Spawn__10CEnvFunnel(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  return;
}


// Spawn__10CEnvGlobal  @ 000828e0
void Spawn__10CEnvGlobal(int *param_1)

{
  int iVar1;
  
  if (param_1[0xf6] == 0) {
    (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  }
  else if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    iVar1 = Find__12CGlobalStatei(&gGlobalState,param_1[0xf6]);
    if (iVar1 == 0) {
      EntityAdd__12CGlobalStateii12GLOBALESTATE
                (&gGlobalState,param_1[0xf6],*(undefined4 *)(gpGlobals + 0xc),param_1[0xf8]);
    }
  }
  return;
}


// Spawn__10CFuncTrain  @ 000c3bf8
void Spawn__10CFuncTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
  }
  if (*(int *)(*param_1 + 0x1c8) == 0) {
    (*DAT_001a7f34)(1,"FuncTrain with no target");
  }
  fVar1 = *(float *)(*param_1 + 0x1e0);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1e0) = 0x40000000;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  if ((*(byte *)(*param_1 + 0x1a0) & 8) == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
  }
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar2 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,iVar2 + 0xdc,iVar2 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[0x122] = 0;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x11f]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x11f] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x11f] = 0x3f59999a;
  }
  return;
}


// Spawn__10CFurniture  @ 000ddde4
void Spawn__10CFurniture(int *param_1)

{
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
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
  (**(code **)(param_1[0xf5] + 0x11c))(param_1);
  return;
}


// Spawn__10CGunTarget  @ 000c6f2c
void Spawn__10CGunTarget(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
  }
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  param_1[0x187] = 0;
  *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 1) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)Start__10CGunTarget;
    *(float *)(iVar2 + 0x104) = *(float *)(iVar2 + 0x100) + 0.3;
  }
  return;
}


// Spawn__10CHealthKit  @ 000aae9c
void Spawn__10CHealthKit(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_medkit.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__10CLaserSpot  @ 000f4ad0
void Spawn__10CLaserSpot(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 3;
  *(undefined4 *)(*param_1 + 0x15c) = 0xe;
  *(undefined4 *)(*param_1 + 0x14c) = 0x437f0000;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"sprites/laserdot.spr");
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__10CLightning  @ 00096374
void Spawn__10CLightning(int *param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1[0x100] == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    *(float *)(*param_1 + 0x1e4) = *gpGlobals;
    bVar2 = false;
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf9]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xf9] == 0.0) << 0xe) >> 8)) == 0x40) {
      bVar2 = (*(byte *)(*param_1 + 0x1a0) & 8) == 0;
    }
    if (bVar2) {
      param_1[3] = 0;
      param_1[4] = 0;
      if (0.0 < *(float *)(*param_1 + 0x1e0)) {
        param_1[3] = -0x10000;
        param_1[4] = (int)DamageThink__10CLightning;
        *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      }
      iVar1 = *param_1;
      if (*(int *)(iVar1 + 0x1cc) != 0) {
        if (((*(byte *)(iVar1 + 0x1a0) ^ 1) & 1) == 0) {
          param_1[0xf6] = 1;
        }
        else {
          *(undefined4 *)(iVar1 + 0x118) = 0x80;
          param_1[0xf6] = 0;
          *(undefined4 *)(*param_1 + 0x104) = 0;
        }
        param_1[7] = -0x10000;
        param_1[8] = (int)ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf;
      }
    }
    else {
      param_1[0xf6] = 0;
      if (*(int *)(*param_1 + 0x1cc) != 0) {
        param_1[7] = -0x10000;
        param_1[8] = (int)StrikeUse__10CLightningP11CBaseEntityT18USE_TYPEf;
      }
      if ((*(int *)(*param_1 + 0x1cc) == 0) || ((*(byte *)(*param_1 + 0x1a0) & 1) != 0)) {
        param_1[3] = -0x10000;
        param_1[4] = (int)StrikeThink__10CLightning;
        *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
      }
    }
  }
  return;
}


// Spawn__10CPathTrack  @ 000c14cc
void Spawn__10CPathTrack(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  local_c = 0x41000000;
  local_18 = 0xc1000000;
  local_14 = local_18;
  local_10 = local_18;
  local_8 = local_c;
  local_4 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  param_1[0xf8] = 0;
  param_1[0xf9] = 0;
  return;
}


// Spawn__10CRotButton  @ 00084598
void Spawn__10CRotButton(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar7 = ButtonSound__Fi(param_1[299]);
  (*DAT_001a7e44)(uVar7);
  uVar7 = (*DAT_001a7f4c)(uVar7);
  *(undefined4 *)(*param_1 + 0x1e8) = uVar7;
  AxisDir__11CBaseToggleP9entvars_s(*param_1);
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x1a0) & 2) != 0) {
    *(float *)(iVar6 + 0x44) = *(float *)(iVar6 + 0x44) * -1.0;
    *(float *)(iVar6 + 0x48) = *(float *)(iVar6 + 0x48) * -1.0;
    *(float *)(iVar6 + 0x4c) = *(float *)(iVar6 + 0x4c) * -1.0;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
  }
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42200000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x100]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x100] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x100] = 0x3f800000;
  }
  if (0.0 < *(float *)(*param_1 + 0x160)) {
    *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  }
  param_1[0xfd] = 1;
  iVar6 = *param_1;
  param_1[0x10a] = *(int *)(iVar6 + 0x50);
  param_1[0x10b] = *(int *)(iVar6 + 0x54);
  param_1[0x10c] = *(int *)(iVar6 + 0x58);
  fVar1 = (float)param_1[0xff];
  fVar2 = *(float *)(iVar6 + 0x48);
  fVar3 = *(float *)(iVar6 + 0x4c);
  fVar4 = *(float *)(iVar6 + 0x54);
  fVar5 = *(float *)(iVar6 + 0x58);
  param_1[0x10d] = (int)(*(float *)(iVar6 + 0x50) + fVar1 * *(float *)(iVar6 + 0x44));
  param_1[0x10e] = (int)(fVar4 + fVar1 * fVar2);
  param_1[0x10f] = (int)(fVar5 + fVar1 * fVar3);
  fVar1 = (float)param_1[0x100];
  param_1[0x11e] =
       (uint)((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40);
  param_1[0x11f] = 1;
  if ((*(byte *)(iVar6 + 0x1a1) & 1) == 0) {
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


// Spawn__10CTFGrenade  @ 000f4408
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
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f000000;
  param_1[0x188] = 1;
  param_1[0x189] = 1;
  (**(code **)(param_1[0xf5] + 0x220))(param_1);
  fStack_c = 0.0;
  fStack_8 = 0.0;
  fStack_4 = 0.0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_18,&fStack_c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  iVar7 = *param_1;
  fVar1 = gpGlobals[10];
  fVar2 = gpGlobals[0xb];
  fVar3 = gpGlobals[0xc];
  fVar4 = gpGlobals[0xd];
  fVar5 = gpGlobals[0xe];
  fVar6 = gpGlobals[0xf];
  lVar8 = (longdouble)(*DAT_001a7fac)(0xc1200000,0x41200000);
  fStack_4 = fVar3 * 600.0 + fVar6 * 200.0 + (float)(lVar8 * (longdouble)gpGlobals[0x12]);
  fStack_c = (float)((longdouble)(fVar1 * 600.0 + fVar4 * 200.0) +
                    lVar8 * (longdouble)gpGlobals[0x10]);
  fStack_8 = (float)((longdouble)(fVar2 * 600.0 + fVar5 * 200.0) +
                    lVar8 * (longdouble)gpGlobals[0x11]);
  lVar8 = (longdouble)(*DAT_001a7fac)(0xc1200000,0x41200000);
  fVar1 = gpGlobals[0xe];
  fVar2 = gpGlobals[0xf];
  *(float *)(iVar7 + 0x20) = (float)((longdouble)fStack_c + lVar8 * (longdouble)gpGlobals[0xd]);
  *(float *)(iVar7 + 0x24) = (float)((longdouble)fStack_8 + lVar8 * (longdouble)fVar1);
  *(float *)(iVar7 + 0x28) = fStack_4 + (float)(lVar8 * (longdouble)fVar2);
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


// Spawn__10CTFMedikit  @ 00117de8
void Spawn__10CTFMedikit(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 3;
  param_1[0x110] = -1;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[0x134] = 2;
  return;
}


// Spawn__10CTFNailgun  @ 0011a780
void Spawn__10CTFNailgun(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 4;
  param_1[0x113] = 0x32;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFRailgun  @ 0011b0f8
void Spawn__10CTFRailgun(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_railgun" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 2;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_gauss.mdl");
  param_1[0x113] = 0x11;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFRpgAmmo  @ 0012eaf0
void Spawn__10CTFRpgAmmo(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_rpgammo.mdl");
  Spawn__15CBasePlayerAmmo(param_1);
  return;
}


// Spawn__10CTFShotgun  @ 0011be2c
void Spawn__10CTFShotgun(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 8;
  param_1[0x2c] = 0;
  param_1[0x113] = 8;
  param_1[0x116] = 8;
  param_1[0x107] = 0x3e800000;
  param_1[0x115] = 1;
  param_1[0x106] = 0x447a0000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFSpanner  @ 001177dc
void Spawn__10CTFSpanner(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 4;
  param_1[0x110] = -1;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[0x134] = 1;
  return;
}


// Spawn__10CWeaponBox  @ 00111548
void Spawn__10CWeaponBox(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/backpack.mdl");
  param_1[0xfc] = 0;
  param_1[0xfd] = 0;
  return;
}


// Spawn__10CWorldItem  @ 000ab758
void Spawn__10CWorldItem(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)0x0;
  switch(param_1[0xf6]) {
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
    goto switchD_000ab784_default;
  }
  piVar3 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s(pcVar2,iVar1,iVar4,0);
switchD_000ab784_default:
  if (piVar3 == (int *)0x0) {
    (*DAT_001a7f34)(1,FUN_00136c60,param_1[0xf6]);
  }
  else {
    *(undefined4 *)(*piVar3 + 0x1c8) = *(undefined4 *)(*param_1 + 0x1c8);
    *(undefined4 *)(*piVar3 + 0x1cc) = *(undefined4 *)(*param_1 + 0x1cc);
    *(undefined4 *)(*piVar3 + 0x1a0) = *(undefined4 *)(*param_1 + 0x1a0);
  }
  (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Spawn__10CXenPLight  @ 00114434
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
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/light.mdl");
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  local_c = 0x42a00000;
  local_4 = 32.0;
  local_18 = 0xc2a00000;
  local_10 = 0.0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  SetActivity__13CActAnimating8Activity(param_1,1);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  lVar8 = (longdouble)(*DAT_001a7fac)(0,0x437f0000);
  *(float *)(*param_1 + 0x130) = (float)lVar8;
  iVar5 = *param_1;
  local_4 = (*(float *)(iVar5 + 0xe4) + *(float *)(iVar5 + 0xf0)) * 0.5;
  local_c = 0;
  local_8 = 0;
  local_18 = *(undefined4 *)(iVar5 + 8);
  local_14 = *(undefined4 *)(iVar5 + 0xc);
  local_10 = *(float *)(iVar5 + 0x10) + local_4;
  piVar6 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/flare3.spr",&local_18,0);
  param_1[0xfe] = (int)piVar6;
  iVar5 = *param_1;
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
  iVar5 = *(int *)(*param_1 + 0x208);
  piVar6 = (int *)param_1[0xfe];
  if (iVar5 != 0) {
    uVar7 = (*DAT_001a7f5c)(iVar5);
    *(undefined4 *)(*piVar6 + 0x110) = uVar7;
    *(undefined4 *)(*piVar6 + 0x114) = 1;
    *(int *)(*piVar6 + 0x194) = iVar5;
    *(undefined4 *)(*piVar6 + 0x108) = 0xc;
  }
  return;
}


// Spawn__11CBaseButton  @ 0008374c
void Spawn__11CBaseButton(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  bool bVar5;
  undefined4 uVar6;
  
  uVar6 = ButtonSound__Fi(param_1[299]);
  (*DAT_001a7e44)(uVar6);
  uVar6 = (*DAT_001a7f4c)(uVar6);
  *(undefined4 *)(*param_1 + 0x1e8) = uVar6;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 0x40) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)ButtonSpark__11CBaseButton;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  }
  SetMovedir__FP9entvars_s(*param_1);
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42200000;
  }
  *(undefined4 *)(*param_1 + 0x1b0) = 0;
  if (0.0 < *(float *)(*param_1 + 0x160)) {
    *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
    *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x100]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x100] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x100] = 0x3f800000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x101]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x101] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x101] = 0x40800000;
  }
  param_1[0xfd] = 1;
  iVar3 = *param_1;
  param_1[0x104] = *(int *)(iVar3 + 8);
  param_1[0x105] = *(int *)(iVar3 + 0xc);
  param_1[0x106] = *(int *)(iVar3 + 0x10);
  fVar4 = (ABS((*(float *)(iVar3 + 0xf8) - 2.0) * *(float *)(iVar3 + 0x48)) +
           ABS((*(float *)(iVar3 + 0xf4) - 2.0) * *(float *)(iVar3 + 0x44)) +
          ABS((*(float *)(iVar3 + 0xfc) - 2.0) * *(float *)(iVar3 + 0x4c))) - (float)param_1[0x101];
  fVar1 = *(float *)(iVar3 + 0x48);
  fVar2 = *(float *)(iVar3 + 0x4c);
  param_1[0x107] = (int)((float)param_1[0x104] + fVar4 * *(float *)(iVar3 + 0x44));
  param_1[0x108] = (int)((float)param_1[0x105] + fVar4 * fVar1);
  param_1[0x109] = (int)((float)param_1[0x106] + fVar4 * fVar2);
  bVar5 = false;
  fVar1 = SQRT(((float)param_1[0x109] - (float)param_1[0x106]) *
               ((float)param_1[0x109] - (float)param_1[0x106]) +
               ((float)param_1[0x108] - (float)param_1[0x105]) *
               ((float)param_1[0x108] - (float)param_1[0x105]) +
               ((float)param_1[0x107] - (float)param_1[0x104]) *
               ((float)param_1[0x107] - (float)param_1[0x104]));
  if (((byte)(fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) ||
     ((*(byte *)(iVar3 + 0x1a0) & 1) != 0)) {
    bVar5 = true;
  }
  if (bVar5) {
    param_1[0x107] = param_1[0x104];
    param_1[0x108] = param_1[0x105];
    param_1[0x109] = param_1[0x106];
  }
  fVar1 = (float)param_1[0x100];
  param_1[0x11e] =
       (uint)((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40);
  param_1[0x11f] = 0;
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


// Spawn__11CBaseEntity  @ 00100738
void Spawn__11CBaseEntity(void)

{
  return;
}


// Spawn__11CBasePlayer  @ 000cee9c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__11CBasePlayer(int *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 in_FPUControlWord;
  longdouble lVar7;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  *(int *)*param_1 = (int)"player" - (int)gpGlobals[0x26];
  *(undefined4 *)(*param_1 + 0x160) = 0x42c80000;
  *(undefined4 *)(*param_1 + 0x1bc) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 3;
  *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  *(undefined4 *)(*param_1 + 0x1a4) = 8;
  *(float *)(*param_1 + 0x1fc) = *gpGlobals + 12.0;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x40000000;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x170) = 0;
  *(undefined4 *)(*param_1 + 0x1d8) = 0;
  *(undefined4 *)(*param_1 + 0x1dc) = 0;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f800000;
  param_1[0x1f8] = -1;
  param_1[0x177] = 0;
  param_1[0x19e] = 0;
  param_1[0x201] = 0;
  param_1[0x209] = 0;
  *(undefined4 *)(*param_1 + 0x214) = 0;
  param_1[0x20a] = -1;
  param_1[0x267] = 0;
  param_1[0x47] = 0;
  *(undefined4 *)(*param_1 + 0x24c) = 0;
  (*DAT_001a8020)(*(undefined4 *)(*param_1 + 0x208),&DAT_0013acfa,&DAT_0013acf8);
  sprintf((char *)&local_20,"%u",
          teamallies & 0x1f | (DAT_001b4a88 & 0x1f) << 5 | (DAT_001b4a8c & 0x1f) << 10 |
          (DAT_001b4a90 & 0x1f) << 0xf | (DAT_001b4a94 & 0x1f) << 0x14);
  (*DAT_001a8020)(*(undefined4 *)(*param_1 + 0x208),&DAT_0013ad01,&local_20);
  param_1[0x1ef] = (int)(*gpGlobals + 2.0);
  param_1[0x1a1] = 0;
  param_1[0x1f1] = 0;
  param_1[0x137] = 0x3f000000;
  param_1[0x17b] = 0xf7;
  param_1[0x176] = 0;
  (**(code **)(param_1[0xf5] + 0x78))(param_1);
  *(undefined1 *)(param_1 + 0x269) = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x44] = 0x3f800000;
  param_1[399] = 99;
  param_1[0x18e] = 0x3f800000;
  param_1[0x196] = 0;
  param_1[0x265] = 0;
  param_1[0x264] = 0;
  param_1[0x22] = 0;
  param_1[0xed] = 0;
  param_1[0xee] = 0;
  param_1[0xec] = 0;
  param_1[0xeb] = 0;
  param_1[99] = (int)(*gpGlobals + 10.0);
  param_1[0x34a] = 0;
  param_1[0x72] = 0;
  param_1[0x33e] = 0;
  param_1[0x356] = -1;
  param_1[0x357] = -1;
  param_1[0x359] = -1;
  param_1[0x35a] = -1;
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
  bVar1 = *(byte *)((int)param_1 + 0x85);
  if ((*(byte *)(param_1 + 0x21) & 8) == 0) {
    param_1[0x21] = 0;
  }
  else {
    iVar6 = *(int *)(*param_1 + 0x20c);
    do {
      do {
        do {
          lVar7 = (longdouble)(*DAT_001a7fac)(0,0x41100000);
          uVar2 = CONCAT22(in_FPUControlWord,in_FPUControlWord) & 0xfffff3ff;
          local_20 = uVar2 | 0x400;
          uVar3 = local_20;
          local_20._2_2_ = (undefined2)(uVar2 >> 0x10);
          *(int *)(*param_1 + 0x20c) = (int)ROUND((longdouble)1.0 + ROUND(lVar7));
          in_FPUControlWord = local_20._2_2_;
          local_20 = uVar3;
          iVar4 = IsLegalClass__11CBasePlayeri(param_1,*(undefined4 *)(*param_1 + 0x20c));
        } while (iVar4 == 0);
      } while (*(int *)(*param_1 + 0x20c) == iVar6);
      iVar4 = ClassIsRestricted__Ffi((float)param_1[0x48],*(undefined4 *)(*param_1 + 0x20c));
    } while (iVar4 != 0);
    param_1[0x21] = 8;
  }
  if ((bVar1 & 0x10) != 0) {
    *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) | 0x10;
  }
  TeamFortress_ExecClassScript__11CBasePlayer(param_1);
  if (*(int *)(*param_1 + 0x20c) != 9) {
    Engineer_RemoveBuildings__11CBasePlayer(param_1);
  }
  *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
  TeamFortress_PrintClassName__11CBasePlayeri(param_1,*(undefined4 *)(*param_1 + 0x20c));
  TeamFortress_SetEquipment__11CBasePlayer(param_1);
  TeamFortress_SetHealth__11CBasePlayer(param_1);
  TeamFortress_SetSpeed__11CBasePlayer(param_1);
  TeamFortress_SetSkin__11CBasePlayer(param_1);
  param_1[0x50] = 0;
  param_1[0x62] = 0;
  param_1[0x349] = 0;
  param_1[0x348] = (int)*gpGlobals;
  param_1[0x347] = -0x40800000;
  param_1[5] = -0x10000;
  param_1[6] = (int)PlayerTouch__11CBasePlayerP11CBaseEntity;
  if (param_1[0x7d] != 0) {
    uVar5 = UTIL_dtos1__Fi(param_1[0x7d],0,0,0);
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_battleid",uVar5);
  }
  (**(code **)(*g_pGameRules + 0x60))(g_pGameRules,param_1);
  uVar5 = LookupActivity__14CBaseAnimatingi(param_1,1);
  *(undefined4 *)(*param_1 + 0x128) = uVar5;
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x1a5) & 0x40) == 0) {
    local_18 = 0x42100000;
    local_c = _FUN_0013ad68;
    iVar6 = *param_1;
  }
  else {
    local_18 = 0x41900000;
    local_c = 0xc1900000;
  }
  local_10 = 0xc1800000;
  local_1c = 0x41800000;
  local_20 = local_1c;
  local_14 = local_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar6,&local_14,&local_20);
  iVar6 = *param_1;
  local_18 = 0x41e00000;
  local_20 = 0;
  local_1c = 0;
  *(undefined4 *)(iVar6 + 0x174) = 0;
  *(undefined4 *)(iVar6 + 0x178) = 0;
  *(undefined4 *)(iVar6 + 0x17c) = 0x41e00000;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  local_1c = 0x42000000;
  local_20 = 0;
  local_18 = 0;
  param_1[0x182] = 0;
  param_1[0x183] = 0x42000000;
  param_1[0x184] = 0;
  if (param_1[0x188] == -1) {
    (*DAT_001a7f34)(1,"Couldn\'t alloc player sound slot!\n");
  }
  param_1[0x200] = 0;
  param_1[0x213] = 0;
  param_1[0x1f9] = 1;
  param_1[0x208] = -1;
  param_1[0x1fc] = 0;
  param_1[0x212] = 0;
  param_1[0x206] = -1;
  param_1[0x2b] = -0x40800000;
  param_1[0x2a] = -0x40800000;
  iVar6 = 0;
  do {
    param_1[iVar6 + 0x214] = 0;
    param_1[iVar6 + 0x234] = 0;
    param_1[iVar6 + 0x215] = 0;
    param_1[iVar6 + 0x235] = 0;
    param_1[iVar6 + 0x216] = 0;
    param_1[iVar6 + 0x236] = 0;
    param_1[iVar6 + 0x217] = 0;
    param_1[iVar6 + 0x237] = 0;
    param_1[iVar6 + 0x218] = 0;
    param_1[iVar6 + 0x238] = 0;
    param_1[iVar6 + 0x219] = 0;
    param_1[iVar6 + 0x239] = 0;
    param_1[iVar6 + 0x21a] = 0;
    param_1[iVar6 + 0x23a] = 0;
    param_1[iVar6 + 0x21b] = 0;
    param_1[iVar6 + 0x23b] = 0;
    iVar6 = iVar6 + 8;
  } while (iVar6 < 0x20);
  param_1[0x260] = 0;
  param_1[0x25f] = 0;
  (**(code **)(*g_pGameRules + 0x50))(g_pGameRules,param_1);
  return;
}


// Spawn__11CBaseTurret  @ 00106ab0
void Spawn__11CBaseTurret(int *param_1)

{
  float fVar1;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  *(undefined4 *)(*param_1 + 0x108) = 5;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  fVar1 = gpGlobals[5];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
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
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0x193] = 1;
  }
  if ((*(uint *)(*param_1 + 0x1a0) & 0x60) == 0x20) {
    param_1[0x193] = 1;
  }
  ResetSequenceInfo__14CBaseAnimating(param_1);
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  param_1[0x137] = -0x40800000;
  return;
}


// Spawn__11CBloodSplatP9entvars_s  @ 000cff9c
void Spawn__11CBloodSplatP9entvars_s(int *param_1,int param_2)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *param_1;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  fVar2 = *(float *)(param_2 + 0x10);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar3 + 0xc) = uVar1;
  *(float *)(iVar3 + 0x10) = fVar2 + 32.0;
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


// Spawn__11CCine2Slave  @ 0012b28c
void Spawn__11CCine2Slave(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine2_slave.mdl");
  return;
}


// Spawn__11CCineBarney  @ 0012b35c
void Spawn__11CCineBarney(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-barney.mdl");
  return;
}


// Spawn__11CFireAndDie  @ 001034ec
void Spawn__11CFireAndDie(undefined4 *param_1)

{
  *(int *)*param_1 = (int)"fireanddie" - *(int *)(gpGlobals + 0x98);
  return;
}


// Spawn__11CGibShooter  @ 00099470
void Spawn__11CGibShooter(int *param_1)

{
  undefined4 uVar1;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf6] = 0x3dcccccd;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xfe]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xfe] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xfe] = 0x41c80000;
  }
  SetMovedir__FP9entvars_s(*param_1);
  uVar1 = (*DAT_001a7e50)(param_1[0xfb]);
  *(undefined4 *)(*param_1 + 0x114) = uVar1;
  return;
}


// Spawn__11CItemHealth  @ 000ec944
void Spawn__11CItemHealth(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_medkit.mdl");
    Spawn__5CItem(param_1);
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0xf6] = 0x41a00000;
    }
    if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
      if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
        *(int *)(*param_1 + 0x1e8) = (int)"items/r_item1.wav" - *(int *)(gpGlobals + 0x98);
        param_1[0xf7] = 100;
        param_1[0xf8] = 1;
        return;
      }
      *(int *)(*param_1 + 0x1e8) = (int)"items/health1.wav" - *(int *)(gpGlobals + 0x98);
      param_1[0xf7] = 0x19;
    }
    else {
      *(int *)(*param_1 + 0x1e8) = (int)"items/smallmedkit1.wav" - *(int *)(gpGlobals + 0x98);
      param_1[0xf7] = 0xf;
    }
    param_1[0xf8] = 0;
  }
  return;
}


// Spawn__11CMiniTurret  @ 00106f30
void Spawn__11CMiniTurret(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/miniturret.mdl");
  *(undefined4 *)(*param_1 + 0x160) = DAT_001aa440;
  local_4 = 0x414c0000;
  local_c = 0;
  local_8 = 0;
  param_1[0x182] = 0;
  param_1[0x183] = 0;
  param_1[0x184] = 0x414c0000;
  param_1[0x187] = 0;
  *(undefined4 *)(*param_1 + 0x17c) = 0x414c0000;
  Spawn__11CBaseTurret(param_1);
  param_1[0x18c] = 0x10;
  param_1[0x18b] = 0x20;
  param_1[0x18d] = -0xf;
  local_c = 0x41800000;
  local_18 = 0xc1800000;
  local_14 = local_18;
  local_10 = local_18;
  local_8 = local_c;
  local_4 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  return;
}


// Spawn__11CNodeViewer  @ 000c00e0
void Spawn__11CNodeViewer(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int local_c;
  
  if ((WorldGraph == 0) || (DAT_001a82a4 == 0)) {
    (*DAT_001a7f34)(1,"Graph not ready!\n");
    UTIL_Remove__FP11CBaseEntity(param_1);
    return;
  }
  iVar2 = strcmp((char *)(*(int *)*param_1 + gpGlobals[0x26]),"node_viewer_fly");
  if (iVar2 == 0) {
    param_1[0x1f9] = 3;
    param_1[0x1fa] = 2;
    iVar2 = 0x42c80000;
    iVar1 = 0x437f0000;
    local_c = 0x43200000;
  }
  else {
    iVar2 = strcmp((char *)(*(int *)*param_1 + gpGlobals[0x26]),"node_viewer_large");
    if (iVar2 != 0) {
      param_1[0x1f9] = 1;
      param_1[0x1fa] = 5;
      param_1[0x1fb] = 0x437f0000;
      param_1[0x1fc] = 0x43200000;
      param_1[0x1fd] = 0x42c80000;
      iVar2 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,param_1[0x1fa]);
      param_1[0xf6] = iVar2;
      if (iVar2 < 0) {
        (*DAT_001a7f34)(1,"No nearby node\n");
        return;
      }
      param_1[0xf8] = 0;
      (*DAT_001a7f34)(2,"basenode %d\n",param_1[0xf6]);
      if (DAT_001a82b8 < 0x80) {
        if (0 < DAT_001a82b8) {
          iVar2 = 0;
          do {
            uVar3 = NextNodeInRoute__6CGraphiiii(&WorldGraph,iVar2,param_1[0xf6],param_1[0x1f9],0);
            AddNode__11CNodeViewerii(param_1,iVar2,uVar3);
            iVar2 = iVar2 + 1;
          } while (iVar2 < DAT_001a82b8);
        }
      }
      else {
        FindNodeConnections__11CNodeVieweri(param_1,param_1[0xf6]);
        iVar2 = 0;
        do {
          iVar1 = param_1[0xf8];
          if (iVar2 < iVar1) {
            uVar4 = iVar1 - iVar2 & 3;
            if (uVar4 != 0) {
              if (1 < uVar4) {
                if (2 < uVar4) {
                  FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0xf9]);
                  FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0x179]);
                  iVar2 = iVar2 + 1;
                }
                FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0xf9]);
                FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0x179]);
                iVar2 = iVar2 + 1;
              }
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0xf9]);
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0x179]);
              iVar2 = iVar2 + 1;
              if (iVar1 <= iVar2) goto LAB_000c04f5;
            }
            do {
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0xf9]);
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0x179]);
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0xfa]);
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0x17a]);
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0xfb]);
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0x17b]);
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0xfc]);
              FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0x17c]);
              iVar2 = iVar2 + 4;
            } while (iVar2 < iVar1);
          }
LAB_000c04f5:
        } while (iVar1 != param_1[0xf8]);
      }
      (*DAT_001a7f34)(2,"%d nodes\n",param_1[0xf8]);
      param_1[0xf7] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)DrawThink__11CNodeViewer;
      *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
      return;
    }
    param_1[0x1f9] = 2;
    param_1[0x1fa] = 5;
    iVar2 = 0x437f0000;
    iVar1 = 0x43200000;
    local_c = 0x42c80000;
  }
  param_1[0x1fb] = local_c;
  param_1[0x1fc] = iVar2;
  param_1[0x1fd] = iVar1;
  FUN_000c0258();
  return;
}


// Spawn__11CNullEntity  @ 000e6ac8
void Spawn__11CNullEntity(int *param_1)

{
  (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Spawn__11CPathCorner  @ 000c11d0
void Spawn__11CPathCorner(void)

{
  return;
}


// Spawn__11CTFAssaultC  @ 00115e60
void Spawn__11CTFAssaultC(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_ac" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 4;
  param_1[0x113] = 0x19;
  param_1[0x10b] = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__11CTFGoalItem  @ 000faaa8
void Spawn__11CTFGoalItem(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    *(int *)*param_1 = (int)"item_tfgoal" - *(int *)(gpGlobals + 0x98);
    if (*(int *)(*param_1 + 0xb8) != 0) {
      (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
      (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                      *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
      uVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,"not_carried");
      *(undefined4 *)(*param_1 + 0x128) = uVar3;
      if (*(int *)(*param_1 + 0x128) != -1) {
        ResetSequenceInfo__14CBaseAnimating(param_1);
        *(undefined4 *)(*param_1 + 0x130) = 0;
      }
    }
    (*DAT_001a7e44)("items/itembk2.wav");
    if (*(int *)(*param_1 + 0x1e8) != 0) {
      (*DAT_001a7e44)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
    }
    if (param_1[0x86] == 0) {
      param_1[0x86] = 2;
    }
    if ((*(byte *)((int)param_1 + 0x221) & 0x20) == 0) {
      *(undefined4 *)(*param_1 + 0x10c) = 1;
    }
    else {
      *(undefined4 *)(*param_1 + 0x10c) = 2;
      bVar4 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0x9e])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0x9e]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN((float)param_1[0x9f])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_001a7e04 == (float)param_1[0x9f]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa0];
        bVar4 = (byte)(DAT_001a7e08 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar4) {
        param_1[0x9e] = -0x3e800000;
        param_1[0x9f] = -0x3e800000;
        param_1[0xa0] = -0x3e400000;
      }
      bVar4 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0xa1])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0xa1]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN((float)param_1[0xa2])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_001a7e04 == (float)param_1[0xa2]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa3];
        bVar4 = (byte)(DAT_001a7e08 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar4) {
        param_1[0xa1] = 0x41800000;
        param_1[0xa2] = 0x41800000;
        param_1[0xa3] = 0x42000000;
      }
    }
    if (*(int *)(*param_1 + 0x1d0) == 0) {
      *(int *)(*param_1 + 0x1d0) = (int)"goalitem" - *(int *)(gpGlobals + 0x98);
    }
    fVar1 = (float)param_1[0xc1];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      param_1[0xc1] = 0x42700000;
    }
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,param_1 + 0x9e,param_1 + 0xa1);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    param_1[5] = -0x10000;
    param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
    StartItem__11CTFGoalItem(param_1);
  }
  return;
}


// Spawn__11CTestEffect  @ 00099d20
void Spawn__11CTestEffect(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0xc))(param_1);
  return;
}


// Spawn__11CWallHealth  @ 000ab1b4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__11CWallHealth(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[0x120] = (int)ROUND(_DAT_001aa4a0);
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


// Spawn__12CAutoTrigger  @ 00101950
void Spawn__12CAutoTrigger(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0xc))(param_1);
  return;
}


// Spawn__12CChangeLevel  @ 0010378c
void Spawn__12CChangeLevel(int *param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(param_1 + 0x11e),"");
  if (iVar1 == 0) {
    (*DAT_001a7f34)(1,"a trigger_changelevel doesn\'t have a map");
  }
  iVar1 = strcmp((char *)(param_1 + 0x126),"");
  if (iVar1 == 0) {
    (*DAT_001a7f34)(1,"trigger_changelevel to %s doesn\'t have a landmark",param_1 + 0x11e);
  }
  if (*(int *)(*param_1 + 0x1cc) != 0) {
    param_1[7] = -0x10000;
    param_1[8] = (int)UseChangeLevel__12CChangeLevelP11CBaseEntityT18USE_TYPEf;
  }
  InitTrigger__12CBaseTrigger(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)TouchChangeLevel__12CChangeLevelP11CBaseEntity;
  }
  return;
}


// Spawn__12CCine3Barney  @ 0012b1bc
void Spawn__12CCine3Barney(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine3-barney.mdl");
  return;
}


// Spawn__12CCineMonster  @ 000dbf10
void Spawn__12CCineMonster(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  if ((*(int *)(*param_1 + 0x1cc) == 0) || (param_1[0x187] != 0)) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__12CCineMonster;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
    if (*(int *)(*param_1 + 0x1cc) != 0) {
      param_1[399] = (int)(*gpGlobals + 1e+06);
    }
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
    param_1[0x193] = 1;
  }
  else {
    param_1[0x193] = 0;
  }
  return;
}


// Spawn__12CCinePanther  @ 0012b3c4
void Spawn__12CCinePanther(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-panther.mdl");
  return;
}


// Spawn__12CCyclerProbe  @ 000a95cc
void Spawn__12CCyclerProbe(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *param_1;
  local_c = 0x41800000;
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 16.0;
  local_18 = 0xc1800000;
  local_14 = local_18;
  local_10 = local_18;
  local_8 = local_c;
  local_4 = local_c;
  GenericCyclerSpawn__7CCyclerPcG6VectorT2(param_1,"models/prdroid.mdl",&local_18,&local_c);
  return;
}


// Spawn__12CEnvBeverage  @ 0009af54
void Spawn__12CEnvBeverage(int *param_1)

{
  float fVar1;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
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


// Spawn__12CFuncPlatRot  @ 000c3020
void Spawn__12CFuncPlatRot(undefined4 param_1)

{
  Spawn__9CFuncPlat(param_1);
  SetupRotation__12CFuncPlatRot(param_1);
  return;
}


// Spawn__12CHandGrenade  @ 000aa640
void Spawn__12CHandGrenade(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 0xc;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_grenade.mdl");
  *(undefined4 *)(*param_1 + 0x1e0) = DAT_001aa47c;
  param_1[0x113] = 5;
  FallInit__15CBasePlayerItem(param_1);
  return;
}


// Spawn__12CItemBattery  @ 0012c2a4
void Spawn__12CItemBattery(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_battery.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__12CItemPowerup  @ 000ed7f0
void Spawn__12CItemPowerup(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    Spawn__5CItem(param_1);
    local_c = 0x41800000;
    local_18 = 0xc1800000;
    local_10 = 0;
    local_14 = local_18;
    local_8 = local_c;
    local_4 = local_c;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  }
  return;
}


// Spawn__12CMultiSource  @ 00082be0
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


// Spawn__12CNoBuildArea  @ 0009c814
void Spawn__12CNoBuildArea(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__12CPointEntity  @ 000e6ab4
void Spawn__12CPointEntity(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  return;
}


// Spawn__12CTFAutoRifle  @ 001167b4
void Spawn__12CTFAutoRifle(void)

{
  FUN_001167bb();
  return;
}


// Spawn__12CTFDispenser  @ 00091798
void Spawn__12CTFDispenser(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(int *)*param_1 = (int)"building_dispenser" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  iVar1 = *param_1;
  local_4 = 0x41000000;
  local_c = 0;
  local_8 = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41000000;
  *(undefined4 *)(*param_1 + 0x1b0) = 0x43160000;
  *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/dispenser.mdl");
  local_c = 0x41800000;
  local_4 = 0x41c00000;
  local_18 = 0xc1800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  return;
}


// Spawn__12CTFRpgRocket  @ 000f3c14
void Spawn__12CTFRpgRocket(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 9;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  param_1[0x188] = 1;
  param_1[0x189] = 1;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),FUN_0013ea2c);
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_rpg_rocket" - (int)gpGlobals[0x26];
  param_1[0xde] = (int)"rocket" - (int)gpGlobals[0x26];
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


// Spawn__12CTFSentrygun  @ 000de614
void Spawn__12CTFSentrygun(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(char **)*param_1 = "?building_sentrygun" + (1 - (int)gpGlobals[0x26]);
  *(undefined4 *)(*param_1 + 0x160) = 0x43160000;
  *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
  *(undefined4 *)(*param_1 + 0x108) = 5;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
  iVar1 = *param_1;
  local_4 = 0x41b00000;
  local_c = 0;
  local_8 = 0;
  *(undefined4 *)(iVar1 + 0x174) = 0;
  *(undefined4 *)(iVar1 + 0x178) = 0;
  *(undefined4 *)(iVar1 + 0x17c) = 0x41b00000;
  param_1[0xde] = (int)"sentrygun" - (int)gpGlobals[0x26];
  param_1[0x23] = 1;
  param_1[0x28] = 0x2d;
  param_1[0x29] = 0x13b;
  param_1[0x18a] = 6;
  param_1[0x192] = g_vecZero;
  param_1[0x193] = DAT_001a7e04;
  param_1[0x194] = DAT_001a7e08;
  param_1[0x137] = 0x3f333333;
  param_1[0x33] = 0x19;
  param_1[0x30] = 100;
  param_1[0x38] = 0x14;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/sentry1.mdl");
  local_c = 0x41800000;
  local_4 = 0x42400000;
  local_18 = 0xc1800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x11f,0);
  param_1[3] = -0x10000;
  param_1[4] = (int)SentryRotate__12CTFSentrygun;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  return;
}


// Spawn__12CTFTimerGoal  @ 000fa9f4
void Spawn__12CTFTimerGoal(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    Spawn__7CTFGoal(param_1);
    *(int *)*param_1 = (int)FUN_00140fb4 - *(int *)(gpGlobals + 0x98);
    fVar1 = (float)param_1[0x93];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      *(undefined4 *)(*param_1 + 0x10c) = 0;
    }
    else {
      (*DAT_001a7f34)(1,"Timer Goal %s created with no specified time.\n",
                      *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98));
      dremove__FP11CBaseEntity(param_1);
    }
  }
  return;
}


// Spawn__12CTriggerHurt  @ 00102958
void Spawn__12CTriggerHurt(int *param_1)

{
  longdouble lVar1;
  
  InitTrigger__12CBaseTrigger(param_1);
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
  if ((*(byte *)((int)param_1 + 0x472) & 4) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)RadiationThink__12CTriggerHurt;
    lVar1 = (longdouble)(*DAT_001a7fac)(0,0x3f000000);
    *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__12CTriggerOnce  @ 00102fe4
void Spawn__12CTriggerOnce(int param_1)

{
  *(undefined4 *)(param_1 + 0x400) = 0xbf800000;
  Spawn__16CTriggerMultiple(param_1);
  return;
}


// Spawn__12CTriggerPush  @ 001047b4
void Spawn__12CTriggerPush(int *param_1)

{
  float fVar1;
  bool bVar2;
  
  bVar2 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x50))) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x50)) << 0xe) >> 8)) ==
       0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x54),
     (byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_001a7e04 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 0x58);
    bVar2 = (byte)(DAT_001a7e08 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar2) {
    *(undefined4 *)(*param_1 + 0x54) = 0x43b40000;
  }
  InitTrigger__12CBaseTrigger(param_1);
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
  }
  param_1[7] = -0x10000;
  param_1[8] = (int)ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__12CTriggerSave  @ 00104cc4
void Spawn__12CTriggerSave(int *param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(gpGlobals + 0x14);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    InitTrigger__12CBaseTrigger(param_1);
    param_1[5] = -0x10000;
    param_1[6] = (int)SaveTouch__12CTriggerSaveP11CBaseEntity;
  }
  else {
    (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


// Spawn__12CXenSporeMed  @ 001155dc
void Spawn__12CXenSporeMed(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x110) = 1;
  Spawn__9CXenSpore(param_1);
  local_c = 0x42200000;
  local_4 = 0x42f00000;
  local_18 = 0xc2200000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  return;
}


// Spawn__13CButtonTarget  @ 0008568c
void Spawn__13CButtonTarget(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
  }
  return;
}


// Spawn__13CCyclerSprite  @ 000a9aac
void Spawn__13CCyclerSprite(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0xf6] = 1;
  param_1[0xf7] = (int)*gpGlobals;
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  iVar1 = (*DAT_001a7e50)(*(undefined4 *)(*param_1 + 0xb4));
  param_1[0xf8] = (int)((float)iVar1 - 1.0);
  return;
}


// Spawn__13CEnvExplosion  @ 0009ccec
void Spawn__13CEnvExplosion(int *param_1)

{
  float fVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  fVar1 = (float)(param_1[0x187] + -0x32) * 0.6;
  if (0x3f < (byte)((10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) - 1)) {
    fVar1 = 10.0;
  }
  param_1[0x188] = (int)ROUND(fVar1);
  return;
}


// Spawn__13CFuncConveyor  @ 0008073c
void Spawn__13CFuncConveyor(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  
  SetMovedir__FP9entvars_s(*param_1);
  Spawn__9CFuncWall(param_1);
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
    pbVar1 = (byte *)(*param_1 + 0x1a4);
    *pbVar1 = *pbVar1 | 4;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x110) = 0;
  }
  fVar2 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
  }
  UpdateSpeed__13CFuncConveyorf(param_1,*(undefined4 *)(*param_1 + 0x1f8));
  return;
}


// Spawn__13CFuncRotating  @ 00080cc4
void Spawn__13CFuncRotating(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_4;
  
  param_1[0xf9] = 0x42c60000;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf8]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf8] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf8] = 0x3f800000;
  }
  param_1[0xf7] = 0x3f4ccccd;
  if (*(char *)(*param_1 + 0x1a0) < '\0') {
    param_1[0xf7] = 0x40000000;
  }
  else if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    if ((*(byte *)(*param_1 + 0x1a1) & 2) != 0) {
      param_1[0xf7] = 0x3f4ccccd;
    }
  }
  else {
    param_1[0xf7] = 0x3fa00000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf6] = 0x3f800000;
  }
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 4) == 0) {
    iVar2 = *param_1;
    if ((*(byte *)(iVar2 + 0x1a0) & 8) == 0) {
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x44) = 0;
      *(undefined4 *)(iVar2 + 0x48) = 0x3f800000;
      *(undefined4 *)(iVar2 + 0x4c) = 0;
      goto LAB_00080e07;
    }
    local_c = 0x3f800000;
    local_4 = 0;
  }
  else {
    local_c = 0;
    local_4 = 0x3f800000;
  }
  *(undefined4 *)(iVar2 + 0x44) = local_c;
  *(undefined4 *)(iVar2 + 0x48) = 0;
  *(undefined4 *)(iVar2 + 0x4c) = local_4;
LAB_00080e07:
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 2) != 0) {
    *(float *)(iVar2 + 0x44) = *(float *)(iVar2 + 0x44) * -1.0;
    *(float *)(iVar2 + 0x48) = *(float *)(iVar2 + 0x48) * -1.0;
    *(float *)(iVar2 + 0x4c) = *(float *)(iVar2 + 0x4c) * -1.0;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 0x40) == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x110) = 0xffffffff;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[7] = -0x10000;
  param_1[8] = (int)RotatingUse__13CFuncRotatingP11CBaseEntityT18USE_TYPEf;
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0;
  }
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 1) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_CallUseToggle__11CBaseEntity;
    *(float *)(iVar2 + 0x104) = *(float *)(iVar2 + 0x100) + 1.5;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)HurtTouch__13CFuncRotatingP11CBaseEntity;
  }
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  return;
}


// Spawn__13CItemAntidote  @ 0012c01c
void Spawn__13CItemAntidote(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_antidote.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CItemArmorRed  @ 000ed0a4
void Spawn__13CItemArmorRed(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/r_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0xf7] = 0x43480000;
    param_1[0xf8] = 0x3f4ccccd;
  }
  return;
}


// Spawn__13CItemLongJump  @ 0012be78
void Spawn__13CItemLongJump(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_longjump.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CItemSecurity  @ 0012bf38
void Spawn__13CItemSecurity(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_security.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CMultiManager  @ 00101d2c
void Spawn__13CMultiManager(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  float *pfVar4;
  float *pfVar5;
  int *piVar6;
  int *local_10;
  int local_4;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf;
  param_1[3] = -0x10000;
  param_1[4] = (int)ManagerThink__13CMultiManager;
  do {
    bVar3 = false;
    local_4 = 1;
    if (1 < param_1[0x11e]) {
      pfVar4 = (float *)(param_1 + 0x131);
      piVar6 = param_1 + 0x121;
      pfVar5 = (float *)(param_1 + 0x132);
      local_10 = param_1 + 0x122;
      do {
        fVar1 = *pfVar5;
        if (fVar1 < *pfVar4) {
          iVar2 = *local_10;
          *local_10 = *piVar6;
          *pfVar5 = *pfVar4;
          *piVar6 = iVar2;
          *pfVar4 = fVar1;
          bVar3 = true;
        }
        pfVar4 = pfVar4 + 1;
        piVar6 = piVar6 + 1;
        pfVar5 = pfVar5 + 1;
        local_10 = local_10 + 1;
        local_4 = local_4 + 1;
      } while (local_4 < param_1[0x11e]);
    }
  } while (bVar3);
  return;
}


// Spawn__13CTriggerRelay  @ 00101b48
void Spawn__13CTriggerRelay(void)

{
  return;
}


// Spawn__13CWeaponCycler  @ 000a9d6c
void Spawn__13CWeaponCycler(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  param_1[0x114] = *(int *)(iVar1 + 0xb8);
  param_1[0x115] = *(int *)(iVar1 + 0xb4);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,iVar1 + 8);
  local_c = 0x41800000;
  local_18 = 0xc1800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  local_4 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CBaseSpectator  @ 000e46f8
void Spawn__14CBaseSpectator(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x1a4) = 0x4000000;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 8;
  param_1[1] = 0;
  return;
}


// Spawn__14CCineScientist  @ 0012b494
void Spawn__14CCineScientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-scientist.mdl");
  return;
}


// Spawn__14CGenericCycler  @ 0012b7c4
void Spawn__14CGenericCycler(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0xc1800000;
  local_4 = 0;
  local_18 = 0x41800000;
  local_10 = 0x42900000;
  local_14 = local_18;
  local_8 = local_c;
  GenericCyclerSpawn__7CCyclerPcG6VectorT2
            (param_1,*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98),&local_c,&local_18);
  return;
}


// Spawn__14CItemAmmoCells  @ 000ed730
void Spawn__14CItemAmmoCells(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0xf7] = (int)("?models/w_battery.mdl" + (1 - *(int *)(gpGlobals + 0x98)));
    param_1[0xf8] = (int)("?models/w_battery.mdl" + (1 - *(int *)(gpGlobals + 0x98)));
    *(int *)(*param_1 + 0x1d0) = (int)"cells" - *(int *)(gpGlobals + 0x98);
    param_1[0x37] = 5;
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__14CItemAmmoNails  @ 000ed480
void Spawn__14CItemAmmoNails(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0xf7] = (int)"models/w_crossbow_clip.mdl" - *(int *)(gpGlobals + 0x98);
    param_1[0xf8] = (int)"models/w_crossbow_clip.mdl" - *(int *)(gpGlobals + 0x98);
    *(int *)(*param_1 + 0x1d0) = (int)"nails" - *(int *)(gpGlobals + 0x98);
    param_1[0x35] = 0x19;
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__14CMomentaryDoor  @ 00094f1c
void Spawn__14CMomentaryDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  
  SetMovedir__FP9entvars_s(*param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
  }
  fVar1 = *(float *)(*param_1 + 0x1e0);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1e0) = 0x40000000;
  }
  iVar3 = *param_1;
  param_1[0x104] = *(int *)(iVar3 + 8);
  param_1[0x105] = *(int *)(iVar3 + 0xc);
  param_1[0x106] = *(int *)(iVar3 + 0x10);
  fVar4 = (ABS((*(float *)(iVar3 + 0xf8) - 2.0) * *(float *)(iVar3 + 0x48)) +
           ABS((*(float *)(iVar3 + 0xf4) - 2.0) * *(float *)(iVar3 + 0x44)) +
          ABS((*(float *)(iVar3 + 0xfc) - 2.0) * *(float *)(iVar3 + 0x4c))) - (float)param_1[0x101];
  fVar1 = *(float *)(iVar3 + 0x48);
  fVar2 = *(float *)(iVar3 + 0x4c);
  param_1[0x107] = (int)((float)param_1[0x104] + fVar4 * *(float *)(iVar3 + 0x44));
  param_1[0x108] = (int)((float)param_1[0x105] + fVar4 * fVar1);
  param_1[0x109] = (int)((float)param_1[0x106] + fVar4 * fVar2);
  if ((*(byte *)(iVar3 + 0x1a0) & 1) != 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar3,param_1 + 0x107);
    param_1[0x107] = param_1[0x104];
    param_1[0x108] = param_1[0x105];
    param_1[0x109] = param_1[0x106];
    iVar3 = *param_1;
    param_1[0x104] = *(int *)(iVar3 + 8);
    param_1[0x105] = *(int *)(iVar3 + 0xc);
    param_1[0x106] = *(int *)(iVar3 + 0x10);
  }
  param_1[5] = 0;
  param_1[6] = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  return;
}


// Spawn__14CTFIncendiaryC  @ 0011a114
void Spawn__14CTFIncendiaryC(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 8;
  param_1[0x2c] = 0;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_rpg.mdl");
  param_1[0x113] = 0x32;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CTFNailgunNail  @ 000f2dd8
void Spawn__14CTFNailgunNail(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 9;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),FUN_0013ea2c);
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_nailgun_nail" - (int)gpGlobals[0x26];
  param_1[0xde] = (int)"nails" - (int)gpGlobals[0x26];
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


// Spawn__14CTFSniperRifle  @ 0011cbf0
void Spawn__14CTFSniperRifle(int *param_1)

{
  param_1[0x108] = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 6;
  param_1[0x113] = 5;
  param_1[0x109] = -0x40800000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CTargetCDAudio  @ 001027cc
void Spawn__14CTargetCDAudio(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  if (0.0 < *(float *)(*param_1 + 0x144)) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  }
  return;
}


// Spawn__14CTelefragDeath  @ 00105e10
void Spawn__14CTelefragDeath(int *param_1)

{
  int iVar1;
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
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x58) = DAT_001a7e08;
  local_18 = 0x41800000;
  local_10 = 0x42100000;
  local_24 = 0x40800000;
  local_c = 0x41a00000;
  local_4 = 0x42200000;
  local_30 = 0xc1a00000;
  local_28 = 0xc2200000;
  local_2c = local_30;
  local_20 = local_24;
  local_1c = local_24;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_30,&local_c);
  param_1[5] = -0x10000;
  param_1[6] = (int)DeathTouch__14CTelefragDeathP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  return;
}


// Spawn__14CTriggerCamera  @ 00105238
void Spawn__14CTriggerCamera(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x108) = 8;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 2;
  param_1[0x103] = *(int *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x104]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x104] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x104] = 0x43fa0000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x105]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x105] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x105] = 0x43fa0000;
  }
  return;
}


// Spawn__14CTriggerVolume  @ 0010345c
void Spawn__14CTriggerVolume(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xb8) = 0;
  *(undefined4 *)(*param_1 + 0xb4) = 0;
  return;
}


// Spawn__14CXenSporeLarge  @ 00115654
void Spawn__14CXenSporeLarge(int *param_1)

{
  int iVar1;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  *(undefined4 *)(*param_1 + 0x110) = 2;
  Spawn__9CXenSpore(param_1);
  local_c = 48.0;
  local_4 = 240.0;
  local_18 = -48.0;
  local_10 = 110.0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  (*DAT_001a7e90)(*param_1 + 0x50,&local_18,&local_c,0);
  local_30 = _14CXenSporeLarge_m_hullSizes * local_18;
  local_2c = _14CXenSporeLarge_m_hullSizes * local_14;
  local_28 = _14CXenSporeLarge_m_hullSizes * local_10;
  local_3c = DAT_001b5c64 * local_c;
  local_38 = DAT_001b5c64 * local_8;
  local_34 = DAT_001b5c64 * local_4;
  local_24 = local_30 + local_3c;
  local_20 = local_2c + local_38;
  local_1c = local_28 + local_34;
  local_48 = 0x41400000;
  local_44 = 0x41400000;
  local_40 = 0x42f00000;
  local_54 = 0xc1400000;
  local_4c = 0;
  local_50 = local_54;
  CreateHull__8CXenHullP11CBaseEntityRC6VectorN22(param_1,&local_54,&local_48,&local_24);
  iVar1 = 0xc;
  local_58 = 1;
  do {
    local_28 = *(float *)((int)&_14CXenSporeLarge_m_hullSizes + iVar1);
    local_30 = local_28 * local_18;
    local_2c = local_28 * local_14;
    local_28 = local_28 * local_10;
    local_34 = *(float *)((int)&DAT_001b5c64 + iVar1);
    local_3c = local_34 * local_c;
    local_38 = local_34 * local_8;
    local_34 = local_34 * local_4;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_1c = local_28 + local_34;
    local_48 = 0x41400000;
    local_44 = 0x41400000;
    local_40 = 0x42f00000;
    local_54 = 0xc1400000;
    local_50 = 0xc1400000;
    local_4c = 0;
    CreateHull__8CXenHullP11CBaseEntityRC6VectorN22(param_1,&local_54,&local_48,&local_24);
    local_28 = *(float *)((int)&DAT_001b5c6c + iVar1);
    local_30 = local_28 * local_18;
    local_2c = local_28 * local_14;
    local_28 = local_28 * local_10;
    local_34 = *(float *)((int)&DAT_001b5c70 + iVar1);
    local_3c = local_34 * local_c;
    local_38 = local_34 * local_8;
    local_34 = local_34 * local_4;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_1c = local_28 + local_34;
    local_48 = 0x41400000;
    local_44 = 0x41400000;
    local_40 = 0x42f00000;
    local_54 = 0xc1400000;
    local_50 = 0xc1400000;
    local_4c = 0;
    CreateHull__8CXenHullP11CBaseEntityRC6VectorN22(param_1,&local_54,&local_48,&local_24);
    iVar1 = iVar1 + 0x18;
    local_58 = local_58 + 2;
  } while (local_58 < 5);
  return;
}


// Spawn__14CXenSporeSmall  @ 00115564
void Spawn__14CXenSporeSmall(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x110) = 0;
  Spawn__9CXenSpore(param_1);
  local_c = 0x41800000;
  local_4 = 0x42800000;
  local_18 = 0xc1800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  return;
}


// Spawn__15CAmbientGeneric  @ 000e0b0c
void Spawn__15CAmbientGeneric(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
      if (((*(byte *)(*param_1 + 0x1a0) & 4) == 0) && ((*(byte *)(*param_1 + 0x1a0) & 8) != 0)) {
        param_1[0xf6] = 0x3f4ccccd;
      }
      else {
        param_1[0xf6] = 0x3fa00000;
      }
    }
    else {
      param_1[0xf6] = 0x40000000;
    }
  }
  else {
    param_1[0xf6] = 0;
  }
  if (*(int *)(*param_1 + 0x1d4) != 0) {
    iVar2 = -1;
    pcVar3 = (char *)((int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1d4));
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      *(undefined4 *)(*param_1 + 0x10c) = 0;
      *(undefined4 *)(*param_1 + 0x108) = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)RampThink__15CAmbientGeneric;
      *(undefined4 *)(*param_1 + 0x104) = 0;
      param_1[7] = -0x10000;
      param_1[8] = (int)ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf;
      param_1[0x110] = 0;
      if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
        param_1[0x111] = 1;
      }
      else {
        param_1[0x111] = 0;
      }
      (**(code **)(param_1[0xf5] + 0xc))();
      return;
    }
  }
  iVar2 = *param_1;
  (*DAT_001a7f34)(4,"EMPTY AMBIENT AT: %f, %f, %f\n",(double)*(float *)(iVar2 + 8),
                  (double)*(float *)(iVar2 + 0xc),(double)*(float *)(iVar2 + 0x10));
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__15CBasePlayerAmmo  @ 00111020
void Spawn__15CBasePlayerAmmo(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  local_c = 0x41800000;
  local_18 = 0xc1800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  local_4 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerAmmoP11CBaseEntity;
  return;
}


// Spawn__15CCine2Scientist  @ 0012b42c
void Spawn__15CCine2Scientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine2-scientist.mdl");
  return;
}


// Spawn__15CCine3Scientist  @ 0012b224
void Spawn__15CCine3Scientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine3-scientist.mdl");
  return;
}


// Spawn__15CFuncTrackTrain  @ 000c58bc
void Spawn__15CFuncTrackTrain(int *param_1)

{
  int iVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x1f8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf9] = 0x42c80000;
  }
  else {
    param_1[0xf9] = *(int *)(*param_1 + 0x1f8);
  }
  *(undefined4 *)(*param_1 + 0x1f8) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x28) = DAT_001a7e08;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
  *(int *)(*param_1 + 0x184) = (int)ROUND((float)param_1[0xf9]);
  param_1[0xfa] = 0x3f800000;
  if (*(int *)(*param_1 + 0x1c8) == 0) {
    (*DAT_001a7f34)(1,"FuncTrain with no target");
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 8) == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = *param_1;
  param_1[0xfc] = *(int *)(iVar1 + 0xdc);
  param_1[0xfd] = *(int *)(iVar1 + 0xe0);
  param_1[0xfe] = *(int *)(iVar1 + 0xe4);
  param_1[0xff] = *(int *)(iVar1 + 0xe8);
  param_1[0x100] = *(int *)(iVar1 + 0xec);
  param_1[0x101] = *(int *)(iVar1 + 0xf0);
  param_1[0x101] = (int)((float)param_1[0x101] + 72.0);
  NextThink__15CFuncTrackTrainfi(param_1,*(float *)(iVar1 + 0x100) + 0.1,0);
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__15CFuncTrackTrain;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  return;
}


// Spawn__15CFuncWallToggle  @ 00080614
void Spawn__15CFuncWallToggle(int *param_1)

{
  Spawn__9CFuncWall(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
    TurnOff__15CFuncWallToggle(param_1);
  }
  return;
}


// Spawn__15CGenericMonster  @ 000a5d78
void Spawn__15CGenericMonster(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = strcmp((char *)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98)),
                 "models/player.mdl");
  if (iVar1 != 0) {
    iVar1 = strcmp((char *)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98)),
                   "models/holo.mdl");
    if (iVar1 != 0) {
      local_14 = 0x41800000;
      local_10 = 0x42900000;
      puVar3 = &local_18;
      local_8 = 0xc1800000;
      local_4 = 0;
      puVar2 = &local_c;
      goto LAB_000a5e90;
    }
  }
  local_8 = 0x41800000;
  local_4 = 0x42100000;
  puVar3 = &local_c;
  local_14 = 0xc1800000;
  local_10 = 0xc2100000;
  puVar2 = &local_18;
LAB_000a5e90:
  local_18 = local_14;
  local_c = local_8;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,puVar2,puVar3);
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 4;
  param_1[0x17b] = 0xf7;
  *(undefined4 *)(*param_1 + 0x160) = 0x41000000;
  param_1[0x137] = 0x3f000000;
  param_1[0x13d] = 0;
  (**(code **)(param_1[0xf5] + 0x11c))(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 4) != 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x16c) = 0;
  }
  return;
}


// Spawn__15CItemAmmoShells  @ 000ed3a4
void Spawn__15CItemAmmoShells(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0xf7] = (int)"models/w_shotbox.mdl" - *(int *)(gpGlobals + 0x98);
    param_1[0xf8] = (int)"models/w_shotbox.mdl" - *(int *)(gpGlobals + 0x98);
    *(int *)(*param_1 + 0x1d0) = (int)"shells" - *(int *)(gpGlobals + 0x98);
    param_1[0x33] = 0x14;
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__15CItemArmorGreen  @ 000ecf14
void Spawn__15CItemArmorGreen(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/g_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0xf7] = 0x42c80000;
    param_1[0xf8] = 0x3e99999a;
  }
  return;
}


// Spawn__15CTFFlamethrower  @ 00118e70
void Spawn__15CTFFlamethrower(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 10;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_egon.mdl");
  param_1[0x113] = 0x32;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__15CTFPrimeGrenade  @ 000ef358
void Spawn__15CTFPrimeGrenade(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (**(code **)(param_1[0xf5] + 0x220))(param_1);
  (**(code **)(param_1[0xf5] + 0x230))(param_1);
  (**(code **)(param_1[0xf5] + 0x234))(param_1);
  (**(code **)(param_1[0xf5] + 0x238))(param_1);
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  param_1[0x188] = 0;
  param_1[0x189] = 1;
  param_1[0x18b] = 0;
  param_1[0x18a] = 0;
  param_1[0x18c] = 0;
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_000ef42e;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_000ef42e:
  param_1[0x48] = *(int *)(iVar1 + 0x120);
  return;
}


// Spawn__15CTFSuperShotgun  @ 0011c708
void Spawn__15CTFSuperShotgun(int param_1)

{
  Spawn__10CTFShotgun(param_1);
  *(undefined4 *)(param_1 + 0x44c) = 0x10;
  *(undefined4 *)(param_1 + 0x458) = 0x10;
  *(undefined4 *)(param_1 + 0x41c) = 0x3ec00000;
  *(undefined4 *)(param_1 + 0x454) = 2;
  return;
}


// Spawn__15CTriggerCDAudio  @ 00102610
void Spawn__15CTriggerCDAudio(undefined4 param_1)

{
  InitTrigger__12CBaseTrigger(param_1);
  return;
}


// Spawn__15CTriggerCounter  @ 001033fc
void Spawn__15CTriggerCounter(int param_1)

{
  *(undefined4 *)(param_1 + 0x400) = 0xbf800000;
  if (*(int *)(param_1 + 0x440) == 0) {
    *(undefined4 *)(param_1 + 0x440) = 2;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0xffff0000;
  *(code **)(param_1 + 0x20) = CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  return;
}


// Spawn__15CTriggerGravity  @ 00104fa4
void Spawn__15CTriggerGravity(void)

{
  FUN_00104fab();
  return;
}


// Spawn__16CFuncIllusionary  @ 00080954
void Spawn__16CFuncIllusionary(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x58) = DAT_001a7e08;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Spawn__16CFuncMonsterClip  @ 000809e4
void Spawn__16CFuncMonsterClip(int *param_1)

{
  longdouble lVar1;
  
  Spawn__9CFuncWall(param_1);
  lVar1 = (longdouble)(*DAT_001a7f24)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0.0) || NAN(lVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0.0 == lVar1) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x118) = 0x80;
  }
  *(byte *)(*param_1 + 0x1a6) = *(byte *)(*param_1 + 0x1a6) | 0x80;
  return;
}


// Spawn__16CFuncMortarField  @ 000b7d98
void Spawn__16CFuncMortarField(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  param_1[7] = -0x10000;
  param_1[8] = (int)FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  return;
}


// Spawn__16CFuncTrackChange  @ 000c5ea4
void Spawn__16CFuncTrackChange(int *param_1)

{
  int iVar1;
  
  Setup__9CFuncPlat(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 0x10) != 0) {
    param_1[0x109] = *(int *)(*param_1 + 0x10);
  }
  SetupRotation__12CFuncPlatRot(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 8) == 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_1 + 0x104);
    param_1[0xfd] = 0;
    iVar1 = *param_1;
    *(int *)(iVar1 + 0x50) = param_1[0x120];
    *(int *)(iVar1 + 0x54) = param_1[0x121];
    *(int *)(iVar1 + 0x58) = param_1[0x122];
    param_1[0x12d] = 1;
  }
  else {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_1 + 0x107);
    param_1[0xfd] = 1;
    iVar1 = *param_1;
    *(int *)(iVar1 + 0x50) = param_1[0x123];
    *(int *)(iVar1 + 0x54) = param_1[0x124];
    *(int *)(iVar1 + 0x58) = param_1[0x125];
    param_1[0x12d] = 0;
  }
  param_1[0x12e] = 1;
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 2.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__16CFuncTrackChange;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  return;
}


// Spawn__16CItemAmmoRockets  @ 000ed55c
void Spawn__16CItemAmmoRockets(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0xf7] = (int)"models/w_rpgammo.mdl" - *(int *)(gpGlobals + 0x98);
    param_1[0xf8] = (int)"models/w_rpgammo.mdl" - *(int *)(gpGlobals + 0x98);
    *(int *)(*param_1 + 0x1d0) = (int)"rockets" - *(int *)(gpGlobals + 0x98);
    param_1[0x39] = 5;
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__16CItemArmorYellow  @ 000ecfdc
void Spawn__16CItemArmorYellow(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/y_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0xf7] = 0x43160000;
    param_1[0xf8] = 0x3f19999a;
  }
  return;
}


// Spawn__16CItemPowerupQuad  @ 000eddb0
void Spawn__16CItemPowerupQuad(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  Spawn__12CItemPowerup(param_1);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf6] = 0x42700000;
  }
  param_1[0xed] = 0x41f00000;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/quad.mdl");
  *(int *)(*param_1 + 0x1d0) = (int)"Quad Damage" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1e8) = (int)"items/damage.wav" - *(int *)(gpGlobals + 0x98);
  param_1[0x22] = 0x400000;
  return;
}


// Spawn__16CRenderFxManager  @ 001020dc
void Spawn__16CRenderFxManager(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  return;
}


// Spawn__16CTFSentrygunBase  @ 000de024
void Spawn__16CTFSentrygunBase(int *param_1)

{
  int iVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(int *)*param_1 = (int)"building_sentrygun_base" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  iVar1 = *param_1;
  local_4 = 0x41000000;
  local_c = 0;
  local_8 = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41000000;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/base.mdl");
  local_c = 0x41800000;
  local_4 = 0x42400000;
  uStack_18 = 0xc1800000;
  uStack_10 = 0;
  uStack_14 = uStack_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_18,&local_c);
  return;
}


// Spawn__16CTriggerMultiple  @ 00102f5c
void Spawn__16CTriggerMultiple(int param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x400)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x400) == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(param_1 + 0x400) = 0x3e4ccccd;
    }
    InitTrigger__12CBaseTrigger(param_1);
    *(undefined4 *)(param_1 + 0x14) = 0xffff0000;
    *(code **)(param_1 + 0x18) = MultiTouch__12CBaseTriggerP11CBaseEntity;
  }
  return;
}


// Spawn__16CTriggerTeleport  @ 00104c58
void Spawn__16CTriggerTeleport(int param_1)

{
  InitTrigger__12CBaseTrigger(param_1);
  *(undefined4 *)(param_1 + 0x14) = 0xffff0000;
  *(code **)(param_1 + 0x18) = TeleportTouch__12CBaseTriggerP11CBaseEntity;
  return;
}


// Spawn__17CFrictionModifier  @ 001016d0
void Spawn__17CFrictionModifier(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x108) = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)ChangeFriction__17CFrictionModifierP11CBaseEntity;
  return;
}


// Spawn__17CFuncTankControls  @ 000a2914
void Spawn__17CFuncTankControls(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  return;
}


// Spawn__17CInfoIntermission  @ 000d3f7c
void Spawn__17CInfoIntermission(int *param_1)

{
  int iVar1;
  
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x74) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x78) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x7c) = DAT_001a7e08;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 2.0;
  return;
}


// Spawn__17CScriptedSentence  @ 000dd80c
void Spawn__17CScriptedSentence(int *param_1)

{
  float fVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  param_1[0x125] = 1;
  if (*(int *)(*param_1 + 0x1cc) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)FindThink__17CScriptedSentence;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  }
  switch(*(undefined4 *)(*param_1 + 0x184)) {
  default:
    param_1[0x123] = 0x40000000;
    break;
  case 1:
    param_1[0x123] = 0x3fa00000;
    break;
  case 2:
    param_1[0x123] = 0x3f4ccccd;
    break;
  case 3:
    param_1[0x123] = 0;
  }
  *(undefined4 *)(*param_1 + 0x184) = 0;
  fVar1 = (float)param_1[0x124];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    param_1[0x124] = 0x3f800000;
  }
  return;
}


// Spawn__18CCine2HeavyWeapons  @ 0012b2f4
void Spawn__18CCine2HeavyWeapons(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine2_hvyweapons.mdl");
  return;
}


// Spawn__18CFuncTrainControls  @ 000c5d4c
void Spawn__18CFuncTrainControls(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + gpGlobals[0x26]);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__18CFuncTrainControls;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Spawn__18CTFGrenadeLauncher  @ 001194e0
void Spawn__18CTFGrenadeLauncher(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 4;
  param_1[0x114] = 8;
  param_1[0x115] = 10;
  param_1[0x116] = 0;
  param_1[0x117] = 4;
  param_1[0x118] = 5;
  param_1[0x113] = 0x32;
  param_1[0x107] = 0x3f2aaaab;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__18CTriggerEndSection  @ 00104e20
void Spawn__18CTriggerEndSection(int *param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(gpGlobals + 0x14);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    InitTrigger__12CBaseTrigger(param_1);
    param_1[7] = -0x10000;
    param_1[8] = (int)EndSectionUse__18CTriggerEndSectionP11CBaseEntityT18USE_TYPEf;
    if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
      param_1[5] = -0x10000;
      param_1[6] = (int)EndSectionTouch__18CTriggerEndSectionP11CBaseEntity;
    }
  }
  else {
    (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


// Spawn__19CItemPowerupRadsuit  @ 000edb4c
void Spawn__19CItemPowerupRadsuit(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  Spawn__12CItemPowerup(param_1);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf6] = 0x42700000;
  }
  param_1[0xee] = 0x41f00000;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_suit.mdl");
  *(int *)(*param_1 + 0x1d0) = (int)"Biosuit" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1e8) = (int)"FVox/HEV_logon.wav" - *(int *)(gpGlobals + 0x98);
  param_1[0x22] = 0x200000;
  return;
}


// Spawn__19CMomentaryRotButton  @ 000848c8
void Spawn__19CMomentaryRotButton(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  
  AxisDir__11CBaseToggleP9entvars_s(*param_1);
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
  }
  fVar1 = (float)param_1[0xff];
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    iVar6 = *param_1;
    param_1[0x121] = *(int *)(iVar6 + 0x50);
    param_1[0x122] = *(int *)(iVar6 + 0x54);
    param_1[0x123] = *(int *)(iVar6 + 0x58);
    fVar1 = (float)param_1[0xff];
    fVar2 = *(float *)(iVar6 + 0x48);
    fVar3 = *(float *)(iVar6 + 0x4c);
    fVar4 = *(float *)(iVar6 + 0x54);
    fVar5 = *(float *)(iVar6 + 0x58);
    param_1[0x124] = (int)(*(float *)(iVar6 + 0x50) + fVar1 * *(float *)(iVar6 + 0x44));
    param_1[0x125] = (int)(fVar4 + fVar1 * fVar2);
    param_1[0x126] = (int)(fVar5 + fVar1 * fVar3);
    param_1[0x11f] = -1;
  }
  else {
    iVar6 = *param_1;
    fVar2 = *(float *)(iVar6 + 0x48);
    fVar3 = *(float *)(iVar6 + 0x4c);
    fVar4 = *(float *)(iVar6 + 0x54);
    fVar5 = *(float *)(iVar6 + 0x58);
    param_1[0x121] = (int)(*(float *)(iVar6 + 0x50) + fVar1 * *(float *)(iVar6 + 0x44));
    param_1[0x122] = (int)(fVar4 + fVar1 * fVar2);
    param_1[0x123] = (int)(fVar5 + fVar1 * fVar3);
    param_1[0x124] = *(int *)(iVar6 + 0x50);
    param_1[0x125] = *(int *)(iVar6 + 0x54);
    param_1[0x126] = *(int *)(iVar6 + 0x58);
    param_1[0x11f] = 1;
    param_1[0xff] = (int)-fVar1;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 4;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  uVar7 = ButtonSound__Fi(param_1[0x127]);
  (*DAT_001a7e44)(uVar7);
  uVar7 = (*DAT_001a7f4c)(uVar7);
  *(undefined4 *)(*param_1 + 0x1e8) = uVar7;
  param_1[0x11e] = 0;
  return;
}


// Spawn__19CTFPipebombLauncher  @ 00119d00
void Spawn__19CTFPipebombLauncher(int param_1)

{
  undefined2 uVar1;
  
  Spawn__18CTFGrenadeLauncher(param_1);
  *(undefined4 *)(param_1 + 0x450) = 9;
  *(undefined4 *)(param_1 + 0x454) = 0xb;
  *(undefined4 *)(param_1 + 0x458) = 1;
  *(undefined4 *)(param_1 + 0x45c) = 6;
  *(undefined4 *)(param_1 + 0x460) = 7;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_pipel.sc");
  *(undefined2 *)(param_1 + 0x464) = uVar1;
  return;
}


// Spawn__19CTriggerMonsterJump  @ 00102464
void Spawn__19CTriggerMonsterJump(int *param_1)

{
  SetMovedir__FP9entvars_s(*param_1);
  InitTrigger__12CBaseTrigger(param_1);
  *(undefined4 *)(*param_1 + 0x104) = 0;
  *(undefined4 *)(*param_1 + 0x1f8) = 0x43480000;
  param_1[0x111] = 0x43160000;
  if (*(int *)(*param_1 + 0x1cc) != 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  }
  return;
}


// Spawn__20CTFFlamethrowerBurst  @ 000f3290
void Spawn__20CTFFlamethrowerBurst(int *param_1)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 9;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),FUN_0013ea2c);
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0.0;
  local_14 = 0.0;
  local_10 = 0.0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(char **)*param_1 = "?tf_flamethrower_burst" + (1 - (int)gpGlobals[0x26]);
  param_1[0xde] = (int)"flames" - (int)gpGlobals[0x26];
  *(float *)(*param_1 + 0x50) = *(float *)(*param_1 + 0x50) - 30.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  *(float *)(*param_1 + 0x50) = -(*(float *)(*param_1 + 0x50) + 30.0);
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  iVar1 = *param_1;
  local_18 = gpGlobals[10] * 600.0;
  local_14 = gpGlobals[0xb] * 600.0;
  local_10 = gpGlobals[0xc] * 600.0;
  *(float *)(iVar1 + 0x20) = local_18;
  *(float *)(iVar1 + 0x24) = local_14;
  *(float *)(iVar1 + 0x28) = local_10;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x198));
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__20CTFIncendiaryCRocket  @ 000f36ec
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__20CTFIncendiaryCRocket(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 9;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),FUN_0013ea2c);
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_rpg_rocket" - (int)gpGlobals[0x26];
  param_1[0xde] = (int)"rocket" - (int)gpGlobals[0x26];
  *(float *)(*param_1 + 0x50) = *(float *)(*param_1 + 0x50) - 30.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  *(float *)(*param_1 + 0x50) = -(*(float *)(*param_1 + 0x50) + 30.0);
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  iVar1 = *param_1;
  fVar2 = gpGlobals[0xb] * _FUN_0013eaf0;
  fVar3 = _FUN_0013eaf0 * gpGlobals[0xc];
  *(float *)(iVar1 + 0x20) = gpGlobals[10] * _FUN_0013eaf0;
  *(float *)(iVar1 + 0x24) = fVar2;
  *(float *)(iVar1 + 0x28) = fVar3;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 5.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__20CTriggerChangeTarget  @ 00105114
void Spawn__20CTriggerChangeTarget(void)

{
  return;
}


// Spawn__22CItemPowerupInvincible  @ 000eda10
void Spawn__22CItemPowerupInvincible(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  Spawn__12CItemPowerup(param_1);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf6] = 0x43960000;
  }
  param_1[0xeb] = 0x41f00000;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/pent.mdl");
  *(int *)(*param_1 + 0x1d0) = (int)"Pentagram of Protection" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1e8) = (int)"items/protect.wav" - *(int *)(gpGlobals + 0x98);
  param_1[0x22] = 0x100000;
  return;
}


// Spawn__23CDispenserRefillThinker  @ 00092270
void Spawn__23CDispenserRefillThinker(undefined4 *param_1)

{
  *(char **)*param_1 = "zCtimer" + (2 - *(int *)(gpGlobals + 0x98));
  param_1[0xea] = 0xe;
  return;
}


// Spawn__24CItemPowerupInvisibility  @ 000edc74
void Spawn__24CItemPowerupInvisibility(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  Spawn__12CItemPowerup(param_1);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf6] = 0x43960000;
  }
  param_1[0xec] = 0x41f00000;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/invis.mdl");
  *(int *)(*param_1 + 0x1d0) = (int)"Ring of Shadows" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1e8) = (int)"items/inv1.wav" - *(int *)(gpGlobals + 0x98);
  param_1[0x22] = 0x80000;
  return;
}


// Spawn__4CGibPCc  @ 0008de94
void Spawn__4CGibPCc(int *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f0ccccd;
  *(undefined4 *)(*param_1 + 0x14c) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x148) = 0;
  *(undefined4 *)(*param_1 + 0x15c) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(int *)*param_1 = (int)&DAT_00133a00 - (int)gpGlobals[0x26];
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),param_2);
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 4.0;
  param_1[0xf9] = 0x41c80000;
  param_1[3] = -0x10000;
  param_1[4] = (int)WaitTillLand__4CGib;
  param_1[5] = -0x10000;
  param_1[6] = (int)BounceGibTouch__4CGibP11CBaseEntity;
  param_1[0xf8] = 9;
  param_1[0xf7] = 5;
  return;
}


// Spawn__5CBeam  @ 00095af8
void Spawn__5CBeam(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  return;
}


// Spawn__5CFade  @ 0009a810
void Spawn__5CFade(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


// Spawn__5CGlow  @ 00098908
void Spawn__5CGlow(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  iVar2 = (*DAT_001a7e50)(*(undefined4 *)(*param_1 + 0xb4));
  param_1[0xf7] = (int)((float)iVar2 - 1.0);
  if (1.0 < (float)param_1[0xf7]) {
    fVar1 = *(float *)(*param_1 + 0x138);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    }
  }
  param_1[0xf6] = (int)*gpGlobals;
  return;
}


// Spawn__5CItem  @ 000ab864
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
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0xf6] = 0x41a00000;
    }
    iVar1 = (*DAT_001a7ea8)();
    if (iVar1 != 0) {
      return;
    }
    param_1 = (int *)*param_1;
    (*DAT_001a7f34)(4,"Item %s fell out of level at %f,%f,%f",*param_1 + *(int *)(gpGlobals + 0x98),
                    (double)(float)param_1[2],(double)(float)param_1[3],(double)(float)param_1[4]);
  }
  UTIL_Remove__FP11CBaseEntity();
  return;
}


// Spawn__6CBlood  @ 0009a190
void Spawn__6CBlood(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  SetMovedir__FP9entvars_s(*param_1);
  return;
}


// Spawn__6CDecal  @ 001124cc
void Spawn__6CDecal(int *param_1)

{
  float fVar1;
  
  if ((-1 < *(int *)(*param_1 + 0x110)) &&
     ((fVar1 = (float)gpGlobals[5],
      (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 ||
      ((*(byte *)(*param_1 + 0x1a1) & 8) == 0)))) {
    if (*(int *)(*param_1 + 0x1cc) == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)StaticDecal__6CDecal;
      *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
      return;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
    param_1[7] = -0x10000;
    param_1[8] = (int)TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf;
    return;
  }
  (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Spawn__6CLaser  @ 0009818c
void Spawn__6CLaser(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (*(int *)(*param_1 + 0xb8) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
    param_1[3] = -0x10000;
    param_1[4] = (int)StrikeThink__6CLaser;
    *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x20;
    PointsInit__5CBeamRC6VectorT1(param_1,*param_1 + 8,*param_1 + 8);
    if ((param_1[0xf6] == 0) && (param_1[0xf7] != 0)) {
      iVar7 = SpriteCreate__7CSpritePCcRC6Vectori
                        (param_1[0xf7] + *(int *)(gpGlobals + 0x98),*param_1 + 8,1);
      param_1[0xf6] = iVar7;
    }
    else {
      param_1[0xf6] = 0;
    }
    if (param_1[0xf6] != 0) {
      iVar7 = *param_1;
      fVar1 = *(float *)(iVar7 + 0x150);
      fVar2 = *(float *)(iVar7 + 0x154);
      fVar3 = *(float *)(iVar7 + 0x158);
      fVar4 = *(float *)(iVar7 + 0x14c);
      piVar5 = (int *)param_1[0xf6];
      uVar6 = *(undefined4 *)(iVar7 + 0x15c);
      *(undefined4 *)(*piVar5 + 0x148) = 3;
      *(float *)(*piVar5 + 0x150) = (float)(int)ROUND(fVar1);
      *(float *)(*piVar5 + 0x154) = (float)(int)ROUND(fVar2);
      *(float *)(*piVar5 + 0x158) = (float)(int)ROUND(fVar3);
      *(float *)(*piVar5 + 0x14c) = (float)(int)ROUND(fVar4);
      *(undefined4 *)(*piVar5 + 0x15c) = uVar6;
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


// Spawn__6CLight  @ 000abf00
void Spawn__6CLight(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  
  if (*(int *)(*param_1 + 0x1cc) == 0) {
    (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
    return;
  }
  if (param_1[0xf6] < 0x20) {
    return;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    if (param_1[0xf7] != 0) {
      puVar1 = (undefined *)(param_1[0xf7] + *(int *)(gpGlobals + 0x98));
      iVar2 = param_1[0xf6];
      goto LAB_000abfa6;
    }
    puVar1 = &DAT_00136e67;
  }
  else {
    puVar1 = &DAT_00136e65;
  }
  iVar2 = param_1[0xf6];
LAB_000abfa6:
  (*DAT_001a7eec)(iVar2,puVar1);
  return;
}


// Spawn__6CShake  @ 0009a620
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


// Spawn__6CTFAxe  @ 00116e60
void Spawn__6CTFAxe(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 5;
  param_1[0x110] = -1;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__6CTFRpg  @ 0011b72c
void Spawn__6CTFRpg(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 8;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_rpg.mdl");
  param_1[0x113] = 0x32;
  param_1[0x107] = 0x3fa00000;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__6CWorld  @ 00113354
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__6CWorld(int param_1)

{
  undefined4 uVar1;
  char *__src;
  longdouble lVar2;
  int local_4;
  
  g_fGameOver = 0;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0xc))(param_1);
  lVar2 = (longdouble)(*DAT_001a7f24)("sv_cheats");
  g_flWeaponCheat = (float)lVar2;
  memset(&g_IpStorage,0,0x100);
  number_of_teams = 0;
  CTF_Map = 0;
  birthday = 0;
  christmas = 0;
  num_world_flames = 0;
  team_menu_string = 0;
  _toggleflags = 0;
  g_bFirstClient = 0;
  TeamFortress_TeamSetColor__Fi(0);
  teamallies = 0;
  g_pLastSpawns = 0;
  teamadvantage = 0x3f800000;
  team_names = 0;
  DAT_001b4a88 = 0;
  DAT_001b4b04 = 0;
  DAT_001b4a74 = 0x3f800000;
  DAT_001b4a9c = 0;
  DAT_001b4a8c = 0;
  DAT_001b4b08 = 0;
  DAT_001b4a78 = 0x3f800000;
  DAT_001b4aa0 = 0;
  DAT_001b4a90 = 0;
  DAT_001b4b0c = 0;
  DAT_001b4a7c = 0x3f800000;
  DAT_001b4aa4 = 0;
  DAT_001b4a94 = 0;
  DAT_001b4b10 = 0;
  DAT_001b4a80 = 0x3f800000;
  DAT_001b4aa8 = 0;
  g_szMapBriefingText = 0;
  local_4 = 0;
  uVar1 = UTIL_VarArgs__FPce("maps/%s.txt",*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98),
                             &local_4);
  __src = (char *)(*DAT_001a7fbc)(uVar1);
  if ((__src != (char *)0x0) && (local_4 != 0)) {
    strncpy(&g_szMapBriefingText,__src,0x1fe);
    uVar1 = UTIL_VarArgs__FPce("maps/%s.txt",*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98))
    ;
    (*pcRam001a8000)(uVar1);
  }
  (*DAT_001a7fc0)(__src);
  return;
}


// Spawn__7CCycler  @ 000a9734
void Spawn__7CCycler(int *param_1)

{
  float fVar1;
  
  InitBoneControllers__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x160) = 0x479c4000;
  *(undefined4 *)(*param_1 + 0xb0) = 0x40a00000;
  *(undefined4 *)(*param_1 + 0xac) = *(undefined4 *)(*param_1 + 0x54);
  (**(code **)(param_1[0xf5] + 0x110))(param_1,0x168);
  param_1[0xf8] = 0x42960000;
  param_1[0xf9] = 0;
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x104) + 1.0;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  if ((*(int *)(*param_1 + 0x128) == 0) &&
     (fVar1 = *(float *)(*param_1 + 0x130),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    param_1[0x187] = 1;
    return;
  }
  param_1[0x187] = 0;
  *(undefined4 *)(*param_1 + 0x138) = 0;
  return;
}


// Spawn__7CLadder  @ 00104718
void Spawn__7CLadder(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x108) = 7;
  return;
}


// Spawn__7CMortar  @ 000b8204
void Spawn__7CMortar(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x43480000;
  param_1[3] = -0x10000;
  param_1[4] = (int)MortarExplode__7CMortar;
  *(undefined4 *)(*param_1 + 0x104) = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  return;
}


// Spawn__7CSentry  @ 001091a8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__7CSentry(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/sentry.mdl");
  *(undefined4 *)(*param_1 + 0x160) = _DAT_001aa444;
  local_4 = 0x42400000;
  local_c = 0;
  local_8 = 0;
  param_1[0x182] = 0;
  param_1[0x183] = 0;
  param_1[0x184] = 0x42400000;
  *(undefined4 *)(*param_1 + 0x17c) = 0x42400000;
  param_1[0x198] = 0x49742400;
  param_1[0x187] = 0x49742400;
  Spawn__11CBaseTurret(param_1);
  param_1[0x18c] = 0x40;
  param_1[0x18b] = 0x40;
  param_1[0x18d] = -0x3c;
  local_c = 0x41800000;
  local_4 = 0x42800000;
  local_18 = 0xc1800000;
  local_10 = 0xc2800000;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  param_1[5] = -0x10000;
  param_1[6] = (int)SentryTouch__7CSentryP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  return;
}


// Spawn__7CShower  @ 0009c8fc
void Spawn__7CShower(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar3 = *param_1;
  lVar4 = (longdouble)(*DAT_001a7fac)(0x43480000,0x43960000);
  fVar1 = *(float *)(*param_1 + 0x54);
  fVar2 = *(float *)(*param_1 + 0x58);
  *(float *)(iVar3 + 0x20) = (float)(lVar4 * (longdouble)*(float *)(*param_1 + 0x50));
  *(float *)(iVar3 + 0x24) = (float)(lVar4 * (longdouble)fVar1);
  *(float *)(iVar3 + 0x28) = (float)(lVar4 * (longdouble)fVar2);
  lVar4 = (longdouble)(*DAT_001a7fac)(0xc2c80000,0x42c80000);
  *(float *)(*param_1 + 0x20) = (float)(lVar4 + (longdouble)*(float *)(*param_1 + 0x20));
  lVar4 = (longdouble)(*DAT_001a7fac)(0xc2c80000,0x42c80000);
  *(float *)(*param_1 + 0x24) = (float)(lVar4 + (longdouble)*(float *)(*param_1 + 0x24));
  iVar3 = *param_1;
  if (*(float *)(iVar3 + 0x28) < 0.0) {
    *(float *)(*param_1 + 0x28) = *(float *)(*param_1 + 0x28) - 200.0;
  }
  else {
    *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) + 200.0;
  }
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/grenade.mdl");
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  lVar4 = (longdouble)(*DAT_001a7fac)(0x3f000000,0x3fc00000);
  *(float *)(*param_1 + 0x1f8) = (float)lVar4;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar3 + 0x54) = DAT_001a7e04;
  *(undefined4 *)(iVar3 + 0x58) = DAT_001a7e08;
  return;
}


// Spawn__7CSprite  @ 00098bd8
void Spawn__7CSprite(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar2 = (*DAT_001a7e50)(*(undefined4 *)(*param_1 + 0xb4));
  param_1[0xf7] = (int)((float)iVar2 - 1.0);
  if ((*(int *)(*param_1 + 0x1cc) == 0) || (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) == 0)) {
    TurnOn__7CSprite(param_1);
  }
  else {
    TurnOff__7CSprite(param_1);
  }
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x54);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x58)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x58) == 0.0) << 0xe) >> 8)) == 0x40)) {
    *(float *)(iVar2 + 0x58) = fVar1;
    *(undefined4 *)(*param_1 + 0x54) = 0;
  }
  return;
}


// Spawn__7CTFGoal  @ 000fa4b4
void Spawn__7CTFGoal(int *param_1)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    *(int *)*param_1 = (int)"info_tfgoal" - *(int *)(gpGlobals + 0x98);
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0xb8) != 0) {
      pcVar3 = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(iVar2 + 0xb8));
      if (*pcVar3 == '*') {
        *(byte *)(iVar2 + 0x118) = *(byte *)(iVar2 + 0x118) | 0x80;
      }
      (*g_engfuncs)(pcVar3);
      (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                      *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    }
    if (*(int *)(*param_1 + 0x1e8) != 0) {
      (*DAT_001a7e44)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
    }
    (*DAT_001a7e44)("items/protect.wav");
    (*DAT_001a7e44)("items/protect2.wav");
    (*DAT_001a7e44)("items/protect3.wav");
    (*DAT_001a7e44)("FVox/HEV_logon.wav");
    (*DAT_001a7e44)("FVox/hev_shutdown.wav");
    (*DAT_001a7e44)("items/inv1.wav");
    (*DAT_001a7e44)("items/inv2.wav");
    (*DAT_001a7e44)("items/inv3.wav");
    (*DAT_001a7e44)("items/damage.wav");
    (*DAT_001a7e44)("items/damage2.wav");
    (*DAT_001a7e44)("items/damage3.wav");
    *(undefined4 *)(*param_1 + 0x10c) = 1;
    if (param_1[0x86] == 0) {
      param_1[0x86] = 2;
    }
    bVar4 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0x9e])) << 10) >> 8) |
               (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0x9e]) << 0xe) >> 8)) == 0x40)
       && ((byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN((float)param_1[0x9f])) << 10) >>
                        8) |
                 (byte)((ushort)((ushort)(DAT_001a7e04 == (float)param_1[0x9f]) << 0xe) >> 8)) ==
           0x40)) {
      fVar1 = (float)param_1[0xa0];
      bVar4 = (byte)(DAT_001a7e08 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar4) {
      bVar4 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0xa1])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0xa1]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN((float)param_1[0xa2])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_001a7e04 == (float)param_1[0xa2]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa3];
        bVar4 = (byte)(DAT_001a7e08 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (!bVar4) {
        UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,param_1 + 0x9e,param_1 + 0xa1);
      }
    }
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    StartGoal__7CTFGoal(param_1);
  }
  return;
}


// Spawn__7CTurret  @ 00106ce8
void Spawn__7CTurret(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/turret.mdl");
  *(undefined4 *)(*param_1 + 0x160) = DAT_001aa43c;
  local_4 = 0x414c0000;
  local_c = 0;
  local_8 = 0;
  param_1[0x182] = 0;
  param_1[0x183] = 0;
  param_1[0x184] = 0x414c0000;
  param_1[0x187] = 0x40a00000;
  *(undefined4 *)(*param_1 + 0x17c) = 0x414c0000;
  Spawn__11CBaseTurret(param_1);
  param_1[0x18c] = 0x10;
  param_1[0x18b] = 0x20;
  param_1[0x18d] = -0xf;
  local_c = 0x42000000;
  local_4 = 0x41800000;
  local_18 = 0xc2000000;
  local_10 = 0xc1800000;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  piVar2 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/flare3.spr",*param_1 + 8,0);
  param_1[0x189] = (int)piVar2;
  *(undefined4 *)(*piVar2 + 0x148) = 3;
  *(undefined4 *)(*piVar2 + 0x150) = 0x437f0000;
  *(undefined4 *)(*piVar2 + 0x154) = 0;
  *(undefined4 *)(*piVar2 + 0x158) = 0;
  *(undefined4 *)(*piVar2 + 0x14c) = 0;
  *(undefined4 *)(*piVar2 + 0x15c) = 0xe;
  iVar1 = *(int *)(*param_1 + 0x208);
  piVar2 = (int *)param_1[0x189];
  if (iVar1 != 0) {
    uVar3 = (*DAT_001a7f5c)(iVar1);
    *(undefined4 *)(*piVar2 + 0x110) = uVar3;
    *(undefined4 *)(*piVar2 + 0x114) = 2;
    *(int *)(*piVar2 + 0x194) = iVar1;
    *(undefined4 *)(*piVar2 + 0x108) = 0xc;
  }
  param_1[0x18a] = 0;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
  return;
}


// Spawn__8CAirtank  @ 0007f1fc
void Spawn__8CAirtank(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 5;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_oxygen.mdl");
  local_c = 0x41800000;
  local_4 = 0x42100000;
  local_18 = 0xc1800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)TankTouch__8CAirtankP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)TankThink__8CAirtank;
  *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x160) = 0x41a00000;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x42480000;
  param_1[0x18e] = 1;
  return;
}


// Spawn__8CCrowbar  @ 0008f184
void Spawn__8CCrowbar(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 1;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_crowbar.mdl");
  param_1[0x110] = -1;
  FallInit__15CBasePlayerItem(param_1);
  return;
}


// Spawn__8CDeadHEV  @ 000d3a7c
void Spawn__8CDeadHEV(int *param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/player.mdl");
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/player.mdl");
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0xb0) = 0x41000000;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x114) = 1;
  param_1[0x17b] = 0xf7;
  uVar1 = LookupSequence__14CBaseAnimatingPCc
                    (param_1,*(undefined4 *)(_8CDeadHEV_m_szPoses + param_1[0x187] * 4));
  *(undefined4 *)(*param_1 + 0x128) = uVar1;
  if (*(int *)(*param_1 + 0x128) == -1) {
    (*DAT_001a7f34)(1,"Dead hevsuit with bad pose\n");
    *(undefined4 *)(*param_1 + 0x128) = 0;
    *(undefined4 *)(*param_1 + 0x118) = 1;
  }
  *(undefined4 *)(*param_1 + 0x160) = 0x41000000;
  (**(code **)(param_1[0xf5] + 0x120))(param_1);
  return;
}


// Spawn__8CDetpack  @ 000906b4
void Spawn__8CDetpack(int *param_1)

{
  char *pcVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[399] = 0;
  param_1[0x18e] = 0;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  param_1[400] = 0;
  if (birthday == 0) {
    pcVar1 = "models/detpack.mdl";
  }
  else {
    pcVar1 = "models/presentlg.mdl";
  }
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),pcVar1);
  param_1[5] = -0x10000;
  param_1[6] = (int)DetpackTouch__8CDetpackP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)DetpackThink__8CDetpack;
  fStack_4 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = fStack_4;
  uStack_10 = 0x40800000;
  uStack_1c = 0xc0800000;
  uStack_18 = uStack_1c;
  uStack_14 = uStack_1c;
  uStack_c = uStack_10;
  uStack_8 = uStack_10;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&uStack_1c,&uStack_10);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[0x42] = 0;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"weapons/mine_activate.wav",0x3f800000,0x3f4ccccd,0
             ,100);
  return;
}


// Spawn__8CGrenade  @ 000a7494
void Spawn__8CGrenade(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x108) = 10;
  *(char **)*param_1 = "?grenade" + (1 - *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/grenade.mdl");
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  param_1[0x188] = 0;
  param_1[0x187] = 0;
  param_1[0x18b] = 0;
  param_1[0x18a] = 0;
  *(undefined4 *)(*param_1 + 0x1e0) = 0x42c80000;
  param_1[0x18c] = 0;
  *(undefined2 *)(param_1 + 0x18d) = 0;
  return;
}


// Spawn__8CMessage  @ 0009a9a0
void Spawn__8CMessage(int *param_1)

{
  float fVar1;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  switch(*(undefined4 *)(*param_1 + 0x184)) {
  default:
    *(undefined4 *)(*param_1 + 0x1f8) = 0x40000000;
    break;
  case 1:
    *(undefined4 *)(*param_1 + 0x1f8) = 0x3fa00000;
    break;
  case 2:
    *(undefined4 *)(*param_1 + 0x1f8) = 0x3f4ccccd;
    break;
  case 3:
    *(undefined4 *)(*param_1 + 0x1f8) = 0;
  }
  *(undefined4 *)(*param_1 + 0x184) = 0;
  fVar1 = *(float *)(*param_1 + 0x144);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(*param_1 + 0x144) = 0x3f800000;
  }
  return;
}


// Spawn__8CNodeEnt  @ 000bb5c8
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
    if (DAT_001a82b8 == 0) {
      uVar4 = GetClassPtr__H1Z9CTestHull_PX01_PX01(0);
      Spawn__9CTestHullP9entvars_s(uVar4,*param_1);
    }
    iVar5 = DAT_001a82ac;
    if (0x3ff < DAT_001a82b8) {
      (*DAT_001a7f34)(2,"cNodes > MAX_NODES\n");
      return;
    }
    iVar6 = DAT_001a82b8 * 0x58;
    puVar1 = (undefined4 *)(DAT_001a82ac + iVar6);
    iVar3 = *param_1;
    *puVar1 = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar5 + 4 + iVar6) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar5 + 8 + iVar6) = *(undefined4 *)(iVar3 + 0x10);
    puVar2 = (undefined4 *)(DAT_001a82ac + DAT_001a82b8 * 0x58);
    puVar1[3] = *puVar2;
    puVar1[4] = puVar2[1];
    puVar1[5] = puVar2[2];
    *(undefined4 *)(DAT_001a82ac + 0x54 + DAT_001a82b8 * 0x58) = *(undefined4 *)(*param_1 + 0x54);
    *(short *)(DAT_001a82ac + 0x50 + DAT_001a82b8 * 0x58) = (short)param_1[0xf6];
    *(undefined2 *)(DAT_001a82ac + 0x52 + DAT_001a82b8 * 0x58) =
         *(undefined2 *)((int)param_1 + 0x3da);
    iVar5 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"info_node_air");
    if (iVar5 == 0) {
      *(undefined4 *)(DAT_001a82ac + 0x1c + DAT_001a82b8 * 0x58) = 2;
    }
    else {
      *(undefined4 *)(DAT_001a82ac + 0x1c + DAT_001a82b8 * 0x58) = 0;
    }
    DAT_001a82b8 = DAT_001a82b8 + 1;
  }
  (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Spawn__8CRotDoor  @ 00094b54
void Spawn__8CRotDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  AxisDir__11CBaseToggleP9entvars_s(*param_1);
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x1a0) & 2) != 0) {
    *(float *)(iVar6 + 0x44) = *(float *)(iVar6 + 0x44) * -1.0;
    *(float *)(iVar6 + 0x48) = *(float *)(iVar6 + 0x48) * -1.0;
    *(float *)(iVar6 + 0x4c) = *(float *)(iVar6 + 0x4c) * -1.0;
  }
  iVar6 = *param_1;
  param_1[0x10a] = *(int *)(iVar6 + 0x50);
  param_1[0x10b] = *(int *)(iVar6 + 0x54);
  param_1[0x10c] = *(int *)(iVar6 + 0x58);
  fVar1 = (float)param_1[0xff];
  fVar2 = *(float *)(iVar6 + 0x48);
  fVar3 = *(float *)(iVar6 + 0x4c);
  fVar4 = *(float *)(iVar6 + 0x54);
  fVar5 = *(float *)(iVar6 + 0x58);
  param_1[0x10d] = (int)(*(float *)(iVar6 + 0x50) + fVar1 * *(float *)(iVar6 + 0x44));
  param_1[0x10e] = (int)(fVar4 + fVar1 * fVar2);
  param_1[0x10f] = (int)(fVar5 + fVar1 * fVar3);
  if ((*(byte *)(iVar6 + 0x1a0) & 8) == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(iVar6 + 0x10c) = 0;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
  }
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x1a0) & 1) != 0) {
    *(int *)(iVar6 + 0x50) = param_1[0x10d];
    *(int *)(iVar6 + 0x54) = param_1[0x10e];
    *(int *)(iVar6 + 0x58) = param_1[0x10f];
    param_1[0x10d] = param_1[0x10a];
    param_1[0x10e] = param_1[0x10b];
    param_1[0x10f] = param_1[0x10c];
    param_1[0x10a] = param_1[0x10a];
    param_1[0x10b] = param_1[0x10b];
    param_1[0x10c] = param_1[0x10c];
    iVar6 = *param_1;
    *(float *)(iVar6 + 0x44) = *(float *)(iVar6 + 0x44) * -1.0;
    *(float *)(iVar6 + 0x48) = *(float *)(iVar6 + 0x48) * -1.0;
    *(float *)(iVar6 + 0x4c) = *(float *)(iVar6 + 0x4c) * -1.0;
  }
  param_1[0xfd] = 1;
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


// Spawn__8CSpeaker  @ 000e38ac
void Spawn__8CSpeaker(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1[0xf6] == 0) {
    if (*(int *)(*param_1 + 0x1d4) != 0) {
      iVar2 = -1;
      pcVar3 = (char *)((int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1d4));
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (iVar2 != -2) goto LAB_000e3968;
    }
    iVar2 = *param_1;
    (*DAT_001a7f34)(4,"SPEAKER with no Level/Sentence! at: %f, %f, %f\n",
                    (double)*(float *)(iVar2 + 8),(double)*(float *)(iVar2 + 0xc),
                    (double)*(float *)(iVar2 + 0x10));
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
LAB_000e3968:
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SpeakerThink__8CSpeaker;
    *(undefined4 *)(*param_1 + 0x104) = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf;
    (**(code **)(param_1[0xf5] + 0xc))();
  }
  return;
}


// Spawn__8CTFFlame  @ 000d8fb4
void Spawn__8CTFFlame(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  *(int *)*param_1 = (int)"tf_fire" - (int)gpGlobals[0x26];
  param_1[0xde] = (int)"flames" - (int)gpGlobals[0x26];
  *(float *)(*param_1 + 0x160) = *gpGlobals + 4.5;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x88;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  param_1[0x187] = *(int *)(*param_1 + 0x104);
  param_1[3] = -0x10000;
  param_1[4] = (int)FlameThink__8CTFFlame;
  return;
}


// Spawn__8CTFKnife  @ 00117b4c
void Spawn__8CTFKnife(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 0x17;
  param_1[0x110] = -1;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[0x134] = 0;
  return;
}


// Spawn__8CTFSpawn  @ 000fa400
void Spawn__8CTFSpawn(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else if (param_1[0x48] - 1U < 4) {
    fVar1 = (float)param_1[0x48];
    if (0x3f < (byte)((fVar1 < number_of_teams |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1)) {
      number_of_teams = fVar1;
    }
    ((undefined4 *)*param_1)[0x74] = *(undefined4 *)*param_1;
    *(int *)*param_1 = *(int *)(sTeamSpawnNames + param_1[0x48] * 4) - *(int *)(gpGlobals + 0x98);
  }
  else {
    (*DAT_001a7f34)(1,"Teamspawnpoint with an invalid team_no of %d\n",param_1[0x48]);
  }
  return;
}


// Spawn__8CTFTranq  @ 0011db1c
void Spawn__8CTFTranq(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_tranq" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  param_1[0xff] = 2;
  param_1[0x113] = 0x11;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__8CXenHair  @ 001148f8
void Spawn__8CXenHair(int *param_1)

{
  longdouble lVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/hair.mdl");
  local_c = 0x40800000;
  local_4 = 0x42000000;
  local_18 = 0xc0800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  *(undefined4 *)(*param_1 + 0x128) = 0;
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
    lVar1 = (longdouble)(*DAT_001a7fac)(0,0x437f0000);
    *(float *)(*param_1 + 0x130) = (float)lVar1;
    lVar1 = (longdouble)(*DAT_001a7fac)(0x3f333333,0x3fb33333);
    *(float *)(*param_1 + 0x138) = (float)lVar1;
  }
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  lVar1 = (longdouble)(*DAT_001a7fac)(0x3dcccccd,0x3ecccccd);
  *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


// Spawn__8CXenTree  @ 00114c40
void Spawn__8CXenTree(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longdouble lVar3;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/tree.mdl");
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  fStack_c = 30.0;
  fStack_4 = 188.0;
  fStack_18 = -30.0;
  fStack_10 = 0.0;
  fStack_14 = fStack_18;
  fStack_8 = fStack_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&fStack_18,&fStack_c);
  SetActivity__13CActAnimating8Activity(param_1,1);
  fStack_1c = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = fStack_1c;
  lVar3 = (longdouble)(*DAT_001a7fac)(0,0x437f0000);
  *(float *)(*param_1 + 0x130) = (float)lVar3;
  lVar3 = (longdouble)(*DAT_001a7fac)(0x3f333333,0x3fb33333);
  *(float *)(*param_1 + 0x138) = (float)lVar3;
  (*DAT_001a7e90)(*param_1 + 0x50,&fStack_18,0,0);
  fStack_28 = fStack_18 * 64.0;
  fStack_24 = fStack_14 * 64.0;
  fStack_20 = fStack_10 * 64.0;
  iVar1 = *param_1;
  fStack_18 = *(float *)(iVar1 + 8) + fStack_28;
  fStack_14 = *(float *)(iVar1 + 0xc) + fStack_24;
  fStack_10 = *(float *)(iVar1 + 0x10) + fStack_20;
  fStack_c = fStack_18;
  fStack_8 = fStack_14;
  fStack_4 = fStack_10;
  puVar2 = (undefined4 *)
           TriggerCreate__15CXenTreeTriggerP7edict_sRC6Vector
                     (*(undefined4 *)(iVar1 + 0x208),&fStack_18);
  param_1[0xfe] = (int)puVar2;
  fStack_28 = 24.0;
  fStack_20 = 128.0;
  fStack_c = -24.0;
  fStack_4 = 0.0;
  fStack_24 = fStack_28;
  fStack_8 = fStack_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*puVar2,&fStack_c,&fStack_28);
  return;
}


// Spawn__9CBaseDoor  @ 00093588
void Spawn__9CBaseDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  SetMovedir__FP9entvars_s(*param_1);
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x110) == 0) {
    if ((*(byte *)(iVar3 + 0x1a0) & 8) == 0) {
      *(undefined4 *)(*param_1 + 0x10c) = 4;
    }
    else {
      *(undefined4 *)(iVar3 + 0x10c) = 0;
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(byte *)(*param_1 + 0x1a3) = *(byte *)(*param_1 + 0x1a3) | 0x80;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
  }
  iVar3 = *param_1;
  param_1[0x104] = *(int *)(iVar3 + 8);
  param_1[0x105] = *(int *)(iVar3 + 0xc);
  param_1[0x106] = *(int *)(iVar3 + 0x10);
  fVar4 = (ABS((*(float *)(iVar3 + 0xf8) - 2.0) * *(float *)(iVar3 + 0x48)) +
           ABS((*(float *)(iVar3 + 0xf4) - 2.0) * *(float *)(iVar3 + 0x44)) +
          ABS((*(float *)(iVar3 + 0xfc) - 2.0) * *(float *)(iVar3 + 0x4c))) - (float)param_1[0x101];
  fVar1 = *(float *)(iVar3 + 0x48);
  fVar2 = *(float *)(iVar3 + 0x4c);
  param_1[0x107] = (int)((float)param_1[0x104] + fVar4 * *(float *)(iVar3 + 0x44));
  param_1[0x108] = (int)((float)param_1[0x105] + fVar4 * fVar1);
  param_1[0x109] = (int)((float)param_1[0x106] + fVar4 * fVar2);
  if ((*(byte *)(iVar3 + 0x1a0) & 1) != 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar3,param_1 + 0x107);
    param_1[0x107] = param_1[0x104];
    param_1[0x108] = param_1[0x105];
    param_1[0x109] = param_1[0x106];
    iVar3 = *param_1;
    param_1[0x104] = *(int *)(iVar3 + 8);
    param_1[0x105] = *(int *)(iVar3 + 0xc);
    param_1[0x106] = *(int *)(iVar3 + 0x10);
  }
  param_1[0xfd] = 1;
  param_1[0x129] = 0;
  *(undefined1 *)(param_1 + 0x12a) = 0;
  *(undefined1 *)((int)param_1 + 0x4a9) = 0;
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


// Spawn__9CBubbling  @ 000956b4
void Spawn__9CBubbling(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  float fVar3;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 2;
  uVar1 = (uint)ROUND(ABS(*(float *)(*param_1 + 0x1f8)));
  *(float *)(*param_1 + 0x150) = (float)((int)uVar1 >> 8);
  *(float *)(*param_1 + 0x154) = (float)(uVar1 & 0xff);
  uVar2 = 0;
  fVar3 = *(float *)(*param_1 + 0x1f8);
  if (0x3f < (byte)((0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) - 1)) {
    uVar2 = 0x3f800000;
  }
  *(undefined4 *)(*param_1 + 0x158) = uVar2;
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) == 0) {
    param_1[0xf9] = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)FizzThink__9CBubbling;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 2.0;
    param_1[0xf9] = 1;
  }
  return;
}


// Spawn__9CEnvLight  @ 000ac514
void Spawn__9CEnvLight(int *param_1)

{
  char local_40 [64];
  
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  sprintf(local_40,"%f",SUB84((double)*(float *)(gpGlobals + 0x28),0),
          (int)((ulonglong)(double)*(float *)(gpGlobals + 0x28) >> 0x20));
  (*DAT_001a7f30)("sv_skyvec_x",local_40);
  sprintf(local_40,"%f",(double)*(float *)(gpGlobals + 0x2c));
  (*DAT_001a7f30)("sv_skyvec_y",local_40);
  sprintf(local_40,"%f",SUB84((double)*(float *)(gpGlobals + 0x30),0),
          (int)((ulonglong)(double)*(float *)(gpGlobals + 0x30) >> 0x20));
  (*DAT_001a7f30)();
  Spawn__6CLight(param_1);
  return;
}


// Spawn__9CEnvSound  @ 000e2288
void Spawn__9CEnvSound(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_001a7fac)(0,0x3f000000);
  *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


// Spawn__9CEnvSpark  @ 000852b0
void Spawn__9CEnvSpark(int *param_1)

{
  float fVar1;
  longdouble lVar2;
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SparkThink__9CEnvSpark;
  }
  else if ((*(byte *)(*param_1 + 0x1a0) & 0x40) == 0) {
    param_1[7] = -0x10000;
    param_1[8] = (int)SparkStart__9CEnvSparkP11CBaseEntityT18USE_TYPEf;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)SparkThink__9CEnvSpark;
    param_1[7] = -0x10000;
    param_1[8] = (int)SparkStop__9CEnvSparkP11CBaseEntityT18USE_TYPEf;
  }
  lVar2 = (longdouble)(*DAT_001a7fac)(0,0x3fc00000);
  *(float *)(*param_1 + 0x104) = (float)((longdouble)0.1 + lVar2 + (longdouble)*gpGlobals);
  fVar1 = (float)param_1[0xf6];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    param_1[0xf6] = 0x3fc00000;
  }
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  return;
}


// Spawn__9CFuncPlat  @ 000c261c
void Spawn__9CFuncPlat(int *param_1)

{
  Setup__9CFuncPlat(param_1);
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  if (*(int *)(*param_1 + 0x1cc) == 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_1 + 0x107);
    param_1[0xfd] = 1;
  }
  else {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_1 + 0x104);
    param_1[0xfd] = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)PlatUse__9CFuncPlatP11CBaseEntityT18USE_TYPEf;
  }
  return;
}


// Spawn__9CFuncTank  @ 0009f9cc
void Spawn__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar6 = *param_1;
  param_1[0xfb] = *(int *)(iVar6 + 0x54);
  param_1[0xff] = *(int *)(iVar6 + 0x50);
  if ((*(byte *)(iVar6 + 0x1a0) & 1) != 0) {
    local_4 = *(float *)(iVar6 + 0x100) + 1.0;
    *(float *)(iVar6 + 0x104) = local_4;
  }
  (*DAT_001a7e90)(*param_1 + 0x50,&local_1c,&local_28,&local_34);
  fVar1 = (float)param_1[0x109];
  fVar2 = *(float *)(*param_1 + 0xc);
  fVar3 = *(float *)(*param_1 + 0x10);
  fVar4 = (float)param_1[0x10a];
  fVar5 = (float)param_1[0x10b];
  param_1[0x111] =
       (int)(*(float *)(*param_1 + 8) + fVar1 * local_1c + fVar4 * local_28 + fVar5 * local_34);
  param_1[0x112] = (int)(fVar2 + fVar1 * local_18 + fVar4 * local_24 + fVar5 * local_30);
  param_1[0x113] = (int)(fVar3 + fVar1 * local_14 + fVar4 * local_20 + fVar5 * local_2c);
  fVar1 = (float)param_1[0x104];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    param_1[0x104] = 0x3f800000;
  }
  if (5 < (uint)param_1[0x114]) {
    param_1[0x114] = 0;
  }
  iVar6 = *param_1;
  *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(iVar6 + 8);
  *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar6 + 0xc);
  *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar6 + 0x10);
  return;
}


// Spawn__9CFuncWall  @ 00080510
void Spawn__9CFuncWall(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x58) = DAT_001a7e08;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 2;
  return;
}


// Spawn__9CItemAmmo  @ 000ed150
void Spawn__9CItemAmmo(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  Spawn__5CItem(param_1);
  Precache__9CItemAmmo(param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),param_1[0xf7] + *(int *)(gpGlobals + 0x98));
  }
  else {
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),param_1[0xf8] + *(int *)(gpGlobals + 0x98));
    param_1[0x33] = param_1[0x33] << 1;
    param_1[0x35] = param_1[0x35] << 1;
    param_1[0x39] = param_1[0x39] << 1;
    param_1[0x37] = param_1[0x37] << 1;
  }
  local_c = 0x41800000;
  local_18 = 0xc1800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  local_4 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  return;
}


// Spawn__9CItemSoda  @ 0009afec
void Spawn__9CItemSoda(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/can.mdl");
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  param_1[3] = -0x10000;
  param_1[4] = (int)CanThink__9CItemSoda;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  return;
}


// Spawn__9CItemSuit  @ 0012c3bc
void Spawn__9CItemSuit(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/w_suit.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__9CPendulum  @ 00081d08
void Spawn__9CPendulum(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  
  AxisDir__11CBaseToggleP9entvars_s(*param_1);
  if ((*(byte *)(*param_1 + 0x1a0) & 8) == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
  }
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]
                 );
  fVar1 = (float)param_1[0xf7];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = *(float *)(*param_1 + 0x1f8);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x1f8) = 0x42c80000;
    }
    iVar5 = *param_1;
    param_1[0xf6] =
         (int)((*(float *)(iVar5 + 0x1f8) * *(float *)(iVar5 + 0x1f8)) /
              (ABS((float)param_1[0xf7]) + ABS((float)param_1[0xf7])));
    param_1[0xfa] = *(int *)(iVar5 + 0x1f8);
    param_1[0xff] = *(int *)(iVar5 + 0x50);
    param_1[0x100] = *(int *)(iVar5 + 0x54);
    param_1[0x101] = *(int *)(iVar5 + 0x58);
    fVar6 = (float)param_1[0xf7] * 0.5;
    fVar1 = *(float *)(iVar5 + 0x48);
    fVar2 = *(float *)(iVar5 + 0x4c);
    fVar3 = *(float *)(iVar5 + 0x54);
    fVar4 = *(float *)(iVar5 + 0x58);
    param_1[0xfc] = (int)(*(float *)(iVar5 + 0x50) + fVar6 * *(float *)(iVar5 + 0x44));
    param_1[0xfd] = (int)(fVar3 + fVar6 * fVar1);
    param_1[0xfe] = (int)(fVar4 + fVar6 * fVar2);
    if ((*(byte *)(iVar5 + 0x1a0) & 1) != 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_CallUseToggle__11CBaseEntity;
      *(float *)(iVar5 + 0x104) = *gpGlobals + 0.1;
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


// Spawn__9CPushable  @ 0009f12c
void Spawn__9CPushable(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  if (*(char *)(*param_1 + 0x1a0) < '\0') {
    Spawn__10CBreakable(param_1);
  }
  else {
    (**(code **)(param_1[0xf5] + 0xc))(param_1);
  }
  *(undefined4 *)(*param_1 + 0x108) = 0xd;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  if (399.0 < *(float *)(*param_1 + 0x120)) {
    *(undefined4 *)(*param_1 + 0x120) = 0x43c78000;
  }
  param_1[0xff] = (int)(400.0 - *(float *)(*param_1 + 0x120));
  pbVar1 = (byte *)(*param_1 + 0x1a5);
  *pbVar1 = *pbVar1 | 0x80;
  *(undefined4 *)(*param_1 + 0x120) = 0;
  *(float *)(*param_1 + 0x10) = *(float *)(*param_1 + 0x10) + 1.0;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar2 = *param_1;
  *(int *)(iVar2 + 0x110) =
       (int)ROUND((*(float *)(iVar2 + 0xec) - *(float *)(iVar2 + 0xe0)) *
                  (*(float *)(iVar2 + 0xe8) - *(float *)(iVar2 + 0xdc)) *
                  (float)*(int *)(iVar2 + 0x110) * 0.0005);
  param_1[0x100] = 0;
  return;
}


// Spawn__9CRecharge  @ 000a8710
void Spawn__9CRecharge(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[0x120] = (int)ROUND(DAT_001aa498);
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


// Spawn__9CSoundEnt  @ 000e3ed4
void Spawn__9CSoundEnt(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  Initialize__9CSoundEnt(param_1);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  return;
}


// Spawn__9CSprayCanP9entvars_s  @ 000cfd24
void Spawn__9CSprayCanP9entvars_s(int *param_1,int param_2)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *param_1;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  fVar2 = *(float *)(param_2 + 0x10);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar3 + 0xc) = uVar1;
  *(float *)(iVar3 + 0x10) = fVar2 + 32.0;
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


// Spawn__9CTFDetect  @ 000fb17c
void Spawn__9CTFDetect(void)

{
  return;
}


// Spawn__9CTestHullP9entvars_s  @ 000bb390
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__9CTestHullP9entvars_s(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),"models/player.mdl");
  local_c = 0x41800000;
  local_4 = 0x42900000;
  local_18 = 0xc1800000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  *(undefined4 *)(*param_1 + 0x10c) = 3;
  *(undefined4 *)(*param_1 + 0x108) = 4;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(undefined4 *)(*param_1 + 0x160) = 0x42480000;
  *(undefined4 *)(*param_1 + 0xb0) = 0x41000000;
  if (WorldGraph == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)DropDelay__9CTestHull;
    iVar2 = *param_1;
    fVar1 = _FUN_00138c40 + *gpGlobals;
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


// Spawn__9CWreckage  @ 000aa0b0
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
    (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                    *(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]);
  }
  param_1[0x187] = (int)ROUND(*gpGlobals);
  return;
}


// Spawn__9CXenSpore  @ 00115974
void Spawn__9CXenSpore(int *param_1)

{
  longdouble lVar1;
  
  (**(code **)(param_1[0xf5] + 0xc))(param_1);
  (*DAT_001a7e48)(*(undefined4 *)(*param_1 + 0x208),
                  *(undefined4 *)(_9CXenSpore_pModelNames + *(int *)(*param_1 + 0x110) * 4));
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 2;
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  lVar1 = (longdouble)(*DAT_001a7fac)(0,0x437f0000);
  *(float *)(*param_1 + 0x130) = (float)lVar1;
  lVar1 = (longdouble)(*DAT_001a7fac)(0x3f333333,0x3fb33333);
  *(float *)(*param_1 + 0x138) = (float)lVar1;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  lVar1 = (longdouble)(*DAT_001a7fac)(0x3dcccccd,0x3ecccccd);
  *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


