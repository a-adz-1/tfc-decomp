// Menu_ClassHelp_Input__11CBasePlayerf  @ 000bf150
void Menu_ClassHelp_Input__11CBasePlayerf(int *param_1)

{
  ResetMenu__11CBasePlayer(param_1);
  if (param_1[0x261] != 1) {
    (**(code **)(*g_pGameRules + 0xdc))(g_pGameRules,*(undefined4 *)(*param_1 + 0x1e8));
    param_1[0x261] = 1;
  }
  return;
}


// Menu_ClassHelp__11CBasePlayer  @ 000bf030
void Menu_ClassHelp__11CBasePlayer(int param_1)

{
  char *pcVar1;
  
  if (*(int *)(param_1 + 0x2c) == 1) {
    pcVar1 = "#Help_scout";
  }
  else if (*(int *)(param_1 + 0x2c) == 2) {
    pcVar1 = "#Help_sniper";
  }
  else if (*(int *)(param_1 + 0x2c) == 3) {
    pcVar1 = "#Help_soldier";
  }
  else if (*(int *)(param_1 + 0x2c) == 4) {
    pcVar1 = "#Help_demoman";
  }
  else if (*(int *)(param_1 + 0x2c) == 5) {
    pcVar1 = "#Help_medic";
  }
  else if (*(int *)(param_1 + 0x2c) == 6) {
    pcVar1 = "#Help_hwguy";
  }
  else if (*(int *)(param_1 + 0x2c) == 7) {
    pcVar1 = "#Help_pyro";
  }
  else if (*(int *)(param_1 + 0x2c) == 8) {
    pcVar1 = "#Help_spy";
  }
  else {
    if (*(int *)(param_1 + 0x2c) != 9) {
      return;
    }
    pcVar1 = "#Help_engineer";
  }
  MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar1,0xffff,0xffffffff);
  return;
}


// Menu_Class_Input__11CBasePlayerf  @ 000bec50
/* WARNING: Removing unreachable block (ram,0x000bece7) */
/* WARNING: Removing unreachable block (ram,0x000becf0) */

void Menu_Class_Input__11CBasePlayerf(int *param_1,float param_2)

{
  if (((byte)(10.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 10.0) << 0xe) >> 8)) != 1) && (1.0 <= param_2)) {
    *(int *)(*param_1 + 0x164) = (int)ROUND(param_2 + 100.0);
    ChangeClass__11CBasePlayeri(param_1,(int)ROUND(param_2));
    ResetMenu__11CBasePlayer(param_1);
    param_1[0x47] = 0;
    param_1[0x46] = 0;
    *(undefined4 *)(*param_1 + 0x164) = 0;
  }
  return;
}


// Menu_Class__11CBasePlayer  @ 000beac0
void Menu_Class__11CBasePlayer(int param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  
  iVar1 = TeamFortress_TeamIsCivilian__Ff((float)*(int *)(param_1 + 0x120));
  if (iVar1 != 0) {
    ChangeClass__11CBasePlayeri(param_1,0xb);
    return;
  }
  piVar2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,FUN_00134a90);
  if (piVar2 == (int *)0x0) {
LAB_000bebd0:
    iVar1 = TeamFortress_TeamIsCivilian__Ff((float)*(int *)(param_1 + 0x120));
    if (iVar1 == 0) {
      if ((byte)((byte)((ushort)((ushort)NAN(spy_off) << 10) >> 8) |
                (byte)((ushort)((ushort)(spy_off == 1.0) << 0xe) >> 8)) == 0x40) {
        pcVar3 = 
        "#Menu_class \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n9. #Engineer \n0. #RandomPC \n"
        ;
      }
      else {
        pcVar3 = 
        "#Menu_class \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n0. #RandomPC \n"
        ;
      }
    }
    else {
      pcVar3 = "#Menu_onlycivs";
    }
  }
  else {
    if (*(int *)(param_1 + 0x120) == 1) {
      if (*(int *)(*piVar2 + 0x1cc) == 0) goto LAB_000bebd0;
      iVar1 = *(int *)(*piVar2 + 0x1cc);
    }
    else if (*(int *)(param_1 + 0x120) == 2) {
      if (*(int *)(*piVar2 + 0x1d0) == 0) goto LAB_000bebd0;
      iVar1 = *(int *)(*piVar2 + 0x1d0);
    }
    else if (*(int *)(param_1 + 0x120) == 3) {
      if (*(int *)(*piVar2 + 0x1d4) == 0) goto LAB_000bebd0;
      iVar1 = *(int *)(*piVar2 + 0x1d4);
    }
    else {
      if ((*(int *)(param_1 + 0x120) != 4) || (piVar2[0xc9] == 0)) goto LAB_000bebd0;
      iVar1 = piVar2[0xc9];
    }
    pcVar3 = (char *)(iVar1 + *(int *)(gpGlobals + 0x98));
  }
  MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar3,0xffff,0xffffffff);
  return;
}


