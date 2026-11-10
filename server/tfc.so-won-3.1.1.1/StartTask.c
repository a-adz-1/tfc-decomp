// StartTask__12CBaseMonsterP6Task_t  @ 000e7564
/* WARNING: Type propagation algorithm not settling */

void StartTask__12CBaseMonsterP6Task_t(int *param_1,int *param_2)

{
  float fVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined2 in_FPUControlWord;
  longdouble lVar11;
  float fVar12;
  float fStack_68;
  float fStack_50;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  uVar2 = (undefined1)in_FPUControlWord;
  switch(*param_2) {
  case 1:
  case 2:
    param_1[0x158] = (int)(*gpGlobals + (float)param_2[1]);
    break;
  case 3:
  case 0x53:
    break;
  case 4:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar2));
    param_1[0x15e] = (int)ROUND((float)param_2[1]);
    goto LAB_000e8c31;
  case 5:
  case 6:
    piVar8 = (int *)__rf__7EHANDLE(param_1 + 0x141);
    iVar6 = *piVar8;
    local_28 = *(float *)(iVar6 + 8) - *(float *)(*param_1 + 8);
    local_24 = *(float *)(iVar6 + 0xc) - *(float *)(*param_1 + 0xc);
    local_20 = *(float *)(iVar6 + 0x10) - *(float *)(*param_1 + 0x10);
    local_1c = SQRT(local_20 * local_20 + local_24 * local_24 + local_28 * local_28);
    if (1.0 <= local_1c) {
      uVar9 = 4;
      if (*param_2 == 5) {
        uVar9 = 3;
      }
      iVar6 = LookupActivity__14CBaseAnimatingi(param_1,uVar9);
      if (iVar6 != -1) {
        iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
        if ((iVar6 == 0) ||
           (iVar6 = MoveToTarget__12CBaseMonster8Activityf(param_1,uVar9,0x40000000), iVar6 == 0)) {
          SetConditions__12CBaseMonsteri(param_1,0x40000000);
          (*DAT_0019f794)(2,"%s Failed to reach target!!!\n",*(int *)*param_1 + (int)gpGlobals[0x26]
                         );
          RouteClear__12CBaseMonster(param_1);
          FUN_000e8c5a();
          return;
        }
        goto code_r0x000e8c5a;
      }
    }
    iVar6 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar6 == 0) {
      param_1[0x15f] = 4;
      FUN_000e8c5a();
      return;
    }
    goto code_r0x000e8c5a;
  case 7:
    piVar8 = (int *)__rf__7EHANDLE(param_1 + 0x141);
    iVar6 = *piVar8;
    local_28 = *(float *)(iVar6 + 8) - *(float *)(*param_1 + 8);
    local_24 = *(float *)(iVar6 + 0xc) - *(float *)(*param_1 + 0xc);
    local_20 = *(float *)(iVar6 + 0x10) - *(float *)(*param_1 + 0x10);
    local_1c = SQRT(local_20 * local_20 + local_24 * local_24 + local_28 * local_28);
    if (1.0 <= local_1c) {
      piVar8 = (int *)__rf__7EHANDLE(param_1 + 0x141);
      iVar6 = *piVar8;
      param_1[0x185] = *(int *)(iVar6 + 8);
      param_1[0x186] = *(int *)(iVar6 + 0xc);
      param_1[0x187] = *(int *)(iVar6 + 0x10);
      iVar6 = MoveToTarget__12CBaseMonster8Activityf(param_1,3,0x40000000);
      if (iVar6 != 0) {
        return;
      }
      goto LAB_000e8808;
    }
    goto code_r0x000e8c5a;
  case 8:
    piVar8 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
    if (piVar8 == (int *)0x0) goto LAB_000e8808;
    iVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,*piVar8 + 8,2,piVar8);
    if (iVar6 == 0) {
      fStack_38 = *(float *)(*piVar8 + 8);
      fStack_34 = *(float *)(*piVar8 + 0xc);
      fStack_30 = *(float *)(*piVar8 + 0x10);
      iVar6 = *piVar8;
      fStack_2c = *(float *)(iVar6 + 0x174);
      local_28 = *(float *)(iVar6 + 0x178);
      local_24 = *(float *)(iVar6 + 0x17c);
      iVar6 = *piVar8;
      local_20 = *(float *)(iVar6 + 8) - *(float *)(*param_1 + 8);
      local_1c = *(float *)(iVar6 + 0xc) - *(float *)(*param_1 + 0xc);
      local_18 = *(float *)(iVar6 + 0x10) - *(float *)(*param_1 + 0x10);
      local_14 = SQRT(local_18 * local_18 + local_1c * local_1c + local_20 * local_20);
      iVar6 = (**(code **)(param_1[0x115] + 0x1ac))(param_1,&fStack_38,&fStack_2c,0,local_14);
      if (iVar6 == 0) {
        FUN_000e87fa();
        return;
      }
    }
    goto code_r0x000e8c5a;
  case 9:
    iVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x191,0x40,0);
    if (iVar6 == 0) {
      local_28 = (float)param_1[0x191];
      local_24 = (float)param_1[0x192];
      local_20 = (float)param_1[0x193];
      iVar6 = *param_1;
      local_1c = *(float *)(iVar6 + 0x174);
      local_18 = *(float *)(iVar6 + 0x178);
      local_14 = *(float *)(iVar6 + 0x17c);
      fStack_34 = local_28 - *(float *)(iVar6 + 8);
      fStack_30 = local_24 - *(float *)(iVar6 + 0xc);
      fStack_2c = local_20 - *(float *)(iVar6 + 0x10);
      fStack_38 = SQRT(fStack_2c * fStack_2c + fStack_30 * fStack_30 + fStack_34 * fStack_34);
      iVar6 = (**(code **)(param_1[0x115] + 0x1ac))(param_1,&local_28,&local_1c,0,fStack_38);
      if (iVar6 == 0) {
        FUN_000e87fa();
        return;
      }
    }
    goto code_r0x000e8c5a;
  case 10:
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    fStack_2c = gpGlobals[10] * 64.0;
    local_28 = gpGlobals[0xb] * 64.0;
    local_24 = gpGlobals[0xc] * 64.0;
    fStack_38 = (float)param_1[0x191] - fStack_2c;
    fStack_34 = (float)param_1[0x192] - local_28;
    fStack_30 = (float)param_1[0x193] - local_24;
    iVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,&fStack_38,0x40,0);
    if (iVar6 == 0) {
      FUN_000e87fa();
      return;
    }
    goto code_r0x000e8c5a;
  default:
    (*DAT_0019f794)(2,"No StartTask entry for %d\n",*param_2);
    break;
  case 0xc:
    iVar6 = (*DAT_0019f6d8)(0,"classname","player");
    if ((iVar6 == 0) && (iVar6 = (*DAT_0019f7b4)(0), iVar6 == 0)) {
      uVar9 = 0;
    }
    else {
      uVar9 = *(undefined4 *)(iVar6 + 0x7c);
    }
    iVar6 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,param_1 + 0x185,0x40,uVar9);
