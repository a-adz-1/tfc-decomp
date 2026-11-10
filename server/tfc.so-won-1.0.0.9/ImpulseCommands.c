// ImpulseCommands__11CBasePlayer  @ 000dda40
void ImpulseCommands__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  PlayerUse__11CBasePlayer(param_1);
  iVar3 = *(int *)(*param_1 + 0x164);
  if (iVar3 == 100) {
    iVar3 = FlashlightIsOn__11CBasePlayer(param_1);
    if (iVar3 == 0) {
      FlashlightTurnOn__11CBasePlayer(param_1);
    }
    else {
      FlashlightTurnOff__11CBasePlayer(param_1);
    }
  }
  else if (iVar3 < 0x65) {
    if (iVar3 == 0x32) {
      *(byte *)(param_1 + 0x202) = *(byte *)(param_1 + 0x202) | 4;
    }
    else {
      if (iVar3 != 99) {
        FUN_000ddc90();
        return;
      }
      bVar5 = gmsgLogo == 0;
      if (bVar5) {
        gmsgLogo = (*DAT_001755ec)(&DAT_0013a380,1);
      }
      (*DAT_00175578)(1,gmsgLogo,0,*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175580)(bVar5);
      (*DAT_0017557c)();
      if (!bVar5) {
        gmsgLogo = 0;
      }
    }
  }
  else if (iVar3 == 0xc9) {
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x260];
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
      iVar3 = *param_1;
      local_54 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
      local_50 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x158);
      local_4c = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x15c);
      local_60 = gpGlobals[10] * 128.0;
      local_5c = gpGlobals[0xb] * 128.0;
      local_58 = gpGlobals[0xc] * 128.0;
      local_48 = local_54 + local_60;
      local_44 = local_50 + local_5c;
      local_40 = local_4c + local_58;
      local_6c = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
      local_68 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x158);
      local_64 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x15c);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_6c,&local_48,1,*(undefined4 *)(iVar3 + 0x1e8),local_3c);
      if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
        param_1[0x260] = (int)(*gpGlobals + (float)decalfrequency._12_4_);
        uVar4 = GetClassPtr__H1Z9CSprayCan_PX01_PX01(0);
        Spawn__9CSprayCanP9entvars_t(uVar4,*param_1);
      }
    }
  }
  else {
    if (iVar3 != 0xcc) {
      FUN_000ddc90();
      return;
    }
    ForceClientDllUpdate__11CBasePlayer(param_1);
  }
  *(undefined4 *)(*param_1 + 0x164) = 0;
  return;
}


