// Spawn__10CBreakable  @ 000b2260
void Spawn__10CBreakable(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  *(undefined4 *)(*param_1 + 0xec) = 4;
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  param_1[0xf8] = *(int *)(*param_1 + 0x54);
  *(undefined4 *)(*param_1 + 0x54) = 0;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  param_1[5] = -0x10000;
  param_1[6] = (int)BreakTouch__10CBreakableP11CBaseEntity;
  if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  iVar2 = IsBreakable__10CBreakable(param_1);
  if ((iVar2 == 0) && (*(int *)(*param_1 + 0x128) != 0)) {
    pbVar1 = (byte *)(*param_1 + 0x187);
    *pbVar1 = *pbVar1 | 2;
  }
  return;
}


// Spawn__10CCineBlood  @ 000bb5a0
void Spawn__10CCineBlood(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)BloodStart__10CCineBloodP11CBaseEntityT18USE_TYPEf;
  *(undefined4 *)(*param_1 + 0x140) = 0x41a00000;
  return;
}


// Spawn__10CEnvFunnel  @ 000afd40
void Spawn__10CEnvFunnel(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  return;
}


// Spawn__10CEnvGlobal  @ 0009d610
void Spawn__10CEnvGlobal(int *param_1)

{
  int iVar1;
  
  if (param_1[0xf3] == 0) {
    (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  }
  else if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
    iVar1 = Find__12CGlobalStatei(&gGlobalState,param_1[0xf3]);
    if (iVar1 == 0) {
      EntityAdd__12CGlobalStateii12GLOBALESTATE
                (&gGlobalState,param_1[0xf3],*(undefined4 *)(gpGlobals + 0xc),param_1[0xf5]);
    }
  }
  return;
}


// Spawn__10CFuncTrain  @ 000d28e0
void Spawn__10CFuncTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
  }
  if (*(int *)(*param_1 + 0x1a8) == 0) {
    (*DAT_001755b4)(1,"FuncTrain with no target");
  }
  fVar1 = *(float *)(*param_1 + 0x1c0);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1c0) = 0x40000000;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  if ((*(byte *)(*param_1 + 0x180) & 8) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
  }
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar2 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar2,iVar2 + 0xbc,iVar2 + 200);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  param_1[0x11f] = 0;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x11c]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x11c] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x11c] = 0x3f59999a;
  }
  return;
}


// Spawn__10CFurniture  @ 000e8cf0
void Spawn__10CFurniture(int *param_1)

{
  (*g_engfuncs)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  *(undefined4 *)(*param_1 + 0x140) = 0x479c4000;
  *(undefined4 *)(*param_1 + 0x14c) = 0x40000000;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x90) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0x110) = 0;
  (**(code **)(param_1[0xf2] + 0x11c))(param_1);
  return;
}


// Spawn__10CGunTarget  @ 000d56b0
void Spawn__10CGunTarget(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0xec) = 4;
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
  }
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) | 0x20;
  param_1[0x184] = 0;
  *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_1 + 0x140);
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x180) & 1) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)Start__10CGunTarget;
    *(float *)(iVar2 + 0xe4) = *(float *)(iVar2 + 0xe0) + 0.3;
  }
  return;
}


// Spawn__10CHealthKit  @ 000bccb0
void Spawn__10CHealthKit(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_medkit.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__10CLaserSpot  @ 001030b0
void Spawn__10CLaserSpot(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 3;
  *(undefined4 *)(*param_1 + 0x13c) = 0xe;
  *(undefined4 *)(*param_1 + 300) = 0x437f0000;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"sprites/laserdot.spr");
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__10CLightning  @ 000abe00
void Spawn__10CLightning(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1[0xfd] == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    *(float *)(*param_1 + 0x1c4) = *gpGlobals;
    bVar3 = false;
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
      bVar3 = (*(byte *)(*param_1 + 0x180) & 8) == 0;
    }
    if (bVar3) {
      param_1[3] = 0;
      param_1[4] = 0;
      fVar1 = *(float *)(*param_1 + 0x1c0);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        param_1[3] = -0x10000;
        param_1[4] = (int)DamageThink__10CLightning;
        *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
      }
      iVar2 = *param_1;
      if (*(int *)(iVar2 + 0x1ac) != 0) {
        if (((*(byte *)(iVar2 + 0x180) ^ 1) & 1) == 0) {
          param_1[0xf3] = 1;
        }
        else {
          *(undefined4 *)(iVar2 + 0xf8) = 0x80;
          param_1[0xf3] = 0;
          *(undefined4 *)(*param_1 + 0xe4) = 0;
        }
        param_1[7] = -0x10000;
        param_1[8] = (int)ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf;
      }
    }
    else {
      param_1[0xf3] = 0;
      if (*(int *)(*param_1 + 0x1ac) != 0) {
        param_1[7] = -0x10000;
        param_1[8] = (int)StrikeUse__10CLightningP11CBaseEntityT18USE_TYPEf;
      }
      if ((*(int *)(*param_1 + 0x1ac) == 0) || ((*(byte *)(*param_1 + 0x180) & 1) != 0)) {
        param_1[3] = -0x10000;
        param_1[4] = (int)StrikeThink__10CLightning;
        *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
      }
    }
  }
  return;
}


// Spawn__10CPathTrack  @ 000d0460
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__10CPathTrack(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0xec) = 1;
  local_10 = _FUN_00137ab0;
  local_c = _FUN_00137ab0;
  local_8 = _FUN_00137ab0;
  local_1c = 0xc1000000;
  local_18 = 0xc1000000;
  local_14 = 0xc1000000;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[0xf5] = 0;
  param_1[0xf6] = 0;
  return;
}


// Spawn__10CRotButton  @ 0009f020
void Spawn__10CRotButton(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar7 = ButtonSound__Fi(param_1[0x128]);
  (*DAT_001754c4)(uVar7);
  uVar7 = (*DAT_001755cc)(uVar7);
  *(undefined4 *)(*param_1 + 0x1c8) = uVar7;
  AxisDir__11CBaseToggleP9entvars_t(*param_1);
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x180) & 2) != 0) {
    *(float *)(iVar6 + 0x44) = *(float *)(iVar6 + 0x44) * -1.0;
    *(float *)(iVar6 + 0x48) = *(float *)(iVar6 + 0x48) * -1.0;
    *(float *)(iVar6 + 0x4c) = *(float *)(iVar6 + 0x4c) * -1.0;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
  }
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42200000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xfd]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xfd] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xfd] = 0x3f800000;
  }
  fVar1 = *(float *)(*param_1 + 0x140);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  }
  param_1[0xfa] = 1;
  iVar6 = *param_1;
  param_1[0x107] = *(int *)(iVar6 + 0x50);
  param_1[0x108] = *(int *)(iVar6 + 0x54);
  param_1[0x109] = *(int *)(iVar6 + 0x58);
  fVar1 = (float)param_1[0xfc];
  fVar2 = *(float *)(iVar6 + 0x48);
  fVar3 = *(float *)(iVar6 + 0x4c);
  fVar4 = *(float *)(iVar6 + 0x54);
  fVar5 = *(float *)(iVar6 + 0x58);
  param_1[0x10a] = (int)(*(float *)(iVar6 + 0x50) + fVar1 * *(float *)(iVar6 + 0x44));
  param_1[0x10b] = (int)(fVar4 + fVar1 * fVar2);
  param_1[0x10c] = (int)(fVar5 + fVar1 * fVar3);
  fVar1 = (float)param_1[0xfd];
  param_1[0x11b] =
       (uint)((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40);
  param_1[0x11c] = 1;
  if ((*(byte *)(iVar6 + 0x181) & 1) == 0) {
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


// Spawn__10CTFGrenade  @ 000fb1d0
void Spawn__10CTFGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  longdouble lVar9;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 10;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x100) = 0x3f000000;
  param_1[0x184] = 1;
  param_1[0x185] = 1;
  (**(code **)(param_1[0xf2] + 0x220))(param_1);
  local_10 = 0.0;
  local_c = 0.0;
  local_8 = 0.0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  iVar7 = *param_1;
  fVar1 = gpGlobals[10];
  fVar2 = gpGlobals[0xb];
  fVar3 = gpGlobals[0xc];
  fVar4 = gpGlobals[0xd];
  fVar5 = gpGlobals[0xe];
  fVar6 = gpGlobals[0xf];
  lVar9 = (longdouble)(*DAT_0017562c)(0xc1200000,0x41200000);
  local_8 = fVar3 * 600.0 + fVar6 * 200.0 + (float)(lVar9 * (longdouble)gpGlobals[0x12]);
  local_10 = (float)((longdouble)(fVar1 * 600.0 + fVar4 * 200.0) +
                    lVar9 * (longdouble)gpGlobals[0x10]);
  local_c = (float)((longdouble)(fVar2 * 600.0 + fVar5 * 200.0) +
                   lVar9 * (longdouble)gpGlobals[0x11]);
  lVar9 = (longdouble)(*DAT_0017562c)(0xc1200000,0x41200000);
  pfVar8 = gpGlobals;
  fVar1 = gpGlobals[0xe];
  fVar2 = gpGlobals[0xf];
  *(float *)(iVar7 + 0x20) = (float)((longdouble)local_10 + lVar9 * (longdouble)gpGlobals[0xd]);
  *(float *)(iVar7 + 0x24) = (float)((longdouble)local_c + lVar9 * (longdouble)fVar1);
  *(float *)(iVar7 + 0x28) = local_8 + (float)(lVar9 * (longdouble)fVar2);
  iVar7 = *param_1;
  *(undefined4 *)(iVar7 + 0x5c) = 0x43960000;
  *(undefined4 *)(iVar7 + 0x60) = 0x43960000;
  *(undefined4 *)(iVar7 + 100) = 0x43960000;
  *(float *)(*param_1 + 0xe4) = *pfVar8 + 2.5;
  param_1[3] = -0x10000;
  param_1[4] = (int)Detonate__8CGrenade;
  *(undefined4 *)(*param_1 + 0x1c0) = 0x42f00000;
  return;
}