// Menu_Dispenser_Input__11CBasePlayerf  @ 000c0830
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Menu_Dispenser_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  float local_1c;
  float fStack_18;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
  if (iVar2 == 0) {
    ResetMenu__11CBasePlayer(param_1);
    return;
  }
  local_1c = 0.0;
  if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) {
    piVar4 = param_1 + 0x4e;
    iVar2 = __rf__7EHANDLE(piVar4);
    if ((((*(int *)(iVar2 + 0xcc) != 0) ||
         (iVar2 = __rf__7EHANDLE(piVar4), *(int *)(iVar2 + 0xd4) != 0)) ||
        (iVar2 = __rf__7EHANDLE(piVar4), *(int *)(iVar2 + 0xe4) != 0)) ||
       (iVar2 = __rf__7EHANDLE(piVar4), *(int *)(iVar2 + 0xdc) != 0)) {
      fStack_18 = (float)(param_1[0x30] - param_1[0x33]);
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      if ((float)*(int *)(iVar2 + 0xcc) < fStack_18) {
        iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
        fStack_18 = (float)*(int *)(iVar2 + 0xcc);
      }
      piVar4 = param_1 + 0x4e;
      iVar2 = __rf__7EHANDLE(piVar4);
      iVar3 = __rf__7EHANDLE(piVar4);
      *(int *)(iVar2 + 0xcc) = (int)ROUND((float)*(int *)(iVar3 + 0xcc) - fStack_18);
      param_1[0x33] = (int)ROUND(fStack_18 + (float)param_1[0x33]);
      fStack_18 = (float)(param_1[0x34] - param_1[0x35]);
      iVar2 = __rf__7EHANDLE(piVar4);
      if ((float)*(int *)(iVar2 + 0xd4) < fStack_18) {
        iVar2 = __rf__7EHANDLE(piVar4);
        fStack_18 = (float)*(int *)(iVar2 + 0xd4);
      }
      piVar4 = param_1 + 0x4e;
      iVar2 = __rf__7EHANDLE(piVar4);
      iVar3 = __rf__7EHANDLE(piVar4);
      *(int *)(iVar2 + 0xd4) = (int)ROUND((float)*(int *)(iVar3 + 0xd4) - fStack_18);
      param_1[0x35] = (int)ROUND(fStack_18 + (float)param_1[0x35]);
      fStack_18 = (float)(param_1[0x38] - param_1[0x39]);
      iVar2 = __rf__7EHANDLE(piVar4);
      if ((float)*(int *)(iVar2 + 0xe4) < fStack_18) {
        iVar2 = __rf__7EHANDLE(piVar4);
        fStack_18 = (float)*(int *)(iVar2 + 0xe4);
      }
      piVar4 = param_1 + 0x4e;
      iVar2 = __rf__7EHANDLE(piVar4);
      iVar3 = __rf__7EHANDLE(piVar4);
      *(int *)(iVar2 + 0xe4) = (int)ROUND((float)*(int *)(iVar3 + 0xe4) - fStack_18);
      param_1[0x39] = (int)ROUND(fStack_18 + (float)param_1[0x39]);
      fStack_18 = (float)(param_1[0x36] - param_1[0x37]);
      iVar2 = __rf__7EHANDLE(piVar4);
      if ((float)*(int *)(iVar2 + 0xdc) < fStack_18) {
        iVar2 = __rf__7EHANDLE(piVar4);
        fStack_18 = (float)*(int *)(iVar2 + 0xdc);
      }
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      iVar3 = __rf__7EHANDLE(param_1 + 0x4e);
      *(int *)(iVar2 + 0xdc) = (int)ROUND((float)*(int *)(iVar3 + 0xdc) - fStack_18);
      param_1[0x37] = (int)ROUND(fStack_18 + (float)param_1[0x37]);
      goto LAB_000c0c4a;
    }
  }
  else {
    if ((byte)((byte)((ushort)((ushort)(NAN(param_2) || NAN(_FUN_001356e0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == _FUN_001356e0) << 0xe) >> 8)) != 0x40)
    goto LAB_000c0c4a;
    piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*piVar4 + 0x19c)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(*piVar4 + 0x19c) == 0.0) << 0xe) >> 8)) != 0x40) {
      fStack_18 = (float)param_1[0x3c] - *(float *)(*param_1 + 0x19c);
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      if (*(float *)(*piVar4 + 0x19c) < fStack_18) {
        piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
        fStack_18 = *(float *)(*piVar4 + 0x19c);
      }
      fVar1 = *(float *)(*param_1 + 0x198);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        *(undefined4 *)(*param_1 + 0x198) = 0x3e99999a;
        *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) | 0x20;
      }
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      *(float *)(*piVar4 + 0x19c) = *(float *)(*piVar5 + 0x19c) - fStack_18;
      *(float *)(*param_1 + 0x19c) = fStack_18 + *(float *)(*param_1 + 0x19c);
      goto LAB_000c0c4a;
    }
  }
  local_1c = 1.0;
LAB_000c0c4a:
  if (((byte)((1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) - 1) < 0x40) &&
     (param_2 <= 3.0)) {
    if ((byte)(local_1c < 0.0 | (byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) != 0x40) {
      ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Dispenser_empty",0,0,0,0);
    }
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x164) = 0;
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
    param_1[0x50] = (int)(*gpGlobals + 0.5);
    fVar1 = *(float *)(*param_1 + 0x19c);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x198) = 0;
      param_1[0xf] = 0;
      param_1[0x23] = param_1[0x23] - (param_1[0x23] & 0xe000U);
    }
  }
  return;
}


// Menu_Dispenser__11CBasePlayer  @ 000c0810
void Menu_Dispenser__11CBasePlayer(undefined4 param_1)

{
  MenuPrint__FP11CBasePlayerPCcii(param_1,"#Menu_Dispenser",0xffff,0xffffffff);
  return;
}


