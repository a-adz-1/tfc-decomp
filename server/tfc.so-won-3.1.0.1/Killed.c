// Killed__11CBaseEntityP9entvars_si  @ 00086bec
void Killed__11CBaseEntityP9entvars_si(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  *(undefined4 *)(*param_1 + 0x170) = 2;
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Killed__11CBasePlayerP9entvars_si  @ 000c9f40
void Killed__11CBasePlayerP9entvars_si(int *param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  float fVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  longdouble lVar7;
  
  (*DAT_001a7ef8)(5,0x17,*param_1 + 8,0);
  (*DAT_001a7f00)(0x7d);
  uVar3 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(uVar3);
  (*DAT_001a7efc)();
  if (param_1[0x211] != 0) {
    (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x120))(param_1[0x211],0);
  }
  (**(code **)(*g_pGameRules + 0x74))(g_pGameRules,param_1,param_2,g_pevLastInflictor);
  piVar6 = param_1 + 0x1fd;
  iVar4 = __opP11CBaseEntity__7EHANDLE(piVar6);
  if (iVar4 != 0) {
    iVar4 = __rf__7EHANDLE(piVar6);
    (**(code **)(*(int *)(iVar4 + 0x3d4) + 0xb0))(iVar4,param_1,param_1,0,0);
    __as__7EHANDLEP11CBaseEntity(piVar6,0);
  }
  uVar5 = ClientSoundIndex__9CSoundEntP7edict_s(*(undefined4 *)(*param_1 + 0x208));
  iVar4 = SoundPointerForIndex__9CSoundEnti(uVar5);
  if (iVar4 != 0) {
    Reset__6CSound(iVar4);
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,4);
  *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xf7;
  param_1[0xec] = 0;
  param_1[0xeb] = 0;
  param_1[0xed] = 0;
  param_1[0xee] = 0;
  *(undefined4 *)(*param_1 + 0xb4) = g_ulModelIndexPlayer;
  if ((((*(byte *)(param_1 + 0x21) & 0x10) != 0) &&
      (*(int *)(*param_1 + 0x208) == *(int *)(*param_1 + 400))) &&
     (piVar6 = (int *)FindTimer__11CBaseEntityi(param_1,2), piVar6 != (int *)0x0)) {
    iVar4 = *(int *)(*piVar6 + 400);
    if ((iVar4 == 0) && (iVar4 = (*DAT_001a7f54)(0), iVar4 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar4 + 0x7c);
    }
    TF_AddFrags__11CBasePlayeri(uVar5,1);
  }
  TeamFortress_RemoveTimers__11CBasePlayer(param_1);
  ResetMenu__11CBasePlayer(param_1);
  *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xfe;
  *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) & 0xfb;
  *(undefined4 *)(*param_1 + 0x170) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  fVar1 = *(float *)(*param_1 + 0x28);
  if (0x3f < (byte)((10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) - 1)) {
    lVar7 = (longdouble)(*DAT_001a7fac)(0,0x43960000);
    *(float *)(*param_1 + 0x28) = (float)(lVar7 + (longdouble)*(float *)(*param_1 + 0x28));
  }
  SetSuitUpdate__11CBasePlayerPcii(param_1,0,0,0);
  param_1[0x205] = 0;
  (*DAT_001a7ef8)(1,gmsgHealth,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(param_1[0x205]);
  (*DAT_001a7efc)();
  (*DAT_001a7ef8)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(0);
  (*DAT_001a7f00)(0xff);
  (*DAT_001a7f00)(0xff);
  (*DAT_001a7efc)();
  param_1[0x20a] = 0;
  param_1[0x209] = 0;
  *(undefined4 *)(*param_1 + 0x214) = 0;
  (*DAT_001a7ef8)(1,gmsgSetFOV,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(0);
  (*DAT_001a7efc)();
  fVar1 = *(float *)(*param_1 + 0x160);
  if ((((byte)((-40.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == -40.0) << 0xe) >> 8)) - 1) < 0x40) ||
      (param_3 == 1)) && (param_3 != 2)) {
    (**(code **)(param_1[0xf5] + 0x200))(param_1);
    *(undefined4 *)(*param_1 + 0x50) = 0;
    *(undefined4 *)(*param_1 + 0x58) = 0;
    param_1[0x25e] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)PlayerDeathThink__11CBasePlayer;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    fVar1 = (float)param_1[0x19f];
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    (**(code **)(param_1[0xf5] + 0x1e8))(param_1);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    fVar1 = (float)param_1[0x19f];
  }
  fVar2 = *gpGlobals;
  TeamFortress_SetupRespawn__11CBasePlayeri
            (param_1,0x3f < (byte)((fVar1 < fVar2 |
                                    (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1));
  return;
}


// Killed__12CBaseMonsterP9entvars_si  @ 0008d780
void Killed__12CBaseMonsterP9entvars_si(int *param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 0x16f) & 0x80) == 0) {
    *(byte *)(param_1 + 0x16f) = *(byte *)(param_1 + 0x16f) | 0x80;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"common/null.wav",0x3f800000,0x3f4ccccd,0,100);
    param_1[0x13e] = 8;
    *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) | 1;
    iVar2 = *(int *)(*param_1 + 0x198);
    if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 != 0) {
      (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x2c))(iVar2,*param_1);
    }
    iVar2 = ShouldGibMonster__12CBaseMonsteri(param_1,param_3);
    if (iVar2 == 0) {
      if ((*(byte *)(*param_1 + 0x1a4) & 0x20) != 0) {
        param_1[5] = 0;
        param_1[6] = 0;
        (**(code **)(param_1[0xf5] + 0x124))(param_1);
      }
      fVar1 = *(float *)(*param_1 + 0x160);
      if (0x3f < (byte)((-99.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == -99.0) << 0xe) >> 8)) - 1)) {
        *(undefined4 *)(*param_1 + 0x160) = 0;
      }
      param_1[0x13e] = 8;
      return;
    }
  }
  else {
    iVar2 = ShouldGibMonster__12CBaseMonsteri(param_1,param_3);
    if (iVar2 == 0) {
      return;
    }
  }
  CallGibMonster__12CBaseMonster(param_1);
  return;
}


