// Move__12CBaseMonsterf  @ 000bd448
void Move__12CBaseMonsterf(int *param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  undefined2 in_FPUControlWord;
  int iStack_70;
  undefined4 local_60;
  float local_5c;
  float afStack_58 [2];
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 local_44;
  undefined2 local_3c;
  undefined2 uStack_3a;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (((param_1[param_1[0x183] * 4 + 0x165] == 0) || (param_1[0x182] == 0)) &&
     ((param_1[0x182] == 0 || (iVar4 = FRefreshRoute__12CBaseMonster(param_1), iVar4 == 0)))) {
    (*DAT_0019f794)(2,"Tried to move with no route!\n");
LAB_000bd906:
    SetConditions__12CBaseMonsteri(param_1,0x40000000);
  }
  else {
    fVar2 = *gpGlobals;
    fVar5 = (float)param_1[0x159];
    if ((byte)(fVar2 < fVar5 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar5)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar5) << 0xe) >> 8)) == 1) {
      return;
    }
    local_60 = 0;
    pfVar1 = (float *)(param_1 + param_1[0x183] * 4 + 0x162);
    iVar4 = *param_1;
    local_28 = *pfVar1 - *(float *)(iVar4 + 8);
    local_24 = pfVar1[1] - *(float *)(iVar4 + 0xc);
    local_2c = pfVar1[2] - *(float *)(iVar4 + 0x10);
    local_20 = SQRT(local_2c * local_2c + local_24 * local_24 + local_28 * local_28);
    if ((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_28 = 0.0;
      local_24 = 0.0;
      local_20 = 1.0;
    }
    else {
      local_20 = 1.0 / local_20;
      local_28 = local_28 * local_20;
      local_24 = local_24 * local_20;
      local_20 = local_20 * local_2c;
    }
    local_10 = local_28;
    local_c = local_24;
    local_8 = local_20;
    pfVar1 = (float *)(param_1 + param_1[0x183] * 4 + 0x162);
    fVar2 = *pfVar1 - *(float *)(*param_1 + 8);
    fVar5 = pfVar1[1] - *(float *)(*param_1 + 0xc);
    fVar2 = SQRT(fVar5 * fVar5 + fVar2 * fVar2);
    local_38 = *pfVar1;
    local_34 = pfVar1[1];
    local_30 = pfVar1[2];
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_38);
    _local_3c = CONCAT22(uStack_3a,in_FPUControlWord);
    local_44 = CONCAT22(uStack_3a,CONCAT11(0xc,(char)in_FPUControlWord));
    (**(code **)(param_1[0x115] + 0x118))(param_1,(int)ROUND(*(float *)(*param_1 + 0xb0)));
    local_5c = fVar2;
    if ((byte)(fVar2 < 200.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 200.0) << 0xe) >> 8)) != 1) {
      local_5c = 200.0;
    }
    if ((param_1[param_1[0x183] * 4 + 0x165] & 0xfffffe7fU) == 2) {
      piVar6 = param_1 + 0x13f;
LAB_000bd657:
      local_60 = __opP11CBaseEntity__7EHANDLE(piVar6);
    }
    else if ((param_1[param_1[0x183] * 4 + 0x165] & 0xfffffe7fU) == 1) {
      piVar6 = param_1 + 0x141;
      goto LAB_000bd657;
    }
    local_2c = local_5c * local_10;
    local_28 = local_5c * local_c;
    local_24 = local_5c * local_8;
    afStack_58[0] = 0.0;
    local_38 = local_2c + *(float *)(*param_1 + 8);
    iVar4 = *param_1;
    local_34 = local_28 + *(float *)(iVar4 + 0xc);
    local_30 = local_24 + *(float *)(iVar4 + 0x10);
    iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,iVar4 + 8,&local_38,local_60,afStack_58);
    if (iVar4 != 2) {
      (**(code **)(param_1[0x115] + 0x154))(param_1);
      fVar5 = gpGlobals[0x1d];
      if ((fVar5 == 0.0) && (fVar5 = (float)(*DAT_0019f7b4)(0), fVar5 == 0.0)) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = *(int **)((int)fVar5 + 0x7c);
      }
      if ((((piVar6 == (int *)0x0) ||
           (DispatchBlocked__FP7edict_sT0
                      (*(undefined4 *)(*param_1 + 0x208),*(undefined4 *)(*piVar6 + 0x208)),
           (float)param_1[0x184] <= 0.0)) ||
          (iVar4 = (**(code **)(piVar6[0x115] + 0x6c))(piVar6), iVar4 == 0)) ||
         (((*(byte *)(*piVar6 + 0x1a4) & 8) != 0 || (*gpGlobals - (float)param_1[0x159] <= 3.0)))) {
        iVar4 = (**(code **)(param_1[0x115] + 0x1a4))
                          (param_1,*param_1 + 8,param_1 + param_1[0x183] * 4 + 0x162,afStack_58[0],
                           local_60,&iStack_1c);
        if (iVar4 == 0) {
          (**(code **)(param_1[0x115] + 0x154))(param_1);
          if (((float)param_1[0x184] <= 0.0) || ((*(byte *)(param_1 + 399) & 0x20) != 0)) {
            SetConditions__12CBaseMonsteri(param_1,0x40000000);
            (*DAT_0019f794)(2,"%s Failed to move (%d)!\n",*(int *)*param_1 + (int)gpGlobals[0x26],
                            (*(byte *)(param_1 + 399) & 0x20) != 0);
            return;
          }
          FRefreshRoute__12CBaseMonster(param_1);
          if ((param_1[param_1[0x183] * 4 + 0x165] != 0) && (param_1[0x182] != 0)) {
            fVar2 = *gpGlobals - (float)param_1[0x159];
            if (0x3f < (byte)((0.2 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == 0.2) << 0xe) >> 8)) - 1)) {
              *(byte *)(param_1 + 399) = *(byte *)(param_1 + 399) | 0x20;
            }
            param_1[0x159] = (int)(*gpGlobals + 0.1);
            return;
          }
          goto LAB_000bd906;
        }
        iStack_50 = iStack_1c;
        iStack_4c = iStack_18;
        iStack_48 = iStack_14;
        iStack_70 = 7;
        uVar3 = param_1[param_1[0x183] * 4 + 0x165];
        do {
          param_1[iStack_70 * 4 + 0x162] = param_1[iStack_70 * 4 + 0x15e];
          param_1[iStack_70 * 4 + 0x163] = param_1[iStack_70 * 4 + 0x15f];
          param_1[iStack_70 * 4 + 0x164] = param_1[iStack_70 * 4 + 0x160];
          param_1[iStack_70 * 4 + 0x165] = param_1[iStack_70 * 4 + 0x161];
          iStack_70 = iStack_70 + -1;
        } while (0 < iStack_70);
        iVar4 = param_1[0x183];
        param_1[iVar4 * 4 + 0x162] = iStack_1c;
        param_1[iVar4 * 4 + 0x163] = iStack_18;
        param_1[iVar4 * 4 + 0x164] = iStack_14;
        param_1[param_1[0x183] * 4 + 0x165] = uVar3 & 0xfffffe7f | 8;
        RouteSimplify__12CBaseMonsterP11CBaseEntity(param_1,local_60);
      }
      else {
        fVar5 = (float)param_1[0x119];
        if (0x3f < (byte)((fVar5 < afStack_58[0] |
                           (byte)((ushort)((ushort)(NAN(fVar5) || NAN(afStack_58[0])) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar5 == afStack_58[0]) << 0xe) >> 8)) - 1)) {
          param_1[0x159] = (int)(*gpGlobals + (float)param_1[0x184]);
          return;
        }
      }
    }
    iVar4 = (**(code **)(param_1[0x115] + 0x14c))(param_1,fVar2);
    if (iVar4 != 0) {
      AdvanceRoute__12CBaseMonsterf(param_1,fVar2);
    }
    if ((float)param_1[0x159] <= *gpGlobals) {
      fVar2 = (float)param_1[0x119] * param_2;
      if (0x3f < (byte)((fVar2 < local_5c |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_5c)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == local_5c) << 0xe) >> 8)) - 1)) {
        param_2 = local_5c / (float)param_1[0x119];
      }
      (**(code **)(param_1[0x115] + 0x148))(param_1,local_60,&local_10,param_2);
      if (param_1[0x182] == 0) {
        (**(code **)(param_1[0x115] + 0x154))(param_1);
        RouteNew__12CBaseMonster(param_1);
        param_1[0x182] = 0;
        param_1[0x188] = 1;
        *(byte *)(param_1 + 399) = *(byte *)(param_1 + 399) & 0xdf;
      }
    }
    else {
      (**(code **)(param_1[0x115] + 0x154))(param_1);
    }
  }
  return;
}


