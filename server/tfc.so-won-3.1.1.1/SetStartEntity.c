// SetStartEntity__5CBeami  @ 000a578c
void SetStartEntity__5CBeami(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  *(uint *)(*param_1 + 0x128) = param_2 & 0xfff | (*(uint *)(*param_1 + 0x128) & 0xf000) << 0xc;
  uVar1 = (*DAT_0019f7c0)(param_2);
  *(undefined4 *)(*param_1 + 0x198) = uVar1;
  return;
}


