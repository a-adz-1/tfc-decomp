// AddSecondaryAmmo__17CBasePlayerWeaponiPci  @ 001206f0
bool AddSecondaryAmmo__17CBasePlayerWeaponiPci
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1[0x119] + 0x444) + 100))
                    (param_1[0x119],param_2,param_3,param_4,0);
  if (0 < iVar1) {
    param_1[299] = iVar1;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/9mmclip1.wav",0x3f800000,0x3f4ccccd,0,100)
    ;
  }
  return 0 < iVar1;
}


