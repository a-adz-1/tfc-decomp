// MaintainSchedule__12CBaseMonster  @ 000e6a1c
void MaintainSchedule__12CBaseMonster(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  int local_8;
  
  local_8 = 0;
  do {
    if (*(int *)(param_1 + 0x580) == 0) {
LAB_000e6aa2:
      (**(code **)(*(int *)(param_1 + 0x454) + 0x17c))(param_1);
      if ((*(int *)(param_1 + 0x578) != 8) &&
         ((*(int *)(param_1 + 0x578) != 6 || (*(int *)(param_1 + 0x574) == 6)))) {
        if (((*(int *)(param_1 + 0x4f8) == 0) || (*(int *)(param_1 + 0x4f8) < 0)) &&
           ((*(int *)(param_1 + 0x580) == 0 || (-1 < *(int *)(*(int *)(param_1 + 0x580) + 8))))) {
          if (*(int *)(param_1 + 0x574) == 2) {
            iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
            if (iVar1 == 0) goto LAB_000e6b04;
          }
        }
        else {
LAB_000e6b04:
          (**(code **)(*(int *)(param_1 + 0x454) + 0x194))(param_1);
        }
      }
      if (((*(byte *)(param_1 + 0x4fb) & 0x40) == 0) ||
         (*(int *)(param_1 + 0x574) != *(int *)(param_1 + 0x578))) {
        SetState__12CBaseMonster12MONSTERSTATE(param_1,*(int *)(param_1 + 0x578));
        if ((*(int *)(param_1 + 0x574) == 6) || (*(int *)(param_1 + 0x574) == 8)) {
          iVar1 = GetSchedule__12CBaseMonster(param_1);
        }
        else {
          iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x178))(param_1);
        }
        *(int *)(param_1 + 0x580) = iVar1;
        *(undefined4 *)(param_1 + 0x584) = 0;
        *(undefined4 *)(param_1 + 0x57c) = 0;
        *(undefined4 *)(param_1 + 0x4f8) = 0;
        *(undefined4 *)(param_1 + 0x670) = 0;
        if ((*(byte *)(iVar1 + 10) & 2) == 0) goto LAB_000e6c54;
        if (*(int *)(iVar1 + 0xc) != 0) goto LAB_000e6c5a;
        pcVar4 = FUN_00151760;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x670);
        if (iVar1 == 0) {
          iVar2 = *(int *)(param_1 + 0x454);
          iVar1 = 0x29;
        }
        else {
          iVar2 = *(int *)(param_1 + 0x454);
        }
        iVar1 = (**(code **)(iVar2 + 0x174))(param_1,iVar1);
        (*DAT_0019f794)(2,"Schedule Failed at %d!\n",*(undefined4 *)(param_1 + 0x584));
        *(int *)(param_1 + 0x580) = iVar1;
        *(undefined4 *)(param_1 + 0x584) = 0;
        *(undefined4 *)(param_1 + 0x57c) = 0;
        *(undefined4 *)(param_1 + 0x4f8) = 0;
        *(undefined4 *)(param_1 + 0x670) = 0;
        if ((*(byte *)(iVar1 + 10) & 2) == 0) {
LAB_000e6c54:
          if (*(int *)(iVar1 + 0xc) == 0) goto LAB_000e6c80;
        }
        else if (*(int *)(iVar1 + 0xc) == 0) {
          pcVar4 = FUN_00151760;
          goto LAB_000e6c72;
        }
LAB_000e6c5a:
        if ((*(byte *)(*(int *)(param_1 + 0x580) + 10) & 2) != 0) goto LAB_000e6c80;
        pcVar4 = (code *)"Sound mask without COND_HEAR_SOUND!\n";
      }
LAB_000e6c72:
      (*DAT_0019f794)(2,pcVar4);
    }
    else {
      if (*(int *)(param_1 + 0x57c) == 4) {
        *(undefined4 *)(param_1 + 0x57c) = 0;
        iVar1 = *(int *)(param_1 + 0x584) + 1;
        *(int *)(param_1 + 0x584) = iVar1;
        if (iVar1 == *(int *)(*(int *)(param_1 + 0x580) + 4)) {
          *(byte *)(param_1 + 0x4fb) = *(byte *)(param_1 + 0x4fb) | 0x80;
        }
      }
      if (((*(int *)(param_1 + 0x580) == 0) ||
          ((*(uint *)(param_1 + 0x4f8) & (*(uint *)(*(int *)(param_1 + 0x580) + 8) | 0xc0000000)) !=
           0)) || (*(int *)(param_1 + 0x574) != *(int *)(param_1 + 0x578))) goto LAB_000e6aa2;
    }
LAB_000e6c80:
    if (*(int *)(param_1 + 0x57c) == 0) {
      uVar3 = GetTask__12CBaseMonster(param_1);
      *(undefined4 *)(param_1 + 0x57c) = 1;
      (**(code **)(*(int *)(param_1 + 0x454) + 0x16c))(param_1,uVar3);
    }
    if (*(int *)(param_1 + 0x568) != *(int *)(param_1 + 0x56c)) {
      (**(code **)(*(int *)(param_1 + 0x454) + 0x198))(param_1,*(int *)(param_1 + 0x56c));
    }
    if (((*(int *)(param_1 + 0x57c) != 4) && (*(int *)(param_1 + 0x57c) != 0)) ||
       (local_8 = local_8 + 1, 9 < local_8)) {
      iVar1 = TaskIsRunning__12CBaseMonster(param_1);
      if (iVar1 != 0) {
        uVar3 = GetTask__12CBaseMonster(param_1);
        (**(code **)(*(int *)(param_1 + 0x454) + 0x170))(param_1,uVar3);
      }
      if (*(int *)(param_1 + 0x568) != *(int *)(param_1 + 0x56c)) {
        (**(code **)(*(int *)(param_1 + 0x454) + 0x198))(param_1,*(int *)(param_1 + 0x56c));
      }
      return;
    }
  } while( true );
}


