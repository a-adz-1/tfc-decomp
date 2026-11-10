// MyTouch__10CHealthKitP11CBasePlayer  @ 000b5fbc
void MyTouch__10CHealthKitP11CBasePlayer(void)

{
  FUN_000b5fc4();
  return;
}


// MyTouch__10CItemArmorP11CBasePlayer  @ 000f9be0
undefined4 MyTouch__10CItemArmorP11CBasePlayer(int param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  float local_14;
  
  fVar1 = *(float *)(*param_2 + 0x1bc);
  fVar2 = (float)param_2[0x3c];
  if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) ||
     ((*(int *)(*param_2 + 0x20c) == 9 && (param_2[0x37] < param_2[0x36])))) {
    local_14 = *(float *)(param_1 + 0x44c);
    fVar1 = *(float *)(*param_2 + 0x1bc);
    if (*(float *)(*param_2 + 0x1bc) < *(float *)(param_1 + 0x450)) {
      fVar1 = *(float *)(param_1 + 0x450);
    }
    fVar2 = (float)param_2[0x3b];
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar2 = fVar1;
    }
    uVar4 = CalculateBit__10CItemArmorf(param_1,fVar2);
    fVar1 = (float)param_2[0x3c];
    if (0x3f < (byte)((local_14 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(local_14) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_14 == fVar1) << 0xe) >> 8)) - 1)) {
      if (((*(int *)(*param_2 + 0x20c) == 9) && (param_2[0x37] < param_2[0x36])) &&
         (iVar5 = (int)ROUND(((float)(int)ROUND(*(float *)(param_1 + 0x44c)) - (float)param_2[0x3c])
                             + (float)param_2[0x37]), param_2[0x37] = iVar5, param_2[0x36] < iVar5))
      {
        param_2[0x37] = param_2[0x36];
      }
      local_14 = (float)param_2[0x3c];
    }
    *(float *)(*param_2 + 0x1b8) = fVar2;
    local_14 = local_14 + *(float *)(*param_2 + 0x1bc);
    fVar1 = (float)param_2[0x3c];
    if (0x3f < (byte)((fVar1 < local_14 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_14)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == local_14) << 0xe) >> 8)) - 1)) {
      fVar1 = local_14;
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
      (**(code **)(*(int *)(param_1 + 0x444) + 0xc0))(param_1);
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// MyTouch__11CItemHealthP11CBasePlayer  @ 000f99ec
undefined4 MyTouch__11CItemHealthP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1[0x114] == 1) {
    if ((*(byte *)(param_2 + 0x21) & 0x10) == 0) {
      fVar1 = *(float *)(*param_2 + 0x160);
      if ((byte)((250.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 250.0) << 0xe) >> 8)) - 1) < 0x40) {
        return 0;
      }
      iVar2 = (**(code **)(param_2[0x111] + 0x3c))(param_2,(float)param_1[0x113],0x1000000);
      if (iVar2 == 0) {
        return 0;
      }
      *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 1;
      piVar3 = (int *)CreateTimer__11CBaseEntityi(param_2,5);
      *(float *)(*piVar3 + 0x104) = *gpGlobals + 5.0;
      piVar3[3] = -0x10000;
      piVar3[4] = (int)Timer_HealthRot__11CBaseEntity;
      *(undefined4 *)(*piVar3 + 400) = *(undefined4 *)(*param_1 + 0x208);
      goto LAB_000f9b49;
    }
LAB_000f9ae5:
    if (0x50 < param_1[0x113]) {
      ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Item_medhealed",0,0,0,0);
      *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xef;
    }
  }
  else {
    iVar2 = (**(code **)(param_2[0x111] + 0x3c))(param_2,(float)param_1[0x113],0);
    if (iVar2 == 0) {
      return 0;
    }
    if ((*(byte *)(param_2 + 0x21) & 0x10) != 0) goto LAB_000f9ae5;
  }
  iVar2 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x111] + 0xc0))(param_1);
  }
LAB_000f9b49:
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return 1;
}


