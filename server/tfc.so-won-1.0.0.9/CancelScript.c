// CancelScript__12CCineMonster  @ 000e7d50
void CancelScript__12CCineMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  (*DAT_001755b4)(2,"Cancelling script: %s\n",param_1[0x185] + *(int *)(gpGlobals + 0x98));
  if (*(int *)(*param_1 + 0x1ac) == 0) {
    ScriptEntityCancel__FP7edict_s(*(undefined4 *)(*param_1 + 0x1e8));
  }
  else {
    iVar2 = *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98);
    iVar3 = 0;
    while( true ) {
      iVar3 = (*DAT_001754f8)(iVar3,"targetname",iVar2);
      bVar1 = false;
      if ((iVar3 == 0) || (iVar2 = (*DAT_001755d8)(iVar3), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      ScriptEntityCancel__FP7edict_s(iVar3);
      iVar2 = *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98);
    }
  }
  return;
}


