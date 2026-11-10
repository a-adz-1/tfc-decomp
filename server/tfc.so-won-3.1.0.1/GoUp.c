// GoUp__12CFuncPlatRot  @ 000c30d8
void GoUp__12CFuncPlatRot(int *param_1)

{
  GoUp__9CFuncPlat(param_1);
  RotMove__12CFuncPlatRotR6Vectorf
            (param_1,param_1 + 0x120,*(float *)(*param_1 + 0x104) - *(float *)(*param_1 + 0x100));
  return;
}


// GoUp__16CFuncTrackChange  @ 000c68a0
void GoUp__16CFuncTrackChange(int *param_1)

{
  int local_c;
  int local_8;
  int local_4;
  
  if (param_1[300] != 1) {
    (**(code **)(param_1[0xf5] + 0x118))(param_1,2);
    if ((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0) {
      GoUp__9CFuncPlat(param_1);
      param_1[0x114] = -0x10000;
      param_1[0x115] = (int)CallHitTop__9CFuncPlat;
      RotMove__12CFuncPlatRotR6Vectorf
                (param_1,param_1 + 0x120,*(float *)(*param_1 + 0x104) - *(float *)(*param_1 + 0x100)
                );
    }
    else {
      param_1[0xfd] = 2;
      param_1[0x114] = -0x10000;
      param_1[0x115] = (int)CallHitTop__9CFuncPlat;
      local_c = param_1[0x120];
      local_8 = param_1[0x121];
      local_4 = param_1[0x122];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
    }
    if (param_1[300] == 2) {
      UpdateTrain__16CFuncTrackChangeR6Vector(param_1,param_1 + 0x120);
      *(undefined4 *)(param_1[0x128] + 0x3d8) = 0;
    }
  }
  return;
}


// GoUp__9CFuncPlat  @ 000c2bc0
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
               ,param_1[0x11f],0x3f4ccccd,0,100);
  }
  param_1[0xfd] = 2;
  param_1[0x114] = -0x10000;
  param_1[0x115] = (int)CallHitTop__9CFuncPlat;
  local_c = param_1[0x104];
  local_8 = param_1[0x105];
  local_4 = param_1[0x106];
  LinearMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
  return;
}


