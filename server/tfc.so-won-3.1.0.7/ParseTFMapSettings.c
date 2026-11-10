// ParseTFMapSettings__Fv  @ 0010e684
void ParseTFMapSettings__Fv(void)

{
  int iVar1;
  
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
        (*DAT_001c110c)("mp_teamplay",0x3f800000);
        *(undefined4 *)(gpGlobals + 0x1c) = 0x3f800000;
      }
      number_of_teams = 2.0;
    }
    teamlives._4_4_ = 0xffffffff;
    DAT_001cdbc4 = 0;
    teammaxplayers._4_4_ = 100;
    g_pLastSpawns._4_4_ = 0;
    teamlives._8_4_ = 0xffffffff;
    DAT_001cdbc8 = 0;
    teammaxplayers._8_4_ = 100;
    g_pLastSpawns._8_4_ = 0;
    teamlives._12_4_ = 0xffffffff;
    DAT_001cdbcc = 0;
    teammaxplayers._12_4_ = 100;
    g_pLastSpawns._12_4_ = 0;
    teamlives._16_4_ = 0xffffffff;
    DAT_001cdbd0 = 0;
    teammaxplayers._16_4_ = 100;
    g_pLastSpawns._16_4_ = 0;
    civilianteams = 0;
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN((float)teamplay._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)teamplay._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_001c110c)("mp_teamplay",0x3f800000);
      *(undefined4 *)(gpGlobals + 0x1c) = 0x3f800000;
    }
    ParseTFDetect__FP11CBaseEntity(iVar1);
    if ((number_of_teams <= 0.0) || (5.0 <= number_of_teams)) {
      number_of_teams = 4.0;
    }
  }
  DAT_001cddec = 0;
  teamscores._4_4_ = 0;
  DAT_001cddf0 = 0;
  teamscores._8_4_ = 0;
  DAT_001cddf4 = 0;
  teamscores._12_4_ = 0;
  DAT_001cddf8 = 0;
  teamscores._16_4_ = 0;
  autokick_kills = 0;
  cease_fire = 0;
  g_fNextPrematchAlert = 0;
  return;
}


