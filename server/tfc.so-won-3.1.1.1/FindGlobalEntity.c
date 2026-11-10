// FindGlobalEntity__Fii  @ 0008d924
undefined4 * FindGlobalEntity__Fii(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (*DAT_0019f6d8)(0,"globalname",param_2 + *(int *)(gpGlobals + 0x98));
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto LAB_0008d986;
    }
  }
  puVar2 = *(undefined4 **)(iVar1 + 0x7c);
LAB_0008d986:
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*puVar2),
                   (char *)(*(int *)(gpGlobals + 0x98) + param_1));
    if (iVar1 != 0) {
      (*DAT_0019f794)(1,"Global entity found %s, wrong class %s\n",
                      param_2 + *(int *)(gpGlobals + 0x98),
                      *(int *)*puVar2 + *(int *)(gpGlobals + 0x98));
      puVar2 = (undefined4 *)0x0;
    }
  }
  return puVar2;
}