LAB_000e86b5_1:
    if (iVar6 == 0) goto LAB_000e86bb_3;
    goto code_r0x000e8c5a;
  case 0xd:
    RouteClear__12CBaseMonster(param_1);
    iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
    if (iVar6 != 0) {
      iVar6 = MoveToTarget__12CBaseMonster8Activityf(param_1,param_1[0x188],0x3f800000);
      goto LAB_000e86b5_1;
    }
LAB_000e86bb_3:
    pcVar10 = "GetPathToSpot failed!!\n";
code_r0x000e87fa:
    (*DAT_0019f794)(2,pcVar10);
    goto LAB_000e8808;
  case 0xe:
    iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                      (param_1,param_1[0x188],0x40000000,DAT_0019fb2c + param_1[0x18e] * 0x58);
    if (iVar6 == 0) {
      FUN_000e87fa();
      return;
    }
    goto code_r0x000e8c5a;
  case 0xf:
    param_1[0x185] = param_1[0x18b];
    param_1[0x186] = param_1[0x18c];
    param_1[0x187] = param_1[0x18d];
    iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                      (param_1,param_1[0x188],0x40000000,param_1 + 0x185);
    if (iVar6 == 0) {
      FUN_000e87fa();
      return;
    }
    goto code_r0x000e8c5a;
  case 0x10:
    iVar6 = (**(code **)(param_1[0x115] + 0x1d4))(param_1);
    if ((iVar6 == 0) ||
       (iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                          (param_1,param_1[0x188],0x40000000,iVar6), iVar6 == 0)) {
      pcVar10 = "GetPathToBestSound failed!!\n";
      goto code_r0x000e87fa;
    }
    goto code_r0x000e8c5a;
  case 0x11:
    iVar6 = (**(code **)(param_1[0x115] + 0x1d8))(param_1);
    if ((iVar6 == 0) ||
       (iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector
                          (param_1,param_1[0x188],0x40000000,iVar6), iVar6 == 0)) {
      pcVar10 = "GetPathToBestScent failed!!\n";
      goto code_r0x000e87fa;
    }
    goto code_r0x000e8c5a;
  case 0x12:
    iVar6 = LookupActivity__14CBaseAnimatingi(param_1,4);
    if (iVar6 == -1) {
LAB_000e885d:
      param_1[0x188] = 3;
      FUN_000e8c5a();
      return;
    }
    goto LAB_000e8828;
  case 0x13:
    if (*(int *)(*param_1 + 0x108) == 5) {
      param_1[0x188] = 5;
    }
    iVar6 = LookupActivity__14CBaseAnimatingi(param_1,3);
    if (iVar6 != -1) goto LAB_000e885d;
