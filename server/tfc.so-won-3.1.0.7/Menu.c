// Menu_ClassHelp_Input__11CBasePlayerf  @ 000b84d0
void Menu_ClassHelp_Input__11CBasePlayerf(undefined4 param_1)

{
  ResetMenu__11CBasePlayer(param_1);
  return;
}


// Menu_ClassHelp__11CBasePlayer  @ 000b83f0
void Menu_ClassHelp__11CBasePlayer(int *param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = *(int *)(*param_1 + 0x20c);
  if (iVar1 == 1) {
    pcVar2 = "#Help_scout";
  }
  else if (iVar1 == 2) {
    pcVar2 = "#Help_sniper";
  }
  else if (iVar1 == 3) {
    pcVar2 = "#Help_soldier";
  }
  else if (iVar1 == 4) {
    pcVar2 = "#Help_demoman";
  }
  else if (iVar1 == 5) {
    pcVar2 = "#Help_medic";
  }
  else if (iVar1 == 6) {
    pcVar2 = "#Help_hwguy";
  }
  else if (iVar1 == 7) {
    pcVar2 = "#Help_pyro";
  }
  else if (iVar1 == 8) {
    pcVar2 = "#Help_spy";
  }
  else {
    if (iVar1 != 9) {
      return;
    }
    pcVar2 = "#Help_engineer";
  }
  MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar2,0xffff,0xffffffff);
  return;
}


// Menu_Class__11CBasePlayer  @ 000b816c
void Menu_Class__11CBasePlayer(int *param_1)

{
  param_1[0x44] = 0x40400000;
  (*DAT_001c10d8)(1,gmsgVGUIMenu,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001c10e0)(3);
  (*DAT_001c10dc)();
  return;
}


// Menu_Dispenser_Input__11CBasePlayerf  @ 000b99cc
void Menu_Dispenser_Input__11CBasePlayerf(void)

{
  return;
}


// Menu_Dispenser__11CBasePlayer  @ 000b99a0
void Menu_Dispenser__11CBasePlayer(undefined4 param_1)

{
  MenuPrint__FP11CBasePlayerPCcii(param_1,"#Menu_Dispenser",0xffff,0xffffffff);
  return;
}


// Menu_EngineerFix_Dispenser_Input__11CBasePlayerf  @ 000b91fc
void Menu_EngineerFix_Dispenser_Input__11CBasePlayerf(void)

{
  return;
}


// Menu_EngineerFix_Dispenser__11CBasePlayer  @ 000b91d0
void Menu_EngineerFix_Dispenser__11CBasePlayer(undefined4 param_1)

{
  MenuPrint__FP11CBasePlayerPCcii
            (param_1,
             "#Action  \n1. #Menu_AmmoDisp \n2. #Menu_ArmorDisp \n3. #Menu_RepairDisp \n4. #Menu_DismantleDisp \n5. #Nothing \n\n"
             ,0xffff,0xffffffff);
  return;
}


// Menu_EngineerFix_Mortar_Input__11CBasePlayerf  @ 000b9910
void Menu_EngineerFix_Mortar_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  
  if ((1.0 <= param_2) &&
     ((byte)(5.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) != 1)) {
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x184) = 0;
    fVar1 = *(float *)(*param_1 + 0x1bc);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x1b8) = 0;
      param_1[0xe] = 0;
      param_1[0x22] = param_1[0x22] - (param_1[0x22] & 0xe000U);
    }
  }
  return;
}


// Menu_EngineerFix_Mortar__11CBasePlayer  @ 000b990c
void Menu_EngineerFix_Mortar__11CBasePlayer(void)

{
  return;
}


