// ClientDisconnected__14CHalfLifeRulesP7edict_s  @ 000b0084
void ClientDisconnected__14CHalfLifeRulesP7edict_s(void)

{
  return;
}


// ClientDisconnected__18CHalfLifeMultiplayP7edict_s  @ 000ae008
void ClientDisconnected__18CHalfLifeMultiplayP7edict_s(undefined4 param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if ((param_2 != 0) && (piVar1 = *(int **)(param_2 + 0x7c), piVar1 != (int *)0x0)) {
    piVar1[0x1e] = 1;
    if (piVar1[0x48] == 0) {
      pcVar2 = "SPECTATOR";
    }
    else {
      pcVar2 = (char *)GetTeamName__Fi(piVar1[0x48]);
    }
    uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar1 + 0x208),pcVar2);
    uVar3 = (*DAT_0019f864)(*(undefined4 *)(*piVar1 + 0x208),uVar3);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%s><%s>\" disconnected\n",
               *(int *)(*piVar1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar3);
    CleanupOnPlayerDisconnection__11CBasePlayer(piVar1);
    if (((byte)((float)tfc_clanbattle._12_4_ < 0.0 |
                (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
       && (piVar1[0x7d] != 0)) {
      CreateGhost__11CBasePlayer(piVar1);
    }
    *(undefined4 *)(*piVar1 + 0x20c) = 0;
    *(undefined4 *)(*piVar1 + 0x160) = 0;
    RemoveAllItems__11CBasePlayeri(piVar1,0);
    (*DAT_0019f758)(2,gmsgSpectator,0,0);
    uVar3 = (*DAT_0019f7bc)(param_2);
    (*DAT_0019f760)(uVar3);
    (*DAT_0019f760)(0);
    (*DAT_0019f75c)();
  }
  return;
}


