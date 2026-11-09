// NUM_FOR_EDICT  @ 000d58e0
int NUM_FOR_EDICT(edict_t *e)

{
  uint uVar1;
  
                    /* Unresolved local var: int b@[???] */
  uVar1 = (uint)((int)e - (int)sv.edicts) / 0x324;
  if (sv.num_edicts <= (int)uVar1) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("NUM_FOR_EDICT: bad pointer");
  }
  return uVar1;
}


