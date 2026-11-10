// AddPrimaryAmmo__17CBasePlayerWeaponiPcii  @ 001258f0
bool AddPrimaryAmmo__17CBasePlayerWeaponiPcii
               (int *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  if (param_4 < 1) {
    iVar1 = param_1[0x11d];
    param_1[0x130] = -1;
  }
  else {
    if (param_1[0x130] == 0) {
      local_8 = param_4;
      if (param_2 < param_4) {
        local_8 = param_2;
      }
      iVar1 = param_1[0x11d];
      param_1[0x130] = local_8;
      iVar2 = *(int *)(iVar1 + 0x454);
      param_2 = param_2 - local_8;
      goto LAB_00125972;
    }
    iVar1 = param_1[0x11d];
  }
  iVar2 = *(int *)(iVar1 + 0x454);
LAB_00125972:
  iVar1 = (**(code **)(iVar2 + 100))(iVar1,param_2,param_3,param_5,0);
  if (0 < iVar1) {
    param_1[0x12e] = iVar1;
    iVar2 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_1[0x11d],param_1);
    if (iVar2 != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"items/9mmclip1.wav",0x3f800000,0x3f4ccccd,0,
                 100);
    }
  }
  return 0 < iVar1;
}


