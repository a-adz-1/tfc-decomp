// AxeHit__10CTFMedikitP11CBaseEntityG6VectorP11TraceResult  @ 00127d7c
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
  int iVar7;
  undefined4 *puVar8;
  undefined2 in_FPUControlWord;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  iVar3 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"player");
  if ((iVar3 != 0) ||
     (fVar1 = *(float *)(*param_2 + 0x160),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
    return 0;
  }
  iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1[0x119],param_2);
  if (iVar3 == 0) {
    ClearMultiDamage__Fv();
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    (**(code **)(param_2[0x111] + 0x34))
              (param_2,*(undefined4 *)param_1[0x119],0x41200000,&local_18,param_4,0x80);
    ApplyMultiDamage__FP9entvars_sT0(*(undefined4 *)param_1[0x119],*(undefined4 *)param_1[0x119]);
    if ((*(byte *)(param_2 + 0x21) & 0x10) != 0) {
      return 1;
    }
    if (*(int *)(*param_2 + 0x20c) == 5) {
      return 1;
    }
    if (*gpGlobals < cb_prematch_time) {
      return 1;
    }
    *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 0x10;
    piVar4 = (int *)CreateTimer__11CBaseEntityi(param_2,2);
    *(float *)(*piVar4 + 0x104) = *gpGlobals + 2.0;
    piVar4[3] = -0x10000;
    piVar4[4] = (int)Timer_Infection__11CBaseEntity;
    *(undefined4 *)(*piVar4 + 400) = *(undefined4 *)(*(int *)param_1[0x119] + 0x208);
    param_2[0x4a] = *(int *)(param_1[0x119] + 0x120);
    if (param_2[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
    }
    uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
    uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar6);
    if (*(int *)(param_1[0x119] + 0x120) == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(param_1[0x119] + 0x120),
                                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
    }
    uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),pcVar5);
    uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),uVar6);
    iVar3 = *(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26];
    pcVar5 = "\"%s<%i><%u><%s>\" triggered \"Medic_Infection\" against \"%s<%i><%u><%s>\"\n";
  }
  else {
    piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,1);
    if (piVar4 != (int *)0x0) {
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_cureconc",*(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26]
                 ,*(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      if (*(int *)(param_1[0x119] + 0x120) == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(param_1[0x119] + 0x120),
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" triggered \"Medic_Cured_Concussion\" against \"%s<%i><%u><%s>\"\n"
                 ,*(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if (piVar4[0x48] != *(int *)(param_1[0x119] + 0x120)) {
        TF_AddFrags__11CBasePlayeri(param_1[0x119],1);
      }
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)SUB_Remove__11CBaseEntity;
    }
    if ((*(byte *)((int)param_2 + 0x85) & 0x40) != 0) {
      piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,3);
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_curehalluc",
                 *(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],
                 *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      if (*(int *)(param_1[0x119] + 0x120) == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(param_1[0x119] + 0x120),
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" triggered \"Medic_Cured_Hallucinations\" against \"%s<%i><%u><%s>\"\n"
                 ,*(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if (piVar4[0x48] != *(int *)(param_1[0x119] + 0x120)) {
        TF_AddFrags__11CBasePlayeri(param_1[0x119],1);
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
                 *(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],
                 *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      if (*(int *)(param_1[0x119] + 0x120) == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(param_1[0x119] + 0x120),
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" triggered \"Medic_Cured_Tranquilisation\" against \"%s<%i><%u><%s>\"\n"
                 ,*(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if (piVar4[0x48] != *(int *)(param_1[0x119] + 0x120)) {
        TF_AddFrags__11CBasePlayeri(param_1[0x119],1);
      }
      *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) & 0x7f;
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)SUB_Remove__11CBaseEntity;
    }
    if ((*(byte *)(param_2 + 0x21) & 0x10) != 0) {
      iVar7 = *param_2;
      _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
      local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      iVar3 = (int)ROUND(*(float *)(iVar7 + 0x160) * 0.5);
      local_18 = *(undefined4 *)(*param_2 + 8);
      local_14 = *(undefined4 *)(iVar7 + 0xc);
      local_10 = *(undefined4 *)(iVar7 + 0x10);
      uVar6 = (**(code **)(param_2[0x111] + 0x44))(param_2,(float)iVar3);
      SpawnBlood__FG6Vectorif(&local_18,uVar6);
      piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,2);
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_cureinfection",
                 *(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],
                 *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      if (*(int *)(param_1[0x119] + 0x120) == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(param_1[0x119] + 0x120),
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" triggered \"Medic_Cured_Infection\" against \"%s<%i><%u><%s>\"\n"
                 ,*(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if (piVar4[0x48] != *(int *)(param_1[0x119] + 0x120)) {
        TF_AddFrags__11CBasePlayeri(param_1[0x119],1);
      }
      iVar7 = *(int *)(*piVar4 + 0x198);
      if ((iVar7 == 0) && (iVar7 = (*DAT_001c1134)(0), iVar7 == 0)) {
        puVar8 = (undefined4 *)0x0;
      }
      else {
        puVar8 = *(undefined4 **)(iVar7 + 0x7c);
      }
      (**(code **)(param_2[0x111] + 0x38))(param_2,*param_1,*puVar8,(float)iVar3,0x8010000);
      *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xef;
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)SUB_Remove__11CBaseEntity;
    }
    if (0.0 < (float)param_2[0x72]) {
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Medic_curefire",*(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26]
                 ,*(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      if (*(int *)(param_1[0x119] + 0x120) == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(param_1[0x119] + 0x120),
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" triggered \"Medic_Doused_Fire\" against \"%s<%i><%u><%s>\"\n",
                 *(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      param_2[0x72] = 0;
      (*DAT_001c120c)(0,*(undefined4 *)(*(int *)param_1[0x119] + 0x208),
                      *(undefined2 *)(param_1 + 0x152),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    }
    if (*(float *)(*param_2 + 0x1b0) <= *(float *)(*param_2 + 0x160)) {
      fVar2 = *(float *)(*param_2 + 0x1b0) + 50.0;
      fVar1 = *(float *)(*param_2 + 0x160);
      if ((byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
        return 1;
      }
      (*DAT_001c120c)(0,*(undefined4 *)(*(int *)param_1[0x119] + 0x208),
                      *(undefined2 *)((int)param_1 + 0x546),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
      (**(code **)(param_2[0x111] + 0x3c))(param_2,0x40a00000,0x1000000);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar6);
      if (*(int *)(param_1[0x119] + 0x120) == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(param_1[0x119] + 0x120),
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      }
      uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),pcVar5);
      uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),uVar6);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%u><%s>\"\n",
                 *(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26],uVar6);
      if ((*(byte *)((int)param_2 + 0x8a) & 1) != 0) {
        return 1;
      }
      *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 1;
      piVar4 = (int *)CreateTimer__11CBaseEntityi(param_2,5);
      *(float *)(*piVar4 + 0x104) = *gpGlobals + 5.0;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)Timer_HealthRot__11CBaseEntity;
      return 1;
    }
    (*DAT_001c120c)(0,*(undefined4 *)(*(int *)param_1[0x119] + 0x208),
                    *(undefined2 *)(param_1 + 0x151),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    (**(code **)(param_2[0x111] + 0x3c))(param_2,0x43480000,0);
    if (param_2[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
    }
    uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
    uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar6);
    if (*(int *)(param_1[0x119] + 0x120) == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(param_1[0x119] + 0x120),
                                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar6);
    }
    uVar6 = (*DAT_001c11f4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),pcVar5);
    uVar6 = (*DAT_001c11e4)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208),uVar6);
    iVar3 = *(int *)(*(int *)param_1[0x119] + 0x1d0) + (int)gpGlobals[0x26];
    pcVar5 = "\"%s<%i><%u><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%u><%s>\"\n";
  }
  UTIL_LogPrintf__FPce(pcVar5,iVar3,uVar6);
  return 1;
}


