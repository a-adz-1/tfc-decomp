// SetupRespawn__FP11CBaseEntity  @ 0010aca0
void SetupRespawn__FP11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  
  param_1[0x9d] = 0;
  iVar2 = (**(code **)(param_1[0xf2] + 0x28))(param_1);
  if (iVar2 == 0x81) {
    InactivateGoal__FP11CBaseEntity(param_1);
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoal_timer_tick__11CBaseEntity;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0x93];
  }
  else if ((*(byte *)(param_1 + 0x8a) & 1) == 0) {
    fVar1 = (float)param_1[0xbe];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      param_1[3] = -0x10000;
      param_1[4] = (int)DoRespawn__11CBaseEntity;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0xbe];
    }
    else {
      fVar1 = (float)param_1[0xbe];
      if ((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) != 0x40) {
        InactivateGoal__FP11CBaseEntity(param_1);
      }
    }
  }
  else {
    RemoveGoal__FP11CBaseEntity(param_1);
  }
  return;
}


