// WaterMove__11CBasePlayer  @ 000d5b90
void WaterMove__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
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
    uVar3 = param_1[0x197];
    param_1[0x197] = uVar3 & 0xfff7ffff;
    *(undefined1 *)(param_1 + 0x199) = 0;
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(iVar4 + 0x1fc);
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
      param_1[0x197] = uVar3 & 0xfff7bfff;
    }
    else {
      fVar2 = *(float *)(iVar4 + 0x200);
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        *(float *)(iVar4 + 0x1e0) = *(float *)(iVar4 + 0x1e0) + 1.0;
        iVar4 = *param_1;
        if (5.0 < *(float *)(iVar4 + 0x1e0)) {
          *(undefined4 *)(iVar4 + 0x1e0) = 0x40a00000;
          iVar4 = *param_1;
        }
        iVar8 = param_1[0x115];
        iVar7 = (*DAT_0019f7b4)(0,*(undefined4 *)(iVar4 + 0x1e0),0x8004000);
        iVar4 = iVar7 + 0x80;
        if (iVar7 == 0) {
          iVar4 = 0;
        }
        iVar7 = (*DAT_0019f7b4)(0,iVar4);
        iVar4 = iVar7 + 0x80;
        if (iVar7 == 0) {
          iVar4 = 0;
        }
        (**(code **)(iVar8 + 0x38))(param_1,iVar4);
        *(float *)(*param_1 + 0x200) = *gpGlobals + 1.0;
        param_1[0x21c] = (int)ROUND(*(float *)(*param_1 + 0x1e0) + (float)param_1[0x21c]);
      }
    }
  }
  else {
    fVar1 = *(float *)(iVar4 + 0x1fc);
    fVar2 = *gpGlobals;
    if ((byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      fVar2 = fVar2 + 9.0;
      if (0x3f < (byte)((fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
        uVar5 = *(undefined4 *)(iVar4 + 0x208);
        pcVar6 = "player/pl_wade2.wav";
        goto LAB_000d5c50;
      }
    }
    else {
      uVar5 = *(undefined4 *)(iVar4 + 0x208);
      pcVar6 = "player/pl_wade1.wav";
LAB_000d5c50:
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,2,pcVar6,0x3f800000,0x3f4ccccd,0,100);
      iVar4 = *param_1;
    }
    *(float *)(iVar4 + 0x1fc) = *gpGlobals + 12.0;
    *(undefined4 *)(*param_1 + 0x1e0) = 0x40000000;
    if (param_1[0x21d] < param_1[0x21c]) {
      param_1[0x197] = param_1[0x197] & 0xffffbfffU | 0x80000;
      *(undefined1 *)(param_1 + 0x199) = 0;
    }
  }
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0x1c0) == 0) {
    if ((*(uint *)(iVar4 + 0x1a4) & 0x10) == 0) {
      return;
    }
    *(uint *)(iVar4 + 0x1a4) = *(uint *)(iVar4 + 0x1a4) & 0xffffffef;
    return;
  }
  fVar1 = *(float *)(iVar4 + 0x1fc);
  fVar2 = *gpGlobals;
  iVar4 = (*DAT_0019f808)(0,0x1f);
  if ((iVar4 == 0) && (iVar4 = (*DAT_0019f808)(0,0xb), (int)ROUND(fVar1 - fVar2) <= iVar4)) {
    uVar5 = (*DAT_0019f808)(0,3);
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
      goto LAB_000d5f54;
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,4,pcVar6,0x3f4ccccd,0x3f4ccccd,0,100);
  }
LAB_000d5f54:
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0x1c4) == -5) {
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(iVar4 + 0x1e4);
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40)
    goto LAB_000d601a;
    iVar8 = param_1[0x115];
    uVar5 = 8;
    iVar4 = *(int *)(iVar4 + 0x1c0) * 10;
  }
  else {
    if (*(int *)(iVar4 + 0x1c4) != -4) goto LAB_000d601a;
    *(float *)(iVar4 + 0x1e4) = *gpGlobals + 1.0;
    iVar8 = param_1[0x115];
    uVar5 = 0x100000;
    iVar4 = *(int *)(*param_1 + 0x1c0) << 2;
  }
  iVar7 = (*DAT_0019f7b4)(0,(float)iVar4,uVar5);
  iVar4 = iVar7 + 0x80;
  if (iVar7 == 0) {
    iVar4 = 0;
  }
  iVar7 = (*DAT_0019f7b4)(0,iVar4);
  iVar4 = iVar7 + 0x80;
  if (iVar7 == 0) {
    iVar4 = 0;
  }
  (**(code **)(iVar8 + 0x38))(param_1,iVar4);
  iVar4 = *param_1;
LAB_000d601a:
  if ((*(uint *)(iVar4 + 0x1a4) & 0x10) == 0) {
    *(uint *)(iVar4 + 0x1a4) = *(uint *)(iVar4 + 0x1a4) | 0x10;
    *(undefined4 *)(*param_1 + 0x1e4) = 0;
  }
  return;
}


