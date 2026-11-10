// SquadAdd__13CSquadMonsterP13CSquadMonster  @ 000f5468
undefined4 SquadAdd__13CSquadMonsterP13CSquadMonster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = param_1 + 0x6a4 + iVar3 * 8;
    iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1);
    if (iVar2 == 0) {
      __as__7EHANDLEP11CBaseEntity(iVar1,param_2);
      __as__7EHANDLEP11CBaseEntity(param_2 + 0x69c,param_1);
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return 0;
}


