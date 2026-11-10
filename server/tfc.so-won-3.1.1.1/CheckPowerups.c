// CheckPowerups__11CBasePlayer  @ 000d8ae0
void CheckPowerups__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  longdouble lVar8;
  undefined4 local_8;
  
  if (*(float *)(*param_1 + 0x160) <= 0.0) {
    return;
  }
  bVar3 = false;
  *(undefined4 *)(*param_1 + 0xb4) = g_ulModelIndexPlayer;
  bVar5 = false;
  bVar4 = false;
  fVar1 = (float)param_1[0x10c];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((*(byte *)(param_1 + 0x21) & 0x40) != 0) {
      fVar1 = *gpGlobals + 10.0;
      param_1[0x10c] = (int)fVar1;
    }
    bVar5 = true;
    fVar2 = *gpGlobals + 3.0;
    if ((0x3f < (byte)((fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
       (param_1[0x110] == 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_ringfade",0,0,0,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"items/inv2.wav",0x3f800000,0x3f4ccccd,0,100);
      param_1[0x110] = 1;
      fVar1 = (float)param_1[0x10c];
    }
    if (fVar1 < *gpGlobals) {
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xf7;
      param_1[0x110] = 0;
      bVar5 = false;
      param_1[0x10c] = 0;
      *(undefined4 *)(*param_1 + 0x148) = 0;
      *(undefined4 *)(*param_1 + 0x15c) = 0;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
    }
  }
  fVar1 = (float)param_1[0x10b];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((*(byte *)(param_1 + 0x21) & 0x20) != 0) {
      fVar1 = *gpGlobals + 10.0;
      param_1[0x10b] = (int)fVar1;
    }
    fVar2 = *gpGlobals + 3.0;
    if ((0x3f < (byte)((fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
       (param_1[0x10f] == 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_pentfade",0,0,0,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"items/protect2.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      param_1[0x10f] = 1;
      fVar1 = (float)param_1[0x10b];
    }
    if (*gpGlobals <= fVar1) {
      bVar4 = true;
    }
    else {
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xef;
      param_1[0x10f] = 0;
      param_1[0x10b] = 0;
      *(undefined4 *)(*param_1 + 0x15c) = 0;
      iVar7 = *param_1;
      *(undefined4 *)(iVar7 + 0x150) = g_vecZero;
      *(undefined4 *)(iVar7 + 0x154) = DAT_0019f664;
      *(undefined4 *)(iVar7 + 0x158) = DAT_0019f668;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
    }
  }
  fVar1 = (float)param_1[0x10d];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((char)param_1[0x21] < '\0') {
      fVar1 = *gpGlobals + 10.0;
      param_1[0x10d] = (int)fVar1;
    }
    fVar2 = *gpGlobals + 3.0;
    if ((0x3f < (byte)((fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
       (param_1[0x111] == 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_quadfade",0,0,0,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"items/damage3.wav",0x3f800000,0x3f4ccccd,0,100
                );
      param_1[0x111] = 1;
      fVar1 = (float)param_1[0x10d];
    }
    if (*gpGlobals <= fVar1) {
      bVar3 = true;
    }
    else {
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xbf;
      param_1[0x111] = 0;
      param_1[0x10d] = 0;
      *(undefined4 *)(*param_1 + 0x15c) = 0;
      iVar7 = *param_1;
      *(undefined4 *)(iVar7 + 0x150) = g_vecZero;
      *(undefined4 *)(iVar7 + 0x154) = DAT_0019f664;
      *(undefined4 *)(iVar7 + 0x158) = DAT_0019f668;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
    }
  }
  fVar1 = (float)param_1[0x10e];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    *(float *)(*param_1 + 0x1fc) = *gpGlobals + 12.0;
    if ((*(byte *)((int)param_1 + 0x85) & 1) != 0) {
      param_1[0x10e] = (int)(*gpGlobals + 10.0);
    }
    fVar1 = (float)param_1[0x10e];
    if ((fVar1 < *gpGlobals + 3.0) && (param_1[0x112] == 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_suitfade",0,0,0,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"FVox/hev_shutdown.wav",0x3f800000,0x3f4ccccd,0
                 ,100);
      param_1[0x112] = 1;
      fVar1 = (float)param_1[0x10e];
    }
    if (fVar1 < *gpGlobals) {
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xdf;
      param_1[0x10e] = 0;
      param_1[0x112] = 0;
    }
  }
  if (((!bVar4) && (!bVar3)) || (*(int *)(*param_1 + 0x15c) != 0)) goto LAB_000d9030;
  *(undefined4 *)(*param_1 + 0x15c) = 0x13;
  *(undefined4 *)(*param_1 + 0x14c) = 0x42c80000;
  if (bVar4) {
    if (bVar3) {
      iVar7 = *param_1;
      uVar6 = 0x437f0000;
      goto LAB_000d9012;
    }
    iVar7 = *param_1;
    uVar6 = 0x437f0000;
    local_8 = 0;
  }
  else {
    if (!bVar3) goto LAB_000d9030;
    iVar7 = *param_1;
    uVar6 = 0x43000000;
LAB_000d9012:
    local_8 = 0x437f0000;
  }
  *(undefined4 *)(iVar7 + 0x150) = uVar6;
  *(undefined4 *)(iVar7 + 0x154) = 0x43000000;
  *(undefined4 *)(iVar7 + 0x158) = local_8;
LAB_000d9030:
  if (bVar5) {
    *(undefined4 *)(*param_1 + 0x148) = 5;
    lVar8 = (longdouble)(*DAT_0019f80c)(0x3f800000,0x437f0000);
    *(float *)(*param_1 + 0x14c) = (float)(int)ROUND(lVar8);
  }
  return;
}


