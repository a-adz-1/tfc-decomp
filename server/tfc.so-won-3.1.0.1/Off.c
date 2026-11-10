// Off__11CWallHealth  @ 000ab578
void Off__11CWallHealth(int *param_1)

{
  code *pcVar1;
  longdouble lVar2;
  
  if (1 < param_1[0x121]) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"items/medcharge4.wav",0,0,0x20,100);
  }
  param_1[0x121] = 0;
  if (param_1[0x120] == 0) {
    lVar2 = (longdouble)(**(code **)(*g_pGameRules + 0xbc))(g_pGameRules);
    param_1[0x11f] = (int)ROUND(lVar2);
    if (0 < (int)ROUND(lVar2)) {
      *(float *)(*param_1 + 0x104) = (float)param_1[0x11f] + *(float *)(*param_1 + 0x100);
      pcVar1 = Recharge__11CWallHealth;
      goto LAB_000ab63e;
    }
  }
  pcVar1 = SUB_DoNothing__11CBaseEntity;
LAB_000ab63e:
  param_1[3] = -0x10000;
  param_1[4] = (int)pcVar1;
  return;
}


// Off__19CMomentaryRotButton  @ 00084fe0
void Off__19CMomentaryRotButton(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
  param_1[0x11e] = 0;
  iVar1 = *param_1;
  if (((*(byte *)(iVar1 + 0x1a0) & 0x10) == 0) || ((float)param_1[0x120] <= 0.0)) {
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)Return__19CMomentaryRotButton;
    *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + 0.1;
    param_1[0x11f] = -1;
  }
  return;
}


// Off__9CRecharge  @ 000a8bcc
void Off__9CRecharge(int *param_1)

{
  code *pcVar1;
  longdouble lVar2;
  
  if (1 < param_1[0x121]) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"items/suitcharge1.wav",0,0,0x20,100);
  }
  param_1[0x121] = 0;
  if (param_1[0x120] == 0) {
    lVar2 = (longdouble)(**(code **)(*g_pGameRules + 0xc0))(g_pGameRules);
    param_1[0x11f] = (int)ROUND(lVar2);
    if (0 < (int)ROUND(lVar2)) {
      *(float *)(*param_1 + 0x104) = (float)param_1[0x11f] + *(float *)(*param_1 + 0x100);
      pcVar1 = Recharge__9CRecharge;
      goto LAB_000a8c92;
    }
  }
  pcVar1 = SUB_DoNothing__11CBaseEntity;
LAB_000a8c92:
  param_1[3] = -0x10000;
  param_1[4] = (int)pcVar1;
  return;
}


