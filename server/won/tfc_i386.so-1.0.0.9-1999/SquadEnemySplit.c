// SquadEnemySplit__13CSquadMonster  @ 000effd0
undefined4 SquadEnemySplit__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
  if (iVar1 != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
    if (iVar1 != 0) {
      param_1 = iVar1;
    }
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
    iVar4 = 0;
    do {
      iVar3 = param_1;
      if (iVar4 < 4) {
        iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x618 + iVar4 * 8);
      }
      if (iVar3 != 0) {
        iVar2 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x470);
        if ((iVar2 != 0) && (iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x470), iVar3 != iVar1)) {
          return 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
  }
  return 0;
}


