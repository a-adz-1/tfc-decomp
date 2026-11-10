// ChangeLevelNow__12CChangeLevelP11CBaseEntity  @ 00115a10
void ChangeLevelNow__12CChangeLevelP11CBaseEntity(int *param_1,undefined4 param_2)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined1 **ppuVar8;
  bool bVar9;
  undefined1 *puStack_538;
  undefined4 uStack_534;
  int *piStack_530;
  int *local_514;
  
  iVar7 = 0xf;
  do {
    bVar9 = iVar7 != 0;
    iVar7 = iVar7 + -1;
  } while (bVar9);
  fVar3 = gpGlobals[5];
  if ((byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar3 = *gpGlobals;
    fVar1 = *(float *)(*param_1 + 0x1e4);
    if ((byte)(fVar1 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar3) << 0xe) >> 8)) == 0x40) {
      return;
    }
    *(float *)(*param_1 + 0x1e4) = fVar3;
    iVar7 = (*DAT_0019f7c0)();
    if ((iVar7 == 0) && (iVar7 = (*DAT_0019f7b4)(), iVar7 == 0)) {
      local_514 = (int *)0x0;
    }
    else {
      local_514 = *(int **)(iVar7 + 0x7c);
    }
    iVar7 = InTransitionVolume__12CChangeLevelP11CBaseEntityPc();
    if (iVar7 == 0) {
      piStack_530 = (int *)0x115bb5;
      (*DAT_0019f794)();
      return;
    }
    if ((param_1[0x14e] != 0) &&
       (piVar5 = (int *)GetClassPtr__H1Z11CFireAndDie_PX01_PX01(), piVar5 != (int *)0x0)) {
      *(int *)(*piVar5 + 0x1c8) = param_1[0x14e];
      piVar5[0x116] = param_1[0x14f];
      iVar7 = *local_514;
      iVar6 = *piVar5;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar7 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar7 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar7 + 0x10);
      DispatchSpawn__FP7edict_s();
    }
    strcpy(st_szNextMap,(char *)(param_1 + 0x13e));
    piStack_530 = param_1 + 0x132;
    uStack_534 = 0x115c4d;
    __as__7EHANDLEP11CBaseEntity();
    uStack_534 = 0;
    puStack_538 = (undefined1 *)0x3;
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2);
    st_szNextSpot = 0;
    iVar7 = FindLandmark__12CChangeLevelPCc();
    bVar9 = false;
    if ((iVar7 == 0) || (iVar6 = (*DAT_0019f7b8)(), iVar6 == 0)) {
      bVar9 = true;
    }
    if (!bVar9) {
      strcpy(&st_szNextSpot,(char *)(param_1 + 0x146));
      pfVar2 = gpGlobals;
      iVar6 = iVar7 + 0x80;
      if (iVar7 == 0) {
        iVar6 = 0;
      }
      gpGlobals[0x28] = *(float *)(iVar6 + 8);
      pfVar2[0x29] = *(float *)(iVar6 + 0xc);
      pfVar2[0x2a] = *(float *)(iVar6 + 0x10);
    }
    piStack_530 = (int *)0x1;
    uStack_534 = 0x115d17;
    (*DAT_0019f794)();
    uStack_534 = 0;
    ppuVar8 = &puStack_538;
    puStack_538 = st_szNextMap;
  }
  else {
    piVar5 = param_1 + 0x13e;
    iVar7 = strcmp((char *)piVar5,"");
    if (iVar7 == 0) {
      fVar3 = (float)(*DAT_0019f7ac)();
      gpGlobals[3] = fVar3;
      param_1[0x13e] = 0x726f6632;
      *(undefined2 *)(param_1 + 0x13f) = 0x74;
    }
    pcVar4 = strstr((char *)piVar5,".bsp");
    if (pcVar4 == (char *)0x0) {
      strcpy(st_szNextMap,(char *)piVar5);
    }
    else {
      piStack_530 = (int *)0x115ade;
      strncpy(st_szNextMap,(char *)piVar5,(size_t)(pcVar4 + (-0x4f8 - (int)param_1)));
    }
    ppuVar8 = (undefined1 **)&stack0xfffffad8;
  }
  *(undefined4 *)((int)ppuVar8 + -4) = 0x115d25;
  (*DAT_0019f6b8)();
  return;
}


