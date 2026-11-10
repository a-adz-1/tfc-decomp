// ChangeLevelNow__12CChangeLevelP11CBaseEntity  @ 0011306c
void ChangeLevelNow__12CChangeLevelP11CBaseEntity(int *param_1,undefined4 param_2)

{
  float fVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  float fVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  
  fVar5 = gpGlobals[5];
  if ((byte)(0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar5 = *gpGlobals;
    fVar1 = *(float *)(*param_1 + 0x1e4);
    if ((byte)(fVar1 < fVar5 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar5)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar5) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0x1e4) = fVar5;
      iVar4 = (*DAT_001c1140)(1);
      if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = *(int **)(iVar4 + 0x7c);
      }
      iVar4 = InTransitionVolume__12CChangeLevelP11CBaseEntityPc(piVar9,param_1 + 0x142);
      if (iVar4 == 0) {
        (*DAT_001c1114)(2,"Player isn\'t in the transition volume %s, aborting\n",param_1 + 0x142);
      }
      else {
        if ((param_1[0x14a] != 0) &&
           (piVar7 = (int *)GetClassPtr__H1Z11CFireAndDie_PX01_PX01(0), piVar7 != (int *)0x0)) {
          *(int *)(*piVar7 + 0x1c8) = param_1[0x14a];
          piVar7[0x112] = param_1[0x14b];
          iVar4 = *piVar7;
          iVar8 = *piVar9;
          *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar8 + 8);
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
          *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar8 + 0x10);
          DispatchSpawn__FP7edict_s(*(undefined4 *)(*piVar7 + 0x208));
        }
        strcpy(st_szNextMap,(char *)(param_1 + 0x13a));
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x12e,param_2);
        SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2,3,0);
        st_szNextSpot[0] = 0;
        iVar4 = FindLandmark__12CChangeLevelPCc(param_1 + 0x142);
        bVar2 = false;
        if ((iVar4 == 0) || (iVar8 = (*DAT_001c1138)(iVar4), iVar8 == 0)) {
          bVar2 = true;
        }
        if (!bVar2) {
          strcpy(st_szNextSpot,(char *)(param_1 + 0x142));
          pfVar3 = gpGlobals;
          iVar8 = iVar4 + 0x80;
          if (iVar4 == 0) {
            iVar8 = 0;
          }
          gpGlobals[0x28] = *(float *)(iVar8 + 8);
          pfVar3[0x29] = *(float *)(iVar8 + 0xc);
          pfVar3[0x2a] = *(float *)(iVar8 + 0x10);
        }
        (*DAT_001c1114)(1,"CHANGE LEVEL: %s %s\n",st_szNextMap,st_szNextSpot);
        (*DAT_001c1038)(st_szNextMap,0);
      }
    }
  }
  else {
    iVar4 = strcmp((char *)(param_1 + 0x13a),"");
    if (iVar4 == 0) {
      fVar5 = (float)(*DAT_001c112c)(&DAT_00153078);
      gpGlobals[3] = fVar5;
      param_1[0x13a] = 0x726f6632;
      *(undefined2 *)(param_1 + 0x13b) = 0x74;
    }
    pcVar6 = strstr((char *)(param_1 + 0x13a),".bsp");
    if (pcVar6 == (char *)0x0) {
      strcpy(st_szNextMap,(char *)(param_1 + 0x13a));
    }
    else {
      strncpy(st_szNextMap,(char *)(param_1 + 0x13a),(size_t)(pcVar6 + (-0x4e8 - (int)param_1)));
    }
    (*DAT_001c1038)(st_szNextMap,0);
  }
  return;
}


