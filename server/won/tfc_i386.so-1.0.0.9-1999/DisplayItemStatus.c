// DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0  @ 0010d4e0
void DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0(int param_1,int *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  
  if (param_3[0x86] == 1) {
    if ((*(int *)(param_1 + 0x2d0) == 0) && (*(int *)(param_1 + 0x2dc) == 0)) {
      return;
    }
    iVar3 = *(int *)(*param_3 + 0x178);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(iVar3 + 0xd8);
    }
    if (param_2[0x48] == param_3[0x87]) {
      iVar5 = *param_2;
      if (*(int *)(iVar5 + 0x1e8) != *(int *)(*param_3 + 0x178)) {
        puVar4 = (undefined *)(*(int *)(*piVar6 + 0x1b0) + *(int *)(gpGlobals + 0x98));
        iVar3 = *(int *)(param_1 + 0x2d0);
LAB_0010d621:
        iVar3 = iVar3 + *(int *)(gpGlobals + 0x98);
        goto LAB_0010d72a;
      }
      iVar3 = *(int *)(param_1 + 0x2d0);
    }
    else {
      iVar5 = *param_2;
      if (*(int *)(iVar5 + 0x1e8) != *(int *)(*param_3 + 0x178)) {
        puVar4 = (undefined *)(*(int *)(*piVar6 + 0x1b0) + *(int *)(gpGlobals + 0x98));
        iVar3 = *(int *)(param_1 + 0x2dc);
        goto LAB_0010d621;
      }
      iVar3 = *(int *)(param_1 + 0x2dc);
    }
    puVar4 = &DAT_00149058;
    iVar3 = iVar3 + *(int *)(gpGlobals + 0x98);
  }
  else {
    bVar7 = false;
    fVar1 = *(float *)(*param_3 + 8);
    fVar2 = *(float *)(*param_3 + 0x14);
    if (((byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) &&
       (fVar1 = *(float *)(*param_3 + 0xc), fVar2 = *(float *)(*param_3 + 0x18),
       (byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40)) {
      fVar1 = *(float *)(*param_3 + 0x10);
      fVar2 = *(float *)(*param_3 + 0x1c);
      bVar7 = (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (bVar7) {
      if ((*(int *)(param_1 + 0x2c8) == 0) && (*(int *)(param_1 + 0x2d4) == 0)) {
        return;
      }
      if (param_2[0x48] == param_3[0x87]) {
        iVar3 = *(int *)(param_1 + 0x2c8);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x2d4);
      }
    }
    else {
      if ((*(int *)(param_1 + 0x2cc) == 0) && (*(int *)(param_1 + 0x2d8) == 0)) {
        return;
      }
      if (param_2[0x48] == param_3[0x87]) {
        iVar3 = *(int *)(param_1 + 0x2cc);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x2d8);
      }
    }
    puVar4 = (undefined *)0x0;
    iVar3 = iVar3 + *(int *)(gpGlobals + 0x98);
LAB_0010d72a:
    iVar5 = *param_2;
  }
  ClientPrint__FP9entvars_tiPCcN42(iVar5,1,iVar3,puVar4,0,0,0);
  return;
}


