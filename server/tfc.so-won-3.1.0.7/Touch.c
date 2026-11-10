// Touch__10CWeaponBoxP11CBaseEntity  @ 001212d8
void Touch__10CWeaponBoxP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  int local_14;
  
  if ((((*(byte *)(*param_1 + 0x1a5) & 2) != 0) && ((*(byte *)(*param_2 + 0x1a4) & 8) != 0)) &&
     (iVar4 = (**(code **)(param_2[0x111] + 0x8c))(param_2), iVar4 != 0)) {
    fVar1 = (float)param_1[0x118];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x118];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        return;
      }
    }
    if ((*(byte *)(*param_2 + 0x180) & 1) == 0) {
      GiveTFAmmo__11CBasePlayeriiii(param_2,param_1[0x33],param_1[0x35],param_1[0x39],param_1[0x37])
      ;
      fVar1 = *(float *)(*param_1 + 0x1bc);
      if ((((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
          (*(int *)(*param_2 + 0x20c) == 9)) && (param_2[0x37] < param_2[0x36])) {
        param_2[0x37] = (int)ROUND((float)param_2[0x37] + fVar1);
      }
      TeamFortress_CheckClassStats__11CBasePlayer(param_2);
      fVar1 = (float)param_1[0x119];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        iVar4 = *(int *)(*param_1 + 400);
        if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(iVar4 + 0x7c);
        }
        if ((iVar4 != 0) &&
           (iVar5 = (**(code **)(*(int *)(iVar4 + 0x444) + 0x2c))(iVar4), iVar5 == 2)) {
          *(int *)(iVar4 + 0xd98) = *(int *)(iVar4 + 0xd98) + -1;
        }
      }
      local_14 = 0;
      piVar7 = param_1 + 0x13a;
      piVar8 = param_1 + 0x11a;
      do {
        if (*piVar8 != 0) {
          iVar4 = param_2[0x111];
          uVar6 = MaxAmmoCarry__Fi(*piVar8,0);
          (**(code **)(iVar4 + 100))(param_2,*piVar7,*piVar8 + (int)gpGlobals[0x26],uVar6);
          *piVar8 = 0;
          *piVar7 = 0;
        }
        if (piVar8[1] != 0) {
          iVar4 = param_2[0x111];
          uVar6 = MaxAmmoCarry__Fi(piVar8[1],0);
          (**(code **)(iVar4 + 100))(param_2,piVar7[1],piVar8[1] + (int)gpGlobals[0x26],uVar6);
          piVar8[1] = 0;
          piVar7[1] = 0;
        }
        piVar7 = piVar7 + 2;
        piVar8 = piVar8 + 2;
        local_14 = local_14 + 2;
      } while (local_14 < 0x20);
      local_14 = 0;
      piVar7 = param_1 + 0x112;
      iVar4 = 0;
      do {
        iVar3 = *piVar7;
        iVar5 = iVar4;
        while (iVar3 != 0) {
          iVar3 = *(int *)((int)param_1 + iVar5 + 0x448);
          *(undefined4 *)((int)param_1 + iVar5 + 0x448) = *(undefined4 *)(iVar3 + 0x468);
          iVar5 = (**(code **)(param_2[0x111] + 0x5c))(param_2,iVar3);
          if (iVar5 != 0) {
            (**(code **)(*(int *)(iVar3 + 0x444) + 0x140))(iVar3,param_2);
          }
          iVar5 = local_14 * 4;
          iVar3 = param_1[local_14 + 0x112];
        }
        iVar5 = iVar4 + 4;
        iVar3 = piVar7[1];
        while (iVar3 != 0) {
          iVar3 = *(int *)((int)param_1 + iVar5 + 0x448);
          *(undefined4 *)((int)param_1 + iVar5 + 0x448) = *(undefined4 *)(iVar3 + 0x468);
          iVar5 = (**(code **)(param_2[0x111] + 0x5c))(param_2,iVar3);
          if (iVar5 != 0) {
            (**(code **)(*(int *)(iVar3 + 0x444) + 0x140))(iVar3,param_2);
          }
          iVar5 = (local_14 + 1) * 4;
          iVar3 = param_1[local_14 + 0x113];
        }
        piVar7 = piVar7 + 2;
        iVar4 = iVar4 + 8;
        local_14 = local_14 + 2;
      } while (local_14 < 6);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_2 + 0x208),3,"items/ammopickup2.wav",0x3f800000,0x3f4ccccd,0
                 ,100);
      param_1[5] = 0;
      param_1[6] = 0;
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
  }
  return;
}


