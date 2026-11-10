// TraceBleed__11CBaseEntityfG6VectorP11TraceResulti  @ 000bf930
void TraceBleed__11CBaseEntityfG6VectorP11TraceResulti
               (int *param_1,float param_2,float *param_3,int param_4,uint param_5)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  int local_68;
  float local_64;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float fStack_2c;
  
  iVar2 = (**(code **)(param_1[0x115] + 0x44))(param_1);
  if (((iVar2 != -1) &&
      ((byte)(param_2 < 0.0 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) != 0x40)) &&
     ((param_5 & 0x8000c7) != 0)) {
    if ((byte)((10.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
               (byte)((ushort)((ushort)(param_2 == 10.0) << 0xe) >> 8)) - 1) < 0x40) {
      if ((byte)((25.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 25.0) << 0xe) >> 8)) - 1) < 0x40) {
        local_64 = 0.3;
        local_68 = 4;
      }
      else {
        local_64 = 0.2;
        local_68 = 2;
      }
    }
    else {
      local_64 = 0.1;
      local_68 = 1;
    }
    if (local_68 != 0) {
      fVar1 = -local_64;
      iVar2 = 0;
      do {
        local_54 = -*param_3;
        local_50 = -param_3[1];
        local_4c = -param_3[2];
        local_48 = local_54;
        local_44 = local_50;
        local_40 = local_4c;
        lVar4 = (longdouble)(*DAT_0019f80c)(fVar1,local_64);
        local_48 = (float)(lVar4 + (longdouble)local_48);
        lVar4 = (longdouble)(*DAT_0019f80c)(fVar1,local_64);
        local_44 = (float)(lVar4 + (longdouble)local_44);
        lVar5 = (longdouble)(*DAT_0019f80c)(fVar1,local_64);
        lVar4 = (longdouble)local_40;
        local_40 = (float)(lVar5 + lVar4);
        local_54 = local_48 * -172.0 + *(float *)(param_4 + 0x14);
        local_50 = local_44 * -172.0 + *(float *)(param_4 + 0x18);
        local_4c = (float)((lVar5 + lVar4) * (longdouble)-172.0 +
                          (longdouble)*(float *)(param_4 + 0x1c));
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_4 + 0x14,&local_54,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
        if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) {
          uVar3 = (**(code **)(param_1[0x115] + 0x44))(param_1);
          UTIL_BloodDecalTrace__FP11TraceResulti(local_3c,uVar3);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < local_68);
    }
  }
  return;
}


