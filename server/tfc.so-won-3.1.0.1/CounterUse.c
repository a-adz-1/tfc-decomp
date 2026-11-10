// CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf  @ 001032ac
void CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  byte bVar5;
  
  param_1[0x110] = param_1[0x110] + -1;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x112,param_2);
  if (param_1[0x110] < 0) {
    return;
  }
  bVar5 = 0;
  puVar1 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x112);
  iVar2 = strcmp((char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)),"player");
  if (iVar2 == 0) {
    bVar5 = (*(byte *)(*param_1 + 0x1a0) ^ 1) & 1;
  }
  if (param_1[0x110] == 0) {
    if (bVar5 != 0) {
      (*DAT_001a7f34)(1,"Sequence completed!");
    }
    uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x112);
    ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity(param_1,uVar3);
    return;
  }
  if (bVar5 == 0) {
    return;
  }
  iVar2 = param_1[0x110];
  if (iVar2 == 2) {
    pcVar4 = "Only 2 more to go...";
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        pcVar4 = "Only 1 more to go...";
        goto LAB_00103394;
      }
    }
    else if (iVar2 == 3) {
      pcVar4 = "Only 3 more to go...";
      goto LAB_00103394;
    }
    pcVar4 = "There are more to go...";
  }
LAB_00103394:
  (*DAT_001a7f34)(1,pcVar4);
  return;
}


