// StartTask__12CBaseMonsterP6Task_t  @ 000da2e0
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
    param_1[0x138] = (int)(*gpGlobals + (float)param_2[1]);
    break;
  case 3:
  case 0x53:
    break;
  case 4:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x13e] = (int)ROUND((float)param_2[1]);
    FUN_000db86d();
    return;
  case 5:
  case 6:
    piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x121);
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
        iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
        if ((iVar3 == 0) ||
           (iVar3 = MoveToTarget__12CBaseMonster8Activityf(param_1,uVar6,0x40000000), iVar3 == 0)) {
          SetConditions__12CBaseMonsteri(param_1,0x40000000);
          (*DAT_001a7f34)(2,"%s Failed to reach target!!!\n",*(int *)*param_1 + (int)gpGlobals[0x26]
                         );
          RouteClear__12CBaseMonster(param_1);
          FUN_000db89a();
          return;
        }
        goto code_r0x000db89a;
      }
    }
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x13f] = 4;
      FUN_000db89a();
      return;
    }
    goto code_r0x000db89a;
  case 7:
    piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x121);
    iVar3 = *piVar5;
    local_24 = *(float *)(iVar3 + 8) - *(float *)(*param_1 + 8);
    local_20 = *(float *)(iVar3 + 0xc) - *(float *)(*param_1 + 0xc);
    local_1c = *(float *)(iVar3 + 0x10) - *(float *)(*param_1 + 0x10);
    local_18 = SQRT(local_1c * local_1c + local_20 * local_20 + local_24 * local_24);
    if (1.0 <= local_18) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x121);
      iVar3 = *piVar5;
      param_1[0x165] = *(int *)(iVar3 + 8);
      param_1[0x166] = *(int *)(iVar3 + 0xc);
      param_1[0x167] = *(int *)(iVar3 + 0x10);
      iVar3 = MoveToTarget__12CBaseMonster8Activityf(param_1,3,0x40000000);
      if (iVar3 != 0) {
        return;
      }
      goto LAB_000db394;
    }
    goto code_r0x000db89a;
  case 8:
    piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
    if (piVar5 == (int *)0x0) goto LAB_000db394;
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
      iVar3 = (**(code **)(param_1[0xf5] + 0x1a4))(param_1,&fStack_34,&fStack_28,0,local_10);
      if (iVar3 == 0) {
        pcVar8 = "GetPathToEnemy failed!!\n";
        goto LAB_000db386;
      }
    }
    goto code_r0x000db89a;
  case 9:
    iVar3 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x171,0x40,0);
    if (iVar3 == 0) {
      local_24 = (float)param_1[0x171];
      local_20 = (float)param_1[0x172];
      local_1c = (float)param_1[0x173];
      iVar3 = *param_1;
      local_18 = *(float *)(iVar3 + 0x174);
      local_14 = *(float *)(iVar3 + 0x178);
      local_10 = *(float *)(iVar3 + 0x17c);
      fStack_30 = (float)param_1[0x171] - *(float *)(iVar3 + 8);
      fStack_2c = (float)param_1[0x172] - *(float *)(iVar3 + 0xc);
      fStack_28 = (float)param_1[0x173] - *(float *)(iVar3 + 0x10);
      fStack_34 = SQRT(fStack_28 * fStack_28 + fStack_2c * fStack_2c + fStack_30 * fStack_30);
      iVar3 = (**(code **)(param_1[0xf5] + 0x1a4))(param_1,&local_24,&local_18,0,fStack_34);
      if (iVar3 == 0) {
        pcVar8 = "GetPathToEnemyLKP failed!!\n";
        goto LAB_000db386;
      }
    }
    goto code_r0x000db89a;
  case 10:
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    fStack_28 = gpGlobals[10] * 64.0;
    local_24 = gpGlobals[0xb] * 64.0;
    local_20 = gpGlobals[0xc] * 64.0;
    fStack_34 = (float)param_1[0x171] - fStack_28;
    fStack_30 = (float)param_1[0x172] - local_24;
    fStack_2c = (float)param_1[0x173] - local_20;
    iVar3 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,&fStack_34,0x40,0);
    if (iVar3 == 0) {
      pcVar8 = "GetPathToEnemyCorpse failed!!\n";
      goto LAB_000db386;
    }
    goto code_r0x000db89a;
  default:
    (*DAT_001a7f34)(2,"No StartTask entry for %d\n",*param_2);
    break;
  case 0xc:
    iVar3 = (*DAT_001a7e78)(0,"classname","player");
    if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(undefined4 *)(iVar3 + 0x7c);
    }
    iVar3 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x165,0x40,uVar6);
