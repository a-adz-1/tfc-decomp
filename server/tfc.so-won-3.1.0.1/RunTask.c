// RunTask__12CBaseMonsterP6Task_t  @ 000d9994
void RunTask__12CBaseMonsterP6Task_t(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  longdouble lVar6;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  switch(*param_2) {
  case 1:
  case 0x52:
    goto LAB_000d9d94;
  case 2:
    local_18 = (float)param_1[0x171];
    local_14 = (float)param_1[0x172];
    local_10 = (float)param_1[0x173];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_18);
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf5] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
LAB_000d9d94:
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x138];
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      FUN_000da189();
      return;
    }
    break;
  case 3:
    iVar5 = (*DAT_001a7e84)(*(undefined4 *)(*param_1 + 0x208));
    bVar3 = false;
    if ((iVar5 == 0) || (iVar5 = (*DAT_001a7f58)(iVar5), iVar5 == 0)) {
      bVar3 = true;
    }
    if (!bVar3) {
      FUN_000da189();
      return;
    }
    break;
  case 7:
    iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
    if (iVar5 == 0) {
      SetConditions__12CBaseMonsteri(param_1,0x40000000);
      return;
    }
    local_18 = (float)param_1[0x165] - *(float *)(*param_1 + 8);
    local_14 = (float)param_1[0x166] - *(float *)(*param_1 + 0xc);
    local_10 = (float)param_1[0x167] - *(float *)(*param_1 + 0x10);
    local_2c = SQRT(local_14 * local_14 + local_18 * local_18);
    fVar1 = (float)param_2[1];
    if ((byte)(local_2c < fVar1 | (byte)((ushort)((ushort)(NAN(local_2c) || NAN(fVar1)) << 10) >> 8)
              | (byte)((ushort)((ushort)(local_2c == fVar1) << 0xe) >> 8)) == 1) {
LAB_000d9ea0:
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x121);
      iVar5 = *piVar4;
      param_1[0x165] = *(int *)(iVar5 + 8);
      param_1[0x166] = *(int *)(iVar5 + 0xc);
      param_1[0x167] = *(int *)(iVar5 + 0x10);
      iVar5 = *param_1;
      local_28 = (float)param_1[0x165] - *(float *)(iVar5 + 8);
      local_24 = (float)param_1[0x166] - *(float *)(iVar5 + 0xc);
      local_20 = (float)param_1[0x167] - *(float *)(iVar5 + 0x10);
      local_2c = SQRT(local_24 * local_24 + local_28 * local_28);
      FRefreshRoute__12CBaseMonster(param_1);
    }
    else {
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x121);
      iVar5 = *piVar4;
      local_1c = (float)param_1[0x165] - *(float *)(iVar5 + 8);
      local_18 = (float)param_1[0x166] - *(float *)(iVar5 + 0xc);
      local_14 = (float)param_1[0x167] - *(float *)(iVar5 + 0x10);
      local_10 = SQRT(local_14 * local_14 + local_18 * local_18 + local_1c * local_1c);
      if ((float)param_2[1] * 0.5 < local_10) goto LAB_000d9ea0;
    }
    fVar1 = (float)param_2[1];
    if ((byte)(local_2c < fVar1 | (byte)((ushort)((ushort)(NAN(local_2c) || NAN(fVar1)) << 10) >> 8)
              | (byte)((ushort)((ushort)(local_2c == fVar1) << 0xe) >> 8)) == 1) {
LAB_000d9f95:
      iVar5 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
      if (iVar5 == 0) {
        param_1[0x13f] = 4;
      }
      RouteClear__12CBaseMonster(param_1);
      switchD_000d99c3::caseD_4();
      return;
    }
    if (((byte)((190.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 190.0) << 0xe) >> 8)) - 1) < 0x40) ||
       (param_1[0x168] == 3)) {
      if ((270.0 <= local_2c) && (param_1[0x168] != 4)) {
        param_1[0x168] = 4;
        switchD_000d99c3::caseD_4();
        return;
      }
    }
    else {
      param_1[0x168] = 3;
    }
    break;
  case 0x18:
  case 0x1b:
  case 0x3d:
    goto code_r0x000da17c;
  case 0x1c:
  case 0x1d:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x55:
  case 0x56:
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf5] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
    iVar5 = FacingIdeal__12CBaseMonster(param_1);
    goto LAB_000d9ca9;
  case 0x1e:
    local_18 = (float)param_1[0x171];
    local_14 = (float)param_1[0x172];
    local_10 = (float)param_1[0x173];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_18);
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf5] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
    iVar5 = FacingIdeal__12CBaseMonster(param_1);