// Spawn__10CTFMedikit  @ 000f98b0
void Spawn__10CTFMedikit(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 3;
  param_1[0x104] = -1;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFNailgun  @ 001003d0
void Spawn__10CTFNailgun(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 4;
  param_1[0x108] = 0x32;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFRailgun  @ 00100c90
void Spawn__10CTFRailgun(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_railgun" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 2;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_gauss.mdl");
  param_1[0x108] = 0x11;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFRpgAmmo  @ 001284e0
void Spawn__10CTFRpgAmmo(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_rpgammo.mdl");
  Spawn__15CBasePlayerAmmo(param_1);
  return;
}


// Spawn__10CTFShotgun  @ 00101ec0
void Spawn__10CTFShotgun(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 8;
  param_1[0x2c] = 0;
  param_1[0x108] = 8;
  param_1[0x10e] = 8;
  param_1[0x10f] = 0x3e800000;
  param_1[0x10d] = 1;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CTFSpanner  @ 000f9380
void Spawn__10CTFSpanner(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 4;
  param_1[0x104] = -1;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__10CWeaponBox  @ 0011c150
void Spawn__10CWeaponBox(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/backpack.mdl");
  param_1[0xf9] = 0;
  param_1[0xfa] = 0;
  return;
}


// Spawn__10CWorldItem  @ 000bd430
void Spawn__10CWorldItem(int *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  
  piVar2 = (int *)0x0;
  iVar4 = param_1[0xf3];
  if (iVar4 == 0x2b) {
    iVar4 = *param_1 + 0x50;
    iVar1 = *param_1 + 8;
    pcVar3 = "item_security";
  }
  else if (iVar4 < 0x2c) {
    if (iVar4 != 0x2a) goto LAB_000bd4db;
    iVar4 = *param_1 + 0x50;
    iVar1 = *param_1 + 8;
    pcVar3 = "item_antidote";
  }
  else if (iVar4 == 0x2c) {
    iVar4 = *param_1 + 0x50;
    iVar1 = *param_1 + 8;
    pcVar3 = "item_battery";
  }
  else {
    if (iVar4 != 0x2d) goto LAB_000bd4db;
    iVar4 = *param_1 + 0x50;
    iVar1 = *param_1 + 8;
    pcVar3 = "item_suit";
  }
  piVar2 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s(pcVar3,iVar1,iVar4,0);
LAB_000bd4db:
  if (piVar2 == (int *)0x0) {
    (*DAT_001755b4)(1,"unable to create world_item %d\n",param_1[0xf3]);
  }
  else {
    *(undefined4 *)(*piVar2 + 0x1a8) = *(undefined4 *)(*param_1 + 0x1a8);
    *(undefined4 *)(*piVar2 + 0x1ac) = *(undefined4 *)(*param_1 + 0x1ac);
    *(undefined4 *)(*piVar2 + 0x180) = *(undefined4 *)(*param_1 + 0x180);
  }
  (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  return;
}


// Spawn__10CXenPLight  @ 0011e280
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
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/light.mdl");
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  local_10 = 0x42a00000;
  local_c = 0x42a00000;
  local_8 = 32.0;
  local_1c = -80.0;
  local_18 = -80.0;
  local_14 = 0.0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  SetActivity__13CActAnimating8Activity(param_1,1);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  lVar8 = (longdouble)(*DAT_0017562c)(0,0x437f0000);
  *(float *)(*param_1 + 0x110) = (float)lVar8;
  iVar5 = *param_1;
  local_8 = (*(float *)(iVar5 + 0xc4) + *(float *)(iVar5 + 0xd0)) * 0.5;
  local_10 = 0;
  local_c = 0;
  local_1c = *(float *)(iVar5 + 8) + 0.0;
  local_18 = *(float *)(iVar5 + 0xc) + 0.0;
  local_14 = *(float *)(iVar5 + 0x10) + local_8;
  piVar6 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/flare3.spr",&local_1c,0);
  param_1[0xfb] = (int)piVar6;
  iVar5 = *param_1;
  fVar1 = *(float *)(iVar5 + 0x130);
  fVar2 = *(float *)(iVar5 + 0x134);
  fVar3 = *(float *)(iVar5 + 0x138);
  fVar4 = *(float *)(iVar5 + 300);
  uVar7 = *(undefined4 *)(iVar5 + 0x13c);
  *(undefined4 *)(*piVar6 + 0x128) = 3;
  *(float *)(*piVar6 + 0x130) = (float)(int)ROUND(fVar1);
  *(float *)(*piVar6 + 0x134) = (float)(int)ROUND(fVar2);
  *(float *)(*piVar6 + 0x138) = (float)(int)ROUND(fVar3);
  *(float *)(*piVar6 + 300) = (float)(int)ROUND(fVar4);
  *(undefined4 *)(*piVar6 + 0x13c) = uVar7;
  iVar5 = *(int *)(*param_1 + 0x1e8);
  piVar6 = (int *)param_1[0xfb];
  if (iVar5 != 0) {
    uVar7 = (*DAT_001755dc)(iVar5);
    *(undefined4 *)(*piVar6 + 0xf0) = uVar7;
    *(undefined4 *)(*piVar6 + 0xf4) = 1;
    *(int *)(*piVar6 + 0x174) = iVar5;
    *(undefined4 *)(*piVar6 + 0xe8) = 0xc;
  }
  return;
}


// Spawn__11CBaseButton  @ 0009e2b0
void Spawn__11CBaseButton(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  bool bVar5;
  undefined4 uVar6;
  
  uVar6 = ButtonSound__Fi(param_1[0x128]);
  (*DAT_001754c4)(uVar6);
  uVar6 = (*DAT_001755cc)(uVar6);
  *(undefined4 *)(*param_1 + 0x1c8) = uVar6;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  if ((*(byte *)(*param_1 + 0x180) & 0x40) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)ButtonSpark__11CBaseButton;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.5;
  }
  SetMovedir__FP9entvars_t(*param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  *(undefined4 *)(*param_1 + 0xec) = 4;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),*(int *)(*param_1 + 0x98) + (int)gpGlobals[0x26]
                 );
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42200000;
  }
  fVar1 = *(float *)(*param_1 + 0x140);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xfd]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xfd] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xfd] = 0x3f800000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xfe]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xfe] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xfe] = 0x40800000;
  }
  param_1[0xfa] = 1;
  iVar3 = *param_1;
  param_1[0x101] = *(int *)(iVar3 + 8);
  param_1[0x102] = *(int *)(iVar3 + 0xc);
  param_1[0x103] = *(int *)(iVar3 + 0x10);
  fVar4 = (ABS((*(float *)(iVar3 + 0xd8) - 2.0) * *(float *)(iVar3 + 0x48)) +
           ABS((*(float *)(iVar3 + 0xd4) - 2.0) * *(float *)(iVar3 + 0x44)) +
          ABS((*(float *)(iVar3 + 0xdc) - 2.0) * *(float *)(iVar3 + 0x4c))) - (float)param_1[0xfe];
  fVar1 = *(float *)(iVar3 + 0x48);
  fVar2 = *(float *)(iVar3 + 0x4c);
  param_1[0x104] = (int)((float)param_1[0x101] + fVar4 * *(float *)(iVar3 + 0x44));
  param_1[0x105] = (int)((float)param_1[0x102] + fVar4 * fVar1);
  param_1[0x106] = (int)((float)param_1[0x103] + fVar4 * fVar2);
  bVar5 = false;
  fVar1 = SQRT(((float)param_1[0x106] - (float)param_1[0x103]) *
               ((float)param_1[0x106] - (float)param_1[0x103]) +
               ((float)param_1[0x105] - (float)param_1[0x102]) *
               ((float)param_1[0x105] - (float)param_1[0x102]) +
               ((float)param_1[0x104] - (float)param_1[0x101]) *
               ((float)param_1[0x104] - (float)param_1[0x101]));
  if (((byte)(fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) ||
     ((*(byte *)(iVar3 + 0x180) & 1) != 0)) {
    bVar5 = true;
  }
  if (bVar5) {
    param_1[0x104] = param_1[0x101];
    param_1[0x105] = param_1[0x102];
    param_1[0x106] = param_1[0x103];
  }
  fVar1 = (float)param_1[0xfd];
  param_1[0x11b] =
       (uint)((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) == 0x40);
  param_1[0x11c] = 0;
  if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
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


// Spawn__11CBaseEntity  @ 0010e570
void Spawn__11CBaseEntity(void)

{
  return;
}


// Spawn__11CBasePlayer  @ 000dc740
void Spawn__11CBasePlayer(int *param_1)

{
  byte bVar1;
  float *pfVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  ushort in_FPUControlWord;
  longdouble lVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  ushort local_10;
  undefined2 uStack_e;
  ushort local_c;
  float local_8;
  
  pfVar2 = gpGlobals;
  *(int *)*param_1 = (int)"player" - (int)gpGlobals[0x26];
  *(undefined4 *)(*param_1 + 0x140) = 0x42c80000;
  *(undefined4 *)(*param_1 + 0x19c) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(undefined4 *)(*param_1 + 0xe8) = 3;
  *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_1 + 0x140);
  *(undefined4 *)(*param_1 + 0x184) = 8;
  *(float *)(*param_1 + 0x1dc) = *pfVar2 + 12.0;
  *(undefined4 *)(*param_1 + 0x1c0) = 0x40000000;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x150) = 0;
  *(undefined4 *)(*param_1 + 0x1b8) = 0;
  *(undefined4 *)(*param_1 + 0x1bc) = 0;
  param_1[499] = -1;
  param_1[0x174] = 0;
  param_1[0x19a] = 0;
  param_1[0x1fc] = 0;
  param_1[0x204] = 0;
  param_1[0x205] = -1;
  param_1[0x260] = 0;
  local_8 = *pfVar2 + 2.0;
  param_1[0x1ea] = (int)local_8;
  param_1[0x19c] = 0;
  param_1[0x1ec] = 0;
  param_1[0x134] = 0x3f000000;
  param_1[0x178] = 0xf7;
  param_1[0x173] = (int)*pfVar2;
  (**(code **)(param_1[0xf2] + 0x78))(param_1);
  *(undefined1 *)(param_1 + 0x263) = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x45] = 0x3f800000;
  param_1[0x18b] = 99;
  param_1[0x18a] = 0x3f800000;
  param_1[0x192] = 0;
  param_1[0x25e] = 0;
  param_1[0x25d] = 0;
  param_1[0x23] = 0;
  param_1[0xea] = 0;
  param_1[0xeb] = 0;
  param_1[0xe9] = 0;
  param_1[0xe8] = 0;
  param_1[99] = (int)(*gpGlobals + 10.0);
  param_1[0x33e] = 0;
  param_1[0x72] = 0;
  if (param_1[0xc] != 0) {
    iVar5 = param_1[0xc];
    param_1[0xb] = iVar5;
    param_1[0xc] = 0;
    if (iVar5 == 10) {
      *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 8;
    }
    else {
      *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) & 0xf7;
    }
  }
  bVar1 = *(byte *)((int)param_1 + 0x89);
  if ((*(byte *)(param_1 + 0x22) & 8) == 0) {
    param_1[0x22] = 0;
  }
  else {
    iVar5 = param_1[0xb];
    do {
      do {
        do {
          lVar6 = (longdouble)(*DAT_0017562c)(0,0x41100000);
          local_c = in_FPUControlWord & 0xf3ff | 0x400;
          _local_10 = CONCAT22(uStack_e,in_FPUControlWord);
          local_18 = (int)ROUND((longdouble)1 + ROUND(lVar6));
          param_1[0xb] = local_18;
          iVar3 = IsLegalClass__11CBasePlayeri(param_1,local_18);
        } while (iVar3 == 0);
      } while (param_1[0xb] == iVar5);
      iVar3 = ClassIsRestricted__Ffi((float)param_1[0x48],param_1[0xb]);
    } while (iVar3 != 0);
    param_1[0x22] = 8;
  }
  if ((bVar1 & 0x10) != 0) {
    *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) | 0x10;
  }
  TeamFortress_ExecClassScript__11CBasePlayer(param_1);
  if (param_1[0xb] != 9) {
    Engineer_RemoveBuildings__11CBasePlayer(param_1);
  }
  *(undefined4 *)(*param_1 + 0x14c) = 0x40000000;
  TeamFortress_PrintClassName__11CBasePlayeri(param_1,param_1[0xb]);
  TeamFortress_SetEquipment__11CBasePlayer(param_1);
  TeamFortress_SetHealth__11CBasePlayer(param_1);
  TeamFortress_SetSpeed__11CBasePlayer(param_1);
  TeamFortress_SetSkin__11CBasePlayer(param_1);
  param_1[0x50] = 0;
  param_1[0x62] = 0;
  param_1[0x33d] = 0;
  param_1[0x33c] = (int)*gpGlobals;
  param_1[0x33b] = -0x40800000;
  if (param_1[0xb] == 0) {
    param_1[0x45] = 0x3f800000;
  }
  param_1[5] = -0x10000;
  param_1[6] = (int)PlayerTouch__11CBasePlayerP11CBaseEntity;
  if (param_1[0x7d] != 0) {
    uVar4 = UTIL_dtos1__Fi(param_1[0x7d],0,0,0);
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Game_battleid",uVar4);
  }
  (**(code **)(*g_pGameRules + 0x60))(g_pGameRules,param_1);
  uVar4 = LookupActivity__14CBaseAnimatingi(param_1,1);
  *(undefined4 *)(*param_1 + 0x108) = uVar4;
  iVar5 = *param_1;
  if ((*(byte *)(iVar5 + 0x185) & 0x40) == 0) {
    local_30 = 0x41800000;
    local_2c = 0x41800000;
    local_28 = 0x42100000;
    puVar8 = &local_30;
    local_24 = 0xc1800000;
    local_20 = 0xc1800000;
    local_1c = 0xc2100000;
    puVar7 = &local_24;
    iVar5 = *param_1;
  }
  else {
    local_24 = 0x41800000;
    local_20 = 0x41800000;
    local_1c = 0x41900000;
    puVar8 = &local_24;
    local_30 = 0xc1800000;
    local_2c = 0xc1800000;
    local_28 = 0xc1900000;
    puVar7 = &local_30;
  }
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar5,puVar7,puVar8);
  iVar5 = *param_1;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x41e00000;
  *(undefined4 *)(iVar5 + 0x154) = 0;
  *(undefined4 *)(iVar5 + 0x158) = 0;
  *(undefined4 *)(iVar5 + 0x15c) = 0x41e00000;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  local_30 = 0;
  local_2c = 0x42000000;
  local_28 = 0;
  param_1[0x17f] = 0;
  param_1[0x180] = 0x42000000;
  param_1[0x181] = 0;
  if (param_1[0x184] == -1) {
    (*DAT_001755b4)(1,"Couldn\'t alloc player sound slot!\n");
  }
  param_1[0x1fb] = 0;
  param_1[0x20e] = 0;
  param_1[500] = 1;
  param_1[0x203] = -1;
  param_1[0x1f7] = 0;
  param_1[0x20d] = 0;
  param_1[0x201] = -1;
  param_1[0x2b] = -0x40800000;
  param_1[0x2a] = -0x40800000;
  iVar5 = 0;
  do {
    param_1[iVar5 + 0x20f] = 0;
    param_1[iVar5 + 0x22f] = 0;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  param_1[0x259] = 0;
  param_1[600] = 0;
  (**(code **)(*g_pGameRules + 0x50))(g_pGameRules,param_1);
  return;
}


// Spawn__11CBaseTurret  @ 00113ae0
void Spawn__11CBaseTurret(int *param_1)

{
  float fVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  *(undefined4 *)(*param_1 + 0xe8) = 5;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 3;
  fVar1 = gpGlobals[5];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x14c) = 0x40000000;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) | 0x20;
  param_1[7] = -0x10000;
  param_1[8] = (int)TurretUse__11CBaseTurretP11CBaseEntityT18USE_TYPEf;
  fVar1 = gpGlobals[5];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[400] = 1;
  }
  if ((*(uint *)(*param_1 + 0x180) & 0x60) == 0x20) {
    param_1[400] = 1;
  }
  ResetSequenceInfo__14CBaseAnimating(param_1);
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  param_1[0x134] = -0x40800000;
  return;
}


// Spawn__11CBloodSplatP9entvars_t  @ 000dd500
void Spawn__11CBloodSplatP9entvars_t(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *param_1;
  fVar1 = *(float *)(param_2 + 0xc);
  fVar2 = *(float *)(param_2 + 0x10);
  *(float *)(iVar3 + 8) = *(float *)(param_2 + 8) + 0.0;
  *(float *)(iVar3 + 0xc) = fVar1 + 0.0;
  *(float *)(iVar3 + 0x10) = fVar2 + 32.0;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(param_2 + 0x74);
  *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(param_2 + 0x78);
  *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(param_2 + 0x7c);
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(param_2 + 0x1e8);
  param_1[3] = -0x10000;
  param_1[4] = (int)Spray__11CBloodSplat;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


// Spawn__11CCine2Slave  @ 00124cb0
void Spawn__11CCine2Slave(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine2_slave.mdl");
  return;
}


// Spawn__11CCineBarney  @ 00124d50
void Spawn__11CCineBarney(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-barney.mdl");
  return;
}


// Spawn__11CFireAndDie  @ 00110e50
void Spawn__11CFireAndDie(undefined4 *param_1)

{
  *(int *)*param_1 = (int)"fireanddie" - *(int *)(gpGlobals + 0x98);
  return;
}


// Spawn__11CGibShooter  @ 000ae730
void Spawn__11CGibShooter(int *param_1)

{
  undefined4 uVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf3] = 0x3dcccccd;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xfb]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xfb] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xfb] = 0x41c80000;
  }
  SetMovedir__FP9entvars_t(*param_1);
  uVar1 = (*DAT_001754d0)(param_1[0xf8]);
  *(undefined4 *)(*param_1 + 0xf4) = uVar1;
  return;
}


// Spawn__11CItemHealth  @ 000f53f0
void Spawn__11CItemHealth(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_medkit.mdl");
    Spawn__5CItem(param_1);
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0xf3] = 0x41a00000;
    }
    if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
      if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
        *(int *)(*param_1 + 0x1c8) = (int)"items/r_item1.wav" - *(int *)(gpGlobals + 0x98);
        param_1[0xf4] = 100;
        param_1[0xf5] = 1;
        return;
      }
      *(int *)(*param_1 + 0x1c8) = (int)"items/health1.wav" - *(int *)(gpGlobals + 0x98);
      param_1[0xf4] = 0x19;
    }
    else {
      *(int *)(*param_1 + 0x1c8) = (int)"items/smallmedkit1.wav" - *(int *)(gpGlobals + 0x98);
      param_1[0xf4] = 0xf;
    }
    param_1[0xf5] = 0;
  }
  return;
}


// Spawn__11CMiniTurret  @ 00113e90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__11CMiniTurret(int *param_1)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/miniturret.mdl");
  *(undefined4 *)(*param_1 + 0x140) = _DAT_00177a60;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0x414c0000;
  param_1[0x17f] = 0;
  param_1[0x180] = 0;
  param_1[0x181] = 0x414c0000;
  param_1[0x184] = 0;
  *(undefined4 *)(*param_1 + 0x15c) = 0x414c0000;
  Spawn__11CBaseTurret(param_1);
  param_1[0x189] = 0x10;
  param_1[0x188] = 0x20;
  param_1[0x18a] = -0xf;
  uStack_10 = 0x41800000;
  uStack_c = 0x41800000;
  uStack_8 = 0x41800000;
  uStack_1c = 0xc1800000;
  uStack_18 = 0xc1800000;
  uStack_14 = 0xc1800000;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&uStack_1c,&uStack_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.3;
  return;
}


// Spawn__11CNodeViewer  @ 000cf930
void Spawn__11CNodeViewer(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_10;
  
  if ((WorldGraph == 0) || (DAT_001758c4 == 0)) {
    (*DAT_001755b4)(1,"Graph not ready!\n");
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    iVar2 = strcmp((char *)(*(int *)*param_1 + gpGlobals[0x26]),"node_viewer_fly");
    if (iVar2 == 0) {
      param_1[0x1f6] = 3;
      param_1[0x1f7] = 2;
      iVar2 = 0x42c80000;
      iVar1 = 0x437f0000;
      local_10 = 0x43200000;
    }
    else {
      iVar2 = strcmp((char *)(*(int *)*param_1 + gpGlobals[0x26]),"node_viewer_large");
      if (iVar2 == 0) {
        param_1[0x1f6] = 2;
        param_1[0x1f7] = 5;
        iVar2 = 0x437f0000;
        iVar1 = 0x43200000;
        local_10 = 0x42c80000;
      }
      else {
        param_1[0x1f6] = 1;
        param_1[0x1f7] = 5;
        iVar2 = 0x43200000;
        iVar1 = 0x42c80000;
        local_10 = 0x437f0000;
      }
    }
    param_1[0x1f8] = local_10;
    param_1[0x1f9] = iVar2;
    param_1[0x1fa] = iVar1;
    iVar2 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,param_1[0x1f7]);
    param_1[0xf3] = iVar2;
    if (iVar2 < 0) {
      (*DAT_001755b4)(1,"No nearby node\n");
    }
    else {
      param_1[0xf5] = 0;
      (*DAT_001755b4)(2,"basenode %d\n",param_1[0xf3]);
      if (DAT_001758d8 < 0x80) {
        iVar2 = 0;
        if (0 < DAT_001758d8) {
          do {
            uVar3 = NextNodeInRoute__6CGraphiiii(&WorldGraph,iVar2,param_1[0xf3],param_1[0x1f6],0);
            AddNode__11CNodeViewerii(param_1,iVar2,uVar3);
            iVar2 = iVar2 + 1;
          } while (iVar2 < DAT_001758d8);
        }
      }
      else {
        FindNodeConnections__11CNodeVieweri(param_1,param_1[0xf3]);
        iVar2 = 0;
        do {
          iVar1 = param_1[0xf5];
          for (; iVar2 < iVar1; iVar2 = iVar2 + 1) {
            FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0xf6]);
            FindNodeConnections__11CNodeVieweri(param_1,param_1[iVar2 + 0x176]);
          }
        } while (iVar1 != param_1[0xf5]);
      }
      (*DAT_001755b4)(2,"%d nodes\n",param_1[0xf5]);
      param_1[0xf4] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)DrawThink__11CNodeViewer;
      *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
    }
  }
  return;
}


// Spawn__11CNullEntity  @ 000f02b0
void Spawn__11CNullEntity(int *param_1)

