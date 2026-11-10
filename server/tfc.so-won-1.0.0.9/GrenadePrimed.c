// GrenadePrimed__15CTFPrimeGrenade  @ 000fca60
void GrenadePrimed__15CTFPrimeGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(*param_1 + 0x178);
  if ((iVar5 == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(iVar5 + 0xd8);
  }
  bVar3 = false;
  if (*(int *)(iVar5 + 0x84) == 0) {
    if (((*(byte *)(iVar5 + 0x89) & 4) == 0) &&
       (iVar6 = (**(code **)(*(int *)(iVar5 + 0x3c8) + 0x88))(iVar5), pfVar4 = gpGlobals, iVar6 != 0
       )) {
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.01;
      fVar1 = *pfVar4;
      fVar2 = (float)param_1[0x189];
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
      bVar3 = true;
    }
    *(byte *)(iVar5 + 0x89) = *(byte *)(iVar5 + 0x89) & 0xfb;
    *(byte *)(iVar5 + 0x88) = *(byte *)(iVar5 + 0x88) & 0xfe;
    if (bVar3) {
      ExplodeInHand__15CTFPrimeGrenade(param_1);
    }
    else {
      iVar5 = (**(code **)(*(int *)(iVar5 + 0x3c8) + 0x88))(iVar5);
      if (iVar5 == 0) {
        DeadThrow__15CTFPrimeGrenade(param_1);
      }
      else {
        Throw__15CTFPrimeGrenade(param_1);
      }
    }
  }
  else {
    *(undefined4 *)(iVar5 + 0x84) = 0;
    *(byte *)(iVar5 + 0x89) = *(byte *)(iVar5 + 0x89) & 0xfb;
    *(byte *)(iVar5 + 0x88) = *(byte *)(iVar5 + 0x88) & 0xfe;
    dremove__FP11CBaseEntity(param_1);
  }
  return;
}