// Touch__10CXenPLightP11CBaseEntity  @ 00124404
void Touch__10CXenPLightP11CBaseEntity(int *param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    *(float *)(*param_1 + 0x1e4) = *gpGlobals + 5.0;
    if ((param_1[0x119] == 1) || (param_1[0x119] == 0x13)) {
      SetActivity__13CActAnimating8Activity(param_1,0x11);
    }
  }
  return;
}


// Touch__11CBaseEntityP11CBaseEntity  @ 0010f7cc
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


// Touch__12CCineMonsterP11CBaseEntity  @ 000e8120
void Touch__12CCineMonsterP11CBaseEntity(void)

{
  return;
}


// Touch__12CPlatTriggerP11CBaseEntity  @ 000cdc74
void Touch__12CPlatTriggerP11CBaseEntity(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_2[0x111] + 0x8c))(param_2);
    if (iVar1 != 0) {
      iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar1 != 0) {
        iVar1 = *(int *)(param_1 + 0x448);
        if (*(int *)(iVar1 + 0x464) == 1) {
          (**(code **)(*(int *)(iVar1 + 0x444) + 0x110))(iVar1);
        }
        else if ((*(int **)(param_1 + 0x448))[0x119] == 0) {
          iVar1 = **(int **)(param_1 + 0x448);
          *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + 1.0;
        }
      }
    }
  }
  return;
}


// Touch__12CTalkMonsterP11CBaseEntity  @ 000f5a58
void Touch__12CTalkMonsterP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  if (((*(byte *)(*param_2 + 0x1a4) & 8) != 0) && ((*(byte *)(param_1 + 0x62c) & 1) == 0)) {
    iVar1 = IsTalking__12CTalkMonster(param_1);
    if (iVar1 == 0) {
      local_4 = ABS(*(float *)(*param_2 + 0x24)) + ABS(*(float *)(*param_2 + 0x20));
      if (0x3f < (byte)((local_4 < 50.0 | (byte)((ushort)((ushort)NAN(local_4) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_4 == 50.0) << 0xe) >> 8)) - 1)) {
        *(byte *)(param_1 + 0x4eb) = *(byte *)(param_1 + 0x4eb) | 0x10;
        iVar1 = *param_2;
        local_10 = *(undefined4 *)(iVar1 + 8);
        local_c = *(undefined4 *)(iVar1 + 0xc);
        local_8 = *(undefined4 *)(iVar1 + 0x10);
        MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_10);
      }
    }
  }
  return;
}


// Touch__12CTriggerPushP11CBaseEntity  @ 00113f3c
void Touch__12CTriggerPushP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float local_18;
  float local_14;
  float local_10;
  
  iVar4 = *param_2;
  switch(*(undefined4 *)(iVar4 + 0x108)) {
  case 0:
  case 7:
  case 8:
  case 0xc:
    break;
  default:
    if (((*(int *)(iVar4 + 0x10c) != 0) && (*(int *)(iVar4 + 0x10c) != 4)) &&
       ((iVar5 = (**(code **)(param_2[0x111] + 0x2c))(param_2), iVar5 != 2 ||
        (iVar5 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar5 != 0
        )))) {
      iVar5 = *param_1;
      if ((*(byte *)(iVar5 + 0x1a0) & 1) == 0) {
        iVar5 = *param_1;
        local_10 = *(float *)(iVar5 + 0x1f8);
        local_18 = local_10 * *(float *)(iVar5 + 0x44);
        local_14 = local_10 * *(float *)(iVar5 + 0x48);
        local_10 = local_10 * *(float *)(iVar5 + 0x4c);
        if ((*(byte *)(iVar4 + 0x1a6) & 0x40) != 0) {
          local_18 = local_18 + *(float *)(iVar4 + 0x2c);
          local_14 = local_14 + *(float *)(iVar4 + 0x30);
          local_10 = local_10 + *(float *)(iVar4 + 0x34);
        }
        *(float *)(iVar4 + 0x2c) = local_18;
        *(float *)(iVar4 + 0x30) = local_14;
        *(float *)(iVar4 + 0x34) = local_10;
        *(byte *)(iVar4 + 0x1a6) = *(byte *)(iVar4 + 0x1a6) | 0x40;
      }
      else {
        fVar1 = *(float *)(iVar5 + 0x1f8);
        fVar2 = *(float *)(iVar5 + 0x48);
        fVar3 = *(float *)(iVar5 + 0x4c);
        *(float *)(iVar4 + 0x20) = *(float *)(iVar4 + 0x20) + fVar1 * *(float *)(iVar5 + 0x44);
        *(float *)(iVar4 + 0x24) = *(float *)(iVar4 + 0x24) + fVar1 * fVar2;
        *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) + fVar1 * fVar3;
        if (0.0 < *(float *)(iVar4 + 0x28)) {
          *(byte *)(iVar4 + 0x1a5) = *(byte *)(iVar4 + 0x1a5) & 0xfd;
        }
        UTIL_Remove__FP11CBaseEntity(param_1);
      }
    }
  }
  return;
}


