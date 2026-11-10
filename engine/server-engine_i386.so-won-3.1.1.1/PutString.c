// PutString__10CUtlBufferPCc  @ 000d84e8
void PutString__10CUtlBufferPCc(undefined4 param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  uVar2 = 0xd84f5;
  local_8 = strlen(param_2);
  cVar1 = IsText__C10CUtlBuffer(param_1);
  if (cVar1 == '\0') {
    local_8 = local_8 + 1;
  }
  Put__10CUtlBufferPCvi(param_1,param_2,local_8,uVar2);
  return;
}


