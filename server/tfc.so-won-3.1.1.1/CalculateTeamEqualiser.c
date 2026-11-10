// CalculateTeamEqualiser__Fv  @ 001137ac
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CalculateTeamEqualiser__Fv(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = 1;
  do {
    (&teamadvantage)[iVar7] = 0x3f800000;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 5);
  if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
            (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) == 0x40) {
    if ((byte)((float)tfc_balance_teams._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)tfc_balance_teams._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_balance_teams._12_4_ == 0.0) << 0xe) >> 8)) !=
        0x40) {
      iVar8 = 0;
      iVar7 = 1;
      if (0 < *(int *)(gpGlobals + 0x90)) {
        do {
          iVar6 = UTIL_PlayerByIndex__Fi(iVar7);
          if ((iVar6 != 0) && (*(int *)(iVar6 + 0x120) == 1)) {
            iVar8 = iVar8 + 1;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 <= *(int *)(gpGlobals + 0x90));
      }
      fVar1 = (float)iVar8;
      iVar7 = 0;
      if (0 < *(int *)(gpGlobals + 0x90)) {
        iVar8 = 1;
        do {
          iVar6 = UTIL_PlayerByIndex__Fi(iVar8);
          if ((iVar6 != 0) && (*(int *)(iVar6 + 0x120) == 2)) {
            iVar7 = iVar7 + 1;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 <= *(int *)(gpGlobals + 0x90));
      }
      fVar5 = (float)iVar7;
      iVar7 = 0;
      if (0 < *(int *)(gpGlobals + 0x90)) {
        iVar8 = 1;
        do {
          iVar6 = UTIL_PlayerByIndex__Fi(iVar8);
          if ((iVar6 != 0) && (*(int *)(iVar6 + 0x120) == 3)) {
            iVar7 = iVar7 + 1;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 <= *(int *)(gpGlobals + 0x90));
      }
      fVar4 = (float)iVar7;
      iVar8 = 0;
      iVar7 = 1;
      if (0 < *(int *)(gpGlobals + 0x90)) {
        do {
          iVar6 = UTIL_PlayerByIndex__Fi(iVar7);
          if ((iVar6 != 0) && (*(int *)(iVar6 + 0x120) == 4)) {
            iVar8 = iVar8 + 1;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 <= *(int *)(gpGlobals + 0x90));
      }
      fVar2 = (float)iVar8;
      fVar3 = fVar1 + fVar5 + fVar4 + fVar2;
      if (fVar3 < 1.0) {
        return;
      }
      fVar3 = fVar3 / number_of_teams;
      if (0.0 < fVar1) {
        fVar1 = fVar3 / fVar1 - 1.0;
        if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar1 = fVar1 * 0.33333334;
        }
        DAT_001ac4c8 = fVar1 + 1.0;
      }
      if ((0x3f < (byte)((fVar5 < 0.0 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) - 1)) &&
         (2.0 <= number_of_teams)) {
        _DAT_001ac4cc = fVar3 / fVar5 - 1.0;
        if ((byte)(0.0 < _DAT_001ac4cc | (byte)((ushort)((ushort)NAN(_DAT_001ac4cc) << 10) >> 8) |
                  (byte)((ushort)((ushort)(_DAT_001ac4cc == 0.0) << 0xe) >> 8)) != 0x40) {
          _DAT_001ac4cc = _DAT_001ac4cc * 0.33333334;
        }
        _DAT_001ac4cc = _DAT_001ac4cc + 1.0;
      }
      if ((0.0 < fVar4) && (3.0 <= number_of_teams)) {
        _DAT_001ac4d0 = fVar3 / fVar4 - 1.0;
        if ((byte)(_DAT_001ac4d0 < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_001ac4d0) << 10) >> 8) |
                  (byte)((ushort)((ushort)(_DAT_001ac4d0 == 0.0) << 0xe) >> 8)) != 0x40) {
          _DAT_001ac4d0 = _DAT_001ac4d0 * 0.33333334;
        }
        _DAT_001ac4d0 = _DAT_001ac4d0 + 1.0;
      }
      if ((0.0 < fVar2) && (4.0 <= number_of_teams)) {
        _DAT_001ac4d4 = fVar3 / fVar2 - 1.0;
        if ((byte)(_DAT_001ac4d4 < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_001ac4d4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(_DAT_001ac4d4 == 0.0) << 0xe) >> 8)) != 0x40) {
          _DAT_001ac4d4 = _DAT_001ac4d4 * 0.33333334;
        }
        _DAT_001ac4d4 = _DAT_001ac4d4 + 1.0;
      }
    }
    if ((byte)((float)tfc_balance_scores._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)tfc_balance_scores._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_balance_scores._12_4_ == 0.0) << 0xe) >> 8)) !=
        0x40) {
      fVar1 = (float)(teamscores._4_4_ + 0x3c);
      if (number_of_teams < 2.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = (float)(teamscores._8_4_ + 0x3c);
      }
      if (number_of_teams < 3.0) {
        fVar4 = 0.0;
      }
      else {
        fVar4 = (float)(teamscores._12_4_ + 0x3c);
      }
      if (number_of_teams < 4.0) {
        fVar3 = 0.0;
      }
      else {
        fVar3 = (float)(teamscores._16_4_ + 0x3c);
      }
      fVar2 = ((fVar5 + fVar4 + fVar3) / (number_of_teams - 1.0)) / fVar1 - 1.0;
      if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
        fVar2 = fVar2 * 0.33333334;
      }
      DAT_001ac4c8 = (fVar2 + 1.0) * DAT_001ac4c8;
      if ((byte)(number_of_teams < 2.0 | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) != 1) {
        fVar2 = ((fVar1 + fVar4 + fVar3) / (number_of_teams - 1.0)) / fVar5 - 1.0;
        if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar2 = fVar2 * 0.33333334;
        }
        _DAT_001ac4cc = (fVar2 + 1.0) * _DAT_001ac4cc;
      }
      if (3.0 <= number_of_teams) {
        fVar2 = ((fVar1 + fVar5 + fVar3) / (number_of_teams - 1.0)) / fVar4 - 1.0;
        if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar2 = fVar2 * 0.33333334;
        }
        _DAT_001ac4d0 = (fVar2 + 1.0) * _DAT_001ac4d0;
      }
      if (4.0 <= number_of_teams) {
        fVar1 = ((fVar5 + fVar4 + fVar1) / (number_of_teams - 1.0)) / fVar3 - 1.0;
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar1 = fVar1 * 0.33333334;
        }
        _DAT_001ac4d4 = (fVar1 + 1.0) * _DAT_001ac4d4;
      }
    }
  }
  return;
}


