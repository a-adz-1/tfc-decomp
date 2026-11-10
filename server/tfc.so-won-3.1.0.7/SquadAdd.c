// SquadAdd__13CSquadMonsterP13CSquadMonster  @ 000f25fc
undefined4 SquadAdd__13CSquadMonsterP13CSquadMonster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 0x694;
  iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
  if (iVar1 != 0) {
    iVar2 = param_1 + 0x69c;
    iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
    if (iVar1 != 0) {
      iVar2 = param_1 + 0x6a4;
      iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
      if (iVar1 != 0) {
        iVar2 = param_1 + 0x6ac;
        iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
        if (iVar1 != 0) {
          return 0;
        }
      }
    }
  }
  __as__7EHANDLEP11CBaseEntity(iVar2,param_2);
  __as__7EHANDLEP11CBaseEntity(param_2 + 0x68c,param_1);
  return 1;
}


