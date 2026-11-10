// StartFollowing__12CTalkMonsterP11CBaseEntity  @ 000e9e84
void StartFollowing__12CTalkMonsterP11CBaseEntity(int param_1,undefined4 param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (*(int *)(param_1 + 0x618) != 0) {
    CancelScript__12CCineMonster(*(undefined4 *)(param_1 + 0x618));
  }
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x4f8) = 3;
  }
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x484,param_2);
  iVar1 = *(int *)(param_1 + 0x3d4);
  lVar2 = (longdouble)(*DAT_001a7fac)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
  (**(code **)(iVar1 + 0x180))(param_1,*(undefined4 *)(param_1 + 0x638),(float)lVar2);
  *(undefined4 *)(param_1 + 0x684) = *(undefined4 *)(param_1 + 0x484);
  *(undefined4 *)(param_1 + 0x688) = *(undefined4 *)(param_1 + 0x488);
  *(byte *)(param_1 + 0x47b) = *(byte *)(param_1 + 0x47b) & 0xef;
  ClearSchedule__12CBaseMonster(param_1);
  return;
}


