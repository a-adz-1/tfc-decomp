// SetFlags__5CBeami  @ 000a6208
void SetFlags__5CBeami(int *param_1,uint param_2)

{
  *(uint *)(*param_1 + 0x148) = *(uint *)(*param_1 + 0x148) & 0xf | param_2 & 0xf0;
  return;
}


