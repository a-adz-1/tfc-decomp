// SetObjectCollisionBox__10CWeaponBox  @ 00111fc4
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


// SetObjectCollisionBox__11CBaseEntity  @ 0008709c
void SetObjectCollisionBox__11CBaseEntity(undefined4 *param_1)

{
  SetObjectCollisionBox__FP9entvars_s(*param_1);
  return;
}


// SetObjectCollisionBox__15CBasePlayerItem  @ 0010fd90
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


// SetObjectCollisionBox__7CTFGoal  @ 000fa750
void SetObjectCollisionBox__7CTFGoal(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = *param_1;
  if (*(char *)(*(int *)(iVar2 + 0xb8) + *(int *)(gpGlobals + 0x98)) == '*') {
    fVar1 = 0.0;
    fVar3 = ABS(*(float *)(*param_1 + 0xdc));
    if (0x3f < (byte)((fVar3 < 0.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar3;
    }
    fVar3 = ABS(*(float *)(*param_1 + 0xe8));
    if (0x3f < (byte)((fVar3 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1)) {
      FUN_000fa8a0();
      return;
    }
    fVar3 = ABS(*(float *)(*param_1 + 0xe0));
    if (0x3f < (byte)((fVar3 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar3;
    }
    fVar3 = ABS(*(float *)(*param_1 + 0xec));
    if (0x3f < (byte)((fVar3 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar3;
    }
    fVar3 = ABS(*(float *)(*param_1 + 0xe4));
    if (0x3f < (byte)((fVar3 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar3;
    }
    fVar3 = ABS(*(float *)(*param_1 + 0xf0));
    if (0x3f < (byte)((fVar3 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar3;
    }
    *(float *)(*param_1 + 0xc4) = *(float *)(*param_1 + 8) - fVar1;
    *(float *)(*param_1 + 0xd0) = fVar1 + *(float *)(*param_1 + 8);
    *(float *)(*param_1 + 200) = *(float *)(*param_1 + 0xc) - fVar1;
    *(float *)(*param_1 + 0xd4) = fVar1 + *(float *)(*param_1 + 0xc);
    *(float *)(*param_1 + 0xcc) = *(float *)(*param_1 + 0x10) - fVar1;
    *(float *)(*param_1 + 0xd8) = fVar1 + *(float *)(*param_1 + 0x10);
    *(float *)(*param_1 + 0xc4) = *(float *)(*param_1 + 0xc4) - 1.0;
    *(float *)(*param_1 + 200) = *(float *)(*param_1 + 200) - 1.0;
    *(float *)(*param_1 + 0xcc) = *(float *)(*param_1 + 0xcc) - 1.0;
    *(float *)(*param_1 + 0xd0) = *(float *)(*param_1 + 0xd0) + 1.0;
    *(float *)(*param_1 + 0xd4) = *(float *)(*param_1 + 0xd4) + 1.0;
    *(float *)(*param_1 + 0xd8) = *(float *)(*param_1 + 0xd8) + 1.0;
  }
  else {
    *(float *)(iVar2 + 0xc4) = *(float *)(iVar2 + 8) + -24.0;
    *(float *)(iVar2 + 200) = *(float *)(iVar2 + 0xc) + -24.0;
    *(undefined4 *)(iVar2 + 0xcc) = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = *param_1;
    *(float *)(iVar2 + 0xd0) = *(float *)(iVar2 + 8) + 24.0;
    *(float *)(iVar2 + 0xd4) = *(float *)(iVar2 + 0xc) + 24.0;
    *(float *)(iVar2 + 0xd8) = *(float *)(iVar2 + 0x10) + 16.0;
  }
  return;
}


// SetObjectCollisionBox__FP9entvars_s  @ 00086e28
void SetObjectCollisionBox__FP9entvars_s(int param_1)

{
  float fVar1;
  float fVar2;
  
  if ((*(int *)(param_1 + 0x10c) == 4) &&
     ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x50)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x50) == 0.0) << 0xe) >> 8)) != 0x40 ||
       ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x54)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(param_1 + 0x54) == 0.0) << 0xe) >> 8)) != 0x40))
      || (fVar1 = *(float *)(param_1 + 0x58),
         (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)))) {
    fVar1 = 0.0;
    fVar2 = ABS(*(float *)(param_1 + 0xdc));
    if (0x3f < (byte)((fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    fVar2 = ABS(*(float *)(param_1 + 0xe8));
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    fVar2 = ABS(*(float *)(param_1 + 0xe0));
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    fVar2 = ABS(*(float *)(param_1 + 0xec));
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    fVar2 = ABS(*(float *)(param_1 + 0xe4));
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    fVar2 = ABS(*(float *)(param_1 + 0xf0));
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 8) - fVar1;
    *(float *)(param_1 + 0xd0) = fVar1 + *(float *)(param_1 + 8);
    *(float *)(param_1 + 200) = *(float *)(param_1 + 0xc) - fVar1;
    *(float *)(param_1 + 0xd4) = fVar1 + *(float *)(param_1 + 0xc);
    *(float *)(param_1 + 0xcc) = *(float *)(param_1 + 0x10) - fVar1;
    *(float *)(param_1 + 0xd8) = fVar1 + *(float *)(param_1 + 0x10);
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


