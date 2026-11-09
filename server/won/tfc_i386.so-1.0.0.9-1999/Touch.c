// Touch__10CWeaponBoxP11CBaseEntity  @ 0011c2a0
void Touch__10CWeaponBoxP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if ((((*(byte *)(*param_1 + 0x185) & 2) != 0) && ((*(byte *)(*param_2 + 0x184) & 8) != 0)) &&
     (iVar3 = (**(code **)(param_2[0xf2] + 0x88))(param_2), iVar3 != 0)) {
    fVar1 = (float)param_1[0xf9];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0xf9];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        return;
      }
    }
    if ((*(byte *)(*param_2 + 0x160) & 1) == 0) {
      GiveTFAmmo__11CBasePlayeriiii(param_2,param_1[0x33],param_1[0x35],param_1[0x39],param_1[0x37])
      ;
      fVar1 = *(float *)(*param_1 + 0x19c);
      if ((((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
          (param_2[0xb] == 9)) && (param_2[0x37] < param_2[0x36])) {
        param_2[0x37] = (int)ROUND((float)param_2[0x37] + fVar1);
      }
      TeamFortress_CheckClassStats__11CBasePlayer(param_2);
      fVar1 = (float)param_1[0xfa];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        iVar3 = *(int *)(*param_1 + 0x170);
        if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(iVar3 + 0xd8);
        }
        if ((iVar3 != 0) &&
           (iVar4 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x28))(iVar3), iVar4 == 2)) {
          *(int *)(iVar3 + 0xce8) = *(int *)(iVar3 + 0xce8) + -1;
        }
      }
      iVar3 = 0;
      do {
        if (param_1[iVar3 + 0xfb] != 0) {
          iVar4 = param_2[0xf2];
          uVar5 = MaxAmmoCarry__Fi(param_1[iVar3 + 0xfb],0);
          (**(code **)(iVar4 + 0x60))
                    (param_2,param_1[iVar3 + 0x11b],param_1[iVar3 + 0xfb] + (int)gpGlobals[0x26],
                     uVar5);
          param_1[iVar3 + 0xfb] = 0;
          param_1[iVar3 + 0x11b] = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x20);
      iVar3 = 0;
      do {
        iVar4 = param_1[iVar3 + 0xf3];
        while (iVar4 != 0) {
          iVar4 = param_1[iVar3 + 0xf3];
          param_1[iVar3 + 0xf3] = *(int *)(iVar4 + 0x3ec);
          iVar6 = (**(code **)(param_2[0xf2] + 0x58))(param_2,iVar4);
          if (iVar6 != 0) {
            (**(code **)(*(int *)(iVar4 + 0x3c8) + 0x138))(iVar4,param_2);
          }
          iVar4 = param_1[iVar3 + 0xf3];
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 6);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_2 + 0x1e8),3,"items/ammopickup2.wav",0x3f800000,0x3f4ccccd,0
                 ,100);
      param_1[5] = 0;
      param_1[6] = 0;
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
  }
  return;
}


// Touch__10CXenPLightP11CBaseEntity  @ 0011e5a0
void Touch__10CXenPLightP11CBaseEntity(int *param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    *(float *)(*param_1 + 0x1c4) = *gpGlobals + 5.0;
    if ((param_1[0xfa] == 1) || (param_1[0xfa] == 0x13)) {
      SetActivity__13CActAnimating8Activity(param_1,0x11);
    }
  }
  return;
}


// Touch__11CBaseEntityP11CBaseEntity  @ 0010e230
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


// Touch__12CCineMonsterP11CBaseEntity  @ 000e71a0
void Touch__12CCineMonsterP11CBaseEntity(void)

{
  return;
}


