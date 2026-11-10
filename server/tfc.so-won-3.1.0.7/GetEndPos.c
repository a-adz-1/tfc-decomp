// GetEndPos__5CBeam  @ 000a01f8
int GetEndPos__5CBeam(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(*param_1 + 0x148) & 0xf;
  if (((uVar1 != 0) && (uVar1 != 3)) &&
     (iVar2 = (*DAT_001c1140)(*(uint *)(*param_1 + 0x110) & 0xfff), iVar2 != 0)) {
    return iVar2 + 0x88;
  }
  return *param_1 + 0x50;
}