{
  (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  return;
}


// Spawn__11CPathCorner  @ 000d01b0
void Spawn__11CPathCorner(void)

{
  return;
}


// Spawn__11CTFAssaultC  @ 000f7580
void Spawn__11CTFAssaultC(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_ac" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 4;
  param_1[0x108] = 0x19;
  param_1[0x10b] = 0;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__11CTFGoalItem  @ 00109480
void Spawn__11CTFGoalItem(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  iVar3 = CheckExistence__11CBaseEntity(param_1);
  iVar2 = gpGlobals;
  if (iVar3 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    *(int *)*param_1 = (int)"item_tfgoal" - *(int *)(gpGlobals + 0x98);
    if (*(int *)(*param_1 + 0x98) != 0) {
      (*g_engfuncs)(*(int *)(*param_1 + 0x98) + *(int *)(iVar2 + 0x98));
      (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                      *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
      uVar4 = LookupSequence__14CBaseAnimatingPCc(param_1,"not_carried");
      *(undefined4 *)(*param_1 + 0x108) = uVar4;
      if (*(int *)(*param_1 + 0x108) != -1) {
        ResetSequenceInfo__14CBaseAnimating(param_1);
        *(undefined4 *)(*param_1 + 0x110) = 0;
      }
    }
    (*DAT_001754c4)("items/itembk2.wav");
    if (*(int *)(*param_1 + 0x1c8) != 0) {
      (*DAT_001754c4)(*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    }
    if (param_1[0x86] == 0) {
      param_1[0x86] = 2;
    }
    if ((*(byte *)((int)param_1 + 0x221) & 0x20) == 0) {
      *(undefined4 *)(*param_1 + 0xec) = 1;
    }
    else {
      *(undefined4 *)(*param_1 + 0xec) = 2;
      bVar5 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0x9e])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0x9e]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN((float)param_1[0x9f])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_00175484 == (float)param_1[0x9f]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa0];
        bVar5 = (byte)(DAT_00175488 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar5) {
        param_1[0x9e] = -0x3e800000;
        param_1[0x9f] = -0x3e800000;
        param_1[0xa0] = -0x3e400000;
      }
      bVar5 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0xa1])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0xa1]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN((float)param_1[0xa2])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_00175484 == (float)param_1[0xa2]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa3];
        bVar5 = (byte)(DAT_00175488 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (bVar5) {
        param_1[0xa1] = 0x41800000;
        param_1[0xa2] = 0x41800000;
        param_1[0xa3] = 0x42000000;
      }
    }
    if (*(int *)(*param_1 + 0x1b0) == 0) {
      *(int *)(*param_1 + 0x1b0) = (int)"goalitem" - *(int *)(gpGlobals + 0x98);
    }
    if ((float)param_1[0xc1] <= 0.0) {
      param_1[0xc1] = 0x42700000;
    }
    UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,param_1 + 0x9e,param_1 + 0xa1);
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
    param_1[5] = -0x10000;
    param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
    StartItem__11CTFGoalItem(param_1);
  }
  return;
}


// Spawn__11CTestEffect  @ 000aee70
void Spawn__11CTestEffect(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0xc))(param_1);
  return;
}


// Spawn__11CWallHealth  @ 000bcf40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__11CWallHealth(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 4;
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar1,iVar1 + 0xbc,iVar1 + 200);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  param_1[0x11d] = (int)ROUND(_DAT_00177ac0);
  *(undefined4 *)(*param_1 + 0x110) = 0;
  return;
}


// Spawn__12CAutoTrigger  @ 0010f560
void Spawn__12CAutoTrigger(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0xc))(param_1);
  return;
}


// Spawn__12CChangeLevel  @ 00111090
void Spawn__12CChangeLevel(int *param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(param_1 + 0x11b),"");
  if (iVar1 == 0) {
    (*DAT_001755b4)(1,"a trigger_changelevel doesn\'t have a map");
  }
  iVar1 = strcmp((char *)(param_1 + 0x123),"");
  if (iVar1 == 0) {
    (*DAT_001755b4)(1,"trigger_changelevel to %s doesn\'t have a landmark",param_1 + 0x11b);
  }
  if (*(int *)(*param_1 + 0x1ac) != 0) {
    param_1[7] = -0x10000;
    param_1[8] = (int)UseChangeLevel__12CChangeLevelP11CBaseEntityT18USE_TYPEf;
  }
  InitTrigger__12CBaseTrigger(param_1);
  if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)TouchChangeLevel__12CChangeLevelP11CBaseEntity;
  }
  return;
}


// Spawn__12CCine3Barney  @ 00124c10
void Spawn__12CCine3Barney(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine3-barney.mdl");
  return;
}


// Spawn__12CCineMonster  @ 000e7020
void Spawn__12CCineMonster(int *param_1)

{
  float *pfVar1;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  if ((*(int *)(*param_1 + 0x1ac) == 0) || (param_1[0x184] != 0)) {
    param_1[3] = -0x10000;
    param_1[4] = (int)CineThink__12CCineMonster;
    pfVar1 = gpGlobals;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
    if (*(int *)(*param_1 + 0x1ac) != 0) {
      param_1[0x18c] = (int)(*pfVar1 + 1e+06);
    }
  }
  if ((*(byte *)(*param_1 + 0x180) & 0x20) == 0) {
    param_1[400] = 1;
  }
  else {
    param_1[400] = 0;
  }
  return;
}


// Spawn__12CCinePanther  @ 00124da0
void Spawn__12CCinePanther(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-panther.mdl");
  return;
}


// Spawn__12CCyclerProbe  @ 000bb6e0
void Spawn__12CCyclerProbe(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *param_1;
  *(float *)(iVar1 + 8) = *(float *)(iVar1 + 8) + 0.0;
  *(float *)(iVar1 + 0xc) = *(float *)(iVar1 + 0xc) + 0.0;
  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 16.0;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0xc1800000;
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x41800000;
  GenericCyclerSpawn__7CCyclerPcG6VectorT2(param_1,"models/prdroid.mdl",&local_1c,&local_10);
  return;
}


// Spawn__12CEnvBeverage  @ 000afe60
void Spawn__12CEnvBeverage(int *param_1)

{
  float fVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  *(undefined4 *)(*param_1 + 0x144) = 0;
  fVar1 = *(float *)(*param_1 + 0x140);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x140) = 0x41200000;
  }
  return;
}


// Spawn__12CFuncPlatRot  @ 000d1e50
void Spawn__12CFuncPlatRot(undefined4 param_1)

{
  Spawn__9CFuncPlat(param_1);
  SetupRotation__12CFuncPlatRot(param_1);
  return;
}


// Spawn__12CHandGrenade  @ 000bc520
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__12CHandGrenade(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 0xc;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_grenade.mdl");
  *(undefined4 *)(*param_1 + 0x1c0) = _DAT_00177a9c;
  param_1[0x108] = 5;
  FallInit__15CBasePlayerItem(param_1);
  return;
}


// Spawn__12CItemBattery  @ 00125a40
void Spawn__12CItemBattery(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_battery.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__12CItemPowerup  @ 000f6100
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
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    Spawn__5CItem(param_1);
    local_10 = 0x41800000;
    local_c = 0x41800000;
    local_8 = 0x41800000;
    local_1c = 0xc1800000;
    local_18 = 0xc1800000;
    local_14 = 0;
    UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  }
  return;
}


// Spawn__12CMultiSource  @ 0009d8c0
void Spawn__12CMultiSource(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 1;
  param_1[3] = -0x10000;
  param_1[4] = (int)Register__12CMultiSource;
  return;
}


// Spawn__12CNoBuildArea  @ 000b1570
void Spawn__12CNoBuildArea(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0xec) = 1;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar1,iVar1 + 0xbc,iVar1 + 200);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__12CPointEntity  @ 000f0290
void Spawn__12CPointEntity(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  return;
}


// Spawn__12CTFAutoRifle  @ 000f8130
void Spawn__12CTFAutoRifle(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_autorifle" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 6;
  param_1[0x108] = 5;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__12CTFDispenser  @ 000a8280
void Spawn__12CTFDispenser(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(int *)*param_1 = (int)"building_dispenser" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*param_1 + 0xec) = 2;
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
  iVar1 = *param_1;
  local_10 = 0;
  local_c = 0;
  local_8 = 0x41000000;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41000000;
  *(undefined4 *)(*param_1 + 400) = 0x43160000;
  *(undefined4 *)(*param_1 + 0x140) = *(undefined4 *)(*param_1 + 400);
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) | 0x20;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/dispenser.mdl");
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x41c00000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__12CTFRpgRocket  @ 001013d0
void Spawn__12CTFRpgRocket(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 9;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  param_1[0x184] = 1;
  param_1[0x185] = 1;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/rpgrocket.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  pfVar4 = gpGlobals;
  *(int *)*param_1 = (int)"tf_rpg_rocket" - (int)gpGlobals[0x26];
  param_1[0xdb] = (int)"rocket" - (int)pfVar4[0x26];
  *(float *)(*param_1 + 0x50) = *(float *)(*param_1 + 0x50) - 30.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  *(float *)(*param_1 + 0x50) = -(*(float *)(*param_1 + 0x50) + 30.0);
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  pfVar4 = gpGlobals;
  iVar3 = *param_1;
  fVar1 = gpGlobals[0xb];
  fVar2 = gpGlobals[0xc];
  *(float *)(iVar3 + 0x20) = gpGlobals[10] * 900.0;
  *(float *)(iVar3 + 0x24) = fVar1 * 900.0;
  *(float *)(iVar3 + 0x28) = fVar2 * 900.0;
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f000000;
  *(float *)(*param_1 + 0xe4) = *pfVar4 + 5.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__12CTFSentrygun  @ 000e9420
void Spawn__12CTFSentrygun(int *param_1)

{
  int iVar1;
  float *pfVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  pfVar2 = gpGlobals;
  *(char **)*param_1 = "L?building_sentrygun" + (2 - (int)gpGlobals[0x26]);
  *(undefined4 *)(*param_1 + 0x140) = 0x43160000;
  *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_1 + 0x140);
  *(undefined4 *)(*param_1 + 0xe8) = 5;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(undefined4 *)(*param_1 + 0x14c) = 0x40000000;
  iVar1 = *param_1;
  local_10 = 0;
  local_c = 0;
  local_8 = 0x41b00000;
  *(undefined4 *)(iVar1 + 0x154) = 0;
  *(undefined4 *)(iVar1 + 0x158) = 0;
  *(undefined4 *)(iVar1 + 0x15c) = 0x41b00000;
  param_1[0xdb] = (int)"sentrygun" - (int)pfVar2[0x26];
  param_1[0x24] = 1;
  param_1[0x28] = 0x2d;
  param_1[0x29] = 0x13b;
  param_1[0x186] = 6;
  param_1[0x18e] = g_vecZero;
  param_1[399] = DAT_00175484;
  param_1[400] = DAT_00175488;
  param_1[0x134] = 0x3f333333;
  param_1[0x33] = 0x19;
  param_1[0x30] = 100;
  param_1[0x38] = 0x14;
  *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) | 0x20;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/sentry1.mdl");
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x42400000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x11c,0);
  param_1[3] = -0x10000;
  param_1[4] = (int)SentryRotate__12CTFSentrygun;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.5;
  return;
}


// Spawn__12CTFTimerGoal  @ 001093f0
void Spawn__12CTFTimerGoal(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_14;
  char *pcStack_10;
  int *piStack_c;
  
  piStack_c = param_1;
  pcStack_10 = (char *)0x1093fd;
  iVar1 = CheckExistence__11CBaseEntity();
  puVar2 = (undefined4 *)&stack0xfffffff8;
  if (iVar1 != 0) {
    piStack_c = param_1;
    pcStack_10 = (char *)0x10940a;
    Spawn__7CTFGoal();
    iVar1 = gpGlobals;
    *(char **)*param_1 = "Ainfo_tfgoal_timer" + (1 - *(int *)(gpGlobals + 0x98));
    if (0.0 < (float)param_1[0x93]) {
      *(undefined4 *)(*param_1 + 0xec) = 0;
      return;
    }
    piStack_c = (int *)(*(int *)(*param_1 + 0x1b0) + *(int *)(iVar1 + 0x98));
    pcStack_10 = "Timer Goal %s created with no specified time.\n";
    puVar2 = &uStack_14;
    uStack_14 = 1;
    (*DAT_001755b4)();
  }
  *(int **)((int)puVar2 + -4) = param_1;
  *(undefined4 *)((int)puVar2 + -8) = 0x109454;
  dremove__FP11CBaseEntity();
  return;
}


// Spawn__12CTriggerHurt  @ 001103a0
void Spawn__12CTriggerHurt(int *param_1)

{
  longdouble lVar1;
  
  InitTrigger__12CBaseTrigger(param_1);
  param_1[5] = -0x10000;
  param_1[6] = (int)HurtTouch__12CBaseTriggerP11CBaseEntity;
  if (*(int *)(*param_1 + 0x1ac) == 0) {
    param_1[7] = 0;
    param_1[8] = 0;
  }
  else {
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  }
  if ((*(byte *)((int)param_1 + 0x466) & 4) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)RadiationThink__12CTriggerHurt;
    lVar1 = (longdouble)(*DAT_0017562c)(0,0x3f000000);
    *(float *)(*param_1 + 0xe4) = (float)(lVar1 + (longdouble)*gpGlobals);
  }
  if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0xec) = 0;
  }
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__12CTriggerOnce  @ 00110990
void Spawn__12CTriggerOnce(int param_1)

{
  *(undefined4 *)(param_1 + 0x3f4) = 0xbf800000;
  Spawn__16CTriggerMultiple(param_1);
  return;
}


// Spawn__12CTriggerPush  @ 00111c70
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
     (byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_00175484 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 0x58);
    bVar2 = (byte)(DAT_00175488 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar2) {
    *(undefined4 *)(*param_1 + 0x54) = 0x43b40000;
  }
  InitTrigger__12CBaseTrigger(param_1);
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
  }
  if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0xec) = 0;
  }
  param_1[7] = -0x10000;
  param_1[8] = (int)ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


// Spawn__12CTriggerSave  @ 001120f0
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
    (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  }
  return;
}


// Spawn__12CXenSporeMed  @ 0011efe0
void Spawn__12CXenSporeMed(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0xf0) = 1;
  Spawn__9CXenSpore(param_1);
  local_10 = 0x42200000;
  local_c = 0x42200000;
  local_8 = 0x42f00000;
  local_1c = 0xc2200000;
  local_18 = 0xc2200000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__13CButtonTarget  @ 0009ff70
void Spawn__13CButtonTarget(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  *(undefined4 *)(*param_1 + 0xec) = 4;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x110) = 0x3f800000;
  }
  return;
}


// Spawn__13CCyclerSprite  @ 000bbb50
void Spawn__13CCyclerSprite(int *param_1)

{
  float *pfVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  pfVar1 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[0xf3] = 1;
  param_1[0xf4] = (int)*pfVar1;
  (*g_engfuncs)(*(int *)(*param_1 + 0x98) + (int)pfVar1[0x26]);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),*(int *)(*param_1 + 0x98) + (int)gpGlobals[0x26]
                 );
  iVar2 = (*DAT_001754d0)(*(undefined4 *)(*param_1 + 0x94));
  param_1[0xf5] = (int)((float)iVar2 - 1.0);
  return;
}


// Spawn__13CEnvExplosion  @ 000b1990
void Spawn__13CEnvExplosion(int *param_1)

{
  float fVar1;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  fVar1 = (float)(param_1[0x184] + -0x32) * 0.6;
  if (fVar1 < 10.0) {
    fVar1 = 10.0;
  }
  param_1[0x185] = (int)ROUND(fVar1);
  return;
}


// Spawn__13CFuncConveyor  @ 0009b840
void Spawn__13CFuncConveyor(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  
  SetMovedir__FP9entvars_t(*param_1);
  Spawn__9CFuncWall(param_1);
  if (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) != 0) {
    pbVar1 = (byte *)(*param_1 + 0x184);
    *pbVar1 = *pbVar1 | 4;
  }
  if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0xec) = 0;
    *(undefined4 *)(*param_1 + 0xf0) = 0;
  }
  fVar2 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
  }
  UpdateSpeed__13CFuncConveyorf(param_1,*(undefined4 *)(*param_1 + 0x1d8));
  return;
}


