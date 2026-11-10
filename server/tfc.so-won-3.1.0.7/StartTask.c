// StartTask__12CBaseMonsterP6Task_t  @ 000e637c
void StartTask__12CBaseMonsterP6Task_t(int *param_1,int *param_2)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  char *pcVar8;
  undefined2 in_FPUControlWord;
  longdouble lVar9;
  float fVar10;
  float fStack_64;
  float fStack_60;
  float fStack_4c;
  float fStack_48;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_4;
  
  uVar7 = (undefined1)in_FPUControlWord;
  switch(*param_2) {
  case 1:
  case 2:
    param_1[0x154] = (int)(*gpGlobals + (float)param_2[1]);
    break;
  case 3:
  case 0x53:
    break;
  case 4:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x15a] = (int)ROUND((float)param_2[1]);
    goto LAB_000e7909;
  case 5:
  case 6:
    piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
    iVar3 = *piVar5;
    local_24 = *(float *)(iVar3 + 8) - *(float *)(*param_1 + 8);
    local_20 = *(float *)(iVar3 + 0xc) - *(float *)(*param_1 + 0xc);
    local_1c = *(float *)(iVar3 + 0x10) - *(float *)(*param_1 + 0x10);
    local_18 = SQRT(local_1c * local_1c + local_20 * local_20 + local_24 * local_24);
    if (1.0 <= local_18) {
      uVar6 = 4;
      if (*param_2 == 5) {
        uVar6 = 3;
      }
      iVar3 = LookupActivity__14CBaseAnimatingi(param_1,uVar6);
      if (iVar3 != -1) {
        iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
        if ((iVar3 == 0) ||
           (iVar3 = MoveToTarget__12CBaseMonster8Activityf(param_1,uVar6,0x40000000), iVar3 == 0)) {
          SetConditions__12CBaseMonsteri(param_1,0x40000000);
          (*DAT_001c1114)(2,"%s Failed to reach target!!!\n",*(int *)*param_1 + (int)gpGlobals[0x26]
                         );
          RouteClear__12CBaseMonster(param_1);
          FUN_000e7936();
          return;
        }
        goto code_r0x000e7936;
      }
    }
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x15b] = 4;
      FUN_000e7936();
      return;
    }
    goto code_r0x000e7936;
  case 7:
    piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
    iVar3 = *piVar5;
    local_24 = *(float *)(iVar3 + 8) - *(float *)(*param_1 + 8);
    local_20 = *(float *)(iVar3 + 0xc) - *(float *)(*param_1 + 0xc);
    local_1c = *(float *)(iVar3 + 0x10) - *(float *)(*param_1 + 0x10);
    local_18 = SQRT(local_1c * local_1c + local_20 * local_20 + local_24 * local_24);
    if (1.0 <= local_18) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      iVar3 = *piVar5;
      param_1[0x181] = *(int *)(iVar3 + 8);
      param_1[0x182] = *(int *)(iVar3 + 0xc);
      param_1[0x183] = *(int *)(iVar3 + 0x10);
      iVar3 = MoveToTarget__12CBaseMonster8Activityf(param_1,3,0x40000000);
      if (iVar3 != 0) {
        return;
      }
      goto LAB_000e7430;
    }
    goto code_r0x000e7936;
  case 8:
    piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
    if (piVar5 == (int *)0x0) goto LAB_000e7430;
    iVar3 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,*piVar5 + 8,2,piVar5);
    if (iVar3 == 0) {
      iVar3 = *piVar5;
      fStack_34 = *(float *)(iVar3 + 8);
      fStack_30 = *(float *)(iVar3 + 0xc);
      fStack_2c = *(float *)(iVar3 + 0x10);
      iVar3 = *piVar5;
      fStack_28 = *(float *)(iVar3 + 0x174);
      local_24 = *(float *)(iVar3 + 0x178);
      local_20 = *(float *)(iVar3 + 0x17c);
      iVar3 = *piVar5;
      iVar1 = *param_1;
      local_1c = *(float *)(iVar3 + 8) - *(float *)(iVar1 + 8);
      local_18 = *(float *)(iVar3 + 0xc) - *(float *)(iVar1 + 0xc);
      local_14 = *(float *)(iVar3 + 0x10) - *(float *)(iVar1 + 0x10);
      local_10 = SQRT(local_14 * local_14 + local_18 * local_18 + local_1c * local_1c);
      iVar3 = (**(code **)(param_1[0x111] + 0x1ac))(param_1,&fStack_34,&fStack_28,0,local_10);
      if (iVar3 == 0) {
        pcVar8 = "GetPathToEnemy failed!!\n";
        goto LAB_000e7422;
      }
    }
    goto code_r0x000e7936;
  case 9:
    iVar3 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x18d,0x40,0);
    if (iVar3 == 0) {
      local_24 = (float)param_1[0x18d];
      local_20 = (float)param_1[0x18e];
      local_1c = (float)param_1[399];
      iVar3 = *param_1;
      local_18 = *(float *)(iVar3 + 0x174);
      local_14 = *(float *)(iVar3 + 0x178);
      local_10 = *(float *)(iVar3 + 0x17c);
      fStack_30 = (float)param_1[0x18d] - *(float *)(iVar3 + 8);
      fStack_2c = (float)param_1[0x18e] - *(float *)(iVar3 + 0xc);
      fStack_28 = (float)param_1[399] - *(float *)(iVar3 + 0x10);
      fStack_34 = SQRT(fStack_28 * fStack_28 + fStack_2c * fStack_2c + fStack_30 * fStack_30);
      iVar3 = (**(code **)(param_1[0x111] + 0x1ac))(param_1,&local_24,&local_18,0,fStack_34);
      if (iVar3 == 0) {
        pcVar8 = "GetPathToEnemyLKP failed!!\n";
        goto LAB_000e7422;
      }
    }
    goto code_r0x000e7936;
  case 10:
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    fStack_28 = gpGlobals[10] * 64.0;
    local_24 = gpGlobals[0xb] * 64.0;
    local_20 = gpGlobals[0xc] * 64.0;
    fStack_34 = (float)param_1[0x18d] - fStack_28;
    fStack_30 = (float)param_1[0x18e] - local_24;
    fStack_2c = (float)param_1[399] - local_20;
    iVar3 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,&fStack_34,0x40,0);
    if (iVar3 == 0) {
      pcVar8 = "GetPathToEnemyCorpse failed!!\n";
      goto LAB_000e7422;
    }
    goto code_r0x000e7936;
  default:
    (*DAT_001c1114)(2,"No StartTask entry for %d\n",*param_2);
    break;
  case 0xc:
    iVar3 = (*DAT_001c1058)(0,"classname","player");
    if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(undefined4 *)(iVar3 + 0x7c);
    }
    iVar3 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x181,0x40,uVar6);
