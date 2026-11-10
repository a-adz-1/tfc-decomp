// PlayerDeathThink__11CBasePlayer  @ 000d6044
void PlayerDeathThink__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  float local_20;
  float local_1c;
  float local_18;
  
  param_1[0x1b] = 0;
  iVar4 = *param_1;
  if ((*(byte *)(iVar4 + 0x1a5) & 2) != 0) {
    fVar1 = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                 *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                 *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20)) - 20.0;
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      local_18 = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                      *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                      *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20));
      if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_20 = 0.0;
        local_1c = 0.0;
        local_18 = 1.0;
      }
      else {
        local_18 = 1.0 / local_18;
        local_20 = *(float *)(iVar4 + 0x20) * local_18;
        local_1c = *(float *)(iVar4 + 0x24) * local_18;
        local_18 = local_18 * *(float *)(iVar4 + 0x28);
      }
      *(float *)(iVar4 + 0x20) = local_20 * fVar1;
      *(float *)(iVar4 + 0x24) = local_1c * fVar1;
      *(float *)(iVar4 + 0x28) = local_18 * fVar1;
    }
    else {
      *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar4 + 0x24) = DAT_0019f664;
      *(undefined4 *)(iVar4 + 0x28) = DAT_0019f668;
    }
    iVar4 = *param_1;
  }
  if (((*(int *)(iVar4 + 0xb4) != 0) && (param_1[0x11b] == 0)) &&
     ((*(int *)(iVar4 + 0x170) == 1 || (*(int *)(iVar4 + 0x170) == 5)))) {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
    fVar1 = (float)param_1[0x285] + 1.0;
    param_1[0x285] = (int)fVar1;
    if ((byte)(fVar1 < 120.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 120.0) << 0xe) >> 8)) == 1) {
      return;
    }
  }
  iVar4 = *param_1;
  if ((*(int *)(iVar4 + 0x108) != 0) && ((*(byte *)(iVar4 + 0x1a5) & 2) != 0)) {
    *(undefined4 *)(iVar4 + 0x108) = 0;
    iVar4 = *param_1;
  }
  if (*(int *)(iVar4 + 0x170) == 5) {
    *(undefined4 *)(iVar4 + 0x138) = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    *(undefined4 *)(*param_1 + 0x138) = 0;
  }
  else {
    iVar4 = HasWeapons__11CBasePlayer(param_1);
    if ((iVar4 != 0) && ((float)param_1[0x1c5] < *gpGlobals)) {
      PackDeadPlayerItems__11CBasePlayer(param_1);
    }
    iVar4 = *param_1;
    if (*(int *)(iVar4 + 0x170) == 1) {
      *(undefined4 *)(iVar4 + 0x170) = 2;
      *(undefined4 *)(*param_1 + 0x10c) = 0;
      iVar4 = *param_1;
    }
    *(undefined4 *)(iVar4 + 0x138) = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    *(undefined4 *)(*param_1 + 0x138) = 0;
    uVar3 = *(uint *)(*param_1 + 0x180);
    if (*(int *)(*param_1 + 0x170) == 2) {
      if ((uVar3 & 0xffff7fff) == 0) {
        iVar4 = (**(code **)(*g_pGameRules + 0x58))(g_pGameRules,param_1);
        if (iVar4 != 0) {
          param_1[0x225] = (int)*gpGlobals;
          *(undefined4 *)(*param_1 + 0x170) = 3;
        }
        *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) & 0xdf;
      }
    }
    else {
      if ((uVar3 & 0xffff7fff) != 0) {
        *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) | 0x20;
      }
      if ((*(byte *)((int)param_1 + 0x85) & 0x20) != 0) {
        fVar1 = *gpGlobals;
        fVar2 = (float)param_1[0x4c];
        if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
          *(undefined4 *)(*param_1 + 0x180) = 0;
          param_1[0x285] = 0;
          *(undefined4 *)(*param_1 + 0x10c) = 3;
          respawn__FP9entvars_si(*param_1,((byte)((uint)param_1[0x1c3] >> 5) ^ 1) & 1);
          *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
        }
      }
    }
  }
  return;
}


