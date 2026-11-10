// NextThink__15CFuncTrackTrainfi  @ 000cf468
void NextThink__15CFuncTrackTrainfi(int *param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    *(byte *)(*param_1 + 0x1a6) = *(byte *)(*param_1 + 0x1a6) & 0xdf;
  }
  else {
    *(byte *)(*param_1 + 0x1a6) = *(byte *)(*param_1 + 0x1a6) | 0x20;
  }
  *(undefined4 *)(*param_1 + 0x104) = param_2;
  return;
}


