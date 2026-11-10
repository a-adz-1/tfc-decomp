// GetStartPos__5CBeam  @ 000a56dc
int GetStartPos__5CBeam(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((*(uint *)(iVar1 + 0x148) & 0xf) == 2) {
    iVar1 = (*DAT_0019f7c0)(*(uint *)(iVar1 + 0x128) & 0xfff);
    iVar1 = iVar1 + 0x88;
  }
  else {
    iVar1 = iVar1 + 8;
  }
  return iVar1;
}


