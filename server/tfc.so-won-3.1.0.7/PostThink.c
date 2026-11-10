// PostThink__11CBasePlayer  @ 000d997c
void PostThink__11CBasePlayer(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  float local_14;
  
  if (g_fGameOver != 0) goto LAB_000d9da8;
  Player_Menu__11CBasePlayer(param_1);
  iVar5 = (**(code **)(param_1[0x111] + 0x8c))(param_1);
  if ((iVar5 == 0) || (*(int *)(*param_1 + 0x170) == 5)) goto LAB_000d9da8;
  piVar1 = param_1 + 0x219;
  iVar5 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar5 != 0) {
    iVar5 = __rf__7EHANDLE(piVar1);
    iVar5 = (**(code **)(*(int *)(iVar5 + 0x444) + 0x84))(iVar5,*param_1);
    if ((iVar5 == 0) || (*(int *)(*param_1 + 0xc0) != 0)) {
      iVar5 = __rf__7EHANDLE(param_1 + 0x219);
      (**(code **)(*(int *)(iVar5 + 0x444) + 0xb8))(iVar5,param_1,param_1,0,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x219,0);
    }
    else {
      iVar5 = __rf__7EHANDLE(piVar1);
      (**(code **)(*(int *)(iVar5 + 0x444) + 0xb8))(iVar5,param_1,param_1,2,0x40000000);
    }
  }
  if ((((cease_fire == 0) && (param_1[0x1a] == 0)) && (param_1[0x1b] == 0)) && (param_1[0x1c] == 0))
  {
    ItemPostFrame__11CBasePlayer(param_1);
  }
  iVar5 = *param_1;
  if ((*(byte *)(iVar5 + 0x1a5) & 2) != 0) {
    if ((0.0 < *(float *)(iVar5 + 0x160)) && (local_14 = (float)param_1[0x1b2], 350.0 <= local_14))
    {
      fVar2 = 0.5;
      if (*(int *)(iVar5 + 0x1c4) != -3) {
        if (local_14 <= 650.0) {
          if ((float)param_1[0x1b2] <= 325.0) {
            fVar3 = (float)param_1[0x1b2];
            if (0x3f < (byte)((200.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar3 == 200.0) << 0xe) >> 8)) - 1)) {
              fVar2 = 0.0;
            }
          }
          else {
            fVar2 = 0.85;
          }
        }
        else {
          local_14 = local_14 * 0.016666668;
          if (*(int *)(iVar5 + 0x20c) == 1) {
            fVar2 = 0.5;
LAB_000d9b2d:
            local_14 = fVar2 * local_14;
          }
          else if (*(int *)(*param_1 + 0x20c) == 6) {
            fVar2 = 1.5;
            goto LAB_000d9b2d;
          }
          fVar2 = *(float *)(*param_1 + 0x160);
          if (0x3f < (byte)((local_14 < fVar2 |
                             (byte)((ushort)((ushort)(NAN(local_14) || NAN(fVar2)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(local_14 == fVar2) << 0xe) >> 8)) - 1)) {
            EMIT_SOUND_DYN__FP7edict_siPCcffii
                      (*(undefined4 *)(*param_1 + 0x208),3,"common/bodysplat.wav",0x3f800000,
                       0x3f4ccccd,0,100);
          }
          if (0.0 < local_14) {
            iVar4 = param_1[0x111];
            iVar6 = (*DAT_001c1134)(0,local_14,0x8000020);
            iVar5 = iVar6 + 0x80;
            if (iVar6 == 0) {
              iVar5 = 0;
            }
            iVar6 = (*DAT_001c1134)(0,iVar5);
            iVar5 = iVar6 + 0x80;
            if (iVar6 == 0) {
              iVar5 = 0;
            }
            (**(code **)(iVar4 + 0x38))(param_1,iVar5);
            *(undefined4 *)(*param_1 + 0x68) = 0;
          }
          fVar2 = 1.0;
        }
      }
      if (0.0 < fVar2) {
        param_1[0x1bd] = 0;
        UpdateStepSound__11CBasePlayer(param_1);
      }
      iVar5 = (**(code **)(param_1[0x111] + 0x8c))(param_1);
      if (iVar5 != 0) {
        SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,1);
      }
    }
    if ((*(byte *)(*param_1 + 0x1a5) & 2) != 0) {
      if ((64.0 < (float)param_1[0x1b2]) &&
         (iVar5 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar5 == 0)) {
        InsertSound__9CSoundEntiRC6Vectorif
                  (4,*param_1 + 8,(int)ROUND((float)param_1[0x1b2]),0x3e4ccccd);
      }
      param_1[0x1b2] = 0;
    }
  }
  iVar5 = (**(code **)(param_1[0x111] + 0x8c))(param_1);
  if (iVar5 != 0) {
    fVar2 = *(float *)(*param_1 + 0x20);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar2 = *(float *)(*param_1 + 0x24);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
        fVar2 = *(float *)(*param_1 + 0x20);
        if (((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) ||
           (fVar2 = *(float *)(*param_1 + 0x24),
           (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) goto LAB_000d9d60;
        goto LAB_000d9d6b;
      }
      uVar7 = 0;
    }
    else {
LAB_000d9d60:
      if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
LAB_000d9d6b:
        if (*(int *)(*param_1 + 0x1c0) < 2) goto LAB_000d9d81;
      }
      uVar7 = 1;
    }
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,uVar7);
  }
