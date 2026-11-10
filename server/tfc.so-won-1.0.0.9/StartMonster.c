// StartMonster__12CBaseMonster  @ 000c43d0
void StartMonster__12CBaseMonster(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1c);
  if (iVar1 != -1) {
    *(byte *)((int)param_1 + 0x5c9) = *(byte *)((int)param_1 + 0x5c9) | 8;
  }
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1d);
  if (iVar1 != -1) {
    *(byte *)((int)param_1 + 0x5c9) = *(byte *)((int)param_1 + 0x5c9) | 0x10;
  }
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1e);
  if (iVar1 != -1) {
    *(byte *)((int)param_1 + 0x5c9) = *(byte *)((int)param_1 + 0x5c9) | 0x20;
  }
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1f);
  if (iVar1 != -1) {
    *(byte *)((int)param_1 + 0x5c9) = *(byte *)((int)param_1 + 0x5c9) | 0x40;
  }
  iVar1 = *param_1;
  if ((*(int *)(iVar1 + 0xe8) == 5) || (*(int *)(iVar1 + 0x180) < 0)) {
    *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
  }
  else {
    *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 1.0;
    (*DAT_00175528)(*(undefined4 *)(*param_1 + 0x1e8));
    iVar1 = (*DAT_0017552c)(*(undefined4 *)(*param_1 + 0x1e8),0,0,0);
    if (iVar1 == 0) {
      (*DAT_001755b4)(4,"Monster %s stuck in wall--level design error",
                      *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      *(undefined4 *)(*param_1 + 0xf8) = 1;
    }
  }
  if (*(int *)(*param_1 + 0x1a8) == 0) goto LAB_000c45eb;
  iVar1 = (*DAT_001754f8)(0,"targetname",*(int *)(gpGlobals + 0x98) + *(int *)(*param_1 + 0x1a8));
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 != 0) goto LAB_000c44fc;
    iVar1 = 0;
  }
  else {
LAB_000c44fc:
    iVar1 = *(int *)(iVar1 + 0xd8);
  }
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    (*DAT_001755b4)(4,"ReadyMonster()--%s couldn\'t find target %s",
                    *(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                    ((int *)*param_1)[0x6a] + *(int *)(gpGlobals + 0x98));
  }
  else {
    iVar1 = *(int *)param_1[1];
    local_10 = *(undefined4 *)(iVar1 + 8);
    local_c = *(undefined4 *)(iVar1 + 0xc);
    local_8 = *(undefined4 *)(iVar1 + 0x10);
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_10);
    param_1[0x15f] = 0x10;
    if (*(int *)(*param_1 + 0xe8) == 5) {
      param_1[0x165] = 5;
    }
    else {
      param_1[0x165] = 3;
    }
    iVar1 = FRefreshRoute__12CBaseMonster(param_1);
    if (iVar1 == 0) {
      (*DAT_001755b4)(2,"Can\'t Create Route!\n");
    }
    SetState__12CBaseMonster12MONSTERSTATE(param_1,1);
    uVar2 = (**(code **)(param_1[0xf2] + 0x16c))(param_1,2);
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,uVar2);
  }
LAB_000c45eb:
  param_1[3] = -0x10000;
  param_1[4] = (int)CallMonsterThink__12CBaseMonster;
  lVar3 = (longdouble)(*DAT_0017562c)(0x3dcccccd,0x3ecccccd);
  *(float *)(*param_1 + 0xe4) = (float)(lVar3 + (longdouble)*(float *)(*param_1 + 0xe4));
  if (*(int *)(*param_1 + 0x1ac) != 0) {
    SetState__12CBaseMonster12MONSTERSTATE(param_1,1);
    (**(code **)(param_1[0xf2] + 400))(param_1,1);
    uVar2 = (**(code **)(param_1[0xf2] + 0x16c))(param_1,0x22);
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,uVar2);
  }
  return;
}


// StartMonster__13CSquadMonster  @ 000efb60
void StartMonster__13CSquadMonster(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  StartMonster__12CBaseMonster(param_1);
  if ((*(byte *)(param_1 + 0x172) & 8) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x184);
    if ((iVar1 == 0) &&
       ((*(int *)(*param_1 + 0x1b0) == 0 || ((*(byte *)(*param_1 + 0x180) & 0x20) != 0)))) {
      iVar1 = SquadRecruit__13CSquadMonsterii(param_1,0x400,4);
      if (iVar1 != 0) {
        (*DAT_001755b4)(2,"Squad of %d %s formed\n",iVar1,
                        *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      }
      piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x184);
      if (piVar2 == param_1) {
        iVar1 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"monster_human_grunt"
                      );
        if (iVar1 == 0) {
          SetBodygroup__14CBaseAnimatingii(param_1,1,1);
          *(undefined4 *)(*param_1 + 0xf0) = 0;
        }
      }
    }
  }
  return;
}