LAB_000e72de:
    if (iVar3 == 0) goto LAB_000e72e6;
    goto code_r0x000e7936;
  case 0xd:
    RouteClear__12CBaseMonster(param_1);
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
    if (iVar3 != 0) {
      iVar3 = MoveToTarget__12CBaseMonster8Activityf(param_1,param_1[0x184],0x3f800000);
      goto LAB_000e72de;
    }
LAB_000e72e6:
    pcVar8 = "GetPathToSpot failed!!\n";
LAB_000e7422:
    (*DAT_001c1114)(2,pcVar8);
    goto LAB_000e7430;
  case 0xe:
    iVar3 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                      (param_1,param_1[0x184],0x40000000,DAT_001c148c + param_1[0x18a] * 0x58);
    if (iVar3 == 0) {
      pcVar8 = "GetPathToHintNode failed!!\n";
      goto LAB_000e7422;
    }
    goto code_r0x000e7936;
  case 0xf:
    param_1[0x181] = param_1[0x187];
    param_1[0x182] = param_1[0x188];
    param_1[0x183] = param_1[0x189];
    iVar3 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                      (param_1,param_1[0x184],0x40000000,param_1 + 0x181);
    if (iVar3 == 0) {
      pcVar8 = "GetPathToLastPosition failed!!\n";
      goto LAB_000e7422;
    }
    goto code_r0x000e7936;
  case 0x10:
    iVar3 = (**(code **)(param_1[0x111] + 0x1d4))(param_1);
    if ((iVar3 == 0) ||
       (iVar3 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                          (param_1,param_1[0x184],0x40000000,iVar3), iVar3 == 0)) {
      pcVar8 = "GetPathToBestSound failed!!\n";
      goto LAB_000e7422;
    }
    goto code_r0x000e7936;
  case 0x11:
    iVar3 = (**(code **)(param_1[0x111] + 0x1d8))(param_1);
    if ((iVar3 == 0) ||
       (iVar3 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                          (param_1,param_1[0x184],0x40000000,iVar3), iVar3 == 0)) {
      pcVar8 = "GetPathToBestScent failed!!\n";
      goto LAB_000e7422;
    }
    goto code_r0x000e7936;
  case 0x12:
    iVar3 = LookupActivity__14CBaseAnimatingi(param_1,4);
    if (iVar3 == -1) {
LAB_000e748a:
      param_1[0x184] = 3;
      FUN_000e7936();
      return;
    }
    goto LAB_000e7454;
  case 0x13:
    if (*(int *)(*param_1 + 0x108) == 5) {
      param_1[0x184] = 5;
    }
    iVar3 = LookupActivity__14CBaseAnimatingi(param_1,3);
    if (iVar3 != -1) goto LAB_000e748a;
