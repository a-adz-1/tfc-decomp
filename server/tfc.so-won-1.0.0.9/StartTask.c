// StartTask__12CBaseMonsterP6Task_t  @ 000e56f0
void StartTask__12CBaseMonsterP6Task_t(int *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  undefined1 uVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  undefined1 *puVar9;
  undefined2 in_FPUControlWord;
  longdouble lVar10;
  float fVar11;
  float local_68;
  float local_50;
  float local_38;
  float local_34;
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
  
  uVar3 = (undefined1)in_FPUControlWord;
  puVar9 = &stack0xffffff74;
  switch(*param_2) {
  case 1:
  case 2:
    param_1[0x135] = (int)(*gpGlobals + (float)param_2[1]);
    break;
  case 3:
  case 0x53:
    break;
  case 4:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar3));
    param_1[0x13b] = (int)ROUND((float)param_2[1]);
    goto code_r0x000e699d;
  case 5:
  case 6:
    piVar8 = (int *)__rf__7EHANDLE();
    iVar6 = *piVar8;
    local_28 = *(float *)(iVar6 + 8) - *(float *)(*param_1 + 8);
    local_24 = *(float *)(iVar6 + 0xc) - *(float *)(*param_1 + 0xc);
    local_20 = *(float *)(iVar6 + 0x10) - *(float *)(*param_1 + 0x10);
    local_1c = SQRT(local_20 * local_20 + local_24 * local_24 + local_28 * local_28);
    if ((local_1c < 1.0) || (iVar6 = LookupActivity__14CBaseAnimatingi(), iVar6 == -1)) {
      iVar6 = HasConditions__12CBaseMonsteri();
      if (iVar6 == 0) {
        param_1[0x13c] = 4;
        FUN_000e69ca();
        return;
      }
    }
    else {
      iVar6 = __opP11CBaseEntity__7EHANDLE();
      if ((iVar6 == 0) || (iVar6 = MoveToTarget__12CBaseMonster8Activityf(param_1), iVar6 == 0)) {
        SetConditions__12CBaseMonsteri();
        (*DAT_001755b4)(2);
        RouteClear__12CBaseMonster(param_1);
        FUN_000e69ca();
        return;
      }
    }
    goto code_r0x000e69ca;
  case 7:
    piVar8 = (int *)__rf__7EHANDLE();
    iVar6 = *piVar8;
    local_28 = *(float *)(iVar6 + 8) - *(float *)(*param_1 + 8);
    local_24 = *(float *)(iVar6 + 0xc) - *(float *)(*param_1 + 0xc);
    local_20 = *(float *)(iVar6 + 0x10) - *(float *)(*param_1 + 0x10);
    local_1c = SQRT(local_20 * local_20 + local_24 * local_24 + local_28 * local_28);
    if (1.0 <= local_1c) {
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
      param_1[0x162] = *(int *)(iVar6 + 8);
      param_1[0x163] = *(int *)(iVar6 + 0xc);
      param_1[0x164] = *(int *)(iVar6 + 0x10);
      iVar6 = MoveToTarget__12CBaseMonster8Activityf(param_1,3);
      if (iVar6 != 0) {
        return;
      }
      goto LAB_000e6517;
    }
    goto code_r0x000e69ca;
  case 8:
    piVar8 = (int *)__opP11CBaseEntity__7EHANDLE();
    if (piVar8 == (int *)0x0) goto LAB_000e6517;
    iVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,*piVar8 + 8);
    if (iVar6 == 0) {
      iVar6 = *piVar8;
      local_38 = *(float *)(iVar6 + 8);
      local_34 = *(float *)(iVar6 + 0xc);
      local_30 = *(float *)(iVar6 + 0x10);
      iVar6 = *piVar8;
      local_2c = *(float *)(iVar6 + 0x154);
      local_28 = *(float *)(iVar6 + 0x158);
      local_24 = *(float *)(iVar6 + 0x15c);
      iVar6 = *piVar8;
      iVar4 = *param_1;
      local_20 = *(float *)(iVar6 + 8) - *(float *)(iVar4 + 8);
      local_1c = *(float *)(iVar6 + 0xc) - *(float *)(iVar4 + 0xc);
      local_18 = *(float *)(iVar6 + 0x10) - *(float *)(iVar4 + 0x10);
      local_14 = SQRT(local_18 * local_18 + local_1c * local_1c + local_20 * local_20);
      iVar6 = (**(code **)(param_1[0xf2] + 0x1a4))(param_1,&local_38,&local_2c);
      if (iVar6 == 0) {
        FUN_000e650b();
        return;
      }
    }
    goto code_r0x000e69ca;
  case 9:
    iVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x16e);
    if (iVar6 == 0) {
      local_28 = (float)param_1[0x16e];
      local_24 = (float)param_1[0x16f];
      local_20 = (float)param_1[0x170];
      iVar6 = *param_1;
      local_1c = *(float *)(iVar6 + 0x154);
      local_18 = *(float *)(iVar6 + 0x158);
      local_14 = *(float *)(iVar6 + 0x15c);
      local_34 = (float)param_1[0x16e] - *(float *)(iVar6 + 8);
      local_30 = (float)param_1[0x16f] - *(float *)(iVar6 + 0xc);
      local_2c = (float)param_1[0x170] - *(float *)(iVar6 + 0x10);
      local_38 = SQRT(local_2c * local_2c + local_30 * local_30 + local_34 * local_34);
      iVar6 = (**(code **)(param_1[0xf2] + 0x1a4))(param_1,&local_28,&local_1c);
      if (iVar6 == 0) {
        FUN_000e650b();
        return;
      }
    }
    goto code_r0x000e69ca;
  case 10:
    UTIL_MakeVectors__FRC6Vector();
    local_2c = gpGlobals[10] * 64.0;
    local_28 = gpGlobals[0xb] * 64.0;
    local_24 = gpGlobals[0xc] * 64.0;
    local_38 = (float)param_1[0x16e] - local_2c;
    local_34 = (float)param_1[0x16f] - local_28;
    local_30 = (float)param_1[0x170] - local_24;
    iVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,&local_38);
    if (iVar6 == 0) {
      FUN_000e650b();
      return;
    }
    goto code_r0x000e69ca;
  default:
    (*DAT_001755b4)(2);
    break;
  case 0xc:
    iVar6 = (*DAT_001754f8)(0);
    if (iVar6 == 0) {
      (*DAT_001755d4)();
    }
    iVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x162);
    goto LAB_000e63ee;
  case 0xd:
    RouteClear__12CBaseMonster();
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 == 0) goto LAB_000e63f6;
    iVar6 = MoveToTarget__12CBaseMonster8Activityf(param_1);
