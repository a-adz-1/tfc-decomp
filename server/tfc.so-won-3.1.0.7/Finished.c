// Finished__11CBaseEntity  @ 0010f3c4
void Finished__11CBaseEntity(void)

{
  return;
}


// Finished__12CTFDispenser  @ 0009ba40
void Finished__12CTFDispenser(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  int *piVar6;
  
  piVar6 = param_1 + 0x51;
  iVar1 = __rf__7EHANDLE(piVar6);
  *(undefined4 *)(iVar1 + 0x14c) = 0x3f800000;
  puVar2 = (undefined4 *)__rf__7EHANDLE(piVar6,1,"#Dispenser_finish",0,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*puVar2);
  piVar3 = (int *)__rf__7EHANDLE(piVar6,0,0);
  uVar4 = __opP11CBaseEntity__7EHANDLE
                    (piVar6,1,"#Dispenser_built",*(int *)(*piVar3 + 0x1d0) + (int)gpGlobals[0x26]);
  teamsprint__FiP11CBaseEntityiPCcN33(param_1[0x48],uVar4);
  iVar1 = __rf__7EHANDLE(piVar6);
  if (*(int *)(iVar1 + 0x120) == 0) {
    pcVar5 = "SPECTATOR";
  }
  else {
    iVar1 = __rf__7EHANDLE(piVar6);
    pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120));
  }
  piVar6 = param_1 + 0x51;
  piVar3 = (int *)__rf__7EHANDLE(piVar6,pcVar5);
  uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*piVar3 + 0x208));
  piVar3 = (int *)__rf__7EHANDLE(piVar6,uVar4);
  uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*piVar3 + 0x208));
  piVar3 = (int *)__rf__7EHANDLE(piVar6,uVar4);
  UTIL_LogPrintf__FPce
            ("\"%s<%i><%u><%s>\" triggered \"Built_Dispenser\"\n",
             *(int *)(*piVar3 + 0x1d0) + (int)gpGlobals[0x26]);
  iVar1 = __rf__7EHANDLE(piVar6);
  *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + -100;
  *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
  param_1[5] = -0x10000;
  param_1[6] = (int)DispenserTouch__12CTFDispenserP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)DispenserThink__12CTFDispenser;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 12.0;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41000000;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  iVar1 = __rf__7EHANDLE(piVar6);
  param_1[0x33] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xcc) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar6);
  param_1[0x35] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xd4) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar6);
  param_1[0x39] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xe4) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar6);
  param_1[0x37] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xdc) * 0.25));
  piVar3 = (int *)__rf__7EHANDLE(piVar6);
  *(float *)(*param_1 + 0x1bc) = ROUND(*(float *)(*piVar3 + 0x1bc) * 0.25);
  iVar1 = __rf__7EHANDLE(piVar6);
  *(int *)(iVar1 + 0xcc) = (int)ROUND(ROUND((double)param_1[0x33] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar6);
  *(int *)(iVar1 + 0xd4) = (int)ROUND(ROUND((double)param_1[0x35] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar6);
  *(int *)(iVar1 + 0xe4) = (int)ROUND(ROUND((double)param_1[0x39] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar6);
  *(int *)(iVar1 + 0xdc) = (int)ROUND(ROUND((double)param_1[0x37] * 0.75));
  piVar6 = (int *)__rf__7EHANDLE(piVar6);
  *(float *)(*piVar6 + 0x1bc) = ROUND(*(float *)(*param_1 + 0x1bc) * 0.75);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100);
  return;
}


// Finished__16CTFSentrygunBase  @ 000ea358
void Finished__16CTFSentrygunBase(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  int *piVar6;
  longdouble lVar7;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar6 = param_1 + 0x51;
  iVar1 = __rf__7EHANDLE(piVar6);
  *(undefined4 *)(iVar1 + 0x150) = 0x3f800000;
  puVar2 = (undefined4 *)__rf__7EHANDLE(piVar6,1,"#Sentry_finish",0,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*puVar2);
  piVar3 = (int *)__rf__7EHANDLE(piVar6,0,0);
  uVar4 = __opP11CBaseEntity__7EHANDLE
                    (piVar6,1,"#Sentry_built",*(int *)(*piVar3 + 0x1d0) + (int)gpGlobals[0x26]);
  teamsprint__FiP11CBaseEntityiPCcN33(param_1[0x48],uVar4);
  iVar1 = __rf__7EHANDLE(piVar6);
  if (*(int *)(iVar1 + 0x120) == 0) {
    pcVar5 = "SPECTATOR";
  }
  else {
    iVar1 = __rf__7EHANDLE(piVar6);
    pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar1 + 0x120));
  }
  piVar6 = param_1 + 0x51;
  piVar3 = (int *)__rf__7EHANDLE(piVar6,pcVar5);
  uVar4 = (*DAT_001c11f4)(*(undefined4 *)(*piVar3 + 0x208));
  piVar3 = (int *)__rf__7EHANDLE(piVar6,uVar4);
  uVar4 = (*DAT_001c11e4)(*(undefined4 *)(*piVar3 + 0x208));
  piVar3 = (int *)__rf__7EHANDLE(piVar6,uVar4);
  UTIL_LogPrintf__FPce
            ("\"%s<%i><%u><%s>\" triggered \"Sentry_Built_Level_1\"\n",
             *(int *)(*piVar3 + 0x1d0) + (int)gpGlobals[0x26]);
  *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
  iVar1 = __rf__7EHANDLE(piVar6);
  *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + -0x82;
  local_c = 0x41800000;
  local_4 = 0x40800000;
  local_18 = 0xc1800000;
  local_10 = 0.0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  piVar6 = (int *)GetClassPtr__H1Z12CTFSentrygun_PX01_PX01(0);
  (**(code **)(piVar6[0x111] + 0xc))(piVar6);
  iVar1 = param_1[0x52];
  piVar6[0x51] = param_1[0x51];
  piVar6[0x52] = iVar1;
  piVar6[0x48] = param_1[0x48];
  *(uint *)(*piVar6 + 0x1a8) =
       (*(int *)(teamcolors + param_1[0x48] * 0x60 + 0x50) + 10U & 0xff) * 0x100 +
       *(int *)(teamcolors + param_1[0x48] * 0x60 + 0x50);
  __as__7EHANDLEP11CBaseEntity(piVar6 + 0x26,param_1);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x26,piVar6);
  local_4 = 0x41a9999a;
  local_c = 0;
  local_8 = 0;
  iVar1 = *param_1;
  local_18 = *(undefined4 *)(iVar1 + 8);
  local_14 = *(undefined4 *)(iVar1 + 0xc);
  local_10 = *(float *)(iVar1 + 0x10) + 21.2;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar6,&local_18);
  *(undefined4 *)(*piVar6 + 0x54) = *(undefined4 *)(*param_1 + 0x54);
  lVar7 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*piVar6 + 0x54));
  piVar6[0x1a9] = (int)(float)lVar7;
  lVar7 = (longdouble)UTIL_AngleMod__Ff((float)((int)ROUND(*(float *)(*piVar6 + 0x54)) + -0x32));
  piVar6[0x28] = (int)ROUND(lVar7);
  lVar7 = (longdouble)UTIL_AngleMod__Ff((float)((int)ROUND(*(float *)(*piVar6 + 0x54)) + 0x32));
  iVar1 = (int)ROUND(lVar7);
  piVar6[0x29] = iVar1;
  if (iVar1 < piVar6[0x28]) {
    piVar6[0x28] = iVar1;
    lVar7 = (longdouble)UTIL_AngleMod__Ff((float)((int)ROUND(*(float *)(*piVar6 + 0x54)) + -0x32));
    piVar6[0x29] = (int)ROUND(lVar7);
  }
  piVar6[0x1ac] = (int)(float)piVar6[0x28];
  piVar6[0x1a8] = 0;
  piVar6[0x1ab] = 0;
  piVar6[0x1a3] = 1;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar6 + 0x208),3,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100);
  piVar6[0x1a5] = (int)(*gpGlobals + 0.1);
  return;
}


