// HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t  @ 000b3e74
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
LAB_000b3fe9:
    SENTENCEG_PlayRndSz__FP7edict_sPCcffii
              (*(undefined4 *)(*param_1 + 0x208),param_2[1],0x3f800000,0x40000000,0,100);
    return;
  }
  if (iVar1 < 0x3ee) {
    if (iVar1 == 0x3ea) {
      if (param_1[0x186] == 0) {
        return;
      }
      uVar5 = 1;
LAB_000b404f:
      AllowInterrupt__12CCineMonsteri(param_1[0x186],uVar5);
      return;
    }
    if (iVar1 < 0x3eb) {
      if (iVar1 == 1000) {
        if (param_1[0x13d] != 6) {
          return;
        }
        *(undefined4 *)(*param_1 + 0x170) = 1;
        *(undefined4 *)(*param_1 + 0x160) = 0;
        return;
      }
      if (iVar1 != 0x3e9) {
        FUN_000b413c();
        return;
      }
      if (param_1[0x186] == 0) {
        return;
      }
      uVar5 = 0;
      goto LAB_000b404f;
    }
    if (iVar1 == 0x3eb) {
      FireTargets__FPCcP11CBaseEntityT18USE_TYPEf(param_2[1],param_1,param_1,3,0);
      return;
    }
    if (iVar1 != 0x3ec) {
      FUN_000b413c();
      return;
    }
    uVar5 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = (char *)param_2[1];
    uVar4 = 0x40000000;
LAB_000b4127:
    uVar3 = 4;
  }
  else {
    if (iVar1 == 0x3f2) {
      if (param_1[0x13d] != 6) {
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
        iVar1 = (*DAT_001a7fa8)(0,1);
        if (iVar1 == 0) {
          pcVar2 = "common/bodydrop3.wav";
        }
        else {
          pcVar2 = "common/bodydrop4.wav";
        }
        uVar6 = 0x5a;
        uVar4 = 0x3f4ccccd;
        uVar3 = 4;
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        goto LAB_000b4130;
      }
      if (iVar1 < 0x7d3) {
        if (iVar1 != 0x7d1) {
          FUN_000b413c();
          return;
        }
        if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
          return;
        }
        iVar1 = (*DAT_001a7fa8)(0,1);
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
          FUN_000b413c();
          return;
        }
        uVar5 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "zombie/claw_miss2.wav";
      }
      uVar4 = 0x3f4ccccd;
      goto LAB_000b4127;
    }
    if (iVar1 != 0x3f0) {
      if (iVar1 != 0x3f1) {
        FUN_000b413c();
        return;
      }
      iVar1 = (*DAT_001a7fa8)(0,2);
      if (iVar1 == 0) {
        return;
      }
      goto LAB_000b3fe9;
    }
    uVar5 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = (char *)param_2[1];
    uVar4 = 0x40000000;
    uVar3 = 2;
  }
  uVar6 = 100;
LAB_000b4130:
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,uVar3,pcVar2,0x3f800000,uVar4,0,uVar6);
  return;
}


// HandleAnimEvent__12CTalkMonsterP14MonsterEvent_t  @ 000e89c0
void HandleAnimEvent__12CTalkMonsterP14MonsterEvent_t(int param_1,int *param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (*param_2 != 0x3ed) {
    if (*param_2 != 0x3f1) {
      HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(param_1,param_2);
      return;
    }
    iVar1 = (*DAT_001a7fa8)(0,99);
    if (iVar1 < 0x4b) {
      return;
    }
  }
  ShutUpFriends__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_1 + 0x3d4);
  lVar2 = (longdouble)(*DAT_001a7fac)(0x40333333,0x4059999a,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x180))(param_1,param_2[1],(float)lVar2);
  return;
}


// HandleAnimEvent__14CBaseAnimatingP14MonsterEvent_t  @ 000b7774
void HandleAnimEvent__14CBaseAnimatingP14MonsterEvent_t(void)

{
  return;
}


// HandleAnimEvent__15CGenericMonsterP14MonsterEvent_t  @ 000a5d50
void HandleAnimEvent__15CGenericMonsterP14MonsterEvent_t(undefined4 param_1,undefined4 param_2)

{
  HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(param_1,param_2);
  return;
}


// HandleAnimEvent__8CXenTreeP14MonsterEvent_t  @ 00114fcc
void HandleAnimEvent__8CXenTreeP14MonsterEvent_t(void)

{
  FUN_00114fd8();
  return;
}


