// RandomPoint__10CLightningR6Vector  @ 000a0ff0
void RandomPoint__10CLightningR6Vector(int *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
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
    lVar3 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar4 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar5 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar6 = (longdouble)(float)SQRT(lVar5 * lVar5 + lVar4 * lVar4 + lVar3 * lVar3);
    lVar7 = (longdouble)0;
    if ((byte)((byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) == 0x40) {
      local_14 = 1.0;
      lVar4 = lVar7;
    }
    else {
      lVar6 = (longdouble)1 / lVar6;
      lVar7 = lVar3 * lVar6;
      lVar4 = lVar4 * lVar6;
      local_14 = (float)(lVar6 * lVar5);
    }
    local_18 = (float)lVar4;
    local_1c = (float)lVar7;
    local_10 = local_1c;
    local_c = local_18;
    local_8 = local_14;
    fVar1 = (float)param_1[0x122];
    local_20 = local_1c * fVar1 + *param_2;
    local_1c = local_18 * fVar1 + param_2[1];
    local_18 = fVar1 * local_14 + param_2[2];
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (param_2,&local_20,1,*(undefined4 *)(*param_1 + 0x208),local_58);
    local_20 = SQRT((local_3c - param_2[2]) * (local_3c - param_2[2]) +
                    (local_40 - param_2[1]) * (local_40 - param_2[1]) +
                    (local_44 - *param_2) * (local_44 - *param_2));
    if (((float)param_1[0x122] * 0.1 <= local_20) &&
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


