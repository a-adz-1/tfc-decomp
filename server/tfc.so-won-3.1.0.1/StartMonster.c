// StartMonster__12CBaseMonster  @ 000b26d8
void StartMonster__12CBaseMonster(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1c);
  if (iVar1 != -1) {
    *(byte *)((int)param_1 + 0x5d5) = *(byte *)((int)param_1 + 0x5d5) | 8;
  }
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1d);
  if (iVar1 != -1) {
    *(byte *)((int)param_1 + 0x5d5) = *(byte *)((int)param_1 + 0x5d5) | 0x10;
  }
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1e);
  if (iVar1 != -1) {
    *(byte *)((int)param_1 + 0x5d5) = *(byte *)((int)param_1 + 0x5d5) | 0x20;
  }
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x1f);
  if (iVar1 != -1) {
    *(byte *)((int)param_1 + 0x5d5) = *(byte *)((int)param_1 + 0x5d5) | 0x40;
  }
  iVar1 = *param_1;
  if ((*(int *)(iVar1 + 0x108) == 5) || (*(int *)(iVar1 + 0x1a0) < 0)) {
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  }
  else {
    *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 1.0;
    (*DAT_001a7ea8)(*(undefined4 *)(*param_1 + 0x208));
    iVar1 = (*DAT_001a7eac)(*(undefined4 *)(*param_1 + 0x208),0,0,0);
    if (iVar1 == 0) {
      (*DAT_001a7f34)(4,"Monster %s stuck in wall--level design error",
                      *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      *(undefined4 *)(*param_1 + 0x118) = 1;
    }
  }
  if (*(int *)(*param_1 + 0x1c8) == 0) goto LAB_000b293c;
  iVar1 = (*DAT_001a7e78)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0);
    if (iVar1 != 0) goto LAB_000b2844;
    iVar1 = 0;
  }
  else {
LAB_000b2844:
    iVar1 = *(int *)(iVar1 + 0x7c);
  }
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    (*DAT_001a7f34)(4,"ReadyMonster()--%s couldn\'t find target %s",
                    *(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                    ((int *)*param_1)[0x72] + *(int *)(gpGlobals + 0x98));
  }
  else {
    iVar1 = *(int *)param_1[1];
    uStack_c = *(undefined4 *)(iVar1 + 8);
    uStack_8 = *(undefined4 *)(iVar1 + 0xc);
    uStack_4 = *(undefined4 *)(iVar1 + 0x10);
    MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&uStack_c);
    param_1[0x162] = 0x10;
    if (*(int *)(*param_1 + 0x108) == 5) {
      param_1[0x168] = 5;
    }
    else {
      param_1[0x168] = 3;
    }
    iVar1 = FRefreshRoute__12CBaseMonster(param_1);
    if (iVar1 == 0) {
      (*DAT_001a7f34)(2,"Can\'t Create Route!\n");
    }
    SetState__12CBaseMonster12MONSTERSTATE(param_1,1);
    uVar2 = (**(code **)(param_1[0xf5] + 0x16c))(param_1,2);
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,uVar2);
  }
LAB_000b293c:
  param_1[3] = -0x10000;
  param_1[4] = (int)CallMonsterThink__12CBaseMonster;
  lVar3 = (longdouble)(*DAT_001a7fac)(0x3dcccccd,0x3ecccccd);
  *(float *)(*param_1 + 0x104) = (float)(lVar3 + (longdouble)*(float *)(*param_1 + 0x104));
  if (*(int *)(*param_1 + 0x1cc) != 0) {
    SetState__12CBaseMonster12MONSTERSTATE(param_1,1);
    (**(code **)(param_1[0xf5] + 400))(param_1,1);
    uVar2 = (**(code **)(param_1[0xf5] + 0x16c))(param_1,0x22);
    ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,uVar2);
  }
  return;
}


// StartMonster__13CSquadMonster  @ 000e6084
void StartMonster__13CSquadMonster(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  StartMonster__12CBaseMonster(param_1);
  if ((*(byte *)(param_1 + 0x175) & 8) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x187);
    if ((iVar1 == 0) &&
       ((*(int *)(*param_1 + 0x1d0) == 0 || ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0)))) {
      iVar1 = SquadRecruit__13CSquadMonsterii(param_1,0x400,4);
      if (iVar1 != 0) {
        (*DAT_001a7f34)(2,"Squad of %d %s formed\n",iVar1,
                        *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      }
      piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x187);
      if (piVar2 == param_1) {
        iVar1 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"monster_human_grunt"
                      );
        if (iVar1 == 0) {
          SetBodygroup__14CBaseAnimatingii(param_1,1,1);
          *(undefined4 *)(*param_1 + 0x110) = 0;
        }
      }
    }
  }
  return;
}


