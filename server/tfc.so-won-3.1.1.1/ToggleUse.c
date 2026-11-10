// ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf  @ 0009fd68
void ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x116]);
  if (iVar1 == 0) {
    return;
  }
  if (param_1[0x116] != 0) {
    param_1[0x116] = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    *(undefined4 *)(*param_1 + 0x104) = 0;
    return;
  }
  param_1[0x116] = 1;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
  iVar1 = *param_1;
  if ((*(uint *)(iVar1 + 0x148) & 0xf) == 2) {
    local_8 = (*DAT_0019f7c0)(*(uint *)(iVar1 + 0x128) & 0xfff);
    local_8 = local_8 + 0x88;
    iVar1 = *param_1;
  }
  else {
    local_8 = iVar1 + 8;
  }
  uVar3 = *(uint *)(iVar1 + 0x148) & 0xf;
  if ((uVar3 != 0) && (uVar3 != 3)) {
    iVar2 = (*DAT_0019f7c0)(*(uint *)(iVar1 + 0x110) & 0xfff);
    if (iVar2 != 0) {
      iVar2 = iVar2 + 0x88;
      iVar1 = *param_1;
      goto LAB_0009fe65;
    }
    iVar1 = *param_1;
  }
  iVar2 = iVar1 + 0x50;
LAB_0009fe65:
  if ((*(uint *)(iVar1 + 0x1a0) & 0x30) != 0) {
    if ((*(uint *)(iVar1 + 0x1a0) & 0x10) != 0) {
      UTIL_Sparks__FRC6Vector(local_8);
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0x1a0) & 0x20) != 0) {
      UTIL_Sparks__FRC6Vector(iVar2);
      iVar1 = *param_1;
    }
  }
  if (0.0 < *(float *)(iVar1 + 0x1e0)) {
    *(undefined4 *)(iVar1 + 0x104) = *gpGlobals;
    *(undefined4 *)(*param_1 + 0x1e4) = *gpGlobals;
  }
  return;
}


// ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf  @ 00118fc4
void ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x10c) == 0) {
    *(undefined4 *)(iVar1 + 0x10c) = 1;
    *(float *)(gpGlobals + 8) = *(float *)(gpGlobals + 8) + 1.0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x10c) = 0;
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf  @ 000efbe4
void ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x1d4) + (int)gpGlobals[0x26];
  if (param_4 != 3) {
    if (param_1[0x130] == 0) {
      if (param_4 == 0) {
        return;
      }
    }
    else if (param_4 == 1) {
      return;
    }
  }
  if (param_4 == 2) {
    if (param_1[0x130] != 0) {
      if (1.0 < param_5) {
        param_5 = 1.0;
      }
      if (0x3f < (byte)((0.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
                        (byte)((ushort)((ushort)(param_5 == 0.0) << 0xe) >> 8)) - 1)) {
        param_5 = 0.01;
      }
      param_1[0x126] = (int)ROUND(param_5 * 255.0);
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar2,0,0,0x80,
                 (int)ROUND(param_5 * 255.0));
      return;
    }
  }
  else if (param_1[0x130] != 0) {
    iVar1 = param_1[0x124];
    if (iVar1 == 0) {
      param_1[0x130] = 0;
      *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 0x10;
      if ((param_1[0x128] == 0) && (param_1[300] == 0)) {
        UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar2,0,0,0x20,0);
        return;
      }
      param_1[0x11b] = param_1[0x128];
      param_1[0x11a] = 0;
      param_1[0x11f] = param_1[300];
      param_1[0x11e] = 0;
    }
    else {
      iVar2 = param_1[0x125];
      if (iVar1 < iVar2) {
        return;
      }
      param_1[0x125] = iVar2 + 1;
      param_1[0x11a] = param_1[0x127];
      param_1[0x11b] = 0;
      iVar1 = ((0xff - param_1[0x119]) / iVar1) * (iVar2 + 1) + param_1[0x119];
      param_1[0x118] = iVar1;
      if (0xff < iVar1) {
        param_1[0x118] = 0xff;
      }
    }
    goto LAB_000efe42;
  }
  if (param_1[0x131] == 0) {
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(iVar1 + 0x208),iVar1 + 8,iVar2,0,0,0x20,0);
  }
  else {
    param_1[0x130] = 1;
  }
  InitModulationParms__15CAmbientGeneric(param_1);
  UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
            (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar2,(float)param_1[0x12a] * 0.01,
             param_1[0x116],0,param_1[0x126]);
LAB_000efe42:
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


// ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf  @ 000f1eac
void ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x104);
  bVar3 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1;
  if (param_4 != 3) {
    if (bVar3) {
      if (param_4 == 0) {
        return;
      }
    }
    else if (param_4 == 1) {
      return;
    }
  }
  if ((param_4 == 1) || ((param_4 != 0 && (bVar3)))) {
    *(float *)(iVar2 + 0x104) = *gpGlobals + 0.1;
  }
  else {
    *(undefined4 *)(iVar2 + 0x104) = 0;
  }
  return;
}


