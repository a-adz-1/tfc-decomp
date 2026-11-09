// EDICT_NUM  @ 00092050
edict_t_conflict * EDICT_NUM(int n)

{
  if ((n < 0) || (sv.max_edicts <= n)) {
    Sys_Error("EDICT_NUM: bad number %i",n);
  }
  return sv.edicts + n;
}


