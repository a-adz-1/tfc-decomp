// SquadCount__13CSquadMonster  @ 000f286c
char SquadCount__13CSquadMonster(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
  if (iVar1 == 0) {
    cVar2 = '\0';
  }
  else {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
    if (iVar1 != 0) {
      param_1 = iVar1;
    }
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x694);
    cVar2 = iVar1 != 0;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
    if (iVar1 != 0) {
      cVar2 = cVar2 + '\x01';
    }
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x6a4);
    if (iVar1 != 0) {
      cVar2 = cVar2 + '\x01';
    }
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x6ac);
    if (iVar1 != 0) {
      cVar2 = cVar2 + '\x01';
    }
    if (param_1 != 0) {
      cVar2 = cVar2 + '\x01';
    }
  }
  return cVar2;
}


