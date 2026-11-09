// GoUp__12CFuncPlatRot  @ 000d1f00
void GoUp__12CFuncPlatRot(int *param_1)

{
  GoUp__9CFuncPlat(param_1);
  RotMove__12CFuncPlatRotR6Vectorf
            (param_1,param_1 + 0x11d,*(float *)(*param_1 + 0xe4) - *(float *)(*param_1 + 0xe0));
  return;
}


// GoUp__16CFuncTrackChange  @ 000d5020
void GoUp__16CFuncTrackChange(int *param_1)

{
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1[0x129] != 1) {
    (**(code **)(param_1[0xf2] + 0x118))(param_1,2);
    if ((*(byte *)(*param_1 + 0x180) & 0x10) == 0) {
      GoUp__9CFuncPlat(param_1);
      param_1[0x111] = -0x10000;
      param_1[0x112] = (int)CallHitTop__9CFuncPlat;
      RotMove__12CFuncPlatRotR6Vectorf
                (param_1,param_1 + 0x11d,*(float *)(*param_1 + 0xe4) - *(float *)(*param_1 + 0xe0));
    }
    else {
      param_1[0xfa] = 2;
      param_1[0x111] = -0x10000;
      param_1[0x112] = (int)CallHitTop__9CFuncPlat;
      iStack_10 = param_1[0x11d];
      iStack_c = param_1[0x11e];
      iStack_8 = param_1[0x11f];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&iStack_10,*(undefined4 *)(*param_1 + 0x1d8));
    }
    if (param_1[0x129] == 2) {
      UpdateTrain__16CFuncTrackChangeR6Vector(param_1,param_1 + 0x11d);
      *(undefined4 *)(param_1[0x125] + 0x3cc) = 0;
    }
  }
  return;
}


// GoUp__9CFuncPlat  @ 000d1a50
void GoUp__9CFuncPlat(int *param_1)

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
  param_1[0xfa] = 2;
  param_1[0x111] = -0x10000;
  param_1[0x112] = (int)CallHitTop__9CFuncPlat;
  local_10 = param_1[0x101];
  local_c = param_1[0x102];
  local_8 = param_1[0x103];
  LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1d8));
  return;
}


