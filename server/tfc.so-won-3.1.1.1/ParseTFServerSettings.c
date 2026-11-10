// ParseTFServerSettings__Fv  @ 00110fcc
void ParseTFServerSettings__Fv(void)

{
  tm *ptVar1;
  int *piVar2;
  time_t local_8;
  
  toggleflags._0_1_ = (byte)toggleflags & 0xfd;
  time(&local_8);
  ptVar1 = localtime(&local_8);
  if ((ptVar1->tm_mon == 0xb) && (ptVar1->tm_mday == 0x19)) {
    christmas = 1;
  }
  if (((byte)((byte)((ushort)((ushort)NAN((float)tfc_birthday._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)tfc_birthday._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) ||
     (((ptVar1->tm_mon == 7 && (ptVar1->tm_mday == 0x18)) || (christmas == 1)))) {
    birthday = 1;
    piVar2 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s("timer",&g_vecZero,&g_vecZero,0);
    piVar2[0x23] = 10;
    piVar2[3] = -0x10000;
    piVar2[4] = (int)Timer_Birthday__11CBaseEntity;
    *(float *)(*piVar2 + 0x104) = *gpGlobals + 60.0;
  }
  cb_prematch_time = (float)tfc_clanbattle_prematch._12_4_ * 60.0;
  if ((byte)((byte)((ushort)((ushort)NAN(cb_prematch_time) << 10) >> 8) |
            (byte)((ushort)((ushort)(cb_prematch_time == 0.0) << 0xe) >> 8)) == 0x40) {
    cb_prematch_time = (float)tfc_prematch._12_4_ * 60.0;
  }
  if ((byte)((float)tfc_clanbattle._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    clan_scores_dumped = 0;
    cb_ceasefire_time = (float)tfc_clanbattle_ceasefire._12_4_ * 60.0;
    if ((byte)(cb_ceasefire_time < 0.0 | (byte)((ushort)((ushort)NAN(cb_ceasefire_time) << 10) >> 8)
              | (byte)((ushort)((ushort)(cb_ceasefire_time == 0.0) << 0xe) >> 8)) != 0x40) {
      last_cease_fire = 1;
      initial_cease_fire = 1;
      cease_fire = 1;
    }
  }
  autokick_kills = tfc_autokick_kills._12_4_;
  if ((byte)((float)tfc_fragscoring._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)tfc_fragscoring._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)tfc_fragscoring._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
    toggleflags._1_1_ = toggleflags._1_1_ & 0xbf;
  }
  else {
    toggleflags._1_1_ = toggleflags._1_1_ | 0x40;
  }
  gpGlobals[7] = (float)teamplay._12_4_;
  return;
}


