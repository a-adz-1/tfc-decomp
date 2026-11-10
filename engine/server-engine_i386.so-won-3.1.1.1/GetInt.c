// GetInt__10CUtlBuffer  @ 000dbbb8
undefined4 GetInt__10CUtlBuffer(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 local_8;
  
  cVar1 = IsText__C10CUtlBuffer(param_1);
  if (cVar1 == '\0') {
    cVar1 = CheckGet__10CUtlBufferi(param_1,4);
    if (cVar1 == '\0') {
      local_8 = 0;
    }
    else {
      puVar2 = (undefined4 *)PeekGet__C10CUtlBufferi(param_1,0);
      local_8 = *puVar2;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
    }
  }
  else {
    Scanf__10CUtlBufferPCce(param_1,&DAT_000eddd0,&local_8);
  }
  return local_8;
}


