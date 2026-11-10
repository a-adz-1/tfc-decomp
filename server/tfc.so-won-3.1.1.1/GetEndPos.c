// GetEndPos__5CBeam  @ 000a5678
int GetEndPos__5CBeam(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  uVar1 = *(uint *)(iVar2 + 0x148) & 0xf;
  if ((uVar1 == 0) || (uVar1 == 3)) {
    iVar2 = iVar2 + 0x50;
  }
  else {
    iVar2 = (*DAT_0019f7c0)(*(uint *)(iVar2 + 0x110) & 0xfff);
    if (iVar2 == 0) {
      iVar2 = *param_1 + 0x50;
    }
    else {
      iVar2 = iVar2 + 0x88;
    }
  }
  return iVar2;
}