// Menu_EngineerFix_SentryGun_Input__11CBasePlayerf  @ 000b9270
void Menu_EngineerFix_SentryGun_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  longdouble lVar7;
  float local_14;
  float local_10;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
  if (iVar2 == 0) {
    ResetMenu__11CBasePlayer(param_1);
  }
  else {
    iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
    iVar2 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
    if (iVar2 != 0) {
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      iVar2 = __rf__7EHANDLE(iVar2 + 0x144);
      if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x150)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x150) == 0.0) << 0xe) >> 8)) != 0x40) {
        if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) {
          local_10 = 40.0;
          if ((float)param_1[0x33] < 40.0) {
            local_10 = (float)param_1[0x33];
          }
          piVar5 = param_1 + 0x4e;
          iVar2 = __rf__7EHANDLE(piVar5);
          iVar3 = __rf__7EHANDLE(piVar5);
          fVar1 = (float)(*(int *)(iVar2 + 0xc0) - *(int *)(iVar3 + 0xcc));
          if (0x3f < (byte)((local_10 < fVar1 |
                             (byte)((ushort)((ushort)(NAN(local_10) || NAN(fVar1)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(local_10 == fVar1) << 0xe) >> 8)) - 1)) {
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar3 = __rf__7EHANDLE(piVar5);
            local_10 = (float)(*(int *)(iVar2 + 0xc0) - *(int *)(iVar3 + 0xcc));
          }
          param_1[0x33] = (int)ROUND((float)param_1[0x33] - local_10);
          piVar5 = param_1 + 0x4e;
          iVar2 = __rf__7EHANDLE(piVar5);
          iVar3 = __rf__7EHANDLE(piVar5);
          *(int *)(iVar2 + 0xcc) = (int)ROUND(local_10 + (float)*(int *)(iVar3 + 0xcc));
          iVar2 = __rf__7EHANDLE(piVar5);
          if (*(int *)(iVar2 + 0x8c) == 3) {
            local_10 = 20.0;
            if ((float)param_1[0x39] < 20.0) {
              local_10 = (float)param_1[0x39];
            }
            piVar5 = param_1 + 0x4e;
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar3 = __rf__7EHANDLE(piVar5);
            fVar1 = (float)(*(int *)(iVar2 + 0xe0) - *(int *)(iVar3 + 0xe4));
            if (0x3f < (byte)((local_10 < fVar1 |
                               (byte)((ushort)((ushort)(NAN(local_10) || NAN(fVar1)) << 10) >> 8) |
                              (byte)((ushort)((ushort)(local_10 == fVar1) << 0xe) >> 8)) - 1)) {
              iVar2 = __rf__7EHANDLE(piVar5);
              iVar3 = __rf__7EHANDLE(piVar5);
              local_10 = (float)(*(int *)(iVar2 + 0xe0) - *(int *)(iVar3 + 0xe4));
            }
            param_1[0x39] = (int)ROUND((float)param_1[0x39] - local_10);
            iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
            iVar3 = __rf__7EHANDLE(param_1 + 0x4e);
            *(int *)(iVar2 + 0xe4) = (int)ROUND(local_10 + (float)*(int *)(iVar3 + 0xe4));
          }
        }
        else {
          piVar5 = param_1 + 0x4e;
          iVar2 = __rf__7EHANDLE(piVar5);
          if (((*(int *)(iVar2 + 0x8c) < 3) &&
              ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) == 0x40)) &&
             (0x81 < param_1[0x37])) {
            param_1[0x37] = param_1[0x37] + -0x82;
            uVar4 = __opP11CBaseEntity__7EHANDLE(piVar5);
            Upgrade__12CTFSentrygun(uVar4);
            iVar2 = __rf__7EHANDLE(piVar5,0,0,0);
            uVar4 = UTIL_dtos1__Fi(*(undefined4 *)(iVar2 + 0x8c));
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_upgrade",uVar4);
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) {
            piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
            piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
            local_14 = (*(float *)(*piVar5 + 0x1b0) - *(float *)(*piVar6 + 0x160)) * 0.2;
            if ((float)param_1[0x37] < local_14) {
              local_14 = (float)param_1[0x37];
            }
            param_1[0x37] = (int)ROUND((float)param_1[0x37] - local_14);
            piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
            piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
            *(float *)(*piVar5 + 0x160) = local_14 * 5.0 + *(float *)(*piVar6 + 0x160);
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
            piVar5 = param_1 + 0x4e;
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar2 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
            if (iVar2 != 0) {
              iVar2 = __rf__7EHANDLE(piVar5);
              piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
              if (piVar6 != param_1) {
                return;
              }
              iVar2 = __rf__7EHANDLE(piVar5);
              iVar2 = __rf__7EHANDLE(iVar2 + 0x144);
              *(undefined4 *)(iVar2 + 0x150) = 0;
            }
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_dismantle",0,0,0,0);
            param_1[0x37] = param_1[0x37] + 0x41;
            TeamFortress_CheckClassStats__11CBasePlayer(param_1);
            iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
            uVar4 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x98);
            dremove__FP11CBaseEntity(uVar4);
            uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
            dremove__FP11CBaseEntity(uVar4);
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) == 0x40) {
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_rotate",0,0,0,0);
            piVar5 = param_1 + 0x4e;
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar3 = __rf__7EHANDLE(piVar5);
            lVar7 = (longdouble)anglemod__Ff((float)(*(int *)(iVar3 + 0xa0) + 0x2d));
            *(int *)(iVar2 + 0xa0) = (int)ROUND(lVar7);
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar3 = __rf__7EHANDLE(piVar5);
            lVar7 = (longdouble)anglemod__Ff((float)(*(int *)(iVar3 + 0xa4) + 0x2d));
            *(int *)(iVar2 + 0xa4) = (int)ROUND(lVar7);
          }
        }
        if (param_2 < 1.0) {
          return;
        }
        if ((byte)(6.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) == 1) {
          return;
        }
        ResetMenu__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x184) = 0;
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
        fVar1 = *(float *)(*param_1 + 0x1bc);
        if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          return;
        }
        *(undefined4 *)(*param_1 + 0x1b8) = 0;
        param_1[0xe] = 0;
        param_1[0x22] = param_1[0x22] - (param_1[0x22] & 0xe000U);
        return;
      }
    }
    ResetMenu__11CBasePlayer(param_1);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
  }
  return;
}


