// ObjectCaps__10CBreakable  @ 0009f8ec
undefined4 ObjectCaps__10CBreakable(void)

{
  return 0;
}


// ObjectCaps__10CFurniture  @ 000dded0
undefined4 ObjectCaps__10CFurniture(void)

{
  return 0;
}


// ObjectCaps__10CGunTarget  @ 000c7510
undefined4 ObjectCaps__10CGunTarget(void)

{
  return 0;
}


// ObjectCaps__10CLaserSpot  @ 000f4c68
undefined4 ObjectCaps__10CLaserSpot(void)

{
  return 0x80000000;
}


// ObjectCaps__11CBaseButton  @ 000859a8
char ObjectCaps__11CBaseButton(int *param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  return ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) * '\b';
}


// ObjectCaps__11CBaseEntity  @ 0010072c
undefined4 ObjectCaps__11CBaseEntity(void)

{
  return 2;
}


// ObjectCaps__11CBasePlayer  @ 000d8c70
undefined4 ObjectCaps__11CBasePlayer(void)

{
  return 0;
}


// ObjectCaps__11CFireAndDie  @ 0010635c
undefined4 ObjectCaps__11CFireAndDie(void)

{
  return 0x82;
}


// ObjectCaps__11CWallHealth  @ 000ab64c
undefined4 ObjectCaps__11CWallHealth(void)

{
  return 0x10;
}


// ObjectCaps__12CAutoTrigger  @ 001066e4
undefined4 ObjectCaps__12CAutoTrigger(void)

{
  return 0;
}


// ObjectCaps__12CBaseTrigger  @ 001065c8
undefined4 ObjectCaps__12CBaseTrigger(void)

{
  return 0;
}


// ObjectCaps__12CCineMonster  @ 000ddfa4
undefined4 ObjectCaps__12CCineMonster(void)

{
  return 0;
}


// ObjectCaps__12CPlatTrigger  @ 000c7718
undefined4 ObjectCaps__12CPlatTrigger(void)

{
  return 0x80000000;
}


// ObjectCaps__12CPointEntity  @ 000e7b84
undefined4 ObjectCaps__12CPointEntity(void)

{
  return 0;
}


// ObjectCaps__13CActAnimating  @ 00115df0
undefined4 ObjectCaps__13CActAnimating(void)

{
  return 0;
}


// ObjectCaps__13CButtonTarget  @ 000857ac
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


// ObjectCaps__13CCyclerSprite  @ 000aa510
undefined4 ObjectCaps__13CCyclerSprite(void)

{
  return 0x8000000a;
}


// ObjectCaps__13CFuncRotating  @ 000825b8
undefined4 ObjectCaps__13CFuncRotating(void)

{
  return 0;
}


// ObjectCaps__13CMultiManager  @ 00106654
undefined4 ObjectCaps__13CMultiManager(void)

{
  return 0;
}


// ObjectCaps__13CTriggerRelay  @ 0010669c
undefined4 ObjectCaps__13CTriggerRelay(void)

{
  return 0;
}


// ObjectCaps__14CBasePlatTrain  @ 000c7834
undefined4 ObjectCaps__14CBasePlatTrain(void)

{
  return 0;
}


// ObjectCaps__14CMomentaryDoor  @ 000954f8
undefined4 ObjectCaps__14CMomentaryDoor(void)

{
  return 0;
}


// ObjectCaps__14CTriggerCamera  @ 001060f0
undefined4 ObjectCaps__14CTriggerCamera(void)

{
  return 0;
}


// ObjectCaps__15CAmbientGeneric  @ 000e3db4
undefined4 ObjectCaps__15CAmbientGeneric(void)

{
  return 0;
}


// ObjectCaps__15CFuncTrackTrain  @ 000c787c
undefined4 ObjectCaps__15CFuncTrackTrain(void)

{
  return 0x40;
}


