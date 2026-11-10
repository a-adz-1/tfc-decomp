// GoDown__12CFuncPlatRot  @ 000d1e70
void GoDown__12CFuncPlatRot(int *param_1)

{
  GoDown__9CFuncPlat(param_1);
  RotMove__12CFuncPlatRotR6Vectorf
            (param_1,param_1 + 0x120,*(float *)(*param_1 + 0xe4) - *(float *)(*param_1 + 0xe0));
  return;
}


// GoDown__16CFuncTrackChange  @ 000d4f20
void GoDown__16CFuncTrackChange(int *param_1)

{
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1[0x129] != 1) {
    (**(code **)(param_1[0xf2] + 0x118))(param_1,3);
    if ((*(byte *)(*param_1 + 0x180) & 0x10) == 0) {
      GoDown__9CFuncPlat(param_1);
      param_1[0x111] = -0x10000;
      param_1[0x112] = (int)CallHitBottom__9CFuncPlat;
      RotMove__12CFuncPlatRotR6Vectorf
                (param_1,param_1 + 0x120,*(float *)(*param_1 + 0xe4) - *(float *)(*param_1 + 0xe0));
    }
    else {
      param_1[0x111] = -0x10000;
      param_1[0x112] = (int)CallHitBottom__9CFuncPlat;
      param_1[0xfa] = 3;
      iStack_10 = param_1[0x120];
      iStack_c = param_1[0x121];
      iStack_8 = param_1[0x122];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&iStack_10,*(undefined4 *)(*param_1 + 0x1d8));
    }
    if (param_1[0x129] == 2) {
      UpdateTrain__16CFuncTrackChangeR6Vector(param_1,param_1 + 0x120);
      *(undefined4 *)(param_1[0x125] + 0x3cc) = 0;
    }
  }
  return;
}


// GoDown__9CFuncPlat  @ 000d1910
void GoDown__9CFuncPlat(int *param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1c8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),6,*(int *)(iVar1 + 0x1c8) + *(int *)(gpGlobals + 0x98)
               ,param_1[0x11c],0x3f4ccccd,0,100);
  }
  param_1[0xfa] = 3;
  param_1[0x111] = -0x10000;
  param_1[0x112] = (int)CallHitBottom__9CFuncPlat;
  local_10 = param_1[0x104];
  local_c = param_1[0x105];
  local_8 = param_1[0x106];
  LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1d8));
  return;
}


