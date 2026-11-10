// ExtractAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon  @ 001243c4
uint ExtractAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_3c;
  uint local_38;
  undefined1 local_30 [8];
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int local_14;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x118))(param_1,local_30);
  if (local_28 != 0) {
    iVar1 = *(int *)(param_1 + 0x4cc);
    if (local_14 < 1) {
      iVar2 = param_2[0x11d];
      param_2[0x130] = -1;
      iVar3 = *(int *)(iVar2 + 0x454);
    }
    else if (param_2[0x130] == 0) {
      local_3c = local_14;
      if (iVar1 < local_14) {
        local_3c = iVar1;
      }
      iVar2 = param_2[0x11d];
      param_2[0x130] = local_3c;
      iVar3 = *(int *)(iVar2 + 0x454);
      iVar1 = iVar1 - local_3c;
    }
    else {
      iVar2 = param_2[0x11d];
      iVar3 = *(int *)(iVar2 + 0x454);
    }
    iVar1 = (**(code **)(iVar3 + 100))(iVar2,iVar1,local_28,local_24,0);
    if (0 < iVar1) {
      param_2[0x12e] = iVar1;
      iVar2 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_2[0x11d],param_2);
      if (iVar2 != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_2 + 0x208),3,"items/9mmclip1.wav",0x3f800000,0x3f4ccccd,0,
                   100);
      }
    }
    local_38 = (uint)(0 < iVar1);
    *(undefined4 *)(param_1 + 0x4cc) = 0;
  }
  if (local_20 != 0) {
    iVar1 = (**(code **)(*(int *)(param_2[0x11d] + 0x454) + 100))
                      (param_2[0x11d],0,local_20,local_1c,0);
    if (0 < iVar1) {
      param_2[0x12f] = iVar1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_2 + 0x208),3,"items/9mmclip1.wav",0x3f800000,0x3f4ccccd,0,
                 100);
    }
    local_38 = (uint)(0 < iVar1);
  }
  return local_38;
}


