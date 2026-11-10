// MyTouch__10CHealthKitP11CBasePlayer  @ 000b5254
undefined4 MyTouch__10CHealthKitP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(param_2[0x115] + 0x3c))(param_2,DAT_001a1d24,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    (*DAT_0019f758)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f778)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    (*DAT_0019f75c)();
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/smallmedkit1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    iVar1 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar1 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(param_1[0x115] + 0xc0))(param_1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


// MyTouch__10CItemArmorP11CBasePlayer  @ 000fc188
undefined4 MyTouch__10CItemArmorP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  float local_14;
  
  iVar6 = *param_2;
  fVar2 = (float)param_2[0x3c];
  if ((*(float *)(iVar6 + 0x1bc) < fVar2) ||
     ((*(int *)(iVar6 + 0x20c) == 9 && (param_2[0x37] < param_2[0x36])))) {
    local_14 = *(float *)(param_1 + 0x45c);
    fVar3 = *(float *)(iVar6 + 0x1bc);
    if (fVar3 < *(float *)(param_1 + 0x460)) {
      fVar3 = *(float *)(param_1 + 0x460);
    }
    fVar4 = (float)param_2[0x3b];
    if (0x3f < (byte)((fVar4 < fVar3 |
                       (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar4 == fVar3) << 0xe) >> 8)) - 1)) {
      fVar4 = fVar3;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == 0.3) << 0xe) >> 8)) == 0x40) {
      uVar7 = 0x2000;
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar4 == 0.6) << 0xe) >> 8)) == 0x40) {
      uVar7 = 0x4000;
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar4 == 0.8) << 0xe) >> 8)) == 0x40) {
      uVar7 = 0x8000;
    }
    else {
      (*DAT_0019f794)(4,"Bad ArmorType.\n");
      uVar7 = 0;
      iVar6 = *param_2;
      fVar2 = (float)param_2[0x3c];
    }
    if (fVar2 < local_14) {
      if (*(int *)(iVar6 + 0x20c) == 9) {
        iVar6 = param_2[0x36];
        if ((param_2[0x37] < iVar6) &&
           (iVar1 = (int)ROUND(((float)(int)ROUND(*(float *)(param_1 + 0x45c)) - fVar2) +
                               (float)param_2[0x37]), param_2[0x37] = iVar1, iVar6 < iVar1)) {
          param_2[0x37] = iVar6;
        }
      }
      local_14 = (float)param_2[0x3c];
      iVar6 = *param_2;
    }
    *(float *)(iVar6 + 0x1b8) = fVar4;
    local_14 = local_14 + *(float *)(*param_2 + 0x1bc);
    fVar2 = (float)param_2[0x3c];
    if (0x3f < (byte)((fVar2 < local_14 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_14)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == local_14) << 0xe) >> 8)) - 1)) {
      fVar2 = local_14;
    }
    *(float *)(*param_2 + 0x1bc) = fVar2;
    param_2[0x22] = uVar7 | param_2[0x22] & 0xffff1fffU;
    if (0 < *(int *)(param_1 + 0x38)) {
      param_2[0xe] = *(int *)(param_1 + 0x38);
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/armoron_1.wav",0x3f800000,0x3f4ccccd,0,100
              );
    iVar6 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar6 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x454) + 0xc0))(param_1);
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


// MyTouch__11CItemHealthP11CBasePlayer  @ 000fbff8
undefined4 MyTouch__11CItemHealthP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1[0x118] == 1) {
    if ((*(byte *)(param_2 + 0x21) & 0x10) == 0) {
      fVar1 = *(float *)(*param_2 + 0x160);
      if ((0x3f < (byte)((250.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar1 == 250.0) << 0xe) >> 8)) - 1)) &&
         (iVar2 = (**(code **)(param_2[0x115] + 0x3c))(param_2,(float)param_1[0x117],0x1000000),
         iVar2 != 0)) {
        *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 1;
        piVar3 = (int *)CreateTimer__11CBaseEntityi(param_2,5);
        *(float *)(*piVar3 + 0x104) = *gpGlobals + 5.0;
        piVar3[3] = -0x10000;
        piVar3[4] = (int)Timer_HealthRot__11CBaseEntity;
        *(undefined4 *)(*piVar3 + 400) = *(undefined4 *)(*param_1 + 0x208);
        SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
        return 1;
      }
      return 0;
    }
  }
  else {
    iVar2 = (**(code **)(param_2[0x115] + 0x3c))(param_2,(float)param_1[0x117],0);
    if (iVar2 == 0) {
      return 0;
    }
    if ((*(byte *)(param_2 + 0x21) & 0x10) == 0) goto LAB_000fc135;
  }
  if (0x50 < param_1[0x117]) {
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Item_medhealed",0,0,0,0);
    *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xef;
  }
LAB_000fc135:
  iVar2 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0xc0))(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return 1;
}


