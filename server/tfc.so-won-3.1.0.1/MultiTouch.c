// MultiTouch__12CBaseTriggerP11CBaseEntity  @ 0010300c
void MultiTouch__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_2;
  iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
  if (iVar2 == 0) {
    return;
  }
  if ((((*(byte *)(piVar1 + 0x69) & 8) == 0) || ((*(byte *)(*param_1 + 0x1a0) & 2) != 0)) &&
     (((*(byte *)(piVar1 + 0x69) & 0x20) == 0 || ((*(byte *)(*param_1 + 0x1a0) & 1) == 0)))) {
    if ((*(byte *)(*param_1 + 0x1a0) & 4) == 0) {
      return;
    }
    iVar2 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"func_pushable");
    if (iVar2 != 0) {
      return;
    }
  }
  ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity(param_1,param_2);
  return;
}


