// GoDown__12CFuncPlatRot  @ 000ce3a4
void GoDown__12CFuncPlatRot(int *param_1)

{
  GoDown__9CFuncPlat(param_1);
  RotMove__12CFuncPlatRotR6Vectorf
            (param_1,param_1 + 0x13f,*(float *)(*param_1 + 0x104) - *(float *)(*param_1 + 0x100));
  return;
}


// GoDown__16CFuncTrackChange  @ 000d1aec
void GoDown__16CFuncTrackChange(int *param_1)

{
  int local_c;
  int local_8;
  int local_4;
  
  if (param_1[0x148] != 1) {
    (**(code **)(param_1[0x111] + 0x120))(param_1,3);
    if ((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0) {
      GoDown__9CFuncPlat(param_1);
      param_1[0x130] = -0x10000;
      param_1[0x131] = (int)CallHitBottom__9CFuncPlat;
      RotMove__12CFuncPlatRotR6Vectorf
                (param_1,param_1 + 0x13f,*(float *)(*param_1 + 0x104) - *(float *)(*param_1 + 0x100)
                );
    }
    else {
      param_1[0x130] = -0x10000;
      param_1[0x131] = (int)CallHitBottom__9CFuncPlat;
      param_1[0x119] = 3;
      local_c = param_1[0x13f];
      local_8 = param_1[0x140];
      local_4 = param_1[0x141];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
    }
    if (param_1[0x148] == 2) {
      UpdateTrain__16CFuncTrackChangeR6Vector(param_1,param_1 + 0x13f);
      *(undefined4 *)(param_1[0x144] + 0x448) = 0;
    }
  }
  return;
}


// GoDown__9CFuncPlat  @ 000cddbc
void GoDown__9CFuncPlat(int *param_1)

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
  param_1[0x119] = 3;
  param_1[0x130] = -0x10000;
  param_1[0x131] = (int)CallHitBottom__9CFuncPlat;
  local_c = param_1[0x123];
  local_8 = param_1[0x124];
  local_4 = param_1[0x125];
  LinearMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
  return;
}


