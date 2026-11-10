// CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf  @ 0011547c
void CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  char *pcVar5;
  byte bVar6;
  
  param_1[0x130] = param_1[0x130] + -1;
  piVar4 = param_1 + 0x132;
  __as__7EHANDLEP11CBaseEntity(piVar4,param_2);
  if (param_1[0x130] < 0) {
    return;
  }
  bVar6 = 0;
  iVar1 = __opi__7EHANDLE(piVar4);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__rf__7EHANDLE(piVar4);
    iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar1 == 0) {
      bVar6 = (*(byte *)(*param_1 + 0x1a0) ^ 1) & 1;
    }
  }
  iVar1 = param_1[0x130];
  if (iVar1 == 0) {
    if (bVar6 != 0) {
      (*DAT_0019f794)(1,"Sequence completed!");
    }
    uVar3 = __opP11CBaseEntity__7EHANDLE(piVar4);
    ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity(param_1,uVar3);
    return;
  }
  if (bVar6 == 0) {
    return;
  }
  if (iVar1 == 2) {
    pcVar5 = "Only 2 more to go...";
  }
  else {
    if (iVar1 < 3) {
      if (iVar1 == 1) {
        pcVar5 = "Only 1 more to go...";
        goto LAB_00115588;
      }
    }
    else if (iVar1 == 3) {
      pcVar5 = "Only 3 more to go...";
      goto LAB_00115588;
    }
    pcVar5 = "There are more to go...";
  }
LAB_00115588:
  (*DAT_0019f794)(1,pcVar5);
  return;
}


