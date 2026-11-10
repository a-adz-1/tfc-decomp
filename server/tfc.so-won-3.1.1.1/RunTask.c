// RunTask__12CBaseMonsterP6Task_t  @ 000e6d40
void RunTask__12CBaseMonsterP6Task_t(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined2 in_FPUControlWord;
  longdouble lVar7;
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
    goto LAB_000e70d7;
  case 2:
    local_1c = (float)param_1[0x191];
    local_18 = (float)param_1[0x192];
    local_14 = (float)param_1[0x193];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_1c);
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x115] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
LAB_000e70d7:
    if (*gpGlobals < (float)param_1[0x158]) {
      return;
    }
    goto LAB_000e7481;
  case 3:
    iVar6 = (*DAT_0019f6e4)(*(undefined4 *)(*param_1 + 0x208));
    bVar3 = false;
    if ((iVar6 == 0) || (iVar6 = (*DAT_0019f7b8)(iVar6), iVar6 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      return;
    }
    goto LAB_000e7481;
  case 7:
    piVar4 = param_1 + 0x141;
    iVar6 = __opP11CBaseEntity__7EHANDLE(piVar4);
    if (iVar6 == 0) {
      SetConditions__12CBaseMonsteri(param_1,0x40000000);
      switchD_000e6d74::caseD_4();
      return;
    }
    local_1c = (float)param_1[0x185] - *(float *)(*param_1 + 8);
    local_18 = (float)param_1[0x186] - *(float *)(*param_1 + 0xc);
    local_14 = (float)param_1[0x187] - *(float *)(*param_1 + 0x10);
    local_30 = SQRT(local_18 * local_18 + local_1c * local_1c);
    fVar1 = (float)param_2[1];
    if ((byte)(local_30 < fVar1 | (byte)((ushort)((ushort)(NAN(local_30) || NAN(fVar1)) << 10) >> 8)
              | (byte)((ushort)((ushort)(local_30 == fVar1) << 0xe) >> 8)) == 1) {
LAB_000e71d9:
      piVar4 = (int *)__rf__7EHANDLE(piVar4);
      iVar6 = *piVar4;
      param_1[0x185] = *(int *)(iVar6 + 8);
      param_1[0x186] = *(int *)(iVar6 + 0xc);
      param_1[0x187] = *(int *)(iVar6 + 0x10);
      local_2c = (float)param_1[0x185] - *(float *)(*param_1 + 8);
      local_28 = (float)param_1[0x186] - *(float *)(*param_1 + 0xc);
      local_24 = (float)param_1[0x187] - *(float *)(*param_1 + 0x10);
      local_30 = SQRT(local_28 * local_28 + local_2c * local_2c);
      FRefreshRoute__12CBaseMonster(param_1);
      fVar1 = (float)param_2[1];
    }
    else {
      piVar5 = (int *)__rf__7EHANDLE(piVar4);
      iVar6 = *piVar5;
      local_20 = (float)param_1[0x185] - *(float *)(iVar6 + 8);
      local_1c = (float)param_1[0x186] - *(float *)(iVar6 + 0xc);
      local_18 = (float)param_1[0x187] - *(float *)(iVar6 + 0x10);
      local_14 = SQRT(local_18 * local_18 + local_1c * local_1c + local_20 * local_20);
      fVar1 = (float)param_2[1];
      fVar2 = fVar1 * 0.5;
      if (0x3f < (byte)((local_14 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(local_14) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_14 == fVar2) << 0xe) >> 8)) - 1))
      goto LAB_000e71d9;
    }
    if (local_30 < fVar1) {
LAB_000e72c1:
      iVar6 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
      if (iVar6 == 0) {
        param_1[0x15f] = 4;
      }
      RouteClear__12CBaseMonster(param_1);
      switchD_000e6d74::caseD_4();
      return;
    }
    if ((0x3f < (byte)((190.0 < local_30 | (byte)((ushort)((ushort)NAN(local_30) << 10) >> 8) |
                       (byte)((ushort)((ushort)(local_30 == 190.0) << 0xe) >> 8)) - 1)) &&
       (param_1[0x188] != 3)) {
      param_1[0x188] = 3;
      switchD_000e6d74::caseD_4();
      return;
    }
    if ((270.0 <= local_30) && (param_1[0x188] != 4)) {
      param_1[0x188] = 4;
      switchD_000e6d74::caseD_4();
      return;
    }
    break;
  case 0x18:
  case 0x1b:
  case 0x3d:
    goto code_r0x000e7474;
  case 0x1c:
  case 0x1d:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x55:
  case 0x56:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x115] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
    iVar6 = FacingIdeal__12CBaseMonster(param_1);
    goto joined_r0x000e701a;
  case 0x1e:
    local_1c = (float)param_1[0x191];
    local_18 = (float)param_1[0x192];
    local_14 = (float)param_1[0x193];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_1c);
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x115] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
    iVar6 = FacingIdeal__12CBaseMonster(param_1);
    goto joined_r0x000e701a;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
    local_2c = (float)param_1[0x191];
    local_28 = (float)param_1[0x192];
    local_24 = (float)param_1[0x193];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_2c);
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x115] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (param_1[0x11b] == 0) {
      return;
    }
    param_1[0x15a] = 0;
    goto LAB_000e7481;
  case 0x3e:
  case 0x3f:
    if (*param_2 == 0x3f) {
      piVar4 = param_1 + 0x141;
    }
    else {
      piVar4 = param_1 + 0x13f;
    }
    piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4);
    if (piVar4 != (int *)0x0) {
      iVar6 = *piVar4;
      local_1c = *(float *)(iVar6 + 8) - *(float *)(*param_1 + 8);
      local_18 = *(float *)(iVar6 + 0xc) - *(float *)(*param_1 + 0xc);
      local_14 = *(float *)(iVar6 + 0x10) - *(float *)(*param_1 + 0x10);
      lVar7 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_1c);
      *(float *)(*param_1 + 0xac) = (float)lVar7;
      local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
      local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
      (**(code **)(param_1[0x115] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
      switchD_000e6d74::caseD_18();
      return;
    }
    goto code_r0x000e7474;
  case 0x4c:
    if ((param_1[0x11b] != 0) && (255.0 <= *(float *)(*param_1 + 0x130))) {
      *(undefined4 *)(*param_1 + 0x170) = 2;
      param_1[3] = 0;
      param_1[4] = 0;
      *(undefined4 *)(*param_1 + 0x138) = 0;
      iVar6 = BBoxFlat__12CBaseMonster(param_1);
      if (iVar6 == 0) {
        local_2c = 4.0;
        local_24 = 1.0;
        local_20 = -4.0;
        local_18 = 0.0;
        iVar6 = *param_1;
        local_28 = local_2c;
        local_1c = local_20;
      }
      else {
        iVar6 = *param_1;
        local_24 = *(float *)(iVar6 + 0xe4) + 1.0;
        local_2c = *(float *)(iVar6 + 0xe8);
        local_28 = *(float *)(iVar6 + 0xec);
        local_20 = *(float *)(iVar6 + 0xdc);
        local_1c = *(float *)(iVar6 + 0xe0);
        local_18 = *(float *)(iVar6 + 0xe4);
      }
      UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar6,&local_20,&local_2c);
      iVar6 = (**(code **)(param_1[0x115] + 0x114))(param_1);
      if (iVar6 != 0) {
        SUB_StartFadeOut__11CBaseEntity(param_1);
        switchD_000e6d74::caseD_4();
        return;
      }
      InsertSound__9CSoundEntiRC6Vectorif(8,*param_1 + 8,0x180,0x41f00000);
      switchD_000e6d74::caseD_4();
      return;
    }
    break;
  case 0x4d:
    if ((*(int *)(param_1[0x1a6] + 0x6b8) < 1) && (*(float *)(param_1[0x1a6] + 0x6bc) <= *gpGlobals)
       ) {
      iVar6 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
      if (iVar6 == 0) {
        param_1[0x15f] = 4;
      }
      iVar6 = param_1[0x1a6];
      (**(code **)(*(int *)(iVar6 + 0x454) + 0x220))(iVar6,param_1,*(undefined4 *)(iVar6 + 0x6a0),1)
      ;
      if (param_1[0x11b] != 0) {
        param_1[0x15f] = 0;
        param_1[0x160] = 0;
        param_1[0x161] = 0;
      }
      *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
      switchD_000e6d74::caseD_4();
      return;
    }
    break;
  case 0x4e:
    if (param_1[0x11b] != 0) {
      SequenceDone__12CCineMonsterP12CBaseMonster(param_1[0x1a6],param_1);
    }
    break;
  case 0x59:
    if (param_1[0x182] != 0) {
      return;
    }
    goto LAB_000e72c1;
  }
  return;
