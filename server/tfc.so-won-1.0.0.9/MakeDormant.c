// MakeDormant__11CBaseEntity  @ 000a1850
void MakeDormant__11CBaseEntity(int *param_1)

{
  *(byte *)(*param_1 + 0x187) = *(byte *)(*param_1 + 0x187) | 0x80;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
  *(undefined4 *)(*param_1 + 0xe4) = 0;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


