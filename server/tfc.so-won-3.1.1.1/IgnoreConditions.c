// IgnoreConditions__12CBaseMonster  @ 000c2b98
uint IgnoreConditions__12CBaseMonster(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  fVar1 = *gpGlobals;
  fVar2 = *(float *)(param_1 + 0x674);
  uVar5 = (uint)((byte)(fVar1 < fVar2 |
                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) << 6;
  if ((*(int *)(param_1 + 0x574) == 6) && (iVar3 = *(int *)(param_1 + 0x698), iVar3 != 0)) {
    uVar4 = (**(code **)(*(int *)(iVar3 + 0x454) + 0x1c4))(iVar3);
    uVar5 = uVar5 | uVar4;
  }
  return uVar5;
}


// IgnoreConditions__12CCineMonster  @ 000eb1a8
undefined4 IgnoreConditions__12CCineMonster(int param_1)

{
  int *piVar1;
  bool bVar2;
  
  if (*(int *)(param_1 + 0x6cc) != 0) {
    piVar1 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x504);
    bVar2 = false;
    if (piVar1 != (int *)0x0) {
      bVar2 = *(int *)(*piVar1 + 0x170) == 0;
    }
    if (bVar2) {
      return 0;
    }
  }
  return 0x300;
}


