// FindGlobalEntity__Fii  @ 000a07f0
undefined4 * FindGlobalEntity__Fii(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (*DAT_001754f8)(0,"globalname",*(int *)(gpGlobals + 0x98) + param_2);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto LAB_000a0842;
    }
  }
  puVar2 = *(undefined4 **)(iVar1 + 0xd8);
LAB_000a0842:
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*puVar2),
                   (char *)(param_1 + *(int *)(gpGlobals + 0x98)));
    if (iVar1 != 0) {
      (*DAT_001755b4)(1,"Global entity found %s, wrong class %s\n",
                      param_2 + *(int *)(gpGlobals + 0x98),
                      *(int *)*puVar2 + *(int *)(gpGlobals + 0x98));
      puVar2 = (undefined4 *)0x0;
    }
  }
  return puVar2;
}


