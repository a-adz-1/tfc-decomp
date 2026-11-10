// UpdateSound__15CFuncTrackTrain  @ 000ceea4
void UpdateSound__15CFuncTrackTrain(int *param_1)

{
  int iVar1;
  int iVar2;
  uint local_24;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1e8) != 0) {
    iVar2 = (int)ROUND(*(float *)(iVar1 + 0x1f8));
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    iVar2 = (iVar2 * 0x8c) / 1000 + 0x3c;
    if (param_1[0x122] == 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar1 + 0x208),3,"plats/ttrain_start1.wav",param_1[0x124],
                 0x3f4ccccd,0,100);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,
                 *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),param_1[0x124],0x3f4ccccd,0
                 ,(int)ROUND((float)iVar2));
      param_1[0x122] = 1;
    }
    else {
      local_24 = (uint)(longlong)ROUND((float)param_1[0x124] * 40.0);
      (*DAT_0019f88c)(10,*(undefined4 *)(iVar1 + 0x208),(short)param_1[0x127],0,&g_vecZero,
                      &g_vecZero,0,0,
                      (uint)(ushort)((*(ushort *)(param_1 + 0x123) & 7) << 0xc |
                                    ((ushort)(longlong)ROUND((double)iVar2 * 0.1) & 0x3f) << 6) |
                      local_24 & 0x3f,0,0,0);
    }
  }
  return;
}


