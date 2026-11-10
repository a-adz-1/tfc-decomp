// HashString__18CSaveRestoreBufferPCc  @ 0011cb94
void HashString__18CSaveRestoreBufferPCc(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = *param_2;
  while (cVar1 != '\0') {
    uVar2 = _rotr(uVar2,4);
    uVar2 = (int)*param_2 ^ uVar2;
    param_2 = param_2 + 1;
    cVar1 = *param_2;
  }
  return;
}


