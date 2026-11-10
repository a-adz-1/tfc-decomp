// SetEndEntity__5CBeami  @ 00095bf0
void SetEndEntity__5CBeami(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  *(uint *)(*param_1 + 0x110) = param_2 & 0xfff | (*(uint *)(*param_1 + 0x110) & 0xf000) << 0xc;
  uVar1 = (*DAT_001a7f60)(param_2);
  *(undefined4 *)(*param_1 + 0x194) = uVar1;
  return;
}


