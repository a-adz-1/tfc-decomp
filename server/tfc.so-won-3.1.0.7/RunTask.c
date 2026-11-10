// RunTask__12CBaseMonsterP6Task_t  @ 000e5a30
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RunTask__12CBaseMonsterP6Task_t(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  longdouble lVar6;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_4;
  
  switch(*param_2) {
  case 1:
  case 0x52:
    goto LAB_000e5e30;
  case 2:
    local_18 = (float)param_1[0x18d];
    local_14 = (float)param_1[0x18e];
    local_10 = (float)param_1[399];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_18);
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x111] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
LAB_000e5e30:
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x154];
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      return;
    }
    goto LAB_000e6225;
  case 3:
    iVar5 = (*DAT_001c1064)(*(undefined4 *)(*param_1 + 0x208));
    bVar3 = false;
    if ((iVar5 == 0) || (iVar5 = (*DAT_001c1138)(iVar5), iVar5 == 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      return;
    }
    goto LAB_000e6225;
  case 7:
    iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
    if (iVar5 == 0) {
      SetConditions__12CBaseMonsteri(param_1,0x40000000);
      return;
    }
    local_18 = (float)param_1[0x181] - *(float *)(*param_1 + 8);
    local_14 = (float)param_1[0x182] - *(float *)(*param_1 + 0xc);
    local_10 = (float)param_1[0x183] - *(float *)(*param_1 + 0x10);
    fStack_2c = SQRT(local_14 * local_14 + local_18 * local_18);
    fVar1 = (float)param_2[1];
    if ((byte)(fStack_2c < fVar1 |
               (byte)((ushort)((ushort)(NAN(fStack_2c) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_2c == fVar1) << 0xe) >> 8)) == 1) {
LAB_000e5f3c:
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      iVar5 = *piVar4;
      param_1[0x181] = *(int *)(iVar5 + 8);
      param_1[0x182] = *(int *)(iVar5 + 0xc);
      param_1[0x183] = *(int *)(iVar5 + 0x10);
      iVar5 = *param_1;
      fStack_28 = (float)param_1[0x181] - *(float *)(iVar5 + 8);
      fStack_24 = (float)param_1[0x182] - *(float *)(iVar5 + 0xc);
      fStack_20 = (float)param_1[0x183] - *(float *)(iVar5 + 0x10);
      fStack_2c = SQRT(fStack_24 * fStack_24 + fStack_28 * fStack_28);
      FRefreshRoute__12CBaseMonster(param_1);
    }
    else {
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      iVar5 = *piVar4;
      fStack_1c = (float)param_1[0x181] - *(float *)(iVar5 + 8);
      local_18 = (float)param_1[0x182] - *(float *)(iVar5 + 0xc);
      local_14 = (float)param_1[0x183] - *(float *)(iVar5 + 0x10);
      local_10 = SQRT(local_14 * local_14 + local_18 * local_18 + fStack_1c * fStack_1c);
      if ((float)param_2[1] * 0.5 < local_10) goto LAB_000e5f3c;
    }
    fVar1 = (float)param_2[1];
    if ((byte)(fStack_2c < fVar1 |
               (byte)((ushort)((ushort)(NAN(fStack_2c) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_2c == fVar1) << 0xe) >> 8)) == 1) {
LAB_000e6031:
      iVar5 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
      if (iVar5 == 0) {
        param_1[0x15b] = 4;
      }
      RouteClear__12CBaseMonster(param_1);
      switchD_000e5a5f::caseD_4();
      return;
    }
    if ((0x3f < (byte)((_FUN_0014c5c8 < fStack_2c |
                        (byte)((ushort)((ushort)(NAN(_FUN_0014c5c8) || NAN(fStack_2c)) << 10) >> 8)
                       | (byte)((ushort)((ushort)(_FUN_0014c5c8 == fStack_2c) << 0xe) >> 8)) - 1))
       && (param_1[0x184] != 3)) {
      param_1[0x184] = 3;
      switchD_000e5a5f::caseD_4();
      return;
    }
    if ((270.0 <= fStack_2c) && (param_1[0x184] != 4)) {
      param_1[0x184] = 4;
      switchD_000e5a5f::caseD_4();
      return;
    }
    break;
  case 0x18:
  case 0x1b:
  case 0x3d:
    goto code_r0x000e6218;
  case 0x1c:
  case 0x1d:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x55:
  case 0x56:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x111] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
    iVar5 = FacingIdeal__12CBaseMonster(param_1);
    goto joined_r0x000e5d47;
  case 0x1e:
    local_18 = (float)param_1[0x18d];
    local_14 = (float)param_1[0x18e];
    local_10 = (float)param_1[399];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_18);
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x111] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
    iVar5 = FacingIdeal__12CBaseMonster(param_1);
    goto joined_r0x000e5d47;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
    fStack_28 = (float)param_1[0x18d];
    fStack_24 = (float)param_1[0x18e];
    fStack_20 = (float)param_1[399];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&fStack_28);
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x111] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (param_1[0x117] == 0) {
      return;
    }
    param_1[0x156] = 0;
    goto LAB_000e6225;
  case 0x3e:
  case 0x3f:
    if (*param_2 == 0x3f) {
      piVar4 = param_1 + 0x13d;
    }
    else {
      piVar4 = param_1 + 0x13b;
    }
    piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4);
    if (piVar4 != (int *)0x0) {
      iVar5 = *piVar4;
      local_18 = *(float *)(iVar5 + 8) - *(float *)(*param_1 + 8);
      local_14 = *(float *)(iVar5 + 0xc) - *(float *)(*param_1 + 0xc);
      local_10 = *(float *)(iVar5 + 0x10) - *(float *)(*param_1 + 0x10);
      lVar6 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_18);
      *(float *)(*param_1 + 0xac) = (float)lVar6;
      local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
      local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
      (**(code **)(param_1[0x111] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
      switchD_000e5a5f::caseD_18();
      return;
    }
    goto code_r0x000e6218;
  case 0x4c:
    if ((param_1[0x117] != 0) && (255.0 <= *(float *)(*param_1 + 0x130))) {
      *(undefined4 *)(*param_1 + 0x170) = 2;
      param_1[3] = 0;
      param_1[4] = 0;
      *(undefined4 *)(*param_1 + 0x138) = 0;
      iVar5 = BBoxFlat__12CBaseMonster(param_1);
      if (iVar5 == 0) {
        fStack_28 = 4.0;
        fStack_20 = 1.0;
        fStack_1c = -4.0;
        local_14 = 0.0;
        iVar5 = *param_1;
        fStack_24 = fStack_28;
        local_18 = fStack_1c;
      }
      else {
        iVar5 = *param_1;
        fStack_20 = *(float *)(iVar5 + 0xe4) + 1.0;
        fStack_28 = *(float *)(iVar5 + 0xe8);
        fStack_24 = *(float *)(iVar5 + 0xec);
        fStack_1c = *(float *)(iVar5 + 0xdc);
        local_18 = *(float *)(iVar5 + 0xe0);
        local_14 = *(float *)(iVar5 + 0xe4);
      }
      UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar5,&fStack_1c,&fStack_28);
      iVar5 = (**(code **)(param_1[0x111] + 0x114))(param_1);
      if (iVar5 != 0) {
        SUB_StartFadeOut__11CBaseEntity(param_1);
        switchD_000e5a5f::caseD_4();
        return;
      }
      InsertSound__9CSoundEntiRC6Vectorif(8,*param_1 + 8,0x180,0x41f00000);
      switchD_000e5a5f::caseD_4();
      return;
    }
    break;
  case 0x4d:
    if (*(int *)(param_1[0x1a2] + 0x6a8) < 1) {
      fVar1 = *gpGlobals;
      fVar2 = *(float *)(param_1[0x1a2] + 0x6ac);
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        iVar5 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
        if (iVar5 == 0) {
          param_1[0x15b] = 4;
        }
        iVar5 = param_1[0x1a2];
        (**(code **)(*(int *)(iVar5 + 0x444) + 0x220))
                  (iVar5,param_1,*(undefined4 *)(iVar5 + 0x690),1);
        if (param_1[0x117] != 0) {
          ClearSchedule__12CBaseMonster(param_1);
        }
        *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
        switchD_000e5a5f::caseD_4();
        return;
      }
    }
    break;
  case 0x4e:
    if (param_1[0x117] != 0) {
      SequenceDone__12CCineMonsterP12CBaseMonster(param_1[0x1a2],param_1);
    }
    break;
  case 0x59:
    if (param_1[0x17e] != 0) {
      return;
    }
    goto LAB_000e6031;
  }
  return;
