// Touch__10CWeaponBoxP11CBaseEntity  @ 0012465c
void Touch__10CWeaponBoxP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14;
  
  if ((((((*(byte *)(*param_1 + 0x1a5) & 2) != 0) && ((*(byte *)(*param_2 + 0x1a4) & 8) != 0)) &&
       (iVar2 = (**(code **)(param_2[0x115] + 0x8c))(param_2), iVar2 != 0)) &&
      ((fVar1 = (float)param_1[0x11c],
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 || (fVar1 <= *gpGlobals))
      )) && ((*(byte *)(*param_2 + 0x180) & 1) == 0)) {
    GiveTFAmmo__11CBasePlayeriiii(param_2,param_1[0x33],param_1[0x35],param_1[0x39],param_1[0x37]);
    fVar1 = *(float *)(*param_1 + 0x1bc);
    if ((((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
        (*(int *)(*param_2 + 0x20c) == 9)) && (param_2[0x37] < param_2[0x36])) {
      param_2[0x37] = (int)ROUND(fVar1 + (float)param_2[0x37]);
    }
    TeamFortress_CheckClassStats__11CBasePlayer(param_2);
    fVar1 = (float)param_1[0x11d];
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      iVar2 = *(int *)(*param_1 + 400);
      if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
      if ((iVar2 != 0) && (iVar3 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x2c))(iVar2), iVar3 == 2)
         ) {
        *(int *)(iVar2 + 0xdb4) = *(int *)(iVar2 + 0xdb4) + -1;
      }
    }
    local_14 = 0;
    do {
      if (param_1[local_14 + 0x11e] != 0) {
        iVar2 = param_2[0x115];
        uVar4 = MaxAmmoCarry__Fi(param_1[local_14 + 0x11e],0);
        (**(code **)(iVar2 + 100))
                  (param_2,param_1[local_14 + 0x13e],
                   param_1[local_14 + 0x11e] + (int)gpGlobals[0x26],uVar4);
        param_1[local_14 + 0x11e] = 0;
        param_1[local_14 + 0x13e] = 0;
      }
      local_14 = local_14 + 1;
    } while (local_14 < 0x20);
    local_14 = 0;
    do {
      iVar2 = param_1[local_14 + 0x116];
      while (iVar2 != 0) {
        iVar2 = param_1[local_14 + 0x116];
        param_1[local_14 + 0x116] = *(int *)(iVar2 + 0x478);
        iVar3 = (**(code **)(param_2[0x115] + 0x5c))(param_2,iVar2);
        if (iVar3 != 0) {
          (**(code **)(*(int *)(iVar2 + 0x454) + 0x140))(iVar2,param_2);
        }
        iVar2 = param_1[local_14 + 0x116];
      }
      local_14 = local_14 + 1;
    } while (local_14 < 6);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),3,"items/ammopickup2.wav",0x3f800000,0x3f4ccccd,0,
               100);
    param_1[5] = 0;
    param_1[6] = 0;
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Touch__10CXenPLightP11CBaseEntity  @ 00129abc
void Touch__10CXenPLightP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    *(float *)(*param_1 + 0x1e4) = *gpGlobals + 5.0;
    if ((param_1[0x11d] == 1) || (param_1[0x11d] == 0x13)) {
      iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x11);
      if (iVar1 != -1) {
        *(int *)(*param_1 + 0x128) = iVar1;
        param_1[0x11d] = 0x11;
        *(undefined4 *)(*param_1 + 0x130) = 0;
        ResetSequenceInfo__14CBaseAnimating(param_1);
      }
    }
  }
  return;
}


// Touch__11CBaseEntityP11CBaseEntity  @ 00112c94
void Touch__11CBaseEntityP11CBaseEntity(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (*(short *)(param_1 + 0x16) != 0) {
    if (*(short *)(param_1 + 0x16) < 1) {
      pcVar1 = *(code **)(param_1 + 0x18);
    }
    else {
      pcVar1 = *(code **)(*(int *)(*(short *)(param_1 + 0x18) + param_1) + -4 +
                         *(short *)(param_1 + 0x16) * 4);
    }
    (*pcVar1)(*(short *)(param_1 + 0x14) + param_1,param_2);
  }
  return;
}


// Touch__12CCineMonsterP11CBaseEntity  @ 000eb5b4
void Touch__12CCineMonsterP11CBaseEntity(void)

{
  return;
}


