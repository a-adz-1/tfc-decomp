// WindDown__11CTFAssaultC  @ 000f7e20
void WindDown__11CTFAssaultC(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (*(int *)(param_1 + 0x42c) == 2) {
    uVar2 = *(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8);
    pcVar3 = "weapons/asscan2.wav";
  }
  else {
    uVar2 = *(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8);
    pcVar3 = "weapons/asscan4.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar2,6,pcVar3,0,0,0x20,100);
  *(undefined4 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(param_1 + 0x42c) = 0;
  pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x89);
  *pbVar1 = *pbVar1 & 0xf7;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 1000));
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,3);
  *(float *)(param_1 + 0x404) = *gpGlobals + 2.0;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/asscan3.wav",0x3f7ae148,
             0x3f4ccccd,0,0x7d);
  return;
}


