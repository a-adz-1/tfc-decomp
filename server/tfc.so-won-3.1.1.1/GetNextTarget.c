// GetNextTarget__11CBaseEntity  @ 0008e204
undefined4 GetNextTarget__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar2 = (*DAT_0019f6d8)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if ((!bVar1) && ((iVar2 != 0 || (iVar2 = (*DAT_0019f7b4)(0), iVar2 != 0)))) {
      return *(undefined4 *)(iVar2 + 0x7c);
    }
  }
  return 0;
}


