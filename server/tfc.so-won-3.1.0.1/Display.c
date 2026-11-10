// Display_Prematch__Fv  @ 000eb7f4
void Display_Prematch__Fv(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 uVar9;
  
  if (g_fNextPrematchAlert <= *gpGlobals) {
    iVar5 = (int)ROUND(ROUND(cb_prematch_time - *gpGlobals));
    iVar2 = iVar5 / 0x3c;
    if ((iVar5 == iVar2 * 0x3c) && (1 < iVar2)) {
      uVar3 = UTIL_dtos1__Fi(iVar2,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Game_minsleft",uVar3);
      g_fNextPrematchAlert = (float)(iVar5 + -0x3c) + *gpGlobals;
    }
    else {
      if (iVar5 == 0x3c) {
        UTIL_ClientPrintAll__FiPCcN41(1,"#Game_oneminleft",0,0,0,0);
        fVar1 = 30.0;
      }
      else if (iVar5 == 0x1e) {
        UTIL_ClientPrintAll__FiPCcN41(1,"#Game_thirtysecleft",0,0,0,0);
        fVar1 = 20.0;
      }
      else {
        if (iVar5 - 2U < 9) {
          uVar9 = 0;
          uVar7 = 0;
          uVar6 = 0;
          uVar3 = UTIL_dtos1__Fi(iVar5,0,0,0);
          pcVar4 = "#Game_secsleft";
        }
        else {
          if (iVar5 != 1) {
            if (1 < iVar5) {
              return;
            }
            UTIL_ClientPrintAll__FiPCcN41(1,"#Game_matchbegin",0,0,0,0);
            UTIL_LogPrintf__FPce("MATCH BEGINS NOW\n");
            if ((byte)(0.0 < (float)tfc_clanbattle_locked._12_4_ |
                       (byte)((ushort)((ushort)NAN((float)tfc_clanbattle_locked._12_4_) << 10) >> 8)
                      | (byte)((ushort)((ushort)((float)tfc_clanbattle_locked._12_4_ == 0.0) << 0xe)
                              >> 8)) != 0x40) {
              UTIL_ClientPrintAll__FiPCcN41(1,"#Game_matchlocked",0,0,0,0);
            }
            teamscores._4_4_ = 0;
            DAT_001b4a38 = 0;
            teamscores._8_4_ = 0;
            DAT_001b4a3c = 0;
            teamscores._12_4_ = 0;
            DAT_001b4a40 = 0;
            teamscores._16_4_ = 0;
            DAT_001b4a44 = 0;
            cb_prematch_time = 0.0;
            for (iVar5 = 1; iVar5 <= (int)gpGlobals[0x24]; iVar5 = iVar5 + 1) {
              piVar8 = (int *)UTIL_PlayerByIndex__Fi(iVar5);
              if (piVar8 != (int *)0x0) {
                if (piVar8[0x7d] == 0) {
                  CreateBattleID__11CBasePlayer(piVar8);
                }
                TeamFortress_RemoveTimers__11CBasePlayer(piVar8);
                (**(code **)(piVar8[0xf5] + 0x34))(piVar8,*piVar8,*piVar8,0x461c4000,0x8001000);
                *(undefined4 *)(*piVar8 + 0x164) = 0;
                piVar8[0x4b] = 0;
                piVar8[600] = 0;
              }
            }
            piVar8 = (int *)0x0;
            while (piVar8 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar8,"grenade"),
                  piVar8 != (int *)0x0) {
              piVar8[3] = -0x10000;
              piVar8[4] = (int)SUB_Remove__11CBaseEntity;
              *(float *)(*piVar8 + 0x104) = *gpGlobals;
            }
            return;
          }
          uVar9 = 0;
          uVar7 = 0;
          uVar6 = 0;
          uVar3 = 0;
          pcVar4 = "#Game_onesec";
        }
        UTIL_ClientPrintAll__FiPCcN41(1,pcVar4,uVar3,uVar6,uVar7,uVar9);
        fVar1 = 1.0;
      }
      g_fNextPrematchAlert = fVar1 + *gpGlobals;
    }
  }
  return;
}


