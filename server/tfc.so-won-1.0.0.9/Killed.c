// Killed__11CBaseEntityP9entvars_ti  @ 000a13d0
void Killed__11CBaseEntityP9entvars_ti(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(undefined4 *)(*param_1 + 0x150) = 2;
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Killed__11CBasePlayerP9entvars_ti  @ 000d7b70
void Killed__11CBasePlayerP9entvars_ti(int *param_1,undefined4 param_2,int param_3)

{
  float *pfVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  longdouble lVar6;
  
  (*DAT_00175578)(5,0x17,*param_1 + 8,0);
  (*DAT_00175580)(0x7d);
  uVar2 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8));
  (*DAT_00175580)(uVar2);
  (*DAT_0017557c)();
  if (param_1[0x20c] != 0) {
    (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x120))(param_1[0x20c]);
  }
  (**(code **)(*g_pGameRules + 0x74))(g_pGameRules,param_1,param_2,g_pevLastInflictor);
  piVar5 = param_1 + 0x1f8;
  iVar3 = __opP11CBaseEntity__7EHANDLE(piVar5);
  if (iVar3 != 0) {
    iVar3 = __rf__7EHANDLE(piVar5);
    (**(code **)(*(int *)(iVar3 + 0x3c8) + 0xb0))(iVar3,param_1,param_1,0,0);
    __as__7EHANDLEP11CBaseEntity(piVar5,0);
  }
  uVar4 = ClientSoundIndex__9CSoundEntP7edict_s(*(undefined4 *)(*param_1 + 0x1e8));
  iVar3 = SoundPointerForIndex__9CSoundEnti(uVar4);
  if (iVar3 != 0) {
    Reset__6CSound(iVar3);
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,4);
  *(byte *)((int)param_1 + 0x8e) = *(byte *)((int)param_1 + 0x8e) & 0xf7;
  param_1[0xe9] = 0;
  param_1[0xe8] = 0;
  param_1[0xea] = 0;
  param_1[0xeb] = 0;
  *(undefined4 *)(*param_1 + 0x94) = g_ulModelIndexPlayer;
  if (((*(byte *)(param_1 + 0x22) & 0x10) != 0) &&
     (*(int *)(*param_1 + 0x1e8) == *(int *)(*param_1 + 0x170))) {
    piVar5 = (int *)FindTimer__11CBaseEntityi(param_1,2);
    if (piVar5 != (int *)0x0) {
      iVar3 = *(int *)(*piVar5 + 0x170);
      if (iVar3 == 0) {
        iVar3 = (*DAT_001755d4)(0);
        if (iVar3 != 0) goto LAB_000d7cf5;
        uVar4 = 0;
      }
      else {
LAB_000d7cf5:
        uVar4 = *(undefined4 *)(iVar3 + 0xd8);
      }
      TF_AddFrags__11CBasePlayeri(uVar4,1);
    }
  }
  TeamFortress_RemoveTimers__11CBasePlayer(param_1);
  ResetMenu__11CBasePlayer(param_1);
  *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) & 0xfe;
  *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0xfb;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x154) = 0;
  *(undefined4 *)(iVar3 + 0x158) = 0;
  *(undefined4 *)(iVar3 + 0x15c) = 0xc1000000;
  *(undefined4 *)(*param_1 + 0x150) = 1;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
  if (*(float *)(*param_1 + 0x28) < 10.0) {
    lVar6 = (longdouble)(*DAT_0017562c)(0,0x43960000);
    *(float *)(*param_1 + 0x28) = (float)(lVar6 + (longdouble)*(float *)(*param_1 + 0x28));
  }
  SetSuitUpdate__11CBasePlayerPcii(param_1,0,0,0);
  param_1[0x200] = 0;
  (*DAT_00175578)(1,gmsgHealth,0,*(undefined4 *)(*param_1 + 0x1e8));
  (*DAT_00175580)(param_1[0x200]);
  (*DAT_0017557c)();
  (*DAT_00175578)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x1e8));
  (*DAT_00175580)(0);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0xff);
  (*DAT_0017557c)();
  param_1[0x205] = 0;
  param_1[0x204] = 0;
  (*DAT_00175578)(1,gmsgSetFOV,0,*(undefined4 *)(*param_1 + 0x1e8));
  (*DAT_00175580)(0);
  (*DAT_0017557c)();
  if (((*(float *)(*param_1 + 0x140) < -40.0) && (param_3 != 1)) || (param_3 == 2)) {
    (**(code **)(param_1[0xf2] + 0x1e8))(param_1);
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
    if (*gpGlobals < (float)param_1[0x19b]) {
      uVar4 = 1;
      goto LAB_000d7f72;
    }
  }
  else {
    (**(code **)(param_1[0xf2] + 0x200))(param_1);
    *(undefined4 *)(*param_1 + 0x50) = 0;
    *(undefined4 *)(*param_1 + 0x58) = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)PlayerDeathThink__11CBasePlayer;
    pfVar1 = gpGlobals;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
    if (*pfVar1 < (float)param_1[0x19b]) {
      uVar4 = 1;
      goto LAB_000d7f72;
    }
  }
  uVar4 = 0;
