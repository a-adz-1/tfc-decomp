// MyTouch__10CHealthKitP11CBasePlayer  @ 000aaf1c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 MyTouch__10CHealthKitP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(param_2[0xf5] + 0x38))(param_2,_DAT_001aa4a4,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    (*DAT_001a7ef8)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f18)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    (*DAT_001a7efc)();
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/smallmedkit1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    iVar1 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar1 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(param_1[0xf5] + 0xb8))(param_1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


// MyTouch__10CItemArmorP11CBasePlayer  @ 000eccd8
undefined4 MyTouch__10CItemArmorP11CBasePlayer(int param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  float fStack_14;
  
  fVar1 = *(float *)(*param_2 + 0x1bc);
  fVar2 = (float)param_2[0x3c];
  if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) ||
     ((*(int *)(*param_2 + 0x20c) == 9 && (param_2[0x37] < param_2[0x36])))) {
    fStack_14 = *(float *)(param_1 + 0x3dc);
    fVar1 = *(float *)(*param_2 + 0x1bc);
    if (*(float *)(*param_2 + 0x1bc) < *(float *)(param_1 + 0x3e0)) {
      fVar1 = *(float *)(param_1 + 0x3e0);
    }
    fVar2 = (float)param_2[0x3b];
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar2 = fVar1;
    }
    uVar4 = CalculateBit__10CItemArmorf(param_1,fVar2);
    fVar1 = (float)param_2[0x3c];
    if (0x3f < (byte)((fStack_14 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fStack_14) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fStack_14 == fVar1) << 0xe) >> 8)) - 1)) {
      if (((*(int *)(*param_2 + 0x20c) == 9) && (param_2[0x37] < param_2[0x36])) &&
         (iVar5 = (int)ROUND(((float)(int)ROUND(*(float *)(param_1 + 0x3dc)) - (float)param_2[0x3c])
                             + (float)param_2[0x37]), param_2[0x37] = iVar5, param_2[0x36] < iVar5))
      {
        param_2[0x37] = param_2[0x36];
      }
      fStack_14 = (float)param_2[0x3c];
    }
    *(float *)(*param_2 + 0x1b8) = fVar2;
    fStack_14 = fStack_14 + *(float *)(*param_2 + 0x1bc);
    fVar1 = (float)param_2[0x3c];
    if (0x3f < (byte)((fVar1 < fStack_14 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fStack_14)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fStack_14) << 0xe) >> 8)) - 1)) {
      fVar1 = fStack_14;
    }
    *(float *)(*param_2 + 0x1bc) = fVar1;
    *(byte *)((int)param_2 + 0x89) = *(byte *)((int)param_2 + 0x89) & 0x1f;
    param_2[0x22] = param_2[0x22] | uVar4;
    if (0 < *(int *)(param_1 + 0x38)) {
      param_2[0xe] = *(int *)(param_1 + 0x38);
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/armoron_1.wav",0x3f800000,0x3f4ccccd,0,100
              );
    iVar5 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar5 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0xb8))(param_1);
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// MyTouch__11CItemHealthP11CBasePlayer  @ 000ecae4
void MyTouch__11CItemHealthP11CBasePlayer(void)

{
  FUN_000ecaec();
  return;
}


// MyTouch__12CItemBatteryP11CBasePlayer  @ 0012c0a8
undefined4 MyTouch__12CItemBatteryP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  char local_40 [64];
  
  iVar3 = *param_2;
  fVar1 = *(float *)(iVar3 + 0x1bc);
  if (((byte)((100.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 100.0) << 0xe) >> 8)) - 1) < 0x40) ||
     (-1 < *(int *)(iVar3 + 0x168))) {
    uVar2 = 0;
  }
  else {
    *(float *)(iVar3 + 0x1bc) = *(float *)(iVar3 + 0x1bc) + DAT_001aa49c;
    fVar1 = *(float *)(*param_2 + 0x1bc);
    if (0x3f < (byte)((fVar1 < 100.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 100.0) << 0xe) >> 8)) - 1)) {
      fVar1 = 100.0;
    }
    *(float *)(*param_2 + 0x1bc) = fVar1;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/gunpickup2.wav",0x3f800000,0x3f4ccccd,0,
               100);
    (*DAT_001a7ef8)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001a7f18)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    (*DAT_001a7efc)();
    iVar3 = (int)ROUND(*(float *)(*param_2 + 0x1bc) * 100.0 * 0.01 + 0.5) / 5;
    if (0 < iVar3) {
      iVar3 = iVar3 + -1;
    }
    sprintf(local_40,"!HEV_%1dP",iVar3);
    SetSuitUpdate__11CBasePlayerPcii(param_2,local_40,0,0x1e);
    uVar2 = 1;
  }
  return uVar2;
}


