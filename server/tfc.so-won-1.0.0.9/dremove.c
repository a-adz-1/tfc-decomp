// dremove__FP11CBaseEntity  @ 0011a1a0
void dremove__FP11CBaseEntity(int *param_1)

{
  if ((param_1 != (int *)0x0) && (param_1[0x19] != 1)) {
    param_1[0x19] = 1;
    (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  }
  return;
}


