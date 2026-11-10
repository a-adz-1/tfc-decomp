// RunAI__12CBaseMonster  @ 000c8a20
void RunAI__12CBaseMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((param_1[0x13a] == 1) || (param_1[0x13a] == 3)) {
    iVar2 = (*DAT_00175628)(0,99);
    if ((iVar2 == 0) && ((*(byte *)(*param_1 + 0x184) & 2) == 0)) {
      (**(code **)(param_1[0xf2] + 0x208))(param_1);
    }
  }
  if (((param_1[0x13a] == 0) || (param_1[0x13a] == 5)) || (param_1[0x13a] == 8)) goto LAB_000c8b62;
  iVar2 = (*DAT_00175504)(*(undefined4 *)(*param_1 + 0x1e8));
  bVar1 = false;
  if (iVar2 == 0) {
LAB_000c8abc:
    bVar1 = true;
  }
  else {
    iVar2 = (*DAT_001755d8)(iVar2);
    if (iVar2 == 0) goto LAB_000c8abc;
  }
  if ((!bVar1) || (param_1[0x13a] == 2)) {
    (**(code **)(param_1[0xf2] + 0x104))(param_1,(int)ROUND((float)param_1[0x17c]));
    Listen__12CBaseMonster(param_1);
    uVar3 = (**(code **)(param_1[0xf2] + 0x1bc))(param_1);
    param_1[0x11b] = param_1[0x11b] & ~uVar3;
    GetEnemy__12CBaseMonster(param_1);
  }
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
  if (iVar2 != 0) {
    iVar2 = param_1[0xf2];
    uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
    (**(code **)(iVar2 + 0x198))(param_1,uVar4);
  }
  (**(code **)(param_1[0xf2] + 0x1b8))(param_1);
LAB_000c8b62:
  FCheckAITrigger__12CBaseMonster(param_1);
  (**(code **)(param_1[0xf2] + 0x1e0))(param_1);
  MaintainSchedule__12CBaseMonster(param_1);
  *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) & 0xfc;
  return;
}


