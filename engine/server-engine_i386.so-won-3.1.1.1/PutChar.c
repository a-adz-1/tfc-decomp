// PutChar__10CUtlBufferc  @ 000dbc60
void PutChar__10CUtlBufferc(int param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = IsText__C10CUtlBuffer(param_1);
  if (cVar1 == '\0') {
    cVar1 = CheckPut__10CUtlBufferi(param_1,1);
    if (cVar1 != '\0') {
      pcVar2 = (char *)PeekPut__10CUtlBufferi(param_1,0);
      *pcVar2 = param_2;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    }
  }
  else {
    Printf__10CUtlBufferPCce(param_1,&UNK_000eddca,(int)param_2);
  }
  return;
}


