// CheckPowerups__11CBasePlayer  @ 000db670
void CheckPowerups__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  float *pfVar5;
  longdouble lVar6;
  
  if (0.0 < *(float *)(*param_1 + 0x140)) {
    *(undefined4 *)(*param_1 + 0x94) = g_ulModelIndexPlayer;
    bVar4 = false;
    fVar1 = (float)param_1[0xe9];
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      if ((*(byte *)(param_1 + 0x22) & 0x40) != 0) {
        param_1[0xe9] = (int)(*gpGlobals + 10.0);
      }
      bVar4 = true;
      if (((float)param_1[0xe9] < *gpGlobals + 3.0) && (param_1[0xed] == 0)) {
        ClientPrint__FP9entvars_tiPCcN42(*param_1,1,FUN_0013a038,0,0,0,0);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),2,"items/inv2.wav",0x3f800000,0x3f4ccccd,0,100)
        ;
        param_1[0xed] = 1;
      }
      fVar1 = (float)param_1[0xe9];
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        *(byte *)((int)param_1 + 0x8e) = *(byte *)((int)param_1 + 0x8e) & 0xf7;
        param_1[0xe9] = 0;
        param_1[0xed] = 0;
        bVar4 = false;
        *(undefined4 *)(*param_1 + 0x128) = 0;
        *(undefined4 *)(*param_1 + 0x13c) = 0;
        *(undefined4 *)(*param_1 + 300) = 0;
      }
    }
    if (bVar4) {
      *(undefined4 *)(*param_1 + 0x128) = 5;
      lVar6 = (longdouble)(*DAT_0017562c)(0x3f800000,0x437f0000);
      *(float *)(*param_1 + 300) = (float)(int)ROUND(lVar6);
    }
    fVar1 = (float)param_1[0xe8];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      if ((*(byte *)(param_1 + 0x22) & 0x20) != 0) {
        param_1[0xe8] = (int)(*gpGlobals + 10.0);
      }
      if (((float)param_1[0xe8] < *gpGlobals + 3.0) && (param_1[0xec] == 0)) {
        ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Item_pentfade",0,0,0,0);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),2,"items/protect2.wav",0x3f800000,0x3f4ccccd,0,
                   100);
        param_1[0xec] = 1;
      }
      fVar1 = (float)param_1[0xe8];
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        *(byte *)((int)param_1 + 0x8e) = *(byte *)((int)param_1 + 0x8e) & 0xef;
        param_1[0xe8] = 0;
        param_1[0xec] = 0;
      }
      fVar1 = (float)param_1[0xea];
      fVar2 = *gpGlobals;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        fVar1 = (float)param_1[0xe8];
        fVar2 = *gpGlobals;
        if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
          *(undefined4 *)(*param_1 + 0x13c) = 0;
          iVar3 = *param_1;
          *(undefined4 *)(iVar3 + 0x130) = g_vecZero;
          *(undefined4 *)(iVar3 + 0x134) = DAT_00175484;
          *(undefined4 *)(iVar3 + 0x138) = DAT_00175488;
          *(undefined4 *)(*param_1 + 300) = 0;
        }
      }
    }
    fVar1 = (float)param_1[0xea];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      if ((char)param_1[0x22] < '\0') {
        param_1[0xea] = (int)(*gpGlobals + 10.0);
      }
      if (((float)param_1[0xea] < *gpGlobals + 3.0) && (param_1[0xee] == 0)) {
        ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Item_quadfade",0,0,0,0);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),2,"items/damage3.wav",0x3f800000,0x3f4ccccd,0,
                   100);
        param_1[0xee] = 1;
      }
      fVar1 = (float)param_1[0xea];
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        *(byte *)((int)param_1 + 0x8e) = *(byte *)((int)param_1 + 0x8e) & 0xbf;
        param_1[0xea] = 0;
        param_1[0xee] = 0;
      }
      fVar1 = (float)param_1[0xea];
      fVar2 = *gpGlobals;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        fVar1 = (float)param_1[0xe8];
        fVar2 = *gpGlobals;
        if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
          *(undefined4 *)(*param_1 + 0x13c) = 0;
          iVar3 = *param_1;
          *(undefined4 *)(iVar3 + 0x130) = g_vecZero;
          *(undefined4 *)(iVar3 + 0x134) = DAT_00175484;
          *(undefined4 *)(iVar3 + 0x138) = DAT_00175488;
          *(undefined4 *)(*param_1 + 300) = 0;
        }
      }
    }
    pfVar5 = gpGlobals;
    fVar1 = (float)param_1[0xeb];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0x1dc) = *gpGlobals + 12.0;
      if ((*(byte *)((int)param_1 + 0x89) & 1) != 0) {
        param_1[0xeb] = (int)(*pfVar5 + 10.0);
      }
      if (((float)param_1[0xeb] < *gpGlobals + 3.0) && (param_1[0xef] == 0)) {
        ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Item_suitfade",0,0,0,0);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),2,"FVox/hev_shutdown.wav",0x3f800000,0x3f4ccccd
                   ,0,100);
        param_1[0xef] = 1;
      }
      fVar1 = (float)param_1[0xeb];
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        *(byte *)((int)param_1 + 0x8e) = *(byte *)((int)param_1 + 0x8e) & 0xdf;
        param_1[0xeb] = 0;
        param_1[0xef] = 0;
      }
    }
  }
  return;
}


