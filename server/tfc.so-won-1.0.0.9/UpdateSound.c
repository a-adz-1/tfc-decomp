// UpdateSound__15CFuncTrackTrain  @ 000d3260
void UpdateSound__15CFuncTrackTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar2 = (int)ROUND(*(float *)(*param_1 + 0x1d8));
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    fVar1 = (float)((iVar2 * 0x8c) / 1000 + 0x3c);
    if (param_1[0xff] == 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),3,"plats/ttrain_start1.wav",param_1[0x101],
                 0x3f4ccccd,0,100);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),6,
                 *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98),param_1[0x101],0x3f4ccccd,0
                 ,(int)ROUND(fVar1));
      param_1[0xff] = 1;
    }
    else {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),6,
                 *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98),param_1[0x101],0x3f4ccccd,
                 0x80,(int)ROUND(fVar1));
    }
  }
  return;
}


