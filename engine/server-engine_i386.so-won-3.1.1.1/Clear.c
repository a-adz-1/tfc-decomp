// Clear__10ObjectListb  @ 000cab20
void Clear__10ObjectListb(int param_1,char param_2)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = *(int *)(param_1 + 4);
  while (local_c != 0) {
    iVar1 = *(int *)(local_c + 4);
    if ((param_2 != '\0') && (*(int *)(local_c + 8) != 0)) {
      Mem_Free(*(undefined4 *)(local_c + 8));
    }
    Mem_Free(local_c);
    local_c = iVar1;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


