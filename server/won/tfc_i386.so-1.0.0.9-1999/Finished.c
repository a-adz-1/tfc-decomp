// Finished__11CBaseEntity  @ 0010ddd0
void Finished__11CBaseEntity(void)

{
  return;
}


// Finished__12CTFDispenser  @ 000a8460
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
  ClientPrint__FP9entvars_tiPCcN42(*puVar2);
  piVar3 = (int *)__rf__7EHANDLE(piVar5,0,0);
  uVar4 = __opP11CBaseEntity__7EHANDLE
                    (piVar5,1,"#Dispenser_built",*(int *)(*piVar3 + 0x1b0) + (int)gpGlobals[0x26]);
  teamsprint__FiP11CBaseEntityiPCcN33(param_1[0x48],uVar4);
  piVar3 = (int *)__rf__7EHANDLE(piVar5);
  uVar4 = (*DAT_00175684)(*(undefined4 *)(*piVar3 + 0x1e8));
  piVar3 = (int *)__rf__7EHANDLE(piVar5,uVar4);
  UTIL_LogPrintf__FPce
            ("\"%s<%i>\" built a \"dispenser\".\n",*(int *)(*piVar3 + 0x1b0) + (int)gpGlobals[0x26])
  ;
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + -100;
  *(undefined4 *)(*param_1 + 0x14c) = 0x40000000;
  param_1[5] = -0x10000;
  param_1[6] = (int)DispenserTouch__12CTFDispenserP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)DispenserThink__12CTFDispenser;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 12.0;
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41000000;
  *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
  iVar1 = __rf__7EHANDLE(piVar5);
  param_1[0x33] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xcc) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar5);
  param_1[0x35] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xd4) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar5);
  param_1[0x39] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xe4) * 0.25));
  iVar1 = __rf__7EHANDLE(piVar5);
  param_1[0x37] = (int)ROUND(ROUND((double)*(int *)(iVar1 + 0xdc) * 0.25));
  piVar3 = (int *)__rf__7EHANDLE(piVar5);
  *(float *)(*param_1 + 0x19c) = ROUND(*(float *)(*piVar3 + 0x19c) * 0.25);
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xcc) = (int)ROUND(ROUND((double)param_1[0x33] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xd4) = (int)ROUND(ROUND((double)param_1[0x35] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xe4) = (int)ROUND(ROUND((double)param_1[0x39] * 0.75));
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xdc) = (int)ROUND(ROUND((double)param_1[0x37] * 0.75));
  piVar5 = (int *)__rf__7EHANDLE(piVar5);
  *(float *)(*piVar5 + 0x19c) = ROUND(*(float *)(*param_1 + 0x19c) * 0.75);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),1,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100);
  return;
}


// Finished__16CTFSentrygunBase  @ 000e90c0
void Finished__16CTFSentrygunBase(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  longdouble lVar6;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar5 = param_1 + 0x51;
  iVar1 = __rf__7EHANDLE(piVar5);
  *(undefined4 *)(iVar1 + 0x150) = 0x3f800000;
  puVar2 = (undefined4 *)__rf__7EHANDLE(piVar5,1,"#Sentry_finish",0,0,0,0);
  ClientPrint__FP9entvars_tiPCcN42(*puVar2);
  piVar3 = (int *)__rf__7EHANDLE(piVar5,0,0);
  uVar4 = __opP11CBaseEntity__7EHANDLE
                    (piVar5,1,"#Sentry_built",*(int *)(*piVar3 + 0x1b0) + *(int *)(gpGlobals + 0x98)
                    );
  teamsprint__FiP11CBaseEntityiPCcN33(param_1[0x48],uVar4);
  piVar3 = (int *)__rf__7EHANDLE(piVar5);
  uVar4 = (*DAT_00175684)(*(undefined4 *)(*piVar3 + 0x1e8));
  piVar3 = (int *)__rf__7EHANDLE(piVar5,uVar4);
  UTIL_LogPrintf__FPce
            ("\"%s<%i>\" built a \"sentry\".\n",
             *(int *)(*piVar3 + 0x1b0) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x14c) = 0x40000000;
  iVar1 = __rf__7EHANDLE(piVar5);
  *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + -0x82;
  local_10 = 0x41800000;
  local_c = 0x41800000;
  local_8 = 0x40800000;
  local_1c = -16.0;
  local_18 = -16.0;
  local_14 = 0.0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_1c,&local_10);
  piVar5 = (int *)GetClassPtr__H1Z12CTFSentrygun_PX01_PX01(0);
  (**(code **)(piVar5[0xf2] + 8))(piVar5);
  iVar1 = param_1[0x52];
  piVar5[0x51] = param_1[0x51];
  piVar5[0x52] = iVar1;
  piVar5[0x48] = param_1[0x48];
  *(uint *)(*piVar5 + 0x188) =
       (*(int *)(teamcolors + param_1[0x48] * 4) + 10U & 0xff) * 0x100 +
       *(int *)(teamcolors + param_1[0x48] * 4);
  __as__7EHANDLEP11CBaseEntity(piVar5 + 0x26,param_1);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x26,piVar5);
  local_10 = 0;
  local_c = 0;
  local_8 = 0x41a9999a;
  iVar1 = *param_1;
  local_1c = *(float *)(iVar1 + 8) + 0.0;
  local_18 = *(float *)(iVar1 + 0xc) + 0.0;
  local_14 = *(float *)(iVar1 + 0x10) + 21.2;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar5,&local_1c);
  *(undefined4 *)(*piVar5 + 0x54) = *(undefined4 *)(*param_1 + 0x54);
  lVar6 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*piVar5 + 0x54));
  piVar5[0x189] = (int)(float)lVar6;
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
  piVar5[0x18c] = (int)(float)piVar5[0x28];
  piVar5[0x188] = 0;
  piVar5[0x18b] = 0;
  piVar5[0x184] = 1;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar5 + 0x1e8),3,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100);
  return;
}


