// Killed__11CBaseEntityP9entvars_sT1i  @ 0008ec08
void Killed__11CBaseEntityP9entvars_sT1i(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  *(undefined4 *)(*param_1 + 0x170) = 2;
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Killed__11CBasePlayerP9entvars_sT1i  @ 000d51a0
void Killed__11CBasePlayerP9entvars_sT1i
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  longdouble lVar6;
  
  (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(0x7d);
  uVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(uVar2);
  (*DAT_0019f75c)();
  param_1[0x367] = 0;
  *(undefined4 *)(*param_1 + 0x24c) = 0;
  iVar3 = param_1[0x237];
  if (iVar3 != 0) {
    (**(code **)(*(int *)(iVar3 + 0x454) + 0x128))(iVar3,0);
  }
  (**(code **)(*g_pGameRules + 0x74))(g_pGameRules,param_1,param_3,g_pevLastInflictor);
  piVar5 = param_1 + 0x223;
  iVar3 = __opP11CBaseEntity__7EHANDLE(piVar5);
  if (iVar3 != 0) {
    iVar3 = __rf__7EHANDLE(piVar5);
    (**(code **)(*(int *)(iVar3 + 0x454) + 0xb8))(iVar3,param_1,param_1,0,0);
    __as__7EHANDLEP11CBaseEntity(piVar5,0);
  }
  uVar4 = ClientSoundIndex__9CSoundEntP7edict_s(*(undefined4 *)(*param_1 + 0x208));
  iVar3 = SoundPointerForIndex__9CSoundEnti(uVar4);
  if (iVar3 != 0) {
    Reset__6CSound(iVar3);
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,4);
  *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xf7;
  param_1[0x10c] = 0;
  param_1[0x10b] = 0;
  param_1[0x10d] = 0;
  param_1[0x10e] = 0;
  *(undefined4 *)(*param_1 + 0xb4) = g_ulModelIndexPlayer;
  if ((((*(byte *)(param_1 + 0x21) & 0x10) != 0) &&
      (*(int *)(*param_1 + 0x208) == *(int *)(*param_1 + 400))) &&
     (piVar5 = (int *)FindTimer__11CBaseEntityi(param_1,2), piVar5 != (int *)0x0)) {
    iVar3 = *(int *)(*piVar5 + 400);
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar3 + 0x7c);
    }
    TF_AddFrags__11CBasePlayeri(uVar4,1);
  }
  TeamFortress_RemoveTimers__11CBasePlayer(param_1);
  ResetMenu__11CBasePlayer(param_1);
  param_1[0x21] = param_1[0x21] & 0xfffffbfe;
  *(undefined4 *)(*param_1 + 0x170) = 1;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  fVar1 = *(float *)(*param_1 + 0x28);
  if (0x3f < (byte)((10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) - 1)) {
    lVar6 = (longdouble)(*DAT_0019f80c)(0,0x43960000);
    *(float *)(*param_1 + 0x28) = (float)(lVar6 + (longdouble)*(float *)(*param_1 + 0x28));
  }
  SetSuitUpdate__11CBasePlayerPcii(param_1,0,0,0);
  param_1[0x22b] = 0;
  (*DAT_0019f758)(1,gmsgHealth,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(param_1[0x22b]);
  (*DAT_0019f75c)();
  (*DAT_0019f758)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(0xff);
  (*DAT_0019f760)(0xff);
  (*DAT_0019f75c)();
  param_1[0x230] = 0;
  param_1[0x22f] = 0;
  *(undefined4 *)(*param_1 + 0x214) = 0;
  (*DAT_0019f758)(1,gmsgSetFOV,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(0);
  (*DAT_0019f75c)();
  fVar1 = *(float *)(*param_1 + 0x160);
  if ((((byte)((-40.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == -40.0) << 0xe) >> 8)) - 1) < 0x40) ||
      (param_4 == 1)) && (param_4 != 2)) {
    (**(code **)(param_1[0x115] + 0x208))(param_1);
    param_1[0x1b] = 0;
    *(undefined4 *)(*param_1 + 0x50) = 0;
    *(undefined4 *)(*param_1 + 0x58) = 0;
    param_1[0x285] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)PlayerDeathThink__11CBasePlayer;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    (**(code **)(param_1[0x115] + 0x1f0))(param_1);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  }
  TeamFortress_SetupRespawn__11CBasePlayeri(param_1,*gpGlobals < (float)param_1[0x1c4]);
  return;
}


