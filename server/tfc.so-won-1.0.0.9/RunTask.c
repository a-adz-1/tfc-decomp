// RunTask__12CBaseMonsterP6Task_t  @ 000e4f70
void RunTask__12CBaseMonsterP6Task_t(int *param_1,int *param_2)

{
  float fVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined2 in_FPUControlWord;
  longdouble lVar5;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  switch(*param_2) {
  case 1:
  case 0x52:
    goto switchD_000e4f8a_caseD_1;
  case 2:
    local_1c = (float)param_1[0x16e];
    local_18 = (float)param_1[0x16f];
    local_14 = (float)param_1[0x170];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_1c);
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf2] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0x90)));
    goto switchD_000e4f8a_caseD_1;
  case 3:
    iVar4 = (*DAT_00175504)(*(undefined4 *)(*param_1 + 0x1e8));
    bVar2 = false;
    if ((iVar4 == 0) || (iVar4 = (*DAT_001755d8)(iVar4), iVar4 == 0)) {
      bVar2 = true;
    }
    if (bVar2) {
      return;
    }
    goto LAB_000e558d;
  case 7:
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11e);
    if (iVar4 == 0) {
      SetConditions__12CBaseMonsteri(param_1,0x40000000);
      switchD_000e4f8a::caseD_4();
      return;
    }
    local_1c = (float)param_1[0x162] - *(float *)(*param_1 + 8);
    local_18 = (float)param_1[0x163] - *(float *)(*param_1 + 0xc);
    local_14 = (float)param_1[0x164] - *(float *)(*param_1 + 0x10);
    local_30 = SQRT(local_18 * local_18 + local_1c * local_1c);
    fVar1 = (float)param_2[1];
    if ((byte)(local_30 < fVar1 | (byte)((ushort)((ushort)(NAN(local_30) || NAN(fVar1)) << 10) >> 8)
              | (byte)((ushort)((ushort)(local_30 == fVar1) << 0xe) >> 8)) == 1) {
LAB_000e52b4:
      piVar3 = (int *)__rf__7EHANDLE(param_1 + 0x11e);
      iVar4 = *piVar3;
      param_1[0x162] = *(int *)(iVar4 + 8);
      param_1[0x163] = *(int *)(iVar4 + 0xc);
      param_1[0x164] = *(int *)(iVar4 + 0x10);
      iVar4 = *param_1;
      local_2c = (float)param_1[0x162] - *(float *)(iVar4 + 8);
      local_28 = (float)param_1[0x163] - *(float *)(iVar4 + 0xc);
      local_24 = (float)param_1[0x164] - *(float *)(iVar4 + 0x10);
      local_30 = SQRT(local_28 * local_28 + local_2c * local_2c);
      FRefreshRoute__12CBaseMonster(param_1);
    }
    else {
      piVar3 = (int *)__rf__7EHANDLE(param_1 + 0x11e);
      iVar4 = *piVar3;
      local_20 = (float)param_1[0x162] - *(float *)(iVar4 + 8);
      local_1c = (float)param_1[0x163] - *(float *)(iVar4 + 0xc);
      local_18 = (float)param_1[0x164] - *(float *)(iVar4 + 0x10);
      local_14 = SQRT(local_18 * local_18 + local_1c * local_1c + local_20 * local_20);
      fVar1 = (float)param_2[1] * 0.5;
      if ((byte)(fVar1 < local_14 |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_14)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == local_14) << 0xe) >> 8)) == 1) goto LAB_000e52b4;
    }
    fVar1 = (float)param_2[1];
    if ((byte)(local_30 < fVar1 | (byte)((ushort)((ushort)(NAN(local_30) || NAN(fVar1)) << 10) >> 8)
              | (byte)((ushort)((ushort)(local_30 == fVar1) << 0xe) >> 8)) == 1) {
LAB_000e53ad:
      iVar4 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
      if (iVar4 == 0) {
        param_1[0x13c] = 4;
      }
      RouteClear__12CBaseMonster(param_1);
      switchD_000e4f8a::caseD_4();
      return;
    }
    if ((local_30 < 190.0) && (param_1[0x165] != 3)) {
      param_1[0x165] = 3;
      switchD_000e4f8a::caseD_4();
      return;
    }
    if (((byte)((270.0 < local_30 | (byte)((ushort)((ushort)NAN(local_30) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_30 == 270.0) << 0xe) >> 8)) - 1) < 0x40) &&
       (param_1[0x165] != 4)) {
      param_1[0x165] = 4;
      switchD_000e4f8a::caseD_4();
      return;
    }
    break;
  case 0x18:
  case 0x1b:
  case 0x3d:
    goto code_r0x000e5580;
  case 0x1c:
  case 0x1d:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x55:
  case 0x56:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf2] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0x90)));
    iVar4 = FacingIdeal__12CBaseMonster(param_1);
    goto joined_r0x000e50ee;
  case 0x1e:
    local_1c = (float)param_1[0x16e];
    local_18 = (float)param_1[0x16f];
    local_14 = (float)param_1[0x170];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_1c);
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf2] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0x90)));
    iVar4 = FacingIdeal__12CBaseMonster(param_1);
    goto joined_r0x000e50ee;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
    local_2c = (float)param_1[0x16e];
    local_28 = (float)param_1[0x16f];
    local_24 = (float)param_1[0x170];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_2c);
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf2] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0x90)));
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (param_1[0xf8] == 0) {
      return;
    }
    param_1[0x137] = 0;
    goto LAB_000e558d;
  case 0x3e:
  case 0x3f:
    if (*param_2 == 0x3f) {
      piVar3 = param_1 + 0x11e;
    }
    else {
      piVar3 = param_1 + 0x11c;
    }
    piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(piVar3);
    if (piVar3 != (int *)0x0) {
      iVar4 = *piVar3;
      local_1c = *(float *)(iVar4 + 8) - *(float *)(*param_1 + 8);
      local_18 = *(float *)(iVar4 + 0xc) - *(float *)(*param_1 + 0xc);
      local_14 = *(float *)(iVar4 + 0x10) - *(float *)(*param_1 + 0x10);
      lVar5 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_1c);
      *(float *)(*param_1 + 0x8c) = (float)lVar5;
      local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
      local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
      (**(code **)(param_1[0xf2] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0x90)));
      switchD_000e4f8a::caseD_18();
      return;
    }
    goto code_r0x000e5580;
  case 0x4c:
    if (param_1[0xf8] != 0) {
      fVar1 = *(float *)(*param_1 + 0x110);
      if ((byte)((255.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 255.0) << 0xe) >> 8)) - 1) < 0x40) {
        *(undefined4 *)(*param_1 + 0x150) = 2;
        param_1[3] = 0;
        param_1[4] = 0;
        *(undefined4 *)(*param_1 + 0x118) = 0;
        iVar4 = BBoxFlat__12CBaseMonster(param_1);
        if (iVar4 == 0) {
          local_2c = 4.0;
          local_28 = 4.0;
          local_24 = 1.0;
          local_20 = -4.0;
          local_1c = -4.0;
          local_18 = 0.0;
          iVar4 = *param_1;
        }
        else {
          iVar4 = *param_1;
          local_24 = *(float *)(iVar4 + 0xc4) + 1.0;
          local_2c = *(float *)(iVar4 + 200);
          local_28 = *(float *)(iVar4 + 0xcc);
          local_20 = *(float *)(iVar4 + 0xbc);
          local_1c = *(float *)(iVar4 + 0xc0);
          local_18 = *(float *)(iVar4 + 0xc4);
        }
        UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar4,&local_20,&local_2c);
        iVar4 = (**(code **)(param_1[0xf2] + 0x10c))(param_1);
        if (iVar4 == 0) {
          InsertSound__9CSoundEntiRC6Vectorif(8,*param_1 + 8,0x180,0x41f00000);
          switchD_000e4f8a::caseD_4();
          return;
        }
        SUB_StartFadeOut__11CBaseEntity(param_1);
        switchD_000e4f8a::caseD_4();
        return;
      }
    }
    break;
  case 0x4d:
    if ((*(int *)(param_1[0x183] + 0x62c) < 1) && (*(float *)(param_1[0x183] + 0x630) <= *gpGlobals)
       ) {
      iVar4 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
      if (iVar4 == 0) {
        param_1[0x13c] = 4;
      }
      iVar4 = param_1[0x183];
      (**(code **)(*(int *)(iVar4 + 0x3c8) + 0x218))(iVar4,param_1,*(undefined4 *)(iVar4 + 0x614),1)
      ;
      if (param_1[0xf8] != 0) {
        ClearSchedule__12CBaseMonster(param_1);
      }
      *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
    }
    break;
  case 0x4e:
    if (param_1[0xf8] != 0) {
      SequenceDone__12CCineMonsterP12CBaseMonster(param_1[0x183],param_1);
    }
    break;
  case 0x59:
    if (param_1[0x15f] != 0) {
      return;
    }
    goto LAB_000e53ad;
  }
  return;
