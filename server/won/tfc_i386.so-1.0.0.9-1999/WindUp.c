// WindUp__11CTFAssaultC  @ 000f7da0
void WindUp__11CTFAssaultC(int param_1)

{
  byte *pbVar1;
  
  *(undefined4 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(param_1 + 0x42c) = 1;
  pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x89);
  *pbVar1 = *pbVar1 | 8;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 1000));
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,2);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/asscan1.wav",0x3f7ae148,
             0x3f4ccccd,0,0x7d);
  return;
}


