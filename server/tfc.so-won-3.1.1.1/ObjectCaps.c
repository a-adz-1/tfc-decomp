// ObjectCaps__10CBreakable  @ 000a9bf8
undefined4 ObjectCaps__10CBreakable(void)

{
  return 0;
}


// ObjectCaps__10CFurniture  @ 000eac58
undefined4 ObjectCaps__10CFurniture(void)

{
  return 0;
}


// ObjectCaps__10CGunTarget  @ 000d1888
undefined4 ObjectCaps__10CGunTarget(void)

{
  return 0;
}


// ObjectCaps__10CLaserSpot  @ 00104d78
undefined4 ObjectCaps__10CLaserSpot(void)

{
  return 0x80000000;
}


// ObjectCaps__11CBaseButton  @ 0008d52c
char ObjectCaps__11CBaseButton(int *param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  return ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) * '\b';
}


// ObjectCaps__11CBaseEntity  @ 00112f60
undefined4 ObjectCaps__11CBaseEntity(void)

{
  return 2;
}


// ObjectCaps__11CBasePlayer  @ 000e6094
undefined4 ObjectCaps__11CBasePlayer(void)

{
  return 0;
}


// ObjectCaps__11CFireAndDie  @ 00118b6c
undefined4 ObjectCaps__11CFireAndDie(void)

{
  return 0x82;
}


// ObjectCaps__11CWallHealth  @ 000b5984
undefined4 ObjectCaps__11CWallHealth(void)

{
  return 0x10;
}


// ObjectCaps__12CAutoTrigger  @ 00119fdc
undefined4 ObjectCaps__12CAutoTrigger(void)

{
  return 0;
}


// ObjectCaps__12CBaseTrigger  @ 001197c8
undefined4 ObjectCaps__12CBaseTrigger(void)

{
  return 0;
}


// ObjectCaps__12CCineMonster  @ 000eb888
undefined4 ObjectCaps__12CCineMonster(void)

{
  return 0;
}


// ObjectCaps__12CPlatTrigger  @ 000d2eb4
undefined4 ObjectCaps__12CPlatTrigger(void)

{
  return 0x80000000;
}


// ObjectCaps__12CPointEntity  @ 000f6acc
undefined4 ObjectCaps__12CPointEntity(void)

{
  return 0;
}


// ObjectCaps__13CActAnimating  @ 00129dd8
undefined4 ObjectCaps__13CActAnimating(void)

{
  return 0;
}


// ObjectCaps__13CButtonTarget  @ 0008c1e4
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


// ObjectCaps__13CCyclerSprite  @ 000b443c
undefined4 ObjectCaps__13CCyclerSprite(void)

{
  return 0x8000000a;
}


// ObjectCaps__13CFuncRotating  @ 0008988c
undefined4 ObjectCaps__13CFuncRotating(void)

{
  return 0;
}


// ObjectCaps__13CMultiManager  @ 00119b1c
undefined4 ObjectCaps__13CMultiManager(void)

{
  return 0;
}


// ObjectCaps__13CTriggerRelay  @ 00119d28
undefined4 ObjectCaps__13CTriggerRelay(void)

{
  return 0;
}


// ObjectCaps__14CBasePlatTrain  @ 000d30f8
undefined4 ObjectCaps__14CBasePlatTrain(void)

{
  return 0;
}


// ObjectCaps__14CMomentaryDoor  @ 0009ef88
undefined4 ObjectCaps__14CMomentaryDoor(void)

{
  return 0;
}


// ObjectCaps__14CTriggerCamera  @ 00117ea4
undefined4 ObjectCaps__14CTriggerCamera(void)

{
  return 0;
}


// ObjectCaps__15CAmbientGeneric  @ 000f2ab0
undefined4 ObjectCaps__15CAmbientGeneric(void)

{
  return 0;
}


// ObjectCaps__15CFuncTrackTrain  @ 000d3174
undefined4 ObjectCaps__15CFuncTrackTrain(void)

{
  return 0x40;
}


