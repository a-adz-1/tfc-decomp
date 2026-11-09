// NUM_FOR_EDICT  @ 0806fe80
uint NUM_FOR_EDICT(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(param_1 - DAT_0814043c) / 0x2c8;
  if (DAT_08140434 <= (int)uVar1) {
    Sys_Error("NUM_FOR_EDICT: bad pointer");
  }
  return uVar1;
}


