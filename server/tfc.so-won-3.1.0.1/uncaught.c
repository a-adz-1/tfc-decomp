// uncaught_exception__Fv  @ 00127200
bool uncaught_exception__Fv(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = __cp_eh_info();
  bVar2 = false;
  if (iVar1 != 0) {
    bVar2 = *(char *)(iVar1 + 0x14) == '\0';
  }
  return bVar2;
}


