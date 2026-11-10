// EntsInit__5CBeamii  @ 000a52d0
void EntsInit__5CBeamii(int *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  *(uint *)(*param_1 + 0x148) = (uint)((byte)*(undefined4 *)(*param_1 + 0x148) & 0xf0 | 2);
  *(uint *)(*param_1 + 0x128) = param_2 & 0xfff | (*(uint *)(*param_1 + 0x128) & 0xf000) << 0xc;
  uVar1 = (*DAT_0019f7c0)(param_2);
  *(undefined4 *)(*param_1 + 0x198) = uVar1;
  *(uint *)(*param_1 + 0x110) = param_3 & 0xfff | (*(uint *)(*param_1 + 0x110) & 0xf000) << 0xc;
  uVar1 = (*DAT_0019f7c0)(param_3);
  *(undefined4 *)(*param_1 + 0x194) = uVar1;
  *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xfff;
  *(uint *)(*param_1 + 0x110) = *(uint *)(*param_1 + 0x110) & 0xfff;
  RelinkBeam__5CBeam(param_1);
  return;
}


