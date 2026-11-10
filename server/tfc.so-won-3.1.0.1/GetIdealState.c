// GetIdealState__12CBaseMonster  @ 000b79b8
undefined4 GetIdealState__12CBaseMonster(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = IScheduleFlags__12CBaseMonster(param_1);
  switch(*(undefined4 *)(param_1 + 0x4f4)) {
  case 1:
    if ((uVar1 & 0x10000) != 0) {
LAB_000b7ae7:
      *(undefined4 *)(param_1 + 0x4f8) = 2;
      uVar4 = switchD_000b79f0::caseD_4();
      return uVar4;
    }
    if (((uVar1 & 0x100) != 0) || ((uVar1 & 0x200) != 0)) {
      local_c = *(undefined4 *)(param_1 + 0x5c4);
      local_8 = *(undefined4 *)(param_1 + 0x5c8);
      local_4 = *(undefined4 *)(param_1 + 0x5cc);
      MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_c);
      *(undefined4 *)(param_1 + 0x4f8) = 3;
      uVar4 = switchD_000b79f0::caseD_4();
      return uVar4;
    }
    if ((uVar1 & 0x20000) == 0) {
      if ((uVar1 & 0x40040) != 0) {
        *(undefined4 *)(param_1 + 0x4f8) = 3;
        uVar4 = switchD_000b79f0::caseD_4();
        return uVar4;
      }
    }
    else {
      puVar2 = (undefined4 *)(**(code **)(*(int *)(param_1 + 0x3d4) + 0x1cc))(param_1);
      if (puVar2 != (undefined4 *)0x0) {
        local_c = *puVar2;
        local_8 = puVar2[1];
        local_4 = puVar2[2];
        MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_c);
        if ((*(byte *)(puVar2 + 3) & 0x21) != 0) {
          *(undefined4 *)(param_1 + 0x4f8) = 3;
          uVar4 = switchD_000b79f0::caseD_4();
          return uVar4;
        }
      }
    }
    break;
  case 2:
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x4f8) = 3;
      (*DAT_001a7f34)(2,FUN_00138540);
    }
    break;
  case 3:
    if ((uVar1 & 0x10010) != 0) goto LAB_000b7ae7;
    if ((uVar1 & 0x20000) != 0) {
      *(undefined4 *)(param_1 + 0x4f8) = 3;
      puVar2 = (undefined4 *)(**(code **)(*(int *)(param_1 + 0x3d4) + 0x1cc))(param_1);
      if (puVar2 != (undefined4 *)0x0) {
        local_c = *puVar2;
        local_8 = puVar2[1];
        local_4 = puVar2[2];
        MakeIdealYaw__12CBaseMonsterG6Vector(param_1,&local_c);
        uVar4 = switchD_000b79f0::caseD_4();
        return uVar4;
      }
    }
    break;
  case 6:
    if ((uVar1 & 0x40000300) != 0) {
      ExitScriptedSequence__12CBaseMonster(param_1);
      uVar4 = switchD_000b79f0::caseD_4();
      return uVar4;
    }
    break;
  case 8:
    *(undefined4 *)(param_1 + 0x4f8) = 8;
  }
  return *(undefined4 *)(param_1 + 0x4f8);
}


// GetIdealState__13CSquadMonster  @ 000e6598
void GetIdealState__13CSquadMonster(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  IScheduleFlags__12CBaseMonster(param_1);
  if (((*(int *)(param_1 + 0x4f4) == 1) || (*(int *)(param_1 + 0x4f4) == 3)) &&
     ((*(byte *)(param_1 + 0x47a) & 1) != 0)) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
    if (iVar1 != 0) {
      uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
      SquadMakeEnemy__13CSquadMonsterP11CBaseEntity(param_1,uVar2);
    }
  }
  GetIdealState__12CBaseMonster(param_1);
  return;
}


