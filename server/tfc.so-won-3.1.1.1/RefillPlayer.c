// RefillPlayer__12CTFDispenserP11CBasePlayer  @ 0009bf00
undefined4 RefillPlayer__12CTFDispenserP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_1c;
  int local_18;
  
  iVar3 = param_1[0x33];
  if ((((iVar3 == 0) && (param_1[0x35] == 0)) && (param_1[0x39] == 0)) &&
     ((param_1[0x37] == 0 &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x1bc)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1bc) == 0.0) << 0xe) >> 8)) == 0x40)))
     ) {
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Dispenser_empty",0,0,0,0);
    uVar4 = 0;
  }
  else {
    iVar7 = iVar3;
    if (param_2[0x30] - param_2[0x33] < iVar3) {
      iVar7 = param_2[0x30] - param_2[0x33];
    }
    if (0x14 < iVar7) {
      iVar7 = 0x14;
    }
    param_1[0x33] = iVar3 - iVar7;
    iVar3 = param_1[0x35];
    iVar6 = iVar3;
    if (param_2[0x34] - param_2[0x35] < iVar3) {
      iVar6 = param_2[0x34] - param_2[0x35];
    }
    if (0x14 < iVar6) {
      iVar6 = 0x14;
    }
    param_1[0x35] = iVar3 - iVar6;
    iVar3 = param_1[0x39];
    iVar5 = iVar3;
    if (param_2[0x38] - param_2[0x39] < iVar3) {
      iVar5 = param_2[0x38] - param_2[0x39];
    }
    if (10 < iVar5) {
      iVar5 = 10;
    }
    param_1[0x39] = iVar3 - iVar5;
    if (*(int *)(*param_2 + 0x20c) == 9) {
      local_18 = param_1[0x37];
      local_1c = local_18;
      if (param_2[0x36] - param_2[0x37] < local_18) {
        local_1c = param_2[0x36] - param_2[0x37];
      }
      if (0x4b < local_1c) {
        local_1c = 0x4b;
      }
    }
    else {
      local_18 = param_1[0x37];
      local_1c = local_18;
      if (param_2[0x36] - param_2[0x37] < local_18) {
        local_1c = param_2[0x36] - param_2[0x37];
      }
      if (10 < local_1c) {
        local_1c = 10;
      }
    }
    param_1[0x37] = local_18 - local_1c;
    GiveTFAmmo__11CBasePlayeriiii(param_2,iVar7,iVar6,iVar5,local_1c);
    fVar2 = (float)param_2[0x3c] - *(float *)(*param_2 + 0x1bc);
    iVar3 = *param_1;
    fVar1 = *(float *)(iVar3 + 0x1bc);
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    if (20.0 < fVar1) {
      fVar1 = 20.0;
    }
    fVar2 = (float)(int)ROUND(fVar1);
    *(float *)(iVar3 + 0x1bc) = *(float *)(iVar3 + 0x1bc) - fVar2;
    *(float *)(*param_2 + 0x1bc) = fVar2 + *(float *)(*param_2 + 0x1bc);
    fVar2 = *(float *)(*param_1 + 0x1b8);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x1b8) = 0x3e99999a;
      *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) | 0x20;
    }
    if (iVar7 + iVar6 + iVar5 + local_1c + (int)ROUND(fVar1) == 0) {
      uVar4 = 0;
    }
    else {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_2 + 0x208),3,"items/ammopickup2.wav",0x3f800000,0x3f4ccccd,0
                 ,100);
      uVar4 = 1;
    }
  }
  return uVar4;
}