LAB_000e7454:
    param_1[0x184] = 4;
    FUN_000e7936();
    return;
  case 0x14:
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    fStack_4c = (float)param_1[0x15e] - *(float *)(*param_1 + 8);
    fStack_30 = (float)param_1[0x15f] - *(float *)(*param_1 + 0xc);
    fStack_2c = (float)param_1[0x160] - *(float *)(*param_1 + 0x10);
    fStack_28 = SQRT(fStack_30 * fStack_30 + fStack_4c * fStack_4c);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_28 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_4c = 0.0;
      fStack_48 = 0.0;
    }
    else {
      fStack_4c = (1.0 / fStack_28) * fStack_4c;
      fStack_48 = (1.0 / fStack_28) * fStack_30;
    }
    fStack_64 = gpGlobals[0x10];
    fStack_60 = gpGlobals[0x11];
    fStack_34 = SQRT(fStack_60 * fStack_60 + fStack_64 * fStack_64);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_34) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_34 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_64 = 0.0;
      fStack_60 = 0.0;
    }
    else {
      fStack_64 = (1.0 / fStack_34) * fStack_64;
      fStack_60 = (1.0 / fStack_34) * fStack_60;
    }
    if (0.0 < fStack_48 * fStack_60 + fStack_4c * fStack_64) {
      param_1[0x184] = 0xc;
      FUN_000e7936();
      return;
    }
    param_1[0x184] = 0xb;
    FUN_000e7936();
    return;
  case 0x15:
    param_1[0x155] = (int)*gpGlobals;
    FUN_000e7936();
    return;
  case 0x16:
    iVar3 = *param_1;
    param_1[0x187] = *(int *)(iVar3 + 8);
    param_1[0x188] = *(int *)(iVar3 + 0xc);
    param_1[0x189] = *(int *)(iVar3 + 0x10);
    FUN_000e7936();
    return;
  case 0x17:
    param_1[0x187] = (int)g_vecZero;
    param_1[0x188] = (int)DAT_001c0fe4;
    param_1[0x189] = (int)DAT_001c0fe8;
    FUN_000e7936();
    return;
  case 0x18:
    param_1[0x157] = (int)*(short *)(DAT_001c148c + 0x52 + param_1[0x18a] * 0x58);
    break;
  case 0x19:
    iVar3 = FindHintNode__12CBaseMonster(param_1);
    param_1[0x18a] = iVar3;
    if (iVar3 == -1) goto LAB_000e7430;
    goto code_r0x000e7936;
  case 0x1a:
    param_1[0x18a] = -1;
    FUN_000e7936();
    return;
  case 0x1b:
    iVar3 = GetSmallFlinchActivity__12CBaseMonster(param_1);
    param_1[0x157] = iVar3;
    break;
  case 0x1c:
    goto switchD_000e63b2_caseD_1c;
  case 0x1d:
    iVar3 = FRouteClear__12CBaseMonster(param_1);
    if (iVar3 != 0) {
      pcVar8 = "No route to face!\n";
      goto LAB_000e7422;
    }
    pfVar2 = (float *)(param_1 + param_1[0x17f] * 4 + 0x15e);
    local_24 = *pfVar2;
    local_20 = pfVar2[1];
    local_1c = pfVar2[2];
    goto LAB_000e6ca8;
  case 0x1e:
    local_24 = (float)param_1[0x18d];
    local_20 = (float)param_1[0x18e];
    local_1c = (float)param_1[399];
    goto LAB_000e6ca8;
  case 0x1f:
    *(undefined4 *)(*param_1 + 0xac) = *(undefined4 *)(DAT_001c148c + 0x54 + param_1[0x18a] * 0x58);
    goto switchD_000e63b2_caseD_1c;
  case 0x20:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      iVar3 = *piVar5;
      local_24 = *(float *)(iVar3 + 8);
      local_20 = *(float *)(iVar3 + 0xc);
      local_1c = *(float *)(iVar3 + 0x10);
      goto LAB_000e6ca8;
    }
    goto LAB_000e7430;
  case 0x21:
    local_24 = (float)param_1[0x187];
    local_20 = (float)param_1[0x188];
    local_1c = (float)param_1[0x189];
