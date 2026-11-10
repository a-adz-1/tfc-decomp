// SetupRespawn__FP11CBaseEntity  @ 0010cdec
void SetupRespawn__FP11CBaseEntity(int *param_1)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
  param_1[0x9f] = 0;
  if ((*(byte *)(param_1 + 0x8c) & 1) != 0) {
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    param_1[0x86] = 3;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    return;
  }
  iVar3 = (**(code **)(param_1[0x115] + 0x2c))(param_1);
  if (iVar3 == 0x81) {
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
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoal_timer_tick__11CBaseEntity;
    fVar2 = *gpGlobals + (float)param_1[0x95];
  }
  else {
    fVar2 = (float)param_1[0xc5];
    if (fVar2 <= 0.0) {
      if ((byte)(-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) == 0x40) {
        return;
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
        if (*(char *)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]) == '*') {
          return;
        }
        pbVar1 = (byte *)(*param_1 + 0x118);
        *pbVar1 = *pbVar1 & 0x7f;
        return;
      }
      return;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)DoRespawn__11CBaseEntity;
    fVar2 = *gpGlobals + fVar2;
  }
  *(float *)(*param_1 + 0x104) = fVar2;
  return;
}


