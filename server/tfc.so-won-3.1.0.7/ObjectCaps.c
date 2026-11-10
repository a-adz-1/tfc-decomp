// ObjectCaps__10CBreakable  @ 000aa2f4
undefined4 ObjectCaps__10CBreakable(void)

{
  return 0;
}


// ObjectCaps__10CFurniture  @ 000e9f6c
undefined4 ObjectCaps__10CFurniture(void)

{
  return 0;
}


// ObjectCaps__10CGunTarget  @ 000d2870
undefined4 ObjectCaps__10CGunTarget(void)

{
  return 0;
}


// ObjectCaps__10CLaserSpot  @ 00102424
undefined4 ObjectCaps__10CLaserSpot(void)

{
  return 0x80000000;
}


// ObjectCaps__11CBaseButton  @ 0008da4c
char ObjectCaps__11CBaseButton(int *param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  return ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) * '\b';
}


// ObjectCaps__11CBaseEntity  @ 0010fa34
undefined4 ObjectCaps__11CBaseEntity(void)

{
  return 2;
}


// ObjectCaps__11CBasePlayer  @ 000e4c40
undefined4 ObjectCaps__11CBasePlayer(void)

{
  return 0;
}


// ObjectCaps__11CFireAndDie  @ 00115c28
undefined4 ObjectCaps__11CFireAndDie(void)

{
  return 0x82;
}


// ObjectCaps__11CWallHealth  @ 000b66ec
undefined4 ObjectCaps__11CWallHealth(void)

{
  return 0x10;
}


// ObjectCaps__12CAutoTrigger  @ 00116150
undefined4 ObjectCaps__12CAutoTrigger(void)

{
  return 0;
}


// ObjectCaps__12CBaseTrigger  @ 00115fb4
undefined4 ObjectCaps__12CBaseTrigger(void)

{
  return 0;
}


// ObjectCaps__12CCineMonster  @ 000ea0a0
undefined4 ObjectCaps__12CCineMonster(void)

{
  return 0;
}


// ObjectCaps__12CPlatTrigger  @ 000d2b38
undefined4 ObjectCaps__12CPlatTrigger(void)

{
  return 0x80000000;
}


// ObjectCaps__12CPointEntity  @ 000f4838
undefined4 ObjectCaps__12CPointEntity(void)

{
  return 0;
}


// ObjectCaps__13CActAnimating  @ 00125ae8
undefined4 ObjectCaps__13CActAnimating(void)

{
  return 0;
}


// ObjectCaps__13CButtonTarget  @ 0008d7b0
undefined4 ObjectCaps__13CButtonTarget(int *param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  return uVar1;
}


// ObjectCaps__13CCyclerSprite  @ 000b5520
undefined4 ObjectCaps__13CCyclerSprite(void)

{
  return 0x8000000a;
}


// ObjectCaps__13CFuncRotating  @ 0008a4fc
undefined4 ObjectCaps__13CFuncRotating(void)

{
  return 0;
}


// ObjectCaps__13CMultiManager  @ 00116080
undefined4 ObjectCaps__13CMultiManager(void)

{
  return 0;
}


// ObjectCaps__13CTriggerRelay  @ 001160e8
undefined4 ObjectCaps__13CTriggerRelay(void)

{
  return 0;
}


// ObjectCaps__14CBasePlatTrain  @ 000d2c94
undefined4 ObjectCaps__14CBasePlatTrain(void)

{
  return 0;
}


// ObjectCaps__14CMomentaryDoor  @ 0009f9f8
undefined4 ObjectCaps__14CMomentaryDoor(void)

{
  return 0;
}


// ObjectCaps__14CTriggerCamera  @ 0011589c
undefined4 ObjectCaps__14CTriggerCamera(void)

{
  return 0;
}


// ObjectCaps__15CAmbientGeneric  @ 000f0830
undefined4 ObjectCaps__15CAmbientGeneric(void)

{
  return 0;
}


// ObjectCaps__15CFuncTrackTrain  @ 000d2cfc
undefined4 ObjectCaps__15CFuncTrackTrain(void)

{
  return 0x40;
}