// Killed__12CBaseMonsterP9entvars_sT1i  @ 00095ce8
void Killed__12CBaseMonsterP9entvars_sT1i
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  int iVar2;
  
  if ((param_1[399] & 0x80U) == 0) {
    param_1[399] = param_1[399] | 0x80;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"common/null.wav",0x3f800000,0x3f4ccccd,0,100);
    param_1[0x15e] = 8;
    *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) | 1;
    iVar2 = *(int *)(*param_1 + 0x198);
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 != 0) {
      (**(code **)(*(int *)(iVar2 + 0x454) + 0x30))(iVar2,*param_1);
    }
    if (((param_4 != 0) || (-30.0 <= *(float *)(*param_1 + 0x160))) && (param_4 != 2)) {
      iVar2 = *param_1;
      if ((*(byte *)(iVar2 + 0x1a4) & 0x20) != 0) {
        param_1[5] = 0;
        param_1[6] = 0;
        (**(code **)(param_1[0x115] + 300))(param_1);
        iVar2 = *param_1;
      }
      fVar1 = *(float *)(iVar2 + 0x160);
      if (0x3f < (byte)((-99.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == -99.0) << 0xe) >> 8)) - 1)) {
        *(undefined4 *)(iVar2 + 0x160) = 0;
      }
      param_1[0x15e] = 8;
      return;
    }
  }
  else if (((param_4 != 0) || (-30.0 <= *(float *)(*param_1 + 0x160))) && (param_4 != 2)) {
    return;
  }
  CallGibMonster__12CBaseMonster(param_1);
  return;
}


// Killed__12CTFDispenserP9entvars_sT1i  @ 0009b77c
void Killed__12CTFDispenserP9entvars_sT1i(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined1 *puVar7;
  int local_2c;
  undefined1 local_24 [32];
  
  piVar6 = param_1 + 0x51;
  iVar1 = __opP11CBaseEntity__7EHANDLE(piVar6);
  if (*(int *)(iVar1 + 0xdac) == 0) {
    puVar2 = (undefined4 *)__rf__7EHANDLE(piVar6,4,"#Dispenser_destroyed",0,0,0,0);
    ClientPrint__FP9entvars_siPCcN42(*puVar2);
  }
  iVar1 = __rf__7EHANDLE(piVar6);
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  iVar1 = __opP11CBaseEntity__7EHANDLE(piVar6);
  *(undefined4 *)(iVar1 + 0xdac) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Dispenser_Explode__12CTFDispenser;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (param_3 != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar6);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_3 + 0x208);
      if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
        local_2c = 0;
      }
      else {
        local_2c = *(int *)(iVar1 + 0x7c);
      }
      puVar7 = local_24;
      GetWeapon__FP9entvars_sT0Pc(param_2,param_3,puVar7);
      if (param_2 == param_3) {
        iVar1 = __rf__7EHANDLE(piVar6);
        if (*(int *)(iVar1 + 0x120) == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          iVar1 = __rf__7EHANDLE(piVar6);
          pcVar3 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120));
        }
        piVar4 = (int *)__rf__7EHANDLE(piVar6,pcVar3);
        uVar5 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208));
        piVar4 = (int *)__rf__7EHANDLE(piVar6,uVar5);
        uVar5 = (*DAT_0019f864)(*(undefined4 *)(*piVar4 + 0x208));
        piVar6 = (int *)__rf__7EHANDLE(piVar6,uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%s><%s>\" triggered \"Dispenser_Destroyed\"\n",
                   *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26]);
      }
      else {
        piVar4 = (int *)__rf__7EHANDLE(piVar6);
        if (param_3 != *piVar4) {
          iVar1 = __rf__7EHANDLE(piVar6,puVar7);
          if (*(int *)(iVar1 + 0x120) == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            iVar1 = __rf__7EHANDLE(piVar6,puVar7);
            pcVar3 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120));
          }
          piVar4 = (int *)__rf__7EHANDLE(piVar6,pcVar3);
          uVar5 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208));
          piVar4 = (int *)__rf__7EHANDLE(piVar6,uVar5);
          uVar5 = (*DAT_0019f864)(*(undefined4 *)(*piVar4 + 0x208));
          piVar6 = (int *)__rf__7EHANDLE(piVar6,uVar5);
          if (*(int *)(local_2c + 0x120) == 0) {
            pcVar3 = "SPECTATOR";
          }
          else {
            pcVar3 = (char *)GetTeamName__Fi(*(int *)(local_2c + 0x120),
                                             *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26]);
          }
          uVar5 = (*DAT_0019f8dc)(*(undefined4 *)(param_3 + 0x208),pcVar3);
          uVar5 = (*DAT_0019f864)(*(undefined4 *)(param_3 + 0x208),uVar5);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Dispenser_Destroyed\" against \"%s<%i><%s><%s>\" with \"%s\"\n"
                     ,*(int *)(param_3 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        }
      }
      return;
    }
    return;
  }
  return;
}


