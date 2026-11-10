// StartFollowing__12CTalkMonsterP11CBaseEntity  @ 000f30e0
void StartFollowing__12CTalkMonsterP11CBaseEntity(int param_1,undefined4 param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (*(int *)(param_1 + 0x60c) != 0) {
    CancelScript__12CCineMonster(*(undefined4 *)(param_1 + 0x60c));
  }
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x4ec) = 3;
  }
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x478,param_2);
  iVar1 = *(int *)(param_1 + 0x3c8);
  lVar2 = (longdouble)(*DAT_0017562c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x180))(param_1,*(undefined4 *)(param_1 + 0x62c),(float)lVar2);
  *(undefined4 *)(param_1 + 0x678) = *(undefined4 *)(param_1 + 0x478);
  *(undefined4 *)(param_1 + 0x67c) = *(undefined4 *)(param_1 + 0x47c);
  *(byte *)(param_1 + 0x46f) = *(byte *)(param_1 + 0x46f) & 0xef;
  ClearSchedule__12CBaseMonster(param_1);
  return;
}


