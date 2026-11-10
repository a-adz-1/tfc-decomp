// Check_Ceasefire__Fv  @ 000f8ab8
void Check_Ceasefire__Fv(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  fVar1 = *gpGlobals;
  if ((0x3f < (byte)((fVar1 < cb_ceasefire_time |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_ceasefire_time)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == cb_ceasefire_time) << 0xe) >> 8)) - 1)) &&
     (initial_cease_fire != 0)) {
    if (cease_fire == 0) goto LAB_000f8b18;
    initial_cease_fire = 0;
    cease_fire = 0;
  }
  if (cease_fire != 0) {
    last_cease_fire = cease_fire;
    return;
  }
LAB_000f8b18:
  if (no_cease_fire_text == 0) {
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
  }
  UTIL_LogPrintf__FPce("World triggered \"Resume_Fire\"\n");
  for (iVar3 = 1; iVar3 <= (int)gpGlobals[0x24]; iVar3 = iVar3 + 1) {
    piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(*piVar2 + 0x250) = 0;
      piVar2[99] = (int)(*gpGlobals + 10.0);
      *(byte *)((int)piVar2 + 0x86) = *(byte *)((int)piVar2 + 0x86) & 0xfe;
      TeamFortress_SetSpeed__11CBasePlayer(piVar2);
    }
  }
  last_cease_fire = cease_fire;
  return;
}


