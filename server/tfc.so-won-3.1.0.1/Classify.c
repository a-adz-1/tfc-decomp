// Classify__10CFurniture  @ 000ddecc
undefined4 Classify__10CFurniture(void)

{
  return 0;
}


// Classify__10CGunTarget  @ 000c7538
undefined4 Classify__10CGunTarget(void)

{
  return 1;
}


// Classify__11CBaseEntity  @ 00100724
undefined4 Classify__11CBaseEntity(void)

{
  return 0;
}


// Classify__11CBasePlayer  @ 000cc23c
undefined4 Classify__11CBasePlayer(void)

{
  return 2;
}


// Classify__11CBaseTurret  @ 00109138
undefined4 Classify__11CBaseTurret(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x644) == 0) && (*(int *)(param_1 + 0x64c) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// Classify__11CTFGoalItem  @ 000ffff4
undefined4 Classify__11CTFGoalItem(void)

{
  return 0x82;
}


// Classify__12CTFDispenser  @ 00092ecc
undefined4 Classify__12CTFDispenser(void)

{
  return 1;
}


// Classify__12CTFSentrygun  @ 000e097c
undefined4 Classify__12CTFSentrygun(void)

{
  return 1;
}


// Classify__12CTFTimerGoal  @ 000fffa8
undefined4 Classify__12CTFTimerGoal(void)

{
  return 0x81;
}


// Classify__15CGenericMonster  @ 000a5d34
undefined4 Classify__15CGenericMonster(void)

{
  return 0xb;
}


// Classify__16CTFSentrygunBase  @ 000e0928
undefined4 Classify__16CTFSentrygunBase(void)

{
  return 1;
}


// Classify__7CTFGoal  @ 00100040
undefined4 Classify__7CTFGoal(void)

{
  return 0x80;
}


// Classify__8CDeadHEV  @ 000d8bc8
undefined4 Classify__8CDeadHEV(void)

{
  return 4;
}


// Classify__8CDetpack  @ 00091730
undefined4 Classify__8CDetpack(void)

{
  return 1;
}


// Classify__8CTFSpawn  @ 000fff5c
undefined4 Classify__8CTFSpawn(void)

{
  return 0x83;
}


// Classify__8CXenHull  @ 001306b0
undefined4 Classify__8CXenHull(void)

{
  return 99;
}


// Classify__8CXenTree  @ 00115cb8
undefined4 Classify__8CXenTree(void)

{
  return 99;
}


// Classify__9CTFDetect  @ 000fff10
undefined4 Classify__9CTFDetect(void)

{
  return 0x80;
}


