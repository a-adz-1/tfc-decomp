// Classify__10CFurniture  @ 000e8dc0
undefined4 Classify__10CFurniture(void)

{
  return 0;
}


// Classify__10CGunTarget  @ 000d5c50
undefined4 Classify__10CGunTarget(void)

{
  return 1;
}


// Classify__11CBaseEntity  @ 0010e530
undefined4 Classify__11CBaseEntity(void)

{
  return 0;
}


// Classify__11CBasePlayer  @ 000d9e90
undefined4 Classify__11CBasePlayer(void)

{
  return 2;
}


// Classify__11CBaseTurret  @ 00115e10
undefined4 Classify__11CBaseTurret(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x638) == 0) && (*(int *)(param_1 + 0x640) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// Classify__11CTFGoalItem  @ 0010dd40
undefined4 Classify__11CTFGoalItem(void)

{
  return 0x82;
}


// Classify__12CTFDispenser  @ 000a8ec0
undefined4 Classify__12CTFDispenser(void)

{
  return 1;
}


// Classify__12CTFSentrygun  @ 000eaf40
undefined4 Classify__12CTFSentrygun(void)

{
  return 1;
}


// Classify__12CTFTimerGoal  @ 0010dd00
undefined4 Classify__12CTFTimerGoal(void)

{
  return 0x81;
}


// Classify__15CGenericMonster  @ 000b8a20
undefined4 Classify__15CGenericMonster(void)

{
  return 0xb;
}


// Classify__16CTFSentrygunBase  @ 000eaef0
undefined4 Classify__16CTFSentrygunBase(void)

{
  return 1;
}


// Classify__7CTFGoal  @ 0010dd80
undefined4 Classify__7CTFGoal(void)

{
  return 0x80;
}


// Classify__8CDeadHEV  @ 000e43c0
undefined4 Classify__8CDeadHEV(void)

{
  return 4;
}


// Classify__8CDetpack  @ 000a8230
undefined4 Classify__8CDetpack(void)

{
  return 1;
}


// Classify__8CTFSpawn  @ 0010dcc0
undefined4 Classify__8CTFSpawn(void)

{
  return 0x83;
}


// Classify__8CXenHull  @ 00129ec0
undefined4 Classify__8CXenHull(void)

{
  return 99;
}


// Classify__8CXenTree  @ 0011f470
undefined4 Classify__8CXenTree(void)

{
  return 99;
}


// Classify__9CTFDetect  @ 0010dc80
undefined4 Classify__9CTFDetect(void)

{
  return 0x80;
}


