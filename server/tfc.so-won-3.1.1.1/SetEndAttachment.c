// SetEndAttachment__5CBeami  @ 000a5e30
void SetEndAttachment__5CBeami(int *param_1,uint param_2)

{
  *(uint *)(*param_1 + 0x110) = *(uint *)(*param_1 + 0x110) & 0xfff | (param_2 & 0xf) << 0xc;
  return;
}


