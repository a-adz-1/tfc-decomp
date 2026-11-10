// CheckPowerups__11CBasePlayer  @ 000d9170
void CheckPowerups__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  longdouble lVar7;
  undefined4 local_c;
  undefined4 local_4;
  
  if (*(float *)(*param_1 + 0x160) <= 0.0) {
    return;
  }
  *(undefined4 *)(*param_1 + 0xb4) = g_ulModelIndexPlayer;
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  fVar1 = (float)param_1[0x108];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((*(byte *)(param_1 + 0x21) & 0x40) != 0) {
      param_1[0x108] = (int)(*gpGlobals + 10.0);
    }
    bVar5 = true;
    fVar2 = *gpGlobals + 3.0;
    fVar1 = (float)param_1[0x108];
    if ((0x3f < (byte)((fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
       (param_1[0x10c] == 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_ringfade",0,0,0,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"items/inv2.wav",0x3f800000,0x3f4ccccd,0,100);
      param_1[0x10c] = 1;
    }
    if ((float)param_1[0x108] < *gpGlobals) {
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xf7;
      param_1[0x108] = 0;
      param_1[0x10c] = 0;
      bVar5 = false;
      *(undefined4 *)(*param_1 + 0x148) = 0;
      *(undefined4 *)(*param_1 + 0x15c) = 0;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
    }
  }
  fVar1 = (float)param_1[0x107];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((*(byte *)(param_1 + 0x21) & 0x20) != 0) {
      param_1[0x107] = (int)(*gpGlobals + 10.0);
    }
    fVar2 = *gpGlobals + 3.0;
    fVar1 = (float)param_1[0x107];
    if ((0x3f < (byte)((fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
       (param_1[0x10b] == 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_pentfade",0,0,0,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"items/protect2.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      param_1[0x10b] = 1;
    }
    if (*gpGlobals <= (float)param_1[0x107]) {
      bVar4 = true;
    }
    else {
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xef;
      param_1[0x107] = 0;
      param_1[0x10b] = 0;
      *(undefined4 *)(*param_1 + 0x15c) = 0;
      iVar6 = *param_1;
      *(undefined4 *)(iVar6 + 0x150) = g_vecZero;
      *(undefined4 *)(iVar6 + 0x154) = DAT_001c0fe4;
      *(undefined4 *)(iVar6 + 0x158) = DAT_001c0fe8;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
    }
  }
  fVar1 = (float)param_1[0x109];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((char)param_1[0x21] < '\0') {
      param_1[0x109] = (int)(*gpGlobals + 10.0);
    }
    fVar2 = *gpGlobals + 3.0;
    fVar1 = (float)param_1[0x109];
    if ((0x3f < (byte)((fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
       (param_1[0x10d] == 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_quadfade",0,0,0,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"items/damage3.wav",0x3f800000,0x3f4ccccd,0,100
                );
      param_1[0x10d] = 1;
    }
    if (*gpGlobals <= (float)param_1[0x109]) {
      bVar3 = true;
    }
    else {
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xbf;
      param_1[0x109] = 0;
      param_1[0x10d] = 0;
      *(undefined4 *)(*param_1 + 0x15c) = 0;
      iVar6 = *param_1;
      *(undefined4 *)(iVar6 + 0x150) = g_vecZero;
      *(undefined4 *)(iVar6 + 0x154) = DAT_001c0fe4;
      *(undefined4 *)(iVar6 + 0x158) = DAT_001c0fe8;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
    }
  }
  fVar1 = (float)param_1[0x10a];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    *(float *)(*param_1 + 0x1fc) = *gpGlobals + 12.0;
    if ((*(byte *)((int)param_1 + 0x85) & 1) != 0) {
      param_1[0x10a] = (int)(*gpGlobals + 10.0);
    }
    fVar2 = *gpGlobals + 3.0;
    fVar1 = (float)param_1[0x10a];
    if ((0x3f < (byte)((fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
       (param_1[0x10e] == 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_suitfade",0,0,0,0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"FVox/hev_shutdown.wav",0x3f800000,0x3f4ccccd,0
                 ,100);
      param_1[0x10e] = 1;
    }
    if ((float)param_1[0x10a] < *gpGlobals) {
      *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) & 0xdf;
      param_1[0x10a] = 0;
      param_1[0x10e] = 0;
    }
  }
  if (((!bVar4) && (!bVar3)) || (*(int *)(*param_1 + 0x15c) != 0)) goto LAB_000d96e6;
  *(undefined4 *)(*param_1 + 0x15c) = 0x13;
  *(undefined4 *)(*param_1 + 0x14c) = 0x42c80000;
  if (bVar4) {
    if (bVar3) {
      iVar6 = *param_1;
      local_c = 0x437f0000;
      goto LAB_000d96be;
    }
    if (!bVar4) goto LAB_000d96a4;
    iVar6 = *param_1;
    local_c = 0x437f0000;
    local_4 = 0;
  }
  else {
LAB_000d96a4:
    if (!bVar3) goto LAB_000d96e6;
    iVar6 = *param_1;
    local_c = 0x43000000;
LAB_000d96be:
    local_4 = 0x437f0000;
  }
  *(undefined4 *)(iVar6 + 0x150) = local_c;
  *(undefined4 *)(iVar6 + 0x154) = 0x43000000;
  *(undefined4 *)(iVar6 + 0x158) = local_4;
LAB_000d96e6:
  if (bVar5) {
    *(undefined4 *)(*param_1 + 0x148) = 5;
    lVar7 = (longdouble)(*DAT_001c118c)(0x3f800000,0x437f0000);
    *(float *)(*param_1 + 0x14c) = (float)(int)ROUND(lVar7);
  }
  return;
}


