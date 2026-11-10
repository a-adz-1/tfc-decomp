// ParseTFMapSettings__Fv  @ 001111a0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ParseTFMapSettings__Fv(void)

{
  int iVar1;
  int iVar2;
  
  flagem_checked = 0;
  iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_tfdetect");
  if (iVar1 == 0) {
    iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_player_team1");
    if ((iVar1 == 0) && (CTF_Map != 1)) {
      number_of_teams = 4.0;
    }
    else {
      CTF_Map = 1;
      if ((byte)((byte)((ushort)((ushort)NAN((float)teamplay._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)teamplay._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
        (*DAT_0019f78c)("mp_teamplay",0x3f800000);
        *(undefined4 *)(gpGlobals + 0x1c) = 0x3f800000;
      }
      number_of_teams = 2.0;
    }
    iVar1 = 1;
    do {
      *(undefined4 *)(teamlives + iVar1 * 4) = 0xffffffff;
      (&illegalclasses)[iVar1] = 0;
      *(undefined4 *)(teammaxplayers + iVar1 * 4) = 100;
      iVar2 = iVar1 + 1;
      (&g_pLastSpawns)[iVar1] = 0;
      iVar1 = iVar2;
    } while (iVar2 < 5);
    _civilianteams = 0;
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN((float)teamplay._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)teamplay._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_0019f78c)("mp_teamplay",0x3f800000);
      *(undefined4 *)(gpGlobals + 0x1c) = 0x3f800000;
    }
    ParseTFDetect__FP11CBaseEntity(iVar1);
    if (((byte)((number_of_teams < 0.0 | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                (byte)((ushort)((ushort)(number_of_teams == 0.0) << 0xe) >> 8)) - 1) < 0x40) ||
       (5.0 <= number_of_teams)) {
      number_of_teams = 4.0;
    }
  }
  iVar1 = 1;
  do {
    iVar2 = iVar1 * 4;
    (&teamfrags)[iVar1] = 0;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(teamscores + iVar2) = 0;
  } while (iVar1 < 5);
  autokick_kills = 0;
  cease_fire = 0;
  g_fNextPrematchAlert = 0;
  return;
}