LAB_000db242:
    if (iVar3 == 0) goto LAB_000db24a;
    goto code_r0x000db89a;
  case 0xd:
    RouteClear__12CBaseMonster(param_1);
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
    if (iVar3 != 0) {
      iVar3 = MoveToTarget__12CBaseMonster8Activityf(param_1,param_1[0x168],0x3f800000);
      goto LAB_000db242;
    }
LAB_000db24a:
    pcVar8 = "GetPathToSpot failed!!\n";
LAB_000db386:
    (*DAT_001a7f34)(2,pcVar8);
    goto LAB_000db394;
  case 0xe:
    iVar3 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                      (param_1,param_1[0x168],0x40000000,DAT_001a82ac + param_1[0x16e] * 0x58);
    if (iVar3 == 0) {
      pcVar8 = "GetPathToHintNode failed!!\n";
      goto LAB_000db386;
    }
    goto code_r0x000db89a;
  case 0xf:
    param_1[0x165] = param_1[0x16b];
    param_1[0x166] = param_1[0x16c];
    param_1[0x167] = param_1[0x16d];
    iVar3 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                      (param_1,param_1[0x168],0x40000000,param_1 + 0x165);
    if (iVar3 == 0) {
      pcVar8 = "GetPathToLastPosition failed!!\n";
      goto LAB_000db386;
    }
    goto code_r0x000db89a;
  case 0x10:
    iVar3 = (**(code **)(param_1[0xf5] + 0x1cc))(param_1);
    if ((iVar3 == 0) ||
       (iVar3 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                          (param_1,param_1[0x168],0x40000000,iVar3), iVar3 == 0)) {
      pcVar8 = "GetPathToBestSound failed!!\n";
      goto LAB_000db386;
    }
    goto code_r0x000db89a;
  case 0x11:
    iVar3 = (**(code **)(param_1[0xf5] + 0x1d0))(param_1);
    if ((iVar3 == 0) ||
       (iVar3 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                          (param_1,param_1[0x168],0x40000000,iVar3), iVar3 == 0)) {
      pcVar8 = "GetPathToBestScent failed!!\n";
      goto LAB_000db386;
    }
    goto code_r0x000db89a;
  case 0x12:
    iVar3 = LookupActivity__14CBaseAnimatingi(param_1,4);
    if (iVar3 == -1) {
LAB_000db3ee:
      param_1[0x168] = 3;
      FUN_000db89a();
      return;
    }
    goto LAB_000db3b8;
  case 0x13:
    if (*(int *)(*param_1 + 0x108) == 5) {
      param_1[0x168] = 5;
    }
    iVar3 = LookupActivity__14CBaseAnimatingi(param_1,3);
    if (iVar3 != -1) goto LAB_000db3ee;