LAB_000e63ee:
    if (iVar6 == 0) {
LAB_000e63f6:
      FUN_000e650b();
      return;
    }
    goto code_r0x000e69ca;
  case 0xe:
    iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,param_1[0x165]);
    if (iVar6 == 0) {
      FUN_000e650b();
      return;
    }
    goto code_r0x000e69ca;
  case 0xf:
    param_1[0x162] = param_1[0x168];
    param_1[0x163] = param_1[0x169];
    param_1[0x164] = param_1[0x16a];
    iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,param_1[0x165]);
    if (iVar6 == 0) {
      FUN_000e650b();
      return;
    }
    goto code_r0x000e69ca;
  case 0x10:
    iVar6 = (**(code **)(param_1[0xf2] + 0x1cc))();
    if ((iVar6 == 0) ||
       (iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,param_1[0x165]),
       iVar6 == 0)) {
      FUN_000e650b();
      return;
    }
    goto code_r0x000e69ca;
  case 0x11:
    iVar6 = (**(code **)(param_1[0xf2] + 0x1d0))();
    if ((iVar6 == 0) ||
       (iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,param_1[0x165]),
       iVar6 == 0)) {
      (*DAT_001755b4)();
      goto LAB_000e6517;
    }
    goto code_r0x000e69ca;
  case 0x12:
    iVar6 = LookupActivity__14CBaseAnimatingi();
    if (iVar6 == -1) {
LAB_000e6575:
      param_1[0x165] = 3;
      FUN_000e69ca();
      return;
    }
    goto LAB_000e6540;
  case 0x13:
    if (*(int *)(*param_1 + 0xe8) == 5) {
      param_1[0x165] = 5;
    }
    iVar6 = LookupActivity__14CBaseAnimatingi();
    if (iVar6 != -1) goto LAB_000e6575;
