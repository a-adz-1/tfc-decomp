// dremove__FP11CBaseEntity  @ 00120aa4
void dremove__FP11CBaseEntity(int *param_1)

{
  if ((param_1 != (int *)0x0) && (param_1[0x18] != 1)) {
    param_1[0x18] = 1;
    (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


