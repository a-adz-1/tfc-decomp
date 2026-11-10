// GetIdealState__12CBaseMonster  @ 000c3520
undefined4 GetIdealState__12CBaseMonster(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar1 = IScheduleFlags__12CBaseMonster(param_1);
  switch(*(undefined4 *)(param_1 + 0x574)) {
  case 1:
    if ((uVar1 & 0x10000) != 0) {
LAB_000c3643:
      *(undefined4 *)(param_1 + 0x578) = 2;
      uVar4 = switchD_000c355a::caseD_4();
      return uVar4;
    }
    if (((uVar1 & 0x100) != 0) || ((uVar1 & 0x200) != 0)) {
      uStack_10 = *(undefined4 *)(param_1 + 0x644);
      uStack_c = *(undefined4 *)(param_1 + 0x648);
      uStack_8 = *(undefined4 *)(param_1 + 0x64c);
      MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&uStack_10);
      *(undefined4 *)(param_1 + 0x578) = 3;
      uVar4 = switchD_000c355a::caseD_4();
      return uVar4;
    }
    if ((uVar1 & 0x20000) == 0) {
      if ((uVar1 & 0x40040) != 0) {
        *(undefined4 *)(param_1 + 0x578) = 3;
        uVar4 = switchD_000c355a::caseD_4();
        return uVar4;
      }
    }
    else {
      puVar2 = (undefined4 *)(**(code **)(*(int *)(param_1 + 0x454) + 0x1d4))(param_1);
      if (puVar2 != (undefined4 *)0x0) {
        uStack_10 = *puVar2;
        uStack_c = puVar2[1];
        uStack_8 = puVar2[2];
        MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&uStack_10);
        if ((*(byte *)(puVar2 + 3) & 0x21) != 0) {
          *(undefined4 *)(param_1 + 0x578) = 3;
          uVar4 = switchD_000c355a::caseD_4();
          return uVar4;
        }
      }
    }
    break;
  case 2:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x578) = 3;
      (*DAT_0019f794)(2,"***Combat state with no enemy!\n");
      uVar4 = switchD_000c355a::caseD_4();
      return uVar4;
    }
    break;
  case 3:
    if ((uVar1 & 0x10010) != 0) goto LAB_000c3643;
    if ((uVar1 & 0x20000) != 0) {
      *(undefined4 *)(param_1 + 0x578) = 3;
      puVar2 = (undefined4 *)(**(code **)(*(int *)(param_1 + 0x454) + 0x1d4))(param_1);
      if (puVar2 != (undefined4 *)0x0) {
        uStack_10 = *puVar2;
        uStack_c = puVar2[1];
        uStack_8 = puVar2[2];
        MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&uStack_10);
        uVar4 = switchD_000c355a::caseD_4();
        return uVar4;
      }
    }
    break;
  case 6:
    if ((uVar1 & 0x40000300) != 0) {
      ExitScriptedSequence__12CBaseMonster(param_1);
      uVar4 = switchD_000c355a::caseD_4();
      return uVar4;
    }
    break;
  case 8:
    *(undefined4 *)(param_1 + 0x578) = 8;
  }
  return *(undefined4 *)(param_1 + 0x578);
}


// GetIdealState__13CSquadMonster  @ 000f52c0
void GetIdealState__13CSquadMonster(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  IScheduleFlags__12CBaseMonster(param_1);
  if (((*(int *)(param_1 + 0x574) == 1) || (*(int *)(param_1 + 0x574) == 3)) &&
     ((*(byte *)(param_1 + 0x4fa) & 1) != 0)) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
    if (iVar1 != 0) {
      uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
      SquadMakeEnemy__13CSquadMonsterP11CBaseEntity(param_1,uVar2);
    }
  }
  GetIdealState__12CBaseMonster(param_1);
  return;
}


