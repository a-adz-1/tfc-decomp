// MyTouch__10CHealthKitP11CBasePlayer  @ 000bcd10
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 MyTouch__10CHealthKitP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(param_2[0xf2] + 0x38))(param_2,_DAT_00177ac4,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    (*DAT_00175578)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175598)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    (*DAT_0017557c)();
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x1e8),3,"items/smallmedkit1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    iVar1 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar1 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(param_1[0xf2] + 0xb8))(param_1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


// MyTouch__10CItemArmorP11CBasePlayer  @ 000f5770
undefined4 MyTouch__10CItemArmorP11CBasePlayer(int param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  float local_18;
  
  if (((float)param_2[0x3c] <= *(float *)(*param_2 + 0x19c)) &&
     ((param_2[0xb] != 9 || (param_2[0x36] <= param_2[0x37])))) {
    return 0;
  }
  fVar1 = *(float *)(param_1 + 0x3d4);
  local_18 = *(float *)(param_1 + 0x3d0);
  fVar2 = (float)param_2[0x3b];
  if (fVar1 <= *(float *)(*param_2 + 0x19c)) {
    if (*(float *)(*param_2 + 0x19c) < fVar2) goto LAB_000f57f9;
  }
  else if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
LAB_000f57f9:
    if (fVar1 <= *(float *)(*param_2 + 0x19c)) {
      fVar1 = *(float *)(*param_2 + 0x19c);
    }
    goto LAB_000f5826;
  }
  fVar1 = (float)param_2[0x3b];
LAB_000f5826:
  uVar3 = CalculateBit__10CItemArmorf(param_1,fVar1);
  if ((float)param_2[0x3c] < local_18) {
    if (((param_2[0xb] == 9) && (param_2[0x37] < param_2[0x36])) &&
       (iVar4 = (int)ROUND(((float)(int)ROUND(*(float *)(param_1 + 0x3d0)) - (float)param_2[0x3c]) +
                           (float)param_2[0x37]), param_2[0x37] = iVar4, param_2[0x36] < iVar4)) {
      param_2[0x37] = param_2[0x36];
    }
    local_18 = (float)param_2[0x3c];
  }
  *(float *)(*param_2 + 0x198) = fVar1;
  local_18 = local_18 + *(float *)(*param_2 + 0x19c);
  fVar2 = (float)param_2[0x3c];
  if ((byte)(local_18 < fVar2 | (byte)((ushort)((ushort)(NAN(local_18) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_18 == fVar2) << 0xe) >> 8)) != 1) {
    local_18 = (float)param_2[0x3c];
  }
  *(float *)(*param_2 + 0x19c) = local_18;
  *(byte *)((int)param_2 + 0x8d) = *(byte *)((int)param_2 + 0x8d) & 0x1f;
  param_2[0x23] = param_2[0x23] | uVar3;
  if (0 < *(int *)(param_1 + 0x3c)) {
    param_2[0xf] = *(int *)(param_1 + 0x3c);
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_2 + 0x1e8),3,"items/armoron_1.wav",0x3f800000,0x3f4ccccd,0,100);
  iVar4 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
  if (iVar4 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0xb8))(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return 1;
}


// MyTouch__11CItemHealthP11CBasePlayer  @ 000f5560
undefined4 MyTouch__11CItemHealthP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1[0xf5] == 1) {
    if ((*(byte *)(param_2 + 0x22) & 0x10) == 0) {
      fVar1 = *(float *)(*param_2 + 0x140);
      if ((byte)((250.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 250.0) << 0xe) >> 8)) - 1) < 0x40) {
        return 0;
      }
      iVar2 = (**(code **)(param_2[0xf2] + 0x38))(param_2,(float)param_1[0xf4],0x1000000);
      if (iVar2 == 0) {
        return 0;
      }
      *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 1;
      piVar3 = (int *)CreateTimer__11CBaseEntityi(param_2,5);
      *(float *)(*piVar3 + 0xe4) = *gpGlobals + 5.0;
      piVar3[3] = -0x10000;
      piVar3[4] = (int)Timer_HealthRot__11CBaseEntity;
      *(undefined4 *)(*piVar3 + 0x170) = *(undefined4 *)(*param_1 + 0x1e8);
      goto LAB_000f56b9;
    }
LAB_000f5659:
    if (0x50 < param_1[0xf4]) {
      ClientPrint__FP9entvars_tiPCcN42(*param_2,1,"#Item_medhealed",0,0,0,0);
      *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) & 0xef;
    }
  }
  else {
    iVar2 = (**(code **)(param_2[0xf2] + 0x38))(param_2,(float)param_1[0xf4],0);
    if (iVar2 == 0) {
      return 0;
    }
    if ((*(byte *)(param_2 + 0x22) & 0x10) != 0) goto LAB_000f5659;
  }
  iVar2 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf2] + 0xb8))(param_1);
  }
LAB_000f56b9:
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return 1;
}


