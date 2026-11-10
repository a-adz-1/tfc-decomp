// Display_Prematch__Fv  @ 000f46b0
void Display_Prematch__Fv(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 uVar8;
  
  if (g_fNextPrematchAlert <= *gpGlobals) {
    iVar3 = (int)ROUND(ROUND(cb_prematch_time - *gpGlobals));
    iVar1 = iVar3 / 0x3c;
    if ((iVar3 == iVar1 * 0x3c) && (1 < iVar1)) {
      uVar2 = UTIL_dtos1__Fi(iVar1,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Game_minsleft",uVar2);
      g_fNextPrematchAlert = (float)(iVar3 + -0x3c) + *gpGlobals;
    }
    else {
      if (iVar3 == 0x3c) {
        UTIL_ClientPrintAll__FiPCcN41(1,"#Game_oneminleft",0,0,0,0);
        FUN_000f4810();
        return;
      }
      if (iVar3 == 0x1e) {
        UTIL_ClientPrintAll__FiPCcN41(1,"#Game_thirtysecleft",0,0,0,0);
        FUN_000f4810();
        return;
      }
      if (iVar3 - 2U < 9) {
        uVar8 = 0;
        uVar6 = 0;
        uVar5 = 0;
        uVar2 = UTIL_dtos1__Fi(iVar3,0,0,0);
        pcVar4 = "#Game_secsleft";
      }
      else {
        if (iVar3 != 1) {
          if (1 < iVar3) {
            return;
          }
          UTIL_ClientPrintAll__FiPCcN41(1,"#Game_matchbegin",0,0,0,0);
          UTIL_LogPrintf__FPce("MATCH BEGINS NOW\n");
          if ((byte)(0.0 < (float)tfc_clanbattle_locked._12_4_ |
                     (byte)((ushort)((ushort)NAN((float)tfc_clanbattle_locked._12_4_) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)tfc_clanbattle_locked._12_4_ == 0.0) << 0xe) >>
                          8)) != 0x40) {
            UTIL_ClientPrintAll__FiPCcN41(1,"#Game_matchlocked",0,0,0,0);
          }
          iVar3 = 1;
          do {
            *(undefined4 *)(teamscores + iVar3 * 4) = 0;
            (&teamfrags)[iVar3] = 0;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 5);
          cb_prematch_time = 0.0;
          for (iVar3 = 1; iVar3 <= (int)gpGlobals[0x24]; iVar3 = iVar3 + 1) {
            piVar7 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
            if (piVar7 != (int *)0x0) {
              if (piVar7[0x7d] == 0) {
                CreateBattleID__11CBasePlayer(piVar7);
              }
              TeamFortress_RemoveTimers__11CBasePlayer(piVar7);
              *(undefined4 *)(*piVar7 + 0x144) = 0;
              piVar7[0x4b] = 0;
              (**(code **)(piVar7[0xf2] + 0x34))(piVar7,*piVar7,*piVar7,0x461c4000,0x8001000);
            }
          }
          piVar7 = (int *)0x0;
          while (piVar7 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar7,"grenade"),
                piVar7 != (int *)0x0) {
            piVar7[3] = -0x10000;
            piVar7[4] = (int)SUB_Remove__11CBaseEntity;
            *(float *)(*piVar7 + 0xe4) = *gpGlobals;
          }
          return;
        }
        uVar8 = 0;
        uVar6 = 0;
        uVar5 = 0;
        uVar2 = 0;
        pcVar4 = "#Game_onesec";
      }
      UTIL_ClientPrintAll__FiPCcN41(1,pcVar4,uVar2,uVar5,uVar6,uVar8);
      g_fNextPrematchAlert = *gpGlobals + 1.0;
    }
  }
  return;
}


