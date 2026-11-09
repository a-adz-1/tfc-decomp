// EDICT_NUM  @ 0806fe40
int EDICT_NUM(int param_1)

{
  if ((param_1 < 0) || (DAT_08140438 <= param_1)) {
    Sys_Error("EDICT_NUM: bad number %i",param_1);
  }
  return DAT_0814043c + param_1 * 0x2c8;
}


