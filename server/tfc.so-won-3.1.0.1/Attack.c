// Attack__12CTFSentrygun  @ 000def28
void Attack__12CTFSentrygun(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  longdouble lVar4;
  float local_3c;
  float local_38 [3];
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
  float local_4;
  
  if (*(int *)(*param_1 + 0x15c) != 0) {
    CheckShield__12CTFSentrygun(param_1);
  }
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_4 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_4;
  uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
  iVar3 = ValidTarget__12CTFSentrygunP11CBaseEntity(param_1,uVar2);
  if (iVar3 == 0) {
LAB_000defc4:
    param_1[3] = -0x10000;
    param_1[4] = (int)SentryRotate__12CTFSentrygun;
    local_4 = *gpGlobals + 0.1;
    *(float *)(*param_1 + 0x104) = local_4;
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x11f,0);
  }
  else {
    if (param_1[0x23] == 3) {
LAB_000defb2:
      if ((param_1[0x33] < 1) && (param_1[0x39] < 1)) goto LAB_000defc4;
    }
    else {
      if (param_1[0x33] < 1) goto LAB_000defc4;
      if (param_1[0x23] == 3) goto LAB_000defb2;
    }
    iVar3 = *param_1;
    local_10 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
    local_c = *(float *)(*param_1 + 0xc) + *(float *)(iVar3 + 0x178);
    local_8 = *(float *)(*param_1 + 0x10) + *(float *)(iVar3 + 0x17c);
    iVar3 = __rf__7EHANDLE(param_1 + 0x11f);
    (**(code **)(*(int *)(iVar3 + 0x3d4) + 0xd0))(&local_1c,iVar3,&local_10);
    local_2c = local_20 - local_14;
    local_28 = local_1c - local_10;
    local_24 = local_18 - local_c;
    UTIL_VecToAngles__FRC6Vector(local_38,&local_2c);
    lVar4 = (longdouble)UTIL_AngleMod__Ff(local_38[0]);
    local_38[0] = (float)lVar4;
    if (0x3f < (byte)((-180.0 < local_3c | (byte)((ushort)((ushort)NAN(local_3c) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_3c == -180.0) << 0xe) >> 8)) - 1)) {
      local_3c = local_3c + 360.0;
    }
    if (180.0 < local_3c) {
      local_3c = local_3c - 360.0;
    }
    fVar1 = 50.0;
    if (((byte)(50.0 < local_3c | (byte)((ushort)((ushort)NAN(local_3c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_3c == 50.0) << 0xe) >> 8)) == 1) ||
       (fVar1 = -50.0,
       0x3f < (byte)((-50.0 < local_3c | (byte)((ushort)((ushort)NAN(local_3c) << 10) >> 8) |
                     (byte)((ushort)((ushort)(local_3c == -50.0) << 0xe) >> 8)) - 1))) {
      local_3c = fVar1;
    }
    param_1[400] = (int)local_38[0];
    param_1[399] = (int)local_3c;
    MoveTurret__12CTFSentrygun(param_1);
    if ((*gpGlobals < (float)param_1[0x176]) ||
       (fVar1 = SQRT(((float)param_1[0x191] - (float)param_1[0x18e]) *
                     ((float)param_1[0x191] - (float)param_1[0x18e]) +
                     ((float)param_1[400] - (float)param_1[0x18d]) *
                     ((float)param_1[400] - (float)param_1[0x18d]) +
                     ((float)param_1[399] - (float)param_1[0x18c]) *
                     ((float)param_1[399] - (float)param_1[0x18c])),
       (byte)(10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) == 1)) {
      SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM(param_1,2);
    }
    else {
      Fire__12CTFSentrygun(param_1);
      if (param_1[0x23] == 1) {
        fVar1 = 0.2;
      }
      else {
        fVar1 = 0.1;
      }
      param_1[0x176] = (int)(fVar1 + *gpGlobals);
    }
  }
  return;
}


// Attack__8CXenTree  @ 00114f30
void Attack__8CXenTree(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  longdouble lVar3;
  
  if (param_1[0xfd] == 1) {
    SetActivity__13CActAnimating8Activity(param_1,0x1e);
    lVar3 = (longdouble)(*DAT_001a7fac)(0x3f800000,0x3fb33333);
    *(float *)(*param_1 + 0x138) = (float)lVar3;
    uVar1 = (*DAT_001a7fa8)(0x5f,0x69);
    iVar2 = (*DAT_001a7fa8)(0,1,0x3f800000,0x3f4ccccd,0,uVar1);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,(&_8CXenTree_pAttackMissSounds)[iVar2]);
  }
  return;
}


// Attack__9CXenSpore  @ 00115c50
void Attack__9CXenSpore(void)

{
  return;
}


