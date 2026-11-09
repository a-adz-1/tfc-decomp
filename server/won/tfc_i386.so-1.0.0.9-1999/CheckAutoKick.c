// CheckAutoKick__11CBasePlayer  @ 000f41e0
void CheckAutoKick__11CBasePlayer(int *param_1)

{
  bool bVar1;
  float *pfVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (((float)param_1[0x7e] < autokick_kills) ||
     ((byte)(0.0 < autokick_kills | (byte)((ushort)((ushort)NAN(autokick_kills) << 10) >> 8) |
            (byte)((ushort)((ushort)(autokick_kills == 0.0) << 0xe) >> 8)) == 0x40)) {
    if ((byte)(0.0 < autokick_kills | (byte)((ushort)((ushort)NAN(autokick_kills) << 10) >> 8) |
              (byte)((ushort)((ushort)(autokick_kills == 0.0) << 0xe) >> 8)) != 0x40) {
      if ((byte)((byte)((ushort)((ushort)(NAN(autokick_kills - 1.0) || NAN((float)param_1[0x7e])) <<
                                10) >> 8) |
                (byte)((ushort)((ushort)(autokick_kills - 1.0 == (float)param_1[0x7e]) << 0xe) >> 8)
                ) == 0x40) {
        ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#AKick_warn",0,0,0,0);
        ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#AKick_warn",0,0,0,0);
      }
      bVar1 = false;
      piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"ak_timer");
      if (piVar4 != (int *)0x0) {
        do {
          if (*(int *)(*piVar4 + 0x178) == *(int *)(*param_1 + 0x1e8)) {
            bVar1 = true;
          }
          piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"ak_timer");
        } while ((piVar4 != (int *)0x0) && (!bVar1));
      }
      if (!bVar1) {
        piVar4 = (int *)CreateTimer__11CBaseEntityi(param_1,0);
        pfVar2 = gpGlobals;
        *(int *)*piVar4 = (int)"ak_timer" - (int)gpGlobals[0x26];
        piVar4[3] = -0x10000;
        piVar4[4] = (int)Timer_AutokickThink__11CBaseEntity;
        *(float *)(*piVar4 + 0xe4) = *pfVar2 + (float)tfc_autokick_time._12_4_;
      }
    }
  }
  else {
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#AKick_kicked",*(int *)(*param_1 + 0x1b0) + (int)gpGlobals[0x26],0,0,0);
    uVar3 = (*DAT_00175684)(*(undefined4 *)(*param_1 + 0x1e8));
    UTIL_LogPrintf__FPce
              ("\"%s<%i>\" was KICKED for KILLING TEAMMATES.\n",
               *(int *)(*param_1 + 0x1b0) + (int)gpGlobals[0x26],uVar3);
    KickPlayer__FP11CBaseEntity(param_1);
  }
  return;
}


