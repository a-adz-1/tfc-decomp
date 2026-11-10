// AddAmmo__10CTFRpgAmmoP11CBaseEntity  @ 00144150
bool AddAmmo__10CTFRpgAmmoP11CBaseEntity(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
  uVar2 = 1;
  if (iVar1 != 0) {
    uVar2 = 2;
  }
  iVar1 = (**(code **)(*(int *)(param_2 + 0x454) + 100))(param_2,uVar2,"rockets",5,0);
  if (iVar1 != -1) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"items/9mmclip1.wav",0x3f800000,0x3f4ccccd,0,100)
    ;
  }
  return iVar1 != -1;
}


// AddAmmo__15CBasePlayerAmmoP11CBaseEntity  @ 001264f0
undefined4 AddAmmo__15CBasePlayerAmmoP11CBaseEntity(void)

{
  return 1;
}


