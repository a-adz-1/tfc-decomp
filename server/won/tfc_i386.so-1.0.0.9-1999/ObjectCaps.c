// ObjectCaps__10CBreakable  @ 000b3ca0
undefined4 ObjectCaps__10CBreakable(void)

{
  return 0;
}


// ObjectCaps__10CFurniture  @ 000e8dd0
undefined4 ObjectCaps__10CFurniture(void)

{
  return 0;
}


// ObjectCaps__10CGunTarget  @ 000d5c10
undefined4 ObjectCaps__10CGunTarget(void)

{
  return 0;
}


// ObjectCaps__10CLaserSpot  @ 00103de0
undefined4 ObjectCaps__10CLaserSpot(void)

{
  return 0x80000000;
}


// ObjectCaps__11CBaseButton  @ 000a0250
undefined4 ObjectCaps__11CBaseButton(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x14c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x14c) == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar1 = 8;
  }
  return uVar1;
}


// ObjectCaps__11CBaseEntity  @ 0010e550
undefined4 ObjectCaps__11CBaseEntity(void)

{
  return 2;
}


// ObjectCaps__11CBasePlayer  @ 000e4440
undefined4 ObjectCaps__11CBasePlayer(void)

{
  return 0;
}


// ObjectCaps__11CFireAndDie  @ 001134f0
undefined4 ObjectCaps__11CFireAndDie(void)

{
  return 0x82;
}


// ObjectCaps__11CWallHealth  @ 000bd360
undefined4 ObjectCaps__11CWallHealth(void)

{
  return 0x10;
}


// ObjectCaps__12CAutoTrigger  @ 001137a0
undefined4 ObjectCaps__12CAutoTrigger(void)

{
  return 0;
}


// ObjectCaps__12CBaseTrigger  @ 001136b0
undefined4 ObjectCaps__12CBaseTrigger(void)

{
  return 0;
}


// ObjectCaps__12CCineMonster  @ 000e8e80
undefined4 ObjectCaps__12CCineMonster(void)

{
  return 0;
}


// ObjectCaps__12CPlatTrigger  @ 000d5e00
undefined4 ObjectCaps__12CPlatTrigger(void)

{
  return 0x80000000;
}


// ObjectCaps__12CPointEntity  @ 000f11c0
undefined4 ObjectCaps__12CPointEntity(void)

{
  return 0;
}


// ObjectCaps__13CActAnimating  @ 0011f560
undefined4 ObjectCaps__13CActAnimating(void)

{
  return 0;
}


// ObjectCaps__13CButtonTarget  @ 000a0070
undefined4 ObjectCaps__13CButtonTarget(int *param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  return uVar1;
}


// ObjectCaps__13CCyclerSprite  @ 000bc420
undefined4 ObjectCaps__13CCyclerSprite(void)

{
  return 0x8000000a;
}


// ObjectCaps__13CFuncRotating  @ 0009d370
undefined4 ObjectCaps__13CFuncRotating(void)

{
  return 0;
}


// ObjectCaps__13CMultiManager  @ 00113720
undefined4 ObjectCaps__13CMultiManager(void)

{
  return 0;
}


// ObjectCaps__13CTriggerRelay  @ 00113760
undefined4 ObjectCaps__13CTriggerRelay(void)

{
  return 0;
}


// ObjectCaps__14CBasePlatTrain  @ 000d5ef0
undefined4 ObjectCaps__14CBasePlatTrain(void)

{
  return 0;
}


// ObjectCaps__14CMomentaryDoor  @ 000ab0f0
undefined4 ObjectCaps__14CMomentaryDoor(void)

{
  return 0;
}


// ObjectCaps__14CTriggerCamera  @ 00113320
undefined4 ObjectCaps__14CTriggerCamera(void)

{
  return 0;
}


// ObjectCaps__15CAmbientGeneric  @ 000edee0
undefined4 ObjectCaps__15CAmbientGeneric(void)

{
  return 0;
}


// ObjectCaps__15CFuncTrackTrain  @ 000d5f30
undefined4 ObjectCaps__15CFuncTrackTrain(void)

{
  return 0x40;
}


