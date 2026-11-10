// ExplosionCreate__FRC6VectorT0P7edict_sii  @ 0009d5e4
void ExplosionCreate__FRC6VectorT0P7edict_sii
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5)

{
  int *piVar1;
  char local_90 [128];
  undefined1 local_10 [4];
  char *local_c;
  char *local_8;
  
  piVar1 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                            ("env_explosion",param_1,param_2,param_3);
  sprintf(local_90,"%3d",param_4);
  local_c = "iMagnitude";
  local_8 = local_90;
  (**(code **)(piVar1[0xf5] + 0x10))(piVar1,local_10);
  if (param_5 == 0) {
    *(byte *)(*piVar1 + 0x1a0) = *(byte *)(*piVar1 + 0x1a0) | 1;
  }
  (**(code **)(piVar1[0xf5] + 8))(piVar1);
  (**(code **)(piVar1[0xf5] + 0xb0))(piVar1,0,0,3,0);
  return;
}


