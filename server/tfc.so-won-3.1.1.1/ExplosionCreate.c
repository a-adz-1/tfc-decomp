// ExplosionCreate__FRC6VectorT0P7edict_sii  @ 000a7510
void ExplosionCreate__FRC6VectorT0P7edict_sii
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5)

{
  int *piVar1;
  char local_94 [128];
  undefined1 local_14 [4];
  char *local_10;
  char *local_c;
  
  piVar1 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                            ("env_explosion",param_1,param_2,param_3);
  sprintf(local_94,"%3d",param_4);
  local_10 = "iMagnitude";
  local_c = local_94;
  (**(code **)(piVar1[0x115] + 0x14))(piVar1,local_14);
  if (param_5 == 0) {
    *(byte *)(*piVar1 + 0x1a0) = *(byte *)(*piVar1 + 0x1a0) | 1;
  }
  (**(code **)(piVar1[0x115] + 0xc))(piVar1);
  (**(code **)(piVar1[0x115] + 0xb8))(piVar1,0,0,3,0);
  return;
}


