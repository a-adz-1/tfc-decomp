// CountToken__9TokenLine  @ 000cb0b0
int CountToken__9TokenLine(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < *(int *)(param_1 + 0x1200); local_c = local_c + 1) {
    if (*(int *)(local_c * 4 + param_1 + 0x1000) != 0) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


