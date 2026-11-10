// CheckEnemy__12CBaseMonsterP11CBaseEntity  @ 000b027c
void CheckEnemy__12CBaseMonsterP11CBaseEntity(void)

{
  FUN_000b0288();
  return;
}


// CheckEnemy__13CSquadMonsterP11CBaseEntity  @ 000e5fec
int CheckEnemy__13CSquadMonsterP11CBaseEntity(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
  iVar2 = CheckEnemy__12CBaseMonsterP11CBaseEntity(param_1,uVar1);
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
  if (iVar3 != 0) {
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
    iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
    iVar3 = param_1;
    if (iVar5 != 0) {
      iVar3 = iVar5;
    }
    iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x47c);
    if (iVar4 == iVar3) {
      if (iVar2 == 0) {
        SquadCopyEnemyInfo__13CSquadMonster(param_1);
      }
      else {
        SquadPasteEnemyInfo__13CSquadMonster(param_1);
      }
    }
  }
  return iVar2;
}