// Spawn__13CFuncRotating  @ 0009bd00
void Spawn__13CFuncRotating(int *param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_8;
  
  param_1[0xf6] = 0x42c60000;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf5]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf5] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf5] = 0x3f800000;
  }
  param_1[0xf4] = 0x3f4ccccd;
  if (*(char *)(*param_1 + 0x180) < '\0') {
    param_1[0xf4] = 0x40000000;
  }
  else if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
    if ((*(byte *)(*param_1 + 0x181) & 2) != 0) {
      param_1[0xf4] = 0x3f4ccccd;
    }
  }
  else {
    param_1[0xf4] = 0x3fa00000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf3] = 0x3f800000;
  }
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x180) & 4) == 0) {
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x180) & 8) == 0) {
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x44) = 0;
      *(undefined4 *)(iVar1 + 0x48) = 0x3f800000;
      *(undefined4 *)(iVar1 + 0x4c) = 0;
      goto LAB_0009be49;
    }
    local_10 = 0x3f800000;
    local_8 = 0;
  }
  else {
    local_10 = 0;
    local_8 = 0x3f800000;
  }
  *(undefined4 *)(iVar1 + 0x44) = local_10;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined4 *)(iVar1 + 0x4c) = local_8;
LAB_0009be49:
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x180) & 2) != 0) {
    *(float *)(iVar1 + 0x44) = *(float *)(iVar1 + 0x44) * -1.0;
    *(float *)(iVar1 + 0x48) = *(float *)(iVar1 + 0x48) * -1.0;
    *(float *)(iVar1 + 0x4c) = *(float *)(iVar1 + 0x4c) * -1.0;
  }
  if ((*(byte *)(*param_1 + 0x180) & 0x40) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
    *(undefined4 *)(*param_1 + 0xf0) = 0xffffffff;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  param_1[7] = -0x10000;
  param_1[8] = (int)RotatingUse__13CFuncRotatingP11CBaseEntityT18USE_TYPEf;
  if (*(float *)(*param_1 + 0x1d8) <= 0.0) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0;
  }
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x180) & 1) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_CallUseToggle__11CBaseEntity;
    *(float *)(iVar1 + 0xe4) = *(float *)(iVar1 + 0xe0) + 1.5;
  }
  if ((*(byte *)(*param_1 + 0x180) & 0x20) != 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)HurtTouch__13CFuncRotatingP11CBaseEntity;
  }
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  return;
}


// Spawn__13CItemAntidote  @ 00125850
void Spawn__13CItemAntidote(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_antidote.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CItemArmorRed  @ 000f5ae0
void Spawn__13CItemArmorRed(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/r_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0xf4] = 0x43480000;
    param_1[0xf5] = 0x3f4ccccd;
  }
  return;
}


// Spawn__13CItemLongJump  @ 001256e0
void Spawn__13CItemLongJump(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_longjump.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CItemSecurity  @ 00125790
void Spawn__13CItemSecurity(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_security.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__13CMultiManager  @ 0010f8e0
void Spawn__13CMultiManager(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  param_1[7] = -0x10000;
  param_1[8] = (int)ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf;
  param_1[3] = -0x10000;
  param_1[4] = (int)ManagerThink__13CMultiManager;
  do {
    bVar4 = false;
    iVar5 = 1;
    if (1 < param_1[0x11b]) {
      do {
        fVar1 = (float)param_1[iVar5 + 0x12e];
        fVar2 = (float)param_1[iVar5 + 0x12d];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
          iVar3 = param_1[iVar5 + 0x11e];
          param_1[iVar5 + 0x11e] = param_1[iVar5 + 0x11d];
          param_1[iVar5 + 0x12e] = param_1[iVar5 + 0x12d];
          param_1[iVar5 + 0x11d] = iVar3;
          param_1[iVar5 + 0x12d] = (int)fVar1;
          bVar4 = true;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[0x11b]);
    }
  } while (bVar4);
  return;
}


// Spawn__13CTriggerRelay  @ 0010f730
void Spawn__13CTriggerRelay(void)

{
  return;
}


// Spawn__13CWeaponCycler  @ 000bbda0
void Spawn__13CWeaponCycler(int *param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  (*g_engfuncs)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  param_1[0x109] = *(int *)(iVar1 + 0x98);
  param_1[0x10a] = *(int *)(iVar1 + 0x94);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(iVar1,iVar1 + 8);
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x41800000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CBaseSpectator  @ 000ee750
void Spawn__14CBaseSpectator(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x184) = 0x4000000;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 8;
  param_1[1] = 0;
  return;
}


// Spawn__14CCineScientist  @ 00124e40
void Spawn__14CCineScientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine-scientist.mdl");
  return;
}


// Spawn__14CGenericCycler  @ 00125110
void Spawn__14CGenericCycler(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0xc1800000;
  local_c = 0xc1800000;
  local_8 = 0;
  local_1c = 0x41800000;
  local_18 = 0x41800000;
  local_14 = 0x42900000;
  GenericCyclerSpawn__7CCyclerPcG6VectorT2
            (param_1,*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98),&local_10,&local_1c);
  return;
}


// Spawn__14CItemAmmoCells  @ 000f6060
void Spawn__14CItemAmmoCells(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  iVar1 = gpGlobals;
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0xf4] = (int)("?models/w_battery.mdl" + (1 - *(int *)(gpGlobals + 0x98)));
    param_1[0xf5] = (int)("?models/w_battery.mdl" + (1 - *(int *)(iVar1 + 0x98)));
    *(int *)(*param_1 + 0x1b0) = (int)"cells" - *(int *)(iVar1 + 0x98);
    param_1[0x37] = 5;
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__14CItemAmmoNails  @ 000f5e40
void Spawn__14CItemAmmoNails(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  iVar1 = gpGlobals;
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0xf4] = (int)"models/w_crossbow_clip.mdl" - *(int *)(gpGlobals + 0x98);
    param_1[0xf5] = (int)"models/w_crossbow_clip.mdl" - *(int *)(iVar1 + 0x98);
    *(int *)(*param_1 + 0x1b0) = (int)"nails" - *(int *)(iVar1 + 0x98);
    param_1[0x35] = 0x19;
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__14CMomentaryDoor  @ 000aab80
void Spawn__14CMomentaryDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  
  SetMovedir__FP9entvars_t(*param_1);
  *(undefined4 *)(*param_1 + 0xec) = 4;
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
  }
  fVar1 = *(float *)(*param_1 + 0x1c0);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1c0) = 0x40000000;
  }
  iVar3 = *param_1;
  param_1[0x101] = *(int *)(iVar3 + 8);
  param_1[0x102] = *(int *)(iVar3 + 0xc);
  param_1[0x103] = *(int *)(iVar3 + 0x10);
  fVar4 = (ABS((*(float *)(iVar3 + 0xd8) - 2.0) * *(float *)(iVar3 + 0x48)) +
           ABS((*(float *)(iVar3 + 0xd4) - 2.0) * *(float *)(iVar3 + 0x44)) +
          ABS((*(float *)(iVar3 + 0xdc) - 2.0) * *(float *)(iVar3 + 0x4c))) - (float)param_1[0xfe];
  fVar1 = *(float *)(iVar3 + 0x48);
  fVar2 = *(float *)(iVar3 + 0x4c);
  param_1[0x104] = (int)((float)param_1[0x101] + fVar4 * *(float *)(iVar3 + 0x44));
  param_1[0x105] = (int)((float)param_1[0x102] + fVar4 * fVar1);
  param_1[0x106] = (int)((float)param_1[0x103] + fVar4 * fVar2);
  if ((*(byte *)(iVar3 + 0x180) & 1) != 0) {
    UTIL_SetOrigin__FP9entvars_tRC6Vector(iVar3,param_1 + 0x104);
    param_1[0x104] = param_1[0x101];
    param_1[0x105] = param_1[0x102];
    param_1[0x106] = param_1[0x103];
    iVar3 = *param_1;
    param_1[0x101] = *(int *)(iVar3 + 8);
    param_1[0x102] = *(int *)(iVar3 + 0xc);
    param_1[0x103] = *(int *)(iVar3 + 0x10);
  }
  param_1[5] = 0;
  param_1[6] = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  return;
}


// Spawn__14CTFIncendiaryC  @ 000ff620
void Spawn__14CTFIncendiaryC(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 8;
  param_1[0x2c] = 0;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_rpg.mdl");
  param_1[0x108] = 0x32;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CTFNailgunNail  @ 00100120
void Spawn__14CTFNailgunNail(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 9;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/rpgrocket.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  pfVar4 = gpGlobals;
  *(int *)*param_1 = (int)"tf_nailgun_nail" - (int)gpGlobals[0x26];
  param_1[0xdb] = (int)"nails" - (int)pfVar4[0x26];
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  pfVar4 = gpGlobals;
  iVar3 = *param_1;
  fVar1 = gpGlobals[0xb];
  fVar2 = gpGlobals[0xc];
  *(float *)(iVar3 + 0x20) = gpGlobals[10] * 1000.0;
  *(float *)(iVar3 + 0x24) = fVar1 * 1000.0;
  *(float *)(iVar3 + 0x28) = fVar2 * 1000.0;
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f000000;
  *(float *)(*param_1 + 0xe4) = *pfVar4 + 6.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__14CTFSniperRifle  @ 001031c0
void Spawn__14CTFSniperRifle(int *param_1)

{
  param_1[0x109] = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 6;
  param_1[0x108] = 5;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__14CTargetCDAudio  @ 00110250
void Spawn__14CTargetCDAudio(int *param_1)

{
  float fVar1;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  fVar1 = *(float *)(*param_1 + 0x124);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  }
  return;
}


// Spawn__14CTelefragDeath  @ 00113080
void Spawn__14CTelefragDeath(int *param_1)

{
  int iVar1;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x58) = DAT_00175488;
  uStack_1c = 0x41800000;
  uStack_18 = 0x41800000;
  uStack_14 = 0x42100000;
  uStack_28 = 0x40800000;
  uStack_24 = 0x40800000;
  uStack_20 = 0x40800000;
  uStack_10 = 0x41a00000;
  uStack_c = 0x41a00000;
  uStack_8 = 0x42200000;
  uStack_34 = 0xc1a00000;
  uStack_30 = 0xc1a00000;
  uStack_2c = 0xc2200000;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&uStack_34,&uStack_10);
  param_1[5] = -0x10000;
  param_1[6] = (int)DeathTouch__14CTelefragDeathP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.2;
  return;
}


// Spawn__14CTriggerCamera  @ 00112580
void Spawn__14CTriggerCamera(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xe8) = 8;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 300) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 2;
  param_1[0x100] = *(int *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x101]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x101] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x101] = 0x43fa0000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x102]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x102] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x102] = 0x43fa0000;
  }
  return;
}


// Spawn__14CTriggerVolume  @ 00110dd0
void Spawn__14CTriggerVolume(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x98) = 0;
  *(undefined4 *)(*param_1 + 0x94) = 0;
  return;
}


// Spawn__14CXenSporeLarge  @ 0011f040
void Spawn__14CXenSporeLarge(int *param_1)

{
  uint uVar1;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
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
  
  *(undefined4 *)(*param_1 + 0xf0) = 2;
  Spawn__9CXenSpore(param_1);
  local_10 = 48.0;
  local_c = 48.0;
  local_8 = 240.0;
  local_1c = -48.0;
  local_18 = -48.0;
  local_14 = 110.0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  (*DAT_00175510)(*param_1 + 0x50,&local_1c,&local_10,0);
  uVar1 = 0;
  do {
    local_2c = (float)(&_14CXenSporeLarge_m_hullSizes)[uVar1 * 3];
    local_34 = local_2c * local_1c;
    local_30 = local_2c * local_18;
    local_2c = local_2c * local_14;
    local_38 = (float)(&DAT_00183264)[uVar1 * 3];
    local_40 = local_38 * local_10;
    local_3c = local_38 * local_c;
    local_38 = local_38 * local_8;
    local_28 = local_34 + local_40;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_4c = 0x41400000;
    local_48 = 0x41400000;
    local_44 = 0x42f00000;
    local_58 = 0xc1400000;
    local_54 = 0xc1400000;
    local_50 = 0;
    CreateHull__8CXenHullP11CBaseEntityRC6VectorN22(param_1,&local_58,&local_4c,&local_28);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 5);
  return;
}


// Spawn__14CXenSporeSmall  @ 0011ef80
void Spawn__14CXenSporeSmall(int *param_1)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(undefined4 *)(*param_1 + 0xf0) = 0;
  Spawn__9CXenSpore(param_1);
  local_10 = 0x41800000;
  uStack_c = 0x41800000;
  uStack_8 = 0x42800000;
  uStack_1c = 0xc1800000;
  uStack_18 = 0xc1800000;
  uStack_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&uStack_1c,&local_10);
  return;
}


// Spawn__15CAmbientGeneric  @ 000eb070
void Spawn__15CAmbientGeneric(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
      if (((*(byte *)(*param_1 + 0x180) & 4) == 0) && ((*(byte *)(*param_1 + 0x180) & 8) != 0)) {
        param_1[0xf3] = 0x3f4ccccd;
      }
      else {
        param_1[0xf3] = 0x3fa00000;
      }
    }
    else {
      param_1[0xf3] = 0x40000000;
    }
  }
  else {
    param_1[0xf3] = 0;
  }
  if (*(int *)(*param_1 + 0x1b4) != 0) {
    iVar2 = -1;
    pcVar3 = (char *)((int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1b4));
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      *(undefined4 *)(*param_1 + 0xec) = 0;
      *(undefined4 *)(*param_1 + 0xe8) = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)RampThink__15CAmbientGeneric;
      *(undefined4 *)(*param_1 + 0xe4) = 0;
      param_1[7] = -0x10000;
      param_1[8] = (int)ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf;
      param_1[0x10d] = 0;
      if ((*(byte *)(*param_1 + 0x180) & 0x20) == 0) {
        param_1[0x10e] = 1;
      }
      else {
        param_1[0x10e] = 0;
      }
      (**(code **)(param_1[0xf2] + 0xc))();
      return;
    }
  }
  iVar2 = *param_1;
  (*DAT_001755b4)(4,"EMPTY AMBIENT AT: %f, %f, %f\n",(double)*(float *)(iVar2 + 8),
                  (double)*(float *)(iVar2 + 0xc),(double)*(float *)(iVar2 + 0x10));
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__15CBasePlayerAmmo  @ 0011bcd0
void Spawn__15CBasePlayerAmmo(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x41800000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerAmmoP11CBaseEntity;
  return;
}


// Spawn__15CCine2Scientist  @ 00124df0
void Spawn__15CCine2Scientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine2-scientist.mdl");
  return;
}


// Spawn__15CCine3Scientist  @ 00124c60
void Spawn__15CCine3Scientist(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,"models/cine3-scientist.mdl");
  return;
}


// Spawn__15CFuncTrackTrain  @ 000d4190
void Spawn__15CFuncTrackTrain(int *param_1)

{
  int iVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x1d8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1d8) == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf6] = 0x42c80000;
  }
  else {
    param_1[0xf6] = *(int *)(*param_1 + 0x1d8);
  }
  *(undefined4 *)(*param_1 + 0x1d8) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  *(int *)(*param_1 + 0x164) = (int)ROUND((float)param_1[0xf6]);
  param_1[0xf7] = 0x3f800000;
  if (*(int *)(*param_1 + 0x1a8) == 0) {
    (*DAT_001755b4)(1,"FuncTrain with no target");
  }
  if ((*(byte *)(*param_1 + 0x180) & 8) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar1,iVar1 + 0xbc,iVar1 + 200);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = *param_1;
  param_1[0xf9] = *(int *)(iVar1 + 0xbc);
  param_1[0xfa] = *(int *)(iVar1 + 0xc0);
  param_1[0xfb] = *(int *)(iVar1 + 0xc4);
  param_1[0xfc] = *(int *)(iVar1 + 200);
  param_1[0xfd] = *(int *)(iVar1 + 0xcc);
  param_1[0xfe] = *(int *)(iVar1 + 0xd0);
  param_1[0xfe] = (int)((float)param_1[0xfe] + 72.0);
  NextThink__15CFuncTrackTrainfi(param_1,*(float *)(iVar1 + 0xe0) + 0.1,0);
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__15CFuncTrackTrain;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  return;
}


// Spawn__15CFuncWallToggle  @ 0009b730
void Spawn__15CFuncWallToggle(int *param_1)

{
  Spawn__9CFuncWall(param_1);
  if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
    TurnOff__15CFuncWallToggle(param_1);
  }
  return;
}


// Spawn__15CGenericMonster  @ 000b8a80
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
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar1 = strcmp((char *)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98)),
                 "models/player.mdl");
  if (iVar1 != 0) {
    iVar1 = strcmp((char *)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98)),
                   "models/holo.mdl");
    if (iVar1 != 0) {
      local_1c = 0x41800000;
      local_18 = 0x41800000;
      local_14 = 0x42900000;
      puVar3 = &local_1c;
      local_10 = 0xc1800000;
      local_c = 0xc1800000;
      local_8 = 0;
      puVar2 = &local_10;
      goto LAB_000b8b70;
    }
  }
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x42100000;
  puVar3 = &local_10;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0xc2100000;
  puVar2 = &local_1c;
