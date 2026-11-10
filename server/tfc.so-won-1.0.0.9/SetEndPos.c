// SetEndPos__5CBeamRC6Vector  @ 000b09c0
void SetEndPos__5CBeamRC6Vector(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  return;
}