// Menu_EngineerFix_SentryGun__11CBasePlayer  @ 000b9200
void Menu_EngineerFix_SentryGun__11CBasePlayer(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x138);
  if (iVar1 != 0) {
    iVar1 = __rf__7EHANDLE(param_1 + 0x138);
    if ((*(int *)(iVar1 + 0x8c) < 3) && (0x81 < *(int *)(param_1 + 0xdc))) {
      pcVar2 = FUN_00148240;
    }
    else {
      pcVar2 = FUN_001482e0;
    }
    MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar2,0xffff,0xffffffff);
  }
  return;
}


// Menu_Engineer_Input__11CBasePlayerf  @ 000b8b28
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Menu_Engineer_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  longdouble lVar8;
  undefined4 uVar9;
  
  if ((((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) &&
      (99 < param_1[0x37])) &&
     (fVar1 = (float)param_1[0x53],
     (byte)(fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) {
    uVar9 = 1;
  }
  else {
    if ((((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) != 0x40) ||
        (param_1[0x37] < 0x82)) ||
       (fVar1 = (float)param_1[0x54],
       (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40)) {
      if (((((byte)(param_2 < 3.0 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) ||
           ((byte)(4.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40)) ||
          ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) == 0x40)) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x54]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x54] == 1.0) << 0xe) >> 8)) == 0x40)) {
        ResetMenu__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x184) = 0;
        piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_sentrygun");
        if (piVar4 == (int *)0x0) {
          return;
        }
        do {
          piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4 + 0x51);
          if (piVar5 == param_1) break;
          piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                    (piVar4,"building_sentrygun");
        } while (piVar4 != (int *)0x0);
        if (piVar4 == (int *)0x0) {
          return;
        }
        if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) != 0x40) {
          if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_rotate",0,0,0,0);
            lVar8 = (longdouble)anglemod__Ff((float)(piVar4[0x28] + 0x2d));
            piVar4[0x28] = (int)ROUND(lVar8);
            iVar7 = piVar4[0x29] + 0x2d;
          }
          else {
            if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) != 0x40) {
              return;
            }
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_rotate180",0,0,0,0);
            lVar8 = (longdouble)anglemod__Ff((float)(piVar4[0x28] + 0xb4));
            piVar4[0x28] = (int)ROUND(lVar8);
            iVar7 = piVar4[0x29] + 0xb4;
          }
          lVar8 = (longdouble)anglemod__Ff((float)iVar7);
          piVar4[0x29] = (int)ROUND(lVar8);
          return;
        }
        iVar7 = *param_1;
        fVar1 = *(float *)(iVar7 + 8) - *(float *)(*piVar4 + 8);
        fVar3 = *(float *)(iVar7 + 0xc) - *(float *)(*piVar4 + 0xc);
        fVar2 = *(float *)(iVar7 + 0x10) - *(float *)(*piVar4 + 0x10);
        if (SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) <= 128.0) {
          ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sentry_dismantle",0,0,0,0);
          if (param_1[0x48] == 0) {
            pcVar6 = "SPECTATOR";
          }
          else {
            pcVar6 = (char *)GetTeamName__Fi(param_1[0x48]);
          }
          uVar9 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar6);
          uVar9 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar9);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%u><%s>\" triggered \"Sentry_Dismantle\"\n",
                     *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar9);
          param_1[0x37] = param_1[0x37] + piVar4[0x23] * 0x40 + piVar4[0x23];
          TeamFortress_CheckClassStats__11CBasePlayer(param_1);
          uVar9 = __opP11CBaseEntity__7EHANDLE(piVar4 + 0x26);
          dremove__FP11CBaseEntity(uVar9);
          dremove__FP11CBaseEntity(piVar4);
          param_1[0x54] = 0;
          return;
        }
        pcVar6 = "#Sentry_DistDismantle";
