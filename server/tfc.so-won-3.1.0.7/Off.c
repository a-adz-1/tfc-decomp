// Off__11CWallHealth  @ 000b6618
void Off__11CWallHealth(int *param_1)

{
  code *pcVar1;
  longdouble lVar2;
  
  if (1 < param_1[0x13d]) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"items/medcharge4.wav",0,0,0x20,100);
  }
  param_1[0x13d] = 0;
  if (param_1[0x13c] == 0) {
    lVar2 = (longdouble)(**(code **)(*g_pGameRules + 0xbc))(g_pGameRules);
    param_1[0x13b] = (int)ROUND(lVar2);
    if (0 < (int)ROUND(lVar2)) {
      *(float *)(*param_1 + 0x104) = (float)param_1[0x13b] + *(float *)(*param_1 + 0x100);
      pcVar1 = Recharge__11CWallHealth;
      goto LAB_000b66de;
    }
  }
  pcVar1 = SUB_DoNothing__11CBaseEntity;
LAB_000b66de:
  param_1[3] = -0x10000;
  param_1[4] = (int)pcVar1;
  return;
}


// Off__19CMomentaryRotButton  @ 0008cfe4
void Off__19CMomentaryRotButton(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 100) = DAT_001c0fe8;
  param_1[0x13a] = 0;
  iVar1 = *param_1;
  if (((*(byte *)(iVar1 + 0x1a0) & 0x10) == 0) || ((float)param_1[0x13c] <= 0.0)) {
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)Return__19CMomentaryRotButton;
    *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + 0.1;
    param_1[0x13b] = -1;
  }
  return;
}


// Off__9CRecharge  @ 000b3b3c
void Off__9CRecharge(int *param_1)

{
  code *pcVar1;
  longdouble lVar2;
  
  if (1 < param_1[0x13d]) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"items/suitcharge1.wav",0,0,0x20,100);
  }
  param_1[0x13d] = 0;
  if (param_1[0x13c] == 0) {
    lVar2 = (longdouble)(**(code **)(*g_pGameRules + 0xc0))(g_pGameRules);
    param_1[0x13b] = (int)ROUND(lVar2);
    if (0 < (int)ROUND(lVar2)) {
      *(float *)(*param_1 + 0x104) = (float)param_1[0x13b] + *(float *)(*param_1 + 0x100);
      pcVar1 = Recharge__9CRecharge;
      goto LAB_000b3c02;
    }
  }
  pcVar1 = SUB_DoNothing__11CBaseEntity;
LAB_000b3c02:
  param_1[3] = -0x10000;
  param_1[4] = (int)pcVar1;
  return;
}


