// CaltropGrenadePrimed__17CTFCaltropGrenade  @ 000fd7d0
void CaltropGrenadePrimed__17CTFCaltropGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *(int *)(*param_1 + 0x178);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001755d4)(0), iVar4 == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0xd8);
  }
  pfVar3 = gpGlobals;
  if (*(int *)(iVar4 + 0x84) == 0) {
    if ((*(byte *)(iVar4 + 0x89) & 4) == 0) {
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
      fVar1 = *pfVar3;
      fVar2 = (float)param_1[0x189];
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
    }
    *(byte *)(iVar4 + 0x89) = *(byte *)(iVar4 + 0x89) & 0xfb;
    *(byte *)(iVar4 + 0x88) = *(byte *)(iVar4 + 0x88) & 0xfe;
    iVar4 = *param_1;
    *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar4 + 0x24) = DAT_00175484;
    *(undefined4 *)(iVar4 + 0x28) = DAT_00175488;
    iVar4 = *param_1;
    *(undefined4 *)(iVar4 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar4 + 0x60) = DAT_00175484;
    *(undefined4 *)(iVar4 + 100) = DAT_00175488;
    (**(code **)(param_1[0xf2] + 0x234))(param_1);
    *(int *)(*param_1 + 0x1c4) = param_1[0x189];
    param_1[3] = -0x10000;
    param_1[4] = (int)Detonate__8CGrenade;
    *(float *)(*param_1 + 0xe4) = *gpGlobals;
    uVar5 = (*DAT_00175628)(3,6);
    *(undefined4 *)(*param_1 + 0x108) = uVar5;
    *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
    *(undefined4 *)(*param_1 + 0xfc) = 0x3f000000;
    *(undefined4 *)(*param_1 + 0x100) = 0x3f4ccccd;
    (**(code **)(param_1[0xf2] + 0x220))(param_1);
  }
  else {
    *(undefined4 *)(iVar4 + 0x84) = 0;
    *(byte *)(iVar4 + 0x89) = *(byte *)(iVar4 + 0x89) & 0xfb;
    *(byte *)(iVar4 + 0x88) = *(byte *)(iVar4 + 0x88) & 0xfe;
    dremove__FP11CBaseEntity(param_1);
  }
  return;
}


