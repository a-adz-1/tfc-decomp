// RandomPoint__10CLightningR6Vector  @ 000ad180
void RandomPoint__10CLightningR6Vector(int *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  undefined1 local_58 [16];
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = 0;
  while( true ) {
    lVar3 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    fVar1 = (float)lVar3;
    lVar3 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    lVar4 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    lVar5 = (longdouble)(float)lVar3;
    local_14 = (float)SQRT(lVar4 * lVar4 + lVar5 * lVar5 + (longdouble)fVar1 * (longdouble)fVar1);
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 1.0;
    }
    else {
      local_14 = 1.0 / local_14;
      local_1c = local_14 * fVar1;
      local_18 = local_14 * (float)lVar3;
      local_14 = local_14 * (float)lVar4;
    }
    local_10 = local_1c;
    local_c = local_18;
    local_8 = local_14;
    fVar1 = (float)param_1[0xff];
    local_20 = *param_2 + fVar1 * local_1c;
    local_1c = param_2[1] + fVar1 * local_18;
    local_18 = param_2[2] + fVar1 * local_14;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (param_2,&local_20,1,*(undefined4 *)(*param_1 + 0x1e8),local_58);
    local_20 = SQRT((local_3c - param_2[2]) * (local_3c - param_2[2]) +
                    (local_40 - param_2[1]) * (local_40 - param_2[1]) +
                    (local_44 - *param_2) * (local_44 - *param_2));
    if (((float)param_1[0xff] * 0.1 <= local_20) &&
       ((byte)(1.0 < local_48 | (byte)((ushort)((ushort)NAN(local_48) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_48 == 1.0) << 0xe) >> 8)) != 0x40)) break;
    iVar2 = iVar2 + 1;
    if (9 < iVar2) {
      return;
    }
  }
  Zap__10CLightningRC6VectorT1(param_1,param_2,&local_44);
  return;
}


