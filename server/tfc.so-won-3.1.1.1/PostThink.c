// PostThink__11CBasePlayer  @ 000d928c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PostThink__11CBasePlayer(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int local_18;
  
  if (g_fGameOver != 0) goto LAB_000d9674;
  Player_Menu__11CBasePlayer(param_1);
  iVar5 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
  if ((iVar5 == 0) || (*(int *)(*param_1 + 0x170) == 5)) goto LAB_000d9674;
  piVar1 = param_1 + 0x223;
  iVar5 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar5 != 0) {
    iVar5 = __rf__7EHANDLE(piVar1);
    iVar5 = (**(code **)(*(int *)(iVar5 + 0x454) + 0x84))(iVar5,*param_1);
    if ((iVar5 == 0) || (*(int *)(*param_1 + 0xc0) != 0)) {
      iVar5 = __rf__7EHANDLE(piVar1);
      (**(code **)(*(int *)(iVar5 + 0x454) + 0xb8))(iVar5,param_1,param_1,0,0);
      __as__7EHANDLEP11CBaseEntity(piVar1,0);
    }
    else {
      iVar5 = __rf__7EHANDLE(piVar1);
      (**(code **)(*(int *)(iVar5 + 0x454) + 0xb8))(iVar5,param_1,param_1,2,0x40000000);
    }
  }
  if ((((cease_fire == 0) && (param_1[0x1a] == 0)) && (param_1[0x1b] == 0)) && (param_1[0x1c] == 0))
  {
    ItemPostFrame__11CBasePlayer(param_1);
  }
  iVar5 = *param_1;
  if ((*(byte *)(iVar5 + 0x1a5) & 2) != 0) {
    if ((0.0 < *(float *)(iVar5 + 0x160)) && (fVar2 = (float)param_1[0x1bb], 350.0 <= fVar2)) {
      fVar3 = 0.5;
      if (*(int *)(iVar5 + 0x1c4) != -3) {
        if (fVar2 <= 650.0) {
          if (fVar2 <= 325.0) {
            if (0x3f < (byte)((200.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == 200.0) << 0xe) >> 8)) - 1)) {
              fVar3 = 0.0;
            }
          }
          else {
            fVar3 = 0.85;
          }
        }
        else {
          fVar2 = fVar2 * 0.016666668;
          dVar4 = _FUN_00150878;
          if (*(int *)(iVar5 + 0x20c) == 1) {
LAB_000d941f:
            fVar2 = (float)dVar4 * fVar2;
          }
          else if (*(int *)(iVar5 + 0x20c) == 6) {
            dVar4 = 1.5;
            goto LAB_000d941f;
          }
          fVar3 = *(float *)(iVar5 + 0x160);
          if (0x3f < (byte)((fVar2 < fVar3 |
                             (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
            EMIT_SOUND_DYN__FP7edict_siPCcffii
                      (*(undefined4 *)(iVar5 + 0x208),3,"common/bodysplat.wav",0x3f800000,0x3f4ccccd
                       ,0,100);
          }
          if (0.0 < fVar2) {
            iVar7 = param_1[0x115];
            iVar6 = (*DAT_0019f7b4)(0,fVar2,0x8000020);
            iVar5 = iVar6 + 0x80;
            if (iVar6 == 0) {
              iVar5 = 0;
            }
            iVar6 = (*DAT_0019f7b4)(0,iVar5);
            iVar5 = iVar6 + 0x80;
            if (iVar6 == 0) {
              iVar5 = 0;
            }
            (**(code **)(iVar7 + 0x38))(param_1,iVar5);
            *(undefined4 *)(*param_1 + 0x68) = 0;
          }
          fVar3 = 1.0;
        }
      }
      if (0.0 < fVar3) {
        param_1[0x1c7] = 0;
        UpdateStepSound__11CBasePlayer(param_1);
      }
      iVar5 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
      if (iVar5 != 0) {
        SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,1);
      }
    }
    if ((*(byte *)(*param_1 + 0x1a5) & 2) != 0) {
      if ((64.0 < (float)param_1[0x1bb]) &&
         (iVar5 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar5 == 0)) {
        InsertSound__9CSoundEntiRC6Vectorif
                  (4,*param_1 + 8,(int)ROUND((float)param_1[0x1bb]),0x3e4ccccd);
      }
      param_1[0x1bb] = 0;
    }
  }
  iVar5 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
  if (iVar5 != 0) {
    iVar5 = *param_1;
    fVar2 = *(float *)(iVar5 + 0x20);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar3 = *(float *)(iVar5 + 0x24);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 0x40) {
        if (((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) ||
           ((byte)(fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 0x40)) goto LAB_000d9630;
        goto LAB_000d9639;
      }
      uVar8 = 0;
    }
    else {
LAB_000d9630:
      if ((*(byte *)(iVar5 + 0x1a5) & 2) == 0) {
LAB_000d9639:
        if (*(int *)(iVar5 + 0x1c0) < 2) goto LAB_000d964d;
      }
      uVar8 = 1;
    }
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,uVar8);
  }
LAB_000d964d:
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  CheckPowerups__11CBasePlayer(param_1);
  UpdatePlayerSound__11CBasePlayer(param_1);
  param_1[0x1b5] = *(int *)(*param_1 + 0x180);
LAB_000d9674:
  local_18 = 0;
  do {
    for (iVar5 = param_1[local_18 + 0x231]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x478)) {
      iVar7 = (**(code **)(*(int *)(iVar5 + 0x454) + 0x150))(iVar5);
      if (iVar7 != 0) {
        fVar2 = *(float *)(iVar7 + 0x488) - *(float *)(gpGlobals + 4);
        if (0x3f < (byte)((-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) - 1)) {
          fVar2 = -1.0;
        }
        *(float *)(iVar7 + 0x488) = fVar2;
        fVar2 = *(float *)(iVar7 + 0x4a4) - *(float *)(gpGlobals + 4);
        if (fVar2 < -1.0) {
          fVar2 = -1.0;
        }
        *(float *)(iVar7 + 0x4a4) = fVar2;
        fVar2 = *(float *)(iVar7 + 0x48c) - *(float *)(gpGlobals + 4);
        fVar3 = -0.001;
        if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
          fVar2 = fVar3;
        }
        *(float *)(iVar7 + 0x48c) = fVar2;
        fVar2 = *(float *)(iVar7 + 0x494) - *(float *)(gpGlobals + 4);
        if (fVar2 < -0.001) {
          fVar2 = fVar3;
        }
        *(float *)(iVar7 + 0x494) = fVar2;
        fVar2 = *(float *)(iVar7 + 0x498);
        if ((byte)(1000.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 1000.0) << 0xe) >> 8)) != 0x40) {
          fVar2 = fVar2 - *(float *)(gpGlobals + 4);
          if (fVar2 < -0.001) {
            fVar2 = fVar3;
          }
          *(float *)(iVar7 + 0x498) = fVar2;
        }
        fVar2 = *(float *)(iVar7 + 0x490);
        if ((byte)(1000.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 1000.0) << 0xe) >> 8)) != 0x40) {
          fVar2 = fVar2 - *(float *)(gpGlobals + 4);
          if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
            fVar2 = -0.001;
          }
          *(float *)(iVar7 + 0x490) = fVar2;
        }
      }
    }
    local_18 = local_18 + 1;
  } while (local_18 < 6);
  fVar2 = (float)param_1[0x196] - *(float *)(gpGlobals + 4);
  param_1[0x196] = (int)fVar2;
  if (fVar2 < -0.001) {
    param_1[0x196] = -0x457ced91;
  }
  return;
}