// Killed__12CTFDispenserP9entvars_si  @ 00091ecc
void Killed__12CTFDispenserP9entvars_si(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar1 + 0xd10) == 0) {
    puVar2 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,4,"#Dispenser_destroyed",0,0,0,0);
    ClientPrint__FP9entvars_siPCcN42(*puVar2);
  }
  piVar5 = param_1 + 0x51;
  iVar1 = __rf__7EHANDLE(piVar5);
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  iVar1 = __opP11CBaseEntity__7EHANDLE(piVar5);
  *(undefined4 *)(iVar1 + 0xd10) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Dispenser_Explode__12CTFDispenser;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (param_2 != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar5);
    if (iVar1 != 0) {
      piVar3 = (int *)__rf__7EHANDLE(piVar5);
      uVar4 = (*DAT_001a8004)(*(undefined4 *)(*piVar3 + 0x208));
      piVar5 = (int *)__rf__7EHANDLE(piVar5,uVar4);
      uVar4 = (*DAT_001a8004)(*(undefined4 *)(param_2 + 0x208),
                              *(int *)(*piVar5 + 0x1d0) + (int)gpGlobals[0x26]);
      UTIL_LogPrintf__FPce
                ("\"%s<%i>\" destroyed \"%s<%i>\"\'s \"dispenser\".\n",
                 *(int *)(param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
    }
  }
  return;
}