LAB_000e6ca8:
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_24);
    SetTurnActivity__12CBaseMonster(param_1);
    break;
  case 0x22:
  case 0x27:
    param_1[0x157] = 0x1c;
    break;
  case 0x23:
  case 0x28:
    param_1[0x157] = 0x1d;
    break;
  case 0x24:
  case 0x29:
    param_1[0x157] = 0x1e;
    break;
  case 0x25:
  case 0x2a:
    param_1[0x157] = 0x1f;
    break;
  case 0x26:
  case 0x2b:
    param_1[0x157] = 0x20;
    break;
  case 0x2c:
    param_1[0x157] = 0x3c;
    break;
  case 0x2d:
    param_1[0x157] = 0x3d;
    break;
  case 0x37:
    (*DAT_001c1114)(2,"SOUND\n");
    FUN_000e7936();
    return;
  case 0x38:
  case 0x43:
    pcVar4 = *(code **)(param_1[0x111] + 0x208);
    goto LAB_000e7705;
  case 0x39:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x157] = (int)ROUND((float)param_2[1]);
    goto LAB_000e7909;
  case 0x3a:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    iVar3 = (**(code **)(param_1[0x111] + 0x174))(param_1,(int)ROUND((float)param_2[1]));
    if (iVar3 != 0) {
      ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,iVar3);
      return;
    }
    goto LAB_000e7430;
  case 0x3b:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x198] = (int)ROUND((float)param_2[1]);
    goto LAB_000e7909;
  case 0x3c:
    param_1[0x198] = 0;
    goto code_r0x000e7936;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    param_1[0x157] = (int)ROUND((float)param_2[1]);
    break;
  case 0x40:
    pcVar4 = *(code **)(param_1[0x111] + 0x210);
    goto LAB_000e7705;
  case 0x41:
    pcVar4 = *(code **)(param_1[0x111] + 0x20c);
    goto LAB_000e7705;
  case 0x42:
    pcVar4 = *(code **)(param_1[0x111] + 0x214);
LAB_000e7705:
    (*pcVar4)(param_1);
    FUN_000e7936();
    return;
  case 0x44:
    pfVar2 = (float *)(**(code **)(param_1[0x111] + 0x1d4))(param_1);
    if (pfVar2 != (float *)0x0) {
      local_24 = *pfVar2;
      local_20 = pfVar2[1];
      local_1c = pfVar2[2];
      local_18 = g_vecZero;
      local_14 = DAT_001c0fe4;
      local_10 = DAT_001c0fe8;
      iVar3 = param_1[0x111];
      lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b8))(param_1);
      fVar10 = (float)(int)pfVar2[4];
LAB_000e6b80:
      iVar3 = (**(code **)(iVar3 + 0x1b0))(param_1,&local_24,&local_18,fVar10,(float)lVar9);
      if (iVar3 != 0) {
        param_1[0x155] = (int)(*gpGlobals + (float)param_2[1]);
        goto LAB_000e7909;
      }
    }
    goto LAB_000e7430;
  case 0x45:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
    if (iVar3 == 0) {
      iVar3 = *param_1;
    }
    else {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13b);
      iVar3 = *piVar5;
    }
    iVar1 = FindLateralCover__12CBaseMonsterRC6VectorT1(param_1,iVar3 + 8,iVar3 + 0x174);
    if (iVar1 == 0) {
      local_24 = *(float *)(iVar3 + 8);
      local_20 = *(float *)(iVar3 + 0xc);
      local_1c = *(float *)(iVar3 + 0x10);
      local_18 = *(float *)(iVar3 + 0x174);
      local_14 = *(float *)(iVar3 + 0x178);
      local_10 = *(float *)(iVar3 + 0x17c);
      iVar3 = param_1[0x111];
      lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b8))(param_1);
      fVar10 = 0.0;
      goto LAB_000e6b80;
    }