LAB_000e6540:
    param_1[0x165] = 4;
    FUN_000e69ca();
    return;
  case 0x14:
    UTIL_MakeVectors__FRC6Vector();
    local_50 = (float)param_1[0x13f] - *(float *)(*param_1 + 8);
    local_34 = (float)param_1[0x140] - *(float *)(*param_1 + 0xc);
    local_30 = (float)param_1[0x141] - *(float *)(*param_1 + 0x10);
    local_2c = SQRT(local_34 * local_34 + local_50 * local_50);
    fVar11 = 0.0;
    if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 0.0) << 0xe) >> 8)) == 0x40) {
      local_50 = 0.0;
    }
    else {
      local_50 = (1.0 / local_2c) * local_50;
      fVar11 = (1.0 / local_2c) * local_34;
    }
    local_68 = gpGlobals[0x10];
    fVar1 = gpGlobals[0x11];
    local_38 = SQRT(fVar1 * fVar1 + local_68 * local_68);
    fVar2 = 0.0;
    if ((byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_68 = 0.0;
    }
    else {
      local_68 = (1.0 / local_38) * local_68;
      fVar2 = (1.0 / local_38) * fVar1;
    }
    fVar11 = fVar11 * fVar2 + local_50 * local_68;
    if ((byte)(0.0 < fVar11 | (byte)((ushort)((ushort)NAN(fVar11) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar11 == 0.0) << 0xe) >> 8)) == 1) {
      param_1[0x165] = 0xc;
      FUN_000e69ca();
      return;
    }
    param_1[0x165] = 0xb;
    FUN_000e69ca();
    return;
  case 0x15:
    param_1[0x136] = (int)*gpGlobals;
    FUN_000e69ca();
    return;
  case 0x16:
    iVar6 = *param_1;
    param_1[0x168] = *(int *)(iVar6 + 8);
    param_1[0x169] = *(int *)(iVar6 + 0xc);
    param_1[0x16a] = *(int *)(iVar6 + 0x10);
    FUN_000e69ca();
    return;
  case 0x17:
    param_1[0x168] = (int)g_vecZero;
    param_1[0x169] = (int)DAT_00175484;
    param_1[0x16a] = (int)DAT_00175488;
    FUN_000e69ca();
    return;
  case 0x18:
    param_1[0x138] = (int)*(short *)(DAT_001758cc + 0x52 + param_1[0x16b] * 0x58);
    break;
  case 0x19:
    iVar6 = FindHintNode__12CBaseMonster();
    param_1[0x16b] = iVar6;
    if (iVar6 == -1) goto LAB_000e6517;
    goto code_r0x000e69ca;
  case 0x1a:
    param_1[0x16b] = -1;
    FUN_000e69ca();
    return;
  case 0x1b:
    iVar6 = GetSmallFlinchActivity__12CBaseMonster();
    param_1[0x138] = iVar6;
    break;
  case 0x1c:
    goto switchD_000e570b_caseD_1c;
  case 0x1d:
    iVar6 = FRouteClear__12CBaseMonster();
    if (iVar6 != 0) {
      FUN_000e650b();
      return;
    }
    pfVar5 = (float *)(param_1 + param_1[0x160] * 4 + 0x13f);
    local_28 = *pfVar5;
    local_24 = pfVar5[1];
    local_20 = pfVar5[2];
    goto LAB_000e5e1e;
  case 0x1e:
    local_28 = (float)param_1[0x16e];
    local_24 = (float)param_1[0x16f];
    local_20 = (float)param_1[0x170];
    goto LAB_000e5e1e;
  case 0x1f:
    *(undefined4 *)(*param_1 + 0x8c) = *(undefined4 *)(DAT_001758cc + 0x54 + param_1[0x16b] * 0x58);
    puVar9 = &stack0xffffff74;
    goto switchD_000e570b_caseD_1c;
  case 0x20:
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 != 0) {
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
      local_28 = *(float *)(iVar6 + 8);
      local_24 = *(float *)(iVar6 + 0xc);
      local_20 = *(float *)(iVar6 + 0x10);
      goto LAB_000e5e1e;
    }
    goto LAB_000e6517;
  case 0x21:
    local_28 = (float)param_1[0x168];
    local_24 = (float)param_1[0x169];
    local_20 = (float)param_1[0x16a];
