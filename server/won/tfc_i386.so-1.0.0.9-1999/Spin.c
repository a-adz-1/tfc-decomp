// Spin__11CTFAssaultC  @ 000f7d30
void Spin__11CTFAssaultC(int param_1)

{
  *(undefined4 *)(param_1 + 0x42c) = 3;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),6,"weapons/asscan2.wav",0,0,0x20,
             100);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),6,"weapons/asscan4.wav",0x3f7ae148,
             0x3f4ccccd,0,0x7d);
  return;
}


