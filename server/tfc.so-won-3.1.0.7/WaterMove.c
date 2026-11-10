// WaterMove__11CBasePlayer  @ 000d603c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WaterMove__11CBasePlayer(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0x108) == 8) {
    return;
  }
  if (*(int *)(iVar4 + 0x108) == 0) {
    return;
  }
  if (*(float *)(iVar4 + 0x160) < 0.0) {
    return;
  }
  if (*(int *)(iVar4 + 0x1c0) == 3) {
    *(byte *)((int)param_1 + 0x64e) = *(byte *)((int)param_1 + 0x64e) & 0xf7;
    *(undefined1 *)(param_1 + 0x195) = 0;
    iVar4 = *param_1;
    if (*gpGlobals <= *(float *)(iVar4 + 0x1fc)) {
      *(byte *)((int)param_1 + 0x64d) = *(byte *)((int)param_1 + 0x64d) & 0xbf;
    }
    else if (*(float *)(iVar4 + 0x200) < *gpGlobals) {
      *(float *)(iVar4 + 0x1e0) = *(float *)(iVar4 + 0x1e0) + 1.0;
      if (_FUN_0014b050 < *(float *)(*param_1 + 0x1e0)) {
        *(float *)(*param_1 + 0x1e0) = _FUN_0014b050;
      }
      iVar8 = param_1[0x111];
      iVar7 = (*DAT_001c1134)(0,*(undefined4 *)(*param_1 + 0x1e0),0x8004000);
      iVar4 = iVar7 + 0x80;
      if (iVar7 == 0) {
        iVar4 = 0;
      }
      iVar7 = (*DAT_001c1134)(0,iVar4);
      iVar4 = iVar7 + 0x80;
      if (iVar7 == 0) {
        iVar4 = 0;
      }
      (**(code **)(iVar8 + 0x38))(param_1,iVar4);
      *(float *)(*param_1 + 0x200) = *gpGlobals + 1.0;
      param_1[0x212] = (int)ROUND((float)param_1[0x212] + *(float *)(*param_1 + 0x1e0));
    }
  }
  else {
    if (*gpGlobals <= *(float *)(iVar4 + 0x1fc)) {
      fVar3 = *gpGlobals + 9.0;
      fVar2 = *(float *)(*param_1 + 0x1fc);
      if (0x3f < (byte)((fVar3 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1)) {
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        pcVar6 = "player/pl_wade2.wav";
        goto LAB_000d60e8;
      }
    }
    else {
      uVar5 = *(undefined4 *)(iVar4 + 0x208);
      pcVar6 = "player/pl_wade1.wav";
LAB_000d60e8:
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,2,pcVar6,0x3f800000,0x3f4ccccd,0,100);
    }
    *(float *)(*param_1 + 0x1fc) = *gpGlobals + 12.0;
    *(undefined4 *)(*param_1 + 0x1e0) = 0x40000000;
    if (param_1[0x213] < param_1[0x212]) {
      *(byte *)((int)param_1 + 0x64e) = *(byte *)((int)param_1 + 0x64e) | 8;
      *(byte *)((int)param_1 + 0x64d) = *(byte *)((int)param_1 + 0x64d) & 0xbf;
      *(undefined1 *)(param_1 + 0x195) = 0;
    }
  }
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0x1c0) == 0) {
    if ((*(byte *)(iVar4 + 0x1a4) & 0x10) == 0) {
      return;
    }
    *(byte *)(iVar4 + 0x1a4) = *(byte *)(iVar4 + 0x1a4) & 0xef;
    return;
  }
  fVar2 = *(float *)(*param_1 + 0x1fc);
  fVar3 = *gpGlobals;
  iVar4 = (*DAT_001c1188)(0,0x1f);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001c1188)(0,0xb), (int)ROUND(fVar2 - fVar3) <= iVar4)) {
    uVar5 = (*DAT_001c1188)(0,3);
    switch(uVar5) {
    case 0:
      uVar5 = *(undefined4 *)(*param_1 + 0x208);
      pcVar6 = "player/pl_swim1.wav";
      break;
    case 1:
      uVar5 = *(undefined4 *)(*param_1 + 0x208);
      pcVar6 = "player/pl_swim2.wav";
      break;
    case 2:
      uVar5 = *(undefined4 *)(*param_1 + 0x208);
      pcVar6 = "player/pl_swim3.wav";
      break;
    case 3:
      uVar5 = *(undefined4 *)(*param_1 + 0x208);
      pcVar6 = "player/pl_swim4.wav";
      break;
    default:
      goto switchD_000d633b_default;
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,4,pcVar6,0x3f4ccccd,0x3f4ccccd,0,100);
  }
switchD_000d633b_default:
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0x1c4) == -5) {
    if (*gpGlobals <= *(float *)(iVar4 + 0x1e4)) goto LAB_000d647d;
    iVar8 = param_1[0x111];
    uVar5 = 8;
    iVar4 = *(int *)(iVar4 + 0x1c0) * 10;
  }
  else {
    if (*(int *)(*param_1 + 0x1c4) != -4) goto LAB_000d647d;
    *(float *)(*param_1 + 0x1e4) = *gpGlobals + 1.0;
    iVar8 = param_1[0x111];
    uVar5 = 0x100000;
    iVar4 = *(int *)(*param_1 + 0x1c0) << 2;
  }
  iVar7 = (*DAT_001c1134)(0,(float)iVar4,uVar5);
  iVar4 = iVar7 + 0x80;
  if (iVar7 == 0) {
    iVar4 = 0;
  }
  iVar7 = (*DAT_001c1134)(0,iVar4);
  iVar4 = iVar7 + 0x80;
  if (iVar7 == 0) {
    iVar4 = 0;
  }
  (**(code **)(iVar8 + 0x38))(param_1,iVar4);
LAB_000d647d:
  if ((*(byte *)(*param_1 + 0x1a4) & 0x10) == 0) {
    pbVar1 = (byte *)(*param_1 + 0x1a4);
    *pbVar1 = *pbVar1 | 0x10;
    *(undefined4 *)(*param_1 + 0x1e4) = 0;
  }
  return;
}


