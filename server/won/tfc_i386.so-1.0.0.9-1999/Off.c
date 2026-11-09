// Off__11CWallHealth  @ 000bd2a0
void Off__11CWallHealth(int *param_1)

{
  code *pcVar1;
  longdouble lVar2;
  
  if (1 < param_1[0x11e]) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),6,"items/medcharge4.wav",0,0,0x20,100);
  }
  param_1[0x11e] = 0;
  if (param_1[0x11d] == 0) {
    lVar2 = (longdouble)(**(code **)(*g_pGameRules + 0xbc))(g_pGameRules);
    param_1[0x11c] = (int)ROUND(lVar2);
    if (0 < (int)ROUND(lVar2)) {
      *(float *)(*param_1 + 0xe4) = (float)param_1[0x11c] + *(float *)(*param_1 + 0xe0);
      pcVar1 = Recharge__11CWallHealth;
      goto LAB_000bd34d;
    }
  }
  pcVar1 = SUB_DoNothing__11CBaseEntity;
LAB_000bd34d:
  param_1[3] = -0x10000;
  param_1[4] = (int)pcVar1;
  return;
}


// Off__19CMomentaryRotButton  @ 0009f9b0
void Off__19CMomentaryRotButton(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar2 + 100) = DAT_00175488;
  param_1[0x11b] = 0;
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x180) & 0x10) == 0) ||
     (fVar1 = (float)param_1[0x11d],
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)Return__19CMomentaryRotButton;
    *(float *)(iVar2 + 0xe4) = *(float *)(iVar2 + 0xe0) + 0.1;
    param_1[0x11c] = -1;
  }
  return;
}


// Off__9CRecharge  @ 000baef0
void Off__9CRecharge(int *param_1)

{
  code *pcVar1;
  longdouble lVar2;
  
  if (1 < param_1[0x11e]) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),6,"items/suitcharge1.wav",0,0,0x20,100);
  }
  param_1[0x11e] = 0;
  if (param_1[0x11d] == 0) {
    lVar2 = (longdouble)(**(code **)(*g_pGameRules + 0xc0))(g_pGameRules);
    param_1[0x11c] = (int)ROUND(lVar2);
    if (0 < (int)ROUND(lVar2)) {
      *(float *)(*param_1 + 0xe4) = (float)param_1[0x11c] + *(float *)(*param_1 + 0xe0);
      pcVar1 = Recharge__9CRecharge;
      goto LAB_000baf9d;
    }
  }
  pcVar1 = SUB_DoNothing__11CBaseEntity;
LAB_000baf9d:
  param_1[3] = -0x10000;
  param_1[4] = (int)pcVar1;
  return;
}


