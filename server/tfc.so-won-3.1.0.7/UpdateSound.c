// UpdateSound__15CFuncTrackTrain  @ 000cfa54
void UpdateSound__15CFuncTrackTrain(int *param_1)

{
  int iVar1;
  uint local_1c;
  
  if (*(int *)(*param_1 + 0x1e8) != 0) {
    iVar1 = (int)ROUND(*(float *)(*param_1 + 0x1f8));
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    iVar1 = (iVar1 * 0x8c) / 1000 + 0x3c;
    if (param_1[0x11e] == 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"plats/ttrain_start1.wav",param_1[0x120],
                 0x3f4ccccd,0,100);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,
                 *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),param_1[0x120],0x3f4ccccd,0
                 ,(int)ROUND((float)iVar1));
      param_1[0x11e] = 1;
    }
    else {
      local_1c = (uint)(longlong)ROUND((float)param_1[0x120] * 40.0);
      (*DAT_001c120c)(10,*(undefined4 *)(*param_1 + 0x208),(short)param_1[0x123],0,&g_vecZero,
                      &g_vecZero,0,0,
                      (uint)(ushort)((*(ushort *)(param_1 + 0x11f) & 7) << 0xc |
                                    ((ushort)(longlong)ROUND((double)iVar1 * 0.1) & 0x3f) << 6) |
                      local_1c & 0x3f,0,0,0);
    }
  }
  return;
}


