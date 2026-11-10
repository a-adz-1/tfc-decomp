// GetStartPos__5CBeam  @ 000ab760
int GetStartPos__5CBeam(int *param_1)

{
  int iVar1;
  
  if ((*(uint *)(*param_1 + 0x128) & 0xf) == 2) {
    iVar1 = (*DAT_001755e0)(*(uint *)(*param_1 + 0x108) & 0xfff);
    iVar1 = iVar1 + 0xe4;
  }
  else {
    iVar1 = *param_1 + 8;
  }
  return iVar1;
}


