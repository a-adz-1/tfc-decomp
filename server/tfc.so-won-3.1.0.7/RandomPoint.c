// RandomPoint__10CLightningR6Vector  @ 000a2178
void RandomPoint__10CLightningR6Vector(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  undefined1 local_54 [16];
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = 0;
  while( true ) {
    lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    fVar1 = (float)lVar4;
    lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    fVar2 = (float)lVar4;
    lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    local_10 = (float)SQRT(lVar4 * lVar4 + (longdouble)(fVar1 * fVar1) + (longdouble)(fVar2 * fVar2)
                          );
    if ((byte)((byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_18 = 0.0;
      local_14 = 0.0;
      local_10 = 1.0;
    }
    else {
      local_10 = 1.0 / local_10;
      local_18 = local_10 * fVar1;
      local_14 = local_10 * fVar2;
      local_10 = local_10 * (float)lVar4;
    }
    local_c = local_18;
    local_8 = local_14;
    local_4 = local_10;
    fVar1 = (float)param_1[0x11e];
    local_1c = *param_2 + fVar1 * local_18;
    local_18 = param_2[1] + fVar1 * local_14;
    local_14 = param_2[2] + fVar1 * local_10;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (param_2,&local_1c,1,*(undefined4 *)(*param_1 + 0x208),local_54);
    local_1c = SQRT((local_38 - param_2[2]) * (local_38 - param_2[2]) +
                    (local_3c - param_2[1]) * (local_3c - param_2[1]) +
                    (local_40 - *param_2) * (local_40 - *param_2));
    if (((float)param_1[0x11e] * 0.1 <= local_1c) &&
       ((byte)(1.0 < local_44 | (byte)((ushort)((ushort)NAN(local_44) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_44 == 1.0) << 0xe) >> 8)) != 0x40)) break;
    iVar3 = iVar3 + 1;
    if (9 < iVar3) {
      return;
    }
  }
  Zap__10CLightningRC6VectorT1(param_1,param_2,&local_40);
  return;
}