LAB_000e6af9:
    param_1[0x155] = (int)(*gpGlobals + (float)param_2[1]);
    goto LAB_000e7909;
  case 0x47:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13b);
      iVar3 = *piVar5;
      local_24 = *(float *)(iVar3 + 8);
      local_20 = *(float *)(iVar3 + 0xc);
      local_1c = *(float *)(iVar3 + 0x10);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13b);
      iVar3 = *piVar5;
      local_18 = *(float *)(iVar3 + 0x174);
      local_14 = *(float *)(iVar3 + 0x178);
      local_10 = *(float *)(iVar3 + 0x17c);
      iVar3 = param_1[0x111];
      lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b8))(param_1);
      iVar3 = (**(code **)(iVar3 + 0x1b0))(param_1,&local_24,&local_18,0,(float)lVar9);
joined_r0x000e693b:
      if (iVar3 != 0) goto code_r0x000e7936;
    }
    goto LAB_000e7430;
  case 0x48:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13b);
      iVar3 = *piVar5;
      local_18 = *(float *)(iVar3 + 8);
      local_14 = *(float *)(iVar3 + 0xc);
      local_10 = *(float *)(iVar3 + 0x10);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13b);
      iVar3 = *piVar5;
      local_24 = *(float *)(iVar3 + 0x174);
      local_20 = *(float *)(iVar3 + 0x178);
      local_1c = *(float *)(iVar3 + 0x17c);
      iVar3 = (**(code **)(param_1[0x111] + 0x1b0))(param_1,&local_18,&local_24,0,param_2[1]);
      goto joined_r0x000e693b;
    }
    goto LAB_000e7430;
  case 0x49:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13b);
      iVar3 = *piVar5;
      local_24 = *(float *)(iVar3 + 8);
      local_20 = *(float *)(iVar3 + 0xc);
      local_1c = *(float *)(iVar3 + 0x10);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13b);
      iVar3 = *piVar5;
      local_18 = *(float *)(iVar3 + 0x174);
      local_14 = *(float *)(iVar3 + 0x178);
      local_10 = *(float *)(iVar3 + 0x17c);
      iVar3 = param_1[0x111];
      lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b8))(param_1);
      iVar3 = (**(code **)(iVar3 + 0x1b0))(param_1,&local_24,&local_18,param_2[1],(float)lVar9);
      goto joined_r0x000e693b;
    }
    goto LAB_000e7430;
  case 0x4a:
    iVar3 = *param_1;
    local_24 = *(float *)(iVar3 + 8);
    local_20 = *(float *)(iVar3 + 0xc);
    local_1c = *(float *)(iVar3 + 0x10);
    local_18 = *(float *)(iVar3 + 0x174);
    local_14 = *(float *)(iVar3 + 0x178);
    local_10 = *(float *)(iVar3 + 0x17c);
    iVar3 = param_1[0x111];
    lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b8))(param_1);
    iVar3 = (**(code **)(iVar3 + 0x1b0))(param_1,&local_24,&local_18,0,(float)lVar9);
    if (iVar3 != 0) goto LAB_000e6af9;
LAB_000e7430:
    SetConditions__12CBaseMonsteri(param_1,0x40000000);
    break;
  case 0x4b:
    Eat__12CBaseMonsterf(param_1,param_2[1]);
    goto LAB_000e7909;
  case 0x4c:
    RouteClear__12CBaseMonster(param_1);
    iVar3 = (**(code **)(param_1[0x111] + 0x1ec))(param_1);
    param_1[0x157] = iVar3;
    *(undefined4 *)(*param_1 + 0x170) = 1;
    break;
  case 0x4d:
    iVar3 = param_1[0x1a2];
    if (*(int *)(iVar3 + 0x68c) == 0) {
      param_1[0x157] = 1;
    }
    else {
      (**(code **)(*(int *)(iVar3 + 0x444) + 0x220))(iVar3,param_1,*(undefined4 *)(iVar3 + 0x68c),0)
      ;
      iVar3 = strcmp((char *)((int)gpGlobals[0x26] + *(int *)(param_1[0x1a2] + 0x68c)),
                     (char *)((int)gpGlobals[0x26] + *(int *)(param_1[0x1a2] + 0x690)));
      if (iVar3 == 0) {
        *(undefined4 *)(*param_1 + 0x138) = 0;
      }
    }
    break;
  case 0x4e:
    *(undefined4 *)(*param_1 + 0x108) = 5;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    param_1[0x1a1] = 0;
    break;
  case 0x4f:
    DelayStart__12CCineMonsteri(param_1[0x1a2],0);
    FUN_000e7936();
    return;
  case 0x50:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      iVar3 = *param_1;
      iVar1 = *piVar5;
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
      *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
      FUN_000e7936();
      return;
    }