LAB_000b90ce:
        ClientPrint__FP9entvars_siPCcN42(iVar7,1,pcVar6,0,0,0,0);
        return;
      }
      if (((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 7.0) << 0xe) >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x53]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x53] == 1.0) << 0xe) >> 8)) == 0x40)) {
        pcVar6 = "building_dispenser";
      }
      else {
        if (((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 8.0) << 0xe) >> 8)) != 0x40) ||
           ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x54]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x54] == 1.0) << 0xe) >> 8)) != 0x40)) {
          if (((byte)((byte)((ushort)((ushort)(NAN(param_2) || NAN(_FUN_001481b0)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_2 == _FUN_001481b0) << 0xe) >> 8)) != 0x40) ||
             ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x53]) << 10) >> 8) |
                    (byte)((ushort)((ushort)((float)param_1[0x53] == 1.0) << 0xe) >> 8)) != 0x40)) {
            if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) != 0x40) {
              return;
            }
            ResetMenu__11CBasePlayer(param_1);
            *(undefined4 *)(*param_1 + 0x184) = 0;
            return;
          }
          ResetMenu__11CBasePlayer(param_1);
          *(undefined4 *)(*param_1 + 0x184) = 0;
          piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_dispenser");
          if (piVar4 == (int *)0x0) {
            return;
          }
          do {
            piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4 + 0x51);
            if (piVar5 == param_1) break;
            piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                      (piVar4,"building_dispenser");
          } while (piVar4 != (int *)0x0);
          if (piVar4 == (int *)0x0) {
            return;
          }
          iVar7 = *param_1;
          fVar1 = *(float *)(iVar7 + 8) - *(float *)(*piVar4 + 8);
          fVar3 = *(float *)(iVar7 + 0xc) - *(float *)(*piVar4 + 0xc);
          fVar2 = *(float *)(iVar7 + 0x10) - *(float *)(*piVar4 + 0x10);
          if (SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) <= 128.0) {
            ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Dispenser_dismantle",0,0,0,0);
            if (param_1[0x48] == 0) {
              pcVar6 = "SPECTATOR";
            }
            else {
              pcVar6 = (char *)GetTeamName__Fi(param_1[0x48]);
            }
            uVar9 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar6);
            uVar9 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar9);
            UTIL_LogPrintf__FPce
                      (FUN_00148160,*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar9);
            param_1[0x37] = param_1[0x37] + 0x32;
            TeamFortress_CheckClassStats__11CBasePlayer(param_1);
            dremove__FP11CBaseEntity(piVar4);
            param_1[0x53] = 0;
            return;
          }
          pcVar6 = "#Dispenser_DistDismantle";
          goto LAB_000b90ce;
        }
        pcVar6 = "building_sentrygun";
      }
      DestroyBuilding__FP11CBaseEntityPc(param_1,pcVar6);
      goto LAB_000b8fb7;
    }
    uVar9 = 2;
  }
  TeamFortress_EngineerBuild__11CBasePlayeri(param_1,uVar9);
