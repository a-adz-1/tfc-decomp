// EDICT_NUM  @ 0008e5e4
int EDICT_NUM(int param_1)

{
  if ((param_1 < 0) || (DAT_003a78b4 <= param_1)) {
    Sys_Error("EDICT_NUM: bad number %i",param_1);
  }
  return param_1 * 0x324 + DAT_003a78b8;
}


