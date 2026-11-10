// HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t  @ 000bec74
void HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(int *param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = *param_2;
  if (iVar1 == 0x3ed) {
LAB_000bee05:
    SENTENCEG_PlayRndSz__FP7edict_sPCcffii
              (*(undefined4 *)(*param_1 + 0x208),param_2[1],0x3f800000,0x40000000,0,100);
    return;
  }
  if (iVar1 < 0x3ee) {
    if (iVar1 == 0x3ea) {
      iVar1 = param_1[0x1a6];
      if (iVar1 == 0) {
        return;
      }
      uVar5 = 1;
    }
    else {
      if (0x3ea < iVar1) {
        if (iVar1 == 0x3eb) {
          FireTargets__FPCcP11CBaseEntityT18USE_TYPEf(param_2[1],param_1,param_1,3,0);
          return;
        }
        if (iVar1 != 0x3ec) {
          FUN_000bef74();
          return;
        }
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = (char *)param_2[1];
        uVar4 = 0x40000000;
        goto LAB_000bef68;
      }
      if (iVar1 == 1000) {
        if (param_1[0x15d] != 6) {
          return;
        }
        *(undefined4 *)(*param_1 + 0x170) = 1;
        *(undefined4 *)(*param_1 + 0x160) = 0;
        return;
      }
      if (iVar1 != 0x3e9) {
        FUN_000bef74();
        return;
      }
      iVar1 = param_1[0x1a6];
      if (iVar1 == 0) {
        return;
      }
      uVar5 = 0;
    }
    AllowInterrupt__12CCineMonsteri(iVar1,uVar5);
  }
  else {
    if (iVar1 == 0x3f2) {
      if (param_1[0x15d] != 6) {
        return;
      }
      *(undefined4 *)(*param_1 + 0x170) = 0;
      *(undefined4 *)(*param_1 + 0x160) = *(undefined4 *)(*param_1 + 0x1b0);
      return;
    }
    if (iVar1 < 0x3f3) {
      if (iVar1 != 0x3f0) {
        if (iVar1 != 0x3f1) {
          FUN_000bef74();
          return;
        }
        iVar1 = (*DAT_0019f808)(0,2);
        if (iVar1 == 0) {
          return;
        }
        goto LAB_000bee05;
      }
      uVar5 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = (char *)param_2[1];
      uVar4 = 0x40000000;
      uVar3 = 2;
    }
    else {
      if (iVar1 == 0x7d2) {
        if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
          return;
        }
        iVar1 = (*DAT_0019f808)(0,1);
        if (iVar1 == 0) {
          pcVar2 = "common/bodydrop3.wav";
        }
        else {
          pcVar2 = "common/bodydrop4.wav";
        }
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),4,pcVar2,0x3f800000,0x3f4ccccd,0,0x5a);
        return;
      }
      if (iVar1 < 0x7d3) {
        if (iVar1 != 0x7d1) {
          FUN_000bef74();
          return;
        }
        if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
          return;
        }
        iVar1 = (*DAT_0019f808)(0,1);
        if (iVar1 == 0) {
          uVar5 = *(undefined4 *)(*param_1 + 0x208);
          uVar4 = 0x3f4ccccd;
          pcVar2 = "common/bodydrop3.wav";
        }
        else {
          uVar5 = *(undefined4 *)(*param_1 + 0x208);
          uVar4 = 0x3f4ccccd;
          pcVar2 = "common/bodydrop4.wav";
        }
      }
      else {
        if (iVar1 != 0x7da) {
          FUN_000bef74();
          return;
        }
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        uVar4 = 0x3f4ccccd;
        pcVar2 = "zombie/claw_miss2.wav";
      }
LAB_000bef68:
      uVar3 = 4;
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,uVar3,pcVar2,0x3f800000,uVar4,0,100);
  }
  return;
}


// HandleAnimEvent__12CTalkMonsterP14MonsterEvent_t  @ 000f8f7c
void HandleAnimEvent__12CTalkMonsterP14MonsterEvent_t(int param_1,int *param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (*param_2 != 0x3ed) {
    if (*param_2 != 0x3f1) {
      HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(param_1,param_2);
      return;
    }
    iVar1 = (*DAT_0019f808)(0,99);
    if (iVar1 < 0x4b) {
      return;
    }
  }
  ShutUpFriends__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_1 + 0x454);
  lVar2 = (longdouble)(*DAT_0019f80c)(0x40333333,0x4059999a,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x188))(param_1,param_2[1],(float)lVar2);
  return;
}


// HandleAnimEvent__14CBaseAnimatingP14MonsterEvent_t  @ 000c331c
void HandleAnimEvent__14CBaseAnimatingP14MonsterEvent_t(void)

{
  return;
}


// HandleAnimEvent__15CGenericMonsterP14MonsterEvent_t  @ 000b05b8
void HandleAnimEvent__15CGenericMonsterP14MonsterEvent_t(undefined4 param_1,undefined4 param_2)

{
  HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(param_1,param_2);
  return;
}


// HandleAnimEvent__8CXenTreeP14MonsterEvent_t  @ 001289a4
void HandleAnimEvent__8CXenTreeP14MonsterEvent_t(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  int local_68;
  float local_30;
  float fStack_2c;
  float fStack_28;
  undefined4 local_24 [8];
  
  if (*param_2 == 1) {
    bVar6 = false;
    iVar7 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i
                      (local_24,8,*(int *)param_1[0x11e] + 0xc4,*(int *)param_1[0x11e] + 0xd0,0x28);
    (*DAT_0019f6f0)(*param_1 + 0x50,&local_30,0,0);
    local_68 = 0;
    if (0 < iVar7) {
      do {
        piVar3 = (int *)local_24[local_68];
        if ((piVar3 != param_1) &&
           (iVar4 = *param_1, *(int *)(*piVar3 + 0x198) != *(int *)(iVar4 + 0x208))) {
          bVar6 = true;
          (**(code **)(piVar3[0x115] + 0x38))(piVar3,iVar4,iVar4,0x41c80000,5);
          *(undefined4 *)(*(int *)local_24[local_68] + 0x68) = 0x41700000;
          piVar3 = (int *)local_24[local_68];
          iVar4 = *piVar3;
          iVar5 = *piVar3;
          fVar1 = *(float *)(iVar5 + 0x24);
          fVar2 = *(float *)(iVar5 + 0x28);
          *(float *)(iVar4 + 0x20) = local_30 * 100.0 + *(float *)(iVar5 + 0x20);
          *(float *)(iVar4 + 0x24) = fStack_2c * 100.0 + fVar1;
          *(float *)(iVar4 + 0x28) = fStack_28 * 100.0 + fVar2;
        }
        local_68 = local_68 + 1;
      } while (local_68 < iVar7);
    }
    if (bVar6) {
      uVar8 = (*DAT_0019f808)(0x5f,0x69);
      iVar7 = (*DAT_0019f808)(0,2,0x3f800000,0x3f4ccccd,0,uVar8);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),1,(&_8CXenTree_pAttackHitSounds)[iVar7]);
    }
  }
  return;
}


