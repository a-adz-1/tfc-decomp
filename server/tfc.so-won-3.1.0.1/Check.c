// Check_Ceasefire__Fv  @ 000ebb50
void Check_Ceasefire__Fv(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  fVar1 = *gpGlobals;
  if ((0x3f < (byte)((fVar1 < cb_ceasefire_time |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_ceasefire_time)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == cb_ceasefire_time) << 0xe) >> 8)) - 1)) &&
     (initial_cease_fire != 0)) {
    if (cease_fire == 0) goto LAB_000ebbac;
    initial_cease_fire = 0;
    cease_fire = 0;
  }
  if (cease_fire != 0) {
    last_cease_fire = cease_fire;
    return;
  }
LAB_000ebbac:
  UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
  UTIL_LogPrintf__FPce("RESUME FIRE\n");
  for (iVar3 = 1; iVar3 <= (int)gpGlobals[0x24]; iVar3 = iVar3 + 1) {
    iVar2 = UTIL_PlayerByIndex__Fi(iVar3);
    if (iVar2 != 0) {
      *(float *)(iVar2 + 0x18c) = *gpGlobals + 10.0;
      *(byte *)(iVar2 + 0x86) = *(byte *)(iVar2 + 0x86) & 0xfe;
      TeamFortress_SetSpeed__11CBasePlayer(iVar2);
    }
  }
  last_cease_fire = cease_fire;
  return;
}