// AxeHit__10CTFSpannerP11CBaseEntityG6VectorP11TraceResult  @ 001276f0
undefined4
AxeHit__10CTFSpannerP11CBaseEntityG6VectorP11TraceResult
          (int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(byte *)(param_2 + 0x228) & 8) == 0) {
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(*(undefined4 *)(param_1 + 0x464),param_2);
    if (iVar2 == 0) {
      ClearMultiDamage__Fv();
      local_c = *param_3;
      local_8 = param_3[1];
      local_4 = param_3[2];
      (**(code **)(*(int *)(param_2 + 0x444) + 0x34))
                (param_2,**(undefined4 **)(param_1 + 0x464),0x41a00000,&local_c,param_4,0x80);
      ApplyMultiDamage__FP9entvars_sT0
                (**(undefined4 **)(param_1 + 0x464),**(undefined4 **)(param_1 + 0x464));
      uVar1 = 1;
    }
    else {
      iVar2 = (**(code **)(*(int *)(param_2 + 0x444) + 0xe8))
                        (param_2,*(undefined4 *)(param_1 + 0x464));
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x3f8) = 1;
    (**(code **)(*(int *)(param_2 + 0x444) + 0xb8))
              (param_2,*(undefined4 *)(param_1 + 0x464),*(undefined4 *)(param_1 + 0x464),3,
               0x41000000);
    *(undefined4 *)(param_2 + 0x3f8) = 0;
    uVar1 = 1;
  }
  return uVar1;
}


