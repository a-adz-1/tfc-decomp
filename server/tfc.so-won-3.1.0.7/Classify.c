// Classify__10CFurniture  @ 000e9f68
undefined4 Classify__10CFurniture(void)

{
  return 0;
}


// Classify__10CGunTarget  @ 000d2898
undefined4 Classify__10CGunTarget(void)

{
  return 1;
}


// Classify__11CBaseEntity  @ 0010fa2c
undefined4 Classify__11CBaseEntity(void)

{
  return 0;
}


// Classify__11CBasePlayer  @ 000d78ec
undefined4 Classify__11CBasePlayer(void)

{
  return 2;
}


// Classify__11CBaseTurret  @ 00118c04
undefined4 Classify__11CBaseTurret(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x6b4) == 0) && (*(int *)(param_1 + 0x6bc) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// Classify__11CTFGoalItem  @ 0010f2e8
undefined4 Classify__11CTFGoalItem(void)

{
  return 0x82;
}


// Classify__12CTFDispenser  @ 0009d3ac
undefined4 Classify__12CTFDispenser(void)

{
  return 1;
}


// Classify__12CTFSentrygun  @ 000ed388
undefined4 Classify__12CTFSentrygun(void)

{
  return 1;
}


// Classify__12CTFTimerGoal  @ 0010f27c
undefined4 Classify__12CTFTimerGoal(void)

{
  return 0x81;
}


// Classify__15CGenericMonster  @ 000b0aa4
undefined4 Classify__15CGenericMonster(void)

{
  return 0xb;
}


// Classify__16CTFSentrygunBase  @ 000ed314
undefined4 Classify__16CTFSentrygunBase(void)

{
  return 1;
}


// Classify__7CTFGoal  @ 0010f354
undefined4 Classify__7CTFGoal(void)

{
  return 0x80;
}


// Classify__8CDeadHEV  @ 000e4b58
undefined4 Classify__8CDeadHEV(void)

{
  return 4;
}


// Classify__8CDetpack  @ 0009b788
undefined4 Classify__8CDetpack(void)

{
  return 1;
}


// Classify__8CTFSpawn  @ 0010f210
undefined4 Classify__8CTFSpawn(void)

{
  return 0x83;
}


// Classify__8CXenHull  @ 001407d8
undefined4 Classify__8CXenHull(void)

{
  return 99;
}


// Classify__8CXenTree  @ 00125930
undefined4 Classify__8CXenTree(void)

{
  return 99;
}


// Classify__9CTFDetect  @ 0010f1a4
undefined4 Classify__9CTFDetect(void)

{
  return 0x80;
}


