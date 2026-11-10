// SetType__5CBeami  @ 000a622c
void SetType__5CBeami(int *param_1,uint param_2)

{
  *(uint *)(*param_1 + 0x148) = *(uint *)(*param_1 + 0x148) & 0xf0 | param_2 & 0xf;
  return;
}