// ObjectCaps__16CFuncIllusionary  @ 0008a5cc
undefined4 ObjectCaps__16CFuncIllusionary(void)

{
  return 0;
}


// ObjectCaps__16CFuncMortarField  @ 000c381c
undefined4 ObjectCaps__16CFuncMortarField(void)

{
  return 0;
}


// ObjectCaps__17CFrictionModifier  @ 001161b8
undefined4 ObjectCaps__17CFrictionModifier(void)

{
  return 0;
}


// ObjectCaps__17CFuncTankControls  @ 000ad194
undefined4 ObjectCaps__17CFuncTankControls(void)

{
  return 8;
}


// ObjectCaps__17CScriptedSentence  @ 000e9fd4
undefined4 ObjectCaps__17CScriptedSentence(void)

{
  return 0;
}


// ObjectCaps__18CFuncTrainControls  @ 000d2a08
undefined4 ObjectCaps__18CFuncTrainControls(void)

{
  return 0;
}


// ObjectCaps__19CMomentaryRotButton  @ 0008d904
undefined4 ObjectCaps__19CMomentaryRotButton(int *param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ObjectCaps__20CTriggerChangeTarget  @ 00115904
undefined4 ObjectCaps__20CTriggerChangeTarget(void)

{
  return 0;
}


// ObjectCaps__4CGib  @ 0013a00c
undefined4 ObjectCaps__4CGib(void)

{
  return 0x80000000;
}


// ObjectCaps__5CBeam  @ 000a6250
int ObjectCaps__5CBeam(int *param_1)

{
  return (uint)(*(short *)(*param_1 + 0x1a0) < 0) << 0x1f;
}


// ObjectCaps__7CCorpse  @ 00140330
undefined4 ObjectCaps__7CCorpse(void)

{
  return 0x80000000;
}


// ObjectCaps__7CCycler  @ 000b55f4
undefined4 ObjectCaps__7CCycler(void)

{
  return 10;
}


// ObjectCaps__7CShower  @ 000a80a8
undefined4 ObjectCaps__7CShower(void)

{
  return 0x80000000;
}


// ObjectCaps__7CSprite  @ 000a644c
int ObjectCaps__7CSprite(int *param_1)

{
  return (uint)(*(short *)(*param_1 + 0x1a0) < 0) << 0x1f;
}


// ObjectCaps__8CNodeEnt  @ 000cbf08
undefined4 ObjectCaps__8CNodeEnt(void)

{
  return 0;
}


// ObjectCaps__8CSpeaker  @ 000f0764
undefined4 ObjectCaps__8CSpeaker(void)

{
  return 0;
}


// ObjectCaps__9CBaseDoor  @ 0009fac4
undefined4 ObjectCaps__9CBaseDoor(int *param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  return uVar1;
}


// ObjectCaps__9CBubbling  @ 000a5ddc
undefined4 ObjectCaps__9CBubbling(void)

{
  return 0;
}


// ObjectCaps__9CFuncTank  @ 000ad864
undefined4 ObjectCaps__9CFuncTank(void)

{
  return 0;
}


// ObjectCaps__9CFuncWall  @ 0008a6fc
undefined4 ObjectCaps__9CFuncWall(void)

{
  return 0;
}


// ObjectCaps__9CPendulum  @ 0008a494
undefined4 ObjectCaps__9CPendulum(void)

{
  return 0;
}


// ObjectCaps__9CPushable  @ 000aa23c
undefined4 ObjectCaps__9CPushable(void)

{
  return 0x10;
}


// ObjectCaps__9CRecharge  @ 000b3c10
undefined4 ObjectCaps__9CRecharge(void)

{
  return 0x10;
}


// ObjectCaps__9CSoundEnt  @ 000f0f5c
undefined4 ObjectCaps__9CSoundEnt(void)

{
  return 0x80000000;
}


// ObjectCaps__9CSprayCan  @ 000e4bc4
undefined4 ObjectCaps__9CSprayCan(void)

{
  return 0x80000000;
}


// ObjectCaps__9CTestHull  @ 0013cea4
undefined4 ObjectCaps__9CTestHull(void)

{
  return 0;
}


