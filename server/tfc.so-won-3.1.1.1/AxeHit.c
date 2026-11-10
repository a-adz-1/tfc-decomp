// AxeHit__10CTFMedikitP11CBaseEntityG6VectorP11TraceResult  @ 0012b760
undefined4
AxeHit__10CTFMedikitP11CBaseEntityG6VectorP11TraceResult
          (undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined2 in_FPUControlWord;
  char *local_98;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int iStack_10;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  iVar3 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"player");
  if ((iVar3 != 0) ||
     (fVar1 = *(float *)(*param_2 + 0x160),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
    return 0;
  }
  iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1[0x11d],param_2);
  if (iVar3 == 0) {
    ClearMultiDamage__Fv();
    local_1c = *param_3;
    local_18 = param_3[1];
    local_14 = param_3[2];
    (**(code **)(param_2[0x115] + 0x34))
              (param_2,*(undefined4 *)param_1[0x11d],0x41200000,&local_1c,param_4,0x80);
    ApplyMultiDamage__FP9entvars_sT0(*(undefined4 *)param_1[0x11d],*(undefined4 *)param_1[0x11d]);
    if ((param_2[0x21] & 0x10U) != 0) {
      return 1;
    }
    if (*(int *)(*param_2 + 0x20c) == 5) {
      return 1;
    }
    fVar1 = *gpGlobals;
    if ((byte)(fVar1 < cb_prematch_time |
               (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) == 1) {
      return 1;
    }
    param_2[0x21] = param_2[0x21] | 0x10;
    if (*(int *)(*param_2 + 0x170) != 0) {
      return 1;
    }
    piVar4 = (int *)CreateTimer__11CBaseEntityi(param_2,2);
    *(float *)(*piVar4 + 0x104) = *gpGlobals + 2.0;
    piVar4[3] = -0x10000;
    piVar4[4] = (int)Timer_Infection__11CBaseEntity;
    *(undefined4 *)(*piVar4 + 400) = *(undefined4 *)(*(int *)param_1[0x11d] + 0x208);
    param_2[0x4a] = *(int *)(param_1[0x11d] + 0x120);
    if (param_2[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
    }
    uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
    uVar6 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar6);
    piVar4 = (int *)param_1[0x11d];
    if (piVar4[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(piVar4[0x48],
                                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      piVar4 = (int *)param_1[0x11d];
    }
    uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208),pcVar5);
    uVar6 = (*DAT_0019f864)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),uVar6);
    iVar3 = *(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26];
    pcVar5 = "\"%s<%i><%s><%s>\" triggered \"Medic_Infection\" against \"%s<%i><%s><%s>\"\n";
  }
  else {
    piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,1);
    if (piVar4 != (int *)0x0) {
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_cureconc",*(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26]
                 ,*(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      piVar7 = (int *)param_1[0x11d];
      if (piVar7[0x48] == 0) {
        local_98 = "SPECTATOR";
      }
      else {
        local_98 = (char *)GetTeamName__Fi(piVar7[0x48],
                                           *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
        piVar7 = (int *)param_1[0x11d];
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar7 + 0x208),local_98);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Concussion\" against \"%s<%i><%s><%s>\"\n"
                 ,*(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if (piVar4[0x48] != *(int *)(param_1[0x11d] + 0x120)) {
        TF_AddFrags__11CBasePlayeri(param_1[0x11d],1);
      }
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)SUB_Remove__11CBaseEntity;
    }
    if ((*(byte *)((int)param_2 + 0x85) & 0x40) != 0) {
      piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,3);
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_curehalluc",
                 *(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],
                 *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      piVar7 = (int *)param_1[0x11d];
      if (piVar7[0x48] == 0) {
        local_98 = "SPECTATOR";
      }
      else {
        local_98 = (char *)GetTeamName__Fi(piVar7[0x48],
                                           *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
        piVar7 = (int *)param_1[0x11d];
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar7 + 0x208),local_98);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Hallucinations\" against \"%s<%i><%s><%s>\"\n"
                 ,*(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if (piVar4[0x48] != *(int *)(param_1[0x11d] + 0x120)) {
        TF_AddFrags__11CBasePlayeri(param_1[0x11d],1);
      }
      *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) & 0xbf;
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)SUB_Remove__11CBaseEntity;
    }
    if ((short)param_2[0x21] < 0) {
      piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,4);
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_curetranq",
                 *(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],
                 *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      piVar7 = (int *)param_1[0x11d];
      if (piVar7[0x48] == 0) {
        local_98 = "SPECTATOR";
      }
      else {
        local_98 = (char *)GetTeamName__Fi(piVar7[0x48],
                                           *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
        piVar7 = (int *)param_1[0x11d];
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar7 + 0x208),local_98);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Tranquilisation\" against \"%s<%i><%s><%s>\"\n"
                 ,*(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if (piVar4[0x48] != *(int *)(param_1[0x11d] + 0x120)) {
        TF_AddFrags__11CBasePlayeri(param_1[0x11d],1);
      }
      *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) & 0x7f;
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)SUB_Remove__11CBaseEntity;
    }
    if ((*(byte *)(param_2 + 0x21) & 0x10) != 0) {
      iVar3 = *param_2;
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      iStack_10 = (int)ROUND(*(float *)(iVar3 + 0x160) * 0.5);
      fVar1 = (float)iStack_10;
      local_1c = *(undefined4 *)(*param_2 + 8);
      local_18 = *(undefined4 *)(iVar3 + 0xc);
      local_14 = *(undefined4 *)(iVar3 + 0x10);
      uVar6 = (**(code **)(param_2[0x115] + 0x44))(param_2,fVar1);
      SpawnBlood__FG6Vectorif(&local_1c,uVar6);
      piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,2);
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_cureinfection",
                 *(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],
                 *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      piVar7 = (int *)param_1[0x11d];
      if (piVar7[0x48] == 0) {
        local_98 = "SPECTATOR";
      }
      else {
        local_98 = (char *)GetTeamName__Fi(piVar7[0x48],
                                           *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
        piVar7 = (int *)param_1[0x11d];
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar7 + 0x208),local_98);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Infection\" against \"%s<%i><%s><%s>\"\n"
                 ,*(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if (piVar4[0x48] != *(int *)(param_1[0x11d] + 0x120)) {
        TF_AddFrags__11CBasePlayeri(param_1[0x11d],1);
      }
      iVar3 = *(int *)(*piVar4 + 0x198);
      if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
        puVar8 = (undefined4 *)0x0;
      }
      else {
        puVar8 = *(undefined4 **)(iVar3 + 0x7c);
      }
      (**(code **)(param_2[0x115] + 0x38))(param_2,*param_1,*puVar8,fVar1,0x8010000);
      *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xef;
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)SUB_Remove__11CBaseEntity;
    }
    if (0.0 < (float)param_2[0x72]) {
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_curefire",*(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26]
                 ,*(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      piVar4 = (int *)param_1[0x11d];
      if (piVar4[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(piVar4[0x48],
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
        piVar4 = (int *)param_1[0x11d];
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208),pcVar5);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Medic_Doused_Fire\" against \"%s<%i><%s><%s>\"\n",
                 *(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      param_2[0x72] = 0;
      (*DAT_0019f88c)(0,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),
                      *(undefined2 *)(param_1 + 0x156),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    }
    fVar1 = *(float *)(*param_2 + 0x160);
    fVar2 = *(float *)(*param_2 + 0x1b0);
    if ((byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      fVar2 = fVar2 + 50.0;
      if ((byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
        return 1;
      }
      (*DAT_0019f88c)(0,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),
                      *(undefined2 *)((int)param_1 + 0x556),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
      (**(code **)(param_2[0x115] + 0x3c))(param_2,0x40a00000,0x1000000);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      piVar4 = (int *)param_1[0x11d];
      if (piVar4[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(piVar4[0x48],
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
        piVar4 = (int *)param_1[0x11d];
      }
      uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208),pcVar5);
      uVar6 = (*DAT_0019f864)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%s><%s>\"\n",
                 *(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if ((param_2[0x22] & 0x10000U) != 0) {
        return 1;
      }
      param_2[0x22] = param_2[0x22] | 0x10000;
      piVar4 = (int *)CreateTimer__11CBaseEntityi(param_2,5);
      *(float *)(*piVar4 + 0x104) = *gpGlobals + 5.0;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)Timer_HealthRot__11CBaseEntity;
      return 1;
    }
    (*DAT_0019f88c)(0,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),
                    *(undefined2 *)(param_1 + 0x155),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    (**(code **)(param_2[0x115] + 0x3c))(param_2,0x43480000,0);
    if (param_2[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
    }
    uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
    uVar6 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar6);
    piVar4 = (int *)param_1[0x11d];
    if (piVar4[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(piVar4[0x48],
                                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      piVar4 = (int *)param_1[0x11d];
    }
    uVar6 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208),pcVar5);
    uVar6 = (*DAT_0019f864)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),uVar6);
    iVar3 = *(int *)(*(int *)param_1[0x11d] + 0x1d0) + (int)gpGlobals[0x26];
    pcVar5 = "\"%s<%i><%s><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%s><%s>\"\n";
  }
  UTIL_LogPrintf__FPce(pcVar5,iVar3,uVar6);
  return 1;
}


// AxeHit__10CTFSpannerP11CBaseEntityG6VectorP11TraceResult  @ 0012ce40
undefined4
AxeHit__10CTFSpannerP11CBaseEntityG6VectorP11TraceResult
          (int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((*(byte *)(param_2 + 0x228) & 8) == 0) {
    iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(*(undefined4 *)(param_1 + 0x474),param_2);
    if (iVar1 == 0) {
      ClearMultiDamage__Fv();
      local_10 = *param_3;
      local_c = param_3[1];
      local_8 = param_3[2];
      (**(code **)(*(int *)(param_2 + 0x454) + 0x34))
                (param_2,**(undefined4 **)(param_1 + 0x474),0x41a00000,&local_10,param_4,0x80);
      ApplyMultiDamage__FP9entvars_sT0
                (**(undefined4 **)(param_1 + 0x474),**(undefined4 **)(param_1 + 0x474));
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_2 + 0x454) + 0xe8))
                        (param_2,*(undefined4 *)(param_1 + 0x474));
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x408) = 1;
    (**(code **)(*(int *)(param_2 + 0x454) + 0xb8))
              (param_2,*(undefined4 *)(param_1 + 0x474),*(undefined4 *)(param_1 + 0x474),3,
               0x41000000);
    *(undefined4 *)(param_2 + 0x408) = 0;
  }
  return 1;
}


