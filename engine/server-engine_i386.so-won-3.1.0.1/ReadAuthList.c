// ReadAuthList__Fv  @ 00095298
int * ReadAuthList__Fv(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int *local_8;
  
  piVar4 = (int *)0x0;
  local_8 = (int *)0x0;
  piVar2 = (int *)Crypt_ParseServers__FPc(g_szServerFile);
  if (piVar2 != (int *)0x0) {
    piVar4 = (int *)0x0;
    do {
      piVar1 = (int *)*piVar2;
      uVar3 = rand();
      if ((uVar3 & 1) == 0) {
        *piVar2 = (int)local_8;
        local_8 = piVar2;
      }
      else {
        *piVar2 = (int)piVar4;
        piVar4 = piVar2;
      }
      piVar2 = piVar1;
    } while (piVar1 != (int *)0x0);
  }
  piVar2 = (int *)0x0;
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)*piVar4;
    *piVar4 = (int)piVar2;
    piVar2 = piVar4;
    piVar4 = piVar1;
  }
  while (piVar4 = local_8, piVar4 != (int *)0x0) {
    local_8 = (int *)*piVar4;
    *piVar4 = (int)piVar2;
    piVar2 = piVar4;
  }
  return piVar2;
}


