// SquadPasteEnemyInfo__13CSquadMonster  @ 000e5a54
void SquadPasteEnemyInfo__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
  iVar2 = param_1;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x5c4) = *(undefined4 *)(param_1 + 0x5c4);
    *(undefined4 *)(iVar2 + 0x5c8) = *(undefined4 *)(param_1 + 0x5c8);
    *(undefined4 *)(iVar2 + 0x5cc) = *(undefined4 *)(param_1 + 0x5cc);
  }
  return;
}


