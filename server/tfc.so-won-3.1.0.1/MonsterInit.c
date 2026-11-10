// MonsterInit__12CBaseMonster  @ 000b2554
void MonsterInit__12CBaseMonster(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  
  fVar2 = gpGlobals[5];
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x118) = 0;
    *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
    *(undefined4 *)(*param_1 + 0xac) = *(undefined4 *)(*param_1 + 0x54);
    *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
    *(undefined4 *)(*param_1 + 0x170) = 0;
    param_1[0x13e] = 1;
    param_1[0x13b] = 1;
    *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
    if ((*(byte *)(*param_1 + 0x1a0) & 4) != 0) {
      pbVar1 = (byte *)(*param_1 + 0x1a6);
      *pbVar1 = *pbVar1 | 0x80;
    }
    ClearSchedule__12CBaseMonster(param_1);
    RouteClear__12CBaseMonster(param_1);
    InitBoneControllers__14CBaseAnimating(param_1);
    param_1[0x16e] = -1;
    param_1[0x16f] = 0;
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x11f,0);
    param_1[0x17e] = 0x44800000;
    param_1[0x17f] = 0x45000000;
    SetEyePosition__12CBaseMonster(param_1);
    param_1[3] = -0x10000;
    param_1[4] = (int)MonsterInitThink__12CBaseMonster;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    param_1[7] = -0x10000;
    param_1[8] = (int)MonsterUse__12CBaseMonsterP11CBaseEntityT18USE_TYPEf;
  }
  else {
    (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


