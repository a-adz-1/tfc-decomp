// PlayerDeathThink__11CBasePlayer  @ 000d8da0
void PlayerDeathThink__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x185) & 2) != 0) {
    fVar1 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                 *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                 *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20)) - 20.0;
    if (0.0 < fVar1) {
      iVar2 = *param_1;
      local_18 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                      *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                      *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
      if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_20 = 0.0;
        local_1c = 0.0;
        local_18 = 1.0;
      }
      else {
        local_18 = 1.0 / local_18;
        local_20 = local_18 * *(float *)(iVar2 + 0x20);
        local_1c = local_18 * *(float *)(iVar2 + 0x24);
        local_18 = local_18 * *(float *)(iVar2 + 0x28);
      }
      *(float *)(iVar2 + 0x20) = fVar1 * local_20;
      *(float *)(iVar2 + 0x24) = fVar1 * local_1c;
      *(float *)(iVar2 + 0x28) = fVar1 * local_18;
    }
    else {
      *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar2 + 0x24) = DAT_00175484;
      *(undefined4 *)(iVar2 + 0x28) = DAT_00175488;
    }
  }
  iVar2 = *param_1;
  if ((*(int *)(iVar2 + 0x94) != 0) && (param_1[0xf8] == 0)) {
    if ((*(int *)(iVar2 + 0x150) != 1) && (*(int *)(iVar2 + 0x150) != 99)) goto LAB_000d8f30;
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
    fVar1 = (float)param_1[599];
    param_1[599] = (int)(fVar1 + 1.0);
    if (fVar1 + 1.0 < 60.0) {
      return;
    }
  }
  if (*(int *)(*param_1 + 0x150) == 99) {
    *(undefined4 *)(*param_1 + 0x118) = 0;
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x20;
    *(undefined4 *)(*param_1 + 0x118) = 0;
    return;
  }
LAB_000d8f30:
  iVar2 = HasWeapons__11CBasePlayer(param_1);
  if (iVar2 != 0) {
    PackDeadPlayerItems__11CBasePlayer(param_1);
  }
  if (*(int *)(*param_1 + 0x150) == 1) {
    *(undefined4 *)(*param_1 + 0x150) = 2;
  }
  *(undefined4 *)(*param_1 + 0x118) = 0;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x20;
  *(undefined4 *)(*param_1 + 0x118) = 0;
  iVar2 = *(int *)(*param_1 + 0x160);
  if (*(int *)(*param_1 + 0x150) == 2) {
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*g_pGameRules + 0x58))(g_pGameRules,param_1);
      if (iVar2 != 0) {
        param_1[0x1fa] = (int)*gpGlobals;
        *(undefined4 *)(*param_1 + 0x150) = 3;
      }
      *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0xdf;
    }
  }
  else {
    if (iVar2 != 0) {
      *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) | 0x20;
    }
    if (((*(byte *)((int)param_1 + 0x89) & 0x20) != 0) && ((float)param_1[0x4c] <= *gpGlobals)) {
      *(undefined4 *)(*param_1 + 0x160) = 0;
      param_1[599] = 0;
      respawn__FP9entvars_ti(*param_1,((byte)((uint)param_1[0x19a] >> 5) ^ 1) & 1);
      *(undefined4 *)(*param_1 + 0xe4) = 0xbf800000;
    }
  }
  return;
}


