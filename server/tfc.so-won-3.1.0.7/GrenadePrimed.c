// GrenadePrimed__15CTFPrimeGrenade  @ 000fcd90
void GrenadePrimed__15CTFPrimeGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(*param_1 + 0x198);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x7c);
  }
  bVar3 = false;
  if (*(int *)(iVar4 + 0x80) == 0) {
    if (((*(byte *)(iVar4 + 0x85) & 4) == 0) &&
       (iVar5 = (**(code **)(*(int *)(iVar4 + 0x444) + 0x8c))(iVar4), iVar5 != 0)) {
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.01;
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x1aa];
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
      bVar3 = true;
    }
    *(byte *)(iVar4 + 0x85) = *(byte *)(iVar4 + 0x85) & 0xfb;
    *(byte *)(iVar4 + 0x84) = *(byte *)(iVar4 + 0x84) & 0xfe;
    if (bVar3) {
      ExplodeInHand__15CTFPrimeGrenade(param_1);
    }
    else {
      iVar4 = (**(code **)(*(int *)(iVar4 + 0x444) + 0x8c))(iVar4);
      if (iVar4 == 0) {
        DeadThrow__15CTFPrimeGrenade(param_1);
      }
      else {
        Throw__15CTFPrimeGrenade(param_1);
      }
    }
  }
  else {
    *(undefined4 *)(iVar4 + 0x80) = 0;
    *(byte *)(iVar4 + 0x85) = *(byte *)(iVar4 + 0x85) & 0xfb;
    *(byte *)(iVar4 + 0x84) = *(byte *)(iVar4 + 0x84) & 0xfe;
    dremove__FP11CBaseEntity(param_1);
  }
  return;
}