LAB_000db3b8:
    param_1[0x168] = 4;
    FUN_000db89a();
    return;
  case 0x14:
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    fStack_4c = (float)param_1[0x142] - *(float *)(*param_1 + 8);
    fStack_30 = (float)param_1[0x143] - *(float *)(*param_1 + 0xc);
    fStack_2c = (float)param_1[0x144] - *(float *)(*param_1 + 0x10);
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
      param_1[0x168] = 0xc;
      FUN_000db89a();
      return;
    }
    param_1[0x168] = 0xb;
    FUN_000db89a();
    return;
  case 0x15:
    param_1[0x139] = (int)*gpGlobals;
    FUN_000db89a();
    return;
  case 0x16:
    iVar3 = *param_1;
    param_1[0x16b] = *(int *)(iVar3 + 8);
    param_1[0x16c] = *(int *)(iVar3 + 0xc);
    param_1[0x16d] = *(int *)(iVar3 + 0x10);
    FUN_000db89a();
    return;
  case 0x17:
    param_1[0x16b] = (int)g_vecZero;
    param_1[0x16c] = (int)DAT_001a7e04;
    param_1[0x16d] = (int)DAT_001a7e08;
    FUN_000db89a();
    return;
  case 0x18:
    param_1[0x13b] = (int)*(short *)(DAT_001a82ac + 0x52 + param_1[0x16e] * 0x58);
    break;
  case 0x19:
    iVar3 = FindHintNode__12CBaseMonster(param_1);
    param_1[0x16e] = iVar3;
    if (iVar3 == -1) goto LAB_000db394;
    goto code_r0x000db89a;
  case 0x1a:
    param_1[0x16e] = -1;
    FUN_000db89a();
    return;
  case 0x1b:
    iVar3 = GetSmallFlinchActivity__12CBaseMonster(param_1);
    param_1[0x13b] = iVar3;
    break;
  case 0x1c:
    goto switchD_000da316_caseD_1c;
  case 0x1d:
    iVar3 = FRouteClear__12CBaseMonster(param_1);
    if (iVar3 != 0) {
      pcVar8 = "No route to face!\n";
      goto LAB_000db386;
    }
    pfVar2 = (float *)(param_1 + param_1[0x163] * 4 + 0x142);
    local_24 = *pfVar2;
    local_20 = pfVar2[1];
    local_1c = pfVar2[2];
    goto LAB_000dac0c;
  case 0x1e:
    local_24 = (float)param_1[0x171];
    local_20 = (float)param_1[0x172];
    local_1c = (float)param_1[0x173];
    goto LAB_000dac0c;
  case 0x1f:
    *(undefined4 *)(*param_1 + 0xac) = *(undefined4 *)(DAT_001a82ac + 0x54 + param_1[0x16e] * 0x58);
    goto switchD_000da316_caseD_1c;
  case 0x20:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x121);
      iVar3 = *piVar5;
      local_24 = *(float *)(iVar3 + 8);
      local_20 = *(float *)(iVar3 + 0xc);
      local_1c = *(float *)(iVar3 + 0x10);
      goto LAB_000dac0c;
    }
    goto LAB_000db394;
  case 0x21:
    local_24 = (float)param_1[0x16b];
    local_20 = (float)param_1[0x16c];
    local_1c = (float)param_1[0x16d];
LAB_000dac0c:
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_24);
    SetTurnActivity__12CBaseMonster(param_1);
    break;
  case 0x22:
  case 0x27:
    param_1[0x13b] = 0x1c;
    break;
  case 0x23:
  case 0x28:
    param_1[0x13b] = 0x1d;
    break;
  case 0x24:
  case 0x29:
    param_1[0x13b] = 0x1e;
    break;
  case 0x25:
  case 0x2a:
    param_1[0x13b] = 0x1f;
    break;
  case 0x26:
  case 0x2b:
    param_1[0x13b] = 0x20;
    break;
  case 0x2c:
    param_1[0x13b] = 0x3c;
    break;
  case 0x2d:
    param_1[0x13b] = 0x3d;
    break;
  case 0x37:
    (*DAT_001a7f34)(2,"SOUND\n");
    FUN_000db89a();
    return;
  case 0x38:
  case 0x43:
    pcVar4 = *(code **)(param_1[0xf5] + 0x200);
    goto LAB_000db669;
  case 0x39:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x13b] = (int)ROUND((float)param_2[1]);
    FUN_000db86d();
    return;
  case 0x3a:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    iVar3 = (**(code **)(param_1[0xf5] + 0x16c))(param_1,(int)ROUND((float)param_2[1]));
    if (iVar3 != 0) {
      ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,iVar3);
      return;
    }
    goto LAB_000db394;
  case 0x3b:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x17c] = (int)ROUND((float)param_2[1]);
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x13f] = 4;
    }
    break;
  case 0x3c:
    param_1[0x17c] = 0;
    goto code_r0x000db89a;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    param_1[0x13b] = (int)ROUND((float)param_2[1]);
    break;
  case 0x40:
    pcVar4 = *(code **)(param_1[0xf5] + 0x208);
    goto LAB_000db669;
  case 0x41:
    pcVar4 = *(code **)(param_1[0xf5] + 0x204);
    goto LAB_000db669;
  case 0x42:
    pcVar4 = *(code **)(param_1[0xf5] + 0x20c);