// Touch__12CPlatTriggerP11CBaseEntity  @ 000d17d0
void Touch__12CPlatTriggerP11CBaseEntity(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_2[0xf2] + 0x88))(param_2);
    if (iVar1 != 0) {
      iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar1 != 0) {
        iVar1 = *(int *)(param_1 + 0x3cc);
        if (*(int *)(iVar1 + 1000) == 1) {
          (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x108))(iVar1);
        }
        else if ((*(int **)(param_1 + 0x3cc))[0xfa] == 0) {
          iVar1 = **(int **)(param_1 + 0x3cc);
          *(float *)(iVar1 + 0xe4) = *(float *)(iVar1 + 0xe0) + 1.0;
        }
      }
    }
  }
  return;
}


// Touch__12CTalkMonsterP11CBaseEntity  @ 000f21c0
void Touch__12CTalkMonsterP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  if (((*(byte *)(*param_2 + 0x184) & 8) != 0) && ((*(byte *)(param_1 + 0x5b0) & 1) == 0)) {
    iVar1 = IsTalking__12CTalkMonster(param_1);
    if (iVar1 == 0) {
      local_8 = ABS(*(float *)(*param_2 + 0x24)) + ABS(*(float *)(*param_2 + 0x20));
      if (50.0 < local_8) {
        *(byte *)(param_1 + 0x46f) = *(byte *)(param_1 + 0x46f) | 0x10;
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


// Touch__12CTriggerPushP11CBaseEntity  @ 00111d40
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
  iVar5 = *(int *)(iVar4 + 0xe8);
  if (iVar5 < 9) {
    if (6 < iVar5) {
      return;
    }
    if (iVar5 == 0) {
      return;
    }
  }
  else if (iVar5 == 0xc) {
    return;
  }
  if (((*(int *)(iVar4 + 0xec) != 0) && (*(int *)(iVar4 + 0xec) != 4)) &&
     ((iVar5 = (**(code **)(param_2[0xf2] + 0x28))(param_2), iVar5 != 2 ||
      (iVar5 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar5 != 0))
     )) {
    iVar5 = *param_1;
    if ((*(byte *)(iVar5 + 0x180) & 1) == 0) {
      iVar5 = *param_1;
      local_14 = *(float *)(iVar5 + 0x1d8);
      local_1c = local_14 * *(float *)(iVar5 + 0x44);
      local_18 = local_14 * *(float *)(iVar5 + 0x48);
      local_14 = local_14 * *(float *)(iVar5 + 0x4c);
      if ((*(byte *)(iVar4 + 0x186) & 0x40) != 0) {
        local_1c = local_1c + *(float *)(iVar4 + 0x2c);
        local_18 = local_18 + *(float *)(iVar4 + 0x30);
        local_14 = local_14 + *(float *)(iVar4 + 0x34);
      }
      *(float *)(iVar4 + 0x2c) = local_1c;
      *(float *)(iVar4 + 0x30) = local_18;
      *(float *)(iVar4 + 0x34) = local_14;
      *(byte *)(iVar4 + 0x186) = *(byte *)(iVar4 + 0x186) | 0x40;
    }
    else {
      fVar1 = *(float *)(iVar5 + 0x1d8);
      fVar2 = *(float *)(iVar5 + 0x48);
      fVar3 = *(float *)(iVar5 + 0x4c);
      *(float *)(iVar4 + 0x20) = *(float *)(iVar4 + 0x20) + fVar1 * *(float *)(iVar5 + 0x44);
      *(float *)(iVar4 + 0x24) = *(float *)(iVar4 + 0x24) + fVar1 * fVar2;
      *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) + fVar1 * fVar3;
      fVar1 = *(float *)(iVar4 + 0x28);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        *(byte *)(iVar4 + 0x185) = *(byte *)(iVar4 + 0x185) & 0xfd;
      }
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
  }
  return;
}


// Touch__15CTriggerCDAudioP11CBaseEntity  @ 001100d0
void Touch__15CTriggerCDAudioP11CBaseEntity(undefined4 param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    PlayTrack__15CTriggerCDAudio(param_1);
  }
  return;
}


// Touch__15CXenTreeTriggerP11CBaseEntity  @ 0011e860
void Touch__15CXenTreeTriggerP11CBaseEntity(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x178) != 0) {
    iVar1 = *(int *)(*param_1 + 0x178);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xd8);
    }
    (**(code **)(*(int *)(iVar1 + 0x3c8) + 0xac))(iVar1,param_2);
    return;
  }
  return;
}