// Menu_EngineerFix_Dispenser_Input__11CBasePlayerf  @ 000bf830
void Menu_EngineerFix_Dispenser_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  float local_18;
  float fStack_14;
  
  iVar2 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"player");
  if ((iVar2 == 0) && (iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e), iVar2 != 0)) {
    if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) {
      local_18 = 40.0;
      fVar1 = (float)param_1[0x33];
      if ((byte)(fVar1 < 40.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 40.0) << 0xe) >> 8)) == 1) {
        local_18 = fVar1;
      }
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      if ((float)(400 - *(int *)(iVar2 + 0xcc)) < local_18) {
        iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
        local_18 = (float)(400 - *(int *)(iVar2 + 0xcc));
      }
      param_1[0x33] = (int)ROUND((float)param_1[0x33] - local_18);
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      iVar3 = __rf__7EHANDLE(param_1 + 0x4e);
      *(int *)(iVar2 + 0xcc) = (int)ROUND(local_18 + (float)*(int *)(iVar3 + 0xcc));
      local_18 = 40.0;
      fVar1 = (float)param_1[0x35];
      if ((byte)(fVar1 < 40.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 40.0) << 0xe) >> 8)) == 1) {
        local_18 = fVar1;
      }
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      if ((float)(600 - *(int *)(iVar2 + 0xd4)) < local_18) {
        iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
        local_18 = (float)(600 - *(int *)(iVar2 + 0xd4));
      }
      param_1[0x35] = (int)ROUND((float)param_1[0x35] - local_18);
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      iVar3 = __rf__7EHANDLE(param_1 + 0x4e);
      *(int *)(iVar2 + 0xd4) = (int)ROUND(local_18 + (float)*(int *)(iVar3 + 0xd4));
      local_18 = 20.0;
      fVar1 = (float)param_1[0x39];
      if ((byte)(fVar1 < 20.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 20.0) << 0xe) >> 8)) == 1) {
        local_18 = fVar1;
      }
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      if ((float)(300 - *(int *)(iVar2 + 0xe4)) < local_18) {
        iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
        local_18 = (float)(300 - *(int *)(iVar2 + 0xe4));
      }
      param_1[0x39] = (int)ROUND((float)param_1[0x39] - local_18);
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      iVar3 = __rf__7EHANDLE(param_1 + 0x4e);
      *(int *)(iVar2 + 0xe4) = (int)ROUND(local_18 + (float)*(int *)(iVar3 + 0xe4));
      local_18 = 20.0;
      fVar1 = (float)param_1[0x37];
      if ((byte)(fVar1 < 20.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 20.0) << 0xe) >> 8)) == 1) {
        local_18 = fVar1;
      }
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      if ((float)(400 - *(int *)(iVar2 + 0xdc)) < local_18) {
        iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
        local_18 = (float)(400 - *(int *)(iVar2 + 0xdc));
      }
      param_1[0x37] = (int)ROUND((float)param_1[0x37] - local_18);
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      iVar3 = __rf__7EHANDLE(param_1 + 0x4e);
      *(int *)(iVar2 + 0xdc) = (int)ROUND(local_18 + (float)*(int *)(iVar3 + 0xdc));
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) == 0x40) {
      local_18 = 80.0;
      if (*(float *)(*param_1 + 0x19c) < 80.0) {
        local_18 = *(float *)(*param_1 + 0x19c);
      }
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      fVar1 = 500.0 - *(float *)(*piVar4 + 0x19c);
      if ((byte)(fVar1 < local_18 |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_18)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == local_18) << 0xe) >> 8)) == 1) {
        piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
        local_18 = 500.0 - *(float *)(*piVar4 + 0x19c);
      }
      *(float *)(*param_1 + 0x19c) = *(float *)(*param_1 + 0x19c) - local_18;
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      *(float *)(*piVar4 + 0x19c) = local_18 + *(float *)(*piVar5 + 0x19c);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) {
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      fStack_14 = (*(float *)(*piVar4 + 400) - *(float *)(*piVar5 + 0x140)) / 5.0;
      fVar1 = (float)param_1[0x37];
      if ((byte)(fVar1 < fStack_14 |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fStack_14)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fStack_14) << 0xe) >> 8)) == 1) {
        fStack_14 = fVar1;
      }
      param_1[0x37] = (int)ROUND((float)param_1[0x37] - fStack_14);
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
      *(float *)(*piVar4 + 0x140) = fStack_14 * 5.0 + *(float *)(*piVar5 + 0x140);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
      ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Dispenser_dismantle",0,0,0,0);
      param_1[0x37] = param_1[0x37] + 0x32;
      TeamFortress_CheckClassStats__11CBasePlayer(param_1);
      piVar4 = param_1 + 0x4e;
      iVar2 = __rf__7EHANDLE(piVar4);
      piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
      if (piVar5 != param_1) {
        iVar2 = __rf__7EHANDLE(piVar4,1,"#Dispenser_otherdismantled",
                               *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),0,0,0);
        puVar6 = (undefined4 *)__rf__7EHANDLE(iVar2 + 0x144);
        ClientPrint__FP9entvars_tiPCcN42(*puVar6);
        iVar2 = __rf__7EHANDLE(piVar4,0);
        piVar5 = (int *)__rf__7EHANDLE(iVar2 + 0x144);
        iVar2 = __rf__7EHANDLE(piVar4,1,"#Dispenser_otherdismantledhis",
                               *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),
                               *(int *)(*piVar5 + 0x1b0) + *(int *)(gpGlobals + 0x98));
        uVar7 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
        iVar2 = __rf__7EHANDLE(piVar4,uVar7);
        iVar2 = __rf__7EHANDLE(iVar2 + 0x144);
        teamsprint__FiP11CBaseEntityiPCcN33(*(undefined4 *)(iVar2 + 0x120));
      }
      iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
      iVar2 = __rf__7EHANDLE(iVar2 + 0x144);
      *(undefined4 *)(iVar2 + 0x14c) = 0;
      uVar7 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
      dremove__FP11CBaseEntity(uVar7);
    }
    if (((byte)((1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) - 1) < 0x40) &&
       (param_2 <= 5.0)) {
      ResetMenu__11CBasePlayer(param_1);
      *(undefined4 *)(*param_1 + 0x164) = 0;
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
      fVar1 = *(float *)(*param_1 + 0x19c);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        *(undefined4 *)(*param_1 + 0x198) = 0;
        param_1[0xf] = 0;
        param_1[0x23] = param_1[0x23] - (param_1[0x23] & 0xe000U);
      }
    }
  }
  return;
}