// ObjectCaps__16CFuncIllusionary  @ 0009d3f0
undefined4 ObjectCaps__16CFuncIllusionary(void)

{
  return 0;
}


// ObjectCaps__16CFuncMortarField  @ 000c9520
undefined4 ObjectCaps__16CFuncMortarField(void)

{
  return 0;
}


// ObjectCaps__17CFrictionModifier  @ 001137e0
undefined4 ObjectCaps__17CFrictionModifier(void)

{
  return 0;
}


// ObjectCaps__17CFuncTankControls  @ 000b61f0
undefined4 ObjectCaps__17CFuncTankControls(void)

{
  return 8;
}


// ObjectCaps__17CScriptedSentence  @ 000e8e10
undefined4 ObjectCaps__17CScriptedSentence(void)

{
  return 0;
}


// ObjectCaps__18CFuncTrainControls  @ 000d5d60
undefined4 ObjectCaps__18CFuncTrainControls(void)

{
  return 0;
}


// ObjectCaps__19CMomentaryRotButton  @ 000a0190
undefined4 ObjectCaps__19CMomentaryRotButton(int *param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ObjectCaps__20CTriggerChangeTarget  @ 00113360
undefined4 ObjectCaps__20CTriggerChangeTarget(void)

{
  return 0;
}


// ObjectCaps__4CGib  @ 001234d0
undefined4 ObjectCaps__4CGib(void)

{
  return 0x80000000;
}


// ObjectCaps__5CBeam  @ 000b0a60
int ObjectCaps__5CBeam(int *param_1)

{
  return (uint)(*(short *)(*param_1 + 0x180) < 0) << 0x1f;
}


// ObjectCaps__7CCorpse  @ 00129a80
undefined4 ObjectCaps__7CCorpse(void)

{
  return 0x80000000;
}


// ObjectCaps__7CCycler  @ 000bc4a0
undefined4 ObjectCaps__7CCycler(void)

{
  return 10;
}


// ObjectCaps__7CShower  @ 000b1fb0
undefined4 ObjectCaps__7CShower(void)

{
  return 0x80000000;
}


// ObjectCaps__7CSprite  @ 000b0c40
int ObjectCaps__7CSprite(int *param_1)

{
  return (uint)(*(short *)(*param_1 + 0x180) < 0) << 0x1f;
}


// ObjectCaps__8CNodeEnt  @ 000d0080
undefined4 ObjectCaps__8CNodeEnt(void)

{
  return 0;
}


// ObjectCaps__8CSpeaker  @ 000ede70
undefined4 ObjectCaps__8CSpeaker(void)

{
  return 0;
}


// ObjectCaps__9CBaseDoor  @ 000ab160
undefined4 ObjectCaps__9CBaseDoor(int *param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  return uVar1;
}


// ObjectCaps__9CBubbling  @ 000b05a0
undefined4 ObjectCaps__9CBubbling(void)

{
  return 0;
}


// ObjectCaps__9CFuncTank  @ 000b6750
undefined4 ObjectCaps__9CFuncTank(void)

{
  return 0;
}


// ObjectCaps__9CFuncWall  @ 0009d490
undefined4 ObjectCaps__9CFuncWall(void)

{
  return 0;
}


// ObjectCaps__9CPendulum  @ 0009d330
undefined4 ObjectCaps__9CPendulum(void)

{
  return 0;
}


// ObjectCaps__9CPushable  @ 000b3c00
undefined4 ObjectCaps__9CPushable(void)

{
  return 0x10;
}


// ObjectCaps__9CRecharge  @ 000bafb0
undefined4 ObjectCaps__9CRecharge(void)

{
  return 0x10;
}


// ObjectCaps__9CSoundEnt  @ 000ee540
undefined4 ObjectCaps__9CSoundEnt(void)

{
  return 0x80000000;
}


// ObjectCaps__9CSprayCan  @ 000e4400
undefined4 ObjectCaps__9CSprayCan(void)

{
  return 0x80000000;
}


// ObjectCaps__9CTestHull  @ 00125f30
undefined4 ObjectCaps__9CTestHull(void)

{
  return 0;
}


