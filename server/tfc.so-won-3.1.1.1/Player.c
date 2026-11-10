// Player_Encode__FP7delta_sPCUcT1  @ 0009321c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Player_Encode__FP7delta_sPCUcT1(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  
  if (initialized_736 == 0) {
    _DAT_0015ee60 = (*DAT_0019f8b0)(param_1,player_field_alias);
    _DAT_0015ee84 = (*DAT_0019f8b0)(param_1,&DAT_0015ee64);
    _DAT_0015eea8 = (*DAT_0019f8b0)(param_1,&DAT_0015ee88);
    initialized_736 = 1;
  }
  iVar1 = (*DAT_0019f8a8)();
  if (*(int *)(param_3 + 4) + -1 == iVar1) {
    (*DAT_0019f8b8)(param_1,_DAT_0015ed80);
    (*DAT_0019f8b8)(param_1,_DAT_0015eda4);
    (*DAT_0019f8b8)(param_1,_DAT_0015edc8);
  }
  if ((*(int *)(param_3 + 0x58) == 0xc) && (*(int *)(param_3 + 0x94) != 0)) {
    (*DAT_0019f8b8)(param_1,_DAT_0015ed80);
    (*DAT_0019f8b8)(param_1,_DAT_0015eda4);
    pcVar2 = DAT_0019f8b8;
  }
  else {
    if (*(int *)(param_3 + 0x94) == *(int *)(param_2 + 0x94)) {
      return;
    }
    (*DAT_0019f8b4)(param_1,_DAT_0015ed80);
    (*DAT_0019f8b4)(param_1,_DAT_0015eda4);
    pcVar2 = DAT_0019f8b4;
  }
  (*pcVar2)(param_1,_DAT_0015edc8);
  return;
}


// Player_FieldInit__FP7delta_s  @ 00094440
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Player_FieldInit__FP7delta_s(undefined4 param_1)

{
  _DAT_0015ee60 = (*DAT_0019f8b0)(param_1,player_field_alias);
  _DAT_0015ee84 = (*DAT_0019f8b0)(param_1,&DAT_0015ee64);
  _DAT_0015eea8 = (*DAT_0019f8b0)(param_1,&DAT_0015ee88);
  return;
}


// Player_Menu__11CBasePlayer  @ 000b6b54
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Player_Menu__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  if (param_1[0x28f] == 0) {
    (**(code **)(*g_pGameRules + 0xdc))(g_pGameRules,*(undefined4 *)(*param_1 + 0x208));
    Menu_Team__11CBasePlayer(param_1);
    param_1[0x28f] = 1;
  }
  fVar1 = (float)param_1[0x44];
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
     ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) == 0x40)) {
    iVar4 = *param_1;
    if ((*(int *)(iVar4 + 0x20c) == 0) &&
       ((*(int *)(iVar4 + 0x1ac) == 0 && (*(int *)(iVar4 + 0x244) == 0)))) {
      fVar2 = (float)param_1[0x47];
      if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
        param_1[0x47] = (int)(*gpGlobals + 2.0);
      }
      else if (fVar2 < *gpGlobals) {
        Menu_Team__11CBasePlayer(param_1);
        param_1[0x47] = 0;
        return;
      }
    }
  }
  else {
    param_1[0x47] = 0;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x46] = 0;
  }
  else {
    fVar2 = (float)param_1[0x46];
    fVar3 = *gpGlobals;
    if (fVar2 <= fVar3) {
      param_1[0x46] = (int)(fVar3 + 2.0);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 5.0) << 0xe) >> 8)) == 0x40) {
        Menu_Intro__11CBasePlayer(param_1);
        fVar1 = (float)param_1[0x45];
        if ((byte)(4.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 4.0) << 0xe) >> 8)) != 1) {
          FUN_000b6d6c();
          return;
        }
      }
      else {
        if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 6.0) << 0xe) >> 8)) != 0x40) {
          if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 12.0) << 0xe) >> 8)) == 0x40) {
            Menu_Spy__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 13.0) << 0xe) >> 8)) == 0x40) {
            Menu_Spy_Skin__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 14.0) << 0xe) >> 8)) == 0x40) {
            Menu_Spy_Color__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 15.0) << 0xe) >> 8)) == 0x40) {
            Menu_Engineer__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 17.0) << 0xe) >> 8)) == 0x40) {
            Menu_EngineerFix_SentryGun__11CBasePlayer(param_1);
            return;
          }
          if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 19.0) << 0xe) >> 8)) == 0x40) {
            Menu_Dispenser__11CBasePlayer(param_1);
            return;
          }
          fVar1 = (float)param_1[0x44];
          if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 8.0) << 0xe) >> 8)) == 0x40) {
            Menu_RepeatHelp__11CBasePlayer(param_1);
            param_1[0x44] = 0x3f800000;
            return;
          }
          if ((byte)(2.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) == 0x40) {
            return;
          }
          if ((byte)(3.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 3.0) << 0xe) >> 8)) == 0x40) {
            return;
          }
          param_1[0x44] = 0;
          param_1[0x46] = 0;
          return;
        }
        Menu_ClassHelp__11CBasePlayer(param_1);
        if ((float)param_1[0x45] <= (float)_FUN_0014cd50) {
          param_1[0x45] = (int)((float)param_1[0x45] + 1.0);
          return;
        }
      }
      *(undefined1 *)(param_1 + 0x290) = 0;
      param_1[0x45] = 0;
      param_1[0x46] = 0;
      param_1[0x44] = 0x3f800000;
    }
    else {
      fVar3 = fVar3 + 2.0;
      if (0x3f < (byte)((fVar3 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1)) {
        fVar3 = fVar2;
      }
      param_1[0x46] = (int)fVar3;
    }
  }
  return;
}