code_r0x000e7936:
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x15b] = 4;
    }
    break;
  case 0x51:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13d);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      lVar9 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*piVar5 + 0x54));
      *(float *)(*param_1 + 0xac) = (float)lVar9;
    }
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x15b] = 4;
    }
    param_1[0x157] = 1;
    RouteClear__12CBaseMonster(param_1);
    break;
  case 0x52:
    lVar9 = (longdouble)(*DAT_001c118c)(0x3dcccccd,param_2[1]);
    param_1[0x154] = (int)(float)(lVar9 + (longdouble)*gpGlobals);
    break;
  case 0x54:
    if (param_1[0x157] == param_1[0x184]) {
      iVar3 = (**(code **)(param_1[0x111] + 0x150))(param_1);
      param_1[0x157] = iVar3;
    }
    RouteClear__12CBaseMonster(param_1);
    FUN_000e7936();
    return;
  case 0x55:
    lVar9 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
    lVar9 = (longdouble)UTIL_AngleMod__Ff((float)(lVar9 + (longdouble)(float)param_2[1]));
    *(float *)(*param_1 + 0xac) = (float)lVar9;
    FUN_000e6cb7();
    return;
  case 0x56:
    lVar9 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
    lVar9 = (longdouble)UTIL_AngleMod__Ff((float)(lVar9 - (longdouble)(float)param_2[1]));
    *(float *)(*param_1 + 0xac) = (float)lVar9;
    FUN_000e6cb7();
    return;
  case 0x57:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x18b] = param_1[0x18b] | (int)ROUND((float)param_2[1]);
    goto LAB_000e7909;
  case 0x58:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x18b] = param_1[0x18b] & ~(int)ROUND((float)param_2[1]);
LAB_000e7909:
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x15b] = 4;
    }
    break;
  case 0x59:
    iVar3 = FRouteClear__12CBaseMonster(param_1);
    if (iVar3 != 0) {
      FUN_000e7936();
      return;
    }
  }
  return;
switchD_000e63b2_caseD_1c:
  SetTurnActivity__12CBaseMonster(param_1);
  return;
}


