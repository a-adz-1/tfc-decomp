// GetIdealState__12CBaseMonster  @ 000c2c58
undefined4 GetIdealState__12CBaseMonster(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = IScheduleFlags__12CBaseMonster(param_1);
  switch(*(undefined4 *)(param_1 + 0x564)) {
  case 1:
    if ((uVar1 & 0x10000) == 0) {
      if (((uVar1 & 0x100) == 0) && ((uVar1 & 0x200) == 0)) {
        if ((uVar1 & 0x20000) == 0) {
          if ((uVar1 & 0x40040) != 0) {
            *(undefined4 *)(param_1 + 0x568) = 3;
          }
        }
        else {
          puVar2 = (undefined4 *)(**(code **)(*(int *)(param_1 + 0x444) + 0x1d4))(param_1);
          if (puVar2 != (undefined4 *)0x0) {
            local_c = *puVar2;
            local_8 = puVar2[1];
            local_4 = puVar2[2];
            MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_c);
            if ((*(byte *)(puVar2 + 3) & 0x21) != 0) {
              *(undefined4 *)(param_1 + 0x568) = 3;
            }
          }
        }
      }
      else {
        local_c = *(undefined4 *)(param_1 + 0x634);
        local_8 = *(undefined4 *)(param_1 + 0x638);
        local_4 = *(undefined4 *)(param_1 + 0x63c);
        MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_c);
        *(undefined4 *)(param_1 + 0x568) = 3;
      }
      break;
    }
    goto LAB_000c2d87;
  case 2:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x568) = 3;
      (*DAT_001c1114)(2,FUN_00148e80);
    }
    break;
  case 3:
    if ((uVar1 & 0x10010) == 0) {
      if ((uVar1 & 0x20000) != 0) {
        *(undefined4 *)(param_1 + 0x568) = 3;
        puVar2 = (undefined4 *)(**(code **)(*(int *)(param_1 + 0x444) + 0x1d4))(param_1);
        if (puVar2 != (undefined4 *)0x0) {
          local_c = *puVar2;
          local_8 = puVar2[1];
          local_4 = puVar2[2];
          MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_c);
        }
      }
      break;
    }
LAB_000c2d87:
    *(undefined4 *)(param_1 + 0x568) = 2;
    break;
  case 6:
    if ((uVar1 & 0x40000300) != 0) {
      ExitScriptedSequence__12CBaseMonster(param_1);
    }
    break;
  case 8:
    *(undefined4 *)(param_1 + 0x568) = 8;
  }
  return *(undefined4 *)(param_1 + 0x568);
}


// GetIdealState__13CSquadMonster  @ 000f31cc
void GetIdealState__13CSquadMonster(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  IScheduleFlags__12CBaseMonster(param_1);
  if (((*(int *)(param_1 + 0x564) == 1) || (*(int *)(param_1 + 0x564) == 3)) &&
     ((*(byte *)(param_1 + 0x4ea) & 1) != 0)) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
    if (iVar1 != 0) {
      uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
      SquadMakeEnemy__13CSquadMonsterP11CBaseEntity(param_1,uVar2);
    }
  }
  GetIdealState__12CBaseMonster(param_1);
  return;
}


