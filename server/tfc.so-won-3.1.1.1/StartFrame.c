// StartFrame__Fv  @ 00091994
void StartFrame__Fv(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  
  if (g_pGameRules != (int *)0x0) {
    (**(code **)(*g_pGameRules + 0xc))(g_pGameRules);
  }
  if (g_fGameOver == 0) {
    gpGlobals[7] = (float)teamplay._12_4_;
    if ((int)gpGlobals[0x24] < 8) {
      lVar4 = (longdouble)(*DAT_0019f784)("deathmatch");
      gpGlobals[5] = (float)lVar4;
    }
    else {
      gpGlobals[5] = 1.0;
    }
    if ((((byte)((byte)((ushort)((ushort)NAN((float)tfc_balance_teams._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)tfc_balance_teams._12_4_ == 0.0) << 0xe) >> 8)) !=
          0x40) ||
        ((byte)((float)tfc_balance_scores._12_4_ < 0.0 |
                (byte)((ushort)((ushort)NAN((float)tfc_balance_scores._12_4_) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)tfc_balance_scores._12_4_ == 0.0) << 0xe) >> 8)) !=
         0x40)) &&
       (fVar1 = *gpGlobals,
       0x3f < (byte)((fVar1 < flNextEqualisationCalc |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(flNextEqualisationCalc)) << 10) >>
                            8) |
                     (byte)((ushort)((ushort)(fVar1 == flNextEqualisationCalc) << 0xe) >> 8)) - 1)))
    {
      CalculateTeamEqualiser__Fv();
      flNextEqualisationCalc = *gpGlobals + 10.0;
    }
    if ((byte)(cb_prematch_time < 0.0 | (byte)((ushort)((ushort)NAN(cb_prematch_time) << 10) >> 8) |
              (byte)((ushort)((ushort)(cb_prematch_time == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = (float)tfc_clanbattle_prematch._12_4_ * 60.0;
      if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        fVar1 = (float)tfc_prematch._12_4_ * 60.0;
      }
      fVar2 = ROUND(fVar1);
      fVar3 = ROUND(fOldPrematch);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 0x40) {
        cb_prematch_time = *gpGlobals + fVar1;
        g_fNextPrematchAlert = 0;
        fOldPrematch = fVar1;
      }
      Display_Prematch__Fv();
    }
    if (initial_cease_fire != 0) {
      fVar1 = (float)tfc_clanbattle_ceasefire._12_4_ * 60.0;
      fVar2 = ROUND(fVar1);
      fVar3 = ROUND(fOldCeaseFire);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 0x40) {
        cb_ceasefire_time = *gpGlobals + fVar1;
        fOldCeaseFire = fVar1;
      }
    }
    if (last_cease_fire != 0) {
      Check_Ceasefire__Fv();
    }
    g_iSkillLevel = 1;
    g_ulFrameCount = g_ulFrameCount + 1;
  }
  return;
}


