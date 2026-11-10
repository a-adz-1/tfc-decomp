// DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0  @ 0010df08
void DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0(int param_1,int *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  undefined *puVar7;
  
  if (param_3[0x89] != 0) {
    iVar3 = GetTeamCheckTeam__FPCc(param_3[0x89] + *(int *)(gpGlobals + 0x98));
    param_3[0x87] = iVar3;
  }
  if (param_3[0x86] == 1) {
    if ((*(int *)(param_1 + 0x2d8) == 0) && (*(int *)(param_1 + 0x2e4) == 0)) {
      return;
    }
    iVar3 = *(int *)(*param_3 + 0x198);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(iVar3 + 0x7c);
    }
    if (param_2[0x48] == param_3[0x87]) {
      iVar4 = *param_2;
      if (*(int *)(iVar4 + 0x208) != *(int *)(*param_3 + 0x198)) {
        puVar7 = (undefined *)(*(int *)(*piVar5 + 0x1d0) + *(int *)(gpGlobals + 0x98));
        iVar3 = *(int *)(param_1 + 0x2d8);
        goto LAB_0010e1a8;
      }
      iVar3 = *(int *)(param_1 + 0x2d8);
    }
    else {
      iVar4 = *param_2;
      if (*(int *)(iVar4 + 0x208) != *(int *)(*param_3 + 0x198)) {
        puVar7 = (undefined *)(*(int *)(*piVar5 + 0x1d0) + *(int *)(gpGlobals + 0x98));
        iVar3 = *(int *)(param_1 + 0x2e4);
        goto LAB_0010e1e8;
      }
      iVar3 = *(int *)(param_1 + 0x2e4);
    }
    puVar7 = &DAT_001529e8;
    iVar3 = iVar3 + *(int *)(gpGlobals + 0x98);
    goto LAB_0010e20a;
  }
  bVar6 = false;
  fVar1 = *(float *)(*param_3 + 8);
  fVar2 = *(float *)(*param_3 + 0x14);
  if (((byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) &&
     (fVar1 = *(float *)(*param_3 + 0xc), fVar2 = *(float *)(*param_3 + 0x18),
     (byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_3 + 0x10);
    fVar2 = *(float *)(*param_3 + 0x1c);
    bVar6 = (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar6) {
    if ((*(int *)(param_1 + 0x2d0) == 0) && (*(int *)(param_1 + 0x2dc) == 0)) {
      return;
    }
    if (param_2[0x48] != param_3[0x87]) {
      puVar7 = (undefined *)0x0;
      iVar3 = *(int *)(param_1 + 0x2dc);
      goto LAB_0010e1e8;
    }
    puVar7 = (undefined *)0x0;
    iVar3 = *(int *)(param_1 + 0x2d0);
  }
  else {
    if ((*(int *)(param_1 + 0x2d4) == 0) && (*(int *)(param_1 + 0x2e0) == 0)) {
      return;
    }
    if (param_2[0x48] == param_3[0x87]) {
      puVar7 = (undefined *)0x0;
      iVar3 = *(int *)(param_1 + 0x2d4);
LAB_0010e1e8:
      iVar3 = iVar3 + *(int *)(gpGlobals + 0x98);
      iVar4 = *param_2;
      goto LAB_0010e20a;
    }
    puVar7 = (undefined *)0x0;
    iVar3 = *(int *)(param_1 + 0x2e0);
  }
LAB_0010e1a8:
  iVar3 = iVar3 + *(int *)(gpGlobals + 0x98);
  iVar4 = *param_2;
LAB_0010e20a:
  ClientPrint__FP9entvars_siPCcN42(iVar4,1,iVar3,puVar7,0,0,0);
  return;
}


