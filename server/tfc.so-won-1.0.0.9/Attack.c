// Attack__12CTFSentrygun  @ 000e9c30
void Attack__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  longdouble lVar5;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(*param_1 + 0x13c) != 0) {
    CheckShield__12CTFSentrygun(param_1);
  }
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0xe4) = local_8;
  uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
  iVar4 = ValidTarget__12CTFSentrygunP11CBaseEntity(param_1,uVar3);
  if (iVar4 != 0) {
    if (param_1[0x24] != 3) {
      if (param_1[0x33] < 1) goto LAB_000e9cbb;
      if (param_1[0x24] != 3) goto LAB_000e9d00;
    }
    if ((0 < param_1[0x33]) || (0 < param_1[0x39])) {
LAB_000e9d00:
      iVar4 = *param_1;
      local_14 = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x154);
      local_10 = *(float *)(*param_1 + 0xc) + *(float *)(iVar4 + 0x158);
      local_c = *(float *)(*param_1 + 0x10) + *(float *)(iVar4 + 0x15c);
      iVar4 = __rf__7EHANDLE(param_1 + 0x11c);
      (**(code **)(*(int *)(iVar4 + 0x3c8) + 0xd0))(&local_20,iVar4,&local_14);
      local_2c = local_20 - local_14;
      local_28 = local_1c - local_10;
      local_24 = local_18 - local_c;
      UTIL_VecToAngles__FRC6Vector(&local_38,&local_2c);
      lVar5 = (longdouble)UTIL_AngleMod__Ff(local_34);
      local_34 = (float)lVar5;
      if (local_38 < -180.0) {
        local_38 = local_38 + 360.0;
      }
      if ((byte)(180.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_38 == 180.0) << 0xe) >> 8)) == 1) {
        local_38 = local_38 - 360.0;
      }
      fVar1 = 50.0;
      if (((byte)(50.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_38 == 50.0) << 0xe) >> 8)) == 1) ||
         (fVar1 = -50.0, local_38 < -50.0)) {
        local_38 = fVar1;
      }
      param_1[0x18c] = (int)local_34;
      param_1[0x18b] = (int)local_38;
      MoveTurret__12CTFSentrygun(param_1);
      fVar1 = (float)param_1[0x173];
      fVar2 = *gpGlobals;
      if (((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) &&
         (SQRT(((float)param_1[0x18d] - (float)param_1[0x18a]) *
               ((float)param_1[0x18d] - (float)param_1[0x18a]) +
               ((float)param_1[0x18c] - (float)param_1[0x189]) *
               ((float)param_1[0x18c] - (float)param_1[0x189]) +
               ((float)param_1[0x18b] - (float)param_1[0x188]) *
               ((float)param_1[0x18b] - (float)param_1[0x188])) <= 10.0)) {
        Fire__12CTFSentrygun(param_1);
        if (param_1[0x24] == 1) {
          fVar1 = 0.2;
        }
        else {
          fVar1 = 0.1;
        }
        param_1[0x173] = (int)(fVar1 + *gpGlobals);
        return;
      }
      SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM(param_1,2);
      return;
    }
  }
LAB_000e9cbb:
  param_1[3] = -0x10000;
  param_1[4] = (int)SentryRotate__12CTFSentrygun;
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0xe4) = local_8;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x11c,0);
  return;
}


// Attack__8CXenTree  @ 0011eba0
void Attack__8CXenTree(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  longdouble lVar3;
  
  if (param_1[0xfa] == 1) {
    SetActivity__13CActAnimating8Activity(param_1,0x1e);
    lVar3 = (longdouble)(*DAT_0017562c)(0x3f800000,0x3fb33333);
    *(float *)(*param_1 + 0x118) = (float)lVar3;
    uVar1 = (*DAT_00175628)(0x5f,0x69);
    iVar2 = (*DAT_00175628)(0,1,0x3f800000,0x3f4ccccd,0,uVar1);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,(&_8CXenTree_pAttackMissSounds)[iVar2]);
  }
  return;
}


// Attack__9CXenSpore  @ 0011f410
void Attack__9CXenSpore(void)

{
  return;
}