LAB_000d9ca9:
    if (iVar5 != 0) {
      FUN_000da189();
      return;
    }
    break;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
    local_28 = (float)param_1[0x171];
    local_24 = (float)param_1[0x172];
    local_20 = (float)param_1[0x173];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_28);
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf5] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (param_1[0xfb] != 0) {
      param_1[0x13a] = 0;
      FUN_000da189();
      return;
    }
    break;
  case 0x3e:
  case 0x3f:
    if (*param_2 == 0x3f) {
      piVar4 = param_1 + 0x121;
    }
    else {
      piVar4 = param_1 + 0x11f;
    }
    piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4);
    if (piVar4 != (int *)0x0) {
      iVar5 = *piVar4;
      local_18 = *(float *)(iVar5 + 8) - *(float *)(*param_1 + 8);
      local_14 = *(float *)(iVar5 + 0xc) - *(float *)(*param_1 + 0xc);
      local_10 = *(float *)(iVar5 + 0x10) - *(float *)(*param_1 + 0x10);
      lVar6 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_18);
      *(float *)(*param_1 + 0xac) = (float)lVar6;
      _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
      local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      (**(code **)(param_1[0xf5] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
      switchD_000d99c3::caseD_18();
      return;
    }
    goto code_r0x000da17c;
  case 0x4c:
    if ((param_1[0xfb] != 0) && (255.0 <= *(float *)(*param_1 + 0x130))) {
      *(undefined4 *)(*param_1 + 0x170) = 2;
      param_1[3] = 0;
      param_1[4] = 0;
      *(undefined4 *)(*param_1 + 0x138) = 0;
      iVar5 = BBoxFlat__12CBaseMonster(param_1);
      if (iVar5 == 0) {
        local_28 = 4.0;
        local_20 = 1.0;
        local_1c = -4.0;
        local_14 = 0.0;
        iVar5 = *param_1;
        local_24 = local_28;
        local_18 = local_1c;
      }
      else {
        iVar5 = *param_1;
        local_20 = *(float *)(iVar5 + 0xe4) + 1.0;
        local_28 = *(float *)(iVar5 + 0xe8);
        local_24 = *(float *)(iVar5 + 0xec);
        local_1c = *(float *)(iVar5 + 0xdc);
        local_18 = *(float *)(iVar5 + 0xe0);
        local_14 = *(float *)(iVar5 + 0xe4);
      }
      UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar5,&local_1c,&local_28);
      iVar5 = (**(code **)(param_1[0xf5] + 0x10c))(param_1);
      if (iVar5 == 0) {
        InsertSound__9CSoundEntiRC6Vectorif(8,*param_1 + 8,0x180,0x41f00000);
        switchD_000d99c3::caseD_4();
        return;
      }
      SUB_StartFadeOut__11CBaseEntity(param_1);
      switchD_000d99c3::caseD_4();
      return;
    }
    break;
  case 0x4d:
    if (*(int *)(param_1[0x186] + 0x638) < 1) {
      fVar1 = *gpGlobals;
      fVar2 = *(float *)(param_1[0x186] + 0x63c);
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        iVar5 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
        if (iVar5 == 0) {
          param_1[0x13f] = 4;
        }
        iVar5 = param_1[0x186];
        (**(code **)(*(int *)(iVar5 + 0x3d4) + 0x218))
                  (iVar5,param_1,*(undefined4 *)(iVar5 + 0x620),1);
        if (param_1[0xfb] != 0) {
          ClearSchedule__12CBaseMonster(param_1);
        }
        *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
        switchD_000d99c3::caseD_4();
        return;
      }
    }
    break;
  case 0x4e:
    if (param_1[0xfb] != 0) {
      SequenceDone__12CCineMonsterP12CBaseMonster(param_1[0x186],param_1);
    }
    break;
  case 0x59:
    if (param_1[0x162] != 0) {
      return;
    }
    goto LAB_000d9f95;
  }
  return;
