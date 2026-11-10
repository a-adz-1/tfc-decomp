// CaltropGrenadePrimed__17CTFCaltropGrenade  @ 000f0b70
void CaltropGrenadePrimed__17CTFCaltropGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *(int *)(*param_1 + 0x198);
  if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar3 + 0x7c);
  }
  if (*(int *)(iVar3 + 0x80) == 0) {
    if ((*(byte *)(iVar3 + 0x85) & 4) == 0) {
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x18e];
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        return;
      }
    }
    *(byte *)(iVar3 + 0x85) = *(byte *)(iVar3 + 0x85) & 0xfb;
    *(byte *)(iVar3 + 0x84) = *(byte *)(iVar3 + 0x84) & 0xfe;
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar3 + 0x24) = DAT_001a7e04;
    *(undefined4 *)(iVar3 + 0x28) = DAT_001a7e08;
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar3 + 0x60) = DAT_001a7e04;
    *(undefined4 *)(iVar3 + 100) = DAT_001a7e08;
    (**(code **)(param_1[0xf5] + 0x234))(param_1);
    *(int *)(*param_1 + 0x1e4) = param_1[0x18e];
    param_1[3] = -0x10000;
    param_1[4] = (int)Detonate__8CGrenade;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
    uVar4 = (*DAT_001a7fa8)(3,6);
    *(undefined4 *)(*param_1 + 0x128) = uVar4;
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
    *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
    *(undefined4 *)(*param_1 + 0x120) = 0x3f4ccccd;
    (**(code **)(param_1[0xf5] + 0x220))(param_1);
  }
  else {
    *(undefined4 *)(iVar3 + 0x80) = 0;
    *(byte *)(iVar3 + 0x85) = *(byte *)(iVar3 + 0x85) & 0xfb;
    *(byte *)(iVar3 + 0x84) = *(byte *)(iVar3 + 0x84) & 0xfe;
    dremove__FP11CBaseEntity(param_1);
  }
  return;
}


