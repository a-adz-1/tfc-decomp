// HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t  @ 000bf0d4
void HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(int *param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar1 = *param_2;
  if (iVar1 == 0x3ed) {
LAB_000bf249:
    SENTENCEG_PlayRndSz__FP7edict_sPCcffii
              (*(undefined4 *)(*param_1 + 0x208),param_2[1],0x3f800000,0x40000000,0,100);
    return;
  }
  if (iVar1 < 0x3ee) {
    if (iVar1 == 0x3ea) {
      if (param_1[0x1a2] == 0) {
        return;
      }
      uVar5 = 1;
LAB_000bf2af:
      AllowInterrupt__12CCineMonsteri(param_1[0x1a2],uVar5);
      return;
    }
    if (iVar1 < 0x3eb) {
      if (iVar1 == 1000) {
        if (param_1[0x159] != 6) {
          return;
        }
        *(undefined4 *)(*param_1 + 0x170) = 1;
        *(undefined4 *)(*param_1 + 0x160) = 0;
        return;
      }
      if (iVar1 != 0x3e9) {
        FUN_000bf39c();
        return;
      }
      if (param_1[0x1a2] == 0) {
        return;
      }
      uVar5 = 0;
      goto LAB_000bf2af;
    }
    if (iVar1 == 0x3eb) {
      FireTargets__FPCcP11CBaseEntityT18USE_TYPEf(param_2[1],param_1,param_1,3,0);
      return;
    }
    if (iVar1 != 0x3ec) {
      FUN_000bf39c();
      return;
    }
    uVar5 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = (char *)param_2[1];
    uVar4 = 0x40000000;
LAB_000bf387:
    uVar3 = 4;
  }
  else {
    if (iVar1 == 0x3f2) {
      if (param_1[0x159] != 6) {
        return;
      }
      *(undefined4 *)(*param_1 + 0x170) = 0;
      *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
      return;
    }
    if (0x3f2 < iVar1) {
      if (iVar1 == 0x7d2) {
        if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
          return;
        }
        iVar1 = (*DAT_001c1188)(0,1);
        if (iVar1 == 0) {
          FUN_000bf318(0x3f4ccccd,0,0x5a);
          return;
        }
        uVar6 = 0x5a;
        uVar4 = 0x3f4ccccd;
        pcVar2 = "common/bodydrop4.wav";
        uVar3 = 4;
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        goto LAB_000bf390;
      }
      if (iVar1 < 0x7d3) {
        if (iVar1 != 0x7d1) {
          FUN_000bf39c();
          return;
        }
        if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
          return;
        }
        iVar1 = (*DAT_001c1188)(0,1);
        if (iVar1 == 0) {
          uVar5 = *(undefined4 *)(*param_1 + 0x208);
          pcVar2 = "common/bodydrop3.wav";
        }
        else {
          uVar5 = *(undefined4 *)(*param_1 + 0x208);
          pcVar2 = "common/bodydrop4.wav";
        }
      }
      else {
        if (iVar1 != 0x7da) {
          FUN_000bf39c();
          return;
        }
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "zombie/claw_miss2.wav";
      }
      uVar4 = 0x3f4ccccd;
      goto LAB_000bf387;
    }
    if (iVar1 != 0x3f0) {
      if (iVar1 != 0x3f1) {
        FUN_000bf39c();
        return;
      }
      iVar1 = (*DAT_001c1188)(0,2);
      if (iVar1 == 0) {
        return;
      }
      goto LAB_000bf249;
    }
    uVar5 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = (char *)param_2[1];
    uVar4 = 0x40000000;
    uVar3 = 2;
  }
  uVar6 = 100;
LAB_000bf390:
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,uVar3,pcVar2,0x3f800000,uVar4,0,uVar6);
  return;
}


// HandleAnimEvent__12CTalkMonsterP14MonsterEvent_t  @ 000f569c
void HandleAnimEvent__12CTalkMonsterP14MonsterEvent_t(int param_1,int *param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (*param_2 != 0x3ed) {
    if (*param_2 != 0x3f1) {
      HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(param_1,param_2);
      return;
    }
    iVar1 = (*DAT_001c1188)(0,99);
    if (iVar1 < 0x4b) {
      return;
    }
  }
  ShutUpFriends__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_1 + 0x444);
  lVar2 = (longdouble)(*DAT_001c118c)(0x40333333,0x4059999a,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x188))(param_1,param_2[1],(float)lVar2);
  return;
}


// HandleAnimEvent__14CBaseAnimatingP14MonsterEvent_t  @ 000c29f4
void HandleAnimEvent__14CBaseAnimatingP14MonsterEvent_t(void)

