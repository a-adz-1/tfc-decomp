// CheckAutoKick__11CBasePlayer  @ 000eb164
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckAutoKick__11CBasePlayer(int *param_1)

{
  float fVar1;
  bool bVar2;
  undefined4 uVar3;
  int *piVar4;
  
  fVar1 = (float)param_1[0x7e];
  if ((byte)(fVar1 < autokick_kills |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(autokick_kills)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == autokick_kills) << 0xe) >> 8)) == 1) {
    if ((byte)(0.0 < autokick_kills | (byte)((ushort)((ushort)NAN(autokick_kills) << 10) >> 8) |
              (byte)((ushort)((ushort)(autokick_kills == 0.0) << 0xe) >> 8)) != 0x40) {
      if ((byte)((byte)((ushort)((ushort)(NAN(autokick_kills - _FUN_0013d928) ||
                                         NAN((float)param_1[0x7e])) << 10) >> 8) |
                (byte)((ushort)((ushort)(autokick_kills - _FUN_0013d928 == (float)param_1[0x7e]) <<
                               0xe) >> 8)) == 0x40) {
        ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#AKick_warn",0,0,0,0);
        ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#AKick_warn",0,0,0,0);
      }
      bVar2 = false;
      piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"ak_timer");
      if (piVar4 != (int *)0x0) {
        do {
          if (*(int *)(*piVar4 + 0x198) == *(int *)(*param_1 + 0x208)) {
            bVar2 = true;
          }
          piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"ak_timer");
        } while ((piVar4 != (int *)0x0) && (!bVar2));
      }
      if (!bVar2) {
        piVar4 = (int *)CreateTimer__11CBaseEntityi(param_1,0);
        *(int *)*piVar4 = (int)"ak_timer" - (int)gpGlobals[0x26];
        piVar4[3] = -0x10000;
        piVar4[4] = (int)Timer_AutokickThink__11CBaseEntity;
        *(float *)(*piVar4 + 0x104) = *gpGlobals + (float)tfc_autokick_time._12_4_;
      }
    }
  }
  else if ((byte)(0.0 < autokick_kills | (byte)((ushort)((ushort)NAN(autokick_kills) << 10) >> 8) |
                 (byte)((ushort)((ushort)(autokick_kills == 0.0) << 0xe) >> 8)) != 0x40) {
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#AKick_kicked",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],0,0,0);
    uVar3 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208));
    UTIL_LogPrintf__FPce
              ("\"%s<%i>\" was KICKED for KILLING TEAMMATES.\n",
               *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
    BanPlayer__FP11CBaseEntity(param_1);
  }
  return;
}


