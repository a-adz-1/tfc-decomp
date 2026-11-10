// Check_Ceasefire__Fv  @ 000fae50
void Check_Ceasefire__Fv(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  if ((cb_ceasefire_time < *gpGlobals) && (initial_cease_fire != 0)) {
    if (cease_fire == 0) goto LAB_000faeab;
    initial_cease_fire = 0;
    cease_fire = 0;
  }
  if (cease_fire != 0) {
    last_cease_fire = cease_fire;
    return;
  }
LAB_000faeab:
  if (no_cease_fire_text == 0) {
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
  }
  UTIL_LogPrintf__FPce("World triggered \"Resume_Fire\"\n");
  iVar3 = 1;
  if (0 < (int)gpGlobals[0x24]) {
    do {
      piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
      if (piVar2 != (int *)0x0) {
        *(undefined4 *)(*piVar2 + 0x250) = 0;
        fVar1 = *gpGlobals;
        *(byte *)((int)piVar2 + 0x86) = *(byte *)((int)piVar2 + 0x86) & 0xfe;
        piVar2[99] = (int)(fVar1 + 10.0);
        TeamFortress_SetSpeed__11CBasePlayer(piVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= (int)gpGlobals[0x24]);
  }
  last_cease_fire = cease_fire;
  return;
}


