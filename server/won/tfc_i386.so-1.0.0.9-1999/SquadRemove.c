// SquadRemove__13CSquadMonsterP13CSquadMonster  @ 000ef480
void SquadRemove__13CSquadMonsterP13CSquadMonster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
  iVar4 = param_1;
  if (iVar1 != 0) {
    iVar4 = iVar1;
  }
  if (param_2 == iVar4) {
    iVar4 = 0;
    do {
      iVar1 = param_1 + 0x618 + iVar4 * 8;
      iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1);
      if (iVar2 != 0) {
        __as__7EHANDLEP11CBaseEntity(iVar2 + 0x610,0);
        __as__7EHANDLEP11CBaseEntity(iVar1,0);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
  }
  else {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
    iVar4 = param_1;
    if (iVar1 != 0) {
      iVar4 = iVar1;
    }
    if (iVar4 != 0) {
      iVar1 = 0;
      do {
        iVar2 = iVar4 + 0x618 + iVar1 * 8;
        iVar3 = __opP11CBaseEntity__7EHANDLE(iVar2);
        if (iVar3 == param_1) {
          __as__7EHANDLEP11CBaseEntity(iVar2,0);
          break;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 4);
    }
  }
  __as__7EHANDLEP11CBaseEntity(param_2 + 0x610,0);
  return;
}