// Touch__15CTriggerCDAudioP11CBaseEntity  @ 00111c94
void Touch__15CTriggerCDAudioP11CBaseEntity(undefined4 param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    PlayTrack__15CTriggerCDAudio(param_1);
  }
  return;
}


// Touch__15CXenTreeTriggerP11CBaseEntity  @ 00124724
void Touch__15CXenTreeTriggerP11CBaseEntity(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x198) != 0) {
    iVar1 = *(int *)(*param_1 + 0x198);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x7c);
    }
    (**(code **)(*(int *)(iVar1 + 0x444) + 0xb4))(iVar1,param_2);
    return;
  }
  return;
}


// Touch__16CFuncTrackChangeP11CBaseEntity  @ 000d134c
void Touch__16CFuncTrackChangeP11CBaseEntity(void)

{
  return;
}


// Touch__19CTriggerMonsterJumpP11CBaseEntity  @ 00111bd4
void Touch__19CTriggerMonsterJumpP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *param_2;
  if ((*(byte *)(iVar4 + 0x1a4) & 0x20) != 0) {
    *(float *)(iVar4 + 0x10) = *(float *)(iVar4 + 0x10) + 1.0;
    if ((*(byte *)(iVar4 + 0x1a5) & 2) != 0) {
      *(byte *)(iVar4 + 0x1a5) = *(byte *)(iVar4 + 0x1a5) & 0xfd;
    }
    iVar5 = *param_1;
    fVar1 = *(float *)(iVar5 + 0x1f8);
    fVar2 = *(float *)(iVar5 + 0x48);
    fVar3 = *(float *)(iVar5 + 0x4c);
    *(float *)(iVar4 + 0x20) = fVar1 * *(float *)(iVar5 + 0x44);
    *(float *)(iVar4 + 0x24) = fVar1 * fVar2;
    *(float *)(iVar4 + 0x28) = fVar1 * fVar3;
    *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) + (float)param_1[0x12d];
    *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


// Touch__7CShowerP11CBaseEntity  @ 000a74d4
void Touch__7CShowerP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a5) & 2) == 0) {
    iVar2 = *param_1;
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


// Touch__8CXenTreeP11CBaseEntity  @ 00124ad4
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


// Touch__9CPendulumP11CBaseEntity  @ 0008a274
void Touch__9CPendulumP11CBaseEntity(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar3 = *param_2;
  fVar1 = *(float *)((int)*param_1 + 0x1e0);
  if ((0.0 < fVar1) &&
     (fVar2 = *(float *)(iVar3 + 0x16c),
     (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
    local_3c = fVar1 * *(float *)((int)*param_1 + 0x1f8) * 0.01;
    if (0x3f < (byte)((0.0 < local_3c | (byte)((ushort)((ushort)NAN(local_3c) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_3c == 0.0) << 0xe) >> 8)) - 1)) {
      local_3c = -local_3c;
    }
    (**(code **)(param_2[0x111] + 0x38))(param_2,*param_1,*param_1,local_3c,1);
    fVar1 = *param_1;
    VecBModelOrigin__FP9entvars_s(&local_34,fVar1);
    local_20 = *(float *)(iVar3 + 8) - local_38;
    local_34 = *(float *)(iVar3 + 0xc) - local_34;
    local_30 = *(float *)(iVar3 + 0x10) - local_30;
    local_18 = SQRT(local_30 * local_30 + local_34 * local_34 + local_20 * local_20);
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = local_18 * local_20;
      local_1c = local_18 * local_34;
      local_18 = local_18 * local_30;
    }
    *(float *)(iVar3 + 0x20) = fVar1 * local_20;
    *(float *)(iVar3 + 0x24) = fVar1 * local_1c;
    *(float *)(iVar3 + 0x28) = fVar1 * local_18;
  }
  return;
}


// Touch__9CPushableP11CBaseEntity  @ 000a9f98
void Touch__9CPushableP11CBaseEntity(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"worldspawn");
  if (iVar1 != 0) {
    Move__9CPushableP11CBaseEntityi(param_1,param_2,1);
  }
  return;
}


// Touch__9CXenSporeP11CBaseEntity  @ 00125698
void Touch__9CXenSporeP11CBaseEntity(void)

{
  return;
}