// StartTask__12CTalkMonsterP6Task_t  @ 000f49cc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StartTask__12CTalkMonsterP6Task_t(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  switch(*param_2) {
  case 0x4e:
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1bd,0);
    StartTask__12CBaseMonsterP6Task_t(param_1,param_2);
    return;
  default:
    StartTask__12CBaseMonsterP6Task_t(param_1,param_2);
    return;
  case 0x5b:
    (**(code **)(param_1[0x111] + 0x218))(param_1,0);
    iVar1 = param_1[0x111];
    lVar3 = (longdouble)(*DAT_001c118c)(0x40000000,0x40200000,0x3f800000,0x3f4ccccd);
    (**(code **)(iVar1 + 0x188))(param_1,param_1[0x1ac],(float)lVar3);
    break;
  case 0x5c:
    iVar1 = *param_1;
    fStack_c = *(float *)(iVar1 + 0x50);
    fStack_4 = *(float *)(iVar1 + 0x58);
    fStack_8 = _FUN_0014e394 + *(float *)(iVar1 + 0xac);
    (*DAT_001c1070)(&fStack_c,&fStack_18,0,0);
    fStack_28 = (float)param_2[1];
    fStack_30 = fStack_28 * fStack_18;
    fStack_2c = fStack_28 * fStack_14;
    fStack_28 = fStack_28 * fStack_10;
    iVar1 = *param_1;
    fStack_24 = *(float *)(iVar1 + 8) + fStack_30;
    fStack_20 = *(float *)(iVar1 + 0xc) + fStack_2c;
    fStack_1c = *(float *)(iVar1 + 0x10) + fStack_28;
    fStack_c = fStack_24;
    fStack_8 = fStack_20;
    fStack_4 = fStack_1c;
    iVar1 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,3,0x40000000,&fStack_c);
    if (iVar1 == 0) {
      iVar1 = *param_1;
      fStack_30 = *(float *)(iVar1 + 8);
      fStack_2c = *(float *)(iVar1 + 0xc);
      fStack_28 = *(float *)(iVar1 + 0x10);
      fStack_24 = *(float *)(iVar1 + 0x174);
      fStack_20 = *(float *)(iVar1 + 0x178);
      fStack_1c = *(float *)(iVar1 + 0x17c);
      iVar1 = param_1[0x111];
      lVar3 = (longdouble)(**(code **)(iVar1 + 0x1b8))(param_1);
      iVar1 = (**(code **)(iVar1 + 0x1b0))(param_1,&fStack_30,&fStack_24,0,(float)lVar3);
      if (iVar1 == 0) {
        SetConditions__12CBaseMonsteri(param_1,0x40000000);
        return;
      }
      param_1[0x155] = (int)(*gpGlobals + 2.0);
    }
    break;
  case 0x5d:
    param_1[0x184] = 3;
    return;
  case 0x5e:
    IdleRespond__12CTalkMonster(param_1);
    break;
  case 0x5f:
    FIdleSpeak__12CTalkMonster(param_1);
    break;
  case 0x60:
    FIdleHello__12CTalkMonster(param_1);
    break;
  case 0x61:
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1bd,0);
    break;
  case 0x62:
    iVar1 = param_1[0x111];
    lVar3 = (longdouble)(*DAT_001c118c)(0x40333333,0x404ccccd,0x3f800000,0x3f4ccccd);
    (**(code **)(iVar1 + 0x188))(param_1,param_1[0x1ad],(float)lVar3);
    break;
  case 99:
    func_0x00082cc4(param_1);
    break;
  case 100:
  case 0x65:
  case 0x68:
    param_1[0x154] = (int)(*gpGlobals + (float)param_2[1]);
    return;
  case 0x66:
    goto LAB_000f4e32;
  case 0x67:
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1bd);
    if (iVar1 != 0) {
      *(undefined4 *)(*param_1 + 0xb0) = 0x42700000;
      piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x1bd);
      iVar1 = *piVar2;
      fStack_c = *(float *)(iVar1 + 8) - *(float *)(*param_1 + 8);
      fStack_8 = *(float *)(iVar1 + 0xc) - *(float *)(*param_1 + 0xc);
      fStack_4 = *(float *)(iVar1 + 0x10) - *(float *)(*param_1 + 0x10);
      lVar3 = (longdouble)VecToYaw__12CBaseMonsterG6Vector(param_1,&fStack_c);
      lVar3 = lVar3 - (longdouble)*(float *)(*param_1 + 0x54);
      if ((longdouble)_FUN_0014e394 < lVar3) {
        lVar3 = lVar3 - (longdouble)360.0;
      }
      lVar4 = (longdouble)-180.0;
      if (0x3f < (byte)((lVar4 < lVar3 |
                         (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1)) {
        lVar3 = (longdouble)360.0 + lVar3;
      }
      lVar4 = (longdouble)0.0;
      if ((byte)((lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1) < 0x40) {
        iVar1 = *param_1;
        lVar3 = lVar3 - (longdouble)45.0;
        lVar4 = (longdouble)0.0;
        if (0x3f < (byte)((lVar4 < lVar3 |
                           (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1))
        goto LAB_000f4bb8;
      }
      else {
        iVar1 = *param_1;
        lVar3 = (longdouble)45.0 + lVar3;
        if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 1) {
          FUN_000f4bbc();
          return;
        }
LAB_000f4bb8:
        lVar3 = (longdouble)0.0;
      }
      *(float *)(iVar1 + 0xac) = (float)(lVar3 + (longdouble)*(float *)(*param_1 + 0x54));
    }
  }
  iVar1 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
  if (iVar1 == 0) {
    param_1[0x15b] = 4;
  }
LAB_000f4e32:
  return;
}