LAB_000b8b70:
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,puVar2,puVar3);
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(undefined4 *)(*param_1 + 0xe8) = 4;
  param_1[0x178] = 0xf7;
  *(undefined4 *)(*param_1 + 0x140) = 0x41000000;
  param_1[0x134] = 0x3f000000;
  param_1[0x13a] = 0;
  (**(code **)(param_1[0xf2] + 0x11c))(param_1);
  if ((*(byte *)(*param_1 + 0x180) & 4) != 0) {
    *(undefined4 *)(*param_1 + 0xec) = 0;
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  return;
}


// Spawn__15CItemAmmoShells  @ 000f5d90
void Spawn__15CItemAmmoShells(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  iVar1 = gpGlobals;
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0xf4] = (int)("L?models/w_shotbox.mdl" + (2 - *(int *)(gpGlobals + 0x98)));
    param_1[0xf5] = (int)("L?models/w_shotbox.mdl" + (2 - *(int *)(iVar1 + 0x98)));
    *(int *)(*param_1 + 0x1b0) = (int)"shells" - *(int *)(iVar1 + 0x98);
    param_1[0x33] = 0x14;
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__15CItemArmorGreen  @ 000f59a0
void Spawn__15CItemArmorGreen(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/g_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0xf4] = 0x42c80000;
    param_1[0xf5] = 0x3e99999a;
  }
  return;
}


// Spawn__15CTFFlamethrower  @ 000fa7a0
void Spawn__15CTFFlamethrower(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 10;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_egon.mdl");
  param_1[0x108] = 0x32;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__15CTFPrimeGrenade  @ 000fc430
void Spawn__15CTFPrimeGrenade(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xe8) = 10;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  (**(code **)(param_1[0xf2] + 0x220))(param_1);
  (**(code **)(param_1[0xf2] + 0x230))(param_1);
  (**(code **)(param_1[0xf2] + 0x234))(param_1);
  (**(code **)(param_1[0xf2] + 0x238))(param_1);
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  param_1[0x184] = 0;
  param_1[0x185] = 1;
  param_1[0x187] = 0;
  param_1[0x186] = 0;
  param_1[0x188] = 0;
  return;
}


// Spawn__15CTFSuperShotgun  @ 001029d0
void Spawn__15CTFSuperShotgun(int param_1)

{
  Spawn__10CTFShotgun(param_1);
  *(undefined4 *)(param_1 + 0x420) = 0x10;
  *(undefined4 *)(param_1 + 0x438) = 0x10;
  *(undefined4 *)(param_1 + 0x43c) = 0x3ec00000;
  *(undefined4 *)(param_1 + 0x434) = 2;
  return;
}


// Spawn__15CTriggerCDAudio  @ 001100f0
void Spawn__15CTriggerCDAudio(undefined4 param_1)

{
  InitTrigger__12CBaseTrigger(param_1);
  return;
}


// Spawn__15CTriggerCounter  @ 00110d80
void Spawn__15CTriggerCounter(int param_1)

{
  *(undefined4 *)(param_1 + 0x3f4) = 0xbf800000;
  if (*(int *)(param_1 + 0x434) == 0) {
    *(undefined4 *)(param_1 + 0x434) = 2;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0xffff0000;
  *(code **)(param_1 + 0x20) = CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  return;
}


// Spawn__15CTriggerGravity  @ 00112340
void Spawn__15CTriggerGravity(int param_1)

{
  InitTrigger__12CBaseTrigger(param_1);
  *(undefined4 *)(param_1 + 0x14) = 0xffff0000;
  *(code **)(param_1 + 0x18) = GravityTouch__15CTriggerGravityP11CBaseEntity;
  return;
}


// Spawn__16CFuncIllusionary  @ 0009ba10
void Spawn__16CFuncIllusionary(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x58) = DAT_00175488;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  return;
}


// Spawn__16CFuncMonsterClip  @ 0009ba90
void Spawn__16CFuncMonsterClip(int *param_1)

{
  longdouble lVar1;
  
  Spawn__9CFuncWall(param_1);
  lVar1 = (longdouble)(*DAT_001755a4)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar1) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  }
  *(byte *)(*param_1 + 0x186) = *(byte *)(*param_1 + 0x186) | 0x80;
  return;
}


// Spawn__16CFuncMortarField  @ 000c8f00
void Spawn__16CFuncMortarField(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  param_1[7] = -0x10000;
  param_1[8] = (int)FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  return;
}


// Spawn__16CFuncTrackChange  @ 000d4710
void Spawn__16CFuncTrackChange(int *param_1)

{
  int iVar1;
  
  Setup__9CFuncPlat(param_1);
  if ((*(byte *)(*param_1 + 0x180) & 0x10) != 0) {
    param_1[0x106] = *(int *)(*param_1 + 0x10);
  }
  SetupRotation__12CFuncPlatRot(param_1);
  if ((*(byte *)(*param_1 + 0x180) & 8) == 0) {
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,param_1 + 0x101);
    param_1[0xfa] = 0;
    iVar1 = *param_1;
    *(int *)(iVar1 + 0x50) = param_1[0x11d];
    *(int *)(iVar1 + 0x54) = param_1[0x11e];
    *(int *)(iVar1 + 0x58) = param_1[0x11f];
    param_1[0x12a] = 1;
  }
  else {
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,param_1 + 0x104);
    param_1[0xfa] = 1;
    iVar1 = *param_1;
    *(int *)(iVar1 + 0x50) = param_1[0x120];
    *(int *)(iVar1 + 0x54) = param_1[0x121];
    *(int *)(iVar1 + 0x58) = param_1[0x122];
    param_1[0x12a] = 0;
  }
  param_1[299] = 1;
  *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 2.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__16CFuncTrackChange;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  return;
}


// Spawn__16CItemAmmoRockets  @ 000f5ef0
void Spawn__16CItemAmmoRockets(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = CheckExistence__11CBaseEntity(param_1);
  iVar1 = gpGlobals;
  if (iVar2 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    param_1[0xf4] = (int)"models/w_rpgammo.mdl" - *(int *)(gpGlobals + 0x98);
    param_1[0xf5] = (int)"models/w_rpgammo.mdl" - *(int *)(iVar1 + 0x98);
    *(int *)(*param_1 + 0x1b0) = (int)"rockets" - *(int *)(iVar1 + 0x98);
    param_1[0x39] = 5;
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    Spawn__9CItemAmmo(param_1);
  }
  return;
}


// Spawn__16CItemArmorYellow  @ 000f5a40
void Spawn__16CItemArmorYellow(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/y_armor.mdl");
    Spawn__5CItem(param_1);
    param_1[0xf4] = 0x43160000;
    param_1[0xf5] = 0x3f19999a;
  }
  return;
}


// Spawn__16CItemPowerupQuad  @ 000f6620
void Spawn__16CItemPowerupQuad(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  Spawn__12CItemPowerup(param_1);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf3] = 0x42700000;
  }
  param_1[0xea] = 0x41f00000;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/quad.mdl");
  iVar1 = gpGlobals;
  *(int *)(*param_1 + 0x1b0) = (int)"Quad Damage" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1c8) = (int)"items/damage.wav" - *(int *)(iVar1 + 0x98);
  param_1[0x23] = 0x400000;
  return;
}


// Spawn__16CRenderFxManager  @ 0010fc50
void Spawn__16CRenderFxManager(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  return;
}


// Spawn__16CTFSentrygunBase  @ 000e8ee0
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
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
  iVar1 = *param_1;
  local_10 = 0;
  local_c = 0;
  local_8 = 0x41000000;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41000000;
  *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) | 0x20;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/base.mdl");
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x42400000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__16CTriggerMultiple  @ 00110920
void Spawn__16CTriggerMultiple(int param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x3f4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x3f4) == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(param_1 + 0x3f4) = 0x3e4ccccd;
    }
    InitTrigger__12CBaseTrigger(param_1);
    *(undefined4 *)(param_1 + 0x14) = 0xffff0000;
    *(code **)(param_1 + 0x18) = MultiTouch__12CBaseTriggerP11CBaseEntity;
  }
  return;
}


// Spawn__16CTriggerTeleport  @ 001120a0
void Spawn__16CTriggerTeleport(int param_1)

{
  InitTrigger__12CBaseTrigger(param_1);
  *(undefined4 *)(param_1 + 0x14) = 0xffff0000;
  *(code **)(param_1 + 0x18) = TeleportTouch__12CBaseTriggerP11CBaseEntity;
  return;
}


// Spawn__17CFrictionModifier  @ 0010f330
void Spawn__17CFrictionModifier(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 1;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)ChangeFriction__17CFrictionModifierP11CBaseEntity;
  return;
}


// Spawn__17CFuncTankControls  @ 000b6370
void Spawn__17CFuncTankControls(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0xec) = 1;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),*(int *)(*param_1 + 0x98) + (int)gpGlobals[0x26]
                 );
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar1,iVar1 + 0xbc,iVar1 + 200);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.3;
  return;
}


// Spawn__17CInfoIntermission  @ 000e01f0
void Spawn__17CInfoIntermission(int *param_1)

{
  int iVar1;
  
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0x80;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x74) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x78) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x7c) = DAT_00175488;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 2.0;
  return;
}


// Spawn__17CScriptedSentence  @ 000e8790
void Spawn__17CScriptedSentence(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  param_1[0x122] = 1;
  if (*(int *)(*param_1 + 0x1ac) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)FindThink__17CScriptedSentence;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  }
  iVar1 = *(int *)(*param_1 + 0x164);
  if (iVar1 == 1) {
    param_1[0x120] = 0x3fa00000;
    goto LAB_000e883a;
  }
  if (1 < iVar1) {
    if (iVar1 == 2) {
      param_1[0x120] = 0x3f4ccccd;
      goto LAB_000e883a;
    }
    if (iVar1 == 3) {
      param_1[0x120] = 0;
      goto LAB_000e883a;
    }
  }
  param_1[0x120] = 0x40000000;
LAB_000e883a:
  *(undefined4 *)(*param_1 + 0x164) = 0;
  if ((float)param_1[0x121] <= 0.0) {
    param_1[0x121] = 0x3f800000;
  }
  return;
}


// Spawn__18CCine2HeavyWeapons  @ 00124d00
void Spawn__18CCine2HeavyWeapons(undefined4 param_1)

{
  CineSpawn__18CLegacyCineMonsterPc(param_1,FUN_00132c00);
  return;
}


// Spawn__18CFuncTrainControls  @ 000d45f0
void Spawn__18CFuncTrainControls(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),*(int *)(*param_1 + 0x98) + gpGlobals[0x26]);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar1,iVar1 + 0xbc,iVar1 + 200);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  param_1[3] = -0x10000;
  param_1[4] = (int)Find__18CFuncTrainControls;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


// Spawn__18CTFGrenadeLauncher  @ 000fb760
void Spawn__18CTFGrenadeLauncher(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 4;
  param_1[0x10c] = 8;
  param_1[0x10d] = 10;
  param_1[0x10e] = 0;
  param_1[0x10f] = 4;
  param_1[0x110] = 5;
  param_1[0x108] = 0x32;
  param_1[0x10b] = 0x3f2aaaab;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__18CTriggerEndSection  @ 00112200
void Spawn__18CTriggerEndSection(int *param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(gpGlobals + 0x14);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    InitTrigger__12CBaseTrigger(param_1);
    param_1[7] = -0x10000;
    param_1[8] = (int)EndSectionUse__18CTriggerEndSectionP11CBaseEntityT18USE_TYPEf;
    if (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) != 0) {
      param_1[5] = -0x10000;
      param_1[6] = (int)EndSectionTouch__18CTriggerEndSectionP11CBaseEntity;
    }
  }
  else {
    (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  }
  return;
}


// Spawn__19CItemPowerupRadsuit  @ 000f6450
void Spawn__19CItemPowerupRadsuit(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  Spawn__12CItemPowerup(param_1);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf3] = 0x42700000;
  }
  param_1[0xeb] = 0x41f00000;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_suit.mdl");
  iVar1 = gpGlobals;
  *(int *)(*param_1 + 0x1b0) = (int)"Biosuit" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1c8) = (int)"FVox/HEV_logon.wav" - *(int *)(iVar1 + 0x98);
  param_1[0x23] = 0x200000;
  return;
}


// Spawn__19CMomentaryRotButton  @ 0009f2f0
void Spawn__19CMomentaryRotButton(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  
  AxisDir__11CBaseToggleP9entvars_t(*param_1);
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
  }
  fVar1 = (float)param_1[0xfc];
  if (0.0 <= fVar1) {
    iVar6 = *param_1;
    param_1[0x11e] = *(int *)(iVar6 + 0x50);
    param_1[0x11f] = *(int *)(iVar6 + 0x54);
    param_1[0x120] = *(int *)(iVar6 + 0x58);
    fVar1 = (float)param_1[0xfc];
    fVar2 = *(float *)(iVar6 + 0x48);
    fVar3 = *(float *)(iVar6 + 0x4c);
    fVar4 = *(float *)(iVar6 + 0x54);
    fVar5 = *(float *)(iVar6 + 0x58);
    param_1[0x121] = (int)(*(float *)(iVar6 + 0x50) + fVar1 * *(float *)(iVar6 + 0x44));
    param_1[0x122] = (int)(fVar4 + fVar1 * fVar2);
    param_1[0x123] = (int)(fVar5 + fVar1 * fVar3);
    param_1[0x11c] = -1;
  }
  else {
    iVar6 = *param_1;
    fVar2 = *(float *)(iVar6 + 0x48);
    fVar3 = *(float *)(iVar6 + 0x4c);
    fVar4 = *(float *)(iVar6 + 0x54);
    fVar5 = *(float *)(iVar6 + 0x58);
    param_1[0x11e] = (int)(*(float *)(iVar6 + 0x50) + fVar1 * *(float *)(iVar6 + 0x44));
    param_1[0x11f] = (int)(fVar4 + fVar1 * fVar2);
    param_1[0x120] = (int)(fVar5 + fVar1 * fVar3);
    param_1[0x121] = *(int *)(iVar6 + 0x50);
    param_1[0x122] = *(int *)(iVar6 + 0x54);
    param_1[0x123] = *(int *)(iVar6 + 0x58);
    param_1[0x11c] = 1;
    param_1[0xfc] = (int)-fVar1;
  }
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 4;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  uVar7 = ButtonSound__Fi(param_1[0x124]);
  (*DAT_001754c4)(uVar7);
  uVar7 = (*DAT_001755cc)(uVar7);
  *(undefined4 *)(*param_1 + 0x1c8) = uVar7;
  param_1[0x11b] = 0;
  return;
}


// Spawn__19CTFPipebombLauncher  @ 000fbf70
void Spawn__19CTFPipebombLauncher(int param_1)

{
  Spawn__18CTFGrenadeLauncher(param_1);
  *(undefined4 *)(param_1 + 0x430) = 9;
  *(undefined4 *)(param_1 + 0x434) = 0xb;
  *(undefined4 *)(param_1 + 0x438) = 1;
  *(undefined4 *)(param_1 + 0x43c) = 6;
  *(undefined4 *)(param_1 + 0x440) = 7;
  return;
}


// Spawn__19CTriggerMonsterJump  @ 0010ff70
void Spawn__19CTriggerMonsterJump(int *param_1)

{
  SetMovedir__FP9entvars_t(*param_1);
  InitTrigger__12CBaseTrigger(param_1);
  *(undefined4 *)(*param_1 + 0xe4) = 0;
  *(undefined4 *)(*param_1 + 0x1d8) = 0x43480000;
  param_1[0x10e] = 0x43160000;
  if (*(int *)(*param_1 + 0x1ac) != 0) {
    *(undefined4 *)(*param_1 + 0xec) = 0;
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf;
  }
  return;
}


// Spawn__20CTFFlamethrowerBurst  @ 000fa530
void Spawn__20CTFFlamethrowerBurst(int *param_1)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 9;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/rpgrocket.mdl");
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0.0;
  local_18 = 0.0;
  local_14 = 0.0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  pfVar2 = gpGlobals;
  *(int *)*param_1 = (int)"tf_flamethrower_burst" - (int)gpGlobals[0x26];
  param_1[0xdb] = (int)"flames" - (int)pfVar2[0x26];
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
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f000000;
  uVar3 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x178));
  UTIL_ClientProjectile__FRC6VectorT0sii
            (*param_1 + 8,*param_1 + 0x20,(int)sModelIndexFlameThrowerFlame,uVar3,1);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__20CTFIncendiaryCRocket  @ 000ff310
