// ParseTFMapSettings__Fv  @ 0010da20
void ParseTFMapSettings__Fv(void)

{
  int iVar1;
  int iVar2;
  
  flagem_checked = 0;
  iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_tfdetect");
  if (iVar2 == 0) {
    iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_player_team1");
    if ((iVar2 == 0) && (CTF_Map != 1)) {
      number_of_teams = 4.0;
    }
    else {
      CTF_Map = 1;
      if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x1c)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x1c) == 0.0) << 0xe) >> 8)) == 0x40
         ) {
        (*DAT_001755ac)("mp_teamplay",0x3f800000);
        *(undefined4 *)(gpGlobals + 0x1c) = 0x3f800000;
      }
      number_of_teams = 2.0;
    }
    iVar2 = 1;
    do {
      iVar1 = iVar2 * 4;
      *(undefined4 *)(teamlives + iVar1) = 0xffffffff;
      *(undefined4 *)(&illegalclasses + iVar1) = 0;
      *(undefined4 *)(teammaxplayers + iVar1) = 100;
      (&g_pLastSpawns)[iVar2] = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    civilianteams = 0;
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x1c)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x1c) == 0.0) << 0xe) >> 8)) == 0x40)
    {
      (*DAT_001755ac)("mp_teamplay",0x3f800000);
      *(undefined4 *)(gpGlobals + 0x1c) = 0x3f800000;
    }
    ParseTFDetect__FP11CBaseEntity(iVar2);
    if ((number_of_teams <= 0.0) ||
       ((byte)((5.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
               (byte)((ushort)((ushort)(number_of_teams == 5.0) << 0xe) >> 8)) - 1) < 0x40)) {
      number_of_teams = 4.0;
    }
  }
  iVar2 = 1;
  do {
    (&teamfrags)[iVar2] = 0;
    *(undefined4 *)(teamscores + iVar2 * 4) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  autokick_kills = 0;
  cease_fire = 0;
  return;
}


