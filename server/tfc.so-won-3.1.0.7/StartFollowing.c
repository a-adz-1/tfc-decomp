// StartFollowing__12CTalkMonsterP11CBaseEntity  @ 000f6b60
void StartFollowing__12CTalkMonsterP11CBaseEntity(int param_1,undefined4 param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (*(int *)(param_1 + 0x688) != 0) {
    CancelScript__12CCineMonster(*(undefined4 *)(param_1 + 0x688));
  }
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x568) = 3;
  }
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x4f4,param_2);
  iVar1 = *(int *)(param_1 + 0x444);
  lVar2 = (longdouble)(*DAT_001c118c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x188))(param_1,*(undefined4 *)(param_1 + 0x6a8),(float)lVar2);
  *(undefined4 *)(param_1 + 0x6f4) = *(undefined4 *)(param_1 + 0x4f4);
  *(undefined4 *)(param_1 + 0x6f8) = *(undefined4 *)(param_1 + 0x4f8);
  *(byte *)(param_1 + 0x4eb) = *(byte *)(param_1 + 0x4eb) & 0xef;
  ClearSchedule__12CBaseMonster(param_1);
  return;
}


