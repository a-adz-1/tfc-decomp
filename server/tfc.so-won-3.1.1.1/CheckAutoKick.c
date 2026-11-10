// CheckAutoKick__11CBasePlayer  @ 000fa354
void CheckAutoKick__11CBasePlayer(int *param_1)

{
  float fVar1;
  bool bVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  
  fVar1 = (float)param_1[0x7e];
  if (fVar1 < autokick_kills) {
    if ((byte)(0.0 < autokick_kills | (byte)((ushort)((ushort)NAN(autokick_kills) << 10) >> 8) |
              (byte)((ushort)((ushort)(autokick_kills == 0.0) << 0xe) >> 8)) != 0x40) {
      if ((byte)((byte)((ushort)((ushort)(NAN(autokick_kills - 1.0) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(autokick_kills - 1.0 == fVar1) << 0xe) >> 8)) == 0x40) {
        ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#AKick_warn",0,0,0,0);
        ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#AKick_warn",0,0,0,0);
      }
      bVar2 = false;
      piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"ak_timer");
      if (piVar5 != (int *)0x0) {
        bVar2 = false;
        do {
          if (*(int *)(*piVar5 + 0x198) == *(int *)(*param_1 + 0x208)) {
            bVar2 = true;
          }
          piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"ak_timer");
        } while ((piVar5 != (int *)0x0) && (!bVar2));
      }
      if (!bVar2) {
        piVar5 = (int *)CreateTimer__11CBaseEntityi(param_1,0);
        *(int *)*piVar5 = (int)"ak_timer" - (int)gpGlobals[0x26];
        piVar5[3] = -0x10000;
        piVar5[4] = (int)Timer_AutokickThink__11CBaseEntity;
        *(float *)(*piVar5 + 0x104) = *gpGlobals + (float)tfc_autokick_time._12_4_;
      }
    }
  }
  else if ((byte)(0.0 < autokick_kills | (byte)((ushort)((ushort)NAN(autokick_kills) << 10) >> 8) |
                 (byte)((ushort)((ushort)(autokick_kills == 0.0) << 0xe) >> 8)) != 0x40) {
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#AKick_kicked",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],0,0,0);
    if (param_1[0x48] == 0) {
      pcVar3 = "SPECTATOR";
    }
    else {
      pcVar3 = (char *)GetTeamName__Fi(param_1[0x48]);
    }
    uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
    uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar4);
    UTIL_LogPrintf__FPce
              ("\"<-1><><>\" triggered \"Auto_Kick_For_TK\" against \"%s<%i><%s><%s>\"\n",
               *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
    BanPlayer__FP11CBaseEntity(param_1);
  }
  return;
}