// Move__14CTriggerCamera  @ 00117648
void Move__14CTriggerCamera(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  longdouble lVar5;
  int iVar6;
  undefined4 uVar7;
  float fVar8;
  float local_20;
  float local_1c;
  float local_18;
  
  if ((int *)param_1[0x11c] != (int *)0x0) {
    fVar8 = (float)param_1[0x121] - *(float *)(*param_1 + 0x1f8) * gpGlobals[1];
    param_1[0x121] = (int)fVar8;
    if (fVar8 <= 0.0) {
      iVar6 = *(int *)param_1[0x11c];
      if (*(int *)(iVar6 + 0x1d4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(iVar6 + 0x1d4) + (int)gpGlobals[0x26],param_1,param_1,3,0);
        if ((*(byte *)(*(int *)param_1[0x11c] + 0x1a0) & 4) != 0) {
          *(undefined4 *)(*(int *)param_1[0x11c] + 0x1d4) = 0;
        }
      }
      piVar4 = (int *)(**(code **)(*(int *)(param_1[0x11c] + 0x454) + 0xac))(param_1[0x11c]);
      param_1[0x11c] = (int)piVar4;
      if (piVar4 == (int *)0x0) {
        iVar6 = *param_1;
        *(undefined4 *)(iVar6 + 0x20) = g_vecZero;
        *(undefined4 *)(iVar6 + 0x24) = DAT_0019f664;
        *(undefined4 *)(iVar6 + 0x28) = DAT_0019f668;
      }
      else {
        fVar8 = *(float *)(*piVar4 + 0x1f8);
        if ((byte)(fVar8 < 0.0 | (byte)((ushort)((ushort)NAN(fVar8) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar8 == 0.0) << 0xe) >> 8)) != 0x40) {
          param_1[0x122] = (int)fVar8;
        }
        iVar6 = *(int *)param_1[0x11c];
        iVar1 = *param_1;
        local_20 = *(float *)(iVar6 + 8) - *(float *)(iVar1 + 8);
        local_1c = *(float *)(iVar6 + 0xc) - *(float *)(iVar1 + 0xc);
        local_18 = *(float *)(iVar6 + 0x10) - *(float *)(iVar1 + 0x10);
        fVar8 = local_18 * local_18 + local_1c * local_1c + local_20 * local_20;
        param_1[0x121] = (int)SQRT(fVar8);
        fVar8 = SQRT(fVar8);
        if ((byte)((byte)((ushort)((ushort)NAN(fVar8) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar8 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_20 = 0.0;
          local_1c = 0.0;
          local_18 = 1.0;
        }
        else {
          fVar8 = 1.0 / fVar8;
          local_20 = local_20 * fVar8;
          local_1c = local_1c * fVar8;
          local_18 = local_18 * fVar8;
        }
        *(float *)(iVar1 + 0x44) = local_20;
        *(float *)(iVar1 + 0x48) = local_1c;
        *(float *)(iVar1 + 0x4c) = local_18;
        lVar5 = (longdouble)(**(code **)(*(int *)(param_1[0x11c] + 0x454) + 0x68))(param_1[0x11c]);
        param_1[0x120] = (int)(float)(lVar5 + (longdouble)*gpGlobals);
      }
    }
    if ((float)param_1[0x120] <= *gpGlobals) {
      fVar8 = (float)param_1[0x124] * gpGlobals[1];
      uVar7 = *(undefined4 *)(*param_1 + 0x1f8);
      iVar6 = param_1[0x122];
    }
    else {
      fVar8 = (float)param_1[0x125] * gpGlobals[1];
      uVar7 = *(undefined4 *)(*param_1 + 0x1f8);
      iVar6 = 0;
    }
    lVar5 = (longdouble)UTIL_Approach__Ffff(iVar6,uVar7,fVar8);
    *(float *)(*param_1 + 0x1f8) = (float)lVar5;
    fVar2 = gpGlobals[1] + gpGlobals[1];
    fVar3 = 1.0 - fVar2;
    iVar6 = *param_1;
    fVar8 = *(float *)(iVar6 + 0x1f8);
    *(float *)(iVar6 + 0x20) =
         *(float *)(iVar6 + 0x44) * fVar8 * fVar2 + *(float *)(iVar6 + 0x20) * fVar3;
    *(float *)(iVar6 + 0x24) =
         *(float *)(iVar6 + 0x48) * fVar8 * fVar2 + *(float *)(iVar6 + 0x24) * fVar3;
    *(float *)(iVar6 + 0x28) =
         fVar8 * *(float *)(iVar6 + 0x4c) * fVar2 + fVar3 * *(float *)(iVar6 + 0x28);
  }
  return;
}


// Move__9CPushableP11CBaseEntityi  @ 000a9210
void Move__9CPushableP11CBaseEntityi(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  iVar5 = *param_2;
  bVar4 = false;
  uVar2 = *(uint *)(iVar5 + 0x1a4);
  if ((((uVar2 & 0x200) == 0) || (*(int *)(iVar5 + 0x19c) == 0)) ||
     (iVar3 = *param_1, *(int *)(iVar5 + 0x19c) + 0x80 != iVar3)) {
    if ((uVar2 & 8) != 0) {
      if ((param_3 != 0) && ((*(byte *)(iVar5 + 0x180) & 0x28) == 0)) {
        return;
      }
      bVar4 = true;
    }
    iVar3 = *param_1;
    if (bVar4) {
      if ((uVar2 & 0x200) == 0) {
        if (*(int *)(iVar3 + 0x1c0) < 1) {
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
    *(float *)(iVar3 + 0x20) = *(float *)(iVar5 + 0x20) * fVar1 + *(float *)(iVar3 + 0x20);
    *(float *)(*param_1 + 0x24) = *(float *)(iVar5 + 0x24) * fVar1 + *(float *)(*param_1 + 0x24);
    iVar3 = *param_1;
    fVar1 = SQRT(*(float *)(iVar3 + 0x24) * *(float *)(iVar3 + 0x24) +
                 *(float *)(iVar3 + 0x20) * *(float *)(iVar3 + 0x20));
    if ((param_3 != 0) && ((float)param_1[0x11f] < fVar1)) {
      *(float *)(iVar3 + 0x20) = ((float)param_1[0x11f] * *(float *)(iVar3 + 0x20)) / fVar1;
      *(float *)(*param_1 + 0x24) = (*(float *)(*param_1 + 0x24) * (float)param_1[0x11f]) / fVar1;
    }
    if (bVar4) {
      *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(*param_1 + 0x20);
      *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(*param_1 + 0x24);
      if (0.7 < *gpGlobals - (float)param_1[0x120]) {
        param_1[0x120] = (int)*gpGlobals;
        if ((fVar1 <= 0.0) || ((*(byte *)(*param_1 + 0x1a5) & 2) == 0)) {
          uVar6 = *(undefined4 *)(*param_1 + 0x208);
          puVar7 = (&_9CPushable_m_soundNames)[param_1[0x11e]];
          uVar10 = 0x20;
          uVar9 = 0;
          uVar8 = 0;
        }
        else {
          iVar5 = (*DAT_0019f808)(0,2);
          param_1[0x11e] = iVar5;
          uVar6 = *(undefined4 *)(*param_1 + 0x208);
          puVar7 = (&_9CPushable_m_soundNames)[iVar5];
          uVar10 = 0;
          uVar9 = 0x3f4ccccd;
          uVar8 = 0x3f000000;
        }
        EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar6,1,puVar7,uVar8,uVar9,uVar10,100);
      }
    }
  }
  else if (0 < *(int *)(iVar3 + 0x1c0)) {
    *(float *)(iVar3 + 0x28) = *(float *)(iVar5 + 0x28) * 0.1 + *(float *)(iVar3 + 0x28);
  }
  return;
}


