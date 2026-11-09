// StopSound__15CFuncTrackTrain  @ 000d31d0
void StopSound__15CFuncTrackTrain(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xff] != 0) && (iVar1 = *param_1, *(int *)(iVar1 + 0x1c8) != 0)) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),6,*(int *)(iVar1 + 0x1c8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),3,"plats/ttrain_brake1.wav",param_1[0x101],
               0x3f4ccccd,0,100);
  }
  param_1[0xff] = 0;
  return;
}