code_r0x000e7474:
  iVar6 = param_1[0x11b];
joined_r0x000e701a:
  if (iVar6 == 0) {
    return;
  }
LAB_000e7481:
  iVar6 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
  if (iVar6 != 0) {
    return;
  }
  param_1[0x15f] = 4;
  switchD_000e6d74::caseD_4();
  return;
}


// RunTask__12CTalkMonsterP6Task_t  @ 000f6f78
void RunTask__12CTalkMonsterP6Task_t(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  float **ppfVar5;
  longdouble lVar6;
  longdouble lVar7;
  float *pfStack_38;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  switch(*param_2) {
  case 1.24716e-43:
    pfStack_38 = param_1;
    iVar3 = IsTalking__12CTalkMonster();
    if (iVar3 == 0) {
LAB_000f7304:
      pfStack_38 = (float *)((int)*param_1 + 8);
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1);
      FIdleHello__12CTalkMonster(param_1);
      iVar3 = (*DAT_0019f808)(0,(int)param_1[0x1a8] * 0x14);
      if (iVar3 == 0) {
        pfStack_38 = param_1;
        FIdleSpeak__12CTalkMonster();
      }
    }
    else {
      pfStack_38 = param_1 + 0x1c1;
      iVar3 = __opP11CBaseEntity__7EHANDLE();
      if (iVar3 == 0) goto LAB_000f7304;
      pfStack_38 = param_1 + 0x1c1;
      piVar4 = (int *)__rf__7EHANDLE();
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
    }
    ppfVar5 = (float **)&stack0xffffffcc;
    pfStack_38 = param_2;
    RunTask__12CBaseMonsterP6Task_t(param_1);
    if (param_1[0x15f] != 5.60519e-45) {
      return;
    }
    fVar2 = *param_1;
LAB_000f735b:
    *(int *)((int)ppfVar5 + -4) = (int)fVar2 + 8;
    *(float **)((int)ppfVar5 + -8) = param_1;
    *(undefined4 *)((int)ppfVar5 + -0xc) = 0xf7365;
    IdleHeadTurn__12CTalkMonsterR6Vector();
    return;
  default:
    pfStack_38 = param_1;
    iVar3 = IsTalking__12CTalkMonster();
    if (iVar3 != 0) {
      pfStack_38 = param_1 + 0x1c1;
      iVar3 = __opP11CBaseEntity__7EHANDLE();
      if (iVar3 != 0) {
        pfStack_38 = param_1 + 0x1c1;
        piVar4 = (int *)__rf__7EHANDLE();
        IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
        goto LAB_000f73a8;
      }
    }
    pfStack_38 = (float *)0x0;
    SetBoneController__14CBaseAnimatingif(param_1,0);
LAB_000f73a8:
    pfStack_38 = param_2;
    RunTask__12CBaseMonsterP6Task_t(param_1);
    return;
  case 1.30321e-43:
    local_14 = param_1[0x18b] - *(float *)((int)*param_1 + 8);
    local_10 = param_1[0x18c] - *(float *)((int)*param_1 + 0xc);
    local_c = param_1[0x18d] - *(float *)((int)*param_1 + 0x10);
    local_8 = SQRT(local_10 * local_10 + local_14 * local_14);
    if ((local_8 <= param_2[1]) && (param_1[0x182] != 0.0)) {
      return;
    }
    pfStack_38 = (float *)0x40000000;
    iVar3 = HasConditions__12CBaseMonsteri(param_1);
    if (iVar3 == 0) {
      param_1[0x15f] = 5.60519e-45;
    }
    pfStack_38 = param_1;
    RouteClear__12CBaseMonster();
    return;
  case 1.4013e-43:
  case 1.41531e-43:
    if (param_1[0x15d] == 1.4013e-45) {
      pfStack_38 = param_1;
      iVar3 = (**(code **)((int)param_1[0x115] + 0x6c))();
      if (iVar3 == 0) {
        pfStack_38 = param_1;
        iVar3 = IsTalking__12CTalkMonster();
        if (iVar3 == 0) {
          pfStack_38 = (float *)0x1;
          iVar3 = (*DAT_0019f7c0)();
          if (iVar3 != 0) {
            pfStack_38 = (float *)(iVar3 + 0x88);
            IdleHeadTurn__12CTalkMonsterR6Vector(param_1);
          }
          if (*param_2 == 1.41531e-43) {
            local_10 = *(float *)(iVar3 + 0x88) - *(float *)((int)*param_1 + 8);
            local_c = *(float *)(iVar3 + 0x8c) - *(float *)((int)*param_1 + 0xc);
            local_8 = *(float *)(iVar3 + 0x90) - *(float *)((int)*param_1 + 0x10);
            local_14 = SQRT(local_c * local_c + local_10 * local_10);
            if (128.0 < local_14) {
              pfStack_38 = (float *)0x40000000;
              SetConditions__12CBaseMonsteri(param_1);
            }
            pfStack_38 = (float *)(iVar3 + 0xd0);
            UTIL_MakeVectors__FRC6Vector();
            lVar6 = (longdouble)
                    UTIL_DotPoints__FRC6VectorN20(iVar3 + 0x88,(int)*param_1 + 8,gpGlobals + 10);
            if (lVar6 < (longdouble)param_1[0x157]) {
              pfStack_38 = (float *)0x40000000;
              SetConditions__12CBaseMonsteri(param_1);
            }
          }
          if (*gpGlobals <= param_1[0x158]) {
            return;
          }
          goto LAB_000f7228;
        }
      }
    }
    break;
  case 1.42932e-43:
    pfStack_38 = param_1;
    iVar3 = (**(code **)((int)param_1[0x115] + 0x6c))();
    if (iVar3 != 0) {
LAB_000f7228:
      pfStack_38 = (float *)0x40000000;
      iVar3 = HasConditions__12CBaseMonsteri(param_1);
      if (iVar3 != 0) {
        return;
      }
      param_1[0x15f] = 5.60519e-45;
      return;
    }
    pfStack_38 = param_1;
    iVar3 = IsTalking__12CTalkMonster();
    if (iVar3 == 0) goto LAB_000f7228;
    pfStack_38 = param_1 + 0x1c1;
    iVar3 = __opP11CBaseEntity__7EHANDLE();
    if (iVar3 == 0) goto LAB_000f7228;
    ppfVar5 = &pfStack_38;
    pfStack_38 = param_1 + 0x1c1;
    pfVar1 = (float *)__rf__7EHANDLE();
    fVar2 = *pfVar1;
    goto LAB_000f735b;
  case 1.45735e-43:
    pfStack_38 = (float *)0x1;
    iVar3 = (*DAT_0019f7c0)();
    if (iVar3 != 0) {
      pfStack_38 = &local_14;
      local_14 = *(float *)(iVar3 + 0x88);
      local_10 = *(float *)(iVar3 + 0x8c);
      local_c = *(float *)(iVar3 + 0x90);
      MakeIdealYaw__12CBaseMonsterG6Vector(param_1);
      (**(code **)((int)param_1[0x115] + 0x118))
                (param_1,(int)ROUND(*(float *)((int)*param_1 + 0xb0)));
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,iVar3 + 0x88);
      if (*gpGlobals <= param_1[0x158]) {
        return;
      }
      pfStack_38 = param_1;
      lVar6 = (longdouble)FlYawDiff__12CBaseMonster();
      lVar7 = (longdouble)10.0;
      if ((byte)((lVar7 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
      goto LAB_000f7228;
    }
  }
  pfStack_38 = (float *)0x40000000;
  SetConditions__12CBaseMonsteri(param_1);
  return;
}