// MyTouch__12CItemBatteryP11CBasePlayer  @ 0013c778
undefined4 MyTouch__12CItemBatteryP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  char acStack_40 [64];
  
  iVar3 = *param_2;
  fVar1 = *(float *)(iVar3 + 0x1bc);
  if (((byte)((100.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 100.0) << 0xe) >> 8)) - 1) < 0x40) ||
     (-1 < *(int *)(iVar3 + 0x168))) {
    uVar2 = 0;
  }
  else {
    *(float *)(iVar3 + 0x1bc) = *(float *)(iVar3 + 0x1bc) + DAT_001c367c;
    fVar1 = *(float *)(*param_2 + 0x1bc);
    if (0x3f < (byte)((fVar1 < 100.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 100.0) << 0xe) >> 8)) - 1)) {
      fVar1 = 100.0;
    }
    *(float *)(*param_2 + 0x1bc) = fVar1;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/gunpickup2.wav",0x3f800000,0x3f4ccccd,0,
               100);
    (*DAT_001c10d8)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_001c10f8)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    (*DAT_001c10dc)();
    iVar3 = (int)ROUND(*(float *)(*param_2 + 0x1bc) * 100.0 * 0.01 + 0.5) / 5;
    if (0 < iVar3) {
      iVar3 = iVar3 + -1;
    }
    sprintf(acStack_40,"!HEV_%1dP",iVar3);
    SetSuitUpdate__11CBasePlayerPcii(param_2,acStack_40,0,0x1e);
    uVar2 = 1;
  }
  return uVar2;
}


// MyTouch__12CItemPowerupP11CBasePlayer  @ 000fa780
undefined4 MyTouch__12CItemPowerupP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_2 + 0x208),3,*(int *)(*param_1 + 0x1e8) + (int)gpGlobals[0x26],
             0x3f800000,0x3f4ccccd,0,100);
  param_2[0x22] = param_2[0x22] | param_1[0x22];
  fVar1 = (float)param_1[0x107];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0x107] = (int)(*gpGlobals + fVar1);
  }
  fVar1 = (float)param_1[0x10a];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0x10a] = (int)(*gpGlobals + (float)param_1[0x10a]);
  }
  fVar1 = (float)param_1[0x108];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0x108] = (int)(*gpGlobals + (float)param_1[0x108]);
  }
  fVar1 = (float)param_1[0x109];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_2[0x109] = (int)(*gpGlobals + (float)param_1[0x109]);
  }
  *(undefined4 *)(*param_2 + 0x15c) = 0;
  iVar2 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    (**(code **)(param_1[0x111] + 0xc0))(param_1);
  }
  SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  return 1;
}


// MyTouch__13CItemAntidoteP11CBasePlayer  @ 0013c674
undefined4 MyTouch__13CItemAntidoteP11CBasePlayer(undefined4 param_1,int param_2)

{
  SetSuitUpdate__11CBasePlayerPcii(param_2,&DAT_00147619,0,0x3c);
  *(int *)(param_2 + 0x6d4) = *(int *)(param_2 + 0x6d4) + 1;
  return 1;
}


// MyTouch__13CItemLongJumpP11CBasePlayer  @ 0013c408
undefined4 MyTouch__13CItemLongJumpP11CBasePlayer(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2[0x21d] == 0) {
    if (*(int *)(*param_2 + 0x168) < 0) {
      param_2[0x21d] = 1;
      (*DAT_001c10d8)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
      (*DAT_001c10f8)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      (*DAT_001c10dc)();
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


// MyTouch__13CItemSecurityP11CBasePlayer  @ 0013c594
undefined4 MyTouch__13CItemSecurityP11CBasePlayer(undefined4 param_1,int param_2)

{
  *(int *)(param_2 + 0x6d8) = *(int *)(param_2 + 0x6d8) + 1;
  return 1;
}


// MyTouch__5CItemP11CBasePlayer  @ 000b6e20
undefined4 MyTouch__5CItemP11CBasePlayer(void)

{
  return 0;
}


// MyTouch__9CItemAmmoP11CBasePlayer  @ 000fa164
undefined4 MyTouch__9CItemAmmoP11CBasePlayer(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x444) + 0x10c))(param_1,param_2);
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
      (*DAT_001c10d8)(1,gmsgItemPickup,0,*(undefined4 *)(*param_2 + 0x208));
      (*DAT_001c10f8)("grenade");
      (*DAT_001c10dc)();
    }
    iVar1 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
    if (iVar1 == 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x444) + 0xc0))(param_1);
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    uVar3 = 1;
  }
  return uVar3;
}


// MyTouch__9CItemSuitP11CBasePlayer  @ 0013ca20
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


