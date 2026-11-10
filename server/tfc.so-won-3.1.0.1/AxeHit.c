// AxeHit__10CTFMedikitP11CBaseEntityG6VectorP11TraceResult  @ 00117f94
undefined4
AxeHit__10CTFMedikitP11CBaseEntityG6VectorP11TraceResult
          (undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined2 in_FPUControlWord;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  iVar3 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"player");
  if (iVar3 == 0) {
    iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1[0xfd],param_2);
    if (iVar3 == 0) {
      ClearMultiDamage__Fv();
      uStack_18 = *param_3;
      uStack_14 = param_3[1];
      uStack_10 = param_3[2];
      (**(code **)(param_2[0xf5] + 0x30))
                (param_2,*(undefined4 *)param_1[0xfd],0x41200000,&uStack_18,param_4,0x80);
      ApplyMultiDamage__FP9entvars_sT0(*(undefined4 *)param_1[0xfd],*(undefined4 *)param_1[0xfd]);
      if ((((*(byte *)(param_2 + 0x21) & 0x10) == 0) && (*(int *)(*param_2 + 0x20c) != 5)) &&
         (cb_prematch_time <= *gpGlobals)) {
        *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 0x10;
        piVar4 = (int *)CreateTimer__11CBaseEntityi(param_2,2);
        *(float *)(*piVar4 + 0x104) = *gpGlobals + 2.0;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)Timer_Infection__11CBaseEntity;
        *(undefined4 *)(*piVar4 + 400) = *(undefined4 *)(*(int *)param_1[0xfd] + 0x208);
        param_2[0x4a] = *(int *)(param_1[0xfd] + 0x120);
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                                *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" infected \"%s<%i>\".\n",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],uVar5);
      }
    }
    else {
      piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,1);
      if (piVar4 != (int *)0x0) {
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_cureconc",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                                *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" cured \"%s<%i>\"\'s \"concussion\".\n",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        if (piVar4[0x48] != *(int *)(param_1[0xfd] + 0x120)) {
          TF_AddFrags__11CBasePlayeri(param_1[0xfd],1);
        }
        *(float *)(*piVar4 + 0x104) = *gpGlobals;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)SUB_Remove__11CBaseEntity;
      }
      if ((*(byte *)((int)param_2 + 0x85) & 0x40) != 0) {
        piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,3);
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_curehalluc",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                                *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" cured \"%s<%i>\"\'s \"hallucinations\".\n",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        if (piVar4[0x48] != *(int *)(param_1[0xfd] + 0x120)) {
          TF_AddFrags__11CBasePlayeri(param_1[0xfd],1);
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
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                                *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" cured \"%s<%i>\"\'s \"tranquilisation\".\n",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        if (piVar4[0x48] != *(int *)(param_1[0xfd] + 0x120)) {
          TF_AddFrags__11CBasePlayeri(param_1[0xfd],1);
        }
        *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) & 0x7f;
        TeamFortress_SetSpeed__11CBasePlayer(param_2);
        *(float *)(*piVar4 + 0x104) = *gpGlobals;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)SUB_Remove__11CBaseEntity;
      }
      if ((*(byte *)(param_2 + 0x21) & 0x10) != 0) {
        iVar6 = *param_2;
        _uStack_4 = CONCAT22(uStack_2,in_FPUControlWord);
        uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
        iVar3 = (int)ROUND(*(float *)(iVar6 + 0x160) * 0.5);
        uStack_18 = *(undefined4 *)(*param_2 + 8);
        uStack_14 = *(undefined4 *)(iVar6 + 0xc);
        uStack_10 = *(undefined4 *)(iVar6 + 0x10);
        uVar5 = (**(code **)(param_2[0xf5] + 0x40))(param_2,(float)iVar3);
        SpawnBlood__FG6Vectorif(&uStack_18,uVar5);
        piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,2);
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_cureinfection",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                                *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" cured \"%s<%i>\"\'s \"infection\".\n",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        if (piVar4[0x48] != *(int *)(param_1[0xfd] + 0x120)) {
          TF_AddFrags__11CBasePlayeri(param_1[0xfd],1);
        }
        iVar6 = *(int *)(*piVar4 + 0x198);
        if ((iVar6 == 0) && (iVar6 = (*DAT_001a7f54)(0), iVar6 == 0)) {
          puVar7 = (undefined4 *)0x0;
        }
        else {
          puVar7 = *(undefined4 **)(iVar6 + 0x7c);
        }
        (**(code **)(param_2[0xf5] + 0x34))(param_2,*param_1,*puVar7,(float)iVar3,0x8010000);
        *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xef;
        *(float *)(*piVar4 + 0x104) = *gpGlobals;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)SUB_Remove__11CBaseEntity;
      }
      if (0.0 < (float)param_2[0x72]) {
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_curefire",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
        uVar5 = (*DAT_001a8004)(*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                                *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" doused \"%s<%i>\"\'s \"fire\".\n",
                   *(int *)(*(int *)param_1[0xfd] + 0x1d0) + (int)gpGlobals[0x26],uVar5);
        param_2[0x72] = 0;
        (*DAT_001a802c)(0,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                        *(undefined2 *)(param_1 + 0x136),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
      }
      if (*(float *)(*param_2 + 0x1b0) <= *(float *)(*param_2 + 0x160)) {
        fVar2 = *(float *)(*param_2 + 0x1b0) + 50.0;
        fVar1 = *(float *)(*param_2 + 0x160);
        if (0x3f < (byte)((fVar2 < fVar1 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
          (*DAT_001a802c)(0,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                          *(undefined2 *)((int)param_1 + 0x4d6),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0)
          ;
          (**(code **)(param_2[0xf5] + 0x38))(param_2,0x40a00000,0x1000000);
          if ((*(byte *)((int)param_2 + 0x8a) & 1) == 0) {
            *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 1;
            piVar4 = (int *)CreateTimer__11CBaseEntityi(param_2,5);
            *(float *)(*piVar4 + 0x104) = *gpGlobals + 5.0;
            piVar4[3] = -0x10000;
            piVar4[4] = (int)Timer_HealthRot__11CBaseEntity;
          }
        }
      }
      else {
        (*DAT_001a802c)(0,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),
                        *(undefined2 *)(param_1 + 0x135),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
        (**(code **)(param_2[0xf5] + 0x38))(param_2,0x43480000,0);
      }
    }
    return 1;
  }
  return 0;
}


