// UpdateMasks__13CVoiceGameMgr  @ 0013ad94
void UpdateMasks__13CVoiceGameMgr(undefined4 *param_1)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  longdouble lVar11;
  bool local_49;
  int local_38;
  uint local_10;
  undefined4 *local_c;
  int local_8;
  
  param_1[4] = 0;
  param_1[5] = 0;
  lVar11 = (longdouble)(*DAT_0019f784)("sv_alltalk");
  local_38 = 0;
  if (0 < (int)param_1[3]) {
    do {
      iVar4 = local_38 + 1;
      piVar5 = (int *)UTIL_PlayerByIndex__Fi(iVar4);
      if ((piVar5 != (int *)0x0) &&
         (iVar6 = (**(code **)(piVar5[0x115] + 0xa0))(piVar5), iVar6 != 0)) {
        local_c = &g_bWantModEnable;
        local_8 = local_38;
        bVar9 = (byte)local_38 & 0x1f;
        if (((&g_bWantModEnable)[local_38 >> 5] & 1 << bVar9) != 0) {
          (*DAT_0019f758)(1,param_1[1],0,*(undefined4 *)(*piVar5 + 0x208));
          (*DAT_0019f75c)();
        }
        iVar6 = 0;
        do {
          (&local_10)[iVar6] = 0;
          iVar6 = iVar6 + 1;
        } while (iVar6 < 1);
        if ((((&g_PlayerModEnable)[local_38 >> 5] & 1 << bVar9) != 0) &&
           (iVar6 = 0, 0 < (int)param_1[3])) {
          do {
            iVar1 = iVar6 + 1;
            iVar7 = UTIL_PlayerByIndex__Fi(iVar1);
            if (((iVar7 != 0) &&
                (iVar8 = (**(code **)(*(int *)(iVar7 + 0x454) + 0xa0))(iVar7), iVar8 != 0)) &&
               (((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar11)) << 10) >> 8) |
                       (byte)((ushort)((ushort)((longdouble)0 == lVar11) << 0xe) >> 8)) != 0x40 ||
                (cVar3 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar5,iVar7),
                cVar3 != '\0')))) {
              (&local_10)[iVar6 >> 5] = (&local_10)[iVar6 >> 5] | 1 << ((byte)iVar6 & 0x1f);
            }
            iVar6 = iVar1;
          } while (iVar1 < (int)param_1[3]);
        }
        iVar6 = 0;
        do {
          if ((&local_10)[iVar6] != (&g_SentGameRulesMasks)[local_38 + iVar6]) {
            bVar2 = false;
            goto LAB_0013af7b;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 1);
        bVar2 = true;
LAB_0013af7b:
        if (bVar2) {
          iVar6 = 0;
          do {
            if ((&g_BanMasks)[local_38 + iVar6] != (&g_SentBanMasks)[local_38 + iVar6]) {
              bVar2 = false;
              goto LAB_0013afaf;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 1);
          bVar2 = true;
LAB_0013afaf:
          if (!bVar2) goto LAB_0013afb8;
        }
        else {
LAB_0013afb8:
          (&g_SentGameRulesMasks)[local_38] = local_10;
          (&g_SentBanMasks)[local_38] = (&g_BanMasks)[local_38];
          (*DAT_0019f758)(1,*param_1,0,*(undefined4 *)(*piVar5 + 0x208));
          iVar6 = 0;
          do {
            (*DAT_0019f76c)((&local_10)[iVar6]);
            (*DAT_0019f76c)((&g_BanMasks)[local_38 + iVar6]);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 1);
          (*DAT_0019f75c)();
        }
        iVar6 = 0;
        if (0 < (int)param_1[3]) {
          do {
            local_49 = false;
            uVar10 = 1 << ((byte)iVar6 & 0x1f);
            if (((&local_10)[iVar6 >> 5] & uVar10) != 0) {
              local_49 = ((&g_BanMasks)[local_38 + (iVar6 >> 5)] & uVar10) == 0;
            }
            iVar6 = iVar6 + 1;
            (*DAT_0019f8d8)(iVar4,iVar6,local_49);
          } while (iVar6 < (int)param_1[3]);
        }
      }
      local_38 = iVar4;
    } while (iVar4 < (int)param_1[3]);
  }
  return;
}


