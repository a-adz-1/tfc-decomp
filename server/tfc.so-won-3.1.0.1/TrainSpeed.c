// TrainSpeed__Fii  @ 000c8324
undefined4 TrainSpeed__Fii(int param_1,int param_2)

{
  double dVar1;
  undefined4 uVar2;
  
  dVar1 = (double)param_1 / (double)param_2;
  if (param_1 < 0) {
    uVar2 = 5;
  }
  else if (param_1 == 0) {
    uVar2 = 1;
  }
  else if ((byte)((0.33 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(dVar1 == 0.33) << 0xe) >> 8)) - 1) < 0x40) {
    uVar2 = 4;
    if (0x3f < (byte)((0.66 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(dVar1 == 0.66) << 0xe) >> 8)) - 1)) {
      uVar2 = 3;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


