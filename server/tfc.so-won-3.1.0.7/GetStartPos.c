// GetStartPos__5CBeam  @ 000a01a8
int GetStartPos__5CBeam(int *param_1)

{
  int iVar1;
  
  if ((*(uint *)(*param_1 + 0x148) & 0xf) == 2) {
    iVar1 = (*DAT_001c1140)(*(uint *)(*param_1 + 0x128) & 0xfff);
    iVar1 = iVar1 + 0x88;
  }
  else {
    iVar1 = *param_1 + 8;
  }
  return iVar1;
}


