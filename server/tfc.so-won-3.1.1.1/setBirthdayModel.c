// setBirthdayModel__8CGrenade  @ 0010469c
undefined4 setBirthdayModel__8CGrenade(int *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  if (birthday != 0) {
    lVar1 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
    lVar2 = (longdouble)0.5;
    if (0x3f < (byte)((lVar2 < lVar1 |
                       (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1)) {
      (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),"models/presentsm.mdl");
      return 1;
    }
  }
  return 0;
}


