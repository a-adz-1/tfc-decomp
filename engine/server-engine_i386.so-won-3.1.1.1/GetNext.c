// GetNext__10ObjectList  @ 000cace0
undefined4 GetNext__10ObjectList(int param_1)

{
  undefined4 local_8;
  
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    local_8 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 4);
  }
  return local_8;
}


