// SetStartAttachment__5CBeami  @ 000b0990
void SetStartAttachment__5CBeami(int *param_1,uint param_2)

{
  *(uint *)(*param_1 + 0x108) = *(uint *)(*param_1 + 0x108) & 0xfff | (param_2 & 0xf) << 0xc;
  return;
}


