// MonsterInit__12CBaseMonster  @ 000bda88
void MonsterInit__12CBaseMonster(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  
  fVar2 = gpGlobals[5];
  if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x118) = 0;
    *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
    *(undefined4 *)(*param_1 + 0xac) = *(undefined4 *)(*param_1 + 0x54);
    *(undefined4 *)(*param_1 + 0x1b0) = *(undefined4 *)(*param_1 + 0x160);
    *(undefined4 *)(*param_1 + 0x170) = 0;
    param_1[0x15e] = 1;
    param_1[0x15b] = 1;
    *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) | 0x20;
    if ((*(byte *)(*param_1 + 0x1a0) & 4) != 0) {
      pbVar1 = (byte *)(*param_1 + 0x1a6);
      *pbVar1 = *pbVar1 | 0x80;
    }
    ClearSchedule__12CBaseMonster(param_1);
    RouteNew__12CBaseMonster(param_1);
    param_1[0x182] = 0;
    param_1[0x188] = 1;
    *(byte *)(param_1 + 399) = *(byte *)(param_1 + 399) & 0xdf;
    InitBoneControllers__14CBaseAnimating(param_1);
    param_1[0x18e] = -1;
    param_1[399] = 0;
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x13f,0);
    param_1[0x19e] = 0x44800000;
    param_1[0x19f] = 0x45000000;
    SetEyePosition__12CBaseMonster(param_1);
    param_1[3] = -0x10000;
    param_1[4] = (int)MonsterInitThink__12CBaseMonster;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    param_1[7] = -0x10000;
    param_1[8] = (int)MonsterUse__12CBaseMonsterP11CBaseEntityT18USE_TYPEf;
  }
  else {
    (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


