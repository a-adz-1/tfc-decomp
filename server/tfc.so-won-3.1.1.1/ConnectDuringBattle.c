// ConnectDuringBattle__11CBasePlayer  @ 000fa8ec
void ConnectDuringBattle__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *__s;
  int *piVar3;
  int local_8;
  
  local_8 = 0;
  uVar2 = (*DAT_0019f848)(*(undefined4 *)(*param_1 + 0x208));
  __s = (char *)(*DAT_0019f84c)(uVar2,"tf_id");
  if ((__s != (char *)0x0) && (*__s != '\0')) {
    sscanf(__s,"%d",&local_8);
  }
  iVar1 = local_8;
  if (local_8 != 0) {
    piVar3 = (int *)0x0;
    do {
      piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"ghost");
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
        break;
      }
    } while (piVar3[0x7d] != iVar1);
    if (piVar3 != (int *)0x0) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Game_welcomeback",0,0,0,0);
      param_1[0x7d] = iVar1;
      TeamFortress_TeamSet__11CBasePlayeri(param_1,piVar3[0x48]);
      *(undefined4 *)(*param_1 + 0x164) = *(undefined4 *)(*piVar3 + 0x164);
      iVar1 = piVar3[0x4b];
      param_1[0x4b] = iVar1;
      *(float *)(*param_1 + 0x164) = (float)iVar1;
      *(undefined4 *)(*param_1 + 0x20c) = *(undefined4 *)(*piVar3 + 0x20c);
      param_1[0x21] = piVar3[0x21];
      ResetMenu__11CBasePlayer(param_1);
      UTIL_Remove__FP11CBaseEntity(piVar3);
      return;
    }
  }
  CreateBattleID__11CBasePlayer(param_1);
  return;
}


