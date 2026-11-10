// dremove__FP11CBaseEntity  @ 0011e89c
void dremove__FP11CBaseEntity(int *param_1)

{
  if ((param_1 != (int *)0x0) && (param_1[0x18] != 1)) {
    param_1[0x18] = 1;
    (*DAT_001c1078)(*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


