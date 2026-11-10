// Check_Ceasefire__Fv  @ 000f4970
void Check_Ceasefire__Fv(void)

{
  int iVar1;
  int iVar2;
  
  if ((cb_ceasefire_time < *gpGlobals) && (initial_cease_fire != 0)) {
    if (cease_fire == 0) goto LAB_000f49b7;
    initial_cease_fire = 0;
    cease_fire = 0;
  }
  if (cease_fire != 0) {
    last_cease_fire = cease_fire;
    return;
  }
LAB_000f49b7:
  UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
  UTIL_LogPrintf__FPce("RESUME FIRE\n");
  for (iVar2 = 1; iVar2 <= (int)gpGlobals[0x24]; iVar2 = iVar2 + 1) {
    iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
    if (iVar1 != 0) {
      *(float *)(iVar1 + 0x18c) = *gpGlobals + 10.0;
      *(byte *)(iVar1 + 0x8a) = *(byte *)(iVar1 + 0x8a) & 0xfe;
      TeamFortress_SetSpeed__11CBasePlayer(iVar1);
    }
  }
  last_cease_fire = cease_fire;
  return;
}


