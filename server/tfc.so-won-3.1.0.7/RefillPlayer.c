// RefillPlayer__12CTFDispenserP11CBasePlayer  @ 0009c9d0
undefined4 RefillPlayer__12CTFDispenserP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_18;
  int local_14;
  
  if ((((param_1[0x33] == 0) && (param_1[0x35] == 0)) && (param_1[0x39] == 0)) &&
     ((param_1[0x37] == 0 &&
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x1bc)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x1bc) == 0.0) << 0xe) >> 8)) == 0x40)))
     ) {
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Dispenser_empty",0,0,0,0);
    uVar3 = 0;
  }
  else {
    iVar4 = param_1[0x33];
    if (param_2[0x30] - param_2[0x33] < param_1[0x33]) {
      iVar4 = param_2[0x30] - param_2[0x33];
    }
    if (0x14 < iVar4) {
      iVar4 = 0x14;
    }
    param_1[0x33] = param_1[0x33] - iVar4;
    iVar5 = param_1[0x35];
    if (param_2[0x34] - param_2[0x35] < param_1[0x35]) {
      iVar5 = param_2[0x34] - param_2[0x35];
    }
    if (0x14 < iVar5) {
      iVar5 = 0x14;
    }
    param_1[0x35] = param_1[0x35] - iVar5;
    local_18 = param_1[0x39];
    if (param_2[0x38] - param_2[0x39] < param_1[0x39]) {
      local_18 = param_2[0x38] - param_2[0x39];
    }
    if (10 < local_18) {
      local_18 = 10;
    }
    param_1[0x39] = param_1[0x39] - local_18;
    if (*(int *)(*param_2 + 0x20c) == 9) {
      local_14 = param_1[0x37];
      if (param_2[0x36] - param_2[0x37] < param_1[0x37]) {
        local_14 = param_2[0x36] - param_2[0x37];
      }
      if (0x4b < local_14) {
        local_14 = 0x4b;
      }
    }
    else {
      local_14 = param_1[0x37];
      if (param_2[0x36] - param_2[0x37] < param_1[0x37]) {
        local_14 = param_2[0x36] - param_2[0x37];
      }
      if (10 < local_14) {
        local_14 = 10;
      }
    }
    param_1[0x37] = param_1[0x37] - local_14;
    GiveTFAmmo__11CBasePlayeriiii(param_2,iVar4,iVar5,local_18,local_14);
    fVar2 = (float)param_2[0x3c] - *(float *)(*param_2 + 0x1bc);
    fVar1 = *(float *)(*param_1 + 0x1bc);
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    if (20.0 < fVar1) {
      fVar1 = 20.0;
    }
    fVar2 = (float)(int)ROUND(fVar1);
    *(float *)(*param_1 + 0x1bc) = *(float *)(*param_1 + 0x1bc) - fVar2;
    *(float *)(*param_2 + 0x1bc) = fVar2 + *(float *)(*param_2 + 0x1bc);
    fVar2 = *(float *)(*param_1 + 0x1b8);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x1b8) = 0x3e99999a;
      *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) | 0x20;
    }
    if (iVar4 + iVar5 + local_18 + local_14 + (int)ROUND(fVar1) == 0) {
      uVar3 = 0;
    }
    else {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_2 + 0x208),3,"items/ammopickup2.wav",0x3f800000,0x3f4ccccd,0
                 ,100);
      uVar3 = 1;
    }
  }
  return uVar3;
}


