// NextThink__15CFuncTrackTrainfi  @ 000d2d60
void NextThink__15CFuncTrackTrainfi(int *param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    *(byte *)(*param_1 + 0x186) = *(byte *)(*param_1 + 0x186) & 0xdf;
  }
  else {
    *(byte *)(*param_1 + 0x186) = *(byte *)(*param_1 + 0x186) | 0x20;
  }
  *(undefined4 *)(*param_1 + 0xe4) = param_2;
  return;
}


