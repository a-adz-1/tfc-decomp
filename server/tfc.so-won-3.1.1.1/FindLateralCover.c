// FindLateralCover__12CBaseMonsterRC6VectorT1  @ 000c0678
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FindLateralCover__12CBaseMonsterRC6VectorT1(int *param_1,float *param_2,float *param_3)

{
  int iVar1;
  int iStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  fStack_78 = *(float *)(gpGlobals + 0x40) * 48.0;
  fStack_74 = *(float *)(gpGlobals + 0x44) * 48.0;
  fStack_70 = 0.0;
  iVar1 = *param_1;
  fStack_6c = *(float *)(iVar1 + 8);
  fStack_68 = *(float *)(iVar1 + 0xc);
  fStack_64 = *(float *)(iVar1 + 0x10);
  iStack_94 = 0;
  fStack_60 = fStack_6c;
  fStack_5c = fStack_68;
  fStack_58 = fStack_64;
  do {
    fStack_60 = fStack_60 - fStack_78;
    fStack_5c = fStack_5c - fStack_74;
    fStack_58 = fStack_58 - fStack_70;
    fStack_6c = fStack_78 + fStack_6c;
    fStack_68 = fStack_74 + fStack_68;
    fStack_64 = fStack_70 + fStack_64;
    iVar1 = *param_1;
    fStack_84 = fStack_60 + *(float *)(iVar1 + 0x174);
    fStack_80 = fStack_5c + *(float *)(iVar1 + 0x178);
    fStack_7c = fStack_58 + *(float *)(iVar1 + 0x17c);
    fStack_90 = *param_2 + *param_3;
    fStack_8c = param_2[1] + param_3[1];
    fStack_88 = param_2[2] + param_3[2];
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&fStack_90,&fStack_84,1,1,*(undefined4 *)(*param_1 + 0x208),auStack_3c);
    if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar1 = (**(code **)(param_1[0x115] + 0x1b4))(param_1,&fStack_60);
      if ((iVar1 != 0) &&
         (iVar1 = (**(code **)(param_1[0x115] + 0x140))(param_1,*param_1 + 8,&fStack_60,0,0),
         iVar1 == 2)) {
        param_1[0x188] = 4;
        param_1[0x184] = 0;
        param_1[0x182] = 0x40;
        param_1[0x185] = (int)fStack_60;
        param_1[0x186] = (int)fStack_5c;
        param_1[0x187] = (int)fStack_58;
        iVar1 = FRefreshRoute__12CBaseMonster(param_1);
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
    iVar1 = *param_1;
    fStack_90 = fStack_6c + *(float *)(iVar1 + 0x174);
    fStack_8c = fStack_68 + *(float *)(iVar1 + 0x178);
    fStack_88 = fStack_64 + *(float *)(iVar1 + 0x17c);
    fStack_84 = *param_2 + *param_3;
    fStack_80 = param_2[1] + param_3[1];
    fStack_7c = param_2[2] + param_3[2];
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&fStack_84,&fStack_90,1,1,*(undefined4 *)(*param_1 + 0x208),auStack_3c);
    if ((((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) &&
        (iVar1 = (**(code **)(param_1[0x115] + 0x1b4))(param_1,&fStack_6c), iVar1 != 0)) &&
       (iVar1 = (**(code **)(param_1[0x115] + 0x140))(param_1,*param_1 + 8,&fStack_6c,0,0),
       iVar1 == 2)) {
      param_1[0x188] = 4;
      param_1[0x184] = 0;
      param_1[0x182] = 0x40;
      param_1[0x185] = (int)fStack_6c;
      param_1[0x186] = (int)fStack_68;
      param_1[0x187] = (int)fStack_64;
      iVar1 = FRefreshRoute__12CBaseMonster(param_1);
      if (iVar1 != 0) {
        return 1;
      }
    }
    iStack_94 = iStack_94 + 1;
  } while (iStack_94 < 5);
  return 0;
}


