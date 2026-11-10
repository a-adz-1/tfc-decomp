// StopSound__15CFuncTrackTrain  @ 000cf9a0
void StopSound__15CFuncTrackTrain(int *param_1)

{
  if ((param_1[0x11e] != 0) && (*(int *)(*param_1 + 0x1e8) != 0)) {
    (*DAT_001c120c)(10,*(undefined4 *)(*param_1 + 0x208),(short)param_1[0x123],0,&g_vecZero,
                    &g_vecZero,0,0,(*(ushort *)(param_1 + 0x11f) & 7) << 0xc,0,1,0);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"plats/ttrain_brake1.wav",param_1[0x120],
               0x3f4ccccd,0,100);
  }
  param_1[0x11e] = 0;
  return;
}


