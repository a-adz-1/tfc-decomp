// AxeHit__10CTFMedikitP11CBaseEntityG6VectorP11TraceResult  @ 000f9990
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
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  iVar3 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"player");
  if (iVar3 == 0) {
    iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1[0xfa],param_2);
    if (iVar3 == 0) {
      ClearMultiDamage__Fv();
      uStack_1c = *param_3;
      uStack_18 = param_3[1];
      uStack_14 = param_3[2];
      (**(code **)(param_2[0xf2] + 0x30))
                (param_2,*(undefined4 *)param_1[0xfa],0x41200000,&uStack_1c,param_4,0x80);
      ApplyMultiDamage__FP9entvars_tT0(*(undefined4 *)param_1[0xfa],*(undefined4 *)param_1[0xfa]);
      if ((((*(byte *)(param_2 + 0x22) & 0x10) == 0) && (param_2[0xb] != 5)) &&
         (cb_prematch_time <= *gpGlobals)) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_2 + 0x1e8),2,"player/death2.wav",0x3f800000,0x3f4ccccd,0,
                   100);
        *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) | 0x10;
        piVar4 = (int *)CreateTimer__11CBaseEntityi(param_2,2);
        *(float *)(*piVar4 + 0xe4) = *gpGlobals + 2.0;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)Timer_Infection__11CBaseEntity;
        *(undefined4 *)(*piVar4 + 0x170) = *(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8);
        param_2[0x4a] = *(int *)(param_1[0xfa] + 0x120);
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8));
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),
                                *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" infected \"%s<%i>\".\n",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],uVar5);
      }
    }
    else {
      piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,1);
      if (piVar4 != (int *)0x0) {
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_cureconc",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8));
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),
                                *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" cured \"%s<%i>\"\'s \"concussion\".\n",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        if (piVar4[0x48] != *(int *)(param_1[0xfa] + 0x120)) {
          TF_AddFrags__11CBasePlayeri(param_1[0xfa],1);
        }
        *(float *)(*piVar4 + 0xe4) = *gpGlobals;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)SUB_Remove__11CBaseEntity;
      }
      if ((*(byte *)((int)param_2 + 0x89) & 0x40) != 0) {
        piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,3);
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_curehalluc",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8));
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),
                                *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" cured \"%s<%i>\"\'s \"hallucinations\".\n",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        if (piVar4[0x48] != *(int *)(param_1[0xfa] + 0x120)) {
          TF_AddFrags__11CBasePlayeri(param_1[0xfa],1);
        }
        *(byte *)((int)param_2 + 0x89) = *(byte *)((int)param_2 + 0x89) & 0xbf;
        *(float *)(*piVar4 + 0xe4) = *gpGlobals;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)SUB_Remove__11CBaseEntity;
      }
      if ((short)param_2[0x22] < 0) {
        piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,4);
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_curetranq",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8));
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),
                                *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" cured \"%s<%i>\"\'s \"tranquilisation\".\n",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        if (piVar4[0x48] != *(int *)(param_1[0xfa] + 0x120)) {
          TF_AddFrags__11CBasePlayeri(param_1[0xfa],1);
        }
        *(byte *)((int)param_2 + 0x89) = *(byte *)((int)param_2 + 0x89) & 0x7f;
        TeamFortress_SetSpeed__11CBasePlayer(param_2);
        *(float *)(*piVar4 + 0xe4) = *gpGlobals;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)SUB_Remove__11CBaseEntity;
      }
      if ((*(byte *)(param_2 + 0x22) & 0x10) != 0) {
        piVar4 = (int *)FindTimer__11CBaseEntityi(param_2,2);
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_cureinfection",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8));
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),
                                *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" cured \"%s<%i>\"\'s \"infection\".\n",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        if (piVar4[0x48] != *(int *)(param_1[0xfa] + 0x120)) {
          TF_AddFrags__11CBasePlayeri(param_1[0xfa],1);
        }
        _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
        uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
        iVar3 = (int)ROUND(*(float *)(*param_2 + 0x140) * 0.5);
        uStack_1c = *(undefined4 *)(*param_2 + 8);
        uStack_18 = *(undefined4 *)(*param_2 + 0xc);
        uStack_14 = *(undefined4 *)(*param_2 + 0x10);
        uVar5 = (**(code **)(param_2[0xf2] + 0x40))(param_2,(float)iVar3);
        SpawnBlood__FG6Vectorif(&uStack_1c,uVar5);
        iVar6 = *(int *)(*piVar4 + 0x178);
        if ((iVar6 == 0) && (iVar6 = (*DAT_001755d4)(0), iVar6 == 0)) {
          puVar7 = (undefined4 *)0x0;
        }
        else {
          puVar7 = *(undefined4 **)(iVar6 + 0xd8);
        }
        (**(code **)(param_2[0xf2] + 0x34))(param_2,*param_1,*puVar7,(float)iVar3,0x8010000);
        *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) & 0xef;
        *(float *)(*piVar4 + 0xe4) = *gpGlobals;
        piVar4[3] = -0x10000;
        piVar4[4] = (int)SUB_Remove__11CBaseEntity;
      }
      fVar1 = (float)param_2[0x72];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Medic_curefire",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0);
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*param_2 + 0x1e8));
        uVar5 = (*DAT_00175684)(*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),
                                *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i>\" doused \"%s<%i>\"\'s \"fire\".\n",
                   *(int *)(*(int *)param_1[0xfa] + 0x1b0) + (int)gpGlobals[0x26],uVar5);
        param_2[0x72] = 0;
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),3,"ambience/steamburst1.wav",
                   0x3f800000,0x3f4ccccd,0,100);
      }
      iVar3 = *param_2;
      fVar1 = *(float *)(iVar3 + 0x140);
      fVar2 = *(float *)(iVar3 + 400);
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar3 + 0x1e8),3,"items/medshot4.wav",0x3f800000,0x3f4ccccd,0,100
                  );
        (**(code **)(param_2[0xf2] + 0x38))(param_2,0x43480000,0);
      }
      else {
        iVar3 = *param_2;
        if (*(float *)(iVar3 + 0x140) < *(float *)(iVar3 + 400) + 50.0) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(iVar3 + 0x1e8),3,"items/medshot5.wav",0x3f800000,0x3f4ccccd,0,
                     100);
          (**(code **)(param_2[0xf2] + 0x38))(param_2,0x40a00000,0x1000000);
          if ((*(byte *)((int)param_2 + 0x8e) & 1) == 0) {
            *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 1;
            piVar4 = (int *)CreateTimer__11CBaseEntityi(param_2,5);
            *(float *)(*piVar4 + 0xe4) = *gpGlobals + 5.0;
            piVar4[3] = -0x10000;
            piVar4[4] = (int)Timer_HealthRot__11CBaseEntity;
          }
        }
      }
    }
    return 1;
  }
  return 0;
}


