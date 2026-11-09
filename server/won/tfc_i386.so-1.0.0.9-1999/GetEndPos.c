// GetEndPos__5CBeam  @ 000ab7a0
int GetEndPos__5CBeam(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(*param_1 + 0x128) & 0xf;
  if (((uVar1 != 0) && (uVar1 != 3)) &&
     (iVar2 = (*DAT_001755e0)(*(uint *)(*param_1 + 0xf0) & 0xfff), iVar2 != 0)) {
    return iVar2 + 0xe4;
  }
  return *param_1 + 0x50;
}


