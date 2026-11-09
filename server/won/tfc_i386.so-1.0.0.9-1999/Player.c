// Player_Menu__11CBasePlayer  @ 000be450
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Player_Menu__11CBasePlayer(int *param_1)

{
  float fVar1;
  double dVar2;
  
  fVar1 = 0.0;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x45] == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = (float)param_1[0x47];
    if (fVar1 <= *gpGlobals) {
      param_1[0x47] = (int)(*gpGlobals + 2.0);
      if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x45] == 5.0) << 0xe) >> 8)) == 0x40) {
        Menu_Intro__11CBasePlayer(param_1);
        fVar1 = (float)param_1[0x46];
        if ((byte)(4.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 4.0) << 0xe) >> 8)) == 1) {
          ResetMenu__11CBasePlayer(param_1);
          return;
        }
      }
      else {
        if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x45] == 6.0) << 0xe) >> 8)) != 0x40) {
          if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x45] == 12.0) << 0xe) >> 8)) == 0x40) {
            Menu_Spy__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x45] == 13.0) << 0xe) >> 8)) == 0x40) {
            Menu_Spy_Skin__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x45] == 14.0) << 0xe) >> 8)) == 0x40) {
            Menu_Spy_Color__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x45] == 15.0) << 0xe) >> 8)) == 0x40) {
            Menu_Engineer__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x45] == 16.0) << 0xe) >> 8)) == 0x40) {
            Menu_EngineerFix_Dispenser__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x45] == 17.0) << 0xe) >> 8)) == 0x40) {
            Menu_EngineerFix_SentryGun__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x45] == 19.0) << 0xe) >> 8)) == 0x40) {
            Menu_Dispenser__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x45] == 8.0) << 0xe) >> 8)) == 0x40) {
            Menu_RepeatHelp__11CBasePlayer(param_1);
            param_1[0x45] = 0x3f800000;
            return;
          }
          fVar1 = (float)param_1[0x45];
          if ((byte)(20.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 20.0) << 0xe) >> 8)) != 0x40) {
            fVar1 = (float)param_1[0x45];
            if ((byte)(21.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 21.0) << 0xe) >> 8)) != 0x40) {
              if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x45]) << 10) >> 8) |
                        (byte)((ushort)((ushort)((float)param_1[0x45] == 4.0) << 0xe) >> 8)) == 0x40
                 ) {
                Menu_MapBriefing__11CBasePlayer(param_1);
                return;
              }
              if (((param_1[0x48] != 0) ||
                  (fVar1 = gpGlobals[7],
                  (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) ||
                 (param_1[0x49] == 0)) {
                if (((param_1[0xb] != 0) || (param_1[0x49] == 0)) ||
                   (*(int *)(*param_1 + 0x150) != 0)) {
                  param_1[0x45] = 0;
                  param_1[0x47] = 0;
                  return;
                }
                param_1[0x45] = 0x40400000;
                goto LAB_000be804;
              }
              param_1[0x45] = 0x40000000;
            }
            Menu_Team__11CBasePlayer(param_1);
            return;
          }
LAB_000be804:
          Menu_Class__11CBasePlayer(param_1);
          return;
        }
        Menu_ClassHelp__11CBasePlayer(param_1);
        dVar2 = (double)(float)param_1[0x46];
        if ((byte)(_FUN_00134910 < dVar2 |
                   (byte)((ushort)((ushort)(NAN(_FUN_00134910) || NAN(dVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(_FUN_00134910 == dVar2) << 0xe) >> 8)) == 1) {
          ResetMenu__11CBasePlayer(param_1);
          if (param_1[0x261] == 1) {
            return;
          }
          (**(code **)(*g_pGameRules + 0xdc))(g_pGameRules,*(undefined4 *)(*param_1 + 0x1e8));
          param_1[0x261] = 1;
          return;
        }
      }
      param_1[0x46] = (int)((float)param_1[0x46] + 1.0);
      return;
    }
    if (*gpGlobals + 2.0 <= fVar1) {
      fVar1 = *gpGlobals + 2.0;
    }
  }
  param_1[0x47] = (int)fVar1;
  return;
}