// AxeHit__6CTFAxeP11CBaseEntityG6VectorP11TraceResult  @ 0012b494
undefined4
AxeHit__6CTFAxeP11CBaseEntityG6VectorP11TraceResult
          (int param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  ClearMultiDamage__Fv();
  if (*(int *)(**(int **)(param_1 + 0x474) + 0x20c) == 8) {
    iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar1 == 0) {
      UTIL_MakeVectors__FRC6Vector(*param_2 + 0x74);
      local_10 = *(float *)(gpGlobals + 0x40);
      local_c = *(float *)(gpGlobals + 0x44);
      local_8 = *(undefined4 *)(gpGlobals + 0x48);
      UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
      if (local_10 * *(float *)(gpGlobals + 0x2c) - *(float *)(gpGlobals + 0x28) * local_c <= 0.0) {
        local_1c = *param_3;
        local_18 = param_3[1];
        local_14 = param_3[2];
        iVar1 = param_2[0x115];
        uVar3 = 0x80;
        uVar2 = 0x42200000;
      }
      else if (*(int *)(param_1 + 0x548) == 0) {
        local_1c = *param_3;
        local_18 = param_3[1];
        local_14 = param_3[2];
        iVar1 = param_2[0x115];
        uVar3 = 0x8000080;
        uVar2 = 0x42700000;
      }
      else {
        local_1c = *param_3;
        local_18 = param_3[1];
        local_14 = param_3[2];
        iVar1 = param_2[0x115];
        uVar3 = 0x8000080;
        uVar2 = 0x42f00000;
      }
      goto LAB_0012b63b;
    }
  }
  local_1c = *param_3;
  local_18 = param_3[1];
  local_14 = param_3[2];
  iVar1 = param_2[0x115];
  uVar3 = 0x80;
  uVar2 = 0x41a00000;
LAB_0012b63b:
  (**(code **)(iVar1 + 0x34))
            (param_2,**(undefined4 **)(param_1 + 0x474),uVar2,&local_1c,param_4,uVar3);
  ApplyMultiDamage__FP9entvars_sT0
            (**(undefined4 **)(param_1 + 0x474),**(undefined4 **)(param_1 + 0x474));
  return 1;
}


