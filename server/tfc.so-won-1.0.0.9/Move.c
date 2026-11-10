// Move__12CBaseMonsterf  @ 000c3bf0
void Move__12CBaseMonsterf(int *param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 in_FPUControlWord;
  float fStack_60;
  float afStack_58 [2];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = FRouteClear__12CBaseMonster(param_1);
  if ((iVar3 != 0) &&
     ((param_1[0x15f] == 0 || (iVar3 = FRefreshRoute__12CBaseMonster(param_1), iVar3 == 0)))) {
    (*DAT_001755b4)(2,"Tried to move with no route!\n");
    goto LAB_000c3ff0;
  }
  if (*gpGlobals < (float)param_1[0x136]) {
    return;
  }
  uVar6 = 0;
  pfVar1 = (float *)(param_1 + param_1[0x160] * 4 + 0x13f);
  iVar3 = *param_1;
  fStack_28 = *pfVar1 - *(float *)(iVar3 + 8);
  fStack_24 = pfVar1[1] - *(float *)(iVar3 + 0xc);
  fStack_2c = pfVar1[2] - *(float *)(iVar3 + 0x10);
  fStack_20 = SQRT(fStack_2c * fStack_2c + fStack_24 * fStack_24 + fStack_28 * fStack_28);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_20) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_20 == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_28 = 0.0;
    fStack_24 = 0.0;
    fStack_20 = 1.0;
  }
  else {
    fStack_20 = 1.0 / fStack_20;
    fStack_28 = fStack_20 * fStack_28;
    fStack_24 = fStack_20 * fStack_24;
    fStack_20 = fStack_20 * fStack_2c;
  }
  fStack_10 = fStack_28;
  fStack_c = fStack_24;
  fStack_8 = fStack_20;
  pfVar1 = (float *)(param_1 + param_1[0x160] * 4 + 0x13f);
  fVar2 = *pfVar1 - *(float *)(*param_1 + 8);
  fVar4 = pfVar1[1] - *(float *)(*param_1 + 0xc);
  fVar2 = SQRT(fVar4 * fVar4 + fVar2 * fVar2);
  fStack_38 = *pfVar1;
  fStack_34 = pfVar1[1];
  fStack_30 = pfVar1[2];
  MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&fStack_38);
  _uStack_3c = CONCAT22(uStack_3a,in_FPUControlWord);
  uStack_44 = CONCAT22(uStack_3a,CONCAT11(0xc,(char)in_FPUControlWord));
  (**(code **)(param_1[0xf2] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0x90)));
  fStack_60 = fVar2;
  if ((byte)(fVar2 < 200.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 200.0) << 0xe) >> 8)) != 1) {
    fStack_60 = 200.0;
  }
  if ((param_1[param_1[0x160] * 4 + 0x142] & 0xfffffe7fU) == 2) {
    piVar5 = param_1 + 0x11c;
LAB_000c3df0:
    uVar6 = __opP11CBaseEntity__7EHANDLE(piVar5);
  }
  else if ((param_1[param_1[0x160] * 4 + 0x142] & 0xfffffe7fU) == 1) {
    piVar5 = param_1 + 0x11e;
    goto LAB_000c3df0;
  }
  afStack_58[0] = 0.0;
  fStack_2c = fStack_60 * fStack_10;
  fStack_28 = fStack_60 * fStack_c;
  fStack_24 = fStack_60 * fStack_8;
  iVar3 = *param_1;
  fStack_38 = *(float *)(iVar3 + 8) + fStack_2c;
  fStack_34 = *(float *)(iVar3 + 0xc) + fStack_28;
  fStack_30 = *(float *)(iVar3 + 0x10) + fStack_24;
  iVar3 = (**(code **)(param_1[0xf2] + 0x138))(param_1,iVar3 + 8,&fStack_38,uVar6,afStack_58);
  if (iVar3 != 2) {
    (**(code **)(param_1[0xf2] + 0x14c))(param_1);
    fVar4 = gpGlobals[0x1d];
    if ((fVar4 == 0.0) && (fVar4 = (float)(*DAT_001755d4)(0), fVar4 == 0.0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)((int)fVar4 + 0xd8);
    }
    if (piVar5 != (int *)0x0) {
      DispatchBlocked__FP7edict_sT0
                (*(undefined4 *)(*param_1 + 0x1e8),*(undefined4 *)(*piVar5 + 0x1e8));
      fVar4 = (float)param_1[0x161];
      if (((((byte)(0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) == 1) &&
           (iVar3 = (**(code **)(piVar5[0xf2] + 0x68))(piVar5), iVar3 != 0)) &&
          ((*(byte *)(*piVar5 + 0x184) & 8) == 0)) &&
         (fVar4 = *gpGlobals - (float)param_1[0x136],
         (byte)(3.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar4 == 3.0) << 0xe) >> 8)) == 1)) {
        fVar4 = (float)param_1[0xf6];
        if ((byte)(afStack_58[0] < fVar4 |
                   (byte)((ushort)((ushort)(NAN(afStack_58[0]) || NAN(fVar4)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(afStack_58[0] == fVar4) << 0xe) >> 8)) == 1) {
          param_1[0x136] = (int)(*gpGlobals + (float)param_1[0x161]);
          return;
        }
        goto code_r0x000c40a0;
      }
    }
    iVar3 = (**(code **)(param_1[0xf2] + 0x19c))
                      (param_1,*param_1 + 8,param_1 + param_1[0x160] * 4 + 0x13f,afStack_58[0],uVar6
                       ,&uStack_1c);
    if (iVar3 != 0) {
      uStack_50 = uStack_1c;
      uStack_4c = uStack_18;
      uStack_48 = uStack_14;
      InsertWaypoint__12CBaseMonsterG6Vectori(param_1,&uStack_50,8);
      RouteSimplify__12CBaseMonsterP11CBaseEntity(param_1,uVar6);
      FUN_000c40a0();
      return;
    }
    (**(code **)(param_1[0xf2] + 0x14c))(param_1);
    fVar2 = (float)param_1[0x161];
    if (((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) ||
       ((*(byte *)(param_1 + 0x16c) & 0x20) != 0)) {
      SetConditions__12CBaseMonsteri(param_1,0x40000000);
      (*DAT_001755b4)(2,"%s Failed to move (%d)!\n",*(int *)*param_1 + (int)gpGlobals[0x26],
                      (*(byte *)(param_1 + 0x16c) & 0x20) != 0);
      return;
    }
    FRefreshRoute__12CBaseMonster(param_1);
    iVar3 = FRouteClear__12CBaseMonster(param_1);
    if (iVar3 == 0) {
      if (*gpGlobals - (float)param_1[0x136] < 0.2) {
        *(byte *)(param_1 + 0x16c) = *(byte *)(param_1 + 0x16c) | 0x20;
      }
      param_1[0x136] = (int)(*gpGlobals + 0.1);
      return;
    }
LAB_000c3ff0:
    SetConditions__12CBaseMonsteri(param_1,0x40000000);
    return;
  }
