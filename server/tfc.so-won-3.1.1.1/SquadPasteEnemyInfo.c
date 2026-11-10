// SquadPasteEnemyInfo__13CSquadMonster  @ 000f540c
void SquadPasteEnemyInfo__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
  iVar2 = param_1;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x644) = *(undefined4 *)(param_1 + 0x644);
    *(undefined4 *)(iVar2 + 0x648) = *(undefined4 *)(param_1 + 0x648);
    *(undefined4 *)(iVar2 + 0x64c) = *(undefined4 *)(param_1 + 0x64c);
  }
  return;
}


