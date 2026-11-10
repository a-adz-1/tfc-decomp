// PutInt__10CUtlBufferi  @ 000dbce4
void PutInt__10CUtlBufferi(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = IsText__C10CUtlBuffer(param_1);
  if (cVar1 == '\0') {
    cVar1 = CheckPut__10CUtlBufferi(param_1,4);
    if (cVar1 != '\0') {
      puVar2 = (undefined4 *)PeekPut__10CUtlBufferi(param_1,0);
      *puVar2 = param_2;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 4;
    }
  }
  else {
    Printf__10CUtlBufferPCce(param_1,&DAT_000eddd0,param_2);
  }
  return;
}