// ObjectCaps__16CFuncIllusionary  @ 00089b7c
undefined4 ObjectCaps__16CFuncIllusionary(void)

{
  return 0;
}


// ObjectCaps__16CFuncMortarField  @ 000c40d0
undefined4 ObjectCaps__16CFuncMortarField(void)

{
  return 0;
}


// ObjectCaps__17CFrictionModifier  @ 0011a220
undefined4 ObjectCaps__17CFrictionModifier(void)

{
  return 0;
}


// ObjectCaps__17CFuncTankControls  @ 000abe34
undefined4 ObjectCaps__17CFuncTankControls(void)

{
  return 8;
}


// ObjectCaps__17CScriptedSentence  @ 000eb07c
undefined4 ObjectCaps__17CScriptedSentence(void)

{
  return 0;
}


// ObjectCaps__18CFuncTrainControls  @ 000d20b4
undefined4 ObjectCaps__18CFuncTrainControls(void)

{
  return 0;
}


// ObjectCaps__19CMomentaryRotButton  @ 0008cac4
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


// ObjectCaps__20CTriggerChangeTarget  @ 001180b4
undefined4 ObjectCaps__20CTriggerChangeTarget(void)

{
  return 0;
}


// ObjectCaps__4CGib  @ 0013ed54
undefined4 ObjectCaps__4CGib(void)

{
  return 0x80000000;
}


// ObjectCaps__5CBeam  @ 000a5f18
int ObjectCaps__5CBeam(int *param_1)

{
  return (uint)(*(short *)(*param_1 + 0x1a0) < 0) << 0x1f;
}


// ObjectCaps__7CCorpse  @ 00145904
undefined4 ObjectCaps__7CCorpse(void)

{
  return 0x80000000;
}


// ObjectCaps__7CCycler  @ 000b4990
undefined4 ObjectCaps__7CCycler(void)

{
  return 10;
}


// ObjectCaps__7CShower  @ 000a790c
undefined4 ObjectCaps__7CShower(void)

{
  return 0x80000000;
}


// ObjectCaps__7CSprite  @ 000a613c
int ObjectCaps__7CSprite(int *param_1)

{
  return (uint)(*(short *)(*param_1 + 0x1a0) < 0) << 0x1f;
}


// ObjectCaps__8CNodeEnt  @ 000cba48
undefined4 ObjectCaps__8CNodeEnt(void)

{
  return 0;
}


// ObjectCaps__8CSpeaker  @ 000f204c
undefined4 ObjectCaps__8CSpeaker(void)

{
  return 0;
}


// ObjectCaps__9CBaseDoor  @ 0009f350
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


// ObjectCaps__9CBubbling  @ 000a5a38
undefined4 ObjectCaps__9CBubbling(void)

{
  return 0;
}


// ObjectCaps__9CFuncTank  @ 000acd54
undefined4 ObjectCaps__9CFuncTank(void)

{
  return 0;
}


// ObjectCaps__9CFuncWall  @ 0008a118
undefined4 ObjectCaps__9CFuncWall(void)

{
  return 0;
}


// ObjectCaps__9CPendulum  @ 000896ec
undefined4 ObjectCaps__9CPendulum(void)

{
  return 0;
}


// ObjectCaps__9CPushable  @ 000a96fc
undefined4 ObjectCaps__9CPushable(void)

{
  return 0x10;
}


// ObjectCaps__9CRecharge  @ 000b301c
undefined4 ObjectCaps__9CRecharge(void)

{
  return 0x10;
}


// ObjectCaps__9CSoundEnt  @ 000f32d0
undefined4 ObjectCaps__9CSoundEnt(void)

{
  return 0x80000000;
}


// ObjectCaps__9CSprayCan  @ 000e5918
undefined4 ObjectCaps__9CSprayCan(void)

{
  return 0x80000000;
}


// ObjectCaps__9CTestHull  @ 00141e68
undefined4 ObjectCaps__9CTestHull(void)

{
  return 0;
}