LAB_000e5e1e:
    MakeIdealYaw__12CBaseMonsterG6Vector();
    puVar9 = &stack0xffffff6c;
    goto switchD_000e570b_caseD_1c;
  case 0x22:
  case 0x27:
    param_1[0x138] = 0x1c;
    break;
  case 0x23:
  case 0x28:
    param_1[0x138] = 0x1d;
    break;
  case 0x24:
  case 0x29:
    param_1[0x138] = 0x1e;
    break;
  case 0x25:
  case 0x2a:
    param_1[0x138] = 0x1f;
    break;
  case 0x26:
  case 0x2b:
    param_1[0x138] = 0x20;
    break;
  case 0x2c:
    param_1[0x138] = 0x3c;
    break;
  case 0x2d:
    param_1[0x138] = 0x3d;
    break;
  case 0x37:
    (*DAT_001755b4)();
    FUN_000e69ca();
    return;
  case 0x38:
  case 0x43:
    pcVar7 = *(code **)(param_1[0xf2] + 0x200);
    goto LAB_000e67ad;
  case 0x39:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar3));
    param_1[0x138] = (int)ROUND((float)param_2[1]);
    FUN_000e699d();
    return;
  case 0x3a:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar3));
    iVar6 = (**(code **)(param_1[0xf2] + 0x16c))();
    if (iVar6 != 0) {
      ChangeSchedule__12CBaseMonsterP10Schedule_t();
      return;
    }
    goto LAB_000e6517;
  case 0x3b:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar3));
    param_1[0x179] = (int)ROUND((float)param_2[1]);
    goto code_r0x000e699d;
  case 0x3c:
    param_1[0x179] = 0;
    goto code_r0x000e69ca;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    param_1[0x138] = (int)ROUND((float)param_2[1]);
    break;
  case 0x40:
    pcVar7 = *(code **)(param_1[0xf2] + 0x208);
    goto LAB_000e67ad;
  case 0x41:
    pcVar7 = *(code **)(param_1[0xf2] + 0x204);
    goto LAB_000e67ad;
  case 0x42:
    pcVar7 = *(code **)(param_1[0xf2] + 0x20c);
