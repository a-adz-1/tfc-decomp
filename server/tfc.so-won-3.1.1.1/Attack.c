// Attack__12CTFSentrygun  @ 000ecb20
void Attack__12CTFSentrygun(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  longdouble lVar6;
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
  
  iVar5 = *param_1;
  if (*(int *)(iVar5 + 0x15c) != 0) {
    *(float *)(iVar5 + 0x14c) = *(float *)(iVar5 + 0x14c) - 40.0;
    fVar2 = *(float *)(*param_1 + 0x14c);
    if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
      *(undefined4 *)(*param_1 + 0x15c) = 0;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
      iVar5 = *param_1;
      *(undefined4 *)(iVar5 + 0x150) = g_vecZero;
      *(undefined4 *)(iVar5 + 0x154) = DAT_0019f664;
      *(undefined4 *)(iVar5 + 0x158) = DAT_0019f668;
    }
  }
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_8 = *gpGlobals + 0.1;
  piVar1 = param_1 + 0x13f;
  *(float *)(*param_1 + 0x104) = local_8;
  piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(piVar1);
  if (((((piVar4 == (int *)0x0) || (iVar5 = (**(code **)(piVar4[0x115] + 0x8c))(piVar4), iVar5 == 0)
        ) || (piVar4[0x1c] != 0)) ||
      (((fVar2 = gpGlobals[7],
        (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40 && (param_1[0x48] != 0))
       && ((iVar5 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar4), iVar5 != 0 ||
           (piVar4[0x75] == param_1[0x48])))))) ||
     (((*(char *)(*piVar4 + 0x1a4) < '\0' || ((*(byte *)((int)piVar4 + 0x8a) & 8) != 0)) ||
      (iVar5 = (**(code **)(param_1[0x115] + 0xe0))(param_1,piVar4), iVar5 == 0)))) {
LAB_000ecc9a:
    param_1[3] = -0x10000;
    param_1[4] = (int)SentryRotate__12CTFSentrygun;
    local_8 = *gpGlobals + 0.1;
    *(float *)(*param_1 + 0x104) = local_8;
    __as__7EHANDLEP11CBaseEntity(piVar1,0);
  }
  else {
    if (param_1[0x23] == 3) {
      if (param_1[0x33] < 1) {
        iVar5 = param_1[0x39];
        goto joined_r0x000ecc98;
      }
    }
    else {
      iVar5 = param_1[0x33];
joined_r0x000ecc98:
      if (iVar5 < 1) goto LAB_000ecc9a;
    }
    iVar5 = *param_1;
    local_14 = *(float *)(iVar5 + 8) + *(float *)(iVar5 + 0x174);
    local_10 = *(float *)(*param_1 + 0xc) + *(float *)(iVar5 + 0x178);
    local_c = *(float *)(*param_1 + 0x10) + *(float *)(iVar5 + 0x17c);
    iVar5 = __rf__7EHANDLE(piVar1);
    (**(code **)(*(int *)(iVar5 + 0x454) + 0xd8))(&local_20,iVar5,&local_14);
    local_2c = local_20 - local_14;
    local_28 = local_1c - local_10;
    local_24 = local_18 - local_c;
    UTIL_VecToAngles__FRC6Vector(&local_38,&local_2c);
    lVar6 = (longdouble)UTIL_AngleMod__Ff(local_34);
    local_34 = (float)lVar6;
    if (0x3f < (byte)((-180.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_38 == -180.0) << 0xe) >> 8)) - 1)) {
      local_38 = local_38 + 360.0;
    }
    if (180.0 < local_38) {
      local_38 = local_38 - 360.0;
    }
    fVar2 = 50.0;
    if (((byte)(50.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_38 == 50.0) << 0xe) >> 8)) != 1) &&
       (fVar2 = -50.0,
       (byte)((-50.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == -50.0) << 0xe) >> 8)) - 1) < 0x40)) {
      fVar2 = local_38;
    }
    local_38 = fVar2;
    param_1[0x1b0] = (int)local_34;
    param_1[0x1af] = (int)local_38;
    MoveTurret__12CTFSentrygun(param_1);
    fVar2 = *gpGlobals;
    fVar3 = (float)param_1[0x196];
    if (((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) ||
       (fVar2 = SQRT(((float)param_1[0x1b1] - (float)param_1[0x1ae]) *
                     ((float)param_1[0x1b1] - (float)param_1[0x1ae]) +
                     ((float)param_1[0x1b0] - (float)param_1[0x1ad]) *
                     ((float)param_1[0x1b0] - (float)param_1[0x1ad]) +
                     ((float)param_1[0x1af] - (float)param_1[0x1ac]) *
                     ((float)param_1[0x1af] - (float)param_1[0x1ac])),
       (byte)(10.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 10.0) << 0xe) >> 8)) == 1)) {
      iVar5 = *param_1;
      if (*(int *)(iVar5 + 0x128) != 2) {
        if (1 < *(int *)(iVar5 + 0x128) - 1U) {
          *(undefined4 *)(iVar5 + 0x130) = 0;
          iVar5 = *param_1;
        }
        *(undefined4 *)(iVar5 + 0x128) = 2;
        ResetSequenceInfo__14CBaseAnimating(param_1);
      }
    }
    else {
      Fire__12CTFSentrygun(param_1);
      if (param_1[0x23] == 1) {
        fVar2 = 0.2;
      }
      else {
        fVar2 = 0.1;
      }
      param_1[0x196] = (int)(fVar2 + *gpGlobals);
    }
  }
  return;
}


// Attack__8CXenTree  @ 001294bc
void Attack__8CXenTree(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  if (param_1[0x11d] == 1) {
    iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1e);
    if (iVar1 != -1) {
      *(int *)(*param_1 + 0x128) = iVar1;
      param_1[0x11d] = 0x1e;
      *(undefined4 *)(*param_1 + 0x130) = 0;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
    lVar3 = (longdouble)(*DAT_0019f80c)(0x3f800000,0x3fb33333);
    *(float *)(*param_1 + 0x138) = (float)lVar3;
    uVar2 = (*DAT_0019f808)(0x5f,0x69);
    iVar1 = (*DAT_0019f808)(0,1,0x3f800000,0x3f4ccccd,0,uVar2);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,(&_8CXenTree_pAttackMissSounds)[iVar1]);
  }
  return;
}


// Attack__9CXenSpore  @ 00129358
void Attack__9CXenSpore(void)

{
  return;
}


