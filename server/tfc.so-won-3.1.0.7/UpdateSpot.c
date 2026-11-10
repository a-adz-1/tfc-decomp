// UpdateSpot__14CTFSniperRifle  @ 0012d4c0
void UpdateSpot__14CTFSniperRifle(int param_1)

{
  int *piVar1;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_54 [20];
  undefined1 local_40 [36];
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(param_1 + 0x4c4) != 0) {
    if (*(int *)(param_1 + 0x4c0) == 0) {
      piVar1 = (int *)CreateSpot__10CLaserSpot();
      *(int **)(param_1 + 0x4c0) = piVar1;
      *(byte *)(*piVar1 + 0x1a5) = *(byte *)(*piVar1 + 0x1a5) | 1;
      *(undefined4 *)(**(int **)(param_1 + 0x4c0) + 0x198) =
           *(undefined4 *)(**(int **)(param_1 + 0x464) + 0x208);
    }
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x464) + 0x74);
    GetGunPosition__12CBaseMonster(&local_c,*(undefined4 *)(param_1 + 0x464));
    local_1c = *(float *)(gpGlobals + 0x28);
    local_18 = *(float *)(gpGlobals + 0x2c);
    local_14 = *(float *)(gpGlobals + 0x30);
    local_60 = local_10 + local_1c * 8192.0;
    local_5c = local_c + local_18 * 8192.0;
    local_58 = local_8 + local_14 * 8192.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_c,&local_60,0,*(undefined4 *)(**(int **)(param_1 + 0x464) + 0x208),local_54);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(**(undefined4 **)(param_1 + 0x4c0),local_40);
    *(float *)(**(int **)(param_1 + 0x4c0) + 0x14c) = *(float *)(param_1 + 0x490) * 0.25 + 150.0;
  }
  return;
}


