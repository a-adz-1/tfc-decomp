// GoUp__12CFuncPlatRot  @ 000ce438
void GoUp__12CFuncPlatRot(int *param_1)

{
  GoUp__9CFuncPlat(param_1);
  RotMove__12CFuncPlatRotR6Vectorf
            (param_1,param_1 + 0x13c,*(float *)(*param_1 + 0x104) - *(float *)(*param_1 + 0x100));
  return;
}


// GoUp__16CFuncTrackChange  @ 000d1c00
void GoUp__16CFuncTrackChange(int *param_1)

{
  int local_c;
  int local_8;
  int local_4;
  
  if (param_1[0x148] != 1) {
    (**(code **)(param_1[0x111] + 0x120))(param_1,2);
    if ((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0) {
      GoUp__9CFuncPlat(param_1);
      param_1[0x130] = -0x10000;
      param_1[0x131] = (int)CallHitTop__9CFuncPlat;
      RotMove__12CFuncPlatRotR6Vectorf
                (param_1,param_1 + 0x13c,*(float *)(*param_1 + 0x104) - *(float *)(*param_1 + 0x100)
                );
    }
    else {
      param_1[0x119] = 2;
      param_1[0x130] = -0x10000;
      param_1[0x131] = (int)CallHitTop__9CFuncPlat;
      local_c = param_1[0x13c];
      local_8 = param_1[0x13d];
      local_4 = param_1[0x13e];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
    }
    if (param_1[0x148] == 2) {
      UpdateTrain__16CFuncTrackChangeR6Vector(param_1,param_1 + 0x13c);
      *(undefined4 *)(param_1[0x144] + 0x448) = 0;
    }
  }
  return;
}


// GoUp__9CFuncPlat  @ 000cdf20
void GoUp__9CFuncPlat(int *param_1)

{
  int iVar1;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1e8) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),6,*(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98)
               ,param_1[0x13b],0x3f4ccccd,0,100);
  }
  param_1[0x119] = 2;
  param_1[0x130] = -0x10000;
  param_1[0x131] = (int)CallHitTop__9CFuncPlat;
  local_c = param_1[0x120];
  local_8 = param_1[0x121];
  local_4 = param_1[0x122];
  LinearMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
  return;
}


