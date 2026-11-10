// FlameDestroy__8CTFFlame  @ 000e690c
void FlameDestroy__8CTFFlame(int *param_1)

{
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,"ambience/fire1.wav",0,0,0x20,100);
  num_world_flames = num_world_flames - 1.0;
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


