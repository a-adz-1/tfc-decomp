// ButtonActivate__11CBaseButton  @ 0008b474
void ButtonActivate__11CBaseButton(int *param_1)

{
  float fVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,
             *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100);
  iVar2 = UTIL_IsMasterTriggered__Fi(param_1[0x13d]);
  if (iVar2 == 0) {
    PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x141,1,1);
  }
  else {
    PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x141,0,1);
    param_1[0x11d] = 2;
    fVar1 = *(float *)(*param_1 + 0x1b0);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      *(float *)(*param_1 + 0x160) = fVar1;
    }
    param_1[0x134] = -0x10000;
    param_1[0x135] = (int)TriggerAndWait__11CBaseButton;
    if (param_1[0x13f] == 0) {
      local_10 = param_1[0x127];
      local_c = param_1[0x128];
      local_8 = param_1[0x129];
      LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1f8));
    }
    else {
      local_10 = param_1[0x12d];
      local_c = param_1[0x12e];
      local_8 = param_1[0x12f];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1f8));
    }
  }
  return;
}


