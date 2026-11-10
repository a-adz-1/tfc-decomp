// MultiTouch__12CBaseTriggerP11CBaseEntity  @ 00118de4
void MultiTouch__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = (int *)*param_2;
  iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
  if (iVar3 == 0) {
    return;
  }
  uVar2 = piVar1[0x69];
  if ((((uVar2 & 8) == 0) || ((*(byte *)(*param_1 + 0x1a0) & 2) != 0)) &&
     (((uVar2 & 0x20) == 0 || ((*(byte *)(*param_1 + 0x1a0) & 1) == 0)))) {
    if ((*(byte *)(*param_1 + 0x1a0) & 4) == 0) {
      return;
    }
    iVar3 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"func_pushable");
    if (iVar3 != 0) {
      return;
    }
  }
  ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity(param_1,param_2);
  return;
}