// AxeHit__10CTFSpannerP11CBaseEntityG6VectorP11TraceResult  @ 000f9460
undefined4
AxeHit__10CTFSpannerP11CBaseEntityG6VectorP11TraceResult
          (int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((*(byte *)(param_2 + 0x220) & 8) == 0) {
    iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(*(undefined4 *)(param_1 + 1000),param_2);
    if (iVar1 == 0) {
      ClearMultiDamage__Fv();
      local_10 = *param_3;
      local_c = param_3[1];
      local_8 = param_3[2];
      (**(code **)(*(int *)(param_2 + 0x3c8) + 0x30))
                (param_2,**(undefined4 **)(param_1 + 1000),0x41a00000,&local_10,param_4,0x80);
      ApplyMultiDamage__FP9entvars_tT0
                (**(undefined4 **)(param_1 + 1000),**(undefined4 **)(param_1 + 1000));
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0xe0))
                        (param_2,*(undefined4 *)(param_1 + 1000));
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x37c) = 1;
    (**(code **)(*(int *)(param_2 + 0x3c8) + 0xb0))
              (param_2,*(undefined4 *)(param_1 + 1000),*(undefined4 *)(param_1 + 1000),3,0x41000000)
    ;
    *(undefined4 *)(param_2 + 0x37c) = 0;
  }
  return 1;
}


// AxeHit__6CTFAxeP11CBaseEntityG6VectorP11TraceResult  @ 000f9170
undefined4
AxeHit__6CTFAxeP11CBaseEntityG6VectorP11TraceResult
          (int param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  ClearMultiDamage__Fv();
  if (*(int *)(*(int *)(param_1 + 1000) + 0x2c) == 8) {
    iVar2 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar2 == 0) {
      UTIL_MakeVectors__FRC6Vector(*param_2 + 0x74);
      local_10 = *(float *)(gpGlobals + 0x40);
      local_c = *(float *)(gpGlobals + 0x44);
      local_8 = *(undefined4 *)(gpGlobals + 0x48);
      UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
      fVar1 = local_10 * *(float *)(gpGlobals + 0x2c) - *(float *)(gpGlobals + 0x28) * local_c;
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        if (*(int *)(param_1 + 0x49c) == 0) {
          local_1c = *param_3;
          local_18 = param_3[1];
          local_14 = param_3[2];
          iVar2 = param_2[0xf2];
          uVar4 = 0x42700000;
          uVar3 = **(undefined4 **)(param_1 + 1000);
        }
        else {
          local_1c = *param_3;
          local_18 = param_3[1];
          local_14 = param_3[2];
          iVar2 = param_2[0xf2];
          uVar4 = 0x42f00000;
          uVar3 = **(undefined4 **)(param_1 + 1000);
        }
        (**(code **)(iVar2 + 0x30))(param_2,uVar3,uVar4,&local_1c,param_4,0x8000080);
        (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,3);
      }
      else {
        local_1c = *param_3;
        local_18 = param_3[1];
        local_14 = param_3[2];
        (**(code **)(param_2[0xf2] + 0x30))
                  (param_2,**(undefined4 **)(param_1 + 1000),0x42200000,&local_1c,param_4,0x80);
        (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,2);
      }
      goto LAB_000f935b;
    }
  }
  local_1c = *param_3;
  local_18 = param_3[1];
  local_14 = param_3[2];
  (**(code **)(param_2[0xf2] + 0x30))
            (param_2,**(undefined4 **)(param_1 + 1000),0x41a00000,&local_1c,param_4,0x80);
LAB_000f935b:
  ApplyMultiDamage__FP9entvars_tT0
            (**(undefined4 **)(param_1 + 1000),**(undefined4 **)(param_1 + 1000));
  return 1;
}


