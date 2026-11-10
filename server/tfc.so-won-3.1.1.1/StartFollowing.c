// StartFollowing__12CTalkMonsterP11CBaseEntity  @ 000f86bc
void StartFollowing__12CTalkMonsterP11CBaseEntity(int param_1,undefined4 param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (*(int *)(param_1 + 0x698) != 0) {
    CancelScript__12CCineMonster(*(int *)(param_1 + 0x698));
  }
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x578) = 3;
  }
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x504,param_2);
  iVar1 = *(int *)(param_1 + 0x454);
  lVar2 = (longdouble)(*DAT_0019f80c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x188))(param_1,*(undefined4 *)(param_1 + 0x6b8),(float)lVar2);
  *(undefined4 *)(param_1 + 0x704) = *(undefined4 *)(param_1 + 0x504);
  *(undefined4 *)(param_1 + 0x708) = *(undefined4 *)(param_1 + 0x508);
  *(byte *)(param_1 + 0x4fb) = *(byte *)(param_1 + 0x4fb) & 0xef;
  ClearSchedule__12CBaseMonster(param_1);
  return;
}