void Spawn__20CTFIncendiaryCRocket(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 9;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/rpgrocket.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  pfVar4 = gpGlobals;
  *(int *)*param_1 = (int)"tf_rpg_rocket" - (int)gpGlobals[0x26];
  param_1[0xdb] = (int)"rocket" - (int)pfVar4[0x26];
  *(float *)(*param_1 + 0x50) = *(float *)(*param_1 + 0x50) - 30.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  *(float *)(*param_1 + 0x50) = -(*(float *)(*param_1 + 0x50) + 30.0);
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  pfVar4 = gpGlobals;
  iVar3 = *param_1;
  fVar1 = gpGlobals[0xb];
  fVar2 = gpGlobals[0xc];
  *(float *)(iVar3 + 0x20) = gpGlobals[10] * 600.0;
  *(float *)(iVar3 + 0x24) = fVar1 * 600.0;
  *(float *)(iVar3 + 0x28) = fVar2 * 600.0;
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f000000;
  *(float *)(*param_1 + 0xe4) = *pfVar4 + 5.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


// Spawn__20CTriggerChangeTarget  @ 00112480
void Spawn__20CTriggerChangeTarget(void)

{
  return;
}


// Spawn__22CItemPowerupInvincible  @ 000f6360
void Spawn__22CItemPowerupInvincible(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  Spawn__12CItemPowerup(param_1);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf3] = 0x43960000;
  }
  param_1[0xe8] = 0x41f00000;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/pent.mdl");
  iVar1 = gpGlobals;
  *(int *)(*param_1 + 0x1b0) = (int)"Pentagram of Protection" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1c8) = (int)"items/protect.wav" - *(int *)(iVar1 + 0x98);
  param_1[0x23] = 0x100000;
  return;
}


// Spawn__24CItemPowerupInvisibility  @ 000f6530
void Spawn__24CItemPowerupInvisibility(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  Spawn__12CItemPowerup(param_1);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xf3] = 0x43960000;
  }
  param_1[0xe9] = 0x41f00000;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/invis.mdl");
  iVar1 = gpGlobals;
  *(int *)(*param_1 + 0x1b0) = (int)"Ring of Shadows" - *(int *)(gpGlobals + 0x98);
  *(int *)(*param_1 + 0x1c8) = (int)"items/inv1.wav" - *(int *)(iVar1 + 0x98);
  param_1[0x23] = 0x80000;
  return;
}


// Spawn__4CGibPCc  @ 000a5480
void Spawn__4CGibPCc(int *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0xe8) = 10;
  *(undefined4 *)(*param_1 + 0x100) = 0x3f0ccccd;
  *(undefined4 *)(*param_1 + 300) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x13c) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(int *)*param_1 = (int)&DAT_0012d2f0 - (int)gpGlobals[0x26];
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),param_2);
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 4.0;
  param_1[0xf6] = 0x41c80000;
  param_1[3] = -0x10000;
  param_1[4] = (int)WaitTillLand__4CGib;
  param_1[5] = -0x10000;
  param_1[6] = (int)BounceGibTouch__4CGibP11CBaseEntity;
  param_1[0xf5] = 9;
  param_1[0xf4] = 5;
  return;
}


// Spawn__5CBeam  @ 000ab630
void Spawn__5CBeam(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  return;
}


// Spawn__5CFade  @ 000af800
void Spawn__5CFade(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  return;
}


// Spawn__5CGlow  @ 000add70
void Spawn__5CGlow(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  (*g_engfuncs)(*(int *)(*param_1 + 0x98) + (int)gpGlobals[0x26]);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),*(int *)(*param_1 + 0x98) + (int)gpGlobals[0x26]
                 );
  iVar2 = (*DAT_001754d0)(*(undefined4 *)(*param_1 + 0x94));
  param_1[0xf4] = (int)((float)iVar2 - 1.0);
  fVar1 = (float)param_1[0xf4];
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) {
    fVar1 = *(float *)(*param_1 + 0x118);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
    }
  }
  param_1[0xf3] = (int)*gpGlobals;
  return;
}


// Spawn__5CItem  @ 000bd550
void Spawn__5CItem(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity();
  if (iVar1 != 0) {
    *(undefined4 *)(*param_1 + 0xe8) = 6;
    *(undefined4 *)(*param_1 + 0xec) = 1;
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
    UTIL_SetSize__FP9entvars_tRC6VectorT1();
    param_1[5] = -0x10000;
    param_1[6] = (int)ItemTouch__5CItemP11CBaseEntity;
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0xf3] = 0x41a00000;
    }
    iVar1 = (*DAT_00175528)();
    if (iVar1 != 0) {
      return;
    }
    param_1 = (int *)*param_1;
    (*DAT_001755b4)(4,"Item %s fell out of level at %f,%f,%f",*param_1 + *(int *)(gpGlobals + 0x98),
                    (double)(float)param_1[2],(double)(float)param_1[3],(double)(float)param_1[4]);
  }
  UTIL_Remove__FP11CBaseEntity();
  return;
}


// Spawn__6CBlood  @ 000af240
void Spawn__6CBlood(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  SetMovedir__FP9entvars_t(*param_1);
  return;
}


// Spawn__6CDecal  @ 0011cce0
void Spawn__6CDecal(int *param_1)

{
  float fVar1;
  
  if ((-1 < *(int *)(*param_1 + 0xf0)) &&
     ((fVar1 = (float)gpGlobals[5],
      (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 ||
      ((*(byte *)(*param_1 + 0x181) & 8) == 0)))) {
    if (*(int *)(*param_1 + 0x1ac) == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)StaticDecal__6CDecal;
      *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
      return;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
    param_1[7] = -0x10000;
    param_1[8] = (int)TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf;
    return;
  }
  (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  return;
}


// Spawn__6CLaser  @ 000ad630
void Spawn__6CLaser(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (*(int *)(*param_1 + 0x98) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
    param_1[3] = -0x10000;
    param_1[4] = (int)StrikeThink__6CLaser;
    *(byte *)(*param_1 + 0x187) = *(byte *)(*param_1 + 0x187) | 0x20;
    PointsInit__5CBeamRC6VectorT1(param_1,*param_1 + 8,*param_1 + 8);
    if ((param_1[0xf3] == 0) && (param_1[0xf4] != 0)) {
      iVar7 = SpriteCreate__7CSpritePCcRC6Vectori
                        (param_1[0xf4] + *(int *)(gpGlobals + 0x98),*param_1 + 8,1);
      param_1[0xf3] = iVar7;
    }
    else {
      param_1[0xf3] = 0;
    }
    if (param_1[0xf3] != 0) {
      iVar7 = *param_1;
      fVar1 = *(float *)(iVar7 + 0x130);
      fVar2 = *(float *)(iVar7 + 0x134);
      fVar3 = *(float *)(iVar7 + 0x138);
      fVar4 = *(float *)(iVar7 + 300);
      piVar5 = (int *)param_1[0xf3];
      uVar6 = *(undefined4 *)(iVar7 + 0x13c);
      *(undefined4 *)(*piVar5 + 0x128) = 3;
      *(float *)(*piVar5 + 0x130) = (float)(int)ROUND(fVar1);
      *(float *)(*piVar5 + 0x134) = (float)(int)ROUND(fVar2);
      *(float *)(*piVar5 + 0x138) = (float)(int)ROUND(fVar3);
      *(float *)(*piVar5 + 300) = (float)(int)ROUND(fVar4);
      *(undefined4 *)(*piVar5 + 0x13c) = uVar6;
    }
    if ((*(int *)(*param_1 + 0x1ac) == 0) || (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) == 0)) {
      TurnOn__6CLaser(param_1);
    }
    else {
      TurnOff__6CLaser(param_1);
    }
  }
  return;
}


// Spawn__6CLight  @ 000bdaf0
void Spawn__6CLight(int *param_1)

{
  undefined *puVar1;
  
  if (*(int *)(*param_1 + 0x1ac) == 0) {
    (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  }
  else if (0x1f < param_1[0xf3]) {
    if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
      if (param_1[0xf4] == 0) {
        puVar1 = &DAT_001345ef;
      }
      else {
        puVar1 = (undefined *)(param_1[0xf4] + *(int *)(gpGlobals + 0x98));
      }
    }
    else {
      puVar1 = &DAT_001345ed;
    }
    (*DAT_0017556c)(param_1[0xf3],puVar1);
  }
  return;
}


// Spawn__6CShake  @ 000af630
void Spawn__6CShake(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
    *(undefined4 *)(*param_1 + 0x1c0) = 0;
  }
  return;
}


// Spawn__6CTFAxe  @ 000f8760
void Spawn__6CTFAxe(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 5;
  param_1[0x104] = -1;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__6CTFRpg  @ 001017b0
void Spawn__6CTFRpg(int *param_1)

{
  param_1[0x2c] = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 8;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_rpg.mdl");
  param_1[0x108] = 0x32;
  param_1[0x10b] = 0x3fa00000;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__6CWorld  @ 0011d8b0
void Spawn__6CWorld(int param_1)

{
  undefined4 uVar1;
  char *__src;
  int iVar2;
  longdouble lVar3;
  int local_8;
  
  g_fGameOver = 0;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0xc))(param_1);
  lVar3 = (longdouble)(*DAT_001755a4)("sv_cheats");
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
  iVar2 = 0;
  do {
    (&teamallies)[iVar2] = 0;
    (&g_pLastSpawns)[iVar2] = 0;
    (&teamadvantage)[iVar2] = 0x3f800000;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  g_szMapBriefingText = 0;
  local_8 = 0;
  uVar1 = UTIL_VarArgs__FPce("maps/%s.txt",*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98),
                             &local_8);
  __src = (char *)(*DAT_0017563c)(uVar1);
  if ((__src != (char *)0x0) && (local_8 != 0)) {
    strncpy(&g_szMapBriefingText,__src,0x1fe);
    uVar1 = UTIL_VarArgs__FPce("maps/%s.txt",*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98))
    ;
    (*DAT_00175680)(uVar1);
  }
  (*DAT_00175640)(__src);
  return;
}


// Spawn__7CCycler  @ 000bb820
void Spawn__7CCycler(int *param_1)

{
  float fVar1;
  
  InitBoneControllers__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x140) = 0x479c4000;
  *(undefined4 *)(*param_1 + 0x90) = 0x40a00000;
  *(undefined4 *)(*param_1 + 0x8c) = *(undefined4 *)(*param_1 + 0x54);
  (**(code **)(param_1[0xf2] + 0x110))(param_1,0x168);
  param_1[0xf5] = 0x42960000;
  param_1[0xf6] = 0;
  *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe4) + 1.0;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  if ((*(int *)(*param_1 + 0x108) == 0) &&
     (fVar1 = *(float *)(*param_1 + 0x110),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    param_1[0x184] = 1;
  }
  else {
    param_1[0x184] = 0;
    *(undefined4 *)(*param_1 + 0x118) = 0;
  }
  return;
}


// Spawn__7CLadder  @ 00111bf0
void Spawn__7CLadder(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  return;
}


// Spawn__7CMortar  @ 000c9290
void Spawn__7CMortar(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0x1c0) = 0x43480000;
  param_1[3] = -0x10000;
  param_1[4] = (int)MortarExplode__7CMortar;
  *(undefined4 *)(*param_1 + 0xe4) = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  return;
}


// Spawn__7CSentry  @ 00115e70
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__7CSentry(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/sentry.mdl");
  *(undefined4 *)(*param_1 + 0x140) = _DAT_00177a64;
  local_10 = 0;
  local_c = 0;
  local_8 = 0x42400000;
  param_1[0x17f] = 0;
  param_1[0x180] = 0;
  param_1[0x181] = 0x42400000;
  *(undefined4 *)(*param_1 + 0x15c) = 0x42400000;
  param_1[0x195] = 0x49742400;
  param_1[0x184] = 0x49742400;
  Spawn__11CBaseTurret(param_1);
  param_1[0x189] = 0x40;
  param_1[0x188] = 0x40;
  param_1[0x18a] = -0x3c;
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x42800000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0xc2800000;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[5] = -0x10000;
  param_1[6] = (int)SentryTouch__7CSentryP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.3;
  return;
}


// Spawn__7CShower  @ 000b1630
void Spawn__7CShower(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar3 = *param_1;
  lVar4 = (longdouble)(*DAT_0017562c)(0x43480000,0x43960000);
  fVar1 = *(float *)(*param_1 + 0x54);
  fVar2 = *(float *)(*param_1 + 0x58);
  *(float *)(iVar3 + 0x20) = (float)(lVar4 * (longdouble)*(float *)(*param_1 + 0x50));
  *(float *)(iVar3 + 0x24) = (float)(lVar4 * (longdouble)fVar1);
  *(float *)(iVar3 + 0x28) = (float)(lVar4 * (longdouble)fVar2);
  lVar4 = (longdouble)(*DAT_0017562c)(0xc2c80000,0x42c80000);
  *(float *)(*param_1 + 0x20) = (float)(lVar4 + (longdouble)*(float *)(*param_1 + 0x20));
  lVar4 = (longdouble)(*DAT_0017562c)(0xc2c80000,0x42c80000);
  *(float *)(*param_1 + 0x24) = (float)(lVar4 + (longdouble)*(float *)(*param_1 + 0x24));
  iVar3 = *param_1;
  fVar1 = *(float *)(iVar3 + 0x28);
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) + 200.0;
  }
  else {
    *(float *)(*param_1 + 0x28) = *(float *)(*param_1 + 0x28) - 200.0;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 10;
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f000000;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/grenade.mdl");
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&g_vecZero,&g_vecZero);
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  lVar4 = (longdouble)(*DAT_0017562c)(0x3f000000,0x3fc00000);
  *(float *)(*param_1 + 0x1d8) = (float)lVar4;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar3 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar3 + 0x58) = DAT_00175488;
  return;
}


// Spawn__7CSprite  @ 000adfa0
void Spawn__7CSprite(int *param_1)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar2 = (*DAT_001754d0)(*(undefined4 *)(*param_1 + 0x94));
  param_1[0xf4] = (int)((float)iVar2 - 1.0);
  if ((*(int *)(*param_1 + 0x1ac) == 0) || (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) == 0)) {
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


// Spawn__7CTFGoal  @ 00108ff0
void Spawn__7CTFGoal(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  
  iVar3 = CheckExistence__11CBaseEntity(param_1);
  iVar2 = gpGlobals;
  if (iVar3 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    *(int *)*param_1 = (int)"info_tfgoal" - *(int *)(gpGlobals + 0x98);
    iVar3 = *param_1;
    if (*(int *)(iVar3 + 0x98) != 0) {
      pcVar4 = (char *)(*(int *)(iVar3 + 0x98) + *(int *)(iVar2 + 0x98));
      if (*pcVar4 == '*') {
        *(byte *)(iVar3 + 0xf8) = *(byte *)(iVar3 + 0xf8) | 0x80;
      }
      (*g_engfuncs)(pcVar4);
      (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                      *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
    }
    if (*(int *)(*param_1 + 0x1c8) != 0) {
      (*DAT_001754c4)(*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    }
    (*DAT_001754c4)("items/protect.wav");
    (*DAT_001754c4)("items/protect2.wav");
    (*DAT_001754c4)("items/protect3.wav");
    (*DAT_001754c4)("FVox/HEV_logon.wav");
    (*DAT_001754c4)("FVox/hev_shutdown.wav");
    (*DAT_001754c4)("items/inv1.wav");
    (*DAT_001754c4)("items/inv2.wav");
    (*DAT_001754c4)("items/inv3.wav");
    (*DAT_001754c4)("items/damage.wav");
    (*DAT_001754c4)("items/damage2.wav");
    (*DAT_001754c4)("items/damage3.wav");
    *(undefined4 *)(*param_1 + 0xec) = 1;
    if (param_1[0x86] == 0) {
      param_1[0x86] = 2;
    }
    bVar5 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0x9e])) << 10) >> 8) |
               (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0x9e]) << 0xe) >> 8)) == 0x40)
       && ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN((float)param_1[0x9f])) << 10) >>
                        8) |
                 (byte)((ushort)((ushort)(DAT_00175484 == (float)param_1[0x9f]) << 0xe) >> 8)) ==
           0x40)) {
      fVar1 = (float)param_1[0xa0];
      bVar5 = (byte)(DAT_00175488 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar5) {
      bVar5 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN((float)param_1[0xa1])) << 10) >> 8)
                 | (byte)((ushort)((ushort)(g_vecZero == (float)param_1[0xa1]) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN((float)param_1[0xa2])) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(DAT_00175484 == (float)param_1[0xa2]) << 0xe) >> 8)) ==
          0x40)) {
        fVar1 = (float)param_1[0xa3];
        bVar5 = (byte)(DAT_00175488 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
      }
      if (!bVar5) {
        UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,param_1 + 0x9e,param_1 + 0xa1);
      }
    }
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
    StartGoal__7CTFGoal(param_1);
  }
  return;
}