// Touch__12CPlatTriggerP11CBaseEntity  @ 000d2d0c
void Touch__12CPlatTriggerP11CBaseEntity(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
  if (iVar2 == 0) {
    iVar2 = (**(code **)(param_2[0x115] + 0x8c))(param_2);
    if (iVar2 != 0) {
      iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar2 != 0) {
        piVar1 = *(int **)(param_1 + 0x458);
        if (piVar1[0x11d] == 1) {
          (**(code **)(piVar1[0x115] + 0x110))(piVar1);
        }
        else if (piVar1[0x11d] == 0) {
          *(float *)(*piVar1 + 0x104) = *(float *)(*piVar1 + 0x100) + 1.0;
        }
      }
    }
  }
  return;
}


// Touch__12CTalkMonsterP11CBaseEntity  @ 000f8e7c
void Touch__12CTalkMonsterP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  if (((*(byte *)(*param_2 + 0x1a4) & 8) != 0) && ((*(byte *)(param_1 + 0x63c) & 1) == 0)) {
    iVar1 = IsTalking__12CTalkMonster(param_1);
    if (iVar1 == 0) {
      local_8 = ABS(*(float *)(*param_2 + 0x24)) + ABS(*(float *)(*param_2 + 0x20));
      if (0x3f < (byte)((local_8 < 50.0 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_8 == 50.0) << 0xe) >> 8)) - 1)) {
        *(byte *)(param_1 + 0x4fb) = *(byte *)(param_1 + 0x4fb) | 0x10;
        iVar1 = *param_2;
        local_14 = *(undefined4 *)(iVar1 + 8);
        local_10 = *(undefined4 *)(iVar1 + 0xc);
        local_c = *(undefined4 *)(iVar1 + 0x10);
        MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_14);
      }
    }
  }
  return;
}


// Touch__12CTriggerPushP11CBaseEntity  @ 0011664c
void Touch__12CTriggerPushP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float local_1c;
  float local_18;
  float local_14;
  
  iVar4 = *param_2;
  switch(*(undefined4 *)(iVar4 + 0x108)) {
  case 0:
  case 7:
  case 8:
  case 0xc:
    break;
  default:
    if (((*(int *)(iVar4 + 0x10c) != 0) && (*(int *)(iVar4 + 0x10c) != 4)) &&
       ((iVar5 = (**(code **)(param_2[0x115] + 0x2c))(param_2), iVar5 != 2 ||
        (iVar5 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar5 != 0
        )))) {
      iVar5 = *param_1;
      if ((*(byte *)(iVar5 + 0x1a0) & 1) == 0) {
        local_14 = *(float *)(iVar5 + 0x1f8);
        local_1c = *(float *)(iVar5 + 0x44) * local_14;
        local_18 = *(float *)(iVar5 + 0x48) * local_14;
        local_14 = local_14 * *(float *)(iVar5 + 0x4c);
        if ((*(byte *)(iVar4 + 0x1a6) & 0x40) != 0) {
          local_1c = local_1c + *(float *)(iVar4 + 0x2c);
          local_18 = local_18 + *(float *)(iVar4 + 0x30);
          local_14 = local_14 + *(float *)(iVar4 + 0x34);
        }
        *(float *)(iVar4 + 0x2c) = local_1c;
        *(float *)(iVar4 + 0x30) = local_18;
        *(float *)(iVar4 + 0x34) = local_14;
        *(byte *)(iVar4 + 0x1a6) = *(byte *)(iVar4 + 0x1a6) | 0x40;
      }
      else {
        fVar1 = *(float *)(iVar5 + 0x1f8);
        fVar2 = *(float *)(iVar5 + 0x48);
        fVar3 = *(float *)(iVar5 + 0x4c);
        *(float *)(iVar4 + 0x20) = *(float *)(iVar5 + 0x44) * fVar1 + *(float *)(iVar4 + 0x20);
        *(float *)(iVar4 + 0x24) = fVar2 * fVar1 + *(float *)(iVar4 + 0x24);
        *(float *)(iVar4 + 0x28) = fVar1 * fVar3 + *(float *)(iVar4 + 0x28);
        if (0.0 < *(float *)(iVar4 + 0x28)) {
          *(byte *)(iVar4 + 0x1a5) = *(byte *)(iVar4 + 0x1a5) & 0xfd;
        }
        UTIL_Remove__FP11CBaseEntity(param_1);
      }
    }
  }
  return;
}


// Touch__15CTriggerCDAudioP11CBaseEntity  @ 001193ec
void Touch__15CTriggerCDAudioP11CBaseEntity(undefined4 param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    PlayTrack__15CTriggerCDAudio(param_1);
  }
  return;
}


