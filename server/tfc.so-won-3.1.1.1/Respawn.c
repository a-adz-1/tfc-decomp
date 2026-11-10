// Respawn__11CBaseEntity  @ 00112bb0
undefined4 Respawn__11CBaseEntity(void)

{
  return 0;
}


// Respawn__15CBasePlayerAmmo  @ 00125354
int * Respawn__15CBasePlayerAmmo(int *param_1)

{
  longdouble lVar1;
  undefined1 local_10 [12];
  
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  param_1[5] = 0;
  param_1[6] = 0;
  (**(code **)(*g_pGameRules + 0xb8))(local_10,g_pGameRules,param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,local_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)Materialize__15CBasePlayerAmmo;
  lVar1 = (longdouble)(**(code **)(*g_pGameRules + 0xb4))(g_pGameRules,param_1);
  *(float *)(*param_1 + 0x104) = (float)lVar1;
  return param_1;
}


// Respawn__15CBasePlayerItem  @ 00123e00
void Respawn__15CBasePlayerItem(void)

{
  FUN_00123e0e();
  return;
}


// Respawn__5CItem  @ 000b5fac
int * Respawn__5CItem(int *param_1)

{
  longdouble lVar1;
  undefined1 local_10 [12];
  
  param_1[5] = 0;
  param_1[6] = 0;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
  (**(code **)(*g_pGameRules + 0xa4))(local_10,g_pGameRules,param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,local_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)Materialize__5CItem;
  lVar1 = (longdouble)(**(code **)(*g_pGameRules + 0xa0))(g_pGameRules,param_1);
  *(float *)(*param_1 + 0x104) = (float)lVar1;
  return param_1;
}