// Menu_EngineerFix_Dispenser__11CBasePlayer  @ 000bf810
void Menu_EngineerFix_Dispenser__11CBasePlayer(undefined4 param_1)

{
  MenuPrint__FP11CBasePlayerPCcii(param_1,FUN_001353a0,0xffff,0xffffffff);
  return;
}


// Menu_EngineerFix_Mortar_Input__11CBasePlayerf  @ 000c0790
void Menu_EngineerFix_Mortar_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  
  if (((byte)((1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) - 1) < 0x40) &&
     (param_2 <= 5.0)) {
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x164) = 0;
    fVar1 = *(float *)(*param_1 + 0x19c);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x198) = 0;
      param_1[0xf] = 0;
      param_1[0x23] = param_1[0x23] - (param_1[0x23] & 0xe000U);
    }
  }
  return;
}


// Menu_EngineerFix_Mortar__11CBasePlayer  @ 000c0780
void Menu_EngineerFix_Mortar__11CBasePlayer(void)

{
  return;
}


// Menu_EngineerFix_SentryGun_Input__11CBasePlayerf  @ 000bff80
void Menu_EngineerFix_SentryGun_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  longdouble lVar8;
  code *pcVar9;
  float fStack_18;
  float fStack_14;
  
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
          fStack_14 = 40.0;
          fVar1 = (float)param_1[0x33];
          if ((byte)(fVar1 < 40.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 40.0) << 0xe) >> 8)) == 1) {
            fStack_14 = fVar1;
          }
          piVar5 = param_1 + 0x4e;
          iVar2 = __rf__7EHANDLE(piVar5);
          iVar3 = __rf__7EHANDLE(piVar5);
          if ((float)(*(int *)(iVar2 + 0xc0) - *(int *)(iVar3 + 0xcc)) < fStack_14) {
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar3 = __rf__7EHANDLE(piVar5);
            fStack_14 = (float)(*(int *)(iVar2 + 0xc0) - *(int *)(iVar3 + 0xcc));
          }
          param_1[0x33] = (int)ROUND((float)param_1[0x33] - fStack_14);
          piVar5 = param_1 + 0x4e;
          iVar2 = __rf__7EHANDLE(piVar5);
          iVar3 = __rf__7EHANDLE(piVar5);
          *(int *)(iVar2 + 0xcc) = (int)ROUND(fStack_14 + (float)*(int *)(iVar3 + 0xcc));
          iVar2 = __rf__7EHANDLE(piVar5);
          if (*(int *)(iVar2 + 0x90) == 3) {
            fStack_14 = 20.0;
            fVar1 = (float)param_1[0x39];
            if ((byte)(fVar1 < 20.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 20.0) << 0xe) >> 8)) == 1) {
              fStack_14 = fVar1;
            }
            piVar5 = param_1 + 0x4e;
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar3 = __rf__7EHANDLE(piVar5);
            if ((float)(*(int *)(iVar2 + 0xe0) - *(int *)(iVar3 + 0xe4)) < fStack_14) {
              iVar2 = __rf__7EHANDLE(piVar5);
              iVar3 = __rf__7EHANDLE(piVar5);
              fStack_14 = (float)(*(int *)(iVar2 + 0xe0) - *(int *)(iVar3 + 0xe4));
            }
            param_1[0x39] = (int)ROUND((float)param_1[0x39] - fStack_14);
            iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
            iVar3 = __rf__7EHANDLE(param_1 + 0x4e);
            *(int *)(iVar2 + 0xe4) = (int)ROUND(fStack_14 + (float)*(int *)(iVar3 + 0xe4));
          }
        }
        else {
          piVar5 = param_1 + 0x4e;
          iVar2 = __rf__7EHANDLE(piVar5);
          if (((*(int *)(iVar2 + 0x90) < 3) &&
              ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) == 0x40)) &&
             (0x81 < param_1[0x37])) {
            param_1[0x37] = param_1[0x37] + -0x82;
            uVar4 = __opP11CBaseEntity__7EHANDLE(piVar5);
            Upgrade__12CTFSentrygun(uVar4);
            iVar2 = __rf__7EHANDLE(piVar5,0,0,0);
            uVar4 = UTIL_dtos1__Fi(*(undefined4 *)(iVar2 + 0x90));
            ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Sentry_upgrade",uVar4);
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) {
            piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
            piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
            fStack_18 = (*(float *)(*piVar5 + 400) - *(float *)(*piVar6 + 0x140)) / 5.0;
            fVar1 = (float)param_1[0x37];
            if ((byte)(fVar1 < fStack_18 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fStack_18)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fStack_18) << 0xe) >> 8)) == 1) {
              fStack_18 = fVar1;
            }
            param_1[0x37] = (int)ROUND((float)param_1[0x37] - fStack_18);
            piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
            piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x4e);
            *(float *)(*piVar5 + 0x140) = fStack_18 * 5.0 + *(float *)(*piVar6 + 0x140);
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
            ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Sentry_dismantle",0,0,0,0);
            param_1[0x37] = param_1[0x37] + 0x41;
            TeamFortress_CheckClassStats__11CBasePlayer(param_1);
            piVar5 = param_1 + 0x4e;
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar2 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
            if (iVar2 != 0) {
              iVar2 = __rf__7EHANDLE(piVar5);
              piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
              if (piVar6 != param_1) {
                iVar2 = __rf__7EHANDLE(piVar5,1,"#Sentry_otherdismantled",
                                       *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),0,0,0
                                      );
                puVar7 = (undefined4 *)__rf__7EHANDLE(iVar2 + 0x144);
                ClientPrint__FP9entvars_tiPCcN42(*puVar7);
                iVar2 = __rf__7EHANDLE(piVar5,0);
                piVar6 = (int *)__rf__7EHANDLE(iVar2 + 0x144);
                iVar2 = __rf__7EHANDLE(piVar5,1,"#Sentry_otherdismantledhis",
                                       *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),
                                       *(int *)(*piVar6 + 0x1b0) + *(int *)(gpGlobals + 0x98));
                uVar4 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
                iVar2 = __rf__7EHANDLE(piVar5,uVar4);
                iVar2 = __rf__7EHANDLE(iVar2 + 0x144);
                teamsprint__FiP11CBaseEntityiPCcN33(*(undefined4 *)(iVar2 + 0x120));
                iVar2 = __rf__7EHANDLE(piVar5);
                uVar4 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
                iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,uVar4);
                if (iVar2 == 0) {
                  iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
                  piVar5 = (int *)__rf__7EHANDLE(iVar2 + 0x144);
                  uVar4 = (*DAT_00175684)(*(undefined4 *)(*piVar5 + 0x1e8));
                  iVar2 = __rf__7EHANDLE(param_1 + 0x4e,uVar4);
                  piVar5 = (int *)__rf__7EHANDLE(iVar2 + 0x144);
                  uVar4 = (*DAT_00175684)(*(undefined4 *)(*param_1 + 0x1e8),
                                          *(int *)(*piVar5 + 0x1b0) + *(int *)(gpGlobals + 0x98));
                  iVar2 = *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98);
                  pcVar9 = (code *)"\"%s<%i>\" dismantled \"%s<%i>\"\'s \"sentrygun\".\n";
                }
                else {
                  iVar2 = __rf__7EHANDLE(piVar5);
                  piVar6 = (int *)__rf__7EHANDLE(iVar2 + 0x144);
                  uVar4 = (*DAT_00175684)(*(undefined4 *)(*piVar6 + 0x1e8));
                  iVar2 = __rf__7EHANDLE(piVar5,uVar4);
                  piVar5 = (int *)__rf__7EHANDLE(iVar2 + 0x144);
                  uVar4 = (*DAT_00175684)(*(undefined4 *)(*param_1 + 0x1e8),
                                          *(int *)(*piVar5 + 0x1b0) + *(int *)(gpGlobals + 0x98));
                  iVar2 = *(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98);
                  pcVar9 = FUN_00135620;
                }
                UTIL_LogPrintf__FPce(pcVar9,iVar2,uVar4);
              }
              iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
              iVar2 = __rf__7EHANDLE(iVar2 + 0x144);
              *(undefined4 *)(iVar2 + 0x150) = 0;
            }
            iVar2 = __rf__7EHANDLE(param_1 + 0x4e);
            uVar4 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x98);
            dremove__FP11CBaseEntity(uVar4);
            uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4e);
            dremove__FP11CBaseEntity(uVar4);
          }
          else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                         (byte)((ushort)((ushort)(param_2 == 6.0) << 0xe) >> 8)) == 0x40) {
            ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Sentry_rotate",0,0,0,0);
            piVar5 = param_1 + 0x4e;
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar3 = __rf__7EHANDLE(piVar5);
            lVar8 = (longdouble)anglemod__Ff((float)(*(int *)(iVar3 + 0xa0) + 0x2d));
            *(int *)(iVar2 + 0xa0) = (int)ROUND(lVar8);
            iVar2 = __rf__7EHANDLE(piVar5);
            iVar3 = __rf__7EHANDLE(piVar5);
            lVar8 = (longdouble)anglemod__Ff((float)(*(int *)(iVar3 + 0xa4) + 0x2d));
            *(int *)(iVar2 + 0xa4) = (int)ROUND(lVar8);
          }
        }
        if (0x3f < (byte)((1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) - 1)) {
          return;
        }
        if (6.0 < param_2) {
          return;
        }
        ResetMenu__11CBasePlayer(param_1);
        *(undefined4 *)(*param_1 + 0x164) = 0;
        __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
        fVar1 = *(float *)(*param_1 + 0x19c);
        if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          return;
        }
        *(undefined4 *)(*param_1 + 0x198) = 0;
        param_1[0xf] = 0;
        param_1[0x23] = param_1[0x23] - (param_1[0x23] & 0xe000U);
        return;
      }
    }
    ResetMenu__11CBasePlayer(param_1);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x4e,0);
  }
  return;
}


