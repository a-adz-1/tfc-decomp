// PlayerTouch__11CBasePlayerP11CBaseEntity  @ 000e3ac8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PlayerTouch__11CBasePlayerP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined1 auStack_40 [48];
  int iStack_10;
  float fStack_8;
  
  iVar4 = (**(code **)(param_2[0x115] + 0x2c))(param_2);
  if (iVar4 != 2) {
    return;
  }
  if ((*(int *)(*param_1 + 0x20c) == 8) || (*(int *)(*param_2 + 0x20c) == 8)) {
    CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(param_1,param_2);
    CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(param_2,param_1);
  }
  iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2);
  if (iVar4 == 0) {
    return;
  }
  iVar4 = *param_2;
  fVar1 = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
               *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
               *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20));
  if ((byte)((50.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 50.0) << 0xe) >> 8)) - 1) < 0x40) {
    return;
  }
  iVar4 = *param_1;
  fStack_8 = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                  *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                  *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20));
  if (((byte)(55.0 < fStack_8 | (byte)((ushort)((ushort)NAN(fStack_8) << 10) >> 8) |
             (byte)((ushort)((ushort)(fStack_8 == 55.0) << 0xe) >> 8)) != 1) &&
     ((*(byte *)((int)param_1 + 0x8a) & 6) == 0)) {
    return;
  }
  UTIL_MakeVectors__FRC6Vector(iVar4 + 0x74);
  iVar4 = *param_1;
  fStack_4c = *(float *)(gpGlobals + 0x28) * 24.0 + *(float *)(iVar4 + 8);
  fStack_48 = *(float *)(gpGlobals + 0x2c) * 24.0 + *(float *)(iVar4 + 0xc);
  fStack_44 = *(float *)(gpGlobals + 0x30) * 24.0 + *(float *)(iVar4 + 0x10);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (iVar4 + 8,&fStack_4c,0,*(undefined4 *)(iVar4 + 0x208),auStack_40);
  bVar3 = false;
  if ((iStack_10 == 0) || (iVar4 = (*DAT_0019f7b8)(iStack_10), iVar4 == 0)) {
    bVar3 = true;
  }
  if (!bVar3) {
    if ((iStack_10 == 0) && (iStack_10 = (*DAT_0019f7b4)(0), iStack_10 == 0)) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(iStack_10 + 0x7c);
    }
    if (piVar6 == param_2) {
      if ((*(byte *)((int)param_1 + 0x8a) & 6) == 0) {
        if ((*(byte *)((int)param_2 + 0x8a) & 6) != 0) {
          return;
        }
        iVar2 = *param_1;
        iVar4 = *param_2;
        fStack_44 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                         *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                         *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
        if ((byte)((byte)((ushort)((ushort)NAN(fStack_44) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_44 == 0.0) << 0xe) >> 8)) == 0x40) {
          fStack_4c = 0.0;
          fStack_48 = 0.0;
          fStack_44 = 1.0;
        }
        else {
          fStack_44 = 1.0 / fStack_44;
          fStack_4c = *(float *)(iVar2 + 0x20) * fStack_44;
          fStack_48 = *(float *)(iVar2 + 0x24) * fStack_44;
          fStack_44 = fStack_44 * *(float *)(iVar2 + 0x28);
        }
        iVar2 = *param_2;
        fVar1 = *(float *)(iVar2 + 0x24);
        fVar5 = fStack_44 * 30.0 + *(float *)(iVar2 + 0x28);
        *(float *)(iVar4 + 0x20) = fStack_4c * 30.0 + *(float *)(iVar2 + 0x20);
        *(float *)(iVar4 + 0x24) = fStack_48 * 30.0 + fVar1;
      }
      else {
        iVar2 = *param_1;
        iVar4 = *param_2;
        fStack_5c = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                         *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                         *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
        if ((byte)((byte)((ushort)((ushort)NAN(fStack_5c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_5c == 0.0) << 0xe) >> 8)) == 0x40) {
          fStack_64 = 0.0;
          fStack_60 = 0.0;
          fStack_5c = 1.0;
        }
        else {
          fStack_5c = 1.0 / fStack_5c;
          fStack_64 = *(float *)(iVar2 + 0x20) * fStack_5c;
          fStack_60 = *(float *)(iVar2 + 0x24) * fStack_5c;
          fStack_5c = fStack_5c * *(float *)(iVar2 + 0x28);
        }
        fStack_60 = fStack_60 * _FUN_00151544;
        iVar2 = *param_2;
        fVar1 = *(float *)(iVar2 + 0x24);
        fVar5 = _FUN_00151544 * fStack_5c + *(float *)(iVar2 + 0x28);
        *(float *)(iVar4 + 0x20) = fStack_64 * _FUN_00151544 + *(float *)(iVar2 + 0x20);
        *(float *)(iVar4 + 0x24) = fStack_60 + fVar1;
      }
      *(float *)(iVar4 + 0x28) = fVar5;
    }
    return;
  }
  return;
}


