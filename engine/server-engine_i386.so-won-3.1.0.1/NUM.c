// NUM_FOR_EDICT  @ 00071bcc
uint NUM_FOR_EDICT(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(param_1 - DAT_00186f94) / 0x324;
  if (DAT_00186f8c <= (int)uVar1) {
    Sys_Error("NUM_FOR_EDICT: bad pointer");
  }
  return uVar1;
}


