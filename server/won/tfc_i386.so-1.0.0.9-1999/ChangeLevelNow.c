// ChangeLevelNow__12CChangeLevelP11CBaseEntity  @ 00111260
void ChangeLevelNow__12CChangeLevelP11CBaseEntity(int *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  
  iVar6 = 0xf;
  do {
    bVar8 = iVar6 != 0;
    iVar6 = iVar6 + -1;
  } while (bVar8);
  if ((byte)((byte)((ushort)((ushort)NAN(gpGlobals[5]) << 10) >> 8) |
            (byte)((ushort)((ushort)(gpGlobals[5] == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(*param_1 + 0x1c4);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0x1c4) = fVar1;
      iVar6 = (*DAT_001755e0)(1);
      if ((iVar6 == 0) && (iVar6 = (*DAT_001755d4)(0), iVar6 == 0)) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = *(int **)(iVar6 + 0xd8);
      }
      iVar6 = InTransitionVolume__12CChangeLevelP11CBaseEntityPc(piVar7,param_1 + 0x123);
      if (iVar6 == 0) {
        (*DAT_001755b4)(2,"Player isn\'t in the transition volume %s, aborting\n",param_1 + 0x123);
      }
      else {
        if ((param_1[299] != 0) &&
           (piVar4 = (int *)GetClassPtr__H1Z11CFireAndDie_PX01_PX01(0), piVar4 != (int *)0x0)) {
          *(int *)(*piVar4 + 0x1a8) = param_1[299];
          piVar4[0xf3] = param_1[300];
          iVar6 = *piVar4;
          iVar5 = *piVar7;
          *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar5 + 8);
          *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar5 + 0xc);
          *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar5 + 0x10);
          DispatchSpawn__FP7edict_s(*(undefined4 *)(*piVar4 + 0x1e8));
        }
        strcpy(st_szNextMap,(char *)(param_1 + 0x11b));
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x10f,param_2);
        SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2,3,0);
        st_szNextSpot[0] = 0;
        iVar6 = FindLandmark__12CChangeLevelPCc(param_1 + 0x123);
        bVar8 = false;
        if ((iVar6 == 0) || (iVar5 = (*DAT_001755d8)(iVar6), iVar5 == 0)) {
          bVar8 = true;
        }
        if (!bVar8) {
          strcpy(st_szNextSpot,(char *)(param_1 + 0x123));
          pfVar3 = gpGlobals;
          iVar5 = iVar6 + 0xdc;
          if (iVar6 == 0) {
            iVar5 = 0;
          }
          gpGlobals[0x28] = *(float *)(iVar5 + 8);
          pfVar3[0x29] = *(float *)(iVar5 + 0xc);
          pfVar3[0x2a] = *(float *)(iVar5 + 0x10);
        }
        (*DAT_001755b4)(1,"CHANGE LEVEL: %s %s\n",st_szNextMap,st_szNextSpot);
        (*DAT_001754d8)(st_szNextMap,st_szNextSpot);
      }
    }
  }
  return;
}