LAB_000db669:
    (*pcVar4)(param_1);
    FUN_000db89a();
    return;
  case 0x44:
    pfVar2 = (float *)(**(code **)(param_1[0xf5] + 0x1cc))(param_1);
    if (pfVar2 != (float *)0x0) {
      local_24 = *pfVar2;
      local_20 = pfVar2[1];
      local_1c = pfVar2[2];
      local_18 = g_vecZero;
      local_14 = DAT_001a7e04;
      local_10 = DAT_001a7e08;
      iVar3 = param_1[0xf5];
      lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b0))(param_1);
      fVar10 = (float)(int)pfVar2[4];
      goto code_r0x000daae4;
    }
    goto LAB_000db394;
  case 0x45:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
    if (iVar3 == 0) {
      iVar3 = *param_1;
    }
    else {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11f);
      iVar3 = *piVar5;
    }
    iVar1 = FindLateralCover__12CBaseMonsterRC6VectorT1(param_1,iVar3 + 8,iVar3 + 0x174);
    if (iVar1 != 0) {
LAB_000daa5d:
      param_1[0x139] = (int)(*gpGlobals + (float)param_2[1]);
      FUN_000db86d();
      return;
    }
    local_24 = *(float *)(iVar3 + 8);
    local_20 = *(float *)(iVar3 + 0xc);
    local_1c = *(float *)(iVar3 + 0x10);
    local_18 = *(float *)(iVar3 + 0x174);
    local_14 = *(float *)(iVar3 + 0x178);
    local_10 = *(float *)(iVar3 + 0x17c);
    iVar3 = param_1[0xf5];
    lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b0))(param_1);
    fVar10 = 0.0;
code_r0x000daae4:
    iVar3 = (**(code **)(iVar3 + 0x1a8))(param_1,&local_24,&local_18,fVar10,(float)lVar9);
    if (iVar3 != 0) {
      param_1[0x139] = (int)(*gpGlobals + (float)param_2[1]);
      FUN_000db86d();
      return;
    }
    goto LAB_000db394;
  case 0x47:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11f);
      iVar3 = *piVar5;
      local_24 = *(float *)(iVar3 + 8);
      local_20 = *(float *)(iVar3 + 0xc);
      local_1c = *(float *)(iVar3 + 0x10);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11f);
      iVar3 = *piVar5;
      local_18 = *(float *)(iVar3 + 0x174);
      local_14 = *(float *)(iVar3 + 0x178);
      local_10 = *(float *)(iVar3 + 0x17c);
      iVar3 = param_1[0xf5];
      lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b0))(param_1);
      iVar3 = (**(code **)(iVar3 + 0x1a8))(param_1,&local_24,&local_18,0,(float)lVar9);
joined_r0x000da89f:
      if (iVar3 != 0) goto code_r0x000db89a;
    }
    goto LAB_000db394;
  case 0x48:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11f);
      iVar3 = *piVar5;
      local_18 = *(float *)(iVar3 + 8);
      local_14 = *(float *)(iVar3 + 0xc);
      local_10 = *(float *)(iVar3 + 0x10);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11f);
      iVar3 = *piVar5;
      local_24 = *(float *)(iVar3 + 0x174);
      local_20 = *(float *)(iVar3 + 0x178);
      local_1c = *(float *)(iVar3 + 0x17c);
      iVar3 = (**(code **)(param_1[0xf5] + 0x1a8))(param_1,&local_18,&local_24,0,param_2[1]);
      goto joined_r0x000da89f;
    }
    goto LAB_000db394;
  case 0x49:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11f);
      iVar3 = *piVar5;
      local_24 = *(float *)(iVar3 + 8);
      local_20 = *(float *)(iVar3 + 0xc);
      local_1c = *(float *)(iVar3 + 0x10);
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11f);
      iVar3 = *piVar5;
      local_18 = *(float *)(iVar3 + 0x174);
      local_14 = *(float *)(iVar3 + 0x178);
      local_10 = *(float *)(iVar3 + 0x17c);
      iVar3 = param_1[0xf5];
      lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b0))(param_1);
      iVar3 = (**(code **)(iVar3 + 0x1a8))(param_1,&local_24,&local_18,param_2[1],(float)lVar9);
      goto joined_r0x000da89f;
    }
    goto LAB_000db394;
  case 0x4a:
    iVar3 = *param_1;
    local_24 = *(float *)(iVar3 + 8);
    local_20 = *(float *)(iVar3 + 0xc);
    local_1c = *(float *)(iVar3 + 0x10);
    local_18 = *(float *)(iVar3 + 0x174);
    local_14 = *(float *)(iVar3 + 0x178);
    local_10 = *(float *)(iVar3 + 0x17c);
    iVar3 = param_1[0xf5];
    lVar9 = (longdouble)(**(code **)(iVar3 + 0x1b0))(param_1);
    iVar3 = (**(code **)(iVar3 + 0x1a8))(param_1,&local_24,&local_18,0,(float)lVar9);
    if (iVar3 != 0) goto LAB_000daa5d;