LAB_000e8828:
    param_1[0x188] = 4;
    FUN_000e8c5a();
    return;
  case 0x14:
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    fStack_50 = (float)param_1[0x162] - *(float *)(*param_1 + 8);
    fStack_34 = (float)param_1[0x163] - *(float *)(*param_1 + 0xc);
    fStack_30 = (float)param_1[0x164] - *(float *)(*param_1 + 0x10);
    fStack_2c = SQRT(fStack_34 * fStack_34 + fStack_50 * fStack_50);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_2c == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar12 = 0.0;
      fStack_50 = 0.0;
    }
    else {
      fStack_50 = fStack_50 * (1.0 / fStack_2c);
      fVar12 = (1.0 / fStack_2c) * fStack_34;
    }
    fStack_68 = gpGlobals[0x10];
    fVar1 = gpGlobals[0x11];
    fStack_38 = SQRT(fVar1 * fVar1 + fStack_68 * fStack_68);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_38 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar1 = 0.0;
      fStack_68 = 0.0;
    }
    else {
      fStack_68 = fStack_68 * (1.0 / fStack_38);
      fVar1 = (1.0 / fStack_38) * fVar1;
    }
    if (0.0 < fVar12 * fVar1 + fStack_50 * fStack_68) {
      param_1[0x188] = 0xc;
      FUN_000e8c5a();
      return;
    }
    param_1[0x188] = 0xb;
    FUN_000e8c5a();
    return;
  case 0x15:
    param_1[0x159] = (int)*gpGlobals;
    FUN_000e8c5a();
    return;
  case 0x16:
    iVar6 = *param_1;
    param_1[0x18b] = *(int *)(iVar6 + 8);
    param_1[0x18c] = *(int *)(iVar6 + 0xc);
    param_1[0x18d] = *(int *)(iVar6 + 0x10);
    FUN_000e8c5a();
    return;
  case 0x17:
    param_1[0x18b] = (int)g_vecZero;
    param_1[0x18c] = (int)DAT_0019f664;
    param_1[0x18d] = (int)DAT_0019f668;
    FUN_000e8c5a();
    return;
  case 0x18:
    param_1[0x15b] = (int)*(short *)(DAT_0019fb2c + 0x52 + param_1[0x18e] * 0x58);
    break;
  case 0x19:
    iVar6 = FindHintNode__12CBaseMonster(param_1);
    param_1[0x18e] = iVar6;
    if (iVar6 == -1) goto LAB_000e8808;
    goto code_r0x000e8c5a;
  case 0x1a:
    param_1[0x18e] = -1;
    FUN_000e8c5a();
    return;
  case 0x1b:
    iVar6 = GetSmallFlinchActivity__12CBaseMonster(param_1);
    param_1[0x15b] = iVar6;
    break;
  case 0x1c:
    lVar11 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
    fVar12 = (float)lVar11;
    if ((byte)(-45.0 < fVar12 | (byte)((ushort)((ushort)NAN(fVar12) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar12 == -45.0) << 0xe) >> 8)) != 1) {
      iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0x10);
