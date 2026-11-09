// ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf  @ 000ac2f0
void ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0xf3]);
  if (iVar3 != 0) {
    if (param_1[0xf3] == 0) {
      param_1[0xf3] = 1;
      *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
      uVar4 = GetEndPos__5CBeam(param_1);
      uVar4 = GetStartPos__5CBeam(param_1,uVar4);
      DoSparks__5CBeamRC6VectorT1(param_1,uVar4);
      puVar2 = gpGlobals;
      fVar1 = *(float *)(*param_1 + 0x1c0);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
        *(undefined4 *)(*param_1 + 0x1c4) = *puVar2;
      }
    }
    else {
      param_1[0xf3] = 0;
      *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
      *(undefined4 *)(*param_1 + 0xe4) = 0;
    }
  }
  return;
}


// ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf  @ 00110750
void ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  if (*(int *)(*param_1 + 0xec) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 1;
    *(float *)(gpGlobals + 8) = *(float *)(gpGlobals + 8) + 1.0;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 0;
  }
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


// ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf  @ 000eba10
void ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5)

{
  int iVar1;
  
  iVar1 = (int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1b4);
  if (param_4 != 3) {
    if (param_1[0x10d] != 0) {
      if (param_4 == 1) {
        return;
      }
      if (param_1[0x10d] != 0) goto LAB_000eba5b;
    }
    if (param_4 == 0) {
      return;
    }
  }
LAB_000eba5b:
  if (param_4 == 2) {
    if (param_1[0x10d] != 0) {
      if ((byte)(1.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_5 == 1.0) << 0xe) >> 8)) == 1) {
        param_5 = 1.0;
      }
      if (param_5 < 0.0) {
        param_5 = 0.01;
      }
      param_1[0x103] = (int)ROUND(param_5 * 255.0);
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),*param_1 + 8,iVar1,0,0,0x80,
                 (int)ROUND(param_5 * 255.0));
      return;
    }
  }
  else if (param_1[0x10d] != 0) {
    if (param_1[0x101] == 0) {
      param_1[0x10d] = 0;
      *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 0x10;
      if ((param_1[0x105] == 0) && (param_1[0x109] == 0)) {
        UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),*param_1 + 8,iVar1,0,0,0x20,0);
        return;
      }
      param_1[0xf8] = param_1[0x105];
      param_1[0xf7] = 0;
      param_1[0xfc] = param_1[0x109];
      param_1[0xfb] = 0;
    }
    else {
      if (param_1[0x101] < param_1[0x102]) {
        return;
      }
      param_1[0x102] = param_1[0x102] + 1;
      param_1[0xf7] = param_1[0x104];
      param_1[0xf8] = 0;
      iVar1 = ((0xff - param_1[0xf6]) / param_1[0x101]) * param_1[0x102] + param_1[0xf6];
      param_1[0xf5] = iVar1;
      if (0xff < iVar1) {
        param_1[0xf5] = 0xff;
      }
    }
    goto LAB_000ebc84;
  }
  if (param_1[0x10e] == 0) {
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),*param_1 + 8,iVar1,0,0,0x20,0);
  }
  else {
    param_1[0x10d] = 1;
  }
  InitModulationParms__15CAmbientGeneric(param_1);
  UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),*param_1 + 8,iVar1,(float)param_1[0x107] * 0.01,
             param_1[0xf3],0,param_1[0x103]);
LAB_000ebc84:
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


// ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf  @ 000edd90
void ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  bool bVar2;
  
  fVar1 = *(float *)(*param_1 + 0xe4);
  bVar2 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1;
  if (param_4 != 3) {
    if (bVar2) {
      if (param_4 == 0) {
        return;
      }
    }
    else if (param_4 == 1) {
      return;
    }
  }
  if ((param_4 == 1) || ((param_4 != 0 && (bVar2)))) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  else {
    *(undefined4 *)(*param_1 + 0xe4) = 0;
  }
  return;
}