// MyTouch__12CItemBatteryP11CBasePlayer  @ 00141788
undefined4 MyTouch__12CItemBatteryP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  char local_44 [64];
  
  iVar3 = *param_2;
  if ((100.0 <= *(float *)(iVar3 + 0x1bc)) || (-1 < *(int *)(iVar3 + 0x168))) {
    uVar2 = 0;
  }
  else {
    *(float *)(iVar3 + 0x1bc) = *(float *)(iVar3 + 0x1bc) + DAT_001a1d1c;
    fVar1 = *(float *)(*param_2 + 0x1bc);
    if (0x3f < (byte)((fVar1 < 100.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 100.0) << 0xe) >> 8)) - 1)) {
      fVar1 = 100.0;
    }
    *(float *)(*param_2 + 0x1bc) = fVar1;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/gunpickup2.wav",0x3f800000,0x3f4ccccd,0,
               100);
    (*DAT_0019f758)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f778)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    (*DAT_0019f75c)();
    iVar3 = (int)ROUND(*(float *)(*param_2 + 0x1bc) * 100.0 * 0.01 + 0.5) / 5;
    if (0 < iVar3) {
      iVar3 = iVar3 + -1;
    }
    sprintf(local_44,"!HEV_%1dP",iVar3);
    SetSuitUpdate__11CBasePlayerPcii(param_2,local_44,0,0x1e);
    uVar2 = 1;
  }
  return uVar2;
}


// MyTouch__12CItemPowerupP11CBasePlayer  @ 000fc700
undefined4 MyTouch__12CItemPowerupP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_2 + 0x208),3,*(int *)(*param_1 + 0x1e8) + (int)gpGlobals[0x26],
             0x3f800000,0x3f4ccccd,0,100);
  param_2[0x22] = param_2[0x22] | param_1[0x22];
  fVar1 = (float)param_1[0x10b];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0x10b] = (int)(fVar1 + *gpGlobals);
  }
  fVar1 = (float)param_1[0x10e];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0x10e] = (int)(fVar1 + *gpGlobals);
  }
  fVar1 = (float)param_1[0x10c];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0x10c] = (int)(fVar1 + *gpGlobals);
  }
  fVar1 = (float)param_1[0x10d];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0x10d] = (int)(fVar1 + *gpGlobals);
  }
  *(undefined4 *)(*param_2 + 0x15c) = 0;
  iVar2 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x115] + 0xc0))(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return 1;
}


// MyTouch__13CItemAntidoteP11CBasePlayer  @ 00141668
undefined4 MyTouch__13CItemAntidoteP11CBasePlayer(undefined4 param_1,int param_2)

{
  SetSuitUpdate__11CBasePlayerPcii(param_2,"!HEV_DET4",0,0x3c);
  *(int *)(param_2 + 0x6f8) = *(int *)(param_2 + 0x6f8) + 1;
  return 1;
}


// MyTouch__13CItemLongJumpP11CBasePlayer  @ 001413cc
undefined4 MyTouch__13CItemLongJumpP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2[0x227] == 0) {
    if (*(int *)(*param_2 + 0x168) < 0) {
      param_2[0x227] = 1;
      (*DAT_0019f758)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
      (*DAT_0019f778)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      (*DAT_0019f75c)();
      EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_2 + 0x208),"!HEV_A1");
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// MyTouch__13CItemSecurityP11CBasePlayer  @ 0014156c
undefined4 MyTouch__13CItemSecurityP11CBasePlayer(undefined4 param_1,int param_2)

{
  *(int *)(param_2 + 0x6fc) = *(int *)(param_2 + 0x6fc) + 1;
  return 1;
}


// MyTouch__5CItemP11CBasePlayer  @ 000b6198
undefined4 MyTouch__5CItemP11CBasePlayer(void)

{
  return 0;
}


// MyTouch__9CItemAmmoP11CBasePlayer  @ 000fc4e0
undefined4 MyTouch__9CItemAmmoP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x10c))(param_1,param_2);
  iVar2 = GiveTFAmmo__11CBasePlayeriiii
                    (param_2,*(undefined4 *)(param_1 + 0xcc),*(undefined4 *)(param_1 + 0xd4),
                     *(undefined4 *)(param_1 + 0xe4),*(undefined4 *)(param_1 + 0xdc));
  if ((iVar2 == 0) && (iVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/gunpickup2.wav",0x3f800000,0x3f4ccccd,0,
               100);
    if (iVar1 != 0) {
      (*DAT_0019f758)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
      (*DAT_0019f778)("grenade");
      (*DAT_0019f75c)();
    }
    iVar1 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar1 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x454) + 0xc0))(param_1);
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    uVar3 = 1;
  }
  return uVar3;
}


// MyTouch__9CItemSuitP11CBasePlayer  @ 00141a0c
undefined4 MyTouch__9CItemSuitP11CBasePlayer(int *param_1,int *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (*(int *)(*param_2 + 0x168) < 0) {
    uVar1 = 0;
  }
  else {
    if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
      pcVar2 = "!HEV_AAx";
    }
    else {
      pcVar2 = "!HEV_A0";
    }
    EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_2 + 0x208),pcVar2);
    *(byte *)(*param_2 + 0x16b) = *(byte *)(*param_2 + 0x16b) | 0x80;
    uVar1 = 1;
  }
  return uVar1;
}


