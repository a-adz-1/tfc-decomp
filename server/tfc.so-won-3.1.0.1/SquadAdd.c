// SquadAdd__13CSquadMonsterP13CSquadMonster  @ 000e59c8
undefined4 SquadAdd__13CSquadMonsterP13CSquadMonster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 0x624;
  iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
  if (iVar1 != 0) {
    iVar2 = param_1 + 0x62c;
    iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
    if (iVar1 != 0) {
      iVar2 = param_1 + 0x634;
      iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
      if (iVar1 != 0) {
        iVar2 = param_1 + 0x63c;
        iVar1 = __opP11CBaseEntity__7EHANDLE(iVar2);
        if (iVar1 != 0) {
          return 0;
        }
      }
    }
  }
  __as__7EHANDLEP11CBaseEntity(iVar2,param_2);
  __as__7EHANDLEP11CBaseEntity(param_2 + 0x61c,param_1);
  return 1;
}


