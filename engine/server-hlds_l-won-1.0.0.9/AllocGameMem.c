// AllocGameMem__Fv  @ 080896a0
bool AllocGameMem__Fv(void)

{
  int iVar1;
  int local_8;
  
  giMemSize = 0xc00000;
  iVar1 = CheckParm__FPCcPPc("-heapsize",&local_8);
  if ((iVar1 != 0) && (local_8 != 0)) {
    iVar1 = __strtol_internal(local_8,0,10,0);
    giMemSize = iVar1 << 10;
  }
  gpMemBase = malloc(giMemSize);
  return gpMemBase != (void *)0x0;
}