LAB_000b8fb7:
  ResetMenu__11CBasePlayer(param_1);
  *(undefined4 *)(*param_1 + 0x184) = 0;
  return;
}


// Menu_Engineer__11CBasePlayer  @ 000b89d8
void Menu_Engineer__11CBasePlayer(int param_1)

{
  float fVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *local_c;
  
  pcVar5 = "7. #Menu_DetDisp \n";
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x14c)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x14c) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (pcVar5 = "\n", 99 < *(int *)(param_1 + 0xdc))) {
    pcVar5 = "1. #Menu_BuildDisp \n";
  }
  pcVar3 = "8. #Menu_DetSentry \n";
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x150)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x150) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (pcVar3 = "\n", 0x81 < *(int *)(param_1 + 0xdc))) {
    pcVar3 = "2. #Menu_BuildSentry \n";
  }
  fVar1 = *(float *)(param_1 + 0x150);
  pcVar4 = "\n";
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    pcVar4 = "3. #Menu_DismantleSentry \n";
  }
  fVar1 = *(float *)(param_1 + 0x150);
  pcVar2 = "\n";
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    pcVar2 = "4. #Menu_RotateSentry \n";
  }
  fVar1 = *(float *)(param_1 + 0x14c);
  local_c = "\n";
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    local_c = "9. #Menu_DismantleDisp \n";
  }
  sprintf(cbuf,"%s%s%s%s%s%s%s","#Action \n",pcVar5,pcVar3,pcVar4,pcVar2,local_c,"5. #Nothing \n\n")
  ;
  MenuPrint__FP11CBasePlayerPCcii(param_1,cbuf,0xffff,0xffffffff);
  return;
}


// Menu_Input__11CBasePlayerf  @ 000b8200
void Menu_Input__11CBasePlayerf(int param_1,undefined4 param_2)

{
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x110)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0x110) == 12.0) << 0xe) >> 8)) == 0x40) {
    Menu_Spy_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x110)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x110) == 13.0) << 0xe) >> 8)) ==
           0x40) {
    Menu_Spy_Skin_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x110)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x110) == 14.0) << 0xe) >> 8)) ==
           0x40) {
    Menu_Spy_Color_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x110)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x110) == 15.0) << 0xe) >> 8)) ==
           0x40) {
    Menu_Engineer_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x110)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x110) == 18.0) << 0xe) >> 8)) ==
           0x40) {
    Menu_EngineerFix_Mortar_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x110)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x110) == 17.0) << 0xe) >> 8)) ==
           0x40) {
    Menu_EngineerFix_SentryGun_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x110)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x110) == 19.0) << 0xe) >> 8)) ==
           0x40) {
    Menu_Dispenser_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x110)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x110) == 6.0) << 0xe) >> 8)) == 0x40
          ) {
    Menu_ClassHelp_Input__11CBasePlayerf(param_1,param_2);
  }
  return;
}


