// CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf  @ 00110c40
void CounterUse__12CBaseTriggerP11CBaseEntityT18USE_TYPEf(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  char *pcVar5;
  
  param_1[0x10d] = param_1[0x10d] + -1;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x10f,param_2);
  if (-1 < param_1[0x10d]) {
    bVar4 = 0;
    puVar1 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x10f);
    iVar2 = strcmp((char *)(*(int *)*puVar1 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar2 == 0) {
      bVar4 = (*(byte *)(*param_1 + 0x180) ^ 1) & 1;
    }
    if (param_1[0x10d] == 0) {
      if (bVar4 != 0) {
        (*DAT_001755b4)(1,"Sequence completed!");
      }
      uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f);
      ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity(param_1,uVar3);
    }
    else if (bVar4 != 0) {
      iVar2 = param_1[0x10d];
      if (iVar2 == 2) {
        pcVar5 = "Only 2 more to go...";
      }
      else if (iVar2 < 3) {
        if (iVar2 != 1) {
          FUN_00110d20();
          return;
        }
        pcVar5 = "Only 1 more to go...";
      }
      else {
        if (iVar2 != 3) {
          FUN_00110d20();
          return;
        }
        pcVar5 = "Only 3 more to go...";
      }
      (*DAT_001755b4)(1,pcVar5);
    }
  }
  return;
}