code_r0x000da17c:
  if (param_1[0xfb] == 0) {
    return;
  }
  iVar5 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
  if (iVar5 != 0) {
    return;
  }
  param_1[0x13f] = 4;
  switchD_000d99c3::caseD_4();
  return;
}


// RunTask__12CTalkMonsterP6Task_t  @ 000e8168
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
LAB_000e855c:
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*param_1 + 8);
      FIdleHello__12CTalkMonster(param_1);
      iVar3 = (*DAT_001a7fa8)(0,param_1[0x188] * 0x14);
      if (iVar3 == 0) {
        FIdleSpeak__12CTalkMonster(param_1);
      }
    }
    else {
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a1);
      if (iVar3 == 0) goto LAB_000e855c;
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x1a1);
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
    }
    RunTask__12CBaseMonsterP6Task_t(param_1,param_2);
    if (param_1[0x13f] == 4) {
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*param_1 + 8);
    }
    break;
  default:
    iVar3 = IsTalking__12CTalkMonster(param_1);
    if (iVar3 == 0) {
LAB_000e85f0:
      SetBoneController__14CBaseAnimatingif(param_1,0,0);
    }
    else {
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a1);
      if (iVar3 == 0) goto LAB_000e85f0;
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x1a1);
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
    }
    RunTask__12CBaseMonsterP6Task_t(param_1,param_2);
    break;
  case 0x5d:
    local_10 = (float)param_1[0x16b] - *(float *)(*param_1 + 8);
    local_c = (float)param_1[0x16c] - *(float *)(*param_1 + 0xc);
    local_8 = (float)param_1[0x16d] - *(float *)(*param_1 + 0x10);
    local_4 = SQRT(local_c * local_c + local_10 * local_10);
    if (((float)param_2[1] < local_4) || (param_1[0x162] == 0)) {
      iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
      if (iVar3 == 0) {
        param_1[0x13f] = 4;
      }
      RouteClear__12CBaseMonster(param_1);
    }
    break;
  case 100:
  case 0x65:
    if (((param_1[0x13d] == 1) && (iVar3 = (**(code **)(param_1[0xf5] + 0x68))(param_1), iVar3 == 0)
        ) && (iVar3 = IsTalking__12CTalkMonster(param_1), iVar3 == 0)) {
      iVar3 = (*DAT_001a7f60)(1);
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
        if (lVar5 < (longdouble)(float)param_1[0x137]) {
          SetConditions__12CBaseMonsteri(param_1,0x40000000);
        }
      }
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x138];
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
      FUN_000e8474();
      return;
    }
    goto LAB_000e8414;
  case 0x66:
    iVar3 = (**(code **)(param_1[0xf5] + 0x68))(param_1);
    if ((iVar3 == 0) && (iVar3 = IsTalking__12CTalkMonster(param_1), iVar3 != 0)) {
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a1);
      if (iVar3 != 0) {
        piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x1a1);
        IdleHeadTurn__12CTalkMonsterR6Vector(param_1,*piVar4 + 8);
        return;
      }
    }
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x13f] = 4;
    }
    break;
  case 0x68:
    iVar3 = (*DAT_001a7f60)(1);
    if (iVar3 != 0) {
      local_10 = *(float *)(iVar3 + 0x88);
      local_c = *(float *)(iVar3 + 0x8c);
      local_8 = *(float *)(iVar3 + 0x90);
      MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_10);
      (**(code **)(param_1[0xf5] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
      IdleHeadTurn__12CTalkMonsterR6Vector(param_1,iVar3 + 0x88);
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x138];
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
      FUN_000e8474();
      return;
    }
LAB_000e8414:
    SetConditions__12CBaseMonsteri(param_1,0x40000000);
  }
  return;
}