LAB_000e67ad:
    (*pcVar7)();
    FUN_000e69ca();
    return;
  case 0x44:
    pfVar5 = (float *)(**(code **)(param_1[0xf2] + 0x1cc))();
    if (pfVar5 != (float *)0x0) {
      local_28 = *pfVar5;
      local_24 = pfVar5[1];
      local_20 = pfVar5[2];
      local_1c = g_vecZero;
      local_18 = DAT_00175484;
      local_14 = DAT_00175488;
      iVar6 = param_1[0xf2];
      (**(code **)(iVar6 + 0x1b0))();
      fVar11 = (float)(int)pfVar5[4];
      goto LAB_000e5cf6;
    }
    goto LAB_000e6517;
  case 0x45:
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 == 0) {
      iVar6 = *param_1;
    }
    else {
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
    }
    iVar4 = FindLateralCover__12CBaseMonsterRC6VectorT1(param_1);
    if (iVar4 != 0) {
LAB_000e5c75:
      param_1[0x136] = (int)(*gpGlobals + (float)param_2[1]);
      FUN_000e699d();
      return;
    }
    local_28 = *(float *)(iVar6 + 8);
    local_24 = *(float *)(iVar6 + 0xc);
    local_20 = *(float *)(iVar6 + 0x10);
    local_1c = *(float *)(iVar6 + 0x154);
    local_18 = *(float *)(iVar6 + 0x158);
    local_14 = *(float *)(iVar6 + 0x15c);
    iVar6 = param_1[0xf2];
    (**(code **)(iVar6 + 0x1b0))();
    fVar11 = 0.0;
LAB_000e5cf6:
    iVar6 = (**(code **)(iVar6 + 0x1a8))(param_1,&local_28,&local_1c,fVar11);
    if (iVar6 != 0) {
      param_1[0x136] = (int)(*gpGlobals + (float)param_2[1]);
      FUN_000e699d();
      return;
    }
    goto LAB_000e6517;
  case 0x47:
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 != 0) {
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
      local_28 = *(float *)(iVar6 + 8);
      local_24 = *(float *)(iVar6 + 0xc);
      local_20 = *(float *)(iVar6 + 0x10);
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
      local_1c = *(float *)(iVar6 + 0x154);
      local_18 = *(float *)(iVar6 + 0x158);
      local_14 = *(float *)(iVar6 + 0x15c);
      iVar6 = param_1[0xf2];
      (**(code **)(iVar6 + 0x1b0))();
      iVar6 = (**(code **)(iVar6 + 0x1a8))(param_1,&local_28,&local_1c,0);
joined_r0x000e5ac0:
      if (iVar6 != 0) goto code_r0x000e69ca;
    }
    goto LAB_000e6517;
  case 0x48:
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 != 0) {
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
      local_1c = *(float *)(iVar6 + 8);
      local_18 = *(float *)(iVar6 + 0xc);
      local_14 = *(float *)(iVar6 + 0x10);
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
      local_28 = *(float *)(iVar6 + 0x154);
      local_24 = *(float *)(iVar6 + 0x158);
      local_20 = *(float *)(iVar6 + 0x15c);
      iVar6 = (**(code **)(param_1[0xf2] + 0x1a8))(param_1,&local_1c,&local_28);
      goto joined_r0x000e5ac0;
    }
    goto LAB_000e6517;
  case 0x49:
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 != 0) {
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
      local_28 = *(float *)(iVar6 + 8);
      local_24 = *(float *)(iVar6 + 0xc);
      local_20 = *(float *)(iVar6 + 0x10);
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *piVar8;
      local_1c = *(float *)(iVar6 + 0x154);
      local_18 = *(float *)(iVar6 + 0x158);
      local_14 = *(float *)(iVar6 + 0x15c);
      iVar6 = param_1[0xf2];
      (**(code **)(iVar6 + 0x1b0))();
      iVar6 = (**(code **)(iVar6 + 0x1a8))(param_1,&local_28,&local_1c,param_2[1]);
      goto joined_r0x000e5ac0;
    }
    goto LAB_000e6517;
  case 0x4a:
    iVar6 = *param_1;
    local_28 = *(float *)(iVar6 + 8);
    local_24 = *(float *)(iVar6 + 0xc);
    local_20 = *(float *)(iVar6 + 0x10);
    local_1c = *(float *)(iVar6 + 0x154);
    local_18 = *(float *)(iVar6 + 0x158);
    local_14 = *(float *)(iVar6 + 0x15c);
    iVar6 = param_1[0xf2];
    (**(code **)(iVar6 + 0x1b0))();
    iVar6 = (**(code **)(iVar6 + 0x1a8))(param_1,&local_28,&local_1c,0);
    if (iVar6 != 0) goto LAB_000e5c75;
