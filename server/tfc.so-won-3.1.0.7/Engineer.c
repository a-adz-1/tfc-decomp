// Engineer_RemoveBuildings__11CBasePlayer  @ 000e212c
void Engineer_RemoveBuildings__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x1a] == 1) {
    *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) & 0xfe;
    TeamFortress_SetSpeed__11CBasePlayer(param_1);
    iVar1 = FindTimer__11CBaseEntityi(param_1,0xb);
    if (iVar1 != 0) {
      dremove__FP11CBaseEntity(iVar1);
    }
    uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
    UTIL_Remove__FP11CBaseEntity(uVar2);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
    param_1[0x1a] = 0;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"weapons/building.wav",0,0,0x20,100);
    if (param_1[0x22d] != 0) {
      (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x120))(param_1[0x22d]);
    }
  }
  DestroyBuilding__FP11CBaseEntityPc(param_1,"building_dispenser");
  DestroyBuilding__FP11CBaseEntityPc(param_1,"building_sentrygun");
  return;
}


