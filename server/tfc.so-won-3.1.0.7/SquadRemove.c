// SquadRemove__13CSquadMonsterP13CSquadMonster  @ 000f2470
void SquadRemove__13CSquadMonsterP13CSquadMonster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
  iVar2 = param_1;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (param_2 == iVar2) {
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x694);
    if (iVar2 != 0) {
      __as__7EHANDLEP11CBaseEntity(iVar2 + 0x68c,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x694,0);
    }
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
    if (iVar2 != 0) {
      __as__7EHANDLEP11CBaseEntity(iVar2 + 0x68c,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x69c,0);
    }
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x6a4);
    if (iVar2 != 0) {
      __as__7EHANDLEP11CBaseEntity(iVar2 + 0x68c,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x6a4,0);
    }
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x6ac);
    if (iVar2 != 0) {
      __as__7EHANDLEP11CBaseEntity(iVar2 + 0x68c,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x6ac,0);
    }
  }
  else {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
    iVar2 = param_1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    if (iVar2 != 0) {
      iVar1 = iVar2 + 0x694;
      iVar3 = __opP11CBaseEntity__7EHANDLE(iVar1);
      if (iVar3 != param_1) {
        iVar1 = iVar2 + 0x69c;
        iVar3 = __opP11CBaseEntity__7EHANDLE(iVar1);
        if (iVar3 != param_1) {
          iVar1 = iVar2 + 0x6a4;
          iVar3 = __opP11CBaseEntity__7EHANDLE(iVar1);
          if (iVar3 != param_1) {
            iVar1 = iVar2 + 0x6ac;
            iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1);
            if (iVar2 != param_1) goto LAB_000f25e0;
          }
        }
      }
      __as__7EHANDLEP11CBaseEntity(iVar1,0);
    }
  }
LAB_000f25e0:
  __as__7EHANDLEP11CBaseEntity(param_2 + 0x68c,0);
  return;
}