// Spawn__7CTurret  @ 00113c90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__7CTurret(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/turret.mdl");
  *(undefined4 *)(*param_1 + 0x140) = _DAT_00177a5c;
  local_10 = 0;
  local_c = 0;
  local_8 = 0x414c0000;
  param_1[0x17f] = 0;
  param_1[0x180] = 0;
  param_1[0x181] = 0x414c0000;
  param_1[0x184] = 0x40a00000;
  *(undefined4 *)(*param_1 + 0x15c) = 0x414c0000;
  Spawn__11CBaseTurret(param_1);
  param_1[0x189] = 0x10;
  param_1[0x188] = 0x20;
  param_1[0x18a] = -0xf;
  local_10 = 0x42000000;
  local_c = 0x42000000;
  local_8 = 0x41800000;
  local_1c = 0xc2000000;
  local_18 = 0xc2000000;
  local_14 = 0xc1800000;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)Initialize__11CBaseTurret;
  piVar2 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/flare3.spr",*param_1 + 8,0);
  param_1[0x186] = (int)piVar2;
  *(undefined4 *)(*piVar2 + 0x128) = 3;
  *(undefined4 *)(*piVar2 + 0x130) = 0x437f0000;
  *(undefined4 *)(*piVar2 + 0x134) = 0;
  *(undefined4 *)(*piVar2 + 0x138) = 0;
  *(undefined4 *)(*piVar2 + 300) = 0;
  *(undefined4 *)(*piVar2 + 0x13c) = 0xe;
  iVar1 = *(int *)(*param_1 + 0x1e8);
  piVar2 = (int *)param_1[0x186];
  if (iVar1 != 0) {
    uVar3 = (*DAT_001755dc)(iVar1);
    *(undefined4 *)(*piVar2 + 0xf0) = uVar3;
    *(undefined4 *)(*piVar2 + 0xf4) = 2;
    *(int *)(*piVar2 + 0x174) = iVar1;
    *(undefined4 *)(*piVar2 + 0xe8) = 0xc;
  }
  param_1[0x187] = 0;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.3;
  return;
}


// Spawn__8CAirtank  @ 0009a790
void Spawn__8CAirtank(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 5;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_oxygen.mdl");
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x42100000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)TankTouch__8CAirtankP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)TankThink__8CAirtank;
  *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) | 0x20;
  *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x140) = 0x41a00000;
  *(undefined4 *)(*param_1 + 0x1c0) = 0x42480000;
  param_1[0x189] = 1;
  return;
}


// Spawn__8CCrowbar  @ 000a64a0
void Spawn__8CCrowbar(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 1;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_crowbar.mdl");
  param_1[0x104] = -1;
  FallInit__15CBasePlayerItem(param_1);
  return;
}


// Spawn__8CDeadHEV  @ 000dfd90
void Spawn__8CDeadHEV(int *param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/player.mdl");
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/player.mdl");
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x90) = 0x41000000;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0xf4) = 1;
  param_1[0x178] = 0xf7;
  uVar1 = LookupSequence__14CBaseAnimatingPCc
                    (param_1,*(undefined4 *)(_8CDeadHEV_m_szPoses + param_1[0x184] * 4));
  *(undefined4 *)(*param_1 + 0x108) = uVar1;
  if (*(int *)(*param_1 + 0x108) == -1) {
    (*DAT_001755b4)(1,"Dead hevsuit with bad pose\n");
    *(undefined4 *)(*param_1 + 0x108) = 0;
    *(undefined4 *)(*param_1 + 0xf8) = 1;
  }
  *(undefined4 *)(*param_1 + 0x140) = 0x41000000;
  (**(code **)(param_1[0xf2] + 0x120))(param_1);
  return;
}


// Spawn__8CDetpack  @ 000a74b0
void Spawn__8CDetpack(int *param_1)

{
  char *pcVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0x18a] = 0;
  param_1[0x189] = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  param_1[0x18b] = 0;
  if (birthday == 0) {
    pcVar1 = "models/detpack.mdl";
  }
  else {
    pcVar1 = "models/presentlg.mdl";
  }
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),pcVar1);
  param_1[5] = -0x10000;
  param_1[6] = (int)DetpackTouch__8CDetpackP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)DetpackThink__8CDetpack;
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0xe4) = local_8;
  local_14 = 0x40800000;
  local_10 = 0x40800000;
  local_c = 0x40800000;
  local_20 = 0xc0800000;
  local_1c = 0xc0800000;
  local_18 = 0xc0800000;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_20,&local_14);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  param_1[0x43] = 0;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),1,"weapons/mine_activate.wav",0x3f800000,0x3f4ccccd,0
             ,100);
  return;
}


// Spawn__8CGrenade  @ 000b9b20
void Spawn__8CGrenade(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0xe8) = 10;
  *(char **)*param_1 = "?grenade" + (1 - *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xec) = 2;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/grenade.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[0x184] = 0;
  param_1[0x187] = 0;
  param_1[0x186] = 0;
  *(undefined4 *)(*param_1 + 0x1c0) = 0x42c80000;
  param_1[0x188] = 0;
  return;
}


// Spawn__8CMessage  @ 000af970
void Spawn__8CMessage(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  iVar1 = *(int *)(*param_1 + 0x164);
  if (iVar1 == 1) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x3fa00000;
    goto LAB_000af9fc;
  }
  if (1 < iVar1) {
    if (iVar1 == 2) {
      *(undefined4 *)(*param_1 + 0x1d8) = 0x3f4ccccd;
      goto LAB_000af9fc;
    }
    if (iVar1 == 3) {
      *(undefined4 *)(*param_1 + 0x1d8) = 0;
      goto LAB_000af9fc;
    }
  }
  *(undefined4 *)(*param_1 + 0x1d8) = 0x40000000;
LAB_000af9fc:
  *(undefined4 *)(*param_1 + 0x164) = 0;
  if (*(float *)(*param_1 + 0x124) <= 0.0) {
    *(undefined4 *)(*param_1 + 0x124) = 0x3f800000;
  }
  return;
}


// Spawn__8CNodeEnt  @ 000cbca0
void Spawn__8CNodeEnt(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  if (WorldGraph == 0) {
    if (DAT_001758d8 == 0) {
      uVar4 = GetClassPtr__H1Z9CTestHull_PX01_PX01(0);
      Spawn__9CTestHullP9entvars_t(uVar4,*param_1);
    }
    iVar5 = DAT_001758cc;
    if (0x3ff < DAT_001758d8) {
      (*DAT_001755b4)(2,"cNodes > MAX_NODES\n");
      return;
    }
    iVar6 = DAT_001758d8 * 0x58;
    puVar1 = (undefined4 *)(DAT_001758cc + iVar6);
    iVar3 = *param_1;
    *puVar1 = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar5 + 4 + iVar6) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar5 + 8 + iVar6) = *(undefined4 *)(iVar3 + 0x10);
    puVar2 = (undefined4 *)(DAT_001758cc + DAT_001758d8 * 0x58);
    puVar1[3] = *puVar2;
    puVar1[4] = puVar2[1];
    puVar1[5] = puVar2[2];
    *(undefined4 *)(DAT_001758cc + 0x54 + DAT_001758d8 * 0x58) = *(undefined4 *)(*param_1 + 0x54);
    *(short *)(DAT_001758cc + 0x50 + DAT_001758d8 * 0x58) = (short)param_1[0xf3];
    *(undefined2 *)(DAT_001758cc + 0x52 + DAT_001758d8 * 0x58) =
         *(undefined2 *)((int)param_1 + 0x3ce);
    iVar5 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"info_node_air");
    if (iVar5 == 0) {
      *(undefined4 *)(DAT_001758cc + 0x1c + DAT_001758d8 * 0x58) = 2;
    }
    else {
      *(undefined4 *)(DAT_001758cc + 0x1c + DAT_001758d8 * 0x58) = 0;
    }
    DAT_001758d8 = DAT_001758d8 + 1;
  }
  (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  return;
}


// Spawn__8CRotDoor  @ 000aa820
void Spawn__8CRotDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  AxisDir__11CBaseToggleP9entvars_t(*param_1);
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x180) & 2) != 0) {
    *(float *)(iVar6 + 0x44) = *(float *)(iVar6 + 0x44) * -1.0;
    *(float *)(iVar6 + 0x48) = *(float *)(iVar6 + 0x48) * -1.0;
    *(float *)(iVar6 + 0x4c) = *(float *)(iVar6 + 0x4c) * -1.0;
  }
  iVar6 = *param_1;
  param_1[0x107] = *(int *)(iVar6 + 0x50);
  param_1[0x108] = *(int *)(iVar6 + 0x54);
  param_1[0x109] = *(int *)(iVar6 + 0x58);
  fVar1 = (float)param_1[0xfc];
  fVar2 = *(float *)(iVar6 + 0x48);
  fVar3 = *(float *)(iVar6 + 0x4c);
  fVar4 = *(float *)(iVar6 + 0x54);
  fVar5 = *(float *)(iVar6 + 0x58);
  param_1[0x10a] = (int)(*(float *)(iVar6 + 0x50) + fVar1 * *(float *)(iVar6 + 0x44));
  param_1[0x10b] = (int)(fVar4 + fVar1 * fVar2);
  param_1[0x10c] = (int)(fVar5 + fVar1 * fVar3);
  if ((*(byte *)(iVar6 + 0x180) & 8) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 4;
  }
  else {
    *(undefined4 *)(iVar6 + 0xec) = 0;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
  }
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x180) & 1) != 0) {
    *(int *)(iVar6 + 0x50) = param_1[0x10a];
    *(int *)(iVar6 + 0x54) = param_1[0x10b];
    *(int *)(iVar6 + 0x58) = param_1[0x10c];
    param_1[0x10a] = param_1[0x107];
    param_1[0x10b] = param_1[0x108];
    param_1[0x10c] = param_1[0x109];
    param_1[0x107] = param_1[0x107];
    param_1[0x108] = param_1[0x108];
    param_1[0x109] = param_1[0x109];
    iVar6 = *param_1;
    *(float *)(iVar6 + 0x44) = *(float *)(iVar6 + 0x44) * -1.0;
    *(float *)(iVar6 + 0x48) = *(float *)(iVar6 + 0x48) * -1.0;
    *(float *)(iVar6 + 0x4c) = *(float *)(iVar6 + 0x4c) * -1.0;
  }
  param_1[0xfa] = 1;
  if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  else {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  return;
}


// Spawn__8CSpeaker  @ 000eda30
void Spawn__8CSpeaker(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1[0xf3] == 0) {
    if (*(int *)(*param_1 + 0x1b4) != 0) {
      iVar2 = -1;
      pcVar3 = (char *)((int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1b4));
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (iVar2 != -2) goto LAB_000edad0;
    }
    iVar2 = *param_1;
    (*DAT_001755b4)(4,"SPEAKER with no Level/Sentence! at: %f, %f, %f\n",
                    (double)*(float *)(iVar2 + 8),(double)*(float *)(iVar2 + 0xc),
                    (double)*(float *)(iVar2 + 0x10));
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
LAB_000edad0:
    *(undefined4 *)(*param_1 + 0xec) = 0;
    *(undefined4 *)(*param_1 + 0xe8) = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SpeakerThink__8CSpeaker;
    *(undefined4 *)(*param_1 + 0xe4) = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf;
    (**(code **)(param_1[0xf2] + 0xc))();
  }
  return;
}


// Spawn__8CTFFlame  @ 000e4720
void Spawn__8CTFFlame(int *param_1)

{
  float *pfVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  pfVar1 = gpGlobals;
  *(char **)*param_1 = "?tf_fire" + (1 - (int)gpGlobals[0x26]);
  param_1[0xdb] = (int)"flames" - (int)pfVar1[0x26];
  *(float *)(*param_1 + 0x140) = *pfVar1 + 4.5;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x88;
  *(float *)(*param_1 + 0xe4) = *pfVar1 + 1.0;
  param_1[0x184] = *(int *)(*param_1 + 0xe4);
  param_1[3] = -0x10000;
  param_1[4] = (int)FlameThink__8CTFFlame;
  return;
}


// Spawn__8CTFKnife  @ 000f9690
void Spawn__8CTFKnife(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 0x17;
  param_1[0x104] = -1;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__8CTFSpawn  @ 00108f50
void Spawn__8CTFSpawn(int *param_1)

{
  int iVar1;
  
  iVar1 = CheckExistence__11CBaseEntity(param_1);
  if (iVar1 == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else if (param_1[0x48] - 1U < 4) {
    if (number_of_teams < (float)param_1[0x48]) {
      number_of_teams = (float)param_1[0x48];
    }
    ((undefined4 *)*param_1)[0x6c] = *(undefined4 *)*param_1;
    *(int *)*param_1 = *(int *)(sTeamSpawnNames + param_1[0x48] * 4) - *(int *)(gpGlobals + 0x98);
  }
  else {
    (*DAT_001755b4)(1,"Teamspawnpoint with an invalid team_no of %d\n",param_1[0x48]);
  }
  return;
}


// Spawn__8CTFTranq  @ 00103e30
void Spawn__8CTFTranq(int *param_1)

{
  *(int *)*param_1 = (int)"tf_weapon_tranq" - *(int *)(gpGlobals + 0x98);
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  param_1[0xfc] = 2;
  param_1[0x108] = 0x11;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  return;
}


// Spawn__8CXenHair  @ 0011e680
void Spawn__8CXenHair(int *param_1)

{
  longdouble lVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/hair.mdl");
  local_10 = 0x40800000;
  local_c = 0x40800000;
  local_8 = 0x42000000;
  local_1c = 0xc0800000;
  local_18 = 0xc0800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  *(undefined4 *)(*param_1 + 0x108) = 0;
  if (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) != 0) {
    lVar1 = (longdouble)(*DAT_0017562c)(0,0x437f0000);
    *(float *)(*param_1 + 0x110) = (float)lVar1;
    lVar1 = (longdouble)(*DAT_0017562c)(0x3f333333,0x3fb33333);
    *(float *)(*param_1 + 0x118) = (float)lVar1;
  }
  ResetSequenceInfo__14CBaseAnimating(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  lVar1 = (longdouble)(*DAT_0017562c)(0x3dcccccd,0x3ecccccd);
  *(float *)(*param_1 + 0xe4) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


// Spawn__8CXenTree  @ 0011e950
void Spawn__8CXenTree(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longdouble lVar3;
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
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/tree.mdl");
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  local_10 = 30.0;
  local_c = 30.0;
  local_8 = 188.0;
  local_1c = -30.0;
  local_18 = -30.0;
  local_14 = 0.0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  SetActivity__13CActAnimating8Activity(param_1,1);
  local_20 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0xe4) = local_20;
  lVar3 = (longdouble)(*DAT_0017562c)(0,0x437f0000);
  *(float *)(*param_1 + 0x110) = (float)lVar3;
  lVar3 = (longdouble)(*DAT_0017562c)(0x3f333333,0x3fb33333);
  *(float *)(*param_1 + 0x118) = (float)lVar3;
  (*DAT_00175510)(*param_1 + 0x50,&local_1c,0,0);
  local_2c = local_1c * 64.0;
  local_28 = local_18 * 64.0;
  local_24 = local_14 * 64.0;
  iVar1 = *param_1;
  local_1c = *(float *)(iVar1 + 8) + local_2c;
  local_18 = *(float *)(iVar1 + 0xc) + local_28;
  local_14 = *(float *)(iVar1 + 0x10) + local_24;
  local_10 = local_1c;
  local_c = local_18;
  local_8 = local_14;
  puVar2 = (undefined4 *)
           TriggerCreate__15CXenTreeTriggerP7edict_sRC6Vector
                     (*(undefined4 *)(iVar1 + 0x1e8),&local_1c);
  param_1[0xfb] = (int)puVar2;
  local_2c = 24.0;
  local_28 = 24.0;
  local_24 = 128.0;
  local_10 = -24.0;
  local_c = -24.0;
  local_8 = 0.0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*puVar2,&local_10,&local_2c);
  return;
}


// Spawn__9CBaseDoor  @ 000a94b0
void Spawn__9CBaseDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  SetMovedir__FP9entvars_t(*param_1);
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0xf0) == 0) {
    if ((*(byte *)(iVar3 + 0x180) & 8) == 0) {
      *(undefined4 *)(*param_1 + 0xec) = 4;
    }
    else {
      *(undefined4 *)(iVar3 + 0xec) = 0;
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
    *(byte *)(*param_1 + 0x183) = *(byte *)(*param_1 + 0x183) | 0x80;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
  }
  iVar3 = *param_1;
  param_1[0x101] = *(int *)(iVar3 + 8);
  param_1[0x102] = *(int *)(iVar3 + 0xc);
  param_1[0x103] = *(int *)(iVar3 + 0x10);
  fVar4 = (ABS((*(float *)(iVar3 + 0xd8) - 2.0) * *(float *)(iVar3 + 0x48)) +
           ABS((*(float *)(iVar3 + 0xd4) - 2.0) * *(float *)(iVar3 + 0x44)) +
          ABS((*(float *)(iVar3 + 0xdc) - 2.0) * *(float *)(iVar3 + 0x4c))) - (float)param_1[0xfe];
  fVar1 = *(float *)(iVar3 + 0x48);
  fVar2 = *(float *)(iVar3 + 0x4c);
  param_1[0x104] = (int)((float)param_1[0x101] + fVar4 * *(float *)(iVar3 + 0x44));
  param_1[0x105] = (int)((float)param_1[0x102] + fVar4 * fVar1);
  param_1[0x106] = (int)((float)param_1[0x103] + fVar4 * fVar2);
  if ((*(byte *)(iVar3 + 0x180) & 1) != 0) {
    UTIL_SetOrigin__FP9entvars_tRC6Vector(iVar3,param_1 + 0x104);
    param_1[0x104] = param_1[0x101];
    param_1[0x105] = param_1[0x102];
    param_1[0x106] = param_1[0x103];
    iVar3 = *param_1;
    param_1[0x101] = *(int *)(iVar3 + 8);
    param_1[0x102] = *(int *)(iVar3 + 0xc);
    param_1[0x103] = *(int *)(iVar3 + 0x10);
  }
  param_1[0xfa] = 1;
  if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  else {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  return;
}


// Spawn__9CBubbling  @ 000ab260
void Spawn__9CBubbling(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),*(int *)(*param_1 + 0x98) + (int)gpGlobals[0x26]
                 );
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 300) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 2;
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    fVar1 = -*(float *)(*param_1 + 0x1d8);
  }
  *(float *)(*param_1 + 0x130) = (float)((int)ROUND(fVar1) >> 8);
  *(float *)(*param_1 + 0x134) = (float)((int)ROUND(fVar1) & 0xff);
  uVar2 = 0;
  if (*(float *)(*param_1 + 0x1d8) < 0.0) {
    uVar2 = 0x3f800000;
  }
  *(undefined4 *)(*param_1 + 0x138) = uVar2;
  if (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) == 0) {
    param_1[0xf6] = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)FizzThink__9CBubbling;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 2.0;
    param_1[0xf6] = 1;
  }
  return;
}


