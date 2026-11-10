// WaterMove__11CBasePlayer  @ 000d8480
void WaterMove__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0xe8) == 8) {
    return;
  }
  if (*(float *)(iVar4 + 0x140) < 0.0) {
    return;
  }
  if (*(int *)(iVar4 + 0x1a0) == 3) {
    *(byte *)((int)param_1 + 0x5d2) = *(byte *)((int)param_1 + 0x5d2) & 0xf7;
    *(undefined1 *)(param_1 + 0x176) = 0;
    iVar4 = *param_1;
    fVar1 = *(float *)(iVar4 + 0x1dc);
    fVar2 = *gpGlobals;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      fVar1 = *(float *)(iVar4 + 0x1e0);
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        *(float *)(iVar4 + 0x1c0) = *(float *)(iVar4 + 0x1c0) + 1.0;
        fVar1 = *(float *)(*param_1 + 0x1c0);
        if ((byte)(5.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 5.0) << 0xe) >> 8)) == 1) {
          *(undefined4 *)(*param_1 + 0x1c0) = 0x40a00000;
        }
        iVar4 = param_1[0xf2];
        iVar3 = (*DAT_001755d4)(0,*(undefined4 *)(*param_1 + 0x1c0),0x8004000);
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = iVar3 + 0xdc;
        }
        iVar3 = (*DAT_001755d4)(0,iVar3);
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = iVar3 + 0xdc;
        }
        (**(code **)(iVar4 + 0x34))(param_1,iVar3);
        *(float *)(*param_1 + 0x1e0) = *gpGlobals + 1.0;
        param_1[0x1f1] = (int)ROUND((float)param_1[0x1f1] + *(float *)(*param_1 + 0x1c0));
      }
    }
    else {
      *(byte *)((int)param_1 + 0x5d1) = *(byte *)((int)param_1 + 0x5d1) & 0xbf;
    }
  }
  else {
    fVar1 = *(float *)(iVar4 + 0x1dc);
    fVar2 = *gpGlobals;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      uVar5 = *(undefined4 *)(iVar4 + 0x1e8);
      pcVar6 = "player/pl_wade1.wav";
LAB_000d8525:
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,2,pcVar6,0x3f800000,0x3f4ccccd,0,100);
    }
    else if (*(float *)(*param_1 + 0x1dc) < *gpGlobals + 9.0) {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade2.wav";
      goto LAB_000d8525;
    }
    *(float *)(*param_1 + 0x1dc) = *gpGlobals + 12.0;
    *(undefined4 *)(*param_1 + 0x1c0) = 0x40000000;
    if (param_1[0x1f2] < param_1[0x1f1]) {
      *(byte *)((int)param_1 + 0x5d2) = *(byte *)((int)param_1 + 0x5d2) | 8;
      *(byte *)((int)param_1 + 0x5d1) = *(byte *)((int)param_1 + 0x5d1) & 0xbf;
      *(undefined1 *)(param_1 + 0x176) = 0;
    }
  }
  if (*(int *)(*param_1 + 0x1a0) == 0) {
    if ((*(byte *)(*param_1 + 0x184) & 0x10) == 0) {
      return;
    }
    iVar4 = (*DAT_00175628)(0,3);
    if (iVar4 == 1) {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade2.wav";
    }
    else if (iVar4 < 2) {
      if (iVar4 != 0) goto LAB_000d8783;
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade1.wav";
    }
    else if (iVar4 == 2) {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade3.wav";
    }
    else {
      if (iVar4 != 3) goto LAB_000d8783;
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade4.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,4,pcVar6,0x3f800000,0x3f4ccccd,0,100);
LAB_000d8783:
    *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) & 0xef;
    return;
  }
  fVar1 = *(float *)(*param_1 + 0x1dc);
  fVar2 = *gpGlobals;
  iVar4 = (*DAT_00175628)(0,0x1f);
  if ((iVar4 == 0) && (iVar4 = (*DAT_00175628)(0,0xb), (int)ROUND(fVar1 - fVar2) <= iVar4)) {
    iVar4 = (*DAT_00175628)(0,3);
    if (iVar4 == 1) {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_swim2.wav";
    }
    else if (iVar4 < 2) {
      if (iVar4 != 0) goto LAB_000d88fe;
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_swim1.wav";
    }
    else if (iVar4 == 2) {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_swim3.wav";
    }
    else {
      if (iVar4 != 3) goto LAB_000d88fe;
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = (char *)FUN_00139a90;
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,4,pcVar6,0x3f4ccccd,0x3f4ccccd,0,100);
  }
LAB_000d88fe:
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0x1a4) == -5) {
    fVar1 = *(float *)(iVar4 + 0x1c4);
    fVar2 = *gpGlobals;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      iVar3 = param_1[0xf2];
      iVar4 = (*DAT_001755d4)(0,(float)(*(int *)(iVar4 + 0x1a0) * 10),8);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar4 + 0xdc;
      }
      iVar4 = (*DAT_001755d4)(0,iVar4);
      if (iVar4 != 0) {
        FUN_000d8a10();
        return;
      }
LAB_000d8a09:
      iVar4 = 0;
LAB_000d8a16:
      (**(code **)(iVar3 + 0x34))(param_1,iVar4);
    }
  }
  else if (*(int *)(*param_1 + 0x1a4) == -4) {
    *(float *)(*param_1 + 0x1c4) = *gpGlobals + 1.0;
    iVar3 = param_1[0xf2];
    iVar4 = (*DAT_001755d4)(0,(float)(*(int *)(*param_1 + 0x1a0) << 2),0x100000);
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = iVar4 + 0xdc;
    }
    iVar4 = (*DAT_001755d4)(0,iVar4);
    if (iVar4 == 0) goto LAB_000d8a09;
    iVar4 = iVar4 + 0xdc;
    goto LAB_000d8a16;
  }
  if ((*(byte *)(*param_1 + 0x184) & 0x10) != 0) {
    return;
  }
  if (*(int *)(*param_1 + 0x1a4) == -3) {
    iVar4 = (*DAT_00175628)(0,3);
    if (iVar4 == 1) {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade2.wav";
    }
    else if (iVar4 < 2) {
      if (iVar4 != 0) goto LAB_000d8af3;
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade1.wav";
    }
    else if (iVar4 == 2) {
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade3.wav";
    }
    else {
      if (iVar4 != 3) goto LAB_000d8af3;
      uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "player/pl_wade4.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,4,pcVar6,0x3f800000,0x3f4ccccd,0,100);
  }
LAB_000d8af3:
  *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) | 0x10;
  *(undefined4 *)(*param_1 + 0x1c4) = 0;
  return;
}