// Menu_Intro__11CBasePlayer  @ 000b836c
void Menu_Intro__11CBasePlayer(undefined4 param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (char *)infokey__FP11CBasePlayerPCc(0,"motd1");
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    MenuPrint__FP11CBasePlayerPCcii
              (param_1,
               "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
               ,0xffff,0xffffffff);
  }
  else {
    uVar2 = infokey__FP11CBasePlayerPCc(0,"motd2");
    sprintf(cbuf,"%s\n%s",pcVar1,uVar2);
    MenuPrint__FP11CBasePlayerPCcii(param_1,cbuf,0xffff,0xffffffff);
  }
  return;
}


// Menu_MapBriefing__11CBasePlayer  @ 000b7fb0
void Menu_MapBriefing__11CBasePlayer(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  bVar1 = true;
  uVar2 = (*DAT_001c11c8)(*(undefined4 *)(*param_1 + 0x208));
  pcVar3 = (char *)(*DAT_001c11cc)(uVar2,&DAT_00147868);
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    iVar4 = 2;
    bVar7 = true;
    pcVar5 = pcVar3;
    pcVar6 = "0";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar4 = 4;
      bVar7 = true;
      pcVar5 = "off";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (!bVar7) goto LAB_000b8030;
    }
    bVar1 = false;
  }
LAB_000b8030:
  if (bVar1) {
    (*DAT_001c10d8)(1,gmsgVGUIMenu,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)(4);
    (*DAT_001c10f8)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98));
    (*DAT_001c10dc)();
  }
  return;
}


// Menu_RepeatHelp__11CBasePlayer  @ 000b81d4
void Menu_RepeatHelp__11CBasePlayer(undefined4 param_1)

{
  MenuPrint__FP11CBasePlayerPCcii(param_1,"#Menu_repeathelp",0xffff,0xffffffff);
  return;
}


// Menu_Spy_Color_Input__11CBasePlayerf  @ 000b8954
void Menu_Spy_Color_Input__11CBasePlayerf(int *param_1,float param_2)

{
  if ((1.0 <= param_2) && (param_2 <= number_of_teams)) {
    TeamFortress_SpyChangeColor__11CBasePlayeri(param_1,(int)ROUND(param_2));
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x184) = 0;
  }
  return;
}


// Menu_Spy_Color__11CBasePlayer  @ 000b8854
void Menu_Spy_Color__11CBasePlayer(int *param_1)

{
  char *pcVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
            (byte)((ushort)((ushort)(number_of_teams == 0.0) << 0xe) >> 8)) == 0x40) {
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_nocolorchange",0,0,0,0);
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x184) = 0;
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
              (byte)((ushort)((ushort)(number_of_teams == 1.0) << 0xe) >> 8)) == 0x40) {
      pcVar1 = "#Spy_colormenu \n\n1. #BlueTeam \n\n";
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                   (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) == 0x40) {
      pcVar1 = "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n";
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                   (byte)((ushort)((ushort)(number_of_teams == 3.0) << 0xe) >> 8)) == 0x40) {
      pcVar1 = "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n";
    }
    else {
      pcVar1 = "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n"
      ;
    }
    MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar1,0xffff,0xffffffff);
  }
  return;
}


