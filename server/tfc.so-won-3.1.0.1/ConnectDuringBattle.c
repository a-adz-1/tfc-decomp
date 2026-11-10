// ConnectDuringBattle__11CBasePlayer  @ 000eb5e0
void ConnectDuringBattle__11CBasePlayer(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = GetBattleID__FP7edict_s(*(undefined4 *)(*param_1 + 0x208));
  if ((iVar1 != 0) && (piVar2 = (int *)FindGhost__Fi(iVar1), piVar2 != (int *)0x0)) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Game_welcomeback",0,0,0,0);
    param_1[0x7d] = iVar1;
    TeamFortress_TeamSet__11CBasePlayeri(param_1,piVar2[0x48]);
    *(undefined4 *)(*param_1 + 0x164) = *(undefined4 *)(*piVar2 + 0x164);
    param_1[0x4b] = piVar2[0x4b];
    *(float *)(*param_1 + 0x164) = (float)param_1[0x4b];
    *(undefined4 *)(*param_1 + 0x20c) = *(undefined4 *)(*piVar2 + 0x20c);
    param_1[0x21] = piVar2[0x21];
    ResetMenu__11CBasePlayer(param_1);
    UTIL_Remove__FP11CBaseEntity(piVar2);
    return;
  }
  CreateBattleID__11CBasePlayer(param_1);
  return;
}


