// GetEyePosition__FPvPf  @ 0007f7e4
void GetEyePosition__FPvPf(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    (*DAT_001a7f34)(1,"GetEyePosition() Can\'t get pstudiohdr ptr!\n");
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x4c);
    param_2[1] = *(undefined4 *)(param_1 + 0x50);
    param_2[2] = *(undefined4 *)(param_1 + 0x54);
  }
  return;
}


