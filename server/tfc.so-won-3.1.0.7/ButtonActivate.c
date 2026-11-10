// ButtonActivate__11CBaseButton  @ 0008c084
void ButtonActivate__11CBaseButton(int *param_1)

{
  float fVar1;
  int iVar2;
  int local_c;
  int local_8;
  int local_4;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,
             *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100);
  iVar2 = UTIL_IsMasterTriggered__Fi(param_1[0x139]);
  if (iVar2 == 0) {
    PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x13d,1,1);
  }
  else {
    PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x13d,0,1);
    param_1[0x119] = 2;
    fVar1 = *(float *)(*param_1 + 0x1b0);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0x160) = fVar1;
    }
    param_1[0x130] = -0x10000;
    param_1[0x131] = (int)TriggerAndWait__11CBaseButton;
    if (param_1[0x13b] == 0) {
      local_c = param_1[0x123];
      local_8 = param_1[0x124];
      local_4 = param_1[0x125];
      LinearMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
    }
    else {
      local_c = param_1[0x129];
      local_8 = param_1[0x12a];
      local_4 = param_1[299];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
    }
  }
  return;
}


