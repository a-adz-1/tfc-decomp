// EDICT_NUM  @ 00071b78
int EDICT_NUM(int param_1)

{
  if ((param_1 < 0) || (DAT_00186f90 <= param_1)) {
    Sys_Error("EDICT_NUM: bad number %i",param_1);
  }
  return DAT_00186f94 + param_1 * 0x324;
}


