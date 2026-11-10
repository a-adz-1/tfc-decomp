// uncaught_exception__Fv  @ 001205d8
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

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


