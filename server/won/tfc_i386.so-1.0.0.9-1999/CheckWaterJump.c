// CheckWaterJump__11CBasePlayer  @ 000d8b40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckWaterJump__11CBasePlayer(int *param_1)

{
  float *pfVar1;
  int iVar2;
  undefined1 auStack_64 [16];
  float fStack_54;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = IsOnLadder__11CBasePlayer(param_1);
  if (iVar2 == 0) {
    local_10 = *(float *)(*param_1 + 8);
    local_c = *(float *)(*param_1 + 0xc);
    local_8 = *(float *)(*param_1 + 0x10) + 8.0;
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    pfVar1 = gpGlobals;
    gpGlobals[0xc] = 0.0;
    fStack_14 = SQRT(pfVar1[0xc] * pfVar1[0xc] + pfVar1[0xb] * pfVar1[0xb] + pfVar1[10] * pfVar1[10]
                    );
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_1c = 0.0;
      fStack_18 = 0.0;
      fStack_14 = 1.0;
    }
    else {
      fStack_14 = 1.0 / fStack_14;
      fStack_1c = fStack_14 * pfVar1[10];
      fStack_18 = fStack_14 * pfVar1[0xb];
      fStack_14 = fStack_14 * pfVar1[0xc];
    }
    pfVar1[10] = fStack_1c;
    pfVar1[0xb] = fStack_18;
    pfVar1[0xc] = fStack_14;
    fStack_2c = gpGlobals[10] * 24.0;
    fStack_28 = gpGlobals[0xb] * 24.0;
    fStack_24 = gpGlobals[0xc] * 24.0;
    fStack_20 = local_10 + fStack_2c;
    fStack_1c = local_c + fStack_28;
    fStack_18 = local_8 + fStack_24;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_10,&fStack_20,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_64);
    if ((byte)(fStack_54 < 1.0 | (byte)((ushort)((ushort)NAN(fStack_54) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_54 == 1.0) << 0xe) >> 8)) == 1) {
      iVar2 = *param_1;
      local_8 = (*(float *)(iVar2 + 0xd0) - 8.0) + local_8;
      fStack_2c = local_10 + gpGlobals[10] * 24.0;
      fStack_28 = local_c + gpGlobals[0xb] * 24.0;
      fStack_24 = local_8 + gpGlobals[0xc] * 24.0;
      *(float *)(iVar2 + 0x44) = fStack_40 * -50.0;
      *(float *)(iVar2 + 0x48) = fStack_3c * -50.0;
      *(float *)(iVar2 + 0x4c) = fStack_38 * -50.0;
      fStack_20 = fStack_2c;
      fStack_1c = fStack_28;
      fStack_18 = fStack_24;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_10,&fStack_20,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_64);
      if ((byte)((byte)((ushort)((ushort)NAN(fStack_54) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_54 == 1.0) << 0xe) >> 8)) == 0x40) {
        *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) | 8;
        *(undefined4 *)(*param_1 + 0x28) = 0x43610000;
        *(float *)(*param_1 + 0x194) = _FUN_00139ac0 + *gpGlobals;
      }
    }
  }
  return;
}


