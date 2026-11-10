// ChangeYaw__12CBaseMonsteri  @ 000be9cc
longdouble ChangeYaw__12CBaseMonsteri(int *param_1,int param_2)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar2 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
  lVar3 = (longdouble)*(float *)(*param_1 + 0xac);
  if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) == 0x40) {
    return (longdouble)0;
  }
  lVar4 = lVar3 - lVar2;
  lVar5 = (longdouble)*(float *)(gpGlobals + 4) * (longdouble)param_2 * (longdouble)10.0;
  if ((byte)((lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) - 1) < 0x40) {
    lVar3 = (longdouble)-180.0;
    if ((byte)(lVar3 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == lVar4) << 0xe) >> 8)) != 1) {
      lVar4 = (longdouble)360.0 + lVar4;
    }
  }
  else if ((longdouble)180.0 <= lVar4) {
    lVar4 = lVar4 - (longdouble)360.0;
  }
  if (lVar4 <= (longdouble)0) {
    lVar3 = -lVar5;
    lVar5 = lVar4;
    if (0x3f < (byte)((lVar3 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar3 == lVar4) << 0xe) >> 8)) - 1))
    goto LAB_000beaa4;
  }
  else {
    lVar3 = lVar4;
    if ((byte)((lVar4 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar5)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar4 == lVar5) << 0xe) >> 8)) - 1) < 0x40)
    goto LAB_000beaa4;
  }
  lVar3 = lVar5;
LAB_000beaa4:
  lVar2 = (longdouble)UTIL_AngleMod__Ff((float)(lVar2 + lVar3));
  *(float *)(*param_1 + 0x54) = (float)lVar2;
  if ((*(byte *)((int)param_1 + 0x655) & 4) != 0) {
    fVar1 = *(float *)(*param_1 + 0xac) - *(float *)(*param_1 + 0x54);
    if (180.0 < fVar1) {
      fVar1 = fVar1 - 360.0;
    }
    if (0x3f < (byte)((-180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == -180.0) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar1 + 360.0;
    }
    SetBoneController__14CBaseAnimatingif(param_1,0,fVar1);
  }
  return lVar3;
}


