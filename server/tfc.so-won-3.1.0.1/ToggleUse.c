// ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf  @ 000968a0
void ToggleUse__10CLightningP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0xf6]);
  if (iVar1 != 0) {
    if (param_1[0xf6] == 0) {
      param_1[0xf6] = 1;
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
      uVar2 = GetEndPos__5CBeam(param_1);
      uVar2 = GetStartPos__5CBeam(param_1,uVar2);
      DoSparks__5CBeamRC6VectorT1(param_1,uVar2);
      if (0.0 < *(float *)(*param_1 + 0x1e0)) {
        *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
        *(undefined4 *)(*param_1 + 0x1e4) = *gpGlobals;
      }
    }
    else {
      param_1[0xf6] = 0;
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
      *(undefined4 *)(*param_1 + 0x104) = 0;
    }
  }
  return;
}


// ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf  @ 00102d48
void ToggleUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  if (*(int *)(*param_1 + 0x10c) == 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 1;
    *(float *)(gpGlobals + 8) = *(float *)(gpGlobals + 8) + 1.0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf  @ 000e14f4
void ToggleUse__15CAmbientGenericP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,float param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = (int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1d4);
  if (param_4 != 3) {
    if (param_1[0x110] != 0) {
      if (param_4 == 1) {
        return;
      }
      if (param_1[0x110] != 0) goto LAB_000e154e;
    }
    if (param_4 == 0) {
      return;
    }
  }
LAB_000e154e:
  if (param_4 == 2) {
    if (param_1[0x110] != 0) {
      if (1.0 < param_5) {
        param_5 = 1.0;
      }
      if (0x3f < (byte)((0.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
                        (byte)((ushort)((ushort)(param_5 == 0.0) << 0xe) >> 8)) - 1)) {
        param_5 = 0.01;
      }
      iVar5 = (int)ROUND(param_5 * 255.0);
      param_1[0x106] = iVar5;
      uVar4 = 0x80;
      iVar1 = *param_1;
      uVar2 = *(undefined4 *)(iVar1 + 0x208);
LAB_000e170d:
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar2,iVar1 + 8,iVar3,0,0,uVar4,iVar5);
      return;
    }
  }
  else if (param_1[0x110] != 0) {
    if (param_1[0x104] == 0) {
      param_1[0x110] = 0;
      *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 0x10;
      if ((param_1[0x108] == 0) && (param_1[0x10c] == 0)) {
        iVar5 = 0;
        uVar4 = 0x20;
        iVar1 = *param_1;
        uVar2 = *(undefined4 *)(iVar1 + 0x208);
        goto LAB_000e170d;
      }
      param_1[0xfb] = param_1[0x108];
      param_1[0xfa] = 0;
      param_1[0xff] = param_1[0x10c];
      param_1[0xfe] = 0;
    }
    else {
      if (param_1[0x104] < param_1[0x105]) {
        return;
      }
      param_1[0x105] = param_1[0x105] + 1;
      param_1[0xfa] = param_1[0x107];
      param_1[0xfb] = 0;
      iVar3 = ((0xff - param_1[0xf9]) / param_1[0x104]) * param_1[0x105] + param_1[0xf9];
      param_1[0xf8] = iVar3;
      if (0xff < iVar3) {
        param_1[0xf8] = 0xff;
      }
    }
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    return;
  }
  if (param_1[0x111] == 0) {
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar3,0,0,0x20,0);
  }
  else {
    param_1[0x110] = 1;
  }
  InitModulationParms__15CAmbientGeneric(param_1);
  UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
            (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar3,(float)param_1[0x10a] * 0.01,
             param_1[0xf6],0,param_1[0x106]);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


// ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf  @ 000e3c34
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ToggleUse__8CSpeakerP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  double dVar1;
  bool bVar2;
  
  dVar1 = (double)*(float *)(*param_1 + 0x104);
  bVar2 = (byte)(_FUN_0013cc18 < dVar1 |
                 (byte)((ushort)((ushort)(NAN(_FUN_0013cc18) || NAN(dVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(_FUN_0013cc18 == dVar1) << 0xe) >> 8)) != 1;
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
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  else {
    *(undefined4 *)(*param_1 + 0x104) = 0;
  }
  return;
}


