// UpdateSpot__14CTFSniperRifle  @ 0013151c
void UpdateSpot__14CTFSniperRifle(int param_1)

{
  int *piVar1;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 auStack_54 [20];
  undefined1 auStack_40 [36];
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (*(int *)(param_1 + 0x4d4) != 0) {
    if (*(int *)(param_1 + 0x4d0) == 0) {
      piVar1 = (int *)CreateSpot__10CLaserSpot();
      *(int **)(param_1 + 0x4d0) = piVar1;
      *(byte *)(*piVar1 + 0x1a5) = *(byte *)(*piVar1 + 0x1a5) | 1;
      *(undefined4 *)(**(int **)(param_1 + 0x4d0) + 0x198) =
           *(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208);
    }
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    GetGunPosition__12CBaseMonster(&fStack_10,*(undefined4 *)(param_1 + 0x474));
    fStack_1c = *(float *)(gpGlobals + 0x28);
    fStack_18 = *(float *)(gpGlobals + 0x2c);
    fStack_14 = *(float *)(gpGlobals + 0x30);
    fStack_60 = fStack_1c * 8192.0 + fStack_10;
    fStack_5c = fStack_18 * 8192.0 + fStack_c;
    fStack_58 = fStack_14 * 8192.0 + fStack_8;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&fStack_10,&fStack_60,0,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
               auStack_54);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(**(undefined4 **)(param_1 + 0x4d0),auStack_40);
    *(float *)(**(int **)(param_1 + 0x4d0) + 0x14c) = *(float *)(param_1 + 0x4a0) * 0.25 + 150.0;
  }
  return;
}