// Menu_EngineerFix_SentryGun__11CBasePlayer  @ 000bff20
void Menu_EngineerFix_SentryGun__11CBasePlayer(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = __rf__7EHANDLE(param_1 + 0x138);
  if ((*(int *)(iVar1 + 0x90) < 3) && (0x81 < *(int *)(param_1 + 0xdc))) {
    pcVar2 = FUN_001354a0;
  }
  else {
    pcVar2 = (code *)
             "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
    ;
  }
  MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar2,0xffff,0xffffffff);
  return;
}


// Menu_Engineer_Input__11CBasePlayerf  @ 000bf6e0
void Menu_Engineer_Input__11CBasePlayerf(int *param_1,float param_2)

{
  float fVar1;
  int **ppiVar2;
  int *piStack_10;
  char *pcStack_c;
  
  ppiVar2 = (int **)&stack0xfffffff8;
  if ((((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) &&
      (99 < param_1[0x37])) &&
     (fVar1 = (float)param_1[0x53],
     (byte)(fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) {
    pcStack_c = (char *)0x1;
  }
  else {
    if ((((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) != 0x40) ||
        (param_1[0x37] < 0x82)) ||
       (fVar1 = (float)param_1[0x54],
       (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40)) {
      if (((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 7.0) << 0xe) >> 8)) == 0x40) &&
         ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x53]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)param_1[0x53] == 1.0) << 0xe) >> 8)) == 0x40)) {
        pcStack_c = "building_dispenser";
      }
      else {
        if (((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 8.0) << 0xe) >> 8)) != 0x40) ||
           ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x54]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0x54] == 1.0) << 0xe) >> 8)) != 0x40)) {
          if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) != 0x40) {
            return;
          }
          goto LAB_000bf7f2;
        }
        pcStack_c = "building_sentrygun";
      }
      ppiVar2 = &piStack_10;
      piStack_10 = param_1;
      DestroyBuilding__FP11CBaseEntityPc();
      goto LAB_000bf7f2;
    }
    pcStack_c = (char *)0x2;
  }
  ppiVar2 = &piStack_10;
  piStack_10 = param_1;
  TeamFortress_Build__11CBasePlayeri();