LAB_000d7f72:
  TeamFortress_SetupRespawn__11CBasePlayeri(param_1,uVar4);
  return;
}


// Killed__12CBaseMonsterP9entvars_ti  @ 000a4dd0
void Killed__12CBaseMonsterP9entvars_ti(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x16c) & 0x80) == 0) {
    *(byte *)(param_1 + 0x16c) = *(byte *)(param_1 + 0x16c) | 0x80;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,"common/null.wav",0x3f800000,0x3f4ccccd,0,100);
    param_1[0x13b] = 8;
    *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 1;
    iVar1 = *(int *)(*param_1 + 0x178);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xd8);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x2c))(iVar1,*param_1);
    }
    iVar1 = ShouldGibMonster__12CBaseMonsteri(param_1,param_3);
    if (iVar1 == 0) {
      if ((*(byte *)(*param_1 + 0x184) & 0x20) != 0) {
        param_1[5] = 0;
        param_1[6] = 0;
        (**(code **)(param_1[0xf2] + 0x124))(param_1);
      }
      if (*(float *)(*param_1 + 0x140) < -99.0) {
        *(undefined4 *)(*param_1 + 0x140) = 0;
      }
      param_1[0x13b] = 8;
      return;
    }
  }
  else {
    iVar1 = ShouldGibMonster__12CBaseMonsteri(param_1,param_3);
    if (iVar1 == 0) {
      return;
    }
  }
  CallGibMonster__12CBaseMonster(param_1);
  return;
}


// Killed__12CTFDispenserP9entvars_ti  @ 000a88f0
void Killed__12CTFDispenserP9entvars_ti(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,4,"#Dispenser_destroyed",0,0,0,0);
  ClientPrint__FP9entvars_tiPCcN42(*puVar1);
  iVar2 = __rf__7EHANDLE(param_1 + 0x51);
  *(undefined4 *)(iVar2 + 0x14c) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Dispenser_Explode__12CTFDispenser;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


// Killed__12CTFSentrygunP9entvars_ti  @ 000ea4b0
void Killed__12CTFSentrygunP9entvars_ti(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,4,"#Sentry_destroyed",0,0,0,0);
  ClientPrint__FP9entvars_tiPCcN42(*puVar1);
  iVar2 = __rf__7EHANDLE(param_1 + 0x51);
  *(undefined4 *)(iVar2 + 0x150) = 0;
  for (iVar2 = 1; iVar2 <= (int)gpGlobals[0x24]; iVar2 = iVar2 + 1) {
    iVar3 = UTIL_PlayerByIndex__Fi(iVar2);
    if (iVar3 != 0) {
      piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(iVar3 + 0x138);
      if (piVar4 == param_1) {
        ResetMenu__11CBasePlayer(iVar3);
        __as__7EHANDLEP11CBaseEntity(iVar3 + 0x138,0);
      }
    }
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Sentry_Explode__12CTFSentrygun;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


// Killed__12CTalkMonsterP9entvars_ti  @ 000f1b00
void Killed__12CTalkMonsterP9entvars_ti(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(byte *)(param_2 + 0x184) & 8) == 0) || (*(int *)(param_1 + 0x4e8) == 5))
  goto LAB_000f1b5c;
  AlertFriends__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_2 + 0x1e8);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0,0);
    if (iVar1 != 0) goto LAB_000f1b3f;
    uVar2 = 0;
  }
  else {
LAB_000f1b3f:
    uVar2 = *(undefined4 *)(iVar1 + 0xd8);
  }
  LimitFollowers__12CTalkMonsterP11CBaseEntityi(param_1,uVar2);
LAB_000f1b5c:
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x478,0);
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x188))(param_1);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  Killed__12CBaseMonsterP9entvars_ti(param_1,param_2,param_3);
  return;
}


// Killed__13CSquadMonsterP9entvars_ti  @ 000ef420
void Killed__13CSquadMonsterP9entvars_ti(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  VacateSlot__13CSquadMonster(param_1);
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
  if (iVar1 != 0) {
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610,param_1);
    iVar1 = param_1;
    if (iVar2 != 0) {
      iVar1 = iVar2;
    }
    SquadRemove__13CSquadMonsterP13CSquadMonster(iVar1);
  }
  Killed__12CBaseMonsterP9entvars_ti(param_1,param_2,param_3);
  return;
}


// Killed__8CAirtankP9entvars_ti  @ 0009a8a0
void Killed__8CAirtankP9entvars_ti(int *param_1,int param_2)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(param_2 + 0x1e8);
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  local_1c = 0;
  local_18 = 0;
  local_14 = 0xbf800000;
  (**(code **)(param_1[0xf2] + 0x214))(param_1,&local_10,&local_1c);
  return;
}


// Killed__8CGrenadeP9entvars_ti  @ 000b9340
void Killed__8CGrenadeP9entvars_ti(undefined4 param_1)

{
  Detonate__8CGrenade(param_1);
  return;
}


