// UpdateSpot__14CTFSniperRifle  @ 00103490
void UpdateSpot__14CTFSniperRifle(int param_1)

{
  undefined4 uVar1;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 auStack_54 [20];
  undefined1 auStack_40 [36];
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  if (*(int *)(param_1 + 0x434) != 0) {
    if (*(int *)(param_1 + 0x430) == 0) {
      uVar1 = CreateSpot__10CLaserSpot();
      *(undefined4 *)(param_1 + 0x430) = uVar1;
    }
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    GetGunPosition__12CBaseMonster(&local_10,*(undefined4 *)(param_1 + 1000));
    fStack_1c = *(float *)(gpGlobals + 0x28);
    fStack_18 = *(float *)(gpGlobals + 0x2c);
    fStack_14 = *(float *)(gpGlobals + 0x30);
    fStack_60 = local_10 + fStack_1c * 8192.0;
    fStack_5c = fStack_c + fStack_18 * 8192.0;
    fStack_58 = fStack_8 + fStack_14 * 8192.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_10,&fStack_60,0,*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),auStack_54
              );
    UTIL_SetOrigin__FP9entvars_tRC6Vector(**(undefined4 **)(param_1 + 0x430),auStack_40);
    *(float *)(**(int **)(param_1 + 0x430) + 300) = *(float *)(param_1 + 0x424) * 0.25 + 150.0;
  }
  return;
}


