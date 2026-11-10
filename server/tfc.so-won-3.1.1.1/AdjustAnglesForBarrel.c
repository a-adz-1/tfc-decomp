// AdjustAnglesForBarrel__9CFuncTankR6Vectorf  @ 000ac73c
void AdjustAnglesForBarrel__9CFuncTankR6Vectorf(int param_1,float *param_2,float param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar4 = (longdouble)0;
  lVar1 = (longdouble)*(float *)(param_1 + 0x4a8);
  if (((byte)((byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar4)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar1 == lVar4) << 0xe) >> 8)) != 0x40) ||
     (lVar2 = (longdouble)*(float *)(param_1 + 0x4ac),
     (byte)(lVar2 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
           (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) != 0x40)) {
    lVar3 = (longdouble)*(float *)(param_1 + 0x4ac);
    lVar2 = ((longdouble)param_3 - lVar3) * ((longdouble)param_3 - lVar3);
    if ((byte)(lVar1 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar1 == lVar4) << 0xe) >> 8)) != 0x40) {
      lVar1 = (longdouble)fpatan(lVar1,SQRT(lVar2 - lVar1 * lVar1));
      param_2[1] = (float)(lVar1 * (longdouble)57.29577951308232 + (longdouble)param_2[1]);
      lVar3 = (longdouble)*(float *)(param_1 + 0x4ac);
    }
    if ((byte)(lVar3 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar4) << 0xe) >> 8)) != 0x40) {
      lVar4 = (longdouble)fpatan(-lVar3,SQRT(lVar2 - lVar3 * lVar3));
      *param_2 = (float)(lVar4 * (longdouble)57.29577951308232 + (longdouble)*param_2);
    }
  }
  return;
}


