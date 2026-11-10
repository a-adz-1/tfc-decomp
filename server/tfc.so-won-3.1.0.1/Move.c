// Move__12CBaseMonsterf  @ 000b1e6c
void Move__12CBaseMonsterf(int *param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined2 in_FPUControlWord;
  float fStack_5c;
  float afStack_54 [2];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined2 uStack_38;
  undefined2 uStack_36;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = FRouteClear__12CBaseMonster(param_1);
  if ((iVar3 == 0) ||
     ((param_1[0x162] != 0 && (iVar3 = FRefreshRoute__12CBaseMonster(param_1), iVar3 != 0)))) {
    if (*gpGlobals < (float)param_1[0x139]) {
      return;
    }
    uVar5 = 0;
    pfVar1 = (float *)(param_1 + param_1[0x163] * 4 + 0x142);
    iVar3 = *param_1;
    local_24 = *pfVar1 - *(float *)(iVar3 + 8);
    local_20 = pfVar1[1] - *(float *)(iVar3 + 0xc);
    local_28 = pfVar1[2] - *(float *)(iVar3 + 0x10);
    local_1c = SQRT(local_28 * local_28 + local_20 * local_20 + local_24 * local_24);
    if ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40) {
      local_24 = 0.0;
      local_20 = 0.0;
      local_1c = 1.0;
    }
    else {
      local_1c = 1.0 / local_1c;
      local_24 = local_1c * local_24;
      local_20 = local_1c * local_20;
      local_1c = local_1c * local_28;
    }
    local_c = local_24;
    local_8 = local_20;
    local_4 = local_1c;
    pfVar1 = (float *)(param_1 + param_1[0x163] * 4 + 0x142);
    fVar2 = *pfVar1 - *(float *)(*param_1 + 8);
    fVar4 = pfVar1[1] - *(float *)(*param_1 + 0xc);
    fVar2 = SQRT(fVar4 * fVar4 + fVar2 * fVar2);
    local_34 = *pfVar1;
    local_30 = pfVar1[1];
    local_2c = pfVar1[2];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_34);
    _uStack_38 = CONCAT22(uStack_36,in_FPUControlWord);
    uStack_40 = CONCAT22(uStack_36,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0xf5] + 0x110))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
    fStack_5c = fVar2;
    if ((byte)(fVar2 < 200.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 200.0) << 0xe) >> 8)) != 1) {
      fStack_5c = 200.0;
    }
    if ((param_1[param_1[0x163] * 4 + 0x145] & 0xfffffe7fU) == 2) {
      piVar6 = param_1 + 0x11f;
LAB_000b20b8:
      uVar5 = __opP11CBaseEntity__7EHANDLE(piVar6);
    }
    else if ((param_1[param_1[0x163] * 4 + 0x145] & 0xfffffe7fU) == 1) {
      piVar6 = param_1 + 0x121;
      goto LAB_000b20b8;
    }
    afStack_54[0] = 0.0;
    local_28 = fStack_5c * local_c;
    local_24 = fStack_5c * local_8;
    local_20 = fStack_5c * local_4;
    iVar3 = *param_1;
    local_34 = *(float *)(iVar3 + 8) + local_28;
    local_30 = *(float *)(iVar3 + 0xc) + local_24;
    local_2c = *(float *)(iVar3 + 0x10) + local_20;
    iVar3 = (**(code **)(param_1[0xf5] + 0x138))(param_1,iVar3 + 8,&local_34,uVar5,afStack_54);
    if (iVar3 != 2) {
      (**(code **)(param_1[0xf5] + 0x14c))(param_1);
      fVar4 = gpGlobals[0x1d];
      if ((fVar4 == 0.0) && (fVar4 = (float)(*DAT_001a7f54)(0), fVar4 == 0.0)) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = *(int **)((int)fVar4 + 0x7c);
      }
      if ((((piVar6 == (int *)0x0) ||
           (DispatchBlocked__FP7edict_sT0
                      (*(undefined4 *)(*param_1 + 0x208),*(undefined4 *)(*piVar6 + 0x208)),
           (float)param_1[0x164] <= 0.0)) ||
          (iVar3 = (**(code **)(piVar6[0xf5] + 0x68))(piVar6), iVar3 == 0)) ||
         (((*(byte *)(*piVar6 + 0x1a4) & 8) != 0 || (*gpGlobals - (float)param_1[0x139] <= 3.0)))) {
        iVar3 = (**(code **)(param_1[0xf5] + 0x19c))
                          (param_1,*param_1 + 8,param_1 + param_1[0x163] * 4 + 0x142,afStack_54[0],
                           uVar5,&uStack_18);
        if (iVar3 != 0) {
          uStack_4c = uStack_18;
          uStack_48 = uStack_14;
          uStack_44 = uStack_10;
          InsertWaypoint__12CBaseMonsterG6Vectori(param_1,&uStack_4c,8);
          RouteSimplify__12CBaseMonsterP11CBaseEntity(param_1,uVar5);
          FUN_000b2394();
          return;
        }
        (**(code **)(param_1[0xf5] + 0x14c))(param_1);
        if (((float)param_1[0x164] <= 0.0) || ((*(byte *)(param_1 + 0x16f) & 0x20) != 0)) {
          SetConditions__12CBaseMonsteri(param_1,0x40000000);
          (*DAT_001a7f34)(2,"%s Failed to move (%d)!\n",*(int *)*param_1 + (int)gpGlobals[0x26],
                          (*(byte *)(param_1 + 0x16f) & 0x20) != 0);
          return;
        }
        FRefreshRoute__12CBaseMonster(param_1);
        iVar3 = FRouteClear__12CBaseMonster(param_1);
        if (iVar3 == 0) {
          fVar2 = *gpGlobals - (float)param_1[0x139];
          if (0x3f < (byte)((0.2 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == 0.2) << 0xe) >> 8)) - 1)) {
            *(byte *)(param_1 + 0x16f) = *(byte *)(param_1 + 0x16f) | 0x20;
          }
          param_1[0x139] = (int)(*gpGlobals + 0.1);
          return;
        }
        goto LAB_000b22e3;
      }
      if (afStack_54[0] < (float)param_1[0xf9]) {
        param_1[0x139] = (int)(*gpGlobals + (float)param_1[0x164]);
        return;
      }
    }
    iVar3 = (**(code **)(param_1[0xf5] + 0x144))(param_1,fVar2);
    if (iVar3 != 0) {
      AdvanceRoute__12CBaseMonsterf(param_1,fVar2);
    }
    fVar2 = (float)param_1[0x139];
    fVar4 = *gpGlobals;
    if ((byte)((fVar2 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar4)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar4) << 0xe) >> 8)) - 1) < 0x40) {
      fVar2 = param_2 * (float)param_1[0xf9];
      if (0x3f < (byte)((fVar2 < fStack_5c |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fStack_5c)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fStack_5c) << 0xe) >> 8)) - 1)) {
        param_2 = fStack_5c / (float)param_1[0xf9];
      }
      (**(code **)(param_1[0xf5] + 0x140))(param_1,uVar5,&local_c,param_2);
      if (param_1[0x162] == 0) {
        (**(code **)(param_1[0xf5] + 0x14c))(param_1);
        RouteClear__12CBaseMonster(param_1);
      }
    }
    else {
      (**(code **)(param_1[0xf5] + 0x14c))(param_1);
    }
  }
  else {
    (*DAT_001a7f34)(2,"Tried to move with no route!\n");
LAB_000b22e3:
    SetConditions__12CBaseMonsteri(param_1,0x40000000);
  }
  return;
}


