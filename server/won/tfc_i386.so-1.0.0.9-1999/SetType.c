// SetType__5CBeami  @ 000b0a30
void SetType__5CBeami(int *param_1,uint param_2)

{
  *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xf0 | param_2 & 0xf;
  return;
}


