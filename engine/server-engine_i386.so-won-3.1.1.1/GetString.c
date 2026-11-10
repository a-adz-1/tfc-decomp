// GetString__10CUtlBufferPc  @ 000d7f30
void GetString__10CUtlBufferPc(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  
  cVar1 = IsValid__C10CUtlBuffer(param_1);
  if (cVar1 == '\0') {
    *param_2 = '\0';
  }
  else {
    cVar1 = IsText__C10CUtlBuffer(param_1);
    if (cVar1 == '\0') {
      pcVar2 = (char *)__vc__t10CUtlMemory1ZUci(param_1,*(undefined4 *)(param_1 + 0xc));
      sVar3 = strlen(pcVar2);
      Get__10CUtlBufferPvi(param_1,param_2,sVar3 + 1);
    }
    else {
      EatWhiteSpace__10CUtlBuffer(param_1);
      iVar4 = Size__C10CUtlBuffer(param_1);
      while (*(int *)(param_1 + 0xc) < iVar4) {
        pcVar2 = (char *)__vc__t10CUtlMemory1ZUci(param_1,*(undefined4 *)(param_1 + 0xc));
        cVar1 = *pcVar2;
        if (((*(ushort *)(__ctype_b + cVar1 * 2) & 0x2000) != 0) || (cVar1 == '\0')) break;
        *param_2 = cVar1;
        param_2 = param_2 + 1;
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      }
      *param_2 = '\0';
    }
  }
  return;
}


