// Kill__10CWeaponBox  @ 00124574
void Kill__10CWeaponBox(int *param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    for (piVar2 = (int *)param_1[iVar4 + 0x116]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x11e]
        ) {
      piVar2[3] = -0x10000;
      piVar2[4] = (int)SUB_Remove__11CBaseEntity;
      *(float *)(*piVar2 + 0x104) = *gpGlobals + 0.1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  fVar1 = (float)param_1[0x11d];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar4 = *(int *)(*param_1 + 400);
    if ((iVar4 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x7c);
    }
    if ((iVar4 != 0) && (iVar3 = (**(code **)(*(int *)(iVar4 + 0x454) + 0x2c))(iVar4), iVar3 == 2))
    {
      *(int *)(iVar4 + 0xdb4) = *(int *)(iVar4 + 0xdb4) + -1;
    }
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Kill__15CBasePlayerItem  @ 00125c3c
void Kill__15CBasePlayerItem(int *param_1)

{
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


