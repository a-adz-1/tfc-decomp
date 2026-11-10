// PointEntInit__5CBeamRC6Vectori  @ 000a53a4
void PointEntInit__5CBeamRC6Vectori(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *(uint *)(*param_1 + 0x148) = (uint)((byte)*(undefined4 *)(*param_1 + 0x148) & 0xf0 | 1);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 8) = *param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_2[1];
  *(undefined4 *)(iVar1 + 0x10) = param_2[2];
  *(uint *)(*param_1 + 0x110) = param_3 & 0xfff | (*(uint *)(*param_1 + 0x110) & 0xf000) << 0xc;
  uVar2 = (*DAT_0019f7c0)(param_3);
  *(undefined4 *)(*param_1 + 0x194) = uVar2;
  *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xfff;
  *(uint *)(*param_1 + 0x110) = *(uint *)(*param_1 + 0x110) & 0xfff;
  RelinkBeam__5CBeam(param_1);
  return;
}


