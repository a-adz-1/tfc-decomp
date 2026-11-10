// CreateInstancedBaselines__Fv  @ 0008c084
void CreateInstancedBaselines__Fv(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined1 local_154 [340];
  
  local_160 = 0;
  local_15c = 0;
  local_158 = 0;
  memset(local_154,0,0x154);
  piVar1 = (int *)GetClassPtr__H1Z10CTFCaltrop_PX01_PX01(0);
  ScatterDrop__10CTFCaltropP11CBaseEntity(piVar1,0);
  local_16c = local_160;
  local_168 = local_15c;
  local_164 = local_158;
  local_178 = local_160;
  local_174 = local_15c;
  local_170 = local_158;
  CreateBaseline__FiiP14entity_state_sP7edict_siG6VectorT5
            (0,0,local_154,*(undefined4 *)(*piVar1 + 0x208),0,&local_16c,&local_178);
  (*DAT_001a8060)(*(undefined4 *)*piVar1,local_154);
  piVar2 = (int *)GetClassPtr__H1Z10CWeaponBox_PX01_PX01(0);
  *(int *)*piVar2 = (int)"weaponbox" - *(int *)(gpGlobals + 0x98);
  (**(code **)(piVar2[0xf5] + 8))(piVar2);
  local_178 = local_160;
  local_174 = local_15c;
  local_170 = local_158;
  local_16c = local_160;
  local_168 = local_15c;
  local_164 = local_158;
  CreateBaseline__FiiP14entity_state_sP7edict_siG6VectorT5
            (0,0,local_154,*(undefined4 *)(*piVar2 + 0x208),0,&local_178,&local_16c);
  (*DAT_001a8060)(*(undefined4 *)*piVar2,local_154);
  UTIL_Remove__FP11CBaseEntity(piVar1);
  UTIL_Remove__FP11CBaseEntity(piVar2);
  return;
}


