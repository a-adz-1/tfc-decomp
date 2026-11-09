// ConnectDuringBattle__11CBasePlayer  @ 000f4530
void ConnectDuringBattle__11CBasePlayer(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = GetBattleID__FP7edict_s(*(undefined4 *)(*param_1 + 0x1e8));
  if ((iVar1 != 0) && (piVar2 = (int *)FindGhost__Fi(iVar1), piVar2 != (int *)0x0)) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Game_welcomeback",0,0,0,0);
    param_1[0x7d] = iVar1;
    TeamFortress_TeamSet__11CBasePlayeri(param_1,piVar2[0x48]);
    *(undefined4 *)(*param_1 + 0x144) = *(undefined4 *)(*piVar2 + 0x144);
    param_1[0x4b] = piVar2[0x4b];
    *(float *)(*param_1 + 0x144) = (float)param_1[0x4b];
    param_1[0xb] = piVar2[0xb];
    param_1[0x22] = piVar2[0x22];
    ResetMenu__11CBasePlayer(param_1);
    UTIL_Remove__FP11CBaseEntity(piVar2);
    return;
  }
  CreateBattleID__11CBasePlayer(param_1);
  return;
}


