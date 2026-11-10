// ButtonActivate__11CBaseButton  @ 00084080
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
  iVar2 = UTIL_IsMasterTriggered__Fi(param_1[0x11d]);
  if (iVar2 == 0) {
    PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x121,1,1);
  }
  else {
    PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x121,0,1);
    param_1[0xfd] = 2;
    fVar1 = *(float *)(*param_1 + 0x1b0);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0x160) = fVar1;
    }
    param_1[0x114] = -0x10000;
    param_1[0x115] = (int)TriggerAndWait__11CBaseButton;
    if (param_1[0x11f] == 0) {
      local_c = param_1[0x107];
      local_8 = param_1[0x108];
      local_4 = param_1[0x109];
      LinearMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
    }
    else {
      local_c = param_1[0x10d];
      local_8 = param_1[0x10e];
      local_4 = param_1[0x10f];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
    }
  }
  return;
}


