// SquadCount__13CSquadMonster  @ 000ef770
int SquadCount__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
    if (iVar1 != 0) {
      param_1 = iVar1;
    }
    iVar1 = 0;
    iVar3 = 0;
    do {
      iVar2 = param_1;
      if (iVar3 < 4) {
        iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x618 + iVar3 * 8);
      }
      if (iVar2 != 0) {
        iVar1 = iVar1 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
  }
  return iVar1;
}