// MyTouch__12CItemBatteryP11CBasePlayer  @ 001258c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 MyTouch__12CItemBatteryP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  char local_44 [64];
  
  iVar3 = *param_2;
  if ((100.0 <= *(float *)(iVar3 + 0x19c)) || (-1 < *(int *)(iVar3 + 0x148))) {
    uVar2 = 0;
  }
  else {
    *(float *)(iVar3 + 0x19c) = *(float *)(iVar3 + 0x19c) + _DAT_00177abc;
    fVar1 = *(float *)(*param_2 + 0x19c);
    if ((byte)(fVar1 < 100.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 100.0) << 0xe) >> 8)) != 1) {
      fVar1 = 100.0;
    }
    *(float *)(*param_2 + 0x19c) = fVar1;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x1e8),3,"items/gunpickup2.wav",0x3f800000,0x3f4ccccd,0,
               100);
    (*DAT_00175578)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
    (*DAT_00175598)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    (*DAT_0017557c)();
    iVar3 = (int)ROUND(*(float *)(*param_2 + 0x19c) * 100.0 * 0.01 + 0.5) / 5;
    if (0 < iVar3) {
      iVar3 = iVar3 + -1;
    }
    sprintf(local_44,"!HEV_%1dP",iVar3);
    SetSuitUpdate__11CBasePlayerPcii(param_2,local_44,0,0x1e);
    uVar2 = 1;
  }
  return uVar2;
}


// MyTouch__12CItemPowerupP11CBasePlayer  @ 000f6170
undefined4 MyTouch__12CItemPowerupP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_2 + 0x1e8),3,*(int *)(*param_1 + 0x1c8) + (int)gpGlobals[0x26],
             0x3f800000,0x3f4ccccd,0,100);
  param_2[0x23] = param_2[0x23] | param_1[0x23];
  fVar1 = (float)param_1[0xe8];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    *(undefined4 *)(*param_2 + 0x13c) = 0x13;
    iVar2 = *param_2;
    *(undefined4 *)(iVar2 + 0x130) = 0x437f0000;
    *(undefined4 *)(iVar2 + 0x134) = 0x43000000;
    *(undefined4 *)(iVar2 + 0x138) = 0;
    *(undefined4 *)(*param_2 + 300) = 0x42c80000;
    param_2[0xe8] = (int)(*gpGlobals + (float)param_1[0xe8]);
  }
  fVar1 = (float)param_1[0xeb];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0xeb] = (int)(*gpGlobals + (float)param_1[0xeb]);
  }
  fVar1 = (float)param_1[0xe9];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0xe9] = (int)(*gpGlobals + (float)param_1[0xe9]);
  }
  fVar1 = (float)param_1[0xea];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    *(undefined4 *)(*param_2 + 0x13c) = 0x13;
    iVar2 = *param_2;
    *(undefined4 *)(iVar2 + 0x130) = 0x43000000;
    *(undefined4 *)(iVar2 + 0x134) = 0x43000000;
    *(undefined4 *)(iVar2 + 0x138) = 0x437f0000;
    *(undefined4 *)(*param_2 + 300) = 0x42c80000;
    param_2[0xea] = (int)(*gpGlobals + (float)param_1[0xea]);
  }
  iVar2 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf2] + 0xb8))(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return 1;
}


// MyTouch__13CItemAntidoteP11CBasePlayer  @ 00125800
undefined4 MyTouch__13CItemAntidoteP11CBasePlayer(undefined4 param_1,int param_2)

{
  SetSuitUpdate__11CBasePlayerPcii(param_2,"!HEV_DET4",0,0x3c);
  *(int *)(param_2 + 0x654) = *(int *)(param_2 + 0x654) + 1;
  return 1;
}


// MyTouch__13CItemLongJumpP11CBasePlayer  @ 00125620
undefined4 MyTouch__13CItemLongJumpP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2[0x1fc] == 0) {
    if (*(int *)(*param_2 + 0x148) < 0) {
      param_2[0x1fc] = 1;
      (*DAT_00175578)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
      (*DAT_00175598)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      (*DAT_0017557c)();
      EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_2 + 0x1e8),"!HEV_A1");
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


// MyTouch__13CItemSecurityP11CBasePlayer  @ 00125750
undefined4 MyTouch__13CItemSecurityP11CBasePlayer(undefined4 param_1,int param_2)

{
  *(int *)(param_2 + 0x658) = *(int *)(param_2 + 0x658) + 1;
  return 1;
}


// MyTouch__5CItemP11CBasePlayer  @ 000bd950
undefined4 MyTouch__5CItemP11CBasePlayer(void)

{
  return 0;
}


// MyTouch__9CItemAmmoP11CBasePlayer  @ 000f5c60
undefined4 MyTouch__9CItemAmmoP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x104))(param_1,param_2);
  iVar2 = GiveTFAmmo__11CBasePlayeriiii
                    (param_2,*(undefined4 *)(param_1 + 0xcc),*(undefined4 *)(param_1 + 0xd4),
                     *(undefined4 *)(param_1 + 0xe4),*(undefined4 *)(param_1 + 0xdc));
  if ((iVar2 == 0) && (iVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x1e8),3,"items/gunpickup2.wav",0x3f800000,0x3f4ccccd,0,
               100);
    if (iVar1 != 0) {
      (*DAT_00175578)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x1e8));
      (*DAT_00175598)("grenade");
      (*DAT_0017557c)();
    }
    iVar1 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar1 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0xb8))(param_1);
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    uVar3 = 1;
  }
  return uVar3;
}


// MyTouch__9CItemSuitP11CBasePlayer  @ 00125ab0
undefined4 MyTouch__9CItemSuitP11CBasePlayer(int *param_1,int *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (*(int *)(*param_2 + 0x148) < 0) {
    uVar1 = 0;
  }
  else {
    if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
      pcVar2 = "!HEV_AAx";
    }
    else {
      pcVar2 = "!HEV_A0";
    }
    EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_2 + 0x1e8),pcVar2);
    *(byte *)(*param_2 + 0x14b) = *(byte *)(*param_2 + 0x14b) | 0x80;
    uVar1 = 1;
  }
  return uVar1;
}