// Touch__15CXenTreeTriggerP11CBaseEntity  @ 00129800
void Touch__15CXenTreeTriggerP11CBaseEntity(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x198) != 0) {
    iVar1 = *(int *)(*(int *)(*param_1 + 0x198) + 0x7c);
    (**(code **)(*(int *)(iVar1 + 0x454) + 0xb4))(iVar1,param_2);
  }
  return;
}


// Touch__16CFuncTrackChangeP11CBaseEntity  @ 000d1da0
void Touch__16CFuncTrackChangeP11CBaseEntity(void)

{
  return;
}


// Touch__19CTriggerMonsterJumpP11CBaseEntity  @ 001194ac
void Touch__19CTriggerMonsterJumpP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = *param_2;
  uVar5 = *(uint *)(iVar4 + 0x1a4);
  if ((uVar5 & 0x20) != 0) {
    *(float *)(iVar4 + 0x10) = *(float *)(iVar4 + 0x10) + 1.0;
    if ((uVar5 & 0x200) != 0) {
      *(uint *)(iVar4 + 0x1a4) = uVar5 & 0xfffffdff;
    }
    iVar6 = *param_1;
    fVar1 = *(float *)(iVar6 + 0x1f8);
    fVar2 = *(float *)(iVar6 + 0x48);
    fVar3 = *(float *)(iVar6 + 0x4c);
    *(float *)(iVar4 + 0x20) = *(float *)(iVar6 + 0x44) * fVar1;
    *(float *)(iVar4 + 0x24) = fVar2 * fVar1;
    *(float *)(iVar4 + 0x28) = fVar1 * fVar3;
    *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) + (float)param_1[0x131];
    *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


// Touch__7CShowerP11CBaseEntity  @ 000a77d0
void Touch__7CShowerP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a5) & 2) == 0) {
    fVar1 = 0.6;
  }
  else {
    fVar1 = 0.1;
  }
  *(float *)(iVar2 + 0x20) = *(float *)(iVar2 + 0x20) * fVar1;
  *(float *)(iVar2 + 0x24) = *(float *)(iVar2 + 0x24) * fVar1;
  *(float *)(iVar2 + 0x28) = fVar1 * *(float *)(iVar2 + 0x28);
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
          *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20);
  if (0x3f < (byte)((10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(iVar2 + 0x1f8) = 0;
  }
  return;
}


// Touch__8CXenTreeP11CBaseEntity  @ 00129590
void Touch__8CXenTreeP11CBaseEntity(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (((*(byte *)((int *)*param_2 + 0x69) & 8) == 0) &&
     (iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"monster_bigmomma"),
     iVar1 == 0)) {
    return;
  }
  Attack__8CXenTree(param_1);
  return;
}


// Touch__9CPendulumP11CBaseEntity  @ 000892c4
void Touch__9CPendulumP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar3 = *param_1;
  iVar4 = *param_2;
  fVar1 = *(float *)(iVar3 + 0x1e0);
  if ((0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) &&
     (fVar2 = *(float *)(iVar4 + 0x16c),
     (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
    fVar1 = fVar1 * *(float *)(iVar3 + 0x1f8) * 0.01;
    if (fVar1 < 0.0) {
      fVar1 = -fVar1;
    }
    (**(code **)(param_2[0x115] + 0x38))(param_2,iVar3,iVar3,fVar1,1);
    iVar3 = *param_1;
    local_20 = *(float *)(iVar4 + 8) - (*(float *)(iVar3 + 0xf4) * 0.5 + *(float *)(iVar3 + 0xc4));
    local_1c = *(float *)(iVar4 + 0xc) - (*(float *)(iVar3 + 0xf8) * 0.5 + *(float *)(iVar3 + 200));
    fVar2 = *(float *)(iVar4 + 0x10) - (*(float *)(iVar3 + 0xfc) * 0.5 + *(float *)(iVar3 + 0xcc));
    local_18 = SQRT(fVar2 * fVar2 + local_1c * local_1c + local_20 * local_20);
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = local_20 * local_18;
      local_1c = local_1c * local_18;
      local_18 = local_18 * fVar2;
    }
    *(float *)(iVar4 + 0x20) = local_20 * fVar1;
    *(float *)(iVar4 + 0x24) = local_1c * fVar1;
    *(float *)(iVar4 + 0x28) = local_18 * fVar1;
  }
  return;
}


// Touch__9CPushableP11CBaseEntity  @ 000a9450
void Touch__9CPushableP11CBaseEntity(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"worldspawn");
  if (iVar1 != 0) {
    Move__9CPushableP11CBaseEntityi(param_1,param_2,1);
  }
  return;
}


// Touch__9CXenSporeP11CBaseEntity  @ 00128e70
void Touch__9CXenSporeP11CBaseEntity(void)

{
  return;
}


