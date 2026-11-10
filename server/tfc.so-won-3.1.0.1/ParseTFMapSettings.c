// ParseTFMapSettings__Fv  @ 000ffb38
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
        (*DAT_001a7f2c)("mp_teamplay",0x3f800000);
        *(undefined4 *)(gpGlobals + 0x1c) = 0x3f800000;
      }
      number_of_teams = 2.0;
    }
    teamlives._4_4_ = 0xffffffff;
    DAT_001b49e4 = 0;
    teammaxplayers._4_4_ = 100;
    DAT_001b4b04 = 0;
    teamlives._8_4_ = 0xffffffff;
    DAT_001b49e8 = 0;
    teammaxplayers._8_4_ = 100;
    DAT_001b4b08 = 0;
    teamlives._12_4_ = 0xffffffff;
    DAT_001b49ec = 0;
    teammaxplayers._12_4_ = 100;
    DAT_001b4b0c = 0;
    teamlives._16_4_ = 0xffffffff;
    DAT_001b49f0 = 0;
    teammaxplayers._16_4_ = 100;
    DAT_001b4b10 = 0;
    civilianteams = 0;
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN((float)teamplay._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)teamplay._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_001a7f2c)("mp_teamplay",0x3f800000);
      *(undefined4 *)(gpGlobals + 0x1c) = 0x3f800000;
    }
    ParseTFDetect__FP11CBaseEntity(iVar1);
    if ((number_of_teams <= 0.0) || (5.0 <= number_of_teams)) {
      number_of_teams = 4.0;
    }
  }
  DAT_001b4a38 = 0;
  teamscores._4_4_ = 0;
  DAT_001b4a3c = 0;
  teamscores._8_4_ = 0;
  DAT_001b4a40 = 0;
  teamscores._12_4_ = 0;
  DAT_001b4a44 = 0;
  teamscores._16_4_ = 0;
  autokick_kills = 0;
  cease_fire = 0;
  g_fNextPrematchAlert = 0;
  return;
}


