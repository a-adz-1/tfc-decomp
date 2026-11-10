// EntsInit__5CBeamii  @ 000a04d8
void EntsInit__5CBeamii(int *param_1,undefined4 param_2,undefined4 param_3)

{
  *(uint *)(*param_1 + 0x148) = (uint)((byte)*(undefined4 *)(*param_1 + 0x148) & 0xf0 | 2);
  SetStartEntity__5CBeami(param_1,param_2);
  SetEndEntity__5CBeami(param_1,param_3);
  *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xfff;
  *(uint *)(*param_1 + 0x110) = *(uint *)(*param_1 + 0x110) & 0xfff;
  RelinkBeam__5CBeam(param_1);
  return;
}


