// SetStartAttachment__5CBeami  @ 000a5e5c
void SetStartAttachment__5CBeami(int *param_1,uint param_2)

{
  *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xfff | (param_2 & 0xf) << 0xc;
  return;
}