// Menu_Spy_Input__11CBasePlayerf  @ 000b85fc
void Menu_Spy_Input__11CBasePlayerf(int *param_1,float param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (((byte)(1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) != 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) != 0x40)) {
LAB_000b8694:
    if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) {
      Menu_Spy_Skin__11CBasePlayer(param_1);
      param_1[0x44] = 0x41500000;
      param_1[0x45] = 0;
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) == 0x40) {
      Menu_Spy_Color__11CBasePlayer(param_1);
      param_1[0x44] = 0x41600000;
      param_1[0x45] = 0;
    }
    else {
      if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) {
        TeamFortress_SpyFeignDeath__11CBasePlayeri(param_1,0);
        ResetMenu__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x184) = 0;
        return;
      }
      if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
        Spy_RemoveDisguise__11CBasePlayer(param_1);
        ResetMenu__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x184) = 0;
        return;
      }
      if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) != 0x40) {
        return;
      }
      if ((param_1[0x75] == 0) && (param_1[0x76] == 0)) {
        return;
      }
      ResetMenu__11CBasePlayer(param_1);
    }
    *(undefined4 *)(*param_1 + 0x184) = 0;
    return;
  }
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x118) & 5) == 0) {
    if (param_1[0x1d] != 1) goto LAB_000b8694;
    pcVar2 = "#Spy_unable";
    iVar1 = *param_1;
  }
  else {
    pcVar2 = "#Spy_glowing";
  }
  ClientPrint__FP9entvars_siPCcN42(iVar1,1,pcVar2,0,0,0,0);
  ResetMenu__11CBasePlayer(param_1);
  *(undefined4 *)(*param_1 + 0x184) = 0;
  return;
}


// Menu_Spy_Skin_Input__11CBasePlayerf  @ 000b87cc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Menu_Spy_Skin_Input__11CBasePlayerf(int *param_1,float param_2)

{
  if ((0x3f < (byte)((10.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_2 == 10.0) << 0xe) >> 8)) - 1)) &&
     (_FUN_00147e60 < param_2)) {
    TeamFortress_SpyChangeSkin__11CBasePlayeri(param_1,(int)ROUND(param_2));
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x184) = 0;
  }
  return;
}


// Menu_Spy_Skin__11CBasePlayer  @ 000b87a0
void Menu_Spy_Skin__11CBasePlayer(undefined4 param_1)

{
  MenuPrint__FP11CBasePlayerPCcii
            (param_1,
             "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
             ,0xffff,0xffffffff);
  return;
}


// Menu_Spy__11CBasePlayer  @ 000b84ec
void Menu_Spy__11CBasePlayer(int *param_1)

{
  char *pcVar1;
  
  if (((*(byte *)(*param_1 + 0x118) & 5) != 0) || (param_1[0x1d] == 1)) {
    ResetMenu__11CBasePlayer(param_1);
    return;
  }
  if (param_1[0x1c] == 0) {
    if (param_1[0x75] != 0) {
      if (param_1[0x76] != 0) {
        pcVar1 = (char *)FUN_00147bc0;
        goto LAB_000b85ed;
      }
      if (param_1[0x75] != 0) {
        pcVar1 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
        ;
        goto LAB_000b85ed;
      }
    }
    if (param_1[0x76] == 0) {
      pcVar1 = (char *)FUN_00147d40;
    }
    else {
      pcVar1 = 
      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
      ;
    }
    goto LAB_000b85ed;
  }
  if (param_1[0x75] != 0) {
    if (param_1[0x76] != 0) {
      pcVar1 = 
      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
      ;
      goto LAB_000b85ed;
    }
    if (param_1[0x75] != 0) {
      pcVar1 = (char *)FUN_00147a60;
      goto LAB_000b85ed;
    }
  }
  if (param_1[0x76] == 0) {
    pcVar1 = 
    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n";
  }
  else {
    pcVar1 = 
    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
    ;
  }
LAB_000b85ed:
  MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar1,0xffff,0xffffffff);
  return;
}


// Menu_Team__11CBasePlayer  @ 000b80a8
void Menu_Team__11CBasePlayer(void)

{
  FUN_000b80b2();
  return;
}


