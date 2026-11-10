// FixedUnsigned16__Fff  @ 0011a1b0
int FixedUnsigned16__Fff(float param_1,float param_2)

{
  int iVar1;
  
  iVar1 = (int)ROUND(param_1 * param_2);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (0xffff < iVar1) {
    iVar1 = 0xffff;
  }
  return (int)(short)iVar1;
}


