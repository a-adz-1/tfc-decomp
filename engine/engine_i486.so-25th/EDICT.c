// EDICT_NUM  @ 000753e0
edict_t * EDICT_NUM(int n)

{
  if ((n < 0) || (sv.max_edicts <= n)) {
    Sys_Error("EDICT_NUM: bad number %i",n);
  }
  return sv.edicts + n;
}