code_r0x000c40a0:
  iVar3 = (**(code **)(param_1[0xf2] + 0x144))(param_1,fVar2);
  if (iVar3 != 0) {
    AdvanceRoute__12CBaseMonsterf(param_1,fVar2);
  }
  if (*gpGlobals < (float)param_1[0x136]) {
    (**(code **)(param_1[0xf2] + 0x14c))(param_1);
    return;
  }
  if (fStack_60 < param_2 * (float)param_1[0xf6]) {
    param_2 = fStack_60 / (float)param_1[0xf6];
  }
  (**(code **)(param_1[0xf2] + 0x140))(param_1,uVar6,&fStack_10,param_2);
  if (param_1[0x15f] != 0) {
    return;
  }
  (**(code **)(param_1[0xf2] + 0x14c))(param_1);
  RouteClear__12CBaseMonster(param_1);
  return;
}


// Move__14CTriggerCamera  @ 00112d60
void Move__14CTriggerCamera(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  longdouble lVar6;
  undefined4 uVar7;
  float fVar8;
  float local_20;
  float local_1c;
  float local_18;
  
  pfVar4 = gpGlobals;
  if (param_1[0xf9] != 0) {
    fVar8 = (float)param_1[0xfe] - *(float *)(*param_1 + 0x1d8) * gpGlobals[1];
    param_1[0xfe] = (int)fVar8;
    if (fVar8 <= 0.0) {
      if (*(int *)(*(int *)param_1[0xf9] + 0x1b4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*(int *)param_1[0xf9] + 0x1b4) + (int)pfVar4[0x26],param_1,param_1,3,0);
        if ((*(byte *)(*(int *)param_1[0xf9] + 0x180) & 4) != 0) {
          *(undefined4 *)(*(int *)param_1[0xf9] + 0x1b4) = 0;
        }
      }
      iVar5 = (**(code **)(*(int *)(param_1[0xf9] + 0x3c8) + 0xa4))(param_1[0xf9]);
      param_1[0xf9] = iVar5;
      if (iVar5 == 0) {
        iVar5 = *param_1;
        *(undefined4 *)(iVar5 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar5 + 0x24) = DAT_00175484;
        *(undefined4 *)(iVar5 + 0x28) = DAT_00175488;
      }
      else {
        fVar8 = *(float *)(*(int *)param_1[0xf9] + 0x1d8);
        if ((byte)(0.0 < fVar8 | (byte)((ushort)((ushort)NAN(fVar8) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar8 == 0.0) << 0xe) >> 8)) != 0x40) {
          param_1[0xff] = (int)fVar8;
        }
        iVar5 = *(int *)param_1[0xf9];
        iVar1 = *param_1;
        local_20 = *(float *)(iVar5 + 8) - *(float *)(iVar1 + 8);
        local_1c = *(float *)(iVar5 + 0xc) - *(float *)(iVar1 + 0xc);
        fVar8 = *(float *)(iVar5 + 0x10) - *(float *)(iVar1 + 0x10);
        param_1[0xfe] = (int)SQRT(fVar8 * fVar8 + local_1c * local_1c + local_20 * local_20);
        local_18 = SQRT(fVar8 * fVar8 + local_1c * local_1c + local_20 * local_20);
        if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_20 = 0.0;
          local_1c = 0.0;
          local_18 = 1.0;
        }
        else {
          local_18 = 1.0 / local_18;
          local_20 = local_18 * local_20;
          local_1c = local_18 * local_1c;
          local_18 = local_18 * fVar8;
        }
        *(float *)(iVar1 + 0x44) = local_20;
        *(float *)(iVar1 + 0x48) = local_1c;
        *(float *)(iVar1 + 0x4c) = local_18;
        lVar6 = (longdouble)(**(code **)(*(int *)(param_1[0xf9] + 0x3c8) + 100))(param_1[0xf9]);
        param_1[0xfd] = (int)(float)(lVar6 + (longdouble)*gpGlobals);
      }
    }
    if ((float)param_1[0xfd] <= *gpGlobals) {
      fVar8 = (float)param_1[0x101] * gpGlobals[1];
      uVar7 = *(undefined4 *)(*param_1 + 0x1d8);
      iVar5 = param_1[0xff];
    }
    else {
      fVar8 = (float)param_1[0x102] * gpGlobals[1];
      uVar7 = *(undefined4 *)(*param_1 + 0x1d8);
      iVar5 = 0;
    }
    lVar6 = (longdouble)UTIL_Approach__Ffff(iVar5,uVar7,fVar8);
    *(float *)(*param_1 + 0x1d8) = (float)lVar6;
    fVar2 = gpGlobals[1] + gpGlobals[1];
    iVar5 = *param_1;
    fVar8 = *(float *)(iVar5 + 0x1d8);
    fVar3 = 1.0 - fVar2;
    *(float *)(iVar5 + 0x20) =
         fVar2 * fVar8 * *(float *)(iVar5 + 0x44) + fVar3 * *(float *)(iVar5 + 0x20);
    *(float *)(iVar5 + 0x24) =
         fVar2 * fVar8 * *(float *)(iVar5 + 0x48) + fVar3 * *(float *)(iVar5 + 0x24);
    *(float *)(iVar5 + 0x28) =
         fVar2 * fVar8 * *(float *)(iVar5 + 0x4c) + fVar3 * *(float *)(iVar5 + 0x28);
  }
  return;
}


