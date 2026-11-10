// GetPlayerSpawnSpot__10CGameRulesP11CBasePlayer  @ 000b6a00
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetPlayerSpawnSpot__10CGameRulesP11CBasePlayer(undefined4 param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  longdouble lVar9;
  char *pcVar10;
  
  iVar3 = EntSelectSpawnPoint__FP7edict_s(*(undefined4 *)(*param_2 + 0x1e8));
  iVar6 = *param_2;
  if (iVar3 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = iVar3 + 0xdc;
  }
  fVar1 = *(float *)(iVar7 + 0xc);
  fVar2 = *(float *)(iVar7 + 0x10);
  *(float *)(iVar6 + 8) = *(float *)(iVar7 + 8) + 0.0;
  *(float *)(iVar6 + 0xc) = fVar1 + 0.0;
  *(float *)(iVar6 + 0x10) = fVar2 + 1.0;
  iVar6 = *param_2;
  *(undefined4 *)(iVar6 + 0x74) = g_vecZero;
  *(undefined4 *)(iVar6 + 0x78) = DAT_00175484;
  *(undefined4 *)(iVar6 + 0x7c) = DAT_00175488;
  iVar6 = *param_2;
  *(undefined4 *)(iVar6 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar6 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar6 + 0x28) = DAT_00175488;
  if (iVar3 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = iVar3 + 0xdc;
  }
  iVar7 = *param_2;
  *(undefined4 *)(iVar7 + 0x50) = *(undefined4 *)(iVar6 + 0x50);
  *(undefined4 *)(iVar7 + 0x54) = *(undefined4 *)(iVar6 + 0x54);
  *(undefined4 *)(iVar7 + 0x58) = *(undefined4 *)(iVar6 + 0x58);
  iVar6 = *param_2;
  *(undefined4 *)(iVar6 + 0x68) = g_vecZero;
  *(undefined4 *)(iVar6 + 0x6c) = DAT_00175484;
  *(undefined4 *)(iVar6 + 0x70) = DAT_00175488;
  *(undefined4 *)(*param_2 + 0x80) = 1;
  if (param_2[0xb] != 0) {
    piVar4 = (int *)GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(0);
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar4,*param_2 + 8);
    *(undefined4 *)(*piVar4 + 0x178) = *(undefined4 *)(*param_2 + 0x1e8);
    (**(code **)(piVar4[0xf2] + 8))(piVar4);
  }
  lVar8 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
  lVar9 = (longdouble)_FUN_00131d08;
  if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) == 1) {
    uVar5 = *(undefined4 *)(*param_2 + 0x1e8);
    pcVar10 = "misc/r_tele3.wav";
  }
  else {
    uVar5 = *(undefined4 *)(*param_2 + 0x1e8);
    pcVar10 = "misc/r_tele4.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,2,pcVar10,0x3f800000,0x3f4ccccd,0,100);
  if (iVar3 == 0) {
    iVar3 = (*DAT_001755d4)(0);
    if (iVar3 == 0) {
      piVar4 = (int *)0x0;
      goto LAB_000b6bd2;
    }
  }
  piVar4 = *(int **)(iVar3 + 0xd8);
LAB_000b6bd2:
  iVar6 = (**(code **)(piVar4[0xf2] + 0x28))(piVar4);
  if (iVar6 == 0x83) {
    fVar1 = *gpGlobals;
    if ((byte)(cb_prematch_time < fVar1 |
               (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) == 1) {
      if ((*(int *)(*piVar4 + 0x1b4) != 0) && (param_2[0x338] == 0)) {
        ClientPrint__FP9entvars_tiPCcN42
                  (*param_2,4,*(int *)(*piVar4 + 0x1b4) + (int)gpGlobals[0x26],0,0,0,0);
        if ((*(byte *)(piVar4 + 0x88) & 2) == 0) {
          *(undefined4 *)(*piVar4 + 0x1b4) = 0;
        }
      }
      DoResults__FP11CBaseEntityP11CBasePlayeri(piVar4,param_2,1);
      if ((piVar4[0x23] != 0) && (((*(byte *)(piVar4 + 0x88) ^ 1) & 1) != 0)) {
        piVar4[0x23] = 0;
      }
      if (piVar4[0x89] == 1) {
        piVar4[0x86] = 3;
      }
    }
  }
  param_2[0x338] = 0;
  if (cease_fire != 0) {
    ClientPrint__FP9entvars_tiPCcN42(*param_2,4,"#Game_ceasefire",0,0,0,0);
    UTIL_LogPrintf__FPce("CEASE FIRE\n");
    param_2[99] = (int)(*gpGlobals + 10.0);
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 1;
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  return;
}


