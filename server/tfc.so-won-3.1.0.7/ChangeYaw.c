// ChangeYaw__12CBaseMonsteri  @ 000beb4c
longdouble ChangeYaw__12CBaseMonsteri(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_4;
  
  lVar3 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
  lVar4 = (longdouble)*(float *)(*param_1 + 0xac);
  if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 0x40) {
    local_4 = 0.0;
    goto LAB_000becb2;
  }
  fVar1 = (float)param_2 * *(float *)(gpGlobals + 4) * 10.0;
  lVar5 = lVar4 - lVar3;
  local_4 = (float)lVar5;
  if ((byte)((lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1) < 0x40) {
    if ((byte)(-180.0 < local_4 | (byte)((ushort)((ushort)NAN(local_4) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_4 == -180.0) << 0xe) >> 8)) != 1) {
      lVar5 = (longdouble)360.0 + (longdouble)local_4;
      goto LAB_000bebf6;
    }
  }
  else if ((longdouble)180.0 <= lVar5) {
    lVar5 = lVar5 - (longdouble)360.0;
LAB_000bebf6:
    local_4 = (float)lVar5;
  }
  if (local_4 <= 0.0) {
    fVar2 = -fVar1;
    if (-fVar1 <= local_4) goto LAB_000bec31;
  }
  else {
    fVar2 = fVar1;
    if (local_4 <= fVar1) {
LAB_000bec31:
      fVar2 = local_4;
    }
  }
  local_4 = fVar2;
  lVar3 = (longdouble)UTIL_AngleMod__Ff((float)(lVar3 + (longdouble)local_4));
  *(float *)(*param_1 + 0x54) = (float)lVar3;
  if ((*(byte *)((int)param_1 + 0x645) & 4) != 0) {
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
LAB_000becb2:
  return (longdouble)local_4;
}


