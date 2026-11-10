// PlayerDeathThink__11CBasePlayer  @ 000d64bc
void PlayerDeathThink__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  float local_1c;
  float local_18;
  float local_14;
  
  param_1[0x1b] = 0;
  iVar4 = *param_1;
  if ((*(byte *)(iVar4 + 0x1a5) & 2) != 0) {
    fVar1 = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                 *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                 *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20)) - 20.0;
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      iVar4 = *param_1;
      local_14 = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                      *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                      *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20));
      if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_1c = 0.0;
        local_18 = 0.0;
        local_14 = 1.0;
      }
      else {
        local_14 = 1.0 / local_14;
        local_1c = local_14 * *(float *)(iVar4 + 0x20);
        local_18 = local_14 * *(float *)(iVar4 + 0x24);
        local_14 = local_14 * *(float *)(iVar4 + 0x28);
      }
      *(float *)(iVar4 + 0x20) = fVar1 * local_1c;
      *(float *)(iVar4 + 0x24) = fVar1 * local_18;
      *(float *)(iVar4 + 0x28) = fVar1 * local_14;
    }
    else {
      *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar4 + 0x24) = DAT_001c0fe4;
      *(undefined4 *)(iVar4 + 0x28) = DAT_001c0fe8;
    }
  }
  iVar4 = *param_1;
  if (((*(int *)(iVar4 + 0xb4) != 0) && (param_1[0x117] == 0)) &&
     ((*(int *)(iVar4 + 0x170) == 1 || (*(int *)(iVar4 + 0x170) == 5)))) {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
    fVar1 = (float)param_1[0x27b];
    param_1[0x27b] = (int)(fVar1 + 1.0);
    if (fVar1 + 1.0 < 120.0) {
      return;
    }
  }
  iVar4 = *param_1;
  if ((*(int *)(iVar4 + 0x108) != 0) && ((*(byte *)(iVar4 + 0x1a5) & 2) != 0)) {
    *(undefined4 *)(iVar4 + 0x108) = 0;
  }
  if (*(int *)(*param_1 + 0x170) == 5) {
    *(undefined4 *)(*param_1 + 0x138) = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    *(undefined4 *)(*param_1 + 0x138) = 0;
  }
  else {
    iVar4 = HasWeapons__11CBasePlayer(param_1);
    if (iVar4 != 0) {
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x1bc];
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        PackDeadPlayerItems__11CBasePlayer(param_1);
      }
    }
    if (*(int *)(*param_1 + 0x170) == 1) {
      *(undefined4 *)(*param_1 + 0x170) = 2;
      *(undefined4 *)(*param_1 + 0x10c) = 0;
    }
    *(undefined4 *)(*param_1 + 0x138) = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    *(undefined4 *)(*param_1 + 0x138) = 0;
    uVar3 = *(uint *)(*param_1 + 0x180);
    if (*(int *)(*param_1 + 0x170) == 2) {
      if ((uVar3 & 0xffff7fff) == 0) {
        iVar4 = (**(code **)(*g_pGameRules + 0x58))(g_pGameRules,param_1);
        if (iVar4 != 0) {
          param_1[0x21b] = (int)*gpGlobals;
          *(undefined4 *)(*param_1 + 0x170) = 3;
        }
        *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) & 0xdf;
      }
    }
    else {
      if ((uVar3 & 0xffff7fff) != 0) {
        *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) | 0x20;
      }
      if (((*(byte *)((int)param_1 + 0x85) & 0x20) != 0) && ((float)param_1[0x4c] <= *gpGlobals)) {
        *(undefined4 *)(*param_1 + 0x180) = 0;
        param_1[0x27b] = 0;
        *(undefined4 *)(*param_1 + 0x10c) = 3;
        respawn__FP9entvars_si(*param_1,((byte)((uint)param_1[0x1ba] >> 5) ^ 1) & 1);
        *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
      }
    }
  }
  return;
}


