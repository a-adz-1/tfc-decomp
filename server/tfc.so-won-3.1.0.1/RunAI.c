// RunAI__12CBaseMonster  @ 000b7820
void RunAI__12CBaseMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((param_1[0x13d] == 1) || (param_1[0x13d] == 3)) {
    iVar2 = (*DAT_001a7fa8)(0,99);
    if ((iVar2 == 0) && ((*(byte *)(*param_1 + 0x1a4) & 2) == 0)) {
      (**(code **)(param_1[0xf5] + 0x208))(param_1);
    }
  }
  if (((param_1[0x13d] == 0) || (param_1[0x13d] == 5)) || (param_1[0x13d] == 8)) goto LAB_000b7988;
  iVar2 = (*DAT_001a7e84)(*(undefined4 *)(*param_1 + 0x208));
  bVar1 = false;
  if (iVar2 == 0) {
LAB_000b78db:
    bVar1 = true;
  }
  else {
    iVar2 = (*DAT_001a7f58)(iVar2);
    if (iVar2 == 0) goto LAB_000b78db;
  }
  if ((!bVar1) || (param_1[0x13d] == 2)) {
    (**(code **)(param_1[0xf5] + 0x104))(param_1,(int)ROUND((float)param_1[0x17f]));
    Listen__12CBaseMonster(param_1);
    uVar3 = (**(code **)(param_1[0xf5] + 0x1bc))(param_1);
    param_1[0x11e] = param_1[0x11e] & ~uVar3;
    GetEnemy__12CBaseMonster(param_1);
  }
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
  if (iVar2 != 0) {
    iVar2 = param_1[0xf5];
    uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11f);
    (**(code **)(iVar2 + 0x198))(param_1,uVar4);
  }
  (**(code **)(param_1[0xf5] + 0x1b8))(param_1);
LAB_000b7988:
  FCheckAITrigger__12CBaseMonster(param_1);
  (**(code **)(param_1[0xf5] + 0x1e0))(param_1);
  MaintainSchedule__12CBaseMonster(param_1);
  *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) & 0xfc;
  return;
}


