// SquadPasteEnemyInfo__13CSquadMonster  @ 000ef5b0
void SquadPasteEnemyInfo__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
  iVar2 = param_1;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x5b8) = *(undefined4 *)(param_1 + 0x5b8);
    *(undefined4 *)(iVar2 + 0x5bc) = *(undefined4 *)(param_1 + 0x5bc);
    *(undefined4 *)(iVar2 + 0x5c0) = *(undefined4 *)(param_1 + 0x5c0);
  }
  return;
}


