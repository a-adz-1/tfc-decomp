// FacingIdeal__12CBaseMonster  @ 000c1974
bool FacingIdeal__12CBaseMonster(int *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar1 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
  lVar2 = (longdouble)*(float *)(*param_1 + 0xac);
  if ((byte)((byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) == 0x40) {
    lVar1 = (longdouble)0;
  }
  else {
    lVar1 = (longdouble)UTIL_AngleDiff__Fff(*(float *)(*param_1 + 0xac),(float)lVar1);
  }
  return ABS(lVar1) <= (longdouble)0.006;
}