LAB_000bf7f2:
  *(int **)((int)ppiVar2 + -4) = param_1;
  *(undefined4 *)((int)ppiVar2 + -8) = 0xbf7f8;
  ResetMenu__11CBasePlayer();
  *(undefined4 *)(*param_1 + 0x164) = 0;
  return;
}


// Menu_Engineer__11CBasePlayer  @ 000bf640
void Menu_Engineer__11CBasePlayer(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = "7. #Menu_DetDisp \n";
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x14c)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x14c) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (pcVar2 = "\n", 99 < *(int *)(param_1 + 0xdc))) {
    pcVar2 = "1. #Menu_BuildDisp \n";
  }
  pcVar1 = "8. #Menu_DetSentry \n";
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x150)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x150) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (pcVar1 = "\n", 0x81 < *(int *)(param_1 + 0xdc))) {
    pcVar1 = "2. #Menu_BuildSentry \n";
  }
  sprintf(cbuf,"%s%s%s%s","#Action \n",pcVar2,pcVar1,"5. #Nothing \n\n");
  MenuPrint__FP11CBasePlayerPCcii(param_1,cbuf,0xffff,0xffffffff);
  return;
}


// Menu_Input__11CBasePlayerf  @ 000bed50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Menu_Input__11CBasePlayerf(int param_1,undefined4 param_2)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x114);
  if (((byte)(2.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) == 0x40) ||
     ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 21.0) << 0xe) >> 8)) == 0x40)) {
    Menu_Team_Input__11CBasePlayerf(param_1,param_2);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 4.0) << 0xe) >> 8)) == 0x40
          ) {
    Menu_MapBriefing_Input__11CBasePlayerf(param_1,param_2);
  }
  else {
    fVar1 = *(float *)(param_1 + 0x114);
    if (((byte)(3.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 3.0) << 0xe) >> 8)) == 0x40) ||
       ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 20.0) << 0xe) >> 8)) == 0x40)) {
      Menu_Class_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 12.0) << 0xe) >> 8)) ==
             0x40) {
      Menu_Spy_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 13.0) << 0xe) >> 8)) ==
             0x40) {
      Menu_Spy_Skin_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 14.0) << 0xe) >> 8)) ==
             0x40) {
      Menu_Spy_Color_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 15.0) << 0xe) >> 8)) ==
             0x40) {
      Menu_Engineer_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 16.0) << 0xe) >> 8)) ==
             0x40) {
      Menu_EngineerFix_Dispenser_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 18.0) << 0xe) >> 8)) ==
             0x40) {
      Menu_EngineerFix_Mortar_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)(NAN(_FUN_00134c10) || NAN(*(float *)(param_1 + 0x114)))
                                   << 10) >> 8) |
                   (byte)((ushort)((ushort)(_FUN_00134c10 == *(float *)(param_1 + 0x114)) << 0xe) >>
                         8)) == 0x40) {
      Menu_EngineerFix_SentryGun_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 19.0) << 0xe) >> 8)) ==
             0x40) {
      Menu_Dispenser_Input__11CBasePlayerf(param_1,param_2);
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x114)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(*(float *)(param_1 + 0x114) == 6.0) << 0xe) >> 8)) ==
             0x40) {
      Menu_ClassHelp_Input__11CBasePlayerf(param_1,param_2);
    }
  }
  return;
}


// Menu_Intro__11CBasePlayer  @ 000befc0
void Menu_Intro__11CBasePlayer(undefined4 param_1)

