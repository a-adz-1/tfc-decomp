// PointEntInit__5CBeamRC6Vectori  @ 000ab9e0
void PointEntInit__5CBeamRC6Vectori(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  
  *(uint *)(*param_1 + 0x128) = (uint)((byte)*(undefined4 *)(*param_1 + 0x128) & 0xf0 | 1);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 8) = *param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_2[1];
  *(undefined4 *)(iVar1 + 0x10) = param_2[2];
  SetEndEntity__5CBeami(param_1,param_3);
  *(uint *)(*param_1 + 0x108) = *(uint *)(*param_1 + 0x108) & 0xfff;
  *(uint *)(*param_1 + 0xf0) = *(uint *)(*param_1 + 0xf0) & 0xfff;
  RelinkBeam__5CBeam(param_1);
  return;
}


