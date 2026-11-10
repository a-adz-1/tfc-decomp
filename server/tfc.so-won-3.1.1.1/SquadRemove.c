// SquadRemove__13CSquadMonsterP13CSquadMonster  @ 000f459c
void SquadRemove__13CSquadMonsterP13CSquadMonster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_8;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
  iVar3 = param_1;
  if (iVar1 != 0) {
    iVar3 = iVar1;
  }
  if (param_2 == iVar3) {
    iVar3 = 0;
    do {
      iVar1 = param_1 + 0x6a4 + iVar3 * 8;
      iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1);
      if (iVar2 != 0) {
        __as__7EHANDLEP11CBaseEntity(iVar2 + 0x69c,0);
        __as__7EHANDLEP11CBaseEntity(iVar1,0);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
  }
  else {
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
    uStack_8 = param_1;
    if (iVar3 != 0) {
      uStack_8 = iVar3;
    }
    if (uStack_8 != 0) {
      iVar3 = 0;
      do {
        iVar1 = uStack_8 + 0x6a4 + iVar3 * 8;
        iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1);
        if (iVar2 == param_1) {
          __as__7EHANDLEP11CBaseEntity(iVar1,0);
          break;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
    }
  }
  __as__7EHANDLEP11CBaseEntity(param_2 + 0x69c,0);
  return;
}


