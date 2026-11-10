// SetEndAttachment__5CBeami  @ 000b0960
void SetEndAttachment__5CBeami(int *param_1,uint param_2)

{
  *(uint *)(*param_1 + 0xf0) = *(uint *)(*param_1 + 0xf0) & 0xfff | (param_2 & 0xf) << 0xc;
  return;
}


