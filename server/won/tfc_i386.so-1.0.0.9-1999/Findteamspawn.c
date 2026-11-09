// Findteamspawn__Fi  @ 00109ba0
int Findteamspawn__Fi(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1(iVar1,"netname","info_player_teamspawn");
    if (iVar1 == 0) {
      (*DAT_001755b4)(1,"Could not find a Teamspawn with a goal_no of %d.\n",param_1);
      return 0;
    }
  } while (*(int *)(iVar1 + 0x210) != param_1);
  return iVar1;
}


