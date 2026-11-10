// CaltropScatterThink__10CTFCaltrop  @ 000f134c
void CaltropScatterThink__10CTFCaltrop(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0xf6];
  if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
      param_1[5] = -0x10000;
      param_1[6] = (int)CanisterTouch__10CTFCaltropP11CBaseEntity;
    }
    else {
      *(undefined4 *)(*param_1 + 0x10c) = 1;
      param_1[5] = -0x10000;
      param_1[6] = (int)CaltropTouch__10CTFCaltropP11CBaseEntity;
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x50) = 0x42b40000;
      *(undefined4 *)(iVar3 + 0x54) = 0x42b40000;
      *(undefined4 *)(iVar3 + 0x58) = 0x42b40000;
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
      *(undefined4 *)(iVar3 + 0x60) = DAT_001a7e04;
      *(undefined4 *)(iVar3 + 100) = DAT_001a7e08;
      iVar4 = *param_1;
      *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar4 + 0x5c);
      *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar4 + 0x60);
      *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar4 + 100);
      UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    }
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  return;
}