joined_r0x000e775d:
      if (iVar6 != -1) {
        param_1[0x15b] = 0x10;
        return;
      }
    }
    goto joined_r0x000e77e9;
  case 0x1d:
    iVar6 = FRouteClear__12CBaseMonster(param_1);
    if (iVar6 != 0) {
      FUN_000e87fa();
      return;
    }
    pfVar5 = (float *)(param_1 + param_1[0x183] * 4 + 0x162);
    local_28 = *pfVar5;
    local_24 = pfVar5[1];
    local_20 = pfVar5[2];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_28);
    lVar11 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
    fVar12 = (float)lVar11;
    if ((byte)(-45.0 < fVar12 | (byte)((ushort)((ushort)NAN(fVar12) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar12 == -45.0) << 0xe) >> 8)) != 1) {
      iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0x10);
      goto joined_r0x000e775d;
    }
    goto joined_r0x000e77e9;
  case 0x1e:
    local_28 = (float)param_1[0x191];
    local_24 = (float)param_1[0x192];
    local_20 = (float)param_1[0x193];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_28);
    lVar11 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
    fVar12 = (float)lVar11;
    if ((byte)(-45.0 < fVar12 | (byte)((ushort)((ushort)NAN(fVar12) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar12 == -45.0) << 0xe) >> 8)) != 1) {
      iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0x10);
      goto joined_r0x000e775d;
    }
    goto joined_r0x000e77e9;
  case 0x1f:
    *(undefined4 *)(*param_1 + 0xac) =
         *(undefined4 *)(DAT_0019fb2c + 0x54 + (param_1[0x18e] + param_1[0x18e] * 10) * 8);
    lVar11 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
    fVar12 = (float)lVar11;
    if ((byte)(-45.0 < fVar12 | (byte)((ushort)((ushort)NAN(fVar12) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar12 == -45.0) << 0xe) >> 8)) != 1) {
      iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0x10);
      goto joined_r0x000e775d;
    }
    goto joined_r0x000e77e9;
  case 0x20:
    iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
    if (iVar6 != 0) {
      piVar8 = (int *)__rf__7EHANDLE(param_1 + 0x141);
      iVar6 = *piVar8;
      local_28 = *(float *)(iVar6 + 8);
      local_24 = *(float *)(iVar6 + 0xc);
      local_20 = *(float *)(iVar6 + 0x10);
      MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_28);
      lVar11 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
      fVar12 = (float)lVar11;
      if ((byte)(-45.0 < fVar12 | (byte)((ushort)((ushort)NAN(fVar12) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar12 == -45.0) << 0xe) >> 8)) != 1) {
        iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0x10);
        goto joined_r0x000e775d;
      }
      goto joined_r0x000e77e9;
    }
    goto LAB_000e8808;
  case 0x21:
    local_28 = (float)param_1[0x18b];
    local_24 = (float)param_1[0x18c];
    local_20 = (float)param_1[0x18d];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_28);
    lVar11 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
    fVar12 = (float)lVar11;
    if ((byte)(-45.0 < fVar12 | (byte)((ushort)((ushort)NAN(fVar12) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar12 == -45.0) << 0xe) >> 8)) != 1) {
      iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0x10);
      goto joined_r0x000e775d;
    }
    goto joined_r0x000e77e9;
  case 0x22:
  case 0x27:
    param_1[0x15b] = 0x1c;
    break;
  case 0x23:
  case 0x28:
    param_1[0x15b] = 0x1d;
    break;
  case 0x24:
  case 0x29:
    param_1[0x15b] = 0x1e;
    break;
  case 0x25:
  case 0x2a:
    param_1[0x15b] = 0x1f;
    break;
  case 0x26:
  case 0x2b:
    param_1[0x15b] = 0x20;
    break;
  case 0x2c:
    param_1[0x15b] = 0x3c;
    break;
  case 0x2d:
    param_1[0x15b] = 0x3d;
    break;
  case 0x37:
    (*DAT_0019f794)(2,"SOUND\n");
    FUN_000e8c5a();
    return;
  case 0x38:
  case 0x43:
    pcVar7 = *(code **)(param_1[0x115] + 0x208);
    goto LAB_000e8a71;
  case 0x39:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar2));
    param_1[0x15b] = (int)ROUND((float)param_2[1]);
    goto LAB_000e8c31;
  case 0x3a:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar2));
    iVar6 = (**(code **)(param_1[0x115] + 0x174))(param_1,(int)ROUND((float)param_2[1]));
    if (iVar6 != 0) {
      param_1[0x160] = iVar6;
      param_1[0x161] = 0;
      param_1[0x15f] = 0;
      param_1[0x13e] = 0;
      param_1[0x19c] = 0;
      if ((*(byte *)(iVar6 + 10) & 2) == 0) {
        if (*(int *)(iVar6 + 0xc) == 0) {
          return;
        }
      }
      else if (*(int *)(iVar6 + 0xc) == 0) {
        pcVar7 = FUN_00151760;
        goto LAB_000e7a02;
      }
      if ((*(byte *)(param_1[0x160] + 10) & 2) != 0) {
        return;
      }
      pcVar7 = (code *)"Sound mask without COND_HEAR_SOUND!\n";
LAB_000e7a02:
      (*DAT_0019f794)(2,pcVar7);
      return;
    }
    goto LAB_000e8808;
  case 0x3b:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar2));
    param_1[0x19c] = (int)ROUND((float)param_2[1]);
    goto LAB_000e8c31;
  case 0x3c:
    param_1[0x19c] = 0;
    goto code_r0x000e8c5a;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    param_1[0x15b] = (int)ROUND((float)param_2[1]);
    break;
  case 0x40:
    pcVar7 = *(code **)(param_1[0x115] + 0x210);
    goto LAB_000e8a71;
  case 0x41:
    pcVar7 = *(code **)(param_1[0x115] + 0x20c);
    goto LAB_000e8a71;
  case 0x42:
    pcVar7 = *(code **)(param_1[0x115] + 0x214);