code_r0x000e6218:
  iVar5 = param_1[0x117];
joined_r0x000e5d47:
  if (iVar5 == 0) {
    return;
  }
LAB_000e6225:
  iVar5 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
  if (iVar5 != 0) {
    return;
  }
  param_1[0x15b] = 4;
  switchD_000e5a5f::caseD_4();
  return;
}


// RunTask__12CTalkMonsterP6Task_t  @ 000f4e3c
void RunTask__12CTalkMonsterP6Task_t(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  longdouble lVar6;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  switch(*param_2) {
  case 0x59:
    iVar3 = IsTalking__12CTalkMonster(param_1);
    if (iVar3 == 0) {
LAB_000f5230:
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*param_1 + 8);
      FIdleHello__12CTalkMonster(param_1);
      iVar3 = (*DAT_001c1188)(0,param_1[0x1a4] * 0x14);
      if (iVar3 == 0) {
        FIdleSpeak__12CTalkMonster(param_1);
      }
    }
    else {
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1bd);
      if (iVar3 == 0) goto LAB_000f5230;
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x1bd);
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
    }
    RunTask__12CBaseMonsterP6Task_t(param_1,param_2);
    if (param_1[0x15b] == 4) {
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*param_1 + 8);
    }
    break;
  default:
    iVar3 = IsTalking__12CTalkMonster(param_1);
    if (iVar3 == 0) {
LAB_000f52c4:
      SetBoneController__14CBaseAnimatingif(param_1,0,0);
    }
    else {
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1bd);
      if (iVar3 == 0) goto LAB_000f52c4;
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x1bd);
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
    }
    RunTask__12CBaseMonsterP6Task_t(param_1,param_2);
    break;
  case 0x5d:
    local_10 = (float)param_1[0x187] - *(float *)(*param_1 + 8);
    local_c = (float)param_1[0x188] - *(float *)(*param_1 + 0xc);
    local_8 = (float)param_1[0x189] - *(float *)(*param_1 + 0x10);
    local_4 = SQRT(local_c * local_c + local_10 * local_10);
    if (((float)param_2[1] < local_4) || (param_1[0x17e] == 0)) {
      iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
      if (iVar3 == 0) {
        param_1[0x15b] = 4;
      }
      RouteClear__12CBaseMonster(param_1);
    }
    break;
  case 100:
  case 0x65:
    if (((param_1[0x159] == 1) &&
        (iVar3 = (**(code **)(param_1[0x111] + 0x6c))(param_1), iVar3 == 0)) &&
       (iVar3 = IsTalking__12CTalkMonster(param_1), iVar3 == 0)) {
      iVar3 = (*DAT_001c1140)(1);
      if (iVar3 != 0) {
        IdleHeadTurn__12CTalkMonsterR6Vector(param_1,iVar3 + 0x88);
      }
      if (*param_2 == 0x65) {
        local_c = *(float *)(iVar3 + 0x88) - *(float *)(*param_1 + 8);
        local_8 = *(float *)(iVar3 + 0x8c) - *(float *)(*param_1 + 0xc);
        local_4 = *(float *)(iVar3 + 0x90) - *(float *)(*param_1 + 0x10);
        local_10 = SQRT(local_8 * local_8 + local_c * local_c);
        if (128.0 < local_10) {
          SetConditions__12CBaseMonsteri(param_1,0x40000000);
        }
        UTIL_MakeVectors__FRC6Vector(iVar3 + 0xd0);
        lVar5 = (longdouble)UTIL_DotPoints__FRC6VectorN20(iVar3 + 0x88,*param_1 + 8,gpGlobals + 10);
        if (lVar5 < (longdouble)(float)param_1[0x153]) {
          SetConditions__12CBaseMonsteri(param_1,0x40000000);
        }
      }
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x154];
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
      FUN_000f5148();
      return;
    }
    goto LAB_000f50e8;
  case 0x66:
    iVar3 = (**(code **)(param_1[0x111] + 0x6c))(param_1);
    if ((iVar3 == 0) && (iVar3 = IsTalking__12CTalkMonster(param_1), iVar3 != 0)) {
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1bd);
      if (iVar3 != 0) {
        piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x1bd);
        IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
        return;
      }
    }
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x15b] = 4;
    }
    break;
  case 0x68:
    iVar3 = (*DAT_001c1140)(1);
    if (iVar3 != 0) {
      local_10 = *(float *)(iVar3 + 0x88);
      local_c = *(float *)(iVar3 + 0x8c);
      local_8 = *(float *)(iVar3 + 0x90);
      MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_10);
      (**(code **)(param_1[0x111] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,iVar3 + 0x88);
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x154];
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
      lVar5 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
      lVar6 = (longdouble)10.0;
      if ((byte)((lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
      FUN_000f5148();
      return;
    }
LAB_000f50e8:
    SetConditions__12CBaseMonsteri(param_1,0x40000000);
  }
  return;
}


