// SetObjectCollisionBox__10CWeaponBox  @ 00124a7c
void SetObjectCollisionBox__10CWeaponBox(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(float *)(iVar1 + 0xc4) = *(float *)(iVar1 + 8) + -16.0;
  *(float *)(iVar1 + 200) = *(float *)(iVar1 + 0xc) + -16.0;
  *(undefined4 *)(iVar1 + 0xcc) = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = *param_1;
  *(float *)(iVar1 + 0xd0) = *(float *)(iVar1 + 8) + 16.0;
  *(float *)(iVar1 + 0xd4) = *(float *)(iVar1 + 0xc) + 16.0;
  *(float *)(iVar1 + 0xd8) = *(float *)(iVar1 + 0x10) + 16.0;
  return;
}


// SetObjectCollisionBox__11CBaseEntity  @ 0008eb30
void SetObjectCollisionBox__11CBaseEntity(undefined4 *param_1)

{
  SetObjectCollisionBox__FP9entvars_s(*param_1);
  return;
}


// SetObjectCollisionBox__15CBasePlayerItem  @ 00123b90
void SetObjectCollisionBox__15CBasePlayerItem(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(float *)(iVar1 + 0xc4) = *(float *)(iVar1 + 8) + -24.0;
  *(float *)(iVar1 + 200) = *(float *)(iVar1 + 0xc) + -24.0;
  *(undefined4 *)(iVar1 + 0xcc) = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = *param_1;
  *(float *)(iVar1 + 0xd0) = *(float *)(iVar1 + 8) + 24.0;
  *(float *)(iVar1 + 0xd4) = *(float *)(iVar1 + 0xc) + 24.0;
  *(float *)(iVar1 + 0xd8) = *(float *)(iVar1 + 0x10) + 16.0;
  return;
}


// SetObjectCollisionBox__7CTFGoal  @ 0010b124
void SetObjectCollisionBox__7CTFGoal(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if (*(char *)(*(int *)(iVar4 + 0xb8) + *(int *)(gpGlobals + 0x98)) == '*') {
    fVar2 = 0.0;
    iVar3 = 0;
    do {
      fVar1 = ABS(*(float *)(iVar4 + 0xdc + iVar3 * 4));
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        fVar2 = fVar1;
      }
      fVar1 = ABS(*(float *)(iVar4 + 0xe8 + iVar3 * 4));
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        fVar2 = fVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    iVar4 = 0;
    do {
      *(float *)(*param_1 + 0xc4 + iVar4 * 4) = *(float *)(*param_1 + 8 + iVar4 * 4) - fVar2;
      *(float *)(*param_1 + 0xd0 + iVar4 * 4) = *(float *)(*param_1 + 8 + iVar4 * 4) + fVar2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    *(float *)(*param_1 + 0xc4) = *(float *)(*param_1 + 0xc4) - 1.0;
    *(float *)(*param_1 + 200) = *(float *)(*param_1 + 200) - 1.0;
    *(float *)(*param_1 + 0xcc) = *(float *)(*param_1 + 0xcc) - 1.0;
    *(float *)(*param_1 + 0xd0) = *(float *)(*param_1 + 0xd0) + 1.0;
    *(float *)(*param_1 + 0xd4) = *(float *)(*param_1 + 0xd4) + 1.0;
    *(float *)(*param_1 + 0xd8) = *(float *)(*param_1 + 0xd8) + 1.0;
  }
  else {
    *(float *)(iVar4 + 0xc4) = *(float *)(iVar4 + 8) + -24.0;
    *(float *)(iVar4 + 200) = *(float *)(iVar4 + 0xc) + -24.0;
    *(undefined4 *)(iVar4 + 0xcc) = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = *param_1;
    *(float *)(iVar4 + 0xd0) = *(float *)(iVar4 + 8) + 24.0;
    *(float *)(iVar4 + 0xd4) = *(float *)(iVar4 + 0xc) + 24.0;
    *(float *)(iVar4 + 0xd8) = *(float *)(iVar4 + 0x10) + 16.0;
  }
  return;
}


// SetObjectCollisionBox__FP9entvars_s  @ 0008e3ac
void SetObjectCollisionBox__FP9entvars_s(int param_1)

{
  float fVar1;
  float fVar2;
  int local_18;
  
  if ((*(int *)(param_1 + 0x10c) == 4) &&
     ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x50)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x50) == 0.0) << 0xe) >> 8)) != 0x40 ||
       ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x54)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x54) == 0.0) << 0xe) >> 8)) != 0x40))
      || (fVar1 = *(float *)(param_1 + 0x58),
         (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)))) {
    fVar1 = 0.0;
    local_18 = 0;
    do {
      fVar2 = ABS(*(float *)(param_1 + 0xdc + local_18 * 4));
      if (0x3f < (byte)((fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
        fVar1 = fVar2;
      }
      fVar2 = ABS(*(float *)(param_1 + 0xe8 + local_18 * 4));
      if (0x3f < (byte)((fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
        fVar1 = fVar2;
      }
      local_18 = local_18 + 1;
    } while (local_18 < 3);
    local_18 = 0;
    do {
      *(float *)(param_1 + 0xc4 + local_18 * 4) = *(float *)(param_1 + 8 + local_18 * 4) - fVar1;
      *(float *)(param_1 + 0xd0 + local_18 * 4) = *(float *)(param_1 + 8 + local_18 * 4) + fVar1;
      local_18 = local_18 + 1;
    } while (local_18 < 3);
  }
  else {
    *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 8) + *(float *)(param_1 + 0xdc);
    *(float *)(param_1 + 200) = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0xe0);
    *(float *)(param_1 + 0xcc) = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0xe4);
    *(float *)(param_1 + 0xd0) = *(float *)(param_1 + 8) + *(float *)(param_1 + 0xe8);
    *(float *)(param_1 + 0xd4) = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0xec);
    *(float *)(param_1 + 0xd8) = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0xf0);
  }
  *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) - 1.0;
  *(float *)(param_1 + 200) = *(float *)(param_1 + 200) - 1.0;
  *(float *)(param_1 + 0xcc) = *(float *)(param_1 + 0xcc) - 1.0;
  *(float *)(param_1 + 0xd0) = *(float *)(param_1 + 0xd0) + 1.0;
  *(float *)(param_1 + 0xd4) = *(float *)(param_1 + 0xd4) + 1.0;
  *(float *)(param_1 + 0xd8) = *(float *)(param_1 + 0xd8) + 1.0;
  return;
}


