// Contains__10ObjectListPv  @ 000caad0
uint Contains__10ObjectListPv(int param_1,int param_2)

{
  uint uVar1;
  uint local_8;
  
  uVar1 = *(uint *)(param_1 + 4);
  for (local_8 = *(uint *)(param_1 + 4);
      (local_8 != 0 && (uVar1 = local_8, *(int *)(local_8 + 8) != param_2));
      local_8 = *(uint *)(local_8 + 4)) {
  }
  if (local_8 == 0) {
    uVar1 = uVar1 & 0xffffff00;
  }
  else {
    *(uint *)(param_1 + 0xc) = local_8;
    uVar1 = CONCAT31((int3)(local_8 >> 8),1);
  }
  return uVar1;
}


