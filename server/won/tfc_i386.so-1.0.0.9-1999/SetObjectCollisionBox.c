// SetObjectCollisionBox__10CWeaponBox  @ 0011c900
void SetObjectCollisionBox__10CWeaponBox(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(float *)(iVar1 + 0xa4) = *(float *)(iVar1 + 8) + -16.0;
  *(float *)(iVar1 + 0xa8) = *(float *)(iVar1 + 0xc) + -16.0;
  *(float *)(iVar1 + 0xac) = *(float *)(iVar1 + 0x10) + 0.0;
  iVar1 = *param_1;
  *(float *)(iVar1 + 0xb0) = *(float *)(iVar1 + 8) + 16.0;
  *(float *)(iVar1 + 0xb4) = *(float *)(iVar1 + 0xc) + 16.0;
  *(float *)(iVar1 + 0xb8) = *(float *)(iVar1 + 0x10) + 16.0;
  return;
}


// SetObjectCollisionBox__11CBaseEntity  @ 000a1790
void SetObjectCollisionBox__11CBaseEntity(undefined4 *param_1)

{
  SetObjectCollisionBox__FP9entvars_t(*param_1);
  return;
}


// SetObjectCollisionBox__15CBasePlayerItem  @ 0011ab40
void SetObjectCollisionBox__15CBasePlayerItem(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(float *)(iVar1 + 0xa4) = *(float *)(iVar1 + 8) + -24.0;
  *(float *)(iVar1 + 0xa8) = *(float *)(iVar1 + 0xc) + -24.0;
  *(float *)(iVar1 + 0xac) = *(float *)(iVar1 + 0x10) + 0.0;
  iVar1 = *param_1;
  *(float *)(iVar1 + 0xb0) = *(float *)(iVar1 + 8) + 24.0;
  *(float *)(iVar1 + 0xb4) = *(float *)(iVar1 + 0xc) + 24.0;
  *(float *)(iVar1 + 0xb8) = *(float *)(iVar1 + 0x10) + 16.0;
  return;
}


// SetObjectCollisionBox__7CTFGoal  @ 00109230
void SetObjectCollisionBox__7CTFGoal(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(*(int *)(iVar3 + 0x98) + *(int *)(gpGlobals + 0x98)) == '*') {
    fVar2 = 0.0;
    iVar3 = 0;
    do {
      fVar1 = ABS(*(float *)(*param_1 + 0xbc + iVar3 * 4));
      if (fVar2 < fVar1) {
        fVar2 = fVar1;
      }
      fVar1 = ABS(*(float *)(*param_1 + 200 + iVar3 * 4));
      if (fVar2 < fVar1) {
        fVar2 = fVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    iVar3 = 0;
    do {
      *(float *)(*param_1 + 0xa4 + iVar3 * 4) = *(float *)(*param_1 + 8 + iVar3 * 4) - fVar2;
      *(float *)(*param_1 + 0xb0 + iVar3 * 4) = fVar2 + *(float *)(*param_1 + 8 + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    *(float *)(*param_1 + 0xa4) = *(float *)(*param_1 + 0xa4) - 1.0;
    *(float *)(*param_1 + 0xa8) = *(float *)(*param_1 + 0xa8) - 1.0;
    *(float *)(*param_1 + 0xac) = *(float *)(*param_1 + 0xac) - 1.0;
    *(float *)(*param_1 + 0xb0) = *(float *)(*param_1 + 0xb0) + 1.0;
    *(float *)(*param_1 + 0xb4) = *(float *)(*param_1 + 0xb4) + 1.0;
    *(float *)(*param_1 + 0xb8) = *(float *)(*param_1 + 0xb8) + 1.0;
  }
  else {
    *(float *)(iVar3 + 0xa4) = *(float *)(iVar3 + 8) + -24.0;
    *(float *)(iVar3 + 0xa8) = *(float *)(iVar3 + 0xc) + -24.0;
    *(float *)(iVar3 + 0xac) = *(float *)(iVar3 + 0x10) + 0.0;
    iVar3 = *param_1;
    *(float *)(iVar3 + 0xb0) = *(float *)(iVar3 + 8) + 24.0;
    *(float *)(iVar3 + 0xb4) = *(float *)(iVar3 + 0xc) + 24.0;
    *(float *)(iVar3 + 0xb8) = *(float *)(iVar3 + 0x10) + 16.0;
  }
  return;
}


// SetObjectCollisionBox__FP9entvars_t  @ 000a15d0
void SetObjectCollisionBox__FP9entvars_t(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0xec) == 4) &&
     ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x50)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x50) == 0.0) << 0xe) >> 8)) != 0x40 ||
       ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x54)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x54) == 0.0) << 0xe) >> 8)) != 0x40))
      || (fVar1 = *(float *)(param_1 + 0x58),
         (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)))) {
    fVar1 = 0.0;
    iVar3 = 0;
    do {
      fVar2 = ABS(*(float *)(param_1 + 0xbc + iVar3 * 4));
      if (fVar1 < fVar2) {
        fVar1 = fVar2;
      }
      fVar2 = ABS(*(float *)(param_1 + 200 + iVar3 * 4));
      if (fVar1 < fVar2) {
        fVar1 = fVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    iVar3 = 0;
    do {
      *(float *)(param_1 + 0xa4 + iVar3 * 4) = *(float *)(param_1 + 8 + iVar3 * 4) - fVar1;
      *(float *)(param_1 + 0xb0 + iVar3 * 4) = fVar1 + *(float *)(param_1 + 8 + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  else {
    *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 8) + *(float *)(param_1 + 0xbc);
    *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0xc0);
    *(float *)(param_1 + 0xac) = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0xc4);
    *(float *)(param_1 + 0xb0) = *(float *)(param_1 + 8) + *(float *)(param_1 + 200);
    *(float *)(param_1 + 0xb4) = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0xcc);
    *(float *)(param_1 + 0xb8) = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0xd0);
  }
  *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa4) - 1.0;
  *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0xa8) - 1.0;
  *(float *)(param_1 + 0xac) = *(float *)(param_1 + 0xac) - 1.0;
  *(float *)(param_1 + 0xb0) = *(float *)(param_1 + 0xb0) + 1.0;
  *(float *)(param_1 + 0xb4) = *(float *)(param_1 + 0xb4) + 1.0;
  *(float *)(param_1 + 0xb8) = *(float *)(param_1 + 0xb8) + 1.0;
  return;
}


