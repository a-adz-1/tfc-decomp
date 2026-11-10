// ChangeClass__11CBasePlayeri  @ 000ddc1c
void ChangeClass__11CBasePlayeri(code *param_1,code *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code **ppcVar5;
  uint uVar6;
  bool bVar7;
  ushort in_FPUControlWord;
  longdouble lVar8;
  code *pcStack_60;
  code *pcStack_5c;
  code *pcStack_58;
  code *pcStack_54;
  code *pcStack_50;
  code *pcStack_4c;
  code *pcStack_48;
  int iStack_38;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  ushort uStack_c;
  undefined2 uStack_a;
  ushort uStack_8;
  
  ppcVar5 = (code **)&stack0xffffffbc;
  if (*(code **)(*(int *)param_1 + 0x20c) == param_2) {
    return;
  }
  if (*(code **)(param_1 + 0x2c) == param_2) {
    return;
  }
  pcStack_48 = (code *)0x150cb9;
  pcStack_4c = *(code **)(*(int *)param_1 + 0x208);
  pcStack_50 = (code *)0xddc6a;
  pcStack_4c = (code *)(*DAT_0019f848)();
  pcStack_50 = (code *)0xddc76;
  pcStack_54 = (code *)(*DAT_0019f84c)();
  pcStack_48 = (code *)0x0;
  pcStack_4c = (code *)0xa;
  pcStack_50 = (code *)0x0;
  pcStack_58 = (code *)0xddc85;
  iVar2 = __strtol_internal();
  pcStack_48 = param_1;
  pcStack_4c = (code *)0xddc91;
  iVar3 = PositionAvailable__11CBasePlayer();
  if (iVar3 == 0) {
    pcStack_48 = (code *)0x0;
    pcStack_4c = (code *)0x0;
    pcStack_50 = (code *)0x0;
    pcStack_54 = (code *)0x0;
    pcStack_58 = (code *)0x150ca1;
    pcStack_5c = (code *)0x1;
    pcStack_60 = *(code **)param_1;
    ppcVar5 = &pcStack_60;
    ClientPrint__FP9entvars_siPCcN42();
    goto LAB_000de202;
  }
  pcStack_48 = (code *)(float)*(int *)(param_1 + 0x120);
  pcStack_4c = (code *)0xddcc9;
  iVar3 = TeamFortress_TeamIsCivilian__Ff();
  if ((iVar3 != 0) && (param_2 != (code *)0xb)) {
    pcStack_58 = (code *)0x150ccb;
LAB_000ddf87:
    pcStack_48 = (code *)0x0;
    pcStack_4c = (code *)0x0;
    pcStack_50 = (code *)0x0;
    pcStack_54 = (code *)0x0;
    pcStack_5c = (code *)0x1;
    pcStack_60 = *(code **)param_1;
    ClientPrint__FP9entvars_siPCcN42();
    return;
  }
  if (*(int *)(*(code **)param_1 + 0x20c) != 0) {
    pcStack_48 = param_2;
    pcStack_4c = param_1;
    pcStack_50 = (code *)0xddd05;
    iVar3 = IsLegalClass__11CBasePlayeri();
    if ((iVar3 == 0) && (param_2 != (code *)0xb)) {
      pcStack_48 = (code *)0x0;
      pcStack_4c = (code *)0x0;
      pcStack_50 = (code *)0x0;
      pcStack_54 = (code *)0x0;
      pcStack_58 = (code *)0x150c7b;
      pcStack_5c = (code *)0x1;
      pcStack_60 = *(code **)param_1;
      ClientPrint__FP9entvars_siPCcN42();
      pcStack_48 = param_1;
      pcStack_4c = (code *)0xddd36;
      TeamFortress_DisplayLegalClasses__11CBasePlayer();
      bVar7 = true;
LAB_000ddda6:
      if (bVar7) {
        return;
      }
      pcStack_48 = (code *)0x0;
      pcStack_4c = (code *)0x0;
      pcStack_50 = (code *)0x0;
      pcStack_54 = (code *)(&sClassNames)[(int)param_2];
      pcStack_58 = (code *)&DAT_00150cb5;
      pcStack_5c = (code *)0xdddd4;
      pcStack_54 = (code *)UTIL_VarArgs__FPce();
      pcStack_58 = (code *)0x150cdf;
      pcStack_5c = (code *)0x1;
      pcStack_60 = *(code **)param_1;
      ClientPrint__FP9entvars_siPCcN42();
      *(code **)(param_1 + 0x2c) = param_2;
      if ((iVar2 != 0) && (*(int *)(*(int *)param_1 + 0x170) == 0)) {
        pcStack_48 = *(code **)(*(int *)param_1 + 0x208);
        pcStack_4c = (code *)0xdde14;
        ClientKill__FP7edict_s();
      }
      pcStack_48 = (code *)(&sClassNames)[(int)param_2];
      pcStack_4c = *(code **)(param_1 + 0x120);
      if (pcStack_4c == (code *)0x0) {
        pcStack_4c = (code *)0x150cf1;
        iStack_38 = *(int *)param_1;
      }
      else {
        pcStack_50 = (code *)0xdde31;
        pcStack_4c = (code *)GetTeamName__Fi();
        iStack_38 = *(int *)param_1;
      }
      pcStack_50 = *(code **)(iStack_38 + 0x208);
      pcStack_54 = (code *)0xdde64;
      pcStack_50 = (code *)(*DAT_0019f8dc)();
      pcStack_54 = *(code **)(*(int *)param_1 + 0x208);
      pcStack_58 = (code *)0xdde81;
      pcStack_54 = (code *)(*DAT_0019f864)();
      pcStack_58 = (code *)(*(int *)(*(int *)param_1 + 0x1d0) + (int)gpGlobals[0x26]);
      pcStack_5c = (code *)0x150d00;
      pcStack_60 = FUN_000ddeac;
      UTIL_LogPrintf__FPce();
      fVar1 = *gpGlobals;
      *(int *)(param_1 + 0xd9c) = 1;
      *(int *)(param_1 + 0x8e8) = 0;
      *(float *)(param_1 + 0x18c) = fVar1 + 10.0;
      pcStack_60 = param_1;
      ResetMenu__11CBasePlayer();
      *(float *)(param_1 + 0x718) = *gpGlobals + 1.0;
      return;
    }
    if (((byte)((byte)((ushort)((ushort)NAN(spy_off) << 10) >> 8) |
               (byte)((ushort)((ushort)(spy_off == 1.0) << 0xe) >> 8)) == 0x40) &&
       (param_2 == (code *)0x8)) {
      pcStack_58 = (code *)0x150c8f;
    }
    else {
      pcStack_48 = param_2;
      pcStack_4c = (code *)(float)*(int *)(param_1 + 0x120);
      pcStack_50 = (code *)0xddd85;
      iVar3 = ClassIsRestricted__Ffi();
      if (iVar3 == 0) {
        bVar7 = false;
        goto LAB_000ddda6;
      }
      pcStack_58 = (code *)0x150ca1;
    }
    goto LAB_000ddf87;
  }
  fVar1 = gpGlobals[7];
  if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (*(int *)(param_1 + 0x120) == 0)) {
    if ((*gpGlobals <= 30.0) ||
       ((byte)((float)tfc_autoteam._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)tfc_autoteam._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_autoteam._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
      pcStack_48 = (code *)0x0;
      pcStack_4c = (code *)0x0;
      pcStack_50 = (code *)0x0;
      pcStack_54 = (code *)0x0;
      pcStack_58 = (code *)0x150d27;
      pcStack_5c = (code *)0x1;
      pcStack_60 = *(code **)param_1;
      ClientPrint__FP9entvars_siPCcN42();
      return;
    }
    pcStack_48 = param_1;
    pcStack_4c = (code *)0xddf40;
    iVar2 = TeamFortress_TeamPutPlayerInTeam__11CBasePlayer();
    if (iVar2 == 0) {
      return;
    }
  }
  if (*(int *)(param_1 + 0x124) == 0) {
    pcStack_58 = (code *)0x150d36;
    goto LAB_000ddf87;
  }
  pcStack_48 = param_2;
  pcStack_4c = param_1;
  pcStack_50 = (code *)0xddfa2;
  iVar2 = IsLegalClass__11CBasePlayeri();
  if ((iVar2 != 0) || (param_2 == (code *)0xb)) {
    if (((byte)((byte)((ushort)((ushort)NAN(spy_off) << 10) >> 8) |
               (byte)((ushort)((ushort)(spy_off == 1.0) << 0xe) >> 8)) == 0x40) &&
       (param_2 == (code *)0x8)) {
      pcStack_58 = (code *)0x150c8f;
    }
    else {
      pcStack_48 = param_2;
      pcStack_4c = (code *)(float)*(int *)(param_1 + 0x120);
      pcStack_50 = (code *)0xde021;
      iVar2 = ClassIsRestricted__Ffi();
      if (iVar2 == 0) {
        bVar7 = false;
        goto LAB_000de04e;
      }
      pcStack_58 = (code *)0x150ca1;
    }
    pcStack_48 = (code *)0x0;
    pcStack_4c = (code *)0x0;
    pcStack_50 = (code *)0x0;
    pcStack_54 = (code *)0x0;
    pcStack_5c = (code *)0x1;
    pcStack_60 = *(code **)param_1;
    ClientPrint__FP9entvars_siPCcN42();
    ppcVar5 = (code **)&stack0xffffffbc;
    goto LAB_000de202;
  }
  pcStack_48 = (code *)0x0;
  pcStack_4c = (code *)0x0;
  pcStack_50 = (code *)0x0;
  pcStack_54 = (code *)0x0;
  pcStack_58 = (code *)0x150c7b;
  pcStack_5c = (code *)0x1;
  pcStack_60 = *(code **)param_1;
  ClientPrint__FP9entvars_siPCcN42();
  pcStack_48 = param_1;
  pcStack_4c = (code *)0xddfd3;
  TeamFortress_DisplayLegalClasses__11CBasePlayer();
  bVar7 = true;
LAB_000de04e:
  if (bVar7) goto LAB_000de202;
  if (param_2 != (code *)0xa) {
    *(int *)(param_1 + 0xd9c) = 1;
    *(int *)(param_1 + 0x8e8) = 0;
    pcStack_48 = param_1;
    pcStack_4c = (code *)0xde076;
    ResetMenu__11CBasePlayer();
    *(int *)(param_1 + 0x87c) = 1;
    *(int *)(param_1 + 0x8b8) = -1;
    *(int *)(param_1 + 0xa24) = -1;
    param_1[0xcc8] = (code)0xa;
    param_1[0xc48] = (code)0xa;
    *(code **)(*(int *)param_1 + 0x20c) = param_2;
    *(int *)(param_1 + 0x2c) = 0;
    goto LAB_000de280;
  }
  uVar6 = 0xfffffe00;
  do {
    pcStack_48 = (code *)0x41100000;
    pcStack_4c = (code *)0x0;
    pcStack_50 = (code *)0xde0e4;
    lVar8 = (longdouble)(*DAT_0019f80c)();
    uStack_8 = in_FPUControlWord & 0xf3ff | 0x400;
    _uStack_c = CONCAT22(uStack_a,in_FPUControlWord);
    uStack_14 = CONCAT22(uStack_a,CONCAT11(0xc,(char)in_FPUControlWord));
    *(int *)(*(int *)param_1 + 0x20c) = (int)ROUND((longdouble)1 + ROUND(lVar8));
    pcStack_48 = *(code **)(*(int *)param_1 + 0x20c);
    uVar6 = uVar6 | 1 << ((char)pcStack_48 - 1U & 0x1f);
    pcStack_4c = param_1;
    pcStack_50 = (code *)0xde142;
    iVar2 = IsLegalClass__11CBasePlayeri();
    if (iVar2 != 0) {
      pcStack_48 = *(code **)(*(int *)param_1 + 0x20c);
      pcStack_4c = (code *)(float)*(int *)(param_1 + 0x120);
      pcStack_50 = (code *)0xde169;
      iVar2 = ClassIsRestricted__Ffi();
      if (iVar2 == 0) break;
    }
  } while ((short)uVar6 != -1);
  iVar2 = *(int *)(*(int *)param_1 + 0x20c);
  pcStack_4c = param_1;
  pcStack_50 = (code *)0xde183;
  pcStack_48 = (code *)iVar2;
  iVar3 = IsLegalClass__11CBasePlayeri();
  if ((iVar3 == 0) && (iVar2 != 0xb)) {
    pcStack_48 = param_1;
    pcStack_4c = (code *)0xde195;
    TeamFortress_DisplayLegalClasses__11CBasePlayer();
    bVar7 = true;
LAB_000de1d9:
    if (!bVar7) {
      pcStack_48 = (code *)0x0;
      pcStack_4c = (code *)0x0;
      pcStack_50 = (code *)0x0;
      pcStack_54 = (code *)0x0;
      pcStack_58 = (code *)0x150d44;
      pcStack_5c = (code *)0x1;
      pcStack_60 = *(code **)param_1;
      ClientPrint__FP9entvars_siPCcN42();
      param_1[0x84] = (code)((byte)param_1[0x84] | 8);
      *(int *)(param_1 + 0xd9c) = 1;
      *(int *)(param_1 + 0x8e8) = 0;
      ResetMenu__11CBasePlayer(param_1);
      *(int *)(param_1 + 0x87c) = 1;
      *(int *)(param_1 + 0x8b8) = -1;
      *(int *)(param_1 + 0xa24) = -1;
      param_1[0xcc8] = (code)0xa;
      param_1[0xc48] = (code)0xa;
      *(int *)(param_1 + 0x2c) = 0;
LAB_000de280:
      pcStack_48 = (code *)(&sClassNames)[(int)param_2];
      pcStack_4c = *(code **)(param_1 + 0x120);
      if (pcStack_4c == (code *)0x0) {
        pcStack_4c = (code *)0x150cf1;
      }
      else {
        pcStack_50 = (code *)0xde29d;
        pcStack_4c = (code *)GetTeamName__Fi();
      }
      pcStack_50 = *(code **)(*(int *)param_1 + 0x208);
      pcStack_54 = (code *)0xde2c2;
      pcStack_50 = (code *)(*DAT_0019f8dc)();
      pcStack_54 = *(code **)(*(int *)param_1 + 0x208);
      pcStack_58 = (code *)0xde2dd;
      pcStack_54 = (code *)(*DAT_0019f864)();
      pcStack_58 = (code *)(*(int *)(*(int *)param_1 + 0x1d0) + (int)gpGlobals[0x26]);
      pcStack_5c = (code *)0x150d00;
      pcStack_60 = (code *)0xde304;
      UTIL_LogPrintf__FPce();
      if ((*(int *)(*(int *)param_1 + 0x244) != 0) || (*(int *)(*(int *)param_1 + 0x248) != 0)) {
        pcStack_50 = (code *)gmsgSpectator;
        pcStack_48 = (code *)0x0;
        pcStack_4c = (code *)0x0;
        pcStack_54 = (code *)0x2;
        pcStack_58 = (code *)0xde338;
        (*DAT_0019f758)();
        pcStack_48 = *(code **)(*(int *)param_1 + 0x208);
        pcStack_4c = (code *)0xde352;
        pcStack_48 = (code *)(*DAT_0019f7bc)();
        pcStack_4c = (code *)0xde35e;
        (*DAT_0019f760)();
        pcStack_4c = (code *)0x0;
        pcStack_50 = (code *)0xde36e;
        (*DAT_0019f760)();
        pcStack_50 = (code *)0xde37c;
        (*DAT_0019f75c)();
        iVar2 = *(int *)param_1;
        *(undefined4 *)(iVar2 + 0x248) = 0;
        *(undefined4 *)(iVar2 + 0x244) = 0;
      }
      *(float *)(param_1 + 0x718) = *gpGlobals + 1.0;
      pcStack_48 = (code *)0x0;
      pcStack_4c = param_1 + 0x69c;
      pcStack_50 = (code *)0xde3b5;
      __as__7EHANDLEP11CBaseEntity();
      *(byte *)(*(int *)param_1 + 0x16b) = *(byte *)(*(int *)param_1 + 0x16b) | 0x80;
      *(int *)(param_1 + 0x8b4) = 0;
      pcStack_50 = param_1;
      pcStack_54 = (code *)0xde3ce;
      TeamFortress_SetEquipment__11CBasePlayer();
      pcStack_54 = param_1;
      pcStack_58 = (code *)0xde3d4;
      TeamFortress_SetHealth__11CBasePlayer();
      pcStack_58 = param_1;
      pcStack_5c = (code *)0xde3da;
      TeamFortress_SetSpeed__11CBasePlayer();
      pcStack_5c = param_1;
      pcStack_60 = (code *)0xde3e0;
      TeamFortress_SetSkin__11CBasePlayer();
      *(undefined4 *)(*(int *)param_1 + 0x16c) = 0x40000000;
      *(undefined4 *)(*(int *)param_1 + 0x10c) = 3;
      *(undefined4 *)(*(int *)param_1 + 0x108) = 3;
      *(undefined4 *)(*(int *)param_1 + 0x1a4) = 0x208;
      *(undefined4 *)(*(int *)param_1 + 0x1c0) = 0;
      *(float *)(*(int *)param_1 + 0x1fc) = *gpGlobals + 12.0;
      uStack_18 = 0x41e00000;
      *(byte *)(*(int *)param_1 + 0x118) = *(byte *)(*(int *)param_1 + 0x118) & 0x7f;
      iVar2 = *(int *)param_1;
      uStack_20 = 0;
      uStack_1c = 0;
      *(undefined4 *)(iVar2 + 0x174) = 0;
      *(undefined4 *)(iVar2 + 0x178) = 0;
      *(undefined4 *)(iVar2 + 0x17c) = 0x41e00000;
      *(undefined4 *)(*(int *)param_1 + 0x170) = 0;
      *(int *)(param_1 + 0x6ec) = 0;
      pcStack_48 = (code *)0x1;
      pcStack_4c = param_1;
      pcStack_50 = (code *)0xde492;
      uVar4 = LookupActivity__14CBaseAnimatingi();
      *(undefined4 *)(*(int *)param_1 + 0x128) = uVar4;
      pcStack_50 = *(code **)param_1;
      if ((*(byte *)((int)pcStack_50 + 0x1a5) & 0x40) == 0) {
        pcStack_48 = (code *)&uStack_2c;
        uStack_28 = 0x41800000;
        uStack_24 = 0x42100000;
        uStack_1c = 0xc1800000;
        uStack_18 = 0xc2100000;
        pcStack_4c = (code *)&uStack_20;
      }
      else {
        pcStack_48 = (code *)&uStack_20;
        uStack_1c = 0x41800000;
        uStack_18 = 0x41900000;
        uStack_28 = 0xc1800000;
        uStack_24 = 0xc1900000;
        pcStack_4c = (code *)&uStack_2c;
      }
      pcStack_54 = (code *)0xde520;
      uStack_2c = uStack_28;
      uStack_20 = uStack_1c;
      UTIL_SetSize__FP9entvars_sRC6VectorT1();
      pcStack_48 = param_1;
      pcStack_4c = (code *)0xde529;
      TeamFortress_ExecClassScript__11CBasePlayer();
      pcStack_4c = param_1;
      pcStack_50 = (code *)g_pGameRules;
      pcStack_54 = (code *)0xde53c;
      (**(code **)(*g_pGameRules + 0x60))();
      return;
    }
  }
  else if (((byte)((byte)((ushort)((ushort)NAN(spy_off) << 10) >> 8) |
                  (byte)((ushort)((ushort)(spy_off == 1.0) << 0xe) >> 8)) != 0x40) || (iVar2 != 8))
  {
    pcStack_4c = (code *)(float)*(int *)(param_1 + 0x120);
    pcStack_50 = (code *)0xde1cd;
    pcStack_48 = (code *)iVar2;
    iVar2 = ClassIsRestricted__Ffi();
    bVar7 = iVar2 != 0;
    goto LAB_000de1d9;
  }
  pcStack_48 = (code *)0x0;
  pcStack_4c = (code *)0x0;
  pcStack_50 = (code *)0x0;
  pcStack_54 = (code *)0x0;
  pcStack_58 = (code *)0x150ca1;
  pcStack_5c = (code *)0x1;
  pcStack_60 = *(code **)param_1;
  ppcVar5 = &pcStack_60;
  ClientPrint__FP9entvars_siPCcN42();
  *(undefined4 *)(*(int *)param_1 + 0x20c) = 0;
LAB_000de202:
  *(code **)((int)ppcVar5 + -4) = param_1;
  *(undefined4 *)((int)ppcVar5 + -8) = 0xde208;
  Menu_Class__11CBasePlayer();
  return;
}


