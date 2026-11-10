// Player_Encode__FP7delta_sPCUcT1  @ 0009402c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Player_Encode__FP7delta_sPCUcT1(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  
  if (initialized_721 == 0) {
    Player_FieldInit__FP7delta_s(param_1);
    initialized_721 = 1;
  }
  iVar1 = (*DAT_001c1228)();
  if (*(int *)(param_3 + 4) + -1 == iVar1) {
    (*DAT_001c1238)(param_1,_DAT_00159c60);
    (*DAT_001c1238)(param_1,_DAT_00159c84);
    (*DAT_001c1238)(param_1,_DAT_00159ca8);
  }
  if ((*(int *)(param_3 + 0x58) == 0xc) && (*(int *)(param_3 + 0x94) != 0)) {
    (*DAT_001c1238)(param_1,_DAT_00159c60);
    (*DAT_001c1238)(param_1,_DAT_00159c84);
    pcVar2 = DAT_001c1238;
  }
  else {
    if (*(int *)(param_3 + 0x94) == *(int *)(param_2 + 0x94)) {
      return;
    }
    (*DAT_001c1234)(param_1,_DAT_00159c60);
    (*DAT_001c1234)(param_1,_DAT_00159c84);
    pcVar2 = DAT_001c1234;
  }
  (*pcVar2)(param_1,_DAT_00159ca8);
  return;
}


// Player_FieldInit__FP7delta_s  @ 00093fc4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Player_FieldInit__FP7delta_s(undefined4 param_1)

{
  _DAT_00159d40 = (*DAT_001c1230)(param_1,player_field_alias);
  _DAT_00159d64 = (*DAT_001c1230)(param_1,&DAT_00159d44);
  _DAT_00159d88 = (*DAT_001c1230)(param_1,&DAT_00159d68);
  return;
}


// Player_Menu__11CBasePlayer  @ 000b7c1c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Player_Menu__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (param_1[0x285] == 0) {
    (**(code **)(*g_pGameRules + 0xdc))(g_pGameRules,*(undefined4 *)(*param_1 + 0x208));
    Menu_Team__11CBasePlayer(param_1);
    param_1[0x285] = 1;
  }
  fVar1 = (float)param_1[0x44];
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
     ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) == 0x40)) {
    iVar3 = *param_1;
    if ((*(int *)(iVar3 + 0x20c) == 0) &&
       ((*(int *)(iVar3 + 0x1ac) == 0 && (*(int *)(iVar3 + 0x244) == 0)))) {
      if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x47]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x47] == 0.0) << 0xe) >> 8)) == 0x40) {
        param_1[0x47] = (int)(*gpGlobals + 2.0);
      }
      else {
        fVar1 = *gpGlobals;
        fVar2 = (float)param_1[0x47];
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          Menu_Team__11CBasePlayer(param_1);
          param_1[0x47] = 0;
          return;
        }
      }
    }
  }
  else {
    param_1[0x47] = 0;
  }
  fVar1 = (float)param_1[0x44];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
LAB_000b7f9c:
    param_1[0x46] = 0;
  }
  else {
    fVar1 = (float)param_1[0x46];
    fVar2 = *gpGlobals;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      fVar2 = *gpGlobals + 2.0;
      if (0x3f < (byte)((fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
        fVar2 = fVar1;
      }
      param_1[0x46] = (int)fVar2;
      return;
    }
    param_1[0x46] = (int)(*gpGlobals + 2.0);
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x44] == 5.0) << 0xe) >> 8)) == 0x40) {
      Menu_Intro__11CBasePlayer(param_1);
      fVar1 = (float)param_1[0x45];
      if ((byte)(4.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 4.0) << 0xe) >> 8)) == 1) {
LAB_000b7e24:
        ResetMenu__11CBasePlayer(param_1);
        return;
      }
    }
    else {
      if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x44] == 6.0) << 0xe) >> 8)) != 0x40) {
        if ((byte)((byte)((ushort)((ushort)(NAN(_FUN_00147840) || NAN((float)param_1[0x44])) << 10)
                         >> 8) |
                  (byte)((ushort)((ushort)(_FUN_00147840 == (float)param_1[0x44]) << 0xe) >> 8)) ==
            0x40) {
          Menu_Spy__11CBasePlayer(param_1);
          return;
        }
        if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x44] == 13.0) << 0xe) >> 8)) == 0x40) {
          Menu_Spy_Skin__11CBasePlayer(param_1);
          return;
        }
        if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x44] == 14.0) << 0xe) >> 8)) == 0x40) {
          Menu_Spy_Color__11CBasePlayer(param_1);
          return;
        }
        if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x44] == 15.0) << 0xe) >> 8)) == 0x40) {
          Menu_Engineer__11CBasePlayer(param_1);
          return;
        }
        if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x44] == 17.0) << 0xe) >> 8)) == 0x40) {
          Menu_EngineerFix_SentryGun__11CBasePlayer(param_1);
          return;
        }
        if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x44] == 19.0) << 0xe) >> 8)) == 0x40) {
          Menu_Dispenser__11CBasePlayer(param_1);
          return;
        }
        if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x44]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x44] == 8.0) << 0xe) >> 8)) == 0x40) {
          Menu_RepeatHelp__11CBasePlayer(param_1);
          param_1[0x44] = 0x3f800000;
          return;
        }
        fVar1 = (float)param_1[0x44];
        if ((byte)(2.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) == 0x40) {
          return;
        }
        if ((byte)(3.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 3.0) << 0xe) >> 8)) == 0x40) {
          return;
        }
        param_1[0x44] = 0;
        goto LAB_000b7f9c;
      }
      Menu_ClassHelp__11CBasePlayer(param_1);
      if (7.5 < (float)param_1[0x45]) goto LAB_000b7e24;
    }
    param_1[0x45] = (int)((float)param_1[0x45] + 1.0);
  }
  return;
}


