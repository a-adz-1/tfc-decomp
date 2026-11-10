// Classify__10CFurniture  @ 000eab00
undefined4 Classify__10CFurniture(void)

{
  return 0;
}


// Classify__10CGunTarget  @ 000d18bc
undefined4 Classify__10CGunTarget(void)

{
  return 1;
}


// Classify__11CBaseEntity  @ 00112f4c
undefined4 Classify__11CBaseEntity(void)

{
  return 0;
}


// Classify__11CBasePlayer  @ 000e5da4
undefined4 Classify__11CBasePlayer(void)

{
  return 2;
}


// Classify__11CBaseTurret  @ 0011cc24
undefined4 Classify__11CBaseTurret(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x6c4) == 0) && (*(int *)(param_1 + 0x6cc) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// Classify__11CTFGoalItem  @ 00112730
undefined4 Classify__11CTFGoalItem(void)

{
  return 0x82;
}


// Classify__12CTFDispenser  @ 0009ca4c
undefined4 Classify__12CTFDispenser(void)

{
  return 1;
}


// Classify__12CTFSentrygun  @ 000ef0f8
undefined4 Classify__12CTFSentrygun(void)

{
  return 1;
}


// Classify__12CTFTimerGoal  @ 001126b4
undefined4 Classify__12CTFTimerGoal(void)

{
  return 0x81;
}


// Classify__15CGenericMonster  @ 000b05f4
undefined4 Classify__15CGenericMonster(void)

{
  return 0xb;
}


// Classify__16CTFSentrygunBase  @ 000ef070
undefined4 Classify__16CTFSentrygunBase(void)

{
  return 1;
}


// Classify__7CTFGoal  @ 001127ac
undefined4 Classify__7CTFGoal(void)

{
  return 0x80;
}


// Classify__8CDeadHEV  @ 000e4e28
undefined4 Classify__8CDeadHEV(void)

{
  return 4;
}


// Classify__8CDetpack  @ 0009acc0
undefined4 Classify__8CDetpack(void)

{
  return 1;
}


// Classify__8CTFSpawn  @ 00112638
undefined4 Classify__8CTFSpawn(void)

{
  return 0x83;
}


// Classify__8CXenHull  @ 00145cf0
undefined4 Classify__8CXenHull(void)

{
  return 99;
}


// Classify__8CXenTree  @ 00129760
undefined4 Classify__8CXenTree(void)

{
  return 99;
}


// Classify__9CTFDetect  @ 001125bc
undefined4 Classify__9CTFDetect(void)

{
  return 0x80;
}