switchD_000e4f8a_caseD_1:
  if (*gpGlobals < (float)param_1[0x135]) {
    return;
  }
  goto LAB_000e558d;
code_r0x000e5580:
  iVar4 = param_1[0xf8];
joined_r0x000e50ee:
  if (iVar4 == 0) {
    return;
  }
LAB_000e558d:
  iVar4 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
  if (iVar4 != 0) {
    return;
  }
  param_1[0x13c] = 4;
  switchD_000e4f8a::caseD_4();
  return;
}


// RunTask__12CTalkMonsterP6Task_t  @ 000f16f0
void RunTask__12CTalkMonsterP6Task_t(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  float **ppfVar5;
  longdouble lVar6;
  longdouble lVar7;
  float *pfStack_34;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  switch(*param_2) {
  case 1.24716e-43:
    pfStack_34 = param_1;
    iVar3 = IsTalking__12CTalkMonster();
    if (iVar3 == 0) {
LAB_000f1a40:
      pfStack_34 = (float *)((int)*param_1 + 8);
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1);
      FIdleHello__12CTalkMonster(param_1);
      iVar3 = (*DAT_00175628)(0,(int)param_1[0x185] * 0x14);
      if (iVar3 == 0) {
        pfStack_34 = param_1;
        FIdleSpeak__12CTalkMonster();
      }
    }
    else {
      pfStack_34 = param_1 + 0x19e;
      iVar3 = __opP11CBaseEntity__7EHANDLE();
      if (iVar3 == 0) goto LAB_000f1a40;
      pfStack_34 = param_1 + 0x19e;
      piVar4 = (int *)__rf__7EHANDLE();
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
    }
    ppfVar5 = (float **)&stack0xffffffd0;
    pfStack_34 = param_2;
    RunTask__12CBaseMonsterP6Task_t(param_1);
    if (param_1[0x13c] != 5.60519e-45) {
      return;
    }
    fVar2 = *param_1;
LAB_000f1a8d:
    *(int *)((int)ppfVar5 + -4) = (int)fVar2 + 8;
    *(float **)((int)ppfVar5 + -8) = param_1;
    *(undefined4 *)((int)ppfVar5 + -0xc) = 0xf1a97;
    IdleHeadTurn__12CTalkMonsterR6Vector();
    return;
  default:
    pfStack_34 = param_1;
    iVar3 = IsTalking__12CTalkMonster();
    if (iVar3 != 0) {
      pfStack_34 = param_1 + 0x19e;
      iVar3 = __opP11CBaseEntity__7EHANDLE();
      if (iVar3 != 0) {
        pfStack_34 = param_1 + 0x19e;
        piVar4 = (int *)__rf__7EHANDLE();
        IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
        goto LAB_000f1aec;
      }
    }
    pfStack_34 = (float *)0x0;
    SetBoneController__14CBaseAnimatingif(param_1,0);
LAB_000f1aec:
    pfStack_34 = param_2;
    RunTask__12CBaseMonsterP6Task_t(param_1);
    return;
  case 1.30321e-43:
    local_14 = param_1[0x168] - *(float *)((int)*param_1 + 8);
    local_10 = param_1[0x169] - *(float *)((int)*param_1 + 0xc);
    local_c = param_1[0x16a] - *(float *)((int)*param_1 + 0x10);
    local_8 = SQRT(local_10 * local_10 + local_14 * local_14);
    if ((local_8 <= param_2[1]) && (param_1[0x15f] != 0.0)) {
      return;
    }
    pfStack_34 = (float *)0x40000000;
    iVar3 = HasConditions__12CBaseMonsteri(param_1);
    if (iVar3 == 0) {
      param_1[0x13c] = 5.60519e-45;
    }
    pfStack_34 = param_1;
    RouteClear__12CBaseMonster();
    return;
  case 1.4013e-43:
  case 1.41531e-43:
    if (param_1[0x13a] == 1.4013e-45) {
      pfStack_34 = param_1;
      iVar3 = (**(code **)((int)param_1[0xf2] + 0x68))();
      if (iVar3 == 0) {
        pfStack_34 = param_1;
        iVar3 = IsTalking__12CTalkMonster();
        if (iVar3 == 0) {
          pfStack_34 = (float *)0x1;
          iVar3 = (*DAT_001755e0)();
          if (iVar3 != 0) {
            pfStack_34 = (float *)(iVar3 + 0xe4);
            IdleHeadTurn__12CTalkMonsterR6Vector(param_1);
          }
          if (*param_2 == 1.41531e-43) {
            local_10 = *(float *)(iVar3 + 0xe4) - *(float *)((int)*param_1 + 8);
            local_c = *(float *)(iVar3 + 0xe8) - *(float *)((int)*param_1 + 0xc);
            local_8 = *(float *)(iVar3 + 0xec) - *(float *)((int)*param_1 + 0x10);
            local_14 = SQRT(local_c * local_c + local_10 * local_10);
            if ((byte)(128.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_14 == 128.0) << 0xe) >> 8)) == 1) {
              pfStack_34 = (float *)0x40000000;
              SetConditions__12CBaseMonsteri(param_1);
            }
            pfStack_34 = (float *)(iVar3 + 300);
            UTIL_MakeVectors__FRC6Vector();
            lVar6 = (longdouble)
                    UTIL_DotPoints__FRC6VectorN20(iVar3 + 0xe4,(int)*param_1 + 8,gpGlobals + 10);
            lVar7 = (longdouble)param_1[0x134];
            if ((byte)(lVar6 < lVar7 |
                       (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar7)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar6 == lVar7) << 0xe) >> 8)) == 1) {
              pfStack_34 = (float *)0x40000000;
              SetConditions__12CBaseMonsteri(param_1);
            }
          }
          if (*gpGlobals <= param_1[0x135]) {
            return;
          }
          goto LAB_000f1950;
        }
      }
    }
    break;
  case 1.42932e-43:
    pfStack_34 = param_1;
    iVar3 = (**(code **)((int)param_1[0xf2] + 0x68))();
    if (iVar3 != 0) {
LAB_000f1950:
      pfStack_34 = (float *)0x40000000;
      iVar3 = HasConditions__12CBaseMonsteri(param_1);
      if (iVar3 != 0) {
        return;
      }
      param_1[0x13c] = 5.60519e-45;
      return;
    }
    pfStack_34 = param_1;
    iVar3 = IsTalking__12CTalkMonster();
    if (iVar3 == 0) goto LAB_000f1950;
    pfStack_34 = param_1 + 0x19e;
    iVar3 = __opP11CBaseEntity__7EHANDLE();
    if (iVar3 == 0) goto LAB_000f1950;
    ppfVar5 = &pfStack_34;
    pfStack_34 = param_1 + 0x19e;
    pfVar1 = (float *)__rf__7EHANDLE();
    fVar2 = *pfVar1;
    goto LAB_000f1a8d;
  case 1.45735e-43:
    pfStack_34 = (float *)0x1;
    iVar3 = (*DAT_001755e0)();
    if (iVar3 != 0) {
      local_14 = *(float *)(iVar3 + 0xe4);
      local_10 = *(float *)(iVar3 + 0xe8);
      local_c = *(float *)(iVar3 + 0xec);
      pfStack_34 = &local_14;
      MakeIdealYaw__12CBaseMonsterG6Vector(param_1);
      (**(code **)((int)param_1[0xf2] + 0x110))
                (param_1,(int)ROUND(*(float *)((int)*param_1 + 0x90)));
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,iVar3 + 0xe4);
      if (*gpGlobals <= param_1[0x135]) {
        return;
      }
      pfStack_34 = param_1;
      lVar7 = (longdouble)FlYawDiff__12CBaseMonster();
      if ((longdouble)10.0 <= lVar7) {
        return;
      }
      goto LAB_000f1950;
    }
  }
  pfStack_34 = (float *)0x40000000;
  SetConditions__12CBaseMonsteri(param_1);
  return;
}