{
  char *pcVar1;
  char **ppcVar2;
  undefined1 *puStackY_30;
  undefined4 uStackY_2c;
  undefined4 uStackY_28;
  char *pcStack_18;
  undefined4 uStack_14;
  char *pcStack_10;
  
  pcStack_10 = "motd1";
  uStack_14 = 0;
  pcStack_18 = (char *)0xbefd4;
  pcVar1 = (char *)infokey__FP11CBasePlayerPCc();
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    pcStack_10 = (char *)0xffffffff;
    uStack_14 = 0xffff;
    ppcVar2 = &pcStack_18;
    pcStack_18 = 
    "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
    ;
  }
  else {
    pcStack_10 = "motd2";
    uStack_14 = 0;
    pcStack_18 = "PSh(L\x13";
    pcStack_18 = (char *)infokey__FP11CBasePlayerPCc();
    uStackY_28 = 0xbefff;
    sprintf(cbuf,"%s\n%s");
    uStackY_28 = 0xffffffff;
    uStackY_2c = 0xffff;
    ppcVar2 = &puStackY_30;
    puStackY_30 = cbuf;
  }
  *(undefined4 *)((int)ppcVar2 + -4) = param_1;
  *(undefined4 *)((int)ppcVar2 + -8) = 0xbf022;
  MenuPrint__FP11CBasePlayerPCcii();
  return;
}


// Menu_MapBriefing_Input__11CBasePlayerf  @ 000be8c0
void Menu_MapBriefing_Input__11CBasePlayerf(undefined4 param_1)

{
  EndMapBriefing__11CBasePlayer(param_1);
  return;
}


// Menu_MapBriefing__11CBasePlayer  @ 000be880
void Menu_MapBriefing__11CBasePlayer(undefined4 param_1)

{
  if (g_szMapBriefingText == '\0') {
    EndMapBriefing__11CBasePlayer(param_1);
  }
  else {
    MenuPrint__FP11CBasePlayerPCcii(param_1,&g_szMapBriefingText,0xffff,0xffffffff);
  }
  return;
}


// Menu_RepeatHelp__11CBasePlayer  @ 000bed30
void Menu_RepeatHelp__11CBasePlayer(undefined4 param_1)

{
  MenuPrint__FP11CBasePlayerPCcii(param_1,"#Menu_repeathelp",0xffff,0xffffffff);
  return;
}


// Menu_Spy_Color_Input__11CBasePlayerf  @ 000bf5d0
void Menu_Spy_Color_Input__11CBasePlayerf(int *param_1,float param_2)

{
  if (((byte)((1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) - 1) < 0x40) &&
     ((byte)((param_2 < number_of_teams |
              (byte)((ushort)((ushort)(NAN(param_2) || NAN(number_of_teams)) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40)) {
    TeamFortress_SpyChangeColor__11CBasePlayeri(param_1,(int)ROUND(param_2));
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x164) = 0;
  }
  return;
}


// Menu_Spy_Color__11CBasePlayer  @ 000bf4d0
void Menu_Spy_Color__11CBasePlayer(int *param_1)

{
  char *pcVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
            (byte)((ushort)((ushort)(number_of_teams == 0.0) << 0xe) >> 8)) == 0x40) {
    ClientPrint__FP9entvars_tiPCcN42(*param_1,1,FUN_001351a0,0,0,0,0);
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x164) = 0;
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


// Menu_Spy_Input__11CBasePlayerf  @ 000bf2d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Menu_Spy_Input__11CBasePlayerf(int *param_1,float param_2)

{
  int **ppiVar1;
  int aiStack_24 [2];
  char *pcStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int *piStack_10;
  int *piStack_c;
  
  if (((byte)(1.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) ||
     ((byte)((byte)((ushort)((ushort)(NAN(_FUN_00135110) || NAN(param_2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_FUN_00135110 == param_2) << 0xe) >> 8)) == 0x40)) {
    if ((*(byte *)(*param_1 + 0xf8) & 5) == 0) {
      if (param_1[0x1e] != 1) goto LAB_000bf360;
      piStack_c = (int *)0x0;
      piStack_10 = (int *)0x0;
      uStack_14 = 0;
      uStack_18 = 0;
      pcStack_1c = "#Spy_unable";
      aiStack_24[1] = 1;
      aiStack_24[0] = *param_1;
      ClientPrint__FP9entvars_tiPCcN42();
      ppiVar1 = (int **)aiStack_24;
    }
    else {
      piStack_c = (int *)0x0;
      piStack_10 = (int *)0x0;
      uStack_14 = 0;
      uStack_18 = 0;
      pcStack_1c = "#Spy_glowing";
      aiStack_24[1] = 1;
      aiStack_24[0] = *param_1;
      ClientPrint__FP9entvars_tiPCcN42();
      ppiVar1 = (int **)aiStack_24;
    }
  }
  else {
LAB_000bf360:
    if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 1.0) << 0xe) >> 8)) == 0x40) {
      piStack_c = param_1;
      piStack_10 = (int *)0xbf376;
      Menu_Spy_Skin__11CBasePlayer();
      param_1[0x45] = 0x41500000;
      param_1[0x46] = 0;
      goto LAB_000bf42a;
    }
    if ((byte)((byte)((ushort)((ushort)(NAN(_FUN_00135110) || NAN(param_2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(_FUN_00135110 == param_2) << 0xe) >> 8)) == 0x40) {
      piStack_c = param_1;
      piStack_10 = (int *)0xbf3aa;
      Menu_Spy_Color__11CBasePlayer();
      param_1[0x45] = 0x41600000;
      param_1[0x46] = 0;
      goto LAB_000bf42a;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) {
      piStack_c = (int *)0x0;
      piStack_10 = param_1;
      uStack_14 = 0xbf3dc;
      TeamFortress_SpyFeignDeath__11CBasePlayeri();
      ppiVar1 = &piStack_10;
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                   (byte)((ushort)((ushort)(param_2 == 4.0) << 0xe) >> 8)) == 0x40) {
      piStack_c = param_1;
      piStack_10 = (int *)0xbf3fa;
      Spy_RemoveDisguise__11CBasePlayer();
      ppiVar1 = &piStack_c;
    }
    else {
      if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) != 0x40) {
        return;
      }
      ppiVar1 = (int **)&stack0xfffffff8;
      if ((param_1[0x75] == 0) && (ppiVar1 = (int **)&stack0xfffffff8, param_1[0x76] == 0)) {
        return;
      }
    }
  }
  *(int **)((int)ppiVar1 + -4) = param_1;
  *(undefined4 *)((int)ppiVar1 + -8) = 0xbf42a;
  ResetMenu__11CBasePlayer();