LAB_000e8a71:
    (*pcVar7)(param_1);
    FUN_000e8c5a();
    return;
  case 0x44:
    pfVar5 = (float *)(**(code **)(param_1[0x115] + 0x1d4))(param_1);
    if (pfVar5 != (float *)0x0) {
      local_28 = *pfVar5;
      local_24 = pfVar5[1];
      local_20 = pfVar5[2];
      local_1c = g_vecZero;
      local_18 = DAT_0019f664;
      local_14 = DAT_0019f668;
      iVar6 = param_1[0x115];
      lVar11 = (longdouble)(**(code **)(iVar6 + 0x1b8))(param_1);
      fVar12 = (float)(int)pfVar5[4];
LAB_000e7d98:
      iVar6 = (**(code **)(iVar6 + 0x1b0))(param_1,&local_28,&local_1c,fVar12,(float)lVar11);
      if (iVar6 != 0) {
        param_1[0x159] = (int)(*gpGlobals + (float)param_2[1]);
        goto LAB_000e8c31;
      }
    }
    goto LAB_000e8808;
  case 0x45:
    iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
    if (iVar6 == 0) {
      iVar6 = *param_1;
    }
    else {
      piVar8 = (int *)__rf__7EHANDLE(param_1 + 0x13f);
      iVar6 = *piVar8;
    }
    iVar4 = FindLateralCover__12CBaseMonsterRC6VectorT1(param_1,iVar6 + 8,iVar6 + 0x174);
    if (iVar4 == 0) {
      local_28 = *(float *)(iVar6 + 8);
      local_24 = *(float *)(iVar6 + 0xc);
      local_20 = *(float *)(iVar6 + 0x10);
      local_1c = *(float *)(iVar6 + 0x174);
      local_18 = *(float *)(iVar6 + 0x178);
      local_14 = *(float *)(iVar6 + 0x17c);
      iVar6 = param_1[0x115];
      lVar11 = (longdouble)(**(code **)(iVar6 + 0x1b8))(param_1);
      fVar12 = 0.0;
      goto LAB_000e7d98;
    }
LAB_000e7d11:
    param_1[0x159] = (int)(*gpGlobals + (float)param_2[1]);
    goto LAB_000e8c31;
  case 0x47:
    piVar8 = param_1 + 0x13f;
    iVar6 = __opP11CBaseEntity__7EHANDLE(piVar8);
    if (iVar6 != 0) {
      piVar3 = (int *)__rf__7EHANDLE(piVar8);
      iVar6 = *piVar3;
      local_28 = *(float *)(iVar6 + 8);
      local_24 = *(float *)(iVar6 + 0xc);
      local_20 = *(float *)(iVar6 + 0x10);
      piVar8 = (int *)__rf__7EHANDLE(piVar8);
      iVar6 = *piVar8;
      local_1c = *(float *)(iVar6 + 0x174);
      local_18 = *(float *)(iVar6 + 0x178);
      local_14 = *(float *)(iVar6 + 0x17c);
      iVar6 = param_1[0x115];
      lVar11 = (longdouble)(**(code **)(iVar6 + 0x1b8))(param_1);
      iVar6 = (**(code **)(iVar6 + 0x1b0))(param_1,&local_28,&local_1c,0,(float)lVar11);
joined_r0x000e7b76:
      if (iVar6 != 0) goto code_r0x000e8c5a;
    }
    goto LAB_000e8808;
  case 0x48:
    piVar8 = param_1 + 0x13f;
    iVar6 = __opP11CBaseEntity__7EHANDLE(piVar8);
    if (iVar6 != 0) {
      piVar3 = (int *)__rf__7EHANDLE(piVar8);
      iVar6 = *piVar3;
      local_1c = *(float *)(iVar6 + 8);
      local_18 = *(float *)(iVar6 + 0xc);
      local_14 = *(float *)(iVar6 + 0x10);
      piVar8 = (int *)__rf__7EHANDLE(piVar8);
      iVar6 = *piVar8;
      local_28 = *(float *)(iVar6 + 0x174);
      local_24 = *(float *)(iVar6 + 0x178);
      local_20 = *(float *)(iVar6 + 0x17c);
      iVar6 = (**(code **)(param_1[0x115] + 0x1b0))(param_1,&local_1c,&local_28,0,param_2[1]);
      goto joined_r0x000e7b76;
    }
    goto LAB_000e8808;
  case 0x49:
    piVar8 = param_1 + 0x13f;
    iVar6 = __opP11CBaseEntity__7EHANDLE(piVar8);
    if (iVar6 != 0) {
      piVar3 = (int *)__rf__7EHANDLE(piVar8);
      iVar6 = *piVar3;
      local_28 = *(float *)(iVar6 + 8);
      local_24 = *(float *)(iVar6 + 0xc);
      local_20 = *(float *)(iVar6 + 0x10);
      piVar8 = (int *)__rf__7EHANDLE(piVar8);
      iVar6 = *piVar8;
      local_1c = *(float *)(iVar6 + 0x174);
      local_18 = *(float *)(iVar6 + 0x178);
      local_14 = *(float *)(iVar6 + 0x17c);
      iVar6 = param_1[0x115];
      lVar11 = (longdouble)(**(code **)(iVar6 + 0x1b8))(param_1);
      iVar6 = (**(code **)(iVar6 + 0x1b0))(param_1,&local_28,&local_1c,param_2[1],(float)lVar11);
      goto joined_r0x000e7b76;
    }
    goto LAB_000e8808;
  case 0x4a:
    iVar6 = *param_1;
    local_28 = *(float *)(iVar6 + 8);
    local_24 = *(float *)(iVar6 + 0xc);
    local_20 = *(float *)(iVar6 + 0x10);
    local_1c = *(float *)(iVar6 + 0x174);
    local_18 = *(float *)(iVar6 + 0x178);
    local_14 = *(float *)(iVar6 + 0x17c);
    iVar6 = param_1[0x115];
    lVar11 = (longdouble)(**(code **)(iVar6 + 0x1b8))(param_1);
    iVar6 = (**(code **)(iVar6 + 0x1b0))(param_1,&local_28,&local_1c,0,(float)lVar11);
    if (iVar6 != 0) goto LAB_000e7d11;
