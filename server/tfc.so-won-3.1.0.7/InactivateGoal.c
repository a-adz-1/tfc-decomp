// InactivateGoal__FP11CBaseEntity  @ 001096e8
void InactivateGoal__FP11CBaseEntity(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  if (param_1[0x86] == 1) {
    iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1);
    if (iVar2 != 0x81) {
      if (((*(byte *)((int)param_1 + 0x229) & 0x20) == 0) ||
         ((iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 != 0x80 &&
          (iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1), iVar2 != 0x82)))) {
        *(undefined4 *)(*param_1 + 0x10c) = 1;
      }
      else {
        *(undefined4 *)(*param_1 + 0x10c) = 2;
      }
    }
    param_1[0x86] = 2;
    if (*(char *)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98)) != '*') {
      pbVar1 = (byte *)(*param_1 + 0x118);
      *pbVar1 = *pbVar1 & 0x7f;
    }
    return;
  }
  return;
}


