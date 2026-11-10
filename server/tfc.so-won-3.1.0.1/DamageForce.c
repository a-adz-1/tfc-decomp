// DamageForce__12CBaseMonsterf  @ 0008eb84
longdouble DamageForce__12CBaseMonsterf(int *param_1,float param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = *param_1;
  lVar2 = (longdouble)
          ((73728.0 /
           (*(float *)(iVar1 + 0xf4) * *(float *)(iVar1 + 0xf8) * *(float *)(iVar1 + 0xfc))) *
           param_2 * 5.0);
  if ((longdouble)1000.0 < lVar2) {
    lVar2 = (longdouble)1000.0;
  }
  return lVar2;
}


