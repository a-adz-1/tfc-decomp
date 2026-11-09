// ClientDisconnected__14CHalfLifeRulesP7edict_s  @ 000b6fb0
void ClientDisconnected__14CHalfLifeRulesP7edict_s(void)

{
  return;
}


// ClientDisconnected__18CHalfLifeMultiplayP7edict_s  @ 000b78a0
void ClientDisconnected__18CHalfLifeMultiplayP7edict_s(undefined4 param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  if ((param_2 != 0) && (piVar1 = *(int **)(param_2 + 0xd8), piVar1 != (int *)0x0)) {
    piVar1[0x1f] = 1;
    uVar3 = (*DAT_00175684)(*(undefined4 *)(*piVar1 + 0x1e8));
    UTIL_LogPrintf__FPce
              ("\"%s<%i>\" disconnected\n",*(int *)(*piVar1 + 0x1b0) + gpGlobals[0x26],uVar3);
    TeamFortress_RemoveTimers__11CBasePlayer(piVar1);
    Engineer_RemoveBuildings__11CBasePlayer(piVar1);
    for (piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"detpack");
        piVar4 != (int *)0x0;
        piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"detpack")) {
      if (((byte)((byte)((ushort)((ushort)NAN((float)piVar4[0x43]) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)piVar4[0x43] == 1.0) << 0xe) >> 8)) == 0x40) &&
         (*(int *)(*piVar4 + 0x170) == *(int *)(*piVar1 + 0x1e8))) {
        piVar4[0x43] = 0;
      }
      if (*(int *)(*piVar4 + 0x178) == *(int *)(*piVar1 + 0x1e8)) {
        if ((byte)((byte)((ushort)((ushort)NAN((float)piVar4[0x43]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)piVar4[0x43] == 1.0) << 0xe) >> 8)) == 0x40) {
          iVar5 = *(int *)(*piVar4 + 0x170);
          bVar2 = false;
          if ((iVar5 == 0) || (iVar5 = (*DAT_001755d8)(iVar5), iVar5 == 0)) {
            bVar2 = true;
          }
          if (!bVar2) {
            iVar5 = *(int *)(*piVar4 + 0x170);
            if ((iVar5 == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
              iVar5 = 0;
            }
            else {
              iVar5 = *(int *)(iVar5 + 0xd8);
            }
            *(byte *)(iVar5 + 0x8a) = *(byte *)(iVar5 + 0x8a) & 0xfe;
            TeamFortress_SetSpeed__11CBasePlayer(iVar5);
            uVar3 = FindTimer__11CBaseEntityi(iVar5,10);
            UTIL_Remove__FP11CBaseEntity(uVar3);
          }
        }
        piVar4[3] = -0x10000;
        piVar4[4] = (int)SUB_Remove__11CBaseEntity;
        *(undefined4 *)(*piVar4 + 0xe4) = *gpGlobals;
      }
    }
    if (((byte)(0.0 < (float)tfc_clanbattle._12_4_ |
                (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
       && (piVar1[0x7d] != 0)) {
      CreateGhost__11CBasePlayer(piVar1);
    }
    piVar1[0xb] = 0;
    *(undefined4 *)(*piVar1 + 0x140) = 0;
    RemoveAllItems__11CBasePlayeri(piVar1,1);
    piVar4 = (int *)0x0;
    while (piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"player"),
          piVar4 != (int *)0x0) {
      bVar2 = false;
      if ((*(int *)(*piVar4 + 0x1e8) == 0) ||
         (iVar5 = (*DAT_001755d8)(*(int *)(*piVar4 + 0x1e8)), iVar5 == 0)) {
        bVar2 = true;
      }
      if (bVar2) {
        return;
      }
      if ((((*piVar4 != 0) && (piVar4 != piVar1)) && (piVar4[0xb] == 8)) &&
         (piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4 + 0x77), piVar6 == piVar1)) {
        TeamFortress_SpyCalcName__11CBasePlayer(piVar4);
      }
    }
  }
  return;
}


