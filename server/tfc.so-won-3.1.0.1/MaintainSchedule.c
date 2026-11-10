// MaintainSchedule__12CBaseMonster  @ 000d9744
void MaintainSchedule__12CBaseMonster(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    if ((*(int *)(param_1 + 0x500) != 0) && (*(int *)(param_1 + 0x4fc) == 4)) {
      NextScheduledTask__12CBaseMonster(param_1);
    }
    iVar1 = FScheduleValid__12CBaseMonster(param_1);
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x4f4) != *(int *)(param_1 + 0x4f8))) {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x174))(param_1);
      if ((*(int *)(param_1 + 0x4f8) != 8) &&
         ((*(int *)(param_1 + 0x4f8) != 6 || (*(int *)(param_1 + 0x4f4) == 6)))) {
        if (((*(int *)(param_1 + 0x478) == 0) || (*(int *)(param_1 + 0x478) < 0)) &&
           ((*(int *)(param_1 + 0x500) == 0 || (-1 < *(int *)(*(int *)(param_1 + 0x500) + 8))))) {
          if (*(int *)(param_1 + 0x4f4) == 2) {
            iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
            if (iVar1 == 0) goto LAB_000d97ff;
          }
        }
        else {
LAB_000d97ff:
          (**(code **)(*(int *)(param_1 + 0x3d4) + 0x18c))(param_1);
        }
      }
      if (((*(byte *)(param_1 + 0x47b) & 0x40) == 0) ||
         (*(int *)(param_1 + 0x4f4) != *(int *)(param_1 + 0x4f8))) {
        SetState__12CBaseMonster12MONSTERSTATE(param_1,*(undefined4 *)(param_1 + 0x4f8));
        if ((*(int *)(param_1 + 0x4f4) == 6) || (*(int *)(param_1 + 0x4f4) == 8)) {
          uVar2 = GetSchedule__12CBaseMonster(param_1);
        }
        else {
          uVar2 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x170))(param_1);
        }
        ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,uVar2);
      }
      else {
        if (*(int *)(param_1 + 0x5f0) == 0) {
          iVar1 = *(int *)(param_1 + 0x3d4);
          uVar2 = 0x29;
        }
        else {
          iVar1 = *(int *)(param_1 + 0x3d4);
          uVar2 = *(undefined4 *)(param_1 + 0x5f0);
        }
        uVar2 = (**(code **)(iVar1 + 0x16c))(param_1,uVar2);
        (*DAT_001a7f34)(2,"Schedule Failed at %d!\n",*(undefined4 *)(param_1 + 0x504));
        ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,uVar2);
      }
    }
    if (*(int *)(param_1 + 0x4fc) == 0) {
      uVar2 = GetTask__12CBaseMonster(param_1);
      *(undefined4 *)(param_1 + 0x4fc) = 1;
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x164))(param_1,uVar2);
    }
    if (*(int *)(param_1 + 0x4e8) != *(int *)(param_1 + 0x4ec)) {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 400))(param_1,*(undefined4 *)(param_1 + 0x4ec));
    }
    if (((*(int *)(param_1 + 0x4fc) != 4) && (*(int *)(param_1 + 0x4fc) != 0)) ||
       (iVar3 = iVar3 + 1, 9 < iVar3)) {
      iVar3 = TaskIsRunning__12CBaseMonster(param_1);
      if (iVar3 != 0) {
        uVar2 = GetTask__12CBaseMonster(param_1);
        (**(code **)(*(int *)(param_1 + 0x3d4) + 0x168))(param_1,uVar2);
      }
      if (*(int *)(param_1 + 0x4e8) != *(int *)(param_1 + 0x4ec)) {
        (**(code **)(*(int *)(param_1 + 0x3d4) + 400))(param_1,*(undefined4 *)(param_1 + 0x4ec));
      }
      return;
    }
  } while( true );
}


