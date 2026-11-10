// Respawn__11CBaseEntity  @ 0010f6f4
undefined4 Respawn__11CBaseEntity(void)

{
  return 0;
}


// Respawn__15CBasePlayerAmmo  @ 00120c00
int * Respawn__15CBasePlayerAmmo(int *param_1)

{
  longdouble lVar1;
  undefined1 local_c [12];
  
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  param_1[5] = 0;
  param_1[6] = 0;
  (**(code **)(*g_pGameRules + 0xb8))(local_c,g_pGameRules,param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,local_c);
  param_1[3] = -0x10000;
  param_1[4] = (int)Materialize__15CBasePlayerAmmo;
  lVar1 = (longdouble)(**(code **)(*g_pGameRules + 0xb4))(g_pGameRules,param_1);
  *(float *)(*param_1 + 0x104) = (float)lVar1;
  return param_1;
}


// Respawn__15CBasePlayerItem  @ 0011fca0
int * Respawn__15CBasePlayerItem(int *param_1)

{
  int *piVar1;
  longdouble lVar2;
  undefined1 local_c [12];
  
  (**(code **)(*g_pGameRules + 0x90))(local_c,g_pGameRules,param_1);
  piVar1 = (int *)*param_1;
  piVar1 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                            (*piVar1 + *(int *)(gpGlobals + 0x98),local_c,piVar1 + 0x14,piVar1[0x66]
                            );
  if (piVar1 == (int *)0x0) {
    (*DAT_001c1114)(1,"Respawn failed to create %s!\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98)
                   );
  }
  else {
    *(byte *)(*piVar1 + 0x118) = *(byte *)(*piVar1 + 0x118) | 0x80;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[3] = -0x10000;
    piVar1[4] = (int)AttemptToMaterialize__15CBasePlayerItem;
    (*DAT_001c1088)(*(undefined4 *)(*param_1 + 0x208));
    lVar2 = (longdouble)(**(code **)(*g_pGameRules + 0x88))(g_pGameRules,param_1);
    *(float *)(*piVar1 + 0x104) = (float)lVar2;
  }
  return piVar1;
}


// Respawn__5CItem  @ 000b6bdc
int * Respawn__5CItem(int *param_1)

{
  longdouble lVar1;
  undefined1 local_c [12];
  
  param_1[5] = 0;
  param_1[6] = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  (**(code **)(*g_pGameRules + 0xa4))(local_c,g_pGameRules,param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,local_c);
  param_1[3] = -0x10000;
  param_1[4] = (int)Materialize__5CItem;
  lVar1 = (longdouble)(**(code **)(*g_pGameRules + 0xa0))(g_pGameRules,param_1);
  *(float *)(*param_1 + 0x104) = (float)lVar1;
  return param_1;
}