LAB_000db394:
    SetConditions__12CBaseMonsteri(param_1,0x40000000);
    break;
  case 0x4b:
    Eat__12CBaseMonsterf(param_1,param_2[1]);
    FUN_000db86d();
    return;
  case 0x4c:
    RouteClear__12CBaseMonster(param_1);
    iVar3 = (**(code **)(param_1[0xf5] + 0x1e4))(param_1);
    param_1[0x13b] = iVar3;
    *(undefined4 *)(*param_1 + 0x170) = 1;
    break;
  case 0x4d:
    iVar3 = param_1[0x186];
    if (*(int *)(iVar3 + 0x61c) == 0) {
      param_1[0x13b] = 1;
    }
    else {
      (**(code **)(*(int *)(iVar3 + 0x3d4) + 0x218))(iVar3,param_1,*(undefined4 *)(iVar3 + 0x61c),0)
      ;
      iVar3 = strcmp((char *)((int)gpGlobals[0x26] + *(int *)(param_1[0x186] + 0x61c)),
                     (char *)((int)gpGlobals[0x26] + *(int *)(param_1[0x186] + 0x620)));
      if (iVar3 == 0) {
        *(undefined4 *)(*param_1 + 0x138) = 0;
      }
    }
    break;
  case 0x4e:
    *(undefined4 *)(*param_1 + 0x108) = 5;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    param_1[0x185] = 0;
    break;
  case 0x4f:
    DelayStart__12CCineMonsteri(param_1[0x186],0);
    FUN_000db89a();
    return;
  case 0x50:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x121);
      iVar3 = *param_1;
      iVar1 = *piVar5;
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
      *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
      FUN_000db89a();
      return;
    }
code_r0x000db89a:
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x13f] = 4;
    }
    break;
  case 0x51:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
    if (iVar3 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x121);
      lVar9 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*piVar5 + 0x54));
      *(float *)(*param_1 + 0xac) = (float)lVar9;
    }
    iVar3 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar3 == 0) {
      param_1[0x13f] = 4;
    }
    param_1[0x13b] = 1;
    RouteClear__12CBaseMonster(param_1);
    break;
  case 0x52:
    lVar9 = (longdouble)(*DAT_001a7fac)(0x3dcccccd,param_2[1]);
    param_1[0x138] = (int)(float)(lVar9 + (longdouble)*gpGlobals);
    break;
  case 0x54:
    if (param_1[0x13b] == param_1[0x168]) {
      iVar3 = (**(code **)(param_1[0xf5] + 0x148))(param_1);
      param_1[0x13b] = iVar3;
    }
    RouteClear__12CBaseMonster(param_1);
    FUN_000db89a();
    return;
  case 0x55:
    lVar9 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
    lVar9 = (longdouble)UTIL_AngleMod__Ff((float)(lVar9 + (longdouble)(float)param_2[1]));
    *(float *)(*param_1 + 0xac) = (float)lVar9;
    FUN_000dac1b();
    return;
  case 0x56:
    lVar9 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
    lVar9 = (longdouble)UTIL_AngleMod__Ff((float)(lVar9 - (longdouble)(float)param_2[1]));
    *(float *)(*param_1 + 0xac) = (float)lVar9;
    FUN_000dac1b();
    return;
  case 0x57:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x16f] = param_1[0x16f] | (int)ROUND((float)param_2[1]);
    FUN_000db86d();
    return;
  case 0x58:
    local_4 = CONCAT22(local_4._2_2_,in_FPUControlWord);
    local_c = CONCAT22(local_4._2_2_,CONCAT11(0xc,uVar7));
    param_1[0x16f] = param_1[0x16f] & ~(int)ROUND((float)param_2[1]);
    FUN_000db86d();
    return;
  case 0x59:
    iVar3 = FRouteClear__12CBaseMonster(param_1);
    if (iVar3 != 0) {
      FUN_000db89a();
      return;
    }
  }
  return;
switchD_000da316_caseD_1c:
  SetTurnActivity__12CBaseMonster(param_1);
  return;
}