// Move__14CTriggerCamera  @ 00105a98
void Move__14CTriggerCamera(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  longdouble lVar5;
  undefined4 uVar6;
  float fVar7;
  float local_1c;
  float local_18;
  float local_14;
  
  if (param_1[0xfc] != 0) {
    fVar7 = (float)param_1[0x101] - *(float *)(*param_1 + 0x1f8) * gpGlobals[1];
    param_1[0x101] = (int)fVar7;
    if ((byte)(0.0 < fVar7 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar7 == 0.0) << 0xe) >> 8)) != 1) {
      if (*(int *)(*(int *)param_1[0xfc] + 0x1d4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*(int *)param_1[0xfc] + 0x1d4) + (int)gpGlobals[0x26],param_1,param_1,3,
                   0);
        if ((*(byte *)(*(int *)param_1[0xfc] + 0x1a0) & 4) != 0) {
          *(undefined4 *)(*(int *)param_1[0xfc] + 0x1d4) = 0;
        }
      }
      iVar4 = (**(code **)(*(int *)(param_1[0xfc] + 0x3d4) + 0xa4))(param_1[0xfc]);
      param_1[0xfc] = iVar4;
      if (iVar4 == 0) {
        iVar4 = *param_1;
        *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar4 + 0x24) = DAT_001a7e04;
        *(undefined4 *)(iVar4 + 0x28) = DAT_001a7e08;
      }
      else {
        fVar7 = *(float *)(*(int *)param_1[0xfc] + 0x1f8);
        if ((byte)(0.0 < fVar7 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar7 == 0.0) << 0xe) >> 8)) != 0x40) {
          param_1[0x102] = (int)fVar7;
        }
        iVar4 = *(int *)param_1[0xfc];
        iVar2 = *param_1;
        local_1c = *(float *)(iVar4 + 8) - *(float *)(iVar2 + 8);
        local_18 = *(float *)(iVar4 + 0xc) - *(float *)(iVar2 + 0xc);
        fVar7 = *(float *)(iVar4 + 0x10) - *(float *)(iVar2 + 0x10);
        param_1[0x101] = (int)SQRT(fVar7 * fVar7 + local_18 * local_18 + local_1c * local_1c);
        local_14 = SQRT(fVar7 * fVar7 + local_18 * local_18 + local_1c * local_1c);
        if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_1c = 0.0;
          local_18 = 0.0;
          local_14 = 1.0;
        }
        else {
          local_14 = 1.0 / local_14;
          local_1c = local_14 * local_1c;
          local_18 = local_14 * local_18;
          local_14 = local_14 * fVar7;
        }
        *(float *)(iVar2 + 0x44) = local_1c;
        *(float *)(iVar2 + 0x48) = local_18;
        *(float *)(iVar2 + 0x4c) = local_14;
        lVar5 = (longdouble)(**(code **)(*(int *)(param_1[0xfc] + 0x3d4) + 100))(param_1[0xfc]);
        param_1[0x100] = (int)(float)(lVar5 + (longdouble)*gpGlobals);
      }
    }
    fVar7 = (float)param_1[0x100];
    fVar1 = *gpGlobals;
    if ((byte)((fVar7 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar7) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar7 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      fVar7 = (float)param_1[0x104] * gpGlobals[1];
      uVar6 = *(undefined4 *)(*param_1 + 0x1f8);
      iVar4 = param_1[0x102];
    }
    else {
      fVar7 = (float)param_1[0x105] * gpGlobals[1];
      uVar6 = *(undefined4 *)(*param_1 + 0x1f8);
      iVar4 = 0;
    }
    lVar5 = (longdouble)UTIL_Approach__Ffff(iVar4,uVar6,fVar7);
    *(float *)(*param_1 + 0x1f8) = (float)lVar5;
    fVar1 = gpGlobals[1] + gpGlobals[1];
    iVar4 = *param_1;
    fVar7 = *(float *)(iVar4 + 0x1f8);
    fVar3 = 1.0 - fVar1;
    *(float *)(iVar4 + 0x20) =
         fVar1 * fVar7 * *(float *)(iVar4 + 0x44) + fVar3 * *(float *)(iVar4 + 0x20);
    *(float *)(iVar4 + 0x24) =
         fVar1 * fVar7 * *(float *)(iVar4 + 0x48) + fVar3 * *(float *)(iVar4 + 0x24);
    *(float *)(iVar4 + 0x28) =
         fVar1 * fVar7 * *(float *)(iVar4 + 0x4c) + fVar3 * *(float *)(iVar4 + 0x28);
  }
  return;
}


