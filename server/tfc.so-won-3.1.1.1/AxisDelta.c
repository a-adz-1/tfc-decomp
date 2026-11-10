// AxisDelta__11CBaseToggleiRC6VectorT2  @ 000f6358
longdouble AxisDelta__11CBaseToggleiRC6VectorT2(byte param_1,float *param_2,float *param_3)

{
  longdouble lVar1;
  
  if ((param_1 & 0x40) == 0) {
    if ((char)param_1 < '\0') {
      lVar1 = (longdouble)*param_2 - (longdouble)*param_3;
    }
    else {
      lVar1 = (longdouble)param_2[1] - (longdouble)param_3[1];
    }
  }
  else {
    lVar1 = (longdouble)param_2[2] - (longdouble)param_3[2];
  }
  return lVar1;
}