LAB_000e8808:
    SetConditions__12CBaseMonsteri(param_1,0x40000000);
    break;
  case 0x4b:
    Eat__12CBaseMonsterf(param_1,param_2[1]);
    goto LAB_000e8c31;
  case 0x4c:
    RouteClear__12CBaseMonster(param_1);
    iVar6 = (**(code **)(param_1[0x115] + 0x1ec))(param_1);
    param_1[0x15b] = iVar6;
    *(undefined4 *)(*param_1 + 0x170) = 1;
    break;
  case 0x4d:
    iVar6 = param_1[0x1a6];
    if (*(int *)(iVar6 + 0x69c) == 0) {
      param_1[0x15b] = 1;
    }
    else {
      (**(code **)(*(int *)(iVar6 + 0x454) + 0x220))(iVar6,param_1,*(int *)(iVar6 + 0x69c),0);
      iVar6 = strcmp((char *)((int)gpGlobals[0x26] + *(int *)(param_1[0x1a6] + 0x69c)),
                     (char *)((int)gpGlobals[0x26] + *(int *)(param_1[0x1a6] + 0x6a0)));
      if (iVar6 == 0) {
        *(undefined4 *)(*param_1 + 0x138) = 0;
      }
    }
    break;
  case 0x4e:
    *(undefined4 *)(*param_1 + 0x108) = 5;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    param_1[0x1a5] = 0;
    break;
  case 0x4f:
    DelayStart__12CCineMonsteri(param_1[0x1a6],0);
    FUN_000e8c5a();
    return;
  case 0x50:
    iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
    if (iVar6 != 0) {
      piVar8 = (int *)__rf__7EHANDLE(param_1 + 0x141);
      iVar6 = *param_1;
      iVar4 = *piVar8;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar4 + 8);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar4 + 0xc);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
      FUN_000e8c5a();
      return;
    }
code_r0x000e8c5a:
    iVar6 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar6 == 0) {
      param_1[0x15f] = 4;
    }
    break;
  case 0x51:
    iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
    if (iVar6 != 0) {
      piVar8 = (int *)__rf__7EHANDLE(param_1 + 0x141);
      lVar11 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*piVar8 + 0x54));
      *(float *)(*param_1 + 0xac) = (float)lVar11;
    }
    iVar6 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar6 == 0) {
      param_1[0x15f] = 4;
    }
    param_1[0x15b] = 1;
    RouteClear__12CBaseMonster(param_1);
    break;
  case 0x52:
    lVar11 = (longdouble)(*DAT_0019f80c)(0x3dcccccd,param_2[1]);
    param_1[0x158] = (int)(float)(lVar11 + (longdouble)*gpGlobals);
    break;
  case 0x54:
    if (param_1[0x15b] == param_1[0x188]) {
      iVar6 = (**(code **)(param_1[0x115] + 0x150))(param_1);
      param_1[0x15b] = iVar6;
    }
    RouteClear__12CBaseMonster(param_1);
    FUN_000e8c5a();
    return;
  case 0x55:
    lVar11 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
    lVar11 = (longdouble)UTIL_AngleMod__Ff((float)(lVar11 + (longdouble)(float)param_2[1]));
    *(float *)(*param_1 + 0xac) = (float)lVar11;
    lVar11 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
    fVar12 = (float)lVar11;
    if ((byte)(-45.0 < fVar12 | (byte)((ushort)((ushort)NAN(fVar12) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar12 == -45.0) << 0xe) >> 8)) != 1) {
      iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0x10);
      goto joined_r0x000e775d;
    }
    goto joined_r0x000e77e9;
  case 0x56:
    lVar11 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
    lVar11 = (longdouble)UTIL_AngleMod__Ff((float)(lVar11 - (longdouble)(float)param_2[1]));
    *(float *)(*param_1 + 0xac) = (float)lVar11;
    lVar11 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
    fVar12 = (float)lVar11;
    if ((byte)(-45.0 < fVar12 | (byte)((ushort)((ushort)NAN(fVar12) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar12 == -45.0) << 0xe) >> 8)) != 1) {
      iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0x10);
      goto joined_r0x000e775d;
    }
