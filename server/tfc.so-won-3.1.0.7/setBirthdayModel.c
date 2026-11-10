// setBirthdayModel__8CGrenade  @ 001016a4
undefined4 setBirthdayModel__8CGrenade(int *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  if (birthday != 0) {
    lVar1 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
    lVar2 = (longdouble)0.5;
    if (0x3f < (byte)((lVar2 < lVar1 |
                       (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1)) {
      (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),"models/presentsm.mdl");
      return 1;
    }
  }
  return 0;
}