LAB_000e6517:
    SetConditions__12CBaseMonsteri();
    break;
  case 0x4b:
    Eat__12CBaseMonsterf();
    goto code_r0x000e699d;
  case 0x4c:
    RouteClear__12CBaseMonster();
    iVar6 = (**(code **)(param_1[0xf2] + 0x1e4))();
    param_1[0x138] = iVar6;
    *(undefined4 *)(*param_1 + 0x150) = 1;
    break;
  case 0x4d:
    iVar6 = param_1[0x183];
    if (*(int *)(iVar6 + 0x610) == 0) {
      param_1[0x138] = 1;
    }
    else {
      (**(code **)(*(int *)(iVar6 + 0x3c8) + 0x218))(iVar6,param_1);
      iVar6 = strcmp((char *)((int)gpGlobals[0x26] + *(int *)(param_1[0x183] + 0x610)),
                     (char *)((int)gpGlobals[0x26] + *(int *)(param_1[0x183] + 0x614)));
      if (iVar6 == 0) {
        *(undefined4 *)(*param_1 + 0x118) = 0;
      }
    }
    break;
  case 0x4e:
    *(undefined4 *)(*param_1 + 0xe8) = 5;
    *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
    param_1[0x182] = 0;
    break;
  case 0x4f:
    DelayStart__12CCineMonsteri();
    FUN_000e69ca();
    return;
  case 0x50:
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 != 0) {
      piVar8 = (int *)__rf__7EHANDLE();
      iVar6 = *param_1;
      iVar4 = *piVar8;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar4 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar4 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
      FUN_000e69ca();
      return;
    }
code_r0x000e69ca:
    iVar6 = HasConditions__12CBaseMonsteri();
    if (iVar6 == 0) {
      param_1[0x13c] = 4;
    }
    break;
  case 0x51:
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 != 0) {
      __rf__7EHANDLE();
      lVar10 = (longdouble)UTIL_AngleMod__Ff();
      *(float *)(*param_1 + 0x8c) = (float)lVar10;
    }
    iVar6 = HasConditions__12CBaseMonsteri();
    if (iVar6 == 0) {
      param_1[0x13c] = 4;
    }
    param_1[0x138] = 1;
    RouteClear__12CBaseMonster();
    break;
  case 0x52:
    lVar10 = (longdouble)(*DAT_0017562c)();
    param_1[0x135] = (int)(float)(lVar10 + (longdouble)*gpGlobals);
    break;
  case 0x54:
    if (param_1[0x138] == param_1[0x165]) {
      iVar6 = (**(code **)(param_1[0xf2] + 0x148))();
      param_1[0x138] = iVar6;
    }
    RouteClear__12CBaseMonster();
    FUN_000e69ca();
    return;
  case 0x55:
    UTIL_AngleMod__Ff();
    lVar10 = (longdouble)UTIL_AngleMod__Ff();
    *(float *)(*param_1 + 0x8c) = (float)lVar10;
    puVar9 = &stack0xffffff6c;
    goto switchD_000e570b_caseD_1c;
  case 0x56:
    UTIL_AngleMod__Ff();
    lVar10 = (longdouble)UTIL_AngleMod__Ff();
    *(float *)(*param_1 + 0x8c) = (float)lVar10;
    puVar9 = &stack0xffffff6c;
switchD_000e570b_caseD_1c:
    *(int **)(puVar9 + -4) = param_1;
    *(undefined4 *)(puVar9 + -8) = 0xe5e31;
    SetTurnActivity__12CBaseMonster();
    break;
  case 0x57:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar3));
    param_1[0x16c] = param_1[0x16c] | (int)ROUND((float)param_2[1]);
