// PointsInit__5CBeamRC6VectorT1  @ 00095e14
void PointsInit__5CBeamRC6VectorT1(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  *(uint *)(*param_1 + 0x148) = *(uint *)(*param_1 + 0x148) & 0xf0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 8) = *param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_2[1];
  *(undefined4 *)(iVar1 + 0x10) = param_2[2];
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = *param_3;
  *(undefined4 *)(iVar1 + 0x54) = param_3[1];
  *(undefined4 *)(iVar1 + 0x58) = param_3[2];
  *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xfff;
  *(uint *)(*param_1 + 0x110) = *(uint *)(*param_1 + 0x110) & 0xfff;
  RelinkBeam__5CBeam(param_1);
  return;
}


