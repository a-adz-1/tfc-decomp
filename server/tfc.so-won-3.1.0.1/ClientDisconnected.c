// ClientDisconnected__14CHalfLifeRulesP7edict_s  @ 000a38f0
void ClientDisconnected__14CHalfLifeRulesP7edict_s(void)

{
  return;
}


// ClientDisconnected__18CHalfLifeMultiplayP7edict_s  @ 000a4468
void ClientDisconnected__18CHalfLifeMultiplayP7edict_s(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((param_2 != 0) && (piVar1 = *(int **)(param_2 + 0x7c), piVar1 != (int *)0x0)) {
    piVar1[0x1e] = 1;
    uVar2 = (*DAT_001a8004)(*(undefined4 *)(*piVar1 + 0x208));
    UTIL_LogPrintf__FPce
              ("\"%s<%i>\" disconnected\n",*(int *)(*piVar1 + 0x1d0) + *(int *)(gpGlobals + 0x98),
               uVar2);
    CleanupOnPlayerDisconnection__11CBasePlayer(piVar1);
    if (((byte)(0.0 < (float)tfc_clanbattle._12_4_ |
                (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
       && (piVar1[0x7d] != 0)) {
      CreateGhost__11CBasePlayer(piVar1);
    }
    *(undefined4 *)(*piVar1 + 0x20c) = 0;
    *(undefined4 *)(*piVar1 + 0x160) = 0;
    RemoveAllItems__11CBasePlayeri(piVar1,0);
    (*DAT_001a7ef8)(2,gmsgSpectator,0,0);
    uVar2 = (*DAT_001a7f5c)(param_2);
    (*DAT_001a7f00)(uVar2);
    (*DAT_001a7f00)(0);
    (*DAT_001a7efc)();
  }
  return;
}


