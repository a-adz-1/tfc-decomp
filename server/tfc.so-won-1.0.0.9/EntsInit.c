// EntsInit__5CBeamii  @ 000aba50
void EntsInit__5CBeamii(int *param_1,undefined4 param_2,undefined4 param_3)

{
  *(uint *)(*param_1 + 0x128) = (uint)((byte)*(undefined4 *)(*param_1 + 0x128) & 0xf0 | 2);
  SetStartEntity__5CBeami(param_1,param_2);
  SetEndEntity__5CBeami(param_1,param_3);
  *(uint *)(*param_1 + 0x108) = *(uint *)(*param_1 + 0x108) & 0xfff;
  *(uint *)(*param_1 + 0xf0) = *(uint *)(*param_1 + 0xf0) & 0xfff;
  RelinkBeam__5CBeam(param_1);
  return;
}


