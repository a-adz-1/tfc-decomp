// DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0  @ 00110aec
void DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0(int param_1,int *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined *puVar4;
  bool bVar5;
  int iVar6;
  int *local_18;
  
  if (param_3[0x89] != 0) {
    iVar3 = GetTeamCheckTeam__FPCc(param_3[0x89] + *(int *)(gpGlobals + 0x98));
    param_3[0x87] = iVar3;
  }
  if (param_3[0x86] == 1) {
    if ((*(int *)(param_1 + 0x2e8) == 0) && (*(int *)(param_1 + 0x2f4) == 0)) {
      return;
    }
    iVar3 = *(int *)(*param_3 + 0x198);
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
      local_18 = (int *)0x0;
      iVar3 = *param_3;
    }
    else {
      local_18 = *(int **)(iVar3 + 0x7c);
      iVar3 = *param_3;
    }
    if (param_2[0x48] == param_3[0x87]) {
      iVar6 = *param_2;
      if (*(int *)(iVar6 + 0x208) == *(int *)(iVar3 + 0x198)) {
        puVar4 = &DAT_00157b84;
        iVar3 = *(int *)(param_1 + 0x2e8) + *(int *)(gpGlobals + 0x98);
      }
      else {
        puVar4 = (undefined *)(*(int *)(*local_18 + 0x1d0) + *(int *)(gpGlobals + 0x98));
        iVar3 = *(int *)(param_1 + 0x2e8) + *(int *)(gpGlobals + 0x98);
      }
    }
    else {
      iVar6 = *param_2;
      if (*(int *)(iVar6 + 0x208) == *(int *)(iVar3 + 0x198)) {
        puVar4 = &DAT_00157b84;
        iVar3 = *(int *)(param_1 + 0x2f4) + *(int *)(gpGlobals + 0x98);
      }
      else {
        puVar4 = (undefined *)(*(int *)(*local_18 + 0x1d0) + *(int *)(gpGlobals + 0x98));
        iVar3 = *(int *)(param_1 + 0x2f4) + *(int *)(gpGlobals + 0x98);
      }
    }
    goto LAB_00110dde;
  }
  bVar5 = false;
  iVar3 = *param_3;
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x14)) || NAN(*(float *)(iVar3 + 8)))
                             << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x14) == *(float *)(iVar3 + 8)) << 0xe) >>
                   8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x18)) || NAN(*(float *)(iVar3 + 0xc)))
                            << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x18) == *(float *)(iVar3 + 0xc)) << 0xe) >>
                  8)) == 0x40)) {
    fVar1 = *(float *)(iVar3 + 0x10);
    fVar2 = *(float *)(iVar3 + 0x1c);
    bVar5 = (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar5) {
    if ((*(int *)(param_1 + 0x2e0) == 0) && (*(int *)(param_1 + 0x2ec) == 0)) {
      return;
    }
    if (param_2[0x48] != param_3[0x87]) {
      iVar3 = *(int *)(param_1 + 0x2ec) + *(int *)(gpGlobals + 0x98);
      goto LAB_00110dd6;
    }
    iVar3 = *(int *)(param_1 + 0x2e0) + *(int *)(gpGlobals + 0x98);
  }
  else {
    if ((*(int *)(param_1 + 0x2e4) == 0) && (*(int *)(param_1 + 0x2f0) == 0)) {
      return;
    }
    if (param_2[0x48] == param_3[0x87]) {
      iVar3 = *(int *)(param_1 + 0x2e4) + *(int *)(gpGlobals + 0x98);
LAB_00110dd6:
      puVar4 = (undefined *)0x0;
      iVar6 = *param_2;
      goto LAB_00110dde;
    }
    iVar3 = *(int *)(param_1 + 0x2f0) + *(int *)(gpGlobals + 0x98);
  }
  puVar4 = (undefined *)0x0;
  iVar6 = *param_2;
LAB_00110dde:
  ClientPrint__FP9entvars_siPCcN42(iVar6,1,iVar3,puVar4,0,0,0);
  return;
}


