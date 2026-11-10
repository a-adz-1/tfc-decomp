// FindGlobalEntity__Fii  @ 0008e120
undefined4 * FindGlobalEntity__Fii(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (*DAT_001c1058)(0,"globalname",*(int *)(gpGlobals + 0x98) + param_2);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto LAB_0008e17e;
    }
  }
  puVar2 = *(undefined4 **)(iVar1 + 0x7c);
LAB_0008e17e:
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*puVar2),
                   (char *)(param_1 + *(int *)(gpGlobals + 0x98)));
    if (iVar1 != 0) {
      (*DAT_001c1114)(1,"Global entity found %s, wrong class %s\n",
                      param_2 + *(int *)(gpGlobals + 0x98),
                      *(int *)*puVar2 + *(int *)(gpGlobals + 0x98));
      puVar2 = (undefined4 *)0x0;
    }
  }
  return puVar2;
}


