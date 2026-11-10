// GetNextTarget__11CBaseEntity  @ 000a1400
undefined4 GetNextTarget__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(*param_1 + 0x1a8) != 0) {
    iVar2 = (*DAT_001754f8)(0,"targetname",*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if ((!bVar1) && ((iVar2 != 0 || (iVar2 = (*DAT_001755d4)(0), iVar2 != 0)))) {
      return *(undefined4 *)(iVar2 + 0xd8);
    }
  }
  return 0;
}