// Killed__12CTFSentrygunP9entvars_sT1i  @ 000ed6e8
void Killed__12CTFSentrygunP9entvars_sT1i(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_30;
  undefined1 local_24 [32];
  
  if (*(int *)(*param_1 + 0x10c) == 0) {
    return;
  }
  piVar6 = param_1 + 0x51;
  iVar1 = __opP11CBaseEntity__7EHANDLE(piVar6);
  if (*(int *)(iVar1 + 0xda8) == 0) {
    puVar2 = (undefined4 *)__rf__7EHANDLE(piVar6,4,"#Sentry_destroyed",0,0,0,0);
    ClientPrint__FP9entvars_siPCcN42(*puVar2);
  }
  iVar1 = __rf__7EHANDLE(piVar6);
  *(undefined4 *)(iVar1 + 0x150) = 0;
  iVar1 = __opP11CBaseEntity__7EHANDLE(piVar6);
  *(undefined4 *)(iVar1 + 0xda8) = 0;
  for (local_30 = 1; local_30 <= (int)gpGlobals[0x24]; local_30 = local_30 + 1) {
    iVar1 = UTIL_PlayerByIndex__Fi(local_30);
    if (iVar1 != 0) {
      piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(iVar1 + 0x138);
      if (piVar3 == param_1) {
        ResetMenu__11CBasePlayer(iVar1);
        __as__7EHANDLEP11CBaseEntity(iVar1 + 0x138,0);
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  piVar3 = (int *)__rf__7EHANDLE(param_1 + 0x26);
  *(undefined4 *)(*piVar3 + 0x10c) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)Sentry_Explode__12CTFSentrygun;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (param_3 != 0) {
    iVar1 = *(int *)(param_3 + 0x208);
    if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(iVar1 + 0x7c);
    }
    iVar1 = (**(code **)(piVar3[0x115] + 0xa0))(piVar3);
    if (iVar1 != 0) {
      uVar4 = __opP11CBaseEntity__7EHANDLE(piVar6);
      iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(piVar3,uVar4);
      if (iVar1 == 0) {
        TF_AddFrags__11CBasePlayeri(piVar3,1);
        (*DAT_0019f758)(2,gmsgDeathMsg,0,0);
        uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar3 + 0x208));
        (*DAT_0019f760)(uVar4);
        (*DAT_0019f760)(0xffffffff);
        (*DAT_0019f778)("sentrygun");
        (*DAT_0019f75c)();
      }
    }
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar6);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_3 + 0x208);
      if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      puVar8 = local_24;
      GetWeapon__FP9entvars_sT0Pc(param_2,param_3,puVar8);
      if (param_2 == param_3) {
        iVar1 = __rf__7EHANDLE(piVar6);
        if (*(int *)(iVar1 + 0x120) == 0) {
          pcVar5 = "SPECTATOR";
        }
        else {
          iVar1 = __rf__7EHANDLE(piVar6);
          pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120));
        }
        piVar3 = (int *)__rf__7EHANDLE(piVar6,pcVar5);
        uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar3 + 0x208));
        piVar3 = (int *)__rf__7EHANDLE(piVar6,uVar4);
        uVar4 = (*DAT_0019f864)(*(undefined4 *)(*piVar3 + 0x208));
        piVar6 = (int *)__rf__7EHANDLE(piVar6,uVar4);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%s><%s>\" triggered \"Sentry_Destroyed\"\n",
                   *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26]);
      }
      else {
        piVar3 = (int *)__rf__7EHANDLE(piVar6);
        if (param_3 != *piVar3) {
          iVar7 = __rf__7EHANDLE(piVar6,puVar8);
          if (*(int *)(iVar7 + 0x120) == 0) {
            pcVar5 = "SPECTATOR";
          }
          else {
            iVar7 = __rf__7EHANDLE(piVar6,puVar8);
            pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar7 + 0x120));
          }
          piVar3 = (int *)__rf__7EHANDLE(piVar6,pcVar5);
          uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar3 + 0x208));
          piVar3 = (int *)__rf__7EHANDLE(piVar6,uVar4);
          uVar4 = (*DAT_0019f864)(*(undefined4 *)(*piVar3 + 0x208));
          piVar6 = (int *)__rf__7EHANDLE(piVar6,uVar4);
          if (*(int *)(iVar1 + 0x120) == 0) {
            pcVar5 = "SPECTATOR";
          }
          else {
            pcVar5 = (char *)GetTeamName__Fi(*(int *)(iVar1 + 0x120),
                                             *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26]);
          }
          uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(param_3 + 0x208),pcVar5);
          uVar4 = (*DAT_0019f864)(*(undefined4 *)(param_3 + 0x208),uVar4);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Sentry_Destroyed\" against \"%s<%i><%s><%s>\" with \"%s\"\n"
                     ,*(int *)(param_3 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
        }
      }
      return;
    }
    return;
  }
  return;
}


