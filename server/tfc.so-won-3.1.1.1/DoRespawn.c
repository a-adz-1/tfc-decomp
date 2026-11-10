// DoRespawn__11CBaseEntity  @ 0010d018
void DoRespawn__11CBaseEntity(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
  if (param_1[0x86] == 3) {
    fVar2 = (float)param_1[0x95];
    if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      if (((*(byte *)((int)param_1 + 0x229) & 0x20) == 0) ||
         (iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal"),
         iVar3 != 0)) {
        *(undefined4 *)(*param_1 + 0x10c) = 1;
      }
      else {
        *(undefined4 *)(*param_1 + 0x10c) = 2;
      }
    }
    else {
      *(float *)(*param_1 + 0x104) = *gpGlobals + fVar2;
    }
    param_1[0x86] = 2;
    if (*(char *)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]) != '*') {
      pbVar1 = (byte *)(*param_1 + 0x118);
      *pbVar1 = *pbVar1 & 0x7f;
    }
  }
  if (param_1[0x86] == 1) {
    iVar3 = (**(code **)(param_1[0x115] + 0x2c))(param_1);
    if (iVar3 != 0x81) {
      if (((*(byte *)((int)param_1 + 0x229) & 0x20) == 0) ||
         ((iVar3 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar3 != 0x80 &&
          (iVar3 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar3 != 0x82)))) {
        *(undefined4 *)(*param_1 + 0x10c) = 1;
      }
      else {
        *(undefined4 *)(*param_1 + 0x10c) = 2;
      }
    }
    param_1[0x86] = 2;
    if (*(char *)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]) != '*') {
      pbVar1 = (byte *)(*param_1 + 0x118);
      *pbVar1 = *pbVar1 & 0x7f;
    }
    return;
  }
  return;
}


