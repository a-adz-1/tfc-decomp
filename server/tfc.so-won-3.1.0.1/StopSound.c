// StopSound__15CFuncTrackTrain  @ 000c4640
void StopSound__15CFuncTrackTrain(int *param_1)

{
  if ((param_1[0x102] != 0) && (*(int *)(*param_1 + 0x1e8) != 0)) {
    (*DAT_001a802c)(10,*(undefined4 *)(*param_1 + 0x208),(short)param_1[0x107],0,&g_vecZero,
                    &g_vecZero,0,0,(*(ushort *)(param_1 + 0x103) & 7) << 0xc,0,1,0);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"plats/ttrain_brake1.wav",param_1[0x104],
               0x3f4ccccd,0,100);
  }
  param_1[0x102] = 0;
  return;
}


