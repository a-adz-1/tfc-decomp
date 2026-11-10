// Display_Prematch__Fv  @ 000fab4c
void Display_Prematch__Fv(void)

{
  float fVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  fVar1 = *gpGlobals;
  if ((byte)(fVar1 < g_fNextPrematchAlert |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(g_fNextPrematchAlert)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == g_fNextPrematchAlert) << 0xe) >> 8)) != 1) {
    iVar6 = (int)ROUND(ROUND(cb_prematch_time - fVar1));
    iVar5 = iVar6 / 0x3c;
    if ((iVar6 == iVar5 * 0x3c) && (1 < iVar5)) {
      uVar2 = UTIL_dtos1__Fi(iVar5,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Game_minsleft",uVar2);
      g_fNextPrematchAlert = *gpGlobals + (float)(iVar6 + -0x3c);
    }
    else {
      if (iVar6 == 0x3c) {
        UTIL_ClientPrintAll__FiPCcN41(1,"#Game_oneminleft",0,0,0,0);
        fVar1 = 30.0;
      }
      else if (iVar6 == 0x1e) {
        UTIL_ClientPrintAll__FiPCcN41(1,"#Game_thirtysecleft",0,0,0,0);
        fVar1 = 20.0;
      }
      else {
        if (iVar6 - 2U < 9) {
          uVar9 = 0;
          uVar8 = 0;
          uVar7 = 0;
          uVar2 = UTIL_dtos1__Fi(iVar6,0,0,0);
          pcVar3 = "#Game_secsleft";
        }
        else {
          if (iVar6 != 1) {
            if (1 < iVar6) {
              return;
            }
            UTIL_ClientPrintAll__FiPCcN41(1,"#Game_matchbegin",0,0,0,0);
            UTIL_LogPrintf__FPce("World triggered \"Match_Begins_Now\"\n");
            if ((byte)((float)tfc_clanbattle_locked._12_4_ < 0.0 |
                       (byte)((ushort)((ushort)NAN((float)tfc_clanbattle_locked._12_4_) << 10) >> 8)
                      | (byte)((ushort)((ushort)((float)tfc_clanbattle_locked._12_4_ == 0.0) << 0xe)
                              >> 8)) != 0x40) {
              UTIL_ClientPrintAll__FiPCcN41(1,"#Game_matchlocked",0,0,0,0);
            }
            iVar6 = 1;
            do {
              *(undefined4 *)(teamscores + iVar6 * 4) = 0;
              iVar5 = iVar6 + 1;
              (&teamfrags)[iVar6] = 0;
              iVar6 = iVar5;
            } while (iVar5 < 5);
            cb_prematch_time = 0.0;
            iVar6 = 1;
            if (0 < (int)gpGlobals[0x24]) {
              do {
                piVar4 = (int *)UTIL_PlayerByIndex__Fi(iVar6);
                if (piVar4 != (int *)0x0) {
                  if (piVar4[0x7d] == 0) {
                    CreateBattleID__11CBasePlayer(piVar4);
                  }
                  TeamFortress_RemoveTimers__11CBasePlayer(piVar4);
                  (**(code **)(piVar4[0x115] + 0x38))(piVar4,*piVar4,*piVar4,0x461c4000,0x8001000);
                  *(undefined4 *)(*piVar4 + 0x164) = 0;
                  piVar4[0x4b] = 0;
                  piVar4[0x27f] = 0;
                }
                iVar6 = iVar6 + 1;
              } while (iVar6 <= (int)gpGlobals[0x24]);
            }
            piVar4 = (int *)0x0;
            while (piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"grenade"),
                  piVar4 != (int *)0x0) {
              piVar4[3] = -0x10000;
              piVar4[4] = (int)SUB_Remove__11CBaseEntity;
              *(float *)(*piVar4 + 0x104) = *gpGlobals;
            }
            return;
          }
          uVar9 = 0;
          uVar8 = 0;
          uVar7 = 0;
          uVar2 = 0;
          pcVar3 = "#Game_onesec";
        }
        UTIL_ClientPrintAll__FiPCcN41(1,pcVar3,uVar2,uVar7,uVar8,uVar9);
        fVar1 = 1.0;
      }
      g_fNextPrematchAlert = fVar1 + *gpGlobals;
    }
  }
  return;
}