// Touch__16CFuncTrackChangeP11CBaseEntity  @ 000d4840
void Touch__16CFuncTrackChangeP11CBaseEntity(void)

{
  return;
}


// Touch__19CTriggerMonsterJumpP11CBaseEntity  @ 00110030
void Touch__19CTriggerMonsterJumpP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *param_2;
  if ((*(byte *)(iVar4 + 0x184) & 0x20) != 0) {
    *(float *)(iVar4 + 0x10) = *(float *)(iVar4 + 0x10) + 1.0;
    if ((*(byte *)(iVar4 + 0x185) & 2) != 0) {
      *(byte *)(iVar4 + 0x185) = *(byte *)(iVar4 + 0x185) & 0xfd;
    }
    iVar5 = *param_1;
    fVar1 = *(float *)(iVar5 + 0x1d8);
    fVar2 = *(float *)(iVar5 + 0x48);
    fVar3 = *(float *)(iVar5 + 0x4c);
    *(float *)(iVar4 + 0x20) = fVar1 * *(float *)(iVar5 + 0x44);
    *(float *)(iVar4 + 0x24) = fVar1 * fVar2;
    *(float *)(iVar4 + 0x28) = fVar1 * fVar3;
    *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) + (float)param_1[0x10e];
    *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  }
  return;
}


// Touch__7CShowerP11CBaseEntity  @ 000b1820
void Touch__7CShowerP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x185) & 2) == 0) {
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
  if (*(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
      *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20) < 10.0) {
    *(undefined4 *)(iVar2 + 0x1d8) = 0;
  }
  return;
}


// Touch__8CXenTreeP11CBaseEntity  @ 0011eb60
void Touch__8CXenTreeP11CBaseEntity(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (((*(byte *)((int *)*param_2 + 0x61) & 8) == 0) &&
     (iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"monster_bigmomma"),
     iVar1 == 0)) {
    return;
  }
  Attack__8CXenTree(param_1);
  return;
}


// Touch__9CPendulumP11CBaseEntity  @ 0009d170
void Touch__9CPendulumP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_40;
  float local_38;
  float local_34;
  float local_30;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar3 = *param_2;
  fVar1 = *(float *)(*param_1 + 0x1c0);
  if ((0.0 < fVar1) &&
     (fVar2 = *(float *)(iVar3 + 0x14c),
     (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
    local_40 = fVar1 * *(float *)(*param_1 + 0x1d8) * 0.01;
    if (local_40 < 0.0) {
      local_40 = -local_40;
    }
    (**(code **)(param_2[0xf2] + 0x34))(param_2,*param_1,*param_1,local_40,1);
    VecBModelOrigin__FP9entvars_t(&local_38,*param_1);
    local_38 = *(float *)(iVar3 + 8) - local_38;
    local_34 = *(float *)(iVar3 + 0xc) - local_34;
    local_30 = *(float *)(iVar3 + 0x10) - local_30;
    local_18 = SQRT(local_30 * local_30 + local_34 * local_34 + local_38 * local_38);
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = local_18 * local_38;
      local_1c = local_18 * local_34;
      local_18 = local_18 * local_30;
    }
    *(float *)(iVar3 + 0x20) = local_40 * local_20;
    *(float *)(iVar3 + 0x24) = local_40 * local_1c;
    *(float *)(iVar3 + 0x28) = local_40 * local_18;
  }
  return;
}


// Touch__9CPushableP11CBaseEntity  @ 000b3950
void Touch__9CPushableP11CBaseEntity(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"worldspawn");
  if (iVar1 != 0) {
    Move__9CPushableP11CBaseEntityi(param_1,param_2,1);
  }
  return;
}


// Touch__9CXenSporeP11CBaseEntity  @ 0011f280
void Touch__9CXenSporeP11CBaseEntity(void)

{
  return;
}