joined_r0x000e77e9:
    if ((45.0 < fVar12) && (iVar6 = LookupActivity__14CBaseAnimatingi(param_1,0xf), iVar6 != -1)) {
      param_1[0x15b] = 0xf;
    }
    break;
  case 0x57:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar2));
    param_1[399] = param_1[399] | (int)ROUND((float)param_2[1]);
    goto LAB_000e8c31;
  case 0x58:
    local_8 = CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_10 = CONCAT22(local_8._2_2_,CONCAT11(0xc,uVar2));
    param_1[399] = param_1[399] & ~(int)ROUND((float)param_2[1]);
LAB_000e8c31:
    iVar6 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar6 == 0) {
      param_1[0x15f] = 4;
    }
    break;
  case 0x59:
    iVar6 = FRouteClear__12CBaseMonster(param_1);
    if (iVar6 != 0) {
      FUN_000e8c5a();
      return;
    }
  }
  return;
}


// StartTask__12CTalkMonsterP6Task_t  @ 000f6b48
void StartTask__12CTalkMonsterP6Task_t(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int **ppiVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  int *local_4c;
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
  
  ppiVar3 = (int **)&stack0xffffffbc;
  pfStack_48 = (float *)0xf6b56;
  switch(*param_2) {
  case 0x4e:
    pfStack_48 = (float *)0x0;
    local_4c = param_1 + 0x1c1;
    ppiVar3 = &local_4c;
    __as__7EHANDLEP11CBaseEntity();
  default:
    *(undefined4 **)((int)ppiVar3 + -4) = param_2;
    *(int **)((int)ppiVar3 + -8) = param_1;
    *(undefined4 *)((int)ppiVar3 + -0xc) = 0xf6f6c;
    StartTask__12CBaseMonsterP6Task_t();
    return;
  case 0x5b:
    pfStack_48 = (float *)0x0;
    local_4c = param_1;
    (**(code **)(param_1[0x115] + 0x218))();
    iVar1 = param_1[0x115];
    lVar4 = (longdouble)(*DAT_0019f80c)(0x40000000,0x40200000,0x3f800000,0x3f4ccccd);
    (**(code **)(iVar1 + 0x188))(param_1,param_1[0x1b0],(float)lVar4);
    break;
  case 0x5c:
    local_10 = *(float *)(*param_1 + 0x50);
    local_8 = *(float *)(*param_1 + 0x58);
    local_c = *(float *)(*param_1 + 0xac) + 180.0;
    pfStack_48 = (float *)0x0;
    local_4c = (int *)0x0;
    (*DAT_0019f6f0)(&local_10,&local_1c);
    local_2c = (float)param_2[1];
    local_34 = local_1c * local_2c;
    local_30 = local_18 * local_2c;
    local_2c = local_2c * local_14;
    local_28 = local_34 + *(float *)(*param_1 + 8);
    local_24 = local_30 + *(float *)(*param_1 + 0xc);
    local_20 = local_2c + *(float *)(*param_1 + 0x10);
    local_4c = (int *)0x40000000;
    pfStack_48 = &local_10;
    local_10 = local_28;
    local_c = local_24;
    local_8 = local_20;
    iVar1 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,3);
    if (iVar1 == 0) {
      iVar1 = *param_1;
      local_34 = *(float *)(iVar1 + 8);
      local_30 = *(float *)(iVar1 + 0xc);
      local_2c = *(float *)(iVar1 + 0x10);
      local_28 = *(float *)(iVar1 + 0x174);
      local_24 = *(float *)(iVar1 + 0x178);
      local_20 = *(float *)(iVar1 + 0x17c);
      iVar1 = param_1[0x115];
      pfStack_48 = (float *)param_1;
      local_4c = (int *)0xf6ef3;
      lVar4 = (longdouble)(**(code **)(iVar1 + 0x1b8))();
      local_4c = (int *)(float)lVar4;
      iVar1 = (**(code **)(iVar1 + 0x1b0))(param_1,&local_34,&local_28,0);
      if (iVar1 == 0) {
        pfStack_48 = (float *)0x40000000;
        local_4c = param_1;
        SetConditions__12CBaseMonsteri();
        return;
      }
      param_1[0x159] = (int)(*gpGlobals + 2.0);
    }
    break;
  case 0x5d:
    param_1[0x188] = 3;
    return;
  case 0x5e:
    pfStack_48 = (float *)param_1;
    local_4c = (int *)0xf6bfe;
    IdleRespond__12CTalkMonster();
    break;
  case 0x5f:
    pfStack_48 = (float *)param_1;
    local_4c = (int *)0xf6bee;
    FIdleSpeak__12CTalkMonster();
    break;
  case 0x60:
    pfStack_48 = (float *)param_1;
    local_4c = (int *)0xf6c0e;
    FIdleHello__12CTalkMonster();
    break;
  case 0x61:
    pfStack_48 = (float *)0x0;
    local_4c = param_1 + 0x1c1;
    __as__7EHANDLEP11CBaseEntity();
    break;
  case 0x62:
    iVar1 = param_1[0x115];
    pfStack_48 = (float *)0x3f4ccccd;
    local_4c = (int *)0x3f800000;
    lVar4 = (longdouble)(*DAT_0019f80c)(0x40333333,0x404ccccd);
    (**(code **)(iVar1 + 0x188))(param_1,param_1[0x1b1],(float)lVar4);
    break;
  case 99:
    pfStack_48 = (float *)param_1;
    local_4c = (int *)0xf6c1e;
    FIdleStare__12CTalkMonster();
    break;
  case 100:
  case 0x65:
  case 0x68:
    param_1[0x158] = (int)(*gpGlobals + (float)param_2[1]);
    return;
  case 0x66:
    goto switchD_000f6b7a_caseD_66;
  case 0x67:
    local_4c = (int *)0xf6c50;
    pfStack_48 = (float *)(param_1 + 0x1c1);
    iVar1 = __opP11CBaseEntity__7EHANDLE();
    if (iVar1 != 0) {
      *(undefined4 *)(*param_1 + 0xb0) = 0x42700000;
      local_4c = (int *)0xf6c6d;
      pfStack_48 = (float *)(param_1 + 0x1c1);
      piVar2 = (int *)__rf__7EHANDLE();
      iVar1 = *piVar2;
      local_10 = *(float *)(iVar1 + 8) - *(float *)(*param_1 + 8);
      local_c = *(float *)(iVar1 + 0xc) - *(float *)(*param_1 + 0xc);
      local_8 = *(float *)(iVar1 + 0x10) - *(float *)(*param_1 + 0x10);
      pfStack_48 = &local_10;
      local_4c = param_1;
      lVar4 = (longdouble)VecToYaw__12CBaseMonsterG6Vector();
      lVar5 = (longdouble)*(float *)(*param_1 + 0x54);
      lVar4 = lVar4 - lVar5;
      if ((longdouble)180.0 < lVar4) {
        lVar4 = lVar4 - (longdouble)360.0;
      }
      lVar6 = (longdouble)-180.0;
      if (0x3f < (byte)((lVar6 < lVar4 |
                         (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar4)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar6 == lVar4) << 0xe) >> 8)) - 1)) {
        lVar4 = (longdouble)360.0 + lVar4;
      }
      lVar6 = (longdouble)0;
      if ((byte)((lVar6 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar4)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar6 == lVar4) << 0xe) >> 8)) - 1) < 0x40) {
        lVar4 = lVar4 - (longdouble)45.0;
        if (0x3f < (byte)((lVar6 < lVar4 |
                           (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar4)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(lVar6 == lVar4) << 0xe) >> 8)) - 1))
        goto LAB_000f6d1e;
      }
      else {
        lVar4 = (longdouble)45.0 + lVar4;
        if (lVar6 < lVar4) {
LAB_000f6d1e:
          lVar4 = (longdouble)0;
        }
      }
      *(float *)(*param_1 + 0xac) = (float)(lVar5 + lVar4);
    }
  }
  pfStack_48 = (float *)0x40000000;
  local_4c = param_1;
  iVar1 = HasConditions__12CBaseMonsteri();
  if (iVar1 == 0) {
    param_1[0x15f] = 4;
  }
switchD_000f6b7a_caseD_66:
  return;
}


