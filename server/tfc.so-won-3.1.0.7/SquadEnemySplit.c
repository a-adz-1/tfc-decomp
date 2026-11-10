// SquadEnemySplit__13CSquadMonster  @ 000f3284
undefined4 SquadEnemySplit__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
  if (iVar1 != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
    local_4 = param_1;
    if (iVar1 != 0) {
      local_4 = iVar1;
    }
    iVar1 = __opP11CBaseEntity__7EHANDLE(local_4 + 0x4ec);
    iVar2 = __opP11CBaseEntity__7EHANDLE(local_4 + 0x694);
    if (iVar2 != 0) {
      iVar3 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x4ec);
      if ((iVar3 != 0) && (iVar2 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x4ec), iVar2 != iVar1)) {
        return 1;
      }
    }
    iVar3 = local_4 + 0x69c;
    iVar2 = 1;
    do {
      iVar5 = local_4;
      if (iVar2 < 4) {
        iVar5 = __opP11CBaseEntity__7EHANDLE(iVar3);
      }
      if (iVar5 != 0) {
        iVar4 = __opP11CBaseEntity__7EHANDLE(iVar5 + 0x4ec);
        if ((iVar4 != 0) && (iVar5 = __opP11CBaseEntity__7EHANDLE(iVar5 + 0x4ec), iVar5 != iVar1)) {
          return 1;
        }
      }
      iVar5 = local_4;
      if (iVar2 + 1 < 4) {
        iVar5 = __opP11CBaseEntity__7EHANDLE(iVar3 + 8);
      }
      if (iVar5 != 0) {
        iVar4 = __opP11CBaseEntity__7EHANDLE(iVar5 + 0x4ec);
        if ((iVar4 != 0) && (iVar5 = __opP11CBaseEntity__7EHANDLE(iVar5 + 0x4ec), iVar5 != iVar1)) {
          return 1;
        }
      }
      iVar3 = iVar3 + 0x10;
      iVar2 = iVar2 + 2;
    } while (iVar2 < 5);
  }
  return 0;
}


