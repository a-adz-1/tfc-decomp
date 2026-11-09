// NUM_FOR_EDICT  @ 00075420
int NUM_FOR_EDICT(edict_t *e)

{
  uint uVar1;
  
                    /* Unresolved local var: int b@[???] */
  uVar1 = (uint)((int)e - (int)sv.edicts) / 0x324;
  if (sv.num_edicts <= (int)uVar1) {
    Sys_Error("NUM_FOR_EDICT: bad pointer");
  }
  return uVar1;
}


