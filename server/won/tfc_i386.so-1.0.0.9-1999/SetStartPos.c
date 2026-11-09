// SetStartPos__5CBeamRC6Vector  @ 000b09e0
void SetStartPos__5CBeamRC6Vector(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 8) = *param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_2[1];
  *(undefined4 *)(iVar1 + 0x10) = param_2[2];
  return;
}


