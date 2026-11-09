// ChangeYaw__12CBaseMonsteri  @ 000c52b0
longdouble ChangeYaw__12CBaseMonsteri(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_8;
  
  lVar3 = (longdouble)UTIL_AngleMod__Ff(*(undefined4 *)(*param_1 + 0x54));
  lVar4 = (longdouble)*(float *)(*param_1 + 0x8c);
  if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 0x40) {
    local_8 = 0.0;
    goto LAB_000c53f8;
  }
  fVar1 = (float)param_2 * *(float *)(gpGlobals + 4) * 10.0;
  lVar5 = lVar4 - lVar3;
  local_8 = (float)lVar5;
  if (lVar4 <= lVar3) {
    if (local_8 <= -180.0) {
      lVar5 = (longdouble)360.0 + (longdouble)local_8;
      goto LAB_000c5345;
    }
  }
  else {
    lVar4 = (longdouble)180.0;
    if ((byte)((lVar4 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar5)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar4 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
      lVar5 = lVar5 - (longdouble)360.0;
LAB_000c5345:
      local_8 = (float)lVar5;
    }
  }
  if ((byte)(0.0 < local_8 | (byte)((ushort)((ushort)NAN(local_8) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_8 == 0.0) << 0xe) >> 8)) == 1) {
    fVar2 = fVar1;
    if ((byte)(fVar1 < local_8 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_8)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == local_8) << 0xe) >> 8)) != 1) {
LAB_000c537c:
      fVar2 = local_8;
    }
  }
  else {
    fVar2 = -fVar1;
    if (-fVar1 <= local_8) goto LAB_000c537c;
  }
  local_8 = fVar2;
  lVar3 = (longdouble)UTIL_AngleMod__Ff((float)((longdouble)local_8 + lVar3));
  *(float *)(*param_1 + 0x54) = (float)lVar3;
  if ((*(byte *)((int)param_1 + 0x5c9) & 4) != 0) {
    fVar1 = *(float *)(*param_1 + 0x8c) - *(float *)(*param_1 + 0x54);
    if ((byte)(180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) == 1) {
      fVar1 = fVar1 - 360.0;
    }
    if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
    }
    SetBoneController__14CBaseAnimatingif(param_1,0,fVar1);
  }
LAB_000c53f8:
  return (longdouble)local_8;
}


