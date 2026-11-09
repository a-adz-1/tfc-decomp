// EDICT_NUM  @ 000d58a0
edict_t * EDICT_NUM(int n)

{
  if ((-1 < n) && (n < sv.max_edicts)) {
    return sv.edicts + n;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("EDICT_NUM: bad number %i",n);
}