{
  return;
}


// HandleAnimEvent__15CGenericMonsterP14MonsterEvent_t  @ 000b0ac0
void HandleAnimEvent__15CGenericMonsterP14MonsterEvent_t(undefined4 param_1,undefined4 param_2)

{
  HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(param_1,param_2);
  return;
}


// HandleAnimEvent__8CXenTreeP14MonsterEvent_t  @ 00124bc4
void HandleAnimEvent__8CXenTreeP14MonsterEvent_t(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int **ppiVar9;
  int local_50;
  float local_2c;
  float local_28;
  float local_24;
  int *local_20;
  int *local_1c [7];
  
  if (*param_2 == 1) {
    bVar5 = false;
    ppiVar9 = &local_20;
    uVar6 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i
                      (ppiVar9,8,*(int *)param_1[0x11a] + 0xc4,*(int *)param_1[0x11a] + 0xd0,0x28);
    (*DAT_001c1070)(*param_1 + 0x50,&local_2c,0,0);
    local_50 = 0;
    if (0 < (int)uVar6) {
      if ((uVar6 & 1) == 0) goto LAB_00124d38;
      if (local_20 != param_1) {
        iVar8 = *param_1;
        if (*(int *)(*local_20 + 0x198) != *(int *)(iVar8 + 0x208)) {
          bVar5 = true;
          (**(code **)(local_20[0x111] + 0x38))(local_20,iVar8,iVar8,0x41c80000,5);
          *(undefined4 *)(*local_20 + 0x68) = 0x41700000;
          iVar8 = *local_20;
          iVar3 = *local_20;
          fVar1 = *(float *)(iVar3 + 0x24);
          fVar2 = *(float *)(iVar3 + 0x28);
          *(float *)(iVar8 + 0x20) = *(float *)(iVar3 + 0x20) + local_2c * 100.0;
          *(float *)(iVar8 + 0x24) = fVar1 + local_28 * 100.0;
          *(float *)(iVar8 + 0x28) = fVar2 + local_24 * 100.0;
        }
      }
      ppiVar9 = local_1c;
      for (local_50 = 1; local_50 < (int)uVar6; local_50 = local_50 + 2) {
LAB_00124d38:
        if (*ppiVar9 != param_1) {
          piVar4 = *ppiVar9;
          iVar8 = *param_1;
          if (*(int *)(*piVar4 + 0x198) != *(int *)(iVar8 + 0x208)) {
            bVar5 = true;
            (**(code **)(piVar4[0x111] + 0x38))(piVar4,iVar8,iVar8,0x41c80000,5);
            *(undefined4 *)(**ppiVar9 + 0x68) = 0x41700000;
            iVar8 = **ppiVar9;
            iVar3 = **ppiVar9;
            fVar1 = *(float *)(iVar3 + 0x24);
            fVar2 = *(float *)(iVar3 + 0x28);
            *(float *)(iVar8 + 0x20) = *(float *)(iVar3 + 0x20) + local_2c * 100.0;
            *(float *)(iVar8 + 0x24) = fVar1 + local_28 * 100.0;
            *(float *)(iVar8 + 0x28) = fVar2 + local_24 * 100.0;
          }
        }
        if (ppiVar9[1] != param_1) {
          piVar4 = ppiVar9[1];
          iVar8 = *param_1;
          if (*(int *)(*piVar4 + 0x198) != *(int *)(iVar8 + 0x208)) {
            bVar5 = true;
            (**(code **)(piVar4[0x111] + 0x38))(piVar4,iVar8,iVar8,0x41c80000,5);
            *(undefined4 *)(*ppiVar9[1] + 0x68) = 0x41700000;
            iVar8 = *ppiVar9[1];
            iVar3 = *ppiVar9[1];
            fVar1 = *(float *)(iVar3 + 0x24);
            fVar2 = *(float *)(iVar3 + 0x28);
            *(float *)(iVar8 + 0x20) = *(float *)(iVar3 + 0x20) + local_2c * 100.0;
            *(float *)(iVar8 + 0x24) = fVar1 + local_28 * 100.0;
            *(float *)(iVar8 + 0x28) = fVar2 + local_24 * 100.0;
          }
        }
        ppiVar9 = ppiVar9 + 2;
      }
    }
    if (bVar5) {
      uVar7 = (*DAT_001c1188)(0x5f,0x69);
      iVar8 = (*DAT_001c1188)(0,2,0x3f800000,0x3f4ccccd,0,uVar7);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),1,(&_8CXenTree_pAttackHitSounds)[iVar8]);
    }
  }
  return;
}


