// CancelScript__12CCineMonster  @ 000e8da4
void CancelScript__12CCineMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  (*DAT_001c1114)(2,"Cancelling script: %s\n",param_1[0x1a4] + *(int *)(gpGlobals + 0x98));
  if (*(int *)(*param_1 + 0x1cc) != 0) {
    iVar2 = *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98);
    iVar3 = 0;
    while( true ) {
      iVar3 = (*DAT_001c1058)(iVar3,"targetname",iVar2);
      bVar1 = false;
      if ((iVar3 == 0) || (iVar2 = (*DAT_001c1138)(iVar3), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      ScriptEntityCancel__FP7edict_s(iVar3);
      iVar2 = *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98);
    }
    return;
  }
  ScriptEntityCancel__FP7edict_s(*(undefined4 *)(*param_1 + 0x208));
  FUN_000e8e94();
  return;
}