// Killed__12CTalkMonsterP9entvars_sT1i  @ 000f9108
void Killed__12CTalkMonsterP9entvars_sT1i
               (int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(byte *)(param_3 + 0x1a4) & 8) == 0) || (*(int *)(param_1 + 0x574) == 5))
  goto LAB_000f916c;
  AlertFriends__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_3 + 0x208);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0,0);
    if (iVar1 != 0) goto LAB_000f915b;
    uVar2 = 0;
  }
  else {
LAB_000f915b:
    uVar2 = *(undefined4 *)(iVar1 + 0x7c);
  }
  LimitFollowers__12CTalkMonsterP11CBaseEntityi(param_1,uVar2);
LAB_000f916c:
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x504,0);
  (**(code **)(*(int *)(param_1 + 0x454) + 400))(param_1);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  Killed__12CBaseMonsterP9entvars_sT1i(param_1,param_2,param_3,param_4);
  return;
}


// Killed__13CSquadMonsterP9entvars_sT1i  @ 000f54cc
void Killed__13CSquadMonsterP9entvars_sT1i
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x6d0) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
    if (iVar1 != 0) {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
      iVar1 = param_1;
      if (iVar2 != 0) {
        iVar1 = iVar2;
      }
      *(uint *)(iVar1 + 0x6c4) = *(uint *)(iVar1 + 0x6c4) & ~*(uint *)(param_1 + 0x6d0);
      *(undefined4 *)(param_1 + 0x6d0) = 0;
    }
  }
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
  if (iVar1 != 0) {
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c,param_1);
    iVar1 = param_1;
    if (iVar2 != 0) {
      iVar1 = iVar2;
    }
    SquadRemove__13CSquadMonsterP13CSquadMonster(iVar1);
  }
  Killed__12CBaseMonsterP9entvars_sT1i(param_1,param_2,param_3,param_4);
  return;
}


// Killed__8CAirtankP9entvars_sT1i  @ 00086a40
void Killed__8CAirtankP9entvars_sT1i(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(param_3 + 0x208);
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  local_14 = 0xbf800000;
  local_1c = 0;
  local_18 = 0;
  (**(code **)(param_1[0x115] + 0x21c))(param_1,&local_10,&local_1c);
  return;
}


// Killed__8CGrenadeP9entvars_sT1i  @ 000b1e6c
void Killed__8CGrenadeP9entvars_sT1i(undefined4 param_1)

{
  Detonate__8CGrenade(param_1);
  return;
}


