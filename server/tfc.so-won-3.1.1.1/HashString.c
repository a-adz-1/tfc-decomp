// HashString__18CSaveRestoreBufferPCc  @ 00121520
void HashString__18CSaveRestoreBufferPCc(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  uVar2 = 0;
  cVar1 = *param_2;
  while (cVar1 != '\0') {
    iVar4 = 3;
    do {
      uVar3 = uVar2 & 1;
      uVar2 = uVar2 >> 1;
      if (uVar3 != 0) {
        uVar2 = uVar2 | 0x80000000;
      }
      bVar5 = iVar4 != 0;
      iVar4 = iVar4 + -1;
    } while (bVar5);
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    uVar2 = (int)cVar1 ^ uVar2;
    cVar1 = *param_2;
  }
  return;
}


