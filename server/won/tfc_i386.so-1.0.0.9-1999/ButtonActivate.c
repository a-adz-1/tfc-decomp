// ButtonActivate__11CBaseButton  @ 0009eb80
void ButtonActivate__11CBaseButton(int *param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),2,
             *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100);
  iVar1 = UTIL_IsMasterTriggered__Fi(param_1[0x11a]);
  if (iVar1 == 0) {
    PlayLockSounds__FP9entvars_tP10locksoundsii(*param_1,param_1 + 0x11e,1,1);
  }
  else {
    PlayLockSounds__FP9entvars_tP10locksoundsii(*param_1,param_1 + 0x11e,0,1);
    param_1[0xfa] = 2;
    param_1[0x111] = -0x10000;
    param_1[0x112] = (int)TriggerAndWait__11CBaseButton;
    if (param_1[0x11c] == 0) {
      local_10 = param_1[0x104];
      local_c = param_1[0x105];
      local_8 = param_1[0x106];
      LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1d8));
    }
    else {
      local_10 = param_1[0x10a];
      local_c = param_1[0x10b];
      local_8 = param_1[0x10c];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1d8));
    }
  }
  return;
}


