// EatWhiteSpace__10CUtlBuffer  @ 000d7e94
void EatWhiteSpace__10CUtlBuffer(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  cVar1 = IsText__C10CUtlBuffer(param_1);
  if ((cVar1 != '\0') && (cVar1 = IsValid__C10CUtlBuffer(param_1), cVar1 != '\0')) {
    iVar2 = Size__C10CUtlBuffer(param_1);
    while ((*(int *)(param_1 + 0xc) < iVar2 &&
           (pcVar3 = (char *)__vc__t10CUtlMemory1ZUci(param_1,*(undefined4 *)(param_1 + 0xc)),
           (*(ushort *)(__ctype_b + *pcVar3 * 2) & 0x2000) != 0))) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
  }
  return;
}


