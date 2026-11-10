// NUM_FOR_EDICT  @ 0008e66c
uint NUM_FOR_EDICT(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(param_1 - DAT_003a78b8) / 0x324;
  if (DAT_003a78b0 <= (int)uVar1) {
    Sys_Error("NUM_FOR_EDICT: bad pointer");
  }
  return uVar1;
}


