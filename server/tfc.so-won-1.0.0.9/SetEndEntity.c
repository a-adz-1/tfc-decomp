// SetEndEntity__5CBeami  @ 000ab710
void SetEndEntity__5CBeami(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  *(uint *)(*param_1 + 0xf0) = param_2 & 0xfff | (*(uint *)(*param_1 + 0xf0) & 0xf000) << 0xc;
  uVar1 = (*DAT_001755e0)(param_2);
  *(undefined4 *)(*param_1 + 0x174) = uVar1;
  return;
}


