// AddPrimaryAmmo__17CBasePlayerWeaponiPcii  @ 0011b740
bool AddPrimaryAmmo__17CBasePlayerWeaponiPcii
               (int *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar3;
  code *pcVar2;
  
  if (param_4 < 1) {
    param_1[0x104] = -1;
  }
  else if (param_1[0x104] == 0) {
    if (param_2 < param_4) {
      param_4 = param_2;
    }
    param_4 = param_4 - param_1[0x104];
    param_1[0x104] = param_1[0x104] + param_4;
    iVar1 = param_1[0xfa];
    param_2 = param_2 - param_4;
    pcVar2 = *(code **)(*(int *)(iVar1 + 0x3c8) + 0x60);
    goto LAB_0011b7db;
  }
  iVar1 = param_1[0xfa];
  pcVar2 = *(code **)(*(int *)(iVar1 + 0x3c8) + 0x60);
LAB_0011b7db:
  iVar1 = (*pcVar2)(iVar1,param_2,param_3,param_5,0);
  if (0 < iVar1) {
    param_1[0x102] = iVar1;
    iVar3 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_1[0xfa],param_1);
    if (iVar3 != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),3,"items/9mmclip1.wav",0x3f800000,0x3f4ccccd,0,
                 100);
    }
  }
  return 0 < iVar1;
}