// ObjectCaps__16CFuncIllusionary  @ 00082648
undefined4 ObjectCaps__16CFuncIllusionary(void)

{
  return 0;
}


// ObjectCaps__16CFuncMortarField  @ 000b855c
undefined4 ObjectCaps__16CFuncMortarField(void)

{
  return 0;
}


// ObjectCaps__17CFrictionModifier  @ 0010672c
undefined4 ObjectCaps__17CFrictionModifier(void)

{
  return 0;
}


// ObjectCaps__17CFuncTankControls  @ 000a276c
undefined4 ObjectCaps__17CFuncTankControls(void)

{
  return 8;
}


// ObjectCaps__17CScriptedSentence  @ 000ddf18
undefined4 ObjectCaps__17CScriptedSentence(void)

{
  return 0;
}


// ObjectCaps__18CFuncTrainControls  @ 000c7648
undefined4 ObjectCaps__18CFuncTrainControls(void)

{
  return 0;
}


// ObjectCaps__19CMomentaryRotButton  @ 000858c0
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


// ObjectCaps__20CTriggerChangeTarget  @ 00106138
undefined4 ObjectCaps__20CTriggerChangeTarget(void)

{
  return 0;
}


// ObjectCaps__4CGib  @ 001297bc
undefined4 ObjectCaps__4CGib(void)

{
  return 0x80000000;
}


// ObjectCaps__5CBeam  @ 0009bb10
int ObjectCaps__5CBeam(int *param_1)

{
  return (uint)(*(short *)(*param_1 + 0x1a0) < 0) << 0x1f;
}


// ObjectCaps__7CCorpse  @ 0013015c
undefined4 ObjectCaps__7CCorpse(void)

{
  return 0x80000000;
}


// ObjectCaps__7CCycler  @ 000aa5a4
undefined4 ObjectCaps__7CCycler(void)

{
  return 10;
}


// ObjectCaps__7CShower  @ 0009d6f0
undefined4 ObjectCaps__7CShower(void)

{
  return 0x80000000;
}


// ObjectCaps__7CSprite  @ 0009bcec
int ObjectCaps__7CSprite(int *param_1)

{
  return (uint)(*(short *)(*param_1 + 0x1a0) < 0) << 0x1f;
}


// ObjectCaps__8CNodeEnt  @ 000c0c08
undefined4 ObjectCaps__8CNodeEnt(void)

{
  return 0;
}


// ObjectCaps__8CSpeaker  @ 000e3d28
undefined4 ObjectCaps__8CSpeaker(void)

{
  return 0;
}


// ObjectCaps__9CBaseDoor  @ 00095584
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


// ObjectCaps__9CBubbling  @ 0009b6dc
undefined4 ObjectCaps__9CBubbling(void)

{
  return 0;
}


// ObjectCaps__9CFuncTank  @ 000a2d9c
undefined4 ObjectCaps__9CFuncTank(void)

{
  return 0;
}


// ObjectCaps__9CFuncWall  @ 00082718
undefined4 ObjectCaps__9CFuncWall(void)

{
  return 0;
}


// ObjectCaps__9CPendulum  @ 00082570
undefined4 ObjectCaps__9CPendulum(void)

{
  return 0;
}


// ObjectCaps__9CPushable  @ 0009f854
undefined4 ObjectCaps__9CPushable(void)

{
  return 0x10;
}


// ObjectCaps__9CRecharge  @ 000a8ca0
undefined4 ObjectCaps__9CRecharge(void)

{
  return 0x10;
}


// ObjectCaps__9CSoundEnt  @ 000e44c0
undefined4 ObjectCaps__9CSoundEnt(void)

{
  return 0x80000000;
}


// ObjectCaps__9CSprayCan  @ 000d8c14
undefined4 ObjectCaps__9CSprayCan(void)

{
  return 0x80000000;
}


// ObjectCaps__9CTestHull  @ 0012c81c
undefined4 ObjectCaps__9CTestHull(void)

{
  return 0;
}


