// RunAI__12CBaseMonster  @ 000c3394
void RunAI__12CBaseMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((param_1[0x15d] == 1) || (param_1[0x15d] == 3)) {
    iVar2 = (*DAT_0019f808)(0,99);
    if ((iVar2 == 0) && ((*(byte *)(*param_1 + 0x1a4) & 2) == 0)) {
      (**(code **)(param_1[0x115] + 0x210))(param_1);
    }
  }
  iVar2 = param_1[0x15d];
  if (((iVar2 == 0) || (iVar2 == 5)) || (iVar2 == 8)) goto LAB_000c34f3;
  iVar2 = (*DAT_0019f6e4)(*(undefined4 *)(*param_1 + 0x208));
  bVar1 = false;
  if (iVar2 == 0) {
LAB_000c3447:
    bVar1 = true;
  }
  else {
    iVar2 = (*DAT_0019f7b8)(iVar2);
    if (iVar2 == 0) goto LAB_000c3447;
  }
  if ((!bVar1) || (param_1[0x15d] == 2)) {
    (**(code **)(param_1[0x115] + 0x10c))(param_1,(int)ROUND((float)param_1[0x19f]));
    Listen__12CBaseMonster(param_1);
    uVar3 = (**(code **)(param_1[0x115] + 0x1c4))(param_1);
    param_1[0x13e] = param_1[0x13e] & ~uVar3;
    GetEnemy__12CBaseMonster(param_1);
  }
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
  if (iVar2 != 0) {
    iVar2 = param_1[0x115];
    uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
    (**(code **)(iVar2 + 0x1a0))(param_1,uVar4);
  }
  (**(code **)(param_1[0x115] + 0x1c0))(param_1);
LAB_000c34f3:
  FCheckAITrigger__12CBaseMonster(param_1);
  (**(code **)(param_1[0x115] + 0x1e8))(param_1);
  MaintainSchedule__12CBaseMonster(param_1);
  *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) & 0xfc;
  return;
}