// Spawn__9CEnvLight  @ 000be010
void Spawn__9CEnvLight(int *param_1)

{
  char local_44 [64];
  
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  sprintf(local_44,"%f",SUB84((double)*(float *)(gpGlobals + 0x28),0),
          (int)((ulonglong)(double)*(float *)(gpGlobals + 0x28) >> 0x20));
  (*DAT_001755b0)("cl_skyvec_x",local_44);
  sprintf(local_44,"%f",(double)*(float *)(gpGlobals + 0x2c));
  (*DAT_001755b0)("cl_skyvec_y",local_44);
  sprintf(local_44,"%f",SUB84((double)*(float *)(gpGlobals + 0x30),0),
          (int)((ulonglong)(double)*(float *)(gpGlobals + 0x30) >> 0x20));
  (*DAT_001755b0)();
  Spawn__6CLight(param_1);
  return;
}


// Spawn__9CEnvSound  @ 000ec6a0
void Spawn__9CEnvSound(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_0017562c)(0,0x3f000000);
  *(float *)(*param_1 + 0xe4) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


// Spawn__9CEnvSpark  @ 0009fc30
void Spawn__9CEnvSpark(int *param_1)

{
  longdouble lVar1;
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  if ((*(byte *)(*param_1 + 0x180) & 0x20) == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SparkThink__9CEnvSpark;
  }
  else if ((*(byte *)(*param_1 + 0x180) & 0x40) == 0) {
    param_1[7] = -0x10000;
    param_1[8] = (int)SparkStart__9CEnvSparkP11CBaseEntityT18USE_TYPEf;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)SparkThink__9CEnvSpark;
    param_1[7] = -0x10000;
    param_1[8] = (int)SparkStop__9CEnvSparkP11CBaseEntityT18USE_TYPEf;
  }
  lVar1 = (longdouble)(*DAT_0017562c)(0,0x3fc00000);
  *(float *)(*param_1 + 0xe4) = (float)((longdouble)0.1 + lVar1 + (longdouble)*gpGlobals);
  if ((float)param_1[0xf3] <= 0.0) {
    param_1[0xf3] = 0x3fc00000;
  }
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  return;
}


// Spawn__9CFuncPlat  @ 000d1510
void Spawn__9CFuncPlat(int *param_1)

{
  Setup__9CFuncPlat(param_1);
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  if (*(int *)(*param_1 + 0x1ac) == 0) {
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,param_1 + 0x104);
    param_1[0xfa] = 1;
  }
  else {
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,param_1 + 0x101);
    param_1[0xfa] = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)PlatUse__9CFuncPlatP11CBaseEntityT18USE_TYPEf;
  }
  return;
}


// Spawn__9CFuncTank  @ 000b3d60
void Spawn__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  *(undefined4 *)(*param_1 + 0xec) = 4;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar6 = *param_1;
  param_1[0xf8] = *(int *)(iVar6 + 0x54);
  param_1[0xfc] = *(int *)(iVar6 + 0x50);
  if ((*(byte *)(iVar6 + 0x180) & 1) != 0) {
    local_8 = *(float *)(iVar6 + 0xe0) + 1.0;
    *(float *)(iVar6 + 0xe4) = local_8;
  }
  (*DAT_00175510)(*param_1 + 0x50,&local_20,&local_2c,&local_38);
  fVar1 = (float)param_1[0x106];
  fVar2 = *(float *)(*param_1 + 0xc);
  fVar3 = *(float *)(*param_1 + 0x10);
  fVar4 = (float)param_1[0x107];
  fVar5 = (float)param_1[0x108];
  param_1[0x10e] =
       (int)(*(float *)(*param_1 + 8) + fVar1 * local_20 + fVar4 * local_2c + fVar5 * local_38);
  param_1[0x10f] = (int)(fVar2 + fVar1 * local_1c + fVar4 * local_28 + fVar5 * local_34);
  param_1[0x110] = (int)(fVar3 + fVar1 * local_18 + fVar4 * local_24 + fVar5 * local_30);
  if ((float)param_1[0x101] <= 0.0) {
    param_1[0x101] = 0x3f800000;
  }
  if (5 < (uint)param_1[0x111]) {
    param_1[0x111] = 0;
  }
  iVar6 = *param_1;
  *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(iVar6 + 8);
  *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar6 + 0xc);
  *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar6 + 0x10);
  return;
}


// Spawn__9CFuncWall  @ 0009b660
void Spawn__9CFuncWall(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x58) = DAT_00175488;
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  *(undefined4 *)(*param_1 + 0xec) = 4;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(byte *)(*param_1 + 0x187) = *(byte *)(*param_1 + 0x187) | 2;
  return;
}


// Spawn__9CItemAmmo  @ 000f5b70
void Spawn__9CItemAmmo(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  Spawn__5CItem(param_1);
  Precache__9CItemAmmo(param_1);
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),param_1[0xf4] + *(int *)(gpGlobals + 0x98));
  }
  else {
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),param_1[0xf5] + *(int *)(gpGlobals + 0x98));
    param_1[0x33] = param_1[0x33] << 1;
    param_1[0x35] = param_1[0x35] << 1;
    param_1[0x39] = param_1[0x39] << 1;
    param_1[0x37] = param_1[0x37] << 1;
  }
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x41800000;
  local_1c = 0xc1800000;
  local_18 = 0xc1800000;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  return;
}


// Spawn__9CItemSoda  @ 000afef0
void Spawn__9CItemSoda(int *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/can.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)CanThink__9CItemSoda;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.5;
  return;
}


// Spawn__9CItemSuit  @ 00125b40
void Spawn__9CItemSuit(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/w_suit.mdl");
  Spawn__5CItem(param_1);
  return;
}


// Spawn__9CPendulum  @ 0009cbb0
void Spawn__9CPendulum(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  
  AxisDir__11CBaseToggleP9entvars_t(*param_1);
  if ((*(byte *)(*param_1 + 0x180) & 8) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 4;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
  }
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),*(int *)(*param_1 + 0x98) + (int)gpGlobals[0x26]
                 );
  fVar1 = (float)param_1[0xf4];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = *(float *)(*param_1 + 0x1d8);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x1d8) = 0x42c80000;
    }
    iVar5 = *param_1;
    param_1[0xf3] =
         (int)((*(float *)(iVar5 + 0x1d8) * *(float *)(iVar5 + 0x1d8)) /
              (ABS((float)param_1[0xf4]) + ABS((float)param_1[0xf4])));
    param_1[0xf7] = *(int *)(iVar5 + 0x1d8);
    param_1[0xfc] = *(int *)(iVar5 + 0x50);
    param_1[0xfd] = *(int *)(iVar5 + 0x54);
    param_1[0xfe] = *(int *)(iVar5 + 0x58);
    fVar6 = (float)param_1[0xf4] * 0.5;
    fVar1 = *(float *)(iVar5 + 0x48);
    fVar2 = *(float *)(iVar5 + 0x4c);
    fVar3 = *(float *)(iVar5 + 0x54);
    fVar4 = *(float *)(iVar5 + 0x58);
    param_1[0xf9] = (int)(*(float *)(iVar5 + 0x50) + fVar6 * *(float *)(iVar5 + 0x44));
    param_1[0xfa] = (int)(fVar3 + fVar6 * fVar1);
    param_1[0xfb] = (int)(fVar4 + fVar6 * fVar2);
    if ((*(byte *)(iVar5 + 0x180) & 1) != 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_CallUseToggle__11CBaseEntity;
      *(float *)(iVar5 + 0xe4) = *gpGlobals + 0.1;
    }
    *(undefined4 *)(*param_1 + 0x1d8) = 0;
    param_1[7] = -0x10000;
    param_1[8] = (int)PendulumUse__9CPendulumP11CBaseEntityT18USE_TYPEf;
    if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
      param_1[5] = -0x10000;
      param_1[6] = (int)RopeTouch__9CPendulumP11CBaseEntity;
    }
  }
  return;
}


// Spawn__9CPushable  @ 000b3530
void Spawn__9CPushable(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
  if (*(char *)(*param_1 + 0x180) < '\0') {
    Spawn__10CBreakable(param_1);
  }
  else {
    (**(code **)(param_1[0xf2] + 0xc))(param_1);
  }
  *(undefined4 *)(*param_1 + 0xe8) = 0xd;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  fVar2 = *(float *)(*param_1 + 0x100);
  if ((byte)(399.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 399.0) << 0xe) >> 8)) == 1) {
    *(undefined4 *)(*param_1 + 0x100) = 0x43c78000;
  }
  param_1[0xfc] = (int)(400.0 - *(float *)(*param_1 + 0x100));
  pbVar1 = (byte *)(*param_1 + 0x185);
  *pbVar1 = *pbVar1 | 0x80;
  *(undefined4 *)(*param_1 + 0x100) = 0;
  *(float *)(*param_1 + 0x10) = *(float *)(*param_1 + 0x10) + 1.0;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  iVar3 = *param_1;
  *(int *)(iVar3 + 0xf0) =
       (int)ROUND((*(float *)(iVar3 + 0xcc) - *(float *)(iVar3 + 0xc0)) *
                  (*(float *)(iVar3 + 200) - *(float *)(iVar3 + 0xbc)) *
                  (float)*(int *)(iVar3 + 0xf0) * 0.0005);
  param_1[0xfd] = 0;
  return;
}


// Spawn__9CRecharge  @ 000baaa0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Spawn__9CRecharge(int *param_1)

{
  int iVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  *(undefined4 *)(*param_1 + 0xec) = 4;
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  iVar1 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar1,iVar1 + 0xbc,iVar1 + 200);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  param_1[0x11d] = (int)ROUND(_DAT_00177ab8);
  *(undefined4 *)(*param_1 + 0x110) = 0;
  return;
}


// Spawn__9CSoundEnt  @ 000ee000
void Spawn__9CSoundEnt(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xec) = 0;
  Initialize__9CSoundEnt(param_1);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  return;
}


// Spawn__9CSprayCanP9entvars_t  @ 000dd2c0
void Spawn__9CSprayCanP9entvars_t(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *param_1;
  fVar1 = *(float *)(param_2 + 0xc);
  fVar2 = *(float *)(param_2 + 0x10);
  *(float *)(iVar3 + 8) = *(float *)(param_2 + 8) + 0.0;
  *(float *)(iVar3 + 0xc) = fVar1 + 0.0;
  *(float *)(iVar3 + 0x10) = fVar2 + 32.0;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(param_2 + 0x74);
  *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(param_2 + 0x78);
  *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(param_2 + 0x7c);
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(param_2 + 0x1e8);
  *(undefined4 *)(*param_1 + 0x110) = 0;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),2,"player/sprayer.wav",0x3f800000,0x3f4ccccd,0,100);
  return;
}


// Spawn__9CTFDetect  @ 00109af0
void Spawn__9CTFDetect(void)

{
  return;
}


// Spawn__9CTestHullP9entvars_t  @ 000cbaa0
void Spawn__9CTestHullP9entvars_t(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/player.mdl");
  uStack_10 = 0x41800000;
  uStack_c = 0x41800000;
  uStack_8 = 0x42900000;
  uStack_1c = 0xc1800000;
  uStack_18 = 0xc1800000;
  uStack_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&uStack_1c,&uStack_10);
  *(undefined4 *)(*param_1 + 0xec) = 3;
  *(undefined4 *)(*param_1 + 0xe8) = 4;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x140) = 0x42480000;
  *(undefined4 *)(*param_1 + 0x90) = 0x41000000;
  if (WorldGraph == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)DropDelay__9CTestHull;
    iVar2 = *param_1;
    fVar1 = *gpGlobals + 1.0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    iVar2 = *param_1;
    fVar1 = *gpGlobals;
  }
  *(float *)(iVar2 + 0xe4) = fVar1;
  *(undefined4 *)(*param_1 + 0x128) = 2;
  *(undefined4 *)(*param_1 + 300) = 0;
  return;
}


// Spawn__9CWreckage  @ 000bc0c0
void Spawn__9CWreckage(int *param_1)

{
  float *pfVar1;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(undefined4 *)(*param_1 + 0xf8) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  pfVar1 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  if (*(int *)(*param_1 + 0x98) != 0) {
    (*g_engfuncs)(*(int *)(*param_1 + 0x98) + (int)pfVar1[0x26]);
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                    *(int *)(*param_1 + 0x98) + (int)gpGlobals[0x26]);
  }
  param_1[0x184] = (int)ROUND(*gpGlobals);
  return;
}


// Spawn__9CXenSpore  @ 0011f180
void Spawn__9CXenSpore(int *param_1)

{
  longdouble lVar1;
  
  (**(code **)(param_1[0xf2] + 0xc))(param_1);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(undefined4 *)(_9CXenSpore_pModelNames + *(int *)(*param_1 + 0xf0) * 4));
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 2;
  *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  lVar1 = (longdouble)(*DAT_0017562c)(0,0x437f0000);
  *(float *)(*param_1 + 0x110) = (float)lVar1;
  lVar1 = (longdouble)(*DAT_0017562c)(0x3f333333,0x3fb33333);
  *(float *)(*param_1 + 0x118) = (float)lVar1;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  lVar1 = (longdouble)(*DAT_0017562c)(0x3dcccccd,0x3ecccccd);
  *(float *)(*param_1 + 0xe4) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


