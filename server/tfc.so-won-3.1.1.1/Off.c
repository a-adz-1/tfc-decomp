// Off__11CWallHealth  @ 000b5650
void Off__11CWallHealth(int *param_1)

{
  int iVar1;
  code *pcVar2;
  longdouble lVar3;
  
  if (1 < param_1[0x141]) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"items/medcharge4.wav",0,0,0x20,100);
  }
  param_1[0x141] = 0;
  if (param_1[0x140] == 0) {
    lVar3 = (longdouble)(**(code **)(*g_pGameRules + 0xbc))(g_pGameRules);
    iVar1 = (int)ROUND(lVar3);
    param_1[0x13f] = iVar1;
    if (0 < iVar1) {
      *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + (float)iVar1;
      pcVar2 = Recharge__11CWallHealth;
      goto LAB_000b570e;
    }
  }
  pcVar2 = SUB_DoNothing__11CBaseEntity;
LAB_000b570e:
  param_1[3] = -0x10000;
  param_1[4] = (int)pcVar2;
  return;
}


// Off__19CMomentaryRotButton  @ 0008c7f4
void Off__19CMomentaryRotButton(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
  iVar1 = *param_1;
  param_1[0x13e] = 0;
  if (((*(byte *)(iVar1 + 0x1a0) & 0x10) == 0) || ((float)param_1[0x140] <= 0.0)) {
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)Return__19CMomentaryRotButton;
    *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + 0.1;
    param_1[0x13f] = -1;
  }
  return;
}


// Off__9CRecharge  @ 000b2d10
void Off__9CRecharge(int *param_1)

{
  int iVar1;
  code *pcVar2;
  longdouble lVar3;
  
  if (1 < param_1[0x141]) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"items/suitcharge1.wav",0,0,0x20,100);
  }
  param_1[0x141] = 0;
  if (param_1[0x140] == 0) {
    lVar3 = (longdouble)(**(code **)(*g_pGameRules + 0xc0))(g_pGameRules);
    iVar1 = (int)ROUND(lVar3);
    param_1[0x13f] = iVar1;
    if (0 < iVar1) {
      *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + (float)iVar1;
      pcVar2 = Recharge__9CRecharge;
      goto LAB_000b2dce;
    }
  }
  pcVar2 = SUB_DoNothing__11CBaseEntity;
LAB_000b2dce:
  param_1[3] = -0x10000;
  param_1[4] = (int)pcVar2;
  return;
}