// Move__9CPushableP11CBaseEntityi  @ 0009f600
void Move__9CPushableP11CBaseEntityi(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  iVar3 = *param_2;
  bVar2 = false;
  if (((*(byte *)(iVar3 + 0x1a5) & 2) != 0) && (*(int *)(iVar3 + 0x19c) != 0)) {
    iVar4 = *(int *)(iVar3 + 0x19c) + 0x80;
    if (*(int *)(iVar3 + 0x19c) == 0) {
      iVar4 = 0;
    }
    if (iVar4 == *param_1) {
      if (*(int *)(iVar4 + 0x1c0) < 1) {
        return;
      }
      *(float *)(iVar4 + 0x28) = *(float *)(iVar3 + 0x28) * 0.1 + *(float *)(iVar4 + 0x28);
      return;
    }
  }
  if ((*(byte *)(iVar3 + 0x1a4) & 8) != 0) {
    if ((param_3 != 0) && ((*(byte *)(iVar3 + 0x180) & 0x28) == 0)) {
      return;
    }
    bVar2 = true;
  }
  if (bVar2) {
    if ((*(byte *)(iVar3 + 0x1a5) & 2) == 0) {
      if (*(int *)(*param_1 + 0x1c0) < 1) {
        return;
      }
      fVar1 = 0.1;
    }
    else {
      fVar1 = 1.0;
    }
  }
  else {
    fVar1 = 0.25;
  }
  *(float *)(*param_1 + 0x20) = fVar1 * *(float *)(iVar3 + 0x20) + *(float *)(*param_1 + 0x20);
  *(float *)(*param_1 + 0x24) = fVar1 * *(float *)(iVar3 + 0x24) + *(float *)(*param_1 + 0x24);
  iVar4 = *param_1;
  fVar1 = SQRT(*(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
               *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20));
  if ((param_3 != 0) && ((float)param_1[0xff] < fVar1)) {
    *(float *)(iVar4 + 0x20) = ((float)param_1[0xff] * *(float *)(iVar4 + 0x20)) / fVar1;
    *(float *)(*param_1 + 0x24) = ((float)param_1[0xff] * *(float *)(*param_1 + 0x24)) / fVar1;
  }
  if (bVar2) {
    *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(*param_1 + 0x20);
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(*param_1 + 0x24);
    if (0.7 < *gpGlobals - (float)param_1[0x100]) {
      param_1[0x100] = (int)*gpGlobals;
      if ((fVar1 <= 0.0) || ((*(byte *)(*param_1 + 0x1a5) & 2) == 0)) {
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        puVar6 = (&_9CPushable_m_soundNames)[param_1[0xfe]];
        uVar9 = 0x20;
        uVar8 = 0;
        uVar7 = 0;
      }
      else {
        iVar3 = (*DAT_001a7fa8)(0,2);
        param_1[0xfe] = iVar3;
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        puVar6 = (&_9CPushable_m_soundNames)[iVar3];
        uVar9 = 0;
        uVar8 = 0x3f4ccccd;
        uVar7 = 0x3f000000;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,1,puVar6,uVar7,uVar8,uVar9,100);
    }
  }
  return;
}


