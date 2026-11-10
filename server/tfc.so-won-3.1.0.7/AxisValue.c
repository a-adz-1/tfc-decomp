// AxisValue__11CBaseToggleiRC6Vector  @ 000f4564
longdouble AxisValue__11CBaseToggleiRC6Vector(byte param_1,float *param_2)

{
  longdouble lVar1;
  
  if ((param_1 & 0x40) == 0) {
    if ((char)param_1 < '\0') {
      lVar1 = (longdouble)*param_2;
    }
    else {
      lVar1 = (longdouble)param_2[1];
    }
  }
  else {
    lVar1 = (longdouble)param_2[2];
  }
  return lVar1;
}


