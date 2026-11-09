// SetFlags__5CBeami  @ 000b0a00
void SetFlags__5CBeami(int *param_1,uint param_2)

{
  *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xf | param_2 & 0xf0;
  return;
}