// AxeHit__10CTFSpannerP11CBaseEntityG6VectorP11TraceResult  @ 0011792c
undefined4
AxeHit__10CTFSpannerP11CBaseEntityG6VectorP11TraceResult
          (int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(byte *)(param_2 + 0x220) & 8) == 0) {
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(*(undefined4 *)(param_1 + 0x3f4),param_2);
    if (iVar2 == 0) {
      ClearMultiDamage__Fv();
      local_c = *param_3;
      local_8 = param_3[1];
      local_4 = param_3[2];
      (**(code **)(*(int *)(param_2 + 0x3d4) + 0x30))
                (param_2,**(undefined4 **)(param_1 + 0x3f4),0x41a00000,&local_c,param_4,0x80);
      ApplyMultiDamage__FP9entvars_sT0
                (**(undefined4 **)(param_1 + 0x3f4),**(undefined4 **)(param_1 + 0x3f4));
      uVar1 = 1;
    }
    else {
      iVar2 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0xe0))
                        (param_2,*(undefined4 *)(param_1 + 0x3f4));
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x388) = 1;
    (**(code **)(*(int *)(param_2 + 0x3d4) + 0xb0))
              (param_2,*(undefined4 *)(param_1 + 0x3f4),*(undefined4 *)(param_1 + 0x3f4),3,
               0x41000000);
    *(undefined4 *)(param_2 + 0x388) = 0;
    uVar1 = 1;
  }
  return uVar1;
}


// AxeHit__6CTFAxeP11CBaseEntityG6VectorP11TraceResult  @ 00117564
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
  if (*(int *)(**(int **)(param_1 + 0x3f4) + 0x20c) == 8) {
    iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar1 != 0) goto LAB_00117750;
    UTIL_MakeVectors__FRC6Vector(*param_2 + 0x74);
    local_c = *(float *)(gpGlobals + 0x40);
    local_8 = *(float *)(gpGlobals + 0x44);
    local_4 = *(undefined4 *)(gpGlobals + 0x48);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    if (local_c * *(float *)(gpGlobals + 0x2c) - *(float *)(gpGlobals + 0x28) * local_8 <= 0.0) {
      local_18 = *param_3;
      local_14 = param_3[1];
      local_10 = param_3[2];
      iVar1 = param_2[0xf5];
      uVar4 = 0x80;
      uVar3 = 0x42200000;
      puVar2 = *(undefined4 **)(param_1 + 0x3f4);
LAB_00117736:
      (**(code **)(iVar1 + 0x30))(param_2,*puVar2,uVar3,&local_18,param_4,uVar4);
      goto LAB_001177a9;
    }
    if (*(int *)(param_1 + 0x4c8) == 0) {
      local_18 = *param_3;
      local_14 = param_3[1];
      local_10 = param_3[2];
      iVar1 = param_2[0xf5];
      uVar4 = 0x8000080;
      uVar3 = 0x42700000;
      puVar2 = *(undefined4 **)(param_1 + 0x3f4);
      goto LAB_00117736;
    }
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    iVar1 = param_2[0xf5];
    uVar4 = 0x8000080;
    uVar3 = 0x42f00000;
    puVar2 = *(undefined4 **)(param_1 + 0x3f4);
  }
  else {
LAB_00117750:
    local_18 = *param_3;
    local_14 = param_3[1];
    local_10 = param_3[2];
    iVar1 = param_2[0xf5];
    uVar4 = 0x80;
    uVar3 = 0x41a00000;
    puVar2 = *(undefined4 **)(param_1 + 0x3f4);
  }
  (**(code **)(iVar1 + 0x30))(param_2,*puVar2,uVar3,&local_18,param_4,uVar4);
LAB_001177a9:
  ApplyMultiDamage__FP9entvars_sT0
            (**(undefined4 **)(param_1 + 0x3f4),**(undefined4 **)(param_1 + 0x3f4));
  return 1;
}


