// SquadRemove__13CSquadMonsterP13CSquadMonster  @ 000e583c
void SquadRemove__13CSquadMonsterP13CSquadMonster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
  iVar2 = param_1;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (param_2 == iVar2) {
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x624);
    if (iVar2 != 0) {
      __as__7EHANDLEP11CBaseEntity(iVar2 + 0x61c,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x624,0);
    }
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x62c);
    if (iVar2 != 0) {
      __as__7EHANDLEP11CBaseEntity(iVar2 + 0x61c,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x62c,0);
    }
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x634);
    if (iVar2 != 0) {
      __as__7EHANDLEP11CBaseEntity(iVar2 + 0x61c,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x634,0);
    }
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x63c);
    if (iVar2 != 0) {
      __as__7EHANDLEP11CBaseEntity(iVar2 + 0x61c,0);
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x63c,0);
    }
  }
  else {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
    iVar2 = param_1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    if (iVar2 != 0) {
      iVar1 = iVar2 + 0x624;
      iVar3 = __opP11CBaseEntity__7EHANDLE(iVar1);
      if (iVar3 != param_1) {
        iVar1 = iVar2 + 0x62c;
        iVar3 = __opP11CBaseEntity__7EHANDLE(iVar1);
        if (iVar3 != param_1) {
          iVar1 = iVar2 + 0x634;
          iVar3 = __opP11CBaseEntity__7EHANDLE(iVar1);
          if (iVar3 != param_1) {
            iVar1 = iVar2 + 0x63c;
            iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1);
            if (iVar2 != param_1) goto LAB_000e59ac;
          }
        }
      }
      __as__7EHANDLEP11CBaseEntity(iVar1,0);
    }
  }
LAB_000e59ac:
  __as__7EHANDLEP11CBaseEntity(param_2 + 0x61c,0);
  return;
}