// Move__9CPushableP11CBaseEntityi  @ 000b3990
void Move__9CPushableP11CBaseEntityi(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  iVar4 = *param_2;
  bVar3 = false;
  if (((*(byte *)(iVar4 + 0x185) & 2) != 0) && (*(int *)(iVar4 + 0x17c) != 0)) {
    if (*(int *)(iVar4 + 0x17c) == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(iVar4 + 0x17c) + 0xdc;
    }
    if (iVar7 == *param_1) {
      if (*(int *)(iVar7 + 0x1a0) < 1) {
        return;
      }
      *(float *)(iVar7 + 0x28) = *(float *)(iVar4 + 0x28) * 0.1 + *(float *)(iVar7 + 0x28);
      return;
    }
  }
  if ((*(byte *)(iVar4 + 0x184) & 8) != 0) {
    if ((param_3 != 0) && ((*(byte *)(iVar4 + 0x160) & 0x28) == 0)) {
      return;
    }
    bVar3 = true;
  }
  if (bVar3) {
    if ((*(byte *)(iVar4 + 0x185) & 2) == 0) {
      if (*(int *)(*param_1 + 0x1a0) < 1) {
        return;
      }
      fVar2 = 0.1;
    }
    else {
      fVar2 = 1.0;
    }
  }
  else {
    fVar2 = 0.25;
  }
  *(float *)(*param_1 + 0x20) = fVar2 * *(float *)(iVar4 + 0x20) + *(float *)(*param_1 + 0x20);
  *(float *)(*param_1 + 0x24) = fVar2 * *(float *)(iVar4 + 0x24) + *(float *)(*param_1 + 0x24);
  iVar7 = *param_1;
  fVar2 = SQRT(*(float *)(iVar7 + 0x24) * *(float *)(iVar7 + 0x24) +
               *(float *)(iVar7 + 0x20) * *(float *)(iVar7 + 0x20));
  if ((param_3 != 0) &&
     (fVar1 = (float)param_1[0xfc],
     (byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1)) {
    *(float *)(iVar7 + 0x20) = (fVar1 * *(float *)(iVar7 + 0x20)) / fVar2;
    *(float *)(*param_1 + 0x24) = ((float)param_1[0xfc] * *(float *)(*param_1 + 0x24)) / fVar2;
  }
  if (bVar3) {
    *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(*param_1 + 0x20);
    *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(*param_1 + 0x24);
    fVar1 = *gpGlobals - (float)param_1[0xfd];
    if ((byte)(0.7 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.7) << 0xe) >> 8)) == 1) {
      param_1[0xfd] = (int)*gpGlobals;
      if (((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1) &&
         ((*(byte *)(*param_1 + 0x185) & 2) != 0)) {
        iVar4 = (*DAT_00175628)(0,2);
        param_1[0xfb] = iVar4;
        uVar6 = *(undefined4 *)(*param_1 + 0x1e8);
        puVar5 = (&_9CPushable_m_soundNames)[iVar4];
        uVar10 = 0;
        uVar9 = 0x3f4ccccd;
        uVar8 = 0x3f000000;
      }
      else {
        uVar6 = *(undefined4 *)(*param_1 + 0x1e8);
        puVar5 = (&_9CPushable_m_soundNames)[param_1[0xfb]];
        uVar10 = 0x20;
        uVar9 = 0;
        uVar8 = 0;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar6,1,puVar5,uVar8,uVar9,uVar10,100);
    }
  }
  return;
}