LAB_000d9d81:
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  CheckPowerups__11CBasePlayer(param_1);
  UpdatePlayerSound__11CBasePlayer(param_1);
  param_1[0x1ac] = *(int *)(*param_1 + 0x180);
LAB_000d9da8:
  iVar5 = 0;
  do {
    if (param_1[iVar5 + 0x227] != 0) {
      for (iVar4 = param_1[iVar5 + 0x227]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x468)) {
        iVar6 = (**(code **)(*(int *)(iVar4 + 0x444) + 0x150))(iVar4);
        if (iVar6 != 0) {
          fVar2 = *(float *)(iVar6 + 0x478) - *(float *)(gpGlobals + 4);
          if (0x3f < (byte)((-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) - 1)) {
            fVar2 = -1.0;
          }
          *(float *)(iVar6 + 0x478) = fVar2;
          fVar2 = *(float *)(iVar6 + 0x494) - *(float *)(gpGlobals + 4);
          if (0x3f < (byte)((-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) - 1)) {
            fVar2 = -1.0;
          }
          *(float *)(iVar6 + 0x494) = fVar2;
          fVar2 = *(float *)(iVar6 + 0x47c) - *(float *)(gpGlobals + 4);
          if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
            fVar2 = -0.001;
          }
          *(float *)(iVar6 + 0x47c) = fVar2;
          fVar2 = *(float *)(iVar6 + 0x484) - *(float *)(gpGlobals + 4);
          if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
            fVar2 = -0.001;
          }
          *(float *)(iVar6 + 0x484) = fVar2;
          fVar2 = *(float *)(iVar6 + 0x488);
          if ((byte)(1000.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 1000.0) << 0xe) >> 8)) != 0x40) {
            fVar2 = fVar2 - *(float *)(gpGlobals + 4);
            if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
              fVar2 = -0.001;
            }
            *(float *)(iVar6 + 0x488) = fVar2;
          }
          fVar2 = *(float *)(iVar6 + 0x480);
          if ((byte)(1000.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 1000.0) << 0xe) >> 8)) != 0x40) {
            fVar2 = fVar2 - *(float *)(gpGlobals + 4);
            if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
              fVar2 = -0.001;
            }
            *(float *)(iVar6 + 0x480) = fVar2;
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  param_1[0x192] = (int)((float)param_1[0x192] - *(float *)(gpGlobals + 4));
  fVar2 = (float)param_1[0x192];
  if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
    param_1[0x192] = -0x457ced91;
  }
  return;
}


