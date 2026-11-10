// Kill__10CWeaponBox  @ 0011c1c0
void Kill__10CWeaponBox(int *param_1)

{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    pfVar3 = gpGlobals;
    for (piVar2 = (int *)param_1[iVar5 + 0xf3]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xfb])
    {
      piVar2[3] = -0x10000;
      piVar2[4] = (int)SUB_Remove__11CBaseEntity;
      *(float *)(*piVar2 + 0xe4) = *pfVar3 + 0.1;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  fVar1 = (float)param_1[0xfa];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar5 = *(int *)(*param_1 + 0x170);
    if ((iVar5 == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0xd8);
    }
    if ((iVar5 != 0) && (iVar4 = (**(code **)(*(int *)(iVar5 + 0x3c8) + 0x28))(iVar5), iVar4 == 2))
    {
      *(int *)(iVar5 + 0xce8) = *(int *)(iVar5 + 0xce8) + -1;
    }
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Kill__15CBasePlayerItem  @ 0011b3f0
void Kill__15CBasePlayerItem(int *param_1)

{
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


