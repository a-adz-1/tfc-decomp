// V_CalcRoll  @ 08053310
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longdouble V_CalcRoll(undefined4 param_1,float *param_2,float param_3,float param_4)

{
  longdouble lVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  AngleVectors(param_1,&forward,&right,up);
  fVar2 = param_2[2] * _DAT_080c9e9c + param_2[1] * DAT_080c9e98 + *param_2 * right;
  if (0.0 <= fVar2) {
    lVar3 = (longdouble)1;
  }
  else {
    lVar3 = (longdouble)-1.0;
  }
  lVar4 = (longdouble)ABS(fVar2);
  lVar5 = (longdouble)param_3;
  lVar1 = (longdouble)param_4;
  if ((byte)(lVar4 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar4 == lVar1) << 0xe) >> 8)) == 1) {
    lVar5 = (lVar4 * lVar5) / (longdouble)param_4;
  }
  return lVar5 * lVar3;
}


// V_Init  @ 0808d260
void V_Init(void)

{
  return;
}


