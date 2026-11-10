// DamageForce__12CBaseMonsterf  @ 000a5f50
longdouble DamageForce__12CBaseMonsterf(int *param_1,float param_2)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  iVar1 = *param_1;
  lVar2 = (longdouble)
          ((73728.0 /
           (*(float *)(iVar1 + 0xd4) * *(float *)(iVar1 + 0xd8) * *(float *)(iVar1 + 0xdc))) *
           param_2 * 5.0);
  lVar3 = (longdouble)1000.0;
  if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) == 1) {
    lVar2 = (longdouble)1000.0;
  }
  return lVar2;
}


