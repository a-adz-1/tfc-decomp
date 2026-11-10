// SquadPasteEnemyInfo__13CSquadMonster  @ 000f2688
void SquadPasteEnemyInfo__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
  iVar2 = param_1;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x634) = *(undefined4 *)(param_1 + 0x634);
    *(undefined4 *)(iVar2 + 0x638) = *(undefined4 *)(param_1 + 0x638);
    *(undefined4 *)(iVar2 + 0x63c) = *(undefined4 *)(param_1 + 0x63c);
  }
  return;
}