// MyTouch__12CItemPowerupP11CBasePlayer  @ 000ed878
undefined4 MyTouch__12CItemPowerupP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_2 + 0x208),3,*(int *)(*param_1 + 0x1e8) + (int)gpGlobals[0x26],
             0x3f800000,0x3f4ccccd,0,100);
  param_2[0x22] = param_2[0x22] | param_1[0x22];
  fVar1 = (float)param_1[0xeb];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0xeb] = (int)(*gpGlobals + fVar1);
  }
  fVar1 = (float)param_1[0xee];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0xee] = (int)(*gpGlobals + (float)param_1[0xee]);
  }
  fVar1 = (float)param_1[0xec];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0xec] = (int)(*gpGlobals + (float)param_1[0xec]);
  }
  fVar1 = (float)param_1[0xed];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0xed] = (int)(*gpGlobals + (float)param_1[0xed]);
  }
  *(undefined4 *)(*param_2 + 0x15c) = 0;
  iVar2 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0xf5] + 0xb8))(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return 1;
}


// MyTouch__13CItemAntidoteP11CBasePlayer  @ 0012bfc4
undefined4 MyTouch__13CItemAntidoteP11CBasePlayer(undefined4 param_1,int param_2)

{
  SetSuitUpdate__11CBasePlayerPcii(param_2,"!HEV_DET4",0,0x3c);
  *(int *)(param_2 + 0x664) = *(int *)(param_2 + 0x664) + 1;
  return 1;
}


// MyTouch__13CItemLongJumpP11CBasePlayer  @ 0012bd98
undefined4 MyTouch__13CItemLongJumpP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2[0x201] == 0) {
    if (*(int *)(*param_2 + 0x168) < 0) {
      param_2[0x201] = 1;
      (*DAT_001a7ef8)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
      (*DAT_001a7f18)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      (*DAT_001a7efc)();
      EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_2 + 0x208),&UNK_00136d8f);
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


// MyTouch__13CItemSecurityP11CBasePlayer  @ 0012bf04
undefined4 MyTouch__13CItemSecurityP11CBasePlayer(undefined4 param_1,int param_2)

{
  *(int *)(param_2 + 0x668) = *(int *)(param_2 + 0x668) + 1;
  return 1;
}


// MyTouch__5CItemP11CBasePlayer  @ 000abd20
undefined4 MyTouch__5CItemP11CBasePlayer(void)

{
  return 0;
}


// MyTouch__9CItemAmmoP11CBasePlayer  @ 000ed25c
undefined4 MyTouch__9CItemAmmoP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x104))(param_1,param_2);
  iVar2 = GiveTFAmmo__11CBasePlayeriiii
                    (param_2,*(undefined4 *)(param_1 + 0xcc),*(undefined4 *)(param_1 + 0xd4),
                     *(undefined4 *)(param_1 + 0xe4),*(undefined4 *)(param_1 + 0xdc));
  if ((iVar2 == 0) && (iVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,FUN_0013de20,0x3f800000,0x3f4ccccd,0,100);
    if (iVar1 != 0) {
      (*DAT_001a7ef8)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
      (*DAT_001a7f18)("grenade");
      (*DAT_001a7efc)();
    }
    iVar1 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar1 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0xb8))(param_1);
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    uVar3 = 1;
  }
  return uVar3;
}


// MyTouch__9CItemSuitP11CBasePlayer  @ 0012c330
undefined4 MyTouch__9CItemSuitP11CBasePlayer(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if (*(int *)(*param_2 + 0x168) < 0) {
    uVar1 = 0;
  }
  else {
    if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
      puVar2 = &UNK_00136d06;
    }
    else {
      puVar2 = &UNK_00136cfe;
    }
    EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_2 + 0x208),puVar2);
    *(byte *)(*param_2 + 0x16b) = *(byte *)(*param_2 + 0x16b) | 0x80;
    uVar1 = 1;
  }
  return uVar1;
}