// StartTask__12CTalkMonsterP6Task_t  @ 000e7cf8
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
  float local_18;
  float fStack_14;
  float fStack_10;
  float local_c;
  float local_8;
  float local_4;
  
  switch(*param_2) {
  case 0x4e:
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1a1,0);
    StartTask__12CBaseMonsterP6Task_t(param_1,param_2);
    return;
  default:
    StartTask__12CBaseMonsterP6Task_t(param_1,param_2);
    return;
  case 0x5b:
    (**(code **)(param_1[0xf5] + 0x210))(param_1,0);
    iVar1 = param_1[0xf5];
    lVar3 = (longdouble)(*DAT_001a7fac)(0x40000000,0x40200000,0x3f800000,0x3f4ccccd);
    (**(code **)(iVar1 + 0x180))(param_1,param_1[400],(float)lVar3);
    break;
  case 0x5c:
    iVar1 = *param_1;
    local_c = *(float *)(iVar1 + 0x50);
    local_4 = *(float *)(iVar1 + 0x58);
    local_8 = *(float *)(iVar1 + 0xac) + 180.0;
    (*DAT_001a7e90)(&local_c,&local_18,0,0);
    fStack_28 = (float)param_2[1];
    fStack_30 = fStack_28 * local_18;
    fStack_2c = fStack_28 * fStack_14;
    fStack_28 = fStack_28 * fStack_10;
    iVar1 = *param_1;
    fStack_24 = *(float *)(iVar1 + 8) + fStack_30;
    fStack_20 = *(float *)(iVar1 + 0xc) + fStack_2c;
    fStack_1c = *(float *)(iVar1 + 0x10) + fStack_28;
    local_c = fStack_24;
    local_8 = fStack_20;
    local_4 = fStack_1c;
    iVar1 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,3,0x40000000,&local_c);
    if (iVar1 == 0) {
      iVar1 = *param_1;
      fStack_30 = *(float *)(iVar1 + 8);
      fStack_2c = *(float *)(iVar1 + 0xc);
      fStack_28 = *(float *)(iVar1 + 0x10);
      fStack_24 = *(float *)(iVar1 + 0x174);
      fStack_20 = *(float *)(iVar1 + 0x178);
      fStack_1c = *(float *)(iVar1 + 0x17c);
      iVar1 = param_1[0xf5];
      lVar3 = (longdouble)(**(code **)(iVar1 + 0x1b0))(param_1);
      iVar1 = (**(code **)(iVar1 + 0x1a8))(param_1,&fStack_30,&fStack_24,0,(float)lVar3);
      if (iVar1 == 0) {
        SetConditions__12CBaseMonsteri(param_1,0x40000000);
        return;
      }
      param_1[0x139] = (int)(*gpGlobals + 2.0);
    }
    break;
  case 0x5d:
    param_1[0x168] = 3;
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
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1a1,0);
    break;
  case 0x62:
    iVar1 = param_1[0xf5];
    lVar3 = (longdouble)(*DAT_001a7fac)(0x40333333,0x404ccccd,0x3f800000,0x3f4ccccd);
    (**(code **)(iVar1 + 0x180))(param_1,param_1[0x191],(float)lVar3);
    break;
  case 99:
    FIdleStare__12CTalkMonster(param_1);
    break;
  case 100:
  case 0x65:
  case 0x68:
    param_1[0x138] = (int)(*gpGlobals + (float)param_2[1]);
    return;
  case 0x66:
    goto switchD_000e7d2b_caseD_66;
  case 0x67:
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a1);
    if (iVar1 != 0) {
      *(undefined4 *)(*param_1 + 0xb0) = 0x42700000;
      piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x1a1);
      iVar1 = *piVar2;
      local_c = *(float *)(iVar1 + 8) - *(float *)(*param_1 + 8);
      local_8 = *(float *)(iVar1 + 0xc) - *(float *)(*param_1 + 0xc);
      local_4 = *(float *)(iVar1 + 0x10) - *(float *)(*param_1 + 0x10);
      lVar3 = (longdouble)VecToYaw__12CBaseMonsterG6Vector(param_1,&local_c);
      lVar3 = lVar3 - (longdouble)*(float *)(*param_1 + 0x54);
      if ((longdouble)180.0 < lVar3) {
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
        goto LAB_000e7ee4;
      }
      else {
        iVar1 = *param_1;
        lVar3 = (longdouble)45.0 + lVar3;
        if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 1) {
LAB_000e7ee4:
          lVar3 = (longdouble)0.0;
        }
      }
      *(float *)(iVar1 + 0xac) = (float)(lVar3 + (longdouble)*(float *)(*param_1 + 0x54));
    }
  }
  iVar1 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
  if (iVar1 == 0) {
    param_1[0x13f] = 4;
  }
switchD_000e7d2b_caseD_66:
  return;
}


