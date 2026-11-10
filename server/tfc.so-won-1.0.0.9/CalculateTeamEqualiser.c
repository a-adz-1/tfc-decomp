// CalculateTeamEqualiser__Fv  @ 0010eb60
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CalculateTeamEqualiser__Fv(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 auStack_14 [4];
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar5 = 1;
  do {
    (&teamadvantage)[iVar5] = 0x3f800000;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  if (2.0 <= number_of_teams) {
    puVar6 = (undefined4 *)auStack_14;
    if ((byte)(0.0 < (float)tfc_balance_teams._12_4_ |
               (byte)((ushort)((ushort)NAN((float)tfc_balance_teams._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_balance_teams._12_4_ == 0.0) << 0xe) >> 8)) !=
        0x40) {
      uStack_18 = 1;
      uStack_1c = 0x10ebb7;
      iVar5 = TeamFortress_TeamGetNoPlayers__Fi();
      fStack_8 = (float)iVar5;
      uStack_1c = 2;
      uStack_20 = 0x10ebca;
      iVar5 = TeamFortress_TeamGetNoPlayers__Fi();
      fStack_c = (float)iVar5;
      uStack_20 = 3;
      uStack_24 = 0x10ebdd;
      iVar5 = TeamFortress_TeamGetNoPlayers__Fi();
      fStack_10 = (float)iVar5;
      uStack_24 = 4;
      iVar5 = TeamFortress_TeamGetNoPlayers__Fi();
      fVar4 = (float)iVar5;
      fVar1 = fStack_8 + fStack_c + fStack_10 + fVar4;
      if (fVar1 < 1.0) {
        return;
      }
      fVar1 = fVar1 / number_of_teams;
      if (0.0 < fStack_8) {
        fVar2 = fVar1 / fStack_8 - 1.0;
        if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
          fVar3 = 1.0;
        }
        else {
          fVar3 = fVar2 / 3.0;
          fVar2 = 1.0;
        }
        DAT_00182094 = fVar3 + fVar2;
      }
      if (((byte)(0.0 < fStack_c | (byte)((ushort)((ushort)NAN(fStack_c) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_c == 0.0) << 0xe) >> 8)) == 1) &&
         ((byte)((2.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8)
                 | (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) - 1) < 0x40)) {
        _DAT_00182098 = fVar1 / fStack_c - 1.0;
        if ((byte)(_DAT_00182098 < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_00182098) << 10) >> 8) |
                  (byte)((ushort)((ushort)(_DAT_00182098 == 0.0) << 0xe) >> 8)) != 0x40) {
          _DAT_00182098 = _DAT_00182098 / 3.0;
        }
        _DAT_00182098 = _DAT_00182098 + 1.0;
      }
      if (((byte)(0.0 < fStack_10 | (byte)((ushort)((ushort)NAN(fStack_10) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_10 == 0.0) << 0xe) >> 8)) == 1) &&
         ((byte)((3.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8)
                 | (byte)((ushort)((ushort)(number_of_teams == 3.0) << 0xe) >> 8)) - 1) < 0x40)) {
        _DAT_0018209c = fVar1 / fStack_10 - 1.0;
        if ((byte)(_DAT_0018209c < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_0018209c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(_DAT_0018209c == 0.0) << 0xe) >> 8)) != 0x40) {
          _DAT_0018209c = _DAT_0018209c / 3.0;
        }
        _DAT_0018209c = _DAT_0018209c + 1.0;
      }
      puVar6 = &uStack_24;
      if (((byte)(0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) == 1) &&
         (puVar6 = &uStack_24,
         (byte)((4.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                (byte)((ushort)((ushort)(number_of_teams == 4.0) << 0xe) >> 8)) - 1) < 0x40)) {
        fVar1 = fVar1 / fVar4 - 1.0;
        if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          _DAT_001820a0 = 1.0;
        }
        else {
          _DAT_001820a0 = fVar1 / 3.0;
          fVar1 = 1.0;
        }
        _DAT_001820a0 = _DAT_001820a0 + fVar1;
        puVar6 = &uStack_24;
      }
    }
    if ((byte)(0.0 < (float)tfc_balance_scores._12_4_ |
               (byte)((ushort)((ushort)NAN((float)tfc_balance_scores._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_balance_scores._12_4_ == 0.0) << 0xe) >> 8)) !=
        0x40) {
      *(int *)((int)puVar6 + -4) = teamscores._4_4_ + 0x3c;
      fVar1 = (float)*(int *)((int)puVar6 + -4);
      if ((byte)((2.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8)
                 | (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) - 1) < 0x40) {
        *(int *)((int)puVar6 + -4) = teamscores._8_4_ + 0x3c;
        fStack_c = (float)*(int *)((int)puVar6 + -4);
      }
      else {
        fStack_c = 0.0;
      }
      if ((byte)((3.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8)
                 | (byte)((ushort)((ushort)(number_of_teams == 3.0) << 0xe) >> 8)) - 1) < 0x40) {
        *(int *)((int)puVar6 + -4) = teamscores._12_4_ + 0x3c;
        fStack_10 = (float)*(int *)((int)puVar6 + -4);
      }
      else {
        fStack_10 = 0.0;
      }
      if ((byte)((4.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8)
                 | (byte)((ushort)((ushort)(number_of_teams == 4.0) << 0xe) >> 8)) - 1) < 0x40) {
        *(int *)((int)puVar6 + -4) = teamscores._16_4_ + 0x3c;
        fVar4 = (float)*(int *)((int)puVar6 + -4);
      }
      else {
        fVar4 = 0.0;
      }
      fVar2 = ((fStack_c + fStack_10 + fVar4) / (number_of_teams - 1.0)) / fVar1 - 1.0;
      if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
        fVar2 = fVar2 / 3.0;
      }
      DAT_00182094 = (fVar2 + 1.0) * DAT_00182094;
      if ((byte)((2.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8)
                 | (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) - 1) < 0x40) {
        fVar2 = ((fVar1 + fStack_10 + fVar4) / (number_of_teams - 1.0)) / fStack_c - 1.0;
        if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar2 = fVar2 / 3.0;
        }
        _DAT_00182098 = (fVar2 + 1.0) * _DAT_00182098;
      }
      if ((byte)((3.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8)
                 | (byte)((ushort)((ushort)(number_of_teams == 3.0) << 0xe) >> 8)) - 1) < 0x40) {
        fVar2 = ((fStack_c + fVar1 + fVar4) / (number_of_teams - 1.0)) / fStack_10 - 1.0;
        if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar2 = fVar2 / 3.0;
        }
        _DAT_0018209c = (fVar2 + 1.0) * _DAT_0018209c;
      }
      if ((byte)((4.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8)
                 | (byte)((ushort)((ushort)(number_of_teams == 4.0) << 0xe) >> 8)) - 1) < 0x40) {
        fVar1 = ((fStack_c + fStack_10 + fVar1) / (number_of_teams - 1.0)) / fVar4 - 1.0;
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          fVar1 = fVar1 / 3.0;
        }
        _DAT_001820a0 = (fVar1 + 1.0) * _DAT_001820a0;
      }
    }
  }
  return;
}


