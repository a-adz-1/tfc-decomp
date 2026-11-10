// MaintainSchedule__12CBaseMonster  @ 000e57e0
void MaintainSchedule__12CBaseMonster(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    if ((*(int *)(param_1 + 0x570) != 0) && (*(int *)(param_1 + 0x56c) == 4)) {
      NextScheduledTask__12CBaseMonster(param_1);
    }
    iVar1 = FScheduleValid__12CBaseMonster(param_1);
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x564) != *(int *)(param_1 + 0x568))) {
      (**(code **)(*(int *)(param_1 + 0x444) + 0x17c))(param_1);
      if ((*(int *)(param_1 + 0x568) != 8) &&
         ((*(int *)(param_1 + 0x568) != 6 || (*(int *)(param_1 + 0x564) == 6)))) {
        if (((*(int *)(param_1 + 0x4e8) == 0) || (*(int *)(param_1 + 0x4e8) < 0)) &&
           ((*(int *)(param_1 + 0x570) == 0 || (-1 < *(int *)(*(int *)(param_1 + 0x570) + 8))))) {
          if (*(int *)(param_1 + 0x564) == 2) {
            iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
            if (iVar1 == 0) goto LAB_000e589b;
          }
        }
        else {
LAB_000e589b:
          (**(code **)(*(int *)(param_1 + 0x444) + 0x194))(param_1);
        }
      }
      if (((*(byte *)(param_1 + 0x4eb) & 0x40) == 0) ||
         (*(int *)(param_1 + 0x564) != *(int *)(param_1 + 0x568))) {
        SetState__12CBaseMonster12MONSTERSTATE(param_1,*(undefined4 *)(param_1 + 0x568));
        if ((*(int *)(param_1 + 0x564) == 6) || (*(int *)(param_1 + 0x564) == 8)) {
          uVar2 = GetSchedule__12CBaseMonster(param_1);
        }
        else {
          uVar2 = (**(code **)(*(int *)(param_1 + 0x444) + 0x178))(param_1);
        }
        ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,uVar2);
      }
      else {
        if (*(int *)(param_1 + 0x660) == 0) {
          iVar1 = *(int *)(param_1 + 0x444);
          uVar2 = 0x29;
        }
        else {
          iVar1 = *(int *)(param_1 + 0x444);
          uVar2 = *(undefined4 *)(param_1 + 0x660);
        }
        uVar2 = (**(code **)(iVar1 + 0x174))(param_1,uVar2);
        (*DAT_001c1114)(2,"Schedule Failed at %d!\n",*(undefined4 *)(param_1 + 0x574));
        ChangeSchedule__12CBaseMonsterP10Schedule_t(param_1,uVar2);
      }
    }
    if (*(int *)(param_1 + 0x56c) == 0) {
      uVar2 = GetTask__12CBaseMonster(param_1);
      *(undefined4 *)(param_1 + 0x56c) = 1;
      (**(code **)(*(int *)(param_1 + 0x444) + 0x16c))(param_1,uVar2);
    }
    if (*(int *)(param_1 + 0x558) != *(int *)(param_1 + 0x55c)) {
      (**(code **)(*(int *)(param_1 + 0x444) + 0x198))(param_1,*(undefined4 *)(param_1 + 0x55c));
    }
    if (((*(int *)(param_1 + 0x56c) != 4) && (*(int *)(param_1 + 0x56c) != 0)) ||
       (iVar3 = iVar3 + 1, 9 < iVar3)) {
      iVar3 = TaskIsRunning__12CBaseMonster(param_1);
      if (iVar3 != 0) {
        uVar2 = GetTask__12CBaseMonster(param_1);
        (**(code **)(*(int *)(param_1 + 0x444) + 0x170))(param_1,uVar2);
      }
      if (*(int *)(param_1 + 0x558) != *(int *)(param_1 + 0x55c)) {
        (**(code **)(*(int *)(param_1 + 0x444) + 0x198))(param_1,*(undefined4 *)(param_1 + 0x55c));
      }
      return;
    }
  } while( true );
}