// AxeHit__6CTFAxeP11CBaseEntityG6VectorP11TraceResult  @ 00127318
undefined4
AxeHit__6CTFAxeP11CBaseEntityG6VectorP11TraceResult
          (int param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  ClearMultiDamage__Fv();
  if (*(int *)(**(int **)(param_1 + 0x464) + 0x20c) == 8) {
    iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar1 != 0) goto LAB_00127504;
    UTIL_MakeVectors__FRC6Vector(*param_2 + 0x74);
    local_c = *(float *)(gpGlobals + 0x40);
    local_8 = *(float *)(gpGlobals + 0x44);
    local_4 = *(undefined4 *)(gpGlobals + 0x48);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x464) + 0x74);
    if (local_c * *(float *)(gpGlobals + 0x2c) - *(float *)(gpGlobals + 0x28) * local_8 <= 0.0) {
      local_18 = *param_3;
      local_14 = param_3[1];
      local_10 = param_3[2];
      iVar1 = param_2[0x111];
      uVar4 = 0x80;
      uVar3 = 0x42200000;
      puVar2 = *(undefined4 **)(param_1 + 0x464);
LAB_001274ea:
      (**(code **)(iVar1 + 0x34))(param_2,*puVar2,uVar3,&local_18,param_4,uVar4);
      goto LAB_0012755d;
    }
    if (*(int *)(param_1 + 0x538) == 0) {
      local_18 = *param_3;
      local_14 = param_3[1];
      local_10 = param_3[2];
      iVar1 = param_2[0x111];
      uVar4 = 0x8000080;
      uVar3 = 0x42700000;
      puVar2 = *(undefined4 **)(param_1 + 0x464);
      goto LAB_001274ea;
    }
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    iVar1 = param_2[0x111];
    uVar4 = 0x8000080;
    uVar3 = 0x42f00000;
    puVar2 = *(undefined4 **)(param_1 + 0x464);
  }
  else {
LAB_00127504:
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    iVar1 = param_2[0x111];
    uVar4 = 0x80;
    uVar3 = 0x41a00000;
    puVar2 = *(undefined4 **)(param_1 + 0x464);
  }
  (**(code **)(iVar1 + 0x34))(param_2,*puVar2,uVar3,&local_18,param_4,uVar4);
LAB_0012755d:
  ApplyMultiDamage__FP9entvars_sT0
            (**(undefined4 **)(param_1 + 0x464),**(undefined4 **)(param_1 + 0x464));
  return 1;
}