LAB_000bf42a:
  *(undefined4 *)(*param_1 + 0x164) = 0;
  return;
}


// Menu_Spy_Skin_Input__11CBasePlayerf  @ 000bf460
void Menu_Spy_Skin_Input__11CBasePlayerf(int *param_1,float param_2)

{
  if ((param_2 < 10.0) &&
     ((byte)(0.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) == 1)) {
    TeamFortress_SpyChangeSkin__11CBasePlayeri(param_1,(int)ROUND(param_2));
    ResetMenu__11CBasePlayer(param_1);
    *(undefined4 *)(*param_1 + 0x164) = 0;
  }
  return;
}


// Menu_Spy_Skin__11CBasePlayer  @ 000bf440
void Menu_Spy_Skin__11CBasePlayer(undefined4 param_1)

{
  MenuPrint__FP11CBasePlayerPCcii
            (param_1,
             "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
             ,0xffff,0xffffffff);
  return;
}


// Menu_Spy__11CBasePlayer  @ 000bf1a0
void Menu_Spy__11CBasePlayer(int *param_1)

{
  char *pcVar1;
  
  if (((*(byte *)(*param_1 + 0xf8) & 5) != 0) || (param_1[0x1e] == 1)) {
    ResetMenu__11CBasePlayer(param_1);
    return;
  }
  if (param_1[0x1d] == 0) {
    if (param_1[0x75] != 0) {
      if (param_1[0x76] != 0) {
        pcVar1 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
        ;
        goto LAB_000bf2bc;
      }
      if (param_1[0x75] != 0) {
        pcVar1 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
        ;
        goto LAB_000bf2bc;
      }
    }
    if (param_1[0x76] == 0) {
      pcVar1 = 
      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n";
    }
    else {
      pcVar1 = 
      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
      ;
    }
    goto LAB_000bf2bc;
  }
  if (param_1[0x75] != 0) {
    if (param_1[0x76] != 0) {
      pcVar1 = 
      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
      ;
      goto LAB_000bf2bc;
    }
    if (param_1[0x75] != 0) {
      pcVar1 = (char *)FUN_00134dc0;
      goto LAB_000bf2bc;
    }
  }
  if (param_1[0x76] == 0) {
    pcVar1 = 
    "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n";
  }
  else {
    pcVar1 = (char *)FUN_00134e40;
  }
LAB_000bf2bc:
  MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar1,0xffff,0xffffffff);
  return;
}


// Menu_Team_Input__11CBasePlayerf  @ 000bea00
void Menu_Team_Input__11CBasePlayerf(int *param_1,float param_2)

{
  if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 5.0) << 0xe) >> 8)) == 0x40) {
    TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1);
  }
  else if ((((byte)((param_2 < number_of_teams |
                     (byte)((ushort)((ushort)(NAN(param_2) || NAN(number_of_teams)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40)
           && ((byte)(0.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) == 1)) ||
          (((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                  (byte)((ushort)((ushort)(number_of_teams == 0.0) << 0xe) >> 8)) == 0x40 &&
           (param_2 <= 4.0)))) {
    TeamFortress_TeamSet__11CBasePlayeri(param_1,(int)ROUND(param_2));
  }
  ResetMenu__11CBasePlayer(param_1);
  *(undefined4 *)(*param_1 + 0x164) = 0;
  return;
}


// Menu_Team__11CBasePlayer  @ 000be8d0
void Menu_Team__11CBasePlayer(undefined4 param_1)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  
  fVar1 = *gpGlobals;
  if (((((byte)(30.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 30.0) << 0xe) >> 8)) == 1) &&
       ((byte)(0.0 < (float)tfc_autoteam._12_4_ |
               (byte)((ushort)((ushort)NAN((float)tfc_autoteam._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_autoteam._12_4_ == 0.0) << 0xe) >> 8)) != 0x40))
      && (iVar2 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules), iVar2 != 0)) &&
     (iVar2 = TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1), iVar2 != 0)) {
    return;
  }
  if (team_menu_string == 0) {
    if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
              (byte)((ushort)((ushort)(number_of_teams == 1.0) << 0xe) >> 8)) == 0x40) {
      pcVar3 = "#Menu_chooseteam \n1. #BlueTeam ";
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                   (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) == 0x40) {
      pcVar3 = "#Menu_chooseteam \n1. #BlueTeam \n2. #RedTeam \n\n\n5. #AutoTeam ";
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                   (byte)((ushort)((ushort)(number_of_teams == 3.0) << 0xe) >> 8)) == 0x40) {
      pcVar3 = "#Menu_chooseteam \n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n5. #AutoTeam ";
    }
    else {
      pcVar3 = 
      "#Menu_chooseteam \n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n5. #AutoTeam "
      ;
    }
  }
  else {
    pcVar3 = (char *)(team_menu_string + (int)gpGlobals[0x26]);
  }
  MenuPrint__FP11CBasePlayerPCcii(param_1,pcVar3,0xffff,0xffffffff);
  return;
}


