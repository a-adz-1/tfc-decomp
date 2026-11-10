// ImpulseCommands__11CBasePlayer  @ 000d05d0
void ImpulseCommands__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
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
  float local_3c;
  undefined1 local_38 [16];
  float local_28;
  
  PlayerUse__11CBasePlayer(param_1);
  iVar3 = *(int *)(*param_1 + 0x184);
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
      *(byte *)(param_1 + 0x207) = *(byte *)(param_1 + 0x207) | 4;
    }
    else {
      if (iVar3 != 99) {
        FUN_000d086c();
        return;
      }
      bVar5 = gmsgLogo == 0;
      if (bVar5) {
        gmsgLogo = (*DAT_001a7f6c)(&DAT_0013ae88,1);
      }
      (*DAT_001a7ef8)(1,gmsgLogo,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(bVar5);
      (*DAT_001a7efc)();
      if (!bVar5) {
        gmsgLogo = 0;
      }
    }
  }
  else if (iVar3 == 0xc9) {
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x267];
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
      iVar3 = *param_1;
      local_50 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
      local_4c = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x178);
      local_48 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x17c);
      local_5c = gpGlobals[10] * 128.0;
      local_58 = gpGlobals[0xb] * 128.0;
      local_54 = gpGlobals[0xc] * 128.0;
      local_44 = local_50 + local_5c;
      local_40 = local_4c + local_58;
      local_3c = local_48 + local_54;
      local_68 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
      local_64 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x178);
      local_60 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x17c);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_68,&local_44,1,*(undefined4 *)(iVar3 + 0x208),local_38);
      if ((byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) != 0x40) {
        param_1[0x267] = (int)(*gpGlobals + (float)decalfrequency._12_4_);
        uVar4 = GetClassPtr__H1Z9CSprayCan_PX01_PX01(0);
        Spawn__9CSprayCanP9entvars_s(uVar4,*param_1);
      }
    }
  }
  else {
    if (iVar3 != 0xcc) {
      FUN_000d086c();
      return;
    }
    ForceClientDllUpdate__11CBasePlayer(param_1);
  }
  *(undefined4 *)(*param_1 + 0x184) = 0;
  return;
}