// Killed__12CTFSentrygunP9entvars_si  @ 000dfa18
void Killed__12CTFSentrygunP9entvars_si(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  if (*(int *)(*param_1 + 0x10c) == 0) {
    return;
  }
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x51);
  if (*(int *)(iVar1 + 0xd0c) == 0) {
    puVar2 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,4,"#Sentry_destroyed",0,0,0,0);
    ClientPrint__FP9entvars_siPCcN42(*puVar2);
  }
  iVar1 = __rf__7EHANDLE(param_1 + 0x51);
  *(undefined4 *)(iVar1 + 0x150) = 0;
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x51);
  *(undefined4 *)(iVar1 + 0xd0c) = 0;
  for (iVar1 = 1; iVar1 <= (int)gpGlobals[0x24]; iVar1 = iVar1 + 1) {
    iVar3 = UTIL_PlayerByIndex__Fi(iVar1);
    if (iVar3 != 0) {
      piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(iVar3 + 0x138);
      if (piVar4 == param_1) {
        ResetMenu__11CBasePlayer(iVar3);
        __as__7EHANDLEP11CBaseEntity(iVar3 + 0x138,0);
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x26);
  *(undefined4 *)(*piVar4 + 0x10c) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Sentry_Explode__12CTFSentrygun;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 0x208);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(iVar1 + 0x7c);
    }
    iVar1 = (**(code **)(piVar4[0xf5] + 0x9c))(piVar4);
    if (iVar1 != 0) {
      TF_AddFrags__11CBasePlayeri(piVar4,1);
      (*DAT_001a7ef8)(2,gmsgDeathMsg,0,0);
      uVar5 = (*DAT_001a7f5c)(*(undefined4 *)(*piVar4 + 0x208));
      (*DAT_001a7f00)(uVar5);
      (*DAT_001a7f00)(0xffffffff);
      (*DAT_001a7f18)("sentrygun");
      (*DAT_001a7efc)();
    }
    param_1 = param_1 + 0x51;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1);
    if (iVar1 != 0) {
      piVar4 = (int *)__rf__7EHANDLE(param_1);
      uVar5 = (*DAT_001a8004)(*(undefined4 *)(*piVar4 + 0x208));
      piVar4 = (int *)__rf__7EHANDLE(param_1,uVar5);
      uVar5 = (*DAT_001a8004)(*(undefined4 *)(param_2 + 0x208),
                              *(int *)(*piVar4 + 0x1d0) + (int)gpGlobals[0x26]);
      UTIL_LogPrintf__FPce
                ("\"%s<%i>\" destroyed \"%s<%i>\"\'s \"sentry\".\n",
                 *(int *)(param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
    }
    return;
  }
  return;
}


// Killed__12CTalkMonsterP9entvars_si  @ 000e8614
void Killed__12CTalkMonsterP9entvars_si(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(byte *)(param_2 + 0x1a4) & 8) == 0) || (*(int *)(param_1 + 0x4f4) == 5))
  goto LAB_000e8678;
  AlertFriends__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_2 + 0x208);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0,0);
    if (iVar1 != 0) goto LAB_000e8666;
    uVar2 = 0;
  }
  else {
LAB_000e8666:
    uVar2 = *(undefined4 *)(iVar1 + 0x7c);
  }
  LimitFollowers__12CTalkMonsterP11CBaseEntityi(param_1,uVar2);
LAB_000e8678:
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x484,0);
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x188))(param_1);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  Killed__12CBaseMonsterP9entvars_si(param_1,param_2,param_3);
  return;
}


// Killed__13CSquadMonsterP9entvars_si  @ 000e57d8
void Killed__13CSquadMonsterP9entvars_si(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  VacateSlot__13CSquadMonster(param_1);
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
  if (iVar1 != 0) {
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c,param_1);
    iVar1 = param_1;
    if (iVar2 != 0) {
      iVar1 = iVar2;
    }
    SquadRemove__13CSquadMonsterP13CSquadMonster(iVar1);
  }
  Killed__12CBaseMonsterP9entvars_si(param_1,param_2,param_3);
  return;
}


// Killed__8CAirtankP9entvars_si  @ 0007f344
void Killed__8CAirtankP9entvars_si(int *param_1,int param_2)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(param_2 + 0x208);
  iVar1 = *param_1;
  local_c = *(undefined4 *)(iVar1 + 8);
  local_8 = *(undefined4 *)(iVar1 + 0xc);
  local_4 = *(undefined4 *)(iVar1 + 0x10);
  local_10 = 0xbf800000;
  local_18 = 0;
  local_14 = 0;
  (**(code **)(param_1[0xf5] + 0x214))(param_1,&local_c,&local_18);
  return;
}


// Killed__8CGrenadeP9entvars_si  @ 000a6b88
void Killed__8CGrenadeP9entvars_si(undefined4 param_1)

{
  Detonate__8CGrenade(param_1);
  return;
}


