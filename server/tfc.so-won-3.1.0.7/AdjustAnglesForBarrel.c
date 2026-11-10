// AdjustAnglesForBarrel__9CFuncTankR6Vectorf  @ 000abd6c
void AdjustAnglesForBarrel__9CFuncTankR6Vectorf(int param_1,float *param_2,float param_3)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x498)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x498) == 0.0) << 0xe) >> 8)) != 0x40) ||
     (fVar1 = *(float *)(param_1 + 0x49c),
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    lVar2 = (longdouble)param_3 - (longdouble)*(float *)(param_1 + 0x49c);
    lVar2 = lVar2 * lVar2;
    lVar3 = (longdouble)*(float *)(param_1 + 0x498);
    lVar4 = (longdouble)0.0;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 0x40) {
      lVar3 = (longdouble)
              fpatan((longdouble)*(float *)(param_1 + 0x498),SQRT(lVar2 - lVar3 * lVar3));
      param_2[1] = (float)(lVar3 * (longdouble)57.29577951308232 + (longdouble)param_2[1]);
    }
    lVar3 = (longdouble)*(float *)(param_1 + 0x49c);
    lVar4 = (longdouble)0.0;
    if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) != 0x40) {
      lVar2 = (longdouble)fpatan(-lVar3,SQRT(lVar2 - lVar3 * lVar3));
      *param_2 = (float)(lVar2 * (longdouble)57.29577951308232 + (longdouble)*param_2);
    }
  }
  return;
}


