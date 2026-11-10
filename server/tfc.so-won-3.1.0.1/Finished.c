// Finished__11CBaseEntity  @ 00100090
void Finished__11CBaseEntity(void)

{
  return;
}


// Finished__12CTFDispenser  @ 000919c8
void Finished__12CTFDispenser(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  
  piVar5 = param_1 + 0x51;
  iVar1 = __rf__7EHANDLE(piVar5);
  *(undefined4 *)(iVar1 + 0x14c) = 0x3f800000;
  puVar2 = (undefined4 *)__rf__7EHANDLE(piVar5,1,"#Dispenser_finish",0,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*puVar2);
  piVar3 = (int *)__rf__7EHANDLE(piVar5,0,0);
  uVar4 = __opP11CBaseEntity__7EHANDLE
                    (piVar5,1,"#Dispenser_built",*(int *)(*piVar3 + 0x1d0) + (int)gpGlobals[0x26]);
  teamsprint__FiP11CBaseEntityiPCcN33(param_1[0x48],uVar4);
  piVar3 = (int *)__rf__7EHANDLE(piVar5);
  uVar4 = (*DAT_001a8004)(*(undefined4 *)(*piVar3 + 0x208));
  piVar3 = (int *)__rf__7EHANDLE(piVar5,uVar4);
  UTIL_LogPrintf__FPce
            ("\"%s<%i>\" built a \"dispenser\".\n",*(int *)(*piVar3 + 0x1d0) + (int)gpGlobals[0x26])
  ;
  iVar1 = __rf__7EHANDLE(piVar5);
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
  iVar1 = __rf__7EHANDLE(piVar5);
  param_1[0x33] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xcc) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar5);
  param_1[0x35] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xd4) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar5);
  param_1[0x39] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xe4) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar5);
  param_1[0x37] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xdc) * 0.25));
  piVar3 = (int *)__rf__7EHANDLE(piVar5);
  *(float *)(*param_1 + 0x1bc) = ROUND(*(float *)(*piVar3 + 0x1bc) * 0.25);
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xcc) = (int)ROUND(ROUND((double)param_1[0x33] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xd4) = (int)ROUND(ROUND((double)param_1[0x35] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xe4) = (int)ROUND(ROUND((double)param_1[0x39] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xdc) = (int)ROUND(ROUND((double)param_1[0x37] * 0.75));
  piVar5 = (int *)__rf__7EHANDLE(piVar5);
  *(float *)(*piVar5 + 0x1bc) = ROUND(*(float *)(*param_1 + 0x1bc) * 0.75);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100);
  return;
}


// Finished__16CTFSentrygunBase  @ 000de23c
void Finished__16CTFSentrygunBase(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  longdouble lVar6;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar5 = param_1 + 0x51;
  iVar1 = __rf__7EHANDLE(piVar5);
  *(undefined4 *)(iVar1 + 0x150) = 0x3f800000;
  puVar2 = (undefined4 *)__rf__7EHANDLE(piVar5,1,"#Sentry_finish",0,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*puVar2);
  piVar3 = (int *)__rf__7EHANDLE(piVar5,0,0);
  uVar4 = __opP11CBaseEntity__7EHANDLE
                    (piVar5,1,"#Sentry_built",*(int *)(*piVar3 + 0x1d0) + (int)gpGlobals[0x26]);
  teamsprint__FiP11CBaseEntityiPCcN33(param_1[0x48],uVar4);
  piVar3 = (int *)__rf__7EHANDLE(piVar5);
  uVar4 = (*DAT_001a8004)(*(undefined4 *)(*piVar3 + 0x208));
  piVar3 = (int *)__rf__7EHANDLE(piVar5,uVar4);
  UTIL_LogPrintf__FPce
            ("\"%s<%i>\" built a \"sentry\".\n",*(int *)(*piVar3 + 0x1d0) + (int)gpGlobals[0x26]);
  *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + -0x82;
  local_c = 0x41800000;
  local_4 = 0x40800000;
  local_18 = 0xc1800000;
  local_10 = 0.0;
  local_14 = local_18;
  local_8 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  piVar5 = (int *)GetClassPtr__H1Z12CTFSentrygun_PX01_PX01(0);
  (**(code **)(piVar5[0xf5] + 8))(piVar5);
  iVar1 = param_1[0x52];
  piVar5[0x51] = param_1[0x51];
  piVar5[0x52] = iVar1;
  piVar5[0x48] = param_1[0x48];
  *(uint *)(*piVar5 + 0x1a8) =
       (*(int *)(teamcolors + param_1[0x48] * 4) + 10U & 0xff) * 0x100 +
       *(int *)(teamcolors + param_1[0x48] * 4);
  __as__7EHANDLEP11CBaseEntity(piVar5 + 0x26,param_1);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x26,piVar5);
  local_4 = 0x41a9999a;
  local_c = 0;
  local_8 = 0;
  iVar1 = *param_1;
  local_18 = *(undefined4 *)(iVar1 + 8);
  local_14 = *(undefined4 *)(iVar1 + 0xc);
  local_10 = *(float *)(iVar1 + 0x10) + 21.2;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar5,&local_18);
  *(undefined4 *)(*piVar5 + 0x54) = *(undefined4 *)(*param_1 + 0x54);
  lVar6 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*piVar5 + 0x54));
  piVar5[0x18d] = (int)(float)lVar6;
  lVar6 = (longdouble)UTIL_AngleMod__Ff((float)((int)ROUND(*(float *)(*piVar5 + 0x54)) + -0x32));
  piVar5[0x28] = (int)ROUND(lVar6);
  lVar6 = (longdouble)UTIL_AngleMod__Ff((float)((int)ROUND(*(float *)(*piVar5 + 0x54)) + 0x32));
  iVar1 = (int)ROUND(lVar6);
  piVar5[0x29] = iVar1;
  if (iVar1 < piVar5[0x28]) {
    piVar5[0x28] = iVar1;
    lVar6 = (longdouble)UTIL_AngleMod__Ff((float)((int)ROUND(*(float *)(*piVar5 + 0x54)) + -0x32));
    piVar5[0x29] = (int)ROUND(lVar6);
  }
  piVar5[400] = (int)(float)piVar5[0x28];
  piVar5[0x18c] = 0;
  piVar5[399] = 0;
  piVar5[0x187] = 1;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar5 + 0x208),3,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100);
  piVar5[0x189] = (int)(*gpGlobals + 0.1);
  return;
}


