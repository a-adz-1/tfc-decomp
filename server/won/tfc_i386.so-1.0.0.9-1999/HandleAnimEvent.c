// HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t  @ 000c5790
void HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = *param_2;
  if (iVar1 != 0x3ed) {
    if (iVar1 < 0x3ee) {
      if (iVar1 == 0x3ea) {
        if (param_1[0x183] == 0) {
          return;
        }
        uVar4 = 1;
      }
      else {
        if (0x3ea < iVar1) {
          if (iVar1 == 0x3eb) {
            FireTargets__FPCcP11CBaseEntityT18USE_TYPEf(param_2[1],param_1,param_1,3,0);
            return;
          }
          if (iVar1 != 0x3ec) {
            FUN_000c5aa0();
            return;
          }
          uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
          iVar1 = param_2[1];
          uVar2 = 4;
          goto LAB_000c58fc;
        }
        if (iVar1 == 1000) {
          if (param_1[0x13a] != 6) {
            return;
          }
          *(undefined4 *)(*param_1 + 0x150) = 1;
          *(undefined4 *)(*param_1 + 0x140) = 0;
          return;
        }
        if (iVar1 != 0x3e9) {
          FUN_000c5aa0();
          return;
        }
        if (param_1[0x183] == 0) {
          return;
        }
        uVar4 = 0;
      }
      AllowInterrupt__12CCineMonsteri(param_1[0x183],uVar4);
      return;
    }
    if (iVar1 == 0x3f2) {
      if (param_1[0x13a] != 6) {
        return;
      }
      *(undefined4 *)(*param_1 + 0x150) = 0;
      *(undefined4 *)(*param_1 + 0x140) = *(undefined4 *)(*param_1 + 400);
      return;
    }
    if (0x3f2 < iVar1) {
      if (iVar1 == 0x7d2) {
        if ((*(byte *)(*param_1 + 0x185) & 2) == 0) {
          return;
        }
        iVar1 = (*DAT_00175628)(0,1);
        if (iVar1 == 0) {
          pcVar3 = "common/bodydrop3.wav";
        }
        else {
          pcVar3 = "common/bodydrop4.wav";
        }
        uVar2 = 0x5a;
        uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
      }
      else {
        if (iVar1 < 0x7d3) {
          if (iVar1 != 0x7d1) {
            FUN_000c5aa0();
            return;
          }
          if ((*(byte *)(*param_1 + 0x185) & 2) == 0) {
            return;
          }
          iVar1 = (*DAT_00175628)(0,1);
          if (iVar1 == 0) {
            uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
            pcVar3 = "common/bodydrop3.wav";
          }
          else {
            uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
            pcVar3 = "common/bodydrop4.wav";
          }
        }
        else {
          if (iVar1 != 0x7da) {
            FUN_000c5aa0();
            return;
          }
          uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
          pcVar3 = "zombie/claw_miss2.wav";
        }
        uVar2 = 100;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar4,4,pcVar3,0x3f800000,0x3f4ccccd,0,uVar2);
      return;
    }
    if (iVar1 == 0x3f0) {
      uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
      iVar1 = param_2[1];
      uVar2 = 2;
LAB_000c58fc:
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar4,uVar2,iVar1,0x3f800000,0x40000000,0,100);
      return;
    }
    if (iVar1 != 0x3f1) {
      FUN_000c5aa0();
      return;
    }
    iVar1 = (*DAT_00175628)(0,2);
    if (iVar1 == 0) {
      return;
    }
  }
  SENTENCEG_PlayRndSz__FP7edict_sPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),param_2[1],0x3f800000,0x40000000,0,100);
  return;
}


// HandleAnimEvent__12CTalkMonsterP14MonsterEvent_t  @ 000f1ea0
void HandleAnimEvent__12CTalkMonsterP14MonsterEvent_t(int param_1,int *param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (*param_2 != 0x3ed) {
    if (*param_2 != 0x3f1) {
      HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(param_1,param_2);
      return;
    }
    iVar1 = (*DAT_00175628)(0,99);
    if (iVar1 < 0x4b) {
      return;
    }
  }
  ShutUpFriends__12CTalkMonster(param_1);
  iVar1 = *(int *)(param_1 + 0x3c8);
  lVar2 = (longdouble)(*DAT_0017562c)(0x40333333,0x4059999a,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x180))(param_1,param_2[1],(float)lVar2);
  return;
}


// HandleAnimEvent__14CBaseAnimatingP14MonsterEvent_t  @ 000c8990
void HandleAnimEvent__14CBaseAnimatingP14MonsterEvent_t(void)

{
  return;
}


// HandleAnimEvent__15CGenericMonsterP14MonsterEvent_t  @ 000b8a50
void HandleAnimEvent__15CGenericMonsterP14MonsterEvent_t(undefined4 param_1,undefined4 param_2)

{
  HandleAnimEvent__12CBaseMonsterP14MonsterEvent_t(param_1,param_2);
  return;
}


// HandleAnimEvent__8CXenTreeP14MonsterEvent_t  @ 0011ec20
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
  int local_54;
  float local_30;
  float local_2c;
  float local_28;
  int local_24 [8];
  
  if (*param_2 == 1) {
    bVar6 = false;
    iVar7 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i
                      (local_24,8,*(int *)param_1[0xfb] + 0xa4,*(int *)param_1[0xfb] + 0xb0,0x28);
    (*DAT_00175510)(*param_1 + 0x50,&local_30,0,0);
    local_54 = 0;
    if (0 < iVar7) {
      do {
        if ((int *)local_24[local_54] != param_1) {
          piVar3 = (int *)local_24[local_54];
          iVar4 = *param_1;
          if (*(int *)(*piVar3 + 0x178) != *(int *)(iVar4 + 0x1e8)) {
            bVar6 = true;
            (**(code **)(piVar3[0xf2] + 0x34))(piVar3,iVar4,iVar4,0x41c80000,5);
            *(undefined4 *)(*(int *)local_24[local_54] + 0x68) = 0x41700000;
            iVar4 = *(int *)local_24[local_54];
            iVar5 = *(int *)local_24[local_54];
            fVar1 = *(float *)(iVar5 + 0x24);
            fVar2 = *(float *)(iVar5 + 0x28);
            *(float *)(iVar4 + 0x20) = *(float *)(iVar5 + 0x20) + local_30 * 100.0;
            *(float *)(iVar4 + 0x24) = fVar1 + local_2c * 100.0;
            *(float *)(iVar4 + 0x28) = fVar2 + local_28 * 100.0;
          }
        }
        local_54 = local_54 + 1;
      } while (local_54 < iVar7);
    }
    if (bVar6) {
      uVar8 = (*DAT_00175628)(0x5f,0x69);
      iVar7 = (*DAT_00175628)(0,2,0x3f800000,0x3f4ccccd,0,uVar8);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),1,(&_8CXenTree_pAttackHitSounds)[iVar7]);
    }
  }
  return;
}


