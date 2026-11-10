// CalculateTeamEqualiser__Fv  @ 00110418
void CalculateTeamEqualiser__Fv(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float local_c;
  float local_8;
  
  teamadvantage._4_4_ = 0x3f800000;
  teamadvantage._8_4_ = 0x3f800000;
  teamadvantage._12_4_ = 0x3f800000;
  teamadvantage._16_4_ = 0x3f800000;
  if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
            (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) == 0x40) {
    if ((byte)(0.0 < (float)tfc_balance_teams._12_4_ |
               (byte)((ushort)((ushort)NAN((float)tfc_balance_teams._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_balance_teams._12_4_ == 0.0) << 0xe) >> 8)) !=
        0x40) {
      iVar7 = TeamFortress_TeamGetNoPlayers__Fi(1);
      fVar4 = (float)iVar7;
      iVar7 = TeamFortress_TeamGetNoPlayers__Fi(2);
      fVar3 = (float)iVar7;
      iVar7 = TeamFortress_TeamGetNoPlayers__Fi(3);
      fVar5 = (float)iVar7;
      iVar7 = TeamFortress_TeamGetNoPlayers__Fi(4);
      fVar6 = (float)iVar7;
      fVar2 = fVar4 + fVar3 + fVar5 + fVar6;
      if (fVar2 < 1.0) {
        return;
      }
      fVar2 = fVar2 / number_of_teams;
      if (0x3f < (byte)((fVar4 < 0.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) - 1)) {
        fVar4 = fVar2 / fVar4 - 1.0;
        if ((byte)(0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) == 0x40) {
          fVar1 = 1.0;
        }
        else {
          fVar1 = fVar4 * 0.33333334;
          fVar4 = 1.0;
        }
        teamadvantage._4_4_ = fVar1 + fVar4;
      }
      if ((0.0 < fVar3) && (2.0 <= number_of_teams)) {
        fVar4 = fVar2 / fVar3 - 1.0;
        if ((byte)(fVar4 < 0.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar4 = fVar4 * 0.33333334;
        }
        teamadvantage._8_4_ = fVar4 + 1.0;
      }
      if ((0.0 < fVar5) && (3.0 <= number_of_teams)) {
        fVar4 = fVar2 / fVar5 - 1.0;
        if ((byte)(fVar4 < 0.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar4 = fVar4 * 0.33333334;
        }
        teamadvantage._12_4_ = fVar4 + 1.0;
      }
      if ((0.0 < fVar6) && (4.0 <= number_of_teams)) {
        fVar4 = fVar2 / fVar6 - 1.0;
        if ((byte)(fVar4 < 0.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) == 0x40) {
          fVar3 = 1.0;
        }
        else {
          fVar3 = fVar4 * 0.33333334;
          fVar4 = 1.0;
        }
        teamadvantage._16_4_ = fVar3 + fVar4;
      }
    }
    if ((byte)(0.0 < (float)tfc_balance_scores._12_4_ |
               (byte)((ushort)((ushort)NAN((float)tfc_balance_scores._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_balance_scores._12_4_ == 0.0) << 0xe) >> 8)) !=
        0x40) {
      fVar4 = (float)(teamscores._4_4_ + 0x3c);
      if (number_of_teams < 2.0) {
        local_8 = 0.0;
      }
      else {
        local_8 = (float)(teamscores._8_4_ + 0x3c);
      }
      if (number_of_teams < 3.0) {
        local_c = 0.0;
      }
      else {
        local_c = (float)(teamscores._12_4_ + 0x3c);
      }
      if (number_of_teams < 4.0) {
        fVar3 = 0.0;
      }
      else {
        fVar3 = (float)(teamscores._16_4_ + 0x3c);
      }
      fVar5 = ((local_8 + local_c + fVar3) / (number_of_teams - 1.0)) / fVar4 - 1.0;
      if ((byte)(0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 0x40) {
        fVar2 = 1.0;
      }
      else {
        fVar2 = fVar5 * 0.33333334;
        fVar5 = 1.0;
      }
      teamadvantage._4_4_ = (fVar2 + fVar5) * (float)teamadvantage._4_4_;
      if (2.0 <= number_of_teams) {
        fVar5 = ((fVar4 + local_c + fVar3) / (number_of_teams - 1.0)) / local_8 - 1.0;
        if ((byte)(0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 0x40) {
          fVar2 = 1.0;
        }
        else {
          fVar2 = fVar5 * 0.33333334;
          fVar5 = 1.0;
        }
        teamadvantage._8_4_ = (fVar2 + fVar5) * (float)teamadvantage._8_4_;
      }
      if (3.0 <= number_of_teams) {
        fVar5 = ((local_8 + fVar4 + fVar3) / (number_of_teams - 1.0)) / local_c - 1.0;
        if ((byte)(0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 0x40) {
          fVar2 = 1.0;
        }
        else {
          fVar2 = fVar5 * 0.33333334;
          fVar5 = 1.0;
        }
        teamadvantage._12_4_ = (fVar2 + fVar5) * (float)teamadvantage._12_4_;
      }
      if (4.0 <= number_of_teams) {
        fVar4 = ((local_8 + local_c + fVar4) / (number_of_teams - 1.0)) / fVar3 - 1.0;
        if ((byte)(0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) == 0x40) {
          fVar3 = 1.0;
        }
        else {
          fVar3 = fVar4 * 0.33333334;
          fVar4 = 1.0;
        }
        teamadvantage._16_4_ = (fVar3 + fVar4) * (float)teamadvantage._16_4_;
      }
    }
  }
  return;
}


