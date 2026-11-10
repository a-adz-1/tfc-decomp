// new_eh_context  @ 00136a50
undefined4 * new_eh_context(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = malloc(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    __terminate();
  }
  puVar3 = puVar1;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar1[1] = puVar1 + 3;
  return puVar1;
}


