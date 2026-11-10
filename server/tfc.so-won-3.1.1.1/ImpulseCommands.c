// ImpulseCommands__11CBasePlayer  @ 000dacf0
void ImpulseCommands__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  PlayerUse__11CBasePlayer(param_1);
  iVar3 = *param_1;
  iVar1 = *(int *)(iVar3 + 0x184);
  if (iVar1 == 99) {
    bVar4 = gmsgLogo == 0;
    if (bVar4) {
      gmsgLogo = (*DAT_0019f7cc)(&UNK_00150aa8,1);
      iVar3 = *param_1;
    }
    (*DAT_0019f758)(1,gmsgLogo,0,*(undefined4 *)(iVar3 + 0x208));
    (*DAT_0019f760)(bVar4);
    (*DAT_0019f75c)();
    if (!bVar4) {
      gmsgLogo = 0;
    }
  }
  else if (iVar1 < 100) {
    if (iVar1 != 0x32) {
      FUN_000db000();
      return;
    }
    *(byte *)(param_1 + 0x22d) = *(byte *)(param_1 + 0x22d) | 4;
  }
  else if (iVar1 == 100) {
    if ((*(byte *)(iVar3 + 0x118) & 8) == 0) {
      FlashlightTurnOn__11CBasePlayer(param_1);
    }
    else {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar3 + 0x208),1,"items/flashlight1.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0xf7;
      (*DAT_0019f758)(1,gmsgFlashlight,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(0);
      (*DAT_0019f760)(param_1[0x1b4]);
      (*DAT_0019f75c)();
      param_1[0x1b3] = (int)(*gpGlobals + 0.2);
    }
  }
  else {
    if (iVar1 != 0xc9) {
      FUN_000db000();
      return;
    }
    if ((float)param_1[0x28e] <= *gpGlobals) {
      UTIL_MakeVectors__FRC6Vector(iVar3 + 0x74);
      iVar1 = *param_1;
      fStack_58 = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x174);
      fStack_54 = *(float *)(iVar1 + 0xc) + *(float *)(iVar1 + 0x178);
      fStack_50 = *(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0x17c);
      fStack_64 = gpGlobals[10] * 128.0;
      fStack_4c = fStack_58 + fStack_64;
      fStack_60 = gpGlobals[0xb] * 128.0;
      fStack_48 = fStack_54 + fStack_60;
      fStack_5c = gpGlobals[0xc] * 128.0;
      fStack_44 = fStack_50 + fStack_5c;
      fStack_70 = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x174);
      fStack_6c = *(float *)(iVar1 + 0xc) + *(float *)(iVar1 + 0x178);
      fStack_68 = *(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0x17c);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&fStack_70,&fStack_4c,1,*(undefined4 *)(iVar1 + 0x208),auStack_3c);
      if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) {
        param_1[0x28e] = (int)(*gpGlobals + (float)decalfrequency._12_4_);
        uVar2 = GetClassPtr__H1Z9CSprayCan_PX01_PX01(0);
        Spawn__9CSprayCanP9entvars_s(uVar2,*param_1);
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x184) = 0;
  return;
}