code_r0x000e699d:
    iVar6 = HasConditions__12CBaseMonsteri();
    if (iVar6 == 0) {
      param_1[0x13c] = 4;
    }
    break;
  case 0x58:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar3));
    param_1[0x16c] = param_1[0x16c] & ~(int)ROUND((float)param_2[1]);
    FUN_000e699d();
    return;
  case 0x59:
    iVar6 = FRouteClear__12CBaseMonster();
    if (iVar6 != 0) {
      FUN_000e69ca();
      return;
    }
  }
  return;
}


// StartTask__12CTalkMonsterP6Task_t  @ 000f1300
void StartTask__12CTalkMonsterP6Task_t(int *param_1,undefined4 *param_2)

{
  float fVar1;
  byte bVar4;
  int iVar2;
  int *piVar3;
  int **ppiVar5;
  longdouble lVar6;
  longdouble lVar7;
  int *piStack_4c;
  float *pfStack_48;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  ppiVar5 = (int **)&stack0xffffffbc;
  switch(*param_2) {
  case 0x4e:
    pfStack_48 = (float *)0x0;
    piStack_4c = param_1 + 0x19e;
    ppiVar5 = &piStack_4c;
    __as__7EHANDLEP11CBaseEntity();
  default:
    *(undefined4 **)((int)ppiVar5 + -4) = param_2;
    *(int **)((int)ppiVar5 + -8) = param_1;
    *(undefined4 *)((int)ppiVar5 + -0xc) = 0xf16e5;
    StartTask__12CBaseMonsterP6Task_t();
    return;
  case 0x5b:
    pfStack_48 = (float *)0x0;
    piStack_4c = param_1;
    (**(code **)(param_1[0xf2] + 0x210))();
    iVar2 = param_1[0xf2];
    lVar6 = (longdouble)(*DAT_0017562c)(0x40000000,0x40200000,0x3f800000,0x3f4ccccd);
    (**(code **)(iVar2 + 0x180))(param_1,param_1[0x18d],(float)lVar6);
    break;
  case 0x5c:
    iVar2 = *param_1;
    local_10 = *(float *)(iVar2 + 0x50);
    local_8 = *(float *)(iVar2 + 0x58);
    local_c = *(float *)(iVar2 + 0x8c) + 180.0;
    pfStack_48 = (float *)0x0;
    piStack_4c = (int *)0x0;
    (*DAT_00175510)(&local_10,&local_1c);
    local_2c = (float)param_2[1];
    local_34 = local_2c * local_1c;
    local_30 = local_2c * local_18;
    local_2c = local_2c * local_14;
    iVar2 = *param_1;
    local_28 = *(float *)(iVar2 + 8) + local_34;
    local_24 = *(float *)(iVar2 + 0xc) + local_30;
    local_20 = *(float *)(iVar2 + 0x10) + local_2c;
    piStack_4c = (int *)0x40000000;
    pfStack_48 = &local_10;
    local_10 = local_28;
    local_c = local_24;
    local_8 = local_20;
    iVar2 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,3);
    if (iVar2 == 0) {
      iVar2 = *param_1;
      local_34 = *(float *)(iVar2 + 8);
      local_30 = *(float *)(iVar2 + 0xc);
      local_2c = *(float *)(iVar2 + 0x10);
      local_28 = *(float *)(iVar2 + 0x154);
      local_24 = *(float *)(iVar2 + 0x158);
      local_20 = *(float *)(iVar2 + 0x15c);
      iVar2 = param_1[0xf2];
      pfStack_48 = (float *)param_1;
      piStack_4c = (int *)0xf1665;
      lVar6 = (longdouble)(**(code **)(iVar2 + 0x1b0))();
      piStack_4c = (int *)(float)lVar6;
      iVar2 = (**(code **)(iVar2 + 0x1a8))(param_1,&local_34,&local_28,0);
      if (iVar2 == 0) {
        pfStack_48 = (float *)0x40000000;
        piStack_4c = param_1;
        SetConditions__12CBaseMonsteri();
        return;
      }
      param_1[0x136] = (int)(*gpGlobals + 2.0);
    }
    break;
  case 0x5d:
    param_1[0x165] = 3;
    return;
  case 0x5e:
    pfStack_48 = (float *)param_1;
    piStack_4c = (int *)0xf1346;
    IdleRespond__12CTalkMonster();
    break;
  case 0x5f:
    pfStack_48 = (float *)param_1;
    piStack_4c = (int *)0xf1336;
    FIdleSpeak__12CTalkMonster();
    break;
  case 0x60:
    pfStack_48 = (float *)param_1;
    piStack_4c = (int *)0xf1356;
    FIdleHello__12CTalkMonster();
    break;
  case 0x61:
    pfStack_48 = (float *)0x0;
    piStack_4c = param_1 + 0x19e;
    __as__7EHANDLEP11CBaseEntity();
    break;
  case 0x62:
    iVar2 = param_1[0xf2];
    pfStack_48 = (float *)0x3f4ccccd;
    piStack_4c = (int *)0x3f800000;
    lVar6 = (longdouble)(*DAT_0017562c)(0x40333333,0x404ccccd);
    (**(code **)(iVar2 + 0x180))(param_1,param_1[0x18e],(float)lVar6);
    break;
  case 99:
    pfStack_48 = (float *)param_1;
    piStack_4c = (int *)0xf1366;
    FIdleStare__12CTalkMonster();
    break;
  case 100:
  case 0x65:
  case 0x68:
    param_1[0x135] = (int)(*gpGlobals + (float)param_2[1]);
    return;
  case 0x66:
    goto switchD_000f131d_caseD_66;
  case 0x67:
    piStack_4c = (int *)0xf139c;
    pfStack_48 = (float *)(param_1 + 0x19e);
    iVar2 = __opP11CBaseEntity__7EHANDLE();
    if (iVar2 != 0) {
      *(undefined4 *)(*param_1 + 0x90) = 0x42700000;
      piStack_4c = (int *)0xf13b9;
      pfStack_48 = (float *)(param_1 + 0x19e);
      piVar3 = (int *)__rf__7EHANDLE();
      iVar2 = *piVar3;
      local_10 = *(float *)(iVar2 + 8) - *(float *)(*param_1 + 8);
      local_c = *(float *)(iVar2 + 0xc) - *(float *)(*param_1 + 0xc);
      local_8 = *(float *)(iVar2 + 0x10) - *(float *)(*param_1 + 0x10);
      pfStack_48 = &local_10;
      piStack_4c = param_1;
      lVar6 = (longdouble)VecToYaw__12CBaseMonsterG6Vector();
      lVar6 = lVar6 - (longdouble)*(float *)(*param_1 + 0x54);
      lVar7 = (longdouble)180.0;
      if ((byte)(lVar7 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) == 1) {
        lVar6 = lVar6 - (longdouble)360.0;
      }
      if (lVar6 < (longdouble)-180.0) {
        lVar6 = (longdouble)360.0 + lVar6;
      }
      lVar7 = (longdouble)0;
      if (lVar6 < lVar7) {
        iVar2 = *param_1;
        fVar1 = *(float *)(iVar2 + 0x54);
        lVar6 = (longdouble)45.0 + lVar6;
        bVar4 = lVar6 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar7)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar6 == lVar7) << 0xe) >> 8);
      }
      else {
        iVar2 = *param_1;
        fVar1 = *(float *)(iVar2 + 0x54);
        lVar6 = lVar6 - (longdouble)45.0;
        lVar7 = (longdouble)0;
        bVar4 = lVar7 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8);
      }
      if (bVar4 != 1) {
        lVar6 = (longdouble)0;
      }
      *(float *)(iVar2 + 0x8c) = (float)((longdouble)fVar1 + lVar6);
    }
  }
  pfStack_48 = (float *)0x40000000;
  piStack_4c = param_1;
  iVar2 = HasConditions__12CBaseMonsteri();
  if (iVar2 == 0) {
    param_1[0x13c] = 4;
  }
switchD_000f131d_caseD_66:
  return;
}


