// GetPlayerSpawnSpot__10CGameRulesP11CBasePlayer  @ 000a3240
void GetPlayerSpawnSpot__10CGameRulesP11CBasePlayer(undefined4 param_1,int *param_2)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  longdouble lVar9;
  int *local_20;
  
  iVar3 = EntSelectSpawnPoint__FP7edict_s(*(undefined4 *)(*param_2 + 0x208));
  iVar6 = *param_2;
  iVar7 = iVar3 + 0x80;
  if (iVar3 == 0) {
    iVar7 = 0;
  }
  uVar8 = *(undefined4 *)(iVar7 + 0xc);
  fVar1 = *(float *)(iVar7 + 0x10);
  *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar7 + 8);
  *(undefined4 *)(iVar6 + 0xc) = uVar8;
  *(float *)(iVar6 + 0x10) = fVar1 + 1.0;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_2,*param_2 + 8);
  iVar6 = *param_2;
  *(undefined4 *)(iVar6 + 0x74) = g_vecZero;
  *(undefined4 *)(iVar6 + 0x78) = DAT_001a7e04;
  *(undefined4 *)(iVar6 + 0x7c) = DAT_001a7e08;
  iVar6 = *param_2;
  *(undefined4 *)(iVar6 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar6 + 0x24) = DAT_001a7e04;
  *(undefined4 *)(iVar6 + 0x28) = DAT_001a7e08;
  iVar6 = iVar3 + 0x80;
  if (iVar3 == 0) {
    iVar6 = 0;
  }
  iVar7 = *param_2;
  *(undefined4 *)(iVar7 + 0x50) = *(undefined4 *)(iVar6 + 0x50);
  *(undefined4 *)(iVar7 + 0x54) = *(undefined4 *)(iVar6 + 0x54);
  *(undefined4 *)(iVar7 + 0x58) = *(undefined4 *)(iVar6 + 0x58);
  iVar6 = *param_2;
  *(undefined4 *)(iVar6 + 0x68) = g_vecZero;
  *(undefined4 *)(iVar6 + 0x6c) = DAT_001a7e04;
  *(undefined4 *)(iVar6 + 0x70) = DAT_001a7e08;
  *(undefined4 *)(*param_2 + 0xa0) = 1;
  if (*(int *)(*param_2 + 0x20c) != 0) {
    piVar4 = (int *)GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(0);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar4,*param_2 + 8);
    *(undefined4 *)(*piVar4 + 0x198) = *(undefined4 *)(*param_2 + 0x208);
    (**(code **)(piVar4[0xf5] + 8))(piVar4);
  }
  lVar9 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
  if (lVar9 <= (longdouble)0.5) {
    uVar8 = *(undefined4 *)(*param_2 + 0x208);
    pcVar5 = "misc/r_tele4.wav";
  }
  else {
    uVar8 = *(undefined4 *)(*param_2 + 0x208);
    pcVar5 = "misc/r_tele3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar8,2,pcVar5,0x3f800000,0x3f4ccccd,0,100);
  if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar3 + 0x7c);
  }
  iVar6 = (**(code **)(piVar4[0xf5] + 0x28))(piVar4);
  if ((iVar6 == 0x83) && (cb_prematch_time < *gpGlobals)) {
    if ((*(int *)(*piVar4 + 0x1d4) != 0) &&
       ((param_2[0x342] == 0 &&
        (ClientPrint__FP9entvars_siPCcN42
                   (*param_2,4,*(int *)(*piVar4 + 0x1d4) + (int)gpGlobals[0x26],0,0,0,0),
        (*(byte *)(piVar4 + 0x88) & 2) == 0)))) {
      *(undefined4 *)(*piVar4 + 0x1d4) = 0;
    }
    DoResults__FP11CBaseEntityP11CBasePlayeri(piVar4,param_2,1);
    if ((piVar4[0x22] != 0) && (((*(byte *)(piVar4 + 0x88) ^ 1) & 1) != 0)) {
      piVar4[0x22] = 0;
    }
    if (piVar4[0x89] == 1) {
      piVar4[0x86] = 3;
    }
  }
  param_2[0x342] = 0;
  if (cease_fire != 0) {
    ClientPrint__FP9entvars_siPCcN42(*param_2,4,"#Game_ceasefire",0,0,0,0);
    UTIL_LogPrintf__FPce("CEASE FIRE\n");
    param_2[99] = (int)(*gpGlobals + 10.0);
    *(byte *)((int)param_2 + 0x86) = *(byte *)((int)param_2 + 0x86) | 1;
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  local_20 = (int *)0x0;
  while( true ) {
    local_20 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(local_20,"player");
    if (local_20 == (int *)0x0) {
      return;
    }
    bVar2 = false;
    if ((*(int *)(*local_20 + 0x208) == 0) ||
       (iVar6 = (*DAT_001a7f58)(*(int *)(*local_20 + 0x208)), iVar6 == 0)) {
      bVar2 = true;
    }
    if (bVar2) break;
    if ((((*local_20 != 0) && (local_20 != param_2)) &&
        (iVar6 = *local_20, iVar3 = (*DAT_001a7f5c)(*(undefined4 *)(*param_2 + 0x208)),
        *(int *)(iVar6 + 0x248) == iVar3)) &&
       (piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(local_20 + 0x33f), piVar4 == param_2)) {
      iVar6 = *local_20;
      iVar3 = *param_2;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar3 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
      UTIL_SetOrigin__FP9entvars_sRC6Vector(*local_20,*local_20 + 8);
    }
  }
  return;
}


